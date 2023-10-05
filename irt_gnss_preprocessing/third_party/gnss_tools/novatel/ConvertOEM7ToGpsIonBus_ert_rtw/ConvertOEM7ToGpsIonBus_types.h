//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGpsIonBus_types.h
//
// Code generated for Simulink model 'ConvertOEM7ToGpsIonBus'.
//
// Model version                  : 2.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 19:54:30 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ConvertOEM7ToGpsIonBus_types_h_
#define RTW_HEADER_ConvertOEM7ToGpsIonBus_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_OEM7_IonUtc_
#define DEFINED_TYPEDEF_FOR_OEM7_IonUtc_

// Novatel OEM7 Commands and Logs Reference Manual, p.578-579
struct OEM7_IonUtc
{
  // GPS reference week number (field from Oem7Header)
  uint16_T header_week;

  // Milliseconds from the beginning of the GPS reference week (field from Oem7Header) 
  int32_T header_ms;

  // Alpha parameter constant term
  real_T a0;

  // Alpha parameter 1st order term
  real_T a1;

  // Alpha parameter 2nd order term
  real_T a2;

  // Alpha parameter 3rd order term
  real_T a3;

  // Beta parameter constant term
  real_T b0;

  // Beta parameter 1st order term
  real_T b1;

  // Beta parameter 2nd order term
  real_T b2;

  // Beta parameter 3rd order term
  real_T b3;

  // UTC reference week number
  uint32_T utc_wn;

  // Reference time of UTC parameters
  uint32_T tot;

  // UTC constant term of polynomial
  real_T A0;

  // UTC 1st order term of polynomial
  real_T A1;

  // Future week number
  uint32_T wn_lsf;

  // Day number
  uint32_T dn;

  // Delta time due to leap seconds
  int32_T deltat_ls;

  // Future delta time due to leap seconds
  int32_T deltat_lsf;

  // Reserved for internal use
  int32_T Reserved;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_gnssraw_gps_ion_t_
#define DEFINED_TYPEDEF_FOR_gnssraw_gps_ion_t_

struct gnssraw_gps_ion_t
{
  real_T TOW;
  uint16_T WNc;
  uint8_T SVID;
  real_T alpha_0;
  real_T alpha_1;
  real_T alpha_2;
  real_T alpha_3;
  real_T beta_0;
  real_T beta_1;
  real_T beta_2;
  real_T beta_3;
};

#endif
#endif                            // RTW_HEADER_ConvertOEM7ToGpsIonBus_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
