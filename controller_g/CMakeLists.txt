cmake_minimum_required(VERSION 3.0.2)
project(controller_g)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fno-diagnostics-color")

find_package(catkin REQUIRED COMPONENTS
    controller_g_msgs
    std_msgs
    nodelet
    roscpp
    rospy
    mrs_lib
    mrs_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ControllerG
  CATKIN_DEPENDS rospy roscpp std_msgs controller_g_msgs mrs_msgs mrs_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(ControllerG src/ControllerG.cpp)
add_dependencies(ControllerG ${catkin_EXPORTED_TARGETS})

target_link_libraries(ControllerG
    ${catkin_LIBRARIES}
)