#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
案例 10：一键启动巡逻系统。

用法：
    ros2 launch my_turtle patrol.launch.py                 # 默认慢速模式
    ros2 launch my_turtle patrol.launch.py mode:=fast      # 快速模式
    ros2 launch my_turtle patrol.launch.py mode:=fast timeout_sec:=20.0

为什么用 OpaqueFunction：
  Launch 的 substitution 只能在运行时求值，而「根据 mode 选一整套参数」
  需要在生成 Node 之前就算出具体数值，OpaqueFunction 提供的正是这个时机。
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

# 两套速度预设：验收时切换 mode 就能肉眼看出快慢差异
SPEED_PRESETS = {
    'slow': {'linear_speed': 1.0, 'angular_speed': 1.5},
    'fast': {'linear_speed': 3.0, 'angular_speed': 4.0},
}

def spawn_nodes(context, *args, **kwargs):
    """按 mode 决定速度参数，并返回三个节点。"""
    mode = LaunchConfiguration('mode').perform(context).lower()
    if mode not in SPEED_PRESETS:
        raise RuntimeError(
            f"未知 mode='{mode}'，可选值：{', '.join(SPEED_PRESETS)}")

    speeds = SPEED_PRESETS[mode]
    timeout_sec = float(LaunchConfiguration('timeout_sec').perform(context))

    return [
        # 1. 海龟仿真器：提供 /turtle1/pose 和 /turtle1/cmd_vel
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='turtlesim',
            output='screen',
        ),
        # 2. 巡逻服务端：速度参数从 launch 注入（覆盖代码里的默认值）
        Node(
            package='my_turtle',
            executable='patrol_server',
            name='patrol_server',
            parameters=[speeds],
            output='screen',
        ),
        # 3. 巡逻客户端：自动下发默认航线，超时时间可由 launch 覆盖
        Node(
            package='my_turtle',
            executable='patrol_client',
            name='patrol_client',
            parameters=[{'timeout_sec': timeout_sec}],
            output='screen',
        ),
    ]

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'mode', default_value='slow',
            description='速度模式：slow（慢速演示）或 fast（快速演示）'),
        DeclareLaunchArgument(
            'timeout_sec', default_value='60.0',
            description='client 主动取消任务的超时时间（秒），慢速跑完约 28 秒'),
        OpaqueFunction(function=spawn_nodes),
    ])