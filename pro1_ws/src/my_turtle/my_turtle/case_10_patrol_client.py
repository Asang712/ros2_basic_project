#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
案例 10：巡逻小车 —— Action Client 节点（patrol_client）

职责：
  1. 启动后自动把默认航点列表打包成 Goal 下发；
  2. 收到每条 Feedback 就打印「前往航点 x/y，剩余 z m」；
  3. Ctrl+C 或超过 timeout_sec 时主动 cancel，等 server 停稳并回结果再退出。

注意点：
  * rclpy 默认的 SIGINT 处理会直接关闭 context，取消请求根本没机会发出去；
    所以这里覆盖 SIGINT，先取消任务，等 Result 回来再 shutdown。
  * 航点参数用「扁平数组」[x1, y1, x2, y2, ...] 表示——
    ROS2 参数只支持基础类型和数组，不能直接声明 geometry_msgs/Point 列表。
"""

import signal

import rclpy
from rclpy.action import ActionClient
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from geometry_msgs.msg import Point

from my_turtle_interfaces.action import Patrol

class PatrolClient(Node):
    """巡逻任务的客户端：下发任务、看进度、按条件取消。"""

    def __init__(self):
        super().__init__('patrol_client')

        # ---------------- 1. 参数：航点列表 + 超时 ----------------
        # 默认航线：一个绕场一周的矩形，全部落在 (0, 11) 的场地内
        self.declare_parameter('waypoints', [1.0, 1.0, 5.0, 1.0, 5.0, 5.0, 9.0, 5.0])
        # 慢速模式走完这条航线约 28 秒，默认超时给 60 秒留足余量
        self.declare_parameter('timeout_sec', 60.0)   # 超过这个时间就主动取消

        flat = [float(v) for v in self.get_parameter('waypoints').value]
        if len(flat) < 2 or len(flat) % 2 != 0:
            raise ValueError('waypoints 必须是偶数个数字：[x1, y1, x2, y2, ...]')
        # 两两配对成 (x, y)
        self._points = [(flat[i], flat[i + 1]) for i in range(0, len(flat), 2)]
        self._timeout_sec = float(self.get_parameter('timeout_sec').value)

        # ---------------- 2. Action Client ----------------
        self._action_client = ActionClient(self, Patrol, 'patrol')
        self._goal_handle = None
        self._timeout_timer = None
        self._finished = False

        # ---------------- 3. 接管 Ctrl+C ----------------
        signal.signal(signal.SIGINT, self.on_sigint)

        self.get_logger().info(
            f'航线共 {len(self._points)} 个航点，超时 {self._timeout_sec:.1f} 秒')

    # ================= 下发任务 =================
    def send_patrol(self):
        """把参数里的航点打包成 Goal 发出去。"""
        goal = Patrol.Goal()
        # Point 是消息对象，需要逐个构造再 append 进数组字段
        goal.waypoints = [Point(x=x, y=y) for x, y in self._points]

        self.get_logger().info('等待 patrol_server 上线...')
        # wait_for_server 带超时：server 没起来时直接报错退出，而不是无限卡住
        if not self._action_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().error('10 秒内没等到 patrol_server，退出（launch 里是否启动了 server？）')
            self._shutdown()
            return

        future = self._action_client.send_goal_async(
            goal, feedback_callback=self.on_feedback)
        future.add_done_callback(self.on_goal_response)

    # ================= 回调 =================
    def on_goal_response(self, future):
        """服务器是否接受目标。"""
        goal_handle = future.result()

        if not goal_handle.accepted:
            self.get_logger().warn('目标被服务器拒绝（航点为空/越界/已有任务在跑）')
            self._finished = True
            self._shutdown()
            return

        self._goal_handle = goal_handle
        self.get_logger().info('任务已被接受，开始巡逻')

        # 拿最终结果（异步，不阻塞）
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.on_result)

        # 启动一次性超时计时器：到点主动取消任务
        if self._timeout_sec > 0.0:
            self._timeout_timer = self.create_timer(
                self._timeout_sec, self.on_timeout)

    def on_feedback(self, feedback_msg):
        """实时进度：验收要求打印成「前往航点 2/4，剩余 1.3 m」这种格式。"""
        fb = feedback_msg.feedback
        self.get_logger().info(
            f'前往航点 {fb.current_waypoint}/{len(self._points)}，'
            f'剩余 {fb.remaining_distance:.2f} m')

    def on_result(self, future):
        """任务结束：打印最终结果并退出。"""
        wrapped = future.result()
        result = wrapped.result

        if result.success:
            self.get_logger().info(
                f'巡逻完成：{result.waypoints_reached}/{len(self._points)} 个航点')
        else:
            self.get_logger().warn(
                f'巡逻未完成（status={wrapped.status}）：'
                f'{result.waypoints_reached}/{len(self._points)} 个航点')

        self._finished = True
        if self._timeout_timer is not None:
            self._timeout_timer.cancel()
        self._shutdown()

    def on_timeout(self):
        """超时：主动取消，等 server 安全停车并回 canceled 结果。"""
        if self._timeout_timer is not None:
            self._timeout_timer.cancel()   # 一次性，触发后立刻关掉
        self.get_logger().warn(
            f'超过 {self._timeout_sec:.1f} 秒仍未完成，主动取消巡逻任务')
        self.cancel_goal()

    # ================= 取消 / 退出 =================
    def cancel_goal(self):
        """发取消请求；真正的停车由 server 负责。"""
        if self._goal_handle is not None and self._goal_handle.accepted:
            self._goal_handle.cancel_goal_async()

    def on_sigint(self, signum, frame):
        """覆盖 rclpy 默认 SIGINT：先取消任务，等结果回来再退出。"""
        if self._finished or self._goal_handle is None:
            self.get_logger().info('收到 Ctrl+C，退出')
            self._shutdown()
            return

        self.get_logger().warn('收到 Ctrl+C，请求取消巡逻任务，等待 server 安全停车...')
        self.cancel_goal()

    def _shutdown(self):
        """统一出口：关闭 rclpy，spin() 会以 ExternalShutdownException 结束。"""
        if rclpy.ok():
            rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    node = PatrolClient()

    try:
        node.send_patrol()
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        # SIGINT 由节点自己处理；context 关闭时 spin 会抛 ExternalShutdownException
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == '__main__':
    main()