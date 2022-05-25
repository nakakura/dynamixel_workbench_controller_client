cmake_minimum_required(VERSION 3.0.2)
project(dynamixel_workbench_controller_client)

find_package(catkin REQUIRED COMPONENTS
  roscpp std_msgs dynamixel_workbench_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/main.cpp)

add_dependencies(${PROJECT_NAME}
        ${${PROJECT_NAME}_EXPORTED_TARGETS}
        ${catkin_EXPORTED_TARGETS}
        dynamixel_workbench_controllers)

target_link_libraries(${PROJECT_NAME}
   ${catkin_LIBRARIES}
)
