//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// line_detection14.cpp
//
// Code generation for function 'line_detection14'
//

// Include files
#include "line_detection14.h"
#include "Publisher.h"
#include "Subscriber.h"
#include "convhull.h"
#include "diff.h"
#include "hough.h"
#include "houghlines.h"
#include "houghpeaks.h"
#include "imbinarize.h"
#include "imcrop.h"
//#include "insertShape.h"
#include "line_detection14_data.h"
#include "line_detection14_initialize.h"
#include "line_detection14_internal_types.h"
#include "line_detection14_types.h"
#include "medfilt2.h"
#include "minBoundingBox.h"
#include "minOrMax.h"
#include "pause.h"
#include "rosReadImage.h"
#include "rosWriteImage.h"
#include "rt_nonfinite.h"
#include "unique.h"
#include "coder_array.h"
#include "rt_defines.h"
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <string.h>

// Function Declarations
static double rt_atan2d_snf(double u0, double u1);

// Function Definitions
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int b_u0;
    int b_u1;
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }
    y = std::atan2(static_cast<double>(b_u0), static_cast<double>(b_u1));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }
  return y;
}

void line_detection14()
{
  static const double dv[4]{0.0, 1.5707963267948966, -1.5707963267948966, 0.0};
  coder::ros::Publisher PubSimProgress2;
  coder::ros::Subscriber sub;
//  coder::ros::b_Publisher Pubimage;
  coder::ros::b_Subscriber sub2;
  coder::array<b_struct_T, 2U> lines;
  coder::array<darknet_ros_msgs_BoundingBoxStruct_T, 1U> msgSub2_BoundingBoxes_;
  coder::array<double, 2U> H;
  coder::array<double, 2U> P;
  coder::array<double, 2U> R;
  coder::array<double, 2U> T;
  coder::array<double, 2U> X;
  coder::array<double, 2U> area;
  coder::array<double, 2U> b_X;
  coder::array<double, 2U> b_bsize;
  coder::array<double, 2U> bound;
  coder::array<double, 2U> point_data;
  coder::array<double, 1U> b_H;
  coder::array<double, 1U> b_k;
  coder::array<double, 1U> bsize;
  coder::array<double, 1U> r1;
  coder::array<unsigned char, 3U> b_I;
//  coder::array<unsigned char, 3U> b_image_HT;
//  coder::array<unsigned char, 3U> image_HT;
  coder::array<unsigned char, 2U> I_gray;
  coder::array<unsigned char, 2U> r;
  coder::array<unsigned char, 1U> msgSub_Data;
  coder::array<bool, 2U> BW;
  coder::array<bool, 2U> BWcrop;
//  sensor_msgs_ImageStruct_T PubimageMsg;
  std_msgs_Int32Struct_T expl_temp;
  double bounding_box[8];
  double bounding_box2[8];
  double b_x2[4];
  double prev_info[4];
  double bmax[2];
  double sizeI;
  int x2[4];
  int iy;
  unsigned int msgSub_Height;
  unsigned int msgSub_Width;
  int ncols;
  int pos_pre;
  double m_pre;
  char msgSub_MessageType[17];
  if (!isInitialized_line_detection14) {
    line_detection14_initialize();
  }
  PubSimProgress2.matlabCodegenIsDeleted = true;
//  Pubimage.matlabCodegenIsDeleted = true;
  sub.matlabCodegenIsDeleted = true;
  sub2.matlabCodegenIsDeleted = true;
  //  addpath('C:\Users\srd_r\Documents\MATLAB\custom_message\darknet_ros\matlab_msg_gen_ros1\win64\install\m\+ros\+msggen');
  //  savepath;
  //  clear classes;
  //  rehash toolboxcache;
  //  IP = "192.168.1.128"; %%
  //  try
  //      rosinit("http://" + IP + ":11311")
  //  catch exceptions
  //      rosshutdown
  //      pause(0.05)
  //      rosinit("http://" + IP + ":11311")
  //  end
  //  parameter for the system
  // w = 160; % width[px]
  // px->mm
  // mm->pulse
  //  mm
  //  pulse
  // calcuation start postion on x axis
  pos_pre = 0;
  m_pre = 0.0;
  prev_info[2] = 0.0;
  prev_info[3] = 640.0;
  // px, detectiokn margin for ROI
  //  xmin = min(c);
  //  xmax = max(c);
  //  ymin = min(r);
  //  ymax = max(r);
  //  Publisher
  PubSimProgress2.init();
  // 送信→Publisher（初期化）
  coder::ros::Publisher::rosmessage(expl_temp.MessageType, &iy);
//  Pubimage.init();
  // 送信→Publisher（初期化）
//  coder::ros::Publisher::rosmessage(&PubimageMsg);
  sub.init();
  sub2.init();
  // img = readImage(sub_msg);
  coder::pause(0.1);
  printf("%s\n", "Begin Loop");
  fflush(stdout);
  //  Detect lines in each frame
  x2[2] = 1;
  x2[3] = 480;
  while (1) {
    double d;
    double d1;
    double offset;
    double q;
    double sizeOutput_idx_0;
    double sizeOutput_idx_1;
    double varargin_1;
    int b_ibmat;
    int iacol;
    int ibmat;
    int ibtile;
    int j;
    int k;
    bool rEQ0;
    coder::pause(0.001);
    // 	%% Subscrive rostopic
    sub.receive(msgSub_MessageType, &msgSub_Height, &msgSub_Width, msgSub_Data);
    sub2.receive(msgSub2_BoundingBoxes_);
    // msgSub2  = sub2.LatestMessage;
    coder::rosReadImage(msgSub_MessageType, msgSub_Height, msgSub_Width,
                        msgSub_Data, b_I);
    point_data.set_size(1, 1);
    point_data[0] = 0.0;
//    offset = std::floor((prev_info[2] - 32.0));
    offset = std::floor(msgSub2_BoundingBoxes_[0].Xmin);
    I_gray.set_size(b_I.size(0), b_I.size(1));
    sizeI = static_cast<double>(b_I.size(0) * b_I.size(1) * b_I.size(2)) / 3.0;
    ibmat = static_cast<int>(sizeI);
    for (b_ibmat = 0; b_ibmat < ibmat; b_ibmat++) {
      I_gray[b_ibmat] = static_cast<unsigned char>(std::round(
          (static_cast<double>(b_I[b_ibmat]) * 0.29893602129377539 +
           static_cast<double>(
               b_I[static_cast<int>((static_cast<double>(b_ibmat) + 1.0) +
                                    sizeI) -
                   1]) *
               0.58704307445112125) +
          static_cast<double>(
              b_I[static_cast<int>((static_cast<double>(b_ibmat) + 1.0) +
                                   2.0 * sizeI) -
                  1]) *
              0.11402090425510336));
    }
    d = std::floor((prev_info[3] - prev_info[2]) + 64.0);
    d = std::floor(msgSub2_BoundingBoxes_[0].Xmax - msgSub2_BoundingBoxes_[0].Xmin);
    prev_info[0] = offset;
    prev_info[1] = 0.0;
    prev_info[2] = d;
    prev_info[3] = 480.0;
//   メジアンフィルタの適用
//    coder::imcrop(I_gray, prev_info, r);
//    coder::medfilt2(r, I_gray);
//    coder::imbinarize(I_gray, BWcrop);
      coder::medfilt2(I_gray, r);
//	2値化
    coder::imbinarize(r, BW);
    coder::imcrop(BW, prev_info, BWcrop);
    
//    printf("Ymax = %d", msgSub2_BoundingBoxes_[0].Ymax);
    printf("%ld, %ld, %ld, %ld, ", msgSub2_BoundingBoxes_[0].Xmin, msgSub2_BoundingBoxes_[0].Xmax,msgSub2_BoundingBoxes_[0].Ymin, msgSub2_BoundingBoxes_[0].Ymax);

    //     %% ハフ変換
    // [H,theta,rho] = hough(BWsdil);
    coder::hough(BWcrop, H, area);
    iy = H.size(0) * 180;
    b_H = H.reshape(iy);
    coder::houghpeaks(H, std::ceil(0.3 * coder::internal::maximum(b_H)), P);
    coder::houghlines(BWcrop, area, P, lines);
//    image_HT.set_size(I_gray.size(0), I_gray.size(1), 3);
//    ibmat = I_gray.size(0) * I_gray.size(1);
//    for (j = 0; j < ibmat; j++) {
//      image_HT[j] = I_gray[j];
//    }
//    ibtile = I_gray.size(0) * I_gray.size(1);
//    for (j = 0; j < ibtile; j++) {
//      image_HT[ibmat + j] = I_gray[j];
//    }
    iy = (ibmat + ibtile) - 1;
//    ibmat = I_gray.size(0) * I_gray.size(1);
//    for (j = 0; j < ibmat; j++) {
//      image_HT[(iy + j) + 1] = I_gray[j];
//    }
    ibmat = lines.size(1);
    for (k = 0; k < ibmat; k++) {
      // c++ではdeg->radの変換を行うこと！
      prev_info[0] = lines[k].point1[0];
      prev_info[1] = lines[k].point2[0];
      prev_info[2] = lines[k].point1[1];
      prev_info[3] = lines[k].point2[1];
      b_x2[0] = prev_info[0] + offset;
      b_x2[2] = prev_info[2];
      b_x2[1] = prev_info[1] + offset;
      b_x2[3] = prev_info[3];
//      b_image_HT.set_size(image_HT.size(0), image_HT.size(1), 3);
//      iacol = image_HT.size(0) * image_HT.size(1) * image_HT.size(2) - 1;
//      for (ibtile = 0; ibtile <= iacol; ibtile++) {
//        b_image_HT[ibtile] = image_HT[ibtile];
//      }
//      coder::insertShape(b_image_HT, b_x2, image_HT);
      if (k + 1 == 1) {
        point_data.set_size(2, 2);
        point_data[0] = prev_info[0];
        point_data[1] = prev_info[1];
        point_data[2] = prev_info[2];
        point_data[3] = prev_info[3];
      } else {
        iy = point_data.size(0);
        P.set_size(point_data.size(0) + 2, 2);
        iacol = point_data.size(0);
        for (ibtile = 0; ibtile < 2; ibtile++) {
          for (ncols = 0; ncols < iacol; ncols++) {
            P[ncols + P.size(0) * ibtile] = point_data[ncols + iy * ibtile];
          }
        }
        P[point_data.size(0)] = prev_info[0];
        P[point_data.size(0) + 1] = prev_info[1];
        P[point_data.size(0) + P.size(0)] = prev_info[2];
        P[(point_data.size(0) + P.size(0)) + 1] = prev_info[3];
        point_data.set_size(P.size(0), 2);
        iacol = P.size(0) * 2;
        for (ibtile = 0; ibtile < iacol; ibtile++) {
          point_data[ibtile] = P[ibtile];
        }
      }
    }
    //     %% 最小矩形による判別
    X.set_size(point_data.size(1), point_data.size(0));
    iacol = point_data.size(0);
    for (ibmat = 0; ibmat < iacol; ibmat++) {
      iy = point_data.size(1);
      for (ibtile = 0; ibtile < iy; ibtile++) {
        X[ibtile + X.size(0) * ibmat] =
            point_data[ibmat + point_data.size(0) * ibtile];
      }
    }
    //  compute the minimum bounding box of a set of 2D points
    //    Use:   boundingBox = minBoundingBox(point_matrix)
    //
    //  Input:  2xn matrix containing the [x,y] coordinates of n points
    //          *** there must be at least 3 points which are not collinear
    //  output: 2x4 matrix containing the coordinates of the bounding box
    //  corners
    //
    //  Example : generate a random set of point in a randomly rotated rectangle
    //      n = 50000;
    //      t = pi*rand(1);
    //      X = [cos(t) -sin(t) ; sin(t) cos(t)]*[7 0; 0 2]*rand(2,n);
    //      X = [X  20*(rand(2,1)-0.5)];  % add an outlier
    //
    //      tic
    //      c = minBoundingBox(X);
    //      toc
    //
    //      figure(42);
    //      hold off,  plot(X(1,:),X(2,:),'.')
    //      hold on,   plot(c(1,[1:end 1]),c(2,[1:end 1]),'r')
    //      axis equal
    //  compute the convex hull (CH is a 2*k matrix subset of X)
    iacol = X.size(1);
    area.set_size(1, X.size(1));
    for (ibmat = 0; ibmat < iacol; ibmat++) {
      area[ibmat] = X[X.size(0) * ibmat];
    }
    iacol = X.size(1);
    b_X.set_size(1, X.size(1));
    for (ibmat = 0; ibmat < iacol; ibmat++) {
      b_X[ibmat] = X[X.size(0) * ibmat + 1];
    }
    coder::convhull(area, b_X, b_k);
    iacol = X.size(0);
    point_data.set_size(X.size(0), b_k.size(0));
    iy = b_k.size(0);
    for (ibmat = 0; ibmat < iy; ibmat++) {
      for (ibtile = 0; ibtile < iacol; ibtile++) {
        point_data[ibtile + point_data.size(0) * ibmat] =
            X[ibtile + X.size(0) * (static_cast<int>(b_k[ibmat]) - 1)];
      }
    }
    //  compute the angle to test, which are the angle of the CH edges as:
    //    "one side of the bounding box contains an edge of the convex hull"
    coder::diff(point_data, P);
    //  CH edges
    iacol = P.size(1);
    area.set_size(1, P.size(1));
    b_X.set_size(1, P.size(1));
    for (ibmat = 0; ibmat < iacol; ibmat++) {
      area[ibmat] = P[P.size(0) * ibmat + 1];
      b_X[ibmat] = P[P.size(0) * ibmat];
    }
    T.set_size(1, area.size(1));
    iacol = area.size(1);
    for (ibmat = 0; ibmat < iacol; ibmat++) {
      varargin_1 = area[ibmat];
      sizeI = b_X[ibmat];
      T[ibmat] = rt_atan2d_snf(varargin_1, sizeI);
    }
    //  angle of CH edges (used for rotation)
    area.set_size(1, T.size(1));
    iacol = T.size(1);
    for (ibmat = 0; ibmat < iacol; ibmat++) {
      varargin_1 = T[ibmat];
      if (std::isnan(varargin_1) || std::isinf(varargin_1)) {
        sizeI = rtNaN;
      } else if (varargin_1 == 0.0) {
        sizeI = 0.0;
      } else {
        sizeI = std::fmod(varargin_1, 1.5707963267948966);
        rEQ0 = (sizeI == 0.0);
        if (!rEQ0) {
          q = std::abs(varargin_1 / 1.5707963267948966);
          rEQ0 =
              !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 * q);
        }
        if (rEQ0) {
          sizeI = 0.0;
        } else if (varargin_1 < 0.0) {
          sizeI += 1.5707963267948966;
        }
      }
      area[ibmat] = sizeI;
    }
    coder::unique_vector(area, T);
    //  reduced to the unique set of first quadrant angles
    //  create rotation matrix which contains
    //  the 2x2 rotation matrices for *all* angles in T
    //  R is a 2n*2 matrix
    bound.set_size(2, T.size(1) << 1);
    ncols = T.size(1);
    R.set_size(T.size(1) << 1, 2);
    for (k = 0; k < 2; k++) {
      ibtile = k * (ncols << 1);
      iacol = k << 1;
      b_ibmat = k * (T.size(1) << 1) - 1;
      for (j = 0; j < ncols; j++) {
        iy = j << 1;
        ibmat = ibtile + iy;
        iy += b_ibmat;
        bound[ibmat] = T[j];
        R[iy + 1] = dv[iacol];
        bound[ibmat + 1] = T[j];
        R[iy + 2] = dv[iacol + 1];
      }
    }
    if (T.size(1) << 1 == R.size(0)) {
      iy = T.size(1) << 1;
      iacol = iy << 1;
      R.set_size(iy, 2);
      for (ibmat = 0; ibmat < iacol; ibmat++) {
        R[ibmat] = bound[ibmat] + R[ibmat];
      }
    } else {
      binary_expand_op(R, bound, T);
    }
    iy = R.size(0) << 1;
    for (k = 0; k < iy; k++) {
      R[k] = std::cos(R[k]);
    }
    //  % duplicate angles in T
    //  shift angle to convert sine in cosine
    //  rotate CH by all angles
    iy = R.size(0);
    k = b_k.size(0);
    P.set_size(R.size(0), b_k.size(0));
    for (j = 0; j < k; j++) {
      ibtile = j * iy;
      iacol = j * X.size(0);
      for (b_ibmat = 0; b_ibmat < iy; b_ibmat++) {
        P[ibtile + b_ibmat] = R[b_ibmat] * point_data[iacol] +
                              R[R.size(0) + b_ibmat] * point_data[iacol + 1];
      }
    }
    //  compute border size  [w1;h1;w2;h2;....;wn;hn]
    //  and area of bounding box for all possible edges
    coder::internal::maximum(P, bsize);
    coder::internal::minimum(P, r1);
    if (bsize.size(0) == r1.size(0)) {
      iacol = bsize.size(0);
      for (ibmat = 0; ibmat < iacol; ibmat++) {
        bsize[ibmat] = bsize[ibmat] - r1[ibmat];
      }
    } else {
      minus(bsize, r1);
    }
    iy = static_cast<int>(static_cast<double>(bsize.size(0)) / 2.0);
    //  find minimal area, thus the index of the angle in T
    b_bsize = bsize.reshape(2, iy);
    if (b_bsize.size(1) == 0) {
      area.set_size(1, 0);
    } else {
      iy = b_bsize.size(1);
      area.set_size(1, b_bsize.size(1));
      for (b_ibmat = 0; b_ibmat < iy; b_ibmat++) {
        ncols = b_ibmat << 1;
        area[b_ibmat] = b_bsize[ncols] * b_bsize[ncols + 1];
      }
    }
    coder::internal::minimum(area, &sizeI, &ncols);
    //  compute the bound (min and max) on the rotated frame
    d = 2.0 * static_cast<double>(ncols);
    //  rotated frame
    k = b_k.size(0);
    bound.set_size(2, b_k.size(0));
    for (j = 0; j < k; j++) {
      ibtile = j << 1;
      iacol = j * X.size(0);
      ibmat = (ncols << 1) - 2;
      sizeI = point_data[iacol + 1];
      bound[ibtile] =
          R[ibmat] * point_data[iacol] + R[ibmat + R.size(0)] * sizeI;
      bound[ibtile + 1] =
          R[ibmat + 1] * point_data[iacol] + R[(ibmat + R.size(0)) + 1] * sizeI;
    }
    //  project CH on the rotated frame
//    printf("bound = %f, %f, ", bound[0], bound[1]);
    coder::internal::minimum(bound, bmax);
    sizeOutput_idx_0 = bmax[0];
    sizeOutput_idx_1 = bmax[1];
    k = bound.size(1);
    if (bound.size(1) == 0) {
      bmax[0] = rtNaN;
      bmax[1] = rtNaN;
    } else {
      bmax[0] = bound[0];
      bmax[1] = bound[1];
      for (j = 2; j <= k; j++) {
        sizeI = bound[2 * (j - 1)];
        if (std::isnan(sizeI)) {
          rEQ0 = false;
        } else if (std::isnan(bmax[0])) {
          rEQ0 = true;
        } else {
          rEQ0 = (bmax[0] < sizeI);
        }
        if (rEQ0) {
          bmax[0] = sizeI;
        }
        sizeI = bound[2 * (j - 1) + 1];
        if (std::isnan(sizeI)) {
          rEQ0 = false;
        } else if (std::isnan(bmax[1])) {
          rEQ0 = true;
        } else {
          rEQ0 = (bmax[1] < sizeI);
        }
        if (rEQ0) {
          bmax[1] = sizeI;
        }
      }
    }
    //  compute the corner of the bounding box
    prev_info[0] = R[static_cast<int>(d + -1.0) - 1];
    prev_info[1] = R[(static_cast<int>(d + -1.0) + R.size(0)) - 1];
    prev_info[2] = R[static_cast<int>(d) - 1];
    prev_info[3] = R[(static_cast<int>(d) + R.size(0)) - 1];
    std::memset(&bounding_box[0], 0, 8U * sizeof(double));
    sizeI = bmax[0];
    q = bmax[1];
//    printf(" idx = %f, %f ", sizeOutput_idx_0, sizeOutput_idx_1);
    // image_HT = insertShape(image_HT,'Polygon',[bounding_box(1,1)+offset
    // bounding_box(2,1) bounding_box(1,2)+offset bounding_box(2,2)
    // bounding_box(1,3)+offset bounding_box(2,3) bounding_box(1,4)+offset
    // bounding_box(2,4)],'LineWidth',5,'Color',[0 1 0]);
    for (ibmat = 0; ibmat < 2; ibmat++) {
      double d2;
      double d3;
      d = prev_info[ibmat + 2];
      d1 = sizeOutput_idx_1 * d;
      varargin_1 = prev_info[ibmat];
      d2 = sizeI * varargin_1;
      d3 = d2 + d1;
      bounding_box[ibmat + 6] = d3;
      varargin_1 *= sizeOutput_idx_0;
      d1 += varargin_1;
      bounding_box[ibmat] = d1;
      d *= q;
      varargin_1 += d;
      bounding_box[ibmat + 2] = varargin_1;
      d += d2;
      bounding_box[ibmat + 4] = d;
      iy = ibmat << 2;
      bounding_box2[iy] = d1;
      bounding_box2[iy + 1] = varargin_1;
      bounding_box2[iy + 2] = d;
      bounding_box2[iy + 3] = d3;
    }
//    printf("bounding_box[]=  [%f, %f, %f, %f, %f, %f, %f, %f], ",bounding_box[0], bounding_box[1], bounding_box[2], bounding_box[3],bounding_box[4], bounding_box[5], bounding_box[6], bounding_box[7]);//

    sizeI = (bounding_box2[0] - 1.0) * (bounding_box2[0] - 1.0);
    b_x2[0] =
        std::sqrt(sizeI + (bounding_box2[4] - 1.0) * (bounding_box2[4] - 1.0));
    prev_info[0] = std::sqrt(sizeI + (bounding_box2[4] - 480.0) *
                                         (bounding_box2[4] - 480.0));
    sizeI = (bounding_box2[1] - 1.0) * (bounding_box2[1] - 1.0);
    b_x2[1] =
        std::sqrt(sizeI + (bounding_box2[5] - 1.0) * (bounding_box2[5] - 1.0));
    prev_info[1] = std::sqrt(sizeI + (bounding_box2[5] - 480.0) *
                                         (bounding_box2[5] - 480.0));
    sizeI = (bounding_box2[2] - 1.0) * (bounding_box2[2] - 1.0);
    b_x2[2] =
        std::sqrt(sizeI + (bounding_box2[6] - 1.0) * (bounding_box2[6] - 1.0));
    prev_info[2] = std::sqrt(sizeI + (bounding_box2[6] - 480.0) *
                                         (bounding_box2[6] - 480.0));
    sizeI = (bounding_box2[3] - 1.0) * (bounding_box2[3] - 1.0);
    b_x2[3] =
        std::sqrt(sizeI + (bounding_box2[7] - 1.0) * (bounding_box2[7] - 1.0));
    prev_info[3] = std::sqrt(sizeI + (bounding_box2[7] - 480.0) *
                                         (bounding_box2[7] - 480.0));
    coder::internal::minimum(b_x2, &sizeI, &ncols);
    coder::internal::minimum(prev_info, &sizeI, &iy);
    sizeOutput_idx_0 =
        (((bounding_box[0] + bounding_box[2]) + bounding_box[4]) +
         bounding_box[6]) /
        4.0;
    sizeOutput_idx_1 =
        (((bounding_box[1] + bounding_box[3]) + bounding_box[5]) +
         bounding_box[7]) /
        4.0;
    //
    ncols = (ncols - 1) << 1;
    iy = (iy - 1) << 1;
    sizeI = (bounding_box[ncols + 1] - bounding_box[iy + 1]) /
            (bounding_box[ncols] - bounding_box[iy]);
    b_x2[1] = (480.0 - sizeOutput_idx_1) / sizeI + sizeOutput_idx_0;
//    printf("\nb_x2[] = %f, %f, %f, %f, %f", b_x2[0],b_x2[1], b_x2[2],b_x2[3], sizeI);
    // theta = atan2(b,a);
    // theta_rad = deg2rad(theta);
    d = coder::internal::minimum(*(double(*)[4]) & bounding_box2[0]);
    d1 = coder::internal::maximum(*(double(*)[4]) & bounding_box2[0]);
//    printf("d = %f, %f, ", d, d1);
    prev_info[2] = d + offset;
    prev_info[3] = d1 + offset;

    printf("%f, %f, ", (1.0 - sizeOutput_idx_1) / sizeI + sizeOutput_idx_0, b_x2[1]);
    auto bottom = (double) b_x2[1] + msgSub2_BoundingBoxes_[0].Xmin;
//    printf("bot = %f, ", bottom);
    double m = (((1.0 - sizeOutput_idx_1) / sizeI + sizeOutput_idx_0)-b_x2[1])/479.0;
    printf("%f, ", m);

//傾きにもローパスフィルタ
//    m = m*0.7 + m_pre*0.3;
    m_pre = m;
    //     %% スライダの操作量を計算
    d = std::round(((106.66666666666667 - b_x2[1]) * 0.2578125 + 70.0 / sizeI) *
                       80.0 +
                   14400.0);
    printf("%f, ",std::round((( - bottom) * 300 / 640 ) * 80.0 + 26400.0));
    d = std::round((( - bottom) * 300 / 640 + 64*m ) * 80.0 + 26400.0);
    printf("%f, ",d);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        iy = static_cast<int>(d);
      } else {
        iy = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      iy = MAX_int32_T;
    } else {
      iy = 0;
    }
    if ((iy <= 0) || (iy > 26000)) {
    d = std::round((( - bottom) * 290 / 640 ) * 80.0 + 26400.0);
      if (d < 2.147483648E+9) {
        if (d >= -2.147483648E+9) {
          iy = static_cast<int>(d);
        } else {
          iy = MIN_int32_T;
        }
      } else if (d >= 2.147483648E+9) {
        iy = MAX_int32_T;
      } else {
        iy = 0;
      }
    }
    //     %% Publishするrostopicを整形
    //     PubSimProgressMsg2.Data = int32(xmax);
    d = std::round((1.0 - sizeOutput_idx_1) / sizeI + sizeOutput_idx_0);

    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        ibmat = static_cast<int>(d);
      } else {
        ibmat = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      ibmat = MAX_int32_T;
    } else {
      ibmat = 0;
    }
    d = static_cast<double>(ibmat) + offset;
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        ibmat = static_cast<int>(d);
      } else {
        ibmat = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      ibmat = MAX_int32_T;
    } else {
      ibmat = 0;
    }
    x2[0] = ibmat;
    d = std::round(b_x2[1]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        ibmat = static_cast<int>(d);
      } else {
        ibmat = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      ibmat = MAX_int32_T;
    } else {
      ibmat = 0;
    }
    d = static_cast<double>(ibmat) + offset;
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        ibmat = static_cast<int>(d);
      } else {
        ibmat = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      ibmat = MAX_int32_T;
    } else {
      ibmat = 0;
    }
    x2[1] = ibmat;
 //   b_image_HT.set_size(image_HT.size(0), image_HT.size(1), 3);
 //   iacol = image_HT.size(0) * image_HT.size(1) * image_HT.size(2) - 1;
 //   for (ibmat = 0; ibmat <= iacol; ibmat++) {
 //     b_image_HT[ibmat] = image_HT[ibmat];
 //   }
    // insert shape Pos[x2(1,1) x2()]
    printf("%d, %d, %d, %d, ", x2[0], x2[1], x2[2], x2[3]);
//    coder::insertShape(b_image_HT, x2, image_HT);
//    coder::rosWriteImage(&PubimageMsg, image_HT);
// Low-Pass Filter
    if(std::isnan(bottom)){
        iy = pos_pre;
    }else{
        iy = iy*0.9 + pos_pre*0.1; 
    }
    expl_temp.Data = iy;
    printf("%d\n", iy); 
    PubSimProgress2.send(expl_temp);
//    Pubimage.send(&PubimageMsg);
    pos_pre = iy;
  }
}

// End of code generation (line_detection14.cpp)
