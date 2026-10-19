import rclpy
from rclpy.node import Node
from turtlesim.srv import Spawn
import time


class LoopSpawnClient(Node):
    def __init__(self):
        super().__init__('loop_spawn_client')
        # 创建spawn服务客户端
        self.client = self.create_client(Spawn, '/spawn')
        # 等待服务上线
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('等待 /spawn 服务(turtlesim)启动...')
        self.get_logger().info("✅服务就绪，开始每2秒生成海龟！")

    def send_spawn_request(self):
        # 构造请求，name="" 让turtlesim自动分配唯一名字，不会重名
        req = Spawn.Request()
        req.x = 3.0
        req.y = 1.0
        req.theta = 0.0
        req.name = ""

        future = self.client.call_async(req)
        # 同步等待本次请求完成（简单场景适合）
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            self.get_logger().info(f"🐢成功生成海龟: {future.result().name}")
        else:
            self.get_logger().error("❌生成海龟失败")


def main(args=None):
    rclpy.init(args=args)
    node = LoopSpawnClient()

    # 你的循环：while rclpy.ok(): send_request(); sleep(2)
    while rclpy.ok():
        node.send_spawn_request()
        time.sleep(2)  # 等待2秒，再生成下一只

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
