cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(cpp_node src/my_first_node.cpp)
ament_target_dependencies(cpp_node rclcpp)

add_executable(minimal_publisher src/my_node_publisher.cpp)
ament_target_dependencies(minimal_publisher rclcpp example_interfaces)

add_executable(minimal_subscriber src/my_node_subscriber.cpp)
ament_target_dependencies(minimal_subscriber rclcpp example_interfaces)

add_executable(number_publisher src/my_node_publisher_number.cpp)
ament_target_dependencies(number_publisher rclcpp example_interfaces)

install(TARGETS
    cpp_node
    minimal_publisher
    minimal_subscriber
    number_publisher
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
