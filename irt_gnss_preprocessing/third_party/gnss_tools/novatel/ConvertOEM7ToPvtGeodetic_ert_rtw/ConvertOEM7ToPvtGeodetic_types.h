//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToPvtGeodetic_types.h
//
// Code generated for Simulink model 'ConvertOEM7ToPvtGeodetic'.
//
// Model version                  : 2.34
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Nov 30 12:03:08 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_ConvertOEM7ToPvtGeodetic_types_h_
#define RTW_HEADER_ConvertOEM7ToPvtGeodetic_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_OEM7_BestPos_
#define DEFINED_TYPEDEF_FOR_OEM7_BestPos_

// Novatel OEM7 Commands and Logs Reference Manual, p.443-450

struct OEM7_BestPos
{
  // GPS reference week number (field from Oem7Header)
  uint16_T header_week;

  // Milliseconds from the beginning of the GPS reference week (field from Oem7Header) 
  int32_T header_ms;

  // Solution status
  uint32_T sol_stat;

  // Position type
  uint32_T pos_type;

  // Latitude (degrees)
  real_T lat;

  // Longitude (degrees)
  real_T lon;

  // Height above mean sea level (metres)
  real_T hgt;

  // Undulation - the relationship between the geoid and the ellipsoid (m) of the chosen datum 
  real32_T undulation;

  // Datum ID number
  uint32_T datum_id_number;

  // Latitude standard deviation (m)
  real32_T lat_sigma;

  // Longitude standard deviation (m)
  real32_T lon_sigma;

  // Height standard deviation (m)
  real32_T hgt_sigma;

  // Base station ID
  int8_T stn_id[4];

  // Differential age in seconds
  real32_T diff_age;

  // Solution age in seconds
  real32_T sol_age;

  // Number of satellites tracked
  uint8_T number_svs;

  // Number of satellites used in solution
  uint8_T number_soln_svs;

  // Number of satellites with L1/E1/B1 signals used in solution
  uint8_T number_soln_l1_svs;

  // Number of satellites with multi-frequency signals used in solution
  uint8_T number_soln_multi_svs;

  // Reserved for internal use
  int8_T Reserved;

  // Extended solution status
  int8_T ext_sol_stat;

  // Galileo and BeiDou signals used mask
  int8_T galileo_and_beidou_sig_mask;

  // GPS and GLONASS signals used mask
  int8_T gps_and_glonass_sig_mask;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_OEM7_BestVel_
#define DEFINED_TYPEDEF_FOR_OEM7_BestVel_

// Novatel OEM7 Commands and Logs Reference Manual, p.458-460
struct OEM7_BestVel
{
  // GPS reference week number (field from Oem7Header)
  uint16_T header_week;

  // Milliseconds from the beginning of the GPS reference week (field from Oem7Header) 
  int32_T header_ms;

  // Solution status
  uint32_T sol_stat;

  // Velocity type
  uint32_T vel_type;

  // A measure of the latency in the velocity time tag (s)
  real32_T latency;

  // Differential age (s)
  real32_T age;

  // Horizontal speed over ground (m/s)
  real_T hor_spd;

  // Actual direction of motion over ground (track overground) with respect to True North (deg) 
  real_T trk_gnd;

  // Vertical speed (m/s)
  real_T vert_spd;

  // Reserved for internal use
  real32_T Reserved;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_OEM7_ClockModel_
#define DEFINED_TYPEDEF_FOR_OEM7_ClockModel_

// Novatel OEM7 Commands and Logs Reference Manual, p.470-471
struct OEM7_ClockModel
{
  // GPS reference week number (field from Oem7Header)
  uint16_T header_week;

  // Milliseconds from the beginning of the GPS reference week (field from Oem7Header) 
  int32_T header_ms;

  // Clock model status
  uint32_T status;

  // Number of rejected instantaneous clock errors
  uint32_T reject_count;

  // Time of last propagation
  int32_T propagation_time;

  // Time of last update
  int32_T update_time;

