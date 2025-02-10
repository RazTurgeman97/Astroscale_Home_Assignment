// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_msgs:srv/MoveToPosition.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__TRAITS_HPP_
#define ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_msgs/srv/detail/move_to_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveToPosition_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: forearm_position
  {
    out << "forearm_position: ";
    rosidl_generator_traits::value_to_yaml(msg.forearm_position, out);
    out << ", ";
  }

  // member: hand_position
  {
    out << "hand_position: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveToPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: forearm_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "forearm_position: ";
    rosidl_generator_traits::value_to_yaml(msg.forearm_position, out);
    out << "\n";
  }

  // member: hand_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hand_position: ";
    rosidl_generator_traits::value_to_yaml(msg.hand_position, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveToPosition_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use robot_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_msgs::srv::MoveToPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_msgs::srv::MoveToPosition_Request & msg)
{
  return robot_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_msgs::srv::MoveToPosition_Request>()
{
  return "robot_msgs::srv::MoveToPosition_Request";
}

template<>
inline const char * name<robot_msgs::srv::MoveToPosition_Request>()
{
  return "robot_msgs/srv/MoveToPosition_Request";
}

template<>
struct has_fixed_size<robot_msgs::srv::MoveToPosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_msgs::srv::MoveToPosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_msgs::srv::MoveToPosition_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveToPosition_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveToPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveToPosition_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use robot_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_msgs::srv::MoveToPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_msgs::srv::MoveToPosition_Response & msg)
{
  return robot_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_msgs::srv::MoveToPosition_Response>()
{
  return "robot_msgs::srv::MoveToPosition_Response";
}

template<>
inline const char * name<robot_msgs::srv::MoveToPosition_Response>()
{
  return "robot_msgs/srv/MoveToPosition_Response";
}

template<>
struct has_fixed_size<robot_msgs::srv::MoveToPosition_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_msgs::srv::MoveToPosition_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_msgs::srv::MoveToPosition_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_msgs::srv::MoveToPosition>()
{
  return "robot_msgs::srv::MoveToPosition";
}

template<>
inline const char * name<robot_msgs::srv::MoveToPosition>()
{
  return "robot_msgs/srv/MoveToPosition";
}

template<>
struct has_fixed_size<robot_msgs::srv::MoveToPosition>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_msgs::srv::MoveToPosition_Request>::value &&
    has_fixed_size<robot_msgs::srv::MoveToPosition_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_msgs::srv::MoveToPosition>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_msgs::srv::MoveToPosition_Request>::value &&
    has_bounded_size<robot_msgs::srv::MoveToPosition_Response>::value
  >
{
};

template<>
struct is_service<robot_msgs::srv::MoveToPosition>
  : std::true_type
{
};

template<>
struct is_service_request<robot_msgs::srv::MoveToPosition_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_msgs::srv::MoveToPosition_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__TRAITS_HPP_
