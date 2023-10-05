//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateSatelliteClockCorrecti.cpp
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
#include "GNSSPreProcessingDualAntenna_types.h"
#include "GNSSPreProcessingDualAntenna.h"
#include <emmintrin.h>
#include <cmath>
#include <cstring>
#include "CalculateSatelliteClockCorrecti.h"

void GNSSPreProcessingDualAntenna::GNSS_binary_expand_op_ngwdjig3x(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const gnssops_navigation_data *in3, const gnssops_navigation_data_size *in4,
    B_CalculateSatelliteClockCorr_T *localB)
{
    in1_size[0] = 1;
    in1_size[1] = in4->T_oc == 1 ? in2_size[1] : in4->T_oc;
    localB->stride_0_1_da = (in2_size[1] != 1);
    localB->stride_1_1_e = (in4->T_oc != 1);
    localB->loop_ub_bj = in4->T_oc == 1 ? in2_size[1] : in4->T_oc;
    for (localB->i9 = 0; localB->i9 < localB->loop_ub_bj; localB->i9++)
    {
        in1_data[localB->i9] = in2_data[localB->i9 * localB->stride_0_1_da] - in3->T_oc[localB->i9 *
            localB->stride_1_1_e];
    }
}

void GNSSPreProcessingDualAntenna::GNSSP_binary_expand_op_ngwdjig3(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const gnssops_navigation_data *in3, const gnssops_navigation_data_size *in4,
    B_CalculateSatelliteClockCorr_T *localB)
{
    in1_size[0] = 1;
    in1_size[1] = in4->T_oe == 1 ? in2_size[1] : in4->T_oe;
    localB->stride_0_1_l = (in2_size[1] != 1);
    localB->stride_1_1_h = (in4->T_oe != 1);
    localB->loop_ub_bn = in4->T_oe == 1 ? in2_size[1] : in4->T_oe;
    for (localB->i8 = 0; localB->i8 < localB->loop_ub_bn; localB->i8++)
    {
        in1_data[localB->i8] = in2_data[localB->i8 * localB->stride_0_1_l] - in3->T_oe[localB->i8 * localB->stride_1_1_h];
    }
}

real_T GNSSPreProcessingDualAntenna::GNSSPreProcessingDu_rt_powd_snf(real_T u0, real_T u1,
    B_CalculateSatelliteClockCorr_T *localB)
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

