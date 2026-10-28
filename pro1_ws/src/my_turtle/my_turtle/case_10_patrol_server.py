#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
案例 10：巡逻小车 —— Action Server 节点（patrol_server）

职责：
  1. 接收 /patrol 的巡逻任务（Goal 是一串航点）；
  2. 逐个航点执行「转向对准 -> 直行 -> 到达判定」；
  3. 每段路上按固定频率发布 Feedback（第几个航点 + 剩余距离）；
  4. 收到取消请求时先发一次零速 Twist 让小车停稳，再返回 canceled 结果。

设计要点（对应验收自查清单）：
  * 用 Event 等第一帧位姿，用 create_rate() 控制循环节拍，不用 time.sleep() 轮询；
  * 角度差一律经过 normalize_angle() 归一化到 [-pi, pi]，避免跨 ±pi 时掉头绕远路；
  * 所有关键事件用 get_logger() 输出；
  * execute_callback 在 ReentrantCallbackGroup + MultiThreadedExecutor 下运行，
    这样它在跑控制循环时，位姿订阅和取消请求仍能被处理。
"""

import math
import threading

import rclpy
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose

from my_turtle_interfaces.action import Patrol

def normalize_angle(angle: float) -> float:
    """把任意角度折叠到 [-pi, pi]。

    atan2() 的结果本身在 [-pi, pi]，但「目标朝向 - 当前朝向」的差值可能到 ±2pi；
    不归一化的话，海龟会为了从 +3.0 转到 -3.0 而绕几乎一整圈（掉头），
    视觉上就是验收里说的「原地打转」。
    """
    return math.atan2(math.sin(angle), math.cos(angle))

class PatrolServer(Node):
    """巡逻任务的服务端：一个 Action Server + 一套航点控制循环。"""

    def __init__(self):
        super().__init__('patrol_server')

        # ---------------- 1. 参数声明（带默认值，可被 launch / param set 覆盖） ----------------
        self.declare_parameter('linear_speed', 1.5)        # 直行最大线速度 m/s
        self.declare_parameter('angular_speed', 2.0)       # 最大角速度 rad/s（也是转向限幅）
        self.declare_parameter('arrival_tolerance', 0.08)  # 到达判定半径 m
        self.declare_parameter('turn_threshold', 0.15)     # 朝偏差超过它就先原地转，再前进
        self.declare_parameter('control_frequency', 20.0)  # 控制循环频率 Hz
        self.declare_parameter('feedback_frequency', 5.0)  # 反馈发布频率 Hz（别把话题刷爆）

        self.linear_speed = float(self.get_parameter('linear_speed').value)
        self.angular_speed = float(self.get_parameter('angular_speed').value)
        self.arrival_tolerance = float(self.get_parameter('arrival_tolerance').value)
        self.turn_threshold = float(self.get_parameter('turn_threshold').value)
        self.control_frequency = float(self.get_parameter('control_frequency').value)
        feedback_hz = float(self.get_parameter('feedback_frequency').value)

        # 每多少个控制周期发一次反馈：20Hz / 5Hz = 4
        self._feedback_every = max(1, int(round(self.control_frequency / feedback_hz)))

        # 注册参数热更新回调：演示时用 ros2 param set 改速度，快慢要立刻生效
        self.add_on_set_parameters_callback(self.on_parameter_change)

        # ---------------- 2. 内部状态 ----------------
        self._pose = None            # 最近一帧位姿，由订阅回调写入
        self._pose_ready = threading.Event()  # 位姿回调里 set()，execute 里 wait()
        self._active = False         # 是否已有任务在执行（防止两个任务同时抢 cmd_vel）

        # ReentrantCallbackGroup：允许 execute_callback 长时间运行的同时，
        # 其它回调（位姿订阅、取消请求、参数服务）在别的线程继续被处理
        self._cb_group = ReentrantCallbackGroup()

        # ---------------- 3. 话题：订阅位姿、发布速度 ----------------
        self._cmd_pub = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.create_subscription(
            Pose, '/turtle1/pose', self.on_pose, 10, callback_group=self._cb_group)

        # 用 Rate 控制循环节拍：它内部是带超时的事件等待，不会像 time.sleep 那样
        # 让整个线程彻底睡死，节点关闭时也能及时返回
        self._rate = self.create_rate(self.control_frequency)

        # ---------------- 4. Action Server ----------------
        self._server = ActionServer(
            self,
            Patrol,
            'patrol',                                        # 动作名，client 连同一个名字
            execute_callback=self.execute_callback,
            goal_callback=self.on_goal,                      # 目标准入判断
            cancel_callback=self.on_cancel,                  # 取消准入判断
            callback_group=self._cb_group,
        )

        self.get_logger().info(
            f'patrol_server 已启动：线速度上限 {self.linear_speed:.2f} m/s，'
            f'角速度上限 {self.angular_speed:.2f} rad/s，等待巡逻任务...')

    # ================= 订阅回调 =================
    def on_pose(self, msg):
        """缓存位姿，并唤醒可能在等第一帧数据的 execute_callback。"""
        self._pose = msg
        self._pose_ready.set()

    # ================= 参数回调 =================
    def on_parameter_change(self, params):
        """参数热更新：只允许正速度；频率类参数改动需要重启节点才生效。"""
        result = rclpy.node.SetParametersResult()
        result.successful = True

        for param in params:
            if param.name in ('linear_speed', 'angular_speed'):
                if float(param.value) <= 0.0:
                    result.successful = False
                    result.reason = f'{param.name} 必须大于 0'
                    self.get_logger().warn(f'拒绝参数 {param.name}={param.value}')
                    continue
                setattr(self, param.name, float(param.value))
                self.get_logger().info(f'参数热更新 {param.name} -> {float(param.value):.2f}')
        return result

    # ================= Action 回调 =================
    def on_goal(self, goal_request):
        """目标准入：非空、坐标在场内、当前没有别的任务在跑。"""
        if not goal_request.waypoints:
            self.get_logger().warn('拒绝目标：航点列表为空')
            return GoalResponse.REJECT

        for wp in goal_request.waypoints:
            if not (0.0 < wp.x < 11.0 and 0.0 < wp.y < 11.0):
                self.get_logger().warn(f'拒绝目标：航点 ({wp.x:.2f}, {wp.y:.2f}) 超出场地')
                return GoalResponse.REJECT

        if self._active:
            # 简化版「抢占语义」：直接拒绝，避免两条控制循环同时往 cmd_vel 写指令
            self.get_logger().warn('拒绝目标：已有巡逻任务在执行')
            return GoalResponse.REJECT

        self._active = True
        self.get_logger().info(f'接受巡逻任务：{len(goal_request.waypoints)} 个航点')
        return GoalResponse.ACCEPT

    def on_cancel(self, goal_handle):
        """取消准入：一律同意；真正的停车动作在控制循环里做。"""
        self.get_logger().warn('收到取消请求，将在下一控制周期安全停车')
        return CancelResponse.ACCEPT

    def execute_callback(self, goal_handle):
        """巡逻任务主循环：外层遍历航点，内层做「转向 + 直行」。"""
        waypoints = goal_handle.request.waypoints
        result = Patrol.Result()
        result.success = False
        result.waypoints_reached = 0

        try:
            # ---- 0. 等第一帧位姿：Event 由订阅回调 set，2 秒超时，不做 sleep 轮询 ----
            if not self._pose_ready.wait(timeout=2.0):
                self.get_logger().error('2 秒内没收到 /turtle1/pose，检查 turtlesim 是否启动')
                goal_handle.abort()
                return result

            reached = 0   # 已完整到达的航点数
            tick = 0      # 控制周期计数，用来降低反馈频率

            # ---------------- 外层：逐个航点 ----------------
            for index, waypoint in enumerate(waypoints):
                self.get_logger().info(
                    f'前往航点 {index + 1}/{len(waypoints)}：'
                    f'({waypoint.x:.2f}, {waypoint.y:.2f})')

                arrived = False   # 本轮是否用「到达」退出（用于区分节点关闭）

                # ---------------- 内层：单航点的控制循环 ----------------
                while rclpy.ok():
                    # ① 每轮必查取消：发一次零速就返回，海龟立刻停住而不是原地转
                    if goal_handle.is_cancel_requested:
                        self.stop_turtle()
                        goal_handle.canceled()
                        result.success = False
                        result.waypoints_reached = reached
                        self.get_logger().warn(
                            f'任务已取消，安全停车（已到达 {reached} 个航点）')
                        return result

                    pose = self._pose
                    dx = waypoint.x - pose.x
                    dy = waypoint.y - pose.y
                    distance = math.hypot(dx, dy)

                    # ② 到达判定：进入容差圈就算到达，发一条「剩余 0」的反馈
                    if distance <= self.arrival_tolerance:
                        self.stop_turtle()
                        reached = index + 1
                        self.publish_feedback(goal_handle, reached, 0.0)
                        self.get_logger().info(f'到达航点 {reached}/{len(waypoints)}')
                        arrived = True
                        break

                    # ③ 转向 + 直行
                    heading_error = normalize_angle(
                        math.atan2(dy, dx) - pose.theta)

                    cmd = Twist()
                    if abs(heading_error) > self.turn_threshold:
                        # 偏差大：原地转，不前进（避免画弧线切角、跑到航点外侧）
                        cmd.angular.z = self._limit_angular(heading_error)
                    else:
                        # 偏差小：边走边微调；接近目标时按距离减速，防止冲过头来回震荡
                        cmd.linear.x = min(self.linear_speed, max(0.3, distance * 1.2))
                        cmd.angular.z = self._limit_angular(heading_error)

                    self._cmd_pub.publish(cmd)

                    # ④ 每段路上按固定频率上报反馈
                    if tick % self._feedback_every == 0:
                        self.publish_feedback(goal_handle, index + 1, distance)
                    tick += 1

                    # 控制循环节拍：Rate 内部是带超时的事件等待，不是 time.sleep
                    self._rate.sleep()

                if not arrived:
                    # rclpy 正在关闭：不再发速度指令，直接返回失败结果
                    result.waypoints_reached = reached
                    return result

            # ---------------- 全部航点走完 ----------------
            result.waypoints_reached = reached
            if reached == len(waypoints):
                result.success = True
                goal_handle.succeed()
                self.get_logger().info(f'巡逻完成，共到达 {reached} 个航点')
            else:
                goal_handle.abort()
                self.get_logger().warn(f'巡逻中止，仅到达 {reached} 个航点')
            return result

        finally:
            # 无论成功、取消、异常，都释放「任务占用」标记，让下一个目标能进来
            self._active = False

    # ================= 工具方法 =================
    def _limit_angular(self, error: float) -> float:
        """角速度限幅：比例控制 + 上限，防止高速旋转甩尾。"""
        return max(-self.angular_speed, min(self.angular_speed, error * 2.0))

    def publish_feedback(self, goal_handle, current_waypoint: int, remaining_distance: float):
        """构造并发送一条 Feedback。"""
        feedback = Patrol.Feedback()
        feedback.current_waypoint = int(current_waypoint)
        feedback.remaining_distance = float(remaining_distance)
        goal_handle.publish_feedback(feedback)

    def stop_turtle(self):
        """发一次零速 Twist（全零即停车），满足「取消后安全停车」的验收点。"""
        self._cmd_pub.publish(Twist())

def main(args=None):
    rclpy.init(args=args)
    node = PatrolServer()

    # MultiThreadedExecutor 是必须的：execute_callback 会长时间占住一个线程，
    # 单线程执行器下位姿订阅和取消请求都会饿死，海龟就动不起来了
    executor = MultiThreadedExecutor()
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        node.get_logger().info('收到 Ctrl+C，停止巡逻服务')
    finally:
        if rclpy.ok():
            node.stop_turtle()   # 退出前再补一脚刹车
        executor.shutdown()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == '__main__':
    main()