#ifndef _ROS_STRUCTMSG_CONVERSION_H_
#define _ROS_STRUCTMSG_CONVERSION_H_

#include <ros/ros.h>
#include <darknet_ros_msgs/BoundingBox.h>
#include <darknet_ros_msgs/BoundingBoxes.h>
#include <ros/time.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/Header.h>
#include <std_msgs/Int32.h>
#include "line_detection14_types.h"
#include "mlroscpp_msgconvert_utils.h"


void struct2msg(darknet_ros_msgs::BoundingBox* msgPtr, darknet_ros_msgs_BoundingBoxStruct_T const* structPtr);
void msg2struct(darknet_ros_msgs_BoundingBoxStruct_T* structPtr, darknet_ros_msgs::BoundingBox const* msgPtr);

void struct2msg(darknet_ros_msgs::BoundingBoxes* msgPtr, darknet_ros_msgs_BoundingBoxesStruct_T const* structPtr);
void msg2struct(darknet_ros_msgs_BoundingBoxesStruct_T* structPtr, darknet_ros_msgs::BoundingBoxes const* msgPtr);

void struct2msg(ros::Time* msgPtr, ros_TimeStruct_T const* structPtr);
void msg2struct(ros_TimeStruct_T* structPtr, ros::Time const* msgPtr);

void struct2msg(sensor_msgs::Image* msgPtr, sensor_msgs_ImageStruct_T const* structPtr);
void msg2struct(sensor_msgs_ImageStruct_T* structPtr, sensor_msgs::Image const* msgPtr);

void struct2msg(std_msgs::Header* msgPtr, std_msgs_HeaderStruct_T const* structPtr);
void msg2struct(std_msgs_HeaderStruct_T* structPtr, std_msgs::Header const* msgPtr);

void struct2msg(std_msgs::Int32* msgPtr, std_msgs_Int32Struct_T const* structPtr);
void msg2struct(std_msgs_Int32Struct_T* structPtr, std_msgs::Int32 const* msgPtr);


#endif
