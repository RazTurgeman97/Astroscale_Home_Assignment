#include <rclcpp/rclcpp.hpp>
#include <memory>
#include "robot_msgs/srv/move_to_position.hpp"
#include <moveit/move_group_interface/move_group_interface.h>

using MoveToPosition = robot_msgs::srv::MoveToPosition;

using namespace std::placeholders;

class MoveServiceServer : public rclcpp::Node
{
public:
  MoveServiceServer(const rclcpp::NodeOptions & options) : Node("move_service_server", options)
  {
    service_ = create_service<MoveToPosition>("move_to_position", std::bind(&MoveServiceServer::serviceCallback, this, _1, _2));
    RCLCPP_INFO(get_logger(), "Service move_to_position is Ready.");
  }

  void initializeMoveGroupInterface(const std::shared_ptr<MoveServiceServer> & node_shared_ptr)
  {
    move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(node_shared_ptr, "arm");
  }

private:
  rclcpp::Service<MoveToPosition>::SharedPtr service_;
  std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;

  void serviceCallback(const std::shared_ptr<MoveToPosition::Request> req,
                      const std::shared_ptr<MoveToPosition::Response> res)
  {
    RCLCPP_INFO_STREAM(get_logger(), "New Request Received - forearm_position: " << req->forearm_position << " hand_position: " << req->hand_position);

    // Check if the given arguments are within bounds
    if (req->forearm_position < -180 || req->forearm_position > 180 || req->hand_position < -90 || req->hand_position > 90)
    {
      res->success = false;
      res->message = "Input angles are out of bounds. Use: <forearm_position: [-180, 180]> <hand_position: [-90, 90]>";
      RCLCPP_ERROR(get_logger(), "Input angles are out of bounds.");
      return;
    }

    // Set joint values based on received angles
    std::vector<double> joint_group_positions;
    joint_group_positions.push_back(req->forearm_position * M_PI / 180.0); // Convert degrees to radians
    joint_group_positions.push_back(req->hand_position * M_PI / 180.0);    // Convert degrees to radians

    move_group_->setJointValueTarget(joint_group_positions);

    // Plan to the new joint values
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    bool plan_success = (move_group_->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

    if (plan_success)
    {
      // Execute the plan
      moveit::core::MoveItErrorCode result = move_group_->execute(plan);
      bool execute_success = (result == moveit::core::MoveItErrorCode::SUCCESS);
      
      if (execute_success)
      {
        res->success = true;
        res->message = "Motion executed successfully.";
        RCLCPP_INFO(get_logger(), "Motion executed successfully.");
      }
      else
      {
        res->success = false;
        res->message = "Motion execution failed.";
        RCLCPP_ERROR(get_logger(), "Motion execution failed.");
      }
    }
    else
    {
      res->success = false;
      res->message = "Motion planning failed.";
      RCLCPP_ERROR(get_logger(), "Motion planning failed.");
    }
  }
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MoveServiceServer>(rclcpp::NodeOptions());
  node->initializeMoveGroupInterface(node);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}