  // Receiver clock bias (m)
  real_T bias;

  // Receiver clock bias rate (m/s)
  real_T rate;

  // Reserved for internal use
  real_T Reserved1;

  // Receiver clock bias variance (m²)
  real_T bias_variance;

  // Receiver clock bias/bias rate covariance (m²/s)
  real_T covariance;

  // Reserved for internal use
  real_T Reserved2;

  // Reserved for internal use
  real_T Reserved3;

  // Receiver clock bias rate variance (m²/s²)
  real_T rate_variance;

  // Reserved for internal use
  real_T Reserved4;

  // Reserved for internal use
  real_T Reserved5;

  // Reserved for internal use
  real_T Reserved6;

  // Reserved for internal use
  real_T Reserved7;

  // Last instantaneous receiver clock bias (m)
  real_T instantaneous_bias;

  // Last instantaneous receiver clock bias rate (m/s)
  real_T instantaneous_rate;

  // Reserved for internal use
  boolean_T Reserved8;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_OEM7_DualAntennaHeading_
#define DEFINED_TYPEDEF_FOR_OEM7_DualAntennaHeading_

// Novatel OEM7 Commands and Logs Reference Manual, p.477-478
struct OEM7_DualAntennaHeading
{
  // GPS reference week number (field from Oem7Header)
  uint16_T header_week;

  // Milliseconds from the beginning of the GPS reference week (field from Oem7Header) 
  int32_T header_ms;

  // Solution status
  uint32_T sol_stat;

  // Position type
  uint32_T pos_type;

  // Baseline length (m)
  real32_T length;

  // Heading (deg), 0-359.999deg
  real32_T heading;

  // Pitch (deg), +-90deg
  real32_T pitch;

  // Reserved for internal use
  real32_T Reserved;

  // Heading standard deviation (deg)
  real32_T hdg_std_dev;

  // Pitch standard deviation (deg)
  real32_T ptch_std_dev;

  // Station ID string
  int8_T stn_id[4];

  // Number of satellites tracked
  uint8_T number_svs;

  // Number of satellites in solution
  uint8_T number_soln_svs;

  // Number of satellites above the elevation mask angle
  uint8_T number_obs;

  // Number of satellites above the mask angle with L2
  uint8_T number_multi;

  // Solution source
  int8_T sol_source;

  // Extended solution status
  int8_T ext_sol_stat;

  // Galileo and BeiDou signals used mask
  int8_T galileo_and_beidou_sig_mask;

  // GPS and GLONASS signals used mask
  int8_T gps_and_glonass_sig_mask;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_gnssraw_pvt_geodetic_t_
#define DEFINED_TYPEDEF_FOR_gnssraw_pvt_geodetic_t_

struct gnssraw_pvt_geodetic_t
{
  real_T TOW;
  uint16_T WNc;
  uint8_T Mode;
  uint8_T Error;
  real_T phi;
  real32_T phi_var;
  real_T lambda;
  real32_T lambda_var;
  real_T h;
  real32_T h_var;
  real32_T Undulation;
  real_T Vn;
  real_T Ve;
  real_T Vu;
  real_T TrkGND;
  real_T COG;
  real32_T yaw;
  real32_T yaw_var;
  real32_T pitch_roll;
  real32_T pitch_roll_var;
  real_T RxClkBias;
  real_T RxClkBiasVar;
  real_T RxClkDrift;
  real_T RxClkDriftVar;
  uint8_T TimeSystem;
  uint8_T Datum;
  uint8_T NrSV;
  uint8_T NrSVUsed;
  uint8_T NrSVUsedL1;
  uint8_T NrSVUsedMulti;
  uint8_T WACorrInfo;
  uint16_T ReferenceID;
  uint16_T MeanCorrAge;
  uint32_T SignalInfo;
  uint8_T AlertFlag;
  uint8_T NrBases;
  uint16_T PPPInfo;
  boolean_T DoNotUseValues;
};

#endif
#endif                          // RTW_HEADER_ConvertOEM7ToPvtGeodetic_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
