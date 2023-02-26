//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// qhullReject2D.cpp
//
// Code generation for function 'qhullReject2D'
//

// Include files
#include "qhullReject2D.h"
#include "find.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>
#include <string.h>

// Function Declarations
namespace coder {
static void b_qhullReject2D(const ::coder::array<double, 2U> &pts,
                            ::coder::array<bool, 1U> &ptsOffHull);

}

// Function Definitions
namespace coder {
static void b_qhullReject2D(const ::coder::array<double, 2U> &pts,
                            ::coder::array<bool, 1U> &ptsOffHull)
{
  array<double, 2U> c_pts;
  array<double, 2U> d_pts;
  array<double, 2U> e_pts;
  array<double, 2U> farthestNorth;
  array<double, 2U> farthestSouth;
  array<double, 1U> b_pts;
  array<int, 2U> r;
  array<bool, 1U> ptsInNorthTria;
  array<bool, 1U> ptsInSouthTria;
  double ex;
  int b_iindx;
  int iindx;
  bool ptsAreCollinear;
  if ((pts.size(0) == 0) || (pts.size(1) == 0)) {
    ptsOffHull.set_size(0);
  } else {
    int i;
    int loop_ub;
    loop_ub = pts.size(0);
    b_pts.set_size(pts.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_pts[i] = pts[i];
    }
    internal::minimum(b_pts, &ex, &iindx);
    loop_ub = pts.size(0);
    b_pts.set_size(pts.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_pts[i] = pts[i];
    }
    internal::maximum(b_pts, &ex, &b_iindx);
    getFarthestPoints(pts, static_cast<double>(iindx),
                      static_cast<double>(b_iindx), farthestNorth,
                      farthestSouth, ptsInNorthTria, ptsOffHull,
                      &ptsAreCollinear);
    if (ptsAreCollinear) {
      ptsOffHull.set_size(pts.size(0));
      loop_ub = pts.size(0);
      for (i = 0; i < loop_ub; i++) {
        ptsOffHull[i] = false;
      }
    } else {
      ptsInNorthTria.set_size(0);
      if ((farthestNorth.size(0) != 0) && (farthestNorth.size(1) != 0)) {
        loop_ub = pts.size(1);
        c_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          c_pts[i] = pts[(iindx + pts.size(0) * i) - 1];
        }
        loop_ub = pts.size(1);
        d_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          d_pts[i] =
              pts[(static_cast<int>(farthestNorth[0]) + pts.size(0) * i) - 1];
        }
        loop_ub = pts.size(1);
        e_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          e_pts[i] = pts[(b_iindx + pts.size(0) * i) - 1];
        }
        markPtsInTria(pts, c_pts, d_pts, e_pts, ptsInNorthTria);
      }
      ptsInSouthTria.set_size(0);
      if ((farthestSouth.size(0) != 0) && (farthestSouth.size(1) != 0)) {
        loop_ub = pts.size(1);
        c_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          c_pts[i] = pts[(iindx + pts.size(0) * i) - 1];
        }
        loop_ub = pts.size(1);
        d_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          d_pts[i] =
              pts[(static_cast<int>(farthestSouth[0]) + pts.size(0) * i) - 1];
        }
        loop_ub = pts.size(1);
        e_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          e_pts[i] = pts[(b_iindx + pts.size(0) * i) - 1];
        }
        markPtsInTria(pts, c_pts, d_pts, e_pts, ptsInSouthTria);
      }
      if ((farthestNorth.size(0) == 0) || (farthestNorth.size(1) == 0) ||
          ((farthestSouth.size(0) == 0) || (farthestSouth.size(1) == 0))) {
        ptsOffHull.set_size(pts.size(0));
        loop_ub = pts.size(0);
        for (i = 0; i < loop_ub; i++) {
          ptsOffHull[i] = false;
        }
      }
      if (ptsInNorthTria.size(0) != 0) {
        loop_ub = ptsOffHull.size(0);
        for (i = 0; i < loop_ub; i++) {
          ptsOffHull[i] = (ptsOffHull[i] || ptsInNorthTria[i]);
        }
      }
      if (ptsInSouthTria.size(0) != 0) {
        loop_ub = ptsOffHull.size(0);
        for (i = 0; i < loop_ub; i++) {
          ptsOffHull[i] = (ptsOffHull[i] || ptsInSouthTria[i]);
        }
      }
      ptsOffHull[iindx - 1] = false;
      ptsOffHull[b_iindx - 1] = false;
      r.set_size(farthestNorth.size(0), farthestNorth.size(1));
      loop_ub = farthestNorth.size(0) * farthestNorth.size(1);
      for (i = 0; i < loop_ub; i++) {
        r[i] = static_cast<int>(farthestNorth[i]);
      }
      loop_ub = r.size(0) * r.size(1);
      for (i = 0; i < loop_ub; i++) {
        ptsOffHull[r[i] - 1] = false;
      }
      r.set_size(farthestSouth.size(0), farthestSouth.size(1));
      loop_ub = farthestSouth.size(0) * farthestSouth.size(1);
      for (i = 0; i < loop_ub; i++) {
        r[i] = static_cast<int>(farthestSouth[i]);
      }
      loop_ub = r.size(0) * r.size(1);
      for (i = 0; i < loop_ub; i++) {
        ptsOffHull[r[i] - 1] = false;
      }
    }
  }
}

