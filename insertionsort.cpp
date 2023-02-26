//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// insertionsort.cpp
//
// Code generation for function 'insertionsort'
//

// Include files
#include "insertionsort.h"
#include "anonymous_function.h"
#include "line_detection14_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
namespace coder {
namespace internal {
void insertionsort(::coder::array<double, 1U> &x, int xstart, int xend,
                   const anonymous_function *cmp)
{
  int i;
  i = xstart + 1;
  for (int k{i}; k <= xend; k++) {
    double xc;
    int idx;
    bool exitg1;
    xc = x[k - 1];
    idx = k - 2;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= xstart)) {
      double d;
      bool varargout_1;
      d = cmp->workspace
              .pts[(static_cast<int>(xc) + cmp->workspace.pts.size(0)) - 1];
      if (cmp->workspace
              .pts[(static_cast<int>(x[idx]) + cmp->workspace.pts.size(0)) -
                   1] > d) {
        varargout_1 = true;
      } else {
        int i1;
        i1 = static_cast<int>(x[idx]) - 1;
        if (cmp->workspace.pts[i1 + cmp->workspace.pts.size(0)] < d) {
          varargout_1 = false;
        } else {
          varargout_1 = (cmp->workspace.pts[i1] >
                         cmp->workspace.pts[static_cast<int>(xc) - 1]);
        }
      }
      if (varargout_1) {
        x[idx + 1] = x[idx];
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x[idx + 1] = xc;
  }
}

} // namespace internal
} // namespace coder

// End of code generation (insertionsort.cpp)
