import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


class CircleDriver(Node):
    def __init__(self):
        super().__init__('circle_driver')
        # 创建发布者
        self.publisher_ = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        # 定时器，0.1秒周期
        timer_period = 1.0
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = Twist()
        msg.linear.x = 2.0
        msg.angular.z = -1.0
        self.publisher_.publish(msg)
        self.get_logger().info("画圆节点已启动，正在发布速度指令...")


def main(args=None):
    rclpy.init(args=args)
    node = CircleDriver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
