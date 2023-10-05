//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGalGstGpsBus_types.h
//
// Code generated for Simulink model 'ConvertOEM7ToGalGstGpsBus'.
//
// Model version                  : 2.6
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 20:10:35 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ConvertOEM7ToGalGstGpsBus_types_h_
#define RTW_HEADER_ConvertOEM7ToGalGstGpsBus_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_OEM7_GalClock_
#define DEFINED_TYPEDEF_FOR_OEM7_GalClock_

// Novatel OEM7 Commands and Logs Reference Manual, p.492-493
struct OEM7_GalClock
{
  // GPS reference week number (field from Oem7Header)
  uint16_T header_week;

  // Milliseconds from the beginning of the GPS reference week (field from Oem7Header) 
  int32_T header_ms;

  // Constant term of polynomial
  real_T A0;

  // 1st order term of polynomial
  real_T A1;

  // Leap second count before leap second adjustment
  int32_T DeltaTls;

  // UTC data reference time of week (s)
  uint32_T Tot;

  // UTC data reference week number
  uint32_T WNt;

  // Week number of leap second adjustment
  uint32_T WNlsf;

  // Day number at the end of which a leap second adjustment becomes effective
  uint32_T DN;

  // Leap second count after leap second adjustment
  int32_T DeltaTlsf;

  // Constant term of the polynomial describing the difference between Galileo and GPS time 
  real_T A0g;

  // Rate of change of offset the offset between Galileo and GPS time
  real_T A1g;

  // Reference time for GGTO data
  uint32_T T0g;

  // Week number of GGTO reference
  uint32_T WN0g;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_gnssraw_ggto_t_
#define DEFINED_TYPEDEF_FOR_gnssraw_ggto_t_

struct gnssraw_ggto_t
{
  real_T TOW;
  uint16_T WNc;
  uint8_T SVID;
  uint8_T Source;
  real_T A_1G;
  real_T A_0G;
  uint32_T t_oG;
  uint8_T WN_oG;
};

#endif
#endif                         // RTW_HEADER_ConvertOEM7ToGalGstGpsBus_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
