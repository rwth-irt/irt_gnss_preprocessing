//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SimplifyandMaskGALMeasurementBu.cpp
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
#include "GNSSPreProcessingDualAntenna.h"
#include "rtwtypes.h"
#include <cstring>
#include "SimplifyandMaskGALMeasurementBu.h"

// Function for MATLAB Function: '<S18>/Simplify and Mask GAL Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAnt_any_jj(const boolean_T x[200], boolean_T y[40])
{
    int32_T i2;
    i2 = 1;
    for (int32_T i{0}; i < 40; i++)
    {
        int32_T a;
        int32_T ix;
        boolean_T exitg1;
        y[i] = false;
        a = i2 + 4;
        ix = i2;
        i2 += 5;
        exitg1 = false;
        while ((!exitg1) && (ix <= a))
        {
            if (x[ix - 1])
            {
                y[i] = true;
                exitg1 = true;
            }
            else
            {
                ix++;
            }
        }
    }
}

// Function for MATLAB Function: '<S18>/Simplify and Mask GAL Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDua_eml_find_h(const boolean_T x[5], int32_T i_data[], int32_T
    i_size[2])
{
    int32_T idx;
    int32_T ii;
    boolean_T exitg1;
    idx = 0;
    i_size[0] = 1;
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii < 5))
    {
        if (x[ii])
        {
            idx++;
            i_data[idx - 1] = ii + 1;
            if (idx >= 5)
            {
                exitg1 = true;
            }
            else
            {
                ii++;
            }
        }
        else
        {
            ii++;
        }
    }

    if (idx < 1)
    {
        i_size[1] = 0;
    }
    else
    {
        i_size[1] = idx;
    }
}

// Function for MATLAB Function: '<S18>/Simplify and Mask GAL Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAn_merge_p(int32_T idx_data[], uint16_T x_data[], int32_T offset,
    int32_T np, int32_T nq, int32_T iwork_data[], uint16_T xwork_data[])
{
    if (nq != 0)
    {
        int32_T iout;
        int32_T offset1;
        int32_T p;
        int32_T q;
        offset1 = np + nq;
        for (q = 0; q < offset1; q++)
        {
            iout = offset + q;
            iwork_data[q] = idx_data[iout];
            xwork_data[q] = x_data[iout];
        }

        p = 0;
        q = np;
        iout = offset - 1;
        int32_T exitg1;
        do
        {
            exitg1 = 0;
            iout++;
            if (xwork_data[p] <= xwork_data[q])
            {
                idx_data[iout] = iwork_data[p];
                x_data[iout] = xwork_data[p];
                if (p + 1 < np)
                {
                    p++;
                }
                else
                {
                    exitg1 = 1;
                }
            }
            else
            {
                idx_data[iout] = iwork_data[q];
                x_data[iout] = xwork_data[q];
                if (q + 1 < offset1)
                {
                    q++;
                }
                else
                {
                    offset1 = iout - p;
                    for (q = p + 1; q <= np; q++)
                    {
                        iout = offset1 + q;
                        idx_data[iout] = iwork_data[q - 1];
                        x_data[iout] = xwork_data[q - 1];
                    }

                    exitg1 = 1;
                }
            }
        }
        while (exitg1 == 0);
    }
}

// Function for MATLAB Function: '<S18>/Simplify and Mask GAL Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAnt_sort_b(uint16_T x_data[], int32_T x_size[2], int32_T
    idx_data[], int32_T idx_size[2], B_SimplifyandMaskGALMeasureme_T *localB)
{
    int32_T nLeft;
    localB->b_x_size[1] = x_size[1];
    nLeft = x_size[1];
    if (nLeft - 1 >= 0)
    {
        std::memcpy(&localB->b_x_data[0], &x_data[0], static_cast<uint32_T>(nLeft) * sizeof(uint16_T));
    }

    idx_size[0] = 1;
    idx_size[1] = x_size[1];
    nLeft = x_size[1];
    if (nLeft - 1 >= 0)
    {
        std::memset(&idx_data[0], 0, static_cast<uint32_T>(nLeft) * sizeof(int32_T));
    }

    if (x_size[1] != 0)
    {
        int32_T i;
        int32_T i1;
        int32_T i2;
        int32_T nDone;
        int32_T nQuartets_tmp;
        idx_size[0] = 1;
        idx_size[1] = x_size[1];
        nLeft = x_size[1];
        if (nLeft - 1 >= 0)
        {
            std::memset(&idx_data[0], 0, static_cast<uint32_T>(nLeft) * sizeof(int32_T));
        }

        localB->b_x_size[1] = x_size[1];
        nLeft = x_size[1];
        if (nLeft - 1 >= 0)
        {
            std::memcpy(&localB->b_x_data[0], &x_data[0], static_cast<uint32_T>(nLeft) * sizeof(uint16_T));
        }

        localB->x4[0] = 0U;
        localB->idx4[0] = 0;
        localB->x4[1] = 0U;
        localB->idx4[1] = 0;
        localB->x4[2] = 0U;
        localB->idx4[2] = 0;
        localB->x4[3] = 0U;
        localB->idx4[3] = 0;
        nQuartets_tmp = x_size[1] >> 2;
        for (nLeft = 0; nLeft < nQuartets_tmp; nLeft++)
        {
            int32_T i3;
            int32_T i4;
            int32_T tmp;
            uint16_T x4_tmp;
            uint16_T x4_tmp_0;
            uint16_T x4_tmp_1;
            uint16_T x4_tmp_2;
            i = nLeft << 2;
            localB->idx4[0] = static_cast<int8_T>(i + 1);
            localB->idx4[1] = static_cast<int8_T>(i + 2);
            localB->idx4[2] = static_cast<int8_T>(i + 3);
            localB->idx4[3] = static_cast<int8_T>(i + 4);
            x4_tmp_2 = localB->b_x_data[i];
            localB->x4[0] = x4_tmp_2;
            x4_tmp = localB->b_x_data[i + 1];
            localB->x4[1] = x4_tmp;
            x4_tmp_0 = localB->b_x_data[i + 2];
            localB->x4[2] = x4_tmp_0;
            x4_tmp_1 = localB->b_x_data[i + 3];
            localB->x4[3] = x4_tmp_1;
            if (x4_tmp_2 <= x4_tmp)
            {
                i1 = 1;
                i2 = 2;
            }
            else
            {
                i1 = 2;
                i2 = 1;
            }

            if (x4_tmp_0 <= x4_tmp_1)
            {
                i3 = 3;
                i4 = 4;
            }
            else
            {
                i3 = 4;
                i4 = 3;
            }

            nDone = localB->x4[i1 - 1];
            tmp = localB->x4[i3 - 1];
            if (nDone <= tmp)
            {
                nDone = localB->x4[i2 - 1];
                if (nDone <= tmp)
                {
                    localB->perm[0] = static_cast<int8_T>(i1);
                    localB->perm[1] = static_cast<int8_T>(i2);
                    localB->perm[2] = static_cast<int8_T>(i3);
                    localB->perm[3] = static_cast<int8_T>(i4);
                }
                else if (nDone <= localB->x4[i4 - 1])
                {
                    localB->perm[0] = static_cast<int8_T>(i1);
                    localB->perm[1] = static_cast<int8_T>(i3);
                    localB->perm[2] = static_cast<int8_T>(i2);
                    localB->perm[3] = static_cast<int8_T>(i4);
                }
                else
                {
                    localB->perm[0] = static_cast<int8_T>(i1);
                    localB->perm[1] = static_cast<int8_T>(i3);
                    localB->perm[2] = static_cast<int8_T>(i4);
                    localB->perm[3] = static_cast<int8_T>(i2);
                }
            }
            else
            {
                tmp = localB->x4[i4 - 1];
                if (nDone <= tmp)
                {
                    if (localB->x4[i2 - 1] <= tmp)
                    {
                        localB->perm[0] = static_cast<int8_T>(i3);
                        localB->perm[1] = static_cast<int8_T>(i1);
                        localB->perm[2] = static_cast<int8_T>(i2);
                        localB->perm[3] = static_cast<int8_T>(i4);
                    }
                    else
                    {
                        localB->perm[0] = static_cast<int8_T>(i3);
                        localB->perm[1] = static_cast<int8_T>(i1);
                        localB->perm[2] = static_cast<int8_T>(i4);
                        localB->perm[3] = static_cast<int8_T>(i2);
                    }
                }
                else
                {
                    localB->perm[0] = static_cast<int8_T>(i3);
                    localB->perm[1] = static_cast<int8_T>(i4);
                    localB->perm[2] = static_cast<int8_T>(i1);
                    localB->perm[3] = static_cast<int8_T>(i2);
                }
            }

            idx_data[i] = localB->idx4[localB->perm[0] - 1];
            idx_data[i + 1] = localB->idx4[localB->perm[1] - 1];
            idx_data[i + 2] = localB->idx4[localB->perm[2] - 1];
            idx_data[i + 3] = localB->idx4[localB->perm[3] - 1];
            localB->b_x_data[i] = localB->x4[localB->perm[0] - 1];
            localB->b_x_data[i + 1] = localB->x4[localB->perm[1] - 1];
            localB->b_x_data[i + 2] = localB->x4[localB->perm[2] - 1];
            localB->b_x_data[i + 3] = localB->x4[localB->perm[3] - 1];
        }

        nDone = nQuartets_tmp << 2;
        nLeft = x_size[1] - nDone;
        if (nLeft > 0)
        {
            for (i2 = 0; i2 < nLeft; i2++)
            {
                i = nDone + i2;
                localB->idx4[i2] = static_cast<int8_T>(i + 1);
                localB->x4[i2] = localB->b_x_data[i];
            }

            localB->perm[1] = 0;
            localB->perm[2] = 0;
            localB->perm[3] = 0;
            switch (nLeft)
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

            for (i2 = 0; i2 < nLeft; i2++)
            {
                int8_T perm;
                perm = localB->perm[i2];
                i1 = nDone + i2;
                idx_data[i1] = localB->idx4[perm - 1];
                localB->b_x_data[i1] = localB->x4[perm - 1];
            }
        }

        if (x_size[1] > 1)
        {
            nLeft = x_size[1];
            if (nLeft - 1 >= 0)
            {
                std::memset(&localB->iwork_data[0], 0, static_cast<uint32_T>(nLeft) * sizeof(int32_T));
            }

            nLeft = x_size[1];
            if (nLeft - 1 >= 0)
            {
                std::memset(&localB->xwork_data[0], 0, static_cast<uint32_T>(nLeft) * sizeof(uint16_T));
            }

            nLeft = nQuartets_tmp;
            nDone = 4;
            while (nLeft > 1)
            {
                if ((static_cast<uint32_T>(nLeft) & 1U) != 0U)
                {
                    nLeft--;
                    i2 = nDone * nLeft;
                    i = x_size[1] - i2;
                    if (i > nDone)
                    {
                        GNSSPreProcessingDualAn_merge_p(idx_data, localB->b_x_data, i2, nDone, i - nDone,
                            localB->iwork_data, localB->xwork_data);
                    }
                }

                i = nDone << 1;
                nLeft >>= 1;
                for (i2 = 0; i2 < nLeft; i2++)
                {
                    GNSSPreProcessingDualAn_merge_p(idx_data, localB->b_x_data, i2 * i, nDone, nDone, localB->iwork_data,
                        localB->xwork_data);
                }

                nDone = i;
            }

            if (x_size[1] > nDone)
            {
                GNSSPreProcessingDualAn_merge_p(idx_data, localB->b_x_data, 0, nDone, x_size[1] - nDone,
                    localB->iwork_data, localB->xwork_data);
            }
        }
    }

    x_size[0] = 1;
    x_size[1] = localB->b_x_size[1];
    nLeft = localB->b_x_size[1];
    if (nLeft - 1 >= 0)
    {
        std::memcpy(&x_data[0], &localB->b_x_data[0], static_cast<uint32_T>(nLeft) * sizeof(uint16_T));
    }
}

