# ros2_basic_project
ROS2 Python基础通信实战项目，基于`turtlesim`海龟仿真实现。
包含话题、服务、Action、参数系统、rosbag、Launch文件全套案例，配套海龟画圆、键盘控制、巡逻小车考核项目。

## 📦 环境要求
- ROS2 Humble（推荐）
- Python3
- 系统：Ubuntu 22.04

## 📚 项目案例清单
1. Publisher — 海龟画圆
2. Subscriber — 监听海龟实时位姿
3. 状态机控制海龟画正方形
4. Service Client — 调用spawn生成新海龟
5. Service Server — 接收目标坐标导航海龟
6. 键盘实时控制海龟运动
7. 参数化节点 + Launch文件
8. Action通信 — 带进度反馈、可取消导航任务
9. rosbag录制与回放，复现海龟运动轨迹
10. 考核项目：巡逻小车

## 🚀 快速使用
### 1. 构建工作空间
```bash
colcon build --packages-select 你的包名
source install/setup.bash
```

### 2. 运行示例（以海龟画圆为例）
```bash
ros2 run 包名 publisher_node
```

### 3. Launch启动多节点
```bash
ros2 launch 包名 demo.launch.py
```

## 📂 目录结构
```
ros2_basic_project/
├── src/                # ROS2功能包源码
│   ├── my_turtle_pkg/
│   │   ├── my_turtle_pkg/    # Python节点代码
│   │   ├── launch/           # launch启动文件
│   │   ├── package.xml
│   │   └── setup.py
├── README.md
└── .gitignore
```

## 💡 备注
- 所有节点使用Python实现
- 项目从turtlesim仿真起步，后续可迁移至真实机器人
- 附录：ROS2常见报错排查

## 📜 License
MIT
```

## 可选精简版本（如果你不想写太长）
```markdown
# ros2_basic_project
ROS2 Python入门实战项目，基于turtlesim海龟仿真。
覆盖 ROS2 四大核心通信：Topic / Service / Action / Parameter，包含rosbag、Launch多节点管理，配套10个课程案例，最终完成巡逻小车考核项目。

## 环境
ROS2 Humble | Ubuntu22.04

## 案例列表
- Publisher：海龟画圆
- Subscriber：监听海龟位姿
- 状态机绘制正方形
- Service 服务客户端/服务端
- 键盘控制海龟
- 参数+Launch文件
- Action带反馈导航
- rosbag 数据录制回放
- 综合项目：巡逻小车

## 运行
```bash
colcon build
source install/setup.bash
ros2 run 包名 节点名
```
```

---

## 🎬 OpenCV 项目：视频镜头运动分析器（`OpenCV_ws/`）

读取本地视频或 USB 摄像头实时流，使用 Shi-Tomasi 角点检测 + Lucas-Kanade 稀疏光流计算帧间运动向量，
判断镜头运动状态（静止 / 横向移动 / 纵向移动 / 抖动），画面叠加特征点、运动箭头与状态 HUD，
输出 CSV 运动日志，并支持简易防抖预览、自动标记剧烈抖动片段。

```bash
pip install -r OpenCV_ws/requirements.txt
python3 OpenCV_ws/video_motion_analyzer.py --source 视频.mp4         # 本地视频
python3 OpenCV_ws/video_motion_analyzer.py --source 0 --stabilize    # USB 摄像头
```

详见 [OpenCV_ws/README.md](OpenCV_ws/README.md)。
