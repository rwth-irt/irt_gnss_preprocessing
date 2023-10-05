//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateDifferentialCorrecti_l.cpp
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
#include "CalculateDifferentialCorrecti_l.h"
#include "GNSSPreProcessingSingleAntenna_types.h"
#include "rtwtypes.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <cstring>
#include <emmintrin.h>
#include "GNSSPreProcessingSingleAntenna_private.h"
#include <cmath>

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_merge_f(int32_T
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

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_sort_ni(uint16_T
  x_data[], const int32_T *x_size, int32_T idx_data[], int32_T *idx_size)
{
  int32_T b_idx_data[40];
  int32_T iwork_data[40];
  int32_T b;
  int32_T dim;
  int32_T nDone;
  int32_T vstride;
  int32_T vwork_size_idx_0;
  uint16_T b_x_data[40];
  uint16_T vwork_data[40];
  uint16_T x4[4];
  int8_T idx4[4];
  int8_T perm[4];
  dim = 0;
  if (*x_size != 1) {
    dim = -1;
    nDone = *x_size;
  } else {
    nDone = 1;
  }

  b = nDone - 1;
  vwork_size_idx_0 = nDone;
  *idx_size = *x_size;
  vstride = 1;
  for (nDone = 0; nDone <= dim; nDone++) {
    vstride *= *x_size;
  }

  for (dim = 0; dim < vstride; dim++) {
    int32_T nLeft;
    for (nDone = 0; nDone <= b; nDone++) {
      vwork_data[nDone] = x_data[nDone * vstride + dim];
    }

    if (vwork_size_idx_0 - 1 >= 0) {
      std::memcpy(&b_x_data[0], &vwork_data[0], static_cast<uint32_T>
                  (vwork_size_idx_0) * sizeof(uint16_T));
    }

    if (static_cast<int8_T>(vwork_size_idx_0) - 1 >= 0) {
      std::memset(&b_idx_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>
        (vwork_size_idx_0)) * sizeof(int32_T));
    }

    if (vwork_size_idx_0 != 0) {
      int32_T b_i;
      int32_T i1;
      int32_T nQuartets_tmp;
      if (static_cast<int8_T>(vwork_size_idx_0) - 1 >= 0) {
        std::memset(&b_idx_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>
          (vwork_size_idx_0)) * sizeof(int32_T));
      }

      x4[0] = 0U;
      idx4[0] = 0;
      x4[1] = 0U;
      idx4[1] = 0;
      x4[2] = 0U;
      idx4[2] = 0;
      x4[3] = 0U;
      idx4[3] = 0;
      nQuartets_tmp = vwork_size_idx_0 >> 2;
      for (nLeft = 0; nLeft < nQuartets_tmp; nLeft++) {
        int32_T i2;
        int32_T i3;
        int32_T i4;
        int32_T tmp;
        uint16_T x4_tmp;
        uint16_T x4_tmp_0;
        uint16_T x4_tmp_1;
        b_i = nLeft << 2;
        idx4[0] = static_cast<int8_T>(b_i + 1);
        idx4[1] = static_cast<int8_T>(b_i + 2);
        idx4[2] = static_cast<int8_T>(b_i + 3);
        idx4[3] = static_cast<int8_T>(b_i + 4);
        x4[0] = b_x_data[b_i];
        x4_tmp = b_x_data[b_i + 1];
        x4[1] = x4_tmp;
        x4_tmp_0 = b_x_data[b_i + 2];
        x4[2] = x4_tmp_0;
        x4_tmp_1 = b_x_data[b_i + 3];
        x4[3] = x4_tmp_1;
        if (b_x_data[b_i] <= x4_tmp) {
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

        b_idx_data[b_i] = idx4[perm[0] - 1];
        b_idx_data[b_i + 1] = idx4[perm[1] - 1];
        b_idx_data[b_i + 2] = idx4[perm[2] - 1];
        b_idx_data[b_i + 3] = idx4[perm[3] - 1];
        b_x_data[b_i] = x4[perm[0] - 1];
        b_x_data[b_i + 1] = x4[perm[1] - 1];
        b_x_data[b_i + 2] = x4[perm[2] - 1];
        b_x_data[b_i + 3] = x4[perm[3] - 1];
      }

      nDone = nQuartets_tmp << 2;
      nLeft = vwork_size_idx_0 - nDone;
      if (nLeft > 0) {
        for (i1 = 0; i1 < nLeft; i1++) {
          b_i = nDone + i1;
          idx4[i1] = static_cast<int8_T>(b_i + 1);
          x4[i1] = b_x_data[b_i];
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

        for (i1 = 0; i1 < nLeft; i1++) {
          int8_T perm_0;
          perm_0 = perm[i1];
          b_i = nDone + i1;
          b_idx_data[b_i] = idx4[perm_0 - 1];
          b_x_data[b_i] = x4[perm_0 - 1];
        }
      }

      if (vwork_size_idx_0 > 1) {
        if (static_cast<int8_T>(vwork_size_idx_0) - 1 >= 0) {
          std::memset(&iwork_data[0], 0, static_cast<uint32_T>
                      (static_cast<int8_T>(vwork_size_idx_0)) * sizeof(int32_T));
        }

        std::memset(&vwork_data[0], 0, static_cast<uint32_T>(vwork_size_idx_0) *
                    sizeof(uint16_T));
        nLeft = nQuartets_tmp;
        nDone = 4;
        while (nLeft > 1) {
          if ((static_cast<uint32_T>(nLeft) & 1U) != 0U) {
            nLeft--;
            i1 = nDone * nLeft;
            b_i = vwork_size_idx_0 - i1;
            if (b_i > nDone) {
              GNSSPreProcessingSingle_merge_f(b_idx_data, b_x_data, i1, nDone,
                b_i - nDone, iwork_data, vwork_data);
            }
          }

          b_i = nDone << 1;
          nLeft >>= 1;
          for (i1 = 0; i1 < nLeft; i1++) {
            GNSSPreProcessingSingle_merge_f(b_idx_data, b_x_data, i1 * b_i,
              nDone, nDone, iwork_data, vwork_data);
          }

          nDone = b_i;
        }

        if (vwork_size_idx_0 > nDone) {
          GNSSPreProcessingSingle_merge_f(b_idx_data, b_x_data, 0, nDone,
            vwork_size_idx_0 - nDone, iwork_data, vwork_data);
        }
      }
    }

    if (vwork_size_idx_0 - 1 >= 0) {
      std::memcpy(&vwork_data[0], &b_x_data[0], static_cast<uint32_T>
                  (vwork_size_idx_0) * sizeof(uint16_T));
    }

    for (nLeft = 0; nLeft <= b; nLeft++) {
      nDone = nLeft * vstride + dim;
      x_data[nDone] = b_x_data[nLeft];
      idx_data[nDone] = b_idx_data[nLeft];
    }
  }
}

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::GNSSPreProcessingS_do_vectors_c(const
  uint16_T a_data[], const int32_T *a_size, const real_T b_data[], const int32_T
  *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T
  *ia_size, int32_T ib_data[], int32_T *ib_size)
{
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T nc;
  int32_T ncmax;
  if (*a_size <= *b_size) {
    ncmax = *a_size;
  } else {
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
  while ((ialast <= *a_size) && (iblast <= *b_size)) {
    real_T bk;
    int32_T b_ialast;
    int32_T b_iblast;
    uint16_T ak;
    b_ialast = ialast;
    ak = a_data[ialast - 1];
    while ((b_ialast < *a_size) && (a_data[b_ialast] == ak)) {
      b_ialast++;
    }

    ialast = b_ialast;
    b_iblast = iblast;
    bk = b_data[iblast - 1];
    while ((b_iblast < *b_size) && (b_data[b_iblast] == bk)) {
      b_iblast++;
    }

    iblast = b_iblast;
    if (ak == bk) {
      nc++;
      c_data[nc - 1] = ak;
      ia_data[nc - 1] = iafirst + 1;
      ib_data[nc - 1] = ibfirst + 1;
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else if (std::isnan(bk) || (ak < bk)) {
      ialast = b_ialast + 1;
      iafirst = b_ialast;
    } else {
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    }
  }

  if (ncmax > 0) {
    if (nc < 1) {
      *ia_size = 0;
      *ib_size = 0;
      *c_size = 0;
    } else {
      *ia_size = nc;
      *ib_size = nc;
      *c_size = nc;
    }
  }
}

void GNSS_preprocessingModelClass::GNSS_binary_expand_op_espyy15uo(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const gnssops_navigation_data *in3, const real_T in5_data[],
  const int32_T *in5_size)
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1_size[0] = 1;
  in1_size[1] = *in5_size == 1 ? in2_size[1] : *in5_size;
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (*in5_size != 1);
  loop_ub = *in5_size == 1 ? in2_size[1] : *in5_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_1] - in3->T_oc[static_cast<int32_T>
      (in5_data[i * stride_1_1]) - 1];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProcessingSingl_minus_d4(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1_size[0] = 1;
  in1_size[1] = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  loop_ub = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_1] - in3_data[i * stride_1_1];
  }
}

