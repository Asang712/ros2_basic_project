import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import math

# --------常量定义（魔法数字全部放顶部，方便调参）--------
TIMER_PERIOD = 0.1       # 定时器周期 0.1s，10Hz
GO_SPEED = 2.0           # 直行线速度 m/s
GO_CYCLES = 20           # 直行持续20个周期 → 2秒
TURN_SPEED = math.pi / 2 # 转弯角速度 rad/s (90°每秒)
TURN_CYCLES = 10         # 转弯持续10个周期 →1秒
MAX_EDGE = 4             # 一共画4条边


class SquareDriver(Node):
    def __init__(self):
        super().__init__('square_driver')
        # 创建发布者，向 /turtle1/cmd_vel 发布Twist速度消息
        self.publisher_ = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        # 创建定时器
        self.timer = self.create_timer(TIMER_PERIOD, self.timer_callback)

        # 状态机变量
        self.state = "GO"       # 两种状态：GO / TURN
        self.cycles = 0         # 当前状态已经运行的定时器次数
        self.edge = 0           # 已经完成的边数量

        self.get_logger().info("画正方形节点已启动！")

    def timer_callback(self):
        msg = Twist()

        if self.state == "GO":
            # 直行状态
            msg.linear.x = GO_SPEED
            msg.angular.z = 0.0
            self.cycles += 1

            # 判断直行时间是否到达阈值
            if self.cycles >= GO_CYCLES:
                self.state = "TURN"
                self.cycles = 0
                self.edge += 1
                self.get_logger().info(f"第 {self.edge} 条边画完，开始转弯...")

        elif self.state == "TURN":
            # 原地转弯状态
            msg.linear.x = 0.0
            msg.angular.z = TURN_SPEED
            self.cycles += 1

            # 判断转弯时间到达阈值
            if self.cycles >= TURN_CYCLES:
                self.state = "GO"
                self.cycles = 0

        # 判断是否画完全部4条边
        if self.edge >= MAX_EDGE:
            self.timer.cancel()  # 关闭定时器，不再触发回调
            msg.linear.x = 0.0
            msg.angular.z = 0.0
            self.get_logger().info("正方形画完了!停止运动。")

        self.publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = SquareDriver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
