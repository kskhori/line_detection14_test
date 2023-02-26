//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// minOrMax.cpp
//
// Code generation for function 'minOrMax'
//

// Include files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
namespace coder {
namespace internal {
double maximum(const ::coder::array<double, 1U> &x)
{
  double ex;
  int last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 0) {
      ex = rtNaN;
    } else if (x.size(0) == 1) {
      ex = x[0];
    } else if ((x[0] < x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
      ex = x[1];
    } else {
      ex = x[0];
    }
  } else {
    int idx;
    int k;
    if (!std::isnan(x[0])) {
      idx = 1;
    } else {
      bool exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x[0];
    } else {
      ex = x[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        double d;
        d = x[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

void maximum(const ::coder::array<double, 1U> &x, double *ex, int *idx)
{
  int last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 0) {
      *ex = rtNaN;
      *idx = 1;
    } else if (x.size(0) == 1) {
      *ex = x[0];
      *idx = 1;
    } else if ((x[0] < x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
      *ex = x[1];
      *idx = 2;
    } else {
      *ex = x[0];
      *idx = 1;
    }
  } else {
    int k;
    if (!std::isnan(x[0])) {
      *idx = 1;
    } else {
      bool exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      *ex = x[0];
      *idx = 1;
    } else {
      int i;
      *ex = x[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        double d;
        d = x[k - 1];
        if (*ex < d) {
          *ex = d;
          *idx = k;
        }
      }
    }
  }
}

void maximum(const ::coder::array<double, 2U> &x,
             ::coder::array<double, 1U> &ex)
{
  int m;
  int n;
  m = x.size(0) - 1;
  n = x.size(1);
  ex.set_size(x.size(0));
  if (x.size(1) == 0) {
    ex.set_size(x.size(0));
    m = x.size(0);
    for (n = 0; n < m; n++) {
      ex[n] = rtNaN;
    }
  } else if (x.size(0) >= 1) {
    int i;
    for (i = 0; i <= m; i++) {
      ex[i] = x[i];
    }
    for (int j{2}; j <= n; j++) {
      for (i = 0; i <= m; i++) {
        double b;
        bool p;
        b = x[i + x.size(0) * (j - 1)];
        if (std::isnan(b)) {
          p = false;
        } else if (std::isnan(ex[i])) {
          p = true;
        } else {
          p = (ex[i] < b);
        }
        if (p) {
          ex[i] = b;
        }
      }
    }
  }
}

double maximum(const double x[4])
{
  double ex;
  int idx;
  int k;
  if (!std::isnan(x[0])) {
    idx = 1;
  } else {
    bool exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 4)) {
      if (!std::isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    idx++;
    for (k = idx; k < 5; k++) {
      double d;
      d = x[k - 1];
      if (ex < d) {
        ex = d;
      }
    }
  }
  return ex;
}

void minimum(const ::coder::array<double, 1U> &x, double *ex, int *idx)
{
  int last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 0) {
      *ex = rtNaN;
      *idx = 1;
    } else if (x.size(0) == 1) {
      *ex = x[0];
      *idx = 1;
    } else if ((x[0] > x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
      *ex = x[1];
      *idx = 2;
    } else {
      *ex = x[0];
      *idx = 1;
    }
  } else {
    int k;
    if (!std::isnan(x[0])) {
      *idx = 1;
    } else {
      bool exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      *ex = x[0];
      *idx = 1;
    } else {
      int i;
      *ex = x[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        double d;
        d = x[k - 1];
        if (*ex > d) {
          *ex = d;
          *idx = k;
        }
      }
    }
  }
}

void minimum(const ::coder::array<double, 2U> &x,
             ::coder::array<double, 1U> &ex)
{
  int m;
  int n;
  m = x.size(0) - 1;
  n = x.size(1);
  ex.set_size(x.size(0));
  if (x.size(1) == 0) {
    ex.set_size(x.size(0));
    m = x.size(0);
    for (n = 0; n < m; n++) {
      ex[n] = rtNaN;
    }
  } else if (x.size(0) >= 1) {
    int i;
    for (i = 0; i <= m; i++) {
      ex[i] = x[i];
    }
    for (int j{2}; j <= n; j++) {
      for (i = 0; i <= m; i++) {
        double b;
        bool p;
        b = x[i + x.size(0) * (j - 1)];
        if (std::isnan(b)) {
          p = false;
        } else if (std::isnan(ex[i])) {
          p = true;
        } else {
          p = (ex[i] > b);
        }
        if (p) {
          ex[i] = b;
        }
      }
    }
  }
}

void minimum(const ::coder::array<double, 2U> &x, double *ex, int *idx)
{
  int last;
  last = x.size(1);
  if (x.size(1) <= 2) {
    if (x.size(1) == 0) {
      *ex = rtNaN;
      *idx = 1;
    } else if (x.size(1) == 1) {
      *ex = x[0];
      *idx = 1;
    } else if ((x[0] > x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
      *ex = x[1];
      *idx = 2;
    } else {
      *ex = x[0];
      *idx = 1;
    }
  } else {
    int k;
    if (!std::isnan(x[0])) {
      *idx = 1;
    } else {
      bool exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      *ex = x[0];
      *idx = 1;
    } else {
      int i;
      *ex = x[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        double d;
        d = x[k - 1];
        if (*ex > d) {
          *ex = d;
          *idx = k;
        }
      }
    }
  }
}

void minimum(const ::coder::array<double, 2U> &x, double ex[2])
{
  int n;
  n = x.size(1);
  if (x.size(1) == 0) {
    ex[0] = rtNaN;
    ex[1] = rtNaN;
  } else {
    ex[0] = x[0];
    ex[1] = x[1];
    for (int j{2}; j <= n; j++) {
      double b;
      bool p;
      b = x[2 * (j - 1)];
      if (std::isnan(b)) {
        p = false;
      } else if (std::isnan(ex[0])) {
        p = true;
      } else {
        p = (ex[0] > b);
      }
      if (p) {
        ex[0] = b;
      }
      b = x[2 * (j - 1) + 1];
      if (std::isnan(b)) {
        p = false;
      } else if (std::isnan(ex[1])) {
        p = true;
      } else {
        p = (ex[1] > b);
      }
      if (p) {
        ex[1] = b;
      }
    }
  }
}

void minimum(const double x[4], double *ex, int *idx)
{
  int k;
  if (!std::isnan(x[0])) {
    *idx = 1;
  } else {
    bool exitg1;
    *idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!std::isnan(x[k - 1])) {
        *idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (*idx == 0) {
    *ex = x[0];
    *idx = 1;
  } else {
    int i;
    *ex = x[*idx - 1];
    i = *idx + 1;
    for (k = i; k < 5; k++) {
      double d;
      d = x[k - 1];
      if (*ex > d) {
        *ex = d;
        *idx = k;
      }
    }
  }
}

double minimum(const double x[4])
{
  double ex;
  int idx;
  int k;
  if (!std::isnan(x[0])) {
    idx = 1;
  } else {
    bool exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 4)) {
      if (!std::isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    idx++;
    for (k = idx; k < 5; k++) {
      double d;
      d = x[k - 1];
      if (ex > d) {
        ex = d;
      }
    }
  }
  return ex;
}

} // namespace internal
} // namespace coder

// End of code generation (minOrMax.cpp)
