//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Publisher.h
//
// Code generation for function 'Publisher'
//

#ifndef PUBLISHER_H
#define PUBLISHER_H

// Include files
#include "line_detection14_types.h"
#include "rtwtypes.h"
#include "mlroscpp_pub.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace ros {
class Publisher {
public:
  Publisher *init();
  static void rosmessage(char msgFromPub_MessageType[14], int *msgFromPub_Data);
  static void rosmessage(sensor_msgs_ImageStruct_T *msgFromPub);
  void send(const std_msgs_Int32Struct_T msgToSend);
  void matlabCodegenDestructor();
  ~Publisher();
  Publisher();

private:
  void Publisher_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[11];
  double BufferSize;
  bool IsLatching;

private:
  std_msgs_Int32Struct_T MsgStruct;
  MATLABPublisher<std_msgs::Int32, std_msgs_Int32Struct_T> *PublisherHelper;
};

class b_Publisher {
public:
  b_Publisher *init();
  void send(const sensor_msgs_ImageStruct_T *msgToSend);
  void matlabCodegenDestructor();
  ~b_Publisher();
  b_Publisher();

private:
  void Publisher_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[9];
  double BufferSize;
  bool IsLatching;

private:
  sensor_msgs_ImageStruct_T MsgStruct;
  MATLABPublisher<sensor_msgs::Image, sensor_msgs_ImageStruct_T>
      *PublisherHelper;
};

} // namespace ros
} // namespace coder

#endif
// End of code generation (Publisher.h)
