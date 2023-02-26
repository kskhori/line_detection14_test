//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// minOrMax.h
//
// Code generation for function 'minOrMax'
//

#ifndef MINORMAX_H
#define MINORMAX_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
double maximum(const ::coder::array<double, 1U> &x);

void maximum(const ::coder::array<double, 1U> &x, double *ex, int *idx);

void maximum(const ::coder::array<double, 2U> &x,
             ::coder::array<double, 1U> &ex);

double maximum(const double x[4]);

void minimum(const ::coder::array<double, 1U> &x, double *ex, int *idx);

void minimum(const ::coder::array<double, 2U> &x,
             ::coder::array<double, 1U> &ex);

void minimum(const ::coder::array<double, 2U> &x, double *ex, int *idx);

void minimum(const ::coder::array<double, 2U> &x, double ex[2]);

void minimum(const double x[4], double *ex, int *idx);

double minimum(const double x[4]);

} // namespace internal
} // namespace coder

#endif
// End of code generation (minOrMax.h)
