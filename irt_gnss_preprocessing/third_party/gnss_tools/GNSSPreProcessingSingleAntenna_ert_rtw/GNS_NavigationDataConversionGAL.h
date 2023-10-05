//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GNS_NavigationDataConversionGAL.h
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
#ifndef RTW_HEADER_GNS_NavigationDataConversionGAL_h_
#define RTW_HEADER_GNS_NavigationDataConversionGAL_h_
#include "rtwtypes.h"
#include "GNSSPreProcessingSingleAntenna_types.h"

// Block signals for system '<S12>/Navigation Data Conversion GAL'
struct B_NavigationDataConversionGAL_T {
  gnssops_navigation_data GAL_NavigationData_Bus;
                                      // '<S12>/Navigation Data Conversion GAL'
};

// Block states (default storage) for system '<S12>/Navigation Data Conversion GAL' 
struct DW_NavigationDataConversionGA_T {
  gnssops_navigation_data_size SFunction_DIMS2;
                                      // '<S12>/Navigation Data Conversion GAL'
};

#endif                         // RTW_HEADER_GNS_NavigationDataConversionGAL_h_

//
// File trailer for generated code.
//
// [EOF]
//
