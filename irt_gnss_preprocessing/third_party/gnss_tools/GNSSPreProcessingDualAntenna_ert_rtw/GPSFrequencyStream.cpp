//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GPSFrequencyStream.cpp
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
#include "GPSFrequencyStream.h"

//
// System initialize for enable system:
//    '<S17>/GPS L1 Stream'
//    '<S17>/GPS L2C Stream'
//    '<S17>/GPS L5 Stream'
//    '<S144>/GPS L1 Stream'
//    '<S144>/GPS L2C Stream'
//    '<S144>/GPS L5 Stream'
//
void GNSSPreProcessingDualAntenna::G_GPSsinglefrequencystream_Init(B_GPSsinglefrequencystream_GN_T *localB,
    P_GPSsinglefrequencystream_GN_T *localP)
{
    // SystemInitialize for SignalConversion generated from: '<S24>/timeOfWeekIn' incorporates:
    //   Outport: '<S24>/timeOfWeekOut'

    localB->timeOfWeekIn = localP->timeOfWeekOut_Y0;

    // SystemInitialize for SignalConversion generated from: '<S24>/base_position' incorporates:
    //   Outport: '<S24>/basePosition'

    localB->base_position[0] = localP->basePosition_Y0;
    localB->base_position[1] = localP->basePosition_Y0;
    localB->base_position[2] = localP->basePosition_Y0;
}

