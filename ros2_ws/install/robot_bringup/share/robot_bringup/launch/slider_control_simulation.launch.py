import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("robot_description"),
                "launch",
                "gazebo.launch.py"
            )
        )
    )
    
    controller = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("robot_controller"),
                "launch",
                "slider_controller.launch.py"
            )
        )
    )
    
    moveit = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("robot_moveit"),
                "launch",
                "moveit.launch.py"
            )
        )
    )
    
    return LaunchDescription([
        gazebo,
        controller,
        moveit,
    ])