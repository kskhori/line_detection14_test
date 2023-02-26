//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// line_detection14_internal_types.h
//
// Code generation for function 'line_detection14'
//

#ifndef LINE_DETECTION14_INTERNAL_TYPES_H
#define LINE_DETECTION14_INTERNAL_TYPES_H

// Include files
#include "line_detection14_types.h"
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
struct struct_T {
  int xstart;
  int xend;
  int depth;
};

struct b_struct_T {
  double point1[2];
  double point2[2];
  double theta;
  double rho;
};

struct c_struct_T {
  coder::array<double, 2U> pts;
};

#endif
// End of code generation (line_detection14_internal_types.h)
