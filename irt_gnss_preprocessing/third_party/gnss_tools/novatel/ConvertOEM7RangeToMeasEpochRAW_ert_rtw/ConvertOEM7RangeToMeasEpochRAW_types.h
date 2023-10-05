//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7RangeToMeasEpochRAW_types.h
//
// Code generated for Simulink model 'ConvertOEM7RangeToMeasEpochRAW'.
//
// Model version                  : 2.5
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 21:42:15 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ConvertOEM7RangeToMeasEpochRAW_types_h_
#define RTW_HEADER_ConvertOEM7RangeToMeasEpochRAW_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_OEM7_Range_
#define DEFINED_TYPEDEF_FOR_OEM7_Range_

// Novatel OEM7 Commands and Logs Reference Manual, p.712-721
struct OEM7_Range
{
  // GPS reference week number (field from Oem7Header)
  uint16_T header_week;

  // Milliseconds from the beginning of the GPS reference week (field from Oem7Header) 
  int32_T header_ms;

  // Number of observations with information to follow
  uint32_T number_obs;

  // Satellite PRN number of range measurement
  uint16_T prn[112];

  // GLONASS Frequency + 7
  uint16_T glofreq[112];

  // Pseudorange measurement (m)
  real_T psr[112];

  // Pseudorange measurement standard deviation (m)
  real32_T psr_sigma[112];

  // Carrier phase, in cycles (accumulated Doppler range)
  real_T adr[112];

  // Estimated carrier phase standard deviation (cycles)
  real32_T adr_sigma[112];

  // Instantaneous carrier Doppler frequency (Hz)
  real32_T dopp[112];

  // Carrier to noise density ratio (dB-Hz)
  real32_T cn0[112];

  // Number of seconds of continuous tracking (no cycle slipping)
  real32_T locktime[112];

  // Tracking status
  uint32_T ch_tr_status[112];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_gnssraw_measurement_t_
#define DEFINED_TYPEDEF_FOR_gnssraw_measurement_t_

struct gnssraw_measurement_t
{
  real_T TOW;
  uint16_T WNc;
  uint8_T N;
  uint16_T SVID[40];
  real_T Pseudorange[200];
  real_T Pseudorange_Sigma[200];
  real_T Doppler[200];
  uint8_T Type[200];
  real_T Carrier[200];
  real_T Carrier_Sigma[200];
  real_T CN0[200];
  real32_T Locktime[200];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_HCS_Measurement_
#define DEFINED_TYPEDEF_FOR_HCS_Measurement_

struct HCS_Measurement
{
  real_T SVID[40];
  real_T HalfCycleAmbiguity[40];
};

#endif
#endif                    // RTW_HEADER_ConvertOEM7RangeToMeasEpochRAW_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
