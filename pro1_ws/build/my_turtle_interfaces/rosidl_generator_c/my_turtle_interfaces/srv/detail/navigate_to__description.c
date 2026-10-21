// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from my_turtle_interfaces:srv/NavigateTo.idl
// generated code does not contain a copyright notice

#include "my_turtle_interfaces/srv/detail/navigate_to__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_my_turtle_interfaces
const rosidl_type_hash_t *
my_turtle_interfaces__srv__NavigateTo__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x10, 0xce, 0xd3, 0x5d, 0xff, 0x25, 0x76, 0xfd,
      0xd7, 0x90, 0xaf, 0xef, 0x32, 0xea, 0xc9, 0x39,
      0xc8, 0x2d, 0x1f, 0xc5, 0x01, 0x88, 0x80, 0xc6,
      0xef, 0xa9, 0x03, 0xb9, 0x1b, 0xef, 0xcb, 0x75,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_my_turtle_interfaces
const rosidl_type_hash_t *
my_turtle_interfaces__srv__NavigateTo_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x70, 0x23, 0xce, 0x20, 0x03, 0x8d, 0xf4, 0x67,
      0x55, 0x89, 0x86, 0x0e, 0xe8, 0x5c, 0x0b, 0xf2,
      0x43, 0xfd, 0xcc, 0x03, 0xbf, 0x41, 0xe4, 0x48,
      0x8c, 0x4f, 0xc1, 0x7d, 0x50, 0x1f, 0x9e, 0x60,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_my_turtle_interfaces
const rosidl_type_hash_t *
my_turtle_interfaces__srv__NavigateTo_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x54, 0x07, 0x56, 0x5f, 0xef, 0x7a, 0x39, 0x48,
      0x9c, 0xf6, 0x8d, 0xd0, 0xd5, 0x93, 0x1c, 0xb6,
      0x6a, 0x50, 0x41, 0x2d, 0x73, 0xfd, 0x15, 0xf2,
      0xd0, 0x7c, 0x51, 0x6d, 0x95, 0x98, 0xa3, 0x6e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_my_turtle_interfaces
const rosidl_type_hash_t *
my_turtle_interfaces__srv__NavigateTo_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x59, 0x87, 0x63, 0x61, 0x01, 0xec, 0x70, 0x4c,
      0x26, 0xe2, 0x77, 0xf0, 0xb3, 0xfa, 0xdd, 0x8c,
      0xcc, 0xf2, 0x87, 0xa6, 0xe6, 0xf8, 0x4c, 0x72,
      0x02, 0x83, 0xa3, 0xfa, 0x9e, 0xc9, 0x80, 0xc3,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char my_turtle_interfaces__srv__NavigateTo__TYPE_NAME[] = "my_turtle_interfaces/srv/NavigateTo";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char my_turtle_interfaces__srv__NavigateTo_Event__TYPE_NAME[] = "my_turtle_interfaces/srv/NavigateTo_Event";
