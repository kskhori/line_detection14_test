//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// pause.cpp
//
// Code generation for function 'pause'
//

// Include files
#include "pause.h"
#include "rt_nonfinite.h"
#include "coder_posix_time.h"
#include <cmath>
#include <string.h>

// Variable Definitions
static unsigned char pauseState;

// Function Definitions
namespace coder {
void pause(double varargin_1)
{
  coderTimespec b_timespec;
  if (pauseState == 0) {
    double delay;
    double delayInt;
    delay = varargin_1;
    if ((varargin_1 < 0.0) || std::isnan(varargin_1)) {
      delay = 0.0;
    }
    delayInt = std::floor(delay);
    if (delayInt > 4.294967295E+9) {
      delayInt = 4.294967295E+9;
    }
    delay -= delayInt;
    if (delay > 0.0) {
      b_timespec.tv_nsec = std::floor(delay * 1.0E+9);
    } else {
      b_timespec.tv_nsec = 0.0;
    }
    b_timespec.tv_sec = delayInt;
    coderTimeSleep(&b_timespec);
  }
}

} // namespace coder
void cpause_init()
{
  pauseState = 0U;
}

// End of code generation (pause.cpp)
