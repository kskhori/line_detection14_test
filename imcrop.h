//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imcrop.h
//
// Code generation for function 'imcrop'
//

#ifndef IMCROP_H
#define IMCROP_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
//void imcrop(const ::coder::array<unsigned char, 2U> &varargin_1,
//            const double varargin_2[4],
//            ::coder::array<unsigned char, 2U> &varargout_1);

//}
//namespace coder {
void imcrop(const ::coder::array<bool, 2U> &varargin_1,
            const double varargin_2[4], ::coder::array<bool, 2U> &varargout_1);
}

#endif
// End of code generation (imcrop.h)
