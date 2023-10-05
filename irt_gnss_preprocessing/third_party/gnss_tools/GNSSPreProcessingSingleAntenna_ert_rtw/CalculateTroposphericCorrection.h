//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateTroposphericCorrection.h
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
#ifndef RTW_HEADER_CalculateTroposphericCorrection_h_
#define RTW_HEADER_CalculateTroposphericCorrection_h_
#include "rtwtypes.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Block signals for system '<S23>/Calculate Tropospheric Corrections'
struct B_CalculateTroposphericCorrec_T {
  real_T troposphericDelay[40];   // '<S23>/Calculate Tropospheric Corrections'
};

// Block states (default storage) for system '<S23>/Calculate Tropospheric Corrections' 
struct DW_CalculateTroposphericCorre_T {
  int32_T SFunction_DIMS2;        // '<S23>/Calculate Tropospheric Corrections'
};

#endif                         // RTW_HEADER_CalculateTroposphericCorrection_h_

//
// File trailer for generated code.
//
// [EOF]
//
