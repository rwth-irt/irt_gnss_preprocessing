//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GalileoFrequencyStream.h
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
#ifndef RTW_HEADER_GalileoFrequencyStream_h_
#define RTW_HEADER_GalileoFrequencyStream_h_
#include "rtwtypes.h"
#include "rt_sys_GPSFrequencyStream_13.h"
#include "GNSSP_TimeCorrectionPseudorange.h"
#include "GNSSPr_TimeCorrectionDeltarange.h"
#include "GNSS_TimeCorrectionCarrierphase.h"
#include "CalculateSatellitePositionandVe.h"
#include "CalculateSatelliteClockCorrecti.h"
#include "GNSSPreProcessingSingleAntenna_types.h"

// Block signals for system '<S12>/Galileo E1 stream'
struct B_Galileosinglefrequencystrea_T {
  real_T TOW;                          // '<S65>/TOW'
  real_T CN0[40];                      // '<S65>/CN0'
  real_T measured_pr_sigma[40];        // '<S65>/measured_pr_sigma'
  real_T measured_cp_sigma[40];        // '<S65>/measured_cp_sigma'
  real_T basePosition[3];              // '<S65>/basePos'
  real32_T Locktime[40];               // '<S65>/locktime'
  uint16_T PRN[40];                    // '<S65>/SVID'
  B_SignalNoiseVariance_GNSSPre_T sf_SignalNoiseVariance;// '<S65>/Signal Noise Variance' 
  B_TimeCorrectionPseudorange_G_T sf_TimeCorrectionPseudorange;// '<S75>/Time Correction Pseudorange' 
  B_TimeCorrectionDeltarange_GN_T sf_TimeCorrectionDeltarange;// '<S75>/Time Correction Deltarange' 
  B_TimeCorrectionCarrierphase__T sf_TimeCorrectionCarrierphase;// '<S75>/Time Correction Carrierphase' 
  B_CalculateSatellitePositiona_T sf_CalculateSatellitePositionan;
                           // '<S75>/Calculate Satellite Position and Velocity'
  B_CalculateSatelliteClockCorr_T sf_CalculateSatelliteClockCorre;
                                // '<S75>/Calculate Satellite Clock Correction'
};

// Block states (default storage) for system '<S12>/Galileo E1 stream'
struct DW_Galileosinglefrequencystre_T {
  int32_T SVID_DIMS1;                  // '<S65>/SVID'
  int32_T CN0_DIMS1;                   // '<S65>/CN0'
  int32_T measured_pr_sigma_DIMS1;     // '<S65>/measured_pr_sigma'
  int32_T measured_cp_sigma_DIMS1;     // '<S65>/measured_cp_sigma'
  int32_T locktime_DIMS1;              // '<S65>/locktime'
  DW_SignalNoiseVariance_GNSSPr_T sf_SignalNoiseVariance;// '<S65>/Signal Noise Variance' 
  DW_TimeCorrectionPseudorange__T sf_TimeCorrectionPseudorange;// '<S75>/Time Correction Pseudorange' 
  DW_TimeCorrectionDeltarange_G_T sf_TimeCorrectionDeltarange;// '<S75>/Time Correction Deltarange' 
  DW_TimeCorrectionCarrierphase_T sf_TimeCorrectionCarrierphase;// '<S75>/Time Correction Carrierphase' 
  DW_CalculateSatellitePosition_T sf_CalculateSatellitePositionan;
                           // '<S75>/Calculate Satellite Position and Velocity'
  DW_CalculateSatelliteClockCor_T sf_CalculateSatelliteClockCorre;
                                // '<S75>/Calculate Satellite Clock Correction'
};

// Parameters for system: '<S12>/Galileo E1 stream'
struct P_Galileosinglefrequencystrea_T_ {
  real_T TOW_Out_Y0;                   // Computed Parameter: TOW_Out_Y0
                                          //  Referenced by: '<S65>/TOW_Out'

  real_T basePosition_Y0;              // Computed Parameter: basePosition_Y0
                                          //  Referenced by: '<S65>/basePosition'

  real_T delta_satPosECEF_EGNOS_dummy_Va[330];// Expression: zeros(110,3)
                                                 //  Referenced by: '<S65>/delta_satPosECEF_EGNOS_dummy'

  real_T galileoStreamInUse_Value;     // Expression: signal_in_use
                                          //  Referenced by: '<S65>/galileoStreamInUse'

  real_T delta_t_sv_EGNOS_dummy_Value[110];// Expression: zeros(110,1)
                                              //  Referenced by: '<S65>/delta_t_sv_EGNOS_dummy'

};

#endif                                 // RTW_HEADER_GalileoFrequencyStream_h_

//
// File trailer for generated code.
//
// [EOF]
//
