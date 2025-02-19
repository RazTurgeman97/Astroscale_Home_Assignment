#!/bin/bash

# Clean any previously built files
echo "Cleaning previous build files..."
rm -rf /root/ros2_ws/build/*
rm -rf /root/ros2_ws/install/*
rm -rf /root/ros2_ws/log/*

# Source ROS 2 setup.bash (if not already sourced)
source /opt/ros/humble/setup.bash

# Source the workspace setup.bash
source /root/ros2_ws/install/setup.bash

# Execute the command passed to the container (e.g., bash or a specific command)
exec "$@"
