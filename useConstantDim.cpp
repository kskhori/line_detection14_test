//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// useConstantDim.cpp
//
// Code generation for function 'useConstantDim'
//

// Include files
#include "useConstantDim.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
namespace coder {
namespace internal {
void useConstantDim(::coder::array<double, 2U> &varargin_2, int varargin_3)
{
  int subsb_idx_1;
  if (1 == varargin_3) {
    if ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0)) {
      int i;
      i = varargin_2.size(1);
      for (int k{0}; k < i; k++) {
        int i1;
        i1 = varargin_2.size(0);
        if (0 <= i1 - 2) {
          subsb_idx_1 = k + 1;
        }
        for (int b_k{0}; b_k <= i1 - 2; b_k++) {
          varargin_2[(b_k + varargin_2.size(0) * (subsb_idx_1 - 1)) + 1] =
              varargin_2[b_k + varargin_2.size(0) * k] +
              varargin_2[(b_k + varargin_2.size(0) * (subsb_idx_1 - 1)) + 1];
        }
      }
    }
  } else if ((2 == varargin_3) &&
             ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0))) {
    int i;
    i = varargin_2.size(1);
    for (int k{0}; k <= i - 2; k++) {
      int i1;
      i1 = varargin_2.size(0);
      for (int b_k{0}; b_k < i1; b_k++) {
        varargin_2[b_k + varargin_2.size(0) * (k + 1)] =
            varargin_2[b_k + varargin_2.size(0) * k] +
            varargin_2[b_k + varargin_2.size(0) * (k + 1)];
      }
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (useConstantDim.cpp)