static char my_turtle_interfaces__srv__NavigateTo_Request__TYPE_NAME[] = "my_turtle_interfaces/srv/NavigateTo_Request";
static char my_turtle_interfaces__srv__NavigateTo_Response__TYPE_NAME[] = "my_turtle_interfaces/srv/NavigateTo_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char my_turtle_interfaces__srv__NavigateTo__FIELD_NAME__request_message[] = "request_message";
static char my_turtle_interfaces__srv__NavigateTo__FIELD_NAME__response_message[] = "response_message";
static char my_turtle_interfaces__srv__NavigateTo__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field my_turtle_interfaces__srv__NavigateTo__FIELDS[] = {
  {
    {my_turtle_interfaces__srv__NavigateTo__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {my_turtle_interfaces__srv__NavigateTo_Request__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {my_turtle_interfaces__srv__NavigateTo__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {my_turtle_interfaces__srv__NavigateTo_Response__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {my_turtle_interfaces__srv__NavigateTo__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {my_turtle_interfaces__srv__NavigateTo_Event__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription my_turtle_interfaces__srv__NavigateTo__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {my_turtle_interfaces__srv__NavigateTo_Event__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {my_turtle_interfaces__srv__NavigateTo_Request__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {my_turtle_interfaces__srv__NavigateTo_Response__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_turtle_interfaces__srv__NavigateTo__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_turtle_interfaces__srv__NavigateTo__TYPE_NAME, 35, 35},
      {my_turtle_interfaces__srv__NavigateTo__FIELDS, 3, 3},
    },
    {my_turtle_interfaces__srv__NavigateTo__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = my_turtle_interfaces__srv__NavigateTo_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = my_turtle_interfaces__srv__NavigateTo_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = my_turtle_interfaces__srv__NavigateTo_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char my_turtle_interfaces__srv__NavigateTo_Request__FIELD_NAME__x[] = "x";
static char my_turtle_interfaces__srv__NavigateTo_Request__FIELD_NAME__y[] = "y";
static char my_turtle_interfaces__srv__NavigateTo_Request__FIELD_NAME__theta[] = "theta";

static rosidl_runtime_c__type_description__Field my_turtle_interfaces__srv__NavigateTo_Request__FIELDS[] = {
  {
    {my_turtle_interfaces__srv__NavigateTo_Request__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_turtle_interfaces__srv__NavigateTo_Request__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_turtle_interfaces__srv__NavigateTo_Request__FIELD_NAME__theta, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_turtle_interfaces__srv__NavigateTo_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_turtle_interfaces__srv__NavigateTo_Request__TYPE_NAME, 43, 43},
      {my_turtle_interfaces__srv__NavigateTo_Request__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char my_turtle_interfaces__srv__NavigateTo_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field my_turtle_interfaces__srv__NavigateTo_Response__FIELDS[] = {
  {
    {my_turtle_interfaces__srv__NavigateTo_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_turtle_interfaces__srv__NavigateTo_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_turtle_interfaces__srv__NavigateTo_Response__TYPE_NAME, 44, 44},
      {my_turtle_interfaces__srv__NavigateTo_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char my_turtle_interfaces__srv__NavigateTo_Event__FIELD_NAME__info[] = "info";
static char my_turtle_interfaces__srv__NavigateTo_Event__FIELD_NAME__request[] = "request";
static char my_turtle_interfaces__srv__NavigateTo_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field my_turtle_interfaces__srv__NavigateTo_Event__FIELDS[] = {
  {
    {my_turtle_interfaces__srv__NavigateTo_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {my_turtle_interfaces__srv__NavigateTo_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {my_turtle_interfaces__srv__NavigateTo_Request__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {my_turtle_interfaces__srv__NavigateTo_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {my_turtle_interfaces__srv__NavigateTo_Response__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription my_turtle_interfaces__srv__NavigateTo_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {my_turtle_interfaces__srv__NavigateTo_Request__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {my_turtle_interfaces__srv__NavigateTo_Response__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_turtle_interfaces__srv__NavigateTo_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_turtle_interfaces__srv__NavigateTo_Event__TYPE_NAME, 41, 41},
      {my_turtle_interfaces__srv__NavigateTo_Event__FIELDS, 3, 3},
    },
    {my_turtle_interfaces__srv__NavigateTo_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = my_turtle_interfaces__srv__NavigateTo_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = my_turtle_interfaces__srv__NavigateTo_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# ===== Request \\xe8\\xaf\\xb7\\xe6\\xb1\\x82\\xe9\\x83\\xa8\\xe5\\x88\\x86 =====\n"
  "float32 x\n"
  "float32 y\n"
  "float32 theta\n"
  "---\n"
  "# ===== Response \\xe5\\x93\\x8d\\xe5\\xba\\x94\\xe9\\x83\\xa8\\xe5\\x88\\x86 =====\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
my_turtle_interfaces__srv__NavigateTo__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_turtle_interfaces__srv__NavigateTo__TYPE_NAME, 35, 35},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 105, 105},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
my_turtle_interfaces__srv__NavigateTo_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_turtle_interfaces__srv__NavigateTo_Request__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
my_turtle_interfaces__srv__NavigateTo_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_turtle_interfaces__srv__NavigateTo_Response__TYPE_NAME, 44, 44},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
my_turtle_interfaces__srv__NavigateTo_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_turtle_interfaces__srv__NavigateTo_Event__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_turtle_interfaces__srv__NavigateTo__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_turtle_interfaces__srv__NavigateTo__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *my_turtle_interfaces__srv__NavigateTo_Event__get_individual_type_description_source(NULL);
    sources[3] = *my_turtle_interfaces__srv__NavigateTo_Request__get_individual_type_description_source(NULL);
    sources[4] = *my_turtle_interfaces__srv__NavigateTo_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_turtle_interfaces__srv__NavigateTo_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_turtle_interfaces__srv__NavigateTo_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_turtle_interfaces__srv__NavigateTo_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_turtle_interfaces__srv__NavigateTo_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_turtle_interfaces__srv__NavigateTo_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_turtle_interfaces__srv__NavigateTo_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *my_turtle_interfaces__srv__NavigateTo_Request__get_individual_type_description_source(NULL);
    sources[3] = *my_turtle_interfaces__srv__NavigateTo_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
