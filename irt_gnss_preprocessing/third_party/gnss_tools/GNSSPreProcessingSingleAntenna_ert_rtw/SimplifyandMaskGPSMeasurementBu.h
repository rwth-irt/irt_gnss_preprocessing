//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SimplifyandMaskGPSMeasurementBu.h
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
#ifndef RTW_HEADER_SimplifyandMaskGPSMeasurementBu_h_
#define RTW_HEADER_SimplifyandMaskGPSMeasurementBu_h_
#include "rtwtypes.h"
#include "GNSSPreProcessingSingleAntenna_types.h"

// Block signals for system '<S11>/Simplify and Mask GPS Measurement Bus'
struct B_SimplifyandMaskGPSMeasureme_T {
  emxArray__gnssops_navigation__T r;
  emxArray__gnssops_navigation__T r1;
  emxArray__gnssops_navigation__T r2;
  b_gnssops_navigation_data_GNS_T expl_temp;
  gnssops_navigation_data navdata_L1;
                               // '<S11>/Simplify and Mask GPS Measurement Bus'
  gnssops_navigation_data navdata_L2C;
                               // '<S11>/Simplify and Mask GPS Measurement Bus'
  gnssops_navigation_data navdata_L5;
                               // '<S11>/Simplify and Mask GPS Measurement Bus'
  gnssops_navigation_data r3;
  real_T TOW;                  // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T pr_L1[40];            // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T pr_sigma_L1[40];      // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T dr_L1[40];            // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T cn0_L1[40];           // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T cp_L1[40];            // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T cp_sigma_L1[40];      // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T pr_L2C[40];           // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T pr_sigma_L2C[40];     // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T dr_L2C[40];           // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T cn0_L2C[40];          // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T cp_L2C[40];           // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T cp_sigma_L2C[40];     // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T pr_L5[40];            // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T pr_sigma_L5[40];      // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T dr_L5[40];            // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T cn0_L5[40];           // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T cp_L5[40];            // '<S11>/Simplify and Mask GPS Measurement Bus'
  real_T cp_sigma_L5[40];      // '<S11>/Simplify and Mask GPS Measurement Bus'
  real32_T Locktime_L1[40];    // '<S11>/Simplify and Mask GPS Measurement Bus'
  real32_T Locktime_L2C[40];   // '<S11>/Simplify and Mask GPS Measurement Bus'
  real32_T Locktime_L5[40];    // '<S11>/Simplify and Mask GPS Measurement Bus'
  uint16_T svid_L1[40];        // '<S11>/Simplify and Mask GPS Measurement Bus'
  uint16_T svid_L2C[40];       // '<S11>/Simplify and Mask GPS Measurement Bus'
  uint16_T svid_L5[40];        // '<S11>/Simplify and Mask GPS Measurement Bus'
};

// Block states (default storage) for system '<S11>/Simplify and Mask GPS Measurement Bus' 
struct DW_SimplifyandMaskGPSMeasurem_T {
  gnssops_navigation_data_size SFunction_DIMS4;
                               // '<S11>/Simplify and Mask GPS Measurement Bus'
  gnssops_navigation_data_size SFunction_DIMS13;
                               // '<S11>/Simplify and Mask GPS Measurement Bus'
  gnssops_navigation_data_size SFunction_DIMS22;
                               // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS3;     // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS5;     // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS6;     // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS7;     // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS8;     // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS9;     // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS10;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS11;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS12;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS14;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS15;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS16;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS17;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS18;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS19;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS20;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS21;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS23;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS24;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS25;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS26;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS27;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS28;    // '<S11>/Simplify and Mask GPS Measurement Bus'
  int32_T SFunction_DIMS29;    // '<S11>/Simplify and Mask GPS Measurement Bus'
};

#endif                         // RTW_HEADER_SimplifyandMaskGPSMeasurementBu_h_

//
// File trailer for generated code.
//
// [EOF]
//
