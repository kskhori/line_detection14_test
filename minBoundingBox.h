//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// minBoundingBox.h
//
// Code generation for function 'minBoundingBox'
//

#ifndef MINBOUNDINGBOX_H
#define MINBOUNDINGBOX_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void binary_expand_op(coder::array<double, 2U> &R,
                      const coder::array<double, 2U> &bound,
                      const coder::array<double, 2U> &T);

void minus(coder::array<double, 1U> &bsize, const coder::array<double, 1U> &r);

#endif
// End of code generation (minBoundingBox.h)
