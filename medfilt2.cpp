//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// medfilt2.cpp
//
// Code generation for function 'medfilt2'
//

// Include files
#include "medfilt2.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>
#include <string.h>

// Function Declarations
static int div_nzp_s32_floor(int numerator);

// Function Definitions
static int div_nzp_s32_floor(int numerator)
{
  unsigned int absNumerator;
  int quotient;
  unsigned int tempAbsQuotient;
  bool quotientNeedsNegation;
  if (numerator < 0) {
    absNumerator = ~static_cast<unsigned int>(numerator) + 1U;
  } else {
    absNumerator = static_cast<unsigned int>(numerator);
  }
  quotientNeedsNegation = (numerator < 0);
  tempAbsQuotient = absNumerator / 6U;
  if (quotientNeedsNegation) {
    absNumerator %= 6U;
    if (absNumerator > 0U) {
      tempAbsQuotient++;
    }
    quotient = -static_cast<int>(tempAbsQuotient);
  } else {
    quotient = static_cast<int>(tempAbsQuotient);
  }
  return quotient;
}

namespace coder {
void medfilt2(const ::coder::array<unsigned char, 2U> &varargin_1,
              ::coder::array<unsigned char, 2U> &b)
{
  array<unsigned char, 2U> ain;
  int histArray[256];
  unsigned int region_tmp[7];
  unsigned char slicePrevious[7];
  if ((varargin_1.size(0) == 0) || (varargin_1.size(1) == 0)) {
    int pixelCount;
    b.set_size(varargin_1.size(0), varargin_1.size(1));
    pixelCount = varargin_1.size(0) * varargin_1.size(1);
    for (int i{0}; i < pixelCount; i++) {
      b[i] = varargin_1[i];
    }
  } else {
    int b_i;
    int i;
    int i1;
    int j;
    int pixelCount;
    b.set_size(varargin_1.size(0), varargin_1.size(1));
    ain.set_size(static_cast<int>(varargin_1.size(0) + 6U),
                 static_cast<int>(varargin_1.size(1) + 6U));
    for (j = 0; j < 3; j++) {
      i = ain.size(0);
      for (b_i = 0; b_i < i; b_i++) {
        ain[b_i + ain.size(0) * j] = 0U;
      }
    }
    i = varargin_1.size(1) + 4;
    i1 = ain.size(1);
    for (j = i; j <= i1; j++) {
      pixelCount = ain.size(0);
      for (b_i = 0; b_i < pixelCount; b_i++) {
        ain[b_i + ain.size(0) * (j - 1)] = 0U;
      }
    }
    i = varargin_1.size(1);
    for (j = 0; j < i; j++) {
      ain[ain.size(0) * (j + 3)] = 0U;
      ain[ain.size(0) * (j + 3) + 1] = 0U;
      ain[ain.size(0) * (j + 3) + 2] = 0U;
    }
    i = varargin_1.size(1);
    for (j = 0; j < i; j++) {
      i1 = varargin_1.size(0) + 4;
      pixelCount = ain.size(0);
      for (b_i = i1; b_i <= pixelCount; b_i++) {
        ain[(b_i + ain.size(0) * (j + 3)) - 1] = 0U;
      }
    }
    i = varargin_1.size(1);
    for (j = 0; j < i; j++) {
      i1 = varargin_1.size(0);
      for (b_i = 0; b_i < i1; b_i++) {
        ain[(b_i + ain.size(0) * (j + 3)) + 3] =
            varargin_1[b_i + varargin_1.size(0) * j];
      }
    }
    i = varargin_1.size(1);
    for (j = 0; j < i; j++) {
      int leftMedian;
      unsigned int qY;
      unsigned char localMedian;
      std::memset(&histArray[0], 0, 256U * sizeof(int));
      for (i1 = 0; i1 < 7; i1++) {
        qY = (static_cast<unsigned int>(j) + i1) + 1U;
        region_tmp[i1] = qY;
        slicePrevious[i1] = ain[ain.size(0) * (static_cast<int>(qY) - 1)];
      }
      leftMedian = 0;
      localMedian = 0U;
      for (b_i = 0; b_i < 42; b_i++) {
        pixelCount =
            ain[b_i % 6 +
                ain.size(0) *
                    (static_cast<int>(region_tmp[div_nzp_s32_floor(b_i)]) - 1)];
        histArray[pixelCount]++;
      }
      for (b_i = 0; b_i < 7; b_i++) {
        pixelCount = ain[ain.size(0) * (static_cast<int>(region_tmp[b_i]) - 1)];
        histArray[pixelCount]++;
      }
      i1 = varargin_1.size(0);
      for (b_i = 0; b_i < i1; b_i++) {
        for (int c_i{0}; c_i < 7; c_i++) {
          pixelCount = ain[(b_i + ain.size(0) *
                                      (static_cast<int>(region_tmp[c_i]) - 1)) +
                           6];
          histArray[pixelCount]++;
          histArray[slicePrevious[c_i]]--;
          if (slicePrevious[c_i] < localMedian) {
            leftMedian--;
          }
          if (pixelCount < localMedian) {
            leftMedian++;
          }
        }
        pixelCount = leftMedian + histArray[localMedian];
        if (pixelCount < 25) {
          for (leftMedian = pixelCount; leftMedian < 25;
               leftMedian +=
               histArray[static_cast<unsigned char>(pixelCount)]) {
            pixelCount = static_cast<int>(localMedian + 1U);
            if (localMedian + 1U > 255U) {
              pixelCount = 255;
            }
            localMedian = static_cast<unsigned char>(pixelCount);
          }
          leftMedian -= histArray[localMedian];
        } else if (leftMedian > 24) {
          while (leftMedian > 24) {
            qY = localMedian - 1U;
            if (localMedian - 1U > localMedian) {
              qY = 0U;
            }
            localMedian = static_cast<unsigned char>(qY);
            leftMedian -= histArray[static_cast<unsigned char>(qY)];
          }
        }
        for (pixelCount = 0; pixelCount < 7; pixelCount++) {
          slicePrevious[pixelCount] =
              ain[b_i +
                  ain.size(0) * (static_cast<int>(region_tmp[pixelCount]) - 1)];
        }
        b[b_i + b.size(0) * j] = localMedian;
      }
    }
  }
}

} // namespace coder

// End of code generation (medfilt2.cpp)
