//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// diff.cpp
//
// Code generation for function 'diff'
//

// Include files
#include "diff.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
namespace coder {
void diff(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U> &y)
{
  int dimSize;
  dimSize = x.size(1);
  if (x.size(1) <= 1) {
    y.set_size(x.size(0), 0);
  } else {
    y.set_size(x.size(0), x.size(1) - 1);
    if (x.size(0) != 0) {
      int iy;
      int stride;
      stride = x.size(0);
      iy = 0;
      for (int s{0}; s < stride; s++) {
        double work;
        int ixLead;
        ixLead = s + stride;
        work = x[s];
        for (int m{2}; m <= dimSize; m++) {
          double tmp2;
          int work_tmp;
          int work_tmp_tmp;
          tmp2 = work;
          work_tmp_tmp = (m - 2) * stride;
          work_tmp = ixLead + work_tmp_tmp;
          work = x[work_tmp];
          y[iy + work_tmp_tmp] = x[work_tmp] - tmp2;
        }
        iy++;
      }
    }
  }
}

} // namespace coder

// End of code generation (diff.cpp)
