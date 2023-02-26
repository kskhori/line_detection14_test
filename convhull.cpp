//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// convhull.cpp
//
// Code generation for function 'convhull'
//

// Include files
#include "convhull.h"
#include "anonymous_function.h"
#include "find.h"
#include "introsort.h"
#include "line_detection14_internal_types.h"
#include "minOrMax.h"
#include "qhullReject2D.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
namespace coder {
static void orient(const ::coder::array<double, 2U> &pts,
                   ::coder::array<double, 2U> &orientedPts,
                   ::coder::array<double, 1U> &orientPerm);

}
static int div_s32_floor(int numerator, int denominator);

// Function Definitions
namespace coder {
static void orient(const ::coder::array<double, 2U> &pts,
                   ::coder::array<double, 2U> &orientedPts,
                   ::coder::array<double, 1U> &orientPerm)
{
  anonymous_function b_this;
  array<double, 2U> corner_pt;
  array<double, 2U> lineStretches;
  array<double, 2U> relativePt;
  array<double, 1U> b_pts;
  array<double, 1U> slopes;
  array<int, 1U> iidx;
  double numStretch;
  double stretchEnd;
  int b_i;
  int i;
  int i1;
  int iindx;
  int loop_ub;
  int npts;
  bool exitg1;
  loop_ub = pts.size(0);
  b_pts.set_size(pts.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_pts[i] = pts[i + pts.size(0)];
  }
  internal::minimum(b_pts, &numStretch, &iindx);
  loop_ub = pts.size(1);
  corner_pt.set_size(1, pts.size(1));
  for (i = 0; i < loop_ub; i++) {
    corner_pt[i] = pts[(iindx + pts.size(0) * i) - 1];
  }
  slopes.set_size(pts.size(0));
  i = pts.size(0);
  for (b_i = 0; b_i < i; b_i++) {
    loop_ub = pts.size(1);
    relativePt.set_size(1, pts.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      relativePt[i1] = pts[b_i + pts.size(0) * i1] - corner_pt[i1];
    }
    numStretch = relativePt[1] / relativePt[0];
    slopes[b_i] = numStretch;
    if (std::isnan(numStretch)) {
      slopes[b_i] = 0.0;
    }
  }
  internal::sort(slopes, iidx);
  orientPerm.set_size(iidx.size(0));
  loop_ub = iidx.size(0);
  for (i = 0; i < loop_ub; i++) {
    orientPerm[i] = iidx[i];
  }
  npts = slopes.size(0);
  iindx =
      static_cast<int>(std::ceil(static_cast<double>(slopes.size(0)) / 2.0));
  lineStretches.set_size(iindx, 2);
  loop_ub = iindx << 1;
  for (i = 0; i < loop_ub; i++) {
    lineStretches[i] = 0.0;
  }
  numStretch = 0.0;
  stretchEnd = 0.0;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= slopes.size(0) - 2)) {
    if (((stretchEnd != 0.0) &&
         (static_cast<double>(b_i) + 1.0 <= stretchEnd)) ||
        (!(slopes[b_i] == slopes[b_i + 1]))) {
      b_i++;
    } else {
      stretchEnd = (static_cast<double>(b_i) + 1.0) + 1.0;
      numStretch++;
      lineStretches[static_cast<int>(numStretch) - 1] =
          static_cast<double>(b_i) + 1.0;
      while ((stretchEnd <= static_cast<double>(npts) - 1.0) &&
             (slopes[static_cast<int>(stretchEnd) - 1] ==
              slopes[static_cast<int>(stretchEnd)])) {
        stretchEnd++;
      }
      if (stretchEnd == npts) {
        lineStretches[(static_cast<int>(numStretch) + lineStretches.size(0)) -
                      1] = npts;
        exitg1 = true;
      } else {
        lineStretches[(static_cast<int>(numStretch) + lineStretches.size(0)) -
                      1] = stretchEnd;
        b_i++;
      }
    }
  }
  if (1.0 > numStretch) {
    loop_ub = 0;
  } else {
    loop_ub = static_cast<int>(numStretch);
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      lineStretches[i1 + loop_ub * i] =
          lineStretches[i1 + lineStretches.size(0) * i];
    }
  }
  lineStretches.set_size(loop_ub, 2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this.workspace.pts.set_size(pts.size(0), pts.size(1));
    iindx = pts.size(0) * pts.size(1);
    for (i = 0; i < iindx; i++) {
      b_this.workspace.pts[i] = pts[i];
    }
    internal::introsort(
        orientPerm, static_cast<int>(lineStretches[b_i]),
        static_cast<int>(lineStretches[b_i + lineStretches.size(0)]), &b_this);
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    numStretch = lineStretches[b_i];
    if (numStretch > 1.0) {
      double d;
      double d1;
      int i2;
      stretchEnd = lineStretches[b_i + lineStretches.size(0)];
      i = static_cast<int>(orientPerm[static_cast<int>(numStretch - 1.0) - 1]) -
          1;
      i1 = static_cast<int>(orientPerm[static_cast<int>(numStretch) - 1]) - 1;
      d = pts[i + pts.size(0)];
      i2 = static_cast<int>(orientPerm[static_cast<int>(stretchEnd) - 1]) - 1;
      d1 = pts[i];
      if ((pts[i1] - d1) * (pts[i2 + pts.size(0)] - d) -
              (pts[i1 + pts.size(0)] - d) * (pts[i2] - d1) <
          0.0) {
        if (numStretch > stretchEnd) {
          i = 1;
          i1 = 1;
          i2 = 0;
          npts = 0;
        } else {
          i = static_cast<int>(stretchEnd);
          i1 = -1;
          i2 = static_cast<int>(numStretch);
          npts = static_cast<int>(numStretch) - 1;
        }
        iindx = div_s32_floor(i2 - i, i1);
        corner_pt.set_size(1, iindx + 1);
        for (i2 = 0; i2 <= iindx; i2++) {
          corner_pt[i2] = orientPerm[(i + i1 * i2) - 1];
        }
        iindx = corner_pt.size(1);
        for (i = 0; i < iindx; i++) {
          orientPerm[npts + i] = corner_pt[i];
        }
      }
    }
  }
  loop_ub = pts.size(1);
  orientedPts.set_size(orientPerm.size(0), pts.size(1));
  for (i = 0; i < loop_ub; i++) {
    iindx = orientPerm.size(0);
    for (i1 = 0; i1 < iindx; i1++) {
      orientedPts[i1 + orientedPts.size(0) * i] =
          pts[(static_cast<int>(orientPerm[i1]) + pts.size(0) * i) - 1];
    }
  }
}

} // namespace coder
static int div_s32_floor(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int absDenominator;
    unsigned int absNumerator;
    unsigned int tempAbsQuotient;
    bool quotientNeedsNegation;
    if (numerator < 0) {
      absNumerator = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      absNumerator = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      absDenominator = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      absDenominator = static_cast<unsigned int>(denominator);
    }
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
      quotient = -static_cast<int>(tempAbsQuotient);
    } else {
      quotient = static_cast<int>(tempAbsQuotient);
    }
  }
  return quotient;
}

