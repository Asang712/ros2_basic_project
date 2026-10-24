import sys
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from my_turtle_interfaces.action import Navigate


class NavigateActionClient(Node):

    def __init__(self):
        super().__init__('navigate_action_client')
        self._action_client = ActionClient(self, Navigate, 'navigate')
        self._goal_handle = None
        self._cancel_timer = None

    def send_goal(self, x, y, cancel_after=None):
        self.get_logger().info(f'发送导航目标: ({x:.2f}, {y:.2f})')
        goal_msg = Navigate.Goal()
        goal_msg.x = x
        goal_msg.y = y

        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

        if cancel_after is not None:
            self._cancel_timer = self.create_timer(
                cancel_after, self.cancel_goal)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn('目标被拒绝 (REJECT)')
            return
        self.get_logger().info('目标已被接受，开始执行')
        self._goal_handle = goal_handle

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback_msg):
        fb = feedback_msg.feedback
        self.get_logger().info(
            f'剩余 {fb.remaining_distance:.2f} m, 朝向偏差 {fb.heading_error:+.2f} rad, 当前朝向 {fb.heading:+.2f} rad')

    def get_result_callback(self, future):
        result = future.result().result
        if result.success:
            self.get_logger().info(
                f'导航成功完成，总路程 {result.traveled_distance:.2f}，耗时 {result.duration:.2f} 秒')
        else:
            self.get_logger().warn(
                f'导航未完成 (被取消/中止)，已走 {result.traveled_distance:.2f}，耗时 {result.duration:.2f} 秒')
        if self._cancel_timer is not None:
            self._cancel_timer.cancel()

    def cancel_goal(self):
        if self._goal_handle is not None:
            self.get_logger().info('主动取消导航目标!')
            self._goal_handle.cancel_goal_async()
            if self._cancel_timer is not None:
                self._cancel_timer.cancel()


def main(args=None):
    rclpy.init(args=args)
    node = NavigateActionClient()

    # 解析命令行参数: x y [cancel] [seconds]
    argv = sys.argv[1:]
    x = float(argv[0]) if len(argv) > 0 else 8.0
    y = float(argv[1]) if len(argv) > 1 else 8.0
    cancel_after = None
    if len(argv) > 3 and argv[2].lower() == 'cancel':
        cancel_after = float(argv[3])

    node.send_goal(x, y, cancel_after)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()