#!/bin/bash

# Clean any previously built files (optional, based on your needs)
echo "Cleaning previous build files..."
rm -rf /workspace/build/*
rm -rf /workspace/install/*
rm -rf /workspace/log/*

# Source ROS 2 setup.bash (if not already sourced)
if [ -f "/opt/ros/humble/setup.bash" ]; then
    source /opt/ros/humble/setup.bash
    
    # Source the workspace setup.bash
    source /root/ros2_ws/install/setup.bash
else
    echo "ROS 2 setup.bash not found!"
fi

# Execute the command passed to the container (e.g., bash or a specific command)
exec "$@"

