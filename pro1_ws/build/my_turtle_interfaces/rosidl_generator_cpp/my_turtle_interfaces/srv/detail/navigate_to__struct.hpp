// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_turtle_interfaces:srv/NavigateTo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_turtle_interfaces/srv/navigate_to.hpp"


#ifndef MY_TURTLE_INTERFACES__SRV__DETAIL__NAVIGATE_TO__STRUCT_HPP_
#define MY_TURTLE_INTERFACES__SRV__DETAIL__NAVIGATE_TO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Request __declspec(deprecated)
#endif

namespace my_turtle_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct NavigateTo_Request_
{
  using Type = NavigateTo_Request_<ContainerAllocator>;

  explicit NavigateTo_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->theta = 0.0f;
    }
  }

  explicit NavigateTo_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->theta = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _theta_type =
    float;
  _theta_type theta;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__theta(
    const float & _arg)
  {
    this->theta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Request
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Request
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavigateTo_Request_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavigateTo_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavigateTo_Request_

// alias to use template instance with default allocator
using NavigateTo_Request =
  my_turtle_interfaces::srv::NavigateTo_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_turtle_interfaces


#ifndef _WIN32
# define DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Response __declspec(deprecated)
#endif

namespace my_turtle_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct NavigateTo_Response_
{
  using Type = NavigateTo_Response_<ContainerAllocator>;

  explicit NavigateTo_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit NavigateTo_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Response
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Response
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavigateTo_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavigateTo_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavigateTo_Response_

// alias to use template instance with default allocator
using NavigateTo_Response =
  my_turtle_interfaces::srv::NavigateTo_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_turtle_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Event __attribute__((deprecated))
#else
# define DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Event __declspec(deprecated)
#endif

namespace my_turtle_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct NavigateTo_Event_
{
  using Type = NavigateTo_Event_<ContainerAllocator>;

  explicit NavigateTo_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit NavigateTo_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_turtle_interfaces::srv::NavigateTo_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_turtle_interfaces::srv::NavigateTo_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Event
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_turtle_interfaces__srv__NavigateTo_Event
    std::shared_ptr<my_turtle_interfaces::srv::NavigateTo_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavigateTo_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavigateTo_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavigateTo_Event_

// alias to use template instance with default allocator
using NavigateTo_Event =
  my_turtle_interfaces::srv::NavigateTo_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_turtle_interfaces

namespace my_turtle_interfaces
{

namespace srv
{

struct NavigateTo
{
  using Request = my_turtle_interfaces::srv::NavigateTo_Request;
  using Response = my_turtle_interfaces::srv::NavigateTo_Response;
  using Event = my_turtle_interfaces::srv::NavigateTo_Event;
};

}  // namespace srv

}  // namespace my_turtle_interfaces

#endif  // MY_TURTLE_INTERFACES__SRV__DETAIL__NAVIGATE_TO__STRUCT_HPP_
