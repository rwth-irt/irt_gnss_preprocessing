//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ApplyDifferentialCorrectionMask.cpp
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
#include "GNSSPreProcessingDualAntenna_types.h"
#include "rtwtypes.h"
#include "GNSSPreProcessingDualAntenna.h"
#include <cstring>
#include "ApplyDifferentialCorrectionMask.h"

// Function for MATLAB Function: '<S61>/Apply Differential Correction Mask1'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingD_do_vectors_e(const uint16_T a_data[], const int32_T *a_size, const
    uint16_T b_data[], const int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size,
    int32_T ib_data[], int32_T *ib_size)
{
    int32_T iafirst;
    int32_T ialast;
    int32_T ibfirst;
    int32_T iblast;
    int32_T nc;
    int32_T ncmax;
    if (*a_size <= *b_size)
    {
        ncmax = *a_size;
    }
    else
    {
        ncmax = *b_size;
    }

    *c_size = ncmax;
    *ia_size = ncmax;
    *ib_size = ncmax;
    nc = 0;
    iafirst = 0;
    ialast = 1;
    ibfirst = 0;
    iblast = 1;
    while ((ialast <= *a_size) && (iblast <= *b_size))
    {
        int32_T b_ialast;
        int32_T b_iblast;
        uint16_T ak;
        uint16_T bk;
        b_ialast = ialast;
        ak = a_data[ialast - 1];
        while ((b_ialast < *a_size) && (a_data[b_ialast] == ak))
        {
            b_ialast++;
        }

        ialast = b_ialast;
        b_iblast = iblast;
        bk = b_data[iblast - 1];
        while ((b_iblast < *b_size) && (b_data[b_iblast] == bk))
        {
            b_iblast++;
        }

        iblast = b_iblast;
        if (ak == bk)
        {
            nc++;
            c_data[nc - 1] = ak;
            ia_data[nc - 1] = iafirst + 1;
            ib_data[nc - 1] = ibfirst + 1;
            ialast = b_ialast + 1;
            iafirst = b_ialast;
            iblast = b_iblast + 1;
            ibfirst = b_iblast;
        }
        else if (ak < bk)
        {
            ialast = b_ialast + 1;
            iafirst = b_ialast;
        }
        else
        {
            iblast = b_iblast + 1;
            ibfirst = b_iblast;
        }
    }

    if (ncmax > 0)
    {
        if (nc < 1)
        {
            *ia_size = 0;
            *ib_size = 0;
            *c_size = 0;
        }
        else
        {
            *ia_size = nc;
            *ib_size = nc;
            *c_size = nc;
        }
    }
}