void GNSS_preprocessingModelClass::GNSSP_binary_expand_op_espyy15u(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2])
{
  real_T in2_data_0[37];
  int32_T in2_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  in2_size_idx_1 = (in4_size[1] == 1 ? in3_size[1] == 1 ? in1_size[1] :
                    in3_size[1] : in4_size[1]) == 1 ? in2_size[1] : in4_size[1] ==
    1 ? in3_size[1] == 1 ? in1_size[1] : in3_size[1] : in4_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  stride_2_1 = (in3_size[1] != 1);
  stride_3_1 = (in4_size[1] != 1);
  loop_ub = (in4_size[1] == 1 ? in3_size[1] == 1 ? in1_size[1] : in3_size[1] :
             in4_size[1]) == 1 ? in2_size[1] : in4_size[1] == 1 ? in3_size[1] ==
    1 ? in1_size[1] : in3_size[1] : in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    real_T in2_tmp;
    in2_tmp = in4_data[i * stride_3_1];
    in2_data_0[i] = ((in2_tmp - static_cast<real_T>(in2_tmp > 302400.0) *
                      604800.0) + static_cast<real_T>(in2_tmp < -302400.0) *
                     604800.0) * (in1_data[i * stride_1_1] + in3_data[i *
      stride_2_1]) + in2_data[i * stride_0_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in2_size_idx_1;
  if (in2_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in2_data_0[0], static_cast<uint32_T>
                (in2_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPr_binary_expand_op_espyy15(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  in1_size[0] = 1;
  in1_size[1] = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ? in2_size[1]
    : in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in2_size[1] != 1);
  stride_2_1 = (in3_size[1] != 1);
  loop_ub = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ? in2_size[1] :
    in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = static_cast<real_T>(in2_data[i * stride_0_1] > 0.8) *
      3.1415926535897931 + static_cast<real_T>(in2_data[i * stride_1_1] <= 0.8) *
      in3_data[i * stride_2_1];
  }
}

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
boolean_T GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_any_gy(const
  boolean_T x_data[], const int32_T x_size[2])
{
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x_size[1])) {
    if (x_data[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  return y;
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_es(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
  real_T in2_data_0[37];
  int32_T in2_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  in2_size_idx_1 = (in1_size[1] == 1 ? in3_size[1] : in1_size[1]) == 1 ?
    in2_size[1] : in1_size[1] == 1 ? in3_size[1] : in1_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  stride_2_1 = (in1_size[1] != 1);
  loop_ub = (in1_size[1] == 1 ? in3_size[1] : in1_size[1]) == 1 ? in2_size[1] :
    in1_size[1] == 1 ? in3_size[1] : in1_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in2_data_0[i] = in3_data[i * stride_1_1] * in1_data[i * stride_2_1] +
      in2_data[i * stride_0_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in2_size_idx_1;
  if (in2_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in2_data_0[0], static_cast<uint32_T>
                (in2_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_minus_d(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2])
{
  real_T in2_data_0[37];
  int32_T in2_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in2_size_idx_1 = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  loop_ub = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in2_data_0[i] = in2_data[i * stride_0_1] - in1_data[i * stride_1_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in2_size_idx_1;
  if (in2_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in2_data_0[0], static_cast<uint32_T>
                (in2_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPre_binary_expand_op_espyy1(real_T
  in1_data[], int32_T in1_size[2], const gnssops_navigation_data *in2, const
  real_T in4_data[], const int32_T *in4_size, const real_T in5_data[], const
  int32_T in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const
  real_T in7_data[], const int32_T in7_size[2])
{
  real_T in2_data[37];
  int32_T in2_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  int32_T stride_4_1;
  int32_T stride_5_1;
  int32_T stride_6_1;
  int32_T stride_7_1;
  in2_size_idx_1 = (in7_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] :
                    in6_size[1] : in7_size[1]) == 1 ? (in1_size[1] == 1 ?
    *in4_size : in1_size[1]) == 1 ? (in1_size[1] == 1 ? *in4_size : in1_size[1])
    == 1 ? *in4_size : in1_size[1] == 1 ? *in4_size : in1_size[1] : in1_size[1] ==
    1 ? *in4_size : in1_size[1] : in7_size[1] == 1 ? in6_size[1] == 1 ?
    in5_size[1] : in6_size[1] : in7_size[1];
  stride_0_1 = (*in4_size != 1);
  stride_1_1 = (*in4_size != 1);
  stride_2_1 = (in1_size[1] != 1);
  stride_3_1 = (*in4_size != 1);
  stride_4_1 = (in1_size[1] != 1);
  stride_5_1 = (in5_size[1] != 1);
  stride_6_1 = (in6_size[1] != 1);
  stride_7_1 = (in7_size[1] != 1);
  loop_ub = (in7_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1] :
             in7_size[1]) == 1 ? (in1_size[1] == 1 ? *in4_size : in1_size[1]) ==
    1 ? (in1_size[1] == 1 ? *in4_size : in1_size[1]) == 1 ? *in4_size :
    in1_size[1] == 1 ? *in4_size : in1_size[1] : in1_size[1] == 1 ? *in4_size :
    in1_size[1] : in7_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1]
    : in7_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = in1_data[i * stride_4_1];
    in2_data[i] = ((in2->A_f1[static_cast<int32_T>(in4_data[i * stride_1_1]) - 1]
                    * in1_data[i * stride_2_1] + in2->A_f0[static_cast<int32_T>
                    (in4_data[i * stride_0_1]) - 1]) + in2->A_f2
                   [static_cast<int32_T>(in4_data[i * stride_3_1]) - 1] *
                   (varargin_1 * varargin_1)) + in5_data[i * stride_5_1] *
      -4.44280763339306E-10 * in6_data[i * stride_6_1] * in7_data[i * stride_7_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in2_size_idx_1;
  if (in2_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in2_data[0], static_cast<uint32_T>(in2_size_idx_1)
                * sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::correct_Gps_Time_At_Week_Cros_i(real_T
  b_time_data[], int32_T b_time_size[2])
{
  int32_T loop_ub;
  b_time_size[0] = 1;
  loop_ub = b_time_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    real_T tmp;
    tmp = b_time_data[i];
    b_time_data[i] = (tmp - static_cast<real_T>(tmp > 302400.0) * 604800.0) +
      static_cast<real_T>(tmp < -302400.0) * 604800.0;
  }
}

void GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_plus_o(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2])
{
  real_T in1_data_0[37];
  int32_T in1_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1_size_idx_1 = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1 = (in2_size[1] != 1);
  loop_ub = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_0[i] = in1_data[i * stride_0_1] + in2_data[i * stride_1_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in1_size_idx_1;
  if (in1_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in1_data_0[0], static_cast<uint32_T>
                (in1_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_ks(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  in1_size[0] = 1;
  in1_size[1] = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ? in2_size[1]
    : in4_size[1] == 1 ? in3_size[1] : in4_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  stride_2_1 = (in4_size[1] != 1);
  loop_ub = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ? in2_size[1] :
    in4_size[1] == 1 ? in3_size[1] : in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in3_data[i * stride_1_1] * in4_data[i * stride_2_1] +
      in2_data[i * stride_0_1];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_nz(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
  real_T in1_data_0[37];
  int32_T in1_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  in1_size_idx_1 = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ?
    in1_size[1] : in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1 = (in2_size[1] != 1);
  stride_2_1 = (in3_size[1] != 1);
  loop_ub = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ? in1_size[1] :
    in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_0[i] = in1_data[i * stride_0_1] / (1.0 - in2_data[i * stride_1_1] *
      in3_data[i * stride_2_1]);
  }

  in1_size[0] = 1;
  in1_size[1] = in1_size_idx_1;
  if (in1_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in1_data_0[0], static_cast<uint32_T>
                (in1_size_idx_1) * sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::Get_Kepler_Eccentric_Anomaly_b(const real_T
  t_k_data[], const int32_T t_k_size[2], const real_T Ephemeris_DELTA_N_data[],
  const int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[],
  const int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_E_data[], const
  int32_T Ephemeris_E_size[2], const real_T Ephemeris_SQRT_A_data[], const
  int32_T Ephemeris_SQRT_A_size[2], real_T E_k_data[], int32_T E_k_size[2],
  real_T E_k_Dot_data[], int32_T E_k_Dot_size[2])
{
  __m128d tmp;
  __m128d tmp_0;
  real_T E_k_old_data[37];
  real_T M_k_data[37];
  real_T eps_data[37];
  real_T varargin_1;
  int32_T E_k_old_size[2];
  int32_T M_k_size[2];
  int32_T eps_size[2];
  int32_T eps_size_idx_1;
  int32_T i;
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T vectorUB;
  boolean_T eps_data_0[37];
  E_k_Dot_size[0] = 1;
  E_k_Dot_size[1] = Ephemeris_SQRT_A_size[1];
  loop_ub = Ephemeris_SQRT_A_size[1];
  for (int32_T varargin_1_tmp{0}; varargin_1_tmp < loop_ub; varargin_1_tmp++) {
    varargin_1 = Ephemeris_SQRT_A_data[varargin_1_tmp];
    E_k_Dot_data[varargin_1_tmp] = 3.986005E+14 / rt_powd_snf(varargin_1 *
      varargin_1, 3.0);
  }

  i = Ephemeris_SQRT_A_size[1];
  scalarLB = (Ephemeris_SQRT_A_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (loop_ub = 0; loop_ub <= vectorUB; loop_ub += 2) {
    tmp_0 = _mm_loadu_pd(&E_k_Dot_data[loop_ub]);
    _mm_storeu_pd(&E_k_Dot_data[loop_ub], _mm_sqrt_pd(tmp_0));
  }

  for (loop_ub = scalarLB; loop_ub < i; loop_ub++) {
    E_k_Dot_data[loop_ub] = std::sqrt(E_k_Dot_data[loop_ub]);
  }

  if (Ephemeris_SQRT_A_size[1] == Ephemeris_DELTA_N_size[1]) {
    loop_ub = Ephemeris_SQRT_A_size[1] - 1;
    E_k_Dot_size[0] = 1;
    scalarLB = (Ephemeris_SQRT_A_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T varargin_1_tmp{0}; varargin_1_tmp <= vectorUB; varargin_1_tmp +=
         2) {
      tmp_0 = _mm_loadu_pd(&E_k_Dot_data[varargin_1_tmp]);
      _mm_storeu_pd(&E_k_Dot_data[varargin_1_tmp], _mm_add_pd(tmp_0,
        _mm_loadu_pd(&Ephemeris_DELTA_N_data[varargin_1_tmp])));
    }

    for (int32_T varargin_1_tmp{scalarLB}; varargin_1_tmp <= loop_ub;
         varargin_1_tmp++) {
      E_k_Dot_data[varargin_1_tmp] += Ephemeris_DELTA_N_data[varargin_1_tmp];
    }
  } else {
    GNSSPreProcessingSingleA_plus_o(E_k_Dot_data, E_k_Dot_size,
      Ephemeris_DELTA_N_data, Ephemeris_DELTA_N_size);
  }

  if ((E_k_Dot_size[1] == t_k_size[1]) && ((E_k_Dot_size[1] == 1 ? t_k_size[1] :
        E_k_Dot_size[1]) == Ephemeris_M_0_size[1])) {
    M_k_size[0] = 1;
    M_k_size[1] = Ephemeris_M_0_size[1];
    loop_ub = Ephemeris_M_0_size[1];
    scalarLB = (Ephemeris_M_0_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T varargin_1_tmp{0}; varargin_1_tmp <= vectorUB; varargin_1_tmp +=
         2) {
      tmp_0 = _mm_loadu_pd(&E_k_Dot_data[varargin_1_tmp]);
      _mm_storeu_pd(&M_k_data[varargin_1_tmp], _mm_add_pd(_mm_mul_pd(tmp_0,
        _mm_loadu_pd(&t_k_data[varargin_1_tmp])), _mm_loadu_pd
        (&Ephemeris_M_0_data[varargin_1_tmp])));
    }

    for (int32_T varargin_1_tmp{scalarLB}; varargin_1_tmp < loop_ub;
         varargin_1_tmp++) {
      M_k_data[varargin_1_tmp] = E_k_Dot_data[varargin_1_tmp] *
        t_k_data[varargin_1_tmp] + Ephemeris_M_0_data[varargin_1_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_ks(M_k_data, M_k_size, Ephemeris_M_0_data,
      Ephemeris_M_0_size, E_k_Dot_data, E_k_Dot_size, t_k_data, t_k_size);
  }

  if ((Ephemeris_E_size[1] == M_k_size[1]) && ((Ephemeris_E_size[1] == 1 ?
        M_k_size[1] : Ephemeris_E_size[1]) == Ephemeris_E_size[1])) {
    E_k_size[0] = 1;
    E_k_size[1] = Ephemeris_E_size[1];
    loop_ub = Ephemeris_E_size[1];
    for (int32_T varargin_1_tmp{0}; varargin_1_tmp < loop_ub; varargin_1_tmp++)
    {
      varargin_1 = Ephemeris_E_data[varargin_1_tmp];
      E_k_data[varargin_1_tmp] = static_cast<real_T>(varargin_1 > 0.8) *
        3.1415926535897931 + static_cast<real_T>(varargin_1 <= 0.8) *
        M_k_data[varargin_1_tmp];
    }
  } else {
    GNSSPr_binary_expand_op_espyy15(E_k_data, E_k_size, Ephemeris_E_data,
      Ephemeris_E_size, M_k_data, M_k_size);
  }

  i = 0;
  eps_size_idx_1 = E_k_size[1];
  loop_ub = E_k_size[1];
  for (int32_T varargin_1_tmp{0}; varargin_1_tmp < loop_ub; varargin_1_tmp++) {
    eps_data[varargin_1_tmp] = 1.0;
  }

  int32_T exitg1;
  do {
    exitg1 = 0;
    eps_size[0] = 1;
    eps_size[1] = eps_size_idx_1;
    for (int32_T varargin_1_tmp{0}; varargin_1_tmp < eps_size_idx_1;
         varargin_1_tmp++) {
      eps_data_0[varargin_1_tmp] = (eps_data[varargin_1_tmp] > 1.0E-15);
    }

    if (GNSSPreProcessingSingleA_any_gy(eps_data_0, eps_size) && (i < 20)) {
      E_k_old_size[0] = 1;
      E_k_old_size[1] = E_k_size[1];
      loop_ub = E_k_size[1];
      if (loop_ub - 1 >= 0) {
        std::memcpy(&E_k_old_data[0], &E_k_data[0], static_cast<uint32_T>
                    (loop_ub) * sizeof(real_T));
      }

      scalarLB = E_k_size[1];
      for (vectorUB = 0; vectorUB < scalarLB; vectorUB++) {
        E_k_data[vectorUB] = std::sin(E_k_data[vectorUB]);
      }

      if ((Ephemeris_E_size[1] == E_k_size[1]) && ((Ephemeris_E_size[1] == 1 ?
            E_k_size[1] : Ephemeris_E_size[1]) == M_k_size[1])) {
        loop_ub = M_k_size[1] - 1;
        E_k_size[0] = 1;
        E_k_size[1] = M_k_size[1];
        scalarLB = (M_k_size[1] / 2) << 1;
        vectorUB = scalarLB - 2;
        for (int32_T varargin_1_tmp{0}; varargin_1_tmp <= vectorUB;
             varargin_1_tmp += 2) {
          tmp_0 = _mm_loadu_pd(&E_k_data[varargin_1_tmp]);
          tmp = _mm_loadu_pd(&M_k_data[varargin_1_tmp]);
          _mm_storeu_pd(&E_k_data[varargin_1_tmp], _mm_add_pd(_mm_mul_pd
            (_mm_loadu_pd(&Ephemeris_E_data[varargin_1_tmp]), tmp_0), tmp));
        }

        for (int32_T varargin_1_tmp{scalarLB}; varargin_1_tmp <= loop_ub;
             varargin_1_tmp++) {
          E_k_data[varargin_1_tmp] = Ephemeris_E_data[varargin_1_tmp] *
            E_k_data[varargin_1_tmp] + M_k_data[varargin_1_tmp];
        }
      } else {
        GNSSPreProc_binary_expand_op_es(E_k_data, E_k_size, M_k_data, M_k_size,
          Ephemeris_E_data, Ephemeris_E_size);
      }

      if (E_k_size[1] == E_k_old_size[1]) {
        loop_ub = E_k_size[1] - 1;
        E_k_old_size[1] = E_k_size[1];
        scalarLB = (E_k_size[1] / 2) << 1;
        vectorUB = scalarLB - 2;
        for (int32_T varargin_1_tmp{0}; varargin_1_tmp <= vectorUB;
             varargin_1_tmp += 2) {
          tmp_0 = _mm_loadu_pd(&E_k_data[varargin_1_tmp]);
          tmp = _mm_loadu_pd(&E_k_old_data[varargin_1_tmp]);
          _mm_storeu_pd(&E_k_old_data[varargin_1_tmp], _mm_sub_pd(tmp_0, tmp));
        }

        for (int32_T varargin_1_tmp{scalarLB}; varargin_1_tmp <= loop_ub;
             varargin_1_tmp++) {
          E_k_old_data[varargin_1_tmp] = E_k_data[varargin_1_tmp] -
            E_k_old_data[varargin_1_tmp];
        }
      } else {
        GNSSPreProcessingSingle_minus_d(E_k_old_data, E_k_old_size, E_k_data,
          E_k_size);
      }

      eps_size_idx_1 = E_k_old_size[1];
      scalarLB = E_k_old_size[1];
      for (vectorUB = 0; vectorUB < scalarLB; vectorUB++) {
        eps_data[vectorUB] = std::abs(E_k_old_data[vectorUB]);
      }

      i++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  M_k_size[0] = 1;
  M_k_size[1] = E_k_size[1];
  loop_ub = E_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&M_k_data[0], &E_k_data[0], static_cast<uint32_T>(loop_ub) *
                sizeof(real_T));
  }

  i = E_k_size[1];
  for (scalarLB = 0; scalarLB < i; scalarLB++) {
    M_k_data[scalarLB] = std::cos(M_k_data[scalarLB]);
  }

  if ((Ephemeris_E_size[1] == E_k_size[1]) && ((Ephemeris_E_size[1] == 1 ?
        E_k_size[1] : Ephemeris_E_size[1]) == E_k_Dot_size[1])) {
    loop_ub = E_k_Dot_size[1] - 1;
    E_k_Dot_size[0] = 1;
    scalarLB = (E_k_Dot_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T varargin_1_tmp{0}; varargin_1_tmp <= vectorUB; varargin_1_tmp +=
         2) {
      tmp_0 = _mm_loadu_pd(&M_k_data[varargin_1_tmp]);
      tmp = _mm_loadu_pd(&E_k_Dot_data[varargin_1_tmp]);
      _mm_storeu_pd(&E_k_Dot_data[varargin_1_tmp], _mm_div_pd(tmp, _mm_sub_pd
        (_mm_set1_pd(1.0), _mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_E_data[varargin_1_tmp]), tmp_0))));
    }

    for (int32_T varargin_1_tmp{scalarLB}; varargin_1_tmp <= loop_ub;
         varargin_1_tmp++) {
      E_k_Dot_data[varargin_1_tmp] /= 1.0 - Ephemeris_E_data[varargin_1_tmp] *
        M_k_data[varargin_1_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_nz(E_k_Dot_data, E_k_Dot_size, Ephemeris_E_data,
      Ephemeris_E_size, M_k_data, M_k_size);
  }
}

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_cos_g(real_T
  x_data[], const int32_T x_size[2])
{
  int32_T b;
  b = x_size[1];
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::cos(x_data[k]);
  }
}

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_sin_g(real_T
  x_data[], const int32_T x_size[2])
{
  int32_T b;
  b = x_size[1];
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::sin(x_data[k]);
  }
}

void GNSS_preprocessingModelClass::GNSSPreProcessingSingl_times_du(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1_size[0] = 1;
  in1_size[1] = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  loop_ub = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_1] * in3_data[i * stride_1_1];
  }
}

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_sqrt_j(real_T
  x_data[], const int32_T x_size[2])
{
  int32_T b;
  int32_T scalarLB;
  int32_T vectorUB;
  b = x_size[1];
  scalarLB = (x_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T k{0}; k <= vectorUB; k += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&x_data[k]);
    _mm_storeu_pd(&x_data[k], _mm_sqrt_pd(tmp));
  }

  for (int32_T k{scalarLB}; k < b; k++) {
    x_data[k] = std::sqrt(x_data[k]);
  }
}

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::GNSSPreProcessin_expand_atan2_d(const real_T
  a_data[], const int32_T a_size[2], const real_T b_data[], const int32_T
  b_size[2], real_T c_data[], int32_T c_size[2])
{
  int8_T csz_idx_1;
  if (b_size[1] == 1) {
    csz_idx_1 = static_cast<int8_T>(a_size[1]);
  } else if (a_size[1] == 1) {
    csz_idx_1 = static_cast<int8_T>(b_size[1]);
  } else if (a_size[1] <= b_size[1]) {
    csz_idx_1 = static_cast<int8_T>(a_size[1]);
  } else {
    csz_idx_1 = static_cast<int8_T>(b_size[1]);
  }

  c_size[0] = 1;
  c_size[1] = csz_idx_1;
  if (csz_idx_1 != 0) {
    int32_T f;
    boolean_T d;
    boolean_T e;
    d = (a_size[1] != 1);
    e = (b_size[1] != 1);
    f = csz_idx_1 - 1;
    for (int32_T k{0}; k <= f; k++) {
      c_data[k] = rt_atan2d_snf(a_data[d * k], b_data[e * k]);
    }
  }
}

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_atan2_g(const real_T
  y_data[], const int32_T y_size[2], const real_T x_data[], const int32_T
  x_size[2], real_T r_data[], int32_T r_size[2])
{
  if (y_size[1] == x_size[1]) {
    int32_T loop_ub;
    r_size[0] = 1;
    r_size[1] = y_size[1];
    loop_ub = y_size[1];
    for (int32_T r_data_tmp{0}; r_data_tmp < loop_ub; r_data_tmp++) {
      r_data[r_data_tmp] = rt_atan2d_snf(y_data[r_data_tmp], x_data[r_data_tmp]);
    }
  } else {
    GNSSPreProcessin_expand_atan2_d(y_data, y_size, x_data, x_size, r_data,
      r_size);
  }
}

void GNSS_preprocessingModelClass::GNS_binary_expand_op_espyy15uog(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2])
{
  real_T in2_data_0[37];
  real_T in5_data_0[37];
  int32_T in2_size_0[2];
  int32_T in5_size_0[2];
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  in2_size_0[0] = 1;
  in2_size_0[1] = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1]
    : in4_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  stride_2_1 = (in4_size[1] != 1);
  loop_ub = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] :
    in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in2_data_0[i] = in2_data[i * stride_0_1] * in3_data[i * stride_1_1] /
      in4_data[i * stride_2_1];
  }

  in5_size_0[0] = 1;
  in5_size_0[1] = in4_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1]
    : in4_size[1];
  stride_0_1 = (in5_size[1] != 1);
  stride_1_1 = (in6_size[1] != 1);
  stride_2_1 = (in4_size[1] != 1);
  loop_ub = in4_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1] :
    in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in5_data_0[i] = (in5_data[i * stride_0_1] - in6_data[i * stride_1_1]) /
      in4_data[i * stride_2_1];
  }

  GNSSPreProcessingSingle_atan2_g(in2_data_0, in2_size_0, in5_data_0, in5_size_0,
    in1_data, in1_size);
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_gm(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const real_T
  in7_data[], const int32_T in7_size[2])
{
  real_T in2_data_0[37];
  real_T in5_data_0[37];
  real_T tmp_data[37];
  int32_T in2_size_0[2];
  int32_T in5_size_0[2];
  int32_T tmp_size[2];
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  in2_size_0[0] = 1;
  in2_size_0[1] = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1]
    : in4_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  stride_2_1 = (in4_size[1] != 1);
  loop_ub = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] :
    in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in2_data_0[i] = in2_data[i * stride_0_1] * in3_data[i * stride_1_1] /
      in4_data[i * stride_2_1];
  }

  in5_size_0[0] = 1;
  in5_size_0[1] = in4_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1]
    : in4_size[1];
  stride_0_1 = (in5_size[1] != 1);
  stride_1_1 = (in6_size[1] != 1);
  stride_2_1 = (in4_size[1] != 1);
  loop_ub = in4_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] : in6_size[1] :
    in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in5_data_0[i] = (in5_data[i * stride_0_1] - in6_data[i * stride_1_1]) /
      in4_data[i * stride_2_1];
  }

  GNSSPreProcessingSingle_atan2_g(in2_data_0, in2_size_0, in5_data_0, in5_size_0,
    tmp_data, tmp_size);
  in1_size[0] = 1;
  in1_size[1] = in7_size[1] == 1 ? tmp_size[1] : in7_size[1];
  stride_0_1 = (tmp_size[1] != 1);
  stride_1_1 = (in7_size[1] != 1);
  loop_ub = in7_size[1] == 1 ? tmp_size[1] : in7_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = tmp_data[i * stride_0_1] + in7_data[i * stride_1_1];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_du(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2])
{
  real_T in1_data_0[37];
  int32_T in1_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  int32_T stride_4_1;
  in1_size_idx_1 = ((in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ?
                    in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size[1] ==
                    1 ? in4_size[1] : in5_size[1]) == 1 ? in1_size[1] :
    (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in3_size[1] == 1 ?
    in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1];
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1 = (in2_size[1] != 1);
  stride_2_1 = (in3_size[1] != 1);
  stride_3_1 = (in4_size[1] != 1);
  stride_4_1 = (in5_size[1] != 1);
  loop_ub = ((in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in3_size[1] ==
             1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1] :
             in5_size[1]) == 1 ? in1_size[1] : (in5_size[1] == 1 ? in4_size[1] :
    in5_size[1]) == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size
    [1] == 1 ? in4_size[1] : in5_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_0[i] = (in2_data[i * stride_1_1] * in3_data[i * stride_2_1] +
                     in4_data[i * stride_3_1] * in5_data[i * stride_4_1]) +
      in1_data[i * stride_0_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in1_size_idx_1;
  if (in1_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in1_data_0[0], static_cast<uint32_T>
                (in1_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_ii(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const real_T
  in7_data[], const int32_T in7_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  int32_T stride_4_1;
  int32_T stride_5_1;
  in1_size[0] = 1;
  in1_size[1] = ((in7_size[1] == 1 ? in6_size[1] : in7_size[1]) == 1 ? in5_size
                 [1] == 1 ? in4_size[1] : in5_size[1] : in7_size[1] == 1 ?
                 in6_size[1] : in7_size[1]) == 1 ? in3_size[1] == 1 ? in2_size[1]
    : in3_size[1] : (in7_size[1] == 1 ? in6_size[1] : in7_size[1]) == 1 ?
    in5_size[1] == 1 ? in4_size[1] : in5_size[1] : in7_size[1] == 1 ? in6_size[1]
    : in7_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  stride_2_1 = (in4_size[1] != 1);
  stride_3_1 = (in5_size[1] != 1);
  stride_4_1 = (in6_size[1] != 1);
  stride_5_1 = (in7_size[1] != 1);
  loop_ub = ((in7_size[1] == 1 ? in6_size[1] : in7_size[1]) == 1 ? in5_size[1] ==
             1 ? in4_size[1] : in5_size[1] : in7_size[1] == 1 ? in6_size[1] :
             in7_size[1]) == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] :
    (in7_size[1] == 1 ? in6_size[1] : in7_size[1]) == 1 ? in5_size[1] == 1 ?
    in4_size[1] : in5_size[1] : in7_size[1] == 1 ? in6_size[1] : in7_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = in2_data[i * stride_0_1];
    in1_data[i] = (1.0 - in3_data[i * stride_1_1]) * (varargin_1 * varargin_1) +
      (in4_data[i * stride_2_1] * in5_data[i * stride_3_1] + in6_data[i *
       stride_4_1] * in7_data[i * stride_5_1]);
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_ld(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const real_T
  in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
  in8_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  int32_T stride_4_1;
  int32_T stride_5_1;
  int32_T stride_6_1;
  in1_size[0] = 1;
  in1_size[1] = (in8_size[1] == 1 ? in7_size[1] : in8_size[1]) == 1 ?
    ((in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ? in4_size[1] == 1 ?
     in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1] : in6_size[1]) ==
    1 ? in2_size[1] : (in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ?
    in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1]
    : in6_size[1] : in8_size[1] == 1 ? in7_size[1] : in8_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  stride_2_1 = (in4_size[1] != 1);
  stride_3_1 = (in5_size[1] != 1);
  stride_4_1 = (in6_size[1] != 1);
  stride_5_1 = (in7_size[1] != 1);
  stride_6_1 = (in8_size[1] != 1);
  loop_ub = (in8_size[1] == 1 ? in7_size[1] : in8_size[1]) == 1 ? ((in6_size[1] ==
    1 ? in5_size[1] : in6_size[1]) == 1 ? in4_size[1] == 1 ? in3_size[1] :
    in4_size[1] : in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ? in2_size
    [1] : (in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ? in4_size[1] == 1
    ? in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1] : in6_size[1] :
    in8_size[1] == 1 ? in7_size[1] : in8_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = ((in3_data[i * stride_1_1] * in4_data[i * stride_2_1] +
                    in5_data[i * stride_3_1] * in6_data[i * stride_4_1]) +
                   in2_data[i * stride_0_1]) + in7_data[i * stride_5_1] *
      in8_data[i * stride_6_1];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_ow(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2])
{
  real_T in2_data_0[37];
  int32_T in2_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  in2_size_idx_1 = in4_size[1] == 1 ? (in1_size[1] == 1 ? in3_size[1] :
    in1_size[1]) == 1 ? in2_size[1] : in1_size[1] == 1 ? in3_size[1] : in1_size
    [1] : in4_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  stride_2_1 = (in1_size[1] != 1);
  stride_3_1 = (in4_size[1] != 1);
  loop_ub = in4_size[1] == 1 ? (in1_size[1] == 1 ? in3_size[1] : in1_size[1]) ==
    1 ? in2_size[1] : in1_size[1] == 1 ? in3_size[1] : in1_size[1] : in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in2_data_0[i] = (in3_data[i * stride_1_1] * in1_data[i * stride_2_1] +
                     in2_data[i * stride_0_1]) - in4_data[i * stride_3_1] *
      7.2921151467E-5;
  }

  in1_size[0] = 1;
  in1_size[1] = in2_size_idx_1;
  if (in2_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in2_data_0[0], static_cast<uint32_T>
                (in2_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPreProcessingSing_times_duk(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2])
{
  real_T in1_data_0[37];
  int32_T in1_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1_size_idx_1 = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1 = (in2_size[1] != 1);
  loop_ub = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_0[i] = in1_data[i * stride_0_1] * in2_data[i * stride_1_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in1_size_idx_1;
  if (in1_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in1_data_0[0], static_cast<uint32_T>
                (in1_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_in(real_T
  in1_data[], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
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
  for (int32_T i{0}; i < in2_idx_0; i++) {
    in1_data[i] = in2_data[i * stride_0_0] * in3_data[i * stride_1_0] -
      in4_data[i * stride_2_0] * in5_data[i * stride_3_0];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_kd(real_T
  in1_data[], const int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2])
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
  for (int32_T i{0}; i < in1_idx_0; i++) {
    in1_data[i + in1_size[0]] = in2_data[i * stride_0_0] * in3_data[i *
      stride_1_0] + in4_data[i * stride_2_0] * in5_data[i * stride_3_0];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_o1(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
  real_T in1_data_0[37];
  int32_T in1_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  in1_size_idx_1 = in3_size[1] == 1 ? in2_size[1] == 1 ? in1_size[1] : in2_size
    [1] : in3_size[1];
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1 = (in2_size[1] != 1);
  stride_2_1 = (in3_size[1] != 1);
  loop_ub = in3_size[1] == 1 ? in2_size[1] == 1 ? in1_size[1] : in2_size[1] :
    in3_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_0[i] = in1_data[i * stride_0_1] * in2_data[i * stride_1_1] /
      in3_data[i * stride_2_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in1_size_idx_1;
  if (in1_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in1_data_0[0], static_cast<uint32_T>
                (in1_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_dt(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  int32_T stride_4_1;
  in1_size[0] = 1;
  in1_size[1] = in6_size[1] == 1 ? (in5_size[1] == 1 ? in4_size[1] : in5_size[1])
    == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ?
    in4_size[1] : in5_size[1] : in6_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  stride_2_1 = (in4_size[1] != 1);
  stride_3_1 = (in5_size[1] != 1);
  stride_4_1 = (in6_size[1] != 1);
  loop_ub = in6_size[1] == 1 ? (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) ==
    1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ?
    in4_size[1] : in5_size[1] : in6_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = ((in2_data[i * stride_0_1] * 2.0 * in3_data[i * stride_1_1] +
                    1.0) - in4_data[i * stride_2_1] * 2.0 * in5_data[i *
                   stride_3_1]) * in6_data[i * stride_4_1];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_lf(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const real_T
  in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
  in8_size[2], const real_T in9_data[], const int32_T in9_size[2], const real_T
  in10_data[], const int32_T in10_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  int32_T stride_4_1;
  int32_T stride_5_1;
  int32_T stride_6_1;
  int32_T stride_7_1;
  int32_T stride_8_1;
  in1_size[0] = 1;
  in1_size[1] = (in10_size[1] == 1 ? in9_size[1] == 1 ? in8_size[1] == 1 ?
                 in7_size[1] : in8_size[1] : in9_size[1] : in10_size[1]) == 1 ?
    in6_size[1] == 1 ? (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ?
    in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1]
    : in5_size[1] : in6_size[1] : in10_size[1] == 1 ? in9_size[1] == 1 ?
    in8_size[1] == 1 ? in7_size[1] : in8_size[1] : in9_size[1] : in10_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  stride_2_1 = (in4_size[1] != 1);
  stride_3_1 = (in5_size[1] != 1);
  stride_4_1 = (in6_size[1] != 1);
  stride_5_1 = (in7_size[1] != 1);
  stride_6_1 = (in8_size[1] != 1);
  stride_7_1 = (in9_size[1] != 1);
  stride_8_1 = (in10_size[1] != 1);
  loop_ub = (in10_size[1] == 1 ? in9_size[1] == 1 ? in8_size[1] == 1 ? in7_size
             [1] : in8_size[1] : in9_size[1] : in10_size[1]) == 1 ? in6_size[1] ==
    1 ? (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in3_size[1] == 1 ?
    in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1] :
    in6_size[1] : in10_size[1] == 1 ? in9_size[1] == 1 ? in8_size[1] == 1 ?
    in7_size[1] : in8_size[1] : in9_size[1] : in10_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = in7_data[i * stride_5_1];
    in1_data[i] = (in2_data[i * stride_0_1] * in3_data[i * stride_1_1] -
                   in4_data[i * stride_2_1] * in5_data[i * stride_3_1]) * 2.0 *
      in6_data[i * stride_4_1] + varargin_1 * varargin_1 * in8_data[i *
      stride_6_1] * in9_data[i * stride_7_1] * in10_data[i * stride_8_1];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_ni(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2])
{
  real_T tmp_data[37];
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  int32_T stride_4_1;
  int32_T stride_5_1;
  int32_T tmp_size_idx_1;
  tmp_size_idx_1 = in6_size[1] == 1 ? in5_size[1] == 1 ? (in4_size[1] == 1 ?
    in3_size[1] : in4_size[1]) == 1 ? in1_size[1] == 1 ? in2_size[1] : in1_size
    [1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in5_size[1] : in6_size
    [1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  stride_2_1 = (in3_size[1] != 1);
  stride_3_1 = (in4_size[1] != 1);
  stride_4_1 = (in5_size[1] != 1);
  stride_5_1 = (in6_size[1] != 1);
  loop_ub = in6_size[1] == 1 ? in5_size[1] == 1 ? (in4_size[1] == 1 ? in3_size[1]
    : in4_size[1]) == 1 ? in1_size[1] == 1 ? in2_size[1] : in1_size[1] :
    in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in5_size[1] : in6_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    tmp_data[i] = (in2_data[i * stride_0_1] * in1_data[i * stride_1_1] -
                   in3_data[i * stride_2_1] * in4_data[i * stride_3_1]) * 2.0 *
      in5_data[i * stride_4_1] + in6_data[i * stride_5_1];
  }

  in1_size[0] = 1;
  in1_size[1] = tmp_size_idx_1;
  if (tmp_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &tmp_data[0], static_cast<uint32_T>(tmp_size_idx_1)
                * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_j4(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2])
{
  real_T in2_data_0[37];
  int32_T in2_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  in2_size_idx_1 = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ?
    in1_size[1] == 1 ? in2_size[1] : in1_size[1] : in4_size[1] == 1 ? in3_size[1]
    : in4_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  stride_2_1 = (in3_size[1] != 1);
  stride_3_1 = (in4_size[1] != 1);
  loop_ub = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ? in1_size[1] ==
    1 ? in2_size[1] : in1_size[1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in2_data_0[i] = in2_data[i * stride_0_1] * in1_data[i * stride_1_1] -
      in3_data[i * stride_2_1] * in4_data[i * stride_3_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in2_size_idx_1;
  if (in2_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in2_data_0[0], static_cast<uint32_T>
                (in2_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::binary_expand_o_espyy15uognnqac(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2])
{
  real_T in1_data_0[37];
  int32_T in1_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  in1_size_idx_1 = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ?
    in2_size[1] == 1 ? in1_size[1] : in2_size[1] : in4_size[1] == 1 ? in3_size[1]
    : in4_size[1];
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1 = (in2_size[1] != 1);
  stride_2_1 = (in3_size[1] != 1);
  stride_3_1 = (in4_size[1] != 1);
  loop_ub = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ? in2_size[1] ==
    1 ? in1_size[1] : in2_size[1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_0[i] = in1_data[i * stride_0_1] * in2_data[i * stride_1_1] +
      in3_data[i * stride_2_1] * in4_data[i * stride_3_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in1_size_idx_1;
  if (in1_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in1_data_0[0], static_cast<uint32_T>
                (in1_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_times_d(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2])
{
  real_T in2_data_0[37];
  int32_T in2_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in2_size_idx_1 = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  loop_ub = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in2_data_0[i] = in2_data[i * stride_0_1] * in1_data[i * stride_1_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in2_size_idx_1;
  if (in2_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in2_data_0[0], static_cast<uint32_T>
                (in2_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::binary_expand_op_espyy15uognnqa(real_T
  in1_data[], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T
  in6_data[], const int32_T in6_size[2], const real_T in7_data[], const int32_T
  in7_size[2], const real_T in8_data[], const int32_T in8_size[2], const real_T
  in9_data[], const int32_T in9_size[2])
{
  int32_T in2_idx_0;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T stride_2_0;
  int32_T stride_3_0;
  int32_T stride_4_0;
  int32_T stride_5_0;
  int32_T stride_6_0;
  int32_T stride_7_0;
  int32_T stride_8_0;
  in2_idx_0 = in2_size[1];
  stride_0_0 = (in2_size[1] != 1);
  stride_1_0 = (in3_size[1] != 1);
  stride_2_0 = (in4_size[1] != 1);
  stride_3_0 = (in5_size[1] != 1);
  stride_4_0 = (in6_size[1] != 1);
  stride_5_0 = (in5_size[1] != 1);
  stride_6_0 = (in7_size[1] != 1);
  stride_7_0 = (in8_size[0] != 1);
  stride_8_0 = (in9_size[1] != 1);
  for (int32_T i{0}; i < in2_idx_0; i++) {
    in1_data[i] = ((in2_data[i * stride_0_0] * in3_data[i * stride_1_0] -
                    in4_data[i * stride_2_0] * in5_data[i * stride_3_0]) +
                   in6_data[i * stride_4_0] * in5_data[i * stride_5_0] *
                   in7_data[i * stride_6_0]) - in8_data[i * stride_7_0 +
      in8_size[0]] * in9_data[i * stride_8_0];
  }
}

void GNSS_preprocessingModelClass::binary_expand_op_espyy15uognnq(real_T
  in1_data[], const int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const real_T
  in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
  in8_size[2], const real_T in9_data[], const int32_T in9_size[2])
{
  int32_T in1_idx_0;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T stride_2_0;
  int32_T stride_3_0;
  int32_T stride_4_0;
  int32_T stride_5_0;
  int32_T stride_6_0;
  int32_T stride_7_0;
  int32_T stride_8_0;
  in1_idx_0 = in1_size[0];
  stride_0_0 = (in2_size[1] != 1);
  stride_1_0 = (in3_size[1] != 1);
  stride_2_0 = (in4_size[1] != 1);
  stride_3_0 = (in5_size[1] != 1);
  stride_4_0 = (in6_size[1] != 1);
  stride_5_0 = (in5_size[1] != 1);
  stride_6_0 = (in7_size[1] != 1);
  stride_7_0 = (in8_size[0] != 1);
  stride_8_0 = (in9_size[1] != 1);
  for (int32_T i{0}; i < in1_idx_0; i++) {
    in1_data[i + in1_size[0]] = ((in2_data[i * stride_0_0] * in3_data[i *
      stride_1_0] + in4_data[i * stride_2_0] * in5_data[i * stride_3_0]) -
      in6_data[i * stride_4_0] * in5_data[i * stride_5_0] * in7_data[i *
      stride_6_0]) + in8_data[i * stride_7_0] * in9_data[i * stride_8_0];
  }
}

void GNSS_preprocessingModelClass::G_binary_expand_op_espyy15uognn(real_T
  in1_data[], const int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2])
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
  for (int32_T i{0}; i < in1_idx_0; i++) {
    in1_data[i + (in1_size[0] << 1)] = in2_data[i * stride_0_0] * in3_data[i *
      stride_1_0] + in4_data[i * stride_2_0] * in5_data[i * stride_3_0];
  }
}

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_sqrt_ja(real_T
  x_data[], const int32_T *x_size)
{
  int32_T b;
  int32_T scalarLB;
  int32_T vectorUB;
  b = *x_size;
  scalarLB = (*x_size / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T k{0}; k <= vectorUB; k += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&x_data[k]);
    _mm_storeu_pd(&x_data[k], _mm_sqrt_pd(tmp));
  }

  for (int32_T k{scalarLB}; k < b; k++) {
    x_data[k] = std::sqrt(x_data[k]);
  }
}

// Function for MATLAB Function: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::Get_Kepler_Satellite_Position_j(const real_T
  Ephemeris_C_rs_data[], const int32_T Ephemeris_C_rs_size[2], const real_T
  Ephemeris_DELTA_N_data[], const int32_T Ephemeris_DELTA_N_size[2], const
  real_T Ephemeris_M_0_data[], const int32_T Ephemeris_M_0_size[2], const real_T
  Ephemeris_C_uc_data[], const int32_T Ephemeris_C_uc_size[2], const real_T
  Ephemeris_E_data[], const int32_T Ephemeris_E_size[2], const real_T
  Ephemeris_C_us_data[], const int32_T Ephemeris_C_us_size[2], const real_T
  Ephemeris_SQRT_A_data[], const int32_T Ephemeris_SQRT_A_size[2], const real_T
  Ephemeris_T_oe_data[], const int32_T Ephemeris_T_oe_size[2], const real_T
  Ephemeris_C_ic_data[], const int32_T Ephemeris_C_ic_size[2], const real_T
  Ephemeris_OMEGA_0_data[], const int32_T Ephemeris_OMEGA_0_size[2], const
  real_T Ephemeris_C_is_data[], const int32_T Ephemeris_C_is_size[2], const
  real_T Ephemeris_I_0_data[], const int32_T Ephemeris_I_0_size[2], const real_T
  Ephemeris_C_rc_data[], const int32_T Ephemeris_C_rc_size[2], const real_T
  Ephemeris_omega_data[], const int32_T Ephemeris_omega_size[2], const real_T
  Ephemeris_OMEGADOT_data[], const int32_T Ephemeris_OMEGADOT_size[2], const
  real_T Ephemeris_IDOT_data[], const int32_T Ephemeris_IDOT_size[2], const
  real_T T_emission_data[], const int32_T T_emission_size[2], const real_T
  user_position[3], real_T sv_pos_data[], int32_T sv_pos_size[2], real_T
  sv_vel_data[], int32_T sv_vel_size[2])
{
  __m128d tmp_0;
  __m128d tmp_1;
  __m128d tmp_2;
  __m128d tmp_3;
  __m128d tmp_4;
  __m128d tmp_5;
  __m128d tmp_6;
  __m128d tmp_7;
  real_T E_k_Dot_data[37];
  real_T PHI_k_Dot_data[37];
  real_T PHI_k_data[37];
  real_T X_k_tmp_data[37];
  real_T c_data[37];
  real_T cos2PHI_k_data[37];
  real_T cosinus_E_k_data[37];
  real_T cosinus_i_k_data[37];
  real_T cosinus_u_k_data[37];
  real_T d_data[37];
  real_T f_data[37];
  real_T i_k_data[37];
  real_T r_k_Dot_data[37];
  real_T r_k_data[37];
  real_T sin2PHI_k_data[37];
  real_T sinus_E_k_data[37];
  real_T sinus_lambda_k_data[37];
  real_T t_k_data[37];
  real_T tmp_data[37];
  real_T y_tmp_data[37];
  real_T sv_pos_tmp[9];
  real_T tmp[9];
  real_T sv_pos_tmp_0[3];
  real_T N;
  real_T sinus_lambda_k;
  real_T y_user;
  real_T z_user;
  int32_T E_k_Dot_size[2];
  int32_T PHI_k_Dot_size[2];
  int32_T PHI_k_size[2];
  int32_T X_k_tmp_size[2];
  int32_T c_size[2];
  int32_T cos2PHI_k_size[2];
  int32_T cosinus_E_k_size[2];
  int32_T cosinus_i_k_size[2];
  int32_T cosinus_u_k_size[2];
  int32_T d_size[2];
  int32_T f_size[2];
  int32_T i_k_size[2];
  int32_T r_k_Dot_size[2];
  int32_T r_k_size[2];
  int32_T sin2PHI_k_size[2];
  int32_T sinus_E_k_size[2];
  int32_T sinus_lambda_k_size[2];
  int32_T t_k_size[2];
  int32_T tmp_size[2];
  int32_T y_tmp_size[2];
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T scalarLB_tmp;
  int32_T transport_angle_size;
  int32_T vectorUB;
  if (T_emission_size[1] == Ephemeris_T_oe_size[1]) {
    t_k_size[0] = 1;
    t_k_size[1] = T_emission_size[1];
    loop_ub = T_emission_size[1];
    scalarLB = (T_emission_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      _mm_storeu_pd(&t_k_data[t_k_data_tmp], _mm_sub_pd(_mm_loadu_pd
        (&T_emission_data[t_k_data_tmp]), _mm_loadu_pd
        (&Ephemeris_T_oe_data[t_k_data_tmp])));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      t_k_data[t_k_data_tmp] = T_emission_data[t_k_data_tmp] -
        Ephemeris_T_oe_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProcessingSingl_minus_d4(t_k_data, t_k_size, T_emission_data,
      T_emission_size, Ephemeris_T_oe_data, Ephemeris_T_oe_size);
  }

  correct_Gps_Time_At_Week_Cros_i(t_k_data, t_k_size);
  Get_Kepler_Eccentric_Anomaly_b(t_k_data, t_k_size, Ephemeris_DELTA_N_data,
    Ephemeris_DELTA_N_size, Ephemeris_M_0_data, Ephemeris_M_0_size,
    Ephemeris_E_data, Ephemeris_E_size, Ephemeris_SQRT_A_data,
    Ephemeris_SQRT_A_size, sinus_E_k_data, sinus_E_k_size, E_k_Dot_data,
    E_k_Dot_size);
  cosinus_E_k_size[0] = 1;
  cosinus_E_k_size[1] = sinus_E_k_size[1];
  loop_ub = sinus_E_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&cosinus_E_k_data[0], &sinus_E_k_data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  GNSSPreProcessingSingleAn_cos_g(cosinus_E_k_data, cosinus_E_k_size);
  GNSSPreProcessingSingleAn_sin_g(sinus_E_k_data, sinus_E_k_size);
  if (Ephemeris_E_size[1] == cosinus_E_k_size[1]) {
    r_k_Dot_size[0] = 1;
    r_k_Dot_size[1] = Ephemeris_E_size[1];
    loop_ub = Ephemeris_E_size[1];
    scalarLB = (Ephemeris_E_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&cosinus_E_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&r_k_Dot_data[t_k_data_tmp], _mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_E_data[t_k_data_tmp]), tmp_7));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      r_k_Dot_data[t_k_data_tmp] = Ephemeris_E_data[t_k_data_tmp] *
        cosinus_E_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProcessingSingl_times_du(r_k_Dot_data, r_k_Dot_size, Ephemeris_E_data,
      Ephemeris_E_size, cosinus_E_k_data, cosinus_E_k_size);
  }

  y_tmp_size[0] = 1;
  y_tmp_size[1] = r_k_Dot_size[1];
  loop_ub = r_k_Dot_size[1];
  scalarLB = (r_k_Dot_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&r_k_Dot_data[t_k_data_tmp]);
    _mm_storeu_pd(&y_tmp_data[t_k_data_tmp], _mm_sub_pd(_mm_set1_pd(1.0), tmp_7));
  }

  for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++) {
    y_tmp_data[t_k_data_tmp] = 1.0 - r_k_Dot_data[t_k_data_tmp];
  }

  f_size[0] = 1;
  f_size[1] = Ephemeris_E_size[1];
  loop_ub = Ephemeris_E_size[1];
  scalarLB = (Ephemeris_E_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_E_data[t_k_data_tmp]);
    _mm_storeu_pd(&f_data[t_k_data_tmp], _mm_sub_pd(_mm_set1_pd(1.0), _mm_mul_pd
      (tmp_7, tmp_7)));
  }

  for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++) {
    N = Ephemeris_E_data[t_k_data_tmp];
    f_data[t_k_data_tmp] = 1.0 - N * N;
  }

  GNSSPreProcessingSingleA_sqrt_j(f_data, f_size);
  if ((f_size[1] != sinus_E_k_size[1]) || ((f_size[1] == 1 ? sinus_E_k_size[1] :
        f_size[1]) != r_k_Dot_size[1]) || (cosinus_E_k_size[1] !=
       Ephemeris_E_size[1]) || ((cosinus_E_k_size[1] == 1 ? Ephemeris_E_size[1] :
        cosinus_E_k_size[1]) != r_k_Dot_size[1])) {
    GNS_binary_expand_op_espyy15uog(tmp_data, tmp_size, f_data, f_size,
      sinus_E_k_data, sinus_E_k_size, y_tmp_data, y_tmp_size, cosinus_E_k_data,
      cosinus_E_k_size, Ephemeris_E_data, Ephemeris_E_size);
  }

  GNS_binary_expand_op_espyy15uog(tmp_data, tmp_size, f_data, f_size,
    sinus_E_k_data, sinus_E_k_size, y_tmp_data, y_tmp_size, cosinus_E_k_data,
    cosinus_E_k_size, Ephemeris_E_data, Ephemeris_E_size);
  if ((f_size[1] == sinus_E_k_size[1]) && ((f_size[1] == 1 ? sinus_E_k_size[1] :
        f_size[1]) == r_k_Dot_size[1]) && (cosinus_E_k_size[1] ==
       Ephemeris_E_size[1]) && ((cosinus_E_k_size[1] == 1 ? Ephemeris_E_size[1] :
        cosinus_E_k_size[1]) == r_k_Dot_size[1]) && (tmp_size[1] ==
       Ephemeris_omega_size[1])) {
    PHI_k_size[0] = 1;
    PHI_k_size[1] = f_size[1];
    loop_ub = f_size[1];
    scalarLB = (f_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&f_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&sinus_E_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&y_tmp_data[t_k_data_tmp]);
      _mm_storeu_pd(&PHI_k_data[t_k_data_tmp], _mm_div_pd(_mm_mul_pd(tmp_7,
        tmp_5), tmp_6));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      PHI_k_data[t_k_data_tmp] = f_data[t_k_data_tmp] *
        sinus_E_k_data[t_k_data_tmp] / y_tmp_data[t_k_data_tmp];
    }

    f_size[0] = 1;
    f_size[1] = cosinus_E_k_size[1];
    loop_ub = cosinus_E_k_size[1];
    scalarLB = (cosinus_E_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&cosinus_E_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&y_tmp_data[t_k_data_tmp]);
      _mm_storeu_pd(&f_data[t_k_data_tmp], _mm_div_pd(_mm_sub_pd(tmp_7,
        _mm_loadu_pd(&Ephemeris_E_data[t_k_data_tmp])), tmp_5));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      f_data[t_k_data_tmp] = (cosinus_E_k_data[t_k_data_tmp] -
        Ephemeris_E_data[t_k_data_tmp]) / y_tmp_data[t_k_data_tmp];
    }

    GNSSPreProcessingSingle_atan2_g(PHI_k_data, PHI_k_size, f_data, f_size,
      tmp_data, tmp_size);
    PHI_k_size[0] = 1;
    PHI_k_size[1] = tmp_size[1];
    loop_ub = tmp_size[1];
    scalarLB = (tmp_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&tmp_data[t_k_data_tmp]);
      _mm_storeu_pd(&PHI_k_data[t_k_data_tmp], _mm_add_pd(tmp_7, _mm_loadu_pd
        (&Ephemeris_omega_data[t_k_data_tmp])));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      PHI_k_data[t_k_data_tmp] = tmp_data[t_k_data_tmp] +
        Ephemeris_omega_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_gm(PHI_k_data, PHI_k_size, f_data, f_size,
      sinus_E_k_data, sinus_E_k_size, y_tmp_data, y_tmp_size, cosinus_E_k_data,
      cosinus_E_k_size, Ephemeris_E_data, Ephemeris_E_size, Ephemeris_omega_data,
      Ephemeris_omega_size);
  }

  cosinus_E_k_size[0] = 1;
  cosinus_E_k_size[1] = PHI_k_size[1];
  loop_ub = PHI_k_size[1];
  scalarLB = (PHI_k_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&PHI_k_data[t_k_data_tmp]);
    _mm_storeu_pd(&cosinus_E_k_data[t_k_data_tmp], _mm_mul_pd(_mm_set1_pd(2.0),
      tmp_7));
  }

  for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++) {
    cosinus_E_k_data[t_k_data_tmp] = 2.0 * PHI_k_data[t_k_data_tmp];
  }

  sin2PHI_k_size[0] = 1;
  sin2PHI_k_size[1] = PHI_k_size[1];
  loop_ub = PHI_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&sin2PHI_k_data[0], &cosinus_E_k_data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  GNSSPreProcessingSingleAn_sin_g(sin2PHI_k_data, sin2PHI_k_size);
  cos2PHI_k_size[0] = 1;
  cos2PHI_k_size[1] = PHI_k_size[1];
  loop_ub = PHI_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&cos2PHI_k_data[0], &cosinus_E_k_data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  GNSSPreProcessingSingleAn_cos_g(cos2PHI_k_data, cos2PHI_k_size);
  if ((Ephemeris_C_us_size[1] == sin2PHI_k_size[1]) && (Ephemeris_C_uc_size[1] ==
       cos2PHI_k_size[1]) && ((Ephemeris_C_us_size[1] == 1 ? sin2PHI_k_size[1] :
        Ephemeris_C_us_size[1]) == (Ephemeris_C_uc_size[1] == 1 ?
        cos2PHI_k_size[1] : Ephemeris_C_uc_size[1])) && (((Ephemeris_C_us_size[1]
         == 1 ? sin2PHI_k_size[1] : Ephemeris_C_us_size[1]) == 1 ?
        Ephemeris_C_uc_size[1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_uc_size[1]
        : Ephemeris_C_us_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_us_size
        [1]) == PHI_k_size[1])) {
    loop_ub = PHI_k_size[1] - 1;
    PHI_k_size[0] = 1;
    scalarLB = (PHI_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&sin2PHI_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&PHI_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&PHI_k_data[t_k_data_tmp], _mm_add_pd(_mm_add_pd(_mm_mul_pd
        (_mm_loadu_pd(&Ephemeris_C_us_data[t_k_data_tmp]), tmp_7), _mm_mul_pd
        (_mm_loadu_pd(&Ephemeris_C_uc_data[t_k_data_tmp]), tmp_5)), tmp_6));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      PHI_k_data[t_k_data_tmp] += Ephemeris_C_us_data[t_k_data_tmp] *
        sin2PHI_k_data[t_k_data_tmp] + Ephemeris_C_uc_data[t_k_data_tmp] *
        cos2PHI_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_du(PHI_k_data, PHI_k_size, Ephemeris_C_us_data,
      Ephemeris_C_us_size, sin2PHI_k_data, sin2PHI_k_size, Ephemeris_C_uc_data,
      Ephemeris_C_uc_size, cos2PHI_k_data, cos2PHI_k_size);
  }

  scalarLB_tmp = (Ephemeris_SQRT_A_size[1] / 2) << 1;
  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&tmp_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&tmp_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  if ((Ephemeris_SQRT_A_size[1] == r_k_Dot_size[1]) && (Ephemeris_C_rs_size[1] ==
       sin2PHI_k_size[1]) && (Ephemeris_C_rc_size[1] == cos2PHI_k_size[1]) &&
      ((Ephemeris_C_rs_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_rs_size[1])
       == (Ephemeris_C_rc_size[1] == 1 ? cos2PHI_k_size[1] :
           Ephemeris_C_rc_size[1])) && (((Ephemeris_C_rs_size[1] == 1 ?
         sin2PHI_k_size[1] : Ephemeris_C_rs_size[1]) == 1 ? Ephemeris_C_rc_size
        [1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_rc_size[1] :
        Ephemeris_C_rs_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_rs_size[1])
       == (Ephemeris_SQRT_A_size[1] == 1 ? r_k_Dot_size[1] :
           Ephemeris_SQRT_A_size[1]))) {
    r_k_size[0] = 1;
    r_k_size[1] = Ephemeris_SQRT_A_size[1];
    loop_ub = Ephemeris_SQRT_A_size[1];
    vectorUB = scalarLB_tmp - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&r_k_Dot_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&sin2PHI_k_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&r_k_data[t_k_data_tmp], _mm_add_pd(_mm_mul_pd(_mm_mul_pd
        (tmp_7, tmp_7), _mm_sub_pd(_mm_set1_pd(1.0), tmp_5)), _mm_add_pd
        (_mm_mul_pd(_mm_loadu_pd(&Ephemeris_C_rs_data[t_k_data_tmp]), tmp_6),
         _mm_mul_pd(_mm_loadu_pd(&Ephemeris_C_rc_data[t_k_data_tmp]), tmp_4))));
    }

    for (int32_T t_k_data_tmp{scalarLB_tmp}; t_k_data_tmp < loop_ub;
         t_k_data_tmp++) {
      N = Ephemeris_SQRT_A_data[t_k_data_tmp];
      r_k_data[t_k_data_tmp] = N * N * (1.0 - r_k_Dot_data[t_k_data_tmp]) +
        (Ephemeris_C_rs_data[t_k_data_tmp] * sin2PHI_k_data[t_k_data_tmp] +
         Ephemeris_C_rc_data[t_k_data_tmp] * cos2PHI_k_data[t_k_data_tmp]);
    }
  } else {
    GNSSPreProc_binary_expand_op_ii(r_k_data, r_k_size, Ephemeris_SQRT_A_data,
      Ephemeris_SQRT_A_size, r_k_Dot_data, r_k_Dot_size, Ephemeris_C_rs_data,
      Ephemeris_C_rs_size, sin2PHI_k_data, sin2PHI_k_size, Ephemeris_C_rc_data,
      Ephemeris_C_rc_size, cos2PHI_k_data, cos2PHI_k_size);
  }

  if ((Ephemeris_C_is_size[1] == sin2PHI_k_size[1]) && (Ephemeris_C_ic_size[1] ==
       cos2PHI_k_size[1]) && ((Ephemeris_C_is_size[1] == 1 ? sin2PHI_k_size[1] :
        Ephemeris_C_is_size[1]) == (Ephemeris_C_ic_size[1] == 1 ?
        cos2PHI_k_size[1] : Ephemeris_C_ic_size[1])) && (((Ephemeris_C_is_size[1]
         == 1 ? sin2PHI_k_size[1] : Ephemeris_C_is_size[1]) == 1 ?
        Ephemeris_C_ic_size[1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_ic_size[1]
        : Ephemeris_C_is_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_is_size
        [1]) == Ephemeris_I_0_size[1]) && (Ephemeris_IDOT_size[1] == t_k_size[1])
      && ((Ephemeris_I_0_size[1] == 1 ? (Ephemeris_C_is_size[1] == 1 ?
         sin2PHI_k_size[1] : Ephemeris_C_is_size[1]) == 1 ? Ephemeris_C_ic_size
           [1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_ic_size[1] :
           Ephemeris_C_is_size[1] == 1 ? sin2PHI_k_size[1] :
           Ephemeris_C_is_size[1] : Ephemeris_I_0_size[1]) ==
          (Ephemeris_IDOT_size[1] == 1 ? t_k_size[1] : Ephemeris_IDOT_size[1])))
  {
    i_k_size[0] = 1;
    i_k_size[1] = Ephemeris_I_0_size[1];
    loop_ub = Ephemeris_I_0_size[1];
    scalarLB = (Ephemeris_I_0_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&sin2PHI_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&t_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&i_k_data[t_k_data_tmp], _mm_add_pd(_mm_add_pd(_mm_add_pd
        (_mm_mul_pd(_mm_loadu_pd(&Ephemeris_C_is_data[t_k_data_tmp]), tmp_7),
         _mm_mul_pd(_mm_loadu_pd(&Ephemeris_C_ic_data[t_k_data_tmp]), tmp_5)),
        _mm_loadu_pd(&Ephemeris_I_0_data[t_k_data_tmp])), _mm_mul_pd
        (_mm_loadu_pd(&Ephemeris_IDOT_data[t_k_data_tmp]), tmp_6)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      i_k_data[t_k_data_tmp] = ((Ephemeris_C_is_data[t_k_data_tmp] *
        sin2PHI_k_data[t_k_data_tmp] + Ephemeris_C_ic_data[t_k_data_tmp] *
        cos2PHI_k_data[t_k_data_tmp]) + Ephemeris_I_0_data[t_k_data_tmp]) +
        Ephemeris_IDOT_data[t_k_data_tmp] * t_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_ld(i_k_data, i_k_size, Ephemeris_I_0_data,
      Ephemeris_I_0_size, Ephemeris_C_is_data, Ephemeris_C_is_size,
      sin2PHI_k_data, sin2PHI_k_size, Ephemeris_C_ic_data, Ephemeris_C_ic_size,
      cos2PHI_k_data, cos2PHI_k_size, Ephemeris_IDOT_data, Ephemeris_IDOT_size,
      t_k_data, t_k_size);
  }

  f_size[0] = 1;
  f_size[1] = Ephemeris_OMEGADOT_size[1];
  loop_ub = Ephemeris_OMEGADOT_size[1];
  scalarLB = (Ephemeris_OMEGADOT_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    _mm_storeu_pd(&f_data[t_k_data_tmp], _mm_sub_pd(_mm_loadu_pd
      (&Ephemeris_OMEGADOT_data[t_k_data_tmp]), _mm_set1_pd(7.2921151467E-5)));
  }

  for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++) {
    f_data[t_k_data_tmp] = Ephemeris_OMEGADOT_data[t_k_data_tmp] -
      7.2921151467E-5;
  }

  if ((Ephemeris_OMEGADOT_size[1] == t_k_size[1]) && ((Ephemeris_OMEGADOT_size[1]
        == 1 ? t_k_size[1] : Ephemeris_OMEGADOT_size[1]) ==
       Ephemeris_OMEGA_0_size[1]) && ((Ephemeris_OMEGA_0_size[1] == 1 ?
        Ephemeris_OMEGADOT_size[1] == 1 ? t_k_size[1] : Ephemeris_OMEGADOT_size
        [1] : Ephemeris_OMEGA_0_size[1]) == Ephemeris_T_oe_size[1])) {
    loop_ub = Ephemeris_OMEGA_0_size[1] - 1;
    t_k_size[0] = 1;
    t_k_size[1] = Ephemeris_OMEGA_0_size[1];
    scalarLB = (Ephemeris_OMEGA_0_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&f_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&t_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&t_k_data[t_k_data_tmp], _mm_sub_pd(_mm_add_pd(_mm_mul_pd
        (tmp_7, tmp_5), _mm_loadu_pd(&Ephemeris_OMEGA_0_data[t_k_data_tmp])),
        _mm_mul_pd(_mm_set1_pd(7.2921151467E-5), _mm_loadu_pd
                   (&Ephemeris_T_oe_data[t_k_data_tmp]))));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      t_k_data[t_k_data_tmp] = (f_data[t_k_data_tmp] * t_k_data[t_k_data_tmp] +
        Ephemeris_OMEGA_0_data[t_k_data_tmp]) - 7.2921151467E-5 *
        Ephemeris_T_oe_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_ow(t_k_data, t_k_size, Ephemeris_OMEGA_0_data,
      Ephemeris_OMEGA_0_size, f_data, f_size, Ephemeris_T_oe_data,
      Ephemeris_T_oe_size);
  }

  cosinus_u_k_size[0] = 1;
  cosinus_u_k_size[1] = PHI_k_size[1];
  loop_ub = PHI_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&cosinus_u_k_data[0], &PHI_k_data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  GNSSPreProcessingSingleAn_cos_g(cosinus_u_k_data, cosinus_u_k_size);
  GNSSPreProcessingSingleAn_sin_g(PHI_k_data, PHI_k_size);
  cosinus_i_k_size[0] = 1;
  cosinus_i_k_size[1] = i_k_size[1];
  loop_ub = i_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&cosinus_i_k_data[0], &i_k_data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  GNSSPreProcessingSingleAn_cos_g(cosinus_i_k_data, cosinus_i_k_size);
  GNSSPreProcessingSingleAn_sin_g(i_k_data, i_k_size);
  sinus_lambda_k_size[0] = 1;
  sinus_lambda_k_size[1] = t_k_size[1];
  loop_ub = t_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&sinus_lambda_k_data[0], &t_k_data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  GNSSPreProcessingSingleAn_sin_g(sinus_lambda_k_data, sinus_lambda_k_size);
  GNSSPreProcessingSingleAn_cos_g(t_k_data, t_k_size);
  if (r_k_size[1] == cosinus_u_k_size[1]) {
    X_k_tmp_size[0] = 1;
    X_k_tmp_size[1] = r_k_size[1];
    loop_ub = r_k_size[1];
    scalarLB = (r_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&r_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&cosinus_u_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&X_k_tmp_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_5));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      X_k_tmp_data[t_k_data_tmp] = r_k_data[t_k_data_tmp] *
        cosinus_u_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProcessingSingl_times_du(X_k_tmp_data, X_k_tmp_size, r_k_data,
      r_k_size, cosinus_u_k_data, cosinus_u_k_size);
  }

  if (r_k_size[1] == PHI_k_size[1]) {
    loop_ub = r_k_size[1] - 1;
    r_k_size[0] = 1;
    scalarLB = (r_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&r_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&PHI_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&r_k_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_5));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      r_k_data[t_k_data_tmp] *= PHI_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProcessingSing_times_duk(r_k_data, r_k_size, PHI_k_data, PHI_k_size);
  }

  sv_pos_size[0] = X_k_tmp_size[1];
  sv_pos_size[1] = 3;
  loop_ub = X_k_tmp_size[1] * 3;
  if (loop_ub - 1 >= 0) {
    std::memset(&sv_pos_data[0], 0, static_cast<uint32_T>(loop_ub) * sizeof
                (real_T));
  }

  if (r_k_size[1] == cosinus_i_k_size[1]) {
    c_size[0] = 1;
    c_size[1] = r_k_size[1];
    loop_ub = r_k_size[1];
    scalarLB = (r_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&r_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&cosinus_i_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&c_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_5));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      c_data[t_k_data_tmp] = r_k_data[t_k_data_tmp] *
        cosinus_i_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProcessingSingl_times_du(c_data, c_size, r_k_data, r_k_size,
      cosinus_i_k_data, cosinus_i_k_size);
  }

  if ((X_k_tmp_size[1] == t_k_size[1]) && (c_size[1] == sinus_lambda_k_size[1]) &&
      ((X_k_tmp_size[1] == 1 ? t_k_size[1] : X_k_tmp_size[1]) == (c_size[1] == 1
        ? sinus_lambda_k_size[1] : c_size[1]))) {
    loop_ub = X_k_tmp_size[1];
    scalarLB = (X_k_tmp_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&X_k_tmp_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&t_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&c_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&sinus_lambda_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&sv_pos_data[t_k_data_tmp], _mm_sub_pd(_mm_mul_pd(tmp_7,
        tmp_5), _mm_mul_pd(tmp_6, tmp_4)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      sv_pos_data[t_k_data_tmp] = X_k_tmp_data[t_k_data_tmp] *
        t_k_data[t_k_data_tmp] - c_data[t_k_data_tmp] *
        sinus_lambda_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_in(sv_pos_data, X_k_tmp_data, X_k_tmp_size,
      t_k_data, t_k_size, c_data, c_size, sinus_lambda_k_data,
      sinus_lambda_k_size);
  }

  if ((X_k_tmp_size[1] == sinus_lambda_k_size[1]) && (c_size[1] == t_k_size[1]) &&
      ((X_k_tmp_size[1] == 1 ? sinus_lambda_k_size[1] : X_k_tmp_size[1]) ==
       (c_size[1] == 1 ? t_k_size[1] : c_size[1]))) {
    loop_ub = sv_pos_size[0];
    scalarLB = (sv_pos_size[0] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&X_k_tmp_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&sinus_lambda_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&c_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&t_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&sv_pos_data[t_k_data_tmp + sv_pos_size[0]], _mm_add_pd
                    (_mm_mul_pd(tmp_7, tmp_5), _mm_mul_pd(tmp_6, tmp_4)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      sv_pos_data[t_k_data_tmp + sv_pos_size[0]] = X_k_tmp_data[t_k_data_tmp] *
        sinus_lambda_k_data[t_k_data_tmp] + c_data[t_k_data_tmp] *
        t_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_kd(sv_pos_data, sv_pos_size, X_k_tmp_data,
      X_k_tmp_size, sinus_lambda_k_data, sinus_lambda_k_size, c_data, c_size,
      t_k_data, t_k_size);
  }

  if (r_k_size[1] == i_k_size[1]) {
    d_size[0] = 1;
    d_size[1] = r_k_size[1];
    loop_ub = r_k_size[1];
    scalarLB = (r_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&r_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&i_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&d_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_5));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      d_data[t_k_data_tmp] = r_k_data[t_k_data_tmp] * i_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProcessingSingl_times_du(d_data, d_size, r_k_data, r_k_size, i_k_data,
      i_k_size);
  }

  loop_ub = sv_pos_size[0];
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp < loop_ub; t_k_data_tmp++) {
    sv_pos_data[t_k_data_tmp + (sv_pos_size[0] << 1)] = d_data[t_k_data_tmp];
  }

  PHI_k_Dot_size[0] = 1;
  PHI_k_Dot_size[1] = Ephemeris_E_size[1];
  loop_ub = Ephemeris_E_size[1];
  scalarLB = (Ephemeris_E_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_E_data[t_k_data_tmp]);
    _mm_storeu_pd(&PHI_k_Dot_data[t_k_data_tmp], _mm_sub_pd(_mm_set1_pd(1.0),
      _mm_mul_pd(tmp_7, tmp_7)));
  }

  for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++) {
    N = Ephemeris_E_data[t_k_data_tmp];
    PHI_k_Dot_data[t_k_data_tmp] = 1.0 - N * N;
  }

  GNSSPreProcessingSingleA_sqrt_j(PHI_k_Dot_data, PHI_k_Dot_size);
  if ((PHI_k_Dot_size[1] == E_k_Dot_size[1]) && ((PHI_k_Dot_size[1] == 1 ?
        E_k_Dot_size[1] : PHI_k_Dot_size[1]) == r_k_Dot_size[1])) {
    loop_ub = PHI_k_Dot_size[1] - 1;
    PHI_k_Dot_size[0] = 1;
    scalarLB = (PHI_k_Dot_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&PHI_k_Dot_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&E_k_Dot_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&y_tmp_data[t_k_data_tmp]);
      _mm_storeu_pd(&PHI_k_Dot_data[t_k_data_tmp], _mm_div_pd(_mm_mul_pd(tmp_7,
        tmp_5), tmp_6));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      PHI_k_Dot_data[t_k_data_tmp] = PHI_k_Dot_data[t_k_data_tmp] *
        E_k_Dot_data[t_k_data_tmp] / y_tmp_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_o1(PHI_k_Dot_data, PHI_k_Dot_size, E_k_Dot_data,
      E_k_Dot_size, y_tmp_data, y_tmp_size);
  }

  if ((Ephemeris_C_us_size[1] == cos2PHI_k_size[1]) && (Ephemeris_C_uc_size[1] ==
       sin2PHI_k_size[1]) && ((Ephemeris_C_us_size[1] == 1 ? cos2PHI_k_size[1] :
        Ephemeris_C_us_size[1]) == (Ephemeris_C_uc_size[1] == 1 ?
        sin2PHI_k_size[1] : Ephemeris_C_uc_size[1])) && (((Ephemeris_C_us_size[1]
         == 1 ? cos2PHI_k_size[1] : Ephemeris_C_us_size[1]) == 1 ?
        Ephemeris_C_uc_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_uc_size[1]
        : Ephemeris_C_us_size[1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_us_size
        [1]) == PHI_k_Dot_size[1])) {
    cosinus_E_k_size[0] = 1;
    cosinus_E_k_size[1] = Ephemeris_C_us_size[1];
    loop_ub = Ephemeris_C_us_size[1];
    scalarLB = (Ephemeris_C_us_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_set1_pd(2.0);
      tmp_5 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&sin2PHI_k_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&PHI_k_Dot_data[t_k_data_tmp]);
      _mm_storeu_pd(&cosinus_E_k_data[t_k_data_tmp], _mm_mul_pd(_mm_sub_pd
        (_mm_add_pd(_mm_mul_pd(_mm_mul_pd(tmp_7, _mm_loadu_pd
        (&Ephemeris_C_us_data[t_k_data_tmp])), tmp_5), _mm_set1_pd(1.0)),
         _mm_mul_pd(_mm_mul_pd(tmp_7, _mm_loadu_pd
        (&Ephemeris_C_uc_data[t_k_data_tmp])), tmp_6)), tmp_4));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      cosinus_E_k_data[t_k_data_tmp] = ((2.0 * Ephemeris_C_us_data[t_k_data_tmp]
        * cos2PHI_k_data[t_k_data_tmp] + 1.0) - 2.0 *
        Ephemeris_C_uc_data[t_k_data_tmp] * sin2PHI_k_data[t_k_data_tmp]) *
        PHI_k_Dot_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_dt(cosinus_E_k_data, cosinus_E_k_size,
      Ephemeris_C_us_data, Ephemeris_C_us_size, cos2PHI_k_data, cos2PHI_k_size,
      Ephemeris_C_uc_data, Ephemeris_C_uc_size, sin2PHI_k_data, sin2PHI_k_size,
      PHI_k_Dot_data, PHI_k_Dot_size);
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&tmp_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&tmp_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&y_tmp_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&tmp_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  if ((Ephemeris_C_rs_size[1] == cos2PHI_k_size[1]) && (Ephemeris_C_rc_size[1] ==
       sin2PHI_k_size[1]) && ((Ephemeris_C_rs_size[1] == 1 ? cos2PHI_k_size[1] :
        Ephemeris_C_rs_size[1]) == (Ephemeris_C_rc_size[1] == 1 ?
        sin2PHI_k_size[1] : Ephemeris_C_rc_size[1])) && (((Ephemeris_C_rs_size[1]
         == 1 ? cos2PHI_k_size[1] : Ephemeris_C_rs_size[1]) == 1 ?
        Ephemeris_C_rc_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_rc_size[1]
        : Ephemeris_C_rs_size[1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_rs_size
        [1]) == PHI_k_Dot_size[1]) && (Ephemeris_SQRT_A_size[1] ==
       Ephemeris_E_size[1]) && ((Ephemeris_SQRT_A_size[1] == 1 ?
        Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1]) == sinus_E_k_size[1]) &&
      (((Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] :
         Ephemeris_SQRT_A_size[1]) == 1 ? sinus_E_k_size[1] :
        Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] :
        Ephemeris_SQRT_A_size[1]) == E_k_Dot_size[1]) &&
      ((((Ephemeris_C_rs_size[1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_rs_size
          [1]) == 1 ? Ephemeris_C_rc_size[1] == 1 ? sin2PHI_k_size[1] :
         Ephemeris_C_rc_size[1] : Ephemeris_C_rs_size[1] == 1 ? cos2PHI_k_size[1]
         : Ephemeris_C_rs_size[1]) == 1 ? PHI_k_Dot_size[1] :
        (Ephemeris_C_rs_size[1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_rs_size[1])
        == 1 ? Ephemeris_C_rc_size[1] == 1 ? sin2PHI_k_size[1] :
        Ephemeris_C_rc_size[1] : Ephemeris_C_rs_size[1] == 1 ? cos2PHI_k_size[1]
        : Ephemeris_C_rs_size[1]) == (((Ephemeris_SQRT_A_size[1] == 1 ?
          Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1]) == 1 ? sinus_E_k_size
         [1] : Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] :
         Ephemeris_SQRT_A_size[1]) == 1 ? E_k_Dot_size[1] :
        (Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] :
         Ephemeris_SQRT_A_size[1]) == 1 ? sinus_E_k_size[1] :
        Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] :
        Ephemeris_SQRT_A_size[1]))) {
    r_k_Dot_size[0] = 1;
    r_k_Dot_size[1] = Ephemeris_C_rs_size[1];
    loop_ub = Ephemeris_C_rs_size[1];
    scalarLB = (Ephemeris_C_rs_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&sin2PHI_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&PHI_k_Dot_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
      tmp_2 = _mm_loadu_pd(&sinus_E_k_data[t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&E_k_Dot_data[t_k_data_tmp]);
      _mm_storeu_pd(&r_k_Dot_data[t_k_data_tmp], _mm_add_pd(_mm_mul_pd
        (_mm_mul_pd(_mm_sub_pd(_mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_C_rs_data[t_k_data_tmp]), tmp_7), _mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_C_rc_data[t_k_data_tmp]), tmp_5)), _mm_set1_pd(2.0)), tmp_6),
        _mm_mul_pd(_mm_mul_pd(_mm_mul_pd(_mm_mul_pd(tmp_4, tmp_4), _mm_loadu_pd(
        &Ephemeris_E_data[t_k_data_tmp])), tmp_2), tmp_3)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      N = Ephemeris_SQRT_A_data[t_k_data_tmp];
      r_k_Dot_data[t_k_data_tmp] = (Ephemeris_C_rs_data[t_k_data_tmp] *
        cos2PHI_k_data[t_k_data_tmp] - Ephemeris_C_rc_data[t_k_data_tmp] *
        sin2PHI_k_data[t_k_data_tmp]) * 2.0 * PHI_k_Dot_data[t_k_data_tmp] + N *
        N * Ephemeris_E_data[t_k_data_tmp] * sinus_E_k_data[t_k_data_tmp] *
        E_k_Dot_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_lf(r_k_Dot_data, r_k_Dot_size,
      Ephemeris_C_rs_data, Ephemeris_C_rs_size, cos2PHI_k_data, cos2PHI_k_size,
      Ephemeris_C_rc_data, Ephemeris_C_rc_size, sin2PHI_k_data, sin2PHI_k_size,
      PHI_k_Dot_data, PHI_k_Dot_size, Ephemeris_SQRT_A_data,
      Ephemeris_SQRT_A_size, Ephemeris_E_data, Ephemeris_E_size, sinus_E_k_data,
      sinus_E_k_size, E_k_Dot_data, E_k_Dot_size);
  }

  if ((Ephemeris_C_is_size[1] == cos2PHI_k_size[1]) && (Ephemeris_C_ic_size[1] ==
       sin2PHI_k_size[1]) && ((Ephemeris_C_is_size[1] == 1 ? cos2PHI_k_size[1] :
        Ephemeris_C_is_size[1]) == (Ephemeris_C_ic_size[1] == 1 ?
        sin2PHI_k_size[1] : Ephemeris_C_ic_size[1])) && (((Ephemeris_C_is_size[1]
         == 1 ? cos2PHI_k_size[1] : Ephemeris_C_is_size[1]) == 1 ?
        Ephemeris_C_ic_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_ic_size[1]
        : Ephemeris_C_is_size[1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_is_size
        [1]) == PHI_k_Dot_size[1]) && ((((Ephemeris_C_is_size[1] == 1 ?
          cos2PHI_k_size[1] : Ephemeris_C_is_size[1]) == 1 ?
         Ephemeris_C_ic_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_ic_size[1]
         : Ephemeris_C_is_size[1] == 1 ? cos2PHI_k_size[1] :
         Ephemeris_C_is_size[1]) == 1 ? PHI_k_Dot_size[1] :
        (Ephemeris_C_is_size[1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_is_size[1])
        == 1 ? Ephemeris_C_ic_size[1] == 1 ? sin2PHI_k_size[1] :
        Ephemeris_C_ic_size[1] : Ephemeris_C_is_size[1] == 1 ? cos2PHI_k_size[1]
        : Ephemeris_C_is_size[1]) == Ephemeris_IDOT_size[1])) {
    loop_ub = Ephemeris_C_is_size[1] - 1;
    cos2PHI_k_size[0] = 1;
    cos2PHI_k_size[1] = Ephemeris_C_is_size[1];
    scalarLB = (Ephemeris_C_is_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&sin2PHI_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&PHI_k_Dot_data[t_k_data_tmp]);
      _mm_storeu_pd(&cos2PHI_k_data[t_k_data_tmp], _mm_add_pd(_mm_mul_pd
        (_mm_mul_pd(_mm_sub_pd(_mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_C_is_data[t_k_data_tmp]), tmp_7), _mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_C_ic_data[t_k_data_tmp]), tmp_5)), _mm_set1_pd(2.0)), tmp_6),
        _mm_loadu_pd(&Ephemeris_IDOT_data[t_k_data_tmp])));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      cos2PHI_k_data[t_k_data_tmp] = (Ephemeris_C_is_data[t_k_data_tmp] *
        cos2PHI_k_data[t_k_data_tmp] - Ephemeris_C_ic_data[t_k_data_tmp] *
        sin2PHI_k_data[t_k_data_tmp]) * 2.0 * PHI_k_Dot_data[t_k_data_tmp] +
        Ephemeris_IDOT_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_ni(cos2PHI_k_data, cos2PHI_k_size,
      Ephemeris_C_is_data, Ephemeris_C_is_size, Ephemeris_C_ic_data,
      Ephemeris_C_ic_size, sin2PHI_k_data, sin2PHI_k_size, PHI_k_Dot_data,
      PHI_k_Dot_size, Ephemeris_IDOT_data, Ephemeris_IDOT_size);
  }

  if ((r_k_Dot_size[1] == cosinus_u_k_size[1]) && (r_k_size[1] ==
       cosinus_E_k_size[1]) && ((r_k_Dot_size[1] == 1 ? cosinus_u_k_size[1] :
        r_k_Dot_size[1]) == (r_k_size[1] == 1 ? cosinus_E_k_size[1] : r_k_size[1])))
  {
    loop_ub = r_k_Dot_size[1] - 1;
    cosinus_u_k_size[0] = 1;
    cosinus_u_k_size[1] = r_k_Dot_size[1];
    scalarLB = (r_k_Dot_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&r_k_Dot_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&cosinus_u_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&r_k_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&cosinus_E_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&cosinus_u_k_data[t_k_data_tmp], _mm_sub_pd(_mm_mul_pd(tmp_7,
        tmp_5), _mm_mul_pd(tmp_6, tmp_4)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      cosinus_u_k_data[t_k_data_tmp] = r_k_Dot_data[t_k_data_tmp] *
        cosinus_u_k_data[t_k_data_tmp] - r_k_data[t_k_data_tmp] *
        cosinus_E_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_j4(cosinus_u_k_data, cosinus_u_k_size,
      r_k_Dot_data, r_k_Dot_size, r_k_data, r_k_size, cosinus_E_k_data,
      cosinus_E_k_size);
  }

  if ((r_k_Dot_size[1] == PHI_k_size[1]) && (X_k_tmp_size[1] ==
       cosinus_E_k_size[1]) && ((r_k_Dot_size[1] == 1 ? PHI_k_size[1] :
        r_k_Dot_size[1]) == (X_k_tmp_size[1] == 1 ? cosinus_E_k_size[1] :
        X_k_tmp_size[1]))) {
    loop_ub = r_k_Dot_size[1] - 1;
    r_k_Dot_size[0] = 1;
    scalarLB = (r_k_Dot_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&r_k_Dot_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&PHI_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&X_k_tmp_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&cosinus_E_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&r_k_Dot_data[t_k_data_tmp], _mm_add_pd(_mm_mul_pd(tmp_7,
        tmp_5), _mm_mul_pd(tmp_6, tmp_4)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      r_k_Dot_data[t_k_data_tmp] = r_k_Dot_data[t_k_data_tmp] *
        PHI_k_data[t_k_data_tmp] + X_k_tmp_data[t_k_data_tmp] *
        cosinus_E_k_data[t_k_data_tmp];
    }
  } else {
    binary_expand_o_espyy15uognnqac(r_k_Dot_data, r_k_Dot_size, PHI_k_data,
      PHI_k_size, X_k_tmp_data, X_k_tmp_size, cosinus_E_k_data, cosinus_E_k_size);
  }

  sv_vel_size[0] = cosinus_u_k_size[1];
  sv_vel_size[1] = 3;
  loop_ub = cosinus_u_k_size[1] * 3;
  if (loop_ub - 1 >= 0) {
    std::memset(&sv_vel_data[0], 0, static_cast<uint32_T>(loop_ub) * sizeof
                (real_T));
  }

  if (r_k_Dot_size[1] == cosinus_i_k_size[1]) {
    loop_ub = r_k_Dot_size[1] - 1;
    cosinus_i_k_size[0] = 1;
    cosinus_i_k_size[1] = r_k_Dot_size[1];
    scalarLB = (r_k_Dot_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&r_k_Dot_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&cosinus_i_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&cosinus_i_k_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_5));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      cosinus_i_k_data[t_k_data_tmp] *= r_k_Dot_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProcessingSingle_times_d(cosinus_i_k_data, cosinus_i_k_size,
      r_k_Dot_data, r_k_Dot_size);
  }

  if ((cosinus_u_k_size[1] == t_k_size[1]) && (cosinus_i_k_size[1] ==
       sinus_lambda_k_size[1]) && ((cosinus_u_k_size[1] == 1 ? t_k_size[1] :
        cosinus_u_k_size[1]) == (cosinus_i_k_size[1] == 1 ? sinus_lambda_k_size
        [1] : cosinus_i_k_size[1])) && (d_size[1] == sinus_lambda_k_size[1]) &&
      ((d_size[1] == 1 ? sinus_lambda_k_size[1] : d_size[1]) == cos2PHI_k_size[1])
      && (((cosinus_u_k_size[1] == 1 ? t_k_size[1] : cosinus_u_k_size[1]) == 1 ?
           cosinus_i_k_size[1] == 1 ? sinus_lambda_k_size[1] : cosinus_i_k_size
           [1] : cosinus_u_k_size[1] == 1 ? t_k_size[1] : cosinus_u_k_size[1]) ==
          ((d_size[1] == 1 ? sinus_lambda_k_size[1] : d_size[1]) == 1 ?
           cos2PHI_k_size[1] : d_size[1] == 1 ? sinus_lambda_k_size[1] : d_size
           [1])) && (sv_pos_size[0] == Ephemeris_OMEGADOT_size[1]) &&
      ((((cosinus_u_k_size[1] == 1 ? t_k_size[1] : cosinus_u_k_size[1]) == 1 ?
         cosinus_i_k_size[1] == 1 ? sinus_lambda_k_size[1] : cosinus_i_k_size[1]
         : cosinus_u_k_size[1] == 1 ? t_k_size[1] : cosinus_u_k_size[1]) == 1 ?
        (d_size[1] == 1 ? sinus_lambda_k_size[1] : d_size[1]) == 1 ?
        cos2PHI_k_size[1] : d_size[1] == 1 ? sinus_lambda_k_size[1] : d_size[1] :
        (cosinus_u_k_size[1] == 1 ? t_k_size[1] : cosinus_u_k_size[1]) == 1 ?
        cosinus_i_k_size[1] == 1 ? sinus_lambda_k_size[1] : cosinus_i_k_size[1] :
        cosinus_u_k_size[1] == 1 ? t_k_size[1] : cosinus_u_k_size[1]) ==
       (sv_pos_size[0] == 1 ? Ephemeris_OMEGADOT_size[1] : sv_pos_size[0]))) {
    loop_ub = cosinus_u_k_size[1];
    scalarLB = (cosinus_u_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&cosinus_u_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&t_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&cosinus_i_k_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&sinus_lambda_k_data[t_k_data_tmp]);
      tmp_2 = _mm_loadu_pd(&d_data[t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      tmp_0 = _mm_loadu_pd(&sv_pos_data[t_k_data_tmp + sv_pos_size[0]]);
      tmp_1 = _mm_loadu_pd(&f_data[t_k_data_tmp]);
      _mm_storeu_pd(&sv_vel_data[t_k_data_tmp], _mm_sub_pd(_mm_add_pd(_mm_sub_pd
        (_mm_mul_pd(tmp_7, tmp_5), _mm_mul_pd(tmp_6, tmp_4)), _mm_mul_pd
        (_mm_mul_pd(tmp_2, tmp_4), tmp_3)), _mm_mul_pd(tmp_0, tmp_1)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      sinus_lambda_k = sinus_lambda_k_data[t_k_data_tmp];
      sv_vel_data[t_k_data_tmp] = ((cosinus_u_k_data[t_k_data_tmp] *
        t_k_data[t_k_data_tmp] - cosinus_i_k_data[t_k_data_tmp] * sinus_lambda_k)
        + d_data[t_k_data_tmp] * sinus_lambda_k * cos2PHI_k_data[t_k_data_tmp])
        - sv_pos_data[t_k_data_tmp + sv_pos_size[0]] * f_data[t_k_data_tmp];
    }
  } else {
    binary_expand_op_espyy15uognnqa(sv_vel_data, cosinus_u_k_data,
      cosinus_u_k_size, t_k_data, t_k_size, cosinus_i_k_data, cosinus_i_k_size,
      sinus_lambda_k_data, sinus_lambda_k_size, d_data, d_size, cos2PHI_k_data,
      cos2PHI_k_size, sv_pos_data, sv_pos_size, f_data, f_size);
  }

  if ((cosinus_u_k_size[1] == sinus_lambda_k_size[1]) && (cosinus_i_k_size[1] ==
       t_k_size[1]) && ((cosinus_u_k_size[1] == 1 ? sinus_lambda_k_size[1] :
                         cosinus_u_k_size[1]) == (cosinus_i_k_size[1] == 1 ?
        t_k_size[1] : cosinus_i_k_size[1])) && (d_size[1] == t_k_size[1]) &&
      ((d_size[1] == 1 ? t_k_size[1] : d_size[1]) == cos2PHI_k_size[1]) &&
      (((cosinus_u_k_size[1] == 1 ? sinus_lambda_k_size[1] : cosinus_u_k_size[1])
        == 1 ? cosinus_i_k_size[1] == 1 ? t_k_size[1] : cosinus_i_k_size[1] :
        cosinus_u_k_size[1] == 1 ? sinus_lambda_k_size[1] : cosinus_u_k_size[1])
       == ((d_size[1] == 1 ? t_k_size[1] : d_size[1]) == 1 ? cos2PHI_k_size[1] :
           d_size[1] == 1 ? t_k_size[1] : d_size[1])) && (sv_pos_size[0] ==
       Ephemeris_OMEGADOT_size[1]) && ((((cosinus_u_k_size[1] == 1 ?
          sinus_lambda_k_size[1] : cosinus_u_k_size[1]) == 1 ? cosinus_i_k_size
         [1] == 1 ? t_k_size[1] : cosinus_i_k_size[1] : cosinus_u_k_size[1] == 1
         ? sinus_lambda_k_size[1] : cosinus_u_k_size[1]) == 1 ? (d_size[1] == 1 ?
         t_k_size[1] : d_size[1]) == 1 ? cos2PHI_k_size[1] : d_size[1] == 1 ?
        t_k_size[1] : d_size[1] : (cosinus_u_k_size[1] == 1 ?
         sinus_lambda_k_size[1] : cosinus_u_k_size[1]) == 1 ? cosinus_i_k_size[1]
        == 1 ? t_k_size[1] : cosinus_i_k_size[1] : cosinus_u_k_size[1] == 1 ?
        sinus_lambda_k_size[1] : cosinus_u_k_size[1]) == (sv_pos_size[0] == 1 ?
        Ephemeris_OMEGADOT_size[1] : sv_pos_size[0]))) {
    loop_ub = sv_vel_size[0];
    scalarLB = (sv_vel_size[0] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&cosinus_u_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&sinus_lambda_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&cosinus_i_k_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&t_k_data[t_k_data_tmp]);
      tmp_2 = _mm_loadu_pd(&d_data[t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      tmp_0 = _mm_loadu_pd(&sv_pos_data[t_k_data_tmp]);
      tmp_1 = _mm_loadu_pd(&f_data[t_k_data_tmp]);
      _mm_storeu_pd(&sv_vel_data[t_k_data_tmp + sv_vel_size[0]], _mm_add_pd
                    (_mm_sub_pd(_mm_add_pd(_mm_mul_pd(tmp_7, tmp_5), _mm_mul_pd
        (tmp_6, tmp_4)), _mm_mul_pd(_mm_mul_pd(tmp_2, tmp_4), tmp_3)),
                     _mm_mul_pd(tmp_0, tmp_1)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      sinus_lambda_k = t_k_data[t_k_data_tmp];
      sv_vel_data[t_k_data_tmp + sv_vel_size[0]] =
        ((cosinus_u_k_data[t_k_data_tmp] * sinus_lambda_k_data[t_k_data_tmp] +
          cosinus_i_k_data[t_k_data_tmp] * sinus_lambda_k) - d_data[t_k_data_tmp]
         * sinus_lambda_k * cos2PHI_k_data[t_k_data_tmp]) +
        sv_pos_data[t_k_data_tmp] * f_data[t_k_data_tmp];
    }
  } else {
    binary_expand_op_espyy15uognnq(sv_vel_data, sv_vel_size, cosinus_u_k_data,
      cosinus_u_k_size, sinus_lambda_k_data, sinus_lambda_k_size,
      cosinus_i_k_data, cosinus_i_k_size, t_k_data, t_k_size, d_data, d_size,
      cos2PHI_k_data, cos2PHI_k_size, sv_pos_data, sv_pos_size, f_data, f_size);
  }

  if ((r_k_Dot_size[1] == i_k_size[1]) && (c_size[1] == cos2PHI_k_size[1]) &&
      ((r_k_Dot_size[1] == 1 ? i_k_size[1] : r_k_Dot_size[1]) == (c_size[1] == 1
        ? cos2PHI_k_size[1] : c_size[1]))) {
    loop_ub = sv_vel_size[0];
    scalarLB = (sv_vel_size[0] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&r_k_Dot_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&i_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&c_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&sv_vel_data[t_k_data_tmp + (sv_vel_size[0] << 1)],
                    _mm_add_pd(_mm_mul_pd(tmp_7, tmp_5), _mm_mul_pd(tmp_6, tmp_4)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      sv_vel_data[t_k_data_tmp + (sv_vel_size[0] << 1)] =
        r_k_Dot_data[t_k_data_tmp] * i_k_data[t_k_data_tmp] +
        c_data[t_k_data_tmp] * cos2PHI_k_data[t_k_data_tmp];
    }
  } else {
    G_binary_expand_op_espyy15uognn(sv_vel_data, sv_vel_size, r_k_Dot_data,
      r_k_Dot_size, i_k_data, i_k_size, c_data, c_size, cos2PHI_k_data,
      cos2PHI_k_size);
  }

  sinus_lambda_k = std::cos(user_position[0]);
  N = 6.3995936257584924E+6 / std::sqrt(sinus_lambda_k * sinus_lambda_k *
    0.0067394967422761756 + 1.0);
  sinus_lambda_k = (N + user_position[2]) * sinus_lambda_k * std::cos
    (user_position[1]);
  y_user = (N + user_position[2]) * std::cos(user_position[0]) * std::sin
    (user_position[1]);
  z_user = (0.99330562000985889 * N + user_position[2]) * std::sin
    (user_position[0]);
  scalarLB_tmp = (sv_pos_size[0] / 2) << 1;
  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&sv_pos_data[t_k_data_tmp]);
    tmp_7 = _mm_sub_pd(tmp_7, _mm_set1_pd(sinus_lambda_k));
    _mm_storeu_pd(&tmp_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&sv_pos_data[(sv_pos_size[0] << 1) + t_k_data_tmp]);
    tmp_7 = _mm_sub_pd(tmp_7, _mm_set1_pd(z_user));
    _mm_storeu_pd(&tmp_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  transport_angle_size = sv_pos_size[0];
  loop_ub = sv_pos_size[0];
  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&sv_pos_data[t_k_data_tmp]);
    tmp_7 = _mm_sub_pd(tmp_7, _mm_set1_pd(sinus_lambda_k));
    tmp_5 = _mm_loadu_pd(&sv_pos_data[t_k_data_tmp + sv_pos_size[0]]);
    tmp_5 = _mm_sub_pd(tmp_5, _mm_set1_pd(y_user));
    tmp_6 = _mm_loadu_pd(&sv_pos_data[(sv_pos_size[0] << 1) + t_k_data_tmp]);
    tmp_6 = _mm_sub_pd(tmp_6, _mm_set1_pd(z_user));
    _mm_storeu_pd(&t_k_data[t_k_data_tmp], _mm_add_pd(_mm_add_pd(_mm_mul_pd
      (tmp_7, tmp_7), _mm_mul_pd(tmp_5, tmp_5)), _mm_mul_pd(tmp_6, tmp_6)));
  }

  for (int32_T t_k_data_tmp{scalarLB_tmp}; t_k_data_tmp < loop_ub; t_k_data_tmp
       ++) {
    real_T varargin_1;
    real_T varargin_1_0;
    N = sv_pos_data[t_k_data_tmp] - sinus_lambda_k;
    varargin_1 = sv_pos_data[t_k_data_tmp + sv_pos_size[0]] - y_user;
    varargin_1_0 = sv_pos_data[(sv_pos_size[0] << 1) + t_k_data_tmp] - z_user;
    t_k_data[t_k_data_tmp] = (N * N + varargin_1 * varargin_1) + varargin_1_0 *
      varargin_1_0;
  }

  GNSSPreProcessingSingle_sqrt_ja(t_k_data, &transport_angle_size);
  scalarLB = (transport_angle_size / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&t_k_data[t_k_data_tmp]);
    _mm_storeu_pd(&t_k_data[t_k_data_tmp], _mm_mul_pd(_mm_div_pd(tmp_7,
      _mm_set1_pd(2.99792458E+8)), _mm_set1_pd(-7.2921151467E-5)));
  }

  for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < transport_angle_size;
       t_k_data_tmp++) {
    t_k_data[t_k_data_tmp] = t_k_data[t_k_data_tmp] / 2.99792458E+8 *
      -7.2921151467E-5;
  }

  scalarLB = sv_pos_size[0];
  if (sv_pos_size[0] - 1 >= 0) {
    sv_pos_tmp[6] = 0.0;
    sv_pos_tmp[7] = 0.0;
    sv_pos_tmp[2] = 0.0;
    sv_pos_tmp[5] = 0.0;
    sv_pos_tmp[8] = 1.0;
    tmp[6] = 0.0;
    tmp[7] = 0.0;
    tmp[2] = 0.0;
    tmp[5] = 0.0;
    tmp[8] = 1.0;
  }

  for (vectorUB = 0; vectorUB < scalarLB; vectorUB++) {
    sinus_lambda_k = t_k_data[vectorUB];
    y_user = std::sin(-sinus_lambda_k);
    N = std::cos(-sinus_lambda_k);
    sv_pos_tmp[0] = N;
    sv_pos_tmp[3] = y_user;
    sv_pos_tmp[1] = -y_user;
    sv_pos_tmp[4] = N;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= 0; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&sv_pos_tmp[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&sv_pos_tmp[t_k_data_tmp + 3]);
      tmp_6 = _mm_loadu_pd(&sv_pos_tmp[t_k_data_tmp + 6]);
      _mm_storeu_pd(&sv_pos_tmp_0[t_k_data_tmp], _mm_add_pd(_mm_mul_pd(tmp_6,
        _mm_set1_pd(sv_pos_data[vectorUB + (sv_pos_size[0] << 1)])), _mm_add_pd
        (_mm_mul_pd(tmp_5, _mm_set1_pd(sv_pos_data[vectorUB + sv_pos_size[0]])),
         _mm_add_pd(_mm_mul_pd(tmp_7, _mm_set1_pd(sv_pos_data[vectorUB])),
                    _mm_set1_pd(0.0)))));
    }

    for (int32_T t_k_data_tmp{2}; t_k_data_tmp < 3; t_k_data_tmp++) {
      sv_pos_tmp_0[t_k_data_tmp] = sv_pos_data[(sv_pos_size[0] << 1) + vectorUB]
        * sv_pos_tmp[t_k_data_tmp + 6] + (sv_pos_tmp[t_k_data_tmp + 3] *
        sv_pos_data[vectorUB + sv_pos_size[0]] + sv_pos_tmp[t_k_data_tmp] *
        sv_pos_data[vectorUB]);
    }

    tmp[0] = N;
    tmp[3] = y_user;
    tmp[1] = -std::sin(-sinus_lambda_k);
    tmp[4] = N;
    sv_pos_data[vectorUB] = sv_pos_tmp_0[0];
    sv_pos_data[vectorUB + sv_pos_size[0]] = sv_pos_tmp_0[1];
    sv_pos_data[vectorUB + (sv_pos_size[0] << 1)] = sv_pos_tmp_0[2];
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= 0; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&tmp[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&tmp[t_k_data_tmp + 3]);
      tmp_6 = _mm_loadu_pd(&tmp[t_k_data_tmp + 6]);
      _mm_storeu_pd(&sv_pos_tmp_0[t_k_data_tmp], _mm_add_pd(_mm_mul_pd(tmp_6,
        _mm_set1_pd(sv_vel_data[vectorUB + (sv_vel_size[0] << 1)])), _mm_add_pd
        (_mm_mul_pd(tmp_5, _mm_set1_pd(sv_vel_data[vectorUB + sv_vel_size[0]])),
         _mm_add_pd(_mm_mul_pd(tmp_7, _mm_set1_pd(sv_vel_data[vectorUB])),
                    _mm_set1_pd(0.0)))));
    }

    for (int32_T t_k_data_tmp{2}; t_k_data_tmp < 3; t_k_data_tmp++) {
      sv_pos_tmp_0[t_k_data_tmp] = sv_vel_data[(sv_vel_size[0] << 1) + vectorUB]
        * tmp[t_k_data_tmp + 6] + (tmp[t_k_data_tmp + 3] * sv_vel_data[vectorUB
        + sv_vel_size[0]] + tmp[t_k_data_tmp] * sv_vel_data[vectorUB]);
    }

    sv_vel_data[vectorUB] = sv_pos_tmp_0[0];
    sv_vel_data[vectorUB + sv_vel_size[0]] = sv_pos_tmp_0[1];
    sv_vel_data[vectorUB + (sv_vel_size[0] << 1)] = sv_pos_tmp_0[2];
  }
}

void GNSS_preprocessingModelClass::GNSSPreP_binary_expand_op_espyy(const
  gnssops_navigation_data *in1, const real_T in3_data[], const int32_T *in3_size,
  const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[],
  const int32_T in5_size[2], const real_T in6_data[], const int32_T in6_size[2],
  const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[],
  const int32_T in8_size[2], const real_T in9_data[], const int32_T in9_size[2],
  const real_T in10_data[], const int32_T in10_size[2], const real_T in11[3],
  real_T in12_data[], int32_T in12_size[2], real_T in13_data[], int32_T
  in13_size[2])
{
  real_T in1_data[37];
  real_T in1_data_0[37];
  real_T in1_data_1[37];
  real_T in1_data_2[37];
  real_T in1_data_3[37];
  real_T in1_data_4[37];
  real_T in1_data_5[37];
  real_T in1_data_6[37];
  real_T in1_data_7[37];
  real_T in1_data_8[37];
  real_T in1_data_9[37];
  real_T in9_data_0[37];
  int32_T in1_size[2];
  int32_T in1_size_0[2];
  int32_T in1_size_1[2];
  int32_T in1_size_2[2];
  int32_T in1_size_3[2];
  int32_T in1_size_4[2];
  int32_T in1_size_5[2];
  int32_T in1_size_6[2];
  int32_T in1_size_7[2];
  int32_T in1_size_8[2];
  int32_T in1_size_9[2];
  int32_T in9_size_0[2];
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1_size[0] = 1;
  in1_size[1] = *in3_size;
  loop_ub = *in3_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in1->C_rs[static_cast<int32_T>(in3_data[i]) - 1];
  }

  in1_size_0[0] = 1;
  in1_size_0[1] = *in3_size;
  loop_ub = *in3_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_0[i] = in1->C_uc[static_cast<int32_T>(in3_data[i]) - 1];
  }

  in1_size_1[0] = 1;
  in1_size_1[1] = *in3_size;
  loop_ub = *in3_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_1[i] = in1->C_us[static_cast<int32_T>(in3_data[i]) - 1];
  }

  in1_size_2[0] = 1;
  in1_size_2[1] = *in3_size;
  loop_ub = *in3_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_2[i] = in1->C_ic[static_cast<int32_T>(in3_data[i]) - 1];
  }

  in1_size_3[0] = 1;
  in1_size_3[1] = *in3_size;
  loop_ub = *in3_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_3[i] = in1->OMEGA_0[static_cast<int32_T>(in3_data[i]) - 1];
  }

  in1_size_4[0] = 1;
  in1_size_4[1] = *in3_size;
  loop_ub = *in3_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_4[i] = in1->C_is[static_cast<int32_T>(in3_data[i]) - 1];
  }

  in1_size_5[0] = 1;
  in1_size_5[1] = *in3_size;
  loop_ub = *in3_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_5[i] = in1->I_0[static_cast<int32_T>(in3_data[i]) - 1];
  }

  in1_size_6[0] = 1;
  in1_size_6[1] = *in3_size;
  loop_ub = *in3_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_6[i] = in1->C_rc[static_cast<int32_T>(in3_data[i]) - 1];
  }

  in1_size_7[0] = 1;
  in1_size_7[1] = *in3_size;
  loop_ub = *in3_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_7[i] = in1->omega[static_cast<int32_T>(in3_data[i]) - 1];
  }

  in1_size_8[0] = 1;
  in1_size_8[1] = *in3_size;
  loop_ub = *in3_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_8[i] = in1->OMEGADOT[static_cast<int32_T>(in3_data[i]) - 1];
  }

  in1_size_9[0] = 1;
  in1_size_9[1] = *in3_size;
  loop_ub = *in3_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_9[i] = in1->IDOT[static_cast<int32_T>(in3_data[i]) - 1];
  }

  in9_size_0[0] = 1;
  in9_size_0[1] = in10_size[1] == 1 ? in9_size[1] : in10_size[1];
  stride_0_1 = (in9_size[1] != 1);
  stride_1_1 = (in10_size[1] != 1);
  loop_ub = in10_size[1] == 1 ? in9_size[1] : in10_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in9_data_0[i] = in9_data[i * stride_0_1] - in10_data[i * stride_1_1];
  }

  Get_Kepler_Satellite_Position_j(in1_data, in1_size, in4_data, in4_size,
    in5_data, in5_size, in1_data_0, in1_size_0, in6_data, in6_size, in1_data_1,
    in1_size_1, in7_data, in7_size, in8_data, in8_size, in1_data_2, in1_size_2,
    in1_data_3, in1_size_3, in1_data_4, in1_size_4, in1_data_5, in1_size_5,
    in1_data_6, in1_size_6, in1_data_7, in1_size_7, in1_data_8, in1_size_8,
    in1_data_9, in1_size_9, in9_data_0, in9_size_0, in11, in12_data, in12_size,
    in13_data, in13_size);
}

void GNSS_preprocessingModelClass::GNSSPrePr_binary_expand_op_espy(real_T
  in1_data[], int32_T *in1_size, const real_T in2_data[], const int32_T
  in3_data[], const int32_T *in3_size, const real_T in4_data[], const int32_T
  *in4_size)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  *in1_size = *in4_size == 1 ? *in3_size : *in4_size;
  stride_0_0 = (*in3_size != 1);
  stride_1_0 = (*in4_size != 1);
  loop_ub = *in4_size == 1 ? *in3_size : *in4_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2_data[in3_data[i * stride_0_0] - 1] - in4_data[i *
      stride_1_0];
  }
}

void GNSS_preprocessingModelClass::GNSSPrePro_binary_expand_op_esp(real_T
  in1_data[], int32_T *in1_size, const real_T in2_data[], const int32_T
  in2_size[2])
{
  real_T in1_data_0[40];
  int32_T in1_size_idx_0;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in1_size_idx_0 = in2_size[1] == 1 ? *in1_size : in2_size[1];
  stride_0_0 = (*in1_size != 1);
  stride_1_0 = (in2_size[1] != 1);
  loop_ub = in2_size[1] == 1 ? *in1_size : in2_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_0[i] = in2_data[i * stride_1_0] * 2.99792458E+8 + in1_data[i *
      stride_0_0];
  }

  *in1_size = in1_size_idx_0;
  if (in1_size_idx_0 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in1_data_0[0], static_cast<uint32_T>
                (in1_size_idx_0) * sizeof(real_T));
  }
}

// System initialize for atomic system: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::CalculateDifferentialCor_j_Init
  (DW_CalculateDifferentialCor_o_T *localDW)
{
  localDW->delta_pr2.size = 0;
  localDW->PRNs.size = 0;
}

// Output and update for atomic system: '<S70>/Calculate Differential Corrections'
void GNSS_preprocessingModelClass::CalculateDifferentialCorrecti_l(const
  GNSS_Measurement *rtu_GalMeasurementB, const GNSS_Measurement_size
  *rtu_GalMeasurementB_DIMS1, const gnssops_navigation_data *rtu_gpsNavDataBusL1,
  const gnssops_navigation_data_size *rtu_gpsNavDataBusL1_DIMS1, const real_T
  rtu_userPosLlh[3], B_CalculateDifferentialCorr_g_T *localB,
  DW_CalculateDifferentialCor_o_T *localDW)
{
  real_T b_a_data[111];
  real_T real_delta_data[111];
  real_T b_data[40];
  real_T E_k_data[37];
  real_T E_k_old_data[37];
  real_T n_0_data[37];
  real_T navdata_DELTA_N_data[37];
  real_T navdata_E_data[37];
  real_T navdata_M_0_data[37];
  real_T navdata_SQRT_A_data[37];
  real_T navdata_T_oe_data[37];
  real_T real_range_data[37];
  real_T rtu_gpsNavDataBusL1_data[37];
  real_T rtu_gpsNavDataBusL1_data_0[37];
  real_T rtu_gpsNavDataBusL1_data_1[37];
  real_T rtu_gpsNavDataBusL1_data_2[37];
  real_T rtu_gpsNavDataBusL1_data_3[37];
  real_T rtu_gpsNavDataBusL1_data_4[37];
  real_T rtu_gpsNavDataBusL1_data_5[37];
  real_T t_d_data[37];
  real_T t_k_data[37];
  real_T t_sv_emission_data[37];
  int32_T iidx_data[40];
  int32_T iia_data[37];
  int32_T iib_data[37];
  int32_T E_k_old_size[2];
  int32_T E_k_size[2];
  int32_T n_0_size[2];
  int32_T navdata_DELTA_N_size[2];
  int32_T navdata_E_size[2];
  int32_T navdata_M_0_size[2];
  int32_T navdata_SQRT_A_size[2];
  int32_T navdata_T_oe_size[2];
  int32_T real_delta_size[2];
  int32_T rtu_gpsNavDataBusL1_size[2];
  int32_T rtu_gpsNavDataBusL1_size_0[2];
  int32_T rtu_gpsNavDataBusL1_size_1[2];
  int32_T rtu_gpsNavDataBusL1_size_2[2];
  int32_T rtu_gpsNavDataBusL1_size_3[2];
  int32_T rtu_gpsNavDataBusL1_size_4[2];
  int32_T rtu_gpsNavDataBusL1_size_5[2];
  int32_T t_d_size[2];
  int32_T t_k_size[2];
  int32_T t_k_size_0[2];
  int32_T t_sv_emission_size[2];
  int32_T t_sv_emission_size_0[2];
  int32_T iia_size;
  int32_T iib_size;
  int32_T iidx_size;
  int32_T vstride;
  uint16_T a_data[40];
  boolean_T t_k_data_0[37];
  if (!localDW->delta_pr2_not_empty) {
    localDW->delta_pr2.size = 40;
    std::memset(&localDW->delta_pr2.data[0], 0, 40U * sizeof(real_T));
    localDW->delta_pr2_not_empty = true;
    localDW->old_t = 0.0;
    localDW->PRNs.size = 1;
    localDW->PRNs.data[0] = 0U;
  }

  if ((rtu_GalMeasurementB->time_receive > localDW->old_t) ||
      (rtu_GalMeasurementB->time_receive - localDW->old_t < -100.0)) {
    __m128d tmp_0;
    __m128d tmp_1;
    real_T t_d;
    int32_T acoef;
    int32_T i;
    localDW->old_t = rtu_GalMeasurementB->time_receive;
    if (rtu_GalMeasurementB_DIMS1->PRN - 1 >= 0) {
      std::memcpy(&a_data[0], &rtu_GalMeasurementB->PRN[0], static_cast<uint32_T>
                  (rtu_GalMeasurementB_DIMS1->PRN) * sizeof(uint16_T));
    }

    GNSSPreProcessingSingle_sort_ni(a_data, &rtu_GalMeasurementB_DIMS1->PRN,
      iidx_data, &iidx_size);
    GNSSPreProcessingS_do_vectors_c(a_data, &rtu_GalMeasurementB_DIMS1->PRN,
      rtu_gpsNavDataBusL1->SVID, &rtu_gpsNavDataBusL1_DIMS1->SVID,
      localDW->PRNs.data, &localDW->PRNs.size, iia_data, &iia_size, iib_data,
      &iib_size);
    for (int32_T k{0}; k < iib_size; k++) {
      real_range_data[k] = iib_data[k];
    }

    navdata_DELTA_N_size[0] = 1;
    navdata_DELTA_N_size[1] = iib_size;
    for (int32_T k{0}; k < iib_size; k++) {
      navdata_DELTA_N_data[k] = rtu_gpsNavDataBusL1->DELTA_N[static_cast<int32_T>
        (real_range_data[k]) - 1];
    }

    navdata_M_0_size[0] = 1;
    navdata_M_0_size[1] = iib_size;
    for (int32_T k{0}; k < iib_size; k++) {
      navdata_M_0_data[k] = rtu_gpsNavDataBusL1->M_0[static_cast<int32_T>
        (real_range_data[k]) - 1];
    }

    navdata_E_size[0] = 1;
    navdata_E_size[1] = iib_size;
    for (int32_T k{0}; k < iib_size; k++) {
      navdata_E_data[k] = rtu_gpsNavDataBusL1->E[static_cast<int32_T>
        (real_range_data[k]) - 1];
    }

    navdata_SQRT_A_size[0] = 1;
    navdata_SQRT_A_size[1] = iib_size;
    for (int32_T k{0}; k < iib_size; k++) {
      navdata_SQRT_A_data[k] = rtu_gpsNavDataBusL1->SQRT_A[static_cast<int32_T>
        (real_range_data[k]) - 1];
    }

    navdata_T_oe_size[0] = 1;
    navdata_T_oe_size[1] = iib_size;
    for (int32_T k{0}; k < iib_size; k++) {
      navdata_T_oe_data[k] = rtu_gpsNavDataBusL1->T_oe[static_cast<int32_T>
        (real_range_data[k]) - 1];
    }

    for (int32_T k{0}; k < iidx_size; k++) {
      b_data[k] = rtu_GalMeasurementB->pseudorange[iidx_data[k] - 1];
    }

    t_sv_emission_size[0] = 1;
    t_sv_emission_size[1] = iia_size;
    for (int32_T k{0}; k < iia_size; k++) {
      t_sv_emission_data[k] = rtu_GalMeasurementB->time_receive -
        b_data[iia_data[k] - 1] / 2.99792458E+8;
    }

    if (iib_size == iia_size) {
      t_d_size[1] = iia_size;
      for (int32_T k{0}; k < iia_size; k++) {
        t_d_data[k] = t_sv_emission_data[k] - rtu_gpsNavDataBusL1->T_oc[
          static_cast<int32_T>(real_range_data[k]) - 1];
      }
    } else {
      GNSS_binary_expand_op_espyy15uo(t_d_data, t_d_size, t_sv_emission_data,
        t_sv_emission_size, rtu_gpsNavDataBusL1, real_range_data, &iib_size);
    }

    t_d_size[0] = 1;
    vstride = t_d_size[1] - 1;
    for (int32_T k{0}; k <= vstride; k++) {
      t_d = t_d_data[k];
      t_d_data[k] = (t_d - static_cast<real_T>(t_d > 302400.0) * 604800.0) +
        static_cast<real_T>(t_d < -302400.0) * 604800.0;
    }

    if (iia_size == iib_size) {
      t_k_size[0] = 1;
      t_k_size[1] = iia_size;
      iidx_size = (iia_size / 2) << 1;
      acoef = iidx_size - 2;
      for (int32_T k{0}; k <= acoef; k += 2) {
        tmp_0 = _mm_loadu_pd(&t_sv_emission_data[k]);
        tmp_1 = _mm_loadu_pd(&navdata_T_oe_data[k]);
        _mm_storeu_pd(&t_k_data[k], _mm_sub_pd(tmp_0, tmp_1));
      }

      for (int32_T k{iidx_size}; k < iia_size; k++) {
        t_k_data[k] = t_sv_emission_data[k] - navdata_T_oe_data[k];
      }
    } else {
      GNSSPreProcessingSingl_minus_d4(t_k_data, t_k_size, t_sv_emission_data,
        t_sv_emission_size, navdata_T_oe_data, navdata_T_oe_size);
    }

    n_0_size[0] = 1;
    n_0_size[1] = iib_size;
    for (int32_T k{0}; k < iib_size; k++) {
      t_d = navdata_SQRT_A_data[k];
      n_0_data[k] = 3.986005E+14 / rt_powd_snf(t_d * t_d, 3.0);
    }

    iidx_size = (iib_size / 2) << 1;
    acoef = iidx_size - 2;
    for (int32_T k{0}; k <= acoef; k += 2) {
      tmp_0 = _mm_loadu_pd(&n_0_data[k]);
      _mm_storeu_pd(&n_0_data[k], _mm_sqrt_pd(tmp_0));
    }

    for (int32_T k{iidx_size}; k < iib_size; k++) {
      n_0_data[k] = std::sqrt(n_0_data[k]);
    }

    if ((iib_size == t_k_size[1]) && ((iib_size == 1 ? t_k_size[1] : iib_size) ==
         iib_size)) {
      vstride = iib_size - 1;
      n_0_size[0] = 1;
      n_0_size[1] = iib_size;
      for (int32_T k{0}; k <= vstride; k++) {
        t_d = t_k_data[k];
        n_0_data[k] = ((t_d - static_cast<real_T>(t_d > 302400.0) * 604800.0) +
                       static_cast<real_T>(t_d < -302400.0) * 604800.0) *
          (n_0_data[k] + navdata_DELTA_N_data[k]) + navdata_M_0_data[k];
      }
    } else {
      GNSSP_binary_expand_op_espyy15u(n_0_data, n_0_size, navdata_M_0_data,
        navdata_M_0_size, navdata_DELTA_N_data, navdata_DELTA_N_size, t_k_data,
        t_k_size);
    }

    if ((iib_size == n_0_size[1]) && ((iib_size == 1 ? n_0_size[1] : iib_size) ==
         iib_size)) {
      E_k_size[0] = 1;
      E_k_size[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        t_d = navdata_E_data[k];
        E_k_data[k] = static_cast<real_T>(t_d > 0.8) * 3.1415926535897931 +
          static_cast<real_T>(t_d <= 0.8) * n_0_data[k];
      }
    } else {
      GNSSPr_binary_expand_op_espyy15(E_k_data, E_k_size, navdata_E_data,
        navdata_E_size, n_0_data, n_0_size);
    }

    i = 0;
    t_k_size[1] = E_k_size[1];
    vstride = E_k_size[1];
    for (int32_T k{0}; k < vstride; k++) {
      t_k_data[k] = 1.0;
    }

    int32_T exitg1;
    do {
      exitg1 = 0;
      t_k_size_0[0] = 1;
      t_k_size_0[1] = t_k_size[1];
      vstride = t_k_size[1];
      for (int32_T k{0}; k < vstride; k++) {
        t_k_data_0[k] = (t_k_data[k] > 1.0E-15);
      }

      if (GNSSPreProcessingSingleA_any_gy(t_k_data_0, t_k_size_0) && (i < 20)) {
        E_k_old_size[0] = 1;
        E_k_old_size[1] = E_k_size[1];
        vstride = E_k_size[1];
        if (vstride - 1 >= 0) {
          std::memcpy(&E_k_old_data[0], &E_k_data[0], static_cast<uint32_T>
                      (vstride) * sizeof(real_T));
        }

        iidx_size = E_k_size[1];
        for (int32_T k{0}; k < iidx_size; k++) {
          E_k_data[k] = std::sin(E_k_data[k]);
        }

        if ((navdata_E_size[1] == E_k_size[1]) && ((navdata_E_size[1] == 1 ?
              E_k_size[1] : navdata_E_size[1]) == n_0_size[1])) {
          vstride = n_0_size[1] - 1;
          E_k_size[0] = 1;
          E_k_size[1] = n_0_size[1];
          iidx_size = (n_0_size[1] / 2) << 1;
          acoef = iidx_size - 2;
          for (int32_T k{0}; k <= acoef; k += 2) {
            __m128d tmp;
            tmp_0 = _mm_loadu_pd(&navdata_E_data[k]);
            tmp_1 = _mm_loadu_pd(&E_k_data[k]);
            tmp = _mm_loadu_pd(&n_0_data[k]);
            _mm_storeu_pd(&E_k_data[k], _mm_add_pd(_mm_mul_pd(tmp_0, tmp_1), tmp));
          }

          for (int32_T k{iidx_size}; k <= vstride; k++) {
            E_k_data[k] = navdata_E_data[k] * E_k_data[k] + n_0_data[k];
          }
        } else {
          GNSSPreProc_binary_expand_op_es(E_k_data, E_k_size, n_0_data, n_0_size,
            navdata_E_data, navdata_E_size);
        }

        if (E_k_size[1] == E_k_old_size[1]) {
          vstride = E_k_size[1] - 1;
          E_k_old_size[1] = E_k_size[1];
          iidx_size = (E_k_size[1] / 2) << 1;
          acoef = iidx_size - 2;
          for (int32_T k{0}; k <= acoef; k += 2) {
            tmp_0 = _mm_loadu_pd(&E_k_data[k]);
            tmp_1 = _mm_loadu_pd(&E_k_old_data[k]);
            _mm_storeu_pd(&E_k_old_data[k], _mm_sub_pd(tmp_0, tmp_1));
          }

          for (int32_T k{iidx_size}; k <= vstride; k++) {
            E_k_old_data[k] = E_k_data[k] - E_k_old_data[k];
          }
        } else {
          GNSSPreProcessingSingle_minus_d(E_k_old_data, E_k_old_size, E_k_data,
            E_k_size);
        }

        t_k_size[1] = E_k_old_size[1];
        iidx_size = E_k_old_size[1];
        for (int32_T k{0}; k < iidx_size; k++) {
          t_k_data[k] = std::abs(E_k_old_data[k]);
        }

        i++;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    iidx_size = E_k_size[1];
    for (int32_T k{0}; k < iidx_size; k++) {
      E_k_data[k] = std::sin(E_k_data[k]);
    }

    iidx_size = (t_d_size[1] / 2) << 1;
    acoef = iidx_size - 2;
    for (int32_T k{0}; k <= acoef; k += 2) {
      tmp_0 = _mm_loadu_pd(&t_d_data[k]);
      _mm_storeu_pd(&t_k_data[k], _mm_mul_pd(tmp_0, tmp_0));
    }

    acoef = iidx_size - 2;
    for (int32_T k{0}; k <= acoef; k += 2) {
      tmp_0 = _mm_loadu_pd(&t_d_data[k]);
      _mm_storeu_pd(&n_0_data[k], _mm_mul_pd(tmp_0, tmp_0));
    }

    acoef = iidx_size - 2;
    for (int32_T k{0}; k <= acoef; k += 2) {
      tmp_0 = _mm_loadu_pd(&t_d_data[k]);
      _mm_storeu_pd(&E_k_old_data[k], _mm_mul_pd(tmp_0, tmp_0));
    }

    if ((iib_size == t_d_size[1]) && ((iib_size == 1 ? t_d_size[1] : iib_size) ==
         iib_size) && (iib_size == t_d_size[1]) && ((iib_size == 1 ? iib_size ==
          1 ? t_d_size[1] : iib_size : iib_size) == (iib_size == 1 ? t_d_size[1]
          : iib_size)) && (iib_size == E_k_size[1]) && (((iib_size == 1 ?
           iib_size == 1 ? t_d_size[1] : iib_size : iib_size) == 1 ? iib_size ==
          1 ? t_d_size[1] : iib_size : iib_size == 1 ? iib_size == 1 ? t_d_size
          [1] : iib_size : iib_size) == (iib_size == 1 ? E_k_size[1] : iib_size)))
    {
      t_d_size[0] = 1;
      t_d_size[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        t_d = t_d_data[k];
        iidx_size = static_cast<int32_T>(real_range_data[k]) - 1;
        t_d_data[k] = ((rtu_gpsNavDataBusL1->A_f1[iidx_size] * t_d +
                        rtu_gpsNavDataBusL1->A_f0[iidx_size]) + t_d * t_d *
                       rtu_gpsNavDataBusL1->A_f2[iidx_size]) +
          -4.44280763339306E-10 * navdata_E_data[k] * navdata_SQRT_A_data[k] *
          E_k_data[k];
      }
    } else {
      GNSSPre_binary_expand_op_espyy1(t_d_data, t_d_size, rtu_gpsNavDataBusL1,
        real_range_data, &iib_size, navdata_E_data, navdata_E_size,
        navdata_SQRT_A_data, navdata_SQRT_A_size, E_k_data, E_k_size);
    }

    if (iia_size == t_d_size[1]) {
      E_k_size[0] = 1;
      E_k_size[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        E_k_data[k] = rtu_gpsNavDataBusL1->C_rs[static_cast<int32_T>
          (real_range_data[k]) - 1];
      }

      t_k_size[0] = 1;
      t_k_size[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        t_k_data[k] = rtu_gpsNavDataBusL1->C_uc[static_cast<int32_T>
          (real_range_data[k]) - 1];
      }

      n_0_size[0] = 1;
      n_0_size[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        n_0_data[k] = rtu_gpsNavDataBusL1->C_us[static_cast<int32_T>
          (real_range_data[k]) - 1];
      }

      E_k_old_size[0] = 1;
      E_k_old_size[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        E_k_old_data[k] = rtu_gpsNavDataBusL1->C_ic[static_cast<int32_T>
          (real_range_data[k]) - 1];
      }

      rtu_gpsNavDataBusL1_size[0] = 1;
      rtu_gpsNavDataBusL1_size[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        rtu_gpsNavDataBusL1_data[k] = rtu_gpsNavDataBusL1->OMEGA_0[static_cast<
          int32_T>(real_range_data[k]) - 1];
      }

      rtu_gpsNavDataBusL1_size_0[0] = 1;
      rtu_gpsNavDataBusL1_size_0[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        rtu_gpsNavDataBusL1_data_0[k] = rtu_gpsNavDataBusL1->C_is
          [static_cast<int32_T>(real_range_data[k]) - 1];
      }

      rtu_gpsNavDataBusL1_size_1[0] = 1;
      rtu_gpsNavDataBusL1_size_1[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        rtu_gpsNavDataBusL1_data_1[k] = rtu_gpsNavDataBusL1->I_0
          [static_cast<int32_T>(real_range_data[k]) - 1];
      }

      rtu_gpsNavDataBusL1_size_2[0] = 1;
      rtu_gpsNavDataBusL1_size_2[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        rtu_gpsNavDataBusL1_data_2[k] = rtu_gpsNavDataBusL1->C_rc
          [static_cast<int32_T>(real_range_data[k]) - 1];
      }

      rtu_gpsNavDataBusL1_size_3[0] = 1;
      rtu_gpsNavDataBusL1_size_3[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        rtu_gpsNavDataBusL1_data_3[k] = rtu_gpsNavDataBusL1->omega
          [static_cast<int32_T>(real_range_data[k]) - 1];
      }

      rtu_gpsNavDataBusL1_size_4[0] = 1;
      rtu_gpsNavDataBusL1_size_4[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        rtu_gpsNavDataBusL1_data_4[k] = rtu_gpsNavDataBusL1->OMEGADOT[
          static_cast<int32_T>(real_range_data[k]) - 1];
      }

      rtu_gpsNavDataBusL1_size_5[0] = 1;
      rtu_gpsNavDataBusL1_size_5[1] = iib_size;
      for (int32_T k{0}; k < iib_size; k++) {
        rtu_gpsNavDataBusL1_data_5[k] = rtu_gpsNavDataBusL1->IDOT
          [static_cast<int32_T>(real_range_data[k]) - 1];
      }

      t_sv_emission_size_0[0] = 1;
      t_sv_emission_size_0[1] = iia_size;
      iidx_size = (iia_size / 2) << 1;
      acoef = iidx_size - 2;
      for (int32_T k{0}; k <= acoef; k += 2) {
        tmp_0 = _mm_loadu_pd(&t_sv_emission_data[k]);
        tmp_1 = _mm_loadu_pd(&t_d_data[k]);
        _mm_storeu_pd(&real_range_data[k], _mm_sub_pd(tmp_0, tmp_1));
      }

      for (int32_T k{iidx_size}; k < iia_size; k++) {
        real_range_data[k] = t_sv_emission_data[k] - t_d_data[k];
      }

      Get_Kepler_Satellite_Position_j(E_k_data, E_k_size, navdata_DELTA_N_data,
        navdata_DELTA_N_size, navdata_M_0_data, navdata_M_0_size, t_k_data,
        t_k_size, navdata_E_data, navdata_E_size, n_0_data, n_0_size,
        navdata_SQRT_A_data, navdata_SQRT_A_size, navdata_T_oe_data,
        navdata_T_oe_size, E_k_old_data, E_k_old_size, rtu_gpsNavDataBusL1_data,
        rtu_gpsNavDataBusL1_size, rtu_gpsNavDataBusL1_data_0,
        rtu_gpsNavDataBusL1_size_0, rtu_gpsNavDataBusL1_data_1,
        rtu_gpsNavDataBusL1_size_1, rtu_gpsNavDataBusL1_data_2,
        rtu_gpsNavDataBusL1_size_2, rtu_gpsNavDataBusL1_data_3,
        rtu_gpsNavDataBusL1_size_3, rtu_gpsNavDataBusL1_data_4,
        rtu_gpsNavDataBusL1_size_4, rtu_gpsNavDataBusL1_data_5,
        rtu_gpsNavDataBusL1_size_5, real_range_data, t_sv_emission_size_0,
        rtu_userPosLlh, b_a_data, t_k_size_0, real_delta_data, real_delta_size);
    } else {
      GNSSPreP_binary_expand_op_espyy(rtu_gpsNavDataBusL1, real_range_data,
        &iib_size, navdata_DELTA_N_data, navdata_DELTA_N_size, navdata_M_0_data,
        navdata_M_0_size, navdata_E_data, navdata_E_size, navdata_SQRT_A_data,
        navdata_SQRT_A_size, navdata_T_oe_data, navdata_T_oe_size,
        t_sv_emission_data, t_sv_emission_size, t_d_data, t_d_size,
        rtu_userPosLlh, b_a_data, t_k_size_0, real_delta_data, real_delta_size);
    }

    real_delta_size[0] = static_cast<int8_T>(t_k_size_0[0]);
    if (static_cast<int8_T>(t_k_size_0[0]) != 0) {
      acoef = (t_k_size_0[0] != 1);
      for (int32_T k{0}; k < 3; k++) {
        i = real_delta_size[0] - 1;
        for (iidx_size = 0; iidx_size <= i; iidx_size++) {
          real_delta_data[iidx_size + real_delta_size[0] * k] = b_a_data[acoef *
            iidx_size + t_k_size_0[0] * k] - rtu_GalMeasurementB->
            base_position[k];
        }
      }
    }

    vstride = static_cast<int8_T>(t_k_size_0[0]) * 3;
    iidx_size = (vstride / 2) << 1;
    acoef = iidx_size - 2;
    for (int32_T k{0}; k <= acoef; k += 2) {
      tmp_0 = _mm_loadu_pd(&real_delta_data[k]);
      _mm_storeu_pd(&real_delta_data[k], _mm_mul_pd(tmp_0, tmp_0));
    }

    for (int32_T k{iidx_size}; k < vstride; k++) {
      t_d = real_delta_data[k];
      real_delta_data[k] = t_d * t_d;
    }

    if (static_cast<int8_T>(t_k_size_0[0]) == 0) {
      iib_size = 0;
    } else {
      vstride = static_cast<int8_T>(t_k_size_0[0]);
      iib_size = static_cast<int8_T>(t_k_size_0[0]);
      iidx_size = static_cast<int8_T>(t_k_size_0[0]);
      std::memcpy(&real_range_data[0], &real_delta_data[0], static_cast<uint32_T>
                  (iidx_size) * sizeof(real_T));
      for (int32_T k{0}; k < 2; k++) {
        int32_T xoffset;
        xoffset = (k + 1) * vstride;
        iidx_size = (vstride / 2) << 1;
        acoef = iidx_size - 2;
        for (i = 0; i <= acoef; i += 2) {
          tmp_0 = _mm_loadu_pd(&real_delta_data[xoffset + i]);
          tmp_1 = _mm_loadu_pd(&real_range_data[i]);
          _mm_storeu_pd(&real_range_data[i], _mm_add_pd(tmp_0, tmp_1));
        }

        for (i = iidx_size; i < vstride; i++) {
          real_range_data[i] += real_delta_data[xoffset + i];
        }
      }
    }

    iidx_size = (iib_size / 2) << 1;
    acoef = iidx_size - 2;
    for (int32_T k{0}; k <= acoef; k += 2) {
      tmp_0 = _mm_loadu_pd(&real_range_data[k]);
      _mm_storeu_pd(&real_range_data[k], _mm_sqrt_pd(tmp_0));
    }

    for (int32_T k{iidx_size}; k < iib_size; k++) {
      real_range_data[k] = std::sqrt(real_range_data[k]);
    }

    if (iia_size == iib_size) {
      localDW->delta_pr2.size = iia_size;
      for (int32_T k{0}; k < iia_size; k++) {
        localDW->delta_pr2.data[k] = b_data[iia_data[k] - 1] - real_range_data[k];
      }
    } else {
      GNSSPrePr_binary_expand_op_espy(localDW->delta_pr2.data,
        &localDW->delta_pr2.size, b_data, iia_data, &iia_size, real_range_data,
        &iib_size);
    }

    if (localDW->delta_pr2.size == t_d_size[1]) {
      vstride = localDW->delta_pr2.size;
      iidx_size = (localDW->delta_pr2.size / 2) << 1;
      acoef = iidx_size - 2;
      for (int32_T k{0}; k <= acoef; k += 2) {
        tmp_0 = _mm_loadu_pd(&t_d_data[k]);
        tmp_1 = _mm_loadu_pd(&localDW->delta_pr2.data[k]);
        _mm_storeu_pd(&localDW->delta_pr2.data[k], _mm_add_pd(_mm_mul_pd(tmp_0,
          _mm_set1_pd(2.99792458E+8)), tmp_1));
      }

      for (int32_T k{iidx_size}; k < vstride; k++) {
        localDW->delta_pr2.data[k] += t_d_data[k] * 2.99792458E+8;
      }
    } else {
      GNSSPrePro_binary_expand_op_esp(localDW->delta_pr2.data,
        &localDW->delta_pr2.size, t_d_data, t_d_size);
    }

    localDW->delta_pr2_not_empty = (localDW->delta_pr2.size != 0);
  }

  localDW->SFunction_DIMS3 = localDW->PRNs.size;
  vstride = localDW->PRNs.size;
  if (vstride - 1 >= 0) {
    std::memcpy(&localB->maskDiffCorr[0], &localDW->PRNs.data[0],
                static_cast<uint32_T>(vstride) * sizeof(uint16_T));
  }

  localDW->SFunction_DIMS2 = localDW->delta_pr2.size;
  vstride = localDW->delta_pr2.size;
  if (vstride - 1 >= 0) {
    std::memcpy(&localB->diffPseudorangeCorrection[0], &localDW->delta_pr2.data
                [0], static_cast<uint32_T>(vstride) * sizeof(real_T));
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
