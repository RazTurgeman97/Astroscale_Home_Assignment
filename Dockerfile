# Use the official ROS 2 Humble base image
FROM osrf/ros:humble-desktop

# Install required ROS 2 packages
RUN apt update && apt install -y \
    ros-humble-ament-cmake \
    ros-humble-rclcpp \
    ros-humble-std-msgs \
    ros-humble-rcl-interfaces \
    ros-humble-ros-gz-* \
    ros-humble-ros2-control \
    ros-humble-ign-ros2-control* \
    ros-humble-moveit* \
    ros-humble-moveit-core \
    ros-humble-ros2-controllers \
    ros-humble-moveit-ros-planning-interface \
    ros-humble-rosidl-default-generators \
    ros-humble-rosidl-default-runtime \
    ros-humble-urdf \
    ros-humble-xacro \
    ros-humble-robot-state-publisher \
    ros-humble-joint-state-publisher-gui \
    ros-humble-rviz2 \
    ros-humble-ros2launch \
    ros-humble-*-ros2-control \
    ros-humble-ros-gz-sim \
    ros-humble-ros-gz-bridge \
    ros-humble-ign-ros2-control \
    ros-humble-tf-transformations \
    ros-humble-trajectory-msgs \
    ros-humble-sensor-msgs \
    ros-humble-ament-cmake-python \
    ros-humble-pluginlib \
    libserial-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy the existing ros2_ws into the container
WORKDIR /root
COPY ros2_ws /root/ros2_ws

# Build the ROS 2 workspace inside the container
WORKDIR /root/ros2_ws
RUN /bin/bash -c "source /opt/ros/humble/setup.bash && colcon build"

# Source ROS 2 setup when opening the container
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
RUN echo "source /root/ros2_ws/install/setup.bash" >> ~/.bashrc

# Default command: start a bash shell
CMD ["/bin/bash"]
