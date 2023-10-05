//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateDifferentialCorrection.cpp
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
#include "GNSSPreProcessingDualAntenna_types.h"
#include "rtwtypes.h"
#include <cstring>
#include <emmintrin.h>
#include <cmath>
#include "rt_defines.h"
#include "CalculateDifferentialCorrection.h"

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAnte_merge(int32_T idx_data[], uint16_T x_data[], int32_T offset,
    int32_T np, int32_T nq, int32_T iwork_data[], uint16_T xwork_data[], B_CalculateDifferentialCorrec_T *localB)
{
    if (nq != 0)
    {
        int32_T iout;
        int32_T offset1;
        offset1 = np + nq;
        for (localB->q = 0; localB->q < offset1; localB->q++)
        {
            iout = offset + localB->q;
            iwork_data[localB->q] = idx_data[iout];
            xwork_data[localB->q] = x_data[iout];
        }

        localB->p = 0;
        localB->q = np;
        iout = offset - 1;
        int32_T exitg1;
        do
        {
            exitg1 = 0;
            iout++;
            if (xwork_data[localB->p] <= xwork_data[localB->q])
            {
                idx_data[iout] = iwork_data[localB->p];
                x_data[iout] = xwork_data[localB->p];
                if (localB->p + 1 < np)
                {
                    localB->p++;
                }
                else
                {
                    exitg1 = 1;
                }
            }
            else
            {
                idx_data[iout] = iwork_data[localB->q];
                x_data[iout] = xwork_data[localB->q];
                if (localB->q + 1 < offset1)
                {
                    localB->q++;
                }
                else
                {
                    offset1 = iout - localB->p;
                    for (localB->q = localB->p + 1; localB->q <= np; localB->q++)
                    {
                        iout = offset1 + localB->q;
                        idx_data[iout] = iwork_data[localB->q - 1];
                        x_data[iout] = xwork_data[localB->q - 1];
                    }

                    exitg1 = 1;
                }
            }
        }
        while (exitg1 == 0);
    }
}

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAnten_sort(uint16_T x_data[], const int32_T *x_size, int32_T
    idx_data[], int32_T *idx_size, B_CalculateDifferentialCorrec_T *localB)
{
    localB->dim = 0;
    if (*x_size != 1)
    {
        localB->dim = -1;
        localB->nDone = *x_size;
    }
    else
    {
        localB->nDone = 1;
    }

    localB->b = localB->nDone - 1;
    localB->vwork_size_idx_0 = localB->nDone;
    *idx_size = *x_size;
    localB->vstride_o = 1;
    for (localB->nDone = 0; localB->nDone <= localB->dim; localB->nDone++)
    {
        localB->vstride_o *= *x_size;
    }

    for (localB->dim = 0; localB->dim < localB->vstride_o; localB->dim++)
    {
        for (localB->nDone = 0; localB->nDone <= localB->b; localB->nDone++)
        {
            localB->vwork_data[localB->nDone] = x_data[localB->nDone * localB->vstride_o + localB->dim];
        }

        localB->b_x_size = localB->vwork_size_idx_0;
        if (localB->vwork_size_idx_0 - 1 >= 0)
        {
            std::memcpy(&localB->b_x_data[0], &localB->vwork_data[0], static_cast<uint32_T>(localB->vwork_size_idx_0) *
                        sizeof(uint16_T));
        }

        localB->nLeft = static_cast<int8_T>(localB->vwork_size_idx_0);
        if (localB->nLeft - 1 >= 0)
        {
            std::memset(&localB->b_idx_data[0], 0, static_cast<uint32_T>(localB->nLeft) * sizeof(int32_T));
        }

        if (localB->vwork_size_idx_0 != 0)
        {
            localB->nLeft = static_cast<int8_T>(localB->vwork_size_idx_0);
            if (localB->nLeft - 1 >= 0)
            {
                std::memset(&localB->b_idx_data[0], 0, static_cast<uint32_T>(localB->nLeft) * sizeof(int32_T));
            }

            localB->x4[0] = 0U;
            localB->idx4[0] = 0;
            localB->x4[1] = 0U;
            localB->idx4[1] = 0;
            localB->x4[2] = 0U;
            localB->idx4[2] = 0;
            localB->x4[3] = 0U;
            localB->idx4[3] = 0;
            localB->nQuartets_tmp = localB->vwork_size_idx_0 >> 2;
            for (localB->nLeft = 0; localB->nLeft < localB->nQuartets_tmp; localB->nLeft++)
            {
                uint16_T x4_tmp;
                uint16_T x4_tmp_0;
                uint16_T x4_tmp_1;
                localB->b_i = localB->nLeft << 2;
                localB->idx4[0] = static_cast<int8_T>(localB->b_i + 1);
                localB->idx4[1] = static_cast<int8_T>(localB->b_i + 2);
                localB->idx4[2] = static_cast<int8_T>(localB->b_i + 3);
                localB->idx4[3] = static_cast<int8_T>(localB->b_i + 4);
                localB->x4[0] = localB->b_x_data[localB->b_i];
                x4_tmp = localB->b_x_data[localB->b_i + 1];
                localB->x4[1] = x4_tmp;
                x4_tmp_0 = localB->b_x_data[localB->b_i + 2];
                localB->x4[2] = x4_tmp_0;
                x4_tmp_1 = localB->b_x_data[localB->b_i + 3];
                localB->x4[3] = x4_tmp_1;
                if (localB->b_x_data[localB->b_i] <= x4_tmp)
                {
                    localB->i1_b = 1;
                    localB->i2_a = 2;
                }
                else
                {
                    localB->i1_b = 2;
                    localB->i2_a = 1;
                }

                if (x4_tmp_0 <= x4_tmp_1)
                {
                    localB->i3_g = 3;
                    localB->i4_e = 4;
                }
                else
                {
                    localB->i3_g = 4;
                    localB->i4_e = 3;
                }

                localB->nDone = localB->x4[localB->i1_b - 1];
                localB->i6 = localB->x4[localB->i3_g - 1];
                if (localB->nDone <= localB->i6)
                {
                    localB->nDone = localB->x4[localB->i2_a - 1];
                    if (localB->nDone <= localB->i6)
                    {
                        localB->perm[0] = static_cast<int8_T>(localB->i1_b);
                        localB->perm[1] = static_cast<int8_T>(localB->i2_a);
                        localB->perm[2] = static_cast<int8_T>(localB->i3_g);
                        localB->perm[3] = static_cast<int8_T>(localB->i4_e);
                    }
                    else if (localB->nDone <= localB->x4[localB->i4_e - 1])
                    {
                        localB->perm[0] = static_cast<int8_T>(localB->i1_b);
                        localB->perm[1] = static_cast<int8_T>(localB->i3_g);
                        localB->perm[2] = static_cast<int8_T>(localB->i2_a);
                        localB->perm[3] = static_cast<int8_T>(localB->i4_e);
                    }
                    else
                    {
                        localB->perm[0] = static_cast<int8_T>(localB->i1_b);
                        localB->perm[1] = static_cast<int8_T>(localB->i3_g);
                        localB->perm[2] = static_cast<int8_T>(localB->i4_e);
                        localB->perm[3] = static_cast<int8_T>(localB->i2_a);
                    }
                }
                else
                {
                    localB->i6 = localB->x4[localB->i4_e - 1];
                    if (localB->nDone <= localB->i6)
                    {
                        if (localB->x4[localB->i2_a - 1] <= localB->i6)
                        {
                            localB->perm[0] = static_cast<int8_T>(localB->i3_g);
                            localB->perm[1] = static_cast<int8_T>(localB->i1_b);
                            localB->perm[2] = static_cast<int8_T>(localB->i2_a);
                            localB->perm[3] = static_cast<int8_T>(localB->i4_e);
                        }
                        else
                        {
                            localB->perm[0] = static_cast<int8_T>(localB->i3_g);
                            localB->perm[1] = static_cast<int8_T>(localB->i1_b);
                            localB->perm[2] = static_cast<int8_T>(localB->i4_e);
                            localB->perm[3] = static_cast<int8_T>(localB->i2_a);
                        }
                    }
                    else
                    {
                        localB->perm[0] = static_cast<int8_T>(localB->i3_g);
                        localB->perm[1] = static_cast<int8_T>(localB->i4_e);
                        localB->perm[2] = static_cast<int8_T>(localB->i1_b);
                        localB->perm[3] = static_cast<int8_T>(localB->i2_a);
                    }
                }

                localB->b_idx_data[localB->b_i] = localB->idx4[localB->perm[0] - 1];
                localB->b_idx_data[localB->b_i + 1] = localB->idx4[localB->perm[1] - 1];
                localB->b_idx_data[localB->b_i + 2] = localB->idx4[localB->perm[2] - 1];
                localB->b_idx_data[localB->b_i + 3] = localB->idx4[localB->perm[3] - 1];
                localB->b_x_data[localB->b_i] = localB->x4[localB->perm[0] - 1];
                localB->b_x_data[localB->b_i + 1] = localB->x4[localB->perm[1] - 1];
                localB->b_x_data[localB->b_i + 2] = localB->x4[localB->perm[2] - 1];
                localB->b_x_data[localB->b_i + 3] = localB->x4[localB->perm[3] - 1];
            }

            localB->nDone = localB->nQuartets_tmp << 2;
            localB->nLeft = localB->vwork_size_idx_0 - localB->nDone;
            if (localB->nLeft > 0)
            {
                for (localB->i1_b = 0; localB->i1_b < localB->nLeft; localB->i1_b++)
                {
                    localB->b_i = localB->nDone + localB->i1_b;
                    localB->idx4[localB->i1_b] = static_cast<int8_T>(localB->b_i + 1);
                    localB->x4[localB->i1_b] = localB->b_x_data[localB->b_i];
                }

                localB->perm[1] = 0;
                localB->perm[2] = 0;
                localB->perm[3] = 0;
                switch (localB->nLeft)
                {
                  case 1:
                    localB->perm[0] = 1;
                    break;

                  case 2:
                    if (localB->x4[0] <= localB->x4[1])
                    {
                        localB->perm[0] = 1;
                        localB->perm[1] = 2;
                    }
                    else
                    {
                        localB->perm[0] = 2;
                        localB->perm[1] = 1;
                    }
                    break;

                  default:
                    if (localB->x4[0] <= localB->x4[1])
                    {
                        if (localB->x4[1] <= localB->x4[2])
                        {
                            localB->perm[0] = 1;
                            localB->perm[1] = 2;
                            localB->perm[2] = 3;
                        }
                        else if (localB->x4[0] <= localB->x4[2])
                        {
                            localB->perm[0] = 1;
                            localB->perm[1] = 3;
                            localB->perm[2] = 2;
                        }
                        else
                        {
                            localB->perm[0] = 3;
                            localB->perm[1] = 1;
                            localB->perm[2] = 2;
                        }
                    }
                    else if (localB->x4[0] <= localB->x4[2])
                    {
                        localB->perm[0] = 2;
                        localB->perm[1] = 1;
                        localB->perm[2] = 3;
                    }
                    else if (localB->x4[1] <= localB->x4[2])
                    {
                        localB->perm[0] = 2;
                        localB->perm[1] = 3;
                        localB->perm[2] = 1;
                    }
                    else
                    {
                        localB->perm[0] = 3;
                        localB->perm[1] = 2;
                        localB->perm[2] = 1;
                    }
                    break;
                }

                for (localB->i1_b = 0; localB->i1_b < localB->nLeft; localB->i1_b++)
                {
                    int8_T perm;
                    perm = localB->perm[localB->i1_b];
                    localB->b_i = localB->nDone + localB->i1_b;
                    localB->b_idx_data[localB->b_i] = localB->idx4[perm - 1];
                    localB->b_x_data[localB->b_i] = localB->x4[perm - 1];
                }
            }

            if (localB->vwork_size_idx_0 > 1)
            {
                localB->nLeft = static_cast<int8_T>(localB->vwork_size_idx_0);
                if (localB->nLeft - 1 >= 0)
                {
                    std::memset(&localB->iwork_data[0], 0, static_cast<uint32_T>(localB->nLeft) * sizeof(int32_T));
                }

                std::memset(&localB->vwork_data[0], 0, static_cast<uint32_T>(localB->vwork_size_idx_0) * sizeof(uint16_T));
                localB->nLeft = localB->nQuartets_tmp;
                localB->nDone = 4;
                while (localB->nLeft > 1)
                {
                    if ((static_cast<uint32_T>(localB->nLeft) & 1U) != 0U)
                    {
                        localB->nLeft--;
                        localB->i1_b = localB->nDone * localB->nLeft;
                        localB->b_i = localB->vwork_size_idx_0 - localB->i1_b;
                        if (localB->b_i > localB->nDone)
                        {
                            GNSSPreProcessingDualAnte_merge(localB->b_idx_data, localB->b_x_data, localB->i1_b,
                                localB->nDone, localB->b_i - localB->nDone, localB->iwork_data, localB->vwork_data,
                                localB);
                        }
                    }

                    localB->b_i = localB->nDone << 1;
                    localB->nLeft >>= 1;
                    for (localB->i1_b = 0; localB->i1_b < localB->nLeft; localB->i1_b++)
                    {
                        GNSSPreProcessingDualAnte_merge(localB->b_idx_data, localB->b_x_data, localB->i1_b * localB->b_i,
                            localB->nDone, localB->nDone, localB->iwork_data, localB->vwork_data, localB);
                    }

                    localB->nDone = localB->b_i;
                }

                if (localB->vwork_size_idx_0 > localB->nDone)
                {
                    GNSSPreProcessingDualAnte_merge(localB->b_idx_data, localB->b_x_data, 0, localB->nDone,
                        localB->vwork_size_idx_0 - localB->nDone, localB->iwork_data, localB->vwork_data, localB);
                }
            }
        }

        localB->vwork_size_idx_0 = localB->b_x_size;
        localB->nLeft = localB->b_x_size;
        if (localB->nLeft - 1 >= 0)
        {
            std::memcpy(&localB->vwork_data[0], &localB->b_x_data[0], static_cast<uint32_T>(localB->nLeft) * sizeof
                        (uint16_T));
        }

        for (localB->nLeft = 0; localB->nLeft <= localB->b; localB->nLeft++)
        {
            localB->nDone = localB->nLeft * localB->vstride_o + localB->dim;
            x_data[localB->nDone] = localB->b_x_data[localB->nLeft];
            idx_data[localB->nDone] = localB->b_idx_data[localB->nLeft];
        }
    }
}

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDua_do_vectors(const uint16_T a_data[], const int32_T *a_size, const
    real_T b_data[], const int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size,
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
        real_T bk;
        int32_T b_ialast;
        int32_T b_iblast;
        uint16_T ak;
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
        else if (std::isnan(bk) || (ak < bk))
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

void GNSSPreProcessingDualAntenna::GNSSP_binary_expand_op_evirnrbr(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const gnssops_navigation_data *in3, const real_T in5_data[], const int32_T
    *in5_size)
{
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    in1_size[0] = 1;
    in1_size[1] = *in5_size == 1 ? in2_size[1] : *in5_size;
    stride_0_1 = (in2_size[1] != 1);
    stride_1_1 = (*in5_size != 1);
    loop_ub = *in5_size == 1 ? in2_size[1] : *in5_size;
    for (int32_T i{0}; i < loop_ub; i++)
    {
        in1_data[i] = in2_data[i * stride_0_1] - in3->T_oc[static_cast<int32_T>(in5_data[i * stride_1_1]) - 1];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualA_minus_f4(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    in1_size[0] = 1;
    in1_size[1] = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
    stride_0_1 = (in2_size[1] != 1);
    stride_1_1 = (in3_size[1] != 1);
    loop_ub = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
    for (int32_T i{0}; i < loop_ub; i++)
    {
        in1_data[i] = in2_data[i * stride_0_1] - in3_data[i * stride_1_1];
    }
}

real_T GNSSPreProcessingDualAntenna::GNSSPreProcessing_rt_powd_snf_p(real_T u0, real_T u1,
    B_CalculateDifferentialCorrec_T *localB)
{
    real_T y;
    if (std::isnan(u0) || std::isnan(u1))
    {
        y = (rtNaN);
    }
    else
    {
        localB->d = std::abs(u0);
        localB->d1 = std::abs(u1);
        if (std::isinf(u1))
        {
            if (localB->d == 1.0)
            {
                y = 1.0;
            }
            else if (localB->d > 1.0)
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
        else if (localB->d1 == 0.0)
        {
            y = 1.0;
        }
        else if (localB->d1 == 1.0)
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

void GNSSPreProcessingDualAntenna::GNSSPr_binary_expand_op_evirnrb(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    int32_T in2_size_idx_1;
    int32_T loop_ub;
    int32_T stride_2_1;
    int32_T stride_3_1;
    in2_size_idx_1 = (in4_size[1] == 1 ? in3_size[1] == 1 ? in1_size[1] : in3_size[1] : in4_size[1]) == 1 ? in2_size[1] :
        in4_size[1] == 1 ? in3_size[1] == 1 ? in1_size[1] : in3_size[1] : in4_size[1];
    localB->stride_0_1_d = (in2_size[1] != 1);
    localB->stride_1_1_g = (in1_size[1] != 1);
    stride_2_1 = (in3_size[1] != 1);
    stride_3_1 = (in4_size[1] != 1);
    loop_ub = (in4_size[1] == 1 ? in3_size[1] == 1 ? in1_size[1] : in3_size[1] : in4_size[1]) == 1 ? in2_size[1] :
        in4_size[1] == 1 ? in3_size[1] == 1 ? in1_size[1] : in3_size[1] : in4_size[1];
    for (localB->i20 = 0; localB->i20 < loop_ub; localB->i20++)
    {
        localB->in2_tmp = in4_data[localB->i20 * stride_3_1];
        localB->in2_data_jz[localB->i20] = ((localB->in2_tmp - static_cast<real_T>(localB->in2_tmp > 302400.0) *
            604800.0) + static_cast<real_T>(localB->in2_tmp < -302400.0) * 604800.0) * (in1_data[localB->i20 *
            localB->stride_1_1_g] + in3_data[localB->i20 * stride_2_1]) + in2_data[localB->i20 * localB->stride_0_1_d];
    }

    in1_size[0] = 1;
    in1_size[1] = in2_size_idx_1;
    if (in2_size_idx_1 - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in2_data_jz[0], static_cast<uint32_T>(in2_size_idx_1) * sizeof(real_T));
    }
}

void GNSSPreProcessingDualAntenna::GNSSPre_binary_expand_op_evirnr(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2],
    B_CalculateDifferentialCorrec_T *localB)
{
    in1_size[0] = 1;
    in1_size[1] = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ? in2_size[1] : in3_size[1] == 1 ? in2_size[1] :
        in3_size[1];
    localB->stride_0_1_db = (in2_size[1] != 1);
    localB->stride_1_1_j = (in2_size[1] != 1);
    localB->stride_2_1_i3 = (in3_size[1] != 1);
    localB->loop_ub_h = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ? in2_size[1] : in3_size[1] == 1 ? in2_size
        [1] : in3_size[1];
    for (localB->i22 = 0; localB->i22 < localB->loop_ub_h; localB->i22++)
    {
        in1_data[localB->i22] = static_cast<real_T>(in2_data[localB->i22 * localB->stride_0_1_db] > 0.8) *
            3.1415926535897931 + static_cast<real_T>(in2_data[localB->i22 * localB->stride_1_1_j] <= 0.8) *
            in3_data[localB->i22 * localB->stride_2_1_i3];
    }
}

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
boolean_T GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAntenn_any(const boolean_T x_data[], const int32_T x_size[2],
    B_CalculateDifferentialCorrec_T *localB)
{
    boolean_T exitg1;
    boolean_T y;
    y = false;
    localB->ix = 1;
    exitg1 = false;
    while ((!exitg1) && (localB->ix <= x_size[1]))
    {
        if (x_data[localB->ix - 1])
        {
            y = true;
            exitg1 = true;
        }
        else
        {
            localB->ix++;
        }
    }

    return y;
}

void GNSSPreProcessingDualAntenna::GNSSPreProce_binary_expand_op_e(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2],
    B_CalculateDifferentialCorrec_T *localB)
{
    localB->in2_size_idx_1 = (in1_size[1] == 1 ? in3_size[1] : in1_size[1]) == 1 ? in2_size[1] : in1_size[1] == 1 ?
        in3_size[1] : in1_size[1];
    localB->stride_0_1_l = (in2_size[1] != 1);
    localB->stride_1_1_h = (in3_size[1] != 1);
    localB->stride_2_1 = (in1_size[1] != 1);
    localB->loop_ub_m = (in1_size[1] == 1 ? in3_size[1] : in1_size[1]) == 1 ? in2_size[1] : in1_size[1] == 1 ? in3_size
        [1] : in1_size[1];
    for (localB->i1 = 0; localB->i1 < localB->loop_ub_m; localB->i1++)
    {
        localB->in2_data[localB->i1] = in3_data[localB->i1 * localB->stride_1_1_h] * in1_data[localB->i1 *
            localB->stride_2_1] + in2_data[localB->i1 * localB->stride_0_1_l];
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in2_size_idx_1;
    if (localB->in2_size_idx_1 - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in2_data[0], static_cast<uint32_T>(localB->in2_size_idx_1) * sizeof(real_T));
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAn_minus_f(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in2_size_idx_1_p = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
    localB->stride_0_1_a = (in2_size[1] != 1);
    localB->stride_1_1_d = (in1_size[1] != 1);
    localB->loop_ub_a = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
    for (localB->i8 = 0; localB->i8 < localB->loop_ub_a; localB->i8++)
    {
        localB->in2_data_b[localB->i8] = in2_data[localB->i8 * localB->stride_0_1_a] - in1_data[localB->i8 *
            localB->stride_1_1_d];
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in2_size_idx_1_p;
    if (localB->in2_size_idx_1_p - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in2_data_b[0], static_cast<uint32_T>(localB->in2_size_idx_1_p) * sizeof
                    (real_T));
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreP_binary_expand_op_evirn(real_T in1_data[], int32_T in1_size[2], const
    gnssops_navigation_data *in2, const real_T in4_data[], const int32_T *in4_size, const real_T in5_data[], const
    int32_T in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const real_T in7_data[], const int32_T
    in7_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    int32_T in2_size_idx_1;
    int32_T loop_ub;
    int32_T stride_6_1;
    int32_T stride_7_1;
    in2_size_idx_1 = (in7_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1] : in7_size[1]) == 1 ? (in1_size[1]
        == 1 ? *in4_size : in1_size[1]) == 1 ? (in1_size[1] == 1 ? *in4_size : in1_size[1]) == 1 ? *in4_size : in1_size
        [1] == 1 ? *in4_size : in1_size[1] : in1_size[1] == 1 ? *in4_size : in1_size[1] : in7_size[1] == 1 ? in6_size[1]
        == 1 ? in5_size[1] : in6_size[1] : in7_size[1];
    localB->stride_0_1_cj = (*in4_size != 1);
    localB->stride_1_1_m1 = (*in4_size != 1);
    localB->stride_2_1_jp = (in1_size[1] != 1);
    localB->stride_3_1_kn = (*in4_size != 1);
    localB->stride_4_1_mx = (in1_size[1] != 1);
    localB->stride_5_1_p = (in5_size[1] != 1);
    stride_6_1 = (in6_size[1] != 1);
    stride_7_1 = (in7_size[1] != 1);
    loop_ub = (in7_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1] : in7_size[1]) == 1 ? (in1_size[1] == 1 ?
        *in4_size : in1_size[1]) == 1 ? (in1_size[1] == 1 ? *in4_size : in1_size[1]) == 1 ? *in4_size : in1_size[1] == 1
        ? *in4_size : in1_size[1] : in1_size[1] == 1 ? *in4_size : in1_size[1] : in7_size[1] == 1 ? in6_size[1] == 1 ?
        in5_size[1] : in6_size[1] : in7_size[1];
    for (localB->i18 = 0; localB->i18 < loop_ub; localB->i18++)
    {
        localB->varargin_1_c = in1_data[localB->i18 * localB->stride_4_1_mx];
        localB->in2_data_j[localB->i18] = ((in2->A_f1[static_cast<int32_T>(in4_data[localB->i18 * localB->stride_1_1_m1])
            - 1] * in1_data[localB->i18 * localB->stride_2_1_jp] + in2->A_f0[static_cast<int32_T>(in4_data[localB->i18 *
            localB->stride_0_1_cj]) - 1]) + in2->A_f2[static_cast<int32_T>(in4_data[localB->i18 * localB->stride_3_1_kn])
            - 1] * (localB->varargin_1_c * localB->varargin_1_c)) + in5_data[localB->i18 * localB->stride_5_1_p] *
            -4.44280763339306E-10 * in6_data[localB->i18 * stride_6_1] * in7_data[localB->i18 * stride_7_1];
    }

    in1_size[0] = 1;
    in1_size[1] = in2_size_idx_1;
    if (in2_size_idx_1 - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in2_data_j[0], static_cast<uint32_T>(in2_size_idx_1) * sizeof(real_T));
    }
}

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::correct_Gps_Time_At_Week_Cros_b(real_T b_time_data[], int32_T b_time_size[2])
{
    int32_T loop_ub;
    b_time_size[0] = 1;
    loop_ub = b_time_size[1];
    for (int32_T i{0}; i < loop_ub; i++)
    {
        real_T tmp;
        tmp = b_time_data[i];
        b_time_data[i] = (tmp - static_cast<real_T>(tmp > 302400.0) * 604800.0) + static_cast<real_T>(tmp < -302400.0) *
            604800.0;
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAnt_plus_d(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in1_size_idx_1_l = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
    localB->stride_0_1_ms = (in1_size[1] != 1);
    localB->stride_1_1_o = (in2_size[1] != 1);
    localB->loop_ub_n = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
    for (localB->i9 = 0; localB->i9 < localB->loop_ub_n; localB->i9++)
    {
        localB->in1_data_ln[localB->i9] = in1_data[localB->i9 * localB->stride_0_1_ms] + in2_data[localB->i9 *
            localB->stride_1_1_o];
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in1_size_idx_1_l;
    if (localB->in1_size_idx_1_l - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in1_data_ln[0], static_cast<uint32_T>(localB->in1_size_idx_1_l) * sizeof
                    (real_T));
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_ai(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    in1_size[0] = 1;
    in1_size[1] = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ? in2_size[1] : in4_size[1] == 1 ? in3_size[1] :
        in4_size[1];
    localB->stride_0_1_nm = (in2_size[1] != 1);
    localB->stride_1_1_o3 = (in3_size[1] != 1);
    localB->stride_2_1_ch = (in4_size[1] != 1);
    localB->loop_ub_b = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ? in2_size[1] : in4_size[1] == 1 ? in3_size
        [1] : in4_size[1];
    for (localB->i23 = 0; localB->i23 < localB->loop_ub_b; localB->i23++)
    {
        in1_data[localB->i23] = in3_data[localB->i23 * localB->stride_1_1_o3] * in4_data[localB->i23 *
            localB->stride_2_1_ch] + in2_data[localB->i23 * localB->stride_0_1_nm];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProce_binary_expand_op_b(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2],
    B_CalculateDifferentialCorrec_T *localB)
{
    localB->in1_size_idx_1 = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ? in1_size[1] : in3_size[1] == 1 ?
        in2_size[1] : in3_size[1];
    localB->stride_0_1_f = (in1_size[1] != 1);
    localB->stride_1_1_h2 = (in2_size[1] != 1);
    localB->stride_2_1_e = (in3_size[1] != 1);
    localB->loop_ub_ch = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ? in1_size[1] : in3_size[1] == 1 ?
        in2_size[1] : in3_size[1];
    for (localB->i7 = 0; localB->i7 < localB->loop_ub_ch; localB->i7++)
    {
        localB->in1_data_nu[localB->i7] = in1_data[localB->i7 * localB->stride_0_1_f] / (1.0 - in2_data[localB->i7 *
            localB->stride_1_1_h2] * in3_data[localB->i7 * localB->stride_2_1_e]);
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in1_size_idx_1;
    if (localB->in1_size_idx_1 - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in1_data_nu[0], static_cast<uint32_T>(localB->in1_size_idx_1) * sizeof(real_T));
    }
}

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::Get_Kepler_Eccentric_Anomaly_h(const real_T t_k_data[], const int32_T t_k_size[2],
    const real_T Ephemeris_DELTA_N_data[], const int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[],
    const int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_E_data[], const int32_T Ephemeris_E_size[2], const
    real_T Ephemeris_SQRT_A_data[], const int32_T Ephemeris_SQRT_A_size[2], real_T E_k_data[], int32_T E_k_size[2],
    real_T E_k_Dot_data[], int32_T E_k_Dot_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    __m128d tmp;
    __m128d tmp_0;
    E_k_Dot_size[0] = 1;
    E_k_Dot_size[1] = Ephemeris_SQRT_A_size[1];
    localB->loop_ub_e = Ephemeris_SQRT_A_size[1];
    for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp < localB->loop_ub_e; localB->varargin_1_tmp++)
    {
        localB->varargin_1_m = Ephemeris_SQRT_A_data[localB->varargin_1_tmp];
        E_k_Dot_data[localB->varargin_1_tmp] = 3.986005E+14 / GNSSPreProcessing_rt_powd_snf_p(localB->varargin_1_m *
            localB->varargin_1_m, 3.0, localB);
    }

    localB->i_p = Ephemeris_SQRT_A_size[1];
    localB->scalarLB_o = (Ephemeris_SQRT_A_size[1] / 2) << 1;
    localB->vectorUB_h = localB->scalarLB_o - 2;
    for (localB->loop_ub_e = 0; localB->loop_ub_e <= localB->vectorUB_h; localB->loop_ub_e += 2)
    {
        tmp_0 = _mm_loadu_pd(&E_k_Dot_data[localB->loop_ub_e]);
        _mm_storeu_pd(&E_k_Dot_data[localB->loop_ub_e], _mm_sqrt_pd(tmp_0));
    }

    for (localB->loop_ub_e = localB->scalarLB_o; localB->loop_ub_e < localB->i_p; localB->loop_ub_e++)
    {
        E_k_Dot_data[localB->loop_ub_e] = std::sqrt(E_k_Dot_data[localB->loop_ub_e]);
    }

    if (Ephemeris_SQRT_A_size[1] == Ephemeris_DELTA_N_size[1])
    {
        localB->loop_ub_e = Ephemeris_SQRT_A_size[1] - 1;
        E_k_Dot_size[0] = 1;
        localB->scalarLB_o = (Ephemeris_SQRT_A_size[1] / 2) << 1;
        localB->vectorUB_h = localB->scalarLB_o - 2;
        for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp <= localB->vectorUB_h; localB->varargin_1_tmp += 2)
        {
            tmp_0 = _mm_loadu_pd(&E_k_Dot_data[localB->varargin_1_tmp]);
            _mm_storeu_pd(&E_k_Dot_data[localB->varargin_1_tmp], _mm_add_pd(tmp_0, _mm_loadu_pd
                           (&Ephemeris_DELTA_N_data[localB->varargin_1_tmp])));
        }

        for (localB->varargin_1_tmp = localB->scalarLB_o; localB->varargin_1_tmp <= localB->loop_ub_e;
                localB->varargin_1_tmp++)
        {
            E_k_Dot_data[localB->varargin_1_tmp] += Ephemeris_DELTA_N_data[localB->varargin_1_tmp];
        }
    }
    else
    {
        GNSSPreProcessingDualAnt_plus_d(E_k_Dot_data, E_k_Dot_size, Ephemeris_DELTA_N_data, Ephemeris_DELTA_N_size,
            localB);
    }

    if ((E_k_Dot_size[1] == t_k_size[1]) && ((E_k_Dot_size[1] == 1 ? t_k_size[1] : E_k_Dot_size[1]) ==
            Ephemeris_M_0_size[1]))
    {
        localB->M_k_size[0] = 1;
        localB->M_k_size[1] = Ephemeris_M_0_size[1];
        localB->loop_ub_e = Ephemeris_M_0_size[1];
        localB->scalarLB_o = (Ephemeris_M_0_size[1] / 2) << 1;
        localB->vectorUB_h = localB->scalarLB_o - 2;
        for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp <= localB->vectorUB_h; localB->varargin_1_tmp += 2)
        {
            tmp_0 = _mm_loadu_pd(&E_k_Dot_data[localB->varargin_1_tmp]);
            _mm_storeu_pd(&localB->M_k_data[localB->varargin_1_tmp], _mm_add_pd(_mm_mul_pd(tmp_0, _mm_loadu_pd
                            (&t_k_data[localB->varargin_1_tmp])), _mm_loadu_pd(&Ephemeris_M_0_data
                            [localB->varargin_1_tmp])));
        }

        for (localB->varargin_1_tmp = localB->scalarLB_o; localB->varargin_1_tmp < localB->loop_ub_e;
                localB->varargin_1_tmp++)
        {
            localB->M_k_data[localB->varargin_1_tmp] = E_k_Dot_data[localB->varargin_1_tmp] * t_k_data
                [localB->varargin_1_tmp] + Ephemeris_M_0_data[localB->varargin_1_tmp];
        }
    }
    else
    {
        GNSSPreProc_binary_expand_op_ai(localB->M_k_data, localB->M_k_size, Ephemeris_M_0_data, Ephemeris_M_0_size,
            E_k_Dot_data, E_k_Dot_size, t_k_data, t_k_size, localB);
    }

    if ((Ephemeris_E_size[1] == localB->M_k_size[1]) && ((Ephemeris_E_size[1] == 1 ? localB->M_k_size[1] :
            Ephemeris_E_size[1]) == Ephemeris_E_size[1]))
    {
        E_k_size[0] = 1;
        E_k_size[1] = Ephemeris_E_size[1];
        localB->loop_ub_e = Ephemeris_E_size[1];
        for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp < localB->loop_ub_e; localB->varargin_1_tmp++)
        {
            localB->varargin_1_m = Ephemeris_E_data[localB->varargin_1_tmp];
            E_k_data[localB->varargin_1_tmp] = static_cast<real_T>(localB->varargin_1_m > 0.8) * 3.1415926535897931 +
                static_cast<real_T>(localB->varargin_1_m <= 0.8) * localB->M_k_data[localB->varargin_1_tmp];
        }
    }
    else
    {
        GNSSPre_binary_expand_op_evirnr(E_k_data, E_k_size, Ephemeris_E_data, Ephemeris_E_size, localB->M_k_data,
            localB->M_k_size, localB);
    }

    localB->i_p = 0;
    localB->eps_size_idx_1 = E_k_size[1];
    localB->loop_ub_e = E_k_size[1];
    for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp < localB->loop_ub_e; localB->varargin_1_tmp++)
    {
        localB->eps_data[localB->varargin_1_tmp] = 1.0;
    }

    int32_T exitg1;
    do
    {
        exitg1 = 0;
        localB->eps_size[0] = 1;
        localB->eps_size[1] = localB->eps_size_idx_1;
        for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp < localB->eps_size_idx_1; localB->varargin_1_tmp++)
        {
            localB->eps_data_i[localB->varargin_1_tmp] = (localB->eps_data[localB->varargin_1_tmp] > 1.0E-15);
        }

        if (GNSSPreProcessingDualAntenn_any(localB->eps_data_i, localB->eps_size, localB) && (localB->i_p < 20))
        {
            localB->E_k_old_size_c[0] = 1;
            localB->E_k_old_size_c[1] = E_k_size[1];
            localB->loop_ub_e = E_k_size[1];
            if (localB->loop_ub_e - 1 >= 0)
            {
                std::memcpy(&localB->E_k_old_data_d[0], &E_k_data[0], static_cast<uint32_T>(localB->loop_ub_e) * sizeof
                            (real_T));
            }

            localB->scalarLB_o = E_k_size[1];
            for (localB->vectorUB_h = 0; localB->vectorUB_h < localB->scalarLB_o; localB->vectorUB_h++)
            {
                E_k_data[localB->vectorUB_h] = std::sin(E_k_data[localB->vectorUB_h]);
            }

            if ((Ephemeris_E_size[1] == E_k_size[1]) && ((Ephemeris_E_size[1] == 1 ? E_k_size[1] : Ephemeris_E_size[1]) ==
                 localB->M_k_size[1]))
            {
                localB->loop_ub_e = localB->M_k_size[1] - 1;
                E_k_size[0] = 1;
                E_k_size[1] = localB->M_k_size[1];
                localB->scalarLB_o = (localB->M_k_size[1] / 2) << 1;
                localB->vectorUB_h = localB->scalarLB_o - 2;
                for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp <= localB->vectorUB_h; localB->varargin_1_tmp +=
                     2)
                {
                    tmp_0 = _mm_loadu_pd(&E_k_data[localB->varargin_1_tmp]);
                    tmp = _mm_loadu_pd(&localB->M_k_data[localB->varargin_1_tmp]);
                    _mm_storeu_pd(&E_k_data[localB->varargin_1_tmp], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
                                    (&Ephemeris_E_data[localB->varargin_1_tmp]), tmp_0), tmp));
                }

                for (localB->varargin_1_tmp = localB->scalarLB_o; localB->varargin_1_tmp <= localB->loop_ub_e;
                        localB->varargin_1_tmp++)
                {
                    E_k_data[localB->varargin_1_tmp] = Ephemeris_E_data[localB->varargin_1_tmp] * E_k_data
                        [localB->varargin_1_tmp] + localB->M_k_data[localB->varargin_1_tmp];
                }
            }
            else
            {
                GNSSPreProce_binary_expand_op_e(E_k_data, E_k_size, localB->M_k_data, localB->M_k_size, Ephemeris_E_data,
                    Ephemeris_E_size, localB);
            }

            if (E_k_size[1] == localB->E_k_old_size_c[1])
            {
                localB->loop_ub_e = E_k_size[1] - 1;
                localB->E_k_old_size_c[1] = E_k_size[1];
                localB->scalarLB_o = (E_k_size[1] / 2) << 1;
                localB->vectorUB_h = localB->scalarLB_o - 2;
                for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp <= localB->vectorUB_h; localB->varargin_1_tmp +=
                     2)
                {
                    tmp_0 = _mm_loadu_pd(&E_k_data[localB->varargin_1_tmp]);
                    tmp = _mm_loadu_pd(&localB->E_k_old_data_d[localB->varargin_1_tmp]);
                    _mm_storeu_pd(&localB->E_k_old_data_d[localB->varargin_1_tmp], _mm_sub_pd(tmp_0, tmp));
                }

                for (localB->varargin_1_tmp = localB->scalarLB_o; localB->varargin_1_tmp <= localB->loop_ub_e;
                        localB->varargin_1_tmp++)
                {
                    localB->E_k_old_data_d[localB->varargin_1_tmp] = E_k_data[localB->varargin_1_tmp] -
                        localB->E_k_old_data_d[localB->varargin_1_tmp];
                }
            }
            else
            {
                GNSSPreProcessingDualAn_minus_f(localB->E_k_old_data_d, localB->E_k_old_size_c, E_k_data, E_k_size,
                    localB);
            }

            localB->eps_size_idx_1 = localB->E_k_old_size_c[1];
            localB->scalarLB_o = localB->E_k_old_size_c[1];
            for (localB->vectorUB_h = 0; localB->vectorUB_h < localB->scalarLB_o; localB->vectorUB_h++)
            {
                localB->eps_data[localB->vectorUB_h] = std::abs(localB->E_k_old_data_d[localB->vectorUB_h]);
            }

            localB->i_p++;
        }
        else
        {
            exitg1 = 1;
        }
    }
    while (exitg1 == 0);

    localB->M_k_size[0] = 1;
    localB->M_k_size[1] = E_k_size[1];
    localB->loop_ub_e = E_k_size[1];
    if (localB->loop_ub_e - 1 >= 0)
    {
        std::memcpy(&localB->M_k_data[0], &E_k_data[0], static_cast<uint32_T>(localB->loop_ub_e) * sizeof(real_T));
    }

    localB->i_p = E_k_size[1];
    for (localB->scalarLB_o = 0; localB->scalarLB_o < localB->i_p; localB->scalarLB_o++)
    {
        localB->M_k_data[localB->scalarLB_o] = std::cos(localB->M_k_data[localB->scalarLB_o]);
    }

    if ((Ephemeris_E_size[1] == E_k_size[1]) && ((Ephemeris_E_size[1] == 1 ? E_k_size[1] : Ephemeris_E_size[1]) ==
            E_k_Dot_size[1]))
    {
        localB->loop_ub_e = E_k_Dot_size[1] - 1;
        E_k_Dot_size[0] = 1;
        localB->scalarLB_o = (E_k_Dot_size[1] / 2) << 1;
        localB->vectorUB_h = localB->scalarLB_o - 2;
        for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp <= localB->vectorUB_h; localB->varargin_1_tmp += 2)
        {
            tmp_0 = _mm_loadu_pd(&localB->M_k_data[localB->varargin_1_tmp]);
            tmp = _mm_loadu_pd(&E_k_Dot_data[localB->varargin_1_tmp]);
            _mm_storeu_pd(&E_k_Dot_data[localB->varargin_1_tmp], _mm_div_pd(tmp, _mm_sub_pd(_mm_set1_pd(1.0), _mm_mul_pd
                            (_mm_loadu_pd(&Ephemeris_E_data[localB->varargin_1_tmp]), tmp_0))));
        }

        for (localB->varargin_1_tmp = localB->scalarLB_o; localB->varargin_1_tmp <= localB->loop_ub_e;
                localB->varargin_1_tmp++)
        {
            E_k_Dot_data[localB->varargin_1_tmp] /= 1.0 - Ephemeris_E_data[localB->varargin_1_tmp] * localB->
                M_k_data[localB->varargin_1_tmp];
        }
    }
    else
    {
        GNSSPreProce_binary_expand_op_b(E_k_Dot_data, E_k_Dot_size, Ephemeris_E_data, Ephemeris_E_size, localB->M_k_data,
            localB->M_k_size, localB);
    }
}

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAnte_cos_p(real_T x_data[], const int32_T x_size[2])
{
    int32_T b;
    b = x_size[1];
    for (int32_T k{0}; k < b; k++)
    {
        x_data[k] = std::cos(x_data[k]);
    }
}

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAnte_sin_l(real_T x_data[], const int32_T x_size[2])
{
    int32_T b;
    b = x_size[1];
    for (int32_T k{0}; k < b; k++)
    {
        x_data[k] = std::sin(x_data[k]);
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualA_times_ce(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    in1_size[0] = 1;
    in1_size[1] = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
    stride_0_1 = (in2_size[1] != 1);
    stride_1_1 = (in3_size[1] != 1);
    loop_ub = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
    for (int32_T i{0}; i < loop_ub; i++)
    {
        in1_data[i] = in2_data[i * stride_0_1] * in3_data[i * stride_1_1];
    }
}

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAnt_sqrt_f(real_T x_data[], const int32_T x_size[2],
    B_CalculateDifferentialCorrec_T *localB)
{
    localB->b_f = x_size[1];
    localB->scalarLB_i = (x_size[1] / 2) << 1;
    localB->vectorUB_l = localB->scalarLB_i - 2;
    for (localB->k_n = 0; localB->k_n <= localB->vectorUB_l; localB->k_n += 2)
    {
        __m128d tmp;
        tmp = _mm_loadu_pd(&x_data[localB->k_n]);
        _mm_storeu_pd(&x_data[localB->k_n], _mm_sqrt_pd(tmp));
    }

    for (localB->k_n = localB->scalarLB_i; localB->k_n < localB->b_f; localB->k_n++)
    {
        x_data[localB->k_n] = std::sqrt(x_data[localB->k_n]);
    }
}

real_T GNSSPreProcessingDualAntenna::GNSSPreProcessi_rt_atan2d_snf_j(real_T u0, real_T u1,
    B_CalculateDifferentialCorrec_T *localB)
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
            localB->i3 = 1;
        }
        else
        {
            localB->i3 = -1;
        }

        if (u1 > 0.0)
        {
            localB->i4 = 1;
        }
        else
        {
            localB->i4 = -1;
        }

        y = std::atan2(static_cast<real_T>(localB->i3), static_cast<real_T>(localB->i4));
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

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::GNSSPreProcessin_expand_atan2_l(const real_T a_data[], const int32_T a_size[2], const
    real_T b_data[], const int32_T b_size[2], real_T c_data[], int32_T c_size[2], B_CalculateDifferentialCorrec_T
    *localB)
{
    if (b_size[1] == 1)
    {
        localB->csz_idx_1 = static_cast<int8_T>(a_size[1]);
    }
    else if (a_size[1] == 1)
    {
        localB->csz_idx_1 = static_cast<int8_T>(b_size[1]);
    }
    else if (a_size[1] <= b_size[1])
    {
        localB->csz_idx_1 = static_cast<int8_T>(a_size[1]);
    }
    else
    {
        localB->csz_idx_1 = static_cast<int8_T>(b_size[1]);
    }

    c_size[0] = 1;
    c_size[1] = localB->csz_idx_1;
    if (localB->csz_idx_1 != 0)
    {
        localB->d_i = (a_size[1] != 1);
        localB->e = (b_size[1] != 1);
        localB->f = localB->csz_idx_1 - 1;
        for (localB->k_p = 0; localB->k_p <= localB->f; localB->k_p++)
        {
            c_data[localB->k_p] = GNSSPreProcessi_rt_atan2d_snf_j(a_data[localB->d_i * localB->k_p], b_data[localB->e *
                localB->k_p], localB);
        }
    }
}

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAn_atan2_d(const real_T y_data[], const int32_T y_size[2], const
    real_T x_data[], const int32_T x_size[2], real_T r_data[], int32_T r_size[2], B_CalculateDifferentialCorrec_T
    *localB)
{
    if (y_size[1] == x_size[1])
    {
        r_size[0] = 1;
        r_size[1] = y_size[1];
        localB->loop_ub_p = y_size[1];
        for (localB->r_data_tmp = 0; localB->r_data_tmp < localB->loop_ub_p; localB->r_data_tmp++)
        {
            r_data[localB->r_data_tmp] = GNSSPreProcessi_rt_atan2d_snf_j(y_data[localB->r_data_tmp], x_data
                [localB->r_data_tmp], localB);
        }
    }
    else
    {
        GNSSPreProcessin_expand_atan2_l(y_data, y_size, x_data, x_size, r_data, r_size, localB);
    }
}

void GNSSPreProcessingDualAntenna::GNSS_binary_expand_op_evirnrbrc(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const
    int32_T in6_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in2_size_l[0] = 1;
    localB->in2_size_l[1] = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in4_size[1];
    localB->stride_0_1_p = (in2_size[1] != 1);
    localB->stride_1_1_a = (in3_size[1] != 1);
    localB->stride_2_1_j = (in4_size[1] != 1);
    localB->loop_ub_ek = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in4_size[1];
    for (localB->i5 = 0; localB->i5 < localB->loop_ub_ek; localB->i5++)
    {
        localB->in2_data_o[localB->i5] = in2_data[localB->i5 * localB->stride_0_1_p] * in3_data[localB->i5 *
            localB->stride_1_1_a] / in4_data[localB->i5 * localB->stride_2_1_j];
    }

    localB->in5_size_m[0] = 1;
    localB->in5_size_m[1] = in4_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1] : in4_size[1];
    localB->stride_0_1_p = (in5_size[1] != 1);
    localB->stride_1_1_a = (in6_size[1] != 1);
    localB->stride_2_1_j = (in4_size[1] != 1);
    localB->loop_ub_ek = in4_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1] : in4_size[1];
    for (localB->i5 = 0; localB->i5 < localB->loop_ub_ek; localB->i5++)
    {
        localB->in5_data_b[localB->i5] = (in5_data[localB->i5 * localB->stride_0_1_p] - in6_data[localB->i5 *
            localB->stride_1_1_a]) / in4_data[localB->i5 * localB->stride_2_1_j];
    }

    GNSSPreProcessingDualAn_atan2_d(localB->in2_data_o, localB->in2_size_l, localB->in5_data_b, localB->in5_size_m,
        in1_data, in1_size, localB);
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_ka(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const
    int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in2_size[0] = 1;
    localB->in2_size[1] = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in4_size[1];
    localB->stride_0_1_m = (in2_size[1] != 1);
    localB->stride_1_1_h3 = (in3_size[1] != 1);
    localB->stride_2_1_c = (in4_size[1] != 1);
    localB->loop_ub_k = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in4_size[1];
    for (localB->i2 = 0; localB->i2 < localB->loop_ub_k; localB->i2++)
    {
        localB->in2_data_d[localB->i2] = in2_data[localB->i2 * localB->stride_0_1_m] * in3_data[localB->i2 *
            localB->stride_1_1_h3] / in4_data[localB->i2 * localB->stride_2_1_c];
    }

    localB->in5_size[0] = 1;
    localB->in5_size[1] = in4_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1] : in4_size[1];
    localB->stride_0_1_m = (in5_size[1] != 1);
    localB->stride_1_1_h3 = (in6_size[1] != 1);
    localB->stride_2_1_c = (in4_size[1] != 1);
    localB->loop_ub_k = in4_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1] : in4_size[1];
    for (localB->i2 = 0; localB->i2 < localB->loop_ub_k; localB->i2++)
    {
        localB->in5_data[localB->i2] = (in5_data[localB->i2 * localB->stride_0_1_m] - in6_data[localB->i2 *
            localB->stride_1_1_h3]) / in4_data[localB->i2 * localB->stride_2_1_c];
    }

    GNSSPreProcessingDualAn_atan2_d(localB->in2_data_d, localB->in2_size, localB->in5_data, localB->in5_size,
        localB->tmp_data_l, localB->tmp_size_o, localB);
    in1_size[0] = 1;
    in1_size[1] = in7_size[1] == 1 ? localB->tmp_size_o[1] : in7_size[1];
    localB->stride_0_1_m = (localB->tmp_size_o[1] != 1);
    localB->stride_1_1_h3 = (in7_size[1] != 1);
    localB->loop_ub_k = in7_size[1] == 1 ? localB->tmp_size_o[1] : in7_size[1];
    for (localB->i2 = 0; localB->i2 < localB->loop_ub_k; localB->i2++)
    {
        in1_data[localB->i2] = localB->tmp_data_l[localB->i2 * localB->stride_0_1_m] + in7_data[localB->i2 *
            localB->stride_1_1_h3];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_jl(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2], B_CalculateDifferentialCorrec_T
    *localB)
{
    localB->in1_size_idx_1_f = ((in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in3_size[1] == 1 ? in2_size[1] :
        in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in1_size[1] : (in5_size[1] == 1 ? in4_size[1]
        : in5_size[1]) == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1];
    localB->stride_0_1_o = (in1_size[1] != 1);
    localB->stride_1_1_k = (in2_size[1] != 1);
    localB->stride_2_1_i = (in3_size[1] != 1);
    localB->stride_3_1_o = (in4_size[1] != 1);
    localB->stride_4_1_m = (in5_size[1] != 1);
    localB->loop_ub_cu = ((in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in3_size[1] == 1 ? in2_size[1] :
                          in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in1_size[1] : (in5_size[1] ==
        1 ? in4_size[1] : in5_size[1]) == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ?
        in4_size[1] : in5_size[1];
    for (localB->i11 = 0; localB->i11 < localB->loop_ub_cu; localB->i11++)
    {
        localB->in1_data_b[localB->i11] = (in2_data[localB->i11 * localB->stride_1_1_k] * in3_data[localB->i11 *
            localB->stride_2_1_i] + in4_data[localB->i11 * localB->stride_3_1_o] * in5_data[localB->i11 *
            localB->stride_4_1_m]) + in1_data[localB->i11 * localB->stride_0_1_o];
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in1_size_idx_1_f;
    if (localB->in1_size_idx_1_f - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in1_data_b[0], static_cast<uint32_T>(localB->in1_size_idx_1_f) * sizeof
                    (real_T));
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_ik(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const
    int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    in1_size[0] = 1;
    in1_size[1] = ((in7_size[1] == 1 ? in6_size[1] : in7_size[1]) == 1 ? in5_size[1] == 1 ? in4_size[1] : in5_size[1] :
                   in7_size[1] == 1 ? in6_size[1] : in7_size[1]) == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] :
        (in7_size[1] == 1 ? in6_size[1] : in7_size[1]) == 1 ? in5_size[1] == 1 ? in4_size[1] : in5_size[1] : in7_size[1]
        == 1 ? in6_size[1] : in7_size[1];
    localB->stride_0_1_dk = (in2_size[1] != 1);
    localB->stride_1_1_oi = (in3_size[1] != 1);
    localB->stride_2_1_jr = (in4_size[1] != 1);
    localB->stride_3_1_c = (in5_size[1] != 1);
    localB->stride_4_1_h = (in6_size[1] != 1);
    localB->stride_5_1_d = (in7_size[1] != 1);
    localB->loop_ub_c5 = ((in7_size[1] == 1 ? in6_size[1] : in7_size[1]) == 1 ? in5_size[1] == 1 ? in4_size[1] :
                          in5_size[1] : in7_size[1] == 1 ? in6_size[1] : in7_size[1]) == 1 ? in3_size[1] == 1 ?
        in2_size[1] : in3_size[1] : (in7_size[1] == 1 ? in6_size[1] : in7_size[1]) == 1 ? in5_size[1] == 1 ? in4_size[1]
        : in5_size[1] : in7_size[1] == 1 ? in6_size[1] : in7_size[1];
    for (localB->i26 = 0; localB->i26 < localB->loop_ub_c5; localB->i26++)
    {
        localB->varargin_1_m3 = in2_data[localB->i26 * localB->stride_0_1_dk];
        in1_data[localB->i26] = (1.0 - in3_data[localB->i26 * localB->stride_1_1_oi]) * (localB->varargin_1_m3 *
            localB->varargin_1_m3) + (in4_data[localB->i26 * localB->stride_2_1_jr] * in5_data[localB->i26 *
            localB->stride_3_1_c] + in6_data[localB->i26 * localB->stride_4_1_h] * in7_data[localB->i26 *
            localB->stride_5_1_d]);
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProce_binary_expand_op_j(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const
    int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
    in8_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    in1_size[0] = 1;
    in1_size[1] = (in8_size[1] == 1 ? in7_size[1] : in8_size[1]) == 1 ? ((in6_size[1] == 1 ? in5_size[1] : in6_size[1]) ==
        1 ? in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ?
        in2_size[1] : (in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ? in4_size[1] == 1 ? in3_size[1] : in4_size[1]
        : in6_size[1] == 1 ? in5_size[1] : in6_size[1] : in8_size[1] == 1 ? in7_size[1] : in8_size[1];
    localB->stride_0_1_pw = (in2_size[1] != 1);
    localB->stride_1_1_pi = (in3_size[1] != 1);
    localB->stride_2_1_a4 = (in4_size[1] != 1);
    localB->stride_3_1_ow = (in5_size[1] != 1);
    localB->stride_4_1_j = (in6_size[1] != 1);
    localB->stride_5_1_pi = (in7_size[1] != 1);
    localB->stride_6_1_o = (in8_size[1] != 1);
    localB->loop_ub_l = (in8_size[1] == 1 ? in7_size[1] : in8_size[1]) == 1 ? ((in6_size[1] == 1 ? in5_size[1] :
        in6_size[1]) == 1 ? in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1] : in6_size[1])
        == 1 ? in2_size[1] : (in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ? in4_size[1] == 1 ? in3_size[1] :
        in4_size[1] : in6_size[1] == 1 ? in5_size[1] : in6_size[1] : in8_size[1] == 1 ? in7_size[1] : in8_size[1];
    for (localB->i27 = 0; localB->i27 < localB->loop_ub_l; localB->i27++)
    {
        in1_data[localB->i27] = ((in3_data[localB->i27 * localB->stride_1_1_pi] * in4_data[localB->i27 *
            localB->stride_2_1_a4] + in5_data[localB->i27 * localB->stride_3_1_ow] * in6_data[localB->i27 *
            localB->stride_4_1_j]) + in2_data[localB->i27 * localB->stride_0_1_pw]) + in7_data[localB->i27 *
            localB->stride_5_1_pi] * in8_data[localB->i27 * localB->stride_6_1_o];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_nf(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in2_size_idx_1_g = in4_size[1] == 1 ? (in1_size[1] == 1 ? in3_size[1] : in1_size[1]) == 1 ? in2_size[1] :
        in1_size[1] == 1 ? in3_size[1] : in1_size[1] : in4_size[1];
    localB->stride_0_1_mv = (in2_size[1] != 1);
    localB->stride_1_1_m0 = (in3_size[1] != 1);
    localB->stride_2_1_jg = (in1_size[1] != 1);
    localB->stride_3_1_f = (in4_size[1] != 1);
    localB->loop_ub_a5 = in4_size[1] == 1 ? (in1_size[1] == 1 ? in3_size[1] : in1_size[1]) == 1 ? in2_size[1] :
        in1_size[1] == 1 ? in3_size[1] : in1_size[1] : in4_size[1];
    for (localB->i14 = 0; localB->i14 < localB->loop_ub_a5; localB->i14++)
    {
        localB->in2_data_bj[localB->i14] = (in3_data[localB->i14 * localB->stride_1_1_m0] * in1_data[localB->i14 *
            localB->stride_2_1_jg] + in2_data[localB->i14 * localB->stride_0_1_mv]) - in4_data[localB->i14 *
            localB->stride_3_1_f] * 7.2921151467E-5;
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in2_size_idx_1_g;
    if (localB->in2_size_idx_1_g - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in2_data_bj[0], static_cast<uint32_T>(localB->in2_size_idx_1_g) * sizeof
                    (real_T));
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProcessingDual_times_ce5(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in1_size_idx_1_c = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
    localB->stride_0_1_n3 = (in1_size[1] != 1);
    localB->stride_1_1_oy = (in2_size[1] != 1);
    localB->loop_ub_g = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
    for (localB->i17 = 0; localB->i17 < localB->loop_ub_g; localB->i17++)
    {
        localB->in1_data_a[localB->i17] = in1_data[localB->i17 * localB->stride_0_1_n3] * in2_data[localB->i17 *
            localB->stride_1_1_oy];
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in1_size_idx_1_c;
    if (localB->in1_size_idx_1_c - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in1_data_a[0], static_cast<uint32_T>(localB->in1_size_idx_1_c) * sizeof
                    (real_T));
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_ak(real_T in1_data[], const real_T in2_data[], const
    int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
    in4_size[2], const real_T in5_data[], const int32_T in5_size[2])
{
    int32_T in2_idx_0;
    int32_T stride_0_0;
    int32_T stride_1_0;
    int32_T stride_2_0;
    int32_T stride_3_0;
    in2_idx_0 = in2_size[1];
    stride_0_0 = (in2_size[1] != 1);
    stride_1_0 = (in3_size[1] != 1);
    stride_2_0 = (in4_size[1] != 1);
    stride_3_0 = (in5_size[1] != 1);
    for (int32_T i{0}; i < in2_idx_0; i++)
    {
        in1_data[i] = in2_data[i * stride_0_0] * in3_data[i * stride_1_0] - in4_data[i * stride_2_0] * in5_data[i *
            stride_3_0];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProce_binary_expand_op_o(real_T in1_data[], const int32_T in1_size[2], const
    real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
    in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2])
{
    int32_T in1_idx_0;
    int32_T stride_0_0;
    int32_T stride_1_0;
    int32_T stride_2_0;
    int32_T stride_3_0;
    in1_idx_0 = in1_size[0];
    stride_0_0 = (in2_size[1] != 1);
    stride_1_0 = (in3_size[1] != 1);
    stride_2_0 = (in4_size[1] != 1);
    stride_3_0 = (in5_size[1] != 1);
    for (int32_T i{0}; i < in1_idx_0; i++)
    {
        in1_data[i + in1_size[0]] = in2_data[i * stride_0_0] * in3_data[i * stride_1_0] + in4_data[i * stride_2_0] *
            in5_data[i * stride_3_0];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_ay(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2],
    B_CalculateDifferentialCorrec_T *localB)
{
    localB->in1_size_idx_1_fx = in3_size[1] == 1 ? in2_size[1] == 1 ? in1_size[1] : in2_size[1] : in3_size[1];
    localB->stride_0_1_n = (in1_size[1] != 1);
    localB->stride_1_1_d3 = (in2_size[1] != 1);
    localB->stride_2_1_n = (in3_size[1] != 1);
    localB->loop_ub_cg = in3_size[1] == 1 ? in2_size[1] == 1 ? in1_size[1] : in2_size[1] : in3_size[1];
    for (localB->i15 = 0; localB->i15 < localB->loop_ub_cg; localB->i15++)
    {
        localB->in1_data_jz[localB->i15] = in1_data[localB->i15 * localB->stride_0_1_n] * in2_data[localB->i15 *
            localB->stride_1_1_d3] / in3_data[localB->i15 * localB->stride_2_1_n];
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in1_size_idx_1_fx;
    if (localB->in1_size_idx_1_fx - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in1_data_jz[0], static_cast<uint32_T>(localB->in1_size_idx_1_fx) * sizeof
                    (real_T));
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_ce(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const
    int32_T in6_size[2])
{
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    int32_T stride_2_1;
    int32_T stride_3_1;
    int32_T stride_4_1;
    in1_size[0] = 1;
    in1_size[1] = in6_size[1] == 1 ? (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in3_size[1] == 1 ? in2_size[1]
        : in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1] : in6_size[1];
    stride_0_1 = (in2_size[1] != 1);
    stride_1_1 = (in3_size[1] != 1);
    stride_2_1 = (in4_size[1] != 1);
    stride_3_1 = (in5_size[1] != 1);
    stride_4_1 = (in6_size[1] != 1);
    loop_ub = in6_size[1] == 1 ? (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in3_size[1] == 1 ? in2_size[1] :
        in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1] : in6_size[1];
    for (int32_T i{0}; i < loop_ub; i++)
    {
        in1_data[i] = ((in2_data[i * stride_0_1] * 2.0 * in3_data[i * stride_1_1] + 1.0) - in4_data[i * stride_2_1] *
                       2.0 * in5_data[i * stride_3_1]) * in6_data[i * stride_4_1];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProce_binary_expand_op_d(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const
    int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
    in8_size[2], const real_T in9_data[], const int32_T in9_size[2], const real_T in10_data[], const int32_T in10_size[2],
    B_CalculateDifferentialCorrec_T *localB)
{
    in1_size[0] = 1;
    in1_size[1] = (in10_size[1] == 1 ? in9_size[1] == 1 ? in8_size[1] == 1 ? in7_size[1] : in8_size[1] : in9_size[1] :
                   in10_size[1]) == 1 ? in6_size[1] == 1 ? (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ?
        in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1] : in6_size[1] :
        in10_size[1] == 1 ? in9_size[1] == 1 ? in8_size[1] == 1 ? in7_size[1] : in8_size[1] : in9_size[1] : in10_size[1];
    localB->stride_0_1_c3 = (in2_size[1] != 1);
    localB->stride_1_1_c = (in3_size[1] != 1);
    localB->stride_2_1_if = (in4_size[1] != 1);
    localB->stride_3_1_d = (in5_size[1] != 1);
    localB->stride_4_1_g = (in6_size[1] != 1);
    localB->stride_5_1_l = (in7_size[1] != 1);
    localB->stride_6_1 = (in8_size[1] != 1);
    localB->stride_7_1 = (in9_size[1] != 1);
    localB->stride_8_1 = (in10_size[1] != 1);
    localB->loop_ub_f = (in10_size[1] == 1 ? in9_size[1] == 1 ? in8_size[1] == 1 ? in7_size[1] : in8_size[1] : in9_size
                         [1] : in10_size[1]) == 1 ? in6_size[1] == 1 ? (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) ==
        1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1] : in6_size[1] :
        in10_size[1] == 1 ? in9_size[1] == 1 ? in8_size[1] == 1 ? in7_size[1] : in8_size[1] : in9_size[1] : in10_size[1];
    for (localB->i21 = 0; localB->i21 < localB->loop_ub_f; localB->i21++)
    {
        localB->varargin_1_md = in7_data[localB->i21 * localB->stride_5_1_l];
        in1_data[localB->i21] = (in2_data[localB->i21 * localB->stride_0_1_c3] * in3_data[localB->i21 *
            localB->stride_1_1_c] - in4_data[localB->i21 * localB->stride_2_1_if] * in5_data[localB->i21 *
            localB->stride_3_1_d]) * 2.0 * in6_data[localB->i21 * localB->stride_4_1_g] + localB->varargin_1_md *
            localB->varargin_1_md * in8_data[localB->i21 * localB->stride_6_1] * in9_data[localB->i21 *
            localB->stride_7_1] * in10_data[localB->i21 * localB->stride_8_1];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProce_binary_expand_op_g(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const
    int32_T in6_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->tmp_size_idx_1 = in6_size[1] == 1 ? in5_size[1] == 1 ? (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ?
        in1_size[1] == 1 ? in2_size[1] : in1_size[1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in5_size[1] :
        in6_size[1];
    localB->stride_0_1_pe = (in2_size[1] != 1);
    localB->stride_1_1_p = (in1_size[1] != 1);
    localB->stride_2_1_f = (in3_size[1] != 1);
    localB->stride_3_1 = (in4_size[1] != 1);
    localB->stride_4_1 = (in5_size[1] != 1);
    localB->stride_5_1 = (in6_size[1] != 1);
    localB->loop_ub_i = in6_size[1] == 1 ? in5_size[1] == 1 ? (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ?
        in1_size[1] == 1 ? in2_size[1] : in1_size[1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in5_size[1] :
        in6_size[1];
    for (localB->i10 = 0; localB->i10 < localB->loop_ub_i; localB->i10++)
    {
        localB->tmp_data_h[localB->i10] = (in2_data[localB->i10 * localB->stride_0_1_pe] * in1_data[localB->i10 *
            localB->stride_1_1_p] - in3_data[localB->i10 * localB->stride_2_1_f] * in4_data[localB->i10 *
            localB->stride_3_1]) * 2.0 * in5_data[localB->i10 * localB->stride_4_1] + in6_data[localB->i10 *
            localB->stride_5_1];
    }

    in1_size[0] = 1;
    in1_size[1] = localB->tmp_size_idx_1;
    if (localB->tmp_size_idx_1 - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->tmp_data_h[0], static_cast<uint32_T>(localB->tmp_size_idx_1) * sizeof(real_T));
    }
}

void GNSSPreProcessingDualAntenna::binary_expand_o_evirnrbrctmpazf(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in2_size_idx_1_e = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ? in1_size[1] == 1 ? in2_size[1] :
        in1_size[1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1];
    localB->stride_0_1_c = (in2_size[1] != 1);
    localB->stride_1_1_n = (in1_size[1] != 1);
    localB->stride_2_1_ij = (in3_size[1] != 1);
    localB->stride_3_1_m = (in4_size[1] != 1);
    localB->loop_ub_j = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ? in1_size[1] == 1 ? in2_size[1] : in1_size
        [1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1];
    for (localB->i13 = 0; localB->i13 < localB->loop_ub_j; localB->i13++)
    {
        localB->in2_data_e[localB->i13] = in2_data[localB->i13 * localB->stride_0_1_c] * in1_data[localB->i13 *
            localB->stride_1_1_n] - in3_data[localB->i13 * localB->stride_2_1_ij] * in4_data[localB->i13 *
            localB->stride_3_1_m];
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in2_size_idx_1_e;
    if (localB->in2_size_idx_1_e - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in2_data_e[0], static_cast<uint32_T>(localB->in2_size_idx_1_e) * sizeof
                    (real_T));
    }
}

void GNSSPreProcessingDualAntenna::binary_expand_op_evirnrbrctmpaz(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[],
    const int32_T in4_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in1_size_idx_1_b = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ? in2_size[1] == 1 ? in1_size[1] :
        in2_size[1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1];
    localB->stride_0_1_h = (in1_size[1] != 1);
    localB->stride_1_1_m = (in2_size[1] != 1);
    localB->stride_2_1_a = (in3_size[1] != 1);
    localB->stride_3_1_k = (in4_size[1] != 1);
    localB->loop_ub_pc = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ? in2_size[1] == 1 ? in1_size[1] :
        in2_size[1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1];
    for (localB->i12 = 0; localB->i12 < localB->loop_ub_pc; localB->i12++)
    {
        localB->in1_data_da[localB->i12] = in1_data[localB->i12 * localB->stride_0_1_h] * in2_data[localB->i12 *
            localB->stride_1_1_m] + in3_data[localB->i12 * localB->stride_2_1_a] * in4_data[localB->i12 *
            localB->stride_3_1_k];
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in1_size_idx_1_b;
    if (localB->in1_size_idx_1_b - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in1_data_da[0], static_cast<uint32_T>(localB->in1_size_idx_1_b) * sizeof
                    (real_T));
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAn_times_c(real_T in1_data[], int32_T in1_size[2], const real_T
    in2_data[], const int32_T in2_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in2_size_idx_1_k = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
    localB->stride_0_1_pm = (in2_size[1] != 1);
    localB->stride_1_1_p2 = (in1_size[1] != 1);
    localB->loop_ub_nj = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
    for (localB->i16 = 0; localB->i16 < localB->loop_ub_nj; localB->i16++)
    {
        localB->in2_data_f[localB->i16] = in2_data[localB->i16 * localB->stride_0_1_pm] * in1_data[localB->i16 *
            localB->stride_1_1_p2];
    }

    in1_size[0] = 1;
    in1_size[1] = localB->in2_size_idx_1_k;
    if (localB->in2_size_idx_1_k - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in2_data_f[0], static_cast<uint32_T>(localB->in2_size_idx_1_k) * sizeof
                    (real_T));
    }
}

void GNSSPreProcessingDualAntenna::binary_expand_op_evirnrbrctmpa(real_T in1_data[], const real_T in2_data[], const
    int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
    in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T in6_size[2],
    const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T in8_size[2], const real_T
    in9_data[], const int32_T in9_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in2_idx_0 = in2_size[1];
    localB->stride_0_0_e = (in2_size[1] != 1);
    localB->stride_1_0_d = (in3_size[1] != 1);
    localB->stride_2_0_i = (in4_size[1] != 1);
    localB->stride_3_0_g = (in5_size[1] != 1);
    localB->stride_4_0_n = (in6_size[1] != 1);
    localB->stride_5_0_l = (in5_size[1] != 1);
    localB->stride_6_0_c = (in7_size[1] != 1);
    localB->stride_7_0_n = (in8_size[0] != 1);
    localB->stride_8_0_p = (in9_size[1] != 1);
    for (localB->i25 = 0; localB->i25 < localB->in2_idx_0; localB->i25++)
    {
        in1_data[localB->i25] = ((in2_data[localB->i25 * localB->stride_0_0_e] * in3_data[localB->i25 *
            localB->stride_1_0_d] - in4_data[localB->i25 * localB->stride_2_0_i] * in5_data[localB->i25 *
            localB->stride_3_0_g]) + in6_data[localB->i25 * localB->stride_4_0_n] * in5_data[localB->i25 *
            localB->stride_5_0_l] * in7_data[localB->i25 * localB->stride_6_0_c]) - in8_data[localB->i25 *
            localB->stride_7_0_n + in8_size[0]] * in9_data[localB->i25 * localB->stride_8_0_p];
    }
}

void GNSSPreProcessingDualAntenna::G_binary_expand_op_evirnrbrctmp(real_T in1_data[], const int32_T in1_size[2], const
    real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
    in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const
    int32_T in8_size[2], const real_T in9_data[], const int32_T in9_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in1_idx_0 = in1_size[0];
    localB->stride_0_0 = (in2_size[1] != 1);
    localB->stride_1_0 = (in3_size[1] != 1);
    localB->stride_2_0 = (in4_size[1] != 1);
    localB->stride_3_0 = (in5_size[1] != 1);
    localB->stride_4_0 = (in6_size[1] != 1);
    localB->stride_5_0 = (in5_size[1] != 1);
    localB->stride_6_0 = (in7_size[1] != 1);
    localB->stride_7_0 = (in8_size[0] != 1);
    localB->stride_8_0 = (in9_size[1] != 1);
    for (localB->i24 = 0; localB->i24 < localB->in1_idx_0; localB->i24++)
    {
        in1_data[localB->i24 + in1_size[0]] = ((in2_data[localB->i24 * localB->stride_0_0] * in3_data[localB->i24 *
            localB->stride_1_0] + in4_data[localB->i24 * localB->stride_2_0] * in5_data[localB->i24 * localB->stride_3_0])
            - in6_data[localB->i24 * localB->stride_4_0] * in5_data[localB->i24 * localB->stride_5_0] * in7_data
            [localB->i24 * localB->stride_6_0]) + in8_data[localB->i24 * localB->stride_7_0] * in9_data[localB->i24 *
            localB->stride_8_0];
    }
}

void GNSSPreProcessingDualAntenna::GN_binary_expand_op_evirnrbrctm(real_T in1_data[], const int32_T in1_size[2], const
    real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
    in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2])
{
    int32_T in1_idx_0;
    int32_T stride_0_0;
    int32_T stride_1_0;
    int32_T stride_2_0;
    int32_T stride_3_0;
    in1_idx_0 = in1_size[0];
    stride_0_0 = (in2_size[1] != 1);
    stride_1_0 = (in3_size[1] != 1);
    stride_2_0 = (in4_size[1] != 1);
    stride_3_0 = (in5_size[1] != 1);
    for (int32_T i{0}; i < in1_idx_0; i++)
    {
        in1_data[i + (in1_size[0] << 1)] = in2_data[i * stride_0_0] * in3_data[i * stride_1_0] + in4_data[i * stride_2_0]
            * in5_data[i * stride_3_0];
    }
}

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAn_sqrt_fe(real_T x_data[], const int32_T *x_size,
    B_CalculateDifferentialCorrec_T *localB)
{
    localB->b_k = *x_size;
    localB->scalarLB_fz = (*x_size / 2) << 1;
    localB->vectorUB_c = localB->scalarLB_fz - 2;
    for (localB->k_j = 0; localB->k_j <= localB->vectorUB_c; localB->k_j += 2)
    {
        __m128d tmp;
        tmp = _mm_loadu_pd(&x_data[localB->k_j]);
        _mm_storeu_pd(&x_data[localB->k_j], _mm_sqrt_pd(tmp));
    }

    for (localB->k_j = localB->scalarLB_fz; localB->k_j < localB->b_k; localB->k_j++)
    {
        x_data[localB->k_j] = std::sqrt(x_data[localB->k_j]);
    }
}

// Function for MATLAB Function: '<S29>/Calculate Differential Corrections'
void GNSSPreProcessingDualAntenna::Get_Kepler_Satellite_Position_b(const real_T Ephemeris_C_rs_data[], const int32_T
    Ephemeris_C_rs_size[2], const real_T Ephemeris_DELTA_N_data[], const int32_T Ephemeris_DELTA_N_size[2], const real_T
    Ephemeris_M_0_data[], const int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_C_uc_data[], const int32_T
    Ephemeris_C_uc_size[2], const real_T Ephemeris_E_data[], const int32_T Ephemeris_E_size[2], const real_T
    Ephemeris_C_us_data[], const int32_T Ephemeris_C_us_size[2], const real_T Ephemeris_SQRT_A_data[], const int32_T
    Ephemeris_SQRT_A_size[2], const real_T Ephemeris_T_oe_data[], const int32_T Ephemeris_T_oe_size[2], const real_T
    Ephemeris_C_ic_data[], const int32_T Ephemeris_C_ic_size[2], const real_T Ephemeris_OMEGA_0_data[], const int32_T
    Ephemeris_OMEGA_0_size[2], const real_T Ephemeris_C_is_data[], const int32_T Ephemeris_C_is_size[2], const real_T
    Ephemeris_I_0_data[], const int32_T Ephemeris_I_0_size[2], const real_T Ephemeris_C_rc_data[], const int32_T
    Ephemeris_C_rc_size[2], const real_T Ephemeris_omega_data[], const int32_T Ephemeris_omega_size[2], const real_T
    Ephemeris_OMEGADOT_data[], const int32_T Ephemeris_OMEGADOT_size[2], const real_T Ephemeris_IDOT_data[], const
    int32_T Ephemeris_IDOT_size[2], const real_T T_emission_data[], const int32_T T_emission_size[2], const real_T
    user_position[3], real_T sv_pos_data[], int32_T sv_pos_size[2], real_T sv_vel_data[], int32_T sv_vel_size[2],
    B_CalculateDifferentialCorrec_T *localB)
{
    __m128d tmp;
    __m128d tmp_0;
    __m128d tmp_1;
    __m128d tmp_2;
    __m128d tmp_3;
    __m128d tmp_4;
    __m128d tmp_5;
    __m128d tmp_6;
    if (T_emission_size[1] == Ephemeris_T_oe_size[1])
    {
        localB->t_k_size_g[0] = 1;
        localB->t_k_size_g[1] = T_emission_size[1];
        localB->loop_ub_c = T_emission_size[1];
        localB->scalarLB_f = (T_emission_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            _mm_storeu_pd(&localB->t_k_data_l[localB->t_k_data_tmp], _mm_sub_pd(_mm_loadu_pd(&T_emission_data
                            [localB->t_k_data_tmp]), _mm_loadu_pd(&Ephemeris_T_oe_data[localB->t_k_data_tmp])));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->t_k_data_l[localB->t_k_data_tmp] = T_emission_data[localB->t_k_data_tmp] -
                Ephemeris_T_oe_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProcessingDualA_minus_f4(localB->t_k_data_l, localB->t_k_size_g, T_emission_data, T_emission_size,
            Ephemeris_T_oe_data, Ephemeris_T_oe_size);
    }

    correct_Gps_Time_At_Week_Cros_b(localB->t_k_data_l, localB->t_k_size_g);
    Get_Kepler_Eccentric_Anomaly_h(localB->t_k_data_l, localB->t_k_size_g, Ephemeris_DELTA_N_data,
        Ephemeris_DELTA_N_size, Ephemeris_M_0_data, Ephemeris_M_0_size, Ephemeris_E_data, Ephemeris_E_size,
        Ephemeris_SQRT_A_data, Ephemeris_SQRT_A_size, localB->sinus_E_k_data, localB->sinus_E_k_size,
        localB->E_k_Dot_data, localB->E_k_Dot_size, localB);
    localB->cosinus_E_k_size[0] = 1;
    localB->cosinus_E_k_size[1] = localB->sinus_E_k_size[1];
    localB->loop_ub_c = localB->sinus_E_k_size[1];
    if (localB->loop_ub_c - 1 >= 0)
    {
        std::memcpy(&localB->cosinus_E_k_data[0], &localB->sinus_E_k_data[0], static_cast<uint32_T>(localB->loop_ub_c) *
                    sizeof(real_T));
    }

    GNSSPreProcessingDualAnte_cos_p(localB->cosinus_E_k_data, localB->cosinus_E_k_size);
    GNSSPreProcessingDualAnte_sin_l(localB->sinus_E_k_data, localB->sinus_E_k_size);
    if (Ephemeris_E_size[1] == localB->cosinus_E_k_size[1])
    {
        localB->r_k_Dot_size[0] = 1;
        localB->r_k_Dot_size[1] = Ephemeris_E_size[1];
        localB->loop_ub_c = Ephemeris_E_size[1];
        localB->scalarLB_f = (Ephemeris_E_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->r_k_Dot_data[localB->t_k_data_tmp], _mm_mul_pd(_mm_loadu_pd(&Ephemeris_E_data
                            [localB->t_k_data_tmp]), tmp_6));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->r_k_Dot_data[localB->t_k_data_tmp] = Ephemeris_E_data[localB->t_k_data_tmp] *
                localB->cosinus_E_k_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProcessingDualA_times_ce(localB->r_k_Dot_data, localB->r_k_Dot_size, Ephemeris_E_data, Ephemeris_E_size,
            localB->cosinus_E_k_data, localB->cosinus_E_k_size);
    }

    localB->y_tmp_size[0] = 1;
    localB->y_tmp_size[1] = localB->r_k_Dot_size[1];
    localB->loop_ub_c = localB->r_k_Dot_size[1];
    localB->scalarLB_f = (localB->r_k_Dot_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB_f - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&localB->r_k_Dot_data[localB->t_k_data_tmp]);
        _mm_storeu_pd(&localB->y_tmp_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_set1_pd(1.0), tmp_6));
    }

    for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
    {
        localB->y_tmp_data[localB->t_k_data_tmp] = 1.0 - localB->r_k_Dot_data[localB->t_k_data_tmp];
    }

    localB->f_size[0] = 1;
    localB->f_size[1] = Ephemeris_E_size[1];
    localB->loop_ub_c = Ephemeris_E_size[1];
    localB->scalarLB_f = (Ephemeris_E_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB_f - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&Ephemeris_E_data[localB->t_k_data_tmp]);
        _mm_storeu_pd(&localB->f_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_set1_pd(1.0), _mm_mul_pd(tmp_6, tmp_6)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
    {
        localB->N = Ephemeris_E_data[localB->t_k_data_tmp];
        localB->f_data[localB->t_k_data_tmp] = 1.0 - localB->N * localB->N;
    }

    GNSSPreProcessingDualAnt_sqrt_f(localB->f_data, localB->f_size, localB);
    if ((localB->f_size[1] != localB->sinus_E_k_size[1]) || ((localB->f_size[1] == 1 ? localB->sinus_E_k_size[1] :
            localB->f_size[1]) != localB->r_k_Dot_size[1]) || (localB->cosinus_E_k_size[1] != Ephemeris_E_size[1]) ||
            ((localB->cosinus_E_k_size[1] == 1 ? Ephemeris_E_size[1] : localB->cosinus_E_k_size[1]) !=
             localB->r_k_Dot_size[1]))
    {
        GNSS_binary_expand_op_evirnrbrc(localB->tmp_data, localB->tmp_size, localB->f_data, localB->f_size,
            localB->sinus_E_k_data, localB->sinus_E_k_size, localB->y_tmp_data, localB->y_tmp_size,
            localB->cosinus_E_k_data, localB->cosinus_E_k_size, Ephemeris_E_data, Ephemeris_E_size, localB);
    }

    GNSS_binary_expand_op_evirnrbrc(localB->tmp_data, localB->tmp_size, localB->f_data, localB->f_size,
        localB->sinus_E_k_data, localB->sinus_E_k_size, localB->y_tmp_data, localB->y_tmp_size, localB->cosinus_E_k_data,
        localB->cosinus_E_k_size, Ephemeris_E_data, Ephemeris_E_size, localB);
    if ((localB->f_size[1] == localB->sinus_E_k_size[1]) && ((localB->f_size[1] == 1 ? localB->sinus_E_k_size[1] :
            localB->f_size[1]) == localB->r_k_Dot_size[1]) && (localB->cosinus_E_k_size[1] == Ephemeris_E_size[1]) &&
            ((localB->cosinus_E_k_size[1] == 1 ? Ephemeris_E_size[1] : localB->cosinus_E_k_size[1]) ==
             localB->r_k_Dot_size[1]) && (localB->tmp_size[1] == Ephemeris_omega_size[1]))
    {
        localB->PHI_k_size[0] = 1;
        localB->PHI_k_size[1] = localB->f_size[1];
        localB->loop_ub_c = localB->f_size[1];
        localB->scalarLB_f = (localB->f_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->f_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->sinus_E_k_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->y_tmp_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->PHI_k_data[localB->t_k_data_tmp], _mm_div_pd(_mm_mul_pd(tmp_6, tmp_4), tmp_5));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->PHI_k_data[localB->t_k_data_tmp] = localB->f_data[localB->t_k_data_tmp] * localB->
                sinus_E_k_data[localB->t_k_data_tmp] / localB->y_tmp_data[localB->t_k_data_tmp];
        }

        localB->f_size[0] = 1;
        localB->f_size[1] = localB->cosinus_E_k_size[1];
        localB->loop_ub_c = localB->cosinus_E_k_size[1];
        localB->scalarLB_f = (localB->cosinus_E_k_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->y_tmp_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->f_data[localB->t_k_data_tmp], _mm_div_pd(_mm_sub_pd(tmp_6, _mm_loadu_pd
                            (&Ephemeris_E_data[localB->t_k_data_tmp])), tmp_4));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->f_data[localB->t_k_data_tmp] = (localB->cosinus_E_k_data[localB->t_k_data_tmp] -
                Ephemeris_E_data[localB->t_k_data_tmp]) / localB->y_tmp_data[localB->t_k_data_tmp];
        }

        GNSSPreProcessingDualAn_atan2_d(localB->PHI_k_data, localB->PHI_k_size, localB->f_data, localB->f_size,
            localB->tmp_data, localB->tmp_size, localB);
        localB->PHI_k_size[0] = 1;
        localB->PHI_k_size[1] = localB->tmp_size[1];
        localB->loop_ub_c = localB->tmp_size[1];
        localB->scalarLB_f = (localB->tmp_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->tmp_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->PHI_k_data[localB->t_k_data_tmp], _mm_add_pd(tmp_6, _mm_loadu_pd
                           (&Ephemeris_omega_data[localB->t_k_data_tmp])));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->PHI_k_data[localB->t_k_data_tmp] = localB->tmp_data[localB->t_k_data_tmp] +
                Ephemeris_omega_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProc_binary_expand_op_ka(localB->PHI_k_data, localB->PHI_k_size, localB->f_data, localB->f_size,
            localB->sinus_E_k_data, localB->sinus_E_k_size, localB->y_tmp_data, localB->y_tmp_size,
            localB->cosinus_E_k_data, localB->cosinus_E_k_size, Ephemeris_E_data, Ephemeris_E_size, Ephemeris_omega_data,
            Ephemeris_omega_size, localB);
    }

    localB->cosinus_E_k_size[0] = 1;
    localB->cosinus_E_k_size[1] = localB->PHI_k_size[1];
    localB->loop_ub_c = localB->PHI_k_size[1];
    localB->scalarLB_f = (localB->PHI_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB_f - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&localB->PHI_k_data[localB->t_k_data_tmp]);
        _mm_storeu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp], _mm_mul_pd(_mm_set1_pd(2.0), tmp_6));
    }

    for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
    {
        localB->cosinus_E_k_data[localB->t_k_data_tmp] = 2.0 * localB->PHI_k_data[localB->t_k_data_tmp];
    }

    localB->sin2PHI_k_size[0] = 1;
    localB->sin2PHI_k_size[1] = localB->PHI_k_size[1];
    localB->loop_ub_c = localB->PHI_k_size[1];
    if (localB->loop_ub_c - 1 >= 0)
    {
        std::memcpy(&localB->sin2PHI_k_data[0], &localB->cosinus_E_k_data[0], static_cast<uint32_T>(localB->loop_ub_c) *
                    sizeof(real_T));
    }

    GNSSPreProcessingDualAnte_sin_l(localB->sin2PHI_k_data, localB->sin2PHI_k_size);
    localB->cos2PHI_k_size[0] = 1;
    localB->cos2PHI_k_size[1] = localB->PHI_k_size[1];
    localB->loop_ub_c = localB->PHI_k_size[1];
    if (localB->loop_ub_c - 1 >= 0)
    {
        std::memcpy(&localB->cos2PHI_k_data[0], &localB->cosinus_E_k_data[0], static_cast<uint32_T>(localB->loop_ub_c) *
                    sizeof(real_T));
    }

    GNSSPreProcessingDualAnte_cos_p(localB->cos2PHI_k_data, localB->cos2PHI_k_size);
    if ((Ephemeris_C_us_size[1] == localB->sin2PHI_k_size[1]) && (Ephemeris_C_uc_size[1] == localB->cos2PHI_k_size[1]) &&
        ((Ephemeris_C_us_size[1] == 1 ? localB->sin2PHI_k_size[1] : Ephemeris_C_us_size[1]) == (Ephemeris_C_uc_size[1] ==
          1 ? localB->cos2PHI_k_size[1] : Ephemeris_C_uc_size[1])) && (((Ephemeris_C_us_size[1] == 1 ?
            localB->sin2PHI_k_size[1] : Ephemeris_C_us_size[1]) == 1 ? Ephemeris_C_uc_size[1] == 1 ?
            localB->cos2PHI_k_size[1] : Ephemeris_C_uc_size[1] : Ephemeris_C_us_size[1] == 1 ? localB->sin2PHI_k_size[1]
          : Ephemeris_C_us_size[1]) == localB->PHI_k_size[1]))
    {
        localB->loop_ub_c = localB->PHI_k_size[1] - 1;
        localB->PHI_k_size[0] = 1;
        localB->scalarLB_f = (localB->PHI_k_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->PHI_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->PHI_k_data[localB->t_k_data_tmp], _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd
                             (&Ephemeris_C_us_data[localB->t_k_data_tmp]), tmp_6), _mm_mul_pd(_mm_loadu_pd
                             (&Ephemeris_C_uc_data[localB->t_k_data_tmp]), tmp_4)), tmp_5));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp <= localB->loop_ub_c; localB->t_k_data_tmp
                ++)
        {
            localB->PHI_k_data[localB->t_k_data_tmp] += Ephemeris_C_us_data[localB->t_k_data_tmp] *
                localB->sin2PHI_k_data[localB->t_k_data_tmp] + Ephemeris_C_uc_data[localB->t_k_data_tmp] *
                localB->cos2PHI_k_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProc_binary_expand_op_jl(localB->PHI_k_data, localB->PHI_k_size, Ephemeris_C_us_data, Ephemeris_C_us_size,
            localB->sin2PHI_k_data, localB->sin2PHI_k_size, Ephemeris_C_uc_data, Ephemeris_C_uc_size,
            localB->cos2PHI_k_data, localB->cos2PHI_k_size, localB);
    }

    localB->scalarLB_tmp = (Ephemeris_SQRT_A_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB_tmp - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
        _mm_storeu_pd(&localB->tmp_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
    }

    localB->vectorUB = localB->scalarLB_tmp - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
        _mm_storeu_pd(&localB->tmp_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
    }

    if ((Ephemeris_SQRT_A_size[1] == localB->r_k_Dot_size[1]) && (Ephemeris_C_rs_size[1] == localB->sin2PHI_k_size[1]) &&
        (Ephemeris_C_rc_size[1] == localB->cos2PHI_k_size[1]) && ((Ephemeris_C_rs_size[1] == 1 ? localB->sin2PHI_k_size
            [1] : Ephemeris_C_rs_size[1]) == (Ephemeris_C_rc_size[1] == 1 ? localB->cos2PHI_k_size[1] :
            Ephemeris_C_rc_size[1])) && (((Ephemeris_C_rs_size[1] == 1 ? localB->sin2PHI_k_size[1] :
            Ephemeris_C_rs_size[1]) == 1 ? Ephemeris_C_rc_size[1] == 1 ? localB->cos2PHI_k_size[1] :
            Ephemeris_C_rc_size[1] : Ephemeris_C_rs_size[1] == 1 ? localB->sin2PHI_k_size[1] : Ephemeris_C_rs_size[1]) ==
         (Ephemeris_SQRT_A_size[1] == 1 ? localB->r_k_Dot_size[1] : Ephemeris_SQRT_A_size[1])))
    {
        localB->r_k_size[0] = 1;
        localB->r_k_size[1] = Ephemeris_SQRT_A_size[1];
        localB->loop_ub_c = Ephemeris_SQRT_A_size[1];
        localB->vectorUB = localB->scalarLB_tmp - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->r_k_Dot_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
            tmp_3 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->r_k_data[localB->t_k_data_tmp], _mm_add_pd(_mm_mul_pd(_mm_mul_pd(tmp_6, tmp_6),
                            _mm_sub_pd(_mm_set1_pd(1.0), tmp_4)), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
                             (&Ephemeris_C_rs_data[localB->t_k_data_tmp]), tmp_5), _mm_mul_pd(_mm_loadu_pd
                             (&Ephemeris_C_rc_data[localB->t_k_data_tmp]), tmp_3))));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_tmp; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp
                ++)
        {
            localB->N = Ephemeris_SQRT_A_data[localB->t_k_data_tmp];
            localB->r_k_data[localB->t_k_data_tmp] = localB->N * localB->N * (1.0 - localB->r_k_Dot_data
                [localB->t_k_data_tmp]) + (Ephemeris_C_rs_data[localB->t_k_data_tmp] * localB->sin2PHI_k_data
                [localB->t_k_data_tmp] + Ephemeris_C_rc_data[localB->t_k_data_tmp] * localB->cos2PHI_k_data
                [localB->t_k_data_tmp]);
        }
    }
    else
    {
        GNSSPreProc_binary_expand_op_ik(localB->r_k_data, localB->r_k_size, Ephemeris_SQRT_A_data, Ephemeris_SQRT_A_size,
            localB->r_k_Dot_data, localB->r_k_Dot_size, Ephemeris_C_rs_data, Ephemeris_C_rs_size, localB->sin2PHI_k_data,
            localB->sin2PHI_k_size, Ephemeris_C_rc_data, Ephemeris_C_rc_size, localB->cos2PHI_k_data,
            localB->cos2PHI_k_size, localB);
    }

    if ((Ephemeris_C_is_size[1] == localB->sin2PHI_k_size[1]) && (Ephemeris_C_ic_size[1] == localB->cos2PHI_k_size[1]) &&
        ((Ephemeris_C_is_size[1] == 1 ? localB->sin2PHI_k_size[1] : Ephemeris_C_is_size[1]) == (Ephemeris_C_ic_size[1] ==
          1 ? localB->cos2PHI_k_size[1] : Ephemeris_C_ic_size[1])) && (((Ephemeris_C_is_size[1] == 1 ?
            localB->sin2PHI_k_size[1] : Ephemeris_C_is_size[1]) == 1 ? Ephemeris_C_ic_size[1] == 1 ?
            localB->cos2PHI_k_size[1] : Ephemeris_C_ic_size[1] : Ephemeris_C_is_size[1] == 1 ? localB->sin2PHI_k_size[1]
          : Ephemeris_C_is_size[1]) == Ephemeris_I_0_size[1]) && (Ephemeris_IDOT_size[1] == localB->t_k_size_g[1]) &&
            ((Ephemeris_I_0_size[1] == 1 ? (Ephemeris_C_is_size[1] == 1 ? localB->sin2PHI_k_size[1] :
            Ephemeris_C_is_size[1]) == 1 ? Ephemeris_C_ic_size[1] == 1 ? localB->cos2PHI_k_size[1] :
              Ephemeris_C_ic_size[1] : Ephemeris_C_is_size[1] == 1 ? localB->sin2PHI_k_size[1] : Ephemeris_C_is_size[1] :
              Ephemeris_I_0_size[1]) == (Ephemeris_IDOT_size[1] == 1 ? localB->t_k_size_g[1] : Ephemeris_IDOT_size[1])))
    {
        localB->i_k_size[0] = 1;
        localB->i_k_size[1] = Ephemeris_I_0_size[1];
        localB->loop_ub_c = Ephemeris_I_0_size[1];
        localB->scalarLB_f = (Ephemeris_I_0_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->t_k_data_l[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->i_k_data[localB->t_k_data_tmp], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
                             (_mm_loadu_pd(&Ephemeris_C_is_data[localB->t_k_data_tmp]), tmp_6), _mm_mul_pd(_mm_loadu_pd(
                               &Ephemeris_C_ic_data[localB->t_k_data_tmp]), tmp_4)), _mm_loadu_pd
                            (&Ephemeris_I_0_data[localB->t_k_data_tmp])), _mm_mul_pd(_mm_loadu_pd
                            (&Ephemeris_IDOT_data[localB->t_k_data_tmp]), tmp_5)));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->i_k_data[localB->t_k_data_tmp] = ((Ephemeris_C_is_data[localB->t_k_data_tmp] *
                localB->sin2PHI_k_data[localB->t_k_data_tmp] + Ephemeris_C_ic_data[localB->t_k_data_tmp] *
                localB->cos2PHI_k_data[localB->t_k_data_tmp]) + Ephemeris_I_0_data[localB->t_k_data_tmp]) +
                Ephemeris_IDOT_data[localB->t_k_data_tmp] * localB->t_k_data_l[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProce_binary_expand_op_j(localB->i_k_data, localB->i_k_size, Ephemeris_I_0_data, Ephemeris_I_0_size,
            Ephemeris_C_is_data, Ephemeris_C_is_size, localB->sin2PHI_k_data, localB->sin2PHI_k_size,
            Ephemeris_C_ic_data, Ephemeris_C_ic_size, localB->cos2PHI_k_data, localB->cos2PHI_k_size,
            Ephemeris_IDOT_data, Ephemeris_IDOT_size, localB->t_k_data_l, localB->t_k_size_g, localB);
    }

    localB->f_size[0] = 1;
    localB->f_size[1] = Ephemeris_OMEGADOT_size[1];
    localB->loop_ub_c = Ephemeris_OMEGADOT_size[1];
    localB->scalarLB_f = (Ephemeris_OMEGADOT_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB_f - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        _mm_storeu_pd(&localB->f_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_loadu_pd(&Ephemeris_OMEGADOT_data
                        [localB->t_k_data_tmp]), _mm_set1_pd(7.2921151467E-5)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
    {
        localB->f_data[localB->t_k_data_tmp] = Ephemeris_OMEGADOT_data[localB->t_k_data_tmp] - 7.2921151467E-5;
    }

    if ((Ephemeris_OMEGADOT_size[1] == localB->t_k_size_g[1]) && ((Ephemeris_OMEGADOT_size[1] == 1 ? localB->t_k_size_g
            [1] : Ephemeris_OMEGADOT_size[1]) == Ephemeris_OMEGA_0_size[1]) && ((Ephemeris_OMEGA_0_size[1] == 1 ?
            Ephemeris_OMEGADOT_size[1] == 1 ? localB->t_k_size_g[1] : Ephemeris_OMEGADOT_size[1] :
            Ephemeris_OMEGA_0_size[1]) == Ephemeris_T_oe_size[1]))
    {
        localB->loop_ub_c = Ephemeris_OMEGA_0_size[1] - 1;
        localB->t_k_size_g[0] = 1;
        localB->t_k_size_g[1] = Ephemeris_OMEGA_0_size[1];
        localB->scalarLB_f = (Ephemeris_OMEGA_0_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->f_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->t_k_data_l[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->t_k_data_l[localB->t_k_data_tmp], _mm_sub_pd(_mm_add_pd(_mm_mul_pd(tmp_6, tmp_4),
                            _mm_loadu_pd(&Ephemeris_OMEGA_0_data[localB->t_k_data_tmp])), _mm_mul_pd(_mm_set1_pd
                            (7.2921151467E-5), _mm_loadu_pd(&Ephemeris_T_oe_data[localB->t_k_data_tmp]))));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp <= localB->loop_ub_c; localB->t_k_data_tmp
                ++)
        {
            localB->t_k_data_l[localB->t_k_data_tmp] = (localB->f_data[localB->t_k_data_tmp] * localB->t_k_data_l
                [localB->t_k_data_tmp] + Ephemeris_OMEGA_0_data[localB->t_k_data_tmp]) - 7.2921151467E-5 *
                Ephemeris_T_oe_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProc_binary_expand_op_nf(localB->t_k_data_l, localB->t_k_size_g, Ephemeris_OMEGA_0_data,
            Ephemeris_OMEGA_0_size, localB->f_data, localB->f_size, Ephemeris_T_oe_data, Ephemeris_T_oe_size, localB);
    }

    localB->cosinus_u_k_size[0] = 1;
    localB->cosinus_u_k_size[1] = localB->PHI_k_size[1];
    localB->loop_ub_c = localB->PHI_k_size[1];
    if (localB->loop_ub_c - 1 >= 0)
    {
        std::memcpy(&localB->cosinus_u_k_data[0], &localB->PHI_k_data[0], static_cast<uint32_T>(localB->loop_ub_c) *
                    sizeof(real_T));
    }

    GNSSPreProcessingDualAnte_cos_p(localB->cosinus_u_k_data, localB->cosinus_u_k_size);
    GNSSPreProcessingDualAnte_sin_l(localB->PHI_k_data, localB->PHI_k_size);
    localB->cosinus_i_k_size[0] = 1;
    localB->cosinus_i_k_size[1] = localB->i_k_size[1];
    localB->loop_ub_c = localB->i_k_size[1];
    if (localB->loop_ub_c - 1 >= 0)
    {
        std::memcpy(&localB->cosinus_i_k_data[0], &localB->i_k_data[0], static_cast<uint32_T>(localB->loop_ub_c) *
                    sizeof(real_T));
    }

    GNSSPreProcessingDualAnte_cos_p(localB->cosinus_i_k_data, localB->cosinus_i_k_size);
    GNSSPreProcessingDualAnte_sin_l(localB->i_k_data, localB->i_k_size);
    localB->sinus_lambda_k_size[0] = 1;
    localB->sinus_lambda_k_size[1] = localB->t_k_size_g[1];
    localB->loop_ub_c = localB->t_k_size_g[1];
    if (localB->loop_ub_c - 1 >= 0)
    {
        std::memcpy(&localB->sinus_lambda_k_data[0], &localB->t_k_data_l[0], static_cast<uint32_T>(localB->loop_ub_c) *
                    sizeof(real_T));
    }

    GNSSPreProcessingDualAnte_sin_l(localB->sinus_lambda_k_data, localB->sinus_lambda_k_size);
    GNSSPreProcessingDualAnte_cos_p(localB->t_k_data_l, localB->t_k_size_g);
    if (localB->r_k_size[1] == localB->cosinus_u_k_size[1])
    {
        localB->X_k_tmp_size[0] = 1;
        localB->X_k_tmp_size[1] = localB->r_k_size[1];
        localB->loop_ub_c = localB->r_k_size[1];
        localB->scalarLB_f = (localB->r_k_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->cosinus_u_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->X_k_tmp_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_4));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->X_k_tmp_data[localB->t_k_data_tmp] = localB->r_k_data[localB->t_k_data_tmp] *
                localB->cosinus_u_k_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProcessingDualA_times_ce(localB->X_k_tmp_data, localB->X_k_tmp_size, localB->r_k_data, localB->r_k_size,
            localB->cosinus_u_k_data, localB->cosinus_u_k_size);
    }

    if (localB->r_k_size[1] == localB->PHI_k_size[1])
    {
        localB->loop_ub_c = localB->r_k_size[1] - 1;
        localB->r_k_size[0] = 1;
        localB->scalarLB_f = (localB->r_k_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->PHI_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->r_k_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_4));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp <= localB->loop_ub_c; localB->t_k_data_tmp
                ++)
        {
            localB->r_k_data[localB->t_k_data_tmp] *= localB->PHI_k_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProcessingDual_times_ce5(localB->r_k_data, localB->r_k_size, localB->PHI_k_data, localB->PHI_k_size,
            localB);
    }

    sv_pos_size[0] = localB->X_k_tmp_size[1];
    sv_pos_size[1] = 3;
    localB->loop_ub_c = localB->X_k_tmp_size[1] * 3;
    if (localB->loop_ub_c - 1 >= 0)
    {
        std::memset(&sv_pos_data[0], 0, static_cast<uint32_T>(localB->loop_ub_c) * sizeof(real_T));
    }

    if (localB->r_k_size[1] == localB->cosinus_i_k_size[1])
    {
        localB->c_size[0] = 1;
        localB->c_size[1] = localB->r_k_size[1];
        localB->loop_ub_c = localB->r_k_size[1];
        localB->scalarLB_f = (localB->r_k_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->cosinus_i_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->c_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_4));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->c_data[localB->t_k_data_tmp] = localB->r_k_data[localB->t_k_data_tmp] * localB->
                cosinus_i_k_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProcessingDualA_times_ce(localB->c_data, localB->c_size, localB->r_k_data, localB->r_k_size,
            localB->cosinus_i_k_data, localB->cosinus_i_k_size);
    }

    if ((localB->X_k_tmp_size[1] == localB->t_k_size_g[1]) && (localB->c_size[1] == localB->sinus_lambda_k_size[1]) &&
            ((localB->X_k_tmp_size[1] == 1 ? localB->t_k_size_g[1] : localB->X_k_tmp_size[1]) == (localB->c_size[1] == 1
          ? localB->sinus_lambda_k_size[1] : localB->c_size[1])))
    {
        localB->loop_ub_c = localB->X_k_tmp_size[1];
        localB->scalarLB_f = (localB->X_k_tmp_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->X_k_tmp_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->t_k_data_l[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->c_data[localB->t_k_data_tmp]);
            tmp_3 = _mm_loadu_pd(&localB->sinus_lambda_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&sv_pos_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_mul_pd(tmp_6, tmp_4), _mm_mul_pd(tmp_5,
                            tmp_3)));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            sv_pos_data[localB->t_k_data_tmp] = localB->X_k_tmp_data[localB->t_k_data_tmp] * localB->t_k_data_l
                [localB->t_k_data_tmp] - localB->c_data[localB->t_k_data_tmp] * localB->sinus_lambda_k_data
                [localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProc_binary_expand_op_ak(sv_pos_data, localB->X_k_tmp_data, localB->X_k_tmp_size, localB->t_k_data_l,
            localB->t_k_size_g, localB->c_data, localB->c_size, localB->sinus_lambda_k_data, localB->sinus_lambda_k_size);
    }

    if ((localB->X_k_tmp_size[1] == localB->sinus_lambda_k_size[1]) && (localB->c_size[1] == localB->t_k_size_g[1]) &&
            ((localB->X_k_tmp_size[1] == 1 ? localB->sinus_lambda_k_size[1] : localB->X_k_tmp_size[1]) ==
             (localB->c_size[1] == 1 ? localB->t_k_size_g[1] : localB->c_size[1])))
    {
        localB->loop_ub_c = sv_pos_size[0];
        localB->scalarLB_f = (sv_pos_size[0] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->X_k_tmp_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->sinus_lambda_k_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->c_data[localB->t_k_data_tmp]);
            tmp_3 = _mm_loadu_pd(&localB->t_k_data_l[localB->t_k_data_tmp]);
            _mm_storeu_pd(&sv_pos_data[localB->t_k_data_tmp + sv_pos_size[0]], _mm_add_pd(_mm_mul_pd(tmp_6, tmp_4),
                           _mm_mul_pd(tmp_5, tmp_3)));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            sv_pos_data[localB->t_k_data_tmp + sv_pos_size[0]] = localB->X_k_tmp_data[localB->t_k_data_tmp] *
                localB->sinus_lambda_k_data[localB->t_k_data_tmp] + localB->c_data[localB->t_k_data_tmp] *
                localB->t_k_data_l[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProce_binary_expand_op_o(sv_pos_data, sv_pos_size, localB->X_k_tmp_data, localB->X_k_tmp_size,
            localB->sinus_lambda_k_data, localB->sinus_lambda_k_size, localB->c_data, localB->c_size, localB->t_k_data_l,
            localB->t_k_size_g);
    }

    if (localB->r_k_size[1] == localB->i_k_size[1])
    {
        localB->d_size[0] = 1;
        localB->d_size[1] = localB->r_k_size[1];
        localB->loop_ub_c = localB->r_k_size[1];
        localB->scalarLB_f = (localB->r_k_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->i_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->d_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_4));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->d_data[localB->t_k_data_tmp] = localB->r_k_data[localB->t_k_data_tmp] * localB->i_k_data
                [localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProcessingDualA_times_ce(localB->d_data, localB->d_size, localB->r_k_data, localB->r_k_size,
            localB->i_k_data, localB->i_k_size);
    }

    localB->loop_ub_c = sv_pos_size[0];
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
    {
        sv_pos_data[localB->t_k_data_tmp + (sv_pos_size[0] << 1)] = localB->d_data[localB->t_k_data_tmp];
    }

    localB->PHI_k_Dot_size[0] = 1;
    localB->PHI_k_Dot_size[1] = Ephemeris_E_size[1];
    localB->loop_ub_c = Ephemeris_E_size[1];
    localB->scalarLB_f = (Ephemeris_E_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB_f - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&Ephemeris_E_data[localB->t_k_data_tmp]);
        _mm_storeu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_set1_pd(1.0), _mm_mul_pd(tmp_6,
                        tmp_6)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
    {
        localB->N = Ephemeris_E_data[localB->t_k_data_tmp];
        localB->PHI_k_Dot_data[localB->t_k_data_tmp] = 1.0 - localB->N * localB->N;
    }

    GNSSPreProcessingDualAnt_sqrt_f(localB->PHI_k_Dot_data, localB->PHI_k_Dot_size, localB);
    if ((localB->PHI_k_Dot_size[1] == localB->E_k_Dot_size[1]) && ((localB->PHI_k_Dot_size[1] == 1 ?
            localB->E_k_Dot_size[1] : localB->PHI_k_Dot_size[1]) == localB->r_k_Dot_size[1]))
    {
        localB->loop_ub_c = localB->PHI_k_Dot_size[1] - 1;
        localB->PHI_k_Dot_size[0] = 1;
        localB->scalarLB_f = (localB->PHI_k_Dot_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->E_k_Dot_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->y_tmp_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp], _mm_div_pd(_mm_mul_pd(tmp_6, tmp_4), tmp_5));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp <= localB->loop_ub_c; localB->t_k_data_tmp
                ++)
        {
            localB->PHI_k_Dot_data[localB->t_k_data_tmp] = localB->PHI_k_Dot_data[localB->t_k_data_tmp] *
                localB->E_k_Dot_data[localB->t_k_data_tmp] / localB->y_tmp_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProc_binary_expand_op_ay(localB->PHI_k_Dot_data, localB->PHI_k_Dot_size, localB->E_k_Dot_data,
            localB->E_k_Dot_size, localB->y_tmp_data, localB->y_tmp_size, localB);
    }

    if ((Ephemeris_C_us_size[1] == localB->cos2PHI_k_size[1]) && (Ephemeris_C_uc_size[1] == localB->sin2PHI_k_size[1]) &&
        ((Ephemeris_C_us_size[1] == 1 ? localB->cos2PHI_k_size[1] : Ephemeris_C_us_size[1]) == (Ephemeris_C_uc_size[1] ==
          1 ? localB->sin2PHI_k_size[1] : Ephemeris_C_uc_size[1])) && (((Ephemeris_C_us_size[1] == 1 ?
            localB->cos2PHI_k_size[1] : Ephemeris_C_us_size[1]) == 1 ? Ephemeris_C_uc_size[1] == 1 ?
            localB->sin2PHI_k_size[1] : Ephemeris_C_uc_size[1] : Ephemeris_C_us_size[1] == 1 ? localB->cos2PHI_k_size[1]
          : Ephemeris_C_us_size[1]) == localB->PHI_k_Dot_size[1]))
    {
        localB->cosinus_E_k_size[0] = 1;
        localB->cosinus_E_k_size[1] = Ephemeris_C_us_size[1];
        localB->loop_ub_c = Ephemeris_C_us_size[1];
        localB->scalarLB_f = (Ephemeris_C_us_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_set1_pd(2.0);
            tmp_4 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
            tmp_3 = _mm_loadu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp], _mm_mul_pd(_mm_sub_pd(_mm_add_pd(_mm_mul_pd
                             (_mm_mul_pd(tmp_6, _mm_loadu_pd(&Ephemeris_C_us_data[localB->t_k_data_tmp])), tmp_4),
                             _mm_set1_pd(1.0)), _mm_mul_pd(_mm_mul_pd(tmp_6, _mm_loadu_pd(&Ephemeris_C_uc_data
                               [localB->t_k_data_tmp])), tmp_5)), tmp_3));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->cosinus_E_k_data[localB->t_k_data_tmp] = ((2.0 * Ephemeris_C_us_data[localB->t_k_data_tmp] *
                localB->cos2PHI_k_data[localB->t_k_data_tmp] + 1.0) - 2.0 * Ephemeris_C_uc_data[localB->t_k_data_tmp] *
                localB->sin2PHI_k_data[localB->t_k_data_tmp]) * localB->PHI_k_Dot_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProc_binary_expand_op_ce(localB->cosinus_E_k_data, localB->cosinus_E_k_size, Ephemeris_C_us_data,
            Ephemeris_C_us_size, localB->cos2PHI_k_data, localB->cos2PHI_k_size, Ephemeris_C_uc_data,
            Ephemeris_C_uc_size, localB->sin2PHI_k_data, localB->sin2PHI_k_size, localB->PHI_k_Dot_data,
            localB->PHI_k_Dot_size);
    }

    localB->vectorUB = localB->scalarLB_tmp - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
        _mm_storeu_pd(&localB->tmp_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
    }

    localB->vectorUB = localB->scalarLB_tmp - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
        _mm_storeu_pd(&localB->tmp_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
    }

    localB->vectorUB = localB->scalarLB_tmp - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
        _mm_storeu_pd(&localB->y_tmp_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
    }

    localB->vectorUB = localB->scalarLB_tmp - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
        _mm_storeu_pd(&localB->tmp_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
    }

    if ((Ephemeris_C_rs_size[1] == localB->cos2PHI_k_size[1]) && (Ephemeris_C_rc_size[1] == localB->sin2PHI_k_size[1]) &&
        ((Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] : Ephemeris_C_rs_size[1]) == (Ephemeris_C_rc_size[1] ==
          1 ? localB->sin2PHI_k_size[1] : Ephemeris_C_rc_size[1])) && (((Ephemeris_C_rs_size[1] == 1 ?
            localB->cos2PHI_k_size[1] : Ephemeris_C_rs_size[1]) == 1 ? Ephemeris_C_rc_size[1] == 1 ?
            localB->sin2PHI_k_size[1] : Ephemeris_C_rc_size[1] : Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1]
          : Ephemeris_C_rs_size[1]) == localB->PHI_k_Dot_size[1]) && (Ephemeris_SQRT_A_size[1] == Ephemeris_E_size[1]) &&
        ((Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1]) == localB->sinus_E_k_size[1]) &&
        (((Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1]) == 1 ? localB->
            sinus_E_k_size[1] : Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1]) ==
            localB->E_k_Dot_size[1]) && ((((Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] :
            Ephemeris_C_rs_size[1]) == 1 ? Ephemeris_C_rc_size[1] == 1 ? localB->sin2PHI_k_size[1] :
            Ephemeris_C_rc_size[1] : Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] : Ephemeris_C_rs_size[1]) ==
          1 ? localB->PHI_k_Dot_size[1] : (Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] :
            Ephemeris_C_rs_size[1]) == 1 ? Ephemeris_C_rc_size[1] == 1 ? localB->sin2PHI_k_size[1] :
            Ephemeris_C_rc_size[1] : Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] : Ephemeris_C_rs_size[1]) ==
         (((Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1]) == 1 ?
            localB->sinus_E_k_size[1] : Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1]) ==
          1 ? localB->E_k_Dot_size[1] : (Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1])
          == 1 ? localB->sinus_E_k_size[1] : Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] :
            Ephemeris_SQRT_A_size[1])))
    {
        localB->r_k_Dot_size[0] = 1;
        localB->r_k_Dot_size[1] = Ephemeris_C_rs_size[1];
        localB->loop_ub_c = Ephemeris_C_rs_size[1];
        localB->scalarLB_f = (Ephemeris_C_rs_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp]);
            tmp_3 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
            tmp_1 = _mm_loadu_pd(&localB->sinus_E_k_data[localB->t_k_data_tmp]);
            tmp_2 = _mm_loadu_pd(&localB->E_k_Dot_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->r_k_Dot_data[localB->t_k_data_tmp], _mm_add_pd(_mm_mul_pd(_mm_mul_pd(_mm_sub_pd
                             (_mm_mul_pd(_mm_loadu_pd(&Ephemeris_C_rs_data[localB->t_k_data_tmp]), tmp_6), _mm_mul_pd
                              (_mm_loadu_pd(&Ephemeris_C_rc_data[localB->t_k_data_tmp]), tmp_4)), _mm_set1_pd(2.0)),
                            tmp_5), _mm_mul_pd(_mm_mul_pd(_mm_mul_pd(_mm_mul_pd(tmp_3, tmp_3), _mm_loadu_pd
                              (&Ephemeris_E_data[localB->t_k_data_tmp])), tmp_1), tmp_2)));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->N = Ephemeris_SQRT_A_data[localB->t_k_data_tmp];
            localB->r_k_Dot_data[localB->t_k_data_tmp] = (Ephemeris_C_rs_data[localB->t_k_data_tmp] *
                localB->cos2PHI_k_data[localB->t_k_data_tmp] - Ephemeris_C_rc_data[localB->t_k_data_tmp] *
                localB->sin2PHI_k_data[localB->t_k_data_tmp]) * 2.0 * localB->PHI_k_Dot_data[localB->t_k_data_tmp] +
                localB->N * localB->N * Ephemeris_E_data[localB->t_k_data_tmp] * localB->sinus_E_k_data
                [localB->t_k_data_tmp] * localB->E_k_Dot_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProce_binary_expand_op_d(localB->r_k_Dot_data, localB->r_k_Dot_size, Ephemeris_C_rs_data,
            Ephemeris_C_rs_size, localB->cos2PHI_k_data, localB->cos2PHI_k_size, Ephemeris_C_rc_data,
            Ephemeris_C_rc_size, localB->sin2PHI_k_data, localB->sin2PHI_k_size, localB->PHI_k_Dot_data,
            localB->PHI_k_Dot_size, Ephemeris_SQRT_A_data, Ephemeris_SQRT_A_size, Ephemeris_E_data, Ephemeris_E_size,
            localB->sinus_E_k_data, localB->sinus_E_k_size, localB->E_k_Dot_data, localB->E_k_Dot_size, localB);
    }

    if ((Ephemeris_C_is_size[1] == localB->cos2PHI_k_size[1]) && (Ephemeris_C_ic_size[1] == localB->sin2PHI_k_size[1]) &&
        ((Ephemeris_C_is_size[1] == 1 ? localB->cos2PHI_k_size[1] : Ephemeris_C_is_size[1]) == (Ephemeris_C_ic_size[1] ==
          1 ? localB->sin2PHI_k_size[1] : Ephemeris_C_ic_size[1])) && (((Ephemeris_C_is_size[1] == 1 ?
            localB->cos2PHI_k_size[1] : Ephemeris_C_is_size[1]) == 1 ? Ephemeris_C_ic_size[1] == 1 ?
            localB->sin2PHI_k_size[1] : Ephemeris_C_ic_size[1] : Ephemeris_C_is_size[1] == 1 ? localB->cos2PHI_k_size[1]
          : Ephemeris_C_is_size[1]) == localB->PHI_k_Dot_size[1]) && ((((Ephemeris_C_is_size[1] == 1 ?
            localB->cos2PHI_k_size[1] : Ephemeris_C_is_size[1]) == 1 ? Ephemeris_C_ic_size[1] == 1 ?
            localB->sin2PHI_k_size[1] : Ephemeris_C_ic_size[1] : Ephemeris_C_is_size[1] == 1 ? localB->cos2PHI_k_size[1]
           : Ephemeris_C_is_size[1]) == 1 ? localB->PHI_k_Dot_size[1] : (Ephemeris_C_is_size[1] == 1 ?
            localB->cos2PHI_k_size[1] : Ephemeris_C_is_size[1]) == 1 ? Ephemeris_C_ic_size[1] == 1 ?
            localB->sin2PHI_k_size[1] : Ephemeris_C_ic_size[1] : Ephemeris_C_is_size[1] == 1 ? localB->cos2PHI_k_size[1]
          : Ephemeris_C_is_size[1]) == Ephemeris_IDOT_size[1]))
    {
        localB->loop_ub_c = Ephemeris_C_is_size[1] - 1;
        localB->cos2PHI_k_size[0] = 1;
        localB->cos2PHI_k_size[1] = Ephemeris_C_is_size[1];
        localB->scalarLB_f = (Ephemeris_C_is_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp], _mm_add_pd(_mm_mul_pd(_mm_mul_pd(_mm_sub_pd
                             (_mm_mul_pd(_mm_loadu_pd(&Ephemeris_C_is_data[localB->t_k_data_tmp]), tmp_6), _mm_mul_pd
                              (_mm_loadu_pd(&Ephemeris_C_ic_data[localB->t_k_data_tmp]), tmp_4)), _mm_set1_pd(2.0)),
                            tmp_5), _mm_loadu_pd(&Ephemeris_IDOT_data[localB->t_k_data_tmp])));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp <= localB->loop_ub_c; localB->t_k_data_tmp
                ++)
        {
            localB->cos2PHI_k_data[localB->t_k_data_tmp] = (Ephemeris_C_is_data[localB->t_k_data_tmp] *
                localB->cos2PHI_k_data[localB->t_k_data_tmp] - Ephemeris_C_ic_data[localB->t_k_data_tmp] *
                localB->sin2PHI_k_data[localB->t_k_data_tmp]) * 2.0 * localB->PHI_k_Dot_data[localB->t_k_data_tmp] +
                Ephemeris_IDOT_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProce_binary_expand_op_g(localB->cos2PHI_k_data, localB->cos2PHI_k_size, Ephemeris_C_is_data,
            Ephemeris_C_is_size, Ephemeris_C_ic_data, Ephemeris_C_ic_size, localB->sin2PHI_k_data,
            localB->sin2PHI_k_size, localB->PHI_k_Dot_data, localB->PHI_k_Dot_size, Ephemeris_IDOT_data,
            Ephemeris_IDOT_size, localB);
    }

    if ((localB->r_k_Dot_size[1] == localB->cosinus_u_k_size[1]) && (localB->r_k_size[1] == localB->cosinus_E_k_size[1])
        && ((localB->r_k_Dot_size[1] == 1 ? localB->cosinus_u_k_size[1] : localB->r_k_Dot_size[1]) == (localB->r_k_size
            [1] == 1 ? localB->cosinus_E_k_size[1] : localB->r_k_size[1])))
    {
        localB->loop_ub_c = localB->r_k_Dot_size[1] - 1;
        localB->cosinus_u_k_size[0] = 1;
        localB->cosinus_u_k_size[1] = localB->r_k_Dot_size[1];
        localB->scalarLB_f = (localB->r_k_Dot_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->r_k_Dot_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->cosinus_u_k_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
            tmp_3 = _mm_loadu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->cosinus_u_k_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_mul_pd(tmp_6, tmp_4),
                           _mm_mul_pd(tmp_5, tmp_3)));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp <= localB->loop_ub_c; localB->t_k_data_tmp
                ++)
        {
            localB->cosinus_u_k_data[localB->t_k_data_tmp] = localB->r_k_Dot_data[localB->t_k_data_tmp] *
                localB->cosinus_u_k_data[localB->t_k_data_tmp] - localB->r_k_data[localB->t_k_data_tmp] *
                localB->cosinus_E_k_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        binary_expand_o_evirnrbrctmpazf(localB->cosinus_u_k_data, localB->cosinus_u_k_size, localB->r_k_Dot_data,
            localB->r_k_Dot_size, localB->r_k_data, localB->r_k_size, localB->cosinus_E_k_data, localB->cosinus_E_k_size,
            localB);
    }

    if ((localB->r_k_Dot_size[1] == localB->PHI_k_size[1]) && (localB->X_k_tmp_size[1] == localB->cosinus_E_k_size[1]) &&
        ((localB->r_k_Dot_size[1] == 1 ? localB->PHI_k_size[1] : localB->r_k_Dot_size[1]) == (localB->X_k_tmp_size[1] ==
          1 ? localB->cosinus_E_k_size[1] : localB->X_k_tmp_size[1])))
    {
        localB->loop_ub_c = localB->r_k_Dot_size[1] - 1;
        localB->r_k_Dot_size[0] = 1;
        localB->scalarLB_f = (localB->r_k_Dot_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->r_k_Dot_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->PHI_k_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->X_k_tmp_data[localB->t_k_data_tmp]);
            tmp_3 = _mm_loadu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->r_k_Dot_data[localB->t_k_data_tmp], _mm_add_pd(_mm_mul_pd(tmp_6, tmp_4), _mm_mul_pd
                           (tmp_5, tmp_3)));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp <= localB->loop_ub_c; localB->t_k_data_tmp
                ++)
        {
            localB->r_k_Dot_data[localB->t_k_data_tmp] = localB->r_k_Dot_data[localB->t_k_data_tmp] * localB->
                PHI_k_data[localB->t_k_data_tmp] + localB->X_k_tmp_data[localB->t_k_data_tmp] * localB->
                cosinus_E_k_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        binary_expand_op_evirnrbrctmpaz(localB->r_k_Dot_data, localB->r_k_Dot_size, localB->PHI_k_data,
            localB->PHI_k_size, localB->X_k_tmp_data, localB->X_k_tmp_size, localB->cosinus_E_k_data,
            localB->cosinus_E_k_size, localB);
    }

    sv_vel_size[0] = localB->cosinus_u_k_size[1];
    sv_vel_size[1] = 3;
    localB->loop_ub_c = localB->cosinus_u_k_size[1] * 3;
    if (localB->loop_ub_c - 1 >= 0)
    {
        std::memset(&sv_vel_data[0], 0, static_cast<uint32_T>(localB->loop_ub_c) * sizeof(real_T));
    }

    if (localB->r_k_Dot_size[1] == localB->cosinus_i_k_size[1])
    {
        localB->loop_ub_c = localB->r_k_Dot_size[1] - 1;
        localB->cosinus_i_k_size[0] = 1;
        localB->cosinus_i_k_size[1] = localB->r_k_Dot_size[1];
        localB->scalarLB_f = (localB->r_k_Dot_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->r_k_Dot_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->cosinus_i_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&localB->cosinus_i_k_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_4));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp <= localB->loop_ub_c; localB->t_k_data_tmp
                ++)
        {
            localB->cosinus_i_k_data[localB->t_k_data_tmp] *= localB->r_k_Dot_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GNSSPreProcessingDualAn_times_c(localB->cosinus_i_k_data, localB->cosinus_i_k_size, localB->r_k_Dot_data,
            localB->r_k_Dot_size, localB);
    }

    if ((localB->cosinus_u_k_size[1] == localB->t_k_size_g[1]) && (localB->cosinus_i_k_size[1] ==
            localB->sinus_lambda_k_size[1]) && ((localB->cosinus_u_k_size[1] == 1 ? localB->t_k_size_g[1] :
            localB->cosinus_u_k_size[1]) == (localB->cosinus_i_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
            localB->cosinus_i_k_size[1])) && (localB->d_size[1] == localB->sinus_lambda_k_size[1]) && ((localB->d_size[1]
          == 1 ? localB->sinus_lambda_k_size[1] : localB->d_size[1]) == localB->cos2PHI_k_size[1]) &&
            (((localB->cosinus_u_k_size[1] == 1 ? localB->t_k_size_g[1] : localB->cosinus_u_k_size[1]) == 1 ?
              localB->cosinus_i_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] : localB->cosinus_i_k_size[1] :
              localB->cosinus_u_k_size[1] == 1 ? localB->t_k_size_g[1] : localB->cosinus_u_k_size[1]) ==
             ((localB->d_size[1] == 1 ? localB->sinus_lambda_k_size[1] : localB->d_size[1]) == 1 ?
              localB->cos2PHI_k_size[1] : localB->d_size[1] == 1 ? localB->sinus_lambda_k_size[1] : localB->d_size[1])) &&
        (sv_pos_size[0] == Ephemeris_OMEGADOT_size[1]) && ((((localB->cosinus_u_k_size[1] == 1 ? localB->t_k_size_g[1] :
            localB->cosinus_u_k_size[1]) == 1 ? localB->cosinus_i_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
            localB->cosinus_i_k_size[1] : localB->cosinus_u_k_size[1] == 1 ? localB->t_k_size_g[1] :
            localB->cosinus_u_k_size[1]) == 1 ? (localB->d_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
            localB->d_size[1]) == 1 ? localB->cos2PHI_k_size[1] : localB->d_size[1] == 1 ? localB->sinus_lambda_k_size[1]
          : localB->d_size[1] : (localB->cosinus_u_k_size[1] == 1 ? localB->t_k_size_g[1] : localB->cosinus_u_k_size[1])
          == 1 ? localB->cosinus_i_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] : localB->cosinus_i_k_size[1] :
            localB->cosinus_u_k_size[1] == 1 ? localB->t_k_size_g[1] : localB->cosinus_u_k_size[1]) == (sv_pos_size[0] ==
          1 ? Ephemeris_OMEGADOT_size[1] : sv_pos_size[0])))
    {
        localB->loop_ub_c = localB->cosinus_u_k_size[1];
        localB->scalarLB_f = (localB->cosinus_u_k_size[1] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->cosinus_u_k_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->t_k_data_l[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->cosinus_i_k_data[localB->t_k_data_tmp]);
            tmp_3 = _mm_loadu_pd(&localB->sinus_lambda_k_data[localB->t_k_data_tmp]);
            tmp_1 = _mm_loadu_pd(&localB->d_data[localB->t_k_data_tmp]);
            tmp_2 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
            tmp = _mm_loadu_pd(&sv_pos_data[localB->t_k_data_tmp + sv_pos_size[0]]);
            tmp_0 = _mm_loadu_pd(&localB->f_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&sv_vel_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_add_pd(_mm_sub_pd(_mm_mul_pd(tmp_6, tmp_4),
                             _mm_mul_pd(tmp_5, tmp_3)), _mm_mul_pd(_mm_mul_pd(tmp_1, tmp_3), tmp_2)), _mm_mul_pd(tmp,
                            tmp_0)));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->sinus_lambda_k = localB->sinus_lambda_k_data[localB->t_k_data_tmp];
            sv_vel_data[localB->t_k_data_tmp] = ((localB->cosinus_u_k_data[localB->t_k_data_tmp] * localB->
                t_k_data_l[localB->t_k_data_tmp] - localB->cosinus_i_k_data[localB->t_k_data_tmp] *
                localB->sinus_lambda_k) + localB->d_data[localB->t_k_data_tmp] * localB->sinus_lambda_k *
                localB->cos2PHI_k_data[localB->t_k_data_tmp]) - sv_pos_data[localB->t_k_data_tmp + sv_pos_size[0]] *
                localB->f_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        binary_expand_op_evirnrbrctmpa(sv_vel_data, localB->cosinus_u_k_data, localB->cosinus_u_k_size,
            localB->t_k_data_l, localB->t_k_size_g, localB->cosinus_i_k_data, localB->cosinus_i_k_size,
            localB->sinus_lambda_k_data, localB->sinus_lambda_k_size, localB->d_data, localB->d_size,
            localB->cos2PHI_k_data, localB->cos2PHI_k_size, sv_pos_data, sv_pos_size, localB->f_data, localB->f_size,
            localB);
    }

    if ((localB->cosinus_u_k_size[1] == localB->sinus_lambda_k_size[1]) && (localB->cosinus_i_k_size[1] ==
            localB->t_k_size_g[1]) && ((localB->cosinus_u_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
            localB->cosinus_u_k_size[1]) == (localB->cosinus_i_k_size[1] == 1 ? localB->t_k_size_g[1] :
            localB->cosinus_i_k_size[1])) && (localB->d_size[1] == localB->t_k_size_g[1]) && ((localB->d_size[1] == 1 ?
            localB->t_k_size_g[1] : localB->d_size[1]) == localB->cos2PHI_k_size[1]) && (((localB->cosinus_u_k_size[1] ==
           1 ? localB->sinus_lambda_k_size[1] : localB->cosinus_u_k_size[1]) == 1 ? localB->cosinus_i_k_size[1] == 1 ?
            localB->t_k_size_g[1] : localB->cosinus_i_k_size[1] : localB->cosinus_u_k_size[1] == 1 ?
            localB->sinus_lambda_k_size[1] : localB->cosinus_u_k_size[1]) == ((localB->d_size[1] == 1 ?
            localB->t_k_size_g[1] : localB->d_size[1]) == 1 ? localB->cos2PHI_k_size[1] : localB->d_size[1] == 1 ?
            localB->t_k_size_g[1] : localB->d_size[1])) && (sv_pos_size[0] == Ephemeris_OMEGADOT_size[1]) &&
            ((((localB->cosinus_u_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] : localB->cosinus_u_k_size[1]) == 1 ?
               localB->cosinus_i_k_size[1] == 1 ? localB->t_k_size_g[1] : localB->cosinus_i_k_size[1] :
               localB->cosinus_u_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] : localB->cosinus_u_k_size[1]) == 1 ?
              (localB->d_size[1] == 1 ? localB->t_k_size_g[1] : localB->d_size[1]) == 1 ? localB->cos2PHI_k_size[1] :
              localB->d_size[1] == 1 ? localB->t_k_size_g[1] : localB->d_size[1] : (localB->cosinus_u_k_size[1] == 1 ?
            localB->sinus_lambda_k_size[1] : localB->cosinus_u_k_size[1]) == 1 ? localB->cosinus_i_k_size[1] == 1 ?
              localB->t_k_size_g[1] : localB->cosinus_i_k_size[1] : localB->cosinus_u_k_size[1] == 1 ?
              localB->sinus_lambda_k_size[1] : localB->cosinus_u_k_size[1]) == (sv_pos_size[0] == 1 ?
            Ephemeris_OMEGADOT_size[1] : sv_pos_size[0])))
    {
        localB->loop_ub_c = sv_vel_size[0];
        localB->scalarLB_f = (sv_vel_size[0] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->cosinus_u_k_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->sinus_lambda_k_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->cosinus_i_k_data[localB->t_k_data_tmp]);
            tmp_3 = _mm_loadu_pd(&localB->t_k_data_l[localB->t_k_data_tmp]);
            tmp_1 = _mm_loadu_pd(&localB->d_data[localB->t_k_data_tmp]);
            tmp_2 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
            tmp = _mm_loadu_pd(&sv_pos_data[localB->t_k_data_tmp]);
            tmp_0 = _mm_loadu_pd(&localB->f_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&sv_vel_data[localB->t_k_data_tmp + sv_vel_size[0]], _mm_add_pd(_mm_sub_pd(_mm_add_pd
                            (_mm_mul_pd(tmp_6, tmp_4), _mm_mul_pd(tmp_5, tmp_3)), _mm_mul_pd(_mm_mul_pd(tmp_1, tmp_3),
                             tmp_2)), _mm_mul_pd(tmp, tmp_0)));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            localB->sinus_lambda_k = localB->t_k_data_l[localB->t_k_data_tmp];
            sv_vel_data[localB->t_k_data_tmp + sv_vel_size[0]] = ((localB->cosinus_u_k_data[localB->t_k_data_tmp] *
                localB->sinus_lambda_k_data[localB->t_k_data_tmp] + localB->cosinus_i_k_data[localB->t_k_data_tmp] *
                localB->sinus_lambda_k) - localB->d_data[localB->t_k_data_tmp] * localB->sinus_lambda_k *
                localB->cos2PHI_k_data[localB->t_k_data_tmp]) + sv_pos_data[localB->t_k_data_tmp] * localB->
                f_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        G_binary_expand_op_evirnrbrctmp(sv_vel_data, sv_vel_size, localB->cosinus_u_k_data, localB->cosinus_u_k_size,
            localB->sinus_lambda_k_data, localB->sinus_lambda_k_size, localB->cosinus_i_k_data, localB->cosinus_i_k_size,
            localB->t_k_data_l, localB->t_k_size_g, localB->d_data, localB->d_size, localB->cos2PHI_k_data,
            localB->cos2PHI_k_size, sv_pos_data, sv_pos_size, localB->f_data, localB->f_size, localB);
    }

    if ((localB->r_k_Dot_size[1] == localB->i_k_size[1]) && (localB->c_size[1] == localB->cos2PHI_k_size[1]) &&
            ((localB->r_k_Dot_size[1] == 1 ? localB->i_k_size[1] : localB->r_k_Dot_size[1]) == (localB->c_size[1] == 1 ?
          localB->cos2PHI_k_size[1] : localB->c_size[1])))
    {
        localB->loop_ub_c = sv_vel_size[0];
        localB->scalarLB_f = (sv_vel_size[0] / 2) << 1;
        localB->vectorUB = localB->scalarLB_f - 2;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->r_k_Dot_data[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->i_k_data[localB->t_k_data_tmp]);
            tmp_5 = _mm_loadu_pd(&localB->c_data[localB->t_k_data_tmp]);
            tmp_3 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
            _mm_storeu_pd(&sv_vel_data[localB->t_k_data_tmp + (sv_vel_size[0] << 1)], _mm_add_pd(_mm_mul_pd(tmp_6, tmp_4),
                           _mm_mul_pd(tmp_5, tmp_3)));
        }

        for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
        {
            sv_vel_data[localB->t_k_data_tmp + (sv_vel_size[0] << 1)] = localB->r_k_Dot_data[localB->t_k_data_tmp] *
                localB->i_k_data[localB->t_k_data_tmp] + localB->c_data[localB->t_k_data_tmp] * localB->
                cos2PHI_k_data[localB->t_k_data_tmp];
        }
    }
    else
    {
        GN_binary_expand_op_evirnrbrctm(sv_vel_data, sv_vel_size, localB->r_k_Dot_data, localB->r_k_Dot_size,
            localB->i_k_data, localB->i_k_size, localB->c_data, localB->c_size, localB->cos2PHI_k_data,
            localB->cos2PHI_k_size);
    }

    localB->sinus_lambda_k = std::cos(user_position[0]);
    localB->N = 6.3995936257584924E+6 / std::sqrt(localB->sinus_lambda_k * localB->sinus_lambda_k *
        0.0067394967422761756 + 1.0);
    localB->sinus_lambda_k = (localB->N + user_position[2]) * localB->sinus_lambda_k * std::cos(user_position[1]);
    localB->y_user = (localB->N + user_position[2]) * std::cos(user_position[0]) * std::sin(user_position[1]);
    localB->z_user = (0.99330562000985889 * localB->N + user_position[2]) * std::sin(user_position[0]);
    localB->scalarLB_tmp = (sv_pos_size[0] / 2) << 1;
    localB->vectorUB = localB->scalarLB_tmp - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&sv_pos_data[localB->t_k_data_tmp]);
        tmp_6 = _mm_sub_pd(tmp_6, _mm_set1_pd(localB->sinus_lambda_k));
        _mm_storeu_pd(&localB->tmp_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
    }

    localB->vectorUB = localB->scalarLB_tmp - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&sv_pos_data[(sv_pos_size[0] << 1) + localB->t_k_data_tmp]);
        tmp_6 = _mm_sub_pd(tmp_6, _mm_set1_pd(localB->z_user));
        _mm_storeu_pd(&localB->tmp_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
    }

    localB->transport_angle_size = sv_pos_size[0];
    localB->loop_ub_c = sv_pos_size[0];
    localB->vectorUB = localB->scalarLB_tmp - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&sv_pos_data[localB->t_k_data_tmp]);
        tmp_6 = _mm_sub_pd(tmp_6, _mm_set1_pd(localB->sinus_lambda_k));
        tmp_4 = _mm_loadu_pd(&sv_pos_data[localB->t_k_data_tmp + sv_pos_size[0]]);
        tmp_4 = _mm_sub_pd(tmp_4, _mm_set1_pd(localB->y_user));
        tmp_5 = _mm_loadu_pd(&sv_pos_data[(sv_pos_size[0] << 1) + localB->t_k_data_tmp]);
        tmp_5 = _mm_sub_pd(tmp_5, _mm_set1_pd(localB->z_user));
        _mm_storeu_pd(&localB->t_k_data_l[localB->t_k_data_tmp], _mm_add_pd(_mm_add_pd(_mm_mul_pd(tmp_6, tmp_6),
                        _mm_mul_pd(tmp_4, tmp_4)), _mm_mul_pd(tmp_5, tmp_5)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB_tmp; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
    {
        localB->N = sv_pos_data[localB->t_k_data_tmp] - localB->sinus_lambda_k;
        localB->varargin_1 = sv_pos_data[localB->t_k_data_tmp + sv_pos_size[0]] - localB->y_user;
        localB->varargin_1_n = sv_pos_data[(sv_pos_size[0] << 1) + localB->t_k_data_tmp] - localB->z_user;
        localB->t_k_data_l[localB->t_k_data_tmp] = (localB->N * localB->N + localB->varargin_1 * localB->varargin_1) +
            localB->varargin_1_n * localB->varargin_1_n;
    }

    GNSSPreProcessingDualAn_sqrt_fe(localB->t_k_data_l, &localB->transport_angle_size, localB);
    localB->loop_ub_c = localB->transport_angle_size;
    localB->scalarLB_f = (localB->transport_angle_size / 2) << 1;
    localB->vectorUB = localB->scalarLB_f - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB; localB->t_k_data_tmp += 2)
    {
        tmp_6 = _mm_loadu_pd(&localB->t_k_data_l[localB->t_k_data_tmp]);
        _mm_storeu_pd(&localB->t_k_data_l[localB->t_k_data_tmp], _mm_mul_pd(_mm_div_pd(tmp_6, _mm_set1_pd(2.99792458E+8)),
                       _mm_set1_pd(-7.2921151467E-5)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB_f; localB->t_k_data_tmp < localB->loop_ub_c; localB->t_k_data_tmp++)
    {
        localB->t_k_data_l[localB->t_k_data_tmp] = localB->t_k_data_l[localB->t_k_data_tmp] / 2.99792458E+8 *
            -7.2921151467E-5;
    }

    localB->scalarLB_f = sv_pos_size[0];
    if (sv_pos_size[0] - 1 >= 0)
    {
        localB->sv_pos_tmp[6] = 0.0;
        localB->sv_pos_tmp[7] = 0.0;
        localB->sv_pos_tmp[2] = 0.0;
        localB->sv_pos_tmp[5] = 0.0;
        localB->sv_pos_tmp[8] = 1.0;
        localB->dv[6] = 0.0;
        localB->dv[7] = 0.0;
        localB->dv[2] = 0.0;
        localB->dv[5] = 0.0;
        localB->dv[8] = 1.0;
    }

    for (localB->vectorUB = 0; localB->vectorUB < localB->scalarLB_f; localB->vectorUB++)
    {
        localB->sinus_lambda_k = localB->t_k_data_l[localB->vectorUB];
        localB->y_user = std::sin(-localB->sinus_lambda_k);
        localB->N = std::cos(-localB->sinus_lambda_k);
        localB->sv_pos_tmp[0] = localB->N;
        localB->sv_pos_tmp[3] = localB->y_user;
        localB->sv_pos_tmp[1] = -localB->y_user;
        localB->sv_pos_tmp[4] = localB->N;
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= 0; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->sv_pos_tmp[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->sv_pos_tmp[localB->t_k_data_tmp + 3]);
            tmp_5 = _mm_loadu_pd(&localB->sv_pos_tmp[localB->t_k_data_tmp + 6]);
            _mm_storeu_pd(&localB->sv_pos_tmp_o[localB->t_k_data_tmp], _mm_add_pd(_mm_mul_pd(tmp_5, _mm_set1_pd
                            (sv_pos_data[localB->vectorUB + (sv_pos_size[0] << 1)])), _mm_add_pd(_mm_mul_pd(tmp_4,
                             _mm_set1_pd(sv_pos_data[localB->vectorUB + sv_pos_size[0]])), _mm_add_pd(_mm_mul_pd(tmp_6,
                              _mm_set1_pd(sv_pos_data[localB->vectorUB])), _mm_set1_pd(0.0)))));
        }

        for (localB->t_k_data_tmp = 2; localB->t_k_data_tmp < 3; localB->t_k_data_tmp++)
        {
            localB->sv_pos_tmp_o[localB->t_k_data_tmp] = sv_pos_data[(sv_pos_size[0] << 1) + localB->vectorUB] *
                localB->sv_pos_tmp[localB->t_k_data_tmp + 6] + (localB->sv_pos_tmp[localB->t_k_data_tmp + 3] *
                sv_pos_data[localB->vectorUB + sv_pos_size[0]] + localB->sv_pos_tmp[localB->t_k_data_tmp] *
                sv_pos_data[localB->vectorUB]);
        }

        localB->dv[0] = localB->N;
        localB->dv[3] = localB->y_user;
        localB->dv[1] = -std::sin(-localB->sinus_lambda_k);
        localB->dv[4] = localB->N;
        sv_pos_data[localB->vectorUB] = localB->sv_pos_tmp_o[0];
        sv_pos_data[localB->vectorUB + sv_pos_size[0]] = localB->sv_pos_tmp_o[1];
        sv_pos_data[localB->vectorUB + (sv_pos_size[0] << 1)] = localB->sv_pos_tmp_o[2];
        for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= 0; localB->t_k_data_tmp += 2)
        {
            tmp_6 = _mm_loadu_pd(&localB->dv[localB->t_k_data_tmp]);
            tmp_4 = _mm_loadu_pd(&localB->dv[localB->t_k_data_tmp + 3]);
            tmp_5 = _mm_loadu_pd(&localB->dv[localB->t_k_data_tmp + 6]);
            _mm_storeu_pd(&localB->sv_pos_tmp_o[localB->t_k_data_tmp], _mm_add_pd(_mm_mul_pd(tmp_5, _mm_set1_pd
                            (sv_vel_data[localB->vectorUB + (sv_vel_size[0] << 1)])), _mm_add_pd(_mm_mul_pd(tmp_4,
                             _mm_set1_pd(sv_vel_data[localB->vectorUB + sv_vel_size[0]])), _mm_add_pd(_mm_mul_pd(tmp_6,
                              _mm_set1_pd(sv_vel_data[localB->vectorUB])), _mm_set1_pd(0.0)))));
        }

        for (localB->t_k_data_tmp = 2; localB->t_k_data_tmp < 3; localB->t_k_data_tmp++)
        {
            localB->sv_pos_tmp_o[localB->t_k_data_tmp] = sv_vel_data[(sv_vel_size[0] << 1) + localB->vectorUB] *
                localB->dv[localB->t_k_data_tmp + 6] + (localB->dv[localB->t_k_data_tmp + 3] * sv_vel_data
                [localB->vectorUB + sv_vel_size[0]] + localB->dv[localB->t_k_data_tmp] * sv_vel_data[localB->vectorUB]);
        }

        sv_vel_data[localB->vectorUB] = localB->sv_pos_tmp_o[0];
        sv_vel_data[localB->vectorUB + sv_vel_size[0]] = localB->sv_pos_tmp_o[1];
        sv_vel_data[localB->vectorUB + (sv_vel_size[0] << 1)] = localB->sv_pos_tmp_o[2];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPrePr_binary_expand_op_evir(const gnssops_navigation_data *in1, const real_T
    in3_data[], const int32_T *in3_size, const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[],
    const int32_T in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const real_T in7_data[], const
    int32_T in7_size[2], const real_T in8_data[], const int32_T in8_size[2], const real_T in9_data[], const int32_T
    in9_size[2], const real_T in10_data[], const int32_T in10_size[2], const real_T in11[3], real_T in12_data[], int32_T
    in12_size[2], real_T in13_data[], int32_T in13_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    localB->in1_size[0] = 1;
    localB->in1_size[1] = *in3_size;
    localB->loop_ub = *in3_size;
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in1_data_c[localB->i_m] = in1->C_rs[static_cast<int32_T>(in3_data[localB->i_m]) - 1];
    }

    localB->in1_size_a[0] = 1;
    localB->in1_size_a[1] = *in3_size;
    localB->loop_ub = *in3_size;
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in1_data_f[localB->i_m] = in1->C_uc[static_cast<int32_T>(in3_data[localB->i_m]) - 1];
    }

    localB->in1_size_as[0] = 1;
    localB->in1_size_as[1] = *in3_size;
    localB->loop_ub = *in3_size;
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in1_data_g[localB->i_m] = in1->C_us[static_cast<int32_T>(in3_data[localB->i_m]) - 1];
    }

    localB->in1_size_i[0] = 1;
    localB->in1_size_i[1] = *in3_size;
    localB->loop_ub = *in3_size;
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in1_data_g1[localB->i_m] = in1->C_ic[static_cast<int32_T>(in3_data[localB->i_m]) - 1];
    }

    localB->in1_size_l[0] = 1;
    localB->in1_size_l[1] = *in3_size;
    localB->loop_ub = *in3_size;
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in1_data_m[localB->i_m] = in1->OMEGA_0[static_cast<int32_T>(in3_data[localB->i_m]) - 1];
    }

    localB->in1_size_o[0] = 1;
    localB->in1_size_o[1] = *in3_size;
    localB->loop_ub = *in3_size;
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in1_data_n[localB->i_m] = in1->C_is[static_cast<int32_T>(in3_data[localB->i_m]) - 1];
    }

    localB->in1_size_o2[0] = 1;
    localB->in1_size_o2[1] = *in3_size;
    localB->loop_ub = *in3_size;
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in1_data_p[localB->i_m] = in1->I_0[static_cast<int32_T>(in3_data[localB->i_m]) - 1];
    }

    localB->in1_size_ip[0] = 1;
    localB->in1_size_ip[1] = *in3_size;
    localB->loop_ub = *in3_size;
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in1_data_l[localB->i_m] = in1->C_rc[static_cast<int32_T>(in3_data[localB->i_m]) - 1];
    }

    localB->in1_size_f[0] = 1;
    localB->in1_size_f[1] = *in3_size;
    localB->loop_ub = *in3_size;
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in1_data_j[localB->i_m] = in1->omega[static_cast<int32_T>(in3_data[localB->i_m]) - 1];
    }

    localB->in1_size_iz[0] = 1;
    localB->in1_size_iz[1] = *in3_size;
    localB->loop_ub = *in3_size;
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in1_data_d[localB->i_m] = in1->OMEGADOT[static_cast<int32_T>(in3_data[localB->i_m]) - 1];
    }

    localB->in1_size_ff[0] = 1;
    localB->in1_size_ff[1] = *in3_size;
    localB->loop_ub = *in3_size;
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in1_data_gu[localB->i_m] = in1->IDOT[static_cast<int32_T>(in3_data[localB->i_m]) - 1];
    }

    localB->in9_size[0] = 1;
    localB->in9_size[1] = in10_size[1] == 1 ? in9_size[1] : in10_size[1];
    localB->stride_0_1 = (in9_size[1] != 1);
    localB->stride_1_1 = (in10_size[1] != 1);
    localB->loop_ub = in10_size[1] == 1 ? in9_size[1] : in10_size[1];
    for (localB->i_m = 0; localB->i_m < localB->loop_ub; localB->i_m++)
    {
        localB->in9_data[localB->i_m] = in9_data[localB->i_m * localB->stride_0_1] - in10_data[localB->i_m *
            localB->stride_1_1];
    }

    Get_Kepler_Satellite_Position_b(localB->in1_data_c, localB->in1_size, in4_data, in4_size, in5_data, in5_size,
        localB->in1_data_f, localB->in1_size_a, in6_data, in6_size, localB->in1_data_g, localB->in1_size_as, in7_data,
        in7_size, in8_data, in8_size, localB->in1_data_g1, localB->in1_size_i, localB->in1_data_m, localB->in1_size_l,
        localB->in1_data_n, localB->in1_size_o, localB->in1_data_p, localB->in1_size_o2, localB->in1_data_l,
        localB->in1_size_ip, localB->in1_data_j, localB->in1_size_f, localB->in1_data_d, localB->in1_size_iz,
        localB->in1_data_gu, localB->in1_size_ff, localB->in9_data, localB->in9_size, in11, in12_data, in12_size,
        in13_data, in13_size, localB);
}

