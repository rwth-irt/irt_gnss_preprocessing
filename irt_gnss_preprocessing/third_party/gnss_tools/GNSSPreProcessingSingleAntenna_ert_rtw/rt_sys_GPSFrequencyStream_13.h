//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_sys_GPSFrequencyStream_13.h
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
#ifndef RTW_HEADER_rt_sys_GPSFrequencyStream_13_h_
#define RTW_HEADER_rt_sys_GPSFrequencyStream_13_h_
#include "rtwtypes.h"

// Block signals for system '<S18>/Signal Noise Variance'
struct B_SignalNoiseVariance_GNSSPre_T {
  real_T variancePseudorange[40];      // '<S18>/Signal Noise Variance'
  real_T varianceDeltarange[40];       // '<S18>/Signal Noise Variance'
};

// Block states (default storage) for system '<S18>/Signal Noise Variance'
struct DW_SignalNoiseVariance_GNSSPr_T {
  int32_T SFunction_DIMS2;             // '<S18>/Signal Noise Variance'
  int32_T SFunction_DIMS3;             // '<S18>/Signal Noise Variance'
};

#endif                            // RTW_HEADER_rt_sys_GPSFrequencyStream_13_h_

//
// File trailer for generated code.
//
// [EOF]
//
