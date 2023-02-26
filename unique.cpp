//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// unique.cpp
//
// Code generation for function 'unique'
//

// Include files
#include "unique.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>
#include <string.h>

// Function Definitions
namespace coder {
void unique_vector(const ::coder::array<double, 2U> &a,
                   ::coder::array<double, 2U> &b)
{
  array<int, 2U> idx;
  array<int, 1U> iwork;
  double absx;
  int b_i;
  int exponent;
  int i;
  int i2;
  int j;
  int k;
  int n;
  int na;
  int nb;
  int pEnd;
  int qEnd;
  bool exitg1;
  na = a.size(1);
  n = a.size(1) + 1;
  idx.set_size(1, a.size(1));
  i = a.size(1);
  for (b_i = 0; b_i < i; b_i++) {
    idx[b_i] = 0;
  }
  if (a.size(1) != 0) {
    iwork.set_size(a.size(1));
    b_i = a.size(1) - 1;
    for (k = 1; k <= b_i; k += 2) {
      absx = a[k];
      if ((a[k - 1] <= absx) || std::isnan(absx)) {
        idx[k - 1] = k;
        idx[k] = k + 1;
      } else {
        idx[k - 1] = k + 1;
        idx[k] = k;
      }
    }
    if ((a.size(1) & 1) != 0) {
      idx[a.size(1) - 1] = a.size(1);
    }
    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      j = 1;
      for (pEnd = i + 1; pEnd < n; pEnd = qEnd + i) {
        int kEnd;
        int q;
        nb = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          absx = a[idx[q] - 1];
          b_i = idx[nb - 1];
          if ((a[b_i - 1] <= absx) || std::isnan(absx)) {
            iwork[k] = b_i;
            nb++;
            if (nb == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                iwork[k] = idx[q];
                q++;
              }
            }
          } else {
            iwork[k] = idx[q];
            q++;
            if (q + 1 == qEnd) {
              while (nb < pEnd) {
                k++;
                iwork[k] = idx[nb - 1];
                nb++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          idx[(j + k) - 1] = iwork[k];
        }
        j = qEnd;
      }
      i = i2;
    }
  }
  b.set_size(1, a.size(1));
  for (k = 0; k < na; k++) {
    b[k] = a[idx[k] - 1];
  }
  k = 0;
  while ((k + 1 <= na) && std::isinf(b[k]) && (b[k] < 0.0)) {
    k++;
  }
  i2 = k;
  k = a.size(1);
  while ((k >= 1) && std::isnan(b[k - 1])) {
    k--;
  }
  pEnd = a.size(1) - k;
  exitg1 = false;
  while ((!exitg1) && (k >= 1)) {
    absx = b[k - 1];
    if (std::isinf(absx) && (absx > 0.0)) {
      k--;
    } else {
      exitg1 = true;
    }
  }
  i = (a.size(1) - k) - pEnd;
  nb = -1;
  if (i2 > 0) {
    nb = 0;
  }
  while (i2 + 1 <= k) {
    double x;
    x = b[i2];
    int exitg2;
    do {
      exitg2 = 0;
      i2++;
      if (i2 + 1 > k) {
        exitg2 = 1;
      } else {
        absx = std::abs(x / 2.0);
        if ((!std::isinf(absx)) && (!std::isnan(absx))) {
          if (absx <= 2.2250738585072014E-308) {
            absx = 4.94065645841247E-324;
          } else {
            frexp(absx, &exponent);
            absx = std::ldexp(1.0, exponent - 53);
          }
        } else {
          absx = rtNaN;
        }
        if ((!(std::abs(x - b[i2]) < absx)) &&
            ((!std::isinf(b[i2])) || (!std::isinf(x)) ||
             ((b[i2] > 0.0) != (x > 0.0)))) {
          exitg2 = 1;
        }
      }
    } while (exitg2 == 0);
    nb++;
    b[nb] = x;
  }
  if (i > 0) {
    nb++;
    b[nb] = b[k];
  }
  i2 = k + i;
  for (j = 0; j < pEnd; j++) {
    b[(nb + j) + 1] = b[i2 + j];
  }
  nb += pEnd;
  if (1 > nb + 1) {
    nb = -1;
  }
  b.set_size(b.size(0), nb + 1);
}

} // namespace coder

// End of code generation (unique.cpp)