void GNSSPreProcessingDualAntenna::GNSSPrePro_binary_expand_op_evi(real_T in1_data[], int32_T *in1_size, const real_T
    in2_data[], const int32_T in3_data[], const int32_T *in3_size, const real_T in4_data[], const int32_T *in4_size)
{
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    *in1_size = *in4_size == 1 ? *in3_size : *in4_size;
    stride_0_0 = (*in3_size != 1);
    stride_1_0 = (*in4_size != 1);
    loop_ub = *in4_size == 1 ? *in3_size : *in4_size;
    for (int32_T i{0}; i < loop_ub; i++)
    {
        in1_data[i] = in2_data[in3_data[i * stride_0_0] - 1] - in4_data[i * stride_1_0];
    }
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_ev(real_T in1_data[], int32_T *in1_size, const real_T
    in2_data[], const int32_T in2_size[2], B_CalculateDifferentialCorrec_T *localB)
{
    int32_T in1_size_idx_0;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    in1_size_idx_0 = in2_size[1] == 1 ? *in1_size : in2_size[1];
    stride_0_0 = (*in1_size != 1);
    stride_1_0 = (in2_size[1] != 1);
    loop_ub = in2_size[1] == 1 ? *in1_size : in2_size[1];
    for (localB->i19 = 0; localB->i19 < loop_ub; localB->i19++)
    {
        localB->in1_data[localB->i19] = in2_data[localB->i19 * stride_1_0] * 2.99792458E+8 + in1_data[localB->i19 *
            stride_0_0];
    }

    *in1_size = in1_size_idx_0;
    if (in1_size_idx_0 - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &localB->in1_data[0], static_cast<uint32_T>(in1_size_idx_0) * sizeof(real_T));
    }
}

