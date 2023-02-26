//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Subscriber.h
//
// Code generation for function 'Subscriber'
//

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

// Include files
#include "line_detection14_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "mutex"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace ros {
class Subscriber {
public:
  Subscriber *init();
  void lock();
  void unlock();
  void callback();
  double get_MessageCount() const;
  void receive(char receivedMsg_MessageType[17],
               unsigned int *receivedMsg_Height,
               unsigned int *receivedMsg_Width,
               ::coder::array<unsigned char, 1U> &receivedMsg_Data);
  void get_LatestMessage(char lastSubMsg_MessageType[17],
                         unsigned int *lastSubMsg_Height,
                         unsigned int *lastSubMsg_Width,
                         ::coder::array<unsigned char, 1U> &lastSubMsg_Data);
  void matlabCodegenDestructor();
  ~Subscriber();
  Subscriber();

private:
  void Subscriber_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[10];
  double BufferSize;
  double MessageCount;

private:
  void *SubscriberHelper;
  sensor_msgs_ImageStruct_T MsgStruct;
  std::mutex Mutex;
};

class b_Subscriber {
public:
  b_Subscriber *init();
  void lock();
  void unlock();
  void callback();
  double get_MessageCount() const;
  void receive(::coder::array<darknet_ros_msgs_BoundingBoxStruct_T, 1U>
                   &receivedMsg_BoundingBoxes_);
  void get_LatestMessage(::coder::array<darknet_ros_msgs_BoundingBoxStruct_T,
                                        1U> &lastSubMsg_BoundingBoxes_);
  void matlabCodegenDestructor();
  ~b_Subscriber();
  b_Subscriber();

private:
  void Subscriber_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[27];
  double BufferSize;
  double MessageCount;

private:
  void *SubscriberHelper;
  darknet_ros_msgs_BoundingBoxesStruct_T MsgStruct;
  std::mutex Mutex;
};

} // namespace ros
} // namespace coder

#endif
// End of code generation (Subscriber.h)
