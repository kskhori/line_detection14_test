//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// minBoundingBox.cpp
//
// Code generation for function 'minBoundingBox'
//

// Include files
#include "minBoundingBox.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
void binary_expand_op(coder::array<double, 2U> &R,
                      const coder::array<double, 2U> &bound,
                      const coder::array<double, 2U> &T)
{
  coder::array<double, 2U> b_bound;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int unnamed_idx_0;
  unnamed_idx_0 = T.size(1) << 1;
  if (R.size(0) == 1) {
    i = unnamed_idx_0;
  } else {
    i = R.size(0);
  }
  b_bound.set_size(i, 2);
  stride_0_0 = (unnamed_idx_0 != 1);
  stride_1_0 = (R.size(0) != 1);
  if (R.size(0) == 1) {
    loop_ub = unnamed_idx_0;
  } else {
    loop_ub = R.size(0);
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_bound[i1 + b_bound.size(0) * i] =
          bound[i1 * stride_0_0 + unnamed_idx_0 * i] +
          R[i1 * stride_1_0 + R.size(0) * i];
    }
  }
  R.set_size(b_bound.size(0), 2);
  loop_ub = b_bound.size(0);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      R[i1 + R.size(0) * i] = b_bound[i1 + b_bound.size(0) * i];
    }
  }
}

void minus(coder::array<double, 1U> &bsize, const coder::array<double, 1U> &r)
{
  coder::array<double, 1U> b_bsize;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (r.size(0) == 1) {
    i = bsize.size(0);
  } else {
    i = r.size(0);
  }
  b_bsize.set_size(i);
  stride_0_0 = (bsize.size(0) != 1);
  stride_1_0 = (r.size(0) != 1);
  if (r.size(0) == 1) {
    loop_ub = bsize.size(0);
  } else {
    loop_ub = r.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_bsize[i] = bsize[i * stride_0_0] - r[i * stride_1_0];
  }
  bsize.set_size(b_bsize.size(0));
  loop_ub = b_bsize.size(0);
  for (i = 0; i < loop_ub; i++) {
    bsize[i] = b_bsize[i];
  }
}

// End of code generation (minBoundingBox.cpp)
