// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_turtle_interfaces:srv/NavigateTo.idl
// generated code does not contain a copyright notice
#include "my_turtle_interfaces/srv/detail/navigate_to__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
my_turtle_interfaces__srv__NavigateTo_Request__init(my_turtle_interfaces__srv__NavigateTo_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // theta
  return true;
}

void
my_turtle_interfaces__srv__NavigateTo_Request__fini(my_turtle_interfaces__srv__NavigateTo_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // theta
}

bool
my_turtle_interfaces__srv__NavigateTo_Request__are_equal(const my_turtle_interfaces__srv__NavigateTo_Request * lhs, const my_turtle_interfaces__srv__NavigateTo_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // theta
  if (lhs->theta != rhs->theta) {
    return false;
  }
  return true;
}

bool
my_turtle_interfaces__srv__NavigateTo_Request__copy(
  const my_turtle_interfaces__srv__NavigateTo_Request * input,
  my_turtle_interfaces__srv__NavigateTo_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // theta
  output->theta = input->theta;
  return true;
}

my_turtle_interfaces__srv__NavigateTo_Request *
my_turtle_interfaces__srv__NavigateTo_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__srv__NavigateTo_Request * msg = (my_turtle_interfaces__srv__NavigateTo_Request *)allocator.allocate(sizeof(my_turtle_interfaces__srv__NavigateTo_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_turtle_interfaces__srv__NavigateTo_Request));
  bool success = my_turtle_interfaces__srv__NavigateTo_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_turtle_interfaces__srv__NavigateTo_Request__destroy(my_turtle_interfaces__srv__NavigateTo_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_turtle_interfaces__srv__NavigateTo_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_turtle_interfaces__srv__NavigateTo_Request__Sequence__init(my_turtle_interfaces__srv__NavigateTo_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__srv__NavigateTo_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(my_turtle_interfaces__srv__NavigateTo_Request)) {
      return false;
    }
    data = (my_turtle_interfaces__srv__NavigateTo_Request *)allocator.zero_allocate(size, sizeof(my_turtle_interfaces__srv__NavigateTo_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_turtle_interfaces__srv__NavigateTo_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_turtle_interfaces__srv__NavigateTo_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_turtle_interfaces__srv__NavigateTo_Request__Sequence__fini(my_turtle_interfaces__srv__NavigateTo_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_turtle_interfaces__srv__NavigateTo_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_turtle_interfaces__srv__NavigateTo_Request__Sequence *
my_turtle_interfaces__srv__NavigateTo_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__srv__NavigateTo_Request__Sequence * array = (my_turtle_interfaces__srv__NavigateTo_Request__Sequence *)allocator.allocate(sizeof(my_turtle_interfaces__srv__NavigateTo_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_turtle_interfaces__srv__NavigateTo_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_turtle_interfaces__srv__NavigateTo_Request__Sequence__destroy(my_turtle_interfaces__srv__NavigateTo_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_turtle_interfaces__srv__NavigateTo_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_turtle_interfaces__srv__NavigateTo_Request__Sequence__are_equal(const my_turtle_interfaces__srv__NavigateTo_Request__Sequence * lhs, const my_turtle_interfaces__srv__NavigateTo_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_turtle_interfaces__srv__NavigateTo_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_turtle_interfaces__srv__NavigateTo_Request__Sequence__copy(
  const my_turtle_interfaces__srv__NavigateTo_Request__Sequence * input,
  my_turtle_interfaces__srv__NavigateTo_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(my_turtle_interfaces__srv__NavigateTo_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(my_turtle_interfaces__srv__NavigateTo_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_turtle_interfaces__srv__NavigateTo_Request * data =
      (my_turtle_interfaces__srv__NavigateTo_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_turtle_interfaces__srv__NavigateTo_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_turtle_interfaces__srv__NavigateTo_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_turtle_interfaces__srv__NavigateTo_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
my_turtle_interfaces__srv__NavigateTo_Response__init(my_turtle_interfaces__srv__NavigateTo_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
my_turtle_interfaces__srv__NavigateTo_Response__fini(my_turtle_interfaces__srv__NavigateTo_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
my_turtle_interfaces__srv__NavigateTo_Response__are_equal(const my_turtle_interfaces__srv__NavigateTo_Response * lhs, const my_turtle_interfaces__srv__NavigateTo_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
my_turtle_interfaces__srv__NavigateTo_Response__copy(
  const my_turtle_interfaces__srv__NavigateTo_Response * input,
  my_turtle_interfaces__srv__NavigateTo_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

my_turtle_interfaces__srv__NavigateTo_Response *
my_turtle_interfaces__srv__NavigateTo_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__srv__NavigateTo_Response * msg = (my_turtle_interfaces__srv__NavigateTo_Response *)allocator.allocate(sizeof(my_turtle_interfaces__srv__NavigateTo_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_turtle_interfaces__srv__NavigateTo_Response));
  bool success = my_turtle_interfaces__srv__NavigateTo_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_turtle_interfaces__srv__NavigateTo_Response__destroy(my_turtle_interfaces__srv__NavigateTo_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_turtle_interfaces__srv__NavigateTo_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_turtle_interfaces__srv__NavigateTo_Response__Sequence__init(my_turtle_interfaces__srv__NavigateTo_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__srv__NavigateTo_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(my_turtle_interfaces__srv__NavigateTo_Response)) {
      return false;
    }
    data = (my_turtle_interfaces__srv__NavigateTo_Response *)allocator.zero_allocate(size, sizeof(my_turtle_interfaces__srv__NavigateTo_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_turtle_interfaces__srv__NavigateTo_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_turtle_interfaces__srv__NavigateTo_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_turtle_interfaces__srv__NavigateTo_Response__Sequence__fini(my_turtle_interfaces__srv__NavigateTo_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_turtle_interfaces__srv__NavigateTo_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_turtle_interfaces__srv__NavigateTo_Response__Sequence *
my_turtle_interfaces__srv__NavigateTo_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__srv__NavigateTo_Response__Sequence * array = (my_turtle_interfaces__srv__NavigateTo_Response__Sequence *)allocator.allocate(sizeof(my_turtle_interfaces__srv__NavigateTo_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_turtle_interfaces__srv__NavigateTo_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_turtle_interfaces__srv__NavigateTo_Response__Sequence__destroy(my_turtle_interfaces__srv__NavigateTo_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_turtle_interfaces__srv__NavigateTo_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_turtle_interfaces__srv__NavigateTo_Response__Sequence__are_equal(const my_turtle_interfaces__srv__NavigateTo_Response__Sequence * lhs, const my_turtle_interfaces__srv__NavigateTo_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_turtle_interfaces__srv__NavigateTo_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_turtle_interfaces__srv__NavigateTo_Response__Sequence__copy(
  const my_turtle_interfaces__srv__NavigateTo_Response__Sequence * input,
  my_turtle_interfaces__srv__NavigateTo_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(my_turtle_interfaces__srv__NavigateTo_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(my_turtle_interfaces__srv__NavigateTo_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_turtle_interfaces__srv__NavigateTo_Response * data =
      (my_turtle_interfaces__srv__NavigateTo_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_turtle_interfaces__srv__NavigateTo_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_turtle_interfaces__srv__NavigateTo_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_turtle_interfaces__srv__NavigateTo_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "my_turtle_interfaces/srv/detail/navigate_to__functions.h"

bool
my_turtle_interfaces__srv__NavigateTo_Event__init(my_turtle_interfaces__srv__NavigateTo_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    my_turtle_interfaces__srv__NavigateTo_Event__fini(msg);
    return false;
  }
  // request
  if (!my_turtle_interfaces__srv__NavigateTo_Request__Sequence__init(&msg->request, 0)) {
    my_turtle_interfaces__srv__NavigateTo_Event__fini(msg);
    return false;
  }
  // response
  if (!my_turtle_interfaces__srv__NavigateTo_Response__Sequence__init(&msg->response, 0)) {
    my_turtle_interfaces__srv__NavigateTo_Event__fini(msg);
    return false;
  }
  return true;
}

void
my_turtle_interfaces__srv__NavigateTo_Event__fini(my_turtle_interfaces__srv__NavigateTo_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  my_turtle_interfaces__srv__NavigateTo_Request__Sequence__fini(&msg->request);
  // response
  my_turtle_interfaces__srv__NavigateTo_Response__Sequence__fini(&msg->response);
}

bool
my_turtle_interfaces__srv__NavigateTo_Event__are_equal(const my_turtle_interfaces__srv__NavigateTo_Event * lhs, const my_turtle_interfaces__srv__NavigateTo_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!my_turtle_interfaces__srv__NavigateTo_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!my_turtle_interfaces__srv__NavigateTo_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
my_turtle_interfaces__srv__NavigateTo_Event__copy(
  const my_turtle_interfaces__srv__NavigateTo_Event * input,
  my_turtle_interfaces__srv__NavigateTo_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!my_turtle_interfaces__srv__NavigateTo_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!my_turtle_interfaces__srv__NavigateTo_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

my_turtle_interfaces__srv__NavigateTo_Event *
my_turtle_interfaces__srv__NavigateTo_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__srv__NavigateTo_Event * msg = (my_turtle_interfaces__srv__NavigateTo_Event *)allocator.allocate(sizeof(my_turtle_interfaces__srv__NavigateTo_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_turtle_interfaces__srv__NavigateTo_Event));
  bool success = my_turtle_interfaces__srv__NavigateTo_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_turtle_interfaces__srv__NavigateTo_Event__destroy(my_turtle_interfaces__srv__NavigateTo_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_turtle_interfaces__srv__NavigateTo_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_turtle_interfaces__srv__NavigateTo_Event__Sequence__init(my_turtle_interfaces__srv__NavigateTo_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__srv__NavigateTo_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(my_turtle_interfaces__srv__NavigateTo_Event)) {
      return false;
    }
    data = (my_turtle_interfaces__srv__NavigateTo_Event *)allocator.zero_allocate(size, sizeof(my_turtle_interfaces__srv__NavigateTo_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_turtle_interfaces__srv__NavigateTo_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_turtle_interfaces__srv__NavigateTo_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_turtle_interfaces__srv__NavigateTo_Event__Sequence__fini(my_turtle_interfaces__srv__NavigateTo_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_turtle_interfaces__srv__NavigateTo_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_turtle_interfaces__srv__NavigateTo_Event__Sequence *
my_turtle_interfaces__srv__NavigateTo_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__srv__NavigateTo_Event__Sequence * array = (my_turtle_interfaces__srv__NavigateTo_Event__Sequence *)allocator.allocate(sizeof(my_turtle_interfaces__srv__NavigateTo_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_turtle_interfaces__srv__NavigateTo_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_turtle_interfaces__srv__NavigateTo_Event__Sequence__destroy(my_turtle_interfaces__srv__NavigateTo_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_turtle_interfaces__srv__NavigateTo_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_turtle_interfaces__srv__NavigateTo_Event__Sequence__are_equal(const my_turtle_interfaces__srv__NavigateTo_Event__Sequence * lhs, const my_turtle_interfaces__srv__NavigateTo_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_turtle_interfaces__srv__NavigateTo_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_turtle_interfaces__srv__NavigateTo_Event__Sequence__copy(
  const my_turtle_interfaces__srv__NavigateTo_Event__Sequence * input,
  my_turtle_interfaces__srv__NavigateTo_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(my_turtle_interfaces__srv__NavigateTo_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(my_turtle_interfaces__srv__NavigateTo_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_turtle_interfaces__srv__NavigateTo_Event * data =
      (my_turtle_interfaces__srv__NavigateTo_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_turtle_interfaces__srv__NavigateTo_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_turtle_interfaces__srv__NavigateTo_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_turtle_interfaces__srv__NavigateTo_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
