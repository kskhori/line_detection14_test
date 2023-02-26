//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// heapsort.cpp
//
// Code generation for function 'heapsort'
//

// Include files
#include "heapsort.h"
#include "anonymous_function.h"
#include "line_detection14_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Declarations
namespace coder {
namespace internal {
static void heapify(::coder::array<double, 1U> &x, int idx, int xstart,
                    int xend, const anonymous_function *cmp);

}
} // namespace coder

// Function Definitions
namespace coder {
namespace internal {
static void heapify(::coder::array<double, 1U> &x, int idx, int xstart,
                    int xend, const anonymous_function *cmp)
{
  double d;
  double d1;
  double extremum;
  int extremumIdx;
  int i;
  int i1;
  int leftIdx;
  bool changed;
  bool exitg1;
  bool varargout_1;
  changed = true;
  extremumIdx = (idx + xstart) - 2;
  leftIdx = ((idx << 1) + xstart) - 2;
  exitg1 = false;
  while ((!exitg1) && (leftIdx + 1 < xend)) {
    double xcmp;
    int cmpIdx;
    changed = false;
    extremum = x[extremumIdx];
    cmpIdx = leftIdx;
    xcmp = x[leftIdx];
    i = static_cast<int>(x[leftIdx + 1]) - 1;
    i1 = static_cast<int>(x[leftIdx]) - 1;
    d = cmp->workspace.pts[i + cmp->workspace.pts.size(0)];
    d1 = cmp->workspace.pts[i1 + cmp->workspace.pts.size(0)];
    if (d > d1) {
      varargout_1 = true;
    } else if (d < d1) {
      varargout_1 = false;
    } else {
      varargout_1 = (cmp->workspace.pts[i] > cmp->workspace.pts[i1]);
    }
    if (varargout_1) {
      cmpIdx = leftIdx + 1;
      xcmp = x[leftIdx + 1];
    }
    i = static_cast<int>(x[extremumIdx]) - 1;
    d = cmp->workspace
            .pts[(static_cast<int>(xcmp) + cmp->workspace.pts.size(0)) - 1];
    d1 = cmp->workspace.pts[i + cmp->workspace.pts.size(0)];
    if (d > d1) {
      varargout_1 = true;
    } else if (d < d1) {
      varargout_1 = false;
    } else {
      varargout_1 = (cmp->workspace.pts[static_cast<int>(xcmp) - 1] >
                     cmp->workspace.pts[i]);
    }
    if (varargout_1) {
      x[extremumIdx] = xcmp;
      x[cmpIdx] = extremum;
      extremumIdx = cmpIdx;
      leftIdx = ((((cmpIdx - xstart) + 2) << 1) + xstart) - 2;
      changed = true;
    } else {
      exitg1 = true;
    }
  }
  if (changed && (leftIdx + 1 <= xend)) {
    extremum = x[extremumIdx];
    i = static_cast<int>(x[leftIdx]) - 1;
    i1 = static_cast<int>(x[extremumIdx]) - 1;
    d = cmp->workspace.pts[i + cmp->workspace.pts.size(0)];
    d1 = cmp->workspace.pts[i1 + cmp->workspace.pts.size(0)];
    if (d > d1) {
      varargout_1 = true;
    } else if (d < d1) {
      varargout_1 = false;
    } else {
      varargout_1 = (cmp->workspace.pts[i] > cmp->workspace.pts[i1]);
    }
    if (varargout_1) {
      x[extremumIdx] = x[leftIdx];
      x[leftIdx] = extremum;
    }
  }
}

void b_heapsort(::coder::array<double, 1U> &x, int xstart, int xend,
                const anonymous_function *cmp)
{
  int idx;
  int n;
  n = (xend - xstart) - 1;
  for (idx = n + 2; idx >= 1; idx--) {
    heapify(x, idx, xstart, xend, cmp);
  }
  for (int k{0}; k <= n; k++) {
    double t;
    idx = (xend - k) - 1;
    t = x[idx];
    x[idx] = x[xstart - 1];
    x[xstart - 1] = t;
    heapify(x, 1, xstart, (xend - k) - 1, cmp);
  }
}

} // namespace internal
} // namespace coder

// End of code generation (heapsort.cpp)
