cmake_minimum_required(VERSION 3.8)
project(robot_services)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rcl_interfaces REQUIRED)
find_package(robot_msgs REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)

add_executable(move_service_server src/move_service_server.cpp)
ament_target_dependencies(move_service_server rclcpp std_msgs robot_msgs moveit_core moveit_ros_planning_interface)

add_executable(move_service_client src/move_service_client.cpp)
ament_target_dependencies(move_service_client rclcpp std_msgs robot_msgs)

install(TARGETS
  move_service_server
  move_service_client
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
