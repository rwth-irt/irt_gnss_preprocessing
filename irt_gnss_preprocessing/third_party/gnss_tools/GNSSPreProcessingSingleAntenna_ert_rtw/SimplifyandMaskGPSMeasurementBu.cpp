//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SimplifyandMaskGPSMeasurementBu.cpp
//
// Code generated for Simulink model 'GNSSPreProcessingSingleAntenna'.
//
// Model version                  : 7.0
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Jan 26 20:34:15 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "GNSSPreProcessingSingleAntenna_types.h"
#include "SimplifyandMaskGPSMeasurementBu.h"
#include "rtwtypes.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <cstring>

// Function for MATLAB Function: '<S11>/Simplify and Mask GPS Measurement Bus'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_any_k(const
  boolean_T x[200], boolean_T y[40])
{
  int32_T i2;
  i2 = 1;
  for (int32_T i{0}; i < 40; i++) {
    int32_T a;
    int32_T ix;
    boolean_T exitg1;
    y[i] = false;
    a = i2 + 4;
    ix = i2;
    i2 += 5;
    exitg1 = false;
    while ((!exitg1) && (ix <= a)) {
      if (x[ix - 1]) {
        y[i] = true;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }
}

// Function for MATLAB Function: '<S11>/Simplify and Mask GPS Measurement Bus'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingl_eml_find(const
  boolean_T x[4], int32_T i_data[], int32_T i_size[2])
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  i_size[0] = 1;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 4)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 4) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (idx < 1) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

