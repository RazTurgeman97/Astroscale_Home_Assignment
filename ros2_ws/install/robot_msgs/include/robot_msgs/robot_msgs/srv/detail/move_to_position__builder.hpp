// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_msgs:srv/MoveToPosition.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__BUILDER_HPP_
#define ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_msgs/srv/detail/move_to_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveToPosition_Request_hand_position
{
public:
  explicit Init_MoveToPosition_Request_hand_position(::robot_msgs::srv::MoveToPosition_Request & msg)
  : msg_(msg)
  {}
  ::robot_msgs::srv::MoveToPosition_Request hand_position(::robot_msgs::srv::MoveToPosition_Request::_hand_position_type arg)
  {
    msg_.hand_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_msgs::srv::MoveToPosition_Request msg_;
};

class Init_MoveToPosition_Request_forearm_position
{
public:
  Init_MoveToPosition_Request_forearm_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPosition_Request_hand_position forearm_position(::robot_msgs::srv::MoveToPosition_Request::_forearm_position_type arg)
  {
    msg_.forearm_position = std::move(arg);
    return Init_MoveToPosition_Request_hand_position(msg_);
  }

private:
  ::robot_msgs::srv::MoveToPosition_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_msgs::srv::MoveToPosition_Request>()
{
  return robot_msgs::srv::builder::Init_MoveToPosition_Request_forearm_position();
}

}  // namespace robot_msgs


namespace robot_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveToPosition_Response_message
{
public:
  explicit Init_MoveToPosition_Response_message(::robot_msgs::srv::MoveToPosition_Response & msg)
  : msg_(msg)
  {}
  ::robot_msgs::srv::MoveToPosition_Response message(::robot_msgs::srv::MoveToPosition_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_msgs::srv::MoveToPosition_Response msg_;
};

class Init_MoveToPosition_Response_success
{
public:
  Init_MoveToPosition_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPosition_Response_message success(::robot_msgs::srv::MoveToPosition_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveToPosition_Response_message(msg_);
  }

private:
  ::robot_msgs::srv::MoveToPosition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_msgs::srv::MoveToPosition_Response>()
{
  return robot_msgs::srv::builder::Init_MoveToPosition_Response_success();
}

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__BUILDER_HPP_
