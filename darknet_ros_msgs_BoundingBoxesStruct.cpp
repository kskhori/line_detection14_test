//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// darknet_ros_msgs_BoundingBoxesStruct.cpp
//
// Code generation for function 'darknet_ros_msgs_BoundingBoxesStruct'
//

// Include files
#include "darknet_ros_msgs_BoundingBoxesStruct.h"
#include "darknet_ros_msgs_BoundingBoxStruct.h"
#include "line_detection14_types.h"
#include "rt_nonfinite.h"
#include "std_msgs_HeaderStruct.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
void darknet_ros_msgs_BoundingBoxesStruct(
    darknet_ros_msgs_BoundingBoxesStruct_T *msg)
{
  static const char b_cv[30]{'d', 'a', 'r', 'k', 'n', 'e', 't', '_', 'r', 'o',
                             's', '_', 'm', 's', 'g', 's', '/', 'B', 'o', 'u',
                             'n', 'd', 'i', 'n', 'g', 'B', 'o', 'x', 'e', 's'};
  darknet_ros_msgs_BoundingBoxStruct_T t3_BoundingBoxes_;
  //  Message struct definition for darknet_ros_msgs/BoundingBoxes
  std_msgs_HeaderStruct(&msg->Header);
  std_msgs_HeaderStruct(&msg->ImageHeader);
  darknet_ros_msgs_BoundingBoxStruct(&t3_BoundingBoxes_);
  for (int i{0}; i < 30; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->BoundingBoxes_.set_size(1);
  msg->BoundingBoxes_[0] = t3_BoundingBoxes_;
  msg->BoundingBoxes_.set_size(0);
  //(msg);
}

// End of code generation (darknet_ros_msgs_BoundingBoxesStruct.cpp)
