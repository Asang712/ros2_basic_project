// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_turtle_interfaces:srv/TeleportTo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_turtle_interfaces/srv/teleport_to.h"


#ifndef MY_TURTLE_INTERFACES__SRV__DETAIL__TELEPORT_TO__STRUCT_H_
#define MY_TURTLE_INTERFACES__SRV__DETAIL__TELEPORT_TO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/TeleportTo in the package my_turtle_interfaces.
typedef struct my_turtle_interfaces__srv__TeleportTo_Request
{
  float x;
  float y;
  float theta;
} my_turtle_interfaces__srv__TeleportTo_Request;

// Struct for a sequence of my_turtle_interfaces__srv__TeleportTo_Request.
typedef struct my_turtle_interfaces__srv__TeleportTo_Request__Sequence
{
  my_turtle_interfaces__srv__TeleportTo_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_turtle_interfaces__srv__TeleportTo_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/TeleportTo in the package my_turtle_interfaces.
typedef struct my_turtle_interfaces__srv__TeleportTo_Response
{
  bool success;
} my_turtle_interfaces__srv__TeleportTo_Response;

// Struct for a sequence of my_turtle_interfaces__srv__TeleportTo_Response.
typedef struct my_turtle_interfaces__srv__TeleportTo_Response__Sequence
{
  my_turtle_interfaces__srv__TeleportTo_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_turtle_interfaces__srv__TeleportTo_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  my_turtle_interfaces__srv__TeleportTo_Event__request__MAX_SIZE = 1
};
// response
enum
{
  my_turtle_interfaces__srv__TeleportTo_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/TeleportTo in the package my_turtle_interfaces.
typedef struct my_turtle_interfaces__srv__TeleportTo_Event
{
  service_msgs__msg__ServiceEventInfo info;
  my_turtle_interfaces__srv__TeleportTo_Request__Sequence request;
  my_turtle_interfaces__srv__TeleportTo_Response__Sequence response;
} my_turtle_interfaces__srv__TeleportTo_Event;

// Struct for a sequence of my_turtle_interfaces__srv__TeleportTo_Event.
typedef struct my_turtle_interfaces__srv__TeleportTo_Event__Sequence
{
  my_turtle_interfaces__srv__TeleportTo_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_turtle_interfaces__srv__TeleportTo_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_TURTLE_INTERFACES__SRV__DETAIL__TELEPORT_TO__STRUCT_H_
