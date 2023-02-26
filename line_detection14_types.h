//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// line_detection14_types.h
//
// Code generation for function 'line_detection14'
//

#ifndef LINE_DETECTION14_TYPES_H
#define LINE_DETECTION14_TYPES_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
struct ros_TimeStruct_T {
  unsigned int Sec;
  unsigned int Nsec;
};

struct std_msgs_Int32Struct_T {
  char MessageType[14];
  int Data;
};

struct int64m_T {
  unsigned int chunks[2];
};

struct darknet_ros_msgs_BoundingBoxStruct_T {
  char MessageType[28];
  double Probability;
  long Xmin;
  long Ymin;
  long Xmax;
  long Ymax;
  short Id;
  coder::array<char, 2U> Class;
};

struct std_msgs_HeaderStruct_T {
  char MessageType[15];
  unsigned int Seq;
  ros_TimeStruct_T Stamp;
  coder::array<char, 2U> FrameId;
};

struct darknet_ros_msgs_BoundingBoxesStruct_T {
  char MessageType[30];
  std_msgs_HeaderStruct_T Header;
  std_msgs_HeaderStruct_T ImageHeader;
  coder::array<darknet_ros_msgs_BoundingBoxStruct_T, 1U> BoundingBoxes_;
};

struct sensor_msgs_ImageStruct_T {
  char MessageType[17];
  std_msgs_HeaderStruct_T Header;
  unsigned int Height;
  unsigned int Width;
  coder::array<char, 2U> Encoding;
  unsigned char IsBigendian;
  unsigned int Step;
  coder::array<unsigned char, 1U> Data;
};

#endif
// End of code generation (line_detection14_types.h)
