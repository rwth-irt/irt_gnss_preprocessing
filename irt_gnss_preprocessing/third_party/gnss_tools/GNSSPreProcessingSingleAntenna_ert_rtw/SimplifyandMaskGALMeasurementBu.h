//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SimplifyandMaskGALMeasurementBu.h
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
#ifndef RTW_HEADER_SimplifyandMaskGALMeasurementBu_h_
#define RTW_HEADER_SimplifyandMaskGALMeasurementBu_h_
#include "rtwtypes.h"
#include "GNSSPreProcessingSingleAntenna_types.h"

// Block signals for system '<S12>/Simplify and Mask GAL Measurement Bus'
struct B_SimplifyandMaskGALMeasureme_T {
  emxArray__gnssops_navigation__T r;
  emxArray__gnssops_navigation__T r1;
  emxArray__gnssops_navigation__T r2;
  emxArray__gnssops_navigation__T r3;
  b_gnssops_navigation_data_GNS_T expl_temp;
  gnssops_navigation_data navdata_e1;
                               // '<S12>/Simplify and Mask GAL Measurement Bus'
  gnssops_navigation_data navdata_e5a;
                               // '<S12>/Simplify and Mask GAL Measurement Bus'
  gnssops_navigation_data navdata_e5b;
                               // '<S12>/Simplify and Mask GAL Measurement Bus'
  gnssops_navigation_data navdata_e5;
                               // '<S12>/Simplify and Mask GAL Measurement Bus'
  gnssops_navigation_data r4;
  real_T TOW;                  // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T pr_e1[40];            // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T pr_e1_sigma[40];      // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T dr_e1[40];            // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cn0_e1[40];           // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cp_e1[40];            // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cp_e1_sigma[40];      // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T pr_e5a[40];           // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T pr_e5a_sigma[40];     // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T dr_e5a[40];           // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cn0_e5a[40];          // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cp_e5a[40];           // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cp_e5a_sigma[40];     // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T pr_e5b[40];           // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T pr_e5b_sigma[40];     // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T dr_e5b[40];           // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cn0_e5b[40];          // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cp_e5b[40];           // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cp_e5b_sigma[40];     // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T pr_e5[40];            // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T pr_e5_sigma[40];      // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T dr_e5[40];            // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cn0_e5[40];           // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cp_e5[40];            // '<S12>/Simplify and Mask GAL Measurement Bus'
  real_T cp_e5_sigma[40];      // '<S12>/Simplify and Mask GAL Measurement Bus'
  real32_T locktime_e1[40];    // '<S12>/Simplify and Mask GAL Measurement Bus'
  real32_T locktime_e5a[40];   // '<S12>/Simplify and Mask GAL Measurement Bus'
  real32_T locktime_e5b[40];   // '<S12>/Simplify and Mask GAL Measurement Bus'
  real32_T locktime_e5[40];    // '<S12>/Simplify and Mask GAL Measurement Bus'
  uint16_T svid_e1[40];        // '<S12>/Simplify and Mask GAL Measurement Bus'
  uint16_T svid_e5a[40];       // '<S12>/Simplify and Mask GAL Measurement Bus'
  uint16_T svid_e5b[40];       // '<S12>/Simplify and Mask GAL Measurement Bus'
  uint16_T svid_e5[40];        // '<S12>/Simplify and Mask GAL Measurement Bus'
};

// Block states (default storage) for system '<S12>/Simplify and Mask GAL Measurement Bus' 
struct DW_SimplifyandMaskGALMeasurem_T {
  gnssops_navigation_data_size SFunction_DIMS4;
                               // '<S12>/Simplify and Mask GAL Measurement Bus'
  gnssops_navigation_data_size SFunction_DIMS13;
                               // '<S12>/Simplify and Mask GAL Measurement Bus'
  gnssops_navigation_data_size SFunction_DIMS22;
                               // '<S12>/Simplify and Mask GAL Measurement Bus'
  gnssops_navigation_data_size SFunction_DIMS31;
                               // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS3;     // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS5;     // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS6;     // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS7;     // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS8;     // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS9;     // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS10;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS11;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS12;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS14;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS15;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS16;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS17;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS18;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS19;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS20;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS21;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS23;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS24;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS25;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS26;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS27;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS28;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS29;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS30;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS32;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS33;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS34;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS35;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS36;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS37;    // '<S12>/Simplify and Mask GAL Measurement Bus'
  int32_T SFunction_DIMS38;    // '<S12>/Simplify and Mask GAL Measurement Bus'
};

#endif                         // RTW_HEADER_SimplifyandMaskGALMeasurementBu_h_

//
// File trailer for generated code.
//
// [EOF]
//
