//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SimplifyandMaskGPSMeasurementBu.cpp
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
#include "SimplifyandMaskGPSMeasurementBu.h"

// Function for MATLAB Function: '<S17>/Simplify and Mask GPS Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAnt_any_jv(const boolean_T x[200], boolean_T y[40])
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

// Function for MATLAB Function: '<S17>/Simplify and Mask GPS Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualA_eml_find(const boolean_T x[4], int32_T i_data[], int32_T
    i_size[2])
{
    int32_T idx;
    int32_T ii;
    boolean_T exitg1;
    idx = 0;
    i_size[0] = 1;
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii < 4))
    {
        if (x[ii])
        {
            idx++;
            i_data[idx - 1] = ii + 1;
            if (idx >= 4)
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

// Function for MATLAB Function: '<S17>/Simplify and Mask GPS Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAn_merge_o(int32_T idx_data[], uint16_T x_data[], int32_T offset,
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

// Function for MATLAB Function: '<S17>/Simplify and Mask GPS Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAnt_sort_m(uint16_T x_data[], int32_T x_size[2], int32_T
    idx_data[], int32_T idx_size[2], B_SimplifyandMaskGPSMeasureme_T *localB)
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
                        GNSSPreProcessingDualAn_merge_o(idx_data, localB->b_x_data, i2, nDone, i - nDone,
                            localB->iwork_data, localB->xwork_data);
                    }
                }

                i = nDone << 1;
                nLeft >>= 1;
                for (i2 = 0; i2 < nLeft; i2++)
                {
                    GNSSPreProcessingDualAn_merge_o(idx_data, localB->b_x_data, i2 * i, nDone, nDone, localB->iwork_data,
                        localB->xwork_data);
                }

                nDone = i;
            }

            if (x_size[1] > nDone)
            {
                GNSSPreProcessingDualAn_merge_o(idx_data, localB->b_x_data, 0, nDone, x_size[1] - nDone,
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

// Function for MATLAB Function: '<S17>/Simplify and Mask GPS Measurement Bus'
boolean_T GNSSPreProcessingDualAntenna::GNSSPreProcessingDualAn_any_jvg(const boolean_T x_data[], const int32_T *x_size)
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

void GNSSPreProcessingDualAntenna::GNSSPrePro_binary_expand_op_jbw(real_T in1_data[], int32_T in1_size[2], const
    gnssraw_measurement_t *in2, const int8_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], const int32_T in5_data[], const int8_T in6_data[], const int32_T in6_size[2],
    B_SimplifyandMaskGPSMeasureme_T *localB)
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

// Function for MATLAB Function: '<S17>/Simplify and Mask GPS Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPreProcessingDualA_any_jvgx(const boolean_T x_data[], const int32_T x_size[2],
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

void GNSSPreProcessingDualAntenna::emxConvertDynamicMatrixToEmx_37(emxArray_real_T_37_GNSSPrePro_T *emx, const real_T
    data[37], const int32_T *size)
{
    std::memcpy(&emx->data, (void *)data, sizeof(real_T) * static_cast<uint32_T>(*size));
    std::memcpy(&emx->size, (void *)size, sizeof(int32_T));
}

void GNSSPreProcessingDualAntenna::emxConvertStructToEmx_gnssops_n(emxArray__gnssops_navigation__T *emx, const
    gnssops_navigation_data *data, const gnssops_navigation_data_size *size)
{
    emxConvertDynamicMatrixToEmx_37(&emx->TOW, data->TOW, &size->TOW);
    emxConvertDynamicMatrixToEmx_37(&emx->WNc, data->WNc, &size->WNc);
    emxConvertDynamicMatrixToEmx_37(&emx->SVID, data->SVID, &size->SVID);
    emxConvertDynamicMatrixToEmx_37(&emx->T_gd, data->T_gd, &size->T_gd);
    emxConvertDynamicMatrixToEmx_37(&emx->T_oc, data->T_oc, &size->T_oc);
    emxConvertDynamicMatrixToEmx_37(&emx->A_f2, data->A_f2, &size->A_f2);
    emxConvertDynamicMatrixToEmx_37(&emx->A_f1, data->A_f1, &size->A_f1);
    emxConvertDynamicMatrixToEmx_37(&emx->A_f0, data->A_f0, &size->A_f0);
    emxConvertDynamicMatrixToEmx_37(&emx->C_rs, data->C_rs, &size->C_rs);
    emxConvertDynamicMatrixToEmx_37(&emx->DELTA_N, data->DELTA_N, &size->DELTA_N);
    emxConvertDynamicMatrixToEmx_37(&emx->M_0, data->M_0, &size->M_0);
    emxConvertDynamicMatrixToEmx_37(&emx->C_uc, data->C_uc, &size->C_uc);
    emxConvertDynamicMatrixToEmx_37(&emx->E, data->E, &size->E);
    emxConvertDynamicMatrixToEmx_37(&emx->C_us, data->C_us, &size->C_us);
    emxConvertDynamicMatrixToEmx_37(&emx->SQRT_A, data->SQRT_A, &size->SQRT_A);
    emxConvertDynamicMatrixToEmx_37(&emx->T_oe, data->T_oe, &size->T_oe);
    emxConvertDynamicMatrixToEmx_37(&emx->C_ic, data->C_ic, &size->C_ic);
    emxConvertDynamicMatrixToEmx_37(&emx->OMEGA_0, data->OMEGA_0, &size->OMEGA_0);
    emxConvertDynamicMatrixToEmx_37(&emx->C_is, data->C_is, &size->C_is);
    emxConvertDynamicMatrixToEmx_37(&emx->I_0, data->I_0, &size->I_0);
    emxConvertDynamicMatrixToEmx_37(&emx->C_rc, data->C_rc, &size->C_rc);
    emxConvertDynamicMatrixToEmx_37(&emx->omega, data->omega, &size->omega);
    emxConvertDynamicMatrixToEmx_37(&emx->OMEGADOT, data->OMEGADOT, &size->OMEGADOT);
    emxConvertDynamicMatrixToEmx_37(&emx->IDOT, data->IDOT, &size->IDOT);
}

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_jb(boolean_T in1_data[], int32_T *in1_size, const
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

// Function for MATLAB Function: '<S17>/Simplify and Mask GPS Measurement Bus'
void GNSSPreProcessingDualAntenna::GNSSPreP_select_navigation_data(const emxArray__gnssops_navigation__T
    *navigation_data, const boolean_T mask_data[], const int32_T *mask_size, b_gnssops_navigation_data_GNS_T
    *navigation_data_selected, B_SimplifyandMaskGPSMeasureme_T *localB)
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
            localB->o_data_b[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->C_us.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->C_us.data[trueCount] = navigation_data->C_us.data[localB->o_data_b[trueCount] - 1];
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
            localB->p_data_p[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->SQRT_A.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->SQRT_A.data[trueCount] = navigation_data->SQRT_A.data[localB->p_data_p[trueCount] - 1];
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
            localB->q_data_c[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->T_oe.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->T_oe.data[trueCount] = navigation_data->T_oe.data[localB->q_data_c[trueCount] - 1];
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
            localB->r_data_f[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->C_ic.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->C_ic.data[trueCount] = navigation_data->C_ic.data[localB->r_data_f[trueCount] - 1];
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
            localB->s_data_g[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->OMEGA_0.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->OMEGA_0.data[trueCount] = navigation_data->OMEGA_0.data[localB->s_data_g[trueCount] -
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
            localB->u_data_m[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->I_0.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->I_0.data[trueCount] = navigation_data->I_0.data[localB->u_data_m[trueCount] - 1];
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
            localB->v_data_n[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->C_rc.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->C_rc.data[trueCount] = navigation_data->C_rc.data[localB->v_data_n[trueCount] - 1];
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
            localB->w_data_p[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->omega.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->omega.data[trueCount] = navigation_data->omega.data[localB->w_data_p[trueCount] - 1];
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
            localB->x_data_l[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->OMEGADOT.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->OMEGADOT.data[trueCount] = navigation_data->OMEGADOT.data[localB->x_data_l[trueCount]
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
            localB->y_data_j[trueCount] = static_cast<int8_T>(b_i + 1);
            trueCount++;
        }
    }

    navigation_data_selected->IDOT.size = b_size_idx_0;
    for (trueCount = 0; trueCount < b_size_idx_0; trueCount++)
    {
        navigation_data_selected->IDOT.data[trueCount] = navigation_data->IDOT.data[localB->y_data_j[trueCount] - 1];
    }
}

//
// Output and update for atomic system:
//    '<S17>/Simplify and Mask GPS Measurement Bus'
//    '<S144>/Simplify and Mask GPS Measurement Bus'
//
void GNSSPreProcessingDualAntenna::SimplifyandMaskGPSMeasurementBu(const gnssraw_measurement_t *rtu_GpsMeasurementBus,
    const gnssops_navigation_data *rtu_GpsNavBusReshaped, const gnssops_navigation_data_size
    *rtu_GpsNavBusReshaped_DIMS1, const parameters_gps_t *rtu_parameters_gps_Bus, B_SimplifyandMaskGPSMeasureme_T
    *localB, DW_SimplifyandMaskGPSMeasurem_T *localDW)
{
    static const int32_T gnss_frequency[4]
    {
        1575420000, 1227600000, 1176450000, 1
    };

    for (localB->trueCount = 0; localB->trueCount < 200; localB->trueCount++)
    {
        localB->L1_mask_data[localB->trueCount] = (rtu_GpsMeasurementBus->Type[localB->trueCount] == 0);
    }

    GNSSPreProcessingDualAnt_any_jv(localB->L1_mask_data, localB->mask_available_SV_data);
    for (localB->trueCount = 0; localB->trueCount < 200; localB->trueCount++)
    {
        localB->L1_mask_data[localB->trueCount] = (rtu_GpsMeasurementBus->Type[localB->trueCount] == 3);
    }

    GNSSPreProcessingDualAnt_any_jv(localB->L1_mask_data, localB->bv);
    for (localB->trueCount = 0; localB->trueCount < 40; localB->trueCount++)
    {
        localB->dc[localB->trueCount] = ((localB->mask_available_SV_data[localB->trueCount] &&
            rtu_parameters_gps_Bus->enable_gps_l1) || (localB->bv[localB->trueCount] &&
            rtu_parameters_gps_Bus->enable_gps_l2));
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->trueCount++;
        }
    }

    localB->n_size_idx_1 = localB->trueCount;
    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->n_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->n_size_idx_1; localB->trueCount++)
    {
        localB->tmp_svid_data[localB->trueCount] = rtu_GpsMeasurementBus->SVID[localB->n_data[localB->trueCount] - 1];
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->trueCount++;
        }
    }

    localB->o_size_idx_1 = localB->trueCount;
    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->o_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->p_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->q_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->r_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->s_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->t_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->gnss_freq_Matrix_size[0] = 5;
    localB->gnss_freq_Matrix_size[1] = static_cast<int8_T>(localB->o_size_idx_1);
    localB->loop_ub = 5 * static_cast<int8_T>(localB->o_size_idx_1);
    for (localB->trueCount = 0; localB->trueCount < localB->loop_ub; localB->trueCount++)
    {
        localB->gnss_freq_Matrix_data[localB->trueCount] = 1.0;
    }

    for (localB->c_i = 0; localB->c_i < localB->o_size_idx_1; localB->c_i++)
    {
        for (localB->trueCount = 0; localB->trueCount < 5; localB->trueCount++)
        {
            localB->loop_ub = rtu_GpsMeasurementBus->Type[(localB->o_data[localB->c_i] - 1) * 5 + localB->trueCount];
            localB->rtu_GpsMeasurementBus[0] = (localB->loop_ub == 0);
            localB->rtu_GpsMeasurementBus[1] = (localB->loop_ub == 3);
            localB->rtu_GpsMeasurementBus[2] = (localB->loop_ub == 4);
            localB->rtu_GpsMeasurementBus[3] = (localB->loop_ub == 255);
            GNSSPreProcessingDualA_eml_find(localB->rtu_GpsMeasurementBus, localB->ec_data, localB->ec_size);
            if (localB->ec_size[1] != 0)
            {
                localB->gnss_freq_Matrix_data[localB->trueCount + 5 * localB->c_i] = gnss_frequency[localB->ec_data[0] -
                    1];
            }
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->trueCount++;
        }
    }

    localB->u_size[0] = 1;
    localB->u_size[1] = localB->trueCount;
    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->u_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->trueCount = 0;
    for (localB->c_i = 0; localB->c_i < 40; localB->c_i++)
    {
        if (localB->dc[localB->c_i])
        {
            localB->v_data[localB->trueCount] = static_cast<int8_T>(localB->c_i + 1);
            localB->trueCount++;
        }
    }

    localB->a__1_size[0] = 1;
    localB->a__1_size[1] = localB->n_size_idx_1;
    if (localB->n_size_idx_1 - 1 >= 0)
    {
        std::memcpy(&localB->a__1_data[0], &localB->tmp_svid_data[0], static_cast<uint32_T>(localB->n_size_idx_1) *
                    sizeof(uint16_T));
    }

    GNSSPreProcessingDualAnt_sort_m(localB->a__1_data, localB->a__1_size, localB->iidx_data, localB->ec_size, localB);
    localB->loop_ub = localB->ec_size[1];
    for (localB->trueCount = 0; localB->trueCount < localB->loop_ub; localB->trueCount++)
    {
        localB->a__1_data[localB->trueCount] = localB->tmp_svid_data[localB->iidx_data[localB->trueCount] - 1];
    }

    localB->n_size_idx_1 = localB->ec_size[1];
    localB->loop_ub = localB->ec_size[1];
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->tmp_svid_data[0], &localB->a__1_data[0], static_cast<uint32_T>(localB->loop_ub) * sizeof
                    (uint16_T));
    }

    if (localB->n_size_idx_1 - 1 >= 0)
    {
        std::memset(&localB->mask_available_SV_data[0], 0, static_cast<uint32_T>(localB->n_size_idx_1) * sizeof
                    (boolean_T));
    }

    for (localB->c_i = 0; localB->c_i < localB->n_size_idx_1; localB->c_i++)
    {
        localB->tmp_svid = localB->tmp_svid_data[localB->c_i];
        localB->mask_navdata_L1_size = rtu_GpsNavBusReshaped_DIMS1->SVID;
        localB->loop_ub = rtu_GpsNavBusReshaped_DIMS1->SVID;
        for (localB->trueCount = 0; localB->trueCount < localB->loop_ub; localB->trueCount++)
        {
            localB->mask_navdata_L1_data[localB->trueCount] = (rtu_GpsNavBusReshaped->SVID[localB->trueCount] ==
                localB->tmp_svid);
        }

        if (GNSSPreProcessingDualAn_any_jvg(localB->mask_navdata_L1_data, &localB->mask_navdata_L1_size))
        {
            localB->mask_available_SV_data[localB->c_i] = true;
        }
    }

    localB->c_trueCount_tmp = localB->ec_size[1] - 1;
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

    localB->w_size_idx_1 = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->w_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->w_size_idx_1; localB->trueCount++)
    {
        for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < 5; localB->n_size_idx_1++)
        {
            localB->tmp_type_data[localB->n_size_idx_1 + 5 * localB->trueCount] = rtu_GpsMeasurementBus->Type
                [(localB->o_data[localB->iidx_data[localB->w_data[localB->trueCount] - 1] - 1] - 1) * 5 +
                localB->n_size_idx_1];
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

    localB->tmp_svid = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->x_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->tmp_svid; localB->trueCount++)
    {
        for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < 5; localB->n_size_idx_1++)
        {
            localB->tmp_pr_data[localB->n_size_idx_1 + 5 * localB->trueCount] = rtu_GpsMeasurementBus->Pseudorange
                [(localB->p_data[localB->iidx_data[localB->x_data[localB->trueCount] - 1] - 1] - 1) * 5 +
                localB->n_size_idx_1];
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

    localB->tmp_svid = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->y_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->tmp_svid; localB->trueCount++)
    {
        for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < 5; localB->n_size_idx_1++)
        {
            localB->tmp_pr_sigma_data[localB->n_size_idx_1 + 5 * localB->trueCount] =
                rtu_GpsMeasurementBus->Pseudorange_Sigma[(localB->q_data[localB->iidx_data[localB->y_data
                [localB->trueCount] - 1] - 1] - 1) * 5 + localB->n_size_idx_1];
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

    localB->tmp_svid = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->ab_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->tmp_svid; localB->trueCount++)
    {
        for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < 5; localB->n_size_idx_1++)
        {
            localB->tmp_cp_data[localB->n_size_idx_1 + 5 * localB->trueCount] = rtu_GpsMeasurementBus->Carrier
                [(localB->r_data[localB->iidx_data[localB->ab_data[localB->trueCount] - 1] - 1] - 1) * 5 +
                localB->n_size_idx_1];
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

    localB->tmp_svid = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->bb_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->tmp_svid; localB->trueCount++)
    {
        for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < 5; localB->n_size_idx_1++)
        {
            localB->tmp_cp_sigma_data[localB->n_size_idx_1 + 5 * localB->trueCount] =
                rtu_GpsMeasurementBus->Carrier_Sigma[(localB->s_data[localB->iidx_data[localB->bb_data[localB->trueCount]
                - 1] - 1] - 1) * 5 + localB->n_size_idx_1];
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

    localB->tmp_svid = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->cb_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->tmp_svid; localB->trueCount++)
    {
        for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < 5; localB->n_size_idx_1++)
        {
            localB->tmp_Locktime_data[localB->n_size_idx_1 + 5 * localB->trueCount] = rtu_GpsMeasurementBus->Locktime
                [(localB->t_data[localB->iidx_data[localB->cb_data[localB->trueCount] - 1] - 1] - 1) * 5 +
                localB->n_size_idx_1];
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

    localB->db_size[0] = 1;
    localB->db_size[1] = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->db_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    if (localB->u_size[1] == static_cast<int8_T>(localB->o_size_idx_1))
    {
        localB->loop_ub = localB->db_size[1];
        for (localB->trueCount = 0; localB->trueCount < localB->loop_ub; localB->trueCount++)
        {
            for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < 5; localB->n_size_idx_1++)
            {
                localB->tmp_svid = localB->iidx_data[localB->db_data[localB->trueCount] - 1] - 1;
                localB->tmp_dr_data[localB->n_size_idx_1 + 5 * localB->trueCount] = -rtu_GpsMeasurementBus->Doppler
                    [(localB->u_data[localB->tmp_svid] - 1) * 5 + localB->n_size_idx_1] * 2.99792458E+8 /
                    localB->gnss_freq_Matrix_data[5 * localB->tmp_svid + localB->n_size_idx_1];
            }
        }
    }
    else
    {
        GNSSPrePro_binary_expand_op_jbw(localB->tmp_dr_data, localB->a__1_size, rtu_GpsMeasurementBus, localB->u_data,
            localB->u_size, localB->gnss_freq_Matrix_data, localB->gnss_freq_Matrix_size, localB->iidx_data,
            localB->db_data, localB->db_size, localB);
    }

    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->loop_ub++;
        }
    }

    localB->o_size_idx_1 = localB->loop_ub;
    localB->loop_ub = 0;
    for (localB->trueCount = 0; localB->trueCount <= localB->c_trueCount_tmp; localB->trueCount++)
    {
        if (localB->mask_available_SV_data[localB->trueCount])
        {
            localB->eb_data[localB->loop_ub] = static_cast<int8_T>(localB->trueCount + 1);
            localB->loop_ub++;
        }
    }

    for (localB->trueCount = 0; localB->trueCount < localB->o_size_idx_1; localB->trueCount++)
    {
        for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < 5; localB->n_size_idx_1++)
        {
            localB->gnss_freq_Matrix_data[localB->n_size_idx_1 + 5 * localB->trueCount] = rtu_GpsMeasurementBus->CN0
                [(localB->v_data[localB->iidx_data[localB->eb_data[localB->trueCount] - 1] - 1] - 1) * 5 +
                localB->n_size_idx_1];
        }
    }

    localB->L1_mask_size[0] = 5;
    localB->L1_mask_size[1] = static_cast<int8_T>(localB->w_size_idx_1);
    localB->trueCount = 5 * static_cast<int8_T>(localB->w_size_idx_1);
    if (localB->trueCount - 1 >= 0)
    {
        std::memset(&localB->L1_mask_data[0], 0, static_cast<uint32_T>(localB->trueCount) * sizeof(boolean_T));
    }

    localB->L2C_mask_size[0] = 5;
    localB->L2C_mask_size[1] = static_cast<int8_T>(localB->w_size_idx_1);
    if (localB->trueCount - 1 >= 0)
    {
        std::memset(&localB->L2C_mask_data[0], 0, static_cast<uint32_T>(localB->trueCount) * sizeof(boolean_T));
    }

    localB->L5_mask_size[0] = 5;
    localB->L5_mask_size[1] = static_cast<int8_T>(localB->w_size_idx_1);
    if (localB->trueCount - 1 >= 0)
    {
        std::memset(&localB->L5_mask_data[0], 0, static_cast<uint32_T>(localB->trueCount) * sizeof(boolean_T));
    }

    for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < localB->c_i; localB->n_size_idx_1++)
    {
        for (localB->trueCount = 0; localB->trueCount < 5; localB->trueCount++)
        {
            uint8_T tmp_type;
            localB->loop_ub = 5 * localB->n_size_idx_1 + localB->trueCount;
            tmp_type = localB->tmp_type_data[localB->loop_ub];
            localB->L1_mask_data[localB->loop_ub] = (tmp_type == 0);
            localB->L2C_mask_data[localB->loop_ub] = (tmp_type == 3);
            localB->L5_mask_data[localB->loop_ub] = (tmp_type == 4);
        }
    }

    GNSSPreProcessingDualA_any_jvgx(localB->L1_mask_data, localB->L1_mask_size, localB->mask_available_SV_data,
        localB->gnss_freq_Matrix_size);
    localB->trueCount = localB->gnss_freq_Matrix_size[1] - 1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS3 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->f_data[localB->n_size_idx_1] = localB->tmp_svid_data[localB->c_i];
            localB->n_size_idx_1++;
        }
    }

    if (localDW->SFunction_DIMS3 - 1 >= 0)
    {
        std::memcpy(&localB->a__1_data[0], &localB->f_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS3) * sizeof
                    (uint16_T));
    }

    if (localDW->SFunction_DIMS3 - 1 >= 0)
    {
        std::memcpy(&localB->svid_L1[0], &localB->a__1_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS3) * sizeof
                    (uint16_T));
    }

    localB->trueCount = 5 * static_cast<int8_T>(localB->w_size_idx_1) - 1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS5 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->fb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS6 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->gb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS9 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->hb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS10 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->ib_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS11 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->jb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS7 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->kb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS8 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L1_mask_data[localB->c_i])
        {
            localB->lb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->mask_navdata_L1_size = rtu_GpsNavBusReshaped_DIMS1->SVID;
    localB->loop_ub = rtu_GpsNavBusReshaped_DIMS1->SVID;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memset(&localB->mask_navdata_L1_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(boolean_T));
    }

    for (localB->c_i = 0; localB->c_i < localDW->SFunction_DIMS3; localB->c_i++)
    {
        if (localB->mask_navdata_L1_size == rtu_GpsNavBusReshaped_DIMS1->SVID)
        {
            localB->trueCount = localB->svid_L1[localB->c_i];
            localB->loop_ub = localB->mask_navdata_L1_size;
            for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < localB->loop_ub; localB->n_size_idx_1++)
            {
                localB->mask_navdata_L1_data[localB->n_size_idx_1] = (localB->mask_navdata_L1_data[localB->n_size_idx_1]
                    || (rtu_GpsNavBusReshaped->SVID[localB->n_size_idx_1] == localB->trueCount));
            }
        }
        else
        {
            GNSSPreProc_binary_expand_op_jb(localB->mask_navdata_L1_data, &localB->mask_navdata_L1_size,
                rtu_GpsNavBusReshaped, rtu_GpsNavBusReshaped_DIMS1, localB->svid_L1, localB->c_i);
        }
    }

    localB->r3 = *rtu_GpsNavBusReshaped;
    emxConvertStructToEmx_gnssops_n(&localB->r, &localB->r3, rtu_GpsNavBusReshaped_DIMS1);
    GNSSPreP_select_navigation_data(&localB->r, localB->mask_navdata_L1_data, &localB->mask_navdata_L1_size,
        &localB->expl_temp, localB);
    localDW->SFunction_DIMS4.TOW = localB->expl_temp.TOW.size;
    localB->loop_ub = localB->expl_temp.TOW.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.TOW[0], &localB->expl_temp.TOW.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS4.WNc = localB->expl_temp.WNc.size;
    localB->loop_ub = localB->expl_temp.WNc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.WNc[0], &localB->expl_temp.WNc.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS4.SVID = localB->expl_temp.SVID.size;
    localB->loop_ub = localB->expl_temp.SVID.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.SVID[0], &localB->expl_temp.SVID.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.T_gd = localB->expl_temp.T_gd.size;
    localB->loop_ub = localB->expl_temp.T_gd.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.T_gd[0], &localB->expl_temp.T_gd.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.T_oc = localB->expl_temp.T_oc.size;
    localB->loop_ub = localB->expl_temp.T_oc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.T_oc[0], &localB->expl_temp.T_oc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.A_f2 = localB->expl_temp.A_f2.size;
    localB->loop_ub = localB->expl_temp.A_f2.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.A_f2[0], &localB->expl_temp.A_f2.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.A_f1 = localB->expl_temp.A_f1.size;
    localB->loop_ub = localB->expl_temp.A_f1.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.A_f1[0], &localB->expl_temp.A_f1.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.A_f0 = localB->expl_temp.A_f0.size;
    localB->loop_ub = localB->expl_temp.A_f0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.A_f0[0], &localB->expl_temp.A_f0.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_rs = localB->expl_temp.C_rs.size;
    localB->loop_ub = localB->expl_temp.C_rs.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.C_rs[0], &localB->expl_temp.C_rs.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.DELTA_N = localB->expl_temp.DELTA_N.size;
    localB->loop_ub = localB->expl_temp.DELTA_N.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.DELTA_N[0], &localB->expl_temp.DELTA_N.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.M_0 = localB->expl_temp.M_0.size;
    localB->loop_ub = localB->expl_temp.M_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.M_0[0], &localB->expl_temp.M_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_uc = localB->expl_temp.C_uc.size;
    localB->loop_ub = localB->expl_temp.C_uc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.C_uc[0], &localB->expl_temp.C_uc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.E = localB->expl_temp.E.size;
    localB->loop_ub = localB->expl_temp.E.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.E[0], &localB->expl_temp.E.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_us = localB->expl_temp.C_us.size;
    localB->loop_ub = localB->expl_temp.C_us.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.C_us[0], &localB->expl_temp.C_us.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.SQRT_A = localB->expl_temp.SQRT_A.size;
    localB->loop_ub = localB->expl_temp.SQRT_A.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.SQRT_A[0], &localB->expl_temp.SQRT_A.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.T_oe = localB->expl_temp.T_oe.size;
    localB->loop_ub = localB->expl_temp.T_oe.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.T_oe[0], &localB->expl_temp.T_oe.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_ic = localB->expl_temp.C_ic.size;
    localB->loop_ub = localB->expl_temp.C_ic.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.C_ic[0], &localB->expl_temp.C_ic.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.OMEGA_0 = localB->expl_temp.OMEGA_0.size;
    localB->loop_ub = localB->expl_temp.OMEGA_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.OMEGA_0[0], &localB->expl_temp.OMEGA_0.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_is = localB->expl_temp.C_is.size;
    localB->loop_ub = localB->expl_temp.C_is.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.C_is[0], &localB->expl_temp.C_is.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.I_0 = localB->expl_temp.I_0.size;
    localB->loop_ub = localB->expl_temp.I_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.I_0[0], &localB->expl_temp.I_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS4.C_rc = localB->expl_temp.C_rc.size;
    localB->loop_ub = localB->expl_temp.C_rc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.C_rc[0], &localB->expl_temp.C_rc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.omega = localB->expl_temp.omega.size;
    localB->loop_ub = localB->expl_temp.omega.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.omega[0], &localB->expl_temp.omega.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.OMEGADOT = localB->expl_temp.OMEGADOT.size;
    localB->loop_ub = localB->expl_temp.OMEGADOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.OMEGADOT[0], &localB->expl_temp.OMEGADOT.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS4.IDOT = localB->expl_temp.IDOT.size;
    localB->loop_ub = localB->expl_temp.IDOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L1.IDOT[0], &localB->expl_temp.IDOT.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    GNSSPreProcessingDualA_any_jvgx(localB->L2C_mask_data, localB->L2C_mask_size, localB->mask_available_SV_data,
        localB->gnss_freq_Matrix_size);
    localB->trueCount = localB->gnss_freq_Matrix_size[1] - 1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS12 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->h_data[localB->n_size_idx_1] = localB->tmp_svid_data[localB->c_i];
            localB->n_size_idx_1++;
        }
    }

    if (localDW->SFunction_DIMS12 - 1 >= 0)
    {
        std::memcpy(&localB->a__1_data[0], &localB->h_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS12) * sizeof
                    (uint16_T));
    }

    if (localDW->SFunction_DIMS12 - 1 >= 0)
    {
        std::memcpy(&localB->svid_L2C[0], &localB->a__1_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS12) *
                    sizeof(uint16_T));
    }

    localB->trueCount = 5 * static_cast<int8_T>(localB->w_size_idx_1) - 1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS14 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->mb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS15 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->nb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS18 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->ob_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS19 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->pb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS20 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->qb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS16 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->rb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS17 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L2C_mask_data[localB->c_i])
        {
            localB->sb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->mask_navdata_L1_size = rtu_GpsNavBusReshaped_DIMS1->SVID;
    localB->loop_ub = rtu_GpsNavBusReshaped_DIMS1->SVID;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memset(&localB->mask_navdata_L1_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(boolean_T));
    }

    for (localB->c_i = 0; localB->c_i < localDW->SFunction_DIMS12; localB->c_i++)
    {
        if (localB->mask_navdata_L1_size == rtu_GpsNavBusReshaped_DIMS1->SVID)
        {
            localB->trueCount = localB->svid_L2C[localB->c_i];
            localB->loop_ub = localB->mask_navdata_L1_size;
            for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < localB->loop_ub; localB->n_size_idx_1++)
            {
                localB->mask_navdata_L1_data[localB->n_size_idx_1] = (localB->mask_navdata_L1_data[localB->n_size_idx_1]
                    || (rtu_GpsNavBusReshaped->SVID[localB->n_size_idx_1] == localB->trueCount));
            }
        }
        else
        {
            GNSSPreProc_binary_expand_op_jb(localB->mask_navdata_L1_data, &localB->mask_navdata_L1_size,
                rtu_GpsNavBusReshaped, rtu_GpsNavBusReshaped_DIMS1, localB->svid_L2C, localB->c_i);
        }
    }

    localB->r3 = *rtu_GpsNavBusReshaped;
    emxConvertStructToEmx_gnssops_n(&localB->r1, &localB->r3, rtu_GpsNavBusReshaped_DIMS1);
    GNSSPreP_select_navigation_data(&localB->r1, localB->mask_navdata_L1_data, &localB->mask_navdata_L1_size,
        &localB->expl_temp, localB);
    localDW->SFunction_DIMS13.TOW = localB->expl_temp.TOW.size;
    localB->loop_ub = localB->expl_temp.TOW.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.TOW[0], &localB->expl_temp.TOW.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS13.WNc = localB->expl_temp.WNc.size;
    localB->loop_ub = localB->expl_temp.WNc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.WNc[0], &localB->expl_temp.WNc.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS13.SVID = localB->expl_temp.SVID.size;
    localB->loop_ub = localB->expl_temp.SVID.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.SVID[0], &localB->expl_temp.SVID.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.T_gd = localB->expl_temp.T_gd.size;
    localB->loop_ub = localB->expl_temp.T_gd.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.T_gd[0], &localB->expl_temp.T_gd.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.T_oc = localB->expl_temp.T_oc.size;
    localB->loop_ub = localB->expl_temp.T_oc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.T_oc[0], &localB->expl_temp.T_oc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.A_f2 = localB->expl_temp.A_f2.size;
    localB->loop_ub = localB->expl_temp.A_f2.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.A_f2[0], &localB->expl_temp.A_f2.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.A_f1 = localB->expl_temp.A_f1.size;
    localB->loop_ub = localB->expl_temp.A_f1.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.A_f1[0], &localB->expl_temp.A_f1.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.A_f0 = localB->expl_temp.A_f0.size;
    localB->loop_ub = localB->expl_temp.A_f0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.A_f0[0], &localB->expl_temp.A_f0.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_rs = localB->expl_temp.C_rs.size;
    localB->loop_ub = localB->expl_temp.C_rs.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.C_rs[0], &localB->expl_temp.C_rs.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.DELTA_N = localB->expl_temp.DELTA_N.size;
    localB->loop_ub = localB->expl_temp.DELTA_N.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.DELTA_N[0], &localB->expl_temp.DELTA_N.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.M_0 = localB->expl_temp.M_0.size;
    localB->loop_ub = localB->expl_temp.M_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.M_0[0], &localB->expl_temp.M_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_uc = localB->expl_temp.C_uc.size;
    localB->loop_ub = localB->expl_temp.C_uc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.C_uc[0], &localB->expl_temp.C_uc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.E = localB->expl_temp.E.size;
    localB->loop_ub = localB->expl_temp.E.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.E[0], &localB->expl_temp.E.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_us = localB->expl_temp.C_us.size;
    localB->loop_ub = localB->expl_temp.C_us.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.C_us[0], &localB->expl_temp.C_us.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.SQRT_A = localB->expl_temp.SQRT_A.size;
    localB->loop_ub = localB->expl_temp.SQRT_A.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.SQRT_A[0], &localB->expl_temp.SQRT_A.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.T_oe = localB->expl_temp.T_oe.size;
    localB->loop_ub = localB->expl_temp.T_oe.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.T_oe[0], &localB->expl_temp.T_oe.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_ic = localB->expl_temp.C_ic.size;
    localB->loop_ub = localB->expl_temp.C_ic.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.C_ic[0], &localB->expl_temp.C_ic.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.OMEGA_0 = localB->expl_temp.OMEGA_0.size;
    localB->loop_ub = localB->expl_temp.OMEGA_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.OMEGA_0[0], &localB->expl_temp.OMEGA_0.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_is = localB->expl_temp.C_is.size;
    localB->loop_ub = localB->expl_temp.C_is.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.C_is[0], &localB->expl_temp.C_is.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.I_0 = localB->expl_temp.I_0.size;
    localB->loop_ub = localB->expl_temp.I_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.I_0[0], &localB->expl_temp.I_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS13.C_rc = localB->expl_temp.C_rc.size;
    localB->loop_ub = localB->expl_temp.C_rc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.C_rc[0], &localB->expl_temp.C_rc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.omega = localB->expl_temp.omega.size;
    localB->loop_ub = localB->expl_temp.omega.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.omega[0], &localB->expl_temp.omega.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.OMEGADOT = localB->expl_temp.OMEGADOT.size;
    localB->loop_ub = localB->expl_temp.OMEGADOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.OMEGADOT[0], &localB->expl_temp.OMEGADOT.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS13.IDOT = localB->expl_temp.IDOT.size;
    localB->loop_ub = localB->expl_temp.IDOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L2C.IDOT[0], &localB->expl_temp.IDOT.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    GNSSPreProcessingDualA_any_jvgx(localB->L5_mask_data, localB->L5_mask_size, localB->mask_available_SV_data,
        localB->gnss_freq_Matrix_size);
    localB->trueCount = localB->gnss_freq_Matrix_size[1] - 1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS21 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->mask_available_SV_data[localB->c_i])
        {
            localB->l_data[localB->n_size_idx_1] = localB->tmp_svid_data[localB->c_i];
            localB->n_size_idx_1++;
        }
    }

    if (localDW->SFunction_DIMS21 - 1 >= 0)
    {
        std::memcpy(&localB->a__1_data[0], &localB->l_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS21) * sizeof
                    (uint16_T));
    }

    if (localDW->SFunction_DIMS21 - 1 >= 0)
    {
        std::memcpy(&localB->svid_L5[0], &localB->a__1_data[0], static_cast<uint32_T>(localDW->SFunction_DIMS21) *
                    sizeof(uint16_T));
    }

    localB->trueCount = 5 * static_cast<int8_T>(localB->w_size_idx_1) - 1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS23 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->tb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS24 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->ub_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS27 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->vb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS28 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->wb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS29 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->xb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS25 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->yb_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->n_size_idx_1++;
        }
    }

    localDW->SFunction_DIMS26 = localB->n_size_idx_1;
    localB->n_size_idx_1 = 0;
    for (localB->c_i = 0; localB->c_i <= localB->trueCount; localB->c_i++)
    {
        if (localB->L5_mask_data[localB->c_i])
        {
            localB->ac_data[localB->n_size_idx_1] = static_cast<uint8_T>(localB->c_i + 1);
            localB->n_size_idx_1++;
        }
    }

    localB->mask_navdata_L1_size = rtu_GpsNavBusReshaped_DIMS1->SVID;
    localB->loop_ub = rtu_GpsNavBusReshaped_DIMS1->SVID;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memset(&localB->mask_navdata_L1_data[0], 0, static_cast<uint32_T>(localB->loop_ub) * sizeof(boolean_T));
    }

    for (localB->c_i = 0; localB->c_i < localDW->SFunction_DIMS21; localB->c_i++)
    {
        if (localB->mask_navdata_L1_size == rtu_GpsNavBusReshaped_DIMS1->SVID)
        {
            localB->trueCount = localB->svid_L5[localB->c_i];
            localB->loop_ub = localB->mask_navdata_L1_size;
            for (localB->n_size_idx_1 = 0; localB->n_size_idx_1 < localB->loop_ub; localB->n_size_idx_1++)
            {
                localB->mask_navdata_L1_data[localB->n_size_idx_1] = (localB->mask_navdata_L1_data[localB->n_size_idx_1]
                    || (rtu_GpsNavBusReshaped->SVID[localB->n_size_idx_1] == localB->trueCount));
            }
        }
        else
        {
            GNSSPreProc_binary_expand_op_jb(localB->mask_navdata_L1_data, &localB->mask_navdata_L1_size,
                rtu_GpsNavBusReshaped, rtu_GpsNavBusReshaped_DIMS1, localB->svid_L5, localB->c_i);
        }
    }

    localB->r3 = *rtu_GpsNavBusReshaped;
    emxConvertStructToEmx_gnssops_n(&localB->r2, &localB->r3, rtu_GpsNavBusReshaped_DIMS1);
    GNSSPreP_select_navigation_data(&localB->r2, localB->mask_navdata_L1_data, &localB->mask_navdata_L1_size,
        &localB->expl_temp, localB);
    localDW->SFunction_DIMS22.TOW = localB->expl_temp.TOW.size;
    localB->loop_ub = localB->expl_temp.TOW.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.TOW[0], &localB->expl_temp.TOW.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS22.WNc = localB->expl_temp.WNc.size;
    localB->loop_ub = localB->expl_temp.WNc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.WNc[0], &localB->expl_temp.WNc.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS22.SVID = localB->expl_temp.SVID.size;
    localB->loop_ub = localB->expl_temp.SVID.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.SVID[0], &localB->expl_temp.SVID.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.T_gd = localB->expl_temp.T_gd.size;
    localB->loop_ub = localB->expl_temp.T_gd.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.T_gd[0], &localB->expl_temp.T_gd.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.T_oc = localB->expl_temp.T_oc.size;
    localB->loop_ub = localB->expl_temp.T_oc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.T_oc[0], &localB->expl_temp.T_oc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.A_f2 = localB->expl_temp.A_f2.size;
    localB->loop_ub = localB->expl_temp.A_f2.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.A_f2[0], &localB->expl_temp.A_f2.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.A_f1 = localB->expl_temp.A_f1.size;
    localB->loop_ub = localB->expl_temp.A_f1.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.A_f1[0], &localB->expl_temp.A_f1.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.A_f0 = localB->expl_temp.A_f0.size;
    localB->loop_ub = localB->expl_temp.A_f0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.A_f0[0], &localB->expl_temp.A_f0.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_rs = localB->expl_temp.C_rs.size;
    localB->loop_ub = localB->expl_temp.C_rs.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.C_rs[0], &localB->expl_temp.C_rs.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.DELTA_N = localB->expl_temp.DELTA_N.size;
    localB->loop_ub = localB->expl_temp.DELTA_N.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.DELTA_N[0], &localB->expl_temp.DELTA_N.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.M_0 = localB->expl_temp.M_0.size;
    localB->loop_ub = localB->expl_temp.M_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.M_0[0], &localB->expl_temp.M_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_uc = localB->expl_temp.C_uc.size;
    localB->loop_ub = localB->expl_temp.C_uc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.C_uc[0], &localB->expl_temp.C_uc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.E = localB->expl_temp.E.size;
    localB->loop_ub = localB->expl_temp.E.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.E[0], &localB->expl_temp.E.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_us = localB->expl_temp.C_us.size;
    localB->loop_ub = localB->expl_temp.C_us.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.C_us[0], &localB->expl_temp.C_us.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.SQRT_A = localB->expl_temp.SQRT_A.size;
    localB->loop_ub = localB->expl_temp.SQRT_A.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.SQRT_A[0], &localB->expl_temp.SQRT_A.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.T_oe = localB->expl_temp.T_oe.size;
    localB->loop_ub = localB->expl_temp.T_oe.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.T_oe[0], &localB->expl_temp.T_oe.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_ic = localB->expl_temp.C_ic.size;
    localB->loop_ub = localB->expl_temp.C_ic.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.C_ic[0], &localB->expl_temp.C_ic.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.OMEGA_0 = localB->expl_temp.OMEGA_0.size;
    localB->loop_ub = localB->expl_temp.OMEGA_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.OMEGA_0[0], &localB->expl_temp.OMEGA_0.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_is = localB->expl_temp.C_is.size;
    localB->loop_ub = localB->expl_temp.C_is.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.C_is[0], &localB->expl_temp.C_is.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.I_0 = localB->expl_temp.I_0.size;
    localB->loop_ub = localB->expl_temp.I_0.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.I_0[0], &localB->expl_temp.I_0.data[0], static_cast<uint32_T>(localB->loop_ub) *
                    sizeof(real_T));
    }

    localDW->SFunction_DIMS22.C_rc = localB->expl_temp.C_rc.size;
    localB->loop_ub = localB->expl_temp.C_rc.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.C_rc[0], &localB->expl_temp.C_rc.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.omega = localB->expl_temp.omega.size;
    localB->loop_ub = localB->expl_temp.omega.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.omega[0], &localB->expl_temp.omega.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.OMEGADOT = localB->expl_temp.OMEGADOT.size;
    localB->loop_ub = localB->expl_temp.OMEGADOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.OMEGADOT[0], &localB->expl_temp.OMEGADOT.data[0], static_cast<uint32_T>
                    (localB->loop_ub) * sizeof(real_T));
    }

    localDW->SFunction_DIMS22.IDOT = localB->expl_temp.IDOT.size;
    localB->loop_ub = localB->expl_temp.IDOT.size;
    if (localB->loop_ub - 1 >= 0)
    {
        std::memcpy(&localB->navdata_L5.IDOT[0], &localB->expl_temp.IDOT.data[0], static_cast<uint32_T>(localB->loop_ub)
                    * sizeof(real_T));
    }

    localB->TOW = rtu_GpsMeasurementBus->TOW;
    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS5; localB->trueCount++)
    {
        localB->pr_L1[localB->trueCount] = localB->tmp_pr_data[localB->fb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS6; localB->trueCount++)
    {
        localB->pr_sigma_L1[localB->trueCount] = localB->tmp_pr_sigma_data[localB->gb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS7; localB->trueCount++)
    {
        localB->dr_L1[localB->trueCount] = localB->tmp_dr_data[localB->kb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS8; localB->trueCount++)
    {
        localB->cn0_L1[localB->trueCount] = localB->gnss_freq_Matrix_data[localB->lb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS9; localB->trueCount++)
    {
        localB->cp_L1[localB->trueCount] = localB->tmp_cp_data[localB->hb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS10; localB->trueCount++)
    {
        localB->cp_sigma_L1[localB->trueCount] = localB->tmp_cp_sigma_data[localB->ib_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS11; localB->trueCount++)
    {
        localB->Locktime_L1[localB->trueCount] = localB->tmp_Locktime_data[localB->jb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS14; localB->trueCount++)
    {
        localB->pr_L2C[localB->trueCount] = localB->tmp_pr_data[localB->mb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS15; localB->trueCount++)
    {
        localB->pr_sigma_L2C[localB->trueCount] = localB->tmp_pr_sigma_data[localB->nb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS16; localB->trueCount++)
    {
        localB->dr_L2C[localB->trueCount] = localB->tmp_dr_data[localB->rb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS17; localB->trueCount++)
    {
        localB->cn0_L2C[localB->trueCount] = localB->gnss_freq_Matrix_data[localB->sb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS18; localB->trueCount++)
    {
        localB->cp_L2C[localB->trueCount] = localB->tmp_cp_data[localB->ob_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS19; localB->trueCount++)
    {
        localB->cp_sigma_L2C[localB->trueCount] = localB->tmp_cp_sigma_data[localB->pb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS20; localB->trueCount++)
    {
        localB->Locktime_L2C[localB->trueCount] = localB->tmp_Locktime_data[localB->qb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS23; localB->trueCount++)
    {
        localB->pr_L5[localB->trueCount] = localB->tmp_pr_data[localB->tb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS24; localB->trueCount++)
    {
        localB->pr_sigma_L5[localB->trueCount] = localB->tmp_pr_sigma_data[localB->ub_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS25; localB->trueCount++)
    {
        localB->dr_L5[localB->trueCount] = localB->tmp_dr_data[localB->yb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS26; localB->trueCount++)
    {
        localB->cn0_L5[localB->trueCount] = localB->gnss_freq_Matrix_data[localB->ac_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS27; localB->trueCount++)
    {
        localB->cp_L5[localB->trueCount] = localB->tmp_cp_data[localB->vb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS28; localB->trueCount++)
    {
        localB->cp_sigma_L5[localB->trueCount] = localB->tmp_cp_sigma_data[localB->wb_data[localB->trueCount] - 1];
    }

    for (localB->trueCount = 0; localB->trueCount < localDW->SFunction_DIMS29; localB->trueCount++)
    {
        localB->Locktime_L5[localB->trueCount] = localB->tmp_Locktime_data[localB->xb_data[localB->trueCount] - 1];
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
