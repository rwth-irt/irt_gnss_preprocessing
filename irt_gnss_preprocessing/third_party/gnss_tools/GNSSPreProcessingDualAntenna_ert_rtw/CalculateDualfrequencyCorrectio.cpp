//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateDualfrequencyCorrectio.cpp
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
#include <emmintrin.h>
#include "CalculateDualfrequencyCorrectio.h"

// Function for MATLAB Function: '<S57>/Calculate Dualfrequency Correction with L1 and L2C'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingD_do_vectors_k(const uint16_T a_data[], const int32_T *a_size, const
    uint16_T b_data[], const int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size,
    int32_T ib_data[], int32_T *ib_size, B_CalculateDualfrequencyCorre_T *localB)
{
    int32_T iafirst;
    int32_T ialast;
    int32_T ibfirst;
    int32_T iblast;
    if (*a_size <= *b_size)
    {
        localB->ncmax = *a_size;
    }
    else
    {
        localB->ncmax = *b_size;
    }

    *c_size = localB->ncmax;
    *ia_size = localB->ncmax;
    *ib_size = localB->ncmax;
    localB->nc = 0;
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
            localB->nc++;
            c_data[localB->nc - 1] = ak;
            ia_data[localB->nc - 1] = iafirst + 1;
            ib_data[localB->nc - 1] = ibfirst + 1;
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

    if (localB->ncmax > 0)
    {
        if (localB->nc < 1)
        {
            *ia_size = 0;
            *ib_size = 0;
            *c_size = 0;
        }
        else
        {
            *ia_size = localB->nc;
            *ib_size = localB->nc;
            *c_size = localB->nc;
        }
    }
}

