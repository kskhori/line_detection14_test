//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Subscriber.cpp
//
// Code generation for function 'Subscriber'
//

// Include files
#include "Subscriber.h"
#include "darknet_ros_msgs_BoundingBoxesStruct.h"
#include "line_detection14_types.h"
#include "rt_nonfinite.h"
#include "sensor_msgs_ImageStruct.h"
#include "coder_array.h"
#include "mlroscpp_sub.h"
#include "mutex"
#include <string.h>

// Function Definitions
namespace coder {
namespace ros {
void Subscriber::Subscriber_delete() const
{
  delete (SubscriberHelper);
}

void b_Subscriber::Subscriber_delete() const
{
  delete (SubscriberHelper);
}

void Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

void b_Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

void Subscriber::get_LatestMessage(
    char lastSubMsg_MessageType[17], unsigned int *lastSubMsg_Height,
    unsigned int *lastSubMsg_Width,
    ::coder::array<unsigned char, 1U> &lastSubMsg_Data)
{
  int i;
  int loop_ub;
  lock();
  for (i = 0; i < 17; i++) {
    lastSubMsg_MessageType[i] = MsgStruct.MessageType[i];
  }
  *lastSubMsg_Height = MsgStruct.Height;
  *lastSubMsg_Width = MsgStruct.Width;
  lastSubMsg_Data.set_size(MsgStruct.Data.size(0));
  loop_ub = MsgStruct.Data.size(0);
  for (i = 0; i < loop_ub; i++) {
    lastSubMsg_Data[i] = MsgStruct.Data[i];
  }
  unlock();
}

void b_Subscriber::get_LatestMessage(
    ::coder::array<darknet_ros_msgs_BoundingBoxStruct_T, 1U>
        &lastSubMsg_BoundingBoxes_)
{
  int loop_ub;
  lock();
  lastSubMsg_BoundingBoxes_.set_size(MsgStruct.BoundingBoxes_.size(0));
  loop_ub = MsgStruct.BoundingBoxes_.size(0);
  for (int i{0}; i < loop_ub; i++) {
    lastSubMsg_BoundingBoxes_[i] = MsgStruct.BoundingBoxes_[i];
  }
  unlock();
}

double Subscriber::get_MessageCount() const
{
  return MessageCount;
}

double b_Subscriber::get_MessageCount() const
{
  return MessageCount;
}

void Subscriber::lock()
{
  this->Mutex.lock(); //(&Mutex);
}

void b_Subscriber::lock()
{
  this->Mutex.lock(); //(&Mutex);
}

void Subscriber::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    Subscriber_delete();
  }
}

void b_Subscriber::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    Subscriber_delete();
  }
}

void Subscriber::unlock()
{
  this->Mutex.unlock(); //(&Mutex);
}

void b_Subscriber::unlock()
{
  this->Mutex.unlock(); //(&Mutex);
}

Subscriber::Subscriber()
{
  matlabCodegenIsDeleted = true;
}

b_Subscriber::b_Subscriber()
{
  matlabCodegenIsDeleted = true;
}

Subscriber::~Subscriber()
{
  matlabCodegenDestructor();
}

b_Subscriber::~b_Subscriber()
{
  matlabCodegenDestructor();
}

Subscriber *Subscriber::init()
{
  static const char topic[10]{'/', 'i', 'm', 'a', 'g', 'e', '_', 'r', 'a', 'w'};
  Subscriber *obj;
  obj = this;
  for (int i{0}; i < 10; i++) {
    obj->TopicName[i] = topic[i];
  }
  void *input;
  obj->BufferSize = 1.0;
  obj->MessageCount = -1.0;
  //(&obj->Mutex);
  obj->lock();
  obj->unlock();
  sensor_msgs_ImageStruct(&obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  sensor_msgs::Image *msgPtr = nullptr;                //();
  auto sub = make_subscriber(this, msgPtr, structPtr); //();
  sub->createSubscriber(&obj->TopicName[0], 10.0, obj->BufferSize);
  obj->SubscriberHelper = sub; //();
  input = obj->SubscriberHelper;
  //(input);
  obj->callback();
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

b_Subscriber *b_Subscriber::init()
{
  static const char topic[27]{'/', 'd', 'a', 'r', 'k', 'n', 'e', 't', '_',
                              'r', 'o', 's', '/', 'b', 'o', 'u', 'n', 'd',
                              'i', 'n', 'g', '_', 'b', 'o', 'x', 'e', 's'};
  b_Subscriber *obj;
  obj = this;
  for (int i{0}; i < 27; i++) {
    obj->TopicName[i] = topic[i];
  }
  void *input;
  obj->BufferSize = 1.0;
  obj->MessageCount = -1.0;
  //(&obj->Mutex);
  obj->lock();
  obj->unlock();
  darknet_ros_msgs_BoundingBoxesStruct(&obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  darknet_ros_msgs::BoundingBoxes *msgPtr = nullptr;   //();
  auto sub = make_subscriber(this, msgPtr, structPtr); //();
  sub->createSubscriber(&obj->TopicName[0], 27.0, obj->BufferSize);
  obj->SubscriberHelper = sub; //();
  input = obj->SubscriberHelper;
  //(input);
  obj->callback();
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

void Subscriber::receive(char receivedMsg_MessageType[17],
                         unsigned int *receivedMsg_Height,
                         unsigned int *receivedMsg_Width,
                         ::coder::array<unsigned char, 1U> &receivedMsg_Data)
{
  static const char b_statusText[7]{'t', 'i', 'm', 'e', 'o', 'u', 't'};
  double nMessages;
  char statusText[7];
  nMessages = get_MessageCount();
  for (int i{0}; i < 7; i++) {
    statusText[i] = b_statusText[i];
  }
  while (get_MessageCount() == nMessages) {
  }
  getStatusText(true, &statusText[0]);
  get_LatestMessage(receivedMsg_MessageType, receivedMsg_Height,
                    receivedMsg_Width, receivedMsg_Data);
}

void b_Subscriber::receive(::coder::array<darknet_ros_msgs_BoundingBoxStruct_T,
                                          1U> &receivedMsg_BoundingBoxes_)
{
  static const char b_statusText[7]{'t', 'i', 'm', 'e', 'o', 'u', 't'};
  double nMessages;
  char statusText[7];
  nMessages = get_MessageCount();
  for (int i{0}; i < 7; i++) {
    statusText[i] = b_statusText[i];
  }
  while (get_MessageCount() == nMessages) {
  }
  getStatusText(true, &statusText[0]);
  get_LatestMessage(receivedMsg_BoundingBoxes_);
}

} // namespace ros
} // namespace coder

// End of code generation (Subscriber.cpp)
