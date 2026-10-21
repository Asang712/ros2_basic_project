// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_turtle_interfaces:srv/TeleportTo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_turtle_interfaces/srv/teleport_to.hpp"


#ifndef MY_TURTLE_INTERFACES__SRV__DETAIL__TELEPORT_TO__BUILDER_HPP_
#define MY_TURTLE_INTERFACES__SRV__DETAIL__TELEPORT_TO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_turtle_interfaces/srv/detail/teleport_to__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_turtle_interfaces
{

namespace srv
{

namespace builder
{

class Init_TeleportTo_Request_theta
{
public:
  explicit Init_TeleportTo_Request_theta(::my_turtle_interfaces::srv::TeleportTo_Request & msg)
  : msg_(msg)
  {}
  ::my_turtle_interfaces::srv::TeleportTo_Request theta(::my_turtle_interfaces::srv::TeleportTo_Request::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_turtle_interfaces::srv::TeleportTo_Request msg_;
};

class Init_TeleportTo_Request_y
{
public:
  explicit Init_TeleportTo_Request_y(::my_turtle_interfaces::srv::TeleportTo_Request & msg)
  : msg_(msg)
  {}
  Init_TeleportTo_Request_theta y(::my_turtle_interfaces::srv::TeleportTo_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TeleportTo_Request_theta(msg_);
  }

private:
  ::my_turtle_interfaces::srv::TeleportTo_Request msg_;
};

class Init_TeleportTo_Request_x
{
public:
  Init_TeleportTo_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TeleportTo_Request_y x(::my_turtle_interfaces::srv::TeleportTo_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TeleportTo_Request_y(msg_);
  }

private:
  ::my_turtle_interfaces::srv::TeleportTo_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_turtle_interfaces::srv::TeleportTo_Request>()
{
  return my_turtle_interfaces::srv::builder::Init_TeleportTo_Request_x();
}

}  // namespace my_turtle_interfaces


namespace my_turtle_interfaces
{

namespace srv
{

namespace builder
{

class Init_TeleportTo_Response_success
{
public:
  Init_TeleportTo_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_turtle_interfaces::srv::TeleportTo_Response success(::my_turtle_interfaces::srv::TeleportTo_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_turtle_interfaces::srv::TeleportTo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_turtle_interfaces::srv::TeleportTo_Response>()
{
  return my_turtle_interfaces::srv::builder::Init_TeleportTo_Response_success();
}

}  // namespace my_turtle_interfaces


namespace my_turtle_interfaces
{

namespace srv
{

namespace builder
{

class Init_TeleportTo_Event_response
{
public:
  explicit Init_TeleportTo_Event_response(::my_turtle_interfaces::srv::TeleportTo_Event & msg)
  : msg_(msg)
  {}
  ::my_turtle_interfaces::srv::TeleportTo_Event response(::my_turtle_interfaces::srv::TeleportTo_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_turtle_interfaces::srv::TeleportTo_Event msg_;
};

class Init_TeleportTo_Event_request
{
public:
  explicit Init_TeleportTo_Event_request(::my_turtle_interfaces::srv::TeleportTo_Event & msg)
  : msg_(msg)
  {}
  Init_TeleportTo_Event_response request(::my_turtle_interfaces::srv::TeleportTo_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_TeleportTo_Event_response(msg_);
  }

private:
  ::my_turtle_interfaces::srv::TeleportTo_Event msg_;
};

class Init_TeleportTo_Event_info
{
public:
  Init_TeleportTo_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TeleportTo_Event_request info(::my_turtle_interfaces::srv::TeleportTo_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_TeleportTo_Event_request(msg_);
  }

private:
  ::my_turtle_interfaces::srv::TeleportTo_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_turtle_interfaces::srv::TeleportTo_Event>()
{
  return my_turtle_interfaces::srv::builder::Init_TeleportTo_Event_info();
}

}  // namespace my_turtle_interfaces

#endif  // MY_TURTLE_INTERFACES__SRV__DETAIL__TELEPORT_TO__BUILDER_HPP_
