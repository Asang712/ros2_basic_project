// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_turtle_interfaces:srv/NavigateTo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_turtle_interfaces/srv/navigate_to.hpp"


#ifndef MY_TURTLE_INTERFACES__SRV__DETAIL__NAVIGATE_TO__BUILDER_HPP_
#define MY_TURTLE_INTERFACES__SRV__DETAIL__NAVIGATE_TO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_turtle_interfaces/srv/detail/navigate_to__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_turtle_interfaces
{

namespace srv
{

namespace builder
{

class Init_NavigateTo_Request_theta
{
public:
  explicit Init_NavigateTo_Request_theta(::my_turtle_interfaces::srv::NavigateTo_Request & msg)
  : msg_(msg)
  {}
  ::my_turtle_interfaces::srv::NavigateTo_Request theta(::my_turtle_interfaces::srv::NavigateTo_Request::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_turtle_interfaces::srv::NavigateTo_Request msg_;
};

class Init_NavigateTo_Request_y
{
public:
  explicit Init_NavigateTo_Request_y(::my_turtle_interfaces::srv::NavigateTo_Request & msg)
  : msg_(msg)
  {}
  Init_NavigateTo_Request_theta y(::my_turtle_interfaces::srv::NavigateTo_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_NavigateTo_Request_theta(msg_);
  }

private:
  ::my_turtle_interfaces::srv::NavigateTo_Request msg_;
};

class Init_NavigateTo_Request_x
{
public:
  Init_NavigateTo_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateTo_Request_y x(::my_turtle_interfaces::srv::NavigateTo_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_NavigateTo_Request_y(msg_);
  }

private:
  ::my_turtle_interfaces::srv::NavigateTo_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_turtle_interfaces::srv::NavigateTo_Request>()
{
  return my_turtle_interfaces::srv::builder::Init_NavigateTo_Request_x();
}

}  // namespace my_turtle_interfaces


namespace my_turtle_interfaces
{

namespace srv
{

namespace builder
{

class Init_NavigateTo_Response_success
{
public:
  Init_NavigateTo_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_turtle_interfaces::srv::NavigateTo_Response success(::my_turtle_interfaces::srv::NavigateTo_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_turtle_interfaces::srv::NavigateTo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_turtle_interfaces::srv::NavigateTo_Response>()
{
  return my_turtle_interfaces::srv::builder::Init_NavigateTo_Response_success();
}

}  // namespace my_turtle_interfaces


namespace my_turtle_interfaces
{

namespace srv
{

namespace builder
{

class Init_NavigateTo_Event_response
{
public:
  explicit Init_NavigateTo_Event_response(::my_turtle_interfaces::srv::NavigateTo_Event & msg)
  : msg_(msg)
  {}
  ::my_turtle_interfaces::srv::NavigateTo_Event response(::my_turtle_interfaces::srv::NavigateTo_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_turtle_interfaces::srv::NavigateTo_Event msg_;
};

class Init_NavigateTo_Event_request
{
public:
  explicit Init_NavigateTo_Event_request(::my_turtle_interfaces::srv::NavigateTo_Event & msg)
  : msg_(msg)
  {}
  Init_NavigateTo_Event_response request(::my_turtle_interfaces::srv::NavigateTo_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_NavigateTo_Event_response(msg_);
  }

private:
  ::my_turtle_interfaces::srv::NavigateTo_Event msg_;
};

class Init_NavigateTo_Event_info
{
public:
  Init_NavigateTo_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateTo_Event_request info(::my_turtle_interfaces::srv::NavigateTo_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_NavigateTo_Event_request(msg_);
  }

private:
  ::my_turtle_interfaces::srv::NavigateTo_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_turtle_interfaces::srv::NavigateTo_Event>()
{
  return my_turtle_interfaces::srv::builder::Init_NavigateTo_Event_info();
}

}  // namespace my_turtle_interfaces

#endif  // MY_TURTLE_INTERFACES__SRV__DETAIL__NAVIGATE_TO__BUILDER_HPP_
