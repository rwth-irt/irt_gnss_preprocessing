//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GalileoFrequencyStream.cpp
//
// Code generated for Simulink model 'GNSSPreProcessingDualAntenna'.
//
// Model version                  : 3.8
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Tue Jan 24 11:01:39 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "GNSSPreProcessingDualAntenna.h"
#include "rtwtypes.h"
#include "GNSSPreProcessingDualAntenna_types.h"
#include "GalileoFrequencyStream.h"

//
// System initialize for enable system:
//    '<S18>/Galileo E1 stream'
//    '<S18>/Galileo E5 stream'
//    '<S18>/Galileo E5a stream'
//    '<S18>/Galileo E5b stream'
//    '<S145>/Galileo E1 stream'
//    '<S145>/Galileo E5 stream'
//    '<S145>/Galileo E5a stream'
//    '<S145>/Galileo E5b stream'
//
void GNSSPreProcessingDualAntenna::Galileosinglefrequencystre_Init(B_Galileosinglefrequencystrea_T *localB,
    P_Galileosinglefrequencystrea_T *localP)
{
    // SystemInitialize for SignalConversion generated from: '<S71>/TOW' incorporates:
    //   Outport: '<S71>/TOW_Out'

    localB->TOW = localP->TOW_Out_Y0;

    // SystemInitialize for SignalConversion generated from: '<S71>/basePos' incorporates:
    //   Outport: '<S71>/basePosition'

    localB->basePosition[0] = localP->basePosition_Y0;
    localB->basePosition[1] = localP->basePosition_Y0;
    localB->basePosition[2] = localP->basePosition_Y0;
}

