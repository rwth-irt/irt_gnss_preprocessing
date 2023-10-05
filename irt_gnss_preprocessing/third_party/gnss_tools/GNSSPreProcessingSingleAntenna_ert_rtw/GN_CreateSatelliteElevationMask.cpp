//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GN_CreateSatelliteElevationMask.cpp
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
#include "rtwtypes.h"
#include "GN_CreateSatelliteElevationMask.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <cstring>
#include <cmath>
#include <emmintrin.h>
#include "GNSSPreProcessingSingleAntenna_private.h"

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_eu(real_T in1[3],
  const real_T in2[120], const int32_T in3[2], int32_T in4, const real_T in5[3])
{
  int32_T stride_0_1;
  stride_0_1 = (in3[1] != 1);
  in1[0] = in2[in4] - in5[0];
  in1[1] = in2[in3[0] * stride_0_1 + in4] - in5[1];
  in1[2] = in2[(stride_0_1 << 1) * in3[0] + in4] - in5[2];
}

void GNSS_preprocessingModelClass::GNSSPrePro_binary_expand_op_eui(boolean_T
  in1_data[], int32_T *in1_size, const real_T in2[40], int32_T in3, real_T in4,
  const int8_T in5[2])
{
  int32_T loop_ub;
  int32_T stride_0_0;
  *in1_size = in5[0] == 1 ? in3 : static_cast<int32_T>(in5[0]);
  stride_0_0 = (in3 != 1);
  loop_ub = in5[0] == 1 ? in3 : static_cast<int32_T>(in5[0]);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = (in2[i * stride_0_0] > in4);
  }
}

