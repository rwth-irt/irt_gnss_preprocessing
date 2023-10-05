//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGalIonBus_types.h
//
// Code generated for Simulink model 'ConvertOEM7ToGalIonBus'.
//
// Model version                  : 2.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 19:55:17 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ConvertOEM7ToGalIonBus_types_h_
#define RTW_HEADER_ConvertOEM7ToGalIonBus_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_OEM7_GalIono_
#define DEFINED_TYPEDEF_FOR_OEM7_GalIono_

// Novatel OEM7 Commands and Logs Reference Manual, p.507
struct OEM7_GalIono
{
  // GPS reference week number (field from Oem7Header)
  uint16_T header_week;

  // Milliseconds from the beginning of the GPS reference week (field from Oem7Header) 
  int32_T header_ms;

  // Effective ionization level 1st order parameter (sfu)
  real_T Ai0;

  // Effective ionization level 2st order parameter (sfu/degree)
  real_T Ai1;

  // Effective ionization level 3st order parameter (sfu/degree²)
  real_T Ai2;

  // Ionospheric disturbance flag for region 1
  uint8_T SF1;

  // Ionospheric disturbance flag for region 2
  uint8_T SF2;

  // Ionospheric disturbance flag for region 3
  uint8_T SF3;

  // Ionospheric disturbance flag for region 4
  uint8_T SF4;

  // Ionospheric disturbance flag for region 5
  uint8_T SF5;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_gnssraw_gal_ion_t_
#define DEFINED_TYPEDEF_FOR_gnssraw_gal_ion_t_

struct gnssraw_gal_ion_t
{
  real_T TOW;
  uint16_T WNc;
  uint8_T SVID;
  uint8_T Source;
  real_T a_i0;
  real_T a_i1;
  real_T a_i2;
  uint8_T stormflags;
};

#endif
#endif                            // RTW_HEADER_ConvertOEM7ToGalIonBus_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
