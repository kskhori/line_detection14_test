//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Publisher.cpp
//
// Code generation for function 'Publisher'
//

// Include files
#include "Publisher.h"
#include "line_detection14_types.h"
#include "rt_nonfinite.h"
#include "sensor_msgs_ImageStruct.h"
#include "std_msgs_Int32Struct.h"
#include "mlroscpp_pub.h"
#include <string.h>

// Function Definitions
namespace coder {
namespace ros {
void Publisher::Publisher_delete() const
{
  delete (PublisherHelper);
}

void b_Publisher::Publisher_delete() const
{
  delete (PublisherHelper);
}

void Publisher::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    Publisher_delete();
  }
}

void b_Publisher::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    Publisher_delete();
  }
}

Publisher::Publisher()
{
  matlabCodegenIsDeleted = true;
}

b_Publisher::b_Publisher()
{
  matlabCodegenIsDeleted = true;
}

Publisher::~Publisher()
{
  matlabCodegenDestructor();
}

b_Publisher::~b_Publisher()
{
  matlabCodegenDestructor();
}

Publisher *Publisher::init()
{
  static const char topic[11]{'/', 'T', 'H', 'K', '_', 's',
                              'l', 'i', 'd', 'e', 'e'};
  Publisher *obj;
  obj = this;
  for (int i{0}; i < 11; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = true;
  obj->MsgStruct = std_msgs_Int32Struct();
  auto pub =
      new MATLABPublisher<std_msgs::Int32, std_msgs_Int32Struct_T>(); //();
  pub->createPublisher(&obj->TopicName[0], 11.0, obj->BufferSize,
                       obj->IsLatching);
  obj->PublisherHelper = pub; //();
  //(obj->PublisherHelper);
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

b_Publisher *b_Publisher::init()
{
  static const char topic[9]{'/', 'i', 'm', 'a', 'g', 'e', '_', 'H', 'T'};
  b_Publisher *obj;
  obj = this;
  for (int i{0}; i < 9; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = true;
  sensor_msgs_ImageStruct(&obj->MsgStruct);
  auto pub = new MATLABPublisher<sensor_msgs::Image,
                                 sensor_msgs_ImageStruct_T>(); //();
  pub->createPublisher(&obj->TopicName[0], 9.0, obj->BufferSize,
                       obj->IsLatching);
  obj->PublisherHelper = pub; //();
  //(obj->PublisherHelper);
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

void Publisher::rosmessage(char msgFromPub_MessageType[14],
                           int *msgFromPub_Data)
{
  std_msgs_Int32Struct_T expl_temp;
  expl_temp = std_msgs_Int32Struct();
  for (int i{0}; i < 14; i++) {
    msgFromPub_MessageType[i] = expl_temp.MessageType[i];
  }
  *msgFromPub_Data = expl_temp.Data;
}

void Publisher::rosmessage(sensor_msgs_ImageStruct_T *msgFromPub)
{
  sensor_msgs_ImageStruct(msgFromPub);
}

void Publisher::send(const std_msgs_Int32Struct_T msgToSend)
{
  //(&MsgStruct);
  this->PublisherHelper->publish(msgToSend);
}

void b_Publisher::send(const sensor_msgs_ImageStruct_T *msgToSend)
{
  //(&MsgStruct);
  this->PublisherHelper->publish(*msgToSend);
}

} // namespace ros
} // namespace coder

// End of code generation (Publisher.cpp)