// Function for MATLAB Function: '<S18>/Simplify and Mask GAL Measurement Bus'
boolean_T GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAn_any_jjs(const boolean_T x_data[], const int32_T *x_size)
{
    int32_T ix;
    boolean_T exitg1;
    boolean_T y;
    y = false;
    ix = 1;
    exitg1 = false;
    while ((!exitg1) && (ix <= *x_size))
    {
        if (x_data[ix - 1])
        {
            y = true;
            exitg1 = true;
        }
        else
        {
            ix++;
        }
    }

    return y;
}

void GNSSPreProcessingDualAntenna::GNSSPrePro_binary_expand_op_brs(real_T in1_data[], int32_T in1_size[2], const
    gnssraw_measurement_t *in2, const int8_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], const int32_T in5_data[], const int8_T in6_data[], const int32_T in6_size[2],
    B_SimplifyandMaskGALMeasureme_T *localB)
{
    int32_T aux_0_1;
    int32_T aux_1_1;
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    stride_0_1 = (in3_size[1] != 1);
    stride_1_1 = (in4_size[1] != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    loop_ub = in4_size[1] == 1 ? in3_size[1] : in4_size[1];
    for (int32_T i_0{0}; i_0 < loop_ub; i_0++)
    {
        for (int32_T i{0}; i < 5; i++)
        {
            localB->in2_data[i + 5 * i_0] = -in2->Doppler[(in3_data[aux_0_1] - 1) * 5 + i] * 2.99792458E+8 / in4_data[5 *
                aux_1_1 + i];
        }

        aux_1_1 += stride_1_1;
        aux_0_1 += stride_0_1;
    }

    in1_size[0] = 5;
    in1_size[1] = in6_size[1];
    loop_ub = in6_size[1];
    for (int32_T i_0{0}; i_0 < loop_ub; i_0++)
    {
        for (int32_T i{0}; i < 5; i++)
        {
            in1_data[i + 5 * i_0] = localB->in2_data[(in5_data[in6_data[i_0] - 1] - 1) * 5 + i];
        }
    }
}

// Function for MATLAB Function: '<S18>/Simplify and Mask GAL Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualA_any_jjst(const boolean_T x_data[], const int32_T x_size[2],
    boolean_T y_data[], int32_T y_size[2])
{
    int32_T c;
    int32_T i2;
    y_size[0] = 1;
    y_size[1] = static_cast<int8_T>(x_size[1]);
    i2 = static_cast<int8_T>(x_size[1]);
    if (i2 - 1 >= 0)
    {
        std::memset(&y_data[0], 0, static_cast<uint32_T>(i2) * sizeof(boolean_T));
    }

    i2 = 1;
    c = x_size[1];
    for (int32_T i{0}; i < c; i++)
    {
        int32_T a;
        int32_T ix;
        boolean_T exitg1;
        a = i2 + 4;
        ix = i2;
        i2 += 5;
        exitg1 = false;
        while ((!exitg1) && (ix <= a))
        {
            if (x_data[ix - 1])
            {
                y_data[i] = true;
                exitg1 = true;
            }
            else
            {
                ix++;
            }
        }
    }
}

void GNSSPreProcessingDualAntenna::emxConvertDynamicMatrixToEmx__f(emxArray_real_T_37_GNSSPrePro_T *emx, const real_T
    data[37], const int32_T *size)
{
    std::memcpy(&emx->data, (void *)data, sizeof(real_T) * static_cast<uint32_T>(*size));
    std::memcpy(&emx->size, (void *)size, sizeof(int32_T));
}

