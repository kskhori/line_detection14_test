//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// houghlines.h
//
// Code generation for function 'houghlines'
//

#ifndef HOUGHLINES_H
#define HOUGHLINES_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct b_struct_T;

// Function Declarations
namespace coder {
void houghlines(const ::coder::array<bool, 2U> &varargin_1,
                const ::coder::array<double, 2U> &varargin_3,
                const ::coder::array<double, 2U> &varargin_4,
                ::coder::array<b_struct_T, 2U> &lines);

}

#endif
// End of code generation (houghlines.h)
