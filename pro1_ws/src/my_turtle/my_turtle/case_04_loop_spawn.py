import rclpy
from rclpy.node import Node
from turtlesim.srv import Spawn
import time


class LoopSpawnClient(Node):
    def __init__(self):
        super().__init__('loop_spawn_client')
        self.client = self.create_client(Spawn, '/spawn')
        # 记录下一次生成的x坐标，初始3.0，每次+1
        self.next_x = 3.0

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('等待 /spawn 服务(turtlesim)启动...')
        self.get_logger().info("✅服务就绪，开始每2秒生成海龟！")

    def send_spawn_request(self):
        req = Spawn.Request()
        req.x = self.next_x   # 使用不断增加的x
        req.y = 1.0
        req.theta = 0.0
        req.name = ""  # 留空自动分配名字，避免重名

        future = self.client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            self.get_logger().info(f"🐢成功生成海龟:{future.result().name}  x={self.next_x}")
            # 坐标+1，下一只往右偏移，避免重叠
            self.next_x += 1.0
        else:
            self.get_logger().error("❌生成海龟失败")


def main(args=None):
    rclpy.init(args=args)
    node = LoopSpawnClient()

    while rclpy.ok():
        node.send_spawn_request()
        time.sleep(2)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
