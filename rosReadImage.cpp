//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rosReadImage.cpp
//
// Code generation for function 'rosReadImage'
//

// Include files
#include "rosReadImage.h"
#include "line_detection14_data.h"
#include "permute.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>
#include <string.h>

// Function Declarations
static unsigned int mul_u32_sat(unsigned int a, unsigned int b);

static void mul_wide_u32(unsigned int in0, unsigned int in1,
                         unsigned int *ptrOutBitsHi,
                         unsigned int *ptrOutBitsLo);

// Function Definitions
static unsigned int mul_u32_sat(unsigned int a, unsigned int b)
{
  unsigned int result;
  unsigned int u32_chi;
  mul_wide_u32(a, b, &u32_chi, &result);
  if (u32_chi) {
    result = MAX_uint32_T;
  }
  return result;
}

static void mul_wide_u32(unsigned int in0, unsigned int in1,
                         unsigned int *ptrOutBitsHi, unsigned int *ptrOutBitsLo)
{
  int in0Hi;
  int in0Lo;
  int in1Hi;
  int in1Lo;
  unsigned int outBitsLo;
  unsigned int productHiLo;
  unsigned int productLoHi;
  unsigned int productLoLo;
  in0Hi = static_cast<int>(in0 >> 16U);
  in0Lo = static_cast<int>(in0 & 65535U);
  in1Hi = static_cast<int>(in1 >> 16U);
  in1Lo = static_cast<int>(in1 & 65535U);
  productHiLo = static_cast<unsigned int>(in0Hi) * in1Lo;
  productLoHi = static_cast<unsigned int>(in0Lo) * in1Hi;
  productLoLo = static_cast<unsigned int>(in0Lo) * in1Lo;
  in0Lo = 0;
  outBitsLo = productLoLo + (productLoHi << 16U);
  if (outBitsLo < productLoLo) {
    in0Lo = 1;
  }
  productLoLo = outBitsLo;
  outBitsLo += productHiLo << 16U;
  if (outBitsLo < productLoLo) {
    in0Lo = static_cast<int>(in0Lo + 1U);
  }
  *ptrOutBitsHi = ((in0Lo + static_cast<unsigned int>(in0Hi) * in1Hi) +
                   (productLoHi >> 16U)) +
                  (productHiLo >> 16U);
  *ptrOutBitsLo = outBitsLo;
}

