#include "ros_structmsg_conversion.h"


// Conversions between darknet_ros_msgs_BoundingBoxStruct_T and darknet_ros_msgs::BoundingBox

void struct2msg(darknet_ros_msgs::BoundingBox* msgPtr, darknet_ros_msgs_BoundingBoxStruct_T const* structPtr)
{
  const std::string rosMessageType("darknet_ros_msgs/BoundingBox");

  convertFromStructPrimitiveArray(msgPtr->Class, structPtr->Class);
//  msgPtr->id =  structPtr->Id;
  msgPtr->probability =  structPtr->Probability;
  msgPtr->xmax = (int64_t) structPtr->Xmax;
  msgPtr->xmin = (int64_t) structPtr->Xmin;
  msgPtr->ymax = (int64_t) structPtr->Ymax;
  msgPtr->ymin = (int64_t) structPtr->Ymin;
}

void msg2struct(darknet_ros_msgs_BoundingBoxStruct_T* structPtr, darknet_ros_msgs::BoundingBox const* msgPtr)
{
  const std::string rosMessageType("darknet_ros_msgs/BoundingBox");

  convertToStructPrimitiveArray(structPtr->Class, msgPtr->Class);
//  structPtr->Id =  msgPtr->id;
  structPtr->Probability =  msgPtr->probability;
  structPtr->Xmax = (real_T) msgPtr->xmax;
  structPtr->Xmin = (real_T) msgPtr->xmin;
  structPtr->Ymax = (real_T) msgPtr->ymax;
  structPtr->Ymin = (real_T) msgPtr->ymin;
}


// Conversions between darknet_ros_msgs_BoundingBoxesStruct_T and darknet_ros_msgs::BoundingBoxes

void struct2msg(darknet_ros_msgs::BoundingBoxes* msgPtr, darknet_ros_msgs_BoundingBoxesStruct_T const* structPtr)
{
  const std::string rosMessageType("darknet_ros_msgs/BoundingBoxes");

  convertFromStructNestedArray(msgPtr->bounding_boxes, structPtr->BoundingBoxes_);
  struct2msg(&msgPtr->header, &structPtr->Header);
  struct2msg(&msgPtr->image_header, &structPtr->ImageHeader);
}

void msg2struct(darknet_ros_msgs_BoundingBoxesStruct_T* structPtr, darknet_ros_msgs::BoundingBoxes const* msgPtr)
{
  const std::string rosMessageType("darknet_ros_msgs/BoundingBoxes");

  convertToStructNestedArray(structPtr->BoundingBoxes_, msgPtr->bounding_boxes);
  msg2struct(&structPtr->Header, &msgPtr->header);
  msg2struct(&structPtr->ImageHeader, &msgPtr->image_header);
}


// Conversions between ros_TimeStruct_T and ros::Time

void struct2msg(ros::Time* msgPtr, ros_TimeStruct_T const* structPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->nsec =  structPtr->Nsec;
  msgPtr->sec =  structPtr->Sec;
}

void msg2struct(ros_TimeStruct_T* structPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  structPtr->Nsec =  msgPtr->nsec;
  structPtr->Sec =  msgPtr->sec;
}


// Conversions between sensor_msgs_ImageStruct_T and sensor_msgs::Image

void struct2msg(sensor_msgs::Image* msgPtr, sensor_msgs_ImageStruct_T const* structPtr)
{
  const std::string rosMessageType("sensor_msgs/Image");

  convertFromStructPrimitiveArray(msgPtr->data, structPtr->Data);
  convertFromStructPrimitiveArray(msgPtr->encoding, structPtr->Encoding);
  struct2msg(&msgPtr->header, &structPtr->Header);
  msgPtr->height =  structPtr->Height;
  msgPtr->is_bigendian =  structPtr->IsBigendian;
  msgPtr->step =  structPtr->Step;
  msgPtr->width =  structPtr->Width;
}

void msg2struct(sensor_msgs_ImageStruct_T* structPtr, sensor_msgs::Image const* msgPtr)
{
  const std::string rosMessageType("sensor_msgs/Image");

  convertToStructPrimitiveArray(structPtr->Data, msgPtr->data);
  convertToStructPrimitiveArray(structPtr->Encoding, msgPtr->encoding);
  msg2struct(&structPtr->Header, &msgPtr->header);
  structPtr->Height =  msgPtr->height;
  structPtr->IsBigendian =  msgPtr->is_bigendian;
  structPtr->Step =  msgPtr->step;
  structPtr->Width =  msgPtr->width;
}


// Conversions between std_msgs_HeaderStruct_T and std_msgs::Header

void struct2msg(std_msgs::Header* msgPtr, std_msgs_HeaderStruct_T const* structPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromStructPrimitiveArray(msgPtr->frame_id, structPtr->FrameId);
  msgPtr->seq =  structPtr->Seq;
  struct2msg(&msgPtr->stamp, &structPtr->Stamp);
}

void msg2struct(std_msgs_HeaderStruct_T* structPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToStructPrimitiveArray(structPtr->FrameId, msgPtr->frame_id);
  structPtr->Seq =  msgPtr->seq;
  msg2struct(&structPtr->Stamp, &msgPtr->stamp);
}


// Conversions between std_msgs_Int32Struct_T and std_msgs::Int32

void struct2msg(std_msgs::Int32* msgPtr, std_msgs_Int32Struct_T const* structPtr)
{
  const std::string rosMessageType("std_msgs/Int32");

  msgPtr->data =  structPtr->Data;
}

void msg2struct(std_msgs_Int32Struct_T* structPtr, std_msgs::Int32 const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Int32");

  structPtr->Data =  msgPtr->data;
}