// Function for MATLAB Function: '<S11>/Simplify and Mask GPS Measurement Bus'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_merge_o(int32_T
  idx_data[], uint16_T x_data[], int32_T offset, int32_T np, int32_T nq, int32_T
  iwork_data[], uint16_T xwork_data[])
{
  if (nq != 0) {
    int32_T iout;
    int32_T offset1;
    int32_T p;
    int32_T q;
    offset1 = np + nq;
    for (q = 0; q < offset1; q++) {
      iout = offset + q;
      iwork_data[q] = idx_data[iout];
      xwork_data[q] = x_data[iout];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < offset1) {
          q++;
        } else {
          offset1 = iout - p;
          for (q = p + 1; q <= np; q++) {
            iout = offset1 + q;
            idx_data[iout] = iwork_data[q - 1];
            x_data[iout] = xwork_data[q - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

// Function for MATLAB Function: '<S11>/Simplify and Mask GPS Measurement Bus'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_sort_n(uint16_T
  x_data[], int32_T x_size[2], int32_T idx_data[], int32_T idx_size[2])
{
  int32_T iwork_data[40];
  int32_T b_x_size[2];
  int32_T nLeft;
  uint16_T b_x_data[40];
  uint16_T xwork_data[40];
  uint16_T x4[4];
  int8_T idx4[4];
  int8_T perm[4];
  b_x_size[1] = x_size[1];
  nLeft = x_size[1];
  if (nLeft - 1 >= 0) {
    std::memcpy(&b_x_data[0], &x_data[0], static_cast<uint32_T>(nLeft) * sizeof
                (uint16_T));
  }

  idx_size[0] = 1;
  idx_size[1] = x_size[1];
  nLeft = x_size[1];
  if (nLeft - 1 >= 0) {
    std::memset(&idx_data[0], 0, static_cast<uint32_T>(nLeft) * sizeof(int32_T));
  }

  if (x_size[1] != 0) {
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T nDone;
    int32_T nQuartets_tmp;
    idx_size[0] = 1;
    idx_size[1] = x_size[1];
    nLeft = x_size[1];
    if (nLeft - 1 >= 0) {
      std::memset(&idx_data[0], 0, static_cast<uint32_T>(nLeft) * sizeof(int32_T));
    }

    b_x_size[1] = x_size[1];
    nLeft = x_size[1];
    if (nLeft - 1 >= 0) {
      std::memcpy(&b_x_data[0], &x_data[0], static_cast<uint32_T>(nLeft) *
                  sizeof(uint16_T));
    }

    x4[0] = 0U;
    idx4[0] = 0;
    x4[1] = 0U;
    idx4[1] = 0;
    x4[2] = 0U;
    idx4[2] = 0;
    x4[3] = 0U;
    idx4[3] = 0;
    nQuartets_tmp = x_size[1] >> 2;
    for (nLeft = 0; nLeft < nQuartets_tmp; nLeft++) {
      int32_T i3;
      int32_T i4;
      int32_T tmp;
      uint16_T x4_tmp;
      uint16_T x4_tmp_0;
      uint16_T x4_tmp_1;
      uint16_T x4_tmp_2;
      i = nLeft << 2;
      idx4[0] = static_cast<int8_T>(i + 1);
      idx4[1] = static_cast<int8_T>(i + 2);
      idx4[2] = static_cast<int8_T>(i + 3);
      idx4[3] = static_cast<int8_T>(i + 4);
      x4_tmp_2 = b_x_data[i];
      x4[0] = x4_tmp_2;
      x4_tmp = b_x_data[i + 1];
      x4[1] = x4_tmp;
      x4_tmp_0 = b_x_data[i + 2];
      x4[2] = x4_tmp_0;
      x4_tmp_1 = b_x_data[i + 3];
      x4[3] = x4_tmp_1;
      if (x4_tmp_2 <= x4_tmp) {
        i1 = 1;
        i2 = 2;
      } else {
        i1 = 2;
        i2 = 1;
      }

      if (x4_tmp_0 <= x4_tmp_1) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }

      nDone = x4[i1 - 1];
      tmp = x4[i3 - 1];
      if (nDone <= tmp) {
        nDone = x4[i2 - 1];
        if (nDone <= tmp) {
          perm[0] = static_cast<int8_T>(i1);
          perm[1] = static_cast<int8_T>(i2);
          perm[2] = static_cast<int8_T>(i3);
          perm[3] = static_cast<int8_T>(i4);
        } else if (nDone <= x4[i4 - 1]) {
          perm[0] = static_cast<int8_T>(i1);
          perm[1] = static_cast<int8_T>(i3);
          perm[2] = static_cast<int8_T>(i2);
          perm[3] = static_cast<int8_T>(i4);
        } else {
          perm[0] = static_cast<int8_T>(i1);
          perm[1] = static_cast<int8_T>(i3);
          perm[2] = static_cast<int8_T>(i4);
          perm[3] = static_cast<int8_T>(i2);
        }
      } else {
        tmp = x4[i4 - 1];
        if (nDone <= tmp) {
          if (x4[i2 - 1] <= tmp) {
            perm[0] = static_cast<int8_T>(i3);
            perm[1] = static_cast<int8_T>(i1);
            perm[2] = static_cast<int8_T>(i2);
            perm[3] = static_cast<int8_T>(i4);
          } else {
            perm[0] = static_cast<int8_T>(i3);
            perm[1] = static_cast<int8_T>(i1);
            perm[2] = static_cast<int8_T>(i4);
            perm[3] = static_cast<int8_T>(i2);
          }
        } else {
          perm[0] = static_cast<int8_T>(i3);
          perm[1] = static_cast<int8_T>(i4);
          perm[2] = static_cast<int8_T>(i1);
          perm[3] = static_cast<int8_T>(i2);
        }
      }

      idx_data[i] = idx4[perm[0] - 1];
      idx_data[i + 1] = idx4[perm[1] - 1];
      idx_data[i + 2] = idx4[perm[2] - 1];
      idx_data[i + 3] = idx4[perm[3] - 1];
      b_x_data[i] = x4[perm[0] - 1];
      b_x_data[i + 1] = x4[perm[1] - 1];
      b_x_data[i + 2] = x4[perm[2] - 1];
      b_x_data[i + 3] = x4[perm[3] - 1];
    }

    nDone = nQuartets_tmp << 2;
    nLeft = x_size[1] - nDone;
    if (nLeft > 0) {
      for (i2 = 0; i2 < nLeft; i2++) {
        i = nDone + i2;
        idx4[i2] = static_cast<int8_T>(i + 1);
        x4[i2] = b_x_data[i];
      }

      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      switch (nLeft) {
       case 1:
        perm[0] = 1;
        break;

       case 2:
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
        break;

       default:
        if (x4[0] <= x4[1]) {
          if (x4[1] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 2;
            perm[2] = 3;
          } else if (x4[0] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 3;
            perm[2] = 2;
          } else {
            perm[0] = 3;
            perm[1] = 1;
            perm[2] = 2;
          }
        } else if (x4[0] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 1;
          perm[2] = 3;
        } else if (x4[1] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 3;
          perm[2] = 1;
        } else {
          perm[0] = 3;
          perm[1] = 2;
          perm[2] = 1;
        }
        break;
      }

      for (i2 = 0; i2 < nLeft; i2++) {
        int8_T perm_0;
        perm_0 = perm[i2];
        i1 = nDone + i2;
        idx_data[i1] = idx4[perm_0 - 1];
        b_x_data[i1] = x4[perm_0 - 1];
      }
    }

    if (x_size[1] > 1) {
      nLeft = x_size[1];
      if (nLeft - 1 >= 0) {
        std::memset(&iwork_data[0], 0, static_cast<uint32_T>(nLeft) * sizeof
                    (int32_T));
      }

      nLeft = x_size[1];
      if (nLeft - 1 >= 0) {
        std::memset(&xwork_data[0], 0, static_cast<uint32_T>(nLeft) * sizeof
                    (uint16_T));
      }

      nLeft = nQuartets_tmp;
      nDone = 4;
      while (nLeft > 1) {
        if ((static_cast<uint32_T>(nLeft) & 1U) != 0U) {
          nLeft--;
          i2 = nDone * nLeft;
          i = x_size[1] - i2;
          if (i > nDone) {
            GNSSPreProcessingSingle_merge_o(idx_data, b_x_data, i2, nDone, i -
              nDone, iwork_data, xwork_data);
          }
        }

        i = nDone << 1;
        nLeft >>= 1;
        for (i2 = 0; i2 < nLeft; i2++) {
          GNSSPreProcessingSingle_merge_o(idx_data, b_x_data, i2 * i, nDone,
            nDone, iwork_data, xwork_data);
        }

        nDone = i;
      }

      if (x_size[1] > nDone) {
        GNSSPreProcessingSingle_merge_o(idx_data, b_x_data, 0, nDone, x_size[1]
          - nDone, iwork_data, xwork_data);
      }
    }
  }

  x_size[0] = 1;
  x_size[1] = b_x_size[1];
  nLeft = b_x_size[1];
  if (nLeft - 1 >= 0) {
    std::memcpy(&x_data[0], &b_x_data[0], static_cast<uint32_T>(nLeft) * sizeof
                (uint16_T));
  }
}

// Function for MATLAB Function: '<S11>/Simplify and Mask GPS Measurement Bus'
boolean_T GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_any_kl(const
  boolean_T x_data[], const int32_T *x_size)
{
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= *x_size)) {
    if (x_data[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  return y;
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_lw(real_T
  in1_data[], int32_T in1_size[2], const gnssraw_measurement_t *in2, const
  int8_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
  int32_T in4_size[2], const int32_T in5_data[], const int8_T in6_data[], const
  int32_T in6_size[2])
{
  real_T in2_data[200];
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
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    for (int32_T i{0}; i < 5; i++) {
      in2_data[i + 5 * i_0] = -in2->Doppler[(in3_data[aux_0_1] - 1) * 5 + i] *
        2.99792458E+8 / in4_data[5 * aux_1_1 + i];
    }

    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }

  in1_size[0] = 5;
  in1_size[1] = in6_size[1];
  loop_ub = in6_size[1];
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    for (int32_T i{0}; i < 5; i++) {
      in1_data[i + 5 * i_0] = in2_data[(in5_data[in6_data[i_0] - 1] - 1) * 5 + i];
    }
  }
}

// Function for MATLAB Function: '<S11>/Simplify and Mask GPS Measurement Bus'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_any_kle(const
  boolean_T x_data[], const int32_T x_size[2], boolean_T y_data[], int32_T
  y_size[2])
{
  int32_T c;
  int32_T i2;
  y_size[0] = 1;
  y_size[1] = static_cast<int8_T>(x_size[1]);
  i2 = static_cast<int8_T>(x_size[1]);
  if (i2 - 1 >= 0) {
    std::memset(&y_data[0], 0, static_cast<uint32_T>(i2) * sizeof(boolean_T));
  }

  i2 = 1;
  c = x_size[1];
  for (int32_T i{0}; i < c; i++) {
    int32_T a;
    int32_T ix;
    boolean_T exitg1;
    a = i2 + 4;
    ix = i2;
    i2 += 5;
    exitg1 = false;
    while ((!exitg1) && (ix <= a)) {
      if (x_data[ix - 1]) {
        y_data[i] = true;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }
}

void GNSS_preprocessingModelClass::emxConvertDynamicMatrixToEmx_37
  (emxArray_real_T_37_GNSSPrePro_T *emx, const real_T data[37], const int32_T
   *size)
{
  std::memcpy(&emx->data, (void *)data, sizeof(real_T) * static_cast<uint32_T>
              (*size));
  std::memcpy(&emx->size, (void *)size, sizeof(int32_T));
}

void GNSS_preprocessingModelClass::emxConvertStructToEmx_gnssops_n
  (emxArray__gnssops_navigation__T *emx, const gnssops_navigation_data *data,
   const gnssops_navigation_data_size *size)
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
  emxConvertDynamicMatrixToEmx_37(&emx->OMEGADOT, data->OMEGADOT,
    &size->OMEGADOT);
  emxConvertDynamicMatrixToEmx_37(&emx->IDOT, data->IDOT, &size->IDOT);
}

void GNSS_preprocessingModelClass::GNSSPreProce_binary_expand_op_l(boolean_T
  in1_data[], int32_T *in1_size, const gnssops_navigation_data *in2, const
  gnssops_navigation_data_size *in3, const uint16_T in4[40], int32_T in6)
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
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_0[i] = (in1_data[i * stride_0_0] || (in2->SVID[i * stride_1_0] ==
      in4_0));
  }

  *in1_size = in1_size_idx_0;
  if (in1_size_idx_0 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in1_data_0[0], static_cast<uint32_T>
                (in1_size_idx_0) * sizeof(boolean_T));
  }
}

