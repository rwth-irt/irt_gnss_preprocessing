//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGalFnavBus_types.h
//
// Code generated for Simulink model 'ConvertOEM7ToGalFnavBus'.
//
// Model version                  : 2.4
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 20:11:23 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ConvertOEM7ToGalFnavBus_types_h_
#define RTW_HEADER_ConvertOEM7ToGalFnavBus_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_OEM7_GalFnavEphemeris_
#define DEFINED_TYPEDEF_FOR_OEM7_GalFnavEphemeris_

// Novatel OEM7 Commands and Logs Reference Manual, p.495-496
struct OEM7_GalFnavEphemeris
{
  // GPS reference week number (field from Oem7Header)
  uint16_T header_week[36];

  // Milliseconds from the beginning of the GPS reference week (field from Oem7Header) 
  int32_T header_ms[36];

  // Satellite identifier
  uint32_T SatId[36];

  // E5a health status bits
  uint8_T E5aHealth[36];

  // E5a data validity status
  uint8_T E5aDVS[36];

  // Reserved for internal use
  uint8_T Reserved1[36];

  // Reserved for internal use
  uint8_T Reserved2[36];

  // Issue of data ephemeris
  uint16_T IODnav[36];

  // Signal in space accuracy (unitless)
  uint8_T SISA_Index[36];

  // Reserved for internal use
  uint8_T Reserved3[36];

  // Ephemeris reference time (s)
  uint32_T T0e[36];

  // Clock correction data reference time of week from the F/NAV message (s)
  uint32_T T0c[36];

  // Mean anomaly at ref time (radians)
  real_T M0[36];

  // Mean motion difference (radians/s)
  real_T DeltaN[36];

  // Eccentricity (unitless)
  real_T Ecc[36];

  // Square root of semi-major axis
  real_T RootA[36];

  // Inclination angle at ref time (radians)
  real_T I0[36];

  // Rate of inclination angle (radians/s)
  real_T IDot[36];

  // Longitude of ascending node of orbital plane at weekly epoch (radians)
  real_T Omega0[36];

  // Argument of perigee (radians)
  real_T Omega[36];

  // Rate of right ascension (radians/s)
  real_T OmegaDot[36];

  // Amplitude of the cosine harmonic correction term to the argument of latitude (radians) 
  real_T Cuc[36];

  // Amplitude of the sine harmonic correction term to the argument of latitude (radians) 
  real_T Cus[36];

  // Amplitude of the cosine harmonic correction term to the orbit radius (m)
  real_T Crc[36];

  // Amplitude of the sine harmonic correction term to the orbit radius (m)
  real_T Crs[36];

  // Amplitude of the cosine harmonic correction term to the angle of inclination (radians) 
  real_T Cic[36];

  // Amplitude of the sine harmonic correction term to the angle of inclination (radians) 
  real_T Cis[36];

  // SV clock bias correction coefficient from the F/NAV message (s)
  real_T Af0[36];

  // SV clock drift correction coefficient from the F/NAV message (s/s)
  real_T Af1[36];

  // SV clock drift rate correction coefficient from the F/NAV message (s/s²)
  real_T Af2[36];

  // E1, E5a broadcast group delay
  real_T E1E5aBGD[36];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_gnssraw_gal_nav_t_
#define DEFINED_TYPEDEF_FOR_gnssraw_gal_nav_t_

struct gnssraw_gal_nav_t
{
  real_T TOW[36];
  uint16_T WNc[36];
  uint8_T SVID[36];
  real_T SQRT_A[36];
  real_T M_0[36];
  real_T E[36];
  real_T I_0[36];
  real_T omega[36];
  real_T OMEGA_0[36];
  real_T OMEGADOT[36];
  real_T IDOT[36];
  real_T DELTA_N[36];
  real_T C_uc[36];
  real_T C_us[36];
  real_T C_rc[36];
  real_T C_rs[36];
  real_T C_ic[36];
  real_T C_is[36];
  uint32_T T_oc[36];
  uint32_T T_oe[36];
  real_T A_f2[36];
  real_T A_f1[36];
  real_T A_f0[36];
  uint16_T WNt_oc[36];
  uint16_T WNt_oe[36];
  uint16_T IODnav[36];
};

#endif
#endif                           // RTW_HEADER_ConvertOEM7ToGalFnavBus_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