//
// Output and update for enable system:
//    '<S17>/GPS L1 Stream'
//    '<S17>/GPS L2C Stream'
//    '<S17>/GPS L5 Stream'
//    '<S144>/GPS L1 Stream'
//    '<S144>/GPS L2C Stream'
//    '<S144>/GPS L5 Stream'
//
void GNSSPreProcessingDualAntenna::GNSSPr_GPSsinglefrequencystream(boolean_T rtu_Enable, real_T rtu_timeOfWeekIn, const
    uint16_T rtu_SVID[40], const int32_T *rtu_SVID_DIMS1, const gnssops_navigation_data *rtu_GpsNavBus, const
    gnssops_navigation_data_size *rtu_GpsNavBus_DIMS1, const real_T rtu_pseudorange[40], const int32_T
    *rtu_pseudorange_DIMS1, const real_T rtu_deltarange[40], const int32_T *rtu_deltarange_DIMS1, const real_T
    rtu_carrierToNoiseRatio[40], const int32_T *rtu_carrierToNoiseRatio_DIMS1, const real_T rtu_userPosLlh[3], const
    real_T rtu_carrierphase[40], const int32_T *rtu_carrierphase_DIMS1, const real32_T rtu_locktime[40], const int32_T
    *rtu_locktime_DIMS1, const real_T rtu_base_position[3], boolean_T rtu_enable_SatPosVelCalc, boolean_T
    rtu_use_measured_cariance, const real_T rtu_pr_sigma[40], const int32_T *rtu_pr_sigma_DIMS1, const real_T
    rtu_cp_sigma[40], const int32_T *rtu_cp_sigma_DIMS1, real_T rtp_enable_SatClockCorr, B_GPSsinglefrequencystream_GN_T
    *localB, DW_GPSsinglefrequencystream_G_T *localDW, P_GPSsinglefrequencystream_GN_T *localP)
{
    // Outputs for Enabled SubSystem: '<S17>/GPS L1 Stream' incorporates:
    //   EnablePort: '<S24>/Enable'

    if (rtu_Enable)
    {
        // SignalConversion generated from: '<S24>/timeOfWeekIn'
        localB->timeOfWeekIn = rtu_timeOfWeekIn;

        // MATLAB Function: '<S32>/Calculate Satellite Clock Correction' incorporates:
        //   Constant: '<S24>/delta_t_sv_EGNOS_dummy'
        //   Constant: '<S24>/enableSatClockCorr'

        CalculateSatelliteClockCorrecti(localB->timeOfWeekIn, rtu_GpsNavBus, (gnssops_navigation_data_size *)
            rtu_GpsNavBus_DIMS1, rtu_pseudorange, (int32_T *)rtu_pseudorange_DIMS1, rtp_enable_SatClockCorr,
            localP->delta_t_sv_EGNOS_dummy_Value, &localB->sf_CalculateSatelliteClockCorre,
            &localDW->sf_CalculateSatelliteClockCorre);

        // MATLAB Function: '<S32>/Calculate Satellite Position and Velocity' incorporates:
        //   Constant: '<S24>/delta_satPosECEF_EGNOS_dummy'
        //   Constant: '<S24>/gpsStreamInUse'
        //   MATLAB Function: '<S24>/Enable Satellite Position and Velocity Calculation'

        CalculateSatellitePositionandVe(static_cast<real_T>((localP->gpsStreamInUse_Value == 1.0) &&
            rtu_enable_SatPosVelCalc), rtu_userPosLlh, rtu_GpsNavBus, (gnssops_navigation_data_size *)
            rtu_GpsNavBus_DIMS1, localB->sf_CalculateSatelliteClockCorre.timeEmissionCorrected,
            &localDW->sf_CalculateSatelliteClockCorre.SFunction_DIMS2, localP->delta_satPosECEF_EGNOS_dummy_Va,
            &localB->sf_CalculateSatellitePositionan, &localDW->sf_CalculateSatellitePositionan);

        // MATLAB Function: '<S32>/Time Correction Carrierphase' incorporates:
        //   Constant: '<S24>/gpsStreamInUse'

        GNSS_TimeCorrectionCarrierphase(localB->sf_CalculateSatelliteClockCorre.deltaTimeSV,
            &localDW->sf_CalculateSatelliteClockCorre.SFunction_DIMS3, rtu_carrierphase, (int32_T *)
            rtu_carrierphase_DIMS1, localP->gpsStreamInUse_Value, &localB->sf_TimeCorrectionCarrierphase,
            &localDW->sf_TimeCorrectionCarrierphase);

        // MATLAB Function: '<S32>/Time Correction Deltarange'
        GNSSPr_TimeCorrectionDeltarange(localB->sf_CalculateSatelliteClockCorre.drTimeCorr,
            &localDW->sf_CalculateSatelliteClockCorre.SFunction_DIMS4, rtu_deltarange, (int32_T *)rtu_deltarange_DIMS1,
            &localB->sf_TimeCorrectionDeltarange, &localDW->sf_TimeCorrectionDeltarange);

        // MATLAB Function: '<S32>/Time Correction Pseudorange'
        GNSSP_TimeCorrectionPseudorange(localB->sf_CalculateSatelliteClockCorre.deltaTimeSV,
            &localDW->sf_CalculateSatelliteClockCorre.SFunction_DIMS3, rtu_pseudorange, (int32_T *)rtu_pseudorange_DIMS1,
            &localB->sf_TimeCorrectionPseudorange, &localDW->sf_TimeCorrectionPseudorange);

        // SignalConversion generated from: '<S24>/SVID'
        localDW->SVID_DIMS1 = *rtu_SVID_DIMS1;
        for (localB->i = 0; localB->i < *rtu_SVID_DIMS1; localB->i++)
        {
            localB->PRN[localB->i] = rtu_SVID[localB->i];
        }

        // SignalConversion generated from: '<S24>/carrierToNoiseRatio '
        localDW->carrierToNoiseRatio_DIMS1 = *rtu_carrierToNoiseRatio_DIMS1;
        for (localB->i = 0; localB->i < *rtu_carrierToNoiseRatio_DIMS1; localB->i++)
        {
            localB->carrierToNoiseRatio[localB->i] = rtu_carrierToNoiseRatio[localB->i];
        }

        // SignalConversion generated from: '<S24>/pr_sigma '
        localDW->pr_sigma_DIMS1 = *rtu_pr_sigma_DIMS1;
        for (localB->i = 0; localB->i < *rtu_pr_sigma_DIMS1; localB->i++)
        {
            localB->pr_sigma[localB->i] = rtu_pr_sigma[localB->i];
        }

        // SignalConversion generated from: '<S24>/cp_sigma '
        localDW->cp_sigma_DIMS1 = *rtu_cp_sigma_DIMS1;
        for (localB->i = 0; localB->i < *rtu_cp_sigma_DIMS1; localB->i++)
        {
            localB->cp_sigma[localB->i] = rtu_cp_sigma[localB->i];
        }

        // MATLAB Function: '<S24>/Signal Noise Variance'
        GNSSPreProc_SignalNoiseVariance(localB->carrierToNoiseRatio, &localDW->carrierToNoiseRatio_DIMS1,
            rtu_use_measured_cariance, localB->pr_sigma, &localDW->pr_sigma_DIMS1, localB->cp_sigma,
            &localDW->cp_sigma_DIMS1, &localB->sf_SignalNoiseVariance, &localDW->sf_SignalNoiseVariance);

        // SignalConversion generated from: '<S24>/locktime'
        localDW->locktime_DIMS1 = *rtu_locktime_DIMS1;
        for (localB->i = 0; localB->i < *rtu_locktime_DIMS1; localB->i++)
        {
            localB->Locktime[localB->i] = rtu_locktime[localB->i];
        }

        // SignalConversion generated from: '<S24>/base_position'
        localB->base_position[0] = rtu_base_position[0];
        localB->base_position[1] = rtu_base_position[1];
        localB->base_position[2] = rtu_base_position[2];
    }

    // End of Outputs for SubSystem: '<S17>/GPS L1 Stream'
}

//
// File trailer for generated code.
//
// [EOF]
//
