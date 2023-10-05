//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateDualfrequencyCorrectio.h
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
#ifndef RTW_HEADER_CalculateDualfrequencyCorrectio_h_
#define RTW_HEADER_CalculateDualfrequencyCorrectio_h_
#include "rtwtypes.h"
#include "GNSSPreProcessingSingleAntenna_types.h"

// Block signals for system '<S51>/Calculate Dualfrequency Correction with L1 and L2C' 
struct B_CalculateDualfrequencyCorre_T {
  GNSS_Measurement measurementFrequencyBus;
                  // '<S51>/Calculate Dualfrequency Correction with L1 and L2C'
  real_T dualFrequencyCorrection[40];
                  // '<S51>/Calculate Dualfrequency Correction with L1 and L2C'
  uint16_T SvidDualFrequencyCorrected[40];
                  // '<S51>/Calculate Dualfrequency Correction with L1 and L2C'
};

// Block states (default storage) for system '<S51>/Calculate Dualfrequency Correction with L1 and L2C' 
struct DW_CalculateDualfrequencyCorr_T {
  GNSS_Measurement_size SFunction_DIMS2;
                  // '<S51>/Calculate Dualfrequency Correction with L1 and L2C'
  int32_T SFunction_DIMS3;
                  // '<S51>/Calculate Dualfrequency Correction with L1 and L2C'
  int32_T SFunction_DIMS4;
                  // '<S51>/Calculate Dualfrequency Correction with L1 and L2C'
};

#endif                         // RTW_HEADER_CalculateDualfrequencyCorrectio_h_

//
// File trailer for generated code.
//
// [EOF]
//
