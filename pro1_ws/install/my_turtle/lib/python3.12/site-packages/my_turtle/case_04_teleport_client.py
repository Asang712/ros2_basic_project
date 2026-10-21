import rclpy
from rclpy.node import Node
from turtlesim.srv import Spawn
import sys

class SpawnArgClient(Node):
    def __init__(self, x_pos, y_pos):
        super().__init__('spawn_arg_client')
        # 创建spawn客户端
        self.client = self.create_client(Spawn, '/spawn')
        # 等待服务上线
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("等待 /spawn 服务上线...")

        # 构造请求，使用外部传入的坐标
        req = Spawn.Request()
        req.x = x_pos
        req.y = y_pos
        req.theta = 0.0
        req.name = ""   # 空字符串，turtlesim自动分配名字，避免重名

        future = self.client.call_async(req)
        rclpy.spin_until_future_complete(self, future)

        try:
            resp = future.result()
            self.get_logger().info(f"✅生成海龟成功！name={resp.name} x={x_pos} y={y_pos}")
        except Exception as e:
            self.get_logger().error(f"❌调用失败:{e}")


def main(args=None):
    rclpy.init(args=args)
    # sys.argv[0]是程序本身；argv[1]第一个参数，argv[2]第二个参数
    if len(sys.argv) >=3:
        input_x = float(sys.argv[1])
        input_y = float(sys.argv[2])
    else:
        # 没有传参，使用默认值
        input_x = 5.5
        input_y = 5.5
        print("未输入坐标参数，使用默认 x=5.5 y=5.5")

    node = SpawnArgClient(input_x, input_y)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