// Function for MATLAB Function: '<S11>/Simplify and Mask GPS Measurement Bus'
void GNSS_preprocessingModelClass::GNSSPreP_select_navigation_data(const
  emxArray__gnssops_navigation__T *navigation_data, const boolean_T mask_data[],
  const int32_T *mask_size, b_gnssops_navigation_data_GNS_T
  *navigation_data_selected)
{
  int32_T b_size_idx_0;
  int32_T end_tmp;
  int32_T trueCount;
  int8_T b_data[37];
  int8_T c_data[37];
  int8_T d_data[37];
  int8_T e_data[37];
  int8_T f_data[37];
  int8_T g_data[37];
  int8_T h_data[37];
  int8_T i_data[37];
  int8_T j_data[37];
  int8_T k_data[37];
  int8_T l_data[37];
  int8_T m_data[37];
  int8_T n_data[37];
  int8_T o_data[37];
  int8_T p_data[37];
  int8_T q_data[37];
  int8_T r_data[37];
  int8_T s_data[37];
  int8_T t_data[37];
  int8_T u_data[37];
  int8_T v_data[37];
  int8_T w_data[37];
  int8_T x_data[37];
  int8_T y_data[37];
  end_tmp = *mask_size - 1;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      b_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->TOW.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->TOW.data[trueCount] = navigation_data->
      TOW.data[b_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      c_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->WNc.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->WNc.data[trueCount] = navigation_data->
      WNc.data[c_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      d_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->SVID.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->SVID.data[trueCount] = navigation_data->
      SVID.data[d_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      e_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->T_gd.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->T_gd.data[trueCount] = navigation_data->
      T_gd.data[e_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      f_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->T_oc.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->T_oc.data[trueCount] = navigation_data->
      T_oc.data[f_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      g_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->A_f2.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->A_f2.data[trueCount] = navigation_data->
      A_f2.data[g_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      h_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->A_f1.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->A_f1.data[trueCount] = navigation_data->
      A_f1.data[h_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      i_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->A_f0.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->A_f0.data[trueCount] = navigation_data->
      A_f0.data[i_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      j_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->C_rs.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->C_rs.data[trueCount] = navigation_data->
      C_rs.data[j_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      k_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->DELTA_N.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->DELTA_N.data[trueCount] =
      navigation_data->DELTA_N.data[k_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      l_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->M_0.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->M_0.data[trueCount] = navigation_data->
      M_0.data[l_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      m_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->C_uc.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->C_uc.data[trueCount] = navigation_data->
      C_uc.data[m_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      n_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->E.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->E.data[trueCount] = navigation_data->
      E.data[n_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      o_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->C_us.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->C_us.data[trueCount] = navigation_data->
      C_us.data[o_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      p_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->SQRT_A.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->SQRT_A.data[trueCount] =
      navigation_data->SQRT_A.data[p_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      q_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->T_oe.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->T_oe.data[trueCount] = navigation_data->
      T_oe.data[q_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      r_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->C_ic.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->C_ic.data[trueCount] = navigation_data->
      C_ic.data[r_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      s_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->OMEGA_0.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->OMEGA_0.data[trueCount] =
      navigation_data->OMEGA_0.data[s_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      t_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->C_is.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->C_is.data[trueCount] = navigation_data->
      C_is.data[t_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      u_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->I_0.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->I_0.data[trueCount] = navigation_data->
      I_0.data[u_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      v_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->C_rc.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->C_rc.data[trueCount] = navigation_data->
      C_rc.data[v_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      w_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->omega.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->omega.data[trueCount] =
      navigation_data->omega.data[w_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      x_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->OMEGADOT.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->OMEGADOT.data[trueCount] =
      navigation_data->OMEGADOT.data[x_data[trueCount] - 1];
  }

  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      trueCount++;
    }
  }

  b_size_idx_0 = trueCount;
  trueCount = 0;
  for (int32_T b_i{0}; b_i <= end_tmp; b_i++) {
    if (mask_data[b_i]) {
      y_data[trueCount] = static_cast<int8_T>(b_i + 1);
      trueCount++;
    }
  }

  navigation_data_selected->IDOT.size = b_size_idx_0;
  for (trueCount = 0; trueCount < b_size_idx_0; trueCount++) {
    navigation_data_selected->IDOT.data[trueCount] = navigation_data->
      IDOT.data[y_data[trueCount] - 1];
  }
}

// Output and update for atomic system: '<S11>/Simplify and Mask GPS Measurement Bus'
void GNSS_preprocessingModelClass::SimplifyandMaskGPSMeasurementBu(const
  gnssraw_measurement_t *rtu_GpsMeasurementBus, const gnssops_navigation_data
  *rtu_GpsNavBusReshaped, const gnssops_navigation_data_size
  *rtu_GpsNavBusReshaped_DIMS1, const parameters_gps_t *rtu_parameters_gps_Bus,
  B_SimplifyandMaskGPSMeasureme_T *localB, DW_SimplifyandMaskGPSMeasurem_T
  *localDW)
{
  static const int32_T gnss_frequency[4]{ 1575420000, 1227600000, 1176450000, 1
  };

  real_T gnss_freq_Matrix_data[200];
  real_T tmp_cp_data[200];
  real_T tmp_cp_sigma_data[200];
  real_T tmp_dr_data[200];
  real_T tmp_pr_data[200];
  real_T tmp_pr_sigma_data[200];
  int32_T iidx_data[40];
  int32_T ec_data[4];
  int32_T L1_mask_size[2];
  int32_T L2C_mask_size[2];
  int32_T L5_mask_size[2];
  int32_T a__1_size[2];
  int32_T db_size[2];
  int32_T ec_size[2];
  int32_T gnss_freq_Matrix_size[2];
  int32_T u_size[2];
  int32_T c_i;
  int32_T c_trueCount_tmp;
  int32_T loop_ub;
  int32_T n_size_idx_1;
  int32_T o_size_idx_1;
  int32_T tmp_svid;
  int32_T trueCount;
  int32_T w_size_idx_1;
  real32_T tmp_Locktime_data[200];
  uint16_T a__1_data[40];
  uint16_T f_data[40];
  uint16_T h_data[40];
  uint16_T l_data[40];
  uint16_T tmp_svid_data[40];
  int8_T ab_data[40];
  int8_T bb_data[40];
  int8_T cb_data[40];
  int8_T db_data[40];
  int8_T eb_data[40];
  int8_T n_data[40];
  int8_T o_data[40];
  int8_T p_data[40];
  int8_T q_data[40];
  int8_T r_data[40];
  int8_T s_data[40];
  int8_T t_data[40];
  int8_T u_data[40];
  int8_T v_data[40];
  int8_T w_data[40];
  int8_T x_data[40];
  int8_T y_data[40];
  uint8_T ac_data[200];
  uint8_T fb_data[200];
  uint8_T gb_data[200];
  uint8_T hb_data[200];
  uint8_T ib_data[200];
  uint8_T jb_data[200];
  uint8_T kb_data[200];
  uint8_T lb_data[200];
  uint8_T mb_data[200];
  uint8_T nb_data[200];
  uint8_T ob_data[200];
  uint8_T pb_data[200];
  uint8_T qb_data[200];
  uint8_T rb_data[200];
  uint8_T sb_data[200];
  uint8_T tb_data[200];
  uint8_T tmp_type_data[200];
  uint8_T ub_data[200];
  uint8_T vb_data[200];
  uint8_T wb_data[200];
  uint8_T xb_data[200];
  uint8_T yb_data[200];
  boolean_T L1_mask_data[200];
  boolean_T L2C_mask_data[200];
  boolean_T L5_mask_data[200];
  boolean_T dc[40];
  boolean_T mask_available_SV_data[40];
  boolean_T tmp[40];
  boolean_T mask_navdata_L1_data[37];
  boolean_T rtu_GpsMeasurementBus_0[4];
  for (trueCount = 0; trueCount < 200; trueCount++) {
    L1_mask_data[trueCount] = (rtu_GpsMeasurementBus->Type[trueCount] == 0);
  }

  GNSSPreProcessingSingleAn_any_k(L1_mask_data, mask_available_SV_data);
  for (trueCount = 0; trueCount < 200; trueCount++) {
    L1_mask_data[trueCount] = (rtu_GpsMeasurementBus->Type[trueCount] == 3);
  }

  GNSSPreProcessingSingleAn_any_k(L1_mask_data, tmp);
  for (trueCount = 0; trueCount < 40; trueCount++) {
    dc[trueCount] = ((mask_available_SV_data[trueCount] &&
                      rtu_parameters_gps_Bus->enable_gps_l1) || (tmp[trueCount] &&
      rtu_parameters_gps_Bus->enable_gps_l2));
  }

  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      trueCount++;
    }
  }

  n_size_idx_1 = trueCount;
  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      n_data[trueCount] = static_cast<int8_T>(c_i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < n_size_idx_1; trueCount++) {
    tmp_svid_data[trueCount] = rtu_GpsMeasurementBus->SVID[n_data[trueCount] - 1];
  }

  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      trueCount++;
    }
  }

  o_size_idx_1 = trueCount;
  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      o_data[trueCount] = static_cast<int8_T>(c_i + 1);
      trueCount++;
    }
  }

  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      p_data[trueCount] = static_cast<int8_T>(c_i + 1);
      trueCount++;
    }
  }

  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      q_data[trueCount] = static_cast<int8_T>(c_i + 1);
      trueCount++;
    }
  }

  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      r_data[trueCount] = static_cast<int8_T>(c_i + 1);
      trueCount++;
    }
  }

  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      s_data[trueCount] = static_cast<int8_T>(c_i + 1);
      trueCount++;
    }
  }

  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      t_data[trueCount] = static_cast<int8_T>(c_i + 1);
      trueCount++;
    }
  }

  gnss_freq_Matrix_size[0] = 5;
  gnss_freq_Matrix_size[1] = static_cast<int8_T>(o_size_idx_1);
  loop_ub = 5 * static_cast<int8_T>(o_size_idx_1);
  for (trueCount = 0; trueCount < loop_ub; trueCount++) {
    gnss_freq_Matrix_data[trueCount] = 1.0;
  }

  for (c_i = 0; c_i < o_size_idx_1; c_i++) {
    for (trueCount = 0; trueCount < 5; trueCount++) {
      loop_ub = rtu_GpsMeasurementBus->Type[(o_data[c_i] - 1) * 5 + trueCount];
      rtu_GpsMeasurementBus_0[0] = (loop_ub == 0);
      rtu_GpsMeasurementBus_0[1] = (loop_ub == 3);
      rtu_GpsMeasurementBus_0[2] = (loop_ub == 4);
      rtu_GpsMeasurementBus_0[3] = (loop_ub == 255);
      GNSSPreProcessingSingl_eml_find(rtu_GpsMeasurementBus_0, ec_data, ec_size);
      if (ec_size[1] != 0) {
        gnss_freq_Matrix_data[trueCount + 5 * c_i] = gnss_frequency[ec_data[0] -
          1];
      }
    }
  }

  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      trueCount++;
    }
  }

  u_size[0] = 1;
  u_size[1] = trueCount;
  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      u_data[trueCount] = static_cast<int8_T>(c_i + 1);
      trueCount++;
    }
  }

  trueCount = 0;
  for (c_i = 0; c_i < 40; c_i++) {
    if (dc[c_i]) {
      v_data[trueCount] = static_cast<int8_T>(c_i + 1);
      trueCount++;
    }
  }

  a__1_size[0] = 1;
  a__1_size[1] = n_size_idx_1;
  if (n_size_idx_1 - 1 >= 0) {
    std::memcpy(&a__1_data[0], &tmp_svid_data[0], static_cast<uint32_T>
                (n_size_idx_1) * sizeof(uint16_T));
  }

  GNSSPreProcessingSingleA_sort_n(a__1_data, a__1_size, iidx_data, ec_size);
  loop_ub = ec_size[1];
  for (trueCount = 0; trueCount < loop_ub; trueCount++) {
    a__1_data[trueCount] = tmp_svid_data[iidx_data[trueCount] - 1];
  }

  n_size_idx_1 = ec_size[1];
  loop_ub = ec_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&tmp_svid_data[0], &a__1_data[0], static_cast<uint32_T>(loop_ub)
                * sizeof(uint16_T));
  }

  if (n_size_idx_1 - 1 >= 0) {
    std::memset(&mask_available_SV_data[0], 0, static_cast<uint32_T>
                (n_size_idx_1) * sizeof(boolean_T));
  }

  for (c_i = 0; c_i < n_size_idx_1; c_i++) {
    tmp_svid = tmp_svid_data[c_i];
    loop_ub = rtu_GpsNavBusReshaped_DIMS1->SVID;
    for (trueCount = 0; trueCount < loop_ub; trueCount++) {
      mask_navdata_L1_data[trueCount] = (rtu_GpsNavBusReshaped->SVID[trueCount] ==
        tmp_svid);
    }

    if (GNSSPreProcessingSingleA_any_kl(mask_navdata_L1_data,
         &rtu_GpsNavBusReshaped_DIMS1->SVID)) {
      mask_available_SV_data[c_i] = true;
    }
  }

  c_trueCount_tmp = ec_size[1] - 1;
  c_i = 0;
  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      c_i++;
      tmp_svid_data[loop_ub] = tmp_svid_data[trueCount];
      loop_ub++;
    }
  }

  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      loop_ub++;
    }
  }

  w_size_idx_1 = loop_ub;
  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      w_data[loop_ub] = static_cast<int8_T>(trueCount + 1);
      loop_ub++;
    }
  }

  for (trueCount = 0; trueCount < w_size_idx_1; trueCount++) {
    for (n_size_idx_1 = 0; n_size_idx_1 < 5; n_size_idx_1++) {
      tmp_type_data[n_size_idx_1 + 5 * trueCount] = rtu_GpsMeasurementBus->Type
        [(o_data[iidx_data[w_data[trueCount] - 1] - 1] - 1) * 5 + n_size_idx_1];
    }
  }

  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      loop_ub++;
    }
  }

  tmp_svid = loop_ub;
  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      x_data[loop_ub] = static_cast<int8_T>(trueCount + 1);
      loop_ub++;
    }
  }

  for (trueCount = 0; trueCount < tmp_svid; trueCount++) {
    for (n_size_idx_1 = 0; n_size_idx_1 < 5; n_size_idx_1++) {
      tmp_pr_data[n_size_idx_1 + 5 * trueCount] =
        rtu_GpsMeasurementBus->Pseudorange[(p_data[iidx_data[x_data[trueCount] -
        1] - 1] - 1) * 5 + n_size_idx_1];
    }
  }

  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      loop_ub++;
    }
  }

  tmp_svid = loop_ub;
  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      y_data[loop_ub] = static_cast<int8_T>(trueCount + 1);
      loop_ub++;
    }
  }

  for (trueCount = 0; trueCount < tmp_svid; trueCount++) {
    for (n_size_idx_1 = 0; n_size_idx_1 < 5; n_size_idx_1++) {
      tmp_pr_sigma_data[n_size_idx_1 + 5 * trueCount] =
        rtu_GpsMeasurementBus->Pseudorange_Sigma
        [(q_data[iidx_data[y_data[trueCount] - 1] - 1] - 1) * 5 + n_size_idx_1];
    }
  }

  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      loop_ub++;
    }
  }

  tmp_svid = loop_ub;
  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      ab_data[loop_ub] = static_cast<int8_T>(trueCount + 1);
      loop_ub++;
    }
  }

  for (trueCount = 0; trueCount < tmp_svid; trueCount++) {
    for (n_size_idx_1 = 0; n_size_idx_1 < 5; n_size_idx_1++) {
      tmp_cp_data[n_size_idx_1 + 5 * trueCount] = rtu_GpsMeasurementBus->
        Carrier[(r_data[iidx_data[ab_data[trueCount] - 1] - 1] - 1) * 5 +
        n_size_idx_1];
    }
  }

  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      loop_ub++;
    }
  }

  tmp_svid = loop_ub;
  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      bb_data[loop_ub] = static_cast<int8_T>(trueCount + 1);
      loop_ub++;
    }
  }

  for (trueCount = 0; trueCount < tmp_svid; trueCount++) {
    for (n_size_idx_1 = 0; n_size_idx_1 < 5; n_size_idx_1++) {
      tmp_cp_sigma_data[n_size_idx_1 + 5 * trueCount] =
        rtu_GpsMeasurementBus->Carrier_Sigma[(s_data[iidx_data[bb_data[trueCount]
        - 1] - 1] - 1) * 5 + n_size_idx_1];
    }
  }

  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      loop_ub++;
    }
  }

  tmp_svid = loop_ub;
  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      cb_data[loop_ub] = static_cast<int8_T>(trueCount + 1);
      loop_ub++;
    }
  }

  for (trueCount = 0; trueCount < tmp_svid; trueCount++) {
    for (n_size_idx_1 = 0; n_size_idx_1 < 5; n_size_idx_1++) {
      tmp_Locktime_data[n_size_idx_1 + 5 * trueCount] =
        rtu_GpsMeasurementBus->Locktime[(t_data[iidx_data[cb_data[trueCount] - 1]
        - 1] - 1) * 5 + n_size_idx_1];
    }
  }

  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      loop_ub++;
    }
  }

  db_size[0] = 1;
  db_size[1] = loop_ub;
  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      db_data[loop_ub] = static_cast<int8_T>(trueCount + 1);
      loop_ub++;
    }
  }

  if (u_size[1] == static_cast<int8_T>(o_size_idx_1)) {
    loop_ub = db_size[1];
    for (trueCount = 0; trueCount < loop_ub; trueCount++) {
      for (n_size_idx_1 = 0; n_size_idx_1 < 5; n_size_idx_1++) {
        tmp_svid = iidx_data[db_data[trueCount] - 1] - 1;
        tmp_dr_data[n_size_idx_1 + 5 * trueCount] =
          -rtu_GpsMeasurementBus->Doppler[(u_data[tmp_svid] - 1) * 5 +
          n_size_idx_1] * 2.99792458E+8 / gnss_freq_Matrix_data[5 * tmp_svid +
          n_size_idx_1];
      }
    }
  } else {
    GNSSPreProc_binary_expand_op_lw(tmp_dr_data, a__1_size,
      rtu_GpsMeasurementBus, u_data, u_size, gnss_freq_Matrix_data,
      gnss_freq_Matrix_size, iidx_data, db_data, db_size);
  }

  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      loop_ub++;
    }
  }

  o_size_idx_1 = loop_ub;
  loop_ub = 0;
  for (trueCount = 0; trueCount <= c_trueCount_tmp; trueCount++) {
    if (mask_available_SV_data[trueCount]) {
      eb_data[loop_ub] = static_cast<int8_T>(trueCount + 1);
      loop_ub++;
    }
  }

  for (trueCount = 0; trueCount < o_size_idx_1; trueCount++) {
    for (n_size_idx_1 = 0; n_size_idx_1 < 5; n_size_idx_1++) {
      gnss_freq_Matrix_data[n_size_idx_1 + 5 * trueCount] =
        rtu_GpsMeasurementBus->CN0[(v_data[iidx_data[eb_data[trueCount] - 1] - 1]
        - 1) * 5 + n_size_idx_1];
    }
  }

  L1_mask_size[0] = 5;
  L1_mask_size[1] = static_cast<int8_T>(w_size_idx_1);
  trueCount = 5 * static_cast<int8_T>(w_size_idx_1);
  if (trueCount - 1 >= 0) {
    std::memset(&L1_mask_data[0], 0, static_cast<uint32_T>(trueCount) * sizeof
                (boolean_T));
  }

  L2C_mask_size[0] = 5;
  L2C_mask_size[1] = static_cast<int8_T>(w_size_idx_1);
  if (trueCount - 1 >= 0) {
    std::memset(&L2C_mask_data[0], 0, static_cast<uint32_T>(trueCount) * sizeof
                (boolean_T));
  }

  L5_mask_size[0] = 5;
  L5_mask_size[1] = static_cast<int8_T>(w_size_idx_1);
  if (trueCount - 1 >= 0) {
    std::memset(&L5_mask_data[0], 0, static_cast<uint32_T>(trueCount) * sizeof
                (boolean_T));
  }

  for (n_size_idx_1 = 0; n_size_idx_1 < c_i; n_size_idx_1++) {
    for (trueCount = 0; trueCount < 5; trueCount++) {
      uint8_T tmp_type;
      loop_ub = 5 * n_size_idx_1 + trueCount;
      tmp_type = tmp_type_data[loop_ub];
      L1_mask_data[loop_ub] = (tmp_type == 0);
      L2C_mask_data[loop_ub] = (tmp_type == 3);
      L5_mask_data[loop_ub] = (tmp_type == 4);
    }
  }

  GNSSPreProcessingSingle_any_kle(L1_mask_data, L1_mask_size,
    mask_available_SV_data, gnss_freq_Matrix_size);
  trueCount = gnss_freq_Matrix_size[1] - 1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (mask_available_SV_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS3 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (mask_available_SV_data[c_i]) {
      f_data[n_size_idx_1] = tmp_svid_data[c_i];
      n_size_idx_1++;
    }
  }

  if (localDW->SFunction_DIMS3 - 1 >= 0) {
    std::memcpy(&a__1_data[0], &f_data[0], static_cast<uint32_T>
                (localDW->SFunction_DIMS3) * sizeof(uint16_T));
  }

  if (localDW->SFunction_DIMS3 - 1 >= 0) {
    std::memcpy(&localB->svid_L1[0], &a__1_data[0], static_cast<uint32_T>
                (localDW->SFunction_DIMS3) * sizeof(uint16_T));
  }

  trueCount = 5 * static_cast<int8_T>(w_size_idx_1) - 1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS5 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      fb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS6 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      gb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS9 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      hb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS10 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      ib_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS11 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      jb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS7 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      kb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS8 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L1_mask_data[c_i]) {
      lb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  o_size_idx_1 = rtu_GpsNavBusReshaped_DIMS1->SVID;
  if (rtu_GpsNavBusReshaped_DIMS1->SVID - 1 >= 0) {
    std::memset(&mask_navdata_L1_data[0], 0, static_cast<uint32_T>
                (rtu_GpsNavBusReshaped_DIMS1->SVID) * sizeof(boolean_T));
  }

  for (c_i = 0; c_i < localDW->SFunction_DIMS3; c_i++) {
    if (o_size_idx_1 == rtu_GpsNavBusReshaped_DIMS1->SVID) {
      trueCount = localB->svid_L1[c_i];
      for (n_size_idx_1 = 0; n_size_idx_1 < o_size_idx_1; n_size_idx_1++) {
        mask_navdata_L1_data[n_size_idx_1] = (mask_navdata_L1_data[n_size_idx_1]
          || (rtu_GpsNavBusReshaped->SVID[n_size_idx_1] == trueCount));
      }
    } else {
      GNSSPreProce_binary_expand_op_l(mask_navdata_L1_data, &o_size_idx_1,
        rtu_GpsNavBusReshaped, rtu_GpsNavBusReshaped_DIMS1, localB->svid_L1, c_i);
    }
  }

  localB->r3 = *rtu_GpsNavBusReshaped;
  emxConvertStructToEmx_gnssops_n(&localB->r, &localB->r3,
    rtu_GpsNavBusReshaped_DIMS1);
  GNSSPreP_select_navigation_data(&localB->r, mask_navdata_L1_data,
    &o_size_idx_1, &localB->expl_temp);
  localDW->SFunction_DIMS4.TOW = localB->expl_temp.TOW.size;
  loop_ub = localB->expl_temp.TOW.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.TOW[0], &localB->expl_temp.TOW.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.WNc = localB->expl_temp.WNc.size;
  loop_ub = localB->expl_temp.WNc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.WNc[0], &localB->expl_temp.WNc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.SVID = localB->expl_temp.SVID.size;
  loop_ub = localB->expl_temp.SVID.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.SVID[0], &localB->expl_temp.SVID.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.T_gd = localB->expl_temp.T_gd.size;
  loop_ub = localB->expl_temp.T_gd.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.T_gd[0], &localB->expl_temp.T_gd.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.T_oc = localB->expl_temp.T_oc.size;
  loop_ub = localB->expl_temp.T_oc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.T_oc[0], &localB->expl_temp.T_oc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.A_f2 = localB->expl_temp.A_f2.size;
  loop_ub = localB->expl_temp.A_f2.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.A_f2[0], &localB->expl_temp.A_f2.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.A_f1 = localB->expl_temp.A_f1.size;
  loop_ub = localB->expl_temp.A_f1.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.A_f1[0], &localB->expl_temp.A_f1.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.A_f0 = localB->expl_temp.A_f0.size;
  loop_ub = localB->expl_temp.A_f0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.A_f0[0], &localB->expl_temp.A_f0.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.C_rs = localB->expl_temp.C_rs.size;
  loop_ub = localB->expl_temp.C_rs.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.C_rs[0], &localB->expl_temp.C_rs.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.DELTA_N = localB->expl_temp.DELTA_N.size;
  loop_ub = localB->expl_temp.DELTA_N.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.DELTA_N[0], &localB->expl_temp.DELTA_N.data
                [0], static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.M_0 = localB->expl_temp.M_0.size;
  loop_ub = localB->expl_temp.M_0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.M_0[0], &localB->expl_temp.M_0.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.C_uc = localB->expl_temp.C_uc.size;
  loop_ub = localB->expl_temp.C_uc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.C_uc[0], &localB->expl_temp.C_uc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.E = localB->expl_temp.E.size;
  loop_ub = localB->expl_temp.E.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.E[0], &localB->expl_temp.E.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.C_us = localB->expl_temp.C_us.size;
  loop_ub = localB->expl_temp.C_us.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.C_us[0], &localB->expl_temp.C_us.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.SQRT_A = localB->expl_temp.SQRT_A.size;
  loop_ub = localB->expl_temp.SQRT_A.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.SQRT_A[0], &localB->expl_temp.SQRT_A.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.T_oe = localB->expl_temp.T_oe.size;
  loop_ub = localB->expl_temp.T_oe.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.T_oe[0], &localB->expl_temp.T_oe.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.C_ic = localB->expl_temp.C_ic.size;
  loop_ub = localB->expl_temp.C_ic.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.C_ic[0], &localB->expl_temp.C_ic.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.OMEGA_0 = localB->expl_temp.OMEGA_0.size;
  loop_ub = localB->expl_temp.OMEGA_0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.OMEGA_0[0], &localB->expl_temp.OMEGA_0.data
                [0], static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.C_is = localB->expl_temp.C_is.size;
  loop_ub = localB->expl_temp.C_is.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.C_is[0], &localB->expl_temp.C_is.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.I_0 = localB->expl_temp.I_0.size;
  loop_ub = localB->expl_temp.I_0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.I_0[0], &localB->expl_temp.I_0.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.C_rc = localB->expl_temp.C_rc.size;
  loop_ub = localB->expl_temp.C_rc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.C_rc[0], &localB->expl_temp.C_rc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.omega = localB->expl_temp.omega.size;
  loop_ub = localB->expl_temp.omega.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.omega[0], &localB->expl_temp.omega.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.OMEGADOT = localB->expl_temp.OMEGADOT.size;
  loop_ub = localB->expl_temp.OMEGADOT.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.OMEGADOT[0],
                &localB->expl_temp.OMEGADOT.data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS4.IDOT = localB->expl_temp.IDOT.size;
  loop_ub = localB->expl_temp.IDOT.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L1.IDOT[0], &localB->expl_temp.IDOT.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  GNSSPreProcessingSingle_any_kle(L2C_mask_data, L2C_mask_size,
    mask_available_SV_data, gnss_freq_Matrix_size);
  trueCount = gnss_freq_Matrix_size[1] - 1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (mask_available_SV_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS12 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (mask_available_SV_data[c_i]) {
      h_data[n_size_idx_1] = tmp_svid_data[c_i];
      n_size_idx_1++;
    }
  }

  if (localDW->SFunction_DIMS12 - 1 >= 0) {
    std::memcpy(&a__1_data[0], &h_data[0], static_cast<uint32_T>
                (localDW->SFunction_DIMS12) * sizeof(uint16_T));
  }

  if (localDW->SFunction_DIMS12 - 1 >= 0) {
    std::memcpy(&localB->svid_L2C[0], &a__1_data[0], static_cast<uint32_T>
                (localDW->SFunction_DIMS12) * sizeof(uint16_T));
  }

  trueCount = 5 * static_cast<int8_T>(w_size_idx_1) - 1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS14 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      mb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS15 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      nb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS18 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      ob_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS19 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      pb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS20 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      qb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS16 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      rb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS17 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L2C_mask_data[c_i]) {
      sb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  o_size_idx_1 = rtu_GpsNavBusReshaped_DIMS1->SVID;
  if (rtu_GpsNavBusReshaped_DIMS1->SVID - 1 >= 0) {
    std::memset(&mask_navdata_L1_data[0], 0, static_cast<uint32_T>
                (rtu_GpsNavBusReshaped_DIMS1->SVID) * sizeof(boolean_T));
  }

  for (c_i = 0; c_i < localDW->SFunction_DIMS12; c_i++) {
    if (o_size_idx_1 == rtu_GpsNavBusReshaped_DIMS1->SVID) {
      trueCount = localB->svid_L2C[c_i];
      for (n_size_idx_1 = 0; n_size_idx_1 < o_size_idx_1; n_size_idx_1++) {
        mask_navdata_L1_data[n_size_idx_1] = (mask_navdata_L1_data[n_size_idx_1]
          || (rtu_GpsNavBusReshaped->SVID[n_size_idx_1] == trueCount));
      }
    } else {
      GNSSPreProce_binary_expand_op_l(mask_navdata_L1_data, &o_size_idx_1,
        rtu_GpsNavBusReshaped, rtu_GpsNavBusReshaped_DIMS1, localB->svid_L2C,
        c_i);
    }
  }

  localB->r3 = *rtu_GpsNavBusReshaped;
  emxConvertStructToEmx_gnssops_n(&localB->r1, &localB->r3,
    rtu_GpsNavBusReshaped_DIMS1);
  GNSSPreP_select_navigation_data(&localB->r1, mask_navdata_L1_data,
    &o_size_idx_1, &localB->expl_temp);
  localDW->SFunction_DIMS13.TOW = localB->expl_temp.TOW.size;
  loop_ub = localB->expl_temp.TOW.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.TOW[0], &localB->expl_temp.TOW.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.WNc = localB->expl_temp.WNc.size;
  loop_ub = localB->expl_temp.WNc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.WNc[0], &localB->expl_temp.WNc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.SVID = localB->expl_temp.SVID.size;
  loop_ub = localB->expl_temp.SVID.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.SVID[0], &localB->expl_temp.SVID.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.T_gd = localB->expl_temp.T_gd.size;
  loop_ub = localB->expl_temp.T_gd.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.T_gd[0], &localB->expl_temp.T_gd.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.T_oc = localB->expl_temp.T_oc.size;
  loop_ub = localB->expl_temp.T_oc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.T_oc[0], &localB->expl_temp.T_oc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.A_f2 = localB->expl_temp.A_f2.size;
  loop_ub = localB->expl_temp.A_f2.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.A_f2[0], &localB->expl_temp.A_f2.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.A_f1 = localB->expl_temp.A_f1.size;
  loop_ub = localB->expl_temp.A_f1.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.A_f1[0], &localB->expl_temp.A_f1.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.A_f0 = localB->expl_temp.A_f0.size;
  loop_ub = localB->expl_temp.A_f0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.A_f0[0], &localB->expl_temp.A_f0.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.C_rs = localB->expl_temp.C_rs.size;
  loop_ub = localB->expl_temp.C_rs.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.C_rs[0], &localB->expl_temp.C_rs.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.DELTA_N = localB->expl_temp.DELTA_N.size;
  loop_ub = localB->expl_temp.DELTA_N.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.DELTA_N[0], &localB->
                expl_temp.DELTA_N.data[0], static_cast<uint32_T>(loop_ub) *
                sizeof(real_T));
  }

  localDW->SFunction_DIMS13.M_0 = localB->expl_temp.M_0.size;
  loop_ub = localB->expl_temp.M_0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.M_0[0], &localB->expl_temp.M_0.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.C_uc = localB->expl_temp.C_uc.size;
  loop_ub = localB->expl_temp.C_uc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.C_uc[0], &localB->expl_temp.C_uc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.E = localB->expl_temp.E.size;
  loop_ub = localB->expl_temp.E.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.E[0], &localB->expl_temp.E.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.C_us = localB->expl_temp.C_us.size;
  loop_ub = localB->expl_temp.C_us.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.C_us[0], &localB->expl_temp.C_us.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.SQRT_A = localB->expl_temp.SQRT_A.size;
  loop_ub = localB->expl_temp.SQRT_A.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.SQRT_A[0], &localB->expl_temp.SQRT_A.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.T_oe = localB->expl_temp.T_oe.size;
  loop_ub = localB->expl_temp.T_oe.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.T_oe[0], &localB->expl_temp.T_oe.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.C_ic = localB->expl_temp.C_ic.size;
  loop_ub = localB->expl_temp.C_ic.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.C_ic[0], &localB->expl_temp.C_ic.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.OMEGA_0 = localB->expl_temp.OMEGA_0.size;
  loop_ub = localB->expl_temp.OMEGA_0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.OMEGA_0[0], &localB->
                expl_temp.OMEGA_0.data[0], static_cast<uint32_T>(loop_ub) *
                sizeof(real_T));
  }

  localDW->SFunction_DIMS13.C_is = localB->expl_temp.C_is.size;
  loop_ub = localB->expl_temp.C_is.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.C_is[0], &localB->expl_temp.C_is.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.I_0 = localB->expl_temp.I_0.size;
  loop_ub = localB->expl_temp.I_0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.I_0[0], &localB->expl_temp.I_0.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.C_rc = localB->expl_temp.C_rc.size;
  loop_ub = localB->expl_temp.C_rc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.C_rc[0], &localB->expl_temp.C_rc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.omega = localB->expl_temp.omega.size;
  loop_ub = localB->expl_temp.omega.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.omega[0], &localB->expl_temp.omega.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.OMEGADOT = localB->expl_temp.OMEGADOT.size;
  loop_ub = localB->expl_temp.OMEGADOT.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.OMEGADOT[0],
                &localB->expl_temp.OMEGADOT.data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS13.IDOT = localB->expl_temp.IDOT.size;
  loop_ub = localB->expl_temp.IDOT.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L2C.IDOT[0], &localB->expl_temp.IDOT.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  GNSSPreProcessingSingle_any_kle(L5_mask_data, L5_mask_size,
    mask_available_SV_data, gnss_freq_Matrix_size);
  trueCount = gnss_freq_Matrix_size[1] - 1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (mask_available_SV_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS21 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (mask_available_SV_data[c_i]) {
      l_data[n_size_idx_1] = tmp_svid_data[c_i];
      n_size_idx_1++;
    }
  }

  if (localDW->SFunction_DIMS21 - 1 >= 0) {
    std::memcpy(&a__1_data[0], &l_data[0], static_cast<uint32_T>
                (localDW->SFunction_DIMS21) * sizeof(uint16_T));
  }

  if (localDW->SFunction_DIMS21 - 1 >= 0) {
    std::memcpy(&localB->svid_L5[0], &a__1_data[0], static_cast<uint32_T>
                (localDW->SFunction_DIMS21) * sizeof(uint16_T));
  }

  trueCount = 5 * static_cast<int8_T>(w_size_idx_1) - 1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS23 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      tb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS24 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      ub_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS27 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      vb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS28 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      wb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS29 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      xb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS25 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      yb_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      n_size_idx_1++;
    }
  }

  localDW->SFunction_DIMS26 = n_size_idx_1;
  n_size_idx_1 = 0;
  for (c_i = 0; c_i <= trueCount; c_i++) {
    if (L5_mask_data[c_i]) {
      ac_data[n_size_idx_1] = static_cast<uint8_T>(c_i + 1);
      n_size_idx_1++;
    }
  }

  o_size_idx_1 = rtu_GpsNavBusReshaped_DIMS1->SVID;
  if (rtu_GpsNavBusReshaped_DIMS1->SVID - 1 >= 0) {
    std::memset(&mask_navdata_L1_data[0], 0, static_cast<uint32_T>
                (rtu_GpsNavBusReshaped_DIMS1->SVID) * sizeof(boolean_T));
  }

  for (c_i = 0; c_i < localDW->SFunction_DIMS21; c_i++) {
    if (o_size_idx_1 == rtu_GpsNavBusReshaped_DIMS1->SVID) {
      trueCount = localB->svid_L5[c_i];
      for (n_size_idx_1 = 0; n_size_idx_1 < o_size_idx_1; n_size_idx_1++) {
        mask_navdata_L1_data[n_size_idx_1] = (mask_navdata_L1_data[n_size_idx_1]
          || (rtu_GpsNavBusReshaped->SVID[n_size_idx_1] == trueCount));
      }
    } else {
      GNSSPreProce_binary_expand_op_l(mask_navdata_L1_data, &o_size_idx_1,
        rtu_GpsNavBusReshaped, rtu_GpsNavBusReshaped_DIMS1, localB->svid_L5, c_i);
    }
  }

  localB->r3 = *rtu_GpsNavBusReshaped;
  emxConvertStructToEmx_gnssops_n(&localB->r2, &localB->r3,
    rtu_GpsNavBusReshaped_DIMS1);
  GNSSPreP_select_navigation_data(&localB->r2, mask_navdata_L1_data,
    &o_size_idx_1, &localB->expl_temp);
  localDW->SFunction_DIMS22.TOW = localB->expl_temp.TOW.size;
  loop_ub = localB->expl_temp.TOW.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.TOW[0], &localB->expl_temp.TOW.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.WNc = localB->expl_temp.WNc.size;
  loop_ub = localB->expl_temp.WNc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.WNc[0], &localB->expl_temp.WNc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.SVID = localB->expl_temp.SVID.size;
  loop_ub = localB->expl_temp.SVID.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.SVID[0], &localB->expl_temp.SVID.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.T_gd = localB->expl_temp.T_gd.size;
  loop_ub = localB->expl_temp.T_gd.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.T_gd[0], &localB->expl_temp.T_gd.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.T_oc = localB->expl_temp.T_oc.size;
  loop_ub = localB->expl_temp.T_oc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.T_oc[0], &localB->expl_temp.T_oc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.A_f2 = localB->expl_temp.A_f2.size;
  loop_ub = localB->expl_temp.A_f2.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.A_f2[0], &localB->expl_temp.A_f2.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.A_f1 = localB->expl_temp.A_f1.size;
  loop_ub = localB->expl_temp.A_f1.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.A_f1[0], &localB->expl_temp.A_f1.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.A_f0 = localB->expl_temp.A_f0.size;
  loop_ub = localB->expl_temp.A_f0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.A_f0[0], &localB->expl_temp.A_f0.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.C_rs = localB->expl_temp.C_rs.size;
  loop_ub = localB->expl_temp.C_rs.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.C_rs[0], &localB->expl_temp.C_rs.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.DELTA_N = localB->expl_temp.DELTA_N.size;
  loop_ub = localB->expl_temp.DELTA_N.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.DELTA_N[0], &localB->expl_temp.DELTA_N.data
                [0], static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.M_0 = localB->expl_temp.M_0.size;
  loop_ub = localB->expl_temp.M_0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.M_0[0], &localB->expl_temp.M_0.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.C_uc = localB->expl_temp.C_uc.size;
  loop_ub = localB->expl_temp.C_uc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.C_uc[0], &localB->expl_temp.C_uc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.E = localB->expl_temp.E.size;
  loop_ub = localB->expl_temp.E.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.E[0], &localB->expl_temp.E.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.C_us = localB->expl_temp.C_us.size;
  loop_ub = localB->expl_temp.C_us.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.C_us[0], &localB->expl_temp.C_us.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.SQRT_A = localB->expl_temp.SQRT_A.size;
  loop_ub = localB->expl_temp.SQRT_A.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.SQRT_A[0], &localB->expl_temp.SQRT_A.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.T_oe = localB->expl_temp.T_oe.size;
  loop_ub = localB->expl_temp.T_oe.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.T_oe[0], &localB->expl_temp.T_oe.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.C_ic = localB->expl_temp.C_ic.size;
  loop_ub = localB->expl_temp.C_ic.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.C_ic[0], &localB->expl_temp.C_ic.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.OMEGA_0 = localB->expl_temp.OMEGA_0.size;
  loop_ub = localB->expl_temp.OMEGA_0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.OMEGA_0[0], &localB->expl_temp.OMEGA_0.data
                [0], static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.C_is = localB->expl_temp.C_is.size;
  loop_ub = localB->expl_temp.C_is.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.C_is[0], &localB->expl_temp.C_is.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.I_0 = localB->expl_temp.I_0.size;
  loop_ub = localB->expl_temp.I_0.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.I_0[0], &localB->expl_temp.I_0.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.C_rc = localB->expl_temp.C_rc.size;
  loop_ub = localB->expl_temp.C_rc.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.C_rc[0], &localB->expl_temp.C_rc.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.omega = localB->expl_temp.omega.size;
  loop_ub = localB->expl_temp.omega.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.omega[0], &localB->expl_temp.omega.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.OMEGADOT = localB->expl_temp.OMEGADOT.size;
  loop_ub = localB->expl_temp.OMEGADOT.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.OMEGADOT[0],
                &localB->expl_temp.OMEGADOT.data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS22.IDOT = localB->expl_temp.IDOT.size;
  loop_ub = localB->expl_temp.IDOT.size;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->navdata_L5.IDOT[0], &localB->expl_temp.IDOT.data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localB->TOW = rtu_GpsMeasurementBus->TOW;
  for (trueCount = 0; trueCount < localDW->SFunction_DIMS5; trueCount++) {
    localB->pr_L1[trueCount] = tmp_pr_data[fb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS6; trueCount++) {
    localB->pr_sigma_L1[trueCount] = tmp_pr_sigma_data[gb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS7; trueCount++) {
    localB->dr_L1[trueCount] = tmp_dr_data[kb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS8; trueCount++) {
    localB->cn0_L1[trueCount] = gnss_freq_Matrix_data[lb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS9; trueCount++) {
    localB->cp_L1[trueCount] = tmp_cp_data[hb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS10; trueCount++) {
    localB->cp_sigma_L1[trueCount] = tmp_cp_sigma_data[ib_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS11; trueCount++) {
    localB->Locktime_L1[trueCount] = tmp_Locktime_data[jb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS14; trueCount++) {
    localB->pr_L2C[trueCount] = tmp_pr_data[mb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS15; trueCount++) {
    localB->pr_sigma_L2C[trueCount] = tmp_pr_sigma_data[nb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS16; trueCount++) {
    localB->dr_L2C[trueCount] = tmp_dr_data[rb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS17; trueCount++) {
    localB->cn0_L2C[trueCount] = gnss_freq_Matrix_data[sb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS18; trueCount++) {
    localB->cp_L2C[trueCount] = tmp_cp_data[ob_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS19; trueCount++) {
    localB->cp_sigma_L2C[trueCount] = tmp_cp_sigma_data[pb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS20; trueCount++) {
    localB->Locktime_L2C[trueCount] = tmp_Locktime_data[qb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS23; trueCount++) {
    localB->pr_L5[trueCount] = tmp_pr_data[tb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS24; trueCount++) {
    localB->pr_sigma_L5[trueCount] = tmp_pr_sigma_data[ub_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS25; trueCount++) {
    localB->dr_L5[trueCount] = tmp_dr_data[yb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS26; trueCount++) {
    localB->cn0_L5[trueCount] = gnss_freq_Matrix_data[ac_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS27; trueCount++) {
    localB->cp_L5[trueCount] = tmp_cp_data[vb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS28; trueCount++) {
    localB->cp_sigma_L5[trueCount] = tmp_cp_sigma_data[wb_data[trueCount] - 1];
  }

  for (trueCount = 0; trueCount < localDW->SFunction_DIMS29; trueCount++) {
    localB->Locktime_L5[trueCount] = tmp_Locktime_data[xb_data[trueCount] - 1];
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
