//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// qhullReject2D.h
//
// Code generation for function 'qhullReject2D'
//

#ifndef QHULLREJECT2D_H
#define QHULLREJECT2D_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void getFarthestPoints(const ::coder::array<double, 2U> &pts, double pt1,
                       double pt2, ::coder::array<double, 2U> &farthestNorth,
                       ::coder::array<double, 2U> &farthestSouth,
                       ::coder::array<bool, 1U> &northPts,
                       ::coder::array<bool, 1U> &linePts, bool *collinearPts);

void markPtsInTria(const ::coder::array<double, 2U> &pts,
                   const ::coder::array<double, 2U> &a,
                   const ::coder::array<double, 2U> &b,
                   const ::coder::array<double, 2U> &c,
                   ::coder::array<bool, 1U> &ptsInTria);

void qhullReject2D(const ::coder::array<double, 2U> &pts,
                   ::coder::array<bool, 1U> &ptsOffHull);

} // namespace coder

#endif
// End of code generation (qhullReject2D.h)