//
// Output and update for atomic system:
//    '<S57>/Calculate Dualfrequency Correction with L1 and L2C'
//    '<S184>/Calculate Dualfrequency Correction with L1 and L2C'
//
void GNSSPreProcessingDualAntenna::CalculateDualfrequencyCorrectio(const GNSS_Measurement *rtu_measurementBusL1, const
    GNSS_Measurement_size *rtu_measurementBusL1_DIMS1, const GNSS_Measurement *rtu_measurementBusL2C, const
    GNSS_Measurement_size *rtu_measurementBusL2C_DIMS1, boolean_T rtu_enableDualFrequencyCorrecti,
    B_CalculateDualfrequencyCorre_T *localB, DW_CalculateDualfrequencyCorr_T *localDW)
{
    localB->measurementFrequencyBus.time_receive = rtu_measurementBusL1->time_receive;
    localDW->SFunction_DIMS2.satellite_position[0] = rtu_measurementBusL1_DIMS1->satellite_position[0];
    localDW->SFunction_DIMS2.satellite_position[1] = rtu_measurementBusL1_DIMS1->satellite_position[1];
    localB->loop_ub = rtu_measurementBusL1_DIMS1->satellite_position[0] * rtu_measurementBusL1_DIMS1->
        satellite_position[1];
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.satellite_position[0], &rtu_measurementBusL1->satellite_position[0],
                    static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS2.satellite_velocity[0] = rtu_measurementBusL1_DIMS1->satellite_velocity[0];
    localDW->SFunction_DIMS2.satellite_velocity[1] = rtu_measurementBusL1_DIMS1->satellite_velocity[1];
    localB->loop_ub = rtu_measurementBusL1_DIMS1->satellite_velocity[0] * rtu_measurementBusL1_DIMS1->
        satellite_velocity[1];
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.satellite_velocity[0], &rtu_measurementBusL1->satellite_velocity[0],
                    static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS2.PRN = rtu_measurementBusL1_DIMS1->PRN;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->PRN;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.PRN[0], &rtu_measurementBusL1->PRN[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(uint16_T));
    }

    localDW->SFunction_DIMS2.pseudorange = rtu_measurementBusL1_DIMS1->pseudorange;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->pseudorange;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.pseudorange[0], &rtu_measurementBusL1->pseudorange[0], static_cast<
                    uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS2.pseudorange_raw = rtu_measurementBusL1_DIMS1->pseudorange_raw;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->pseudorange_raw;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.pseudorange_raw[0], &rtu_measurementBusL1->pseudorange_raw[0],
                    static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS2.pseudorange_satclk_corrected = rtu_measurementBusL1_DIMS1->pseudorange_satclk_corrected;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->pseudorange_satclk_corrected;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.pseudorange_satclk_corrected[0],
                    &rtu_measurementBusL1->pseudorange_satclk_corrected[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS2.deltarange = rtu_measurementBusL1_DIMS1->deltarange;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->deltarange;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.deltarange[0], &rtu_measurementBusL1->deltarange[0], static_cast<
                    uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS2.deltarange_raw = rtu_measurementBusL1_DIMS1->deltarange_raw;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->deltarange_raw;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.deltarange_raw[0], &rtu_measurementBusL1->deltarange_raw[0],
                    static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS2.deltarange_satclk_corrected = rtu_measurementBusL1_DIMS1->deltarange_satclk_corrected;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->deltarange_satclk_corrected;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.deltarange_satclk_corrected[0],
                    &rtu_measurementBusL1->deltarange_satclk_corrected[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS2.variance_pseudorange = rtu_measurementBusL1_DIMS1->variance_pseudorange;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->variance_pseudorange;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.variance_pseudorange[0],
                    &rtu_measurementBusL1->variance_pseudorange[0], static_cast<uint32_T>(localB->loop_ub) * sizeof
                    (real_T));
    }

    localDW->SFunction_DIMS2.variance_pseudorange_measured = rtu_measurementBusL1_DIMS1->variance_pseudorange_measured;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->variance_pseudorange_measured;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.variance_pseudorange_measured[0],
                    &rtu_measurementBusL1->variance_pseudorange_measured[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS2.variance_deltarange = rtu_measurementBusL1_DIMS1->variance_deltarange;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->variance_deltarange;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.variance_deltarange[0], &rtu_measurementBusL1->variance_deltarange
                    [0], static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS2.carrierphase = rtu_measurementBusL1_DIMS1->carrierphase;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->carrierphase;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.carrierphase[0], &rtu_measurementBusL1->carrierphase[0],
                    static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS2.carrierphase_raw = rtu_measurementBusL1_DIMS1->carrierphase_raw;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->carrierphase_raw;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.carrierphase_raw[0], &rtu_measurementBusL1->carrierphase_raw[0],
                    static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS2.carrierphase_satclk_corrected = rtu_measurementBusL1_DIMS1->carrierphase_satclk_corrected;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->carrierphase_satclk_corrected;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.carrierphase_satclk_corrected[0],
                    &rtu_measurementBusL1->carrierphase_satclk_corrected[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS2.variance_carrierphase_measured = rtu_measurementBusL1_DIMS1->variance_carrierphase_measured;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->variance_carrierphase_measured;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.variance_carrierphase_measured[0],
                    &rtu_measurementBusL1->variance_carrierphase_measured[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS2.locktime = rtu_measurementBusL1_DIMS1->locktime;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->locktime;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.locktime[0], &rtu_measurementBusL1->locktime[0],
                    static_cast<uint32_T>(localB->loop_ub) * sizeof(real32_T));
    }

    localDW->SFunction_DIMS2.CN0 = rtu_measurementBusL1_DIMS1->CN0;
    localB->loop_ub = rtu_measurementBusL1_DIMS1->CN0;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->measurementFrequencyBus.CN0[0], &rtu_measurementBusL1->CN0[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localB->measurementFrequencyBus.base_position[0] = rtu_measurementBusL1->base_position[0];
    localB->measurementFrequencyBus.base_position[1] = rtu_measurementBusL1->base_position[1];
    localB->measurementFrequencyBus.base_position[2] = rtu_measurementBusL1->base_position[2];
    if (rtu_enableDualFrequencyCorrecti)
    {
        localB->rtu_measurementBusL1_DIMS1 = rtu_measurementBusL1_DIMS1->PRN;
        localB->rtu_measurementBusL2C_DIMS1 = rtu_measurementBusL2C_DIMS1->PRN;
        GNSSPreProcessingD_do_vectors_k(rtu_measurementBusL1->PRN, &localB->rtu_measurementBusL1_DIMS1,
            rtu_measurementBusL2C->PRN, &localB->rtu_measurementBusL2C_DIMS1, localB->tmp_data, &localB->tmp_size,
            localB->iia_data, &localB->iia_size, localB->iib_data, &localB->iib_size, localB);
        localDW->SFunction_DIMS4 = localB->tmp_size;
        localB->loop_ub = localB->tmp_size;
        if (localB->loop_ub - 1 >= 0)
        {
            std::memcpy(&localB->SvidDualFrequencyCorrected[0], &localB->tmp_data[0], static_cast<uint32_T>
                        (localB->loop_ub) * sizeof(uint16_T));
        }

        if (localDW->SFunction_DIMS4 != 0)
        {
            std::memset(&localB->fixed_f1[0], 0, 150U * sizeof(real_T));
            std::memset(&localB->fixed_f2[0], 0, 150U * sizeof(real_T));
            std::memset(&localB->fixed_PRN[0], 0, 150U * sizeof(uint16_T));
            localB->i = static_cast<int8_T>(rtu_measurementBusL1_DIMS1->PRN);
            localDW->SFunction_DIMS3 = static_cast<int8_T>(rtu_measurementBusL1_DIMS1->PRN);
            if (localB->i - 1 >= 0)
            {
                std::memset(&localB->dualFrequencyCorrection[0], 0, static_cast<uint32_T>(localB->i) * sizeof(real_T));
            }

            localB->loop_ub = rtu_measurementBusL1_DIMS1->PRN;
            if (localB->loop_ub - 1 >= 0)
            {
                std::memset(&localB->idx2_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(int8_T));
            }

            localB->loop_ub = rtu_measurementBusL1_DIMS1->PRN;
            if (localB->loop_ub - 1 >= 0)
            {
                std::memset(&localB->idx1_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(int8_T));
            }

            localB->c = rtu_measurementBusL1_DIMS1->PRN;
            for (localB->i = 0; localB->i < localB->c; localB->i++)
            {
                localB->loop_ub = rtu_measurementBusL2C_DIMS1->PRN;
                for (localB->vectorUB = 0; localB->vectorUB < localB->loop_ub; localB->vectorUB++)
                {
                    if (rtu_measurementBusL1->PRN[localB->i] == rtu_measurementBusL2C->PRN[localB->vectorUB])
                    {
                        localB->idx1_data[localB->i] = static_cast<int8_T>(localB->i + 1);
                        localB->idx2_data[localB->i] = static_cast<int8_T>(localB->vectorUB + 1);
                    }
                }
            }

            localB->vectorUB = rtu_measurementBusL1_DIMS1->PRN;
            for (localB->i = 0; localB->i < localB->vectorUB; localB->i++)
            {
                int8_T idx1;
                int8_T idx2;
                idx2 = localB->idx2_data[localB->i];
                idx1 = localB->idx1_data[localB->i];
                if ((idx1 != 0) && (idx2 != 0))
                {
                    localB->d = rtu_measurementBusL1->pseudorange[idx1 - 1];
                    if (localB->d != 0.0)
                    {
                        localB->d1 = rtu_measurementBusL2C->pseudorange[idx2 - 1];
                        if (localB->d1 != 0.0)
                        {
                            localB->c = rtu_measurementBusL1->PRN[localB->i] - 1;
                            localB->fixed_PRN[localB->c] = rtu_measurementBusL1->PRN[localB->i];
                            localB->fixed_f1[localB->c] = localB->d;
                            localB->fixed_f2[localB->c] = localB->d1;
                        }
                    }
                }
            }

            for (localB->c = 0; localB->c <= 148; localB->c += 2)
            {
                __m128d tmp;
                __m128d tmp_0;
                tmp = _mm_loadu_pd(&localB->fixed_f2[localB->c]);
                tmp_0 = _mm_loadu_pd(&localB->fixed_f1[localB->c]);
                _mm_storeu_pd(&localB->fixed_f2[localB->c], _mm_div_pd(_mm_mul_pd(_mm_mul_pd(_mm_sub_pd(tmp, tmp_0),
                                 _mm_set1_pd(1.9836839845427221)), _mm_set1_pd(1.2276E+9)), _mm_set1_pd(1.57542E+9)));
            }

            localB->vectorUB = rtu_measurementBusL1_DIMS1->PRN;
            for (localB->i = 0; localB->i < localB->vectorUB; localB->i++)
            {
                boolean_T exitg1;
                boolean_T y;
                localB->loop_ub = 0;
                for (localB->c = 0; localB->c < 150; localB->c++)
                {
                    if (localB->fixed_PRN[localB->c] != 0)
                    {
                        localB->loop_ub++;
                    }
                }

                localB->h_size_idx_0 = localB->loop_ub;
                localB->loop_ub = 0;
                for (localB->c = 0; localB->c < 150; localB->c++)
                {
                    if (localB->fixed_PRN[localB->c] != 0)
                    {
                        localB->h_data[localB->loop_ub] = static_cast<uint8_T>(localB->c + 1);
                        localB->loop_ub++;
                    }
                }

                localB->rtu_measurementBusL1 = rtu_measurementBusL1->PRN[localB->i];
                for (localB->c = 0; localB->c < localB->h_size_idx_0; localB->c++)
                {
                    localB->g_data[localB->c] = (localB->fixed_PRN[localB->h_data[localB->c] - 1] ==
                        localB->rtu_measurementBusL1);
                }

                localB->loop_ub = 0;
                for (localB->c = 0; localB->c < 150; localB->c++)
                {
                    if (localB->fixed_PRN[localB->c] != 0)
                    {
                        localB->k_data[localB->loop_ub] = static_cast<uint8_T>(localB->c + 1);
                        localB->loop_ub++;
                    }
                }

                localB->loop_ub = localB->h_size_idx_0 - 1;
                localB->rtu_measurementBusL1 = 0;
                for (localB->c = 0; localB->c <= localB->loop_ub; localB->c++)
                {
                    if (localB->g_data[localB->c])
                    {
                        localB->rtu_measurementBusL1++;
                    }
                }

                localB->h_size_idx_0 = localB->rtu_measurementBusL1;
                localB->rtu_measurementBusL1 = 0;
                for (localB->c = 0; localB->c <= localB->loop_ub; localB->c++)
                {
                    if (localB->g_data[localB->c])
                    {
                        localB->l_data[localB->rtu_measurementBusL1] = localB->c + 1;
                        localB->rtu_measurementBusL1++;
                    }
                }

                y = false;
                localB->c = 1;
                exitg1 = false;
                while ((!exitg1) && (localB->c <= localB->h_size_idx_0))
                {
                    if (localB->fixed_PRN[localB->k_data[localB->l_data[localB->c - 1] - 1] - 1] != 0)
                    {
                        y = true;
                        exitg1 = true;
                    }
                    else
                    {
                        localB->c++;
                    }
                }

                if (y)
                {
                    localB->dualFrequencyCorrection[localB->i] = localB->fixed_f2[rtu_measurementBusL1->PRN[localB->i] -
                        1];
                }
            }
        }
        else
        {
            localDW->SFunction_DIMS3 = rtu_measurementBusL1_DIMS1->pseudorange;
            localB->loop_ub = rtu_measurementBusL1_DIMS1->pseudorange;
            localB->i = (rtu_measurementBusL1_DIMS1->pseudorange / 2) << 1;
            localB->vectorUB = localB->i - 2;
            for (localB->c = 0; localB->c <= localB->vectorUB; localB->c += 2)
            {
                __m128d tmp;
                tmp = _mm_loadu_pd(&rtu_measurementBusL1->pseudorange[localB->c]);
                _mm_storeu_pd(&localB->dualFrequencyCorrection[localB->c], _mm_mul_pd(_mm_set1_pd(0.0), tmp));
            }

            for (localB->c = localB->i; localB->c < localB->loop_ub; localB->c++)
            {
                localB->dualFrequencyCorrection[localB->c] = 0.0 * rtu_measurementBusL1->pseudorange[localB->c];
            }
        }
    }
    else
    {
        localDW->SFunction_DIMS3 = rtu_measurementBusL1_DIMS1->pseudorange;
        localB->loop_ub = rtu_measurementBusL1_DIMS1->pseudorange;
        localB->i = (rtu_measurementBusL1_DIMS1->pseudorange / 2) << 1;
        localB->vectorUB = localB->i - 2;
        for (localB->c = 0; localB->c <= localB->vectorUB; localB->c += 2)
        {
            __m128d tmp;
            tmp = _mm_loadu_pd(&rtu_measurementBusL1->pseudorange[localB->c]);
            _mm_storeu_pd(&localB->dualFrequencyCorrection[localB->c], _mm_mul_pd(_mm_set1_pd(0.0), tmp));
        }

        for (localB->c = localB->i; localB->c < localB->loop_ub; localB->c++)
        {
            localB->dualFrequencyCorrection[localB->c] = 0.0 * rtu_measurementBusL1->pseudorange[localB->c];
        }

        localDW->SFunction_DIMS4 = 0;
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
