//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGpsNavBus_types.h
//
// Code generated for Simulink model 'ConvertOEM7ToGpsNavBus'.
//
// Model version                  : 2.3
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 19:53:16 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ConvertOEM7ToGpsNavBus_types_h_
#define RTW_HEADER_ConvertOEM7ToGpsNavBus_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_OEM7_GpsEphem_
#define DEFINED_TYPEDEF_FOR_OEM7_GpsEphem_

// Novatel OEM7 Commands and Logs Reference Manual, p.560-563

struct OEM7_GpsEphem
{
  // GPS reference week number (field from Oem7Header)
  uint16_T header_week[32];

  // Milliseconds from the beginning of the GPS reference week (field from Oem7Header) 
  int32_T header_ms[32];

  // Satellite PRN number
  uint32_T PRN[32];

  // Time stamp of subframe 1 (seconds)
  real_T tow[32];

  // Health status - a 6-bit health code as defined in ICD-GPS-200
  uint32_T health[32];

  // Issue of ephemeris data 1
  uint32_T IODE1[32];

  // Issue of ephemeris data 2
  uint32_T IODE2[32];

  // toe week number (computed from Z count week)
  uint32_T week[32];

  // Z count week number
  uint32_T z_week[32];

  // Reference time for ephemeris (seconds)
  real_T T0e[32];

  // Semi-major axis (metres)
  real_T A[32];

  // Mean motion difference (radians/second)
  real_T DeltaN[32];

  // Mean anomaly of reference time (radians)
  real_T M0[32];

  // Eccentricity, dimensionless
  real_T Ecc[32];

  // Argument of perigee (radians)
  real_T Omega[32];

  // Argument of latitude (amplitude of cosine, radians)
  real_T Cuc[32];

  // Argument of latitude (amplitude of sine, radians)
  real_T Cus[32];

  // Orbit radius (amplitude of cosine, metres)
  real_T Crc[32];

  // Orbit radius (amplitude of sine, metres)
  real_T Crs[32];

  // Inclination (amplitude of cosine, radians)
  real_T Cic[32];

  // Inclination (amplitude of sine, radians)
  real_T Cis[32];

  // Inclination angle at reference time, radians
  real_T I0[32];

  // Rate of inclination angle, radians/second
  real_T IDot[32];

  // Right ascension, radians
  real_T Omega0[32];

  // Rate of right ascension, radians/second
  real_T OmegaDot[32];

  // Issue of data clock
  uint32_T IODC[32];

  // SV clock correction term, seconds
  real_T T0c[32];

  // Estimated group delay difference, seconds
  real_T tgd[32];

  // Clock aging parameter (seconds)
  real_T Af0[32];

  // Clock aging parameter, (seconds/second)
  real_T Af1[32];

  // Clock aging parameter, (seconds/second/second)
  real_T Af2[32];

  // Anti-spoofing on
  boolean_T AS[32];

  // Corrected mean motion (radians/second)
  real_T N[32];

  // User Range Accuracy variance (metres²)
  real_T URA[32];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_gnssraw_gps_nav_t_
#define DEFINED_TYPEDEF_FOR_gnssraw_gps_nav_t_

struct gnssraw_gps_nav_t
{
  real_T TOW[37];
  uint16_T WNc[37];
  uint8_T SVID[37];
  uint8_T Health[37];
  uint16_T IODC[37];
  uint8_T IODE[37];
  real_T T_gd[37];
  uint32_T T_oc[37];
  real_T A_f2[37];
  real_T A_f1[37];
  real_T A_f0[37];
  real_T C_rs[37];
  real_T DELTA_N[37];
  real_T M_0[37];
  real_T C_uc[37];
  real_T E[37];
  real_T C_us[37];
  real_T SQRT_A[37];
  uint32_T T_oe[37];
  real_T C_ic[37];
  real_T OMEGA_0[37];
  real_T C_is[37];
  real_T I_0[37];
  real_T C_rc[37];
  real_T omega[37];
  real_T OMEGADOT[37];
  real_T IDOT[37];
  uint16_T WNt_oc[37];
  uint16_T WNt_oe[37];
};

#endif
#endif                            // RTW_HEADER_ConvertOEM7ToGpsNavBus_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
