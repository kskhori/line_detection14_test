//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// insertShape.cpp
//
// Code generation for function 'insertShape'
//

// Include files
#include "insertShape.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "insertShapeUtilsCore_api.hpp"
#include <cmath>
#include <string.h>

// Function Definitions
namespace coder {
void insertShape(const ::coder::array<unsigned char, 3U> &b_I,
                 const double position[4],
                 ::coder::array<unsigned char, 3U> &RGB)
{
  void *colPtr;
  void *polygonEdgePtr;
  void *posPtr;
  void *ptrObj;
  void *ptsDWPtr;
  array<int, 1U> positionOut;
  array<unsigned char, 3U> tmpRGB;
  array<unsigned char, 2U> pixCount;
  double d;
  int loop_ub;
  int position_idx_1;
  int position_idx_2;
  int position_idx_3;
  short pixCountSize;
  unsigned char color[3];
  bool isInitialise;
  tmpRGB.set_size(b_I.size(0), b_I.size(1), 3);
  loop_ub = b_I.size(0) * b_I.size(1) * 3;
  for (position_idx_2 = 0; position_idx_2 < loop_ub; position_idx_2++) {
    tmpRGB[position_idx_2] = b_I[position_idx_2];
  }
  d = std::round(position[0]);
  if (d < 2.147483648E+9) {
    if (d >= -2.147483648E+9) {
      loop_ub = static_cast<int>(d);
    } else {
      loop_ub = MIN_int32_T;
    }
  } else if (d >= 2.147483648E+9) {
    loop_ub = MAX_int32_T;
  } else {
    loop_ub = 0;
  }
  d = std::round(position[2]);
  if (d < 2.147483648E+9) {
    if (d >= -2.147483648E+9) {
      position_idx_1 = static_cast<int>(d);
    } else {
      position_idx_1 = MIN_int32_T;
    }
  } else if (d >= 2.147483648E+9) {
    position_idx_1 = MAX_int32_T;
  } else {
    position_idx_1 = 0;
  }
  d = std::round(position[1]);
  if (d < 2.147483648E+9) {
    if (d >= -2.147483648E+9) {
      position_idx_2 = static_cast<int>(d);
    } else {
      position_idx_2 = MIN_int32_T;
    }
  } else if (d >= 2.147483648E+9) {
    position_idx_2 = MAX_int32_T;
  } else {
    position_idx_2 = 0;
  }
  d = std::round(position[3]);
  if (d < 2.147483648E+9) {
    if (d >= -2.147483648E+9) {
      position_idx_3 = static_cast<int>(d);
    } else {
      position_idx_3 = MIN_int32_T;
    }
  } else if (d >= 2.147483648E+9) {
    position_idx_3 = MAX_int32_T;
  } else {
    position_idx_3 = 0;
  }
  positionOut.set_size(4);
  positionOut[0] = loop_ub;
  positionOut[1] = position_idx_1;
  positionOut[2] = position_idx_2;
  positionOut[3] = position_idx_3;
  position_idx_2 = b_I.size(0);
  if (b_I.size(0) > 32767) {
    position_idx_2 = 32767;
  }
  position_idx_1 = b_I.size(1);
  if (b_I.size(1) > 32767) {
    position_idx_1 = 32767;
  }
  RGB.set_size(b_I.size(0), b_I.size(1), 3);
  loop_ub = b_I.size(0) * b_I.size(1) * 3;
  for (position_idx_3 = 0; position_idx_3 < loop_ub; position_idx_3++) {
    RGB[position_idx_3] = 0U;
  }
  if (static_cast<short>(position_idx_2) > static_cast<short>(position_idx_1)) {
    pixCountSize = static_cast<short>(position_idx_2);
  } else {
    pixCountSize = static_cast<short>(position_idx_1);
  }
  pixCount.set_size(1, static_cast<int>(pixCountSize));
  loop_ub = pixCountSize;
  for (position_idx_3 = 0; position_idx_3 < loop_ub; position_idx_3++) {
    pixCount[position_idx_3] = 0U;
  }
  ptrObj = NULL;
  constructDrawBaseObjectShape(&ptrObj);
  polygonEdgePtr = NULL;
  posPtr = NULL;
  getPositionDataPointer(&posPtr, &(positionOut.data())[0], 4U, 1U);
  ptsDWPtr = NULL;
  getPtsDWPointer(&ptsDWPtr, 2, 2, 4, 1);
  color[0] = 0U;
  color[1] = 1U;
  color[2] = 0U;
  colPtr = NULL;
  getColorDataPointer_uint8(&colPtr, &color[0], 1U, 3U);
  isInitialise = initialiseDrawbaseShape(ptrObj, 0, 2);
  if (!isInitialise) {
    allocatePolygonEdgePointer(&polygonEdgePtr, 2, 2, 4, 1, false, false);
    instantiateDrawBaseShape_uint8(
        ptrObj, &RGB[0], &tmpRGB[0], posPtr, colPtr, 0.6, 5, 2, true,
        static_cast<short>(position_idx_2), static_cast<short>(position_idx_1),
        3, 2, 4, 1, 1, false, false, &pixCount[0], 0, ptsDWPtr, polygonEdgePtr);
  }
  isInitialise = initialiseDrawbaseShape(ptrObj, 1, 2);
  if (!isInitialise) {
    allocatePolygonEdgePointer(&polygonEdgePtr, 2, 2, 4, 1, false, true);
    instantiateDrawBaseShape_uint8(
        ptrObj, &RGB[0], &tmpRGB[0], posPtr, colPtr, 0.6, 5, 2, true,
        static_cast<short>(position_idx_2), static_cast<short>(position_idx_1),
        3, 2, 4, 1, 1, false, true, &pixCount[0], 1, ptsDWPtr, polygonEdgePtr);
  }
  mDrawShapes(ptrObj, false, true, 2, 5,
              static_cast<int>(static_cast<short>(position_idx_2)),
              static_cast<int>(static_cast<short>(position_idx_1)));
  deallocateMemoryShape(ptrObj);
  deallocatePolygonEdgePointer(polygonEdgePtr);
  deletePositionDataPointer(posPtr);
  deletePtsDWPointer(ptsDWPtr);
  deleteColorDataPointer_uint8(colPtr);
}

void insertShape(const ::coder::array<unsigned char, 3U> &b_I,
                 const int position[4], ::coder::array<unsigned char, 3U> &RGB)
{
  void *colPtr;
  void *polygonEdgePtr;
  void *posPtr;
  void *ptrObj;
  void *ptsDWPtr;
  array<int, 1U> positionOut;
  array<unsigned char, 3U> tmpRGB;
  array<unsigned char, 2U> pixCount;
  int i;
  int i1;
  int i2;
  int loop_ub;
  short pixCountSize;
  unsigned char color[3];
  bool isInitialise;
  tmpRGB.set_size(b_I.size(0), b_I.size(1), 3);
  loop_ub = b_I.size(0) * b_I.size(1) * 3;
  for (i = 0; i < loop_ub; i++) {
    tmpRGB[i] = b_I[i];
  }
  positionOut.set_size(4);
  positionOut[0] = position[0];
  positionOut[1] = position[2];
  positionOut[2] = position[1];
  positionOut[3] = position[3];
  i = b_I.size(0);
  if (b_I.size(0) > 32767) {
    i = 32767;
  }
  i1 = b_I.size(1);
  if (b_I.size(1) > 32767) {
    i1 = 32767;
  }
  RGB.set_size(b_I.size(0), b_I.size(1), 3);
  loop_ub = b_I.size(0) * b_I.size(1) * 3;
  for (i2 = 0; i2 < loop_ub; i2++) {
    RGB[i2] = 0U;
  }
  if (static_cast<short>(i) > static_cast<short>(i1)) {
    pixCountSize = static_cast<short>(i);
  } else {
    pixCountSize = static_cast<short>(i1);
  }
  pixCount.set_size(1, static_cast<int>(pixCountSize));
  loop_ub = pixCountSize;
  for (i2 = 0; i2 < loop_ub; i2++) {
    pixCount[i2] = 0U;
  }
  ptrObj = NULL;
  constructDrawBaseObjectShape(&ptrObj);
  polygonEdgePtr = NULL;
  posPtr = NULL;
  getPositionDataPointer(&posPtr, &(positionOut.data())[0], 4U, 1U);
  ptsDWPtr = NULL;
  getPtsDWPointer(&ptsDWPtr, 2, 2, 4, 1);
  color[0] = 1U;
  color[1] = 0U;
  color[2] = 0U;
  colPtr = NULL;
  getColorDataPointer_uint8(&colPtr, &color[0], 1U, 3U);
  isInitialise = initialiseDrawbaseShape(ptrObj, 0, 2);
  if (!isInitialise) {
    allocatePolygonEdgePointer(&polygonEdgePtr, 2, 2, 4, 1, false, false);
    instantiateDrawBaseShape_uint8(
        ptrObj, &RGB[0], &tmpRGB[0], posPtr, colPtr, 0.6, 10, 2, true,
        static_cast<short>(i), static_cast<short>(i1), 3, 2, 4, 1, 1, false,
        false, &pixCount[0], 0, ptsDWPtr, polygonEdgePtr);
  }
  isInitialise = initialiseDrawbaseShape(ptrObj, 1, 2);
  if (!isInitialise) {
    allocatePolygonEdgePointer(&polygonEdgePtr, 2, 2, 4, 1, false, true);
    instantiateDrawBaseShape_uint8(
        ptrObj, &RGB[0], &tmpRGB[0], posPtr, colPtr, 0.6, 10, 2, true,
        static_cast<short>(i), static_cast<short>(i1), 3, 2, 4, 1, 1, false,
        true, &pixCount[0], 1, ptsDWPtr, polygonEdgePtr);
  }
  mDrawShapes(ptrObj, false, true, 2, 10,
              static_cast<int>(static_cast<short>(i)),
              static_cast<int>(static_cast<short>(i1)));
  deallocateMemoryShape(ptrObj);
  deallocatePolygonEdgePointer(polygonEdgePtr);
  deletePositionDataPointer(posPtr);
  deletePtsDWPointer(ptsDWPtr);
  deleteColorDataPointer_uint8(colPtr);
}

} // namespace coder

// End of code generation (insertShape.cpp)
