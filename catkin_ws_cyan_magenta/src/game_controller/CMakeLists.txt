cmake_minimum_required(VERSION 2.8.3)
project(game_controller)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS
      roscpp
      std_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

###Executable node
add_executable(game_controller_node
src/nodes/game_controller_node.cpp
    ${${PROJECT_NAME}_CODE_BASE}
)

target_link_libraries(game_controller_node
    ${catkin_LIBRARIES}
)
add_dependencies(game_controller_node
    ${catkin_EXPORTED_TARGETS}
)