void GNSSPreProcessingDualAntenna::GNSSPr_binary_expand_op_ngwdjig(real_T in1_data[], int32_T in1_size[2], const
    gnssops_navigation_data *in2, const gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T
    in4_size[2], const real_T in5_data[], const int32_T in5_size[2], B_CalculateSatelliteClockCorr_T *localB)
{
    in1_size[0] = 1;
    in1_size[1] = (in5_size[1] == 1 ? in3->DELTA_N == 1 ? in4_size[1] : in3->DELTA_N : in5_size[1]) == 1 ? in3->M_0 :
        in5_size[1] == 1 ? in3->DELTA_N == 1 ? in4_size[1] : in3->DELTA_N : in5_size[1];
    localB->stride_0_1_p = (in3->M_0 != 1);
    localB->stride_1_1_cv = (in4_size[1] != 1);
    localB->stride_2_1_f = (in3->DELTA_N != 1);
    localB->stride_3_1_g = (in5_size[1] != 1);
    localB->loop_ub_g = (in5_size[1] == 1 ? in3->DELTA_N == 1 ? in4_size[1] : in3->DELTA_N : in5_size[1]) == 1 ?
        in3->M_0 : in5_size[1] == 1 ? in3->DELTA_N == 1 ? in4_size[1] : in3->DELTA_N : in5_size[1];
    for (localB->i2 = 0; localB->i2 < localB->loop_ub_g; localB->i2++)
    {
        localB->d = in5_data[localB->i2 * localB->stride_3_1_g];
        in1_data[localB->i2] = ((localB->d - static_cast<real_T>(localB->d > 302400.0) * 604800.0) + static_cast<real_T>
                                (localB->d < -302400.0) * 604800.0) * (in4_data[localB->i2 * localB->stride_1_1_cv] +
            in2->DELTA_N[localB->i2 * localB->stride_2_1_f]) + in2->M_0[localB->i2 * localB->stride_0_1_p];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPre_binary_expand_op_ngwdji(real_T in1_data[], int32_T in1_size[2], const
    gnssops_navigation_data *in2, const gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T
    in4_size[2], B_CalculateSatelliteClockCorr_T *localB)
{
    in1_size[0] = 1;
    in1_size[1] = (in4_size[1] == 1 ? in3->E : in4_size[1]) == 1 ? in3->E : in4_size[1] == 1 ? in3->E : in4_size[1];
    localB->stride_0_1_d = (in3->E != 1);
    localB->stride_1_1_g = (in3->E != 1);
    localB->stride_2_1_l = (in4_size[1] != 1);
    localB->loop_ub_d = (in4_size[1] == 1 ? in3->E : in4_size[1]) == 1 ? in3->E : in4_size[1] == 1 ? in3->E : in4_size[1];
    for (localB->i5 = 0; localB->i5 < localB->loop_ub_d; localB->i5++)
    {
        in1_data[localB->i5] = static_cast<real_T>(in2->E[localB->i5 * localB->stride_0_1_d] > 0.8) * 3.1415926535897931
            + static_cast<real_T>(in2->E[localB->i5 * localB->stride_1_1_g] <= 0.8) * in4_data[localB->i5 *
            localB->stride_2_1_l];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProce_binary_expand_op_n(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const gnssops_navigation_data *in3, const gnssops_navigation_data_size *in4,
    const real_T in5_data[], const int32_T in5_size[2], B_CalculateSatelliteClockCorr_T *localB)
{
    in1_size[0] = 1;
    in1_size[1] = (in5_size[1] == 1 ? in4->E : in5_size[1]) == 1 ? in2_size[1] : in5_size[1] == 1 ? in4->E : in5_size[1];
    localB->stride_0_1_m = (in2_size[1] != 1);
    localB->stride_1_1_n = (in4->E != 1);
    localB->stride_2_1_p = (in5_size[1] != 1);
    localB->loop_ub_l = (in5_size[1] == 1 ? in4->E : in5_size[1]) == 1 ? in2_size[1] : in5_size[1] == 1 ? in4->E :
        in5_size[1];
    for (localB->i3 = 0; localB->i3 < localB->loop_ub_l; localB->i3++)
    {
        in1_data[localB->i3] = in3->E[localB->i3 * localB->stride_1_1_n] * in5_data[localB->i3 * localB->stride_2_1_p] +
            in2_data[localB->i3 * localB->stride_0_1_m];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreP_binary_expand_op_ngwdj(real_T in1_data[], int32_T in1_size[2], const
    gnssops_navigation_data *in2, const gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T
    in4_size[2], const real_T in5_data[], const int32_T in5_size[2], B_CalculateSatelliteClockCorr_T *localB)
{
    in1_size[0] = 1;
    in1_size[1] = (in5_size[1] == 1 ? in3->SQRT_A == 1 ? in3->E : in3->SQRT_A : in5_size[1]) == 1 ? (in4_size[1] == 1 ?
        in3->A_f2 : in4_size[1]) == 1 ? (in4_size[1] == 1 ? in3->A_f1 : in4_size[1]) == 1 ? in3->A_f0 : in4_size[1] == 1
        ? in3->A_f1 : in4_size[1] : in4_size[1] == 1 ? in3->A_f2 : in4_size[1] : in5_size[1] == 1 ? in3->SQRT_A == 1 ?
        in3->E : in3->SQRT_A : in5_size[1];
    localB->stride_0_1_k = (in3->A_f0 != 1);
    localB->stride_1_1_c = (in3->A_f1 != 1);
    localB->stride_2_1 = (in4_size[1] != 1);
    localB->stride_3_1 = (in3->A_f2 != 1);
    localB->stride_4_1 = (in4_size[1] != 1);
    localB->stride_5_1 = (in3->E != 1);
    localB->stride_6_1 = (in3->SQRT_A != 1);
    localB->stride_7_1 = (in5_size[1] != 1);
    localB->loop_ub_b = (in5_size[1] == 1 ? in3->SQRT_A == 1 ? in3->E : in3->SQRT_A : in5_size[1]) == 1 ? (in4_size[1] ==
        1 ? in3->A_f2 : in4_size[1]) == 1 ? (in4_size[1] == 1 ? in3->A_f1 : in4_size[1]) == 1 ? in3->A_f0 : in4_size[1] ==
        1 ? in3->A_f1 : in4_size[1] : in4_size[1] == 1 ? in3->A_f2 : in4_size[1] : in5_size[1] == 1 ? in3->SQRT_A == 1 ?
        in3->E : in3->SQRT_A : in5_size[1];
    for (localB->i1 = 0; localB->i1 < localB->loop_ub_b; localB->i1++)
    {
        localB->varargin_1 = in4_data[localB->i1 * localB->stride_4_1];
        in1_data[localB->i1] = ((in2->A_f1[localB->i1 * localB->stride_1_1_c] * in4_data[localB->i1 * localB->stride_2_1]
            + in2->A_f0[localB->i1 * localB->stride_0_1_k]) + in2->A_f2[localB->i1 * localB->stride_3_1] *
                                (localB->varargin_1 * localB->varargin_1)) + in2->E[localB->i1 * localB->stride_5_1] *
            -4.44280763339306E-10 * in2->SQRT_A[localB->i1 * localB->stride_6_1] * in5_data[localB->i1 *
            localB->stride_7_1];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAnte_minus(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], B_CalculateSatelliteClockCorr_T *localB)
{
    localB->in2_size_idx_1 = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
    localB->stride_0_1 = (in2_size[1] != 1);
    localB->stride_1_1 = (in1_size[1] != 1);
    localB->loop_ub_c = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
    for (localB->i_m = 0; localB->i_m < localB->loop_ub_c; localB->i_m++)
    {
        localB->in2_data[localB->i_m] = in2_data[localB->i_m * localB->stride_0_1] - in1_data[localB->i_m *
            localB->stride_1_1];
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in2_size_idx_1;
    if (localB->in2_size_idx_1 - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in2_data[0], static_cast<uint32_T>(localB->in2_size_idx_1) * sizeof(real_T));
    }
}

void GNSSPreProcessingDualAntenna::GNSSPrePr_binary_expand_op_ngwd(real_T in1_data[], int32_T *in1_size, const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3[110], const gnssops_navigation_data *in4, const
    gnssops_navigation_data_size *in5, B_CalculateSatelliteClockCorr_T *localB)
{
    *in1_size = in5->SVID == 1 ? in2_size[1] : in5->SVID;
    localB->stride_0_0_b = (in2_size[1] != 1);
    localB->stride_1_0_n = (in5->SVID != 1);
    localB->loop_ub_bs = in5->SVID == 1 ? in2_size[1] : in5->SVID;
    for (localB->i7 = 0; localB->i7 < localB->loop_ub_bs; localB->i7++)
    {
        in1_data[localB->i7] = in3[static_cast<int32_T>(in4->SVID[localB->i7 * localB->stride_1_0_n]) - 1] +
            in2_data[localB->i7 * localB->stride_0_0_b];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPrePro_binary_expand_op_ngw(real_T in1_data[], int32_T *in1_size, const
    gnssops_navigation_data *in2, const gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T
    in4_size[2], B_CalculateSatelliteClockCorr_T *localB)
{
    *in1_size = (in4_size[1] == 1 ? in3->A_f2 : in4_size[1]) == 1 ? in3->A_f1 : in4_size[1] == 1 ? in3->A_f2 : in4_size
        [1];
    localB->stride_0_0 = (in3->A_f1 != 1);
    localB->stride_1_0 = (in3->A_f2 != 1);
    localB->stride_2_0 = (in4_size[1] != 1);
    localB->loop_ub_j = (in4_size[1] == 1 ? in3->A_f2 : in4_size[1]) == 1 ? in3->A_f1 : in4_size[1] == 1 ? in3->A_f2 :
        in4_size[1];
    for (localB->i4 = 0; localB->i4 < localB->loop_ub_j; localB->i4++)
    {
        in1_data[localB->i4] = in2->A_f2[localB->i4 * localB->stride_1_0] * 2.0 * in4_data[localB->i4 *
            localB->stride_2_0] + in2->A_f1[localB->i4 * localB->stride_0_0];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_ng(real_T in1_data[], int32_T *in1_size, const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2],
    B_CalculateSatelliteClockCorr_T *localB)
{
    *in1_size = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
    localB->stride_0_0_d = (in2_size[1] != 1);
    localB->stride_1_0_l = (in3_size[1] != 1);
    localB->loop_ub_o = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
    for (localB->i6 = 0; localB->i6 < localB->loop_ub_o; localB->i6++)
    {
        in1_data[localB->i6] = in2_data[localB->i6 * localB->stride_0_0_d] - in3_data[localB->i6 * localB->stride_1_0_l];
    }
}

//
// Output and update for atomic system:
//    '<S32>/Calculate Satellite Clock Correction'
//    '<S40>/Calculate Satellite Clock Correction'
//    '<S48>/Calculate Satellite Clock Correction'
//    '<S81>/Calculate Satellite Clock Correction'
//    '<S89>/Calculate Satellite Clock Correction'
//    '<S97>/Calculate Satellite Clock Correction'
//    '<S105>/Calculate Satellite Clock Correction'
//    '<S159>/Calculate Satellite Clock Correction'
//    '<S167>/Calculate Satellite Clock Correction'
//    '<S175>/Calculate Satellite Clock Correction'
//    ...
//
void GNSSPreProcessingDualAntenna::CalculateSatelliteClockCorrecti(real_T rtu_TOW, const gnssops_navigation_data
    *rtu_GnssNavBus, const gnssops_navigation_data_size *rtu_GnssNavBus_DIMS1, const real_T rtu_pseudorange[40], const
    int32_T *rtu_pseudorange_DIMS1, real_T rtu_enableSatClockCorr, const real_T rtu_delta_t_sv_EGNOS[110],
    B_CalculateSatelliteClockCorr_T *localB, DW_CalculateSatelliteClockCor_T *localDW)
{
    __m128d tmp;
    __m128d tmp_4;
    __m128d tmp_5;
    localB->t_sv_emission_size[0] = 1;
    localB->t_sv_emission_size[1] = *rtu_pseudorange_DIMS1;
    localB->scalarLB = (*rtu_pseudorange_DIMS1 / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
    {
        tmp_5 = _mm_loadu_pd(&rtu_pseudorange[localB->k]);
        _mm_storeu_pd(&localB->t_sv_emission_data[localB->k], _mm_sub_pd(_mm_set1_pd(rtu_TOW), _mm_div_pd(tmp_5,
                        _mm_set1_pd(2.99792458E+8))));
    }

    for (localB->k = localB->scalarLB; localB->k < *rtu_pseudorange_DIMS1; localB->k++)
    {
        localB->t_sv_emission_data[localB->k] = rtu_TOW - rtu_pseudorange[localB->k] / 2.99792458E+8;
    }

    if (*rtu_pseudorange_DIMS1 == rtu_GnssNavBus_DIMS1->T_oc)
    {
        localB->t_d_size[1] = *rtu_pseudorange_DIMS1;
        localB->loop_ub = *rtu_pseudorange_DIMS1;
        localB->scalarLB = (*rtu_pseudorange_DIMS1 / 2) << 1;
        localB->vectorUB = localB->scalarLB - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_5 = _mm_loadu_pd(&localB->t_sv_emission_data[localB->k]);
            tmp_4 = _mm_loadu_pd(&rtu_GnssNavBus->T_oc[localB->k]);
            _mm_storeu_pd(&localB->t_d_data[localB->k], _mm_sub_pd(tmp_5, tmp_4));
        }

        for (localB->k = localB->scalarLB; localB->k < localB->loop_ub; localB->k++)
        {
            localB->t_d_data[localB->k] = localB->t_sv_emission_data[localB->k] - rtu_GnssNavBus->T_oc[localB->k];
        }
    }
    else
    {
        GNSS_binary_expand_op_ngwdjig3x(localB->t_d_data, localB->t_d_size, localB->t_sv_emission_data,
            localB->t_sv_emission_size, rtu_GnssNavBus, rtu_GnssNavBus_DIMS1, localB);
    }

    localB->t_d_size[0] = 1;
    localB->loop_ub = localB->t_d_size[1] - 1;
    for (localB->k = 0; localB->k <= localB->loop_ub; localB->k++)
    {
        localB->t_d = localB->t_d_data[localB->k];
        localB->t_d_data[localB->k] = (localB->t_d - static_cast<real_T>(localB->t_d > 302400.0) * 604800.0) +
            static_cast<real_T>(localB->t_d < -302400.0) * 604800.0;
    }

    if (*rtu_pseudorange_DIMS1 == rtu_GnssNavBus_DIMS1->T_oe)
    {
        localB->t_k_size[0] = 1;
        localB->t_k_size[1] = *rtu_pseudorange_DIMS1;
        localB->loop_ub = *rtu_pseudorange_DIMS1;
        localB->scalarLB = (*rtu_pseudorange_DIMS1 / 2) << 1;
        localB->vectorUB = localB->scalarLB - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_5 = _mm_loadu_pd(&localB->t_sv_emission_data[localB->k]);
            tmp_4 = _mm_loadu_pd(&rtu_GnssNavBus->T_oe[localB->k]);
            _mm_storeu_pd(&localB->t_k_data[localB->k], _mm_sub_pd(tmp_5, tmp_4));
        }

        for (localB->k = localB->scalarLB; localB->k < localB->loop_ub; localB->k++)
        {
            localB->t_k_data[localB->k] = localB->t_sv_emission_data[localB->k] - rtu_GnssNavBus->T_oe[localB->k];
        }
    }
    else
    {
        GNSSP_binary_expand_op_ngwdjig3(localB->t_k_data, localB->t_k_size, localB->t_sv_emission_data,
            localB->t_sv_emission_size, rtu_GnssNavBus, rtu_GnssNavBus_DIMS1, localB);
    }

    localB->n_0_size[0] = 1;
    localB->n_0_size[1] = rtu_GnssNavBus_DIMS1->SQRT_A;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->SQRT_A;
    for (localB->k = 0; localB->k < localB->loop_ub; localB->k++)
    {
        localB->t_d = rtu_GnssNavBus->SQRT_A[localB->k];
        localB->n_0_data[localB->k] = 3.986005E+14 / GNSSPreProcessingDu_rt_powd_snf(localB->t_d * localB->t_d, 3.0,
            localB);
    }

    localB->i = rtu_GnssNavBus_DIMS1->SQRT_A;
    localB->scalarLB = (rtu_GnssNavBus_DIMS1->SQRT_A / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
    {
        tmp_5 = _mm_loadu_pd(&localB->n_0_data[localB->k]);
        _mm_storeu_pd(&localB->n_0_data[localB->k], _mm_sqrt_pd(tmp_5));
    }

    for (localB->k = localB->scalarLB; localB->k < localB->i; localB->k++)
    {
        localB->n_0_data[localB->k] = std::sqrt(localB->n_0_data[localB->k]);
    }

    if ((rtu_GnssNavBus_DIMS1->SQRT_A == rtu_GnssNavBus_DIMS1->DELTA_N) && ((rtu_GnssNavBus_DIMS1->SQRT_A == 1 ?
            rtu_GnssNavBus_DIMS1->DELTA_N : rtu_GnssNavBus_DIMS1->SQRT_A) == localB->t_k_size[1]) &&
            (((rtu_GnssNavBus_DIMS1->SQRT_A == 1 ? rtu_GnssNavBus_DIMS1->DELTA_N : rtu_GnssNavBus_DIMS1->SQRT_A) == 1 ?
              localB->t_k_size[1] : rtu_GnssNavBus_DIMS1->SQRT_A == 1 ? rtu_GnssNavBus_DIMS1->DELTA_N :
              rtu_GnssNavBus_DIMS1->SQRT_A) == rtu_GnssNavBus_DIMS1->M_0))
    {
        localB->M_k_size[0] = 1;
        localB->M_k_size[1] = rtu_GnssNavBus_DIMS1->M_0;
        localB->loop_ub = rtu_GnssNavBus_DIMS1->M_0;
        for (localB->k = 0; localB->k < localB->loop_ub; localB->k++)
        {
            localB->t_d = localB->t_k_data[localB->k];
            localB->M_k_data[localB->k] = ((localB->t_d - static_cast<real_T>(localB->t_d > 302400.0) * 604800.0) +
                static_cast<real_T>(localB->t_d < -302400.0) * 604800.0) * (localB->n_0_data[localB->k] +
                rtu_GnssNavBus->DELTA_N[localB->k]) + rtu_GnssNavBus->M_0[localB->k];
        }
    }
    else
    {
        GNSSPr_binary_expand_op_ngwdjig(localB->M_k_data, localB->M_k_size, rtu_GnssNavBus, rtu_GnssNavBus_DIMS1,
            localB->n_0_data, localB->n_0_size, localB->t_k_data, localB->t_k_size, localB);
    }

    if ((rtu_GnssNavBus_DIMS1->E == localB->M_k_size[1]) && ((rtu_GnssNavBus_DIMS1->E == 1 ? localB->M_k_size[1] :
            rtu_GnssNavBus_DIMS1->E) == rtu_GnssNavBus_DIMS1->E))
    {
        localB->E_k_size[0] = 1;
        localB->E_k_size[1] = rtu_GnssNavBus_DIMS1->E;
        localB->loop_ub = rtu_GnssNavBus_DIMS1->E;
        for (localB->k = 0; localB->k < localB->loop_ub; localB->k++)
        {
            localB->E_k_data[localB->k] = static_cast<real_T>(rtu_GnssNavBus->E[localB->k] > 0.8) * 3.1415926535897931 +
                static_cast<real_T>(rtu_GnssNavBus->E[localB->k] <= 0.8) * localB->M_k_data[localB->k];
        }
    }
    else
    {
        GNSSPre_binary_expand_op_ngwdji(localB->E_k_data, localB->E_k_size, rtu_GnssNavBus, rtu_GnssNavBus_DIMS1,
            localB->M_k_data, localB->M_k_size, localB);
    }

    localB->i = 0;
    localB->n_0_size[1] = localB->E_k_size[1];
    localB->loop_ub = localB->E_k_size[1];
    for (localB->k = 0; localB->k < localB->loop_ub; localB->k++)
    {
        localB->n_0_data[localB->k] = 1.0;
    }

    int32_T exitg1;
    do
    {
        boolean_T exitg2;
        exitg1 = 0;
        localB->vectorUB = localB->n_0_size[1];
        localB->loop_ub = localB->n_0_size[1];
        for (localB->k = 0; localB->k < localB->loop_ub; localB->k++)
        {
            localB->x_data[localB->k] = (localB->n_0_data[localB->k] > 1.0E-15);
        }

        localB->y = false;
        localB->k = 1;
        exitg2 = false;
        while ((!exitg2) && (localB->k <= localB->vectorUB))
        {
            if (localB->x_data[localB->k - 1])
            {
                localB->y = true;
                exitg2 = true;
            }
            else
            {
                localB->k++;
            }
        }

        if (localB->y && (localB->i < 20))
        {
            localB->t_k_size[0] = 1;
            localB->t_k_size[1] = localB->E_k_size[1];
            localB->loop_ub = localB->E_k_size[1];
            if (localB->loop_ub - 1 >= 0)
            {
                std::memcpy(&localB->t_k_data[0], &localB->E_k_data[0], static_cast<uint32_T>(localB->loop_ub) * sizeof
                            (real_T));
            }

            localB->n_0_size[0] = 1;
            localB->n_0_size[1] = localB->E_k_size[1];
            localB->loop_ub = localB->E_k_size[1];
            if (localB->loop_ub - 1 >= 0)
            {
                std::memcpy(&localB->n_0_data[0], &localB->E_k_data[0], static_cast<uint32_T>(localB->loop_ub) * sizeof
                            (real_T));
            }

            localB->scalarLB = localB->E_k_size[1];
            for (localB->k = 0; localB->k < localB->scalarLB; localB->k++)
            {
                localB->n_0_data[localB->k] = std::sin(localB->n_0_data[localB->k]);
            }

            if ((rtu_GnssNavBus_DIMS1->E == localB->E_k_size[1]) && ((rtu_GnssNavBus_DIMS1->E == 1 ? localB->E_k_size[1]
                  : rtu_GnssNavBus_DIMS1->E) == localB->M_k_size[1]))
            {
                localB->E_k_size[0] = 1;
                localB->E_k_size[1] = localB->M_k_size[1];
                localB->loop_ub = localB->M_k_size[1];
                localB->scalarLB = (localB->M_k_size[1] / 2) << 1;
                localB->vectorUB = localB->scalarLB - 2;
                for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
                {
                    tmp_5 = _mm_loadu_pd(&rtu_GnssNavBus->E[localB->k]);
                    tmp_4 = _mm_loadu_pd(&localB->n_0_data[localB->k]);
                    tmp = _mm_loadu_pd(&localB->M_k_data[localB->k]);
                    _mm_storeu_pd(&localB->E_k_data[localB->k], _mm_add_pd(_mm_mul_pd(tmp_5, tmp_4), tmp));
                }

                for (localB->k = localB->scalarLB; localB->k < localB->loop_ub; localB->k++)
                {
                    localB->E_k_data[localB->k] = rtu_GnssNavBus->E[localB->k] * localB->n_0_data[localB->k] +
                        localB->M_k_data[localB->k];
                }
            }
            else
            {
                GNSSPreProce_binary_expand_op_n(localB->E_k_data, localB->E_k_size, localB->M_k_data, localB->M_k_size,
                    rtu_GnssNavBus, rtu_GnssNavBus_DIMS1, localB->n_0_data, localB->n_0_size, localB);
            }

            if (localB->E_k_size[1] == localB->t_k_size[1])
            {
                localB->loop_ub = localB->E_k_size[1] - 1;
                localB->t_k_size[0] = 1;
                localB->t_k_size[1] = localB->E_k_size[1];
                localB->scalarLB = (localB->E_k_size[1] / 2) << 1;
                localB->vectorUB = localB->scalarLB - 2;
                for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
                {
                    tmp_5 = _mm_loadu_pd(&localB->E_k_data[localB->k]);
                    tmp_4 = _mm_loadu_pd(&localB->t_k_data[localB->k]);
                    _mm_storeu_pd(&localB->t_k_data[localB->k], _mm_sub_pd(tmp_5, tmp_4));
                }

                for (localB->k = localB->scalarLB; localB->k <= localB->loop_ub; localB->k++)
                {
                    localB->t_k_data[localB->k] = localB->E_k_data[localB->k] - localB->t_k_data[localB->k];
                }
            }
            else
            {
                GNSSPreProcessingDualAnte_minus(localB->t_k_data, localB->t_k_size, localB->E_k_data, localB->E_k_size,
                    localB);
            }

            localB->n_0_size[1] = localB->t_k_size[1];
            localB->scalarLB = localB->t_k_size[1];
            for (localB->k = 0; localB->k < localB->scalarLB; localB->k++)
            {
                localB->n_0_data[localB->k] = std::abs(localB->t_k_data[localB->k]);
            }

            localB->i++;
        }
        else
        {
            exitg1 = 1;
        }
    }
    while (exitg1 == 0);

    localB->i = localB->E_k_size[1];
    for (localB->k = 0; localB->k < localB->i; localB->k++)
    {
        localB->E_k_data[localB->k] = std::sin(localB->E_k_data[localB->k]);
    }

    localB->loop_ub = (localB->t_d_size[1] / 2) << 1;
    localB->vectorUB = localB->loop_ub - 2;
    for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
    {
        tmp_5 = _mm_loadu_pd(&localB->t_d_data[localB->k]);
        _mm_storeu_pd(&localB->n_0_data[localB->k], _mm_mul_pd(tmp_5, tmp_5));
    }

    localB->vectorUB = localB->loop_ub - 2;
    for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
    {
        tmp_5 = _mm_loadu_pd(&localB->t_d_data[localB->k]);
        _mm_storeu_pd(&localB->M_k_data[localB->k], _mm_mul_pd(tmp_5, tmp_5));
    }

    localB->vectorUB = localB->loop_ub - 2;
    for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
    {
        tmp_5 = _mm_loadu_pd(&localB->t_d_data[localB->k]);
        _mm_storeu_pd(&localB->n_0_data[localB->k], _mm_mul_pd(tmp_5, tmp_5));
    }

    if ((rtu_GnssNavBus_DIMS1->A_f1 == localB->t_d_size[1]) && ((rtu_GnssNavBus_DIMS1->A_f1 == 1 ? localB->t_d_size[1] :
          rtu_GnssNavBus_DIMS1->A_f1) == rtu_GnssNavBus_DIMS1->A_f0) && (rtu_GnssNavBus_DIMS1->A_f2 == localB->t_d_size
            [1]) && ((rtu_GnssNavBus_DIMS1->A_f0 == 1 ? rtu_GnssNavBus_DIMS1->A_f1 == 1 ? localB->t_d_size[1] :
                      rtu_GnssNavBus_DIMS1->A_f1 : rtu_GnssNavBus_DIMS1->A_f0) == (rtu_GnssNavBus_DIMS1->A_f2 == 1 ?
            localB->t_d_size[1] : rtu_GnssNavBus_DIMS1->A_f2)) && (rtu_GnssNavBus_DIMS1->E ==
            rtu_GnssNavBus_DIMS1->SQRT_A) && ((rtu_GnssNavBus_DIMS1->E == 1 ? rtu_GnssNavBus_DIMS1->SQRT_A :
            rtu_GnssNavBus_DIMS1->E) == localB->E_k_size[1]) && (((rtu_GnssNavBus_DIMS1->A_f0 == 1 ?
            rtu_GnssNavBus_DIMS1->A_f1 == 1 ? localB->t_d_size[1] : rtu_GnssNavBus_DIMS1->A_f1 :
            rtu_GnssNavBus_DIMS1->A_f0) == 1 ? rtu_GnssNavBus_DIMS1->A_f2 == 1 ? localB->t_d_size[1] :
            rtu_GnssNavBus_DIMS1->A_f2 : rtu_GnssNavBus_DIMS1->A_f0 == 1 ? rtu_GnssNavBus_DIMS1->A_f1 == 1 ?
            localB->t_d_size[1] : rtu_GnssNavBus_DIMS1->A_f1 : rtu_GnssNavBus_DIMS1->A_f0) == ((rtu_GnssNavBus_DIMS1->E ==
           1 ? rtu_GnssNavBus_DIMS1->SQRT_A : rtu_GnssNavBus_DIMS1->E) == 1 ? localB->E_k_size[1] :
            rtu_GnssNavBus_DIMS1->E == 1 ? rtu_GnssNavBus_DIMS1->SQRT_A : rtu_GnssNavBus_DIMS1->E)))
    {
        localB->t_k_size[0] = 1;
        localB->t_k_size[1] = rtu_GnssNavBus_DIMS1->A_f0;
        localB->loop_ub = rtu_GnssNavBus_DIMS1->A_f0;
        localB->scalarLB = (rtu_GnssNavBus_DIMS1->A_f0 / 2) << 1;
        localB->vectorUB = localB->scalarLB - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            __m128d tmp_0;
            __m128d tmp_1;
            __m128d tmp_2;
            __m128d tmp_3;
            tmp_5 = _mm_loadu_pd(&rtu_GnssNavBus->A_f1[localB->k]);
            tmp_4 = _mm_loadu_pd(&localB->t_d_data[localB->k]);
            tmp = _mm_loadu_pd(&rtu_GnssNavBus->A_f0[localB->k]);
            tmp_0 = _mm_loadu_pd(&rtu_GnssNavBus->A_f2[localB->k]);
            tmp_1 = _mm_loadu_pd(&rtu_GnssNavBus->E[localB->k]);
            tmp_2 = _mm_loadu_pd(&rtu_GnssNavBus->SQRT_A[localB->k]);
            tmp_3 = _mm_loadu_pd(&localB->E_k_data[localB->k]);
            _mm_storeu_pd(&localB->t_k_data[localB->k], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd(tmp_5, tmp_4), tmp),
                            _mm_mul_pd(_mm_mul_pd(tmp_4, tmp_4), tmp_0)), _mm_mul_pd(_mm_mul_pd(_mm_mul_pd(_mm_set1_pd
                              (-4.44280763339306E-10), tmp_1), tmp_2), tmp_3)));
        }

        for (localB->k = localB->scalarLB; localB->k < localB->loop_ub; localB->k++)
        {
            localB->t_d = localB->t_d_data[localB->k];
            localB->t_k_data[localB->k] = ((rtu_GnssNavBus->A_f1[localB->k] * localB->t_d + rtu_GnssNavBus->A_f0
                [localB->k]) + localB->t_d * localB->t_d * rtu_GnssNavBus->A_f2[localB->k]) + -4.44280763339306E-10 *
                rtu_GnssNavBus->E[localB->k] * rtu_GnssNavBus->SQRT_A[localB->k] * localB->E_k_data[localB->k];
        }
    }
    else
    {
        GNSSPreP_binary_expand_op_ngwdj(localB->t_k_data, localB->t_k_size, rtu_GnssNavBus, rtu_GnssNavBus_DIMS1,
            localB->t_d_data, localB->t_d_size, localB->E_k_data, localB->E_k_size, localB);
    }

    if (rtu_enableSatClockCorr != 0.0)
    {
        if (localB->t_k_size[1] == rtu_GnssNavBus_DIMS1->SVID)
        {
            localB->tmp_size = localB->t_k_size[1];
            localB->loop_ub = localB->t_k_size[1];
            for (localB->k = 0; localB->k < localB->loop_ub; localB->k++)
            {
                localB->tmp_data[localB->k] = rtu_delta_t_sv_EGNOS[static_cast<int32_T>(rtu_GnssNavBus->SVID[localB->k])
                    - 1] + localB->t_k_data[localB->k];
            }
        }
        else
        {
            GNSSPrePr_binary_expand_op_ngwd(localB->tmp_data, &localB->tmp_size, localB->t_k_data, localB->t_k_size,
                rtu_delta_t_sv_EGNOS, rtu_GnssNavBus, rtu_GnssNavBus_DIMS1, localB);
        }

        localDW->SFunction_DIMS3 = localB->tmp_size;
        localB->loop_ub = localB->tmp_size;
        if (localB->loop_ub - 1 >= 0)
        {
            std::memcpy(&localB->deltaTimeSV[0], &localB->tmp_data[0], static_cast<uint32_T>(localB->loop_ub) * sizeof
                        (real_T));
        }

        if ((rtu_GnssNavBus_DIMS1->A_f2 == localB->t_d_size[1]) && ((rtu_GnssNavBus_DIMS1->A_f2 == 1 ? localB->t_d_size
                [1] : rtu_GnssNavBus_DIMS1->A_f2) == rtu_GnssNavBus_DIMS1->A_f1))
        {
            localB->tmp_size = rtu_GnssNavBus_DIMS1->A_f1;
            localB->loop_ub = rtu_GnssNavBus_DIMS1->A_f1;
            localB->scalarLB = (rtu_GnssNavBus_DIMS1->A_f1 / 2) << 1;
            localB->vectorUB = localB->scalarLB - 2;
            for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
            {
                tmp_5 = _mm_loadu_pd(&rtu_GnssNavBus->A_f2[localB->k]);
                tmp_4 = _mm_loadu_pd(&localB->t_d_data[localB->k]);
                tmp = _mm_loadu_pd(&rtu_GnssNavBus->A_f1[localB->k]);
                _mm_storeu_pd(&localB->tmp_data[localB->k], _mm_add_pd(_mm_mul_pd(_mm_mul_pd(_mm_set1_pd(2.0), tmp_5),
                                tmp_4), tmp));
            }

            for (localB->k = localB->scalarLB; localB->k < localB->loop_ub; localB->k++)
            {
                localB->tmp_data[localB->k] = 2.0 * rtu_GnssNavBus->A_f2[localB->k] * localB->t_d_data[localB->k] +
                    rtu_GnssNavBus->A_f1[localB->k];
            }
        }
        else
        {
            GNSSPrePro_binary_expand_op_ngw(localB->tmp_data, &localB->tmp_size, rtu_GnssNavBus, rtu_GnssNavBus_DIMS1,
                localB->t_d_data, localB->t_d_size, localB);
        }

        localDW->SFunction_DIMS4 = localB->tmp_size;
        localB->loop_ub = localB->tmp_size;
        if (localB->loop_ub - 1 >= 0)
        {
            std::memcpy(&localB->drTimeCorr[0], &localB->tmp_data[0], static_cast<uint32_T>(localB->loop_ub) * sizeof
                        (real_T));
        }
    }
    else
    {
        localB->k = static_cast<int8_T>(localB->t_k_size[1]);
        localDW->SFunction_DIMS3 = static_cast<int8_T>(localB->t_k_size[1]);
        if (localB->k - 1 >= 0)
        {
            std::memset(&localB->deltaTimeSV[0], 0, static_cast<uint32_T>(localB->k) * sizeof(real_T));
        }

        localB->i = static_cast<int8_T>(rtu_GnssNavBus_DIMS1->A_f1 == 1 ? rtu_GnssNavBus_DIMS1->A_f2 == 1 ?
            localB->t_d_size[1] : rtu_GnssNavBus_DIMS1->A_f2 : rtu_GnssNavBus_DIMS1->A_f1);
        localDW->SFunction_DIMS4 = static_cast<int8_T>(rtu_GnssNavBus_DIMS1->A_f1 == 1 ? rtu_GnssNavBus_DIMS1->A_f2 == 1
            ? localB->t_d_size[1] : rtu_GnssNavBus_DIMS1->A_f2 : rtu_GnssNavBus_DIMS1->A_f1);
        if (localB->i - 1 >= 0)
        {
            std::memset(&localB->drTimeCorr[0], 0, static_cast<uint32_T>(localB->i) * sizeof(real_T));
        }
    }

    if (*rtu_pseudorange_DIMS1 == localB->t_k_size[1])
    {
        localB->tmp_size = *rtu_pseudorange_DIMS1;
        localB->loop_ub = *rtu_pseudorange_DIMS1;
        localB->scalarLB = (*rtu_pseudorange_DIMS1 / 2) << 1;
        localB->vectorUB = localB->scalarLB - 2;
        for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2)
        {
            tmp_5 = _mm_loadu_pd(&localB->t_sv_emission_data[localB->k]);
            tmp_4 = _mm_loadu_pd(&localB->t_k_data[localB->k]);
            _mm_storeu_pd(&localB->tmp_data[localB->k], _mm_sub_pd(tmp_5, tmp_4));
        }

        for (localB->k = localB->scalarLB; localB->k < localB->loop_ub; localB->k++)
        {
            localB->tmp_data[localB->k] = localB->t_sv_emission_data[localB->k] - localB->t_k_data[localB->k];
        }
    }
    else
    {
        GNSSPreProc_binary_expand_op_ng(localB->tmp_data, &localB->tmp_size, localB->t_sv_emission_data,
            localB->t_sv_emission_size, localB->t_k_data, localB->t_k_size, localB);
    }

    localDW->SFunction_DIMS2 = localB->tmp_size;
    localB->loop_ub = localB->tmp_size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->timeEmissionCorrected[0], &localB->tmp_data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