void getFarthestPoints(const ::coder::array<double, 2U> &pts, double pt1,
                       double pt2, ::coder::array<double, 2U> &farthestNorth,
                       ::coder::array<double, 2U> &farthestSouth,
                       ::coder::array<bool, 1U> &northPts,
                       ::coder::array<bool, 1U> &linePts, bool *collinearPts)
{
  array<double, 1U> distVector;
  double a;
  double b;
  double b_tmp;
  double c;
  int exponent;
  int i;
  int iindx;
  c = pts[(static_cast<int>(pt2) + pts.size(0)) - 1];
  a = pts[(static_cast<int>(pt1) + pts.size(0)) - 1] - c;
  b_tmp = pts[static_cast<int>(pt2) - 1];
  b = b_tmp - pts[static_cast<int>(pt1) - 1];
  c = c * -b - b_tmp * a;
  iindx = pts.size(0);
  distVector.set_size(pts.size(0));
  northPts.set_size(pts.size(0));
  linePts.set_size(pts.size(0));
  for (i = 0; i < iindx; i++) {
    b_tmp = (a * pts[i] + b * pts[i + pts.size(0)]) + c;
    distVector[i] = b_tmp;
    northPts[i] = (b_tmp > 0.0);
    linePts[i] = (b_tmp == 0.0);
  }
  internal::minimum(distVector, &b, &iindx);
  internal::maximum(distVector, &a, &i);
  farthestSouth.set_size(0, 0);
  farthestNorth.set_size(0, 0);
  if ((i != pt1) && (i != pt2)) {
    farthestNorth.set_size(1, 1);
    farthestNorth[0] = i;
  }
  if ((iindx != pt1) && (iindx != pt2)) {
    farthestSouth.set_size(1, 1);
    farthestSouth[0] = iindx;
  }
  c = std::abs(b / 2.0);
  if ((!std::isinf(c)) && (!std::isnan(c))) {
    if (c <= 2.2250738585072014E-308) {
      c = 4.94065645841247E-324;
    } else {
      frexp(c, &exponent);
      c = std::ldexp(1.0, exponent - 53);
    }
  } else {
    c = rtNaN;
  }
  if ((std::abs(b - a) < c) ||
      (std::isinf(a) && std::isinf(b) && ((a > 0.0) == (b > 0.0)))) {
    *collinearPts = true;
  } else {
    *collinearPts = false;
  }
}

void markPtsInTria(const ::coder::array<double, 2U> &pts,
                   const ::coder::array<double, 2U> &a,
                   const ::coder::array<double, 2U> &b,
                   const ::coder::array<double, 2U> &c,
                   ::coder::array<bool, 1U> &ptsInTria)
{
  array<double, 2U> centeroid;
  double slope_ab;
  double slope_bc;
  double slope_ca;
  slope_ab = (b[1] - a[1]) / (b[0] - a[0]);
  slope_bc = (c[1] - b[1]) / (c[0] - b[0]);
  slope_ca = (a[1] - c[1]) / (a[0] - c[0]);
  if (std::isinf(slope_ab) || std::isinf(slope_bc) || std::isinf(slope_ca)) {
    int loop_ub;
    ptsInTria.set_size(pts.size(0));
    loop_ub = pts.size(0);
    for (int i{0}; i < loop_ub; i++) {
      ptsInTria[i] = false;
    }
  } else {
    int i;
    int loop_ub;
    bool centeroid_parity_ab_b;
    bool centeroid_parity_bc_b;
    bool centeroid_parity_ca_b;
    centeroid.set_size(1, a.size(1));
    loop_ub = a.size(1);
    for (i = 0; i < loop_ub; i++) {
      centeroid[i] = ((a[i] + b[i]) + c[i]) / 3.0;
    }
    ptsInTria.set_size(pts.size(0));
    centeroid_parity_ab_b =
        (slope_ab * (centeroid[0] - a[0]) - (centeroid[1] - a[1]) < 0.0);
    centeroid_parity_bc_b =
        (slope_bc * (centeroid[0] - b[0]) - (centeroid[1] - b[1]) < 0.0);
    centeroid_parity_ca_b =
        (slope_ca * (centeroid[0] - c[0]) - (centeroid[1] - c[1]) < 0.0);
    i = pts.size(0);
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      double d;
      double d1;
      d = pts[loop_ub];
      d1 = pts[loop_ub + pts.size(0)];
      ptsInTria[loop_ub] = (((slope_ab * (d - a[0]) - (d1 - a[1]) < 0.0) ==
                             centeroid_parity_ab_b) &&
                            ((slope_bc * (d - b[0]) - (d1 - b[1]) < 0.0) ==
                             centeroid_parity_bc_b) &&
                            ((slope_ca * (d - c[0]) - (d1 - c[1]) < 0.0) ==
                             centeroid_parity_ca_b));
    }
  }
}

