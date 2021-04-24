cmake_minimum_required(VERSION 3.0.2)
project(turtlesim_msg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  turtlesim
  message_generation
)

add_message_files(
  FILES
  Info.msg
)

add_service_files(
  FILES
  AddTwoFloats.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(add_two_floats_server src/add_two_floats_server.cpp)
target_link_libraries(add_two_floats_server ${catkin_LIBRARIES})

add_executable(showInfo src/showInfo.cpp)
target_link_libraries(showInfo ${catkin_LIBRARIES})
