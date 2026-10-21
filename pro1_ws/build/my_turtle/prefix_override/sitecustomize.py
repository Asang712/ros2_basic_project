import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/asang/ros2_project/pro1_ws/install/my_turtle'
