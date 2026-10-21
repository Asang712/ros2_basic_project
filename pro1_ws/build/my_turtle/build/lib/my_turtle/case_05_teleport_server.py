import rclpy
from rclpy.node import Node
from rclpy.callback_groups import ReentrantCallbackGroup
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from turtlesim.srv import TeleportAbsolute
# 导入我们自己写的自定义服务接口
from my_turtle_interfaces.srv import NavigateTo, TeleportTo
import math


class NavigateServer(Node):
    def __init__(self):
        super().__init__('navigate_server')
        self.cb_group = ReentrantCallbackGroup()

        # ==========角色1：订阅者，获取海龟位姿==========
        self.sub_pose = self.create_subscription(
            Pose,
            '/turtle1/pose',
            self.pose_callback,
            10,
            callback_group=self.cb_group
        )

        # ==========角色2：发布者，输出速度指令==========
        self.pub_cmd_vel = self.create_publisher(
            Twist,
            '/turtle1/cmd_vel',
            10
        )

        # ==========角色3：Service Server 导航服务 /navigate_to ==========
        self.srv_navigate = self.create_service(
            NavigateTo,
            '/navigate_to',
            self.handle_navigate,
            callback_group=self.cb_group
        )

        # ==========角色4：Service Server 瞬移服务 /teleport_to ==========
        self.srv_teleport = self.create_service(
            TeleportTo,
            '/teleport_to',
            self.handle_teleport,
            callback_group=self.cb_group
        )

        # ==========角色5：Service Client，调用turtlesim瞬移==========
        self.client_teleport = self.create_client(
            TeleportAbsolute,
            '/turtle1/teleport_absolute'
        )
        while not self.client_teleport.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("等待 /turtle1/teleport_absolute 服务上线...")

        # 定时器，10Hz执行导航状态机
        self.timer = self.create_timer(0.1, self.timer_callback, callback_group=self.cb_group)

        # 状态变量
        self.pose = None               # 保存海龟当前位姿
        self.target_x = None
        self.target_y = None
        self.moving = False            # 是否正在导航运动
        self.arrival_threshold = 0.05   # 到达距离阈值

        self.get_logger().info("✅导航服务端已就绪！")

    def stop(self):
        """停止海龟运动"""
        msg = Twist()
        msg.linear.x = 0.0
        msg.angular.z = 0.0
        self.pub_cmd_vel.publish(msg)
        self.moving = False
        self.get_logger().info(f"✅已到达目标点 ({self.target_x:.2f}, {self.target_y:.2f})")

    # ---------------- 导航服务回调 /navigate_to ----------------
    def handle_navigate(self, request, response):
        """服务回调：只设置目标，不做运动，立刻返回success"""
        self.target_x = request.x
        self.target_y = request.y
        self.moving = True
        self.get_logger().info(f"📩收到【导航】请求：目标({self.target_x:.2f}, {self.target_y:.2f})")
        response.success = True
        return response

    # ---------------- 瞬移服务回调 /teleport_to ----------------
    def handle_teleport(self, request, response):
        """链式调用：本服务作为client去调用turtlesim瞬移，纯异步，禁止嵌套spin"""
        req = TeleportAbsolute.Request()
        req.x = request.x
        req.y = request.y
        req.theta = request.theta

        # 保存response对象，给回调里面使用
        self.teleport_response = response

        def teleport_done_callback(self, fut):
            # 瞬移子服务完成之后执行
            res = fut.result()
            self.get_logger().info(f"✅瞬移至 ({request.x:.2f}, {request.y:.2f})")
            self.teleport_response.success = True

        future = self.client_teleport.call_async(req)
        future.add_done_callback(teleport_done_callback)

        # 立刻返回！客户端马上收到response，不会卡住
        response.success = True
        return response

    # ---------------- 位姿订阅回调 ----------------
    def pose_callback(self, msg):
        self.pose = msg
        # 订阅回调也做一次到达判定（双保险，62Hz高频）
        if (not self.moving) or (self.ta-rget_x is None):
            return
        dx = self.target_x - self.pose.x
        dy = self.target_y - self.pose.y
        dist = math.hypot(dx, dy)
        if dist < self.arrival_threshold:
            self.stop()

    # ---------------- 定时器回调：导航状态机核心 10Hz ----------------
    def timer_callback(self):
        if (not self.moving) or (self.pose is None) or (self.target_x is None):
            return

        dx = self.target_x - self.pose.x
        dy = self.target_y - self.pose.y
        dist = math.hypot(dx, dy)

        if dist < self.arrival_threshold:
            self.stop()
            return

        # 计算期望朝向
        target_angle = math.atan2(dy, dx)
        angle_diff = target_angle - self.pose.theta

        # =====角度归一化 [-pi, pi]=====
        while angle_diff > math.pi:
            angle_diff -= 2 * math.pi
        while angle_diff < -math.pi:
            angle_diff += 2 * math.pi

        twist_msg = Twist()
        if abs(angle_diff) > 0.1:
            # 角度偏差大：原地旋转对准
            twist_msg.angular.z = 1.5 if angle_diff > 0 else -1.5
        else:
            # 对准之后前进，同时小角度修正方向
            twist_msg.linear.x = 1.5
            twist_msg.angular.z = angle_diff * 0.5

        self.pub_cmd_vel.publish(twist_msg)


def main(args=None):
    rclpy.init(args=args)
    node = NavigateServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