void GNSSPreProcessingDualAntenna::emxConvertStructToEmx_gnssops_i(emxArray__gnssops_navigation__T *emx, const
    gnssops_navigation_data *data, const gnssops_navigation_data_size *size)
{
    emxConvertDynamicMatrixToEmx__f(&emx->TOW, data->TOW, &size->TOW);
    emxConvertDynamicMatrixToEmx__f(&emx->WNc, data->WNc, &size->WNc);
    emxConvertDynamicMatrixToEmx__f(&emx->SVID, data->SVID, &size->SVID);
    emxConvertDynamicMatrixToEmx__f(&emx->T_gd, data->T_gd, &size->T_gd);
    emxConvertDynamicMatrixToEmx__f(&emx->T_oc, data->T_oc, &size->T_oc);
    emxConvertDynamicMatrixToEmx__f(&emx->A_f2, data->A_f2, &size->A_f2);
    emxConvertDynamicMatrixToEmx__f(&emx->A_f1, data->A_f1, &size->A_f1);
    emxConvertDynamicMatrixToEmx__f(&emx->A_f0, data->A_f0, &size->A_f0);
    emxConvertDynamicMatrixToEmx__f(&emx->C_rs, data->C_rs, &size->C_rs);
    emxConvertDynamicMatrixToEmx__f(&emx->DELTA_N, data->DELTA_N, &size->DELTA_N);
    emxConvertDynamicMatrixToEmx__f(&emx->M_0, data->M_0, &size->M_0);
    emxConvertDynamicMatrixToEmx__f(&emx->C_uc, data->C_uc, &size->C_uc);
    emxConvertDynamicMatrixToEmx__f(&emx->E, data->E, &size->E);
    emxConvertDynamicMatrixToEmx__f(&emx->C_us, data->C_us, &size->C_us);
    emxConvertDynamicMatrixToEmx__f(&emx->SQRT_A, data->SQRT_A, &size->SQRT_A);
    emxConvertDynamicMatrixToEmx__f(&emx->T_oe, data->T_oe, &size->T_oe);
    emxConvertDynamicMatrixToEmx__f(&emx->C_ic, data->C_ic, &size->C_ic);
    emxConvertDynamicMatrixToEmx__f(&emx->OMEGA_0, data->OMEGA_0, &size->OMEGA_0);
    emxConvertDynamicMatrixToEmx__f(&emx->C_is, data->C_is, &size->C_is);
    emxConvertDynamicMatrixToEmx__f(&emx->I_0, data->I_0, &size->I_0);
    emxConvertDynamicMatrixToEmx__f(&emx->C_rc, data->C_rc, &size->C_rc);
    emxConvertDynamicMatrixToEmx__f(&emx->omega, data->omega, &size->omega);
    emxConvertDynamicMatrixToEmx__f(&emx->OMEGADOT, data->OMEGADOT, &size->OMEGADOT);
    emxConvertDynamicMatrixToEmx__f(&emx->IDOT, data->IDOT, &size->IDOT);
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_br(boolean_T in1_data[], int32_T *in1_size, const
    gnssops_navigation_data *in2, const gnssops_navigation_data_size *in3, const uint16_T in4[40], int32_T in6)
{
    int32_T in1_size_idx_0;
    int32_T in4_0;
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    boolean_T in1_data_0[37];
    in4_0 = in4[in6];
    in1_size_idx_0 = in3->SVID == 1 ? *in1_size : in3->SVID;
    stride_0_0 = (*in1_size != 1);
    stride_1_0 = (in3->SVID != 1);
    loop_ub = in3->SVID == 1 ? *in1_size : in3->SVID;
    for (int32_T i{0}; i < loop_ub; i++)
    {
        in1_data_0[i] = (in1_data[i * stride_0_0] || (in2->SVID[i * stride_1_0] == in4_0));
    }

    *in1_size = in1_size_idx_0;
    if (in1_size_idx_0 - 1 >= 0)
    {
        std::memcpy(&in1_data[0], &in1_data_0[0], static_cast<uint32_T>(in1_size_idx_0) * sizeof(boolean_T));
    }
}

// Function for MATLAB Function: '<S18>/Simplify and Mask GAL Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPr_select_navigation_data_c(const emxArray__gnssops_navigation__T
    *navigation_data, const boolean_T mask_data[], const int32_T *mask_size, b_gnssops_navigation_data_GNS_T
    *navigation_data_selected, B_SimplifyandMaskGALMeasureme_T *localB)
{
    int32_T b_size_idx_0;
    int32_T end_tmp;
    int32_T trueCount;
    end_tmp = *mask_size - 1;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->b_data[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->TOW.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->TOW.data[trueCount] = navigation_data->TOW.data[localB->b_data[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->c_data[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->WNc.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->WNc.data[trueCount] = navigation_data->WNc.data[localB->c_data[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->d_data[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->SVID.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->SVID.data[trueCount] = navigation_data->SVID.data[localB->d_data[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->e_data[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->T_gd.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->T_gd.data[trueCount] = navigation_data->T_gd.data[localB->e_data[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->f_data_m[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->T_oc.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->T_oc.data[trueCount] = navigation_data->T_oc.data[localB->f_data_m[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->g_data[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->A_f2.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->A_f2.data[trueCount] = navigation_data->A_f2.data[localB->g_data[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->h_data_c[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->A_f1.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->A_f1.data[trueCount] = navigation_data->A_f1.data[localB->h_data_c[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->i_data[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->A_f0.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->A_f0.data[trueCount] = navigation_data->A_f0.data[localB->i_data[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->j_data[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->C_rs.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->C_rs.data[trueCount] = navigation_data->C_rs.data[localB->j_data[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->k_data[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->DELTA_N.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->DELTA_N.data[trueCount] = navigation_data->DELTA_N.data[localB->k_data[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->l_data_k[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->M_0.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->M_0.data[trueCount] = navigation_data->M_0.data[localB->l_data_k[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->m_data[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->C_uc.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->C_uc.data[trueCount] = navigation_data->C_uc.data[localB->m_data[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->n_data_c[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->E.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->E.data[trueCount] = navigation_data->E.data[localB->n_data_c[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->o_data[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->C_us.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->C_us.data[trueCount] = navigation_data->C_us.data[localB->o_data[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->p_data_b[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->SQRT_A.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->SQRT_A.data[trueCount] = navigation_data->SQRT_A.data[localB->p_data_b[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->q_data_p[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->T_oe.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->T_oe.data[trueCount] = navigation_data->T_oe.data[localB->q_data_p[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->r_data_c[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->C_ic.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->C_ic.data[trueCount] = navigation_data->C_ic.data[localB->r_data_c[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->s_data_f[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->OMEGA_0.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->OMEGA_0.data[trueCount] = navigation_data->OMEGA_0.data[localB->s_data_f[trueCount] -
            1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->t_data_g[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->C_is.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->C_is.data[trueCount] = navigation_data->C_is.data[localB->t_data_g[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->u_data_g[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->I_0.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->I_0.data[trueCount] = navigation_data->I_0.data[localB->u_data_g[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->v_data_m[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->C_rc.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->C_rc.data[trueCount] = navigation_data->C_rc.data[localB->v_data_m[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->w_data_n[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->omega.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->omega.data[trueCount] = navigation_data->omega.data[localB->w_data_n[trueCount] - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->x_data_p[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->OMEGADOT.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->OMEGADOT.data[trueCount] = navigation_data->OMEGADOT.data[localB->x_data_p[trueCount]
            - 1];
    }

    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            trueCount++;
        }
    }

    b_size_idx_0 = trueCount;
    trueCount = 0;
    for (int32_T b_i{0}; b_i <= end_tmp; b_i++)
    {
        if (mask_data[b_i])
        {
            localB->y_data_l[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->IDOT.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->IDOT.data[trueCount] = navigation_data->IDOT.data[localB->y_data_l[trueCount] - 1];
    }
}

//
// Output and update for atomic system:
//    '<S18>/Simplify and Mask GAL Measurement Bus'
//    '<S145>/Simplify and Mask GAL Measurement Bus'
//
void GNSSPreProcessingDualAntenna::SimplifyandMaskGALMeasurementBu(const gnssraw_measurement_t *rtu_GAL_Measurement_Bus,
    const gnssops_navigation_data *rtu_GAL_NavigationData_Bus, const gnssops_navigation_data_size
    *rtu_GAL_NavigationData_Bu_DIMS1, const parameters_galileo_t *rtu_parameters_galileo,
    B_SimplifyandMaskGALMeasureme_T *localB, DW_SimplifyandMaskGALMeasurem_T *localDW)
{
    static const int32_T gnss_frequency[5]
    {
        1575420000, 1176450000, 1207140000, 1191795000, 1
    };

    static const uint8_T lc[5]
    {
        17U, 20U, 21U, 22U, MAX_uint8_T
    };

    for (localB->trueCount = 0; localB->trueCount < 200; localB->trueCount++)
    {
        localB->e1_mask_data[localB->trueCount] = (rtu_GAL_Measurement_Bus->Type[localB->trueCount] == 17);
    }

    GNSSPreProcessingDualAnt_any_jj(localB->e1_mask_data, localB->mask_available_SV_data);
    for (localB->trueCount = 0; localB->trueCount < 200; localB->trueCount++)
    {
        localB->e1_mask_data[localB->trueCount] = (rtu_GAL_Measurement_Bus->Type[localB->trueCount] == 20);
    }

    GNSSPreProcessingDualAnt_any_jj(localB->e1_mask_data, localB->nc);
    for (localB->trueCount = 0; localB->trueCount < 200; localB->trueCount++)
    {
        localB->e1_mask_data[localB->trueCount] = (rtu_GAL_Measurement_Bus->Type[localB->trueCount] == 21);
    }

    GNSSPreProcessingDualAnt_any_jj(localB->e1_mask_data, localB->bv);
    for (localB->trueCount = 0; localB->trueCount < 40; localB->trueCount++)
    {
        localB->mc[localB->trueCount] = ((localB->mask_available_SV_data[localB->trueCount] &&
            rtu_parameters_galileo->enable_galileo_e1) || (localB->nc[localB->trueCount] &&
            rtu_parameters_galileo->enable_galileo_e5a) || (localB->bv[localB->trueCount] &&
            rtu_parameters_galileo->enable_galileo_e5b));
    }

    for (localB->trueCount = 0; localB->trueCount < 200; localB->trueCount++)
    {
        localB->e1_mask_data[localB->trueCount] = (rtu_GAL_Measurement_Bus->Type[localB->trueCount] == 22);
    }

    GNSSPreProcessingDualAnt_any_jj(localB->e1_mask_data, localB->mask_available_SV_data);
    for (localB->trueCount = 0; localB->trueCount < 40; localB->trueCount++)
    {
        localB->nc[localB->trueCount] = (localB->mask_available_SV_data[localB->trueCount] &&
            rtu_parameters_galileo->enable_galileo_e5);
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->trueCount++;
        }
    }

    localB->p_size_idx_1 = localB->trueCount;
    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->p_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->p_size_idx_1; localB->trueCount++)
    {
        localB->tmp_svid_data[localB->trueCount] = rtu_GAL_Measurement_Bus->SVID[localB->p_data[localB->trueCount] - 1];
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->trueCount++;
        }
    }

    localB->q_size_idx_1 = localB->trueCount;
    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->q_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->r_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->s_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->t_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->u_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->v_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->gnss_freq_Matrix_size[0] = 5;
    localB->gnss_freq_Matrix_size[1] = static_cast<int8_T>(localB->q_size_idx_1);
    localB->loop_ub = 5 * static_cast<int8_T>(localB->q_size_idx_1);
    for (localB->trueCount = 0; localB->trueCount < localB->loop_ub; localB->trueCount++)
    {
        localB->gnss_freq_Matrix_data[localB->trueCount] = 1.0;
    }

    for (localB->c_i = 0; localB->c_i < localB->q_size_idx_1; localB->c_i++)
    {
        for (localB->c_trueCount = 0; localB->c_trueCount < 5; localB->c_trueCount++)
        {
            localB->rtu_GAL_Measurement_Bus_j = rtu_GAL_Measurement_Bus->Type[(localB->q_data[localB->c_i] - 1) * 5 +
                localB->c_trueCount];
            for (localB->trueCount = 0; localB->trueCount < 5; localB->trueCount++)
            {
                localB->rtu_GAL_Measurement_Bus[localB->trueCount] = (localB->rtu_GAL_Measurement_Bus_j == lc
                    [localB->trueCount]);
            }

            GNSSPreProcessingDua_eml_find_h(localB->rtu_GAL_Measurement_Bus, localB->oc_data, localB->oc_size);
            if (localB->oc_size[1] != 0)
            {
                localB->gnss_freq_Matrix_data[localB->c_trueCount + 5 * localB->c_i] = gnss_frequency[localB->oc_data[0]
                    - 1];
            }
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->trueCount++;
        }
    }

    localB->w_size[0] = 1;
    localB->w_size[1] = localB->trueCount;
    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->w_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->mc[localB->c_i] || localB->nc[localB->c_i])
        {
            localB->x_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->a__1_size[0] = 1;
    localB->a__1_size[1] = localB->p_size_idx_1;
    if (localB->p_size_idx_1 - 1 >= 0)
    {
        std::memcpy(&localB->a__1_data[0], &localB->tmp_svid_data[0], static_cast<uint32_T>(localB->p_size_idx_1) *
                    sizeof(uint16_T));
    }

    GNSSPreProcessingDualAnt_sort_b(localB->a__1_data, localB->a__1_size, localB->iidx_data, localB->oc_size, localB);
    localB->loop_ub = localB->oc_size[1];
    for (localB->trueCount = 0; localB->trueCount < localB->loop_ub; localB->trueCount++)
    {
        localB->a__1_data[localB->trueCount] = localB->tmp_svid_data[localB->iidx_data[localB->trueCount] - 1];
    }

    localB->c_trueCount = localB->oc_size[1];
    localB->loop_ub = localB->oc_size[1];
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->tmp_svid_data[0], &localB->a__1_data[0], static_cast<uint32_T>(localB->loop_ub) * sizeof
                    (uint16_T));
    }

    if (localB->c_trueCount - 1 >= 0)
    {
        std::memset(&localB->mask_available_SV_data[0], 0, static_cast<uint32_T>(localB->c_trueCount) * sizeof(boolean_T));
    }

    for (localB->c_i = 0; localB->c_i < localB->c_trueCount; localB->c_i++)
    {
        localB->rtu_GAL_Measurement_Bus_j = localB->tmp_svid_data[localB->c_i];
        localB->mask_navdata_e1_size = rtu_GAL_NavigationData_Bu_DIMS1->SVID;
        localB->loop_ub = rtu_GAL_NavigationData_Bu_DIMS1->SVID;
        for (localB->trueCount = 0; localB->trueCount < localB->loop_ub; localB->trueCount++)
        {
            localB->mask_navdata_e1_data[localB->trueCount] = (rtu_GAL_NavigationData_Bus->SVID[localB->trueCount] ==
                localB->rtu_GAL_Measurement_Bus_j);
        }

        if (GNSSPreProcessingDualAn_any_jjs(localB->mask_navdata_e1_data, &localB->mask_navdata_e1_size))
        {
            localB->mask_available_SV_data[localB->c_i] = true;
        }
    }

    localB->c_trueCount_tmp = localB->oc_size[1] - 1;
    localB->c_i = 0;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->c_i++;
            localB->tmp_svid_data[localB->loop_ub] = localB->tmp_svid_data[localB->trueCount];
            localB->loop_ub++;
        }
    }

    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->loop_ub++;
        }
    }

    localB->p_size_idx_1 = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->y_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->p_size_idx_1; localB->trueCount++)
    {
        for (localB->c_trueCount = 0; localB->c_trueCount < 5; localB->c_trueCount++)
        {
            localB->tmp_type_data[localB->c_trueCount + 5 * localB->trueCount] = rtu_GAL_Measurement_Bus->Type
                [(localB->q_data[localB->iidx_data[localB->y_data[localB->trueCount] - 1] - 1] - 1) * 5 +
                localB->c_trueCount];
        }
    }

    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->loop_ub++;
        }
    }

    localB->rtu_GAL_Measurement_Bus_j = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->ab_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->rtu_GAL_Measurement_Bus_j; localB->trueCount++)
    {
        for (localB->c_trueCount = 0; localB->c_trueCount < 5; localB->c_trueCount++)
        {
            localB->tmp_pr_data[localB->c_trueCount + 5 * localB->trueCount] = rtu_GAL_Measurement_Bus->Pseudorange
                [(localB->r_data[localB->iidx_data[localB->ab_data[localB->trueCount] - 1] - 1] - 1) * 5 +
                localB->c_trueCount];
        }
    }

    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->loop_ub++;
        }
    }

    localB->rtu_GAL_Measurement_Bus_j = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->bb_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->rtu_GAL_Measurement_Bus_j; localB->trueCount++)
    {
        for (localB->c_trueCount = 0; localB->c_trueCount < 5; localB->c_trueCount++)
        {
            localB->tmp_pr_sigma_data[localB->c_trueCount + 5 * localB->trueCount] =
                rtu_GAL_Measurement_Bus->Pseudorange_Sigma[(localB->s_data[localB->iidx_data[localB->bb_data
                [localB->trueCount] - 1] - 1] - 1) * 5 + localB->c_trueCount];
        }
    }

    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->loop_ub++;
        }
    }

    localB->rtu_GAL_Measurement_Bus_j = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->cb_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->rtu_GAL_Measurement_Bus_j; localB->trueCount++)
    {
        for (localB->c_trueCount = 0; localB->c_trueCount < 5; localB->c_trueCount++)
        {
            localB->tmp_cp_data[localB->c_trueCount + 5 * localB->trueCount] = rtu_GAL_Measurement_Bus->Carrier
                [(localB->t_data[localB->iidx_data[localB->cb_data[localB->trueCount] - 1] - 1] - 1) * 5 +
                localB->c_trueCount];
        }
    }

    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->loop_ub++;
        }
    }

    localB->rtu_GAL_Measurement_Bus_j = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->db_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->rtu_GAL_Measurement_Bus_j; localB->trueCount++)
    {
        for (localB->c_trueCount = 0; localB->c_trueCount < 5; localB->c_trueCount++)
        {
            localB->tmp_cp_sigma_data[localB->c_trueCount + 5 * localB->trueCount] =
                rtu_GAL_Measurement_Bus->Carrier_Sigma[(localB->u_data[localB->iidx_data[localB->db_data
                [localB->trueCount] - 1] - 1] - 1) * 5 + localB->c_trueCount];
        }
    }

    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->loop_ub++;
        }
    }

    localB->rtu_GAL_Measurement_Bus_j = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->eb_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->rtu_GAL_Measurement_Bus_j; localB->trueCount++)
    {
        for (localB->c_trueCount = 0; localB->c_trueCount < 5; localB->c_trueCount++)
        {
            localB->tmp_locktime_data[localB->c_trueCount + 5 * localB->trueCount] = rtu_GAL_Measurement_Bus->Locktime
                [(localB->v_data[localB->iidx_data[localB->eb_data[localB->trueCount] - 1] - 1] - 1) * 5 +
                localB->c_trueCount];
        }
    }

    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->loop_ub++;
        }
    }

    localB->fb_size[0] = 1;
    localB->fb_size[1] = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->fb_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    if (localB->w_size[1] == static_cast<int8_T>(localB->q_size_idx_1))
    {
        localB->loop_ub = localB->fb_size[1];
        for (localB->trueCount = 0; localB->trueCount < localB->loop_ub; localB->trueCount++)
        {
            for (localB->c_trueCount = 0; localB->c_trueCount < 5; localB->c_trueCount++)
            {
                localB->rtu_GAL_Measurement_Bus_j = localB->iidx_data[localB->fb_data[localB->trueCount] - 1] - 1;
                localB->tmp_dr_data[localB->c_trueCount + 5 * localB->trueCount] = -rtu_GAL_Measurement_Bus->Doppler
                    [(localB->w_data[localB->rtu_GAL_Measurement_Bus_j] - 1) * 5 + localB->c_trueCount] * 2.99792458E+8 /
                    localB->gnss_freq_Matrix_data[5 * localB->rtu_GAL_Measurement_Bus_j + localB->c_trueCount];
            }
        }
    }
    else
    {
        GNSSPrePro_binary_expand_op_brs(localB->tmp_dr_data, localB->a__1_size, rtu_GAL_Measurement_Bus, localB->w_data,
            localB->w_size, localB->gnss_freq_Matrix_data, localB->gnss_freq_Matrix_size, localB->iidx_data,
            localB->fb_data, localB->fb_size, localB);
    }

    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->loop_ub++;
        }
    }

    localB->q_size_idx_1 = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->gb_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->q_size_idx_1; localB->trueCount++)
    {
        for (localB->c_trueCount = 0; localB->c_trueCount < 5; localB->c_trueCount++)
        {
            localB->gnss_freq_Matrix_data[localB->c_trueCount + 5 * localB->trueCount] = rtu_GAL_Measurement_Bus->CN0
                [(localB->x_data[localB->iidx_data[localB->gb_data[localB->trueCount] - 1] - 1] - 1) * 5 +
                localB->c_trueCount];
        }
    }

    localB->e1_mask_size[0] = 5;
    localB->e1_mask_size[1] = static_cast<int8_T>(localB->p_size_idx_1);
    localB->trueCount = 5 * static_cast<int8_T>(localB->p_size_idx_1);
    if (localB->trueCount - 1 >= 0)
    {
        std::memset(&localB->e1_mask_data[0], 0, static_cast<uint32_T>(localB->trueCount) * sizeof(boolean_T));
    }

    localB->e5a_mask_size[0] = 5;
    localB->e5a_mask_size[1] = static_cast<int8_T>(localB->p_size_idx_1);
    if (localB->trueCount - 1 >= 0)
    {
        std::memset(&localB->e5a_mask_data[0], 0, static_cast<uint32_T>(localB->trueCount) * sizeof(boolean_T));
    }

    localB->e5b_mask_size[0] = 5;
    localB->e5b_mask_size[1] = static_cast<int8_T>(localB->p_size_idx_1);
    if (localB->trueCount - 1 >= 0)
    {
        std::memset(&localB->e5b_mask_data[0], 0, static_cast<uint32_T>(localB->trueCount) * sizeof(boolean_T));
    }

    localB->e5_mask_size[0] = 5;
    localB->e5_mask_size[1] = static_cast<int8_T>(localB->p_size_idx_1);
    if (localB->trueCount - 1 >= 0)
    {
        std::memset(&localB->e5_mask_data[0], 0, static_cast<uint32_T>(localB->trueCount) * sizeof(boolean_T));
    }

    for (localB->c_trueCount = 0; localB->c_trueCount < localB->c_i; localB->c_trueCount++)
    {
        for (localB->trueCount = 0; localB->trueCount < 5; localB->trueCount++)
        {
            uint8_T tmp_type;
            localB->loop_ub = 5 * localB->c_trueCount + localB->trueCount;
            tmp_type = localB->tmp_type_data[localB->loop_ub];
            localB->e1_mask_data[localB->loop_ub] = (tmp_type == 17);
            localB->e5a_mask_data[localB->loop_ub] = (tmp_type == 20);
            localB->e5b_mask_data[localB->loop_ub] = (tmp_type == 21);
            localB->e5_mask_data[localB->trueCount + 5 * localB->c_trueCount] = (tmp_type == 22);
        }
    }

    GNSSPreProcessingDualA_any_jjst(localB->e1_mask_data, localB->e1_mask_size, localB->mask_available_SV_data,
        localB->gnss_freq_Matrix_size);
    localB->trueCount = localB->gnss_freq_Matrix_size[1] - 1;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS3 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->f_data[localB->c_trueCount] = localB->tmp_svid_data[localB->c_i];
            localB->c_trueCount++;
        }
    }

    if (localDW->SFunction_DIMS3 - 1 >= 0)
    {
        std::memcpy(&localB->a__1_data[0], &localB->f_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS3) * sizeof
                    (uint16_T));
    }

    if (localDW->SFunction_DIMS3 - 1 >= 0)
    {
        std::memcpy(&localB->svid_e1[0], &localB->a__1_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS3) * sizeof
                    (uint16_T));
    }

    localB->trueCount = 5 * static_cast<int8_T>(localB->p_size_idx_1) - 1;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS5 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->hb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS6 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->ib_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS9 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->jb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS10 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->kb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS11 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->lb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS7 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->mb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS8 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e1_mask_data[localB->c_i])
        {
            localB->nb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->mask_navdata_e1_size = rtu_GAL_NavigationData_Bu_DIMS1->SVID;
    localB->loop_ub = rtu_GAL_NavigationData_Bu_DIMS1->SVID;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memset(&localB->mask_navdata_e1_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(boolean_T));
    }

    for (localB->c_i = 0; localB->c_i < localDW->SFunction_DIMS3; localB->c_i++)
    {
        if (localB->mask_navdata_e1_size == rtu_GAL_NavigationData_Bu_DIMS1->SVID)
        {
            localB->trueCount = localB->svid_e1[localB->c_i];
            localB->loop_ub = localB->mask_navdata_e1_size;
            for (localB->c_trueCount = 0; localB->c_trueCount < localB->loop_ub; localB->c_trueCount++)
            {
                localB->mask_navdata_e1_data[localB->c_trueCount] = (localB->mask_navdata_e1_data[localB->c_trueCount] ||
                    (rtu_GAL_NavigationData_Bus->SVID[localB->c_trueCount] == localB->trueCount));
            }
        }
        else
        {
            GNSSPreProc_binary_expand_op_br(localB->mask_navdata_e1_data, &localB->mask_navdata_e1_size,
                rtu_GAL_NavigationData_Bus, rtu_GAL_NavigationData_Bu_DIMS1, localB->svid_e1, localB->c_i);
        }
    }

    localB->r4 = *rtu_GAL_NavigationData_Bus;
    emxConvertStructToEmx_gnssops_i(&localB->r, &localB->r4, rtu_GAL_NavigationData_Bu_DIMS1);
    GNSSPr_select_navigation_data_c(&localB->r, localB->mask_navdata_e1_data, &localB->mask_navdata_e1_size,
        &localB->expl_temp, localB);
    localDW->SFunction_DIMS4.TOW = localB->expl_temp.TOW.size;
    localB->loop_ub = localB->expl_temp.TOW.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.TOW[0], &localB->expl_temp.TOW.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS4.WNc = localB->expl_temp.WNc.size;
    localB->loop_ub = localB->expl_temp.WNc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.WNc[0], &localB->expl_temp.WNc.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS4.SVID = localB->expl_temp.SVID.size;
    localB->loop_ub = localB->expl_temp.SVID.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.SVID[0], &localB->expl_temp.SVID.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.T_gd = localB->expl_temp.T_gd.size;
    localB->loop_ub = localB->expl_temp.T_gd.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.T_gd[0], &localB->expl_temp.T_gd.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.T_oc = localB->expl_temp.T_oc.size;
    localB->loop_ub = localB->expl_temp.T_oc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.T_oc[0], &localB->expl_temp.T_oc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.A_f2 = localB->expl_temp.A_f2.size;
    localB->loop_ub = localB->expl_temp.A_f2.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.A_f2[0], &localB->expl_temp.A_f2.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.A_f1 = localB->expl_temp.A_f1.size;
    localB->loop_ub = localB->expl_temp.A_f1.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.A_f1[0], &localB->expl_temp.A_f1.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.A_f0 = localB->expl_temp.A_f0.size;
    localB->loop_ub = localB->expl_temp.A_f0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.A_f0[0], &localB->expl_temp.A_f0.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_rs = localB->expl_temp.C_rs.size;
    localB->loop_ub = localB->expl_temp.C_rs.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.C_rs[0], &localB->expl_temp.C_rs.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.DELTA_N = localB->expl_temp.DELTA_N.size;
    localB->loop_ub = localB->expl_temp.DELTA_N.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.DELTA_N[0], &localB->expl_temp.DELTA_N.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.M_0 = localB->expl_temp.M_0.size;
    localB->loop_ub = localB->expl_temp.M_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.M_0[0], &localB->expl_temp.M_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_uc = localB->expl_temp.C_uc.size;
    localB->loop_ub = localB->expl_temp.C_uc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.C_uc[0], &localB->expl_temp.C_uc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.E = localB->expl_temp.E.size;
    localB->loop_ub = localB->expl_temp.E.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.E[0], &localB->expl_temp.E.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_us = localB->expl_temp.C_us.size;
    localB->loop_ub = localB->expl_temp.C_us.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.C_us[0], &localB->expl_temp.C_us.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.SQRT_A = localB->expl_temp.SQRT_A.size;
    localB->loop_ub = localB->expl_temp.SQRT_A.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.SQRT_A[0], &localB->expl_temp.SQRT_A.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.T_oe = localB->expl_temp.T_oe.size;
    localB->loop_ub = localB->expl_temp.T_oe.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.T_oe[0], &localB->expl_temp.T_oe.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_ic = localB->expl_temp.C_ic.size;
    localB->loop_ub = localB->expl_temp.C_ic.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.C_ic[0], &localB->expl_temp.C_ic.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.OMEGA_0 = localB->expl_temp.OMEGA_0.size;
    localB->loop_ub = localB->expl_temp.OMEGA_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.OMEGA_0[0], &localB->expl_temp.OMEGA_0.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_is = localB->expl_temp.C_is.size;
    localB->loop_ub = localB->expl_temp.C_is.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.C_is[0], &localB->expl_temp.C_is.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.I_0 = localB->expl_temp.I_0.size;
    localB->loop_ub = localB->expl_temp.I_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.I_0[0], &localB->expl_temp.I_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_rc = localB->expl_temp.C_rc.size;
    localB->loop_ub = localB->expl_temp.C_rc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.C_rc[0], &localB->expl_temp.C_rc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.omega = localB->expl_temp.omega.size;
    localB->loop_ub = localB->expl_temp.omega.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.omega[0], &localB->expl_temp.omega.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.OMEGADOT = localB->expl_temp.OMEGADOT.size;
    localB->loop_ub = localB->expl_temp.OMEGADOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.OMEGADOT[0], &localB->expl_temp.OMEGADOT.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.IDOT = localB->expl_temp.IDOT.size;
    localB->loop_ub = localB->expl_temp.IDOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e1.IDOT[0], &localB->expl_temp.IDOT.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    GNSSPreProcessingDualA_any_jjst(localB->e5a_mask_data, localB->e5a_mask_size, localB->mask_available_SV_data,
        localB->gnss_freq_Matrix_size);
    localB->trueCount = localB->gnss_freq_Matrix_size[1] - 1;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS12 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->h_data[localB->c_trueCount] = localB->tmp_svid_data[localB->c_i];
            localB->c_trueCount++;
        }
    }

    if (localDW->SFunction_DIMS12 - 1 >= 0)
    {
        std::memcpy(&localB->a__1_data[0], &localB->h_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS12) * sizeof
                    (uint16_T));
    }

    if (localDW->SFunction_DIMS12 - 1 >= 0)
    {
        std::memcpy(&localB->svid_e5a[0], &localB->a__1_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS12) *
                    sizeof(uint16_T));
    }

    localB->trueCount = 5 * static_cast<int8_T>(localB->p_size_idx_1) - 1;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS14 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->ob_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->q_size_idx_1 = 5 * static_cast<int8_T>(localB->p_size_idx_1) - 1;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS15 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->pb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS18 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->qb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS19 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->rb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS20 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->sb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS16 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->tb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS17 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5a_mask_data[localB->c_i])
        {
            localB->ub_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->mask_navdata_e1_size = rtu_GAL_NavigationData_Bu_DIMS1->SVID;
    localB->loop_ub = rtu_GAL_NavigationData_Bu_DIMS1->SVID;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memset(&localB->mask_navdata_e1_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(boolean_T));
    }

    for (localB->c_i = 0; localB->c_i < localDW->SFunction_DIMS12; localB->c_i++)
    {
        if (localB->mask_navdata_e1_size == rtu_GAL_NavigationData_Bu_DIMS1->SVID)
        {
            localB->trueCount = localB->svid_e5a[localB->c_i];
            localB->loop_ub = localB->mask_navdata_e1_size;
            for (localB->c_trueCount = 0; localB->c_trueCount < localB->loop_ub; localB->c_trueCount++)
            {
                localB->mask_navdata_e1_data[localB->c_trueCount] = (localB->mask_navdata_e1_data[localB->c_trueCount] ||
                    (rtu_GAL_NavigationData_Bus->SVID[localB->c_trueCount] == localB->trueCount));
            }
        }
        else
        {
            GNSSPreProc_binary_expand_op_br(localB->mask_navdata_e1_data, &localB->mask_navdata_e1_size,
                rtu_GAL_NavigationData_Bus, rtu_GAL_NavigationData_Bu_DIMS1, localB->svid_e5a, localB->c_i);
        }
    }

    localB->r4 = *rtu_GAL_NavigationData_Bus;
    emxConvertStructToEmx_gnssops_i(&localB->r1, &localB->r4, rtu_GAL_NavigationData_Bu_DIMS1);
    GNSSPr_select_navigation_data_c(&localB->r1, localB->mask_navdata_e1_data, &localB->mask_navdata_e1_size,
        &localB->expl_temp, localB);
    localDW->SFunction_DIMS13.TOW = localB->expl_temp.TOW.size;
    localB->loop_ub = localB->expl_temp.TOW.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.TOW[0], &localB->expl_temp.TOW.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS13.WNc = localB->expl_temp.WNc.size;
    localB->loop_ub = localB->expl_temp.WNc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.WNc[0], &localB->expl_temp.WNc.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS13.SVID = localB->expl_temp.SVID.size;
    localB->loop_ub = localB->expl_temp.SVID.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.SVID[0], &localB->expl_temp.SVID.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.T_gd = localB->expl_temp.T_gd.size;
    localB->loop_ub = localB->expl_temp.T_gd.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.T_gd[0], &localB->expl_temp.T_gd.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.T_oc = localB->expl_temp.T_oc.size;
    localB->loop_ub = localB->expl_temp.T_oc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.T_oc[0], &localB->expl_temp.T_oc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.A_f2 = localB->expl_temp.A_f2.size;
    localB->loop_ub = localB->expl_temp.A_f2.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.A_f2[0], &localB->expl_temp.A_f2.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.A_f1 = localB->expl_temp.A_f1.size;
    localB->loop_ub = localB->expl_temp.A_f1.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.A_f1[0], &localB->expl_temp.A_f1.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.A_f0 = localB->expl_temp.A_f0.size;
    localB->loop_ub = localB->expl_temp.A_f0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.A_f0[0], &localB->expl_temp.A_f0.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_rs = localB->expl_temp.C_rs.size;
    localB->loop_ub = localB->expl_temp.C_rs.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.C_rs[0], &localB->expl_temp.C_rs.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.DELTA_N = localB->expl_temp.DELTA_N.size;
    localB->loop_ub = localB->expl_temp.DELTA_N.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.DELTA_N[0], &localB->expl_temp.DELTA_N.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.M_0 = localB->expl_temp.M_0.size;
    localB->loop_ub = localB->expl_temp.M_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.M_0[0], &localB->expl_temp.M_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_uc = localB->expl_temp.C_uc.size;
    localB->loop_ub = localB->expl_temp.C_uc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.C_uc[0], &localB->expl_temp.C_uc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.E = localB->expl_temp.E.size;
    localB->loop_ub = localB->expl_temp.E.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.E[0], &localB->expl_temp.E.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_us = localB->expl_temp.C_us.size;
    localB->loop_ub = localB->expl_temp.C_us.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.C_us[0], &localB->expl_temp.C_us.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.SQRT_A = localB->expl_temp.SQRT_A.size;
    localB->loop_ub = localB->expl_temp.SQRT_A.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.SQRT_A[0], &localB->expl_temp.SQRT_A.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.T_oe = localB->expl_temp.T_oe.size;
    localB->loop_ub = localB->expl_temp.T_oe.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.T_oe[0], &localB->expl_temp.T_oe.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_ic = localB->expl_temp.C_ic.size;
    localB->loop_ub = localB->expl_temp.C_ic.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.C_ic[0], &localB->expl_temp.C_ic.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.OMEGA_0 = localB->expl_temp.OMEGA_0.size;
    localB->loop_ub = localB->expl_temp.OMEGA_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.OMEGA_0[0], &localB->expl_temp.OMEGA_0.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_is = localB->expl_temp.C_is.size;
    localB->loop_ub = localB->expl_temp.C_is.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.C_is[0], &localB->expl_temp.C_is.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.I_0 = localB->expl_temp.I_0.size;
    localB->loop_ub = localB->expl_temp.I_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.I_0[0], &localB->expl_temp.I_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_rc = localB->expl_temp.C_rc.size;
    localB->loop_ub = localB->expl_temp.C_rc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.C_rc[0], &localB->expl_temp.C_rc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.omega = localB->expl_temp.omega.size;
    localB->loop_ub = localB->expl_temp.omega.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.omega[0], &localB->expl_temp.omega.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.OMEGADOT = localB->expl_temp.OMEGADOT.size;
    localB->loop_ub = localB->expl_temp.OMEGADOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.OMEGADOT[0], &localB->expl_temp.OMEGADOT.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.IDOT = localB->expl_temp.IDOT.size;
    localB->loop_ub = localB->expl_temp.IDOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5a.IDOT[0], &localB->expl_temp.IDOT.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    GNSSPreProcessingDualA_any_jjst(localB->e5b_mask_data, localB->e5b_mask_size, localB->mask_available_SV_data,
        localB->gnss_freq_Matrix_size);
    localB->trueCount = localB->gnss_freq_Matrix_size[1] - 1;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS21 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->l_data[localB->c_trueCount] = localB->tmp_svid_data[localB->c_i];
            localB->c_trueCount++;
        }
    }

    if (localDW->SFunction_DIMS21 - 1 >= 0)
    {
        std::memcpy(&localB->a__1_data[0], &localB->l_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS21) * sizeof
                    (uint16_T));
    }

    if (localDW->SFunction_DIMS21 - 1 >= 0)
    {
        std::memcpy(&localB->svid_e5b[0], &localB->a__1_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS21) *
                    sizeof(uint16_T));
    }

    localB->trueCount = 5 * static_cast<int8_T>(localB->p_size_idx_1) - 1;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS23 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->vb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS24 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->wb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS27 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->xb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS28 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->yb_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS29 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->ac_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS25 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->bc_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS26 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->e5b_mask_data[localB->c_i])
        {
            localB->cc_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->mask_navdata_e1_size = rtu_GAL_NavigationData_Bu_DIMS1->SVID;
    localB->loop_ub = rtu_GAL_NavigationData_Bu_DIMS1->SVID;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memset(&localB->mask_navdata_e1_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(boolean_T));
    }

    for (localB->c_i = 0; localB->c_i < localDW->SFunction_DIMS21; localB->c_i++)
    {
        if (localB->mask_navdata_e1_size == rtu_GAL_NavigationData_Bu_DIMS1->SVID)
        {
            localB->trueCount = localB->svid_e5b[localB->c_i];
            localB->loop_ub = localB->mask_navdata_e1_size;
            for (localB->c_trueCount = 0; localB->c_trueCount < localB->loop_ub; localB->c_trueCount++)
            {
                localB->mask_navdata_e1_data[localB->c_trueCount] = (localB->mask_navdata_e1_data[localB->c_trueCount] ||
                    (rtu_GAL_NavigationData_Bus->SVID[localB->c_trueCount] == localB->trueCount));
            }
        }
        else
        {
            GNSSPreProc_binary_expand_op_br(localB->mask_navdata_e1_data, &localB->mask_navdata_e1_size,
                rtu_GAL_NavigationData_Bus, rtu_GAL_NavigationData_Bu_DIMS1, localB->svid_e5b, localB->c_i);
        }
    }

    localB->r4 = *rtu_GAL_NavigationData_Bus;
    emxConvertStructToEmx_gnssops_i(&localB->r2, &localB->r4, rtu_GAL_NavigationData_Bu_DIMS1);
    GNSSPr_select_navigation_data_c(&localB->r2, localB->mask_navdata_e1_data, &localB->mask_navdata_e1_size,
        &localB->expl_temp, localB);
    localDW->SFunction_DIMS22.TOW = localB->expl_temp.TOW.size;
    localB->loop_ub = localB->expl_temp.TOW.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.TOW[0], &localB->expl_temp.TOW.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS22.WNc = localB->expl_temp.WNc.size;
    localB->loop_ub = localB->expl_temp.WNc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.WNc[0], &localB->expl_temp.WNc.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS22.SVID = localB->expl_temp.SVID.size;
    localB->loop_ub = localB->expl_temp.SVID.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.SVID[0], &localB->expl_temp.SVID.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.T_gd = localB->expl_temp.T_gd.size;
    localB->loop_ub = localB->expl_temp.T_gd.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.T_gd[0], &localB->expl_temp.T_gd.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.T_oc = localB->expl_temp.T_oc.size;
    localB->loop_ub = localB->expl_temp.T_oc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.T_oc[0], &localB->expl_temp.T_oc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.A_f2 = localB->expl_temp.A_f2.size;
    localB->loop_ub = localB->expl_temp.A_f2.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.A_f2[0], &localB->expl_temp.A_f2.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.A_f1 = localB->expl_temp.A_f1.size;
    localB->loop_ub = localB->expl_temp.A_f1.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.A_f1[0], &localB->expl_temp.A_f1.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.A_f0 = localB->expl_temp.A_f0.size;
    localB->loop_ub = localB->expl_temp.A_f0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.A_f0[0], &localB->expl_temp.A_f0.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_rs = localB->expl_temp.C_rs.size;
    localB->loop_ub = localB->expl_temp.C_rs.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.C_rs[0], &localB->expl_temp.C_rs.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.DELTA_N = localB->expl_temp.DELTA_N.size;
    localB->loop_ub = localB->expl_temp.DELTA_N.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.DELTA_N[0], &localB->expl_temp.DELTA_N.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.M_0 = localB->expl_temp.M_0.size;
    localB->loop_ub = localB->expl_temp.M_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.M_0[0], &localB->expl_temp.M_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_uc = localB->expl_temp.C_uc.size;
    localB->loop_ub = localB->expl_temp.C_uc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.C_uc[0], &localB->expl_temp.C_uc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.E = localB->expl_temp.E.size;
    localB->loop_ub = localB->expl_temp.E.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.E[0], &localB->expl_temp.E.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_us = localB->expl_temp.C_us.size;
    localB->loop_ub = localB->expl_temp.C_us.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.C_us[0], &localB->expl_temp.C_us.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.SQRT_A = localB->expl_temp.SQRT_A.size;
    localB->loop_ub = localB->expl_temp.SQRT_A.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.SQRT_A[0], &localB->expl_temp.SQRT_A.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.T_oe = localB->expl_temp.T_oe.size;
    localB->loop_ub = localB->expl_temp.T_oe.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.T_oe[0], &localB->expl_temp.T_oe.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_ic = localB->expl_temp.C_ic.size;
    localB->loop_ub = localB->expl_temp.C_ic.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.C_ic[0], &localB->expl_temp.C_ic.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.OMEGA_0 = localB->expl_temp.OMEGA_0.size;
    localB->loop_ub = localB->expl_temp.OMEGA_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.OMEGA_0[0], &localB->expl_temp.OMEGA_0.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_is = localB->expl_temp.C_is.size;
    localB->loop_ub = localB->expl_temp.C_is.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.C_is[0], &localB->expl_temp.C_is.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.I_0 = localB->expl_temp.I_0.size;
    localB->loop_ub = localB->expl_temp.I_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.I_0[0], &localB->expl_temp.I_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_rc = localB->expl_temp.C_rc.size;
    localB->loop_ub = localB->expl_temp.C_rc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.C_rc[0], &localB->expl_temp.C_rc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.omega = localB->expl_temp.omega.size;
    localB->loop_ub = localB->expl_temp.omega.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.omega[0], &localB->expl_temp.omega.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.OMEGADOT = localB->expl_temp.OMEGADOT.size;
    localB->loop_ub = localB->expl_temp.OMEGADOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.OMEGADOT[0], &localB->expl_temp.OMEGADOT.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.IDOT = localB->expl_temp.IDOT.size;
    localB->loop_ub = localB->expl_temp.IDOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5b.IDOT[0], &localB->expl_temp.IDOT.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    GNSSPreProcessingDualA_any_jjst(localB->e5_mask_data, localB->e5_mask_size, localB->mask_available_SV_data,
        localB->gnss_freq_Matrix_size);
    localB->trueCount = localB->gnss_freq_Matrix_size[1] - 1;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS30 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->n_data[localB->c_trueCount] = localB->tmp_svid_data[localB->c_i];
            localB->c_trueCount++;
        }
    }

    if (localDW->SFunction_DIMS30 - 1 >= 0)
    {
        std::memcpy(&localB->a__1_data[0], &localB->n_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS30) * sizeof
                    (uint16_T));
    }

    if (localDW->SFunction_DIMS30 - 1 >= 0)
    {
        std::memcpy(&localB->svid_e5[0], &localB->a__1_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS30) *
                    sizeof(uint16_T));
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS32 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->dc_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS33 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->ec_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS36 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->fc_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS37 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->gc_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS38 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->hc_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS34 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->ic_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->c_trueCount++;
        }
    }

    localDW->SFunction_DIMS35 = localB->c_trueCount;
    localB->c_trueCount = 0;
    for (localB->c_i = 0; localB->c_i <= localB->q_size_idx_1; localB->c_i++)
    {
        if (localB->e5_mask_data[localB->c_i])
        {
            localB->jc_data[localB->c_trueCount] = static_cast<uint8_T>(localB->c_i + 1);
            localB->c_trueCount++;
        }
    }

    localB->mask_navdata_e1_size = rtu_GAL_NavigationData_Bu_DIMS1->SVID;
    localB->loop_ub = rtu_GAL_NavigationData_Bu_DIMS1->SVID;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memset(&localB->mask_navdata_e1_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(boolean_T));
    }

    for (localB->c_i = 0; localB->c_i < localDW->SFunction_DIMS30; localB->c_i++)
    {
        if (localB->mask_navdata_e1_size == rtu_GAL_NavigationData_Bu_DIMS1->SVID)
        {
            localB->trueCount = localB->svid_e5[localB->c_i];
            localB->loop_ub = localB->mask_navdata_e1_size;
            for (localB->c_trueCount = 0; localB->c_trueCount < localB->loop_ub; localB->c_trueCount++)
            {
                localB->mask_navdata_e1_data[localB->c_trueCount] = (localB->mask_navdata_e1_data[localB->c_trueCount] ||
                    (rtu_GAL_NavigationData_Bus->SVID[localB->c_trueCount] == localB->trueCount));
            }
        }
        else
        {
            GNSSPreProc_binary_expand_op_br(localB->mask_navdata_e1_data, &localB->mask_navdata_e1_size,
                rtu_GAL_NavigationData_Bus, rtu_GAL_NavigationData_Bu_DIMS1, localB->svid_e5, localB->c_i);
        }
    }

    localB->r4 = *rtu_GAL_NavigationData_Bus;
    emxConvertStructToEmx_gnssops_i(&localB->r3, &localB->r4, rtu_GAL_NavigationData_Bu_DIMS1);
    GNSSPr_select_navigation_data_c(&localB->r3, localB->mask_navdata_e1_data, &localB->mask_navdata_e1_size,
        &localB->expl_temp, localB);
    localDW->SFunction_DIMS31.TOW = localB->expl_temp.TOW.size;
    localB->loop_ub = localB->expl_temp.TOW.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.TOW[0], &localB->expl_temp.TOW.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS31.WNc = localB->expl_temp.WNc.size;
    localB->loop_ub = localB->expl_temp.WNc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.WNc[0], &localB->expl_temp.WNc.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS31.SVID = localB->expl_temp.SVID.size;
    localB->loop_ub = localB->expl_temp.SVID.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.SVID[0], &localB->expl_temp.SVID.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.T_gd = localB->expl_temp.T_gd.size;
    localB->loop_ub = localB->expl_temp.T_gd.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.T_gd[0], &localB->expl_temp.T_gd.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.T_oc = localB->expl_temp.T_oc.size;
    localB->loop_ub = localB->expl_temp.T_oc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.T_oc[0], &localB->expl_temp.T_oc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.A_f2 = localB->expl_temp.A_f2.size;
    localB->loop_ub = localB->expl_temp.A_f2.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.A_f2[0], &localB->expl_temp.A_f2.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.A_f1 = localB->expl_temp.A_f1.size;
    localB->loop_ub = localB->expl_temp.A_f1.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.A_f1[0], &localB->expl_temp.A_f1.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.A_f0 = localB->expl_temp.A_f0.size;
    localB->loop_ub = localB->expl_temp.A_f0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.A_f0[0], &localB->expl_temp.A_f0.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.C_rs = localB->expl_temp.C_rs.size;
    localB->loop_ub = localB->expl_temp.C_rs.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.C_rs[0], &localB->expl_temp.C_rs.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.DELTA_N = localB->expl_temp.DELTA_N.size;
    localB->loop_ub = localB->expl_temp.DELTA_N.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.DELTA_N[0], &localB->expl_temp.DELTA_N.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.M_0 = localB->expl_temp.M_0.size;
    localB->loop_ub = localB->expl_temp.M_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.M_0[0], &localB->expl_temp.M_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS31.C_uc = localB->expl_temp.C_uc.size;
    localB->loop_ub = localB->expl_temp.C_uc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.C_uc[0], &localB->expl_temp.C_uc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.E = localB->expl_temp.E.size;
    localB->loop_ub = localB->expl_temp.E.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.E[0], &localB->expl_temp.E.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS31.C_us = localB->expl_temp.C_us.size;
    localB->loop_ub = localB->expl_temp.C_us.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.C_us[0], &localB->expl_temp.C_us.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.SQRT_A = localB->expl_temp.SQRT_A.size;
    localB->loop_ub = localB->expl_temp.SQRT_A.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.SQRT_A[0], &localB->expl_temp.SQRT_A.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.T_oe = localB->expl_temp.T_oe.size;
    localB->loop_ub = localB->expl_temp.T_oe.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.T_oe[0], &localB->expl_temp.T_oe.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.C_ic = localB->expl_temp.C_ic.size;
    localB->loop_ub = localB->expl_temp.C_ic.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.C_ic[0], &localB->expl_temp.C_ic.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.OMEGA_0 = localB->expl_temp.OMEGA_0.size;
    localB->loop_ub = localB->expl_temp.OMEGA_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.OMEGA_0[0], &localB->expl_temp.OMEGA_0.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.C_is = localB->expl_temp.C_is.size;
    localB->loop_ub = localB->expl_temp.C_is.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.C_is[0], &localB->expl_temp.C_is.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.I_0 = localB->expl_temp.I_0.size;
    localB->loop_ub = localB->expl_temp.I_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.I_0[0], &localB->expl_temp.I_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS31.C_rc = localB->expl_temp.C_rc.size;
    localB->loop_ub = localB->expl_temp.C_rc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.C_rc[0], &localB->expl_temp.C_rc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.omega = localB->expl_temp.omega.size;
    localB->loop_ub = localB->expl_temp.omega.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.omega[0], &localB->expl_temp.omega.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.OMEGADOT = localB->expl_temp.OMEGADOT.size;
    localB->loop_ub = localB->expl_temp.OMEGADOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.OMEGADOT[0], &localB->expl_temp.OMEGADOT.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS31.IDOT = localB->expl_temp.IDOT.size;
    localB->loop_ub = localB->expl_temp.IDOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_e5.IDOT[0], &localB->expl_temp.IDOT.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localB->TOW = rtu_GAL_Measurement_Bus->TOW;
    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS5; localB->trueCount++)
    {
        localB->pr_e1[localB->trueCount] = localB->tmp_pr_data[localB->hb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS6; localB->trueCount++)
    {
        localB->pr_e1_sigma[localB->trueCount] = localB->tmp_pr_sigma_data[localB->ib_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS7; localB->trueCount++)
    {
        localB->dr_e1[localB->trueCount] = localB->tmp_dr_data[localB->mb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS8; localB->trueCount++)
    {
        localB->cn0_e1[localB->trueCount] = localB->gnss_freq_Matrix_data[localB->nb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS9; localB->trueCount++)
    {
        localB->cp_e1[localB->trueCount] = localB->tmp_cp_data[localB->jb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS10; localB->trueCount++)
    {
        localB->cp_e1_sigma[localB->trueCount] = localB->tmp_cp_sigma_data[localB->kb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS11; localB->trueCount++)
    {
        localB->locktime_e1[localB->trueCount] = localB->tmp_locktime_data[localB->lb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS14; localB->trueCount++)
    {
        localB->pr_e5a[localB->trueCount] = localB->tmp_pr_data[localB->ob_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS15; localB->trueCount++)
    {
        localB->pr_e5a_sigma[localB->trueCount] = localB->tmp_pr_data[localB->pb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS16; localB->trueCount++)
    {
        localB->dr_e5a[localB->trueCount] = localB->tmp_dr_data[localB->tb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS17; localB->trueCount++)
    {
        localB->cn0_e5a[localB->trueCount] = localB->gnss_freq_Matrix_data[localB->ub_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS18; localB->trueCount++)
    {
        localB->cp_e5a[localB->trueCount] = localB->tmp_cp_data[localB->qb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS19; localB->trueCount++)
    {
        localB->cp_e5a_sigma[localB->trueCount] = localB->tmp_cp_data[localB->rb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS20; localB->trueCount++)
    {
        localB->locktime_e5a[localB->trueCount] = localB->tmp_locktime_data[localB->sb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS23; localB->trueCount++)
    {
        localB->pr_e5b[localB->trueCount] = localB->tmp_pr_data[localB->vb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS24; localB->trueCount++)
    {
        localB->pr_e5b_sigma[localB->trueCount] = localB->tmp_pr_sigma_data[localB->wb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS25; localB->trueCount++)
    {
        localB->dr_e5b[localB->trueCount] = localB->tmp_dr_data[localB->bc_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS26; localB->trueCount++)
    {
        localB->cn0_e5b[localB->trueCount] = localB->gnss_freq_Matrix_data[localB->cc_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS27; localB->trueCount++)
    {
        localB->cp_e5b[localB->trueCount] = localB->tmp_cp_data[localB->xb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS28; localB->trueCount++)
    {
        localB->cp_e5b_sigma[localB->trueCount] = localB->tmp_cp_sigma_data[localB->yb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS29; localB->trueCount++)
    {
        localB->locktime_e5b[localB->trueCount] = localB->tmp_locktime_data[localB->ac_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS32; localB->trueCount++)
    {
        localB->pr_e5[localB->trueCount] = localB->tmp_pr_data[localB->dc_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS33; localB->trueCount++)
    {
        localB->pr_e5_sigma[localB->trueCount] = localB->tmp_pr_sigma_data[localB->ec_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS34; localB->trueCount++)
    {
        localB->dr_e5[localB->trueCount] = localB->tmp_dr_data[localB->ic_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS35; localB->trueCount++)
    {
        localB->cn0_e5[localB->trueCount] = localB->gnss_freq_Matrix_data[localB->jc_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS36; localB->trueCount++)
    {
        localB->cp_e5[localB->trueCount] = localB->tmp_cp_data[localB->fc_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS37; localB->trueCount++)
    {
        localB->cp_e5_sigma[localB->trueCount] = localB->tmp_cp_sigma_data[localB->gc_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS38; localB->trueCount++)
    {
        localB->locktime_e5[localB->trueCount] = localB->tmp_locktime_data[localB->hc_data[localB->trueCount] - 1];
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
