//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateSatelliteClockCorrecti.h
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
#ifndef RTW_HEADER_CalculateSatelliteClockCorrecti_h_
#define RTW_HEADER_CalculateSatelliteClockCorrecti_h_
#include "rtwtypes.h"

// Block signals for system '<S26>/Calculate Satellite Clock Correction'
struct B_CalculateSatelliteClockCorr_T {
  real_T timeEmissionCorrected[40];
                                // '<S26>/Calculate Satellite Clock Correction'
  real_T deltaTimeSV[40];       // '<S26>/Calculate Satellite Clock Correction'
  real_T drTimeCorr[40];        // '<S26>/Calculate Satellite Clock Correction'
};

// Block states (default storage) for system '<S26>/Calculate Satellite Clock Correction' 
struct DW_CalculateSatelliteClockCor_T {
  int32_T SFunction_DIMS2;      // '<S26>/Calculate Satellite Clock Correction'
  int32_T SFunction_DIMS3;      // '<S26>/Calculate Satellite Clock Correction'
  int32_T SFunction_DIMS4;      // '<S26>/Calculate Satellite Clock Correction'
};

#endif                         // RTW_HEADER_CalculateSatelliteClockCorrecti_h_

//
// File trailer for generated code.
//
// [EOF]
//
