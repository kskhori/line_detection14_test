//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// houghlines.cpp
//
// Code generation for function 'houghlines'
//

// Include files
#include "houghlines.h"
#include "line_detection14_internal_types.h"
#include "power.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
namespace coder {
void houghlines(const ::coder::array<bool, 2U> &varargin_1,
                const ::coder::array<double, 2U> &varargin_3,
                const ::coder::array<double, 2U> &varargin_4,
                ::coder::array<b_struct_T, 2U> &lines)
{
  array<double, 1U> indices;
  array<float, 1U> rhoArray;
  array<int, 2U> houghPix;
  array<int, 2U> houghPixIdx;
  array<int, 2U> nonZeroPixelMatrix;
  array<int, 2U> point1Array;
  array<int, 2U> point2Array;
  array<int, 1U> tempBin;
  array<int, 1U> tempHoughPixNumsVector;
  array<int, 1U> tempNumsVector;
  array<signed char, 1U> thetaArray;
  double sortingOrder[2];
  double firstRho;
  double slope;
  int b_i;
  int i;
  int i1;
  int j;
  int k;
  int numLines;
  int numRow;
  unsigned int tempNum;
  bool useParfor;
  useParfor = (varargin_1.size(0) * varargin_1.size(1) > 2500);
  if (useParfor) {
    numRow = varargin_1.size(0) - 1;
    nonZeroPixelMatrix.set_size(varargin_1.size(0), varargin_1.size(1));
    tempNumsVector.set_size(varargin_1.size(1));
    i = varargin_1.size(1);
    for (j = 0; j < i; j++) {
      tempBin.set_size(numRow + 1);
      tempNum = 0U;
      for (b_i = 0; b_i <= numRow; b_i++) {
        if (varargin_1[b_i + varargin_1.size(0) * j]) {
          tempNum++;
          tempBin[static_cast<int>(tempNum) - 1] = b_i;
        }
      }
      tempNumsVector[j] = static_cast<int>(tempNum);
      b_i = 0;
      while ((b_i <= numRow) && (b_i + 1 <= static_cast<int>(tempNum))) {
        nonZeroPixelMatrix[b_i + nonZeroPixelMatrix.size(0) * j] = tempBin[b_i];
        b_i++;
      }
    }
  } else {
    nonZeroPixelMatrix.set_size(varargin_1.size(0), varargin_1.size(1));
    tempNumsVector.set_size(varargin_1.size(1));
    i = varargin_1.size(1);
    for (j = 0; j < i; j++) {
      tempNum = 0U;
      i1 = varargin_1.size(0);
      for (b_i = 0; b_i < i1; b_i++) {
        if (varargin_1[b_i + varargin_1.size(0) * j]) {
          tempNum++;
          nonZeroPixelMatrix[(static_cast<int>(tempNum) +
                              nonZeroPixelMatrix.size(0) * j) -
                             1] = b_i;
        }
      }
      tempNumsVector[j] = static_cast<int>(tempNum);
    }
  }
  numLines = 0;
  point1Array.set_size(0, 2);
  point2Array.set_size(0, 2);
  thetaArray.set_size(0);
  rhoArray.set_size(0);
  firstRho = varargin_3[0];
  slope = (static_cast<double>(varargin_3.size(1)) - 1.0) /
          (varargin_3[varargin_3.size(1) - 1] - varargin_3[0]);
  i = varargin_4.size(0);
  for (int peakIdx{0}; peakIdx < i; peakIdx++) {
    double thetaVal;
    int b_tempNum;
    int colMax;
    int i2;
    int i3;
    int numHoughPix;
    int peak1;
    int peak2;
    int rowMax;
    peak1 = static_cast<int>(varargin_4[peakIdx]);
    peak2 = static_cast<int>(varargin_4[peakIdx + varargin_4.size(0)]);
    if (useParfor) {
      double colMin;
      double cosTheta;
      double rowMin;
      numRow = nonZeroPixelMatrix.size(0);
      numHoughPix = 0;
      thetaVal = ((static_cast<double>(peak2) - 1.0) + -90.0) *
                 3.1415926535897931 / 180.0;
      cosTheta = std::cos(thetaVal);
      thetaVal = std::sin(thetaVal);
      rowMax = 0;
      rowMin = rtInf;
      colMax = 0;
      colMin = rtInf;
      houghPix.set_size(nonZeroPixelMatrix.size(0), nonZeroPixelMatrix.size(1));
      i1 = nonZeroPixelMatrix.size(1);
      tempHoughPixNumsVector.set_size(nonZeroPixelMatrix.size(1));
      for (k = 0; k < i1; k++) {
        tempBin.set_size(numRow);
        b_tempNum = 0;
        i2 = tempNumsVector[k];
        for (j = 0; j < i2; j++) {
          i3 = nonZeroPixelMatrix[j + nonZeroPixelMatrix.size(0) * k];
          if (static_cast<int>(
                  (slope * ((((static_cast<double>(k) + 1.0) - 1.0) * cosTheta +
                             static_cast<double>(i3) * thetaVal) -
                            firstRho) +
                   1.0) +
                  0.5) == peak1) {
            b_tempNum++;
            tempBin[b_tempNum - 1] = i3 + 1;
          }
        }
        tempHoughPixNumsVector[k] = b_tempNum;
        numHoughPix += b_tempNum;
        if (b_tempNum != 0) {
          rowMax = static_cast<int>(
              std::fmax(static_cast<double>(rowMax),
                        static_cast<double>(tempBin[b_tempNum - 1])));
          rowMin = std::fmin(rowMin, static_cast<double>(tempBin[0]));
          colMax = static_cast<int>(std::fmax(static_cast<double>(colMax),
                                              static_cast<double>(k) + 1.0));
          colMin = std::fmin(colMin, static_cast<double>(k) + 1.0);
        }
        b_i = 0;
        while ((b_i <= numRow - 1) && (b_i + 1 <= b_tempNum)) {
          houghPix[b_i + houghPix.size(0) * k] = tempBin[b_i];
          b_i++;
        }
      }
      if (numHoughPix < 1) {
        houghPix.set_size(0, 0);
      } else {
        i1 = nonZeroPixelMatrix.size(1);
        houghPixIdx.set_size(
            nonZeroPixelMatrix.size(0) * nonZeroPixelMatrix.size(1), 2);
        tempNum = 0U;
        for (k = 0; k < i1; k++) {
          i2 = tempHoughPixNumsVector[k];
          for (j = 0; j < i2; j++) {
            numRow = static_cast<int>(tempNum + j);
            houghPixIdx[numRow] = houghPix[j + houghPix.size(0) * k];
            houghPixIdx[numRow + houghPixIdx.size(0)] = k + 1;
          }
          tempNum += tempHoughPixNumsVector[k];
        }
        if (static_cast<double>(rowMax) - rowMin >
            static_cast<double>(colMax) - colMin) {
          sortingOrder[0] = 1.0;
          sortingOrder[1] = 2.0;
        } else {
          sortingOrder[0] = 2.0;
          sortingOrder[1] = 1.0;
        }
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < numHoughPix; i2++) {
            houghPixIdx[i2 + numHoughPix * i1] =
                houghPixIdx[i2 + houghPixIdx.size(0) * i1];
          }
        }
        houghPixIdx.set_size(numHoughPix, 2);
        sortrows(houghPixIdx, sortingOrder);
        houghPix.set_size(houghPixIdx.size(0), 2);
        b_tempNum = houghPixIdx.size(0) * 2;
        for (i1 = 0; i1 < b_tempNum; i1++) {
          houghPix[i1] = houghPixIdx[i1];
        }
      }
    } else {
      double colMin;
      double cosTheta;
      double rowMin;
      numHoughPix = -1;
      thetaVal = ((static_cast<double>(peak2) - 1.0) + -90.0) *
                 3.1415926535897931 / 180.0;
      cosTheta = std::cos(thetaVal);
      thetaVal = std::sin(thetaVal);
      rowMax = 0;
      rowMin = rtInf;
      colMax = 0;
      colMin = rtInf;
      i1 = nonZeroPixelMatrix.size(1);
      houghPixIdx.set_size(
          nonZeroPixelMatrix.size(0) * nonZeroPixelMatrix.size(1), 2);
      for (j = 0; j < i1; j++) {
        i2 = tempNumsVector[j];
        for (b_i = 0; b_i < i2; b_i++) {
          i3 = nonZeroPixelMatrix[b_i + nonZeroPixelMatrix.size(0) * j];
          if (static_cast<int>(
                  (slope * ((((static_cast<double>(j) + 1.0) - 1.0) * cosTheta +
                             static_cast<double>(i3) * thetaVal) -
                            firstRho) +
                   1.0) +
                  0.5) == peak1) {
            numHoughPix++;
            houghPixIdx[numHoughPix] = i3 + 1;
            houghPixIdx[numHoughPix + houghPixIdx.size(0)] = j + 1;
            numRow = houghPixIdx[numHoughPix];
            rowMax = static_cast<int>(std::fmax(static_cast<double>(rowMax),
                                                static_cast<double>(numRow)));
            rowMin = std::fmin(rowMin, static_cast<double>(numRow));
            colMax = static_cast<int>(std::fmax(static_cast<double>(colMax),
                                                static_cast<double>(j) + 1.0));
            colMin = std::fmin(colMin, static_cast<double>(j) + 1.0);
          }
        }
      }
      if (numHoughPix + 1 < 1) {
        houghPix.set_size(0, 0);
      } else {
        if (static_cast<double>(rowMax) - rowMin >
            static_cast<double>(colMax) - colMin) {
          sortingOrder[0] = 1.0;
          sortingOrder[1] = 2.0;
        } else {
          sortingOrder[0] = 2.0;
          sortingOrder[1] = 1.0;
        }
        b_tempNum = numHoughPix + 1;
        for (i1 = 0; i1 < 2; i1++) {
          for (i2 = 0; i2 < b_tempNum; i2++) {
            houghPixIdx[i2 + (numHoughPix + 1) * i1] =
                houghPixIdx[i2 + houghPixIdx.size(0) * i1];
          }
        }
        houghPixIdx.set_size(numHoughPix + 1, 2);
        sortrows(houghPixIdx, sortingOrder);
        houghPix.set_size(houghPixIdx.size(0), 2);
        b_tempNum = houghPixIdx.size(0) * 2;
        for (i1 = 0; i1 < b_tempNum; i1++) {
          houghPix[i1] = houghPixIdx[i1];
        }
      }
      numHoughPix++;
    }
    if (numHoughPix >= 1) {
      tempBin.set_size(houghPix.size(0) - 1);
      thetaVal = 0.0;
      i1 = houghPix.size(0);
      for (k = 0; k <= i1 - 2; k++) {
        i2 = power(houghPix[k + 1] - houghPix[k]) +
             power(houghPix[(k + houghPix.size(0)) + 1] -
                   houghPix[k + houghPix.size(0)]);
        tempBin[k] = i2;
        if (i2 > 900) {
          thetaVal++;
        }
      }
      indices.set_size(static_cast<int>(thetaVal + 2.0));
      indices[0] = 0.0;
      indices[static_cast<int>(thetaVal + 2.0) - 1] = houghPix.size(0);
      tempNum = 1U;
      i1 = houghPix.size(0);
      for (k = 0; k <= i1 - 2; k++) {
        if (tempBin[k] > 900) {
          tempNum++;
          indices[static_cast<int>(tempNum) - 1] = static_cast<double>(k) + 1.0;
        }
      }
      i1 = indices.size(0);
      for (k = 0; k <= i1 - 2; k++) {
        i2 = static_cast<int>(indices[k + 1]) - 1;
        i3 = static_cast<int>(indices[k]);
        rowMax = houghPix[i3 + houghPix.size(0)];
        i3 = houghPix[i3];
        numRow = houghPix[i2 + houghPix.size(0)];
        i2 = houghPix[i2];
        if (power(i2 - i3) + power(numRow - rowMax) >= 4) {
          numLines++;
          b_tempNum = point1Array.size(0);
          houghPixIdx.set_size(point1Array.size(0) + 1, 2);
          for (colMax = 0; colMax < 2; colMax++) {
            for (numHoughPix = 0; numHoughPix < b_tempNum; numHoughPix++) {
              houghPixIdx[numHoughPix + houghPixIdx.size(0) * colMax] =
                  point1Array[numHoughPix + point1Array.size(0) * colMax];
            }
          }
          houghPixIdx[point1Array.size(0)] = rowMax;
          houghPixIdx[point1Array.size(0) + houghPixIdx.size(0)] = i3;
          point1Array.set_size(houghPixIdx.size(0), 2);
          b_tempNum = houghPixIdx.size(0) * 2;
          for (i3 = 0; i3 < b_tempNum; i3++) {
            point1Array[i3] = houghPixIdx[i3];
          }
          b_tempNum = point2Array.size(0);
          houghPixIdx.set_size(point2Array.size(0) + 1, 2);
          for (i3 = 0; i3 < 2; i3++) {
            for (rowMax = 0; rowMax < b_tempNum; rowMax++) {
              houghPixIdx[rowMax + houghPixIdx.size(0) * i3] =
                  point2Array[rowMax + point2Array.size(0) * i3];
            }
          }
          houghPixIdx[point2Array.size(0)] = numRow;
          houghPixIdx[point2Array.size(0) + houghPixIdx.size(0)] = i2;
          point2Array.set_size(houghPixIdx.size(0), 2);
          b_tempNum = houghPixIdx.size(0) * 2;
          for (i2 = 0; i2 < b_tempNum; i2++) {
            point2Array[i2] = houghPixIdx[i2];
          }
          i2 = thetaArray.size(0);
          thetaArray.set_size(thetaArray.size(0) + 1);
          thetaArray[i2] = static_cast<signed char>(peak2 - 91);
          i2 = rhoArray.size(0);
          rhoArray.set_size(rhoArray.size(0) + 1);
          rhoArray[i2] = static_cast<float>(varargin_3[peak1 - 1]);
        }
      }
    }
  }
  repmat(numLines, lines);
  for (k = 0; k < numLines; k++) {
    lines[k].point1[0] = point1Array[k];
    lines[k].point2[0] = point2Array[k];
    lines[k].point1[1] = point1Array[k + point1Array.size(0)];
    lines[k].point2[1] = point2Array[k + point2Array.size(0)];
    lines[k].theta = thetaArray[k];
    lines[k].rho = rhoArray[k];
  }
}

} // namespace coder

// End of code generation (houghlines.cpp)
