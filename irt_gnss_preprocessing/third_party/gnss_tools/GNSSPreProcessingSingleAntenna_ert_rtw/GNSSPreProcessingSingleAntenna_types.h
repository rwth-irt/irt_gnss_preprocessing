//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GNSSPreProcessingSingleAntenna_types.h
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
#ifndef RTW_HEADER_GNSSPreProcessingSingleAntenna_types_h_
#define RTW_HEADER_GNSSPreProcessingSingleAntenna_types_h_
#include "rtwtypes.h"
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

#ifndef DEFINED_TYPEDEF_FOR_DD_RTCM_3_3_L1_E1_t_
#define DEFINED_TYPEDEF_FOR_DD_RTCM_3_3_L1_E1_t_

struct DD_RTCM_3_3_L1_E1_t
{
  real_T TOW;
  real_T base[3];
  uint8_T SVID[40];
  real_T Pseudorange[40];
  uint8_T Type[40];
  real_T Carrier[40];
  real_T CN0[40];
  uint16_T locktime[40];
  uint16_T Reference_Station_ID;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_parameters_gps_t_
#define DEFINED_TYPEDEF_FOR_parameters_gps_t_

struct parameters_gps_t
{
  boolean_T enable_gps;
  boolean_T enable_gps_l1;
  boolean_T enable_gps_l2;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_parameters_galileo_t_
#define DEFINED_TYPEDEF_FOR_parameters_galileo_t_

struct parameters_galileo_t
{
  boolean_T enable_galileo;
  boolean_T enable_galileo_e1;
  boolean_T enable_galileo_e5a;
  boolean_T enable_galileo_e5b;
  boolean_T enable_galileo_e5;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_parameters_gate_t_
#define DEFINED_TYPEDEF_FOR_parameters_gate_t_

struct parameters_gate_t
{
  boolean_T enable_gate;
  uint8_T prn_psl1;
  uint8_T prn_psl2;
  uint8_T prn_psl3;
  uint8_T prn_psl4;
  uint8_T prn_psl5;
  uint8_T prn_psl6;
  uint8_T prn_psl7;
  uint8_T prn_psl8;
  uint8_T prn_psl9;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_parameters_gnss_t_
#define DEFINED_TYPEDEF_FOR_parameters_gnss_t_

struct parameters_gnss_t
{
  parameters_gps_t gps;
  parameters_galileo_t galileo;
  parameters_gate_t gate;
  real_T elevation_mask;
  boolean_T enable_galileo_timebase;
  boolean_T enable_differential_correction;
  boolean_T enable_tropospheric_correction;
  boolean_T enable_ionospheric_correction;
  boolean_T enable_SatPosVel_calculation;
  boolean_T enable_WL_correction;
  boolean_T use_measured_variance;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_parameters_raim_t_
#define DEFINED_TYPEDEF_FOR_parameters_raim_t_

struct parameters_raim_t
{
  // % horizental alarm limit [m]
  real_T HAL;

  // % probability of false alarm
  real_T P_FA;

  // % probability of missed detection
  real_T P_MD;

  // % threshold for the probability identification
  real_T P_BayesThreshold;

  // % time to alert [sec]
  real_T TTA;

  // % time to exclude [sec]
  real_T TTE;

  // % max availeble satellites
  real_T maxNumMeas;

  // % number of variables
  // % GPS/Galileo only, the value is 4: x, y, z, cdtu in ECEF
  // % GPS&Galileo mixed, the value is 5: x, y, z, cdtu_gps, cdtu_galileo
  real_T numVar;

  // % max number of faults, which are allowed to be identified once,
  // % set it as 1, if a pure iterative identifacation is required
  // % set it as 40/RAIM_initialise_parameters.maxNumMeas, if a pure parallel process is required 
  real_T maxNumToIdentifyOnce;

