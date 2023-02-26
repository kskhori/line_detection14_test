//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sortLE.cpp
//
// Code generation for function 'sortLE'
//

// Include files
#include "sortLE.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
namespace coder {
namespace internal {
bool sortLE(const ::coder::array<int, 2U> &v, const int dir[2], int idx1,
            int idx2)
{
  int k;
  bool exitg1;
  bool p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    int abscolk;
    int v1;
    if (dir[k] < 0) {
      abscolk = -dir[k];
    } else {
      abscolk = dir[k];
    }
    v1 = v[(idx1 + v.size(0) * (abscolk - 1)) - 1];
    abscolk = v[(idx2 + v.size(0) * (abscolk - 1)) - 1];
    if (v1 == abscolk) {
      k++;
    } else {
      if (dir[k] < 0) {
        p = (v1 >= abscolk);
      } else {
        p = (v1 <= abscolk);
      }
      exitg1 = true;
    }
  }
  return p;
}

} // namespace internal
} // namespace coder

// End of code generation (sortLE.cpp)
