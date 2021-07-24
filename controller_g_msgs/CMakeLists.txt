cmake_minimum_required(VERSION 3.0.2)
project(controller_g_msgs)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
  roscpp
  rospy
)

add_service_files(
  FILES
  GetStance.srv
)

generate_messages(
  DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES controller_g_msgs
  CATKIN_DEPENDS roscpp rospy message_runtime
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
