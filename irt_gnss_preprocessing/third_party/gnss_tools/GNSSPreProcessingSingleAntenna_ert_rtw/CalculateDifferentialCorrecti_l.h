//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateDifferentialCorrecti_l.h
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
#ifndef RTW_HEADER_CalculateDifferentialCorrecti_l_h_
#define RTW_HEADER_CalculateDifferentialCorrecti_l_h_
#include "rtwtypes.h"
#include "GNSSPreProcessingSingleAntenna_types.h"

// Block signals for system '<S70>/Calculate Differential Corrections'
struct B_CalculateDifferentialCorr_g_T {
  real_T diffPseudorangeCorrection[40];
                                  // '<S70>/Calculate Differential Corrections'
  uint16_T maskDiffCorr[40];      // '<S70>/Calculate Differential Corrections'
};

// Block states (default storage) for system '<S70>/Calculate Differential Corrections' 
struct DW_CalculateDifferentialCor_o_T {
  emxArray_real_T_40_GNSSPrePro_T delta_pr2;
                                  // '<S70>/Calculate Differential Corrections'
  emxArray_uint16_T_37_GNSSPreP_T PRNs;
                                  // '<S70>/Calculate Differential Corrections'
  real_T old_t;                   // '<S70>/Calculate Differential Corrections'
  int32_T SFunction_DIMS2;        // '<S70>/Calculate Differential Corrections'
  int32_T SFunction_DIMS3;        // '<S70>/Calculate Differential Corrections'
  boolean_T delta_pr2_not_empty;  // '<S70>/Calculate Differential Corrections'
};

#endif                         // RTW_HEADER_CalculateDifferentialCorrecti_l_h_

//
// File trailer for generated code.
//
// [EOF]
//
