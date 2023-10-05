//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateTroposphericCorrection.cpp
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
#include <cstring>
#include <cmath>
#include <emmintrin.h>
#include "CalculateTroposphericCorrection.h"

// Function for MATLAB Function: '<S29>/Calculate Tropospheric Corrections'
real_T GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAn_interp1(const real_T varargin_1[5], const real_T
    varargin_2[5], real_T varargin_3, B_CalculateTroposphericCorrec_T *localB)
{
    real_T Vq;
    int32_T low_i;
    Vq = (rtNaN);
    low_i = 0;
    int32_T exitg1;
    do
    {
        exitg1 = 0;
        if (low_i < 5)
        {
            if (std::isnan(varargin_1[low_i]))
            {
                exitg1 = 1;
            }
            else
            {
                low_i++;
            }
        }
        else
        {
            if (!std::isnan(varargin_3))
            {
                int32_T high_i;
                int32_T low_ip1;
                low_i = 1;
                low_ip1 = 2;
                high_i = 5;
                while (high_i > low_ip1)
                {
                    int32_T mid_i;
                    mid_i = (low_i + high_i) >> 1;
                    if (varargin_3 >= varargin_1[mid_i - 1])
                    {
                        low_i = mid_i;
                        low_ip1 = mid_i + 1;
                    }
                    else
                    {
                        high_i = mid_i;
                    }
                }

                localB->r = varargin_1[low_i - 1];
                localB->r = (varargin_3 - localB->r) / (varargin_1[low_i] - localB->r);
                if (localB->r == 0.0)
                {
                    Vq = varargin_2[low_i - 1];
                }
                else if (localB->r == 1.0)
                {
                    Vq = varargin_2[low_i];
                }
                else
                {
                    Vq = varargin_2[low_i - 1];
                    if (!(Vq == varargin_2[low_i]))
                    {
                        Vq = (1.0 - localB->r) * Vq + localB->r * varargin_2[low_i];
                    }
                }
            }

            exitg1 = 1;
        }
    }
    while (exitg1 == 0);

    return Vq;
}

