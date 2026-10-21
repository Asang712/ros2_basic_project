// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from my_turtle_interfaces:srv/TeleportTo.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "my_turtle_interfaces/srv/detail/teleport_to__struct.h"
#include "my_turtle_interfaces/srv/detail/teleport_to__type_support.h"
#include "my_turtle_interfaces/srv/detail/teleport_to__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace my_turtle_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _TeleportTo_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeleportTo_Request_type_support_ids_t;

static const _TeleportTo_Request_type_support_ids_t _TeleportTo_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TeleportTo_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeleportTo_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeleportTo_Request_type_support_symbol_names_t _TeleportTo_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_turtle_interfaces, srv, TeleportTo_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_turtle_interfaces, srv, TeleportTo_Request)),
  }
};

typedef struct _TeleportTo_Request_type_support_data_t
{
  void * data[2];
} _TeleportTo_Request_type_support_data_t;

static _TeleportTo_Request_type_support_data_t _TeleportTo_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeleportTo_Request_message_typesupport_map = {
  2,
  "my_turtle_interfaces",
  &_TeleportTo_Request_message_typesupport_ids.typesupport_identifier[0],
  &_TeleportTo_Request_message_typesupport_symbol_names.symbol_name[0],
  &_TeleportTo_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TeleportTo_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeleportTo_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &my_turtle_interfaces__srv__TeleportTo_Request__get_type_hash,
  &my_turtle_interfaces__srv__TeleportTo_Request__get_type_description,
  &my_turtle_interfaces__srv__TeleportTo_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace my_turtle_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_turtle_interfaces, srv, TeleportTo_Request)() {
  return &::my_turtle_interfaces::srv::rosidl_typesupport_c::TeleportTo_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "my_turtle_interfaces/srv/detail/teleport_to__struct.h"
// already included above
// #include "my_turtle_interfaces/srv/detail/teleport_to__type_support.h"
// already included above
// #include "my_turtle_interfaces/srv/detail/teleport_to__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_turtle_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _TeleportTo_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeleportTo_Response_type_support_ids_t;

static const _TeleportTo_Response_type_support_ids_t _TeleportTo_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TeleportTo_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeleportTo_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeleportTo_Response_type_support_symbol_names_t _TeleportTo_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_turtle_interfaces, srv, TeleportTo_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_turtle_interfaces, srv, TeleportTo_Response)),
  }
};

typedef struct _TeleportTo_Response_type_support_data_t
{
  void * data[2];
} _TeleportTo_Response_type_support_data_t;

static _TeleportTo_Response_type_support_data_t _TeleportTo_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeleportTo_Response_message_typesupport_map = {
  2,
  "my_turtle_interfaces",
  &_TeleportTo_Response_message_typesupport_ids.typesupport_identifier[0],
  &_TeleportTo_Response_message_typesupport_symbol_names.symbol_name[0],
  &_TeleportTo_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TeleportTo_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeleportTo_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &my_turtle_interfaces__srv__TeleportTo_Response__get_type_hash,
  &my_turtle_interfaces__srv__TeleportTo_Response__get_type_description,
  &my_turtle_interfaces__srv__TeleportTo_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace my_turtle_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_turtle_interfaces, srv, TeleportTo_Response)() {
  return &::my_turtle_interfaces::srv::rosidl_typesupport_c::TeleportTo_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "my_turtle_interfaces/srv/detail/teleport_to__struct.h"
// already included above
// #include "my_turtle_interfaces/srv/detail/teleport_to__type_support.h"
// already included above
// #include "my_turtle_interfaces/srv/detail/teleport_to__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_turtle_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _TeleportTo_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeleportTo_Event_type_support_ids_t;

static const _TeleportTo_Event_type_support_ids_t _TeleportTo_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TeleportTo_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeleportTo_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeleportTo_Event_type_support_symbol_names_t _TeleportTo_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_turtle_interfaces, srv, TeleportTo_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_turtle_interfaces, srv, TeleportTo_Event)),
  }
};

typedef struct _TeleportTo_Event_type_support_data_t
{
  void * data[2];
} _TeleportTo_Event_type_support_data_t;

static _TeleportTo_Event_type_support_data_t _TeleportTo_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeleportTo_Event_message_typesupport_map = {
  2,
  "my_turtle_interfaces",
  &_TeleportTo_Event_message_typesupport_ids.typesupport_identifier[0],
  &_TeleportTo_Event_message_typesupport_symbol_names.symbol_name[0],
  &_TeleportTo_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TeleportTo_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeleportTo_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &my_turtle_interfaces__srv__TeleportTo_Event__get_type_hash,
  &my_turtle_interfaces__srv__TeleportTo_Event__get_type_description,
  &my_turtle_interfaces__srv__TeleportTo_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace my_turtle_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_turtle_interfaces, srv, TeleportTo_Event)() {
  return &::my_turtle_interfaces::srv::rosidl_typesupport_c::TeleportTo_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "my_turtle_interfaces/srv/detail/teleport_to__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace my_turtle_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _TeleportTo_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeleportTo_type_support_ids_t;

static const _TeleportTo_type_support_ids_t _TeleportTo_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TeleportTo_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeleportTo_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeleportTo_type_support_symbol_names_t _TeleportTo_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_turtle_interfaces, srv, TeleportTo)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_turtle_interfaces, srv, TeleportTo)),
  }
};

typedef struct _TeleportTo_type_support_data_t
{
  void * data[2];
} _TeleportTo_type_support_data_t;

static _TeleportTo_type_support_data_t _TeleportTo_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeleportTo_service_typesupport_map = {
  2,
  "my_turtle_interfaces",
  &_TeleportTo_service_typesupport_ids.typesupport_identifier[0],
  &_TeleportTo_service_typesupport_symbol_names.symbol_name[0],
  &_TeleportTo_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t TeleportTo_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeleportTo_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &TeleportTo_Request_message_type_support_handle,
  &TeleportTo_Response_message_type_support_handle,
  &TeleportTo_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    my_turtle_interfaces,
    srv,
    TeleportTo
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    my_turtle_interfaces,
    srv,
    TeleportTo
  ),
  &my_turtle_interfaces__srv__TeleportTo__get_type_hash,
  &my_turtle_interfaces__srv__TeleportTo__get_type_description,
  &my_turtle_interfaces__srv__TeleportTo__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace my_turtle_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, my_turtle_interfaces, srv, TeleportTo)() {
  return &::my_turtle_interfaces::srv::rosidl_typesupport_c::TeleportTo_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
