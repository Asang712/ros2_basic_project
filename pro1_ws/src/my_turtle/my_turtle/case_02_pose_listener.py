import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose


class PoseListener(Node):
    def __init__(self):
        super().__init__('pose_listener')
        # 计数器，用来节流打印
        self.count = 0
        # 创建订阅者
        self.subscription = self.create_subscription(
            Pose,
            '/turtle1/pose',
            self.pose_callback,
            10
        )
        # 上次打印时间
        self.last_print_time = self.get_clock().now()

    def pose_callback(self, msg):
        """
        # 收到位姿消息自动执行这个回调
        self.count += 1
        if self.count % 10 == 0:
            self.get_logger().info(
                f"第{self.count}条消息: x={msg.x:.2f}, y={msg.y:.2f}, theta={msg.theta:.2f}, "
                f"线速度={msg.linear_velocity:.2f}, 角速度={msg.angular_velocity:.2f}"
            )
        """
        # 节流打印
        current_time = self.get_clock().now()
        self.count += 1
        if (current_time - self.last_print_time).nanoseconds > 1000000000:
            self.get_logger().info(
                f"第{self.count}条消息: x={msg.x:.2f}, y={msg.y:.2f}, theta={msg.theta:.2f}, "
                f"线速度={msg.linear_velocity:.2f}, 角速度={msg.angular_velocity:.2f}"
            )
            self.last_print_time = current_time


def main(args=None):
    rclpy.init(args=args)
    node = PoseListener()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
