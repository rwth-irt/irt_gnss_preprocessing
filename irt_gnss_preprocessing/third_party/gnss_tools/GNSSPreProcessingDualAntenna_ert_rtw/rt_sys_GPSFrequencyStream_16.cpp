//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_sys_GPSFrequencyStream_16.cpp
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
#include "rtwtypes.h"
#include "GNSSPreProcessingDualAntenna.h"
#include <emmintrin.h>
#include "GNSSPreProcessingDualAntenna_private.h"
#include <cstring>
#include <cmath>
#include "rt_sys_GPSFrequencyStream_16.h"

real_T rt_powd_snf(real_T u0, real_T u1)
{
    real_T y;
    if (std::isnan(u0) || std::isnan(u1))
    {
        y = (rtNaN);
    }
    else
    {
        real_T tmp;
        real_T tmp_0;
        tmp = std::abs(u0);
        tmp_0 = std::abs(u1);
        if (std::isinf(u1))
        {
            if (tmp == 1.0)
            {
                y = 1.0;
            }
            else if (tmp > 1.0)
            {
                if (u1 > 0.0)
                {
                    y = (rtInf);
                }
                else
                {
                    y = 0.0;
                }
            }
            else if (u1 > 0.0)
            {
                y = 0.0;
            }
            else
            {
                y = (rtInf);
            }
        }
        else if (tmp_0 == 0.0)
        {
            y = 1.0;
        }
        else if (tmp_0 == 1.0)
        {
            if (u1 > 0.0)
            {
                y = u0;
            }
            else
            {
                y = 1.0 / u0;
            }
        }
        else if (u1 == 2.0)
        {
            y = u0 * u0;
        }
        else if ((u1 == 0.5) && (u0 >= 0.0))
        {
            y = std::sqrt(u0);
        }
        else if ((u0 < 0.0) && (u1 > std::floor(u1)))
        {
            y = (rtNaN);
        }
        else
        {
            y = std::pow(u0, u1);
        }
    }

    return y;
}

//
// Output and update for atomic system:
//    '<S24>/Signal Noise Variance'
//    '<S25>/Signal Noise Variance'
//    '<S26>/Signal Noise Variance'
//    '<S71>/Signal Noise Variance'
//    '<S72>/Signal Noise Variance'
//    '<S73>/Signal Noise Variance'
//    '<S74>/Signal Noise Variance'
//    '<S151>/Signal Noise Variance'
//    '<S152>/Signal Noise Variance'
//    '<S153>/Signal Noise Variance'
//    ...
//
void GNSSPreProcessingDualAntenna::GNSSPreProc_SignalNoiseVariance(const real_T rtu_carrierToNoiseRatio[40], const
    int32_T *rtu_carrierToNoiseRatio_DIMS1, boolean_T rtu_use_measured_variance, const real_T rtu_pr_sigma[40], const
    int32_T *rtu_pr_sigma_DIMS1, const real_T rtu_cp_sigma[40], const int32_T *rtu_cp_sigma_DIMS1,
    B_SignalNoiseVariance_GNSSPre_T *localB, DW_SignalNoiseVariance_GNSSPr_T *localDW)
{
    if (rtu_use_measured_variance)
    {
        localDW->SFunction_DIMS2 = *rtu_pr_sigma_DIMS1;
        for (int32_T i{0}; i < *rtu_pr_sigma_DIMS1; i++)
        {
            localB->variancePseudorange[i] = rtu_pr_sigma[i];
        }

        localDW->SFunction_DIMS3 = *rtu_cp_sigma_DIMS1;
        for (int32_T i{0}; i < *rtu_cp_sigma_DIMS1; i++)
        {
            localB->varianceDeltarange[i] = rtu_cp_sigma[i];
        }
    }
    else
    {
        int32_T scalarLB;
        int32_T varargin_2_tmp_size_idx_0;
        int32_T vectorUB;
        varargin_2_tmp_size_idx_0 = *rtu_carrierToNoiseRatio_DIMS1;
        scalarLB = (*rtu_carrierToNoiseRatio_DIMS1 / 2) << 1;
        vectorUB = scalarLB - 2;
        for (int32_T i{0}; i <= vectorUB; i += 2)
        {
            __m128d tmp;
            tmp = _mm_loadu_pd(&rtu_carrierToNoiseRatio[i]);
            _mm_storeu_pd(&localB->varargin_2_tmp_data[i], _mm_div_pd(_mm_mul_pd(tmp, _mm_set1_pd(-1.0)), _mm_set1_pd
                           (10.0)));
        }

        for (int32_T i{scalarLB}; i < *rtu_carrierToNoiseRatio_DIMS1; i++)
        {
            localB->varargin_2_tmp_data[i] = -rtu_carrierToNoiseRatio[i] / 10.0;
        }

        for (int32_T i{0}; i < varargin_2_tmp_size_idx_0; i++)
        {
            localB->tmp_data[i] = rt_powd_snf(10.0, localB->varargin_2_tmp_data[i]);
        }

        localDW->SFunction_DIMS2 = *rtu_carrierToNoiseRatio_DIMS1;
        if (*rtu_carrierToNoiseRatio_DIMS1 - 1 >= 0)
        {
            std::memcpy(&localB->variancePseudorange[0], &localB->tmp_data[0], static_cast<uint32_T>
                        (*rtu_carrierToNoiseRatio_DIMS1) * sizeof(real_T));
        }

        for (int32_T i{0}; i < varargin_2_tmp_size_idx_0; i++)
        {
            localB->tmp_data[i] = rt_powd_snf(10.0, localB->varargin_2_tmp_data[i]);
        }

        localDW->SFunction_DIMS3 = *rtu_carrierToNoiseRatio_DIMS1;
        if (*rtu_carrierToNoiseRatio_DIMS1 - 1 >= 0)
        {
            std::memcpy(&localB->varianceDeltarange[0], &localB->tmp_data[0], static_cast<uint32_T>
                        (*rtu_carrierToNoiseRatio_DIMS1) * sizeof(real_T));
        }
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
