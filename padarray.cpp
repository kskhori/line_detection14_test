//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// padarray.cpp
//
// Code generation for function 'padarray'
//

// Include files
#include "padarray.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
namespace coder {
void padarray(const ::coder::array<double, 2U> &varargin_1,
              const double varargin_2[2], ::coder::array<double, 2U> &b)
{
  array<double, 2U> x;
  array<int, 2U> idxA;
  array<unsigned int, 2U> idxDir;
  array<int, 1U> r;
  array<signed char, 2U> onesVector;
  if ((varargin_1.size(0) == 0) || (varargin_1.size(1) == 0)) {
    double sizeA_idx_0;
    double sizeA_idx_1;
    int loop_ub_tmp;
    sizeA_idx_0 = static_cast<double>(varargin_1.size(0)) + 2.0 * varargin_2[0];
    sizeA_idx_1 = static_cast<double>(varargin_1.size(1)) + 2.0 * varargin_2[1];
    b.set_size(static_cast<int>(sizeA_idx_0), static_cast<int>(sizeA_idx_1));
    loop_ub_tmp = static_cast<int>(sizeA_idx_0) * static_cast<int>(sizeA_idx_1);
    for (int i{0}; i < loop_ub_tmp; i++) {
      b[i] = 0.0;
    }
  } else {
    double sizeA_idx_0;
    double sizeA_idx_1;
    double varargin_1_idx_0;
    double varargin_1_idx_1;
    int i;
    int loop_ub_tmp;
    sizeA_idx_0 = varargin_1.size(0);
    sizeA_idx_1 = varargin_1.size(1);
    varargin_1_idx_0 =
        2.0 * varargin_2[0] +
        static_cast<double>(static_cast<unsigned int>(varargin_1.size(0)));
    varargin_1_idx_1 =
        2.0 * varargin_2[1] +
        static_cast<double>(static_cast<unsigned int>(varargin_1.size(1)));
    if ((varargin_1_idx_0 < varargin_1_idx_1) ||
        (std::isnan(varargin_1_idx_0) && (!std::isnan(varargin_1_idx_1)))) {
      varargin_1_idx_0 = varargin_1_idx_1;
    }
    idxA.set_size(static_cast<int>(varargin_1_idx_0), 2);
    loop_ub_tmp = static_cast<int>(varargin_2[0]);
    onesVector.set_size(1, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      onesVector[i] = 1;
    }
    x.set_size(
        1, static_cast<int>(static_cast<double>(
                                static_cast<unsigned int>(varargin_1.size(0))) -
                            1.0) +
               1);
    loop_ub_tmp = static_cast<int>(
        static_cast<double>(static_cast<unsigned int>(varargin_1.size(0))) -
        1.0);
    for (i = 0; i <= loop_ub_tmp; i++) {
      x[i] = static_cast<double>(i) + 1.0;
    }
    idxDir.set_size(1, (onesVector.size(1) + x.size(1)) + onesVector.size(1));
    loop_ub_tmp = onesVector.size(1);
    for (i = 0; i < loop_ub_tmp; i++) {
      idxDir[i] = 1U;
    }
    loop_ub_tmp = x.size(1);
    for (i = 0; i < loop_ub_tmp; i++) {
      idxDir[i + onesVector.size(1)] = static_cast<unsigned int>(x[i]);
    }
    loop_ub_tmp = onesVector.size(1);
    for (i = 0; i < loop_ub_tmp; i++) {
      idxDir[(i + onesVector.size(1)) + x.size(1)] =
          static_cast<unsigned int>(sizeA_idx_0);
    }
    loop_ub_tmp = idxDir.size(1);
    r.set_size(idxDir.size(1));
    for (i = 0; i < loop_ub_tmp; i++) {
      r[i] = i;
    }
    loop_ub_tmp = r.size(0);
    for (i = 0; i < loop_ub_tmp; i++) {
      idxA[r[i]] = static_cast<int>(idxDir[i]);
    }
    loop_ub_tmp = static_cast<int>(varargin_2[1]);
    onesVector.set_size(1, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      onesVector[i] = 1;
    }
    x.set_size(
        1, static_cast<int>(static_cast<double>(
                                static_cast<unsigned int>(varargin_1.size(1))) -
                            1.0) +
               1);
    loop_ub_tmp = static_cast<int>(
        static_cast<double>(static_cast<unsigned int>(varargin_1.size(1))) -
        1.0);
    for (i = 0; i <= loop_ub_tmp; i++) {
      x[i] = static_cast<double>(i) + 1.0;
    }
    idxDir.set_size(1, (onesVector.size(1) + x.size(1)) + onesVector.size(1));
    loop_ub_tmp = onesVector.size(1);
    for (i = 0; i < loop_ub_tmp; i++) {
      idxDir[i] = 1U;
    }
    loop_ub_tmp = x.size(1);
    for (i = 0; i < loop_ub_tmp; i++) {
      idxDir[i + onesVector.size(1)] = static_cast<unsigned int>(x[i]);
    }
    loop_ub_tmp = onesVector.size(1);
    for (i = 0; i < loop_ub_tmp; i++) {
      idxDir[(i + onesVector.size(1)) + x.size(1)] =
          static_cast<unsigned int>(sizeA_idx_1);
    }
    loop_ub_tmp = idxDir.size(1);
    r.set_size(idxDir.size(1));
    for (i = 0; i < loop_ub_tmp; i++) {
      r[i] = i;
    }
    loop_ub_tmp = r.size(0);
    for (i = 0; i < loop_ub_tmp; i++) {
      idxA[r[i] + idxA.size(0)] = static_cast<int>(idxDir[i]);
    }
    i = static_cast<int>(static_cast<double>(varargin_1.size(1)) +
                         2.0 * varargin_2[1]);
    b.set_size(static_cast<int>(static_cast<double>(varargin_1.size(0)) +
                                2.0 * varargin_2[0]),
               static_cast<int>(static_cast<double>(varargin_1.size(1)) +
                                2.0 * varargin_2[1]));
    for (int j{0}; j < i; j++) {
      loop_ub_tmp = b.size(0);
      for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
        b[b_i + b.size(0) * j] =
            varargin_1[(idxA[b_i] +
                        varargin_1.size(0) * (idxA[j + idxA.size(0)] - 1)) -
                       1];
      }
    }
  }
}

} // namespace coder

// End of code generation (padarray.cpp)