void GNSSPreProcessingDualAntenna::GNSSPrePro_binary_expand_op_eyk(real_T in1_data[], int32_T *in1_size, const
    GNSS_Measurement *in2, const int32_T in4_data[], const int32_T *in4_size, const real_T in5[40], const int32_T
    in7_data[], const int32_T *in7_size)
{
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    *in1_size = *in7_size == 1 ? *in4_size : *in7_size;
    stride_0_0 = (*in4_size != 1);
    stride_1_0 = (*in7_size != 1);
    loop_ub = *in7_size == 1 ? *in4_size : *in7_size;
    for (int32_T i{0}; i < loop_ub; i++)
    {
        in1_data[i] = in2->pseudorange[in4_data[i * stride_0_0] - 1] - in5[in7_data[i * stride_1_0] - 1];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_ey(real_T in1_data[], int32_T *in1_size, const
    GNSS_Measurement *in2, const int32_T in4_data[], const int32_T *in4_size, const real_T in5[40], const int32_T
    in7_data[], const int32_T *in7_size)
{
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    *in1_size = *in7_size == 1 ? *in4_size : *in7_size;
    stride_0_0 = (*in4_size != 1);
    stride_1_0 = (*in7_size != 1);
    loop_ub = *in7_size == 1 ? *in4_size : *in7_size;
    for (int32_T i{0}; i < loop_ub; i++)
    {
        in1_data[i] = in2->carrierphase[in4_data[i * stride_0_0] - 1] - in5[in7_data[i * stride_1_0] - 1] /
            0.19029367279836487;
    }
}

//
// Output and update for atomic system:
//    '<S61>/Apply Differential Correction Mask1'
//    '<S188>/Apply Differential Correction Mask1'
//
void GNSSPreProcessingDualAntenna::ApplyDifferentialCorrectionMask(const GNSS_Measurement *rtu_GpsMeasurementBus, const
    GNSS_Measurement_size *rtu_GpsMeasurementBus_DIMS1, const real_T rtu_diffPseudorangeCorrections[40], const uint16_T
    rtu_diffCorrAvailableSvid[40], const int32_T *rtu_diffCorrAvailableSvidS1_DIM, boolean_T rtu_enableDiffCorrection,
    const real_T rtu_rtcm_base_position[3], boolean_T *rty_MeasurementCorrected, B_ApplyDifferentialCorrection_T *localB,
    DW_ApplyDifferentialCorrectio_T *localDW)
{
    int32_T iia_size;
    int32_T iib_size;
    int32_T rtu_GpsMeasurementBus_DIMS1_idx;
    *rty_MeasurementCorrected = true;
    if ((*rtu_diffCorrAvailableSvidS1_DIM > 3) && rtu_enableDiffCorrection)
    {
        int32_T tmp;
        GNSSPreProcessingD_do_vectors_e(rtu_diffCorrAvailableSvid, rtu_diffCorrAvailableSvidS1_DIM,
            rtu_GpsMeasurementBus->PRN, &rtu_GpsMeasurementBus_DIMS1->PRN, localB->a__1_data, &localB->a__1_size,
            localB->iia_data, &iia_size, localB->iib_data, &iib_size);
        localB->GPS_measurement_Bus_masked.time_receive = rtu_GpsMeasurementBus->time_receive;
        localDW->SFunction_DIMS2.satellite_position[0] = iib_size;
        localDW->SFunction_DIMS2.satellite_position[1] = rtu_GpsMeasurementBus_DIMS1->satellite_position[1];
        rtu_GpsMeasurementBus_DIMS1_idx = rtu_GpsMeasurementBus_DIMS1->satellite_position[0];
        tmp = localDW->SFunction_DIMS2.satellite_position[0];
        localB->loop_ub = rtu_GpsMeasurementBus_DIMS1->satellite_position[1];
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->loop_ub_m = iib_size;
            for (localB->i = 0; localB->i < localB->loop_ub_m; localB->i++)
            {
                localB->GPS_measurement_Bus_masked.satellite_position[localB->i + tmp * localB->i1] =
                    rtu_GpsMeasurementBus->satellite_position[(rtu_GpsMeasurementBus_DIMS1_idx * localB->i1 +
                    localB->iib_data[localB->i]) - 1];
            }
        }

        localDW->SFunction_DIMS2.satellite_velocity[0] = iib_size;
        localDW->SFunction_DIMS2.satellite_velocity[1] = rtu_GpsMeasurementBus_DIMS1->satellite_velocity[1];
        rtu_GpsMeasurementBus_DIMS1_idx = rtu_GpsMeasurementBus_DIMS1->satellite_velocity[0];
        tmp = localDW->SFunction_DIMS2.satellite_velocity[0];
        localB->loop_ub = rtu_GpsMeasurementBus_DIMS1->satellite_velocity[1];
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->loop_ub_m = iib_size;
            for (localB->i = 0; localB->i < localB->loop_ub_m; localB->i++)
            {
                localB->GPS_measurement_Bus_masked.satellite_velocity[localB->i + tmp * localB->i1] =
                    rtu_GpsMeasurementBus->satellite_velocity[(rtu_GpsMeasurementBus_DIMS1_idx * localB->i1 +
                    localB->iib_data[localB->i]) - 1];
            }
        }

        localDW->SFunction_DIMS2.PRN = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.PRN[localB->i1] = rtu_GpsMeasurementBus->PRN[localB->iib_data[localB->i1]
                - 1];
        }

        if (iib_size == iia_size)
        {
            rtu_GpsMeasurementBus_DIMS1_idx = iib_size;
            localB->loop_ub = iib_size;
            for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
            {
                localB->tmp_data[localB->i1] = rtu_GpsMeasurementBus->pseudorange[localB->iib_data[localB->i1] - 1] -
                    rtu_diffPseudorangeCorrections[localB->iia_data[localB->i1] - 1];
            }
        }
        else
        {
            GNSSPrePro_binary_expand_op_eyk(localB->tmp_data, &rtu_GpsMeasurementBus_DIMS1_idx, rtu_GpsMeasurementBus,
                localB->iib_data, &iib_size, rtu_diffPseudorangeCorrections, localB->iia_data, &iia_size);
        }

        localDW->SFunction_DIMS2.pseudorange = rtu_GpsMeasurementBus_DIMS1_idx;
        localB->loop_ub = rtu_GpsMeasurementBus_DIMS1_idx;
        if (localB->loop_ub - 1 >= 0)
        {
            std::memcpy(&localB->GPS_measurement_Bus_masked.pseudorange[0], &localB->tmp_data[0], static_cast<uint32_T>
                        (localB->loop_ub) * sizeof(real_T));
        }

        localDW->SFunction_DIMS2.pseudorange_raw = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.pseudorange_raw[localB->i1] = rtu_GpsMeasurementBus->
                pseudorange_raw[localB->iib_data[localB->i1] - 1];
        }

        localDW->SFunction_DIMS2.pseudorange_satclk_corrected = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.pseudorange_satclk_corrected[localB->i1] =
                rtu_GpsMeasurementBus->pseudorange_satclk_corrected[localB->iib_data[localB->i1] - 1];
        }

        localDW->SFunction_DIMS2.deltarange = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.deltarange[localB->i1] = rtu_GpsMeasurementBus->deltarange
                [localB->iib_data[localB->i1] - 1];
        }

        localDW->SFunction_DIMS2.deltarange_raw = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.deltarange_raw[localB->i1] = rtu_GpsMeasurementBus->deltarange_raw
                [localB->iib_data[localB->i1] - 1];
        }

        localDW->SFunction_DIMS2.deltarange_satclk_corrected = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.deltarange_satclk_corrected[localB->i1] =
                rtu_GpsMeasurementBus->deltarange_satclk_corrected[localB->iib_data[localB->i1] - 1];
        }

        localDW->SFunction_DIMS2.variance_pseudorange = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.variance_pseudorange[localB->i1] =
                rtu_GpsMeasurementBus->variance_pseudorange[localB->iib_data[localB->i1] - 1];
        }

        localDW->SFunction_DIMS2.variance_pseudorange_measured = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.variance_pseudorange_measured[localB->i1] =
                rtu_GpsMeasurementBus->variance_pseudorange_measured[localB->iib_data[localB->i1] - 1];
        }

        localDW->SFunction_DIMS2.variance_deltarange = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.variance_deltarange[localB->i1] =
                rtu_GpsMeasurementBus->variance_deltarange[localB->iib_data[localB->i1] - 1];
        }

        if (iib_size == iia_size)
        {
            rtu_GpsMeasurementBus_DIMS1_idx = iib_size;
            localB->loop_ub = iib_size;
            for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
            {
                localB->tmp_data[localB->i1] = rtu_GpsMeasurementBus->carrierphase[localB->iib_data[localB->i1] - 1] -
                    rtu_diffPseudorangeCorrections[localB->iia_data[localB->i1] - 1] / 0.19029367279836487;
            }
        }
        else
        {
            GNSSPreProc_binary_expand_op_ey(localB->tmp_data, &rtu_GpsMeasurementBus_DIMS1_idx, rtu_GpsMeasurementBus,
                localB->iib_data, &iib_size, rtu_diffPseudorangeCorrections, localB->iia_data, &iia_size);
        }

        localDW->SFunction_DIMS2.carrierphase = rtu_GpsMeasurementBus_DIMS1_idx;
        localB->loop_ub = rtu_GpsMeasurementBus_DIMS1_idx;
        if (localB->loop_ub - 1 >= 0)
        {
            std::memcpy(&localB->GPS_measurement_Bus_masked.carrierphase[0], &localB->tmp_data[0], static_cast<uint32_T>
                        (localB->loop_ub) * sizeof(real_T));
        }

        localDW->SFunction_DIMS2.carrierphase_raw = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.carrierphase_raw[localB->i1] = rtu_GpsMeasurementBus->
                carrierphase_raw[localB->iib_data[localB->i1] - 1];
        }

        localDW->SFunction_DIMS2.carrierphase_satclk_corrected = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.carrierphase_satclk_corrected[localB->i1] =
                rtu_GpsMeasurementBus->carrierphase_satclk_corrected[localB->iib_data[localB->i1] - 1];
        }

        localDW->SFunction_DIMS2.variance_carrierphase_measured = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.variance_carrierphase_measured[localB->i1] =
                rtu_GpsMeasurementBus->variance_carrierphase_measured[localB->iib_data[localB->i1] - 1];
        }

        localDW->SFunction_DIMS2.locktime = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.locktime[localB->i1] = rtu_GpsMeasurementBus->locktime[localB->
                iib_data[localB->i1] - 1];
        }

        localDW->SFunction_DIMS2.CN0 = iib_size;
        localB->loop_ub = iib_size;
        for (localB->i1 = 0; localB->i1 < localB->loop_ub; localB->i1++)
        {
            localB->GPS_measurement_Bus_masked.CN0[localB->i1] = rtu_GpsMeasurementBus->CN0[localB->iib_data[localB->i1]
                - 1];
        }

        localB->GPS_measurement_Bus_masked.base_position[0] = rtu_rtcm_base_position[0];
        localB->GPS_measurement_Bus_masked.base_position[1] = rtu_rtcm_base_position[1];
        localB->GPS_measurement_Bus_masked.base_position[2] = rtu_rtcm_base_position[2];
    }
    else
    {
        localDW->SFunction_DIMS2 = *rtu_GpsMeasurementBus_DIMS1;
        localB->GPS_measurement_Bus_masked = *rtu_GpsMeasurementBus;
        *rty_MeasurementCorrected = false;
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
