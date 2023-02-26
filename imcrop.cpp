//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imcrop.cpp
//
// Code generation for function 'imcrop'
//

// Include files
#include "imcrop.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
namespace coder {
void imcrop(const ::coder::array<bool, 2U> &varargin_1,
            const double varargin_2[4], ::coder::array<bool, 2U> &varargout_1)
//void imcrop(const ::coder::array<unsigned char, 2U> &varargin_1,
//            const double varargin_2[4],
//            ::coder::array<unsigned char, 2U> &varargout_1)
{
  double pixelsPerHorizontalUnit;
  double pixelsPerVerticalUnit;
  double r1;
  double x;
  double x_tmp;
  int colIdx2;
  int rowIdx2;
  int xmax;
  unsigned int xmin;
  int ymax;
  unsigned int ymin;
  xmax = 1;
  xmin = 1U;
  if (varargin_1.size(1) > 1) {
    xmax = varargin_1.size(1);
  }
  if (static_cast<unsigned int>(varargin_1.size(1)) < 1U) {
    xmin = static_cast<unsigned int>(varargin_1.size(1));
  }
  ymax = 1;
  ymin = 1U;
  if (varargin_1.size(0) > 1) {
    ymax = varargin_1.size(0);
  }
  if (static_cast<unsigned int>(varargin_1.size(0)) < 1U) {
    ymin = static_cast<unsigned int>(varargin_1.size(0));
  }
  if (varargin_1.size(0) == 1) {
    pixelsPerVerticalUnit = 1.0;
  } else {
    pixelsPerVerticalUnit =
        (static_cast<double>(varargin_1.size(0)) - 1.0) /
        (static_cast<double>(ymax) - static_cast<double>(ymin));
  }
  if (varargin_1.size(1) == 1) {
    pixelsPerHorizontalUnit = 1.0;
  } else {
    pixelsPerHorizontalUnit =
        (static_cast<double>(varargin_1.size(1)) - 1.0) /
        (static_cast<double>(xmax) - static_cast<double>(xmin));
  }
  r1 =
      (varargin_2[1] - static_cast<double>(ymin)) * pixelsPerVerticalUnit + 1.0;
  x = std::round(r1 + varargin_2[3] * pixelsPerVerticalUnit);
  rowIdx2 = static_cast<int>(x);
  x_tmp = std::round(r1);
  xmax = static_cast<int>(x_tmp);
  pixelsPerVerticalUnit =
      (varargin_2[0] - static_cast<double>(xmin)) * pixelsPerHorizontalUnit +
      1.0;
  r1 = std::round(pixelsPerVerticalUnit +
                  varargin_2[2] * pixelsPerHorizontalUnit);
  colIdx2 = static_cast<int>(r1);
  pixelsPerVerticalUnit = std::round(pixelsPerVerticalUnit);
  ymax = static_cast<int>(pixelsPerVerticalUnit);
  if ((static_cast<int>(x_tmp) > varargin_1.size(0)) ||
      (static_cast<int>(x) < 1) ||
      (static_cast<int>(pixelsPerVerticalUnit) > varargin_1.size(1)) ||
      (static_cast<int>(r1) < 1)) {
    varargout_1.set_size(0, 0);
  } else {
    int i;
    int i1;
    if (static_cast<int>(x_tmp) < 1) {
      xmax = 1;
    }
    if (static_cast<int>(x) > varargin_1.size(0)) {
      rowIdx2 = varargin_1.size(0);
    }
    if (static_cast<int>(pixelsPerVerticalUnit) < 1) {
      ymax = 1;
    }
    if (static_cast<int>(r1) > varargin_1.size(1)) {
      colIdx2 = varargin_1.size(1);
    }
    if (xmax > rowIdx2) {
      i = 0;
      rowIdx2 = 0;
    } else {
      i = xmax - 1;
    }
    if (ymax > colIdx2) {
      i1 = 0;
      colIdx2 = 0;
    } else {
      i1 = ymax - 1;
    }
    ymax = rowIdx2 - i;
    xmax = colIdx2 - i1;
    varargout_1.set_size(ymax, xmax);
    for (rowIdx2 = 0; rowIdx2 < xmax; rowIdx2++) {
      for (colIdx2 = 0; colIdx2 < ymax; colIdx2++) {
        varargout_1[colIdx2 + varargout_1.size(0) * rowIdx2] =
            varargin_1[(i + colIdx2) + varargin_1.size(0) * (i1 + rowIdx2)];
      }
    }
  }
}

} // namespace coder

// End of code generation (imcrop.cpp)
