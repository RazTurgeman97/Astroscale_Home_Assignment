cmake_minimum_required(VERSION 3.8)
project(robot_controller)

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)

ament_python_install_package(${PROJECT_NAME})

add_executable(slider_control src/slider_control.cpp)
ament_target_dependencies(slider_control rclcpp moveit_core moveit_ros_planning_interface)

install(
  DIRECTORY include
  DESTINATION include
)

install(
  DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)

install(PROGRAMS
  ${PROJECT_NAME}/slider_control.py
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  slider_control
  DESTINATION lib/${PROJECT_NAME}
)

ament_export_include_directories(
  include
)

ament_export_libraries(
  ${PROJECT_NAME}
)

ament_package()