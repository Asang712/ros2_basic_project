from setuptools import find_packages, setup
from glob import glob

package_name = 'my_turtle'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.py')),

    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='asang',
    maintainer_email='asang@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'circle_driver = my_turtle.case_01_circle_driver:main',
            'pose_listener = my_turtle.case_02_pose_listener:main',
            'square_driver = my_turtle.case_03_square_driver:main',
            'square_driver_02 = my_turtle.case_03_02_square_driver:main',
            'spawn_client = my_turtle.case_04_spawn_cilent:main',
            'loop_spawn_client = my_turtle.case_04_loop_spawn:main',
            'teleport_client = my_turtle.case_04_teleport_client:main',
            'teleport_server = my_turtle.case_05_teleport_server:main',
            'keyboard_teleop = my_turtle.case_06_keyboard_teleop:main',
            'param_circle_driver = my_turtle.case_07_param_circle_driver:main',
            'navigate_action_server = my_turtle.case_08_navigate_action_server:main',
            'navigate_action_client = my_turtle.case_08_navigate_action_client:main',
        ],
    },
)
