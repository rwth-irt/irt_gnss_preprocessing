//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateSatellitePositionandVe.h
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
#ifndef RTW_HEADER_CalculateSatellitePositionandVe_h_
#define RTW_HEADER_CalculateSatellitePositionandVe_h_
#include "rtwtypes.h"

// Block signals for system '<S26>/Calculate Satellite Position and Velocity'
struct B_CalculateSatellitePositiona_T {
  real_T satPosEcef[120];  // '<S26>/Calculate Satellite Position and Velocity'
  real_T satVelEcef[120];  // '<S26>/Calculate Satellite Position and Velocity'
};

// Block states (default storage) for system '<S26>/Calculate Satellite Position and Velocity' 
struct DW_CalculateSatellitePosition_T {
  int32_T SFunction_DIMS2[2];
                           // '<S26>/Calculate Satellite Position and Velocity'
  int32_T SFunction_DIMS3[2];
                           // '<S26>/Calculate Satellite Position and Velocity'
};

#endif                         // RTW_HEADER_CalculateSatellitePositionandVe_h_

//
// File trailer for generated code.
//
// [EOF]
//
