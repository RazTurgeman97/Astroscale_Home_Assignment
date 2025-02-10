// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_msgs:srv/MoveToPosition.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__STRUCT_H_
#define ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MoveToPosition in the package robot_msgs.
typedef struct robot_msgs__srv__MoveToPosition_Request
{
  int64_t forearm_position;
  int64_t hand_position;
} robot_msgs__srv__MoveToPosition_Request;

// Struct for a sequence of robot_msgs__srv__MoveToPosition_Request.
typedef struct robot_msgs__srv__MoveToPosition_Request__Sequence
{
  robot_msgs__srv__MoveToPosition_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_msgs__srv__MoveToPosition_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MoveToPosition in the package robot_msgs.
typedef struct robot_msgs__srv__MoveToPosition_Response
{
  bool success;
  rosidl_runtime_c__String message;
} robot_msgs__srv__MoveToPosition_Response;

// Struct for a sequence of robot_msgs__srv__MoveToPosition_Response.
typedef struct robot_msgs__srv__MoveToPosition_Response__Sequence
{
  robot_msgs__srv__MoveToPosition_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_msgs__srv__MoveToPosition_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_MSGS__SRV__DETAIL__MOVE_TO_POSITION__STRUCT_H_
