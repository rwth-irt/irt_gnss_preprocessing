//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateSatellitePositionandVe.cpp
//
// Code generated for Simulink model 'DDRTCM'.
//
// Model version                  : 3.3
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Fri Dec  9 14:23:41 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "rtwtypes.h"
#include "DDRTCM_types.h"
#include "DDRTCM.h"
#include <cstring>
#include <emmintrin.h>
#include <cmath>
#include "rt_defines.h"
#include "CalculateSatellitePositionandVe.h"

void DDRTCM::DDRTCM_minus_a(real_T in1_data[], int32_T in1_size[2], const real_T
  in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T
  in3_size[2])
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

// Function for MATLAB Function: '<S31>/Calculate Satellite Position and Velocity'
void DDRTCM::correct_Gps_Time_At_Week_Crosso(real_T b_time_data[], int32_T
  b_time_size[2])
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

real_T DDRTCM::DDRTCM_rt_powd_snf_i(real_T u0, real_T u1,
  B_CalculateSatellitePositiona_T *localB)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else {
    localB->d = std::abs(u0);
    localB->d1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (localB->d == 1.0) {
        y = 1.0;
      } else if (localB->d > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (localB->d1 == 0.0) {
      y = 1.0;
    } else if (localB->d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

void DDRTCM::DDRTCM_plus(real_T in1_data[], int32_T in1_size[2], const real_T
  in2_data[], const int32_T in2_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->in1_size_idx_1_ij = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
  localB->stride_0_1_bp = (in1_size[1] != 1);
  localB->stride_1_1_ch = (in2_size[1] != 1);
  localB->loop_ub_n = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
  for (localB->i15 = 0; localB->i15 < localB->loop_ub_n; localB->i15++) {
    localB->in1_data_b[localB->i15] = in1_data[localB->i15 *
      localB->stride_0_1_bp] + in2_data[localB->i15 * localB->stride_1_1_ch];
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in1_size_idx_1_ij;
  if (localB->in1_size_idx_1_ij - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in1_data_b[0], static_cast<uint32_T>
                (localB->in1_size_idx_1_ij) * sizeof(real_T));
  }
}

void DDRTCM::DDRTCM_binary_expand_op_p(real_T in1_data[], int32_T in1_size[2],
  const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
  const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
  B_CalculateSatellitePositiona_T *localB)
{
  in1_size[0] = 1;
  in1_size[1] = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ? in2_size[1]
    : in4_size[1] == 1 ? in3_size[1] : in4_size[1];
  localB->stride_0_1_kt = (in2_size[1] != 1);
  localB->stride_1_1_n = (in3_size[1] != 1);
  localB->stride_2_1_o = (in4_size[1] != 1);
  localB->loop_ub_gg = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ?
    in2_size[1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1];
  for (localB->i20 = 0; localB->i20 < localB->loop_ub_gg; localB->i20++) {
    in1_data[localB->i20] = in3_data[localB->i20 * localB->stride_1_1_n] *
      in4_data[localB->i20 * localB->stride_2_1_o] + in2_data[localB->i20 *
      localB->stride_0_1_kt];
  }
}

void DDRTCM::DDRTCM_binary_expand_op_jn(real_T in1_data[], int32_T in1_size[2],
  const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
  const int32_T in3_size[2], B_CalculateSatellitePositiona_T *localB)
{
  in1_size[0] = 1;
  in1_size[1] = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ? in2_size[1]
    : in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  localB->stride_0_1_fx = (in2_size[1] != 1);
  localB->stride_1_1_pm = (in2_size[1] != 1);
  localB->stride_2_1_p2 = (in3_size[1] != 1);
  localB->loop_ub_nj = (in3_size[1] == 1 ? in2_size[1] : in3_size[1]) == 1 ?
    in2_size[1] : in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  for (localB->i19 = 0; localB->i19 < localB->loop_ub_nj; localB->i19++) {
    in1_data[localB->i19] = static_cast<real_T>(in2_data[localB->i19 *
      localB->stride_0_1_fx] > 0.8) * 3.1415926535897931 + static_cast<real_T>
      (in2_data[localB->i19 * localB->stride_1_1_pm] <= 0.8) * in3_data
      [localB->i19 * localB->stride_2_1_p2];
  }
}

void DDRTCM::DDRTCM_binary_expand_op_k(real_T in1_data[], int32_T in1_size[2],
  const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
  const int32_T in3_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->in2_size_idx_1_h = (in1_size[1] == 1 ? in3_size[1] : in1_size[1]) == 1
    ? in2_size[1] : in1_size[1] == 1 ? in3_size[1] : in1_size[1];
  localB->stride_0_1_e = (in2_size[1] != 1);
  localB->stride_1_1_o4 = (in3_size[1] != 1);
  localB->stride_2_1_h = (in1_size[1] != 1);
  localB->loop_ub_l = (in1_size[1] == 1 ? in3_size[1] : in1_size[1]) == 1 ?
    in2_size[1] : in1_size[1] == 1 ? in3_size[1] : in1_size[1];
  for (localB->i7 = 0; localB->i7 < localB->loop_ub_l; localB->i7++) {
    localB->in2_data_b[localB->i7] = in2_data[localB->i7 * localB->stride_0_1_e]
      / (1.0 - in3_data[localB->i7 * localB->stride_1_1_o4] * in1_data
         [localB->i7 * localB->stride_2_1_h]);
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in2_size_idx_1_h;
  if (localB->in2_size_idx_1_h - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in2_data_b[0], static_cast<uint32_T>
                (localB->in2_size_idx_1_h) * sizeof(real_T));
  }
}

void DDRTCM::DDRTCM_binary_expand_op_lv(real_T in1_data[], int32_T in1_size[2],
  const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
  const int32_T in3_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->in2_size_idx_1 = (in1_size[1] == 1 ? in3_size[1] : in1_size[1]) == 1 ?
    in2_size[1] : in1_size[1] == 1 ? in3_size[1] : in1_size[1];
  localB->stride_0_1 = (in2_size[1] != 1);
  localB->stride_1_1 = (in3_size[1] != 1);
  localB->stride_2_1 = (in1_size[1] != 1);
  localB->loop_ub_o = (in1_size[1] == 1 ? in3_size[1] : in1_size[1]) == 1 ?
    in2_size[1] : in1_size[1] == 1 ? in3_size[1] : in1_size[1];
  for (localB->i1 = 0; localB->i1 < localB->loop_ub_o; localB->i1++) {
    localB->in2_data[localB->i1] = in3_data[localB->i1 * localB->stride_1_1] *
      in1_data[localB->i1 * localB->stride_2_1] + in2_data[localB->i1 *
      localB->stride_0_1];
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in2_size_idx_1;
  if (localB->in2_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in2_data[0], static_cast<uint32_T>
                (localB->in2_size_idx_1) * sizeof(real_T));
  }
}

void DDRTCM::DDRTCM_minus_ad(real_T in1_data[], int32_T in1_size[2], const
  real_T in2_data[], const int32_T in2_size[2], B_CalculateSatellitePositiona_T *
  localB)
{
  localB->in2_size_idx_1_c = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  localB->stride_0_1_me = (in2_size[1] != 1);
  localB->stride_1_1_m = (in1_size[1] != 1);
  localB->loop_ub_h = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  for (localB->i8 = 0; localB->i8 < localB->loop_ub_h; localB->i8++) {
    localB->in2_data_p[localB->i8] = in2_data[localB->i8 * localB->stride_0_1_me]
      - in1_data[localB->i8 * localB->stride_1_1_m];
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in2_size_idx_1_c;
  if (localB->in2_size_idx_1_c - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in2_data_p[0], static_cast<uint32_T>
                (localB->in2_size_idx_1_c) * sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S31>/Calculate Satellite Position and Velocity'
void DDRTCM::DD_Get_Kepler_Eccentric_Anomaly(const real_T t_k_data[], const
  int32_T t_k_size[2], const real_T Ephemeris_DELTA_N_data[], const int32_T
  Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[], const int32_T
  Ephemeris_M_0_size[2], const real_T Ephemeris_E_data[], const int32_T
  Ephemeris_E_size[2], const real_T Ephemeris_SQRT_A_data[], const int32_T
  Ephemeris_SQRT_A_size[2], real_T E_k_data[], int32_T E_k_size[2], real_T
  E_k_Dot_data[], int32_T E_k_Dot_size[2], B_CalculateSatellitePositiona_T
  *localB)
{
  __m128d tmp;
  __m128d tmp_0;
  localB->n_0_size[0] = 1;
  localB->n_0_size[1] = Ephemeris_SQRT_A_size[1];
  localB->loop_ub_i = Ephemeris_SQRT_A_size[1];
  for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp < localB->loop_ub_i;
       localB->varargin_1_tmp++) {
    localB->varargin_1_a = Ephemeris_SQRT_A_data[localB->varargin_1_tmp];
    localB->n_0_data[localB->varargin_1_tmp] = 3.986005E+14 /
      DDRTCM_rt_powd_snf_i(localB->varargin_1_a * localB->varargin_1_a, 3.0,
      localB);
  }

  localB->i_a = Ephemeris_SQRT_A_size[1];
  localB->scalarLB_l = (Ephemeris_SQRT_A_size[1] / 2) << 1;
  localB->vectorUB_o = localB->scalarLB_l - 2;
  for (localB->loop_ub_i = 0; localB->loop_ub_i <= localB->vectorUB_o;
       localB->loop_ub_i += 2) {
    tmp_0 = _mm_loadu_pd(&localB->n_0_data[localB->loop_ub_i]);
    _mm_storeu_pd(&localB->n_0_data[localB->loop_ub_i], _mm_sqrt_pd(tmp_0));
  }

  for (localB->loop_ub_i = localB->scalarLB_l; localB->loop_ub_i < localB->i_a;
       localB->loop_ub_i++) {
    localB->n_0_data[localB->loop_ub_i] = std::sqrt(localB->n_0_data
      [localB->loop_ub_i]);
  }

  if (Ephemeris_SQRT_A_size[1] == Ephemeris_DELTA_N_size[1]) {
    localB->loop_ub_i = Ephemeris_SQRT_A_size[1] - 1;
    localB->n_0_size[0] = 1;
    localB->scalarLB_l = (Ephemeris_SQRT_A_size[1] / 2) << 1;
    localB->vectorUB_o = localB->scalarLB_l - 2;
    for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp <=
         localB->vectorUB_o; localB->varargin_1_tmp += 2) {
      tmp_0 = _mm_loadu_pd(&localB->n_0_data[localB->varargin_1_tmp]);
      _mm_storeu_pd(&localB->n_0_data[localB->varargin_1_tmp], _mm_add_pd(tmp_0,
        _mm_loadu_pd(&Ephemeris_DELTA_N_data[localB->varargin_1_tmp])));
    }

    for (localB->varargin_1_tmp = localB->scalarLB_l; localB->varargin_1_tmp <=
         localB->loop_ub_i; localB->varargin_1_tmp++) {
      localB->n_0_data[localB->varargin_1_tmp] += Ephemeris_DELTA_N_data
        [localB->varargin_1_tmp];
    }
  } else {
    DDRTCM_plus(localB->n_0_data, localB->n_0_size, Ephemeris_DELTA_N_data,
                Ephemeris_DELTA_N_size, localB);
  }

  if ((localB->n_0_size[1] == t_k_size[1]) && ((localB->n_0_size[1] == 1 ?
        t_k_size[1] : localB->n_0_size[1]) == Ephemeris_M_0_size[1])) {
    localB->M_k_size[0] = 1;
    localB->M_k_size[1] = Ephemeris_M_0_size[1];
    localB->loop_ub_i = Ephemeris_M_0_size[1];
    localB->scalarLB_l = (Ephemeris_M_0_size[1] / 2) << 1;
    localB->vectorUB_o = localB->scalarLB_l - 2;
    for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp <=
         localB->vectorUB_o; localB->varargin_1_tmp += 2) {
      tmp_0 = _mm_loadu_pd(&localB->n_0_data[localB->varargin_1_tmp]);
      _mm_storeu_pd(&localB->M_k_data[localB->varargin_1_tmp], _mm_add_pd
                    (_mm_mul_pd(tmp_0, _mm_loadu_pd(&t_k_data
        [localB->varargin_1_tmp])), _mm_loadu_pd(&Ephemeris_M_0_data
        [localB->varargin_1_tmp])));
    }

    for (localB->varargin_1_tmp = localB->scalarLB_l; localB->varargin_1_tmp <
         localB->loop_ub_i; localB->varargin_1_tmp++) {
      localB->M_k_data[localB->varargin_1_tmp] = localB->n_0_data
        [localB->varargin_1_tmp] * t_k_data[localB->varargin_1_tmp] +
        Ephemeris_M_0_data[localB->varargin_1_tmp];
    }
  } else {
    DDRTCM_binary_expand_op_p(localB->M_k_data, localB->M_k_size,
      Ephemeris_M_0_data, Ephemeris_M_0_size, localB->n_0_data, localB->n_0_size,
      t_k_data, t_k_size, localB);
  }

  if ((Ephemeris_E_size[1] == localB->M_k_size[1]) && ((Ephemeris_E_size[1] == 1
        ? localB->M_k_size[1] : Ephemeris_E_size[1]) == Ephemeris_E_size[1])) {
    E_k_size[0] = 1;
    E_k_size[1] = Ephemeris_E_size[1];
    localB->loop_ub_i = Ephemeris_E_size[1];
    for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp < localB->loop_ub_i;
         localB->varargin_1_tmp++) {
      localB->varargin_1_a = Ephemeris_E_data[localB->varargin_1_tmp];
      E_k_data[localB->varargin_1_tmp] = static_cast<real_T>
        (localB->varargin_1_a > 0.8) * 3.1415926535897931 + static_cast<real_T>
        (localB->varargin_1_a <= 0.8) * localB->M_k_data[localB->varargin_1_tmp];
    }
  } else {
    DDRTCM_binary_expand_op_jn(E_k_data, E_k_size, Ephemeris_E_data,
      Ephemeris_E_size, localB->M_k_data, localB->M_k_size, localB);
  }

  localB->i_a = 0;
  localB->eps_size_idx_1 = E_k_size[1];
  localB->loop_ub_i = E_k_size[1];
  for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp < localB->loop_ub_i;
       localB->varargin_1_tmp++) {
    localB->eps_data[localB->varargin_1_tmp] = 1.0;
  }

  int32_T exitg1;
  do {
    boolean_T exitg2;
    exitg1 = 0;
    for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp <
         localB->eps_size_idx_1; localB->varargin_1_tmp++) {
      localB->x_data[localB->varargin_1_tmp] = (localB->eps_data
        [localB->varargin_1_tmp] > 1.0E-15);
    }

    localB->y = false;
    localB->scalarLB_l = 1;
    exitg2 = false;
    while ((!exitg2) && (localB->scalarLB_l <= localB->eps_size_idx_1)) {
      if (localB->x_data[localB->scalarLB_l - 1]) {
        localB->y = true;
        exitg2 = true;
      } else {
        localB->scalarLB_l++;
      }
    }

    if (localB->y && (localB->i_a < 20)) {
      localB->E_k_old_size[0] = 1;
      localB->E_k_old_size[1] = E_k_size[1];
      localB->loop_ub_i = E_k_size[1];
      if (localB->loop_ub_i - 1 >= 0) {
        std::memcpy(&localB->E_k_old_data[0], &E_k_data[0], static_cast<uint32_T>
                    (localB->loop_ub_i) * sizeof(real_T));
      }

      localB->scalarLB_l = E_k_size[1];
      for (localB->vectorUB_o = 0; localB->vectorUB_o < localB->scalarLB_l;
           localB->vectorUB_o++) {
        E_k_data[localB->vectorUB_o] = std::sin(E_k_data[localB->vectorUB_o]);
      }

      if ((Ephemeris_E_size[1] == E_k_size[1]) && ((Ephemeris_E_size[1] == 1 ?
            E_k_size[1] : Ephemeris_E_size[1]) == localB->M_k_size[1])) {
        localB->loop_ub_i = localB->M_k_size[1] - 1;
        E_k_size[0] = 1;
        E_k_size[1] = localB->M_k_size[1];
        localB->scalarLB_l = (localB->M_k_size[1] / 2) << 1;
        localB->vectorUB_o = localB->scalarLB_l - 2;
        for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp <=
             localB->vectorUB_o; localB->varargin_1_tmp += 2) {
          tmp_0 = _mm_loadu_pd(&E_k_data[localB->varargin_1_tmp]);
          tmp = _mm_loadu_pd(&localB->M_k_data[localB->varargin_1_tmp]);
          _mm_storeu_pd(&E_k_data[localB->varargin_1_tmp], _mm_add_pd(_mm_mul_pd
            (_mm_loadu_pd(&Ephemeris_E_data[localB->varargin_1_tmp]), tmp_0),
            tmp));
        }

        for (localB->varargin_1_tmp = localB->scalarLB_l; localB->varargin_1_tmp
             <= localB->loop_ub_i; localB->varargin_1_tmp++) {
          E_k_data[localB->varargin_1_tmp] = Ephemeris_E_data
            [localB->varargin_1_tmp] * E_k_data[localB->varargin_1_tmp] +
            localB->M_k_data[localB->varargin_1_tmp];
        }
      } else {
        DDRTCM_binary_expand_op_lv(E_k_data, E_k_size, localB->M_k_data,
          localB->M_k_size, Ephemeris_E_data, Ephemeris_E_size, localB);
      }

      if (E_k_size[1] == localB->E_k_old_size[1]) {
        localB->loop_ub_i = E_k_size[1] - 1;
        localB->E_k_old_size[1] = E_k_size[1];
        localB->scalarLB_l = (E_k_size[1] / 2) << 1;
        localB->vectorUB_o = localB->scalarLB_l - 2;
        for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp <=
             localB->vectorUB_o; localB->varargin_1_tmp += 2) {
          tmp_0 = _mm_loadu_pd(&E_k_data[localB->varargin_1_tmp]);
          tmp = _mm_loadu_pd(&localB->E_k_old_data[localB->varargin_1_tmp]);
          _mm_storeu_pd(&localB->E_k_old_data[localB->varargin_1_tmp],
                        _mm_sub_pd(tmp_0, tmp));
        }

        for (localB->varargin_1_tmp = localB->scalarLB_l; localB->varargin_1_tmp
             <= localB->loop_ub_i; localB->varargin_1_tmp++) {
          localB->E_k_old_data[localB->varargin_1_tmp] = E_k_data
            [localB->varargin_1_tmp] - localB->E_k_old_data
            [localB->varargin_1_tmp];
        }
      } else {
        DDRTCM_minus_ad(localB->E_k_old_data, localB->E_k_old_size, E_k_data,
                        E_k_size, localB);
      }

      localB->eps_size_idx_1 = localB->E_k_old_size[1];
      localB->scalarLB_l = localB->E_k_old_size[1];
      for (localB->vectorUB_o = 0; localB->vectorUB_o < localB->scalarLB_l;
           localB->vectorUB_o++) {
        localB->eps_data[localB->vectorUB_o] = std::abs(localB->
          E_k_old_data[localB->vectorUB_o]);
      }

      localB->i_a++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  E_k_Dot_size[0] = 1;
  E_k_Dot_size[1] = E_k_size[1];
  localB->loop_ub_i = E_k_size[1];
  if (localB->loop_ub_i - 1 >= 0) {
    std::memcpy(&E_k_Dot_data[0], &E_k_data[0], static_cast<uint32_T>
                (localB->loop_ub_i) * sizeof(real_T));
  }

  localB->i_a = E_k_size[1];
  for (localB->scalarLB_l = 0; localB->scalarLB_l < localB->i_a;
       localB->scalarLB_l++) {
    E_k_Dot_data[localB->scalarLB_l] = std::cos(E_k_Dot_data[localB->scalarLB_l]);
  }

  if ((Ephemeris_E_size[1] == E_k_size[1]) && ((Ephemeris_E_size[1] == 1 ?
        E_k_size[1] : Ephemeris_E_size[1]) == localB->n_0_size[1])) {
    localB->loop_ub_i = localB->n_0_size[1] - 1;
    E_k_Dot_size[0] = 1;
    E_k_Dot_size[1] = localB->n_0_size[1];
    localB->scalarLB_l = (localB->n_0_size[1] / 2) << 1;
    localB->vectorUB_o = localB->scalarLB_l - 2;
    for (localB->varargin_1_tmp = 0; localB->varargin_1_tmp <=
         localB->vectorUB_o; localB->varargin_1_tmp += 2) {
      tmp_0 = _mm_loadu_pd(&E_k_Dot_data[localB->varargin_1_tmp]);
      tmp = _mm_loadu_pd(&localB->n_0_data[localB->varargin_1_tmp]);
      _mm_storeu_pd(&E_k_Dot_data[localB->varargin_1_tmp], _mm_div_pd(tmp,
        _mm_sub_pd(_mm_set1_pd(1.0), _mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_E_data[localB->varargin_1_tmp]), tmp_0))));
    }

    for (localB->varargin_1_tmp = localB->scalarLB_l; localB->varargin_1_tmp <=
         localB->loop_ub_i; localB->varargin_1_tmp++) {
      E_k_Dot_data[localB->varargin_1_tmp] = localB->n_0_data
        [localB->varargin_1_tmp] / (1.0 - Ephemeris_E_data
        [localB->varargin_1_tmp] * E_k_Dot_data[localB->varargin_1_tmp]);
    }
  } else {
    DDRTCM_binary_expand_op_k(E_k_Dot_data, E_k_Dot_size, localB->n_0_data,
      localB->n_0_size, Ephemeris_E_data, Ephemeris_E_size, localB);
  }
}