//
// Output and update for enable system:
//    '<S18>/Galileo E1 stream'
//    '<S18>/Galileo E5 stream'
//    '<S18>/Galileo E5a stream'
//    '<S18>/Galileo E5b stream'
//    '<S145>/Galileo E1 stream'
//    '<S145>/Galileo E5 stream'
//    '<S145>/Galileo E5a stream'
//    '<S145>/Galileo E5b stream'
//
void GNSSPreProcessingDualAntenna::GN_Galileosinglefrequencystream(boolean_T rtu_Enable, boolean_T
    rtu_E5_basedProcessing, real_T rtu_TOW, const uint16_T rtu_SVID[40], const int32_T *rtu_SVID_DIMS1, const
    gnssops_navigation_data *rtu_GAL_NavigationData_Bus, const gnssops_navigation_data_size
    *rtu_GAL_NavigationData_Bu_DIMS1, const real_T rtu_pseudorange[40], const int32_T *rtu_pseudorange_DIMS1, const
    real_T rtu_deltarange[40], const int32_T *rtu_deltarange_DIMS1, const real_T rtu_CN0[40], const int32_T
    *rtu_CN0_DIMS1, const real_T rtu_userPos_LLH[3], const real_T rtu_carrierPhase[40], const int32_T
    *rtu_carrierPhase_DIMS1, const real32_T rtu_locktime[40], const int32_T *rtu_locktime_DIMS1, const real_T
    rtu_basePos[3], boolean_T rtu_enable_SatPosVelCalc, boolean_T rtu_use_measured_variance, const real_T
    rtu_measured_pr_sigma[40], const int32_T *rtu_measured_pr_sigma_DIMS1, const real_T rtu_measured_cp_sigma[40], const
    int32_T *rtu_measured_cp_sigma_DIMS1, real_T rtp_enable_SatClockCorr, B_Galileosinglefrequencystrea_T *localB,
    DW_Galileosinglefrequencystre_T *localDW, P_Galileosinglefrequencystrea_T *localP)
{
    // Outputs for Enabled SubSystem: '<S18>/Galileo E1 stream' incorporates:
    //   EnablePort: '<S71>/Enable'

    if (rtu_Enable)
    {
        // SignalConversion generated from: '<S71>/TOW'
        localB->TOW = rtu_TOW;

        // MATLAB Function: '<S81>/Calculate Satellite Clock Correction' incorporates:
        //   Constant: '<S71>/delta_t_sv_EGNOS_dummy'
        //   Constant: '<S71>/enableSatClockCorr'

        CalculateSatelliteClockCorrecti(localB->TOW, rtu_GAL_NavigationData_Bus, (gnssops_navigation_data_size *)
            rtu_GAL_NavigationData_Bu_DIMS1, rtu_pseudorange, (int32_T *)rtu_pseudorange_DIMS1, rtp_enable_SatClockCorr,
            localP->delta_t_sv_EGNOS_dummy_Value, &localB->sf_CalculateSatelliteClockCorre,
            &localDW->sf_CalculateSatelliteClockCorre);

        // MATLAB Function: '<S71>/Enable Satellite Position and Velocity Calculation' incorporates:
        //   Constant: '<S71>/galileoStreamInUse'

        if ((localP->galileoStreamInUse_Value == 4.0) && rtu_E5_basedProcessing && rtu_enable_SatPosVelCalc)
        {
            localB->i = 1;
        }
        else
        {
            localB->i = ((localP->galileoStreamInUse_Value == 1.0) && (!rtu_E5_basedProcessing) &&
                         rtu_enable_SatPosVelCalc);
        }

        // MATLAB Function: '<S81>/Calculate Satellite Position and Velocity' incorporates:
        //   Constant: '<S71>/delta_satPosECEF_EGNOS_dummy'
        //   MATLAB Function: '<S71>/Enable Satellite Position and Velocity Calculation'

        CalculateSatellitePositionandVe(static_cast<real_T>(localB->i), rtu_userPos_LLH, rtu_GAL_NavigationData_Bus,
            (gnssops_navigation_data_size *)rtu_GAL_NavigationData_Bu_DIMS1,
            localB->sf_CalculateSatelliteClockCorre.timeEmissionCorrected,
            &localDW->sf_CalculateSatelliteClockCorre.SFunction_DIMS2, localP->delta_satPosECEF_EGNOS_dummy_Va,
            &localB->sf_CalculateSatellitePositionan, &localDW->sf_CalculateSatellitePositionan);

        // MATLAB Function: '<S81>/Time Correction Carrierphase' incorporates:
        //   Constant: '<S71>/galileoStreamInUse'

        GNSS_TimeCorrectionCarrierphase(localB->sf_CalculateSatelliteClockCorre.deltaTimeSV,
            &localDW->sf_CalculateSatelliteClockCorre.SFunction_DIMS3, rtu_carrierPhase, (int32_T *)
            rtu_carrierPhase_DIMS1, localP->galileoStreamInUse_Value, &localB->sf_TimeCorrectionCarrierphase,
            &localDW->sf_TimeCorrectionCarrierphase);

        // MATLAB Function: '<S81>/Time Correction Deltarange'
        GNSSPr_TimeCorrectionDeltarange(localB->sf_CalculateSatelliteClockCorre.drTimeCorr,
            &localDW->sf_CalculateSatelliteClockCorre.SFunction_DIMS4, rtu_deltarange, (int32_T *)rtu_deltarange_DIMS1,
            &localB->sf_TimeCorrectionDeltarange, &localDW->sf_TimeCorrectionDeltarange);

        // MATLAB Function: '<S81>/Time Correction Pseudorange'
        GNSSP_TimeCorrectionPseudorange(localB->sf_CalculateSatelliteClockCorre.deltaTimeSV,
            &localDW->sf_CalculateSatelliteClockCorre.SFunction_DIMS3, rtu_pseudorange, (int32_T *)rtu_pseudorange_DIMS1,
            &localB->sf_TimeCorrectionPseudorange, &localDW->sf_TimeCorrectionPseudorange);

        // SignalConversion generated from: '<S71>/SVID'
        localDW->SVID_DIMS1 = *rtu_SVID_DIMS1;
        for (localB->i = 0; localB->i < *rtu_SVID_DIMS1; localB->i++)
        {
            localB->PRN[localB->i] = rtu_SVID[localB->i];
        }

        // SignalConversion generated from: '<S71>/CN0'
        localDW->CN0_DIMS1 = *rtu_CN0_DIMS1;
        for (localB->i = 0; localB->i < *rtu_CN0_DIMS1; localB->i++)
        {
            localB->CN0[localB->i] = rtu_CN0[localB->i];
        }

        // SignalConversion generated from: '<S71>/measured_pr_sigma'
        localDW->measured_pr_sigma_DIMS1 = *rtu_measured_pr_sigma_DIMS1;
        for (localB->i = 0; localB->i < *rtu_measured_pr_sigma_DIMS1; localB->i++)
        {
            localB->measured_pr_sigma[localB->i] = rtu_measured_pr_sigma[localB->i];
        }

        // SignalConversion generated from: '<S71>/measured_cp_sigma'
        localDW->measured_cp_sigma_DIMS1 = *rtu_measured_cp_sigma_DIMS1;
        for (localB->i = 0; localB->i < *rtu_measured_cp_sigma_DIMS1; localB->i++)
        {
            localB->measured_cp_sigma[localB->i] = rtu_measured_cp_sigma[localB->i];
        }

        // MATLAB Function: '<S71>/Signal Noise Variance'
        GNSSPreProc_SignalNoiseVariance(localB->CN0, &localDW->CN0_DIMS1, rtu_use_measured_variance,
            localB->measured_pr_sigma, &localDW->measured_pr_sigma_DIMS1, localB->measured_cp_sigma,
            &localDW->measured_cp_sigma_DIMS1, &localB->sf_SignalNoiseVariance, &localDW->sf_SignalNoiseVariance);

        // SignalConversion generated from: '<S71>/locktime'
        localDW->locktime_DIMS1 = *rtu_locktime_DIMS1;
        for (localB->i = 0; localB->i < *rtu_locktime_DIMS1; localB->i++)
        {
            localB->Locktime[localB->i] = rtu_locktime[localB->i];
        }

        // SignalConversion generated from: '<S71>/basePos'
        localB->basePosition[0] = rtu_basePos[0];
        localB->basePosition[1] = rtu_basePos[1];
        localB->basePosition[2] = rtu_basePos[2];
    }

    // End of Outputs for SubSystem: '<S18>/Galileo E1 stream'
}

//
// File trailer for generated code.
//
// [EOF]
//
