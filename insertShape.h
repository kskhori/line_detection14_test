//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// insertShape.h
//
// Code generation for function 'insertShape'
//

#ifndef INSERTSHAPE_H
#define INSERTSHAPE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void insertShape(const ::coder::array<unsigned char, 3U> &b_I,
                 const double position[4],
                 ::coder::array<unsigned char, 3U> &RGB);

void insertShape(const ::coder::array<unsigned char, 3U> &b_I,
                 const int position[4], ::coder::array<unsigned char, 3U> &RGB);

} // namespace coder

#endif
// End of code generation (insertShape.h)
