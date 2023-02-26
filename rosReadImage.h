//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rosReadImage.h
//
// Code generation for function 'rosReadImage'
//

#ifndef ROSREADIMAGE_H
#define ROSREADIMAGE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void rosReadImage(const char msg_MessageType[17], unsigned int msg_Height,
                  unsigned int msg_Width,
                  const ::coder::array<unsigned char, 1U> &msg_Data,
                  ::coder::array<unsigned char, 3U> &img);

}

#endif
// End of code generation (rosReadImage.h)
