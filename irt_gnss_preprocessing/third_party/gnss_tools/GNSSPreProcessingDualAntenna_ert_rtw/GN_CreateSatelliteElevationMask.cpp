//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GN_CreateSatelliteElevationMask.cpp
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
#include "rt_defines.h"
#include "GN_CreateSatelliteElevationMask.h"

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_pk(real_T in1[3], const real_T in2[120], const int32_T
    in3[2], int32_T in4, const real_T in5[3], B_CreateSatelliteElevationMas_T *localB)
{
    localB->stride_0_1 = (in3[1] != 1);
    in1[0] = in2[in4] - in5[0];
    in1[1] = in2[in3[0] * localB->stride_0_1 + in4] - in5[1];
    in1[2] = in2[(localB->stride_0_1 << 1) * in3[0] + in4] - in5[2];
}

void GNSSPreProcessingDualAntenna::GNSSPrePro_binary_expand_op_pkr(boolean_T in1_data[], int32_T *in1_size, const real_T
    in2[40], int32_T in3, real_T in4, const int8_T in5[2], B_CreateSatelliteElevationMas_T *localB)
{
    *in1_size = in5[0] == 1 ? in3 : static_cast<int32_T>(in5[0]);
    localB->stride_0_0 = (in3 != 1);
    localB->loop_ub_c = in5[0] == 1 ? in3 : static_cast<int32_T>(in5[0]);
    for (localB->i = 0; localB->i < localB->loop_ub_c; localB->i++)
    {
        in1_data[localB->i] = (in2[localB->i * localB->stride_0_0] > in4);
    }
}

real_T GNSSPreProcessingDualAntenna::GNSSPreProcessi_rt_atan2d_snf_o(real_T u0, real_T u1,
    B_CreateSatelliteElevationMas_T *localB)
{
    real_T y;
    if (std::isnan(u0) || std::isnan(u1))
    {
        y = (rtNaN);
    }
    else if (std::isinf(u0) && std::isinf(u1))
    {
        if (u0 > 0.0)
        {
            localB->i1 = 1;
        }
        else
        {
            localB->i1 = -1;
        }

        if (u1 > 0.0)
        {
            localB->i2 = 1;
        }
        else
        {
            localB->i2 = -1;
        }

        y = std::atan2(static_cast<real_T>(localB->i1), static_cast<real_T>(localB->i2));
    }
    else if (u1 == 0.0)
    {
        if (u0 > 0.0)
        {
            y = RT_PI / 2.0;
        }
        else if (u0 < 0.0)
        {
            y = -(RT_PI / 2.0);
        }
        else
        {
            y = 0.0;
        }
    }
    else
    {
        y = std::atan2(u0, u1);
    }

    return y;
}

