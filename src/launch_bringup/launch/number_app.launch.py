from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():

    param_config = os.path.join(get_package_share_directory("launch_bringup"),
                                "config", "number_app.yaml")

    number_publisher = Node(
        package="my_cpp_pkg",
        executable="number_publisher",
        namespace="/xyz",
        name="my_number_publisher",
        remappings=[("number", "my_number")],
        # parameters=[
        #     {"number": 12},
        #     {"timer_period": 1.3}
        # ]
        parameters=[param_config]
    )

    minimal_publisher = Node(
        package="my_cpp_pkg",
        executable="minimal_publisher",
        name="my_node_publisher",
        remappings=[("topic", "my_topic")]
    )

    return LaunchDescription([
        number_publisher,
        minimal_publisher
    ])