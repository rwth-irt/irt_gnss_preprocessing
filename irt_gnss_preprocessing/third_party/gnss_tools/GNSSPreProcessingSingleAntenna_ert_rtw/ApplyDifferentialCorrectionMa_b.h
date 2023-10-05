//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ApplyDifferentialCorrectionMa_b.h
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
#ifndef RTW_HEADER_ApplyDifferentialCorrectionMa_b_h_
#define RTW_HEADER_ApplyDifferentialCorrectionMa_b_h_
#include "rtwtypes.h"
#include "GNSSPreProcessingSingleAntenna_types.h"

// Block signals for system '<S111>/Apply Differential Correction Mask1'
struct B_ApplyDifferentialCorrecti_e_T {
  GNSS_Measurement GPS_measurement_Bus_masked;
                                // '<S111>/Apply Differential Correction Mask1'
};

// Block states (default storage) for system '<S111>/Apply Differential Correction Mask1' 
struct DW_ApplyDifferentialCorrect_l_T {
  GNSS_Measurement_size SFunction_DIMS2;
                                // '<S111>/Apply Differential Correction Mask1'
};

#endif                         // RTW_HEADER_ApplyDifferentialCorrectionMa_b_h_

//
// File trailer for generated code.
//
// [EOF]
//