// Function for MATLAB Function: '<S31>/Calculate Satellite Position and Velocity'
void DDRTCM::DDRTCM_cos(real_T x_data[], const int32_T x_size[2])
{
  int32_T b;
  b = x_size[1];
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::cos(x_data[k]);
  }
}

// Function for MATLAB Function: '<S31>/Calculate Satellite Position and Velocity'
void DDRTCM::DDRTCM_sin(real_T x_data[], const int32_T x_size[2])
{
  int32_T b;
  b = x_size[1];
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::sin(x_data[k]);
  }
}

void DDRTCM::DDRTCM_times_f(real_T in1_data[], int32_T in1_size[2], const real_T
  in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T
  in3_size[2])
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

// Function for MATLAB Function: '<S31>/Calculate Satellite Position and Velocity'
void DDRTCM::DDRTCM_sqrt(real_T x_data[], const int32_T x_size[2],
  B_CalculateSatellitePositiona_T *localB)
{
  localB->b_n = x_size[1];
  localB->scalarLB_c = (x_size[1] / 2) << 1;
  localB->vectorUB_b = localB->scalarLB_c - 2;
  for (localB->k_o = 0; localB->k_o <= localB->vectorUB_b; localB->k_o += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&x_data[localB->k_o]);
    _mm_storeu_pd(&x_data[localB->k_o], _mm_sqrt_pd(tmp));
  }

  for (localB->k_o = localB->scalarLB_c; localB->k_o < localB->b_n; localB->k_o
       ++) {
    x_data[localB->k_o] = std::sqrt(x_data[localB->k_o]);
  }
}

real_T DDRTCM::DDRTCM_rt_atan2d_snf_p(real_T u0, real_T u1,
  B_CalculateSatellitePositiona_T *localB)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else if (std::isinf(u0) && std::isinf(u1)) {
    if (u0 > 0.0) {
      localB->i3 = 1;
    } else {
      localB->i3 = -1;
    }

    if (u1 > 0.0) {
      localB->i4 = 1;
    } else {
      localB->i4 = -1;
    }

    y = std::atan2(static_cast<real_T>(localB->i3), static_cast<real_T>
                   (localB->i4));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

// Function for MATLAB Function: '<S31>/Calculate Satellite Position and Velocity'
void DDRTCM::DDRTCM_expand_atan2(const real_T a_data[], const int32_T a_size[2],
  const real_T b_data[], const int32_T b_size[2], real_T c_data[], int32_T
  c_size[2], B_CalculateSatellitePositiona_T *localB)
{
  if (b_size[1] == 1) {
    localB->csz_idx_1 = static_cast<int8_T>(a_size[1]);
  } else if (a_size[1] == 1) {
    localB->csz_idx_1 = static_cast<int8_T>(b_size[1]);
  } else if (a_size[1] <= b_size[1]) {
    localB->csz_idx_1 = static_cast<int8_T>(a_size[1]);
  } else {
    localB->csz_idx_1 = static_cast<int8_T>(b_size[1]);
  }

  c_size[0] = 1;
  c_size[1] = localB->csz_idx_1;
  if (localB->csz_idx_1 != 0) {
    localB->d_e = (a_size[1] != 1);
    localB->e = (b_size[1] != 1);
    localB->f = localB->csz_idx_1 - 1;
    for (localB->k = 0; localB->k <= localB->f; localB->k++) {
      c_data[localB->k] = DDRTCM_rt_atan2d_snf_p(a_data[localB->d_e * localB->k],
        b_data[localB->e * localB->k], localB);
    }
  }
}

// Function for MATLAB Function: '<S31>/Calculate Satellite Position and Velocity'
void DDRTCM::DDRTCM_atan2(const real_T y_data[], const int32_T y_size[2], const
  real_T x_data[], const int32_T x_size[2], real_T r_data[], int32_T r_size[2],
  B_CalculateSatellitePositiona_T *localB)
{
  if (y_size[1] == x_size[1]) {
    r_size[0] = 1;
    r_size[1] = y_size[1];
    localB->loop_ub_g = y_size[1];
    for (localB->r_data_tmp = 0; localB->r_data_tmp < localB->loop_ub_g;
         localB->r_data_tmp++) {
      r_data[localB->r_data_tmp] = DDRTCM_rt_atan2d_snf_p(y_data
        [localB->r_data_tmp], x_data[localB->r_data_tmp], localB);
    }
  } else {
    DDRTCM_expand_atan2(y_data, y_size, x_data, x_size, r_data, r_size, localB);
  }
}

void DDRTCM::DDRTCM_binary_expand_op_hn(real_T in1_data[], int32_T in1_size[2],
  const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
  const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
  const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
  const int32_T in6_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->in2_size_e[0] = 1;
  localB->in2_size_e[1] = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] :
    in3_size[1] : in4_size[1];
  localB->stride_0_1_c = (in2_size[1] != 1);
  localB->stride_1_1_o = (in3_size[1] != 1);
  localB->stride_2_1_l = (in4_size[1] != 1);
  localB->loop_ub_m = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] :
    in3_size[1] : in4_size[1];
  for (localB->i5 = 0; localB->i5 < localB->loop_ub_m; localB->i5++) {
    localB->in2_data_k[localB->i5] = in2_data[localB->i5 * localB->stride_0_1_c]
      * in3_data[localB->i5 * localB->stride_1_1_o] / in4_data[localB->i5 *
      localB->stride_2_1_l];
  }

  localB->in5_size[0] = 1;
  localB->in5_size[1] = in4_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] :
    in6_size[1] : in4_size[1];
  localB->stride_0_1_c = (in5_size[1] != 1);
  localB->stride_1_1_o = (in6_size[1] != 1);
  localB->stride_2_1_l = (in4_size[1] != 1);
  localB->loop_ub_m = in4_size[1] == 1 ? in6_size[1] == 1 ? in5_size[1] :
    in6_size[1] : in4_size[1];
  for (localB->i5 = 0; localB->i5 < localB->loop_ub_m; localB->i5++) {
    localB->in5_data[localB->i5] = (in5_data[localB->i5 * localB->stride_0_1_c]
      - in6_data[localB->i5 * localB->stride_1_1_o]) / in4_data[localB->i5 *
      localB->stride_2_1_l];
  }

  DDRTCM_atan2(localB->in2_data_k, localB->in2_size_e, localB->in5_data,
               localB->in5_size, in1_data, in1_size, localB);
}

void DDRTCM::DDRTCM_binary_expand_op_l(real_T in1_data[], int32_T in1_size[2],
  const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
  const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
  const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
  const int32_T in6_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->in2_size[0] = 1;
  localB->in2_size[1] = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] :
    in3_size[1] : in4_size[1];
  localB->stride_0_1_i = (in2_size[1] != 1);
  localB->stride_1_1_f = (in3_size[1] != 1);
  localB->stride_2_1_i = (in4_size[1] != 1);
  localB->loop_ub_f = in4_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] :
    in3_size[1] : in4_size[1];
  for (localB->i2 = 0; localB->i2 < localB->loop_ub_f; localB->i2++) {
    localB->in2_data_m[localB->i2] = in2_data[localB->i2 * localB->stride_0_1_i]
      * in3_data[localB->i2 * localB->stride_1_1_f] / in4_data[localB->i2 *
      localB->stride_2_1_i];
  }

  localB->in1_size[0] = 1;
  localB->in1_size[1] = in4_size[1] == 1 ? in5_size[1] == 1 ? in1_size[1] :
    in5_size[1] : in4_size[1];
  localB->stride_0_1_i = (in1_size[1] != 1);
  localB->stride_1_1_f = (in5_size[1] != 1);
  localB->stride_2_1_i = (in4_size[1] != 1);
  localB->loop_ub_f = in4_size[1] == 1 ? in5_size[1] == 1 ? in1_size[1] :
    in5_size[1] : in4_size[1];
  for (localB->i2 = 0; localB->i2 < localB->loop_ub_f; localB->i2++) {
    localB->in1_data[localB->i2] = (in1_data[localB->i2 * localB->stride_0_1_i]
      - in5_data[localB->i2 * localB->stride_1_1_f]) / in4_data[localB->i2 *
      localB->stride_2_1_i];
  }

  DDRTCM_atan2(localB->in2_data_m, localB->in2_size, localB->in1_data,
               localB->in1_size, localB->tmp_data_c, localB->tmp_size_a, localB);
  in1_size[0] = 1;
  in1_size[1] = in6_size[1] == 1 ? localB->tmp_size_a[1] : in6_size[1];
  localB->stride_0_1_i = (localB->tmp_size_a[1] != 1);
  localB->stride_1_1_f = (in6_size[1] != 1);
  localB->loop_ub_f = in6_size[1] == 1 ? localB->tmp_size_a[1] : in6_size[1];
  for (localB->i2 = 0; localB->i2 < localB->loop_ub_f; localB->i2++) {
    in1_data[localB->i2] = localB->tmp_data_c[localB->i2 * localB->stride_0_1_i]
      + in6_data[localB->i2 * localB->stride_1_1_f];
  }
}

