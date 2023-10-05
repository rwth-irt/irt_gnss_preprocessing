//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GN_CreateSatelliteElevationMask.h
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
#ifndef RTW_HEADER_GN_CreateSatelliteElevationMask_h_
#define RTW_HEADER_GN_CreateSatelliteElevationMask_h_
#include "rtwtypes.h"

// Block signals for system '<S54>/Create Satellite Elevation Mask'
struct B_CreateSatelliteElevationMas_T {
  real_T elevationAngle[40];         // '<S54>/Create Satellite Elevation Mask'
  real_T azimuthAngle[40];           // '<S54>/Create Satellite Elevation Mask'
  boolean_T elevationMask[40];       // '<S54>/Create Satellite Elevation Mask'
};

// Block states (default storage) for system '<S54>/Create Satellite Elevation Mask' 
struct DW_CreateSatelliteElevationMa_T {
  int32_T SFunction_DIMS2;           // '<S54>/Create Satellite Elevation Mask'
  int32_T SFunction_DIMS3;           // '<S54>/Create Satellite Elevation Mask'
  int32_T SFunction_DIMS4;           // '<S54>/Create Satellite Elevation Mask'
};

#endif                         // RTW_HEADER_GN_CreateSatelliteElevationMask_h_

//
// File trailer for generated code.
//
// [EOF]
//
