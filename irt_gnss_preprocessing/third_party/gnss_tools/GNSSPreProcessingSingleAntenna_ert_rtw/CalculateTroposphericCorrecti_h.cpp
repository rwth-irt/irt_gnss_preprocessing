//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateTroposphericCorrecti_h.cpp
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
#include "CalculateTroposphericCorrecti_h.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <cstring>
#include <cmath>
#include <emmintrin.h>
#include "GNSSPreProcessingSingleAntenna_private.h"

// Function for MATLAB Function: '<S70>/Calculate Tropospheric Corrections'
real_T GNSS_preprocessingModelClass::GNSSPreProcessingSing_interp1_f(const
  real_T varargin_1[5], const real_T varargin_2[5], real_T varargin_3)
{
  real_T Vq;
  int32_T low_i;
  Vq = (rtNaN);
  low_i = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (low_i < 5) {
      if (std::isnan(varargin_1[low_i])) {
        exitg1 = 1;
      } else {
        low_i++;
      }
    } else {
      if (!std::isnan(varargin_3)) {
        real_T r;
        int32_T high_i;
        int32_T low_ip1;
        low_i = 1;
        low_ip1 = 2;
        high_i = 5;
        while (high_i > low_ip1) {
          int32_T mid_i;
          mid_i = (low_i + high_i) >> 1;
          if (varargin_3 >= varargin_1[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }

        r = varargin_1[low_i - 1];
        r = (varargin_3 - r) / (varargin_1[low_i] - r);
        if (r == 0.0) {
          Vq = varargin_2[low_i - 1];
        } else if (r == 1.0) {
          Vq = varargin_2[low_i];
        } else {
          Vq = varargin_2[low_i - 1];
          if (!(Vq == varargin_2[low_i])) {
            Vq = (1.0 - r) * Vq + r * varargin_2[low_i];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Vq;
}

// Function for MATLAB Function: '<S70>/Calculate Tropospheric Corrections'
void GNSS_preprocessingModelClass::GNSSPreProcessin_expand_power_g(const real_T
  a_data[], const int32_T *a_size, const real_T b_data[], const int32_T *b_size,
  real_T c_data[], int32_T *c_size)
{
  int8_T csz_idx_0;
  if (*b_size == 1) {
    csz_idx_0 = static_cast<int8_T>(*a_size);
  } else if (*a_size == 1) {
    csz_idx_0 = static_cast<int8_T>(*b_size);
  } else if (*a_size <= *b_size) {
    csz_idx_0 = static_cast<int8_T>(*a_size);
  } else {
    csz_idx_0 = static_cast<int8_T>(*b_size);
  }

  *c_size = csz_idx_0;
  if (csz_idx_0 != 0) {
    int32_T f;
    boolean_T d;
    boolean_T e;
    d = (*a_size != 1);
    e = (*b_size != 1);
    f = csz_idx_0 - 1;
    for (int32_T k{0}; k <= f; k++) {
      c_data[k] = rt_powd_snf(a_data[d * k], b_data[e * k]);
    }
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_fi(real_T
  in1_data[], int32_T *in1_size, const real_T in2[40], int32_T in3, const real_T
  in4_data[], const int32_T *in4_size, const real_T in5_data[], const int32_T
  *in5_size, const real_T in6_data[], const int32_T *in6_size, const real_T
  in7_data[], const int32_T *in7_size, const real_T in8_data[], const int32_T
  *in8_size, const real_T in9_data[], const int32_T *in9_size, const real_T
  in10[40], const int32_T *in11, const real_T in12_data[], const int32_T
  *in12_size)
{
  real_T in2_data[40];
  int32_T in2_size_idx_0;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_10_0;
  int32_T stride_11_0;
  int32_T stride_1_0;
  int32_T stride_2_0;
  int32_T stride_3_0;
  int32_T stride_4_0;
  int32_T stride_5_0;
  int32_T stride_6_0;
  int32_T stride_7_0;
  int32_T stride_8_0;
  int32_T stride_9_0;
  in2_size_idx_0 = ((*in11 == 1 ? *in11 == 1 ? *in12_size : *in11 : *in11) == 1 ?
                    *in11 == 1 ? *in9_size : *in11 : *in11 == 1 ? *in11 == 1 ?
                    *in12_size : *in11 : *in11) == 1 ? ((*in8_size == 1 ?
    *in7_size == 1 ? *in6_size == 1 ? *in5_size : *in6_size : *in7_size :
    *in8_size) == 1 ? *in4_size : *in8_size == 1 ? *in7_size == 1 ? *in6_size ==
    1 ? *in5_size : *in6_size : *in7_size : *in8_size) == 1 ? *in1_size == 1 ?
    in3 : *in1_size : (*in8_size == 1 ? *in7_size == 1 ? *in6_size == 1 ?
                       *in5_size : *in6_size : *in7_size : *in8_size) == 1 ?
    *in4_size : *in8_size == 1 ? *in7_size == 1 ? *in6_size == 1 ? *in5_size :
    *in6_size : *in7_size : *in8_size : (*in11 == 1 ? *in11 == 1 ? *in12_size : *
    in11 : *in11) == 1 ? *in11 == 1 ? *in9_size : *in11 : *in11 == 1 ? *in11 ==
    1 ? *in12_size : *in11 : *in11;
  stride_0_0 = (in3 != 1);
  stride_1_0 = (*in1_size != 1);
  stride_2_0 = (*in4_size != 1);
  stride_3_0 = (*in5_size != 1);
  stride_4_0 = (*in6_size != 1);
  stride_5_0 = (*in7_size != 1);
  stride_6_0 = (*in8_size != 1);
  stride_7_0 = (*in9_size != 1);
  stride_8_0 = (*in11 != 1);
  stride_9_0 = (*in12_size != 1);
  stride_10_0 = (*in11 != 1);
  stride_11_0 = (*in11 != 1);
  loop_ub = ((*in11 == 1 ? *in11 == 1 ? *in12_size : *in11 : *in11) == 1 ? *in11
             == 1 ? *in9_size : *in11 : *in11 == 1 ? *in11 == 1 ? *in12_size :
             *in11 : *in11) == 1 ? ((*in8_size == 1 ? *in7_size == 1 ? *in6_size
    == 1 ? *in5_size : *in6_size : *in7_size : *in8_size) == 1 ? *in4_size :
    *in8_size == 1 ? *in7_size == 1 ? *in6_size == 1 ? *in5_size : *in6_size :
    *in7_size : *in8_size) == 1 ? *in1_size == 1 ? in3 : *in1_size : (*in8_size ==
    1 ? *in7_size == 1 ? *in6_size == 1 ? *in5_size : *in6_size : *in7_size :
    *in8_size) == 1 ? *in4_size : *in8_size == 1 ? *in7_size == 1 ? *in6_size ==
    1 ? *in5_size : *in6_size : *in7_size : *in8_size : (*in11 == 1 ? *in11 == 1
    ? *in12_size : *in11 : *in11) == 1 ? *in11 == 1 ? *in9_size : *in11 : *in11 ==
    1 ? *in11 == 1 ? *in12_size : *in11 : *in11;
  for (int32_T i{0}; i < loop_ub; i++) {
    real_T in2_tmp;
    real_T varargout_1;
    varargout_1 = std::fmax(0.0, 4.0 - in10[i * stride_10_0] / 180.0 *
      3.1415926535897931);
    in2_tmp = in10[i * stride_11_0];
    in2_data[i] = (109.65462799999999 / ((in5_data[i * stride_3_0] + 1.0) *
      9.784 - in6_data[i * stride_4_0] * 287.054) * in7_data[i * stride_5_0] /
                   in8_data[i * stride_6_0] * in4_data[i * stride_2_0] +
                   in1_data[i * stride_1_0] * 0.022276538615999996 / 9.784 *
                   in2[i * stride_0_0]) * ((varargout_1 * varargout_1 * 0.015 +
      1.0) * (1.001 / in12_data[i * stride_9_0]) * static_cast<real_T>((in2_tmp >=
      0.034906585039886591) && (in2_tmp < 0.069813170079773182)) + 1.001 /
      in9_data[i * stride_7_0] * static_cast<real_T>(in10[i * stride_8_0] >=
      0.087266462599716474));
  }

  *in1_size = in2_size_idx_0;
  if (in2_size_idx_0 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in2_data[0], static_cast<uint32_T>(in2_size_idx_0)
                * sizeof(real_T));
  }
}

// Output and update for atomic system: '<S70>/Calculate Tropospheric Corrections'
void GNSS_preprocessingModelClass::CalculateTroposphericCorrecti_h(real_T
  rtu_dayOfYear, boolean_T rtu_enableTroposphericCorrectio, const real_T
  rtu_userPos_LLH[3], const real_T rtu_elevationAngle[40], const int32_T
  *rtu_elevationAngle_DIMS1, B_CalculateTroposphericCorr_h_T *localB,
  DW_CalculateTroposphericCor_c_T *localDW)
{
  static const real_T j[5]{ 1013.25, 1017.25, 1015.75, 1011.75, 1013.0 };

  static const real_T l[5]{ 0.0, -3.75, -2.25, -1.75, -0.5 };

  static const real_T m[5]{ 299.65, 294.15, 283.15, 272.15, 263.65 };

  static const real_T n[5]{ 0.0, 7.0, 11.0, 15.0, 14.5 };

  static const real_T o[5]{ 26.31, 21.79, 11.66, 6.78, 4.11 };

  static const real_T p[5]{ 0.0, 8.85, 7.24, 5.36, 3.39 };

  static const real_T q[5]{ 0.0063, 0.00605, 0.00558, 0.00539, 0.00453 };

  static const real_T r[5]{ 0.0, 0.00025, 0.00032, 0.00081, 0.00062 };

  static const real_T s[5]{ 2.77, 3.15, 2.57, 1.81, 1.55 };

  static const real_T t[5]{ 0.0, 0.33, 0.46, 0.74, 0.3 };

  real_T b_b_data[40];
  real_T beta_data[40];
  real_T d_data[40];
  real_T lambda_data[40];
  real_T pressure_data[40];
  real_T temperature_data[40];
  real_T water_vapour_pressure_data[40];
  real_T x_data[40];
  real_T x_tmp_data[40];
  real_T y_data[40];
  real_T tmp[5];
  real_T tmp_0[5];
  real_T tmp_1[2];
  real_T tmp_2[2];
  real_T tmp_3[2];
  real_T tmp_4[2];
  real_T tmp_5[2];
  real_T tmp_6[2];
  real_T tmp_7[2];
  real_T tmp_8[2];
  int32_T b_b_size;
  int32_T beta_size;
  int32_T lambda_size;
  int32_T loop_ub;
  int32_T pressure_size;
  int32_T temperature_size;
  int32_T water_vapour_pressure_size;
  int32_T x_tmp_size;
  if (rtu_enableTroposphericCorrectio) {
    __m128d tmp_a;
    __m128d tmp_b;
    real_T cosinus_day;
    real_T latitude;
    int32_T SFunction_DIMS2_tmp_tmp;
    int32_T k;
    int32_T vectorUB;
    pressure_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    if (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) - 1 >= 0) {
      std::memset(&pressure_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>
        (*rtu_elevationAngle_DIMS1)) * sizeof(real_T));
    }

    temperature_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    if (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) - 1 >= 0) {
      std::memset(&temperature_data[0], 0, static_cast<uint32_T>
                  (static_cast<int8_T>(*rtu_elevationAngle_DIMS1)) * sizeof
                  (real_T));
    }

    water_vapour_pressure_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    if (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) - 1 >= 0) {
      std::memset(&water_vapour_pressure_data[0], 0, static_cast<uint32_T>(
        static_cast<int8_T>(*rtu_elevationAngle_DIMS1)) * sizeof(real_T));
    }

    beta_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    if (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) - 1 >= 0) {
      std::memset(&beta_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>
        (*rtu_elevationAngle_DIMS1)) * sizeof(real_T));
    }

    lambda_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    if (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) - 1 >= 0) {
      std::memset(&lambda_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>(*
        rtu_elevationAngle_DIMS1)) * sizeof(real_T));
    }

    for (k = 0; k < *rtu_elevationAngle_DIMS1; k++) {
      x_data[k] = rtu_elevationAngle[k];
    }

    for (k = 0; k < *rtu_elevationAngle_DIMS1; k++) {
      x_data[k] = std::sin(x_data[k]);
    }

    loop_ub = *rtu_elevationAngle_DIMS1;
    SFunction_DIMS2_tmp_tmp = (*rtu_elevationAngle_DIMS1 / 2) << 1;
    vectorUB = SFunction_DIMS2_tmp_tmp - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_b = _mm_loadu_pd(&x_data[k]);
      _mm_storeu_pd(&y_data[k], _mm_add_pd(_mm_mul_pd(tmp_b, tmp_b), _mm_set1_pd
        (0.002001)));
    }

    for (k = SFunction_DIMS2_tmp_tmp; k < loop_ub; k++) {
      latitude = x_data[k];
      y_data[k] = latitude * latitude + 0.002001;
    }

    loop_ub = *rtu_elevationAngle_DIMS1;
    SFunction_DIMS2_tmp_tmp = (*rtu_elevationAngle_DIMS1 / 2) << 1;
    vectorUB = SFunction_DIMS2_tmp_tmp - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_b = _mm_loadu_pd(&y_data[k]);
      _mm_storeu_pd(&y_data[k], _mm_sqrt_pd(tmp_b));
    }

    for (k = SFunction_DIMS2_tmp_tmp; k < loop_ub; k++) {
      y_data[k] = std::sqrt(y_data[k]);
    }

    for (k = 0; k < *rtu_elevationAngle_DIMS1; k++) {
      x_data[k] = rtu_elevationAngle[k];
    }

    for (k = 0; k < *rtu_elevationAngle_DIMS1; k++) {
      x_data[k] = std::sin(x_data[k]);
    }

    loop_ub = *rtu_elevationAngle_DIMS1;
    SFunction_DIMS2_tmp_tmp = (*rtu_elevationAngle_DIMS1 / 2) << 1;
    vectorUB = SFunction_DIMS2_tmp_tmp - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_b = _mm_loadu_pd(&x_data[k]);
      _mm_storeu_pd(&x_data[k], _mm_add_pd(_mm_mul_pd(tmp_b, tmp_b), _mm_set1_pd
        (0.002001)));
    }

    for (k = SFunction_DIMS2_tmp_tmp; k < loop_ub; k++) {
      latitude = x_data[k];
      x_data[k] = latitude * latitude + 0.002001;
    }

    loop_ub = *rtu_elevationAngle_DIMS1;
    vectorUB = SFunction_DIMS2_tmp_tmp - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_b = _mm_loadu_pd(&x_data[k]);
      _mm_storeu_pd(&x_data[k], _mm_sqrt_pd(tmp_b));
    }

    for (k = SFunction_DIMS2_tmp_tmp; k < loop_ub; k++) {
      x_data[k] = std::sqrt(x_data[k]);
    }

    latitude = rtu_userPos_LLH[0] * 180.0 / 3.1415926535897931;
    if (latitude > 0.0) {
      k = 28;
    } else if (latitude < 0.0) {
      k = 211;
    } else {
      k = 0;
    }

    cosinus_day = std::cos((rtu_dayOfYear - static_cast<real_T>(k)) *
      6.2831853071795862 / 365.25);
    for (SFunction_DIMS2_tmp_tmp = 0; SFunction_DIMS2_tmp_tmp <
         *rtu_elevationAngle_DIMS1; SFunction_DIMS2_tmp_tmp++) {
      if (latitude < 15.0) {
        pressure_data[SFunction_DIMS2_tmp_tmp] = 1013.25 - 0.0 * cosinus_day;
        temperature_data[SFunction_DIMS2_tmp_tmp] = 299.65 - 0.0 * cosinus_day;
        water_vapour_pressure_data[SFunction_DIMS2_tmp_tmp] = 26.31 - 0.0 *
          cosinus_day;
        beta_data[SFunction_DIMS2_tmp_tmp] = 0.0063 - 0.0 * cosinus_day;
        lambda_data[SFunction_DIMS2_tmp_tmp] = 2.77 - 0.0 * cosinus_day;
      } else if (latitude > 75.0) {
        pressure_data[SFunction_DIMS2_tmp_tmp] = 1013.0 - -0.5 * cosinus_day;
        temperature_data[SFunction_DIMS2_tmp_tmp] = 263.65 - 14.5 * cosinus_day;
        water_vapour_pressure_data[SFunction_DIMS2_tmp_tmp] = 4.11 - 3.39 *
          cosinus_day;
        beta_data[SFunction_DIMS2_tmp_tmp] = 0.00453 - 0.00062 * cosinus_day;
        lambda_data[SFunction_DIMS2_tmp_tmp] = 1.55 - 0.3 * cosinus_day;
      } else {
        real_T tmp_c;
        for (k = 0; k < 5; k++) {
          tmp_c = 15.0 * static_cast<real_T>(k) + 15.0;
          tmp[k] = tmp_c;
          tmp_0[k] = tmp_c;
        }

        pressure_data[SFunction_DIMS2_tmp_tmp] = GNSSPreProcessingSing_interp1_f
          (tmp, j, latitude) - GNSSPreProcessingSing_interp1_f(tmp_0, l,
          latitude) * cosinus_day;
        for (k = 0; k < 5; k++) {
          tmp_c = 15.0 * static_cast<real_T>(k) + 15.0;
          tmp[k] = tmp_c;
          tmp_0[k] = tmp_c;
        }

        temperature_data[SFunction_DIMS2_tmp_tmp] =
          GNSSPreProcessingSing_interp1_f(tmp, m, latitude) -
          GNSSPreProcessingSing_interp1_f(tmp_0, n, latitude) * cosinus_day;
        for (k = 0; k < 5; k++) {
          tmp_c = 15.0 * static_cast<real_T>(k) + 15.0;
          tmp[k] = tmp_c;
          tmp_0[k] = tmp_c;
        }

        water_vapour_pressure_data[SFunction_DIMS2_tmp_tmp] =
          GNSSPreProcessingSing_interp1_f(tmp, o, latitude) -
          GNSSPreProcessingSing_interp1_f(tmp_0, p, latitude) * cosinus_day;
        for (k = 0; k < 5; k++) {
          tmp_c = 15.0 * static_cast<real_T>(k) + 15.0;
          tmp[k] = tmp_c;
          tmp_0[k] = tmp_c;
        }

        beta_data[SFunction_DIMS2_tmp_tmp] = GNSSPreProcessingSing_interp1_f(tmp,
          q, latitude) - GNSSPreProcessingSing_interp1_f(tmp_0, r, latitude) *
          cosinus_day;
        for (k = 0; k < 5; k++) {
          tmp_c = 15.0 * static_cast<real_T>(k) + 15.0;
          tmp[k] = tmp_c;
          tmp_0[k] = tmp_c;
        }

        lambda_data[SFunction_DIMS2_tmp_tmp] = GNSSPreProcessingSing_interp1_f
          (tmp, s, latitude) - GNSSPreProcessingSing_interp1_f(tmp_0, t,
          latitude) * cosinus_day;
      }
    }

    latitude = rtu_userPos_LLH[2];
    x_tmp_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    SFunction_DIMS2_tmp_tmp = (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) /
      2) << 1;
    vectorUB = SFunction_DIMS2_tmp_tmp - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_b = _mm_loadu_pd(&beta_data[k]);
      tmp_a = _mm_loadu_pd(&temperature_data[k]);
      _mm_storeu_pd(&x_tmp_data[k], _mm_sub_pd(_mm_set1_pd(1.0), _mm_div_pd
        (_mm_mul_pd(tmp_b, _mm_set1_pd(latitude)), tmp_a)));
    }

    for (k = SFunction_DIMS2_tmp_tmp; k < loop_ub; k++) {
      x_tmp_data[k] = 1.0 - beta_data[k] * latitude / temperature_data[k];
    }

    b_b_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    SFunction_DIMS2_tmp_tmp = (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) /
      2) << 1;
    vectorUB = SFunction_DIMS2_tmp_tmp - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d tmp_9;
      tmp_b = _mm_loadu_pd(&lambda_data[k]);
      tmp_a = _mm_set1_pd(1.0);
      tmp_9 = _mm_loadu_pd(&beta_data[k]);
      _mm_storeu_pd(&b_b_data[k], _mm_sub_pd(_mm_div_pd(_mm_div_pd(_mm_mul_pd
        (_mm_add_pd(tmp_b, tmp_a), _mm_set1_pd(9.80665)), _mm_set1_pd(287.054)),
        tmp_9), tmp_a));
    }

    for (k = SFunction_DIMS2_tmp_tmp; k < loop_ub; k++) {
      b_b_data[k] = (lambda_data[k] + 1.0) * 9.80665 / 287.054 / beta_data[k] -
        1.0;
    }

    if (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) == static_cast<int8_T>
        (*rtu_elevationAngle_DIMS1)) {
      for (k = 0; k < x_tmp_size; k++) {
        d_data[k] = rt_powd_snf(x_tmp_data[k], b_b_data[k]);
      }

      localDW->SFunction_DIMS2 = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
      if (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) - 1 >= 0) {
        std::memcpy(&localB->troposphericDelay[0], &d_data[0],
                    static_cast<uint32_T>(static_cast<int8_T>
          (*rtu_elevationAngle_DIMS1)) * sizeof(real_T));
      }
    } else {
      GNSSPreProcessin_expand_power_g(x_tmp_data, &x_tmp_size, b_b_data,
        &b_b_size, d_data, &loop_ub);
      localDW->SFunction_DIMS2 = loop_ub;
      if (loop_ub - 1 >= 0) {
        std::memcpy(&localB->troposphericDelay[0], &d_data[0],
                    static_cast<uint32_T>(loop_ub) * sizeof(real_T));
      }
    }

    b_b_size = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    SFunction_DIMS2_tmp_tmp = (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) /
      2) << 1;
    vectorUB = SFunction_DIMS2_tmp_tmp - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_b = _mm_loadu_pd(&beta_data[k]);
      _mm_storeu_pd(&b_b_data[k], _mm_div_pd(_mm_set1_pd(0.034163084297727957),
        tmp_b));
    }

    for (k = SFunction_DIMS2_tmp_tmp; k < loop_ub; k++) {
      b_b_data[k] = 0.034163084297727957 / beta_data[k];
    }

    if (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) == static_cast<int8_T>
        (*rtu_elevationAngle_DIMS1)) {
      loop_ub = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
      for (k = 0; k < x_tmp_size; k++) {
        d_data[k] = rt_powd_snf(x_tmp_data[k], b_b_data[k]);
      }
    } else {
      GNSSPreProcessin_expand_power_g(x_tmp_data, &x_tmp_size, b_b_data,
        &b_b_size, d_data, &loop_ub);
    }

    SFunction_DIMS2_tmp_tmp = (*rtu_elevationAngle_DIMS1 / 2) << 1;
    vectorUB = SFunction_DIMS2_tmp_tmp - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_b = _mm_loadu_pd(&rtu_elevationAngle[k]);
      _mm_storeu_pd(&tmp_8[0], _mm_sub_pd(_mm_set1_pd(4.0), _mm_mul_pd
        (_mm_div_pd(tmp_b, _mm_set1_pd(180.0)), _mm_set1_pd(3.1415926535897931))));
      tmp_7[0] = std::fmax(0.0, tmp_8[0]);
      tmp_7[1] = std::fmax(0.0, tmp_8[1]);
      tmp_b = _mm_loadu_pd(&tmp_7[0]);
      _mm_storeu_pd(&x_tmp_data[k], _mm_mul_pd(tmp_b, tmp_b));
    }

    vectorUB = SFunction_DIMS2_tmp_tmp - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_b = _mm_loadu_pd(&rtu_elevationAngle[k]);
      _mm_storeu_pd(&tmp_6[0], _mm_sub_pd(_mm_set1_pd(4.0), _mm_mul_pd
        (_mm_div_pd(tmp_b, _mm_set1_pd(180.0)), _mm_set1_pd(3.1415926535897931))));
      tmp_5[0] = std::fmax(0.0, tmp_6[0]);
      tmp_5[1] = std::fmax(0.0, tmp_6[1]);
      tmp_b = _mm_loadu_pd(&tmp_5[0]);
      _mm_storeu_pd(&b_b_data[k], _mm_mul_pd(tmp_b, tmp_b));
    }

    vectorUB = SFunction_DIMS2_tmp_tmp - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_b = _mm_loadu_pd(&rtu_elevationAngle[k]);
      _mm_storeu_pd(&tmp_4[0], _mm_sub_pd(_mm_set1_pd(4.0), _mm_mul_pd
        (_mm_div_pd(tmp_b, _mm_set1_pd(180.0)), _mm_set1_pd(3.1415926535897931))));
      tmp_3[0] = std::fmax(0.0, tmp_4[0]);
      tmp_3[1] = std::fmax(0.0, tmp_4[1]);
      tmp_b = _mm_loadu_pd(&tmp_3[0]);
      _mm_storeu_pd(&x_tmp_data[k], _mm_mul_pd(tmp_b, tmp_b));
    }

    vectorUB = SFunction_DIMS2_tmp_tmp - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_b = _mm_loadu_pd(&rtu_elevationAngle[k]);
      _mm_storeu_pd(&tmp_2[0], _mm_sub_pd(_mm_set1_pd(4.0), _mm_mul_pd
        (_mm_div_pd(tmp_b, _mm_set1_pd(180.0)), _mm_set1_pd(3.1415926535897931))));
      tmp_1[0] = std::fmax(0.0, tmp_2[0]);
      tmp_1[1] = std::fmax(0.0, tmp_2[1]);
      tmp_b = _mm_loadu_pd(&tmp_1[0]);
      _mm_storeu_pd(&x_tmp_data[k], _mm_mul_pd(tmp_b, tmp_b));
    }

    if ((localDW->SFunction_DIMS2 == static_cast<int8_T>
         (*rtu_elevationAngle_DIMS1)) && (static_cast<int8_T>
         (*rtu_elevationAngle_DIMS1) == loop_ub) && ((loop_ub == 1 ?
          static_cast<int32_T>(static_cast<int8_T>(*rtu_elevationAngle_DIMS1)) :
          loop_ub) == (localDW->SFunction_DIMS2 == 1 ? static_cast<int32_T>(
           static_cast<int8_T>(*rtu_elevationAngle_DIMS1)) :
                       localDW->SFunction_DIMS2)) && (((localDW->SFunction_DIMS2
           == 1 ? static_cast<int32_T>(static_cast<int8_T>
            (*rtu_elevationAngle_DIMS1)) : localDW->SFunction_DIMS2) == 1 ?
          loop_ub == 1 ? static_cast<int32_T>(static_cast<int8_T>
           (*rtu_elevationAngle_DIMS1)) : loop_ub : localDW->SFunction_DIMS2 ==
          1 ? static_cast<int32_T>(static_cast<int8_T>(*rtu_elevationAngle_DIMS1))
          : localDW->SFunction_DIMS2) == *rtu_elevationAngle_DIMS1)) {
      pressure_size = localDW->SFunction_DIMS2;
      for (k = 0; k < localDW->SFunction_DIMS2; k++) {
        latitude = std::fmax(0.0, 4.0 - rtu_elevationAngle[k] / 180.0 *
                             3.1415926535897931);
        pressure_data[k] = (109.65462799999999 / ((lambda_data[k] + 1.0) * 9.784
          - beta_data[k] * 287.054) * water_vapour_pressure_data[k] /
                            temperature_data[k] * d_data[k] +
                            0.022276538615999996 * pressure_data[k] / 9.784 *
                            localB->troposphericDelay[k]) * ((latitude *
          latitude * 0.015 + 1.0) * (1.001 / x_data[k]) * static_cast<real_T>
          ((rtu_elevationAngle[k] >= 0.034906585039886591) &&
           (rtu_elevationAngle[k] < 0.069813170079773182)) + 1.001 / y_data[k] *
          static_cast<real_T>(rtu_elevationAngle[k] >= 0.087266462599716474));
      }
    } else {
      GNSSPreProc_binary_expand_op_fi(pressure_data, &pressure_size,
        localB->troposphericDelay, localDW->SFunction_DIMS2, d_data, &loop_ub,
        lambda_data, &lambda_size, beta_data, &beta_size,
        water_vapour_pressure_data, &water_vapour_pressure_size,
        temperature_data, &temperature_size, y_data, rtu_elevationAngle_DIMS1,
        rtu_elevationAngle, rtu_elevationAngle_DIMS1, x_data,
        rtu_elevationAngle_DIMS1);
    }

    localDW->SFunction_DIMS2 = pressure_size;
    if (pressure_size - 1 >= 0) {
      std::memcpy(&localB->troposphericDelay[0], &pressure_data[0],
                  static_cast<uint32_T>(pressure_size) * sizeof(real_T));
    }
  } else {
    localDW->SFunction_DIMS2 = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    if (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) - 1 >= 0) {
      std::memset(&localB->troposphericDelay[0], 0, static_cast<uint32_T>(
        static_cast<int8_T>(*rtu_elevationAngle_DIMS1)) * sizeof(real_T));
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
