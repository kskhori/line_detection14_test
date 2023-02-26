//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// houghpeaks.cpp
//
// Code generation for function 'houghpeaks'
//

// Include files
#include "houghpeaks.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
static int div_s32(int numerator, int denominator);

// Function Definitions
static int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int b_denominator;
    unsigned int b_numerator;
    if (numerator < 0) {
      b_numerator = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      b_numerator = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      b_denominator = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      b_denominator = static_cast<unsigned int>(denominator);
    }
    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -static_cast<int>(b_numerator);
    } else {
      quotient = static_cast<int>(b_numerator);
    }
  }
  return quotient;
}

namespace coder {
void houghpeaks(const ::coder::array<double, 2U> &varargin_1, double varargin_4,
                ::coder::array<double, 2U> &peaks)
{
  array<double, 2U> hnew;
  double maxVal;
  int peakCoordinates[10];
  int N;
  int iPeak;
  int nhoodSizeDefault_idx_0;
  int rhoToRemove;
  nhoodSizeDefault_idx_0 =
      2 * static_cast<int>(
              std::ceil(static_cast<double>(varargin_1.size(0)) / 50.0 / 2.0)) +
      1;
  if (varargin_1.size(0) < 3) {
    nhoodSizeDefault_idx_0 = 1;
  }
  iPeak = -90;
  rhoToRemove = -90;
  for (N = 0; N < 179; N++) {
    if (iPeak >
        static_cast<signed char>(static_cast<signed char>(N + 1) - 90)) {
      iPeak = static_cast<signed char>(static_cast<signed char>(N + 1) - 90);
    }
    if (rhoToRemove <
        static_cast<signed char>(static_cast<signed char>(N + 1) - 90)) {
      rhoToRemove =
          static_cast<signed char>(static_cast<signed char>(N + 1) - 90);
    }
  }
  if (varargin_1.size(0) * 180 < 1) {
    peaks.set_size(0, 0);
  } else {
    int nhoodCenter_i;
    int numRowH;
    int peakIdx;
    int thetaMin;
    bool isDone;
    bool isThetaAntisymmetric;
    numRowH = varargin_1.size(0);
    isDone = false;
    hnew.set_size(varargin_1.size(0), 180);
    N = varargin_1.size(0) * 180;
    for (thetaMin = 0; thetaMin < N; thetaMin++) {
      hnew[thetaMin] = varargin_1[thetaMin];
    }
    nhoodCenter_i = static_cast<int>(
        (static_cast<double>(nhoodSizeDefault_idx_0) - 1.0) / 2.0);
    peakIdx = -1;
    isThetaAntisymmetric =
        (std::abs(static_cast<double>(iPeak) +
                  std::abs(static_cast<double>(rhoToRemove - iPeak)) / 179.0 *
                      5.0) <= rhoToRemove);
    while (!isDone) {
      int vk;
      if (numRowH < 1200) {
        array<double, 1U> b_hnew;
        N = hnew.size(0) * 180;
        b_hnew = hnew.reshape(N);
        internal::maximum(b_hnew, &maxVal, &N);
        vk = div_s32(N - 1, hnew.size(0));
        iPeak = N - vk * hnew.size(0);
      } else {
        iPeak = 0;
        vk = -1;
        N = hnew.size(0);
        maxVal = -1.0;
        for (rhoToRemove = 0; rhoToRemove < 180; rhoToRemove++) {
          double tempmax;
          tempmax = hnew[hnew.size(0) * rhoToRemove];
          nhoodSizeDefault_idx_0 = 1;
          for (thetaMin = 2; thetaMin <= N; thetaMin++) {
            double temp;
            temp = hnew[(thetaMin + hnew.size(0) * rhoToRemove) - 1];
            if (temp > tempmax) {
              tempmax = temp;
              nhoodSizeDefault_idx_0 = thetaMin;
            }
          }
          if (tempmax > maxVal) {
            maxVal = tempmax;
            vk = rhoToRemove;
            iPeak = nhoodSizeDefault_idx_0;
          }
        }
      }
      if (hnew[(iPeak + hnew.size(0) * vk) - 1] >= varargin_4) {
        int rhoMin;
        peakIdx++;
        peakCoordinates[peakIdx] = iPeak;
        peakCoordinates[peakIdx + 5] = vk + 1;
        rhoMin = iPeak - nhoodCenter_i;
        iPeak += nhoodCenter_i;
        thetaMin = vk - 1;
        nhoodSizeDefault_idx_0 = vk + 3;
        if (rhoMin < 1) {
          rhoMin = 1;
        }
        if (iPeak > numRowH) {
          iPeak = numRowH;
        }
        for (vk = thetaMin; vk <= nhoodSizeDefault_idx_0; vk++) {
          for (int rho{rhoMin}; rho <= iPeak; rho++) {
            rhoToRemove = rho - 1;
            N = vk;
            if (isThetaAntisymmetric) {
              if (vk > 180) {
                rhoToRemove = numRowH - rho;
                N = vk - 180;
              } else if (vk < 1) {
                rhoToRemove = numRowH - rho;
                N = vk + 180;
              }
            }
            if ((N <= 180) && (N >= 1)) {
              hnew[rhoToRemove + hnew.size(0) * (N - 1)] = 0.0;
            }
          }
        }
        isDone = (peakIdx + 1 == 5);
      } else {
        isDone = true;
      }
    }
    if (peakIdx + 1 == 0) {
      peaks.set_size(0, 0);
    } else {
      peaks.set_size(peakIdx + 1, 2);
      for (thetaMin = 0; thetaMin < 2; thetaMin++) {
        for (N = 0; N <= peakIdx; N++) {
          peaks[N + peaks.size(0) * thetaMin] =
              peakCoordinates[N + 5 * thetaMin];
        }
      }
    }
  }
}

} // namespace coder

// End of code generation (houghpeaks.cpp)
