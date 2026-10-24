import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import threading
import termios
import sys


class KeyboardTeleop(Node):
    def __init__(self):
        super().__init__('keyboard_teleop')
        self.publisher_ = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)

        # 共享速度
        self.linear_x = 0.0
        self.angular_z = 0.0
        # =========新增：速度档位系数，默认2档 1.0=========
        self.speed_scale = 1.0

        self.timer = self.create_timer(0.1, self.timer_callback)

    def timer_callback(self):
        twist_msg = Twist()
        twist_msg.linear.x = self.linear_x * self.speed_scale
        twist_msg.angular.z = self.angular_z * self.speed_scale
        self.publisher_.publish(twist_msg)

    def update_velocity(self, linear: float, angular: float):
        """子线程调用，更新基础速度（尚未乘档位）"""
        self.linear_x = linear
        self.angular_z = angular

    def set_speed_scale(self, scale: float):
        """设置速度档位系数，供键盘线程调用"""
        self.speed_scale = scale
        self.get_logger().info(f"⚙切换速度档位，倍率 = {self.speed_scale}")


def keyboard_listener(node: KeyboardTeleop):
    print("=" * 60)
    print("📮键盘遥操作【无回车版本+速度档位】")
    print("W — 前进 | S — 后退")
    print("A — 左转 | D — 右转")
    print("空格 — 急停")
    print("1：慢档(×0.5)   2：标准档(×1.0)   3：快档(×1.5)")
    print("Q — 退出程序")
    print("=" * 60)

    fd = sys.stdin.fileno()
    old_setting = termios.tcgetattr(fd)
    new_setting = termios.tcgetattr(fd)
    # 关闭行缓冲、关闭回显
    new_setting[3] &= ~(termios.ICANON | termios.ECHO)

    try:
        termios.tcsetattr(fd, termios.TCSANOW, new_setting)
        while rclpy.ok():
            key = sys.stdin.read(1).upper()

            if key == 'Q':
                break
            elif key == 'W':
                node.update_velocity(2.0, 0.0)
            elif key == 'S':
                node.update_velocity(-2.0, 0.0)
            elif key == 'A':
                node.update_velocity(0.0, 2.0)
            elif key == 'D':
                node.update_velocity(0.0, -2.0)
            elif key == ' ':
                node.update_velocity(0.0, 0.0)
                print("\n🛑急停！海龟停止")
            # ======== 新增档位按键处理 ========
            elif key == '1':
                node.set_speed_scale(0.5)
            elif key == '2':
                node.set_speed_scale(1.0)
            elif key == '3':
                node.set_speed_scale(1.5)

    finally:
        # 重要：恢复终端原始配置，防止终端坏掉
        termios.tcsetattr(fd, termios.TCSANOW, old_setting)

    # 退出前停止海龟
    node.update_velocity(0.0, 0.0)
    rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    node = KeyboardTeleop()

    key_thread = threading.Thread(
        target=keyboard_listener,
        args=(node,),
        daemon=True
    )
    key_thread.start()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
