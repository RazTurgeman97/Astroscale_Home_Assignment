#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint


class SliderControl(Node):

    def __init__(self):
        super().__init__("slider_control")
        self.arm_pub_ = self.create_publisher(JointTrajectory, "arm_controller/joint_trajectory", 10)
        self.sub_ = self.create_subscription(JointState, "joint_commands", self.sliderCallback, 10)
        self.last_positions = None
        self.get_logger().info("Slider Control Node started")

    def sliderCallback(self, msg):
        arm_controller = JointTrajectory()
        arm_controller.joint_names = ["joint1", "joint2"]

        arm_goal = JointTrajectoryPoint()
        arm_goal.positions = msg.position[:2]

        if self.last_positions != arm_goal.positions:
            self.get_logger().info(f"Publishing trajectory with {len(arm_goal.positions)} positions")
            self.last_positions = arm_goal.positions

        arm_controller.points.append(arm_goal)
        self.arm_pub_.publish(arm_controller)


def main():
    rclpy.init()

    simple_publisher = SliderControl()
    rclpy.spin(simple_publisher)
    
    simple_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()