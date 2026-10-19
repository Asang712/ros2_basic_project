import rclpy
from rclpy.node import Node
from turtlesim.srv import Spawn  # 导入spawn服务类型


class SpawnClient(Node):
    def __init__(self):
        super().__init__('spawn_client')
        # 1.创建服务客户端：服务类型Spawn，服务名字/spawn
        self.client = self.create_client(Spawn, '/spawn')

        # 2.防御等待：循环等待/spawn服务上线
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('等待 /spawn 服务上线...')

        # 3.构造请求数据
        self.req = Spawn.Request()
        self.req.x = 3.0
        self.req.y = 3.0
        self.req.theta = 0.0
        self.req.name = "turtle2"

        # 4.异步发起服务调用，得到future对象
        self.future = self.client.call_async(self.req)
        # 注册回调：服务返回结果自动执行response_callback
        self.future.add_done_callback(self.response_callback)

    def response_callback(self, future):
        """服务收到响应之后自动执行的回调函数"""
        try:
            # 从future取出服务返回的response响应
            resp = future.result()
            self.get_logger().info(f"✅生成海龟成功！返回名字：{resp.name}")
        except Exception as e:
            self.get_logger().error(f"❌服务调用失败: {e}")


def main(args=None):
    rclpy.init(args=args)
    node = SpawnClient()
    rclpy.spin(node)   # 保持节点运行，等待服务响应回调触发
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
