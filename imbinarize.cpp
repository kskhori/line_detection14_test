//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imbinarize.cpp
//
// Code generation for function 'imbinarize'
//

// Include files
#include "imbinarize.h"
#include "padarray.h"
#include "rt_nonfinite.h"
#include "useConstantDim.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
namespace coder {
void imbinarize(const ::coder::array<unsigned char, 2U> &b_I,
                ::coder::array<bool, 2U> &BW)
{
  array<double, 2U> c_I;
  array<double, 2U> intA;
  array<double, 2U> paddedImage;
  array<double, 1U> a;
  array<double, 1U> b;
  array<double, 1U> cj;
  double defaultNeighborhoodSize[2];
  double bij;
  int i;
  int loop_ub;
  int nhoodSize_idx_0_tmp;
  int nhoodSize_idx_1_tmp;
  bool x[2];
  defaultNeighborhoodSize[0] =
      2.0 * std::floor(static_cast<double>(b_I.size(0)) / 16.0) + 1.0;
  defaultNeighborhoodSize[1] =
      2.0 * std::floor(static_cast<double>(b_I.size(1)) / 16.0) + 1.0;
  nhoodSize_idx_0_tmp = static_cast<int>(defaultNeighborhoodSize[0]);
  nhoodSize_idx_1_tmp = static_cast<int>(defaultNeighborhoodSize[1]);
  if ((b_I.size(0) == 0) || (b_I.size(1) == 0)) {
    c_I.set_size(b_I.size(0), b_I.size(1));
    loop_ub = b_I.size(0) * b_I.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_I[i] = 0.0;
    }
  } else {
    double normFactor;
    int mc;
    c_I.set_size(b_I.size(0), b_I.size(1));
    loop_ub = b_I.size(0) * b_I.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_I[i] = static_cast<double>(b_I[i]) / 255.0;
    }
    bij = defaultNeighborhoodSize[0] * defaultNeighborhoodSize[1];
    normFactor = 1.2999999999999998 / bij;
    if (bij < 25.0) {
      int b_i;
      int eC;
      int eR;
      int ib;
      int nc;
      bool exitg1;
      bool y;
      defaultNeighborhoodSize[0] =
          static_cast<double>(nhoodSize_idx_0_tmp) -
          std::floor((static_cast<double>(nhoodSize_idx_0_tmp) + 1.0) / 2.0);
      defaultNeighborhoodSize[1] =
          static_cast<double>(nhoodSize_idx_1_tmp) -
          std::floor((static_cast<double>(nhoodSize_idx_1_tmp) + 1.0) / 2.0);
      eR = static_cast<int>(
          std::fmod(static_cast<double>(nhoodSize_idx_0_tmp), 2.0));
      eC = 1 - eR;
      x[0] = (1 - eR == 1);
      eR = static_cast<int>(
          std::fmod(static_cast<double>(nhoodSize_idx_1_tmp), 2.0));
      x[1] = (1 - eR == 1);
      y = false;
      mc = 0;
      exitg1 = false;
      while ((!exitg1) && (mc <= 1)) {
        if (x[mc]) {
          y = true;
          exitg1 = true;
        } else {
          mc++;
        }
      }
      if (y) {
        padarray(c_I, defaultNeighborhoodSize, paddedImage);
        if (eC + 1 > paddedImage.size(0)) {
          i = -1;
          b_i = -1;
        } else {
          i = eC - 1;
          b_i = paddedImage.size(0) - 1;
        }
        if (2 - eR > paddedImage.size(1)) {
          nc = 0;
          ib = 0;
        } else {
          nc = 1 - eR;
          ib = paddedImage.size(1);
        }
        eC = ib - nc;
        for (ib = 0; ib < eC; ib++) {
          eR = b_i - i;
          for (mc = 0; mc < eR; mc++) {
            paddedImage[mc + eR * ib] =
                paddedImage[((i + mc) + paddedImage.size(0) * (nc + ib)) + 1];
          }
        }
        paddedImage.set_size(b_i - i, eC);
      } else {
        padarray(c_I, defaultNeighborhoodSize, paddedImage);
      }
      nc = nhoodSize_idx_0_tmp - 1;
      mc = nhoodSize_idx_1_tmp - 1;
      intA.set_size(nhoodSize_idx_0_tmp, nhoodSize_idx_1_tmp);
      if (nhoodSize_idx_0_tmp * nhoodSize_idx_1_tmp >= 8192) {
        for (nhoodSize_idx_0_tmp = 0; nhoodSize_idx_0_tmp <= mc;
             nhoodSize_idx_0_tmp++) {
          for (b_i = 0; b_i <= nc; b_i++) {
            intA[b_i + intA.size(0) * nhoodSize_idx_0_tmp] = normFactor;
          }
        }
      } else {
        for (nhoodSize_idx_0_tmp = 0; nhoodSize_idx_0_tmp <= mc;
             nhoodSize_idx_0_tmp++) {
          for (b_i = 0; b_i <= nc; b_i++) {
            intA[b_i + intA.size(0) * nhoodSize_idx_0_tmp] = normFactor;
          }
        }
      }
      if ((paddedImage.size(0) == 1) && (intA.size(0) == 1)) {
        loop_ub = paddedImage.size(1);
        a.set_size(paddedImage.size(1));
        for (i = 0; i < loop_ub; i++) {
          a[i] = paddedImage[paddedImage.size(0) * i];
        }
        loop_ub = intA.size(1);
        b.set_size(intA.size(1));
        for (i = 0; i < loop_ub; i++) {
          b[i] = intA[intA.size(0) * i];
        }
        if (a.size(0) < b.size(0) - 1) {
          mc = -1;
        } else {
          mc = a.size(0) - b.size(0);
        }
        cj.set_size(mc + 1);
        for (i = 0; i <= mc; i++) {
          cj[i] = 0.0;
        }
        if ((a.size(0) != 0) && (mc + 1 != 0)) {
          i = b.size(0) - 1;
          for (ib = 0; ib <= i; ib++) {
            bij = b[(b.size(0) - ib) - 1];
            for (b_i = 0; b_i <= mc; b_i++) {
              cj[b_i] = cj[b_i] + bij * a[ib + b_i];
            }
          }
        }
        c_I.set_size(1, cj.size(0));
        loop_ub = cj.size(0);
        for (i = 0; i < loop_ub; i++) {
          c_I[c_I.size(0) * i] = cj[i];
        }
      } else {
        eC = intA.size(0) - 1;
        eR = intA.size(1) - 1;
        if (paddedImage.size(0) < intA.size(0) - 1) {
          mc = 0;
        } else {
          mc = (paddedImage.size(0) - intA.size(0)) + 1;
        }
        if (paddedImage.size(1) < intA.size(1) - 1) {
          nc = 0;
        } else {
          nc = (paddedImage.size(1) - intA.size(1)) + 1;
        }
        if ((paddedImage.size(0) == 0) || (paddedImage.size(1) == 0) ||
            (mc == 0) || (nc == 0)) {
          c_I.set_size(mc, nc);
          loop_ub = mc * nc;
          for (i = 0; i < loop_ub; i++) {
            c_I[i] = 0.0;
          }
        } else {
          c_I.set_size(mc, nc);
          for (nhoodSize_idx_0_tmp = 0; nhoodSize_idx_0_tmp < nc;
               nhoodSize_idx_0_tmp++) {
            cj.set_size(mc);
            for (i = 0; i < mc; i++) {
              cj[i] = 0.0;
            }
            for (loop_ub = 0; loop_ub <= eR; loop_ub++) {
              for (ib = 0; ib <= eC; ib++) {
                bij = intA[(eC - ib) + intA.size(0) * (eR - loop_ub)];
                for (b_i = 0; b_i < mc; b_i++) {
                  cj[b_i] =
                      cj[b_i] +
                      bij * paddedImage[(b_i + ib) +
                                        paddedImage.size(0) *
                                            (nhoodSize_idx_0_tmp + loop_ub)];
                }
              }
            }
            loop_ub = cj.size(0);
            for (i = 0; i < loop_ub; i++) {
              c_I[i + c_I.size(0) * nhoodSize_idx_0_tmp] = cj[i];
            }
          }
        }
      }
    } else {
      int b_i;
      int eC;
      int nc;
      defaultNeighborhoodSize[0] =
          (static_cast<double>(nhoodSize_idx_0_tmp) - 1.0) / 2.0;
      defaultNeighborhoodSize[1] =
          (static_cast<double>(nhoodSize_idx_1_tmp) - 1.0) / 2.0;
      padarray(c_I, defaultNeighborhoodSize, paddedImage);
      if ((paddedImage.size(0) != 0) && (paddedImage.size(1) != 0)) {
        intA.set_size(
            static_cast<int>(static_cast<double>(static_cast<unsigned int>(
                                 paddedImage.size(0))) +
                             1.0),
            static_cast<int>(static_cast<double>(static_cast<unsigned int>(
                                 paddedImage.size(1))) +
                             1.0));
        loop_ub =
            static_cast<int>(static_cast<double>(static_cast<unsigned int>(
                                 paddedImage.size(0))) +
                             1.0) *
            static_cast<int>(static_cast<double>(static_cast<unsigned int>(
                                 paddedImage.size(1))) +
                             1.0);
        for (i = 0; i < loop_ub; i++) {
          intA[i] = 0.0;
        }
        i = (2 <=
             static_cast<int>(static_cast<double>(static_cast<unsigned int>(
                                  paddedImage.size(0))) +
                              1.0));
        b_i = (2 <=
               static_cast<int>(static_cast<double>(static_cast<unsigned int>(
                                    paddedImage.size(1))) +
                                1.0));
        internal::useConstantDim(paddedImage, 1);
        internal::useConstantDim(paddedImage, 2);
        loop_ub = paddedImage.size(1);
        for (nc = 0; nc < loop_ub; nc++) {
          eC = paddedImage.size(0);
          for (int ib{0}; ib < eC; ib++) {
            intA[(i + ib) + intA.size(0) * (b_i + nc)] =
                paddedImage[ib + paddedImage.size(0) * nc];
          }
        }
      } else {
        intA.set_size(0, 0);
      }
      i = intA.size(0) - nhoodSize_idx_0_tmp;
      b_i = intA.size(1) - nhoodSize_idx_1_tmp;
      c_I.set_size(intA.size(0) - nhoodSize_idx_0_tmp,
                   intA.size(1) - nhoodSize_idx_1_tmp);
      for (mc = 0; mc < b_i; mc++) {
        eC = mc + nhoodSize_idx_1_tmp;
        for (nc = 0; nc < i; nc++) {
          int eR;
          eR = nc + nhoodSize_idx_0_tmp;
          c_I[nc + c_I.size(0) * mc] =
              normFactor *
              (((intA[eR + intA.size(0) * eC] + intA[nc + intA.size(0) * mc]) -
                intA[nc + intA.size(0) * eC]) -
               intA[eR + intA.size(0) * mc]);
        }
      }
    }
    i = c_I.size(0) * c_I.size(1) - 1;
    for (mc = 0; mc <= i; mc++) {
      c_I[mc] = std::fmax(std::fmin(c_I[mc], 1.0), 0.0);
    }
  }
  if ((c_I.size(0) == 1) && (c_I.size(1) == 1)) {
    BW.set_size(b_I.size(0), b_I.size(1));
    bij = 255.0 * c_I[0];
    loop_ub = b_I.size(0) * b_I.size(1);
    for (i = 0; i < loop_ub; i++) {
      BW[i] = (b_I[i] > bij);
    }
  } else {
    BW.set_size(b_I.size(0), b_I.size(1));
    loop_ub = b_I.size(0) * b_I.size(1);
    for (i = 0; i < loop_ub; i++) {
      BW[i] = (b_I[i] > 255.0 * c_I[i]);
    }
  }
}

} // namespace coder

// End of code generation (imbinarize.cpp)
