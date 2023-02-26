//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rosWriteImage.h
//
// Code generation for function 'rosWriteImage'
//

#ifndef ROSWRITEIMAGE_H
#define ROSWRITEIMAGE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct sensor_msgs_ImageStruct_T;

// Function Declarations
namespace coder {
void rosWriteImage(sensor_msgs_ImageStruct_T *msg,
                   const ::coder::array<unsigned char, 3U> &varargin_1);

}

#endif
// End of code generation (rosWriteImage.h)