void DDRTCM::DDRTCM_binary_expand_op_f(real_T in1_data[], int32_T in1_size[2],
  const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
  const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
  const real_T in5_data[], const int32_T in5_size[2],
  B_CalculateSatellitePositiona_T *localB)
{
  localB->in1_size_idx_1 = ((in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ?
    in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1]
    : in5_size[1]) == 1 ? in1_size[1] : (in5_size[1] == 1 ? in4_size[1] :
    in5_size[1]) == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size
    [1] == 1 ? in4_size[1] : in5_size[1];
  localB->stride_0_1_a = (in1_size[1] != 1);
  localB->stride_1_1_d = (in2_size[1] != 1);
  localB->stride_2_1_a = (in3_size[1] != 1);
  localB->stride_3_1_pb = (in4_size[1] != 1);
  localB->stride_4_1_m = (in5_size[1] != 1);
  localB->loop_ub_o3 = ((in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ?
                        in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size
                        [1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in1_size[1]
    : (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in3_size[1] == 1 ?
    in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1];
  for (localB->i11 = 0; localB->i11 < localB->loop_ub_o3; localB->i11++) {
    localB->in1_data_g[localB->i11] = (in2_data[localB->i11 *
      localB->stride_1_1_d] * in3_data[localB->i11 * localB->stride_2_1_a] +
      in4_data[localB->i11 * localB->stride_3_1_pb] * in5_data[localB->i11 *
      localB->stride_4_1_m]) + in1_data[localB->i11 * localB->stride_0_1_a];
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in1_size_idx_1;
  if (localB->in1_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in1_data_g[0], static_cast<uint32_T>
                (localB->in1_size_idx_1) * sizeof(real_T));
  }
}

void DDRTCM::DDRTCM_binary_expand_op_j(real_T in1_data[], int32_T in1_size[2],
  const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
  const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
  const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
  const int32_T in6_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->tmp_size_idx_1_o = ((in6_size[1] == 1 ? in5_size[1] : in6_size[1]) ==
    1 ? in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in6_size[1] == 1 ?
    in5_size[1] : in6_size[1]) == 1 ? in1_size[1] == 1 ? in2_size[1] : in1_size
    [1] : (in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ? in4_size[1] == 1
    ? in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1] : in6_size[1];
  localB->stride_0_1_k = (in2_size[1] != 1);
  localB->stride_1_1_p = (in1_size[1] != 1);
  localB->stride_2_1_p = (in3_size[1] != 1);
  localB->stride_3_1_p = (in4_size[1] != 1);
  localB->stride_4_1_a = (in5_size[1] != 1);
  localB->stride_5_1_j = (in6_size[1] != 1);
  localB->loop_ub_e = ((in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ?
                       in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in6_size[1]
                       == 1 ? in5_size[1] : in6_size[1]) == 1 ? in1_size[1] == 1
    ? in2_size[1] : in1_size[1] : (in6_size[1] == 1 ? in5_size[1] : in6_size[1])
    == 1 ? in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in6_size[1] == 1 ?
    in5_size[1] : in6_size[1];
  for (localB->i9 = 0; localB->i9 < localB->loop_ub_e; localB->i9++) {
    localB->varargin_1_jz = in2_data[localB->i9 * localB->stride_0_1_k];
    localB->tmp_data_cv[localB->i9] = (1.0 - in1_data[localB->i9 *
      localB->stride_1_1_p]) * (localB->varargin_1_jz * localB->varargin_1_jz) +
      (in3_data[localB->i9 * localB->stride_2_1_p] * in4_data[localB->i9 *
       localB->stride_3_1_p] + in5_data[localB->i9 * localB->stride_4_1_a] *
       in6_data[localB->i9 * localB->stride_5_1_j]);
  }

  in1_size[0] = 1;
  in1_size[1] = localB->tmp_size_idx_1_o;
  if (localB->tmp_size_idx_1_o - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->tmp_data_cv[0], static_cast<uint32_T>
                (localB->tmp_size_idx_1_o) * sizeof(real_T));
  }
}

void DDRTCM::DDRTCM_binary_expand_op_a(real_T in1_data[], int32_T in1_size[2],
  const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
  const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
  const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
  const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2],
  const real_T in8_data[], const int32_T in8_size[2],
  B_CalculateSatellitePositiona_T *localB)
{
  in1_size[0] = 1;
  in1_size[1] = (in8_size[1] == 1 ? in7_size[1] : in8_size[1]) == 1 ?
    ((in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ? in4_size[1] == 1 ?
     in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1] : in6_size[1]) ==
    1 ? in2_size[1] : (in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ?
    in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1]
    : in6_size[1] : in8_size[1] == 1 ? in7_size[1] : in8_size[1];
  localB->stride_0_1_c3 = (in2_size[1] != 1);
  localB->stride_1_1_cx = (in3_size[1] != 1);
  localB->stride_2_1_if = (in4_size[1] != 1);
  localB->stride_3_1_d = (in5_size[1] != 1);
  localB->stride_4_1_g = (in6_size[1] != 1);
  localB->stride_5_1_l = (in7_size[1] != 1);
  localB->stride_6_1_f = (in8_size[1] != 1);
  localB->loop_ub_d = (in8_size[1] == 1 ? in7_size[1] : in8_size[1]) == 1 ?
    ((in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ? in4_size[1] == 1 ?
     in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1] : in6_size[1]) ==
    1 ? in2_size[1] : (in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ?
    in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1]
    : in6_size[1] : in8_size[1] == 1 ? in7_size[1] : in8_size[1];
  for (localB->i23 = 0; localB->i23 < localB->loop_ub_d; localB->i23++) {
    in1_data[localB->i23] = ((in3_data[localB->i23 * localB->stride_1_1_cx] *
      in4_data[localB->i23 * localB->stride_2_1_if] + in5_data[localB->i23 *
      localB->stride_3_1_d] * in6_data[localB->i23 * localB->stride_4_1_g]) +
      in2_data[localB->i23 * localB->stride_0_1_c3]) + in7_data[localB->i23 *
      localB->stride_5_1_l] * in8_data[localB->i23 * localB->stride_6_1_f];
  }
}

void DDRTCM::binary_expand_o_hnvylqpxcvlyr4g(real_T in1_data[], int32_T
  in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
  in4_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->in2_size_idx_1_p = in4_size[1] == 1 ? (in1_size[1] == 1 ? in3_size[1] :
    in1_size[1]) == 1 ? in2_size[1] : in1_size[1] == 1 ? in3_size[1] : in1_size
    [1] : in4_size[1];
  localB->stride_0_1_f = (in2_size[1] != 1);
  localB->stride_1_1_h = (in3_size[1] != 1);
  localB->stride_2_1_m = (in1_size[1] != 1);
  localB->stride_3_1_a = (in4_size[1] != 1);
  localB->loop_ub_k = in4_size[1] == 1 ? (in1_size[1] == 1 ? in3_size[1] :
    in1_size[1]) == 1 ? in2_size[1] : in1_size[1] == 1 ? in3_size[1] : in1_size
    [1] : in4_size[1];
  for (localB->i14 = 0; localB->i14 < localB->loop_ub_k; localB->i14++) {
    localB->in2_data_n[localB->i14] = (in3_data[localB->i14 *
      localB->stride_1_1_h] * in1_data[localB->i14 * localB->stride_2_1_m] +
      in2_data[localB->i14 * localB->stride_0_1_f]) - in4_data[localB->i14 *
      localB->stride_3_1_a] * 7.2921151467E-5;
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in2_size_idx_1_p;
  if (localB->in2_size_idx_1_p - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in2_data_n[0], static_cast<uint32_T>
                (localB->in2_size_idx_1_p) * sizeof(real_T));
  }
}

void DDRTCM::DDRTCM_times_fc(real_T in1_data[], int32_T in1_size[2], const
  real_T in2_data[], const int32_T in2_size[2], B_CalculateSatellitePositiona_T *
  localB)
{
  localB->in1_size_idx_1_c = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
  localB->stride_0_1_nr = (in1_size[1] != 1);
  localB->stride_1_1_d3 = (in2_size[1] != 1);
  localB->loop_ub_na = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
  for (localB->i18 = 0; localB->i18 < localB->loop_ub_na; localB->i18++) {
    localB->in1_data_j[localB->i18] = in1_data[localB->i18 *
      localB->stride_0_1_nr] * in2_data[localB->i18 * localB->stride_1_1_d3];
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in1_size_idx_1_c;
  if (localB->in1_size_idx_1_c - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in1_data_j[0], static_cast<uint32_T>
                (localB->in1_size_idx_1_c) * sizeof(real_T));
  }
}

void DDRTCM::binary_expand_op_hnvylqpxcvlyr4(real_T in1_data[], const real_T
  in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T
  in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const real_T
  in5_data[], const int32_T in5_size[2])
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

void DDRTCM::binary_expand_op_hnvylqpxcvlyr(real_T in1_data[], const int32_T
  in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2])
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

void DDRTCM::D_binary_expand_op_hnvylqpxcvly(real_T in1_data[], int32_T
  in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->in2_size_idx_1_m = in1_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] :
    in3_size[1] : in1_size[1];
  localB->stride_0_1_my = (in2_size[1] != 1);
  localB->stride_1_1_j = (in3_size[1] != 1);
  localB->stride_2_1_e = (in1_size[1] != 1);
  localB->loop_ub_mv = in1_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] :
    in3_size[1] : in1_size[1];
  for (localB->i16 = 0; localB->i16 < localB->loop_ub_mv; localB->i16++) {
    localB->in2_data_pp[localB->i16] = in2_data[localB->i16 *
      localB->stride_0_1_my] * in3_data[localB->i16 * localB->stride_1_1_j] /
      in1_data[localB->i16 * localB->stride_2_1_e];
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in2_size_idx_1_m;
  if (localB->in2_size_idx_1_m - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in2_data_pp[0], static_cast<uint32_T>
                (localB->in2_size_idx_1_m) * sizeof(real_T));
  }
}

void DDRTCM::DD_binary_expand_op_hnvylqpxcvl(real_T in1_data[], int32_T
  in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T
  in6_data[], const int32_T in6_size[2])
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

void DDRTCM::DDR_binary_expand_op_hnvylqpxcv(real_T in1_data[], int32_T
  in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T
  in6_data[], const int32_T in6_size[2], const real_T in7_data[], const int32_T
  in7_size[2], const real_T in8_data[], const int32_T in8_size[2], const real_T
  in9_data[], const int32_T in9_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->tmp_size_idx_1 = (in9_size[1] == 1 ? in1_size[1] == 1 ? in8_size[1] ==
    1 ? in7_size[1] : in8_size[1] : in1_size[1] : in9_size[1]) == 1 ? in6_size[1]
    == 1 ? (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in3_size[1] ==
    1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1]
    : in6_size[1] : in9_size[1] == 1 ? in1_size[1] == 1 ? in8_size[1] == 1 ?
    in7_size[1] : in8_size[1] : in1_size[1] : in9_size[1];
  localB->stride_0_1_m = (in2_size[1] != 1);
  localB->stride_1_1_c = (in3_size[1] != 1);
  localB->stride_2_1_f = (in4_size[1] != 1);
  localB->stride_3_1 = (in5_size[1] != 1);
  localB->stride_4_1 = (in6_size[1] != 1);
  localB->stride_5_1 = (in7_size[1] != 1);
  localB->stride_6_1 = (in8_size[1] != 1);
  localB->stride_7_1 = (in1_size[1] != 1);
  localB->stride_8_1 = (in9_size[1] != 1);
  localB->loop_ub_p = (in9_size[1] == 1 ? in1_size[1] == 1 ? in8_size[1] == 1 ?
                       in7_size[1] : in8_size[1] : in1_size[1] : in9_size[1]) ==
    1 ? in6_size[1] == 1 ? (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ?
    in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1]
    : in5_size[1] : in6_size[1] : in9_size[1] == 1 ? in1_size[1] == 1 ?
    in8_size[1] == 1 ? in7_size[1] : in8_size[1] : in1_size[1] : in9_size[1];
  for (localB->i6 = 0; localB->i6 < localB->loop_ub_p; localB->i6++) {
    localB->varargin_1_j = in7_data[localB->i6 * localB->stride_5_1];
    localB->tmp_data_cx[localB->i6] = (in2_data[localB->i6 *
      localB->stride_0_1_m] * in3_data[localB->i6 * localB->stride_1_1_c] -
      in4_data[localB->i6 * localB->stride_2_1_f] * in5_data[localB->i6 *
      localB->stride_3_1]) * 2.0 * in6_data[localB->i6 * localB->stride_4_1] +
      localB->varargin_1_j * localB->varargin_1_j * in8_data[localB->i6 *
      localB->stride_6_1] * in1_data[localB->i6 * localB->stride_7_1] *
      in9_data[localB->i6 * localB->stride_8_1];
  }

  in1_size[0] = 1;
  in1_size[1] = localB->tmp_size_idx_1;
  if (localB->tmp_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->tmp_data_cx[0], static_cast<uint32_T>
                (localB->tmp_size_idx_1) * sizeof(real_T));
  }
}

void DDRTCM::DDRT_binary_expand_op_hnvylqpxc(real_T in1_data[], int32_T
  in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T
  in6_data[], const int32_T in6_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->tmp_size_idx_1_c = in6_size[1] == 1 ? in5_size[1] == 1 ? (in4_size[1] ==
    1 ? in3_size[1] : in4_size[1]) == 1 ? in1_size[1] == 1 ? in2_size[1] :
    in1_size[1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in5_size[1] :
    in6_size[1];
  localB->stride_0_1_b = (in2_size[1] != 1);
  localB->stride_1_1_a = (in1_size[1] != 1);
  localB->stride_2_1_g = (in3_size[1] != 1);
  localB->stride_3_1_e = (in4_size[1] != 1);
  localB->stride_4_1_f = (in5_size[1] != 1);
  localB->stride_5_1_h = (in6_size[1] != 1);
  localB->loop_ub_ei = in6_size[1] == 1 ? in5_size[1] == 1 ? (in4_size[1] == 1 ?
    in3_size[1] : in4_size[1]) == 1 ? in1_size[1] == 1 ? in2_size[1] : in1_size
    [1] : in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in5_size[1] : in6_size
    [1];
  for (localB->i10 = 0; localB->i10 < localB->loop_ub_ei; localB->i10++) {
    localB->tmp_data_f[localB->i10] = (in2_data[localB->i10 *
      localB->stride_0_1_b] * in1_data[localB->i10 * localB->stride_1_1_a] -
      in3_data[localB->i10 * localB->stride_2_1_g] * in4_data[localB->i10 *
      localB->stride_3_1_e]) * 2.0 * in5_data[localB->i10 * localB->stride_4_1_f]
      + in6_data[localB->i10 * localB->stride_5_1_h];
  }

  in1_size[0] = 1;
  in1_size[1] = localB->tmp_size_idx_1_c;
  if (localB->tmp_size_idx_1_c - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->tmp_data_f[0], static_cast<uint32_T>
                (localB->tmp_size_idx_1_c) * sizeof(real_T));
  }
}

void DDRTCM::DDRTC_binary_expand_op_hnvylqpx(real_T in1_data[], int32_T
  in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
  in4_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->in2_size_idx_1_cu = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) ==
    1 ? in1_size[1] == 1 ? in2_size[1] : in1_size[1] : in4_size[1] == 1 ?
    in3_size[1] : in4_size[1];
  localB->stride_0_1_o = (in2_size[1] != 1);
  localB->stride_1_1_k = (in1_size[1] != 1);
  localB->stride_2_1_ie = (in3_size[1] != 1);
  localB->stride_3_1_o = (in4_size[1] != 1);
  localB->loop_ub_m4 = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ?
    in1_size[1] == 1 ? in2_size[1] : in1_size[1] : in4_size[1] == 1 ? in3_size[1]
    : in4_size[1];
  for (localB->i13 = 0; localB->i13 < localB->loop_ub_m4; localB->i13++) {
    localB->in2_data_me[localB->i13] = in2_data[localB->i13 *
      localB->stride_0_1_o] * in1_data[localB->i13 * localB->stride_1_1_k] -
      in3_data[localB->i13 * localB->stride_2_1_ie] * in4_data[localB->i13 *
      localB->stride_3_1_o];
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in2_size_idx_1_cu;
  if (localB->in2_size_idx_1_cu - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in2_data_me[0], static_cast<uint32_T>
                (localB->in2_size_idx_1_cu) * sizeof(real_T));
  }
}

void DDRTCM::DDRTCM_binary_expand_op_hnvylqp(real_T in1_data[], int32_T
  in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
  in4_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->in1_size_idx_1_i = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1
    ? in2_size[1] == 1 ? in1_size[1] : in2_size[1] : in4_size[1] == 1 ?
    in3_size[1] : in4_size[1];
  localB->stride_0_1_n = (in1_size[1] != 1);
  localB->stride_1_1_l = (in2_size[1] != 1);
  localB->stride_2_1_pe = (in3_size[1] != 1);
  localB->stride_3_1_pt = (in4_size[1] != 1);
  localB->loop_ub_ft = (in4_size[1] == 1 ? in3_size[1] : in4_size[1]) == 1 ?
    in2_size[1] == 1 ? in1_size[1] : in2_size[1] : in4_size[1] == 1 ? in3_size[1]
    : in4_size[1];
  for (localB->i12 = 0; localB->i12 < localB->loop_ub_ft; localB->i12++) {
    localB->in1_data_g1[localB->i12] = in1_data[localB->i12 *
      localB->stride_0_1_n] * in2_data[localB->i12 * localB->stride_1_1_l] +
      in3_data[localB->i12 * localB->stride_2_1_pe] * in4_data[localB->i12 *
      localB->stride_3_1_pt];
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in1_size_idx_1_i;
  if (localB->in1_size_idx_1_i - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in1_data_g1[0], static_cast<uint32_T>
                (localB->in1_size_idx_1_i) * sizeof(real_T));
  }
}

void DDRTCM::DDRTCM_times(real_T in1_data[], int32_T in1_size[2], const real_T
  in2_data[], const int32_T in2_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->in2_size_idx_1_g = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  localB->stride_0_1_j = (in2_size[1] != 1);
  localB->stride_1_1_fo = (in1_size[1] != 1);
  localB->loop_ub_a5 = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  for (localB->i17 = 0; localB->i17 < localB->loop_ub_a5; localB->i17++) {
    localB->in2_data_l[localB->i17] = in2_data[localB->i17 *
      localB->stride_0_1_j] * in1_data[localB->i17 * localB->stride_1_1_fo];
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in2_size_idx_1_g;
  if (localB->in2_size_idx_1_g - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in2_data_l[0], static_cast<uint32_T>
                (localB->in2_size_idx_1_g) * sizeof(real_T));
  }
}

void DDRTCM::DDRTCM_binary_expand_op_hnvylq(real_T in1_data[], const real_T
  in2_data[], const int32_T in2_size[2], const real_T in3_data[], const int32_T
  in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const real_T
  in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
  in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T
  in8_data[], const int32_T in8_size[2], const real_T in9_data[], const int32_T
  in9_size[2], B_CalculateSatellitePositiona_T *localB)
{
  localB->in2_idx_0 = in2_size[1];
  localB->stride_0_0_c = (in2_size[1] != 1);
  localB->stride_1_0_c = (in3_size[1] != 1);
  localB->stride_2_0_m = (in4_size[1] != 1);
  localB->stride_3_0_j = (in5_size[1] != 1);
  localB->stride_4_0_k = (in6_size[1] != 1);
  localB->stride_5_0_m = (in5_size[1] != 1);
  localB->stride_6_0_p = (in7_size[1] != 1);
  localB->stride_7_0_d = (in8_size[0] != 1);
  localB->stride_8_0_g = (in9_size[1] != 1);
  for (localB->i22 = 0; localB->i22 < localB->in2_idx_0; localB->i22++) {
    in1_data[localB->i22] = ((in2_data[localB->i22 * localB->stride_0_0_c] *
      in3_data[localB->i22 * localB->stride_1_0_c] - in4_data[localB->i22 *
      localB->stride_2_0_m] * in5_data[localB->i22 * localB->stride_3_0_j]) +
      in6_data[localB->i22 * localB->stride_4_0_k] * in5_data[localB->i22 *
      localB->stride_5_0_m] * in7_data[localB->i22 * localB->stride_6_0_p]) -
      in8_data[localB->i22 * localB->stride_7_0_d + in8_size[0]] *
      in9_data[localB->i22 * localB->stride_8_0_g];
  }
}

