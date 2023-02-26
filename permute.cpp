//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// permute.cpp
//
// Code generation for function 'permute'
//

// Include files
#include "permute.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
namespace coder {
bool nomovement(const double perm[3],
                const ::coder::array<unsigned char, 3U> &a)
{
  bool b;
  b = true;
  if ((a.size(0) != 0) && (a.size(1) != 0)) {
    double plast;
    int k;
    bool exitg1;
    plast = 0.0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      int i;
      if (perm[k] <= 3.0) {
        i = a.size(static_cast<int>(perm[k]) - 1);
      } else {
        i = 1;
      }
      if (i != 1) {
        if (plast > perm[k]) {
          b = false;
          exitg1 = true;
        } else {
          plast = perm[k];
          k++;
        }
      } else {
        k++;
      }
    }
  }
  return b;
}

} // namespace coder

// End of code generation (permute.cpp)
