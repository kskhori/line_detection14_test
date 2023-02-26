//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// introsort.cpp
//
// Code generation for function 'introsort'
//

// Include files
#include "introsort.h"
#include "anonymous_function.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "line_detection14_internal_types.h"
#include "rt_nonfinite.h"
#include "stack1.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
namespace coder {
namespace internal {
void introsort(::coder::array<double, 1U> &x, int xstart, int xend,
               const anonymous_function *cmp)
{
  stack st;
  struct_T frame;
  if (xstart < xend) {
    int nsort;
    nsort = (xend - xstart) + 1;
    if (nsort <= 32) {
      insertionsort(x, xstart, xend, cmp);
    } else {
      int MAXDEPTH;
      int pmax;
      int pmin;
      int pow2p;
      bool exitg1;
      pmax = 31;
      pmin = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax - pmin > 1)) {
        MAXDEPTH = (pmin + pmax) >> 1;
        pow2p = 1 << MAXDEPTH;
        if (pow2p == nsort) {
          pmax = MAXDEPTH;
          exitg1 = true;
        } else if (pow2p > nsort) {
          pmax = MAXDEPTH;
        } else {
          pmin = MAXDEPTH;
        }
      }
      signed char unnamed_idx_0;
      MAXDEPTH = (pmax - 1) << 1;
      frame.xstart = xstart;
      frame.xend = xend;
      frame.depth = 0;
      unnamed_idx_0 = static_cast<signed char>(MAXDEPTH << 1);
      st.d.set_size(static_cast<int>(unnamed_idx_0));
      nsort = unnamed_idx_0;
      for (pow2p = 0; pow2p < nsort; pow2p++) {
        st.d[pow2p] = frame;
      }
      st.d[0] = frame;
      st.n = 1;
      while (st.n > 0) {
        pmin = st.n - 1;
        frame = st.d[st.n - 1];
        st.n--;
        pow2p = frame.xend - frame.xstart;
        if (pow2p + 1 <= 32) {
          insertionsort(x, frame.xstart, frame.xend, cmp);
        } else if (frame.depth == MAXDEPTH) {
          b_heapsort(x, frame.xstart, frame.xend, cmp);
        } else {
          double d;
          double pivot;
          double t;
          bool varargout_1;
          nsort = (frame.xstart + ((pow2p + (pow2p < 0)) >> 1)) - 1;
          d = x[frame.xstart - 1];
          t = cmp->workspace
                  .pts[(static_cast<int>(d) + cmp->workspace.pts.size(0)) - 1];
          if (t > cmp->workspace.pts[(static_cast<int>(x[nsort]) +
                                      cmp->workspace.pts.size(0)) -
                                     1]) {
            varargout_1 = true;
          } else if (t < cmp->workspace.pts[(static_cast<int>(x[nsort]) +
                                             cmp->workspace.pts.size(0)) -
                                            1]) {
            varargout_1 = false;
          } else {
            varargout_1 = (cmp->workspace.pts[static_cast<int>(d) - 1] >
                           cmp->workspace.pts[static_cast<int>(x[nsort]) - 1]);
          }
          if (varargout_1) {
            x[frame.xstart - 1] = x[nsort];
            x[nsort] = d;
          }
          if (cmp->workspace.pts[(static_cast<int>(x[frame.xstart - 1]) +
                                  cmp->workspace.pts.size(0)) -
                                 1] >
              cmp->workspace.pts[(static_cast<int>(x[frame.xend - 1]) +
                                  cmp->workspace.pts.size(0)) -
                                 1]) {
            varargout_1 = true;
          } else {
            pow2p = static_cast<int>(x[frame.xstart - 1]) - 1;
            pmax = static_cast<int>(x[frame.xend - 1]) - 1;
            if (cmp->workspace.pts[pow2p + cmp->workspace.pts.size(0)] <
                cmp->workspace.pts[pmax + cmp->workspace.pts.size(0)]) {
              varargout_1 = false;
            } else {
              varargout_1 =
                  (cmp->workspace.pts[pow2p] > cmp->workspace.pts[pmax]);
            }
          }
          if (varargout_1) {
            t = x[frame.xstart - 1];
            x[frame.xstart - 1] = x[frame.xend - 1];
            x[frame.xend - 1] = t;
          }
          if (cmp->workspace.pts[(static_cast<int>(x[nsort]) +
                                  cmp->workspace.pts.size(0)) -
                                 1] >
              cmp->workspace.pts[(static_cast<int>(x[frame.xend - 1]) +
                                  cmp->workspace.pts.size(0)) -
                                 1]) {
            varargout_1 = true;
          } else {
            pow2p = static_cast<int>(x[frame.xend - 1]) - 1;
            if (cmp->workspace.pts[(static_cast<int>(x[nsort]) +
                                    cmp->workspace.pts.size(0)) -
                                   1] <
                cmp->workspace.pts[pow2p + cmp->workspace.pts.size(0)]) {
              varargout_1 = false;
            } else {
              varargout_1 =
                  (cmp->workspace.pts[static_cast<int>(x[nsort]) - 1] >
                   cmp->workspace.pts[pow2p]);
            }
          }
          if (varargout_1) {
            t = x[nsort];
            x[nsort] = x[frame.xend - 1];
            x[frame.xend - 1] = t;
          }
          pivot = x[nsort];
          x[nsort] = x[frame.xend - 2];
          x[frame.xend - 2] = pivot;
          nsort = frame.xstart - 1;
          pmax = frame.xend - 2;
          d = cmp->workspace
                  .pts[(static_cast<int>(pivot) + cmp->workspace.pts.size(0)) -
                       1];
          int exitg2;
          do {
            int exitg3;
            exitg2 = 0;
            nsort++;
            do {
              exitg3 = 0;
              pow2p = static_cast<int>(x[nsort]) - 1;
              t = cmp->workspace.pts[pow2p + cmp->workspace.pts.size(0)];
              if (d > t) {
                varargout_1 = true;
              } else if (d < t) {
                varargout_1 = false;
              } else {
                varargout_1 = (cmp->workspace.pts[static_cast<int>(pivot) - 1] >
                               cmp->workspace.pts[pow2p]);
              }
              if (varargout_1) {
                nsort++;
              } else {
                exitg3 = 1;
              }
            } while (exitg3 == 0);
            pmax--;
            do {
              exitg3 = 0;
              pow2p = static_cast<int>(x[pmax]) - 1;
              t = cmp->workspace.pts[pow2p + cmp->workspace.pts.size(0)];
              if (t > d) {
                varargout_1 = true;
              } else if (t < d) {
                varargout_1 = false;
              } else {
                varargout_1 = (cmp->workspace.pts[pow2p] >
                               cmp->workspace.pts[static_cast<int>(pivot) - 1]);
              }
              if (varargout_1) {
                pmax--;
              } else {
                exitg3 = 1;
              }
            } while (exitg3 == 0);
            if (nsort + 1 >= pmax + 1) {
              exitg2 = 1;
            } else {
              t = x[nsort];
              x[nsort] = x[pmax];
              x[pmax] = t;
            }
          } while (exitg2 == 0);
          x[frame.xend - 2] = x[nsort];
          x[nsort] = pivot;
          if (nsort + 2 < frame.xend) {
            st.d[pmin].xstart = nsort + 2;
            st.d[pmin].xend = frame.xend;
            st.d[pmin].depth = frame.depth + 1;
            st.n = pmin + 1;
          }
          if (frame.xstart < nsort + 1) {
            st.d[st.n].xstart = frame.xstart;
            st.d[st.n].xend = nsort + 1;
            st.d[st.n].depth = frame.depth + 1;
            st.n++;
          }
        }
      }
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (introsort.cpp)
