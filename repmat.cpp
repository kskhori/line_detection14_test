//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// repmat.cpp
//
// Code generation for function 'repmat'
//

// Include files
#include "repmat.h"
#include "line_detection14_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
namespace coder {
void repmat(int varargin_2, ::coder::array<b_struct_T, 2U> &b)
{
  b_struct_T s;
  s.point1[0] = 0.0;
  s.point2[0] = 0.0;
  s.point1[1] = 0.0;
  s.point2[1] = 0.0;
  s.theta = 0.0;
  s.rho = 0.0;
  b.set_size(1, varargin_2);
  for (int i{0}; i < varargin_2; i++) {
    b[i] = s;
  }
}

} // namespace coder

// End of code generation (repmat.cpp)
