import rclpy
from rclpy.node import Node
from turtlesim.srv import TeleportAbsolute


class TeleportClient(Node):
    def __init__(self):
        super().__init__('teleport_client')
        # 创建客户端，目标服务 /turtle1/teleport_absolute
        self.client = self.create_client(TeleportAbsolute, '/turtle1/teleport_absolute')

        # 防御等待服务上线
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("等待 /turtle1/teleport_absolute 服务上线...")

        # 构造瞬移请求参数
        req = TeleportAbsolute.Request()
        req.x = 7.0      # 目标x坐标
        req.y = 7.0      # 目标y坐标
        req.theta = 3.14 # 朝向，π弧度，面朝向左

        # 异步发起调用
        future = self.client.call_async(req)
        # 等待服务执行完成
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None:
            self.get_logger().info(f"✅turtle1瞬移完成，目标位置 x={req.x},y={req.y}")
        else:
            self.get_logger().error("❌瞬移调用失败！")


def main(args=None):
    rclpy.init(args=args)
    node = TeleportClient()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
