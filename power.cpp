//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// power.cpp
//
// Code generation for function 'power'
//

// Include files
#include "power.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
namespace coder {
int power(int a)
{
  int b_a;
  int bu;
  int y;
  b_a = a;
  y = 1;
  bu = 2;
  int exitg1;
  do {
    exitg1 = 0;
    if ((bu & 1) != 0) {
      y *= b_a;
    }
    bu >>= 1;
    if (bu == 0) {
      exitg1 = 1;
    } else {
      b_a *= b_a;
    }
  } while (exitg1 == 0);
  return y;
}

} // namespace coder

// End of code generation (power.cpp)