//
// Output and update for atomic system:
//    '<S54>/Create Satellite Elevation Mask'
//    '<S110>/Create Satellite Elevation Mask'
//
void GNSS_preprocessingModelClass::GN_CreateSatelliteElevationMask(const real_T
  rtu_userPosLlh[3], boolean_T rtu_userPos_isValid, const real_T rtu_satPosEcef
  [120], const int32_T rtu_satPosEcef_DIMS1[2], real_T rtu_elevationMaskingAngle,
  real_T *rty_removedSats, B_CreateSatelliteElevationMas_T *localB,
  DW_CreateSatelliteElevationMa_T *localDW)
{
  real_T e_unit_tmp[9];
  real_T e_unit[3];
  real_T line_of_sight[3];
  real_T n_unit[3];
  real_T u_unit[3];
  real_T user_Position_ecef[3];
  real_T N;
  real_T elevation_Angle_Limit;
  real_T scale;
  real_T t;
  real_T tmp;
  real_T u_unit_0;
  int32_T c;
  int32_T loop_ub;
  int32_T nz;
  int8_T b[2];
  boolean_T tmp_data[40];
  elevation_Angle_Limit = rtu_elevationMaskingAngle / 180.0 * 3.1415926535897931;
  localDW->SFunction_DIMS3 = rtu_satPosEcef_DIMS1[0];
  loop_ub = rtu_satPosEcef_DIMS1[0];
  if (loop_ub - 1 >= 0) {
    std::memset(&localB->elevationAngle[0], 0, static_cast<uint32_T>(loop_ub) *
                sizeof(real_T));
  }

  localDW->SFunction_DIMS4 = rtu_satPosEcef_DIMS1[0];
  loop_ub = rtu_satPosEcef_DIMS1[0];
  if (loop_ub - 1 >= 0) {
    std::memset(&localB->azimuthAngle[0], 0, static_cast<uint32_T>(loop_ub) *
                sizeof(real_T));
  }

  scale = std::cos(rtu_userPosLlh[0]);
  N = 6.3995936257584924E+6 / std::sqrt(scale * scale * 0.0067394967422761756 +
    1.0);
  t = std::cos(rtu_userPosLlh[1]);
  user_Position_ecef[0] = (N + rtu_userPosLlh[2]) * scale * t;
  u_unit_0 = std::sin(rtu_userPosLlh[1]);
  user_Position_ecef[1] = (N + rtu_userPosLlh[2]) * std::cos(rtu_userPosLlh[0]) *
    u_unit_0;
  tmp = std::sin(rtu_userPosLlh[0]);
  user_Position_ecef[2] = (0.99330562000985889 * N + rtu_userPosLlh[2]) * tmp;
  e_unit_tmp[0] = -u_unit_0;
  e_unit_tmp[1] = t;
  e_unit_tmp[2] = 0.0;
  e_unit_tmp[3] = -tmp * t;
  e_unit_tmp[4] = -std::sin(rtu_userPosLlh[0]) * u_unit_0;
  e_unit_tmp[5] = scale;
  e_unit_tmp[6] = scale * t;
  e_unit_tmp[7] = scale * u_unit_0;
  e_unit_tmp[8] = tmp;
  for (int32_T b_k{0}; b_k <= 0; b_k += 2) {
    __m128d tmp_0;
    __m128d tmp_1;
    __m128d tmp_2;
    __m128d tmp_3;
    __m128d tmp_4;
    __m128d tmp_5;
    __m128d tmp_6;
    tmp_0 = _mm_loadu_pd(&e_unit_tmp[b_k]);
    tmp_3 = _mm_set1_pd(0.0);
    tmp_4 = _mm_mul_pd(tmp_0, tmp_3);
    tmp_1 = _mm_loadu_pd(&e_unit_tmp[b_k + 3]);
    tmp_5 = _mm_mul_pd(tmp_1, tmp_3);
    tmp_2 = _mm_loadu_pd(&e_unit_tmp[b_k + 6]);
    tmp_6 = _mm_mul_pd(tmp_2, tmp_3);
    _mm_storeu_pd(&e_unit[b_k], _mm_add_pd(tmp_6, _mm_add_pd(tmp_5, _mm_add_pd
      (tmp_3, tmp_0))));
    tmp_0 = _mm_add_pd(tmp_4, tmp_3);
    _mm_storeu_pd(&n_unit[b_k], _mm_add_pd(tmp_6, _mm_add_pd(tmp_0, tmp_1)));
    _mm_storeu_pd(&u_unit[b_k], _mm_add_pd(_mm_add_pd(tmp_5, tmp_0), tmp_2));
  }

  for (int32_T b_k{2}; b_k < 3; b_k++) {
    scale = e_unit_tmp[b_k];
    N = scale;
    u_unit_0 = scale * 0.0;
    scale = e_unit_tmp[b_k + 3];
    N += scale * 0.0;
    t = u_unit_0 + scale;
    u_unit_0 += scale * 0.0;
    scale = e_unit_tmp[b_k + 6];
    e_unit[b_k] = scale * 0.0 + N;
    n_unit[b_k] = scale * 0.0 + t;
    u_unit[b_k] = u_unit_0 + scale;
  }

  c = rtu_satPosEcef_DIMS1[0];
  for (nz = 0; nz < c; nz++) {
    if (rtu_satPosEcef_DIMS1[1] == 3) {
      int32_T rtu_satPosEcef_DIMS1_idx_0;
      rtu_satPosEcef_DIMS1_idx_0 = rtu_satPosEcef_DIMS1[0];
      loop_ub = rtu_satPosEcef_DIMS1[1];
      for (int32_T b_k{0}; b_k < loop_ub; b_k++) {
        line_of_sight[b_k] = rtu_satPosEcef[rtu_satPosEcef_DIMS1_idx_0 * b_k +
          nz] - user_Position_ecef[b_k];
      }
    } else {
      GNSSPreProc_binary_expand_op_eu(line_of_sight, rtu_satPosEcef,
        rtu_satPosEcef_DIMS1, nz, user_Position_ecef);
    }

    scale = 3.3121686421112381E-170;
    N = std::abs(line_of_sight[0]);
    if (N > 3.3121686421112381E-170) {
      u_unit_0 = 1.0;
      scale = N;
    } else {
      t = N / 3.3121686421112381E-170;
      u_unit_0 = t * t;
    }

    N = std::abs(line_of_sight[1]);
    if (N > scale) {
      t = scale / N;
      u_unit_0 = u_unit_0 * t * t + 1.0;
      scale = N;
    } else {
      t = N / scale;
      u_unit_0 += t * t;
    }

    N = std::abs(line_of_sight[2]);
    if (N > scale) {
      t = scale / N;
      u_unit_0 = u_unit_0 * t * t + 1.0;
      scale = N;
    } else {
      t = N / scale;
      u_unit_0 += t * t;
    }

    u_unit_0 = scale * std::sqrt(u_unit_0);
    line_of_sight[0] /= u_unit_0;
    line_of_sight[1] /= u_unit_0;
    line_of_sight[2] /= u_unit_0;
    localB->elevationAngle[nz] = std::asin((line_of_sight[0] * u_unit[0] +
      line_of_sight[1] * u_unit[1]) + line_of_sight[2] * u_unit[2]);
    localB->azimuthAngle[nz] = rt_atan2d_snf((line_of_sight[0] * e_unit[0] +
      line_of_sight[1] * e_unit[1]) + line_of_sight[2] * e_unit[2],
      (line_of_sight[0] * n_unit[0] + line_of_sight[1] * n_unit[1]) +
      line_of_sight[2] * n_unit[2]);
  }

  b[0] = static_cast<int8_T>(localDW->SFunction_DIMS3);
  b[1] = 1;
  if (localDW->SFunction_DIMS3 == static_cast<int8_T>(localDW->SFunction_DIMS3))
  {
    nz = localDW->SFunction_DIMS3;
    for (int32_T b_k{0}; b_k < localDW->SFunction_DIMS3; b_k++) {
      tmp_data[b_k] = (localB->elevationAngle[b_k] > elevation_Angle_Limit);
    }
  } else {
    GNSSPrePro_binary_expand_op_eui(tmp_data, &nz, localB->elevationAngle,
      localDW->SFunction_DIMS3, elevation_Angle_Limit, b);
  }

  localDW->SFunction_DIMS2 = nz;
  if (nz - 1 >= 0) {
    std::memcpy(&localB->elevationMask[0], &tmp_data[0], static_cast<uint32_T>
                (nz) * sizeof(boolean_T));
  }

  if (!rtu_userPos_isValid) {
    localDW->SFunction_DIMS2 = rtu_satPosEcef_DIMS1[0];
    loop_ub = rtu_satPosEcef_DIMS1[0];
    for (int32_T b_k{0}; b_k < loop_ub; b_k++) {
      localB->elevationMask[b_k] = true;
    }
  }

  if (localDW->SFunction_DIMS2 == 0) {
    nz = 0;
  } else if (localDW->SFunction_DIMS2 == 0) {
    nz = 0;
  } else {
    nz = localB->elevationMask[0];
    for (int32_T b_k{2}; b_k <= localDW->SFunction_DIMS2; b_k++) {
      nz += localB->elevationMask[b_k - 1];
    }
  }

  *rty_removedSats = localDW->SFunction_DIMS2 - nz;
}

//
// File trailer for generated code.
//
// [EOF]
//
