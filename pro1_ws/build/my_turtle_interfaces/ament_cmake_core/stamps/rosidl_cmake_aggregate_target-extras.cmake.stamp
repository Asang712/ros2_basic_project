# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target my_turtle_interfaces::my_turtle_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${my_turtle_interfaces_TARGETS}.
if(my_turtle_interfaces_TARGETS AND NOT TARGET my_turtle_interfaces::my_turtle_interfaces)
  add_library(my_turtle_interfaces::my_turtle_interfaces INTERFACE IMPORTED)
  set_target_properties(my_turtle_interfaces::my_turtle_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${my_turtle_interfaces_TARGETS}")
endif()