//
// System initialize for atomic system:
//    '<S29>/Calculate Differential Corrections'
//    '<S156>/Calculate Differential Corrections'
//
void GNSSPreProcessingDualAntenna::CalculateDifferentialCorre_Init(DW_CalculateDifferentialCorre_T *localDW)
{
    localDW->delta_pr2.size = 0;
    localDW->PRNs.size = 0;
}

//
// Output and update for atomic system:
//    '<S29>/Calculate Differential Corrections'
//    '<S156>/Calculate Differential Corrections'
//
void GNSSPreProcessingDualAntenna::CalculateDifferentialCorrection(const GNSS_Measurement *rtu_GpsMeasurementB, const
    GNSS_Measurement_size *rtu_GpsMeasurementB_DIMS1, const gnssops_navigation_data *rtu_gpsNavDataBusL1, const
    gnssops_navigation_data_size *rtu_gpsNavDataBusL1_DIMS1, const real_T rtu_userPosLlh[3],
    B_CalculateDifferentialCorrec_T *localB, DW_CalculateDifferentialCorre_T *localDW)
{
    if (!localDW->delta_pr2_not_empty)
    {
        localDW->delta_pr2.size = 40;
        std::memset(&localDW->delta_pr2.data[0], 0, 40U * sizeof(real_T));
        localDW->delta_pr2_not_empty = true;
        localDW->old_t = 0.0;
        localDW->PRNs.size = 1;
        localDW->PRNs.data[0] = 0U;
    }

    if ((rtu_GpsMeasurementB->time_receive > localDW->old_t) || (rtu_GpsMeasurementB->time_receive - localDW->old_t <
            -100.0))
    {
        __m128d tmp_0;
        __m128d tmp_1;
        localDW->old_t = rtu_GpsMeasurementB->time_receive;
        localB->a_size = rtu_GpsMeasurementB_DIMS1->PRN;
        localB->vstride = rtu_GpsMeasurementB_DIMS1->PRN;
        if (localB->vstride - 1 >= 0)
        {
            std::memcpy(&localB->a_data[0], &rtu_GpsMeasurementB->PRN[0], static_cast<uint32_T>(localB->vstride) *
                        sizeof(uint16_T));
        }

        GNSSPreProcessingDualAnten_sort(localB->a_data, &localB->a_size, localB->iidx_data, &localB->iidx_size, localB);
        localB->rtu_gpsNavDataBusL1_DIMS1 = rtu_gpsNavDataBusL1_DIMS1->SVID;
        GNSSPreProcessingDua_do_vectors(localB->a_data, &localB->a_size, rtu_gpsNavDataBusL1->SVID,
            &localB->rtu_gpsNavDataBusL1_DIMS1, localDW->PRNs.data, &localDW->PRNs.size, localB->iia_data,
            &localB->iia_size, localB->iib_data, &localB->iib_size);
        localB->real_range_size = localB->iib_size;
        localB->vstride = localB->iib_size;
        for (localB->k = 0; localB->k < localB->vstride; localB->k++)
        {
            localB->real_range_data[localB->k] = localB->iib_data[localB->k];
        }

        localB->navdata_DELTA_N_size[0] = 1;
        localB->navdata_DELTA_N_size[1] = localB->iib_size;
        localB->vstride = localB->iib_size;
        for (localB->k = 0; localB->k < localB->vstride; localB->k++)
        {
            localB->navdata_DELTA_N_data[localB->k] = rtu_gpsNavDataBusL1->DELTA_N[static_cast<int32_T>
                (localB->real_range_data[localB->k]) - 1];
        }

        localB->navdata_M_0_size[0] = 1;
        localB->navdata_M_0_size[1] = localB->iib_size;
        localB->vstride = localB->iib_size;
        for (localB->k = 0; localB->k < localB->vstride; localB->k++)
        {
            localB->navdata_M_0_data[localB->k] = rtu_gpsNavDataBusL1->M_0[static_cast<int32_T>(localB->
                real_range_data[localB->k]) - 1];
        }

        localB->navdata_E_size[0] = 1;
        localB->navdata_E_size[1] = localB->iib_size;
        localB->vstride = localB->iib_size;
        for (localB->k = 0; localB->k < localB->vstride; localB->k++)
        {
            localB->navdata_E_data[localB->k] = rtu_gpsNavDataBusL1->E[static_cast<int32_T>(localB->
                real_range_data[localB->k]) - 1];
        }

        localB->navdata_SQRT_A_size[0] = 1;
        localB->navdata_SQRT_A_size[1] = localB->iib_size;
        localB->vstride = localB->iib_size;
        for (localB->k = 0; localB->k < localB->vstride; localB->k++)
        {
            localB->navdata_SQRT_A_data[localB->k] = rtu_gpsNavDataBusL1->SQRT_A[static_cast<int32_T>
                (localB->real_range_data[localB->k]) - 1];
        }

        localB->navdata_T_oe_size[0] = 1;
        localB->navdata_T_oe_size[1] = localB->iib_size;
        localB->vstride = localB->iib_size;
        for (localB->k = 0; localB->k < localB->vstride; localB->k++)
        {
            localB->navdata_T_oe_data[localB->k] = rtu_gpsNavDataBusL1->T_oe[static_cast<int32_T>
                (localB->real_range_data[localB->k]) - 1];
        }

        localB->vstride = localB->iidx_size;
        for (localB->k = 0; localB->k < localB->vstride; localB->k++)
        {
            localB->b_data[localB->k] = rtu_GpsMeasurementB->pseudorange[localB->iidx_data[localB->k] - 1];
        }

        localB->t_sv_emission_size[0] = 1;
        localB->t_sv_emission_size[1] = localB->iia_size;
        localB->vstride = localB->iia_size;
        for (localB->k = 0; localB->k < localB->vstride; localB->k++)
        {
            localB->t_sv_emission_data[localB->k] = rtu_GpsMeasurementB->time_receive - localB->b_data[localB->
                iia_data[localB->k] - 1] / 2.99792458E+8;
        }

        if (localB->iib_size == localB->iia_size)
        {
            localB->t_d_size[1] = localB->iia_size;
            localB->vstride = localB->iia_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->t_d_data[localB->k] = localB->t_sv_emission_data[localB->k] - rtu_gpsNavDataBusL1->T_oc[
                    static_cast<int32_T>(localB->real_range_data[localB->k]) - 1];
            }
        }
        else
        {
            GNSSP_binary_expand_op_evirnrbr(localB->t_d_data, localB->t_d_size, localB->t_sv_emission_data,
                localB->t_sv_emission_size, rtu_gpsNavDataBusL1, localB->real_range_data, &localB->real_range_size);
        }

        localB->t_d_size[0] = 1;
        localB->vstride = localB->t_d_size[1] - 1;
        for (localB->k = 0; localB->k <= localB->vstride; localB->k++)
        {
            localB->t_d = localB->t_d_data[localB->k];
            localB->t_d_data[localB->k] = (localB->t_d - static_cast<real_T>(localB->t_d > 302400.0) * 604800.0) +
                static_cast<real_T>(localB->t_d < -302400.0) * 604800.0;
        }

        if (localB->iia_size == localB->iib_size)
        {
            localB->t_k_size[0] = 1;
            localB->t_k_size[1] = localB->iia_size;
            localB->vstride = localB->iia_size;
            localB->scalarLB = (localB->iia_size / 2) << 1;
            localB->acoef = localB->scalarLB - 2;
            for (localB->k = 0; localB->k <= localB->acoef; localB->k += 2)
            {
                tmp_0 = _mm_loadu_pd(&localB->t_sv_emission_data[localB->k]);
                tmp_1 = _mm_loadu_pd(&localB->navdata_T_oe_data[localB->k]);
                _mm_storeu_pd(&localB->t_k_data[localB->k], _mm_sub_pd(tmp_0, tmp_1));
            }

            for (localB->k = localB->scalarLB; localB->k < localB->vstride; localB->k++)
            {
                localB->t_k_data[localB->k] = localB->t_sv_emission_data[localB->k] - localB->navdata_T_oe_data
                    [localB->k];
            }
        }
        else
        {
            GNSSPreProcessingDualA_minus_f4(localB->t_k_data, localB->t_k_size, localB->t_sv_emission_data,
                localB->t_sv_emission_size, localB->navdata_T_oe_data, localB->navdata_T_oe_size);
        }

        localB->n_0_size[0] = 1;
        localB->n_0_size[1] = localB->iib_size;
        localB->vstride = localB->iib_size;
        for (localB->k = 0; localB->k < localB->vstride; localB->k++)
        {
            localB->t_d = localB->navdata_SQRT_A_data[localB->k];
            localB->n_0_data[localB->k] = 3.986005E+14 / GNSSPreProcessing_rt_powd_snf_p(localB->t_d * localB->t_d, 3.0,
                localB);
        }

        localB->i = localB->iib_size;
        localB->scalarLB = (localB->iib_size / 2) << 1;
        localB->acoef = localB->scalarLB - 2;
        for (localB->k = 0; localB->k <= localB->acoef; localB->k += 2)
        {
            tmp_0 = _mm_loadu_pd(&localB->n_0_data[localB->k]);
            _mm_storeu_pd(&localB->n_0_data[localB->k], _mm_sqrt_pd(tmp_0));
        }

        for (localB->k = localB->scalarLB; localB->k < localB->i; localB->k++)
        {
            localB->n_0_data[localB->k] = std::sqrt(localB->n_0_data[localB->k]);
        }

        if ((localB->iib_size == localB->t_k_size[1]) && ((localB->iib_size == 1 ? localB->t_k_size[1] :
                localB->iib_size) == localB->iib_size))
        {
            localB->vstride = localB->iib_size - 1;
            localB->n_0_size[0] = 1;
            localB->n_0_size[1] = localB->iib_size;
            for (localB->k = 0; localB->k <= localB->vstride; localB->k++)
            {
                localB->t_d = localB->t_k_data[localB->k];
                localB->n_0_data[localB->k] = ((localB->t_d - static_cast<real_T>(localB->t_d > 302400.0) * 604800.0) +
                    static_cast<real_T>(localB->t_d < -302400.0) * 604800.0) * (localB->n_0_data[localB->k] +
                    localB->navdata_DELTA_N_data[localB->k]) + localB->navdata_M_0_data[localB->k];
            }
        }
        else
        {
            GNSSPr_binary_expand_op_evirnrb(localB->n_0_data, localB->n_0_size, localB->navdata_M_0_data,
                localB->navdata_M_0_size, localB->navdata_DELTA_N_data, localB->navdata_DELTA_N_size, localB->t_k_data,
                localB->t_k_size, localB);
        }

        if ((localB->iib_size == localB->n_0_size[1]) && ((localB->iib_size == 1 ? localB->n_0_size[1] :
                localB->iib_size) == localB->iib_size))
        {
            localB->E_k_size[0] = 1;
            localB->E_k_size[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->t_d = localB->navdata_E_data[localB->k];
                localB->E_k_data[localB->k] = static_cast<real_T>(localB->t_d > 0.8) * 3.1415926535897931 + static_cast<
                    real_T>(localB->t_d <= 0.8) * localB->n_0_data[localB->k];
            }
        }
        else
        {
            GNSSPre_binary_expand_op_evirnr(localB->E_k_data, localB->E_k_size, localB->navdata_E_data,
                localB->navdata_E_size, localB->n_0_data, localB->n_0_size, localB);
        }

        localB->i = 0;
        localB->t_k_size[1] = localB->E_k_size[1];
        localB->vstride = localB->E_k_size[1];
        for (localB->k = 0; localB->k < localB->vstride; localB->k++)
        {
            localB->t_k_data[localB->k] = 1.0;
        }

        int32_T exitg1;
        do
        {
            exitg1 = 0;
            localB->t_k_size_j[0] = 1;
            localB->t_k_size_j[1] = localB->t_k_size[1];
            localB->vstride = localB->t_k_size[1];
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->t_k_data_n[localB->k] = (localB->t_k_data[localB->k] > 1.0E-15);
            }

            if (GNSSPreProcessingDualAntenn_any(localB->t_k_data_n, localB->t_k_size_j, localB) && (localB->i < 20))
            {
                localB->E_k_old_size[0] = 1;
                localB->E_k_old_size[1] = localB->E_k_size[1];
                localB->vstride = localB->E_k_size[1];
                if (localB->vstride - 1 >= 0)
                {
                    std::memcpy(&localB->E_k_old_data[0], &localB->E_k_data[0], static_cast<uint32_T>(localB->vstride) *
                                sizeof(real_T));
                }

                localB->scalarLB = localB->E_k_size[1];
                for (localB->k = 0; localB->k < localB->scalarLB; localB->k++)
                {
                    localB->E_k_data[localB->k] = std::sin(localB->E_k_data[localB->k]);
                }

                if ((localB->navdata_E_size[1] == localB->E_k_size[1]) && ((localB->navdata_E_size[1] == 1 ?
                        localB->E_k_size[1] : localB->navdata_E_size[1]) == localB->n_0_size[1]))
                {
                    localB->vstride = localB->n_0_size[1] - 1;
                    localB->E_k_size[0] = 1;
                    localB->E_k_size[1] = localB->n_0_size[1];
                    localB->scalarLB = (localB->n_0_size[1] / 2) << 1;
                    localB->acoef = localB->scalarLB - 2;
                    for (localB->k = 0; localB->k <= localB->acoef; localB->k += 2)
                    {
                        __m128d tmp;
                        tmp_0 = _mm_loadu_pd(&localB->navdata_E_data[localB->k]);
                        tmp_1 = _mm_loadu_pd(&localB->E_k_data[localB->k]);
                        tmp = _mm_loadu_pd(&localB->n_0_data[localB->k]);
                        _mm_storeu_pd(&localB->E_k_data[localB->k], _mm_add_pd(_mm_mul_pd(tmp_0, tmp_1), tmp));
                    }

                    for (localB->k = localB->scalarLB; localB->k <= localB->vstride; localB->k++)
                    {
                        localB->E_k_data[localB->k] = localB->navdata_E_data[localB->k] * localB->E_k_data[localB->k] +
                            localB->n_0_data[localB->k];
                    }
                }
                else
                {
                    GNSSPreProce_binary_expand_op_e(localB->E_k_data, localB->E_k_size, localB->n_0_data,
                        localB->n_0_size, localB->navdata_E_data, localB->navdata_E_size, localB);
                }

                if (localB->E_k_size[1] == localB->E_k_old_size[1])
                {
                    localB->vstride = localB->E_k_size[1] - 1;
                    localB->E_k_old_size[1] = localB->E_k_size[1];
                    localB->scalarLB = (localB->E_k_size[1] / 2) << 1;
                    localB->acoef = localB->scalarLB - 2;
                    for (localB->k = 0; localB->k <= localB->acoef; localB->k += 2)
                    {
                        tmp_0 = _mm_loadu_pd(&localB->E_k_data[localB->k]);
                        tmp_1 = _mm_loadu_pd(&localB->E_k_old_data[localB->k]);
                        _mm_storeu_pd(&localB->E_k_old_data[localB->k], _mm_sub_pd(tmp_0, tmp_1));
                    }

                    for (localB->k = localB->scalarLB; localB->k <= localB->vstride; localB->k++)
                    {
                        localB->E_k_old_data[localB->k] = localB->E_k_data[localB->k] - localB->E_k_old_data[localB->k];
                    }
                }
                else
                {
                    GNSSPreProcessingDualAn_minus_f(localB->E_k_old_data, localB->E_k_old_size, localB->E_k_data,
                        localB->E_k_size, localB);
                }

                localB->t_k_size[1] = localB->E_k_old_size[1];
                localB->scalarLB = localB->E_k_old_size[1];
                for (localB->k = 0; localB->k < localB->scalarLB; localB->k++)
                {
                    localB->t_k_data[localB->k] = std::abs(localB->E_k_old_data[localB->k]);
                }

                localB->i++;
            }
            else
            {
                exitg1 = 1;
            }
        }
        while (exitg1 == 0);

        localB->scalarLB = localB->E_k_size[1];
        for (localB->k = 0; localB->k < localB->scalarLB; localB->k++)
        {
            localB->E_k_data[localB->k] = std::sin(localB->E_k_data[localB->k]);
        }

        localB->scalarLB = (localB->t_d_size[1] / 2) << 1;
        localB->acoef = localB->scalarLB - 2;
        for (localB->k = 0; localB->k <= localB->acoef; localB->k += 2)
        {
            tmp_0 = _mm_loadu_pd(&localB->t_d_data[localB->k]);
            _mm_storeu_pd(&localB->t_k_data[localB->k], _mm_mul_pd(tmp_0, tmp_0));
        }

        localB->acoef = localB->scalarLB - 2;
        for (localB->k = 0; localB->k <= localB->acoef; localB->k += 2)
        {
            tmp_0 = _mm_loadu_pd(&localB->t_d_data[localB->k]);
            _mm_storeu_pd(&localB->n_0_data[localB->k], _mm_mul_pd(tmp_0, tmp_0));
        }

        localB->acoef = localB->scalarLB - 2;
        for (localB->k = 0; localB->k <= localB->acoef; localB->k += 2)
        {
            tmp_0 = _mm_loadu_pd(&localB->t_d_data[localB->k]);
            _mm_storeu_pd(&localB->E_k_old_data[localB->k], _mm_mul_pd(tmp_0, tmp_0));
        }

        if ((localB->iib_size == localB->t_d_size[1]) && ((localB->iib_size == 1 ? localB->t_d_size[1] :
                localB->iib_size) == localB->iib_size) && (localB->iib_size == localB->t_d_size[1]) &&
                ((localB->iib_size == 1 ? localB->iib_size == 1 ? localB->t_d_size[1] : localB->iib_size :
                  localB->iib_size) == (localB->iib_size == 1 ? localB->t_d_size[1] : localB->iib_size)) &&
                (localB->iib_size == localB->E_k_size[1]) && (((localB->iib_size == 1 ? localB->iib_size == 1 ?
                localB->t_d_size[1] : localB->iib_size : localB->iib_size) == 1 ? localB->iib_size == 1 ?
                localB->t_d_size[1] : localB->iib_size : localB->iib_size == 1 ? localB->iib_size == 1 ?
                localB->t_d_size[1] : localB->iib_size : localB->iib_size) == (localB->iib_size == 1 ? localB->E_k_size
                [1] : localB->iib_size)))
        {
            localB->t_d_size[0] = 1;
            localB->t_d_size[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->t_d = localB->t_d_data[localB->k];
                localB->scalarLB = static_cast<int32_T>(localB->real_range_data[localB->k]) - 1;
                localB->t_d_data[localB->k] = ((rtu_gpsNavDataBusL1->A_f1[localB->scalarLB] * localB->t_d +
                    rtu_gpsNavDataBusL1->A_f0[localB->scalarLB]) + localB->t_d * localB->t_d * rtu_gpsNavDataBusL1->
                    A_f2[localB->scalarLB]) + -4.44280763339306E-10 * localB->navdata_E_data[localB->k] *
                    localB->navdata_SQRT_A_data[localB->k] * localB->E_k_data[localB->k];
            }
        }
        else
        {
            GNSSPreP_binary_expand_op_evirn(localB->t_d_data, localB->t_d_size, rtu_gpsNavDataBusL1,
                localB->real_range_data, &localB->real_range_size, localB->navdata_E_data, localB->navdata_E_size,
                localB->navdata_SQRT_A_data, localB->navdata_SQRT_A_size, localB->E_k_data, localB->E_k_size, localB);
        }

        if (localB->iia_size == localB->t_d_size[1])
        {
            localB->E_k_size[0] = 1;
            localB->E_k_size[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->E_k_data[localB->k] = rtu_gpsNavDataBusL1->C_rs[static_cast<int32_T>(localB->
                    real_range_data[localB->k]) - 1];
            }

            localB->t_k_size[0] = 1;
            localB->t_k_size[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->t_k_data[localB->k] = rtu_gpsNavDataBusL1->C_uc[static_cast<int32_T>(localB->
                    real_range_data[localB->k]) - 1];
            }

            localB->n_0_size[0] = 1;
            localB->n_0_size[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->n_0_data[localB->k] = rtu_gpsNavDataBusL1->C_us[static_cast<int32_T>(localB->
                    real_range_data[localB->k]) - 1];
            }

            localB->E_k_old_size[0] = 1;
            localB->E_k_old_size[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->E_k_old_data[localB->k] = rtu_gpsNavDataBusL1->C_ic[static_cast<int32_T>(localB->
                    real_range_data[localB->k]) - 1];
            }

            localB->rtu_gpsNavDataBusL1_size[0] = 1;
            localB->rtu_gpsNavDataBusL1_size[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->rtu_gpsNavDataBusL1_data[localB->k] = rtu_gpsNavDataBusL1->OMEGA_0[static_cast<int32_T>
                    (localB->real_range_data[localB->k]) - 1];
            }

            localB->rtu_gpsNavDataBusL1_size_h[0] = 1;
            localB->rtu_gpsNavDataBusL1_size_h[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->rtu_gpsNavDataBusL1_data_m[localB->k] = rtu_gpsNavDataBusL1->C_is[static_cast<int32_T>
                    (localB->real_range_data[localB->k]) - 1];
            }

            localB->rtu_gpsNavDataBusL1_size_c[0] = 1;
            localB->rtu_gpsNavDataBusL1_size_c[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->rtu_gpsNavDataBusL1_data_c[localB->k] = rtu_gpsNavDataBusL1->I_0[static_cast<int32_T>
                    (localB->real_range_data[localB->k]) - 1];
            }

            localB->rtu_gpsNavDataBusL1_size_ct[0] = 1;
            localB->rtu_gpsNavDataBusL1_size_ct[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->rtu_gpsNavDataBusL1_data_k[localB->k] = rtu_gpsNavDataBusL1->C_rc[static_cast<int32_T>
                    (localB->real_range_data[localB->k]) - 1];
            }

            localB->rtu_gpsNavDataBusL1_size_p[0] = 1;
            localB->rtu_gpsNavDataBusL1_size_p[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->rtu_gpsNavDataBusL1_data_cx[localB->k] = rtu_gpsNavDataBusL1->omega[static_cast<int32_T>
                    (localB->real_range_data[localB->k]) - 1];
            }

            localB->rtu_gpsNavDataBusL1_size_p5[0] = 1;
            localB->rtu_gpsNavDataBusL1_size_p5[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->rtu_gpsNavDataBusL1_data_b[localB->k] = rtu_gpsNavDataBusL1->OMEGADOT[static_cast<int32_T>
                    (localB->real_range_data[localB->k]) - 1];
            }

            localB->rtu_gpsNavDataBusL1_size_a[0] = 1;
            localB->rtu_gpsNavDataBusL1_size_a[1] = localB->iib_size;
            localB->vstride = localB->iib_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localB->rtu_gpsNavDataBusL1_data_p[localB->k] = rtu_gpsNavDataBusL1->IDOT[static_cast<int32_T>
                    (localB->real_range_data[localB->k]) - 1];
            }

            localB->t_sv_emission_size_e[0] = 1;
            localB->t_sv_emission_size_e[1] = localB->iia_size;
            localB->vstride = localB->iia_size;
            localB->scalarLB = (localB->iia_size / 2) << 1;
            localB->acoef = localB->scalarLB - 2;
            for (localB->k = 0; localB->k <= localB->acoef; localB->k += 2)
            {
                tmp_0 = _mm_loadu_pd(&localB->t_sv_emission_data[localB->k]);
                tmp_1 = _mm_loadu_pd(&localB->t_d_data[localB->k]);
                _mm_storeu_pd(&localB->real_range_data[localB->k], _mm_sub_pd(tmp_0, tmp_1));
            }

            for (localB->k = localB->scalarLB; localB->k < localB->vstride; localB->k++)
            {
                localB->real_range_data[localB->k] = localB->t_sv_emission_data[localB->k] - localB->t_d_data[localB->k];
            }

            Get_Kepler_Satellite_Position_b(localB->E_k_data, localB->E_k_size, localB->navdata_DELTA_N_data,
                localB->navdata_DELTA_N_size, localB->navdata_M_0_data, localB->navdata_M_0_size, localB->t_k_data,
                localB->t_k_size, localB->navdata_E_data, localB->navdata_E_size, localB->n_0_data, localB->n_0_size,
                localB->navdata_SQRT_A_data, localB->navdata_SQRT_A_size, localB->navdata_T_oe_data,
                localB->navdata_T_oe_size, localB->E_k_old_data, localB->E_k_old_size, localB->rtu_gpsNavDataBusL1_data,
                localB->rtu_gpsNavDataBusL1_size, localB->rtu_gpsNavDataBusL1_data_m, localB->rtu_gpsNavDataBusL1_size_h,
                localB->rtu_gpsNavDataBusL1_data_c, localB->rtu_gpsNavDataBusL1_size_c,
                localB->rtu_gpsNavDataBusL1_data_k, localB->rtu_gpsNavDataBusL1_size_ct,
                localB->rtu_gpsNavDataBusL1_data_cx, localB->rtu_gpsNavDataBusL1_size_p,
                localB->rtu_gpsNavDataBusL1_data_b, localB->rtu_gpsNavDataBusL1_size_p5,
                localB->rtu_gpsNavDataBusL1_data_p, localB->rtu_gpsNavDataBusL1_size_a, localB->real_range_data,
                localB->t_sv_emission_size_e, rtu_userPosLlh, localB->b_a_data, localB->t_k_size_j,
                localB->real_delta_data, localB->real_delta_size, localB);
        }
        else
        {
            GNSSPrePr_binary_expand_op_evir(rtu_gpsNavDataBusL1, localB->real_range_data, &localB->real_range_size,
                localB->navdata_DELTA_N_data, localB->navdata_DELTA_N_size, localB->navdata_M_0_data,
                localB->navdata_M_0_size, localB->navdata_E_data, localB->navdata_E_size, localB->navdata_SQRT_A_data,
                localB->navdata_SQRT_A_size, localB->navdata_T_oe_data, localB->navdata_T_oe_size,
                localB->t_sv_emission_data, localB->t_sv_emission_size, localB->t_d_data, localB->t_d_size,
                rtu_userPosLlh, localB->b_a_data, localB->t_k_size_j, localB->real_delta_data, localB->real_delta_size,
                localB);
        }

        localB->real_delta_size[0] = static_cast<int8_T>(localB->t_k_size_j[0]);
        if (static_cast<int8_T>(localB->t_k_size_j[0]) != 0)
        {
            localB->acoef = (localB->t_k_size_j[0] != 1);
            for (localB->k = 0; localB->k < 3; localB->k++)
            {
                localB->i = localB->real_delta_size[0] - 1;
                for (localB->scalarLB = 0; localB->scalarLB <= localB->i; localB->scalarLB++)
                {
                    localB->real_delta_data[localB->scalarLB + localB->real_delta_size[0] * localB->k] =
                        localB->b_a_data[localB->acoef * localB->scalarLB + localB->t_k_size_j[0] * localB->k] -
                        rtu_GpsMeasurementB->base_position[localB->k];
                }
            }
        }

        localB->vstride = static_cast<int8_T>(localB->t_k_size_j[0]) * 3;
        localB->scalarLB = (localB->vstride / 2) << 1;
        localB->acoef = localB->scalarLB - 2;
        for (localB->k = 0; localB->k <= localB->acoef; localB->k += 2)
        {
            tmp_0 = _mm_loadu_pd(&localB->real_delta_data[localB->k]);
            _mm_storeu_pd(&localB->real_delta_data[localB->k], _mm_mul_pd(tmp_0, tmp_0));
        }

        for (localB->k = localB->scalarLB; localB->k < localB->vstride; localB->k++)
        {
            localB->t_d = localB->real_delta_data[localB->k];
            localB->real_delta_data[localB->k] = localB->t_d * localB->t_d;
        }

        if (static_cast<int8_T>(localB->t_k_size_j[0]) == 0)
        {
            localB->real_range_size = 0;
        }
        else
        {
            localB->vstride = static_cast<int8_T>(localB->t_k_size_j[0]);
            localB->real_range_size = static_cast<int8_T>(localB->t_k_size_j[0]);
            localB->scalarLB = static_cast<int8_T>(localB->t_k_size_j[0]);
            std::memcpy(&localB->real_range_data[0], &localB->real_delta_data[0], static_cast<uint32_T>(localB->scalarLB)
                        * sizeof(real_T));
            for (localB->k = 0; localB->k < 2; localB->k++)
            {
                localB->xoffset = (localB->k + 1) * localB->vstride;
                localB->scalarLB = (localB->vstride / 2) << 1;
                localB->acoef = localB->scalarLB - 2;
                for (localB->i = 0; localB->i <= localB->acoef; localB->i += 2)
                {
                    tmp_0 = _mm_loadu_pd(&localB->real_delta_data[localB->xoffset + localB->i]);
                    tmp_1 = _mm_loadu_pd(&localB->real_range_data[localB->i]);
                    _mm_storeu_pd(&localB->real_range_data[localB->i], _mm_add_pd(tmp_0, tmp_1));
                }

                for (localB->i = localB->scalarLB; localB->i < localB->vstride; localB->i++)
                {
                    localB->real_range_data[localB->i] += localB->real_delta_data[localB->xoffset + localB->i];
                }
            }
        }

        localB->i = localB->real_range_size;
        localB->scalarLB = (localB->real_range_size / 2) << 1;
        localB->acoef = localB->scalarLB - 2;
        for (localB->k = 0; localB->k <= localB->acoef; localB->k += 2)
        {
            tmp_0 = _mm_loadu_pd(&localB->real_range_data[localB->k]);
            _mm_storeu_pd(&localB->real_range_data[localB->k], _mm_sqrt_pd(tmp_0));
        }

        for (localB->k = localB->scalarLB; localB->k < localB->i; localB->k++)
        {
            localB->real_range_data[localB->k] = std::sqrt(localB->real_range_data[localB->k]);
        }

        if (localB->iia_size == localB->real_range_size)
        {
            localDW->delta_pr2.size = localB->iia_size;
            localB->vstride = localB->iia_size;
            for (localB->k = 0; localB->k < localB->vstride; localB->k++)
            {
                localDW->delta_pr2.data[localB->k] = localB->b_data[localB->iia_data[localB->k] - 1] -
                    localB->real_range_data[localB->k];
            }
        }
        else
        {
            GNSSPrePro_binary_expand_op_evi(localDW->delta_pr2.data, &localDW->delta_pr2.size, localB->b_data,
                localB->iia_data, &localB->iia_size, localB->real_range_data, &localB->real_range_size);
        }

        if (localDW->delta_pr2.size == localB->t_d_size[1])
        {
            localB->vstride = localDW->delta_pr2.size;
            localB->scalarLB = (localDW->delta_pr2.size / 2) << 1;
            localB->acoef = localB->scalarLB - 2;
            for (localB->k = 0; localB->k <= localB->acoef; localB->k += 2)
            {
                tmp_0 = _mm_loadu_pd(&localB->t_d_data[localB->k]);
                tmp_1 = _mm_loadu_pd(&localDW->delta_pr2.data[localB->k]);
                _mm_storeu_pd(&localDW->delta_pr2.data[localB->k], _mm_add_pd(_mm_mul_pd(tmp_0, _mm_set1_pd
                                (2.99792458E+8)), tmp_1));
            }

            for (localB->k = localB->scalarLB; localB->k < localB->vstride; localB->k++)
            {
                localDW->delta_pr2.data[localB->k] += localB->t_d_data[localB->k] * 2.99792458E+8;
            }
        }
        else
        {
            GNSSPreProc_binary_expand_op_ev(localDW->delta_pr2.data, &localDW->delta_pr2.size, localB->t_d_data,
                localB->t_d_size, localB);
        }

        localDW->delta_pr2_not_empty = (localDW->delta_pr2.size != 0);
    }

    localDW->SFunction_DIMS3 = localDW->PRNs.size;
    localB->vstride = localDW->PRNs.size;
    if (localB->vstride - 1 >= 0)
    {
        std::memcpy(&localB->maskDiffCorr[0], &localDW->PRNs.data[0], static_cast<uint32_T>(localB->vstride) * sizeof
                    (uint16_T));
    }

    localDW->SFunction_DIMS2 = localDW->delta_pr2.size;
    localB->vstride = localDW->delta_pr2.size;
    if (localB->vstride - 1 >= 0)
    {
        std::memcpy(&localB->diffPseudorangeCorrection[0], &localDW->delta_pr2.data[0], static_cast<uint32_T>
                    (localB->vstride) * sizeof(real_T));
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
