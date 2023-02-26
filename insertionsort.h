//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// insertionsort.h
//
// Code generation for function 'insertionsort'
//

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class anonymous_function;

}

// Function Declarations
namespace coder {
namespace internal {
void insertionsort(::coder::array<double, 1U> &x, int xstart, int xend,
                   const anonymous_function *cmp);

}
} // namespace coder

#endif
// End of code generation (insertionsort.h)
