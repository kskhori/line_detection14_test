//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rosWriteImage.cpp
//
// Code generation for function 'rosWriteImage'
//

// Include files
#include "rosWriteImage.h"
#include "line_detection14_types.h"
#include "permute.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>
#include <string.h>

// Function Definitions
namespace coder {
void rosWriteImage(sensor_msgs_ImageStruct_T *msg,
                   const ::coder::array<unsigned char, 3U> &varargin_1)
{
  array<unsigned char, 3U> image;
  array<unsigned char, 1U> x;
  double dv[3];
  double d;
  int i;
  int loop_ub;
  int subsa_idx_1;
  int subsa_idx_2;
  unsigned int u;
  msg->Encoding.set_size(1, 4);
  msg->Encoding[0] = 'r';
  msg->Encoding[1] = 'g';
  msg->Encoding[2] = 'b';
  msg->Encoding[3] = '8';
  dv[0] = 3.0;
  dv[1] = 2.0;
  dv[2] = 1.0;
  if (nomovement(dv, varargin_1)) {
    image.set_size(3, varargin_1.size(1), varargin_1.size(0));
    loop_ub = 3 * varargin_1.size(1) * varargin_1.size(0);
    for (i = 0; i < loop_ub; i++) {
      image[i] = varargin_1[i];
    }
  } else {
    image.set_size(3, varargin_1.size(1), varargin_1.size(0));
    i = varargin_1.size(1);
    for (int k{0}; k < 3; k++) {
      for (int b_k{0}; b_k < i; b_k++) {
        loop_ub = varargin_1.size(0);
        if (0 <= varargin_1.size(0) - 1) {
          subsa_idx_1 = b_k + 1;
          subsa_idx_2 = k + 1;
        }
        for (int c_k{0}; c_k < loop_ub; c_k++) {
          image[((subsa_idx_2 + 3 * (subsa_idx_1 - 1)) +
                 3 * image.size(1) * c_k) -
                1] = varargin_1[(c_k + varargin_1.size(0) * (subsa_idx_1 - 1)) +
                                varargin_1.size(0) * varargin_1.size(1) *
                                    (subsa_idx_2 - 1)];
        }
      }
    }
  }
  x.set_size(3 * image.size(1) * image.size(2));
  loop_ub = 3 * image.size(1) * image.size(2);
  for (i = 0; i < loop_ub; i++) {
    x[i] = image[i];
  }
  msg->Data.set_size(3 * image.size(1) * image.size(2));
  std::copy(&(x.data())[0], &(x.data())[3 * image.size(1) * image.size(2)],
            &(msg->Data.data())[0]);
  msg->Width = static_cast<unsigned int>(varargin_1.size(1));
  msg->Height = static_cast<unsigned int>(varargin_1.size(0));
  d = static_cast<double>(varargin_1.size(1)) * 3.0;
  if (d < 4.294967296E+9) {
    u = static_cast<unsigned int>(d);
  } else {
    u = MAX_uint32_T;
  }
  msg->Step = u;
}

} // namespace coder

// End of code generation (rosWriteImage.cpp)
