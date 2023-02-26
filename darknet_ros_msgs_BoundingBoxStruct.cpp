//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// darknet_ros_msgs_BoundingBoxStruct.cpp
//
// Code generation for function 'darknet_ros_msgs_BoundingBoxStruct'
//

// Include files
#include "darknet_ros_msgs_BoundingBoxStruct.h"
#include "line_detection14_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
void darknet_ros_msgs_BoundingBoxStruct(
    darknet_ros_msgs_BoundingBoxStruct_T *msg)
{
  static const int64m_T r{
      {0U, 0U} // chunks
  };
  static const char b_cv[28]{'d', 'a', 'r', 'k', 'n', 'e', 't', '_', 'r', 'o',
                             's', '_', 'm', 's', 'g', 's', '/', 'B', 'o', 'u',
                             'n', 'd', 'i', 'n', 'g', 'B', 'o', 'x'};
  //  Message struct definition for darknet_ros_msgs/BoundingBox
  for (int i{0}; i < 28; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->Probability = 0.0;
  msg->Xmin = 0;
  msg->Ymin = 0;
  msg->Xmax = 0;
  msg->Ymax = 0;
  msg->Id = 0;
  msg->Class.set_size(1, 0);
  //(msg);
}

// End of code generation (darknet_ros_msgs_BoundingBoxStruct.cpp)
