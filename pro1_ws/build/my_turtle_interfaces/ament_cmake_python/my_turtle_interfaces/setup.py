from setuptools import find_packages
from setuptools import setup

setup(
    name='my_turtle_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('my_turtle_interfaces', 'my_turtle_interfaces.*')),
)
