//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateDifferentialCorrection.h
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
#ifndef RTW_HEADER_CalculateDifferentialCorrection_h_
#define RTW_HEADER_CalculateDifferentialCorrection_h_
#include "rtwtypes.h"
#include "GNSSPreProcessingSingleAntenna_types.h"

// Block signals for system '<S23>/Calculate Differential Corrections'
struct B_CalculateDifferentialCorrec_T {
  real_T diffPseudorangeCorrection[40];
                                  // '<S23>/Calculate Differential Corrections'
  uint16_T maskDiffCorr[40];      // '<S23>/Calculate Differential Corrections'
};

// Block states (default storage) for system '<S23>/Calculate Differential Corrections' 
struct DW_CalculateDifferentialCorre_T {
  emxArray_real_T_40_GNSSPrePro_T delta_pr2;
                                  // '<S23>/Calculate Differential Corrections'
  emxArray_uint16_T_37_GNSSPreP_T PRNs;
                                  // '<S23>/Calculate Differential Corrections'
  real_T old_t;                   // '<S23>/Calculate Differential Corrections'
  int32_T SFunction_DIMS2;        // '<S23>/Calculate Differential Corrections'
  int32_T SFunction_DIMS3;        // '<S23>/Calculate Differential Corrections'
  boolean_T delta_pr2_not_empty;  // '<S23>/Calculate Differential Corrections'
};

#endif                         // RTW_HEADER_CalculateDifferentialCorrection_h_

//
// File trailer for generated code.
//
// [EOF]
//