real_T GNSSPreProcessingDualAntenna::GNSSPreProcessing_rt_powd_snf_b(real_T u0, real_T u1,
    B_CalculateTroposphericCorrec_T *localB)
{
    real_T y;
    if (std::isnan(u0) || std::isnan(u1))
    {
        y = (rtNaN);
    }
    else
    {
        localB->d1 = std::abs(u0);
        localB->d2 = std::abs(u1);
        if (std::isinf(u1))
        {
            if (localB->d1 == 1.0)
            {
                y = 1.0;
            }
            else if (localB->d1 > 1.0)
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
        else if (localB->d2 == 0.0)
        {
            y = 1.0;
        }
        else if (localB->d2 == 1.0)
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

// Function for MATLAB Function: '<S29>/Calculate Tropospheric Corrections'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingD_expand_power(const real_T a_data[], const int32_T *a_size, const
    real_T b_data[], const int32_T *b_size, real_T c_data[], int32_T *c_size, B_CalculateTroposphericCorrec_T *localB)
{
    int8_T csz_idx_0;
    if (*b_size == 1)
    {
        csz_idx_0 = static_cast<int8_T>(*a_size);
    }
    else if (*a_size == 1)
    {
        csz_idx_0 = static_cast<int8_T>(*b_size);
    }
    else if (*a_size <= *b_size)
    {
        csz_idx_0 = static_cast<int8_T>(*a_size);
    }
    else
    {
        csz_idx_0 = static_cast<int8_T>(*b_size);
    }

    *c_size = csz_idx_0;
    if (csz_idx_0 != 0)
    {
        int32_T f;
        boolean_T d;
        boolean_T e;
        d = (*a_size != 1);
        e = (*b_size != 1);
        f = csz_idx_0 - 1;
        for (int32_T k{0}; k <= f; k++)
        {
            c_data[k] = GNSSPreProcessing_rt_powd_snf_b(a_data[d * k], b_data[e * k], localB);
        }
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_gi(real_T in1_data[], int32_T *in1_size, const real_T
    in2[40], int32_T in3, const real_T in4_data[], const int32_T *in4_size, const real_T in5_data[], const int32_T
    *in5_size, const real_T in6_data[], const int32_T *in6_size, const real_T in7_data[], const int32_T *in7_size, const
    real_T in8_data[], const int32_T *in8_size, const real_T in9_data[], const int32_T *in9_size, const real_T in10[40],
    const int32_T *in11, const real_T in12_data[], const int32_T *in12_size, B_CalculateTroposphericCorrec_T *localB)
{
    int32_T in2_size_idx_0;
    int32_T loop_ub;
    int32_T stride_10_0;
    int32_T stride_11_0;
    in2_size_idx_0 = ((*in11 == 1 ? *in11 == 1 ? *in12_size : *in11 : *in11) == 1 ? *in11 == 1 ? *in9_size : *in11 :
                      *in11 == 1 ? *in11 == 1 ? *in12_size : *in11 : *in11) == 1 ? ((*in8_size == 1 ? *in7_size == 1 ?
        *in6_size == 1 ? *in5_size : *in6_size : *in7_size : *in8_size) == 1 ? *in4_size : *in8_size == 1 ? *in7_size ==
        1 ? *in6_size == 1 ? *in5_size : *in6_size : *in7_size : *in8_size) == 1 ? *in1_size == 1 ? in3 : *in1_size :
        (*in8_size == 1 ? *in7_size == 1 ? *in6_size == 1 ? *in5_size : *in6_size : *in7_size : *in8_size) == 1 ?
        *in4_size : *in8_size == 1 ? *in7_size == 1 ? *in6_size == 1 ? *in5_size : *in6_size : *in7_size : *in8_size : (*
        in11 == 1 ? *in11 == 1 ? *in12_size : *in11 : *in11) == 1 ? *in11 == 1 ? *in9_size : *in11 : *in11 == 1 ? *in11 ==
        1 ? *in12_size : *in11 : *in11;
    localB->stride_0_0 = (in3 != 1);
    localB->stride_1_0 = (*in1_size != 1);
    localB->stride_2_0 = (*in4_size != 1);
    localB->stride_3_0 = (*in5_size != 1);
    localB->stride_4_0 = (*in6_size != 1);
    localB->stride_5_0 = (*in7_size != 1);
    localB->stride_6_0 = (*in8_size != 1);
    localB->stride_7_0 = (*in9_size != 1);
    localB->stride_8_0 = (*in11 != 1);
    localB->stride_9_0 = (*in12_size != 1);
    stride_10_0 = (*in11 != 1);
    stride_11_0 = (*in11 != 1);
    loop_ub = ((*in11 == 1 ? *in11 == 1 ? *in12_size : *in11 : *in11) == 1 ? *in11 == 1 ? *in9_size : *in11 : *in11 == 1
               ? *in11 == 1 ? *in12_size : *in11 : *in11) == 1 ? ((*in8_size == 1 ? *in7_size == 1 ? *in6_size == 1 ?
        *in5_size : *in6_size : *in7_size : *in8_size) == 1 ? *in4_size : *in8_size == 1 ? *in7_size == 1 ? *in6_size ==
        1 ? *in5_size : *in6_size : *in7_size : *in8_size) == 1 ? *in1_size == 1 ? in3 : *in1_size : (*in8_size == 1 ?
        *in7_size == 1 ? *in6_size == 1 ? *in5_size : *in6_size : *in7_size : *in8_size) == 1 ? *in4_size : *in8_size ==
        1 ? *in7_size == 1 ? *in6_size == 1 ? *in5_size : *in6_size : *in7_size : *in8_size : (*in11 == 1 ? *in11 == 1 ?
        *in12_size : *in11 : *in11) == 1 ? *in11 == 1 ? *in9_size : *in11 : *in11 == 1 ? *in11 == 1 ? *in12_size : *in11
        : *in11;
    for (localB->i = 0; localB->i < loop_ub; localB->i++)
    {
        localB->varargout_1 = std::fmax(0.0, 4.0 - in10[localB->i * stride_10_0] / 180.0 * 3.1415926535897931);
        localB->in2_tmp = in10[localB->i * stride_11_0];
        localB->in2_data[localB->i] = (109.65462799999999 / ((in5_data[localB->i * localB->stride_3_0] + 1.0) * 9.784 -
            in6_data[localB->i * localB->stride_4_0] * 287.054) * in7_data[localB->i * localB->stride_5_0] /
            in8_data[localB->i * localB->stride_6_0] * in4_data[localB->i * localB->stride_2_0] + in1_data[localB->i *
            localB->stride_1_0] * 0.022276538615999996 / 9.784 * in2[localB->i * localB->stride_0_0]) *
            ((localB->varargout_1 * localB->varargout_1 * 0.015 + 1.0) * (1.001 / in12_data[localB->i *
              localB->stride_9_0]) * static_cast<real_T>((localB->in2_tmp >= 0.034906585039886591) && (localB->in2_tmp <
               0.069813170079773182)) + 1.001 / in9_data[localB->i * localB->stride_7_0] * static_cast<real_T>
             (in10[localB->i * localB->stride_8_0] >= 0.087266462599716474));
    }

    *in1_size = in2_size_idx_0;
    if (in2_size_idx_0 - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in2_data[0], static_cast<uint32_T>(in2_size_idx_0) * sizeof(real_T));
    }
}

//
// Output and update for atomic system:
//    '<S29>/Calculate Tropospheric Corrections'
//    '<S156>/Calculate Tropospheric Corrections'
//
void GNSSPreProcessingDualAntenna::CalculateTroposphericCorrection(real_T rtu_dayOfYear, boolean_T
    rtu_enableTroposphericCorrectio, const real_T rtu_userPosLlh[3], const real_T rtu_elevationAngle[40], const int32_T *
    rtu_elevationAngle_DIMS1, B_CalculateTroposphericCorrec_T *localB, DW_CalculateTroposphericCorre_T *localDW)
{
    static const real_T j[5]
    {
        1013.25, 1017.25, 1015.75, 1011.75, 1013.0
    };

    static const real_T l[5]
    {
        0.0, -3.75, -2.25, -1.75, -0.5
    };

    static const real_T m[5]
    {
        299.65, 294.15, 283.15, 272.15, 263.65
    };

    static const real_T n[5]
    {
        0.0, 7.0, 11.0, 15.0, 14.5
    };

    static const real_T o[5]
    {
        26.31, 21.79, 11.66, 6.78, 4.11
    };

    static const real_T p[5]
    {
        0.0, 8.85, 7.24, 5.36, 3.39
    };

    static const real_T q[5]
    {
        0.0063, 0.00605, 0.00558, 0.00539, 0.00453
    };

    static const real_T r[5]
    {
        0.0, 0.00025, 0.00032, 0.00081, 0.00062
    };

    static const real_T s[5]
    {
        2.77, 3.15, 2.57, 1.81, 1.55
    };

    static const real_T t[5]
    {
        0.0, 0.33, 0.46, 0.74, 0.3
    };

    if (rtu_enableTroposphericCorrectio)
    {
        __m128d tmp_0;
        __m128d tmp_1;
        localB->pressure_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localB->loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        if (localB->loop_ub - 1 >= 0)
        {
            std::memset(&localB->pressure_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
        }

        localB->temperature_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localB->loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        if (localB->loop_ub - 1 >= 0)
        {
            std::memset(&localB->temperature_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
        }

        localB->water_vapour_pressure_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localB->loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        if (localB->loop_ub - 1 >= 0)
        {
            std::memset(&localB->water_vapour_pressure_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof
                        (real_T));
        }

        localB->beta_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localB->loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        if (localB->loop_ub - 1 >= 0)
        {
            std::memset(&localB->beta_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
        }

        localB->lambda_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localB->loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        if (localB->loop_ub - 1 >= 0)
        {
            std::memset(&localB->lambda_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
        }

        for (localB->k = 0; localB->k < *rtu_elevationAngle_DIMS1; localB->k++)
        {
            localB->x_data[localB->k] = rtu_elevationAngle[localB->k];
        }

        for (localB->k = 0; localB->k < *rtu_elevationAngle_DIMS1; localB->k++)
        {
            localB->x_data[localB->k] = std::sin(localB->x_data[localB->k]);
        }

        localB->y_size = *rtu_elevationAngle_DIMS1;
        localB->loop_ub = *rtu_elevationAngle_DIMS1;
        localB->SFunction_DIMS2_tmp_tmp = (*rtu_elevationAngle_DIMS1 / 2) << 1;
        localB->vectorUB = localB->SFunction_DIMS2_tmp_tmp - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_1 = _mm_loadu_pd(&localB->x_data[localB->k]);
            _mm_storeu_pd(&localB->y_data[localB->k], _mm_add_pd(_mm_mul_pd(tmp_1, tmp_1), _mm_set1_pd(0.002001)));
        }

        for (localB->k = localB->SFunction_DIMS2_tmp_tmp; localB->k < localB->loop_ub; localB->k++)
        {
            localB->latitude = localB->x_data[localB->k];
            localB->y_data[localB->k] = localB->latitude * localB->latitude + 0.002001;
        }

        localB->loop_ub = *rtu_elevationAngle_DIMS1;
        localB->SFunction_DIMS2_tmp_tmp = (*rtu_elevationAngle_DIMS1 / 2) << 1;
        localB->vectorUB = localB->SFunction_DIMS2_tmp_tmp - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_1 = _mm_loadu_pd(&localB->y_data[localB->k]);
            _mm_storeu_pd(&localB->y_data[localB->k], _mm_sqrt_pd(tmp_1));
        }

        for (localB->k = localB->SFunction_DIMS2_tmp_tmp; localB->k < localB->loop_ub; localB->k++)
        {
            localB->y_data[localB->k] = std::sqrt(localB->y_data[localB->k]);
        }

        localB->x_size = *rtu_elevationAngle_DIMS1;
        for (localB->k = 0; localB->k < *rtu_elevationAngle_DIMS1; localB->k++)
        {
            localB->x_data[localB->k] = rtu_elevationAngle[localB->k];
        }

        for (localB->k = 0; localB->k < *rtu_elevationAngle_DIMS1; localB->k++)
        {
            localB->x_data[localB->k] = std::sin(localB->x_data[localB->k]);
        }

        localB->loop_ub = *rtu_elevationAngle_DIMS1;
        localB->SFunction_DIMS2_tmp_tmp = (*rtu_elevationAngle_DIMS1 / 2) << 1;
        localB->vectorUB = localB->SFunction_DIMS2_tmp_tmp - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_1 = _mm_loadu_pd(&localB->x_data[localB->k]);
            _mm_storeu_pd(&localB->x_data[localB->k], _mm_add_pd(_mm_mul_pd(tmp_1, tmp_1), _mm_set1_pd(0.002001)));
        }

        for (localB->k = localB->SFunction_DIMS2_tmp_tmp; localB->k < localB->loop_ub; localB->k++)
        {
            localB->latitude = localB->x_data[localB->k];
            localB->x_data[localB->k] = localB->latitude * localB->latitude + 0.002001;
        }

        localB->loop_ub = *rtu_elevationAngle_DIMS1;
        localB->vectorUB = localB->SFunction_DIMS2_tmp_tmp - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_1 = _mm_loadu_pd(&localB->x_data[localB->k]);
            _mm_storeu_pd(&localB->x_data[localB->k], _mm_sqrt_pd(tmp_1));
        }

        for (localB->k = localB->SFunction_DIMS2_tmp_tmp; localB->k < localB->loop_ub; localB->k++)
        {
            localB->x_data[localB->k] = std::sqrt(localB->x_data[localB->k]);
        }

        localB->latitude = rtu_userPosLlh[0] * 180.0 / 3.1415926535897931;
        if (localB->latitude > 0.0)
        {
            localB->k = 28;
        }
        else if (localB->latitude < 0.0)
        {
            localB->k = 211;
        }
        else
        {
            localB->k = 0;
        }

        localB->cosinus_day = std::cos((rtu_dayOfYear - static_cast<real_T>(localB->k)) * 6.2831853071795862 / 365.25);
        for (localB->SFunction_DIMS2_tmp_tmp = 0; localB->SFunction_DIMS2_tmp_tmp < *rtu_elevationAngle_DIMS1;
                localB->SFunction_DIMS2_tmp_tmp++)
        {
            if (localB->latitude < 15.0)
            {
                localB->pressure_data[localB->SFunction_DIMS2_tmp_tmp] = 1013.25 - 0.0 * localB->cosinus_day;
                localB->temperature_data[localB->SFunction_DIMS2_tmp_tmp] = 299.65 - 0.0 * localB->cosinus_day;
                localB->water_vapour_pressure_data[localB->SFunction_DIMS2_tmp_tmp] = 26.31 - 0.0 * localB->cosinus_day;
                localB->beta_data[localB->SFunction_DIMS2_tmp_tmp] = 0.0063 - 0.0 * localB->cosinus_day;
                localB->lambda_data[localB->SFunction_DIMS2_tmp_tmp] = 2.77 - 0.0 * localB->cosinus_day;
            }
            else if (localB->latitude > 75.0)
            {
                localB->pressure_data[localB->SFunction_DIMS2_tmp_tmp] = 1013.0 - -0.5 * localB->cosinus_day;
                localB->temperature_data[localB->SFunction_DIMS2_tmp_tmp] = 263.65 - 14.5 * localB->cosinus_day;
                localB->water_vapour_pressure_data[localB->SFunction_DIMS2_tmp_tmp] = 4.11 - 3.39 * localB->cosinus_day;
                localB->beta_data[localB->SFunction_DIMS2_tmp_tmp] = 0.00453 - 0.00062 * localB->cosinus_day;
                localB->lambda_data[localB->SFunction_DIMS2_tmp_tmp] = 1.55 - 0.3 * localB->cosinus_day;
            }
            else
            {
                for (localB->k = 0; localB->k < 5; localB->k++)
                {
                    localB->d = 15.0 * static_cast<real_T>(localB->k) + 15.0;
                    localB->dv[localB->k] = localB->d;
                    localB->dv1[localB->k] = localB->d;
                }

                localB->pressure_data[localB->SFunction_DIMS2_tmp_tmp] = GNSSPreProcessingDualAn_interp1(localB->dv, j,
                    localB->latitude, localB) - GNSSPreProcessingDualAn_interp1(localB->dv1, l, localB->latitude, localB)
                    * localB->cosinus_day;
                for (localB->k = 0; localB->k < 5; localB->k++)
                {
                    localB->d = 15.0 * static_cast<real_T>(localB->k) + 15.0;
                    localB->dv[localB->k] = localB->d;
                    localB->dv1[localB->k] = localB->d;
                }

                localB->temperature_data[localB->SFunction_DIMS2_tmp_tmp] = GNSSPreProcessingDualAn_interp1(localB->dv,
                    m, localB->latitude, localB) - GNSSPreProcessingDualAn_interp1(localB->dv1, n, localB->latitude,
                    localB) * localB->cosinus_day;
                for (localB->k = 0; localB->k < 5; localB->k++)
                {
                    localB->d = 15.0 * static_cast<real_T>(localB->k) + 15.0;
                    localB->dv[localB->k] = localB->d;
                    localB->dv1[localB->k] = localB->d;
                }

                localB->water_vapour_pressure_data[localB->SFunction_DIMS2_tmp_tmp] = GNSSPreProcessingDualAn_interp1
                    (localB->dv, o, localB->latitude, localB) - GNSSPreProcessingDualAn_interp1(localB->dv1, p,
                    localB->latitude, localB) * localB->cosinus_day;
                for (localB->k = 0; localB->k < 5; localB->k++)
                {
                    localB->d = 15.0 * static_cast<real_T>(localB->k) + 15.0;
                    localB->dv[localB->k] = localB->d;
                    localB->dv1[localB->k] = localB->d;
                }

                localB->beta_data[localB->SFunction_DIMS2_tmp_tmp] = GNSSPreProcessingDualAn_interp1(localB->dv, q,
                    localB->latitude, localB) - GNSSPreProcessingDualAn_interp1(localB->dv1, r, localB->latitude, localB)
                    * localB->cosinus_day;
                for (localB->k = 0; localB->k < 5; localB->k++)
                {
                    localB->d = 15.0 * static_cast<real_T>(localB->k) + 15.0;
                    localB->dv[localB->k] = localB->d;
                    localB->dv1[localB->k] = localB->d;
                }

                localB->lambda_data[localB->SFunction_DIMS2_tmp_tmp] = GNSSPreProcessingDualAn_interp1(localB->dv, s,
                    localB->latitude, localB) - GNSSPreProcessingDualAn_interp1(localB->dv1, t, localB->latitude, localB)
                    * localB->cosinus_day;
            }
        }

        localB->latitude = rtu_userPosLlh[2];
        localB->x_tmp_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localB->loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localB->SFunction_DIMS2_tmp_tmp = (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) / 2) << 1;
        localB->vectorUB = localB->SFunction_DIMS2_tmp_tmp - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_1 = _mm_loadu_pd(&localB->beta_data[localB->k]);
            tmp_0 = _mm_loadu_pd(&localB->temperature_data[localB->k]);
            _mm_storeu_pd(&localB->x_tmp_data[localB->k], _mm_sub_pd(_mm_set1_pd(1.0), _mm_div_pd(_mm_mul_pd(tmp_1,
                             _mm_set1_pd(localB->latitude)), tmp_0)));
        }

        for (localB->k = localB->SFunction_DIMS2_tmp_tmp; localB->k < localB->loop_ub; localB->k++)
        {
            localB->x_tmp_data[localB->k] = 1.0 - localB->beta_data[localB->k] * localB->latitude /
                localB->temperature_data[localB->k];
        }

        localB->b_b_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localB->loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localB->SFunction_DIMS2_tmp_tmp = (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) / 2) << 1;
        localB->vectorUB = localB->SFunction_DIMS2_tmp_tmp - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            __m128d tmp;
            tmp_1 = _mm_loadu_pd(&localB->lambda_data[localB->k]);
            tmp_0 = _mm_set1_pd(1.0);
            tmp = _mm_loadu_pd(&localB->beta_data[localB->k]);
            _mm_storeu_pd(&localB->b_b_data[localB->k], _mm_sub_pd(_mm_div_pd(_mm_div_pd(_mm_mul_pd(_mm_add_pd(tmp_1,
                               tmp_0), _mm_set1_pd(9.80665)), _mm_set1_pd(287.054)), tmp), tmp_0));
        }

        for (localB->k = localB->SFunction_DIMS2_tmp_tmp; localB->k < localB->loop_ub; localB->k++)
        {
            localB->b_b_data[localB->k] = (localB->lambda_data[localB->k] + 1.0) * 9.80665 / 287.054 / localB->
                beta_data[localB->k] - 1.0;
        }

        if (localB->x_tmp_size == localB->b_b_size)
        {
            localB->loop_ub = localB->x_tmp_size;
            for (localB->k = 0; localB->k < localB->loop_ub; localB->k++)
            {
                localB->d_data[localB->k] = GNSSPreProcessing_rt_powd_snf_b(localB->x_tmp_data[localB->k],
                    localB->b_b_data[localB->k], localB);
            }

            localDW->SFunction_DIMS2 = localB->x_tmp_size;
            localB->loop_ub = localB->x_tmp_size;
            if (localB->loop_ub - 1 >= 0)
            {
                std::memcpy(&localB->troposphericDelay[0], &localB->d_data[0], static_cast<uint32_T>(localB->loop_ub) *
                            sizeof(real_T));
            }
        }
        else
        {
            GNSSPreProcessingD_expand_power(localB->x_tmp_data, &localB->x_tmp_size, localB->b_b_data, &localB->b_b_size,
                localB->d_data, &localB->d_size, localB);
            localDW->SFunction_DIMS2 = localB->d_size;
            localB->loop_ub = localB->d_size;
            if (localB->loop_ub - 1 >= 0)
            {
                std::memcpy(&localB->troposphericDelay[0], &localB->d_data[0], static_cast<uint32_T>(localB->loop_ub) *
                            sizeof(real_T));
            }
        }

        localB->b_b_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localB->loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localB->SFunction_DIMS2_tmp_tmp = (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) / 2) << 1;
        localB->vectorUB = localB->SFunction_DIMS2_tmp_tmp - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_1 = _mm_loadu_pd(&localB->beta_data[localB->k]);
            _mm_storeu_pd(&localB->b_b_data[localB->k], _mm_div_pd(_mm_set1_pd(0.034163084297727957), tmp_1));
        }

        for (localB->k = localB->SFunction_DIMS2_tmp_tmp; localB->k < localB->loop_ub; localB->k++)
        {
            localB->b_b_data[localB->k] = 0.034163084297727957 / localB->beta_data[localB->k];
        }

        if (localB->x_tmp_size == static_cast<int8_T>(*rtu_elevationAngle_DIMS1))
        {
            localB->d_size = localB->x_tmp_size;
            localB->loop_ub = localB->x_tmp_size;
            for (localB->k = 0; localB->k < localB->loop_ub; localB->k++)
            {
                localB->d_data[localB->k] = GNSSPreProcessing_rt_powd_snf_b(localB->x_tmp_data[localB->k],
                    localB->b_b_data[localB->k], localB);
            }
        }
        else
        {
            GNSSPreProcessingD_expand_power(localB->x_tmp_data, &localB->x_tmp_size, localB->b_b_data, &localB->b_b_size,
                localB->d_data, &localB->d_size, localB);
        }

        localB->SFunction_DIMS2_tmp_tmp = (*rtu_elevationAngle_DIMS1 / 2) << 1;
        localB->vectorUB = localB->SFunction_DIMS2_tmp_tmp - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_1 = _mm_loadu_pd(&rtu_elevationAngle[localB->k]);
            _mm_storeu_pd(&localB->dv9[0], _mm_sub_pd(_mm_set1_pd(4.0), _mm_mul_pd(_mm_div_pd(tmp_1, _mm_set1_pd(180.0)),
                            _mm_set1_pd(3.1415926535897931))));
            localB->dv8[0] = std::fmax(0.0, localB->dv9[0]);
            localB->dv8[1] = std::fmax(0.0, localB->dv9[1]);
            tmp_1 = _mm_loadu_pd(&localB->dv8[0]);
            _mm_storeu_pd(&localB->x_tmp_data[localB->k], _mm_mul_pd(tmp_1, tmp_1));
        }

        localB->vectorUB = localB->SFunction_DIMS2_tmp_tmp - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_1 = _mm_loadu_pd(&rtu_elevationAngle[localB->k]);
            _mm_storeu_pd(&localB->dv7[0], _mm_sub_pd(_mm_set1_pd(4.0), _mm_mul_pd(_mm_div_pd(tmp_1, _mm_set1_pd(180.0)),
                            _mm_set1_pd(3.1415926535897931))));
            localB->dv6[0] = std::fmax(0.0, localB->dv7[0]);
            localB->dv6[1] = std::fmax(0.0, localB->dv7[1]);
            tmp_1 = _mm_loadu_pd(&localB->dv6[0]);
            _mm_storeu_pd(&localB->b_b_data[localB->k], _mm_mul_pd(tmp_1, tmp_1));
        }

        localB->vectorUB = localB->SFunction_DIMS2_tmp_tmp - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_1 = _mm_loadu_pd(&rtu_elevationAngle[localB->k]);
            _mm_storeu_pd(&localB->dv5[0], _mm_sub_pd(_mm_set1_pd(4.0), _mm_mul_pd(_mm_div_pd(tmp_1, _mm_set1_pd(180.0)),
                            _mm_set1_pd(3.1415926535897931))));
            localB->dv4[0] = std::fmax(0.0, localB->dv5[0]);
            localB->dv4[1] = std::fmax(0.0, localB->dv5[1]);
            tmp_1 = _mm_loadu_pd(&localB->dv4[0]);
            _mm_storeu_pd(&localB->x_tmp_data[localB->k], _mm_mul_pd(tmp_1, tmp_1));
        }

        localB->vectorUB = localB->SFunction_DIMS2_tmp_tmp - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_1 = _mm_loadu_pd(&rtu_elevationAngle[localB->k]);
            _mm_storeu_pd(&localB->dv3[0], _mm_sub_pd(_mm_set1_pd(4.0), _mm_mul_pd(_mm_div_pd(tmp_1, _mm_set1_pd(180.0)),
                            _mm_set1_pd(3.1415926535897931))));
            localB->dv2[0] = std::fmax(0.0, localB->dv3[0]);
            localB->dv2[1] = std::fmax(0.0, localB->dv3[1]);
            tmp_1 = _mm_loadu_pd(&localB->dv2[0]);
            _mm_storeu_pd(&localB->x_tmp_data[localB->k], _mm_mul_pd(tmp_1, tmp_1));
        }

        if ((localDW->SFunction_DIMS2 == static_cast<int8_T>(*rtu_elevationAngle_DIMS1)) && (static_cast<int8_T>
                (*rtu_elevationAngle_DIMS1) == localB->d_size) && ((localB->d_size == 1 ? static_cast<int32_T>(
                static_cast<int8_T>(*rtu_elevationAngle_DIMS1)) : localB->d_size) == (localDW->SFunction_DIMS2 == 1 ?
                static_cast<int32_T>(static_cast<int8_T>(*rtu_elevationAngle_DIMS1)) : localDW->SFunction_DIMS2)) &&
                (((localDW->SFunction_DIMS2 == 1 ? static_cast<int32_T>(static_cast<int8_T>(*rtu_elevationAngle_DIMS1)) :
                   localDW->SFunction_DIMS2) == 1 ? localB->d_size == 1 ? static_cast<int32_T>(static_cast<int8_T>
                (*rtu_elevationAngle_DIMS1)) : localB->d_size : localDW->SFunction_DIMS2 == 1 ? static_cast<int32_T>(
                static_cast<int8_T>(*rtu_elevationAngle_DIMS1)) : localDW->SFunction_DIMS2) == *rtu_elevationAngle_DIMS1))
        {
            localB->pressure_size = localDW->SFunction_DIMS2;
            for (localB->k = 0; localB->k < localDW->SFunction_DIMS2; localB->k++)
            {
                localB->latitude = std::fmax(0.0, 4.0 - rtu_elevationAngle[localB->k] / 180.0 * 3.1415926535897931);
                localB->pressure_data[localB->k] = (109.65462799999999 / ((localB->lambda_data[localB->k] + 1.0) * 9.784
                    - localB->beta_data[localB->k] * 287.054) * localB->water_vapour_pressure_data[localB->k] /
                    localB->temperature_data[localB->k] * localB->d_data[localB->k] + 0.022276538615999996 *
                    localB->pressure_data[localB->k] / 9.784 * localB->troposphericDelay[localB->k]) *
                    ((localB->latitude * localB->latitude * 0.015 + 1.0) * (1.001 / localB->x_data[localB->k]) *
                     static_cast<real_T>((rtu_elevationAngle[localB->k] >= 0.034906585039886591) &&
                      (rtu_elevationAngle[localB->k] < 0.069813170079773182)) + 1.001 / localB->y_data[localB->k] *
                     static_cast<real_T>(rtu_elevationAngle[localB->k] >= 0.087266462599716474));
            }
        }
        else
        {
            GNSSPreProc_binary_expand_op_gi(localB->pressure_data, &localB->pressure_size, localB->troposphericDelay,
                localDW->SFunction_DIMS2, localB->d_data, &localB->d_size, localB->lambda_data, &localB->lambda_size,
                localB->beta_data, &localB->beta_size, localB->water_vapour_pressure_data,
                &localB->water_vapour_pressure_size, localB->temperature_data, &localB->temperature_size, localB->y_data,
                &localB->y_size, rtu_elevationAngle, rtu_elevationAngle_DIMS1, localB->x_data, &localB->x_size, localB);
        }

        localDW->SFunction_DIMS2 = localB->pressure_size;
        localB->loop_ub = localB->pressure_size;
        if (localB->loop_ub - 1 >= 0)
        {
            std::memcpy(&localB->troposphericDelay[0], &localB->pressure_data[0], static_cast<uint32_T>(localB->loop_ub)
                        * sizeof(real_T));
        }
    }
    else
    {
        localB->SFunction_DIMS2_tmp_tmp = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        localDW->SFunction_DIMS2 = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
        if (localB->SFunction_DIMS2_tmp_tmp - 1 >= 0)
        {
            std::memset(&localB->troposphericDelay[0], 0, static_cast<uint32_T>(localB->SFunction_DIMS2_tmp_tmp) *
                        sizeof(real_T));
        }
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