void DDRTCM::DDRTCM_binary_expand_op_hnvyl(real_T in1_data[], const int32_T
  in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T
  in6_data[], const int32_T in6_size[2], const real_T in7_data[], const int32_T
  in7_size[2], const real_T in8_data[], const int32_T in8_size[2], const real_T
  in9_data[], const int32_T in9_size[2], B_CalculateSatellitePositiona_T *localB)
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
  for (localB->i21 = 0; localB->i21 < localB->in1_idx_0; localB->i21++) {
    in1_data[localB->i21 + in1_size[0]] = ((in2_data[localB->i21 *
      localB->stride_0_0] * in3_data[localB->i21 * localB->stride_1_0] +
      in4_data[localB->i21 * localB->stride_2_0] * in5_data[localB->i21 *
      localB->stride_3_0]) - in6_data[localB->i21 * localB->stride_4_0] *
      in5_data[localB->i21 * localB->stride_5_0] * in7_data[localB->i21 *
      localB->stride_6_0]) + in8_data[localB->i21 * localB->stride_7_0] *
      in9_data[localB->i21 * localB->stride_8_0];
  }
}

void DDRTCM::DDRTCM_binary_expand_op_hnvy(real_T in1_data[], const int32_T
  in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const real_T
  in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2])
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

// Function for MATLAB Function: '<S31>/Calculate Satellite Position and Velocity'
void DDRTCM::DDRTCM_sqrt_g(real_T x_data[], const int32_T *x_size,
  B_CalculateSatellitePositiona_T *localB)
{
  localB->b = *x_size;
  localB->scalarLB_i = (*x_size / 2) << 1;
  localB->vectorUB_h = localB->scalarLB_i - 2;
  for (localB->k_j = 0; localB->k_j <= localB->vectorUB_h; localB->k_j += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&x_data[localB->k_j]);
    _mm_storeu_pd(&x_data[localB->k_j], _mm_sqrt_pd(tmp));
  }

  for (localB->k_j = localB->scalarLB_i; localB->k_j < localB->b; localB->k_j++)
  {
    x_data[localB->k_j] = std::sqrt(x_data[localB->k_j]);
  }
}