//
// Output and update for atomic system:
//    '<S60>/Create Satellite Elevation Mask'
//    '<S116>/Create Satellite Elevation Mask'
//    '<S187>/Create Satellite Elevation Mask'
//    '<S243>/Create Satellite Elevation Mask'
//
void GNSSPreProcessingDualAntenna::GN_CreateSatelliteElevationMask(const real_T rtu_userPosLlh[3], boolean_T
    rtu_userPos_isValid, const real_T rtu_satPosEcef[120], const int32_T rtu_satPosEcef_DIMS1[2], real_T
    rtu_elevationMaskingAngle, real_T *rty_removedSats, B_CreateSatelliteElevationMas_T *localB,
    DW_CreateSatelliteElevationMa_T *localDW)
{
    localB->elevation_Angle_Limit = rtu_elevationMaskingAngle / 180.0 * 3.1415926535897931;
    localDW->SFunction_DIMS3 = rtu_satPosEcef_DIMS1[0];
    localB->loop_ub = rtu_satPosEcef_DIMS1[0];
    if (localB->loop_ub - 1 >= 0)
    {
        std::memset(&localB->elevationAngle[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS4 = rtu_satPosEcef_DIMS1[0];
    localB->loop_ub = rtu_satPosEcef_DIMS1[0];
    if (localB->loop_ub - 1 >= 0)
    {
        std::memset(&localB->azimuthAngle[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->scale = std::cos(rtu_userPosLlh[0]);
    localB->N = 6.3995936257584924E+6 / std::sqrt(localB->scale * localB->scale * 0.0067394967422761756 + 1.0);
    localB->t = std::cos(rtu_userPosLlh[1]);
    localB->user_Position_ecef[0] = (localB->N + rtu_userPosLlh[2]) * localB->scale * localB->t;
    localB->u_unit_m = std::sin(rtu_userPosLlh[1]);
    localB->user_Position_ecef[1] = (localB->N + rtu_userPosLlh[2]) * std::cos(rtu_userPosLlh[0]) * localB->u_unit_m;
    localB->d = std::sin(rtu_userPosLlh[0]);
    localB->user_Position_ecef[2] = (0.99330562000985889 * localB->N + rtu_userPosLlh[2]) * localB->d;
    localB->e_unit_tmp[0] = -localB->u_unit_m;
    localB->e_unit_tmp[1] = localB->t;
    localB->e_unit_tmp[2] = 0.0;
    localB->e_unit_tmp[3] = -localB->d * localB->t;
    localB->e_unit_tmp[4] = -std::sin(rtu_userPosLlh[0]) * localB->u_unit_m;
    localB->e_unit_tmp[5] = localB->scale;
    localB->e_unit_tmp[6] = localB->scale * localB->t;
    localB->e_unit_tmp[7] = localB->scale * localB->u_unit_m;
    localB->e_unit_tmp[8] = localB->d;
    for (localB->b_k = 0; localB->b_k <= 0; localB->b_k += 2)
    {
        __m128d tmp;
        __m128d tmp_0;
        __m128d tmp_1;
        __m128d tmp_2;
        __m128d tmp_3;
        __m128d tmp_4;
        __m128d tmp_5;
        tmp = _mm_loadu_pd(&localB->e_unit_tmp[localB->b_k]);
        tmp_2 = _mm_set1_pd(0.0);
        tmp_3 = _mm_mul_pd(tmp, tmp_2);
        tmp_0 = _mm_loadu_pd(&localB->e_unit_tmp[localB->b_k + 3]);
        tmp_4 = _mm_mul_pd(tmp_0, tmp_2);
        tmp_1 = _mm_loadu_pd(&localB->e_unit_tmp[localB->b_k + 6]);
        tmp_5 = _mm_mul_pd(tmp_1, tmp_2);
        _mm_storeu_pd(&localB->e_unit[localB->b_k], _mm_add_pd(tmp_5, _mm_add_pd(tmp_4, _mm_add_pd(tmp_2, tmp))));
        tmp = _mm_add_pd(tmp_3, tmp_2);
        _mm_storeu_pd(&localB->n_unit[localB->b_k], _mm_add_pd(tmp_5, _mm_add_pd(tmp, tmp_0)));
        _mm_storeu_pd(&localB->u_unit[localB->b_k], _mm_add_pd(_mm_add_pd(tmp_4, tmp), tmp_1));
    }

    for (localB->b_k = 2; localB->b_k < 3; localB->b_k++)
    {
        localB->scale = localB->e_unit_tmp[localB->b_k];
        localB->N = localB->scale;
        localB->u_unit_m = localB->scale * 0.0;
        localB->scale = localB->e_unit_tmp[localB->b_k + 3];
        localB->N += localB->scale * 0.0;
        localB->t = localB->u_unit_m + localB->scale;
        localB->u_unit_m += localB->scale * 0.0;
        localB->scale = localB->e_unit_tmp[localB->b_k + 6];
        localB->e_unit[localB->b_k] = localB->scale * 0.0 + localB->N;
        localB->n_unit[localB->b_k] = localB->scale * 0.0 + localB->t;
        localB->u_unit[localB->b_k] = localB->u_unit_m + localB->scale;
    }

    localB->c = rtu_satPosEcef_DIMS1[0];
    for (localB->nz = 0; localB->nz < localB->c; localB->nz++)
    {
        if (rtu_satPosEcef_DIMS1[1] == 3)
        {
            localB->rtu_satPosEcef_DIMS1_idx_0 = rtu_satPosEcef_DIMS1[0];
            localB->loop_ub = rtu_satPosEcef_DIMS1[1];
            for (localB->b_k = 0; localB->b_k < localB->loop_ub; localB->b_k++)
            {
                localB->line_of_sight[localB->b_k] = rtu_satPosEcef[localB->rtu_satPosEcef_DIMS1_idx_0 * localB->b_k +
                    localB->nz] - localB->user_Position_ecef[localB->b_k];
            }
        }
        else
        {
            GNSSPreProc_binary_expand_op_pk(localB->line_of_sight, rtu_satPosEcef, rtu_satPosEcef_DIMS1, localB->nz,
                localB->user_Position_ecef, localB);
        }

        localB->scale = 3.3121686421112381E-170;
        localB->N = std::abs(localB->line_of_sight[0]);
        if (localB->N > 3.3121686421112381E-170)
        {
            localB->u_unit_m = 1.0;
            localB->scale = localB->N;
        }
        else
        {
            localB->t = localB->N / 3.3121686421112381E-170;
            localB->u_unit_m = localB->t * localB->t;
        }

        localB->N = std::abs(localB->line_of_sight[1]);
        if (localB->N > localB->scale)
        {
            localB->t = localB->scale / localB->N;
            localB->u_unit_m = localB->u_unit_m * localB->t * localB->t + 1.0;
            localB->scale = localB->N;
        }
        else
        {
            localB->t = localB->N / localB->scale;
            localB->u_unit_m += localB->t * localB->t;
        }

        localB->N = std::abs(localB->line_of_sight[2]);
        if (localB->N > localB->scale)
        {
            localB->t = localB->scale / localB->N;
            localB->u_unit_m = localB->u_unit_m * localB->t * localB->t + 1.0;
            localB->scale = localB->N;
        }
        else
        {
            localB->t = localB->N / localB->scale;
            localB->u_unit_m += localB->t * localB->t;
        }

        localB->u_unit_m = localB->scale * std::sqrt(localB->u_unit_m);
        localB->line_of_sight[0] /= localB->u_unit_m;
        localB->line_of_sight[1] /= localB->u_unit_m;
        localB->line_of_sight[2] /= localB->u_unit_m;
        localB->elevationAngle[localB->nz] = std::asin((localB->line_of_sight[0] * localB->u_unit[0] +
            localB->line_of_sight[1] * localB->u_unit[1]) + localB->line_of_sight[2] * localB->u_unit[2]);
        localB->azimuthAngle[localB->nz] = GNSSPreProcessi_rt_atan2d_snf_o((localB->line_of_sight[0] * localB->e_unit[0]
            + localB->line_of_sight[1] * localB->e_unit[1]) + localB->line_of_sight[2] * localB->e_unit[2],
            (localB->line_of_sight[0] * localB->n_unit[0] + localB->line_of_sight[1] * localB->n_unit[1]) +
            localB->line_of_sight[2] * localB->n_unit[2], localB);
    }

    localB->b[0] = static_cast<int8_T>(localDW->SFunction_DIMS3);
    localB->b[1] = 1;
    if (localDW->SFunction_DIMS3 == static_cast<int8_T>(localDW->SFunction_DIMS3))
    {
        localB->tmp_size = localDW->SFunction_DIMS3;
        for (localB->b_k = 0; localB->b_k < localDW->SFunction_DIMS3; localB->b_k++)
        {
            localB->tmp_data[localB->b_k] = (localB->elevationAngle[localB->b_k] > localB->elevation_Angle_Limit);
        }
    }
    else
    {
        GNSSPrePro_binary_expand_op_pkr(localB->tmp_data, &localB->tmp_size, localB->elevationAngle,
            localDW->SFunction_DIMS3, localB->elevation_Angle_Limit, localB->b, localB);
    }

    localDW->SFunction_DIMS2 = localB->tmp_size;
    localB->loop_ub = localB->tmp_size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->elevationMask[0], &localB->tmp_data[0], static_cast<uint32_T>(localB->loop_ub) * sizeof
                    (boolean_T));
    }

    if (!rtu_userPos_isValid)
    {
        localDW->SFunction_DIMS2 = rtu_satPosEcef_DIMS1[0];
        localB->loop_ub = rtu_satPosEcef_DIMS1[0];
        for (localB->b_k = 0; localB->b_k < localB->loop_ub; localB->b_k++)
        {
            localB->elevationMask[localB->b_k] = true;
        }
    }

    if (localDW->SFunction_DIMS2 == 0)
    {
        localB->nz = 0;
    }
    else if (localDW->SFunction_DIMS2 == 0)
    {
        localB->nz = 0;
    }
    else
    {
        localB->nz = localB->elevationMask[0];
        for (localB->b_k = 2; localB->b_k <= localDW->SFunction_DIMS2; localB->b_k++)
        {
            localB->nz += localB->elevationMask[localB->b_k - 1];
        }
    }

    *rty_removedSats = localDW->SFunction_DIMS2 - localB->nz;
}

//
// File trailer for generated code.
//
// [EOF]
//
