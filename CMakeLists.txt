cmake_minimum_required(VERSION 3.5)
project(line_detection14_test)
set(CMAKE_VERBOSE_MAKEFILE ON)

## Make top-level project name available in all nested projects.
set(MW_TOP_LEVEL_PROJECT_NAME ${PROJECT_NAME})


## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
darknet_ros_msgs
roscpp
sensor_msgs
std_msgs
)

add_definitions(
-D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DROS_PROJECT -DMW_SCHED_OTHER -DSTACK_SIZE=200000 )

## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
   CATKIN_DEPENDS darknet_ros_msgs roscpp sensor_msgs std_msgs 
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  include
  ${PROJECT_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

## Get list of .c files in project source directory
file(GLOB ${PROJECT_NAME}_C_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/*.c)
## Get list of .cpp files in project source directory
file(GLOB ${PROJECT_NAME}_CPP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/*.cpp)

## Declare executable
add_executable(${PROJECT_NAME}
   coder_posix_time.c
   insertShapeUtilsCore.cpp
   cvstDraw.cpp
   insertShapeAndMarkerUtils.cpp
   line_detection14_data.cpp
   rt_nonfinite.cpp
   rtGetNaN.cpp
   rtGetInf.cpp
   line_detection14_initialize.cpp
   line_detection14_terminate.cpp
   line_detection14.cpp
   std_msgs_Int32Struct.cpp
   sensor_msgs_ImageStruct.cpp
   std_msgs_HeaderStruct.cpp
   ros_TimeStruct.cpp
   darknet_ros_msgs_BoundingBoxesStruct.cpp
   darknet_ros_msgs_BoundingBoxStruct.cpp
   pause.cpp
   rosReadImage.cpp
   permute.cpp
   medfilt2.cpp
   imbinarize.cpp
   padarray.cpp
   imcrop.cpp
   hough.cpp
   minOrMax.cpp
   houghpeaks.cpp
   houghlines.cpp
   sortLE.cpp
   power.cpp
   repmat.cpp
   insertShape.cpp
   convhull.cpp
   qhullReject2D.cpp
   find.cpp
   diff.cpp
   unique.cpp
   useConstantDim.cpp
   sortrows.cpp
   sort.cpp
   sortIdx.cpp
   introsort.cpp
   insertionsort.cpp
   heapsort.cpp
   rosWriteImage.cpp
   minBoundingBox.cpp
   Publisher.cpp
   Subscriber.cpp
   main.cpp
   ros_structmsg_conversion.cpp
   ${${PROJECT_NAME}_C_SOURCES}
   ${${PROJECT_NAME}_CPP_SOURCES}
)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
   ${catkin_LIBRARIES}
   ${Boost_LIBRARIES}
   rt
   ${CMAKE_DL_LIBS}
)

SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -fpermissive" )
SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include stdbool.h" )
foreach(file_i ${CUDA_BINS})
add_custom_command(TARGET ${PROJECT_NAME}
POST_BUILD
COMMAND ${CMAKE_COMMAND}
ARGS -E copy ${PROJECT_SOURCE_DIR}/${file_i} ${CATKIN_DEVEL_PREFIX}/untitled_ert_rtw/${file_i})
endforeach( file_i )
