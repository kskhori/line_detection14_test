//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sensor_msgs_ImageStruct.cpp
//
// Code generation for function 'sensor_msgs_ImageStruct'
//

// Include files
#include "sensor_msgs_ImageStruct.h"
#include "line_detection14_data.h"
#include "line_detection14_types.h"
#include "rt_nonfinite.h"
#include "std_msgs_HeaderStruct.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
void sensor_msgs_ImageStruct(sensor_msgs_ImageStruct_T *msg)
{
  //  Message struct definition for sensor_msgs/Image
  std_msgs_HeaderStruct(&msg->Header);
  for (int i{0}; i < 17; i++) {
    msg->MessageType[i] = cv[i];
  }
  msg->Height = 0U;
  msg->Width = 0U;
  msg->Encoding.set_size(1, 0);
  msg->IsBigendian = 0U;
  msg->Step = 0U;
  msg->Data.set_size(0);
  //(msg);
}

// End of code generation (sensor_msgs_ImageStruct.cpp)