void qhullReject2D(const ::coder::array<double, 2U> &pts,
                   ::coder::array<bool, 1U> &ptsOffHull)
{
  array<double, 2U> c_pts;
  array<double, 2U> d_pts;
  array<double, 2U> e_pts;
  array<double, 2U> farthestNorth;
  array<double, 2U> farthestSouth;
  array<double, 1U> b_pts;
  array<int, 2U> r;
  array<int, 1U> ii;
  array<int, 1U> r1;
  array<int, 1U> r2;
  array<bool, 1U> linePts;
  array<bool, 1U> northPts;
  array<bool, 1U> ptsInNorthTria;
  array<bool, 1U> ptsInSouthTria;
  double ex;
  int b_iindx;
  int iindx;
  bool ptsAreCollinear;
  if ((pts.size(0) == 0) || (pts.size(1) == 0)) {
    ptsOffHull.set_size(0);
  } else {
    int i;
    int loop_ub;
    loop_ub = pts.size(0);
    b_pts.set_size(pts.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_pts[i] = pts[i];
    }
    internal::minimum(b_pts, &ex, &iindx);
    loop_ub = pts.size(0);
    b_pts.set_size(pts.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_pts[i] = pts[i];
    }
    internal::maximum(b_pts, &ex, &b_iindx);
    getFarthestPoints(pts, static_cast<double>(iindx),
                      static_cast<double>(b_iindx), farthestNorth,
                      farthestSouth, northPts, linePts, &ptsAreCollinear);
    if (ptsAreCollinear) {
      ptsOffHull.set_size(pts.size(0));
      loop_ub = pts.size(0);
      for (i = 0; i < loop_ub; i++) {
        ptsOffHull[i] = false;
      }
    } else {
      ptsInNorthTria.set_size(0);
      if ((farthestNorth.size(0) != 0) && (farthestNorth.size(1) != 0)) {
        loop_ub = pts.size(1);
        c_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          c_pts[i] = pts[(iindx + pts.size(0) * i) - 1];
        }
        loop_ub = pts.size(1);
        d_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          d_pts[i] =
              pts[(static_cast<int>(farthestNorth[0]) + pts.size(0) * i) - 1];
        }
        loop_ub = pts.size(1);
        e_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          e_pts[i] = pts[(b_iindx + pts.size(0) * i) - 1];
        }
        markPtsInTria(pts, c_pts, d_pts, e_pts, ptsInNorthTria);
      }
      ptsInSouthTria.set_size(0);
      if ((farthestSouth.size(0) != 0) && (farthestSouth.size(1) != 0)) {
        loop_ub = pts.size(1);
        c_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          c_pts[i] = pts[(iindx + pts.size(0) * i) - 1];
        }
        loop_ub = pts.size(1);
        d_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          d_pts[i] =
              pts[(static_cast<int>(farthestSouth[0]) + pts.size(0) * i) - 1];
        }
        loop_ub = pts.size(1);
        e_pts.set_size(1, pts.size(1));
        for (i = 0; i < loop_ub; i++) {
          e_pts[i] = pts[(b_iindx + pts.size(0) * i) - 1];
        }
        markPtsInTria(pts, c_pts, d_pts, e_pts, ptsInSouthTria);
      }
      if ((farthestNorth.size(0) != 0) && (farthestNorth.size(1) != 0) &&
          ((farthestSouth.size(0) != 0) && (farthestSouth.size(1) != 0))) {
        ptsOffHull.set_size(linePts.size(0));
        loop_ub = linePts.size(0);
        for (i = 0; i < loop_ub; i++) {
          ptsOffHull[i] = linePts[i];
        }
      } else {
        ptsOffHull.set_size(pts.size(0));
        loop_ub = pts.size(0);
        for (i = 0; i < loop_ub; i++) {
          ptsOffHull[i] = false;
        }
      }
      if (ptsInNorthTria.size(0) != 0) {
        loop_ub = ptsOffHull.size(0);
        for (i = 0; i < loop_ub; i++) {
          ptsOffHull[i] = (ptsOffHull[i] || ptsInNorthTria[i]);
        }
      }
      if (ptsInSouthTria.size(0) != 0) {
        loop_ub = ptsOffHull.size(0);
        for (i = 0; i < loop_ub; i++) {
          ptsOffHull[i] = (ptsOffHull[i] || ptsInSouthTria[i]);
        }
      }
      ptsOffHull[iindx - 1] = false;
      ptsOffHull[b_iindx - 1] = false;
      r.set_size(farthestNorth.size(0), farthestNorth.size(1));
      loop_ub = farthestNorth.size(0) * farthestNorth.size(1);
      for (i = 0; i < loop_ub; i++) {
        r[i] = static_cast<int>(farthestNorth[i]);
      }
      loop_ub = r.size(0) * r.size(1);
      for (i = 0; i < loop_ub; i++) {
        ptsOffHull[r[i] - 1] = false;
      }
      r.set_size(farthestSouth.size(0), farthestSouth.size(1));
      loop_ub = farthestSouth.size(0) * farthestSouth.size(1);
      for (i = 0; i < loop_ub; i++) {
        r[i] = static_cast<int>(farthestSouth[i]);
      }
      loop_ub = r.size(0) * r.size(1);
      for (i = 0; i < loop_ub; i++) {
        ptsOffHull[r[i] - 1] = false;
      }
      eml_find(northPts, ii);
      b_iindx = northPts.size(0) - 1;
      iindx = 0;
      for (loop_ub = 0; loop_ub <= b_iindx; loop_ub++) {
        if (northPts[loop_ub]) {
          iindx++;
        }
      }
      r1.set_size(iindx);
      iindx = 0;
      for (loop_ub = 0; loop_ub <= b_iindx; loop_ub++) {
        if (northPts[loop_ub]) {
          r1[iindx] = loop_ub + 1;
          iindx++;
        }
      }
      loop_ub = pts.size(1);
      farthestNorth.set_size(r1.size(0), pts.size(1));
      for (i = 0; i < loop_ub; i++) {
        iindx = r1.size(0);
        for (b_iindx = 0; b_iindx < iindx; b_iindx++) {
          farthestNorth[b_iindx + farthestNorth.size(0) * i] =
              pts[(r1[b_iindx] + pts.size(0) * i) - 1];
        }
      }
      b_qhullReject2D(farthestNorth, ptsInNorthTria);
      b_iindx = ptsInNorthTria.size(0);
      for (loop_ub = 0; loop_ub < b_iindx; loop_ub++) {
        if (ptsInNorthTria[loop_ub]) {
          ptsOffHull[ii[loop_ub] - 1] = true;
        }
      }
      ptsInNorthTria.set_size(linePts.size(0));
      loop_ub = linePts.size(0);
      for (i = 0; i < loop_ub; i++) {
        ptsInNorthTria[i] = ((!linePts[i]) && (!northPts[i]));
      }
      eml_find(ptsInNorthTria, ii);
      b_iindx = linePts.size(0) - 1;
      iindx = 0;
      for (loop_ub = 0; loop_ub <= b_iindx; loop_ub++) {
        if ((!linePts[loop_ub]) && (!northPts[loop_ub])) {
          iindx++;
        }
      }
      r2.set_size(iindx);
      iindx = 0;
      for (loop_ub = 0; loop_ub <= b_iindx; loop_ub++) {
        if ((!linePts[loop_ub]) && (!northPts[loop_ub])) {
          r2[iindx] = loop_ub + 1;
          iindx++;
        }
      }
      loop_ub = pts.size(1);
      farthestNorth.set_size(r2.size(0), pts.size(1));
      for (i = 0; i < loop_ub; i++) {
        iindx = r2.size(0);
        for (b_iindx = 0; b_iindx < iindx; b_iindx++) {
          farthestNorth[b_iindx + farthestNorth.size(0) * i] =
              pts[(r2[b_iindx] + pts.size(0) * i) - 1];
        }
      }
      b_qhullReject2D(farthestNorth, ptsInNorthTria);
      b_iindx = ptsInNorthTria.size(0);
      for (loop_ub = 0; loop_ub < b_iindx; loop_ub++) {
        if (ptsInNorthTria[loop_ub]) {
          ptsOffHull[ii[loop_ub] - 1] = true;
        }
      }
    }
  }
}

} // namespace coder

// End of code generation (qhullReject2D.cpp)