  // % =1, online calculation, regarding elevation angle
  // % =2, all standard deviation equals 2
  real_T VarianceMode;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_parameters_integrity_t_
#define DEFINED_TYPEDEF_FOR_parameters_integrity_t_

struct parameters_integrity_t
{
  parameters_raim_t raim_parameter;
  boolean_T enable_integrity;
  boolean_T enable_GNSS_exclusion;
  boolean_T enable_IMU_exclusion;
  boolean_T enable_DVL_exclusion;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_LeastSquareSolution_
#define DEFINED_TYPEDEF_FOR_LeastSquareSolution_

struct LeastSquareSolution
{
  real_T user_position_llh[3];
  real_T user_velocity_ned[3];
  real_T receiver_clock_bias;
  real_T receiver_clock_drift;
  boolean_T solution_available;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_GNSS_Measurement_
#define DEFINED_TYPEDEF_FOR_GNSS_Measurement_

struct GNSS_Measurement
{
  real_T time_receive;

  // ECEF coordinate system
  real_T satellite_position[120];

  // ECEF coordinate system
  real_T satellite_velocity[120];

  // the PRN satellite identifier
  uint16_T PRN[40];
  real_T pseudorange[40];
  real_T pseudorange_raw[40];
  real_T pseudorange_satclk_corrected[40];
  real_T deltarange[40];
  real_T deltarange_raw[40];
  real_T deltarange_satclk_corrected[40];
  real_T variance_pseudorange[40];
  real_T variance_pseudorange_measured[40];
  real_T variance_deltarange[40];
  real_T carrierphase[40];
  real_T carrierphase_raw[40];
  real_T carrierphase_satclk_corrected[40];
  real_T variance_carrierphase_measured[40];
  real32_T locktime[40];
  real_T CN0[40];
  real_T base_position[3];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_GNSSMeasurementFixed_
#define DEFINED_TYPEDEF_FOR_GNSSMeasurementFixed_

struct GNSSMeasurementFixed
{
  real_T time_receive;
  real_T satellite_position[120];
  real_T satellite_velocity[120];
  uint16_T PRN[40];
  real_T pseudorange[40];
  real_T pseudorange_raw[40];
  real_T pseudorange_satclk_corrected[40];
  real_T deltarange[40];
  real_T deltarange_raw[40];
  real_T deltarange_satclk_corrected[40];
  real_T variance_pseudorange[40];
  real_T variance_pseudorange_measured[40];
  real_T variance_deltarange[40];
  real_T carrierphase[40];
  real_T carrierphase_raw[40];
  real_T carrierphase_satclk_corrected[40];
  real_T variance_carrierphase_measured[40];
  real32_T locktime[40];
  real_T CN0[40];
  real_T base_position[3];
  real_T elevation_angle[40];
  real_T azimuth_angle[40];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_gnssops_navigation_data_
#define DEFINED_TYPEDEF_FOR_gnssops_navigation_data_

struct gnssops_navigation_data
{
  real_T TOW[37];
  real_T WNc[37];
  real_T SVID[37];
  real_T T_gd[37];
  real_T T_oc[37];
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
  real_T T_oe[37];
  real_T C_ic[37];
  real_T OMEGA_0[37];
  real_T C_is[37];
  real_T I_0[37];
  real_T C_rc[37];
  real_T omega[37];
  real_T OMEGADOT[37];
  real_T IDOT[37];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_GNSS_Measurement_size_
#define DEFINED_TYPEDEF_FOR_GNSS_Measurement_size_

struct GNSS_Measurement_size
{
  int32_T satellite_position[2];
  int32_T satellite_velocity[2];
  int32_T PRN;
  int32_T pseudorange;
  int32_T pseudorange_raw;
  int32_T pseudorange_satclk_corrected;
  int32_T deltarange;
  int32_T deltarange_raw;
  int32_T deltarange_satclk_corrected;
  int32_T variance_pseudorange;
  int32_T variance_pseudorange_measured;
  int32_T variance_deltarange;
  int32_T carrierphase;
  int32_T carrierphase_raw;
  int32_T carrierphase_satclk_corrected;
  int32_T variance_carrierphase_measured;
  int32_T locktime;
  int32_T CN0;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_gnssops_navigation_data_size_
#define DEFINED_TYPEDEF_FOR_gnssops_navigation_data_size_

struct gnssops_navigation_data_size
{
  int32_T TOW;
  int32_T WNc;
  int32_T SVID;
  int32_T T_gd;
  int32_T T_oc;
  int32_T A_f2;
  int32_T A_f1;
  int32_T A_f0;
  int32_T C_rs;
  int32_T DELTA_N;
  int32_T M_0;
  int32_T C_uc;
  int32_T E;
  int32_T C_us;
  int32_T SQRT_A;
  int32_T T_oe;
  int32_T C_ic;
  int32_T OMEGA_0;
  int32_T C_is;
  int32_T I_0;
  int32_T C_rc;
  int32_T omega;
  int32_T OMEGADOT;
  int32_T IDOT;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_cMSvRbwER0TJ6P1ff1MrvF_
#define DEFINED_TYPEDEF_FOR_struct_cMSvRbwER0TJ6P1ff1MrvF_

struct struct_cMSvRbwER0TJ6P1ff1MrvF
{
  real_T max_number_of_satellites_in_view;
};

#endif

#ifndef struct_emxArray_real_T_40_GNSSPrePro_T
#define struct_emxArray_real_T_40_GNSSPrePro_T

struct emxArray_real_T_40_GNSSPrePro_T
{
  real_T data[40];
  int32_T size;
};

#endif                                // struct_emxArray_real_T_40_GNSSPrePro_T

#ifndef struct_emxArray_uint16_T_37_GNSSPreP_T
#define struct_emxArray_uint16_T_37_GNSSPreP_T

struct emxArray_uint16_T_37_GNSSPreP_T
{
  uint16_T data[37];
  int32_T size;
};

#endif                                // struct_emxArray_uint16_T_37_GNSSPreP_T

#ifndef struct_emxArray_real_T_37_GNSSPrePro_T
#define struct_emxArray_real_T_37_GNSSPrePro_T

struct emxArray_real_T_37_GNSSPrePro_T
{
  real_T data[37];
  int32_T size;
};

#endif                                // struct_emxArray_real_T_37_GNSSPrePro_T

// Custom Type definition for MATLAB Function: '<S11>/Simplify and Mask GPS Measurement Bus' 
#ifndef struct_b_gnssops_navigation_data_GNS_T
#define struct_b_gnssops_navigation_data_GNS_T

struct b_gnssops_navigation_data_GNS_T
{
  emxArray_real_T_37_GNSSPrePro_T TOW;
  emxArray_real_T_37_GNSSPrePro_T WNc;
  emxArray_real_T_37_GNSSPrePro_T SVID;
  emxArray_real_T_37_GNSSPrePro_T T_gd;
  emxArray_real_T_37_GNSSPrePro_T T_oc;
  emxArray_real_T_37_GNSSPrePro_T A_f2;
  emxArray_real_T_37_GNSSPrePro_T A_f1;
  emxArray_real_T_37_GNSSPrePro_T A_f0;
  emxArray_real_T_37_GNSSPrePro_T C_rs;
  emxArray_real_T_37_GNSSPrePro_T DELTA_N;
  emxArray_real_T_37_GNSSPrePro_T M_0;
  emxArray_real_T_37_GNSSPrePro_T C_uc;
  emxArray_real_T_37_GNSSPrePro_T E;
  emxArray_real_T_37_GNSSPrePro_T C_us;
  emxArray_real_T_37_GNSSPrePro_T SQRT_A;
  emxArray_real_T_37_GNSSPrePro_T T_oe;
  emxArray_real_T_37_GNSSPrePro_T C_ic;
  emxArray_real_T_37_GNSSPrePro_T OMEGA_0;
  emxArray_real_T_37_GNSSPrePro_T C_is;
  emxArray_real_T_37_GNSSPrePro_T I_0;
  emxArray_real_T_37_GNSSPrePro_T C_rc;
  emxArray_real_T_37_GNSSPrePro_T omega;
  emxArray_real_T_37_GNSSPrePro_T OMEGADOT;
  emxArray_real_T_37_GNSSPrePro_T IDOT;
};

#endif                                // struct_b_gnssops_navigation_data_GNS_T

#ifndef struct_emxArray__gnssops_navigation__T
#define struct_emxArray__gnssops_navigation__T

struct emxArray__gnssops_navigation__T
{
  emxArray_real_T_37_GNSSPrePro_T TOW;
  emxArray_real_T_37_GNSSPrePro_T WNc;
  emxArray_real_T_37_GNSSPrePro_T SVID;
  emxArray_real_T_37_GNSSPrePro_T T_gd;
  emxArray_real_T_37_GNSSPrePro_T T_oc;
  emxArray_real_T_37_GNSSPrePro_T A_f2;
  emxArray_real_T_37_GNSSPrePro_T A_f1;
  emxArray_real_T_37_GNSSPrePro_T A_f0;
  emxArray_real_T_37_GNSSPrePro_T C_rs;
  emxArray_real_T_37_GNSSPrePro_T DELTA_N;
  emxArray_real_T_37_GNSSPrePro_T M_0;
  emxArray_real_T_37_GNSSPrePro_T C_uc;
  emxArray_real_T_37_GNSSPrePro_T E;
  emxArray_real_T_37_GNSSPrePro_T C_us;
  emxArray_real_T_37_GNSSPrePro_T SQRT_A;
  emxArray_real_T_37_GNSSPrePro_T T_oe;
  emxArray_real_T_37_GNSSPrePro_T C_ic;
  emxArray_real_T_37_GNSSPrePro_T OMEGA_0;
  emxArray_real_T_37_GNSSPrePro_T C_is;
  emxArray_real_T_37_GNSSPrePro_T I_0;
  emxArray_real_T_37_GNSSPrePro_T C_rc;
  emxArray_real_T_37_GNSSPrePro_T omega;
  emxArray_real_T_37_GNSSPrePro_T OMEGADOT;
  emxArray_real_T_37_GNSSPrePro_T IDOT;
};

#endif                                // struct_emxArray__gnssops_navigation__T

#ifndef struct_emxArray_real_T_40x3_GNSSPreP_T
#define struct_emxArray_real_T_40x3_GNSSPreP_T

struct emxArray_real_T_40x3_GNSSPreP_T
{
  real_T data[120];
  int32_T size[2];
};

#endif                                // struct_emxArray_real_T_40x3_GNSSPreP_T

#ifndef struct_emxArray_real_T_120x3_GNSSPre_T
#define struct_emxArray_real_T_120x3_GNSSPre_T

struct emxArray_real_T_120x3_GNSSPre_T
{
  real_T data[360];
  int32_T size[2];
};

#endif                                // struct_emxArray_real_T_120x3_GNSSPre_T

#ifndef struct_emxArray_uint16_T_120_GNSSPre_T
#define struct_emxArray_uint16_T_120_GNSSPre_T

struct emxArray_uint16_T_120_GNSSPre_T
{
  uint16_T data[120];
  int32_T size;
};

#endif                                // struct_emxArray_uint16_T_120_GNSSPre_T

#ifndef struct_emxArray_real_T_120_GNSSPrePr_T
#define struct_emxArray_real_T_120_GNSSPrePr_T

struct emxArray_real_T_120_GNSSPrePr_T
{
  real_T data[120];
  int32_T size;
};

#endif                                // struct_emxArray_real_T_120_GNSSPrePr_T

#ifndef struct_emxArray_real32_T_120_GNSSPre_T
#define struct_emxArray_real32_T_120_GNSSPre_T

struct emxArray_real32_T_120_GNSSPre_T
{
  real32_T data[120];
  int32_T size;
};

#endif                                // struct_emxArray_real32_T_120_GNSSPre_T

// Custom Type definition for MATLAB Function: '<S3>/Merge GNSS Measurement'
#ifndef struct_s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T
#define struct_s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T

struct s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T
{
  real_T time_receive;
  emxArray_real_T_120x3_GNSSPre_T satellite_position;
  emxArray_real_T_120x3_GNSSPre_T satellite_velocity;
  emxArray_uint16_T_120_GNSSPre_T PRN;
  emxArray_real_T_120_GNSSPrePr_T pseudorange;
  emxArray_real_T_120_GNSSPrePr_T pseudorange_raw;
  emxArray_real_T_120_GNSSPrePr_T pseudorange_satclk_corrected;
  emxArray_real_T_120_GNSSPrePr_T deltarange;
  emxArray_real_T_120_GNSSPrePr_T deltarange_raw;
  emxArray_real_T_120_GNSSPrePr_T deltarange_satclk_corrected;
  emxArray_real_T_120_GNSSPrePr_T variance_pseudorange;
  emxArray_real_T_120_GNSSPrePr_T variance_pseudorange_measured;
  emxArray_real_T_120_GNSSPrePr_T variance_deltarange;
  emxArray_real_T_120_GNSSPrePr_T carrierphase;
  emxArray_real_T_120_GNSSPrePr_T carrierphase_raw;
  emxArray_real_T_120_GNSSPrePr_T carrierphase_satclk_corrected;
  emxArray_real_T_120_GNSSPrePr_T variance_carrierphase_measured;
  emxArray_real32_T_120_GNSSPre_T locktime;
  emxArray_real_T_120_GNSSPrePr_T CN0;
  real_T base_position[3];
};

#endif                                // struct_s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T

#ifndef struct_emxArray_uint16_T_40_GNSSPreP_T
#define struct_emxArray_uint16_T_40_GNSSPreP_T

struct emxArray_uint16_T_40_GNSSPreP_T
{
  uint16_T data[40];
  int32_T size;
};

#endif                                // struct_emxArray_uint16_T_40_GNSSPreP_T

#ifndef struct_emxArray_real32_T_40_GNSSPreP_T
#define struct_emxArray_real32_T_40_GNSSPreP_T

struct emxArray_real32_T_40_GNSSPreP_T
{
  real32_T data[40];
  int32_T size;
};

#endif                                // struct_emxArray_real32_T_40_GNSSPreP_T

#ifndef struct_emxArray__GNSS_Measurement_GN_T
#define struct_emxArray__GNSS_Measurement_GN_T

struct emxArray__GNSS_Measurement_GN_T
{
  real_T time_receive;
  emxArray_real_T_40x3_GNSSPreP_T satellite_position;
  emxArray_real_T_40x3_GNSSPreP_T satellite_velocity;
  emxArray_uint16_T_40_GNSSPreP_T PRN;
  emxArray_real_T_40_GNSSPrePro_T pseudorange;
  emxArray_real_T_40_GNSSPrePro_T pseudorange_raw;
  emxArray_real_T_40_GNSSPrePro_T pseudorange_satclk_corrected;
  emxArray_real_T_40_GNSSPrePro_T deltarange;
  emxArray_real_T_40_GNSSPrePro_T deltarange_raw;
  emxArray_real_T_40_GNSSPrePro_T deltarange_satclk_corrected;
  emxArray_real_T_40_GNSSPrePro_T variance_pseudorange;
  emxArray_real_T_40_GNSSPrePro_T variance_pseudorange_measured;
  emxArray_real_T_40_GNSSPrePro_T variance_deltarange;
  emxArray_real_T_40_GNSSPrePro_T carrierphase;
  emxArray_real_T_40_GNSSPrePro_T carrierphase_raw;
  emxArray_real_T_40_GNSSPrePro_T carrierphase_satclk_corrected;
  emxArray_real_T_40_GNSSPrePro_T variance_carrierphase_measured;
  emxArray_real32_T_40_GNSSPreP_T locktime;
  emxArray_real_T_40_GNSSPrePro_T CN0;
  real_T base_position[3];
};

#endif                                // struct_emxArray__GNSS_Measurement_GN_T

#ifndef SS_UINT64
#define SS_UINT64                      41
#endif

#ifndef SS_INT64
#define SS_INT64                       42
#endif

// Parameters for system: '<S11>/GPS L1 Stream'
typedef struct P_GPSsinglefrequencystream_GN_T_ P_GPSsinglefrequencystream_GN_T;

// Parameters for system: '<S12>/Galileo E1 stream'
typedef struct P_Galileosinglefrequencystrea_T_ P_Galileosinglefrequencystrea_T;

// Parameters (default storage)
typedef struct P_GNSSPreProcessingSingleAnte_T_ P_GNSSPreProcessingSingleAnte_T;

// Forward declaration for rtModel
typedef struct tag_RTM_GNSSPreProcessingSing_T RT_MODEL_GNSSPreProcessingSin_T;

#endif                    // RTW_HEADER_GNSSPreProcessingSingleAntenna_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
