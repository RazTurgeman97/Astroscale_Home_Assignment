// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_msgs:srv/MoveToPosition.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__STRUCT_HPP_
#define ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_msgs__srv__MoveToPosition_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_msgs__srv__MoveToPosition_Request __declspec(deprecated)
#endif

namespace robot_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveToPosition_Request_
{
  using Type = MoveToPosition_Request_<ContainerAllocator>;

  explicit MoveToPosition_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->forearm_position = 0ll;
      this->hand_position = 0ll;
    }
  }

  explicit MoveToPosition_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->forearm_position = 0ll;
      this->hand_position = 0ll;
    }
  }

  // field types and members
  using _forearm_position_type =
    int64_t;
  _forearm_position_type forearm_position;
  using _hand_position_type =
    int64_t;
  _hand_position_type hand_position;

  // setters for named parameter idiom
  Type & set__forearm_position(
    const int64_t & _arg)
  {
    this->forearm_position = _arg;
    return *this;
  }
  Type & set__hand_position(
    const int64_t & _arg)
  {
    this->hand_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_msgs__srv__MoveToPosition_Request
    std::shared_ptr<robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_msgs__srv__MoveToPosition_Request
    std::shared_ptr<robot_msgs::srv::MoveToPosition_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveToPosition_Request_ & other) const
  {
    if (this->forearm_position != other.forearm_position) {
      return false;
    }
    if (this->hand_position != other.hand_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveToPosition_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveToPosition_Request_

// alias to use template instance with default allocator
using MoveToPosition_Request =
  robot_msgs::srv::MoveToPosition_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_msgs


#ifndef _WIN32
# define DEPRECATED__robot_msgs__srv__MoveToPosition_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_msgs__srv__MoveToPosition_Response __declspec(deprecated)
#endif

namespace robot_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveToPosition_Response_
{
  using Type = MoveToPosition_Response_<ContainerAllocator>;

  explicit MoveToPosition_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit MoveToPosition_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_msgs__srv__MoveToPosition_Response
    std::shared_ptr<robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_msgs__srv__MoveToPosition_Response
    std::shared_ptr<robot_msgs::srv::MoveToPosition_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveToPosition_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveToPosition_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveToPosition_Response_

// alias to use template instance with default allocator
using MoveToPosition_Response =
  robot_msgs::srv::MoveToPosition_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_msgs

namespace robot_msgs
{

namespace srv
{

struct MoveToPosition
{
  using Request = robot_msgs::srv::MoveToPosition_Request;
  using Response = robot_msgs::srv::MoveToPosition_Response;
};

}  // namespace srv

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__STRUCT_HPP_