namespace coder {
void rosReadImage(const char msg_MessageType[17], unsigned int msg_Height,
                  unsigned int msg_Width,
                  const ::coder::array<unsigned char, 1U> &msg_Data,
                  ::coder::array<unsigned char, 3U> &img)
{
  static const double dv[3]{2.0, 1.0, 3.0};
  array<unsigned int, 2U> b_index;
  array<unsigned int, 2U> y;
  array<unsigned int, 1U> indexBase;
  array<unsigned char, 3U> b_b;
  array<unsigned char, 3U> r1;
  array<unsigned char, 2U> r;
  array<unsigned char, 1U> data;
  int ret;
  int subsa_idx_1;
  int subsa_idx_2;
  ret = memcmp(&msg_MessageType[0], &cv[0], 17);
  if (ret == 0) {
    if (msg_Data.size(0) == 0) {
      data.set_size(0);
      std::copy(&(((::coder::array<unsigned char, 1U> *)&msg_Data)->data())[0],
                &(((::coder::array<unsigned char, 1U> *)&msg_Data)->data())[0],
                &(data.data())[0]);
      img.set_size(0, 1, 1);
    } else {
      unsigned int b;
      int i;
      int k;
      int msg_Width_idx_1;
      int msg_Width_idx_1_tmp;
      data.set_size(msg_Data.size(0));
      std::copy(&(((::coder::array<unsigned char, 1U> *)&msg_Data)->data())[0],
                &(((::coder::array<unsigned char, 1U> *)&msg_Data)
                      ->data())[msg_Data.size(0)],
                &(data.data())[0]);
      b = mul_u32_sat(mul_u32_sat(msg_Width, msg_Height), 3U);
      if (b < 1U) {
        ret = -1;
      } else {
        ret = static_cast<int>((b - 1U) / 3U);
      }
      y.set_size(1, ret + 1);
      for (k = 0; k <= ret; k++) {
        y[k] = k * 3U + 1U;
      }
      indexBase.set_size(y.size(1));
      ret = y.size(1);
      for (msg_Width_idx_1_tmp = 0; msg_Width_idx_1_tmp < ret;
           msg_Width_idx_1_tmp++) {
        indexBase[msg_Width_idx_1_tmp] = y[msg_Width_idx_1_tmp];
      }
      b_index.set_size(indexBase.size(0), 3);
      ret = indexBase.size(0) * 3;
      for (msg_Width_idx_1_tmp = 0; msg_Width_idx_1_tmp < ret;
           msg_Width_idx_1_tmp++) {
        b_index[msg_Width_idx_1_tmp] = 0U;
      }
      ret = indexBase.size(0);
      for (i = 0; i < 3; i++) {
        for (msg_Width_idx_1_tmp = 0; msg_Width_idx_1_tmp < ret;
             msg_Width_idx_1_tmp++) {
          double d;
          d = static_cast<double>(indexBase[msg_Width_idx_1_tmp]) +
              (static_cast<double>(i) + 1.0);
          if (d < 4.294967296E+9) {
            b = static_cast<unsigned int>(d);
          } else {
            b = MAX_uint32_T;
          }
          b_index[msg_Width_idx_1_tmp + b_index.size(0) * i] = b - 1U;
        }
      }
      r.set_size(b_index.size(0), 3);
      ret = b_index.size(0) * 3;
      for (msg_Width_idx_1_tmp = 0; msg_Width_idx_1_tmp < ret;
           msg_Width_idx_1_tmp++) {
        r[msg_Width_idx_1_tmp] =
            data[static_cast<int>(b_index[msg_Width_idx_1_tmp]) - 1];
      }
      ret = static_cast<int>(msg_Width);
      i = static_cast<int>(msg_Width);
      msg_Width_idx_1_tmp = static_cast<int>(msg_Height);
      msg_Width_idx_1 = static_cast<int>(msg_Height);
      r1 = r.reshape(ret, msg_Width_idx_1_tmp, 3);
      if (nomovement(dv, r1)) {
        b_b.set_size(static_cast<int>(msg_Height), static_cast<int>(msg_Width),
                     3);
        ret = static_cast<int>(msg_Height) * static_cast<int>(msg_Width) * 3;
        for (msg_Width_idx_1_tmp = 0; msg_Width_idx_1_tmp < ret;
             msg_Width_idx_1_tmp++) {
          b_b[msg_Width_idx_1_tmp] = r[msg_Width_idx_1_tmp];
        }
      } else {
        b_b.set_size(static_cast<int>(msg_Height), static_cast<int>(msg_Width),
                     3);
        for (k = 0; k < 3; k++) {
          for (int b_k{0}; b_k < msg_Width_idx_1_tmp; b_k++) {
            if (0 <= static_cast<int>(msg_Width) - 1) {
              subsa_idx_1 = b_k + 1;
              subsa_idx_2 = k + 1;
              i = static_cast<int>(msg_Width);
              msg_Width_idx_1 = static_cast<int>(msg_Height);
            }
            for (int c_k{0}; c_k < ret; c_k++) {
              b_b[((subsa_idx_1 + b_b.size(0) * c_k) +
                   b_b.size(0) * b_b.size(1) * (subsa_idx_2 - 1)) -
                  1] = r[(c_k + i * (subsa_idx_1 - 1)) +
                         i * msg_Width_idx_1 * (subsa_idx_2 - 1)];
            }
          }
        }
      }
      img.set_size(b_b.size(0), b_b.size(1), 3);
      ret = b_b.size(0) * b_b.size(1) * 3;
      for (msg_Width_idx_1_tmp = 0; msg_Width_idx_1_tmp < ret;
           msg_Width_idx_1_tmp++) {
        img[msg_Width_idx_1_tmp] = b_b[msg_Width_idx_1_tmp];
      }
    }
  }
}

} // namespace coder

// End of code generation (rosReadImage.cpp)
