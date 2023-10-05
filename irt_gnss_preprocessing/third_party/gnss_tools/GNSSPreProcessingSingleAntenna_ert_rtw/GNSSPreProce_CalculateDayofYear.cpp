//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GNSSPreProce_CalculateDayofYear.cpp
//
// Code generated for Simulink model 'GNSSPreProcessingSingleAntenna'.
//
// Model version                  : 7.0
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Jan 26 20:34:15 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "rtwtypes.h"
#include "GNSSPreProce_CalculateDayofYear.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <cmath>

// Output and update for atomic system: '<S3>/Calculate Day of Year'
void GNSS_preprocessingModelClass::GNSSPreProce_CalculateDayofYear(real_T
  rtu_WNc, real_T rtu_TOW, real_T *rty_dayOfYear,
  DW_CalculateDayofYear_GNSSPre_T *localDW)
{
  if (localDW->doy == 0.0) {
    real_T JD;
    real_T a;
    real_T b;
    JD = (rtu_WNc * 7.0 + 2.4442445E+6) + rtu_TOW / 3600.0 / 24.0;
    a = std::trunc(JD + 0.5);
    if (a < 2.299161E+6) {
      b = a + 1524.0;
    } else {
      b = std::trunc((a - 1.86721625E+6) / 36524.25);
      b = ((a + b) - std::trunc(b / 4.0)) + 1525.0;
    }

    a = std::trunc((b - 122.1) / 365.25);
    b = std::trunc((b - std::trunc(365.25 * a)) / 30.6001);
    a = (a - 4715.0) - std::trunc((((b - 1.0) - std::trunc(b / 14.0) * 12.0) +
      7.0) / 10.0);
    localDW->doy = JD - (((((367.0 * a - std::floor(7.0 * a / 4.0)) - std::floor
      ((std::floor((a - 1.1428571428571428) / 100.0) + 1.0) * 3.0 / 4.0)) + 30.0)
                          + 1.0) + 1.7210285E+6);
    localDW->doy = std::floor(localDW->doy);
  }

  *rty_dayOfYear = localDW->doy;
}

//
// File trailer for generated code.
//
// [EOF]
//
