from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from moveit_configs_utils import MoveItConfigsBuilder
import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node


def generate_launch_description():
        
    moveit_config = (
        MoveItConfigsBuilder("manipulator", package_name="robot_moveit")
        .robot_description(file_path=os.path.join(
            get_package_share_directory('robot_description'), 'urdf', 'manipulator.urdf'))
        .robot_description_semantic(file_path="config/manipulator.srdf")
        .trajectory_execution(file_path="config/moveit_controllers.yaml")
        .to_moveit_configs()
    )
    
    move_group_node = Node(
        package='moveit_ros_move_group',
        executable='move_group',
        name='move_group',
        output='screen',
        parameters=[
            moveit_config.to_dict(),
            {"use_sim_time": True},
            {"publish_robot_description_semantic": True}
        ],
        arguments=["--ros-args", "--log-level", "info"]
    )
    
    rviz_config_file = os.path.join(get_package_share_directory('robot_moveit'), 'config', 'moveit.rviz')
    
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config_file],
        parameters=[moveit_config.robot_description,
                    moveit_config.robot_description_semantic,
                    moveit_config.robot_description_kinematics,
                    moveit_config.joint_limits]
    )
    
    return LaunchDescription([
        move_group_node,
        rviz_node
    ])