namespace coder {
void convhull(const ::coder::array<double, 2U> &varargin_1,
              const ::coder::array<double, 2U> &varargin_2,
              ::coder::array<double, 1U> &varargout_1)
{
  array<double, 2U> c_result;
  array<double, 2U> d_result;
  array<double, 2U> diffPt;
  array<double, 2U> farthestSouth;
  array<double, 2U> ptsLikelyOnHull;
  array<double, 2U> result;
  array<double, 1U> b_result;
  array<double, 1U> northPoints;
  array<int, 2U> hull;
  array<int, 2U> r1;
  array<int, 1U> b_diffPt;
  array<int, 1U> ii;
  array<int, 1U> r;
  array<int, 1U> r2;
  array<bool, 1U> linePts;
  array<bool, 1U> northPts;
  array<bool, 1U> pointsOffHull;
  array<bool, 1U> ptsInNorthTria;
  array<bool, 1U> ptsInSouthTria;
  double ex;
  int end;
  int i;
  int i1;
  int iindx;
  int k;
  int loop_ub;
  int npts;
  bool ptsAreCollinear;
  result.set_size(varargin_1.size(1), 2);
  loop_ub = varargin_1.size(1);
  for (i = 0; i < loop_ub; i++) {
    result[i] = varargin_1[i];
  }
  loop_ub = varargin_2.size(1);
  for (i = 0; i < loop_ub; i++) {
    result[i + result.size(0)] = varargin_2[i];
  }
  if (result.size(0) == 0) {
    pointsOffHull.set_size(0);
  } else {
    loop_ub = result.size(0);
    b_result.set_size(result.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_result[i] = result[i];
    }
    internal::minimum(b_result, &ex, &npts);
    loop_ub = result.size(0);
    b_result.set_size(result.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_result[i] = result[i];
    }
    internal::maximum(b_result, &ex, &iindx);
    getFarthestPoints(result, static_cast<double>(npts),
                      static_cast<double>(iindx), ptsLikelyOnHull,
                      farthestSouth, northPts, linePts, &ptsAreCollinear);
    if (ptsAreCollinear) {
      pointsOffHull.set_size(result.size(0));
      loop_ub = result.size(0);
      for (i = 0; i < loop_ub; i++) {
        pointsOffHull[i] = false;
      }
    } else {
      ptsInNorthTria.set_size(0);
      if ((ptsLikelyOnHull.size(0) != 0) && (ptsLikelyOnHull.size(1) != 0)) {
        diffPt.set_size(1, 2);
        c_result.set_size(1, 2);
        d_result.set_size(1, 2);
        diffPt[0] = result[npts - 1];
        c_result[0] = result[static_cast<int>(ptsLikelyOnHull[0]) - 1];
        d_result[0] = result[iindx - 1];
        diffPt[1] = result[(npts + result.size(0)) - 1];
        c_result[1] =
            result[(static_cast<int>(ptsLikelyOnHull[0]) + result.size(0)) - 1];
        d_result[1] = result[(iindx + result.size(0)) - 1];
        markPtsInTria(result, diffPt, c_result, d_result, ptsInNorthTria);
      }
      ptsInSouthTria.set_size(0);
      if ((farthestSouth.size(0) != 0) && (farthestSouth.size(1) != 0)) {
        diffPt.set_size(1, 2);
        c_result.set_size(1, 2);
        d_result.set_size(1, 2);
        diffPt[0] = result[npts - 1];
        c_result[0] = result[static_cast<int>(farthestSouth[0]) - 1];
        d_result[0] = result[iindx - 1];
        diffPt[1] = result[(npts + result.size(0)) - 1];
        c_result[1] =
            result[(static_cast<int>(farthestSouth[0]) + result.size(0)) - 1];
        d_result[1] = result[(iindx + result.size(0)) - 1];
        markPtsInTria(result, diffPt, c_result, d_result, ptsInSouthTria);
      }
      if ((ptsLikelyOnHull.size(0) != 0) && (ptsLikelyOnHull.size(1) != 0) &&
          ((farthestSouth.size(0) != 0) && (farthestSouth.size(1) != 0))) {
        pointsOffHull.set_size(linePts.size(0));
        loop_ub = linePts.size(0);
        for (i = 0; i < loop_ub; i++) {
          pointsOffHull[i] = linePts[i];
        }
      } else {
        pointsOffHull.set_size(result.size(0));
        loop_ub = result.size(0);
        for (i = 0; i < loop_ub; i++) {
          pointsOffHull[i] = false;
        }
      }
      if (ptsInNorthTria.size(0) != 0) {
        loop_ub = pointsOffHull.size(0);
        for (i = 0; i < loop_ub; i++) {
          pointsOffHull[i] = (pointsOffHull[i] || ptsInNorthTria[i]);
        }
      }
      if (ptsInSouthTria.size(0) != 0) {
        loop_ub = pointsOffHull.size(0);
        for (i = 0; i < loop_ub; i++) {
          pointsOffHull[i] = (pointsOffHull[i] || ptsInSouthTria[i]);
        }
      }
      pointsOffHull[npts - 1] = false;
      pointsOffHull[iindx - 1] = false;
      r1.set_size(ptsLikelyOnHull.size(0), ptsLikelyOnHull.size(1));
      loop_ub = ptsLikelyOnHull.size(0) * ptsLikelyOnHull.size(1);
      for (i = 0; i < loop_ub; i++) {
        r1[i] = static_cast<int>(ptsLikelyOnHull[i]);
      }
      loop_ub = r1.size(0) * r1.size(1);
      for (i = 0; i < loop_ub; i++) {
        pointsOffHull[r1[i] - 1] = false;
      }
      r1.set_size(farthestSouth.size(0), farthestSouth.size(1));
      loop_ub = farthestSouth.size(0) * farthestSouth.size(1);
      for (i = 0; i < loop_ub; i++) {
        r1[i] = static_cast<int>(farthestSouth[i]);
      }
      loop_ub = r1.size(0) * r1.size(1);
      for (i = 0; i < loop_ub; i++) {
        pointsOffHull[r1[i] - 1] = false;
      }
      eml_find(northPts, ii);
      northPoints.set_size(ii.size(0));
      loop_ub = ii.size(0);
      for (i = 0; i < loop_ub; i++) {
        northPoints[i] = ii[i];
      }
      end = northPts.size(0) - 1;
      iindx = 0;
      for (npts = 0; npts <= end; npts++) {
        if (northPts[npts]) {
          iindx++;
        }
      }
      b_diffPt.set_size(iindx);
      iindx = 0;
      for (npts = 0; npts <= end; npts++) {
        if (northPts[npts]) {
          b_diffPt[iindx] = npts + 1;
          iindx++;
        }
      }
      ptsLikelyOnHull.set_size(b_diffPt.size(0), 2);
      loop_ub = b_diffPt.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          ptsLikelyOnHull[i1 + ptsLikelyOnHull.size(0) * i] =
              result[(b_diffPt[i1] + result.size(0) * i) - 1];
        }
      }
      qhullReject2D(ptsLikelyOnHull, ptsInNorthTria);
      end = ptsInNorthTria.size(0);
      for (npts = 0; npts < end; npts++) {
        if (ptsInNorthTria[npts]) {
          pointsOffHull[static_cast<int>(northPoints[npts]) - 1] = true;
        }
      }
      ptsInNorthTria.set_size(linePts.size(0));
      loop_ub = linePts.size(0);
      for (i = 0; i < loop_ub; i++) {
        ptsInNorthTria[i] = ((!linePts[i]) && (!northPts[i]));
      }
      eml_find(ptsInNorthTria, ii);
      northPoints.set_size(ii.size(0));
      loop_ub = ii.size(0);
      for (i = 0; i < loop_ub; i++) {
        northPoints[i] = ii[i];
      }
      end = linePts.size(0) - 1;
      iindx = 0;
      for (npts = 0; npts <= end; npts++) {
        if ((!linePts[npts]) && (!northPts[npts])) {
          iindx++;
        }
      }
      r2.set_size(iindx);
      iindx = 0;
      for (npts = 0; npts <= end; npts++) {
        if ((!linePts[npts]) && (!northPts[npts])) {
          r2[iindx] = npts + 1;
          iindx++;
        }
      }
      ptsLikelyOnHull.set_size(r2.size(0), 2);
      loop_ub = r2.size(0);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          ptsLikelyOnHull[i1 + ptsLikelyOnHull.size(0) * i] =
              result[(r2[i1] + result.size(0) * i) - 1];
        }
      }
      qhullReject2D(ptsLikelyOnHull, ptsInNorthTria);
      end = ptsInNorthTria.size(0);
      for (npts = 0; npts < end; npts++) {
        if (ptsInNorthTria[npts]) {
          pointsOffHull[static_cast<int>(northPoints[npts]) - 1] = true;
        }
      }
    }
  }
  end = pointsOffHull.size(0) - 1;
  iindx = 0;
  for (npts = 0; npts <= end; npts++) {
    if (!pointsOffHull[npts]) {
      iindx++;
    }
  }
  r.set_size(iindx);
  iindx = 0;
  for (npts = 0; npts <= end; npts++) {
    if (!pointsOffHull[npts]) {
      r[iindx] = npts + 1;
      iindx++;
    }
  }
  ptsLikelyOnHull.set_size(r.size(0), 2);
  loop_ub = r.size(0);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      ptsLikelyOnHull[i1 + ptsLikelyOnHull.size(0) * i] =
          result[(r[i1] + result.size(0) * i) - 1];
    }
  }
  orient(ptsLikelyOnHull, farthestSouth, northPoints);
  loop_ub = farthestSouth.size(0);
  b_result.set_size(farthestSouth.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_result[i] = farthestSouth[i + farthestSouth.size(0)];
  }
  internal::minimum(b_result, &ex, &npts);
  if (r.size(0) < npts) {
    diffPt.set_size(1, 0);
  } else {
    diffPt.set_size(1, (r.size(0) - npts) + 1);
    loop_ub = r.size(0) - npts;
    for (i = 0; i <= loop_ub; i++) {
      diffPt[i] = npts + i;
    }
  }
  if (static_cast<double>(npts) - 1.0 < 1.0) {
    c_result.set_size(1, 0);
  } else {
    c_result.set_size(
        1, static_cast<int>((static_cast<double>(npts) - 1.0) - 1.0) + 1);
    loop_ub = static_cast<int>((static_cast<double>(npts) - 1.0) - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      c_result[i] = static_cast<double>(i) + 1.0;
    }
  }
  b_diffPt.set_size(diffPt.size(1) + c_result.size(1));
  loop_ub = diffPt.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_diffPt[i] = static_cast<int>(diffPt[i]) - 1;
  }
  loop_ub = c_result.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_diffPt[i + diffPt.size(1)] = static_cast<int>(c_result[i]) - 1;
  }
  ii.set_size(b_diffPt.size(0));
  loop_ub = b_diffPt.size(0);
  for (i = 0; i < loop_ub; i++) {
    ii[i] = static_cast<int>(northPoints[b_diffPt[i]]);
  }
  npts = r.size(0);
  hull.set_size(1, r.size(0) + 1);
  loop_ub = r.size(0) + 1;
  for (i = 0; i < loop_ub; i++) {
    hull[i] = 0;
  }
  k = -2;
  for (loop_ub = 0; loop_ub <= npts; loop_ub++) {
    unsigned int b_i;
    bool b_guard1{false};
    bool guard1{false};
    if (static_cast<unsigned int>(loop_ub) == static_cast<unsigned int>(npts)) {
      b_i = 1U;
    } else {
      b_i = loop_ub + 1U;
    }
    guard1 = false;
    b_guard1 = false;
    if (k + 3 > 1) {
      iindx = hull[k + 1];
      diffPt.set_size(1, 2);
      end = ii[static_cast<int>(b_i) - 1] - 1;
      diffPt[0] = ptsLikelyOnHull[end] - ptsLikelyOnHull[iindx - 1];
      diffPt[1] = ptsLikelyOnHull[end + ptsLikelyOnHull.size(0)] -
                  ptsLikelyOnHull[(iindx + ptsLikelyOnHull.size(0)) - 1];
      if ((!(diffPt[0] == 0.0)) || (!(diffPt[1] == 0.0))) {
        b_guard1 = true;
      }
    } else {
      b_guard1 = true;
    }
    if (b_guard1) {
      int exitg2;
      do {
        exitg2 = 0;
        if (k + 3 >= 3) {
          double d;
          i = hull[k + 1] - 1;
          ex = ptsLikelyOnHull[(hull[k] + ptsLikelyOnHull.size(0)) - 1];
          i1 = ii[static_cast<int>(b_i) - 1] - 1;
          d = ptsLikelyOnHull[hull[k] - 1];
          if ((ptsLikelyOnHull[i] - d) *
                      (ptsLikelyOnHull[i1 + ptsLikelyOnHull.size(0)] - ex) -
                  (ptsLikelyOnHull[i + ptsLikelyOnHull.size(0)] - ex) *
                      (ptsLikelyOnHull[i1] - d) <
              0.0) {
            k--;
          } else {
            guard1 = true;
            exitg2 = 1;
          }
        } else {
          guard1 = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }
    if (guard1) {
      hull[k + 2] = ii[static_cast<int>(b_i) - 1];
      k++;
    }
  }
  if (1 > k + 2) {
    loop_ub = 0;
    i = 0;
  } else {
    loop_ub = k + 2;
    i = k + 2;
  }
  hull.set_size(hull.size(0), i);
  iindx = pointsOffHull.size(0);
  for (i = 0; i < iindx; i++) {
    pointsOffHull[i] = !pointsOffHull[i];
  }
  eml_find(pointsOffHull, ii);
  northPoints.set_size(ii.size(0));
  iindx = ii.size(0);
  for (i = 0; i < iindx; i++) {
    northPoints[i] = ii[i];
  }
  varargout_1.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    varargout_1[i] = northPoints[hull[i] - 1];
  }
  internal::minimum(varargout_1, &ex, &npts);
  if (npts != 1) {
    if (npts > loop_ub - 1) {
      i = 0;
      i1 = 0;
    } else {
      i = npts - 1;
      i1 = loop_ub - 1;
    }
    if (1.0 > static_cast<double>(npts) - 1.0) {
      loop_ub = 1;
    } else {
      loop_ub = npts;
    }
    iindx = i1 - i;
    end = iindx + loop_ub;
    b_result.set_size(end);
    for (k = 0; k < iindx; k++) {
      b_result[k] = varargout_1[i + k];
    }
    for (k = 0; k <= loop_ub - 2; k++) {
      b_result[(k + i1) - i] = varargout_1[k];
    }
    b_result[end - 1] = northPoints[hull[npts - 1] - 1];
    varargout_1.set_size(b_result.size(0));
    loop_ub = b_result.size(0);
    for (i = 0; i < loop_ub; i++) {
      varargout_1[i] = b_result[i];
    }
  }
}

} // namespace coder

// End of code generation (convhull.cpp)
