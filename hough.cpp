//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// hough.cpp
//
// Code generation for function 'hough'
//

// Include files
#include "hough.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
namespace coder {
void hough(const ::coder::array<bool, 2U> &varargin_1,
           ::coder::array<double, 2U> &h, ::coder::array<double, 2U> &rho)
{
  array<int, 2U> nonZeroPixelMatrix;
  array<int, 1U> numNonZeros;
  array<int, 1U> rhoIdxVector;
  array<unsigned int, 1U> tempBin;
  double cost[180];
  double sint[180];
  double delta1;
  double delta2;
  double q;
  int M;
  int i;
  int j;
  int k;
  int rho_tmp;
  M = varargin_1.size(0) - 1;
  q = std::ceil(std::sqrt((static_cast<double>(varargin_1.size(0)) - 1.0) *
                              (static_cast<double>(varargin_1.size(0)) - 1.0) +
                          (static_cast<double>(varargin_1.size(1)) - 1.0) *
                              (static_cast<double>(varargin_1.size(1)) - 1.0)));
  delta2 = 2.0 * q + 1.0;
  if (!(delta2 >= 0.0)) {
    rho.set_size(1, 0);
  } else {
    rho.set_size(1, static_cast<int>(delta2));
    if (static_cast<int>(delta2) >= 1) {
      rho_tmp = static_cast<int>(delta2) - 1;
      rho[static_cast<int>(delta2) - 1] = q;
      if (rho.size(1) >= 2) {
        rho[0] = -q;
        if (rho.size(1) >= 3) {
          if ((-q == -q) && (static_cast<int>(delta2) > 2)) {
            delta1 = q / (static_cast<double>(static_cast<int>(delta2)) - 1.0);
            for (k = 2; k <= rho_tmp; k++) {
              rho[k - 1] = static_cast<double>(
                               ((k << 1) - static_cast<int>(delta2)) - 1) *
                           delta1;
            }
            if ((static_cast<int>(delta2) & 1) == 1) {
              rho[static_cast<int>(delta2) >> 1] = 0.0;
            }
          } else if (((-q < 0.0) != (q < 0.0)) &&
                     ((std::abs(-q) > 8.9884656743115785E+307) ||
                      (std::abs(q) > 8.9884656743115785E+307))) {
            delta1 = -q / (static_cast<double>(rho.size(1)) - 1.0);
            delta2 = q / (static_cast<double>(rho.size(1)) - 1.0);
            i = rho.size(1);
            for (k = 0; k <= i - 3; k++) {
              rho[k + 1] = (-q + delta2 * (static_cast<double>(k) + 1.0)) -
                           delta1 * (static_cast<double>(k) + 1.0);
            }
          } else {
            delta1 = (q - (-q)) / (static_cast<double>(rho.size(1)) - 1.0);
            i = rho.size(1);
            for (k = 0; k <= i - 3; k++) {
              rho[k + 1] = -q + (static_cast<double>(k) + 1.0) * delta1;
            }
          }
        }
      }
    }
  }
  delta2 = rho[0];
  h.set_size(rho.size(1), 180);
  for (k = 0; k < 180; k++) {
    delta1 = (((static_cast<double>(k) + 1.0) - 1.0) + -90.0) *
             3.1415926535897931 / 180.0;
    cost[k] = std::cos(delta1);
    sint[k] = std::sin(delta1);
  }
  delta1 = (static_cast<double>(rho.size(1)) - 1.0) /
           (rho[rho.size(1) - 1] - rho[0]);
  nonZeroPixelMatrix.set_size(varargin_1.size(0), varargin_1.size(1));
  numNonZeros.set_size(varargin_1.size(1));
  i = varargin_1.size(1);
  for (j = 0; j < i; j++) {
    unsigned int tempNum;
    tempBin.set_size(M + 1);
    tempNum = 0U;
    for (k = 0; k <= M; k++) {
      if (varargin_1[k + varargin_1.size(0) * j]) {
        tempNum++;
        tempBin[static_cast<int>(tempNum) - 1] =
            static_cast<unsigned int>(k + 1);
      }
    }
    numNonZeros[j] = static_cast<int>(tempNum);
    k = 0;
    while ((k <= M) && (k + 1 <= static_cast<int>(tempNum))) {
      nonZeroPixelMatrix[k + nonZeroPixelMatrix.size(0) * j] =
          static_cast<int>(tempBin[k]);
      k++;
    }
  }
  M = rho.size(1);
  i = varargin_1.size(1);
  for (int thetaIdx{0}; thetaIdx < 180; thetaIdx++) {
    int i1;
    rhoIdxVector.set_size(rho.size(1));
    for (i1 = 0; i1 < M; i1++) {
      rhoIdxVector[i1] = 0;
    }
    for (j = 0; j < i; j++) {
      i1 = numNonZeros[j];
      for (k = 0; k < i1; k++) {
        rho_tmp = static_cast<int>(
            delta1 *
                ((((static_cast<double>(j) + 1.0) - 1.0) * cost[thetaIdx] +
                  (static_cast<double>(
                       nonZeroPixelMatrix[k + nonZeroPixelMatrix.size(0) * j]) -
                   1.0) *
                      sint[thetaIdx]) -
                 delta2) +
            0.5);
        rhoIdxVector[rho_tmp] = rhoIdxVector[rho_tmp] + 1;
      }
    }
    rho_tmp = rhoIdxVector.size(0);
    for (i1 = 0; i1 < rho_tmp; i1++) {
      h[i1 + h.size(0) * thetaIdx] = rhoIdxVector[i1];
    }
  }
}

} // namespace coder

// End of code generation (hough.cpp)