// Function for MATLAB Function: '<S31>/Calculate Satellite Position and Velocity'
void DDRTCM::Get_Kepler_Satellite_Position_A(const real_T Ephemeris_C_rs_data[],
  const int32_T Ephemeris_C_rs_size[2], const real_T Ephemeris_DELTA_N_data[],
  const int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[],
  const int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_C_uc_data[], const
  int32_T Ephemeris_C_uc_size[2], const real_T Ephemeris_E_data[], const int32_T
  Ephemeris_E_size[2], const real_T Ephemeris_C_us_data[], const int32_T
  Ephemeris_C_us_size[2], const real_T Ephemeris_SQRT_A_data[], const int32_T
  Ephemeris_SQRT_A_size[2], const real_T Ephemeris_T_oe_data[], const int32_T
  Ephemeris_T_oe_size[2], const real_T Ephemeris_C_ic_data[], const int32_T
  Ephemeris_C_ic_size[2], const real_T Ephemeris_OMEGA_0_data[], const int32_T
  Ephemeris_OMEGA_0_size[2], const real_T Ephemeris_C_is_data[], const int32_T
  Ephemeris_C_is_size[2], const real_T Ephemeris_I_0_data[], const int32_T
  Ephemeris_I_0_size[2], const real_T Ephemeris_C_rc_data[], const int32_T
  Ephemeris_C_rc_size[2], const real_T Ephemeris_omega_data[], const int32_T
  Ephemeris_omega_size[2], const real_T Ephemeris_OMEGADOT_data[], const int32_T
  Ephemeris_OMEGADOT_size[2], const real_T Ephemeris_IDOT_data[], const int32_T
  Ephemeris_IDOT_size[2], const real_T T_emission_data[], const int32_T
  T_emission_size[2], const real_T user_position[3], real_T sv_pos_data[],
  int32_T sv_pos_size[2], real_T sv_vel_data[], int32_T sv_vel_size[2],
  B_CalculateSatellitePositiona_T *localB)
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_1;
  __m128d tmp_2;
  __m128d tmp_3;
  __m128d tmp_4;
  __m128d tmp_5;
  __m128d tmp_6;
  if (T_emission_size[1] == Ephemeris_T_oe_size[1]) {
    localB->t_k_size[0] = 1;
    localB->t_k_size[1] = T_emission_size[1];
    localB->loop_ub_a = T_emission_size[1];
    localB->scalarLB = (T_emission_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      _mm_storeu_pd(&localB->t_k_data[localB->t_k_data_tmp], _mm_sub_pd
                    (_mm_loadu_pd(&T_emission_data[localB->t_k_data_tmp]),
                     _mm_loadu_pd(&Ephemeris_T_oe_data[localB->t_k_data_tmp])));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->t_k_data[localB->t_k_data_tmp] = T_emission_data
        [localB->t_k_data_tmp] - Ephemeris_T_oe_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_minus_a(localB->t_k_data, localB->t_k_size, T_emission_data,
                   T_emission_size, Ephemeris_T_oe_data, Ephemeris_T_oe_size);
  }

  correct_Gps_Time_At_Week_Crosso(localB->t_k_data, localB->t_k_size);
  DD_Get_Kepler_Eccentric_Anomaly(localB->t_k_data, localB->t_k_size,
    Ephemeris_DELTA_N_data, Ephemeris_DELTA_N_size, Ephemeris_M_0_data,
    Ephemeris_M_0_size, Ephemeris_E_data, Ephemeris_E_size,
    Ephemeris_SQRT_A_data, Ephemeris_SQRT_A_size, localB->sinus_E_k_data,
    localB->sinus_E_k_size, localB->E_k_Dot_data, localB->E_k_Dot_size, localB);
  localB->cosinus_E_k_size[0] = 1;
  localB->cosinus_E_k_size[1] = localB->sinus_E_k_size[1];
  localB->loop_ub_a = localB->sinus_E_k_size[1];
  if (localB->loop_ub_a - 1 >= 0) {
    std::memcpy(&localB->cosinus_E_k_data[0], &localB->sinus_E_k_data[0],
                static_cast<uint32_T>(localB->loop_ub_a) * sizeof(real_T));
  }

  DDRTCM_cos(localB->cosinus_E_k_data, localB->cosinus_E_k_size);
  DDRTCM_sin(localB->sinus_E_k_data, localB->sinus_E_k_size);
  if (Ephemeris_E_size[1] == localB->cosinus_E_k_size[1]) {
    localB->r_k_size[0] = 1;
    localB->r_k_size[1] = Ephemeris_E_size[1];
    localB->loop_ub_a = Ephemeris_E_size[1];
    localB->scalarLB = (Ephemeris_E_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->r_k_data[localB->t_k_data_tmp], _mm_mul_pd
                    (_mm_loadu_pd(&Ephemeris_E_data[localB->t_k_data_tmp]),
                     tmp_6));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->r_k_data[localB->t_k_data_tmp] = Ephemeris_E_data
        [localB->t_k_data_tmp] * localB->cosinus_E_k_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_times_f(localB->r_k_data, localB->r_k_size, Ephemeris_E_data,
                   Ephemeris_E_size, localB->cosinus_E_k_data,
                   localB->cosinus_E_k_size);
  }

  localB->PHI_k_Dot_size[0] = 1;
  localB->PHI_k_Dot_size[1] = localB->r_k_size[1];
  localB->loop_ub_a = localB->r_k_size[1];
  localB->scalarLB = (localB->r_k_size[1] / 2) << 1;
  localB->vectorUB = localB->scalarLB - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
    _mm_storeu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp], _mm_sub_pd
                  (_mm_set1_pd(1.0), tmp_6));
  }

  for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
       localB->loop_ub_a; localB->t_k_data_tmp++) {
    localB->PHI_k_Dot_data[localB->t_k_data_tmp] = 1.0 - localB->r_k_data
      [localB->t_k_data_tmp];
  }

  localB->f_size[0] = 1;
  localB->f_size[1] = Ephemeris_E_size[1];
  localB->loop_ub_a = Ephemeris_E_size[1];
  localB->scalarLB = (Ephemeris_E_size[1] / 2) << 1;
  localB->vectorUB = localB->scalarLB - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&Ephemeris_E_data[localB->t_k_data_tmp]);
    _mm_storeu_pd(&localB->f_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_set1_pd
      (1.0), _mm_mul_pd(tmp_6, tmp_6)));
  }

  for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
       localB->loop_ub_a; localB->t_k_data_tmp++) {
    localB->N = Ephemeris_E_data[localB->t_k_data_tmp];
    localB->f_data[localB->t_k_data_tmp] = 1.0 - localB->N * localB->N;
  }

  DDRTCM_sqrt(localB->f_data, localB->f_size, localB);
  if ((localB->f_size[1] != localB->sinus_E_k_size[1]) || ((localB->f_size[1] ==
        1 ? localB->sinus_E_k_size[1] : localB->f_size[1]) != localB->r_k_size[1])
      || (localB->cosinus_E_k_size[1] != Ephemeris_E_size[1]) ||
      ((localB->cosinus_E_k_size[1] == 1 ? Ephemeris_E_size[1] :
        localB->cosinus_E_k_size[1]) != localB->r_k_size[1])) {
    DDRTCM_binary_expand_op_hn(localB->i_k_data, localB->i_k_size,
      localB->f_data, localB->f_size, localB->sinus_E_k_data,
      localB->sinus_E_k_size, localB->PHI_k_Dot_data, localB->PHI_k_Dot_size,
      localB->cosinus_E_k_data, localB->cosinus_E_k_size, Ephemeris_E_data,
      Ephemeris_E_size, localB);
  }

  DDRTCM_binary_expand_op_hn(localB->i_k_data, localB->i_k_size, localB->f_data,
    localB->f_size, localB->sinus_E_k_data, localB->sinus_E_k_size,
    localB->PHI_k_Dot_data, localB->PHI_k_Dot_size, localB->cosinus_E_k_data,
    localB->cosinus_E_k_size, Ephemeris_E_data, Ephemeris_E_size, localB);
  if ((localB->f_size[1] == localB->sinus_E_k_size[1]) && ((localB->f_size[1] ==
        1 ? localB->sinus_E_k_size[1] : localB->f_size[1]) == localB->r_k_size[1])
      && (localB->cosinus_E_k_size[1] == Ephemeris_E_size[1]) &&
      ((localB->cosinus_E_k_size[1] == 1 ? Ephemeris_E_size[1] :
        localB->cosinus_E_k_size[1]) == localB->r_k_size[1]) &&
      (localB->i_k_size[1] == Ephemeris_omega_size[1])) {
    localB->sin2PHI_k_size[0] = 1;
    localB->sin2PHI_k_size[1] = localB->f_size[1];
    localB->loop_ub_a = localB->f_size[1];
    localB->scalarLB = (localB->f_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->f_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->sinus_E_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp], _mm_div_pd
                    (_mm_mul_pd(tmp_6, tmp_4), tmp_5));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->sin2PHI_k_data[localB->t_k_data_tmp] = localB->f_data
        [localB->t_k_data_tmp] * localB->sinus_E_k_data[localB->t_k_data_tmp] /
        localB->PHI_k_Dot_data[localB->t_k_data_tmp];
    }

    localB->cos2PHI_k_size[0] = 1;
    localB->cos2PHI_k_size[1] = localB->cosinus_E_k_size[1];
    localB->loop_ub_a = localB->cosinus_E_k_size[1];
    localB->scalarLB = (localB->cosinus_E_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp], _mm_div_pd
                    (_mm_sub_pd(tmp_6, _mm_loadu_pd(&Ephemeris_E_data
        [localB->t_k_data_tmp])), tmp_4));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->cos2PHI_k_data[localB->t_k_data_tmp] = (localB->
        cosinus_E_k_data[localB->t_k_data_tmp] - Ephemeris_E_data
        [localB->t_k_data_tmp]) / localB->PHI_k_Dot_data[localB->t_k_data_tmp];
    }

    DDRTCM_atan2(localB->sin2PHI_k_data, localB->sin2PHI_k_size,
                 localB->cos2PHI_k_data, localB->cos2PHI_k_size,
                 localB->i_k_data, localB->i_k_size, localB);
    localB->cosinus_E_k_size[0] = 1;
    localB->cosinus_E_k_size[1] = localB->i_k_size[1];
    localB->loop_ub_a = localB->i_k_size[1];
    localB->scalarLB = (localB->i_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->i_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp], _mm_add_pd
                    (tmp_6, _mm_loadu_pd(&Ephemeris_omega_data
        [localB->t_k_data_tmp])));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->cosinus_E_k_data[localB->t_k_data_tmp] = localB->i_k_data
        [localB->t_k_data_tmp] + Ephemeris_omega_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_binary_expand_op_l(localB->cosinus_E_k_data, localB->cosinus_E_k_size,
      localB->f_data, localB->f_size, localB->sinus_E_k_data,
      localB->sinus_E_k_size, localB->PHI_k_Dot_data, localB->PHI_k_Dot_size,
      Ephemeris_E_data, Ephemeris_E_size, Ephemeris_omega_data,
      Ephemeris_omega_size, localB);
  }

  localB->i_k_size[0] = 1;
  localB->i_k_size[1] = localB->cosinus_E_k_size[1];
  localB->loop_ub_a = localB->cosinus_E_k_size[1];
  localB->scalarLB = (localB->cosinus_E_k_size[1] / 2) << 1;
  localB->vectorUB = localB->scalarLB - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp]);
    _mm_storeu_pd(&localB->i_k_data[localB->t_k_data_tmp], _mm_mul_pd
                  (_mm_set1_pd(2.0), tmp_6));
  }

  for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
       localB->loop_ub_a; localB->t_k_data_tmp++) {
    localB->i_k_data[localB->t_k_data_tmp] = 2.0 * localB->
      cosinus_E_k_data[localB->t_k_data_tmp];
  }

  localB->sin2PHI_k_size[0] = 1;
  localB->sin2PHI_k_size[1] = localB->cosinus_E_k_size[1];
  localB->loop_ub_a = localB->cosinus_E_k_size[1];
  if (localB->loop_ub_a - 1 >= 0) {
    std::memcpy(&localB->sin2PHI_k_data[0], &localB->i_k_data[0],
                static_cast<uint32_T>(localB->loop_ub_a) * sizeof(real_T));
  }

  DDRTCM_sin(localB->sin2PHI_k_data, localB->sin2PHI_k_size);
  localB->cos2PHI_k_size[0] = 1;
  localB->cos2PHI_k_size[1] = localB->cosinus_E_k_size[1];
  localB->loop_ub_a = localB->cosinus_E_k_size[1];
  if (localB->loop_ub_a - 1 >= 0) {
    std::memcpy(&localB->cos2PHI_k_data[0], &localB->i_k_data[0],
                static_cast<uint32_T>(localB->loop_ub_a) * sizeof(real_T));
  }

  DDRTCM_cos(localB->cos2PHI_k_data, localB->cos2PHI_k_size);
  if ((Ephemeris_C_us_size[1] == localB->sin2PHI_k_size[1]) &&
      (Ephemeris_C_uc_size[1] == localB->cos2PHI_k_size[1]) &&
      ((Ephemeris_C_us_size[1] == 1 ? localB->sin2PHI_k_size[1] :
        Ephemeris_C_us_size[1]) == (Ephemeris_C_uc_size[1] == 1 ?
        localB->cos2PHI_k_size[1] : Ephemeris_C_uc_size[1])) &&
      (((Ephemeris_C_us_size[1] == 1 ? localB->sin2PHI_k_size[1] :
         Ephemeris_C_us_size[1]) == 1 ? Ephemeris_C_uc_size[1] == 1 ?
        localB->cos2PHI_k_size[1] : Ephemeris_C_uc_size[1] :
        Ephemeris_C_us_size[1] == 1 ? localB->sin2PHI_k_size[1] :
        Ephemeris_C_us_size[1]) == localB->cosinus_E_k_size[1])) {
    localB->loop_ub_a = localB->cosinus_E_k_size[1] - 1;
    localB->cosinus_E_k_size[0] = 1;
    localB->scalarLB = (localB->cosinus_E_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp], _mm_add_pd
                    (_mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_C_us_data[localB->t_k_data_tmp]), tmp_6), _mm_mul_pd
        (_mm_loadu_pd(&Ephemeris_C_uc_data[localB->t_k_data_tmp]), tmp_4)),
                     tmp_5));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <=
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->cosinus_E_k_data[localB->t_k_data_tmp] +=
        Ephemeris_C_us_data[localB->t_k_data_tmp] * localB->
        sin2PHI_k_data[localB->t_k_data_tmp] + Ephemeris_C_uc_data
        [localB->t_k_data_tmp] * localB->cos2PHI_k_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_binary_expand_op_f(localB->cosinus_E_k_data, localB->cosinus_E_k_size,
      Ephemeris_C_us_data, Ephemeris_C_us_size, localB->sin2PHI_k_data,
      localB->sin2PHI_k_size, Ephemeris_C_uc_data, Ephemeris_C_uc_size,
      localB->cos2PHI_k_data, localB->cos2PHI_k_size, localB);
  }

  localB->scalarLB_tmp = (Ephemeris_SQRT_A_size[1] / 2) << 1;
  localB->vectorUB = localB->scalarLB_tmp - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
    _mm_storeu_pd(&localB->g_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
  }

  localB->vectorUB = localB->scalarLB_tmp - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
    _mm_storeu_pd(&localB->g_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
  }

  if ((Ephemeris_SQRT_A_size[1] == localB->r_k_size[1]) && (Ephemeris_C_rs_size
       [1] == localB->sin2PHI_k_size[1]) && (Ephemeris_C_rc_size[1] ==
       localB->cos2PHI_k_size[1]) && ((Ephemeris_C_rs_size[1] == 1 ?
        localB->sin2PHI_k_size[1] : Ephemeris_C_rs_size[1]) ==
       (Ephemeris_C_rc_size[1] == 1 ? localB->cos2PHI_k_size[1] :
        Ephemeris_C_rc_size[1])) && (((Ephemeris_C_rs_size[1] == 1 ?
         localB->sin2PHI_k_size[1] : Ephemeris_C_rs_size[1]) == 1 ?
        Ephemeris_C_rc_size[1] == 1 ? localB->cos2PHI_k_size[1] :
        Ephemeris_C_rc_size[1] : Ephemeris_C_rs_size[1] == 1 ?
        localB->sin2PHI_k_size[1] : Ephemeris_C_rs_size[1]) ==
       (Ephemeris_SQRT_A_size[1] == 1 ? localB->r_k_size[1] :
        Ephemeris_SQRT_A_size[1]))) {
    localB->loop_ub_a = Ephemeris_SQRT_A_size[1] - 1;
    localB->r_k_size[0] = 1;
    localB->r_k_size[1] = Ephemeris_SQRT_A_size[1];
    localB->vectorUB = localB->scalarLB_tmp - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->r_k_data[localB->t_k_data_tmp], _mm_add_pd
                    (_mm_mul_pd(_mm_mul_pd(tmp_6, tmp_6), _mm_sub_pd(_mm_set1_pd
        (1.0), tmp_4)), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_C_rs_data[localB->t_k_data_tmp]), tmp_5), _mm_mul_pd
        (_mm_loadu_pd(&Ephemeris_C_rc_data[localB->t_k_data_tmp]), tmp_3))));
    }

    for (localB->t_k_data_tmp = localB->scalarLB_tmp; localB->t_k_data_tmp <=
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->N = Ephemeris_SQRT_A_data[localB->t_k_data_tmp];
      localB->r_k_data[localB->t_k_data_tmp] = localB->N * localB->N * (1.0 -
        localB->r_k_data[localB->t_k_data_tmp]) + (Ephemeris_C_rs_data
        [localB->t_k_data_tmp] * localB->sin2PHI_k_data[localB->t_k_data_tmp] +
        Ephemeris_C_rc_data[localB->t_k_data_tmp] * localB->
        cos2PHI_k_data[localB->t_k_data_tmp]);
    }
  } else {
    DDRTCM_binary_expand_op_j(localB->r_k_data, localB->r_k_size,
      Ephemeris_SQRT_A_data, Ephemeris_SQRT_A_size, Ephemeris_C_rs_data,
      Ephemeris_C_rs_size, localB->sin2PHI_k_data, localB->sin2PHI_k_size,
      Ephemeris_C_rc_data, Ephemeris_C_rc_size, localB->cos2PHI_k_data,
      localB->cos2PHI_k_size, localB);
  }

  if ((Ephemeris_C_is_size[1] == localB->sin2PHI_k_size[1]) &&
      (Ephemeris_C_ic_size[1] == localB->cos2PHI_k_size[1]) &&
      ((Ephemeris_C_is_size[1] == 1 ? localB->sin2PHI_k_size[1] :
        Ephemeris_C_is_size[1]) == (Ephemeris_C_ic_size[1] == 1 ?
        localB->cos2PHI_k_size[1] : Ephemeris_C_ic_size[1])) &&
      (((Ephemeris_C_is_size[1] == 1 ? localB->sin2PHI_k_size[1] :
         Ephemeris_C_is_size[1]) == 1 ? Ephemeris_C_ic_size[1] == 1 ?
        localB->cos2PHI_k_size[1] : Ephemeris_C_ic_size[1] :
        Ephemeris_C_is_size[1] == 1 ? localB->sin2PHI_k_size[1] :
        Ephemeris_C_is_size[1]) == Ephemeris_I_0_size[1]) &&
      (Ephemeris_IDOT_size[1] == localB->t_k_size[1]) && ((Ephemeris_I_0_size[1]
        == 1 ? (Ephemeris_C_is_size[1] == 1 ? localB->sin2PHI_k_size[1] :
                Ephemeris_C_is_size[1]) == 1 ? Ephemeris_C_ic_size[1] == 1 ?
        localB->cos2PHI_k_size[1] : Ephemeris_C_ic_size[1] :
        Ephemeris_C_is_size[1] == 1 ? localB->sin2PHI_k_size[1] :
        Ephemeris_C_is_size[1] : Ephemeris_I_0_size[1]) == (Ephemeris_IDOT_size
        [1] == 1 ? localB->t_k_size[1] : Ephemeris_IDOT_size[1]))) {
    localB->i_k_size[0] = 1;
    localB->i_k_size[1] = Ephemeris_I_0_size[1];
    localB->loop_ub_a = Ephemeris_I_0_size[1];
    localB->scalarLB = (Ephemeris_I_0_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->t_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->i_k_data[localB->t_k_data_tmp], _mm_add_pd
                    (_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_C_is_data[localB->t_k_data_tmp]), tmp_6), _mm_mul_pd
        (_mm_loadu_pd(&Ephemeris_C_ic_data[localB->t_k_data_tmp]), tmp_4)),
        _mm_loadu_pd(&Ephemeris_I_0_data[localB->t_k_data_tmp])), _mm_mul_pd
                     (_mm_loadu_pd(&Ephemeris_IDOT_data[localB->t_k_data_tmp]),
                      tmp_5)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->i_k_data[localB->t_k_data_tmp] = ((Ephemeris_C_is_data
        [localB->t_k_data_tmp] * localB->sin2PHI_k_data[localB->t_k_data_tmp] +
        Ephemeris_C_ic_data[localB->t_k_data_tmp] * localB->
        cos2PHI_k_data[localB->t_k_data_tmp]) + Ephemeris_I_0_data
        [localB->t_k_data_tmp]) + Ephemeris_IDOT_data[localB->t_k_data_tmp] *
        localB->t_k_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_binary_expand_op_a(localB->i_k_data, localB->i_k_size,
      Ephemeris_I_0_data, Ephemeris_I_0_size, Ephemeris_C_is_data,
      Ephemeris_C_is_size, localB->sin2PHI_k_data, localB->sin2PHI_k_size,
      Ephemeris_C_ic_data, Ephemeris_C_ic_size, localB->cos2PHI_k_data,
      localB->cos2PHI_k_size, Ephemeris_IDOT_data, Ephemeris_IDOT_size,
      localB->t_k_data, localB->t_k_size, localB);
  }

  localB->f_size[0] = 1;
  localB->f_size[1] = Ephemeris_OMEGADOT_size[1];
  localB->loop_ub_a = Ephemeris_OMEGADOT_size[1];
  localB->scalarLB = (Ephemeris_OMEGADOT_size[1] / 2) << 1;
  localB->vectorUB = localB->scalarLB - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    _mm_storeu_pd(&localB->f_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_loadu_pd
      (&Ephemeris_OMEGADOT_data[localB->t_k_data_tmp]), _mm_set1_pd
      (7.2921151467E-5)));
  }

  for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
       localB->loop_ub_a; localB->t_k_data_tmp++) {
    localB->f_data[localB->t_k_data_tmp] = Ephemeris_OMEGADOT_data
      [localB->t_k_data_tmp] - 7.2921151467E-5;
  }

  if ((Ephemeris_OMEGADOT_size[1] == localB->t_k_size[1]) &&
      ((Ephemeris_OMEGADOT_size[1] == 1 ? localB->t_k_size[1] :
        Ephemeris_OMEGADOT_size[1]) == Ephemeris_OMEGA_0_size[1]) &&
      ((Ephemeris_OMEGA_0_size[1] == 1 ? Ephemeris_OMEGADOT_size[1] == 1 ?
        localB->t_k_size[1] : Ephemeris_OMEGADOT_size[1] :
        Ephemeris_OMEGA_0_size[1]) == Ephemeris_T_oe_size[1])) {
    localB->loop_ub_a = Ephemeris_OMEGA_0_size[1] - 1;
    localB->t_k_size[0] = 1;
    localB->t_k_size[1] = Ephemeris_OMEGA_0_size[1];
    localB->scalarLB = (Ephemeris_OMEGA_0_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->f_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->t_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->t_k_data[localB->t_k_data_tmp], _mm_sub_pd
                    (_mm_add_pd(_mm_mul_pd(tmp_6, tmp_4), _mm_loadu_pd
        (&Ephemeris_OMEGA_0_data[localB->t_k_data_tmp])), _mm_mul_pd(_mm_set1_pd
        (7.2921151467E-5), _mm_loadu_pd(&Ephemeris_T_oe_data
        [localB->t_k_data_tmp]))));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <=
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->t_k_data[localB->t_k_data_tmp] = (localB->f_data
        [localB->t_k_data_tmp] * localB->t_k_data[localB->t_k_data_tmp] +
        Ephemeris_OMEGA_0_data[localB->t_k_data_tmp]) - 7.2921151467E-5 *
        Ephemeris_T_oe_data[localB->t_k_data_tmp];
    }
  } else {
    binary_expand_o_hnvylqpxcvlyr4g(localB->t_k_data, localB->t_k_size,
      Ephemeris_OMEGA_0_data, Ephemeris_OMEGA_0_size, localB->f_data,
      localB->f_size, Ephemeris_T_oe_data, Ephemeris_T_oe_size, localB);
  }

  localB->cosinus_u_k_size[0] = 1;
  localB->cosinus_u_k_size[1] = localB->cosinus_E_k_size[1];
  localB->loop_ub_a = localB->cosinus_E_k_size[1];
  if (localB->loop_ub_a - 1 >= 0) {
    std::memcpy(&localB->cosinus_u_k_data[0], &localB->cosinus_E_k_data[0],
                static_cast<uint32_T>(localB->loop_ub_a) * sizeof(real_T));
  }

  DDRTCM_cos(localB->cosinus_u_k_data, localB->cosinus_u_k_size);
  DDRTCM_sin(localB->cosinus_E_k_data, localB->cosinus_E_k_size);
  localB->cosinus_i_k_size[0] = 1;
  localB->cosinus_i_k_size[1] = localB->i_k_size[1];
  localB->loop_ub_a = localB->i_k_size[1];
  if (localB->loop_ub_a - 1 >= 0) {
    std::memcpy(&localB->cosinus_i_k_data[0], &localB->i_k_data[0],
                static_cast<uint32_T>(localB->loop_ub_a) * sizeof(real_T));
  }

  DDRTCM_cos(localB->cosinus_i_k_data, localB->cosinus_i_k_size);
  DDRTCM_sin(localB->i_k_data, localB->i_k_size);
  localB->sinus_lambda_k_size[0] = 1;
  localB->sinus_lambda_k_size[1] = localB->t_k_size[1];
  localB->loop_ub_a = localB->t_k_size[1];
  if (localB->loop_ub_a - 1 >= 0) {
    std::memcpy(&localB->sinus_lambda_k_data[0], &localB->t_k_data[0],
                static_cast<uint32_T>(localB->loop_ub_a) * sizeof(real_T));
  }

  DDRTCM_sin(localB->sinus_lambda_k_data, localB->sinus_lambda_k_size);
  DDRTCM_cos(localB->t_k_data, localB->t_k_size);
  if (localB->r_k_size[1] == localB->cosinus_u_k_size[1]) {
    localB->X_k_tmp_size[0] = 1;
    localB->X_k_tmp_size[1] = localB->r_k_size[1];
    localB->loop_ub_a = localB->r_k_size[1];
    localB->scalarLB = (localB->r_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->cosinus_u_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->X_k_tmp_data[localB->t_k_data_tmp], _mm_mul_pd
                    (tmp_6, tmp_4));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->X_k_tmp_data[localB->t_k_data_tmp] = localB->r_k_data
        [localB->t_k_data_tmp] * localB->cosinus_u_k_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_times_f(localB->X_k_tmp_data, localB->X_k_tmp_size, localB->r_k_data,
                   localB->r_k_size, localB->cosinus_u_k_data,
                   localB->cosinus_u_k_size);
  }

  if (localB->r_k_size[1] == localB->cosinus_E_k_size[1]) {
    localB->loop_ub_a = localB->r_k_size[1] - 1;
    localB->r_k_size[0] = 1;
    localB->scalarLB = (localB->r_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->r_k_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6,
        tmp_4));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <=
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->r_k_data[localB->t_k_data_tmp] *= localB->cosinus_E_k_data
        [localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_times_fc(localB->r_k_data, localB->r_k_size, localB->cosinus_E_k_data,
                    localB->cosinus_E_k_size, localB);
  }

  sv_pos_size[0] = localB->X_k_tmp_size[1];
  sv_pos_size[1] = 3;
  localB->loop_ub_a = localB->X_k_tmp_size[1] * 3;
  if (localB->loop_ub_a - 1 >= 0) {
    std::memset(&sv_pos_data[0], 0, static_cast<uint32_T>(localB->loop_ub_a) *
                sizeof(real_T));
  }

  if (localB->r_k_size[1] == localB->cosinus_i_k_size[1]) {
    localB->c_size[0] = 1;
    localB->c_size[1] = localB->r_k_size[1];
    localB->loop_ub_a = localB->r_k_size[1];
    localB->scalarLB = (localB->r_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->cosinus_i_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->c_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6,
        tmp_4));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->c_data[localB->t_k_data_tmp] = localB->r_k_data
        [localB->t_k_data_tmp] * localB->cosinus_i_k_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_times_f(localB->c_data, localB->c_size, localB->r_k_data,
                   localB->r_k_size, localB->cosinus_i_k_data,
                   localB->cosinus_i_k_size);
  }

  if ((localB->X_k_tmp_size[1] == localB->t_k_size[1]) && (localB->c_size[1] ==
       localB->sinus_lambda_k_size[1]) && ((localB->X_k_tmp_size[1] == 1 ?
        localB->t_k_size[1] : localB->X_k_tmp_size[1]) == (localB->c_size[1] ==
        1 ? localB->sinus_lambda_k_size[1] : localB->c_size[1]))) {
    localB->loop_ub_a = localB->X_k_tmp_size[1];
    localB->scalarLB = (localB->X_k_tmp_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->X_k_tmp_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->t_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->c_data[localB->t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&localB->sinus_lambda_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&sv_pos_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_mul_pd
        (tmp_6, tmp_4), _mm_mul_pd(tmp_5, tmp_3)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      sv_pos_data[localB->t_k_data_tmp] = localB->X_k_tmp_data
        [localB->t_k_data_tmp] * localB->t_k_data[localB->t_k_data_tmp] -
        localB->c_data[localB->t_k_data_tmp] * localB->
        sinus_lambda_k_data[localB->t_k_data_tmp];
    }
  } else {
    binary_expand_op_hnvylqpxcvlyr4(sv_pos_data, localB->X_k_tmp_data,
      localB->X_k_tmp_size, localB->t_k_data, localB->t_k_size, localB->c_data,
      localB->c_size, localB->sinus_lambda_k_data, localB->sinus_lambda_k_size);
  }

  if ((localB->X_k_tmp_size[1] == localB->sinus_lambda_k_size[1]) &&
      (localB->c_size[1] == localB->t_k_size[1]) && ((localB->X_k_tmp_size[1] ==
        1 ? localB->sinus_lambda_k_size[1] : localB->X_k_tmp_size[1]) ==
       (localB->c_size[1] == 1 ? localB->t_k_size[1] : localB->c_size[1]))) {
    localB->loop_ub_a = sv_pos_size[0];
    localB->scalarLB = (sv_pos_size[0] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->X_k_tmp_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->sinus_lambda_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->c_data[localB->t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&localB->t_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&sv_pos_data[localB->t_k_data_tmp + sv_pos_size[0]],
                    _mm_add_pd(_mm_mul_pd(tmp_6, tmp_4), _mm_mul_pd(tmp_5, tmp_3)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      sv_pos_data[localB->t_k_data_tmp + sv_pos_size[0]] = localB->
        X_k_tmp_data[localB->t_k_data_tmp] * localB->sinus_lambda_k_data
        [localB->t_k_data_tmp] + localB->c_data[localB->t_k_data_tmp] *
        localB->t_k_data[localB->t_k_data_tmp];
    }
  } else {
    binary_expand_op_hnvylqpxcvlyr(sv_pos_data, sv_pos_size,
      localB->X_k_tmp_data, localB->X_k_tmp_size, localB->sinus_lambda_k_data,
      localB->sinus_lambda_k_size, localB->c_data, localB->c_size,
      localB->t_k_data, localB->t_k_size);
  }

  if (localB->r_k_size[1] == localB->i_k_size[1]) {
    localB->d_size[0] = 1;
    localB->d_size[1] = localB->r_k_size[1];
    localB->loop_ub_a = localB->r_k_size[1];
    localB->scalarLB = (localB->r_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->i_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->d_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6,
        tmp_4));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->d_data[localB->t_k_data_tmp] = localB->r_k_data
        [localB->t_k_data_tmp] * localB->i_k_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_times_f(localB->d_data, localB->d_size, localB->r_k_data,
                   localB->r_k_size, localB->i_k_data, localB->i_k_size);
  }

  localB->loop_ub_a = sv_pos_size[0];
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp < localB->loop_ub_a;
       localB->t_k_data_tmp++) {
    sv_pos_data[localB->t_k_data_tmp + (sv_pos_size[0] << 1)] = localB->
      d_data[localB->t_k_data_tmp];
  }

  localB->g_size[0] = 1;
  localB->g_size[1] = Ephemeris_E_size[1];
  localB->loop_ub_a = Ephemeris_E_size[1];
  localB->scalarLB = (Ephemeris_E_size[1] / 2) << 1;
  localB->vectorUB = localB->scalarLB - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&Ephemeris_E_data[localB->t_k_data_tmp]);
    _mm_storeu_pd(&localB->g_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_set1_pd
      (1.0), _mm_mul_pd(tmp_6, tmp_6)));
  }

  for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
       localB->loop_ub_a; localB->t_k_data_tmp++) {
    localB->N = Ephemeris_E_data[localB->t_k_data_tmp];
    localB->g_data[localB->t_k_data_tmp] = 1.0 - localB->N * localB->N;
  }

  DDRTCM_sqrt(localB->g_data, localB->g_size, localB);
  if ((localB->g_size[1] == localB->E_k_Dot_size[1]) && ((localB->g_size[1] == 1
        ? localB->E_k_Dot_size[1] : localB->g_size[1]) == localB->
       PHI_k_Dot_size[1])) {
    localB->loop_ub_a = localB->g_size[1] - 1;
    localB->PHI_k_Dot_size[0] = 1;
    localB->PHI_k_Dot_size[1] = localB->g_size[1];
    localB->scalarLB = (localB->g_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->g_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->E_k_Dot_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp], _mm_div_pd
                    (_mm_mul_pd(tmp_6, tmp_4), tmp_5));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <=
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->PHI_k_Dot_data[localB->t_k_data_tmp] = localB->g_data
        [localB->t_k_data_tmp] * localB->E_k_Dot_data[localB->t_k_data_tmp] /
        localB->PHI_k_Dot_data[localB->t_k_data_tmp];
    }
  } else {
    D_binary_expand_op_hnvylqpxcvly(localB->PHI_k_Dot_data,
      localB->PHI_k_Dot_size, localB->g_data, localB->g_size,
      localB->E_k_Dot_data, localB->E_k_Dot_size, localB);
  }

  if ((Ephemeris_C_us_size[1] == localB->cos2PHI_k_size[1]) &&
      (Ephemeris_C_uc_size[1] == localB->sin2PHI_k_size[1]) &&
      ((Ephemeris_C_us_size[1] == 1 ? localB->cos2PHI_k_size[1] :
        Ephemeris_C_us_size[1]) == (Ephemeris_C_uc_size[1] == 1 ?
        localB->sin2PHI_k_size[1] : Ephemeris_C_uc_size[1])) &&
      (((Ephemeris_C_us_size[1] == 1 ? localB->cos2PHI_k_size[1] :
         Ephemeris_C_us_size[1]) == 1 ? Ephemeris_C_uc_size[1] == 1 ?
        localB->sin2PHI_k_size[1] : Ephemeris_C_uc_size[1] :
        Ephemeris_C_us_size[1] == 1 ? localB->cos2PHI_k_size[1] :
        Ephemeris_C_us_size[1]) == localB->PHI_k_Dot_size[1])) {
    localB->u_k_Dot_size[0] = 1;
    localB->u_k_Dot_size[1] = Ephemeris_C_us_size[1];
    localB->loop_ub_a = Ephemeris_C_us_size[1];
    localB->scalarLB = (Ephemeris_C_us_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_set1_pd(2.0);
      tmp_4 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->u_k_Dot_data[localB->t_k_data_tmp], _mm_mul_pd
                    (_mm_sub_pd(_mm_add_pd(_mm_mul_pd(_mm_mul_pd(tmp_6,
        _mm_loadu_pd(&Ephemeris_C_us_data[localB->t_k_data_tmp])), tmp_4),
        _mm_set1_pd(1.0)), _mm_mul_pd(_mm_mul_pd(tmp_6, _mm_loadu_pd
        (&Ephemeris_C_uc_data[localB->t_k_data_tmp])), tmp_5)), tmp_3));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->u_k_Dot_data[localB->t_k_data_tmp] = ((2.0 *
        Ephemeris_C_us_data[localB->t_k_data_tmp] * localB->
        cos2PHI_k_data[localB->t_k_data_tmp] + 1.0) - 2.0 *
        Ephemeris_C_uc_data[localB->t_k_data_tmp] * localB->
        sin2PHI_k_data[localB->t_k_data_tmp]) * localB->PHI_k_Dot_data
        [localB->t_k_data_tmp];
    }
  } else {
    DD_binary_expand_op_hnvylqpxcvl(localB->u_k_Dot_data, localB->u_k_Dot_size,
      Ephemeris_C_us_data, Ephemeris_C_us_size, localB->cos2PHI_k_data,
      localB->cos2PHI_k_size, Ephemeris_C_uc_data, Ephemeris_C_uc_size,
      localB->sin2PHI_k_data, localB->sin2PHI_k_size, localB->PHI_k_Dot_data,
      localB->PHI_k_Dot_size);
  }

  localB->vectorUB = localB->scalarLB_tmp - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
    _mm_storeu_pd(&localB->g_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
  }

  localB->vectorUB = localB->scalarLB_tmp - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
    _mm_storeu_pd(&localB->g_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
  }

  localB->vectorUB = localB->scalarLB_tmp - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
    _mm_storeu_pd(&localB->g_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
  }

  localB->vectorUB = localB->scalarLB_tmp - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
    _mm_storeu_pd(&localB->g_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6, tmp_6));
  }

  if ((Ephemeris_C_rs_size[1] == localB->cos2PHI_k_size[1]) &&
      (Ephemeris_C_rc_size[1] == localB->sin2PHI_k_size[1]) &&
      ((Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] :
        Ephemeris_C_rs_size[1]) == (Ephemeris_C_rc_size[1] == 1 ?
        localB->sin2PHI_k_size[1] : Ephemeris_C_rc_size[1])) &&
      (((Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] :
         Ephemeris_C_rs_size[1]) == 1 ? Ephemeris_C_rc_size[1] == 1 ?
        localB->sin2PHI_k_size[1] : Ephemeris_C_rc_size[1] :
        Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] :
        Ephemeris_C_rs_size[1]) == localB->PHI_k_Dot_size[1]) &&
      (Ephemeris_SQRT_A_size[1] == Ephemeris_E_size[1]) &&
      ((Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] :
        Ephemeris_SQRT_A_size[1]) == localB->sinus_E_k_size[1]) &&
      (((Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] :
         Ephemeris_SQRT_A_size[1]) == 1 ? localB->sinus_E_k_size[1] :
        Ephemeris_SQRT_A_size[1] == 1 ? Ephemeris_E_size[1] :
        Ephemeris_SQRT_A_size[1]) == localB->E_k_Dot_size[1]) &&
      ((((Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] :
          Ephemeris_C_rs_size[1]) == 1 ? Ephemeris_C_rc_size[1] == 1 ?
         localB->sin2PHI_k_size[1] : Ephemeris_C_rc_size[1] :
         Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] :
         Ephemeris_C_rs_size[1]) == 1 ? localB->PHI_k_Dot_size[1] :
        (Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] :
         Ephemeris_C_rs_size[1]) == 1 ? Ephemeris_C_rc_size[1] == 1 ?
        localB->sin2PHI_k_size[1] : Ephemeris_C_rc_size[1] :
        Ephemeris_C_rs_size[1] == 1 ? localB->cos2PHI_k_size[1] :
        Ephemeris_C_rs_size[1]) == (((Ephemeris_SQRT_A_size[1] == 1 ?
          Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1]) == 1 ?
         localB->sinus_E_k_size[1] : Ephemeris_SQRT_A_size[1] == 1 ?
         Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1]) == 1 ?
        localB->E_k_Dot_size[1] : (Ephemeris_SQRT_A_size[1] == 1 ?
         Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1]) == 1 ?
        localB->sinus_E_k_size[1] : Ephemeris_SQRT_A_size[1] == 1 ?
        Ephemeris_E_size[1] : Ephemeris_SQRT_A_size[1]))) {
    localB->loop_ub_a = Ephemeris_C_rs_size[1] - 1;
    localB->sinus_E_k_size[0] = 1;
    localB->sinus_E_k_size[1] = Ephemeris_C_rs_size[1];
    localB->scalarLB = (Ephemeris_C_rs_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[localB->t_k_data_tmp]);
      tmp_1 = _mm_loadu_pd(&localB->sinus_E_k_data[localB->t_k_data_tmp]);
      tmp_2 = _mm_loadu_pd(&localB->E_k_Dot_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->sinus_E_k_data[localB->t_k_data_tmp], _mm_add_pd
                    (_mm_mul_pd(_mm_mul_pd(_mm_sub_pd(_mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_C_rs_data[localB->t_k_data_tmp]), tmp_6), _mm_mul_pd
        (_mm_loadu_pd(&Ephemeris_C_rc_data[localB->t_k_data_tmp]), tmp_4)),
        _mm_set1_pd(2.0)), tmp_5), _mm_mul_pd(_mm_mul_pd(_mm_mul_pd(_mm_mul_pd
        (tmp_3, tmp_3), _mm_loadu_pd(&Ephemeris_E_data[localB->t_k_data_tmp])),
        tmp_1), tmp_2)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <=
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->N = Ephemeris_SQRT_A_data[localB->t_k_data_tmp];
      localB->sinus_E_k_data[localB->t_k_data_tmp] = (Ephemeris_C_rs_data
        [localB->t_k_data_tmp] * localB->cos2PHI_k_data[localB->t_k_data_tmp] -
        Ephemeris_C_rc_data[localB->t_k_data_tmp] * localB->
        sin2PHI_k_data[localB->t_k_data_tmp]) * 2.0 * localB->
        PHI_k_Dot_data[localB->t_k_data_tmp] + localB->N * localB->N *
        Ephemeris_E_data[localB->t_k_data_tmp] * localB->sinus_E_k_data
        [localB->t_k_data_tmp] * localB->E_k_Dot_data[localB->t_k_data_tmp];
    }
  } else {
    DDR_binary_expand_op_hnvylqpxcv(localB->sinus_E_k_data,
      localB->sinus_E_k_size, Ephemeris_C_rs_data, Ephemeris_C_rs_size,
      localB->cos2PHI_k_data, localB->cos2PHI_k_size, Ephemeris_C_rc_data,
      Ephemeris_C_rc_size, localB->sin2PHI_k_data, localB->sin2PHI_k_size,
      localB->PHI_k_Dot_data, localB->PHI_k_Dot_size, Ephemeris_SQRT_A_data,
      Ephemeris_SQRT_A_size, Ephemeris_E_data, Ephemeris_E_size,
      localB->E_k_Dot_data, localB->E_k_Dot_size, localB);
  }

  if ((Ephemeris_C_is_size[1] == localB->cos2PHI_k_size[1]) &&
      (Ephemeris_C_ic_size[1] == localB->sin2PHI_k_size[1]) &&
      ((Ephemeris_C_is_size[1] == 1 ? localB->cos2PHI_k_size[1] :
        Ephemeris_C_is_size[1]) == (Ephemeris_C_ic_size[1] == 1 ?
        localB->sin2PHI_k_size[1] : Ephemeris_C_ic_size[1])) &&
      (((Ephemeris_C_is_size[1] == 1 ? localB->cos2PHI_k_size[1] :
         Ephemeris_C_is_size[1]) == 1 ? Ephemeris_C_ic_size[1] == 1 ?
        localB->sin2PHI_k_size[1] : Ephemeris_C_ic_size[1] :
        Ephemeris_C_is_size[1] == 1 ? localB->cos2PHI_k_size[1] :
        Ephemeris_C_is_size[1]) == localB->PHI_k_Dot_size[1]) &&
      ((((Ephemeris_C_is_size[1] == 1 ? localB->cos2PHI_k_size[1] :
          Ephemeris_C_is_size[1]) == 1 ? Ephemeris_C_ic_size[1] == 1 ?
         localB->sin2PHI_k_size[1] : Ephemeris_C_ic_size[1] :
         Ephemeris_C_is_size[1] == 1 ? localB->cos2PHI_k_size[1] :
         Ephemeris_C_is_size[1]) == 1 ? localB->PHI_k_Dot_size[1] :
        (Ephemeris_C_is_size[1] == 1 ? localB->cos2PHI_k_size[1] :
         Ephemeris_C_is_size[1]) == 1 ? Ephemeris_C_ic_size[1] == 1 ?
        localB->sin2PHI_k_size[1] : Ephemeris_C_ic_size[1] :
        Ephemeris_C_is_size[1] == 1 ? localB->cos2PHI_k_size[1] :
        Ephemeris_C_is_size[1]) == Ephemeris_IDOT_size[1])) {
    localB->loop_ub_a = Ephemeris_C_is_size[1] - 1;
    localB->cos2PHI_k_size[0] = 1;
    localB->cos2PHI_k_size[1] = Ephemeris_C_is_size[1];
    localB->scalarLB = (Ephemeris_C_is_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->sin2PHI_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->PHI_k_Dot_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp], _mm_add_pd
                    (_mm_mul_pd(_mm_mul_pd(_mm_sub_pd(_mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_C_is_data[localB->t_k_data_tmp]), tmp_6), _mm_mul_pd
        (_mm_loadu_pd(&Ephemeris_C_ic_data[localB->t_k_data_tmp]), tmp_4)),
        _mm_set1_pd(2.0)), tmp_5), _mm_loadu_pd(&Ephemeris_IDOT_data
        [localB->t_k_data_tmp])));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <=
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->cos2PHI_k_data[localB->t_k_data_tmp] = (Ephemeris_C_is_data
        [localB->t_k_data_tmp] * localB->cos2PHI_k_data[localB->t_k_data_tmp] -
        Ephemeris_C_ic_data[localB->t_k_data_tmp] * localB->
        sin2PHI_k_data[localB->t_k_data_tmp]) * 2.0 * localB->
        PHI_k_Dot_data[localB->t_k_data_tmp] + Ephemeris_IDOT_data
        [localB->t_k_data_tmp];
    }
  } else {
    DDRT_binary_expand_op_hnvylqpxc(localB->cos2PHI_k_data,
      localB->cos2PHI_k_size, Ephemeris_C_is_data, Ephemeris_C_is_size,
      Ephemeris_C_ic_data, Ephemeris_C_ic_size, localB->sin2PHI_k_data,
      localB->sin2PHI_k_size, localB->PHI_k_Dot_data, localB->PHI_k_Dot_size,
      Ephemeris_IDOT_data, Ephemeris_IDOT_size, localB);
  }

  if ((localB->sinus_E_k_size[1] == localB->cosinus_u_k_size[1]) &&
      (localB->r_k_size[1] == localB->u_k_Dot_size[1]) &&
      ((localB->sinus_E_k_size[1] == 1 ? localB->cosinus_u_k_size[1] :
        localB->sinus_E_k_size[1]) == (localB->r_k_size[1] == 1 ?
        localB->u_k_Dot_size[1] : localB->r_k_size[1]))) {
    localB->loop_ub_a = localB->sinus_E_k_size[1] - 1;
    localB->cosinus_u_k_size[0] = 1;
    localB->cosinus_u_k_size[1] = localB->sinus_E_k_size[1];
    localB->scalarLB = (localB->sinus_E_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->sinus_E_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->cosinus_u_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->r_k_data[localB->t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&localB->u_k_Dot_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->cosinus_u_k_data[localB->t_k_data_tmp], _mm_sub_pd
                    (_mm_mul_pd(tmp_6, tmp_4), _mm_mul_pd(tmp_5, tmp_3)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <=
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->cosinus_u_k_data[localB->t_k_data_tmp] = localB->
        sinus_E_k_data[localB->t_k_data_tmp] * localB->cosinus_u_k_data
        [localB->t_k_data_tmp] - localB->r_k_data[localB->t_k_data_tmp] *
        localB->u_k_Dot_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTC_binary_expand_op_hnvylqpx(localB->cosinus_u_k_data,
      localB->cosinus_u_k_size, localB->sinus_E_k_data, localB->sinus_E_k_size,
      localB->r_k_data, localB->r_k_size, localB->u_k_Dot_data,
      localB->u_k_Dot_size, localB);
  }

  if ((localB->sinus_E_k_size[1] == localB->cosinus_E_k_size[1]) &&
      (localB->X_k_tmp_size[1] == localB->u_k_Dot_size[1]) &&
      ((localB->sinus_E_k_size[1] == 1 ? localB->cosinus_E_k_size[1] :
        localB->sinus_E_k_size[1]) == (localB->X_k_tmp_size[1] == 1 ?
        localB->u_k_Dot_size[1] : localB->X_k_tmp_size[1]))) {
    localB->loop_ub_a = localB->sinus_E_k_size[1] - 1;
    localB->sinus_E_k_size[0] = 1;
    localB->scalarLB = (localB->sinus_E_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->sinus_E_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->cosinus_E_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->X_k_tmp_data[localB->t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&localB->u_k_Dot_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->sinus_E_k_data[localB->t_k_data_tmp], _mm_add_pd
                    (_mm_mul_pd(tmp_6, tmp_4), _mm_mul_pd(tmp_5, tmp_3)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <=
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->sinus_E_k_data[localB->t_k_data_tmp] = localB->
        sinus_E_k_data[localB->t_k_data_tmp] * localB->cosinus_E_k_data
        [localB->t_k_data_tmp] + localB->X_k_tmp_data[localB->t_k_data_tmp] *
        localB->u_k_Dot_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_binary_expand_op_hnvylqp(localB->sinus_E_k_data,
      localB->sinus_E_k_size, localB->cosinus_E_k_data, localB->cosinus_E_k_size,
      localB->X_k_tmp_data, localB->X_k_tmp_size, localB->u_k_Dot_data,
      localB->u_k_Dot_size, localB);
  }

  sv_vel_size[0] = localB->cosinus_u_k_size[1];
  sv_vel_size[1] = 3;
  localB->loop_ub_a = localB->cosinus_u_k_size[1] * 3;
  if (localB->loop_ub_a - 1 >= 0) {
    std::memset(&sv_vel_data[0], 0, static_cast<uint32_T>(localB->loop_ub_a) *
                sizeof(real_T));
  }

  if (localB->sinus_E_k_size[1] == localB->cosinus_i_k_size[1]) {
    localB->loop_ub_a = localB->sinus_E_k_size[1] - 1;
    localB->cosinus_i_k_size[0] = 1;
    localB->cosinus_i_k_size[1] = localB->sinus_E_k_size[1];
    localB->scalarLB = (localB->sinus_E_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->sinus_E_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->cosinus_i_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&localB->cosinus_i_k_data[localB->t_k_data_tmp], _mm_mul_pd
                    (tmp_6, tmp_4));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <=
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->cosinus_i_k_data[localB->t_k_data_tmp] *= localB->
        sinus_E_k_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_times(localB->cosinus_i_k_data, localB->cosinus_i_k_size,
                 localB->sinus_E_k_data, localB->sinus_E_k_size, localB);
  }

  if ((localB->cosinus_u_k_size[1] == localB->t_k_size[1]) &&
      (localB->cosinus_i_k_size[1] == localB->sinus_lambda_k_size[1]) &&
      ((localB->cosinus_u_k_size[1] == 1 ? localB->t_k_size[1] :
        localB->cosinus_u_k_size[1]) == (localB->cosinus_i_k_size[1] == 1 ?
        localB->sinus_lambda_k_size[1] : localB->cosinus_i_k_size[1])) &&
      (localB->d_size[1] == localB->sinus_lambda_k_size[1]) && ((localB->d_size
        [1] == 1 ? localB->sinus_lambda_k_size[1] : localB->d_size[1]) ==
       localB->cos2PHI_k_size[1]) && (((localB->cosinus_u_k_size[1] == 1 ?
         localB->t_k_size[1] : localB->cosinus_u_k_size[1]) == 1 ?
        localB->cosinus_i_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
        localB->cosinus_i_k_size[1] : localB->cosinus_u_k_size[1] == 1 ?
        localB->t_k_size[1] : localB->cosinus_u_k_size[1]) == ((localB->d_size[1]
         == 1 ? localB->sinus_lambda_k_size[1] : localB->d_size[1]) == 1 ?
        localB->cos2PHI_k_size[1] : localB->d_size[1] == 1 ?
        localB->sinus_lambda_k_size[1] : localB->d_size[1])) && (sv_pos_size[0] ==
       Ephemeris_OMEGADOT_size[1]) && ((((localB->cosinus_u_k_size[1] == 1 ?
          localB->t_k_size[1] : localB->cosinus_u_k_size[1]) == 1 ?
         localB->cosinus_i_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
         localB->cosinus_i_k_size[1] : localB->cosinus_u_k_size[1] == 1 ?
         localB->t_k_size[1] : localB->cosinus_u_k_size[1]) == 1 ?
        (localB->d_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
         localB->d_size[1]) == 1 ? localB->cos2PHI_k_size[1] : localB->d_size[1]
        == 1 ? localB->sinus_lambda_k_size[1] : localB->d_size[1] :
        (localB->cosinus_u_k_size[1] == 1 ? localB->t_k_size[1] :
         localB->cosinus_u_k_size[1]) == 1 ? localB->cosinus_i_k_size[1] == 1 ?
        localB->sinus_lambda_k_size[1] : localB->cosinus_i_k_size[1] :
        localB->cosinus_u_k_size[1] == 1 ? localB->t_k_size[1] :
        localB->cosinus_u_k_size[1]) == (sv_pos_size[0] == 1 ?
        Ephemeris_OMEGADOT_size[1] : sv_pos_size[0]))) {
    localB->loop_ub_a = localB->cosinus_u_k_size[1];
    localB->scalarLB = (localB->cosinus_u_k_size[1] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->cosinus_u_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->t_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->cosinus_i_k_data[localB->t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&localB->sinus_lambda_k_data[localB->t_k_data_tmp]);
      tmp_1 = _mm_loadu_pd(&localB->d_data[localB->t_k_data_tmp]);
      tmp_2 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
      tmp = _mm_loadu_pd(&sv_pos_data[localB->t_k_data_tmp + sv_pos_size[0]]);
      tmp_0 = _mm_loadu_pd(&localB->f_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&sv_vel_data[localB->t_k_data_tmp], _mm_sub_pd(_mm_add_pd
        (_mm_sub_pd(_mm_mul_pd(tmp_6, tmp_4), _mm_mul_pd(tmp_5, tmp_3)),
         _mm_mul_pd(_mm_mul_pd(tmp_1, tmp_3), tmp_2)), _mm_mul_pd(tmp, tmp_0)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->sinus_lambda_k = localB->sinus_lambda_k_data[localB->t_k_data_tmp];
      sv_vel_data[localB->t_k_data_tmp] = ((localB->cosinus_u_k_data
        [localB->t_k_data_tmp] * localB->t_k_data[localB->t_k_data_tmp] -
        localB->cosinus_i_k_data[localB->t_k_data_tmp] * localB->sinus_lambda_k)
        + localB->d_data[localB->t_k_data_tmp] * localB->sinus_lambda_k *
        localB->cos2PHI_k_data[localB->t_k_data_tmp]) - sv_pos_data
        [localB->t_k_data_tmp + sv_pos_size[0]] * localB->f_data
        [localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_binary_expand_op_hnvylq(sv_vel_data, localB->cosinus_u_k_data,
      localB->cosinus_u_k_size, localB->t_k_data, localB->t_k_size,
      localB->cosinus_i_k_data, localB->cosinus_i_k_size,
      localB->sinus_lambda_k_data, localB->sinus_lambda_k_size, localB->d_data,
      localB->d_size, localB->cos2PHI_k_data, localB->cos2PHI_k_size,
      sv_pos_data, sv_pos_size, localB->f_data, localB->f_size, localB);
  }

  if ((localB->cosinus_u_k_size[1] == localB->sinus_lambda_k_size[1]) &&
      (localB->cosinus_i_k_size[1] == localB->t_k_size[1]) &&
      ((localB->cosinus_u_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
        localB->cosinus_u_k_size[1]) == (localB->cosinus_i_k_size[1] == 1 ?
        localB->t_k_size[1] : localB->cosinus_i_k_size[1])) && (localB->d_size[1]
       == localB->t_k_size[1]) && ((localB->d_size[1] == 1 ? localB->t_k_size[1]
        : localB->d_size[1]) == localB->cos2PHI_k_size[1]) &&
      (((localB->cosinus_u_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
         localB->cosinus_u_k_size[1]) == 1 ? localB->cosinus_i_k_size[1] == 1 ?
        localB->t_k_size[1] : localB->cosinus_i_k_size[1] :
        localB->cosinus_u_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
        localB->cosinus_u_k_size[1]) == ((localB->d_size[1] == 1 ?
         localB->t_k_size[1] : localB->d_size[1]) == 1 ? localB->cos2PHI_k_size
        [1] : localB->d_size[1] == 1 ? localB->t_k_size[1] : localB->d_size[1]))
      && (sv_pos_size[0] == Ephemeris_OMEGADOT_size[1]) &&
      ((((localB->cosinus_u_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
          localB->cosinus_u_k_size[1]) == 1 ? localB->cosinus_i_k_size[1] == 1 ?
         localB->t_k_size[1] : localB->cosinus_i_k_size[1] :
         localB->cosinus_u_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
         localB->cosinus_u_k_size[1]) == 1 ? (localB->d_size[1] == 1 ?
         localB->t_k_size[1] : localB->d_size[1]) == 1 ? localB->cos2PHI_k_size
        [1] : localB->d_size[1] == 1 ? localB->t_k_size[1] : localB->d_size[1] :
        (localB->cosinus_u_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
         localB->cosinus_u_k_size[1]) == 1 ? localB->cosinus_i_k_size[1] == 1 ?
        localB->t_k_size[1] : localB->cosinus_i_k_size[1] :
        localB->cosinus_u_k_size[1] == 1 ? localB->sinus_lambda_k_size[1] :
        localB->cosinus_u_k_size[1]) == (sv_pos_size[0] == 1 ?
        Ephemeris_OMEGADOT_size[1] : sv_pos_size[0]))) {
    localB->loop_ub_a = sv_vel_size[0];
    localB->scalarLB = (sv_vel_size[0] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->cosinus_u_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->sinus_lambda_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->cosinus_i_k_data[localB->t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&localB->t_k_data[localB->t_k_data_tmp]);
      tmp_1 = _mm_loadu_pd(&localB->d_data[localB->t_k_data_tmp]);
      tmp_2 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
      tmp = _mm_loadu_pd(&sv_pos_data[localB->t_k_data_tmp]);
      tmp_0 = _mm_loadu_pd(&localB->f_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&sv_vel_data[localB->t_k_data_tmp + sv_vel_size[0]],
                    _mm_add_pd(_mm_sub_pd(_mm_add_pd(_mm_mul_pd(tmp_6, tmp_4),
        _mm_mul_pd(tmp_5, tmp_3)), _mm_mul_pd(_mm_mul_pd(tmp_1, tmp_3), tmp_2)),
        _mm_mul_pd(tmp, tmp_0)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      localB->sinus_lambda_k = localB->t_k_data[localB->t_k_data_tmp];
      sv_vel_data[localB->t_k_data_tmp + sv_vel_size[0]] =
        ((localB->cosinus_u_k_data[localB->t_k_data_tmp] *
          localB->sinus_lambda_k_data[localB->t_k_data_tmp] +
          localB->cosinus_i_k_data[localB->t_k_data_tmp] *
          localB->sinus_lambda_k) - localB->d_data[localB->t_k_data_tmp] *
         localB->sinus_lambda_k * localB->cos2PHI_k_data[localB->t_k_data_tmp])
        + sv_pos_data[localB->t_k_data_tmp] * localB->f_data
        [localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_binary_expand_op_hnvyl(sv_vel_data, sv_vel_size,
      localB->cosinus_u_k_data, localB->cosinus_u_k_size,
      localB->sinus_lambda_k_data, localB->sinus_lambda_k_size,
      localB->cosinus_i_k_data, localB->cosinus_i_k_size, localB->t_k_data,
      localB->t_k_size, localB->d_data, localB->d_size, localB->cos2PHI_k_data,
      localB->cos2PHI_k_size, sv_pos_data, sv_pos_size, localB->f_data,
      localB->f_size, localB);
  }

  if ((localB->sinus_E_k_size[1] == localB->i_k_size[1]) && (localB->c_size[1] ==
       localB->cos2PHI_k_size[1]) && ((localB->sinus_E_k_size[1] == 1 ?
        localB->i_k_size[1] : localB->sinus_E_k_size[1]) == (localB->c_size[1] ==
        1 ? localB->cos2PHI_k_size[1] : localB->c_size[1]))) {
    localB->loop_ub_a = sv_vel_size[0];
    localB->scalarLB = (sv_vel_size[0] / 2) << 1;
    localB->vectorUB = localB->scalarLB - 2;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->sinus_E_k_data[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->i_k_data[localB->t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&localB->c_data[localB->t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&localB->cos2PHI_k_data[localB->t_k_data_tmp]);
      _mm_storeu_pd(&sv_vel_data[localB->t_k_data_tmp + (sv_vel_size[0] << 1)],
                    _mm_add_pd(_mm_mul_pd(tmp_6, tmp_4), _mm_mul_pd(tmp_5, tmp_3)));
    }

    for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
         localB->loop_ub_a; localB->t_k_data_tmp++) {
      sv_vel_data[localB->t_k_data_tmp + (sv_vel_size[0] << 1)] =
        localB->sinus_E_k_data[localB->t_k_data_tmp] * localB->i_k_data
        [localB->t_k_data_tmp] + localB->c_data[localB->t_k_data_tmp] *
        localB->cos2PHI_k_data[localB->t_k_data_tmp];
    }
  } else {
    DDRTCM_binary_expand_op_hnvy(sv_vel_data, sv_vel_size,
      localB->sinus_E_k_data, localB->sinus_E_k_size, localB->i_k_data,
      localB->i_k_size, localB->c_data, localB->c_size, localB->cos2PHI_k_data,
      localB->cos2PHI_k_size);
  }

  localB->sinus_lambda_k = std::cos(user_position[0]);
  localB->N = 6.3995936257584924E+6 / std::sqrt(localB->sinus_lambda_k *
    localB->sinus_lambda_k * 0.0067394967422761756 + 1.0);
  localB->sinus_lambda_k = (localB->N + user_position[2]) *
    localB->sinus_lambda_k * std::cos(user_position[1]);
  localB->y_user = (localB->N + user_position[2]) * std::cos(user_position[0]) *
    std::sin(user_position[1]);
  localB->z_user = (0.99330562000985889 * localB->N + user_position[2]) * std::
    sin(user_position[0]);
  localB->scalarLB_tmp = (sv_pos_size[0] / 2) << 1;
  localB->vectorUB = localB->scalarLB_tmp - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&sv_pos_data[localB->t_k_data_tmp]);
    tmp_6 = _mm_sub_pd(tmp_6, _mm_set1_pd(localB->sinus_lambda_k));
    _mm_storeu_pd(&localB->t_k_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6,
      tmp_6));
  }

  localB->vectorUB = localB->scalarLB_tmp - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&sv_pos_data[(sv_pos_size[0] << 1) +
                         localB->t_k_data_tmp]);
    tmp_6 = _mm_sub_pd(tmp_6, _mm_set1_pd(localB->z_user));
    _mm_storeu_pd(&localB->t_k_data[localB->t_k_data_tmp], _mm_mul_pd(tmp_6,
      tmp_6));
  }

  localB->transport_angle_size = sv_pos_size[0];
  localB->loop_ub_a = sv_pos_size[0];
  localB->vectorUB = localB->scalarLB_tmp - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&sv_pos_data[localB->t_k_data_tmp]);
    tmp_6 = _mm_sub_pd(tmp_6, _mm_set1_pd(localB->sinus_lambda_k));
    tmp_4 = _mm_loadu_pd(&sv_pos_data[localB->t_k_data_tmp + sv_pos_size[0]]);
    tmp_4 = _mm_sub_pd(tmp_4, _mm_set1_pd(localB->y_user));
    tmp_5 = _mm_loadu_pd(&sv_pos_data[(sv_pos_size[0] << 1) +
                         localB->t_k_data_tmp]);
    tmp_5 = _mm_sub_pd(tmp_5, _mm_set1_pd(localB->z_user));
    _mm_storeu_pd(&localB->t_k_data[localB->t_k_data_tmp], _mm_add_pd(_mm_add_pd
      (_mm_mul_pd(tmp_6, tmp_6), _mm_mul_pd(tmp_4, tmp_4)), _mm_mul_pd(tmp_5,
      tmp_5)));
  }

  for (localB->t_k_data_tmp = localB->scalarLB_tmp; localB->t_k_data_tmp <
       localB->loop_ub_a; localB->t_k_data_tmp++) {
    localB->N = sv_pos_data[localB->t_k_data_tmp] - localB->sinus_lambda_k;
    localB->varargin_1 = sv_pos_data[localB->t_k_data_tmp + sv_pos_size[0]] -
      localB->y_user;
    localB->varargin_1_f = sv_pos_data[(sv_pos_size[0] << 1) +
      localB->t_k_data_tmp] - localB->z_user;
    localB->t_k_data[localB->t_k_data_tmp] = (localB->N * localB->N +
      localB->varargin_1 * localB->varargin_1) + localB->varargin_1_f *
      localB->varargin_1_f;
  }

  DDRTCM_sqrt_g(localB->t_k_data, &localB->transport_angle_size, localB);
  localB->loop_ub_a = localB->transport_angle_size;
  localB->scalarLB = (localB->transport_angle_size / 2) << 1;
  localB->vectorUB = localB->scalarLB - 2;
  for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= localB->vectorUB;
       localB->t_k_data_tmp += 2) {
    tmp_6 = _mm_loadu_pd(&localB->t_k_data[localB->t_k_data_tmp]);
    _mm_storeu_pd(&localB->t_k_data[localB->t_k_data_tmp], _mm_mul_pd(_mm_div_pd
      (tmp_6, _mm_set1_pd(2.99792458E+8)), _mm_set1_pd(-7.2921151467E-5)));
  }

  for (localB->t_k_data_tmp = localB->scalarLB; localB->t_k_data_tmp <
       localB->loop_ub_a; localB->t_k_data_tmp++) {
    localB->t_k_data[localB->t_k_data_tmp] = localB->t_k_data
      [localB->t_k_data_tmp] / 2.99792458E+8 * -7.2921151467E-5;
  }

  localB->scalarLB = sv_pos_size[0];
  if (sv_pos_size[0] - 1 >= 0) {
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

  for (localB->vectorUB = 0; localB->vectorUB < localB->scalarLB;
       localB->vectorUB++) {
    localB->sinus_lambda_k = localB->t_k_data[localB->vectorUB];
    localB->y_user = std::sin(-localB->sinus_lambda_k);
    localB->N = std::cos(-localB->sinus_lambda_k);
    localB->sv_pos_tmp[0] = localB->N;
    localB->sv_pos_tmp[3] = localB->y_user;
    localB->sv_pos_tmp[1] = -localB->y_user;
    localB->sv_pos_tmp[4] = localB->N;
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= 0;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->sv_pos_tmp[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->sv_pos_tmp[localB->t_k_data_tmp + 3]);
      tmp_5 = _mm_loadu_pd(&localB->sv_pos_tmp[localB->t_k_data_tmp + 6]);
      _mm_storeu_pd(&localB->sv_pos_tmp_j[localB->t_k_data_tmp], _mm_add_pd
                    (_mm_mul_pd(tmp_5, _mm_set1_pd(sv_pos_data[localB->vectorUB
        + (sv_pos_size[0] << 1)])), _mm_add_pd(_mm_mul_pd(tmp_4, _mm_set1_pd
        (sv_pos_data[localB->vectorUB + sv_pos_size[0]])), _mm_add_pd(_mm_mul_pd
        (tmp_6, _mm_set1_pd(sv_pos_data[localB->vectorUB])), _mm_set1_pd(0.0)))));
    }

    for (localB->t_k_data_tmp = 2; localB->t_k_data_tmp < 3;
         localB->t_k_data_tmp++) {
      localB->sv_pos_tmp_j[localB->t_k_data_tmp] = sv_pos_data[(sv_pos_size[0] <<
        1) + localB->vectorUB] * localB->sv_pos_tmp[localB->t_k_data_tmp + 6] +
        (localB->sv_pos_tmp[localB->t_k_data_tmp + 3] * sv_pos_data
         [localB->vectorUB + sv_pos_size[0]] + localB->sv_pos_tmp
         [localB->t_k_data_tmp] * sv_pos_data[localB->vectorUB]);
    }

    localB->dv[0] = localB->N;
    localB->dv[3] = localB->y_user;
    localB->dv[1] = -std::sin(-localB->sinus_lambda_k);
    localB->dv[4] = localB->N;
    sv_pos_data[localB->vectorUB] = localB->sv_pos_tmp_j[0];
    sv_pos_data[localB->vectorUB + sv_pos_size[0]] = localB->sv_pos_tmp_j[1];
    sv_pos_data[localB->vectorUB + (sv_pos_size[0] << 1)] = localB->
      sv_pos_tmp_j[2];
    for (localB->t_k_data_tmp = 0; localB->t_k_data_tmp <= 0;
         localB->t_k_data_tmp += 2) {
      tmp_6 = _mm_loadu_pd(&localB->dv[localB->t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&localB->dv[localB->t_k_data_tmp + 3]);
      tmp_5 = _mm_loadu_pd(&localB->dv[localB->t_k_data_tmp + 6]);
      _mm_storeu_pd(&localB->sv_pos_tmp_j[localB->t_k_data_tmp], _mm_add_pd
                    (_mm_mul_pd(tmp_5, _mm_set1_pd(sv_vel_data[localB->vectorUB
        + (sv_vel_size[0] << 1)])), _mm_add_pd(_mm_mul_pd(tmp_4, _mm_set1_pd
        (sv_vel_data[localB->vectorUB + sv_vel_size[0]])), _mm_add_pd(_mm_mul_pd
        (tmp_6, _mm_set1_pd(sv_vel_data[localB->vectorUB])), _mm_set1_pd(0.0)))));
    }

    for (localB->t_k_data_tmp = 2; localB->t_k_data_tmp < 3;
         localB->t_k_data_tmp++) {
      localB->sv_pos_tmp_j[localB->t_k_data_tmp] = sv_vel_data[(sv_vel_size[0] <<
        1) + localB->vectorUB] * localB->dv[localB->t_k_data_tmp + 6] +
        (localB->dv[localB->t_k_data_tmp + 3] * sv_vel_data[localB->vectorUB +
         sv_vel_size[0]] + localB->dv[localB->t_k_data_tmp] * sv_vel_data
         [localB->vectorUB]);
    }

    sv_vel_data[localB->vectorUB] = localB->sv_pos_tmp_j[0];
    sv_vel_data[localB->vectorUB + sv_vel_size[0]] = localB->sv_pos_tmp_j[1];
    sv_vel_data[localB->vectorUB + (sv_vel_size[0] << 1)] = localB->
      sv_pos_tmp_j[2];
  }
}

void DDRTCM::DDRTCM_binary_expand_op_h(real_T in1_data[], int32_T in1_size[2],
  const real_T in2_data[], const int32_T in2_size[2], const real_T in3[330],
  const gnssops_navigation_data *in4, const gnssops_navigation_data_size *in5)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in1_size[0] = in5->SVID == 1 ? in2_size[0] : in5->SVID;
  in1_size[1] = 3;
  stride_0_0 = (in2_size[0] != 1);
  stride_1_0 = (in5->SVID != 1);
  loop_ub = in5->SVID == 1 ? in2_size[0] : in5->SVID;
  for (int32_T i_0{0}; i_0 < 3; i_0++) {
    for (int32_T i{0}; i < loop_ub; i++) {
      in1_data[i + in1_size[0] * i_0] = in3[(static_cast<int32_T>(in4->SVID[i *
        stride_1_0]) + 110 * i_0) - 1] + in2_data[i * stride_0_0 + in2_size[0] *
        i_0];
    }
  }
}

//
// Output and update for atomic system:
//    '<S31>/Calculate Satellite Position and Velocity'
//    '<S39>/Calculate Satellite Position and Velocity'
//    '<S47>/Calculate Satellite Position and Velocity'
//    '<S80>/Calculate Satellite Position and Velocity'
//    '<S88>/Calculate Satellite Position and Velocity'
//    '<S96>/Calculate Satellite Position and Velocity'
//    '<S104>/Calculate Satellite Position and Velocity'
//    '<S158>/Calculate Satellite Position and Velocity'
//    '<S166>/Calculate Satellite Position and Velocity'
//    '<S174>/Calculate Satellite Position and Velocity'
//    ...
//
void DDRTCM::CalculateSatellitePositionandVe(real_T rtu_enableSatPosVelCalc,
  const real_T rtu_userPosLlh[3], const gnssops_navigation_data *rtu_GnssNavBus,
  const gnssops_navigation_data_size *rtu_GnssNavBus_DIMS1, const real_T
  rtu_timeEmissionCorrected[40], const int32_T *rtu_timeEmissionCorrected_DIMS1,
  const real_T rtu_delta_satPosECEF_EGNOS[330], B_CalculateSatellitePositiona_T *
  localB, DW_CalculateSatellitePosition_T *localDW)
{
  if (rtu_enableSatPosVelCalc != 0.0) {
    localB->rtu_GnssNavBus_size[0] = 1;
    localB->rtu_GnssNavBus_size[1] = rtu_GnssNavBus_DIMS1->C_rs;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->C_rs;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data[0], &rtu_GnssNavBus->C_rs[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_o[0] = 1;
    localB->rtu_GnssNavBus_size_o[1] = rtu_GnssNavBus_DIMS1->DELTA_N;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->DELTA_N;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_d[0], &rtu_GnssNavBus->DELTA_N[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_n[0] = 1;
    localB->rtu_GnssNavBus_size_n[1] = rtu_GnssNavBus_DIMS1->M_0;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->M_0;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_g[0], &rtu_GnssNavBus->M_0[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_i[0] = 1;
    localB->rtu_GnssNavBus_size_i[1] = rtu_GnssNavBus_DIMS1->C_uc;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->C_uc;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_l[0], &rtu_GnssNavBus->C_uc[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_oy[0] = 1;
    localB->rtu_GnssNavBus_size_oy[1] = rtu_GnssNavBus_DIMS1->E;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->E;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_dh[0], &rtu_GnssNavBus->E[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_nv[0] = 1;
    localB->rtu_GnssNavBus_size_nv[1] = rtu_GnssNavBus_DIMS1->C_us;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->C_us;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_dy[0], &rtu_GnssNavBus->C_us[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_m[0] = 1;
    localB->rtu_GnssNavBus_size_m[1] = rtu_GnssNavBus_DIMS1->SQRT_A;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->SQRT_A;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_lx[0], &rtu_GnssNavBus->SQRT_A[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_c[0] = 1;
    localB->rtu_GnssNavBus_size_c[1] = rtu_GnssNavBus_DIMS1->T_oe;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->T_oe;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_o[0], &rtu_GnssNavBus->T_oe[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_md[0] = 1;
    localB->rtu_GnssNavBus_size_md[1] = rtu_GnssNavBus_DIMS1->C_ic;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->C_ic;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_b[0], &rtu_GnssNavBus->C_ic[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_m3[0] = 1;
    localB->rtu_GnssNavBus_size_m3[1] = rtu_GnssNavBus_DIMS1->OMEGA_0;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->OMEGA_0;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_n[0], &rtu_GnssNavBus->OMEGA_0[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_j[0] = 1;
    localB->rtu_GnssNavBus_size_j[1] = rtu_GnssNavBus_DIMS1->C_is;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->C_is;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_bs[0], &rtu_GnssNavBus->C_is[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_h[0] = 1;
    localB->rtu_GnssNavBus_size_h[1] = rtu_GnssNavBus_DIMS1->I_0;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->I_0;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_ln[0], &rtu_GnssNavBus->I_0[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_c0[0] = 1;
    localB->rtu_GnssNavBus_size_c0[1] = rtu_GnssNavBus_DIMS1->C_rc;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->C_rc;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_h[0], &rtu_GnssNavBus->C_rc[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_ct[0] = 1;
    localB->rtu_GnssNavBus_size_ct[1] = rtu_GnssNavBus_DIMS1->omega;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->omega;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_bn[0], &rtu_GnssNavBus->omega[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_p[0] = 1;
    localB->rtu_GnssNavBus_size_p[1] = rtu_GnssNavBus_DIMS1->OMEGADOT;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->OMEGADOT;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_da[0], &rtu_GnssNavBus->OMEGADOT
                  [0], static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_GnssNavBus_size_p5[0] = 1;
    localB->rtu_GnssNavBus_size_p5[1] = rtu_GnssNavBus_DIMS1->IDOT;
    localB->loop_ub = rtu_GnssNavBus_DIMS1->IDOT;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->rtu_GnssNavBus_data_e[0], &rtu_GnssNavBus->IDOT[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    localB->rtu_timeEmissionCorrected_size[0] = 1;
    localB->rtu_timeEmissionCorrected_size[1] = *rtu_timeEmissionCorrected_DIMS1;
    for (localB->i = 0; localB->i < *rtu_timeEmissionCorrected_DIMS1; localB->i
         ++) {
      localB->rtu_timeEmissionCorrected_data[localB->i] =
        rtu_timeEmissionCorrected[localB->i];
    }

    Get_Kepler_Satellite_Position_A(localB->rtu_GnssNavBus_data,
      localB->rtu_GnssNavBus_size, localB->rtu_GnssNavBus_data_d,
      localB->rtu_GnssNavBus_size_o, localB->rtu_GnssNavBus_data_g,
      localB->rtu_GnssNavBus_size_n, localB->rtu_GnssNavBus_data_l,
      localB->rtu_GnssNavBus_size_i, localB->rtu_GnssNavBus_data_dh,
      localB->rtu_GnssNavBus_size_oy, localB->rtu_GnssNavBus_data_dy,
      localB->rtu_GnssNavBus_size_nv, localB->rtu_GnssNavBus_data_lx,
      localB->rtu_GnssNavBus_size_m, localB->rtu_GnssNavBus_data_o,
      localB->rtu_GnssNavBus_size_c, localB->rtu_GnssNavBus_data_b,
      localB->rtu_GnssNavBus_size_md, localB->rtu_GnssNavBus_data_n,
      localB->rtu_GnssNavBus_size_m3, localB->rtu_GnssNavBus_data_bs,
      localB->rtu_GnssNavBus_size_j, localB->rtu_GnssNavBus_data_ln,
      localB->rtu_GnssNavBus_size_h, localB->rtu_GnssNavBus_data_h,
      localB->rtu_GnssNavBus_size_c0, localB->rtu_GnssNavBus_data_bn,
      localB->rtu_GnssNavBus_size_ct, localB->rtu_GnssNavBus_data_da,
      localB->rtu_GnssNavBus_size_p, localB->rtu_GnssNavBus_data_e,
      localB->rtu_GnssNavBus_size_p5, localB->rtu_timeEmissionCorrected_data,
      localB->rtu_timeEmissionCorrected_size, rtu_userPosLlh,
      localB->satPosEcef_data, localB->satPosEcef_size, localB->satVelEcef_data,
      localB->satVelEcef_size, localB);
    localDW->SFunction_DIMS3[0] = localB->satVelEcef_size[0];
    localDW->SFunction_DIMS3[1] = 3;
    localB->loop_ub = localB->satVelEcef_size[0] * 3;
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->satVelEcef[0], &localB->satVelEcef_data[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }

    if (localB->satPosEcef_size[0] == rtu_GnssNavBus_DIMS1->SVID) {
      localB->tmp_size[0] = localB->satPosEcef_size[0];
      localB->tmp_size[1] = 3;
      localB->loop_ub = localB->satPosEcef_size[0];
      for (localB->i = 0; localB->i < 3; localB->i++) {
        for (localB->loop_ub_tmp = 0; localB->loop_ub_tmp < localB->loop_ub;
             localB->loop_ub_tmp++) {
          localB->tmp_data[localB->loop_ub_tmp + localB->tmp_size[0] * localB->i]
            = rtu_delta_satPosECEF_EGNOS[(110 * localB->i + static_cast<int32_T>
            (rtu_GnssNavBus->SVID[localB->loop_ub_tmp])) - 1] +
            localB->satPosEcef_data[localB->satPosEcef_size[0] * localB->i +
            localB->loop_ub_tmp];
        }
      }
    } else {
      DDRTCM_binary_expand_op_h(localB->tmp_data, localB->tmp_size,
        localB->satPosEcef_data, localB->satPosEcef_size,
        rtu_delta_satPosECEF_EGNOS, rtu_GnssNavBus, rtu_GnssNavBus_DIMS1);
    }

    localDW->SFunction_DIMS2[0] = localB->tmp_size[0];
    localDW->SFunction_DIMS2[1] = localB->tmp_size[1];
    localB->loop_ub = localB->tmp_size[0] * localB->tmp_size[1];
    if (localB->loop_ub - 1 >= 0) {
      std::memcpy(&localB->satPosEcef[0], &localB->tmp_data[0],
                  static_cast<uint32_T>(localB->loop_ub) * sizeof(real_T));
    }
  } else {
    localDW->SFunction_DIMS2[0] = rtu_GnssNavBus_DIMS1->TOW;
    localDW->SFunction_DIMS2[1] = 3;
    localB->loop_ub_tmp = rtu_GnssNavBus_DIMS1->TOW * 3;
    localDW->SFunction_DIMS3[0] = rtu_GnssNavBus_DIMS1->TOW;
    localDW->SFunction_DIMS3[1] = 3;
    if (localB->loop_ub_tmp - 1 >= 0) {
      std::memset(&localB->satPosEcef[0], 0, static_cast<uint32_T>
                  (localB->loop_ub_tmp) * sizeof(real_T));
    }

    if (localB->loop_ub_tmp - 1 >= 0) {
      std::memset(&localB->satVelEcef[0], 0, static_cast<uint32_T>
                  (localB->loop_ub_tmp) * sizeof(real_T));
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
