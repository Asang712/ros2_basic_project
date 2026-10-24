import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


class ParamCircleDriver(Node):
    def __init__(self):
        super().__init__('param_circle_driver')

        # 1. 声明参数 + 默认值
        self.declare_parameter("linear_speed", 2.0)
        self.declare_parameter("angular_speed", 1.57)
        self.declare_parameter("timer_period", 0.1)

        # 2. 初始化读取参数
        self.linear_speed = self.get_parameter("linear_speed").value
        self.angular_speed = self.get_parameter("angular_speed").value
        self.timer_period = self.get_parameter("timer_period").value

        self.get_logger().info(f"✅初始参数加载完成：")
        self.print_current_param()

        # 3. 创建发布者
        self.publisher_ = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        # 定时器（注意：定时器周期热更新这里先不处理，后面说明原因）
        self.timer = self.create_timer(self.timer_period, self.timer_callback)

        # ========== 注册参数变更回调（核心新增） ==========
        self.add_on_set_parameters_callback(self.param_callback)


    def param_callback(self, params):
        """
        参数热更新回调函数
        params：是本次被修改的参数列表
        返回值：SetParametersResult(successful=True/False)
        """
        from rclpy.parameter import Parameter
        result = rclpy.node.SetParametersResult()
        result.successful = True

        for param in params:
            if param.name == "linear_speed":
                self.linear_speed = param.value
                self.get_logger().info(f"🔄更新 linear_speed → {self.linear_speed}")
            elif param.name == "angular_speed":
                self.angular_speed = param.value
                self.get_logger().info(f"🔄更新 angular_speed → {self.angular_speed}")
            elif param.name == "timer_period":
                self.timer_period = param.value
                self.get_logger().info(f"🔄更新 timer_period → {self.timer_period}")
                # ⚠️重点：原来的定时器不会自动变周期！
                # 如果想要定时器周期也热生效，需要销毁旧timer、新建timer
                self.timer.destroy()
                self.timer = self.create_timer(self.timer_period, self.timer_callback)

        self.get_logger().info(f"📌更新后半径 R ≈ {self.linear_speed / self.angular_speed:.2f}")
        return result


    def timer_callback(self):
        twist_msg = Twist()
        twist_msg.linear.x = self.linear_speed
        twist_msg.angular.z = self.angular_speed
        self.publisher_.publish(twist_msg)


    def print_current_param(self):
        self.get_logger().info(f"linear_speed = {self.linear_speed}")
        self.get_logger().info(f"angular_speed = {self.angular_speed}")
        self.get_logger().info(f"timer_period = {self.timer_period}")
        self.get_logger().info(f"估算半径 R ≈ {self.linear_speed / self.angular_speed:.2f}")


def main(args=None):
    rclpy.init(args=args)
    node = ParamCircleDriver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
