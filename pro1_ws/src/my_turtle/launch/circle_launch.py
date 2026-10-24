from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # 启动海龟仿真器节点
        Node(
            package="turtlesim",
            executable="turtlesim_node",
            name="turtlesim",
            output="screen"
        ),
        # 启动参数化画圆节点，传入自定义参数，并重命名节点
        Node(
            package="my_turtle",
            executable="param_circle_driver",
            name="circle_fast",   # 重新命名节点
            parameters=[{
                "linear_speed": 3.0,
                "angular_speed": 2.0,
                "timer_period": 0.1
            }],
            output="screen"
        )
    ])
