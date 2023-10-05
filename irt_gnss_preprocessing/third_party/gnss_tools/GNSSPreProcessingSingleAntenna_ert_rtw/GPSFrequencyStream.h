//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GPSFrequencyStream.h
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
#ifndef RTW_HEADER_GPSFrequencyStream_h_
#define RTW_HEADER_GPSFrequencyStream_h_
#include "rtwtypes.h"
#include "rt_sys_GPSFrequencyStream_13.h"
#include "GNSSP_TimeCorrectionPseudorange.h"
#include "GNSSPr_TimeCorrectionDeltarange.h"
#include "GNSS_TimeCorrectionCarrierphase.h"
#include "CalculateSatellitePositionandVe.h"
#include "CalculateSatelliteClockCorrecti.h"
#include "GNSSPreProcessingSingleAntenna_types.h"

// Block signals for system '<S11>/GPS L1 Stream'
struct B_GPSsinglefrequencystream_GN_T {
  real_T timeOfWeekIn;                 // '<S18>/timeOfWeekIn'
  real_T carrierToNoiseRatio[40];      // '<S18>/carrierToNoiseRatio '
  real_T pr_sigma[40];                 // '<S18>/pr_sigma '
  real_T cp_sigma[40];                 // '<S18>/cp_sigma '
  real_T base_position[3];             // '<S18>/base_position'
  real32_T Locktime[40];               // '<S18>/locktime'
  uint16_T PRN[40];                    // '<S18>/SVID'
  B_SignalNoiseVariance_GNSSPre_T sf_SignalNoiseVariance;// '<S18>/Signal Noise Variance' 
  B_TimeCorrectionPseudorange_G_T sf_TimeCorrectionPseudorange;// '<S26>/Time Correction Pseudorange' 
  B_TimeCorrectionDeltarange_GN_T sf_TimeCorrectionDeltarange;// '<S26>/Time Correction Deltarange' 
  B_TimeCorrectionCarrierphase__T sf_TimeCorrectionCarrierphase;// '<S26>/Time Correction Carrierphase' 
  B_CalculateSatellitePositiona_T sf_CalculateSatellitePositionan;
                           // '<S26>/Calculate Satellite Position and Velocity'
  B_CalculateSatelliteClockCorr_T sf_CalculateSatelliteClockCorre;
                                // '<S26>/Calculate Satellite Clock Correction'
};

// Block states (default storage) for system '<S11>/GPS L1 Stream'
struct DW_GPSsinglefrequencystream_G_T {
  int32_T SVID_DIMS1;                  // '<S18>/SVID'
  int32_T carrierToNoiseRatio_DIMS1;   // '<S18>/carrierToNoiseRatio '
  int32_T pr_sigma_DIMS1;              // '<S18>/pr_sigma '
  int32_T cp_sigma_DIMS1;              // '<S18>/cp_sigma '
  int32_T locktime_DIMS1;              // '<S18>/locktime'
  DW_SignalNoiseVariance_GNSSPr_T sf_SignalNoiseVariance;// '<S18>/Signal Noise Variance' 
  DW_TimeCorrectionPseudorange__T sf_TimeCorrectionPseudorange;// '<S26>/Time Correction Pseudorange' 
  DW_TimeCorrectionDeltarange_G_T sf_TimeCorrectionDeltarange;// '<S26>/Time Correction Deltarange' 
  DW_TimeCorrectionCarrierphase_T sf_TimeCorrectionCarrierphase;// '<S26>/Time Correction Carrierphase' 
  DW_CalculateSatellitePosition_T sf_CalculateSatellitePositionan;
                           // '<S26>/Calculate Satellite Position and Velocity'
  DW_CalculateSatelliteClockCor_T sf_CalculateSatelliteClockCorre;
                                // '<S26>/Calculate Satellite Clock Correction'
};

// Parameters for system: '<S11>/GPS L1 Stream'
struct P_GPSsinglefrequencystream_GN_T_ {
  real_T timeOfWeekOut_Y0;             // Computed Parameter: timeOfWeekOut_Y0
                                          //  Referenced by: '<S18>/timeOfWeekOut'

  real_T basePosition_Y0;              // Computed Parameter: basePosition_Y0
                                          //  Referenced by: '<S18>/basePosition'

  real_T delta_satPosECEF_EGNOS_dummy_Va[330];// Expression: zeros(110,3)
                                                 //  Referenced by: '<S18>/delta_satPosECEF_EGNOS_dummy'

  real_T gpsStreamInUse_Value;         // Expression: signal_in_use
                                          //  Referenced by: '<S18>/gpsStreamInUse'

  real_T delta_t_sv_EGNOS_dummy_Value[110];// Expression: zeros(110,1)
                                              //  Referenced by: '<S18>/delta_t_sv_EGNOS_dummy'

};

#endif                                 // RTW_HEADER_GPSFrequencyStream_h_

//
// File trailer for generated code.
//
// [EOF]
//
