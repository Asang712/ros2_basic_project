import math
import time

import rclpy
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose

from my_turtle_interfaces.action import Navigate


class NavigateActionServer(Node):

    def __init__(self):
        super().__init__('navigate_action_server')
        self.pose = None
        self.pose_sub = self.create_subscription(
            Pose, '/turtle1/pose', self.pose_callback, 10)
        self.cmd_pub = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)

        self._action_server = ActionServer(
            self,
            Navigate,
            'navigate',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            callback_group=ReentrantCallbackGroup()
        )
        self.get_logger().info('Navigate Action Server 已启动')

    def pose_callback(self, msg):
        self.pose = msg

    def goal_callback(self, goal_request):
        if 0.0 < goal_request.x < 11.0 and 0.0 < goal_request.y < 11.0:
            self.get_logger().info(f'接受目标: ({goal_request.x}, {goal_request.y})')
            return GoalResponse.ACCEPT
        self.get_logger().warn(f'拒绝目标: ({goal_request.x}, {goal_request.y})')
        return GoalResponse.REJECT

    def cancel_callback(self, goal_handle):
        self.get_logger().info('收到取消请求')
        return CancelResponse.ACCEPT

    def stop_turtle(self):
        self.cmd_pub.publish(Twist())

    def execute_callback(self, goal_handle):
        self.get_logger().info('开始执行导航任务...')
        
        # ★ 记录任务开始时间
        start_time = time.time()
        
        goal = goal_handle.request
        feedback = Navigate.Feedback()
        result = Navigate.Result()

        # 等待第一条位姿数据（2秒超时）
        start_wait = time.time()
        while self.pose is None and time.time() - start_wait < 2.0:
            time.sleep(0.05)
        if self.pose is None:
            self.get_logger().error('未收到位姿数据，任务中止')
            goal_handle.abort()
            result.success = False
            result.traveled_distance = 0.0
            # ★ 记录耗时
            result.duration = time.time() - start_time
            return result

        start_x = self.pose.x
        start_y = self.pose.y
        traveled = 0.0
        prev_x, prev_y = start_x, start_y

        while rclpy.ok():
            # ① 取消检查（每轮必查）
            if goal_handle.is_cancel_requested:
                self.stop_turtle()
                goal_handle.canceled()
                result.success = False
                result.traveled_distance = traveled
                # ★ 记录耗时
                result.duration = time.time() - start_time
                self.get_logger().info('任务已取消')
                return result

            if self.pose is None:
                time.sleep(0.05)
                continue

            dx = goal.x - self.pose.x
            dy = goal.y - self.pose.y
            dist = math.hypot(dx, dy)
            heading_error = math.atan2(dy, dx) - self.pose.theta
            heading_error = math.atan2(math.sin(heading_error), math.cos(heading_error))

            # ② 到达判定（距离小于 0.05）
            if dist < 0.05:
                self.stop_turtle()
                goal_handle.succeed()
                result.success = True
                result.traveled_distance = traveled
                # ★ 记录耗时
                result.duration = time.time() - start_time
                self.get_logger().info(
                    f'导航成功，总路程 {traveled:.2f}，耗时 {result.duration:.2f} 秒')
                return result

            # ③ 运动控制
            cmd = Twist()
            cmd.linear.x = min(2.0, dist * 1.5)
            cmd.angular.z = heading_error * 2.0
            self.cmd_pub.publish(cmd)

            # 累计路程
            step = math.hypot(self.pose.x - prev_x, self.pose.y - prev_y)
            traveled += step
            prev_x, prev_y = self.pose.x, self.pose.y

            # ④ 发布反馈
            feedback.remaining_distance = dist
            feedback.heading_error = heading_error
            feedback.heading = self.pose.theta
            goal_handle.publish_feedback(feedback)

            time.sleep(0.1)

        # 节点关闭（异常中止）
        self.stop_turtle()
        goal_handle.abort()
        result.success = False
        result.traveled_distance = traveled
        # ★ 记录耗时
        result.duration = time.time() - start_time
        return result


def main(args=None):
    rclpy.init(args=args)
    node = NavigateActionServer()
    executor = MultiThreadedExecutor()
    rclpy.spin(node, executor=executor)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()