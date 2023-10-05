//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateSatellitePositionandVe.cpp
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
#include "GNSSPreProcessingSingleAntenna_types.h"
#include "CalculateSatellitePositionandVe.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <cstring>
#include <emmintrin.h>
#include <cmath>
#include "GNSSPreProcessingSingleAntenna_private.h"

void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_minus_m(real_T
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

// Function for MATLAB Function: '<S26>/Calculate Satellite Position and Velocity'
void GNSS_preprocessingModelClass::correct_Gps_Time_At_Week_Crosso(real_T
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

void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAnt_plus(real_T
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

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_n2(real_T
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

void GNSS_preprocessingModelClass::GNSSPreProce_binary_expand_op_o(real_T
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

void GNSS_preprocessingModelClass::GNSSPreProce_binary_expand_op_c(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
  real_T in2_data_0[40];
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
    in2_data_0[i] = in2_data[i * stride_0_1] / (1.0 - in3_data[i * stride_1_1] *
      in1_data[i * stride_2_1]);
  }

  in1_size[0] = 1;
  in1_size[1] = in2_size_idx_1;
  if (in2_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in2_data_0[0], static_cast<uint32_T>
                (in2_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_az(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
  real_T in2_data_0[40];
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

void GNSS_preprocessingModelClass::GNSSPreProcessingSingl_minus_m5(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2])
{
  real_T in2_data_0[40];
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

// Function for MATLAB Function: '<S26>/Calculate Satellite Position and Velocity'
void GNSS_preprocessingModelClass::GN_Get_Kepler_Eccentric_Anomaly(const real_T
  t_k_data[], const int32_T t_k_size[2], const real_T Ephemeris_DELTA_N_data[],
  const int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[],
  const int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_E_data[], const
  int32_T Ephemeris_E_size[2], const real_T Ephemeris_SQRT_A_data[], const
  int32_T Ephemeris_SQRT_A_size[2], real_T E_k_data[], int32_T E_k_size[2],
  real_T E_k_Dot_data[], int32_T E_k_Dot_size[2])
{
  __m128d tmp;
  __m128d tmp_0;
  real_T E_k_old_data[40];
  real_T M_k_data[40];
  real_T eps_data[40];
  real_T n_0_data[37];
  real_T varargin_1;
  int32_T E_k_old_size[2];
  int32_T M_k_size[2];
  int32_T n_0_size[2];
  int32_T eps_size_idx_1;
  int32_T i;
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T vectorUB;
  boolean_T x_data[40];
  n_0_size[0] = 1;
  n_0_size[1] = Ephemeris_SQRT_A_size[1];
  loop_ub = Ephemeris_SQRT_A_size[1];
  for (int32_T varargin_1_tmp{0}; varargin_1_tmp < loop_ub; varargin_1_tmp++) {
    varargin_1 = Ephemeris_SQRT_A_data[varargin_1_tmp];
    n_0_data[varargin_1_tmp] = 3.986005E+14 / rt_powd_snf(varargin_1 *
      varargin_1, 3.0);
  }

  i = Ephemeris_SQRT_A_size[1];
  scalarLB = (Ephemeris_SQRT_A_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (loop_ub = 0; loop_ub <= vectorUB; loop_ub += 2) {
    tmp_0 = _mm_loadu_pd(&n_0_data[loop_ub]);
    _mm_storeu_pd(&n_0_data[loop_ub], _mm_sqrt_pd(tmp_0));
  }

  for (loop_ub = scalarLB; loop_ub < i; loop_ub++) {
    n_0_data[loop_ub] = std::sqrt(n_0_data[loop_ub]);
  }

  if (Ephemeris_SQRT_A_size[1] == Ephemeris_DELTA_N_size[1]) {
    loop_ub = Ephemeris_SQRT_A_size[1] - 1;
    n_0_size[0] = 1;
    scalarLB = (Ephemeris_SQRT_A_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T varargin_1_tmp{0}; varargin_1_tmp <= vectorUB; varargin_1_tmp +=
         2) {
      tmp_0 = _mm_loadu_pd(&n_0_data[varargin_1_tmp]);
      _mm_storeu_pd(&n_0_data[varargin_1_tmp], _mm_add_pd(tmp_0, _mm_loadu_pd
        (&Ephemeris_DELTA_N_data[varargin_1_tmp])));
    }

    for (int32_T varargin_1_tmp{scalarLB}; varargin_1_tmp <= loop_ub;
         varargin_1_tmp++) {
      n_0_data[varargin_1_tmp] += Ephemeris_DELTA_N_data[varargin_1_tmp];
    }
  } else {
    GNSSPreProcessingSingleAnt_plus(n_0_data, n_0_size, Ephemeris_DELTA_N_data,
      Ephemeris_DELTA_N_size);
  }

  if ((n_0_size[1] == t_k_size[1]) && ((n_0_size[1] == 1 ? t_k_size[1] :
        n_0_size[1]) == Ephemeris_M_0_size[1])) {
    M_k_size[0] = 1;
    M_k_size[1] = Ephemeris_M_0_size[1];
    loop_ub = Ephemeris_M_0_size[1];
    scalarLB = (Ephemeris_M_0_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T varargin_1_tmp{0}; varargin_1_tmp <= vectorUB; varargin_1_tmp +=
         2) {
      tmp_0 = _mm_loadu_pd(&n_0_data[varargin_1_tmp]);
      _mm_storeu_pd(&M_k_data[varargin_1_tmp], _mm_add_pd(_mm_mul_pd(tmp_0,
        _mm_loadu_pd(&t_k_data[varargin_1_tmp])), _mm_loadu_pd
        (&Ephemeris_M_0_data[varargin_1_tmp])));
    }

    for (int32_T varargin_1_tmp{scalarLB}; varargin_1_tmp < loop_ub;
         varargin_1_tmp++) {
      M_k_data[varargin_1_tmp] = n_0_data[varargin_1_tmp] *
        t_k_data[varargin_1_tmp] + Ephemeris_M_0_data[varargin_1_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_n2(M_k_data, M_k_size, Ephemeris_M_0_data,
      Ephemeris_M_0_size, n_0_data, n_0_size, t_k_data, t_k_size);
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
    GNSSPreProce_binary_expand_op_o(E_k_data, E_k_size, Ephemeris_E_data,
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
    boolean_T exitg2;
    boolean_T y;
    exitg1 = 0;
    for (int32_T varargin_1_tmp{0}; varargin_1_tmp < eps_size_idx_1;
         varargin_1_tmp++) {
      x_data[varargin_1_tmp] = (eps_data[varargin_1_tmp] > 1.0E-15);
    }

    y = false;
    scalarLB = 1;
    exitg2 = false;
    while ((!exitg2) && (scalarLB <= eps_size_idx_1)) {
      if (x_data[scalarLB - 1]) {
        y = true;
        exitg2 = true;
      } else {
        scalarLB++;
      }
    }

    if (y && (i < 20)) {
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
        GNSSPreProc_binary_expand_op_az(E_k_data, E_k_size, M_k_data, M_k_size,
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
        GNSSPreProcessingSingl_minus_m5(E_k_old_data, E_k_old_size, E_k_data,
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

  E_k_Dot_size[0] = 1;
  E_k_Dot_size[1] = E_k_size[1];
  loop_ub = E_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&E_k_Dot_data[0], &E_k_data[0], static_cast<uint32_T>(loop_ub) *
                sizeof(real_T));
  }

  i = E_k_size[1];
  for (scalarLB = 0; scalarLB < i; scalarLB++) {
    E_k_Dot_data[scalarLB] = std::cos(E_k_Dot_data[scalarLB]);
  }

  if ((Ephemeris_E_size[1] == E_k_size[1]) && ((Ephemeris_E_size[1] == 1 ?
        E_k_size[1] : Ephemeris_E_size[1]) == n_0_size[1])) {
    loop_ub = n_0_size[1] - 1;
    E_k_Dot_size[0] = 1;
    E_k_Dot_size[1] = n_0_size[1];
    scalarLB = (n_0_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T varargin_1_tmp{0}; varargin_1_tmp <= vectorUB; varargin_1_tmp +=
         2) {
      tmp_0 = _mm_loadu_pd(&E_k_Dot_data[varargin_1_tmp]);
      tmp = _mm_loadu_pd(&n_0_data[varargin_1_tmp]);
      _mm_storeu_pd(&E_k_Dot_data[varargin_1_tmp], _mm_div_pd(tmp, _mm_sub_pd
        (_mm_set1_pd(1.0), _mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_E_data[varargin_1_tmp]), tmp_0))));
    }

    for (int32_T varargin_1_tmp{scalarLB}; varargin_1_tmp <= loop_ub;
         varargin_1_tmp++) {
      E_k_Dot_data[varargin_1_tmp] = n_0_data[varargin_1_tmp] / (1.0 -
        Ephemeris_E_data[varargin_1_tmp] * E_k_Dot_data[varargin_1_tmp]);
    }
  } else {
    GNSSPreProce_binary_expand_op_c(E_k_Dot_data, E_k_Dot_size, n_0_data,
      n_0_size, Ephemeris_E_data, Ephemeris_E_size);
  }
}

// Function for MATLAB Function: '<S26>/Calculate Satellite Position and Velocity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAnte_cos(real_T
  x_data[], const int32_T x_size[2])
{
  int32_T b;
  b = x_size[1];
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::cos(x_data[k]);
  }
}

// Function for MATLAB Function: '<S26>/Calculate Satellite Position and Velocity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAnte_sin(real_T
  x_data[], const int32_T x_size[2])
{
  int32_T b;
  b = x_size[1];
  for (int32_T k{0}; k < b; k++) {
    x_data[k] = std::sin(x_data[k]);
  }
}

void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_times_a(real_T
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

// Function for MATLAB Function: '<S26>/Calculate Satellite Position and Velocity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAnt_sqrt(real_T
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

// Function for MATLAB Function: '<S26>/Calculate Satellite Position and Velocity'
void GNSS_preprocessingModelClass::GNSSPreProcessingS_expand_atan2(const real_T
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

// Function for MATLAB Function: '<S26>/Calculate Satellite Position and Velocity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_atan2(const real_T
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
    GNSSPreProcessingS_expand_atan2(y_data, y_size, x_data, x_size, r_data,
      r_size);
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_ar(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2])
{
  real_T in2_data_0[40];
  real_T in5_data_0[40];
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

  GNSSPreProcessingSingleAn_atan2(in2_data_0, in2_size_0, in5_data_0, in5_size_0,
    in1_data, in1_size);
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_a3(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2])
{
  real_T in1_data_0[40];
  real_T in2_data_0[40];
  real_T tmp_data[40];
  int32_T in1_size_0[2];
  int32_T in2_size_0[2];
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

  in1_size_0[0] = 1;
  in1_size_0[1] = in4_size[1] == 1 ? in5_size[1] == 1 ? in1_size[1] : in5_size[1]
    : in4_size[1];
  stride_0_1 = (in1_size[1] != 1);
  stride_1_1 = (in5_size[1] != 1);
  stride_2_1 = (in4_size[1] != 1);
  loop_ub = in4_size[1] == 1 ? in5_size[1] == 1 ? in1_size[1] : in5_size[1] :
    in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data_0[i] = (in1_data[i * stride_0_1] - in5_data[i * stride_1_1]) /
      in4_data[i * stride_2_1];
  }

  GNSSPreProcessingSingleAn_atan2(in2_data_0, in2_size_0, in1_data_0, in1_size_0,
    tmp_data, tmp_size);
  in1_size[0] = 1;
  in1_size[1] = in6_size[1] == 1 ? tmp_size[1] : in6_size[1];
  stride_0_1 = (tmp_size[1] != 1);
  stride_1_1 = (in6_size[1] != 1);
  loop_ub = in6_size[1] == 1 ? tmp_size[1] : in6_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = tmp_data[i * stride_0_1] + in6_data[i * stride_1_1];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProce_binary_expand_op_f(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2])
{
  real_T in1_data_0[40];
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

void GNSS_preprocessingModelClass::GNSSPreProce_binary_expand_op_n(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2])
{
  real_T tmp_data[40];
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  int32_T stride_4_1;
  int32_T stride_5_1;
  int32_T tmp_size_idx_1;
  tmp_size_idx_1 = ((in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ?
                    in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in6_size[1] ==
                    1 ? in5_size[1] : in6_size[1]) == 1 ? in1_size[1] == 1 ?
    in2_size[1] : in1_size[1] : (in6_size[1] == 1 ? in5_size[1] : in6_size[1]) ==
    1 ? in4_size[1] == 1 ? in3_size[1] : in4_size[1] : in6_size[1] == 1 ?
    in5_size[1] : in6_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  stride_2_1 = (in3_size[1] != 1);
  stride_3_1 = (in4_size[1] != 1);
  stride_4_1 = (in5_size[1] != 1);
  stride_5_1 = (in6_size[1] != 1);
  loop_ub = ((in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ? in4_size[1] ==
             1 ? in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1] :
             in6_size[1]) == 1 ? in1_size[1] == 1 ? in2_size[1] : in1_size[1] :
    (in6_size[1] == 1 ? in5_size[1] : in6_size[1]) == 1 ? in4_size[1] == 1 ?
    in3_size[1] : in4_size[1] : in6_size[1] == 1 ? in5_size[1] : in6_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = in2_data[i * stride_0_1];
    tmp_data[i] = (1.0 - in1_data[i * stride_1_1]) * (varargin_1 * varargin_1) +
      (in3_data[i * stride_2_1] * in4_data[i * stride_3_1] + in5_data[i *
       stride_4_1] * in6_data[i * stride_5_1]);
  }

  in1_size[0] = 1;
  in1_size[1] = tmp_size_idx_1;
  if (tmp_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &tmp_data[0], static_cast<uint32_T>(tmp_size_idx_1)
                * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSSPreProce_binary_expand_op_e(real_T
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

void GNSS_preprocessingModelClass::binary_expand_o_ar5npdcmtcc01ob(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2])
{
  real_T in2_data_0[40];
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

void GNSS_preprocessingModelClass::GNSSPreProcessingSingl_times_ax(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2])
{
  real_T in1_data_0[40];
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

void GNSS_preprocessingModelClass::binary_expand_op_ar5npdcmtcc01o(real_T
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

void GNSS_preprocessingModelClass::binary_expand_op_ar5npdcmtcc01(real_T
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

void GNSS_preprocessingModelClass::G_binary_expand_op_ar5npdcmtcc0(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
  real_T in2_data_0[40];
  int32_T in2_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  in2_size_idx_1 = in1_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size
    [1] : in1_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  stride_2_1 = (in1_size[1] != 1);
  loop_ub = in1_size[1] == 1 ? in3_size[1] == 1 ? in2_size[1] : in3_size[1] :
    in1_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in2_data_0[i] = in2_data[i * stride_0_1] * in3_data[i * stride_1_1] /
      in1_data[i * stride_2_1];
  }

  in1_size[0] = 1;
  in1_size[1] = in2_size_idx_1;
  if (in2_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in2_data_0[0], static_cast<uint32_T>
                (in2_size_idx_1) * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GN_binary_expand_op_ar5npdcmtcc(real_T
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

void GNSS_preprocessingModelClass::GNS_binary_expand_op_ar5npdcmtc(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const real_T
  in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
  in8_size[2], const real_T in9_data[], const int32_T in9_size[2])
{
  real_T tmp_data[40];
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
  int32_T tmp_size_idx_1;
  tmp_size_idx_1 = (in9_size[1] == 1 ? in1_size[1] == 1 ? in8_size[1] == 1 ?
                    in7_size[1] : in8_size[1] : in1_size[1] : in9_size[1]) == 1 ?
    in6_size[1] == 1 ? (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ?
    in3_size[1] == 1 ? in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1]
    : in5_size[1] : in6_size[1] : in9_size[1] == 1 ? in1_size[1] == 1 ?
    in8_size[1] == 1 ? in7_size[1] : in8_size[1] : in1_size[1] : in9_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in3_size[1] != 1);
  stride_2_1 = (in4_size[1] != 1);
  stride_3_1 = (in5_size[1] != 1);
  stride_4_1 = (in6_size[1] != 1);
  stride_5_1 = (in7_size[1] != 1);
  stride_6_1 = (in8_size[1] != 1);
  stride_7_1 = (in1_size[1] != 1);
  stride_8_1 = (in9_size[1] != 1);
  loop_ub = (in9_size[1] == 1 ? in1_size[1] == 1 ? in8_size[1] == 1 ? in7_size[1]
             : in8_size[1] : in1_size[1] : in9_size[1]) == 1 ? in6_size[1] == 1 ?
    (in5_size[1] == 1 ? in4_size[1] : in5_size[1]) == 1 ? in3_size[1] == 1 ?
    in2_size[1] : in3_size[1] : in5_size[1] == 1 ? in4_size[1] : in5_size[1] :
    in6_size[1] : in9_size[1] == 1 ? in1_size[1] == 1 ? in8_size[1] == 1 ?
    in7_size[1] : in8_size[1] : in1_size[1] : in9_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = in7_data[i * stride_5_1];
    tmp_data[i] = (in2_data[i * stride_0_1] * in3_data[i * stride_1_1] -
                   in4_data[i * stride_2_1] * in5_data[i * stride_3_1]) * 2.0 *
      in6_data[i * stride_4_1] + varargin_1 * varargin_1 * in8_data[i *
      stride_6_1] * in1_data[i * stride_7_1] * in9_data[i * stride_8_1];
  }

  in1_size[0] = 1;
  in1_size[1] = tmp_size_idx_1;
  if (tmp_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &tmp_data[0], static_cast<uint32_T>(tmp_size_idx_1)
                * sizeof(real_T));
  }
}

void GNSS_preprocessingModelClass::GNSS_binary_expand_op_ar5npdcmt(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T
  in5_size[2], const real_T in6_data[], const int32_T in6_size[2])
{
  real_T tmp_data[40];
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

void GNSS_preprocessingModelClass::GNSSP_binary_expand_op_ar5npdcm(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2])
{
  real_T in2_data_0[40];
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

void GNSS_preprocessingModelClass::GNSSPr_binary_expand_op_ar5npdc(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T
  in4_data[], const int32_T in4_size[2])
{
  real_T in1_data_0[40];
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

void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_times(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2])
{
  real_T in2_data_0[40];
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

void GNSS_preprocessingModelClass::GNSSPre_binary_expand_op_ar5npd(real_T
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

void GNSS_preprocessingModelClass::GNSSPreP_binary_expand_op_ar5np(real_T
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

void GNSS_preprocessingModelClass::GNSSPrePr_binary_expand_op_ar5n(real_T
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

// Function for MATLAB Function: '<S26>/Calculate Satellite Position and Velocity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_sqrt_g(real_T
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

// Function for MATLAB Function: '<S26>/Calculate Satellite Position and Velocity'
void GNSS_preprocessingModelClass::Get_Kepler_Satellite_Position_A(const real_T
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
  real_T E_k_Dot_data[40];
  real_T PHI_k_Dot_data[40];
  real_T X_k_tmp_data[40];
  real_T c_data[40];
  real_T cos2PHI_k_data[40];
  real_T cosinus_E_k_data[40];
  real_T cosinus_i_k_data[40];
  real_T cosinus_u_k_data[40];
  real_T d_data[40];
  real_T i_k_data[40];
  real_T r_k_data[40];
  real_T sin2PHI_k_data[40];
  real_T sinus_E_k_data[40];
  real_T sinus_lambda_k_data[40];
  real_T t_k_data[40];
  real_T u_k_Dot_data[40];
  real_T f_data[37];
  real_T g_data[37];
  real_T sv_pos_tmp[9];
  real_T tmp[9];
  real_T sv_pos_tmp_0[3];
  real_T N;
  real_T sinus_lambda_k;
  real_T y_user;
  real_T z_user;
  int32_T E_k_Dot_size[2];
  int32_T PHI_k_Dot_size[2];
  int32_T X_k_tmp_size[2];
  int32_T c_size[2];
  int32_T cos2PHI_k_size[2];
  int32_T cosinus_E_k_size[2];
  int32_T cosinus_i_k_size[2];
  int32_T cosinus_u_k_size[2];
  int32_T d_size[2];
  int32_T f_size[2];
  int32_T g_size[2];
  int32_T i_k_size[2];
  int32_T r_k_size[2];
  int32_T sin2PHI_k_size[2];
  int32_T sinus_E_k_size[2];
  int32_T sinus_lambda_k_size[2];
  int32_T t_k_size[2];
  int32_T u_k_Dot_size[2];
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
    GNSSPreProcessingSingle_minus_m(t_k_data, t_k_size, T_emission_data,
      T_emission_size, Ephemeris_T_oe_data, Ephemeris_T_oe_size);
  }

  correct_Gps_Time_At_Week_Crosso(t_k_data, t_k_size);
  GN_Get_Kepler_Eccentric_Anomaly(t_k_data, t_k_size, Ephemeris_DELTA_N_data,
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

  GNSSPreProcessingSingleAnte_cos(cosinus_E_k_data, cosinus_E_k_size);
  GNSSPreProcessingSingleAnte_sin(sinus_E_k_data, sinus_E_k_size);
  if (Ephemeris_E_size[1] == cosinus_E_k_size[1]) {
    r_k_size[0] = 1;
    r_k_size[1] = Ephemeris_E_size[1];
    loop_ub = Ephemeris_E_size[1];
    scalarLB = (Ephemeris_E_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&cosinus_E_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&r_k_data[t_k_data_tmp], _mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_E_data[t_k_data_tmp]), tmp_7));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      r_k_data[t_k_data_tmp] = Ephemeris_E_data[t_k_data_tmp] *
        cosinus_E_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProcessingSingle_times_a(r_k_data, r_k_size, Ephemeris_E_data,
      Ephemeris_E_size, cosinus_E_k_data, cosinus_E_k_size);
  }

  PHI_k_Dot_size[0] = 1;
  PHI_k_Dot_size[1] = r_k_size[1];
  loop_ub = r_k_size[1];
  scalarLB = (r_k_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&r_k_data[t_k_data_tmp]);
    _mm_storeu_pd(&PHI_k_Dot_data[t_k_data_tmp], _mm_sub_pd(_mm_set1_pd(1.0),
      tmp_7));
  }

  for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++) {
    PHI_k_Dot_data[t_k_data_tmp] = 1.0 - r_k_data[t_k_data_tmp];
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

  GNSSPreProcessingSingleAnt_sqrt(f_data, f_size);
  if ((f_size[1] != sinus_E_k_size[1]) || ((f_size[1] == 1 ? sinus_E_k_size[1] :
        f_size[1]) != r_k_size[1]) || (cosinus_E_k_size[1] != Ephemeris_E_size[1])
      || ((cosinus_E_k_size[1] == 1 ? Ephemeris_E_size[1] : cosinus_E_k_size[1])
          != r_k_size[1])) {
    GNSSPreProc_binary_expand_op_ar(i_k_data, i_k_size, f_data, f_size,
      sinus_E_k_data, sinus_E_k_size, PHI_k_Dot_data, PHI_k_Dot_size,
      cosinus_E_k_data, cosinus_E_k_size, Ephemeris_E_data, Ephemeris_E_size);
  }

  GNSSPreProc_binary_expand_op_ar(i_k_data, i_k_size, f_data, f_size,
    sinus_E_k_data, sinus_E_k_size, PHI_k_Dot_data, PHI_k_Dot_size,
    cosinus_E_k_data, cosinus_E_k_size, Ephemeris_E_data, Ephemeris_E_size);
  if ((f_size[1] == sinus_E_k_size[1]) && ((f_size[1] == 1 ? sinus_E_k_size[1] :
        f_size[1]) == r_k_size[1]) && (cosinus_E_k_size[1] == Ephemeris_E_size[1])
      && ((cosinus_E_k_size[1] == 1 ? Ephemeris_E_size[1] : cosinus_E_k_size[1])
          == r_k_size[1]) && (i_k_size[1] == Ephemeris_omega_size[1])) {
    sin2PHI_k_size[0] = 1;
    sin2PHI_k_size[1] = f_size[1];
    loop_ub = f_size[1];
    scalarLB = (f_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&f_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&sinus_E_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&PHI_k_Dot_data[t_k_data_tmp]);
      _mm_storeu_pd(&sin2PHI_k_data[t_k_data_tmp], _mm_div_pd(_mm_mul_pd(tmp_7,
        tmp_5), tmp_6));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      sin2PHI_k_data[t_k_data_tmp] = f_data[t_k_data_tmp] *
        sinus_E_k_data[t_k_data_tmp] / PHI_k_Dot_data[t_k_data_tmp];
    }

    cos2PHI_k_size[0] = 1;
    cos2PHI_k_size[1] = cosinus_E_k_size[1];
    loop_ub = cosinus_E_k_size[1];
    scalarLB = (cosinus_E_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&cosinus_E_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&PHI_k_Dot_data[t_k_data_tmp]);
      _mm_storeu_pd(&cos2PHI_k_data[t_k_data_tmp], _mm_div_pd(_mm_sub_pd(tmp_7,
        _mm_loadu_pd(&Ephemeris_E_data[t_k_data_tmp])), tmp_5));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      cos2PHI_k_data[t_k_data_tmp] = (cosinus_E_k_data[t_k_data_tmp] -
        Ephemeris_E_data[t_k_data_tmp]) / PHI_k_Dot_data[t_k_data_tmp];
    }

    GNSSPreProcessingSingleAn_atan2(sin2PHI_k_data, sin2PHI_k_size,
      cos2PHI_k_data, cos2PHI_k_size, i_k_data, i_k_size);
    cosinus_E_k_size[0] = 1;
    cosinus_E_k_size[1] = i_k_size[1];
    loop_ub = i_k_size[1];
    scalarLB = (i_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&i_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&cosinus_E_k_data[t_k_data_tmp], _mm_add_pd(tmp_7,
        _mm_loadu_pd(&Ephemeris_omega_data[t_k_data_tmp])));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      cosinus_E_k_data[t_k_data_tmp] = i_k_data[t_k_data_tmp] +
        Ephemeris_omega_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProc_binary_expand_op_a3(cosinus_E_k_data, cosinus_E_k_size, f_data,
      f_size, sinus_E_k_data, sinus_E_k_size, PHI_k_Dot_data, PHI_k_Dot_size,
      Ephemeris_E_data, Ephemeris_E_size, Ephemeris_omega_data,
      Ephemeris_omega_size);
  }

  i_k_size[0] = 1;
  i_k_size[1] = cosinus_E_k_size[1];
  loop_ub = cosinus_E_k_size[1];
  scalarLB = (cosinus_E_k_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&cosinus_E_k_data[t_k_data_tmp]);
    _mm_storeu_pd(&i_k_data[t_k_data_tmp], _mm_mul_pd(_mm_set1_pd(2.0), tmp_7));
  }

  for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++) {
    i_k_data[t_k_data_tmp] = 2.0 * cosinus_E_k_data[t_k_data_tmp];
  }

  sin2PHI_k_size[0] = 1;
  sin2PHI_k_size[1] = cosinus_E_k_size[1];
  loop_ub = cosinus_E_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&sin2PHI_k_data[0], &i_k_data[0], static_cast<uint32_T>(loop_ub)
                * sizeof(real_T));
  }

  GNSSPreProcessingSingleAnte_sin(sin2PHI_k_data, sin2PHI_k_size);
  cos2PHI_k_size[0] = 1;
  cos2PHI_k_size[1] = cosinus_E_k_size[1];
  loop_ub = cosinus_E_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&cos2PHI_k_data[0], &i_k_data[0], static_cast<uint32_T>(loop_ub)
                * sizeof(real_T));
  }

  GNSSPreProcessingSingleAnte_cos(cos2PHI_k_data, cos2PHI_k_size);
  if ((Ephemeris_C_us_size[1] == sin2PHI_k_size[1]) && (Ephemeris_C_uc_size[1] ==
       cos2PHI_k_size[1]) && ((Ephemeris_C_us_size[1] == 1 ? sin2PHI_k_size[1] :
        Ephemeris_C_us_size[1]) == (Ephemeris_C_uc_size[1] == 1 ?
        cos2PHI_k_size[1] : Ephemeris_C_uc_size[1])) && (((Ephemeris_C_us_size[1]
         == 1 ? sin2PHI_k_size[1] : Ephemeris_C_us_size[1]) == 1 ?
        Ephemeris_C_uc_size[1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_uc_size[1]
        : Ephemeris_C_us_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_us_size
        [1]) == cosinus_E_k_size[1])) {
    loop_ub = cosinus_E_k_size[1] - 1;
    cosinus_E_k_size[0] = 1;
    scalarLB = (cosinus_E_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&sin2PHI_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&cosinus_E_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&cosinus_E_k_data[t_k_data_tmp], _mm_add_pd(_mm_add_pd
        (_mm_mul_pd(_mm_loadu_pd(&Ephemeris_C_us_data[t_k_data_tmp]), tmp_7),
         _mm_mul_pd(_mm_loadu_pd(&Ephemeris_C_uc_data[t_k_data_tmp]), tmp_5)),
        tmp_6));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      cosinus_E_k_data[t_k_data_tmp] += Ephemeris_C_us_data[t_k_data_tmp] *
        sin2PHI_k_data[t_k_data_tmp] + Ephemeris_C_uc_data[t_k_data_tmp] *
        cos2PHI_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProce_binary_expand_op_f(cosinus_E_k_data, cosinus_E_k_size,
      Ephemeris_C_us_data, Ephemeris_C_us_size, sin2PHI_k_data, sin2PHI_k_size,
      Ephemeris_C_uc_data, Ephemeris_C_uc_size, cos2PHI_k_data, cos2PHI_k_size);
  }

  scalarLB_tmp = (Ephemeris_SQRT_A_size[1] / 2) << 1;
  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&g_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&g_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  if ((Ephemeris_SQRT_A_size[1] == r_k_size[1]) && (Ephemeris_C_rs_size[1] ==
       sin2PHI_k_size[1]) && (Ephemeris_C_rc_size[1] == cos2PHI_k_size[1]) &&
      ((Ephemeris_C_rs_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_rs_size[1])
       == (Ephemeris_C_rc_size[1] == 1 ? cos2PHI_k_size[1] :
           Ephemeris_C_rc_size[1])) && (((Ephemeris_C_rs_size[1] == 1 ?
         sin2PHI_k_size[1] : Ephemeris_C_rs_size[1]) == 1 ? Ephemeris_C_rc_size
        [1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_rc_size[1] :
        Ephemeris_C_rs_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_rs_size[1])
       == (Ephemeris_SQRT_A_size[1] == 1 ? r_k_size[1] : Ephemeris_SQRT_A_size[1])))
  {
    loop_ub = Ephemeris_SQRT_A_size[1] - 1;
    r_k_size[0] = 1;
    r_k_size[1] = Ephemeris_SQRT_A_size[1];
    vectorUB = scalarLB_tmp - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&r_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&sin2PHI_k_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&r_k_data[t_k_data_tmp], _mm_add_pd(_mm_mul_pd(_mm_mul_pd
        (tmp_7, tmp_7), _mm_sub_pd(_mm_set1_pd(1.0), tmp_5)), _mm_add_pd
        (_mm_mul_pd(_mm_loadu_pd(&Ephemeris_C_rs_data[t_k_data_tmp]), tmp_6),
         _mm_mul_pd(_mm_loadu_pd(&Ephemeris_C_rc_data[t_k_data_tmp]), tmp_4))));
    }

    for (int32_T t_k_data_tmp{scalarLB_tmp}; t_k_data_tmp <= loop_ub;
         t_k_data_tmp++) {
      N = Ephemeris_SQRT_A_data[t_k_data_tmp];
      r_k_data[t_k_data_tmp] = N * N * (1.0 - r_k_data[t_k_data_tmp]) +
        (Ephemeris_C_rs_data[t_k_data_tmp] * sin2PHI_k_data[t_k_data_tmp] +
         Ephemeris_C_rc_data[t_k_data_tmp] * cos2PHI_k_data[t_k_data_tmp]);
    }
  } else {
    GNSSPreProce_binary_expand_op_n(r_k_data, r_k_size, Ephemeris_SQRT_A_data,
      Ephemeris_SQRT_A_size, Ephemeris_C_rs_data, Ephemeris_C_rs_size,
      sin2PHI_k_data, sin2PHI_k_size, Ephemeris_C_rc_data, Ephemeris_C_rc_size,
      cos2PHI_k_data, cos2PHI_k_size);
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
    GNSSPreProce_binary_expand_op_e(i_k_data, i_k_size, Ephemeris_I_0_data,
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
    binary_expand_o_ar5npdcmtcc01ob(t_k_data, t_k_size, Ephemeris_OMEGA_0_data,
      Ephemeris_OMEGA_0_size, f_data, f_size, Ephemeris_T_oe_data,
      Ephemeris_T_oe_size);
  }

  cosinus_u_k_size[0] = 1;
  cosinus_u_k_size[1] = cosinus_E_k_size[1];
  loop_ub = cosinus_E_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&cosinus_u_k_data[0], &cosinus_E_k_data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  GNSSPreProcessingSingleAnte_cos(cosinus_u_k_data, cosinus_u_k_size);
  GNSSPreProcessingSingleAnte_sin(cosinus_E_k_data, cosinus_E_k_size);
  cosinus_i_k_size[0] = 1;
  cosinus_i_k_size[1] = i_k_size[1];
  loop_ub = i_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&cosinus_i_k_data[0], &i_k_data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  GNSSPreProcessingSingleAnte_cos(cosinus_i_k_data, cosinus_i_k_size);
  GNSSPreProcessingSingleAnte_sin(i_k_data, i_k_size);
  sinus_lambda_k_size[0] = 1;
  sinus_lambda_k_size[1] = t_k_size[1];
  loop_ub = t_k_size[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&sinus_lambda_k_data[0], &t_k_data[0], static_cast<uint32_T>
                (loop_ub) * sizeof(real_T));
  }

  GNSSPreProcessingSingleAnte_sin(sinus_lambda_k_data, sinus_lambda_k_size);
  GNSSPreProcessingSingleAnte_cos(t_k_data, t_k_size);
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
    GNSSPreProcessingSingle_times_a(X_k_tmp_data, X_k_tmp_size, r_k_data,
      r_k_size, cosinus_u_k_data, cosinus_u_k_size);
  }

  if (r_k_size[1] == cosinus_E_k_size[1]) {
    loop_ub = r_k_size[1] - 1;
    r_k_size[0] = 1;
    scalarLB = (r_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&r_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&cosinus_E_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&r_k_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_5));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      r_k_data[t_k_data_tmp] *= cosinus_E_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProcessingSingl_times_ax(r_k_data, r_k_size, cosinus_E_k_data,
      cosinus_E_k_size);
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
    GNSSPreProcessingSingle_times_a(c_data, c_size, r_k_data, r_k_size,
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
    binary_expand_op_ar5npdcmtcc01o(sv_pos_data, X_k_tmp_data, X_k_tmp_size,
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
    binary_expand_op_ar5npdcmtcc01(sv_pos_data, sv_pos_size, X_k_tmp_data,
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
    GNSSPreProcessingSingle_times_a(d_data, d_size, r_k_data, r_k_size, i_k_data,
      i_k_size);
  }

  loop_ub = sv_pos_size[0];
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp < loop_ub; t_k_data_tmp++) {
    sv_pos_data[t_k_data_tmp + (sv_pos_size[0] << 1)] = d_data[t_k_data_tmp];
  }

  g_size[0] = 1;
  g_size[1] = Ephemeris_E_size[1];
  loop_ub = Ephemeris_E_size[1];
  scalarLB = (Ephemeris_E_size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_E_data[t_k_data_tmp]);
    _mm_storeu_pd(&g_data[t_k_data_tmp], _mm_sub_pd(_mm_set1_pd(1.0), _mm_mul_pd
      (tmp_7, tmp_7)));
  }

  for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++) {
    N = Ephemeris_E_data[t_k_data_tmp];
    g_data[t_k_data_tmp] = 1.0 - N * N;
  }

  GNSSPreProcessingSingleAnt_sqrt(g_data, g_size);
  if ((g_size[1] == E_k_Dot_size[1]) && ((g_size[1] == 1 ? E_k_Dot_size[1] :
        g_size[1]) == PHI_k_Dot_size[1])) {
    loop_ub = g_size[1] - 1;
    PHI_k_Dot_size[0] = 1;
    PHI_k_Dot_size[1] = g_size[1];
    scalarLB = (g_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&g_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&E_k_Dot_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&PHI_k_Dot_data[t_k_data_tmp]);
      _mm_storeu_pd(&PHI_k_Dot_data[t_k_data_tmp], _mm_div_pd(_mm_mul_pd(tmp_7,
        tmp_5), tmp_6));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      PHI_k_Dot_data[t_k_data_tmp] = g_data[t_k_data_tmp] *
        E_k_Dot_data[t_k_data_tmp] / PHI_k_Dot_data[t_k_data_tmp];
    }
  } else {
    G_binary_expand_op_ar5npdcmtcc0(PHI_k_Dot_data, PHI_k_Dot_size, g_data,
      g_size, E_k_Dot_data, E_k_Dot_size);
  }

  if ((Ephemeris_C_us_size[1] == cos2PHI_k_size[1]) && (Ephemeris_C_uc_size[1] ==
       sin2PHI_k_size[1]) && ((Ephemeris_C_us_size[1] == 1 ? cos2PHI_k_size[1] :
        Ephemeris_C_us_size[1]) == (Ephemeris_C_uc_size[1] == 1 ?
        sin2PHI_k_size[1] : Ephemeris_C_uc_size[1])) && (((Ephemeris_C_us_size[1]
         == 1 ? cos2PHI_k_size[1] : Ephemeris_C_us_size[1]) == 1 ?
        Ephemeris_C_uc_size[1] == 1 ? sin2PHI_k_size[1] : Ephemeris_C_uc_size[1]
        : Ephemeris_C_us_size[1] == 1 ? cos2PHI_k_size[1] : Ephemeris_C_us_size
        [1]) == PHI_k_Dot_size[1])) {
    u_k_Dot_size[0] = 1;
    u_k_Dot_size[1] = Ephemeris_C_us_size[1];
    loop_ub = Ephemeris_C_us_size[1];
    scalarLB = (Ephemeris_C_us_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_set1_pd(2.0);
      tmp_5 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&sin2PHI_k_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&PHI_k_Dot_data[t_k_data_tmp]);
      _mm_storeu_pd(&u_k_Dot_data[t_k_data_tmp], _mm_mul_pd(_mm_sub_pd
        (_mm_add_pd(_mm_mul_pd(_mm_mul_pd(tmp_7, _mm_loadu_pd
        (&Ephemeris_C_us_data[t_k_data_tmp])), tmp_5), _mm_set1_pd(1.0)),
         _mm_mul_pd(_mm_mul_pd(tmp_7, _mm_loadu_pd
        (&Ephemeris_C_uc_data[t_k_data_tmp])), tmp_6)), tmp_4));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      u_k_Dot_data[t_k_data_tmp] = ((2.0 * Ephemeris_C_us_data[t_k_data_tmp] *
        cos2PHI_k_data[t_k_data_tmp] + 1.0) - 2.0 *
        Ephemeris_C_uc_data[t_k_data_tmp] * sin2PHI_k_data[t_k_data_tmp]) *
        PHI_k_Dot_data[t_k_data_tmp];
    }
  } else {
    GN_binary_expand_op_ar5npdcmtcc(u_k_Dot_data, u_k_Dot_size,
      Ephemeris_C_us_data, Ephemeris_C_us_size, cos2PHI_k_data, cos2PHI_k_size,
      Ephemeris_C_uc_data, Ephemeris_C_uc_size, sin2PHI_k_data, sin2PHI_k_size,
      PHI_k_Dot_data, PHI_k_Dot_size);
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&g_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&g_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&g_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
    _mm_storeu_pd(&g_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
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
    loop_ub = Ephemeris_C_rs_size[1] - 1;
    sinus_E_k_size[0] = 1;
    sinus_E_k_size[1] = Ephemeris_C_rs_size[1];
    scalarLB = (Ephemeris_C_rs_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&sin2PHI_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&PHI_k_Dot_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&Ephemeris_SQRT_A_data[t_k_data_tmp]);
      tmp_2 = _mm_loadu_pd(&sinus_E_k_data[t_k_data_tmp]);
      tmp_3 = _mm_loadu_pd(&E_k_Dot_data[t_k_data_tmp]);
      _mm_storeu_pd(&sinus_E_k_data[t_k_data_tmp], _mm_add_pd(_mm_mul_pd
        (_mm_mul_pd(_mm_sub_pd(_mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_C_rs_data[t_k_data_tmp]), tmp_7), _mm_mul_pd(_mm_loadu_pd
        (&Ephemeris_C_rc_data[t_k_data_tmp]), tmp_5)), _mm_set1_pd(2.0)), tmp_6),
        _mm_mul_pd(_mm_mul_pd(_mm_mul_pd(_mm_mul_pd(tmp_4, tmp_4), _mm_loadu_pd(
        &Ephemeris_E_data[t_k_data_tmp])), tmp_2), tmp_3)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      N = Ephemeris_SQRT_A_data[t_k_data_tmp];
      sinus_E_k_data[t_k_data_tmp] = (Ephemeris_C_rs_data[t_k_data_tmp] *
        cos2PHI_k_data[t_k_data_tmp] - Ephemeris_C_rc_data[t_k_data_tmp] *
        sin2PHI_k_data[t_k_data_tmp]) * 2.0 * PHI_k_Dot_data[t_k_data_tmp] + N *
        N * Ephemeris_E_data[t_k_data_tmp] * sinus_E_k_data[t_k_data_tmp] *
        E_k_Dot_data[t_k_data_tmp];
    }
  } else {
    GNS_binary_expand_op_ar5npdcmtc(sinus_E_k_data, sinus_E_k_size,
      Ephemeris_C_rs_data, Ephemeris_C_rs_size, cos2PHI_k_data, cos2PHI_k_size,
      Ephemeris_C_rc_data, Ephemeris_C_rc_size, sin2PHI_k_data, sin2PHI_k_size,
      PHI_k_Dot_data, PHI_k_Dot_size, Ephemeris_SQRT_A_data,
      Ephemeris_SQRT_A_size, Ephemeris_E_data, Ephemeris_E_size, E_k_Dot_data,
      E_k_Dot_size);
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
    GNSS_binary_expand_op_ar5npdcmt(cos2PHI_k_data, cos2PHI_k_size,
      Ephemeris_C_is_data, Ephemeris_C_is_size, Ephemeris_C_ic_data,
      Ephemeris_C_ic_size, sin2PHI_k_data, sin2PHI_k_size, PHI_k_Dot_data,
      PHI_k_Dot_size, Ephemeris_IDOT_data, Ephemeris_IDOT_size);
  }

  if ((sinus_E_k_size[1] == cosinus_u_k_size[1]) && (r_k_size[1] ==
       u_k_Dot_size[1]) && ((sinus_E_k_size[1] == 1 ? cosinus_u_k_size[1] :
        sinus_E_k_size[1]) == (r_k_size[1] == 1 ? u_k_Dot_size[1] : r_k_size[1])))
  {
    loop_ub = sinus_E_k_size[1] - 1;
    cosinus_u_k_size[0] = 1;
    cosinus_u_k_size[1] = sinus_E_k_size[1];
    scalarLB = (sinus_E_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&sinus_E_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&cosinus_u_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&r_k_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&u_k_Dot_data[t_k_data_tmp]);
      _mm_storeu_pd(&cosinus_u_k_data[t_k_data_tmp], _mm_sub_pd(_mm_mul_pd(tmp_7,
        tmp_5), _mm_mul_pd(tmp_6, tmp_4)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      cosinus_u_k_data[t_k_data_tmp] = sinus_E_k_data[t_k_data_tmp] *
        cosinus_u_k_data[t_k_data_tmp] - r_k_data[t_k_data_tmp] *
        u_k_Dot_data[t_k_data_tmp];
    }
  } else {
    GNSSP_binary_expand_op_ar5npdcm(cosinus_u_k_data, cosinus_u_k_size,
      sinus_E_k_data, sinus_E_k_size, r_k_data, r_k_size, u_k_Dot_data,
      u_k_Dot_size);
  }

  if ((sinus_E_k_size[1] == cosinus_E_k_size[1]) && (X_k_tmp_size[1] ==
       u_k_Dot_size[1]) && ((sinus_E_k_size[1] == 1 ? cosinus_E_k_size[1] :
        sinus_E_k_size[1]) == (X_k_tmp_size[1] == 1 ? u_k_Dot_size[1] :
        X_k_tmp_size[1]))) {
    loop_ub = sinus_E_k_size[1] - 1;
    sinus_E_k_size[0] = 1;
    scalarLB = (sinus_E_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&sinus_E_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&cosinus_E_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&X_k_tmp_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&u_k_Dot_data[t_k_data_tmp]);
      _mm_storeu_pd(&sinus_E_k_data[t_k_data_tmp], _mm_add_pd(_mm_mul_pd(tmp_7,
        tmp_5), _mm_mul_pd(tmp_6, tmp_4)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      sinus_E_k_data[t_k_data_tmp] = sinus_E_k_data[t_k_data_tmp] *
        cosinus_E_k_data[t_k_data_tmp] + X_k_tmp_data[t_k_data_tmp] *
        u_k_Dot_data[t_k_data_tmp];
    }
  } else {
    GNSSPr_binary_expand_op_ar5npdc(sinus_E_k_data, sinus_E_k_size,
      cosinus_E_k_data, cosinus_E_k_size, X_k_tmp_data, X_k_tmp_size,
      u_k_Dot_data, u_k_Dot_size);
  }

  sv_vel_size[0] = cosinus_u_k_size[1];
  sv_vel_size[1] = 3;
  loop_ub = cosinus_u_k_size[1] * 3;
  if (loop_ub - 1 >= 0) {
    std::memset(&sv_vel_data[0], 0, static_cast<uint32_T>(loop_ub) * sizeof
                (real_T));
  }

  if (sinus_E_k_size[1] == cosinus_i_k_size[1]) {
    loop_ub = sinus_E_k_size[1] - 1;
    cosinus_i_k_size[0] = 1;
    cosinus_i_k_size[1] = sinus_E_k_size[1];
    scalarLB = (sinus_E_k_size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&sinus_E_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&cosinus_i_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&cosinus_i_k_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_5));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp <= loop_ub; t_k_data_tmp++)
    {
      cosinus_i_k_data[t_k_data_tmp] *= sinus_E_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPreProcessingSingleAn_times(cosinus_i_k_data, cosinus_i_k_size,
      sinus_E_k_data, sinus_E_k_size);
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
    GNSSPre_binary_expand_op_ar5npd(sv_vel_data, cosinus_u_k_data,
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
    GNSSPreP_binary_expand_op_ar5np(sv_vel_data, sv_vel_size, cosinus_u_k_data,
      cosinus_u_k_size, sinus_lambda_k_data, sinus_lambda_k_size,
      cosinus_i_k_data, cosinus_i_k_size, t_k_data, t_k_size, d_data, d_size,
      cos2PHI_k_data, cos2PHI_k_size, sv_pos_data, sv_pos_size, f_data, f_size);
  }

  if ((sinus_E_k_size[1] == i_k_size[1]) && (c_size[1] == cos2PHI_k_size[1]) &&
      ((sinus_E_k_size[1] == 1 ? i_k_size[1] : sinus_E_k_size[1]) == (c_size[1] ==
        1 ? cos2PHI_k_size[1] : c_size[1]))) {
    loop_ub = sv_vel_size[0];
    scalarLB = (sv_vel_size[0] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
      tmp_7 = _mm_loadu_pd(&sinus_E_k_data[t_k_data_tmp]);
      tmp_5 = _mm_loadu_pd(&i_k_data[t_k_data_tmp]);
      tmp_6 = _mm_loadu_pd(&c_data[t_k_data_tmp]);
      tmp_4 = _mm_loadu_pd(&cos2PHI_k_data[t_k_data_tmp]);
      _mm_storeu_pd(&sv_vel_data[t_k_data_tmp + (sv_vel_size[0] << 1)],
                    _mm_add_pd(_mm_mul_pd(tmp_7, tmp_5), _mm_mul_pd(tmp_6, tmp_4)));
    }

    for (int32_T t_k_data_tmp{scalarLB}; t_k_data_tmp < loop_ub; t_k_data_tmp++)
    {
      sv_vel_data[t_k_data_tmp + (sv_vel_size[0] << 1)] =
        sinus_E_k_data[t_k_data_tmp] * i_k_data[t_k_data_tmp] +
        c_data[t_k_data_tmp] * cos2PHI_k_data[t_k_data_tmp];
    }
  } else {
    GNSSPrePr_binary_expand_op_ar5n(sv_vel_data, sv_vel_size, sinus_E_k_data,
      sinus_E_k_size, i_k_data, i_k_size, c_data, c_size, cos2PHI_k_data,
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
    _mm_storeu_pd(&t_k_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
  }

  vectorUB = scalarLB_tmp - 2;
  for (int32_T t_k_data_tmp{0}; t_k_data_tmp <= vectorUB; t_k_data_tmp += 2) {
    tmp_7 = _mm_loadu_pd(&sv_pos_data[(sv_pos_size[0] << 1) + t_k_data_tmp]);
    tmp_7 = _mm_sub_pd(tmp_7, _mm_set1_pd(z_user));
    _mm_storeu_pd(&t_k_data[t_k_data_tmp], _mm_mul_pd(tmp_7, tmp_7));
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

  GNSSPreProcessingSingleA_sqrt_g(t_k_data, &transport_angle_size);
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

void GNSS_preprocessingModelClass::GNSSPreProce_binary_expand_op_a(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3[330], const gnssops_navigation_data *in4, const
  gnssops_navigation_data_size *in5)
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
//    '<S26>/Calculate Satellite Position and Velocity'
//    '<S34>/Calculate Satellite Position and Velocity'
//    '<S42>/Calculate Satellite Position and Velocity'
//    '<S75>/Calculate Satellite Position and Velocity'
//    '<S83>/Calculate Satellite Position and Velocity'
//    '<S91>/Calculate Satellite Position and Velocity'
//    '<S99>/Calculate Satellite Position and Velocity'
//
void GNSS_preprocessingModelClass::CalculateSatellitePositionandVe(real_T
  rtu_enableSatPosVelCalc, const real_T rtu_userPosLlh[3], const
  gnssops_navigation_data *rtu_GnssNavBus, const gnssops_navigation_data_size
  *rtu_GnssNavBus_DIMS1, const real_T rtu_timeEmissionCorrected[40], const
  int32_T *rtu_timeEmissionCorrected_DIMS1, const real_T
  rtu_delta_satPosECEF_EGNOS[330], B_CalculateSatellitePositiona_T *localB,
  DW_CalculateSatellitePosition_T *localDW)
{
  real_T satPosEcef_data[120];
  real_T satVelEcef_data[120];
  real_T tmp_data[120];
  real_T rtu_timeEmissionCorrected_data[40];
  real_T rtu_GnssNavBus_data[37];
  real_T rtu_GnssNavBus_data_0[37];
  real_T rtu_GnssNavBus_data_1[37];
  real_T rtu_GnssNavBus_data_2[37];
  real_T rtu_GnssNavBus_data_3[37];
  real_T rtu_GnssNavBus_data_4[37];
  real_T rtu_GnssNavBus_data_5[37];
  real_T rtu_GnssNavBus_data_6[37];
  real_T rtu_GnssNavBus_data_7[37];
  real_T rtu_GnssNavBus_data_8[37];
  real_T rtu_GnssNavBus_data_9[37];
  real_T rtu_GnssNavBus_data_a[37];
  real_T rtu_GnssNavBus_data_b[37];
  real_T rtu_GnssNavBus_data_c[37];
  real_T rtu_GnssNavBus_data_d[37];
  real_T rtu_GnssNavBus_data_e[37];
  int32_T rtu_GnssNavBus_size[2];
  int32_T rtu_GnssNavBus_size_0[2];
  int32_T rtu_GnssNavBus_size_1[2];
  int32_T rtu_GnssNavBus_size_2[2];
  int32_T rtu_GnssNavBus_size_3[2];
  int32_T rtu_GnssNavBus_size_4[2];
  int32_T rtu_GnssNavBus_size_5[2];
  int32_T rtu_GnssNavBus_size_6[2];
  int32_T rtu_GnssNavBus_size_7[2];
  int32_T rtu_GnssNavBus_size_8[2];
  int32_T rtu_GnssNavBus_size_9[2];
  int32_T rtu_GnssNavBus_size_a[2];
  int32_T rtu_GnssNavBus_size_b[2];
  int32_T rtu_GnssNavBus_size_c[2];
  int32_T rtu_GnssNavBus_size_d[2];
  int32_T rtu_GnssNavBus_size_e[2];
  int32_T rtu_timeEmissionCorrected_size[2];
  int32_T satPosEcef_size[2];
  int32_T satVelEcef_size[2];
  int32_T tmp_size[2];
  if (rtu_enableSatPosVelCalc != 0.0) {
    int32_T loop_ub;
    rtu_GnssNavBus_size[0] = 1;
    rtu_GnssNavBus_size[1] = rtu_GnssNavBus_DIMS1->C_rs;
    if (rtu_GnssNavBus_DIMS1->C_rs - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data[0], &rtu_GnssNavBus->C_rs[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->C_rs) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_0[0] = 1;
    rtu_GnssNavBus_size_0[1] = rtu_GnssNavBus_DIMS1->DELTA_N;
    if (rtu_GnssNavBus_DIMS1->DELTA_N - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_0[0], &rtu_GnssNavBus->DELTA_N[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->DELTA_N) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_1[0] = 1;
    rtu_GnssNavBus_size_1[1] = rtu_GnssNavBus_DIMS1->M_0;
    if (rtu_GnssNavBus_DIMS1->M_0 - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_1[0], &rtu_GnssNavBus->M_0[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->M_0) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_2[0] = 1;
    rtu_GnssNavBus_size_2[1] = rtu_GnssNavBus_DIMS1->C_uc;
    if (rtu_GnssNavBus_DIMS1->C_uc - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_2[0], &rtu_GnssNavBus->C_uc[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->C_uc) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_3[0] = 1;
    rtu_GnssNavBus_size_3[1] = rtu_GnssNavBus_DIMS1->E;
    if (rtu_GnssNavBus_DIMS1->E - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_3[0], &rtu_GnssNavBus->E[0], static_cast<
                  uint32_T>(rtu_GnssNavBus_DIMS1->E) * sizeof(real_T));
    }

    rtu_GnssNavBus_size_4[0] = 1;
    rtu_GnssNavBus_size_4[1] = rtu_GnssNavBus_DIMS1->C_us;
    if (rtu_GnssNavBus_DIMS1->C_us - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_4[0], &rtu_GnssNavBus->C_us[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->C_us) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_5[0] = 1;
    rtu_GnssNavBus_size_5[1] = rtu_GnssNavBus_DIMS1->SQRT_A;
    if (rtu_GnssNavBus_DIMS1->SQRT_A - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_5[0], &rtu_GnssNavBus->SQRT_A[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->SQRT_A) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_6[0] = 1;
    rtu_GnssNavBus_size_6[1] = rtu_GnssNavBus_DIMS1->T_oe;
    if (rtu_GnssNavBus_DIMS1->T_oe - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_6[0], &rtu_GnssNavBus->T_oe[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->T_oe) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_7[0] = 1;
    rtu_GnssNavBus_size_7[1] = rtu_GnssNavBus_DIMS1->C_ic;
    if (rtu_GnssNavBus_DIMS1->C_ic - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_7[0], &rtu_GnssNavBus->C_ic[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->C_ic) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_8[0] = 1;
    rtu_GnssNavBus_size_8[1] = rtu_GnssNavBus_DIMS1->OMEGA_0;
    if (rtu_GnssNavBus_DIMS1->OMEGA_0 - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_8[0], &rtu_GnssNavBus->OMEGA_0[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->OMEGA_0) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_9[0] = 1;
    rtu_GnssNavBus_size_9[1] = rtu_GnssNavBus_DIMS1->C_is;
    if (rtu_GnssNavBus_DIMS1->C_is - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_9[0], &rtu_GnssNavBus->C_is[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->C_is) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_a[0] = 1;
    rtu_GnssNavBus_size_a[1] = rtu_GnssNavBus_DIMS1->I_0;
    if (rtu_GnssNavBus_DIMS1->I_0 - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_a[0], &rtu_GnssNavBus->I_0[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->I_0) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_b[0] = 1;
    rtu_GnssNavBus_size_b[1] = rtu_GnssNavBus_DIMS1->C_rc;
    if (rtu_GnssNavBus_DIMS1->C_rc - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_b[0], &rtu_GnssNavBus->C_rc[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->C_rc) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_c[0] = 1;
    rtu_GnssNavBus_size_c[1] = rtu_GnssNavBus_DIMS1->omega;
    if (rtu_GnssNavBus_DIMS1->omega - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_c[0], &rtu_GnssNavBus->omega[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->omega) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_d[0] = 1;
    rtu_GnssNavBus_size_d[1] = rtu_GnssNavBus_DIMS1->OMEGADOT;
    if (rtu_GnssNavBus_DIMS1->OMEGADOT - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_d[0], &rtu_GnssNavBus->OMEGADOT[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->OMEGADOT) * sizeof
                  (real_T));
    }

    rtu_GnssNavBus_size_e[0] = 1;
    rtu_GnssNavBus_size_e[1] = rtu_GnssNavBus_DIMS1->IDOT;
    if (rtu_GnssNavBus_DIMS1->IDOT - 1 >= 0) {
      std::memcpy(&rtu_GnssNavBus_data_e[0], &rtu_GnssNavBus->IDOT[0],
                  static_cast<uint32_T>(rtu_GnssNavBus_DIMS1->IDOT) * sizeof
                  (real_T));
    }

    rtu_timeEmissionCorrected_size[0] = 1;
    rtu_timeEmissionCorrected_size[1] = *rtu_timeEmissionCorrected_DIMS1;
    for (int32_T i{0}; i < *rtu_timeEmissionCorrected_DIMS1; i++) {
      rtu_timeEmissionCorrected_data[i] = rtu_timeEmissionCorrected[i];
    }

    Get_Kepler_Satellite_Position_A(rtu_GnssNavBus_data, rtu_GnssNavBus_size,
      rtu_GnssNavBus_data_0, rtu_GnssNavBus_size_0, rtu_GnssNavBus_data_1,
      rtu_GnssNavBus_size_1, rtu_GnssNavBus_data_2, rtu_GnssNavBus_size_2,
      rtu_GnssNavBus_data_3, rtu_GnssNavBus_size_3, rtu_GnssNavBus_data_4,
      rtu_GnssNavBus_size_4, rtu_GnssNavBus_data_5, rtu_GnssNavBus_size_5,
      rtu_GnssNavBus_data_6, rtu_GnssNavBus_size_6, rtu_GnssNavBus_data_7,
      rtu_GnssNavBus_size_7, rtu_GnssNavBus_data_8, rtu_GnssNavBus_size_8,
      rtu_GnssNavBus_data_9, rtu_GnssNavBus_size_9, rtu_GnssNavBus_data_a,
      rtu_GnssNavBus_size_a, rtu_GnssNavBus_data_b, rtu_GnssNavBus_size_b,
      rtu_GnssNavBus_data_c, rtu_GnssNavBus_size_c, rtu_GnssNavBus_data_d,
      rtu_GnssNavBus_size_d, rtu_GnssNavBus_data_e, rtu_GnssNavBus_size_e,
      rtu_timeEmissionCorrected_data, rtu_timeEmissionCorrected_size,
      rtu_userPosLlh, satPosEcef_data, satPosEcef_size, satVelEcef_data,
      satVelEcef_size);
    localDW->SFunction_DIMS3[0] = satVelEcef_size[0];
    localDW->SFunction_DIMS3[1] = 3;
    loop_ub = satVelEcef_size[0] * 3;
    if (loop_ub - 1 >= 0) {
      std::memcpy(&localB->satVelEcef[0], &satVelEcef_data[0], static_cast<
                  uint32_T>(loop_ub) * sizeof(real_T));
    }

    if (satPosEcef_size[0] == rtu_GnssNavBus_DIMS1->SVID) {
      tmp_size[0] = satPosEcef_size[0];
      tmp_size[1] = 3;
      loop_ub = satPosEcef_size[0];
      for (int32_T i{0}; i < 3; i++) {
        for (int32_T loop_ub_tmp{0}; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
          tmp_data[loop_ub_tmp + tmp_size[0] * i] = rtu_delta_satPosECEF_EGNOS
            [(110 * i + static_cast<int32_T>(rtu_GnssNavBus->SVID[loop_ub_tmp]))
            - 1] + satPosEcef_data[satPosEcef_size[0] * i + loop_ub_tmp];
        }
      }
    } else {
      GNSSPreProce_binary_expand_op_a(tmp_data, tmp_size, satPosEcef_data,
        satPosEcef_size, rtu_delta_satPosECEF_EGNOS, rtu_GnssNavBus,
        rtu_GnssNavBus_DIMS1);
    }

    localDW->SFunction_DIMS2[0] = tmp_size[0];
    localDW->SFunction_DIMS2[1] = tmp_size[1];
    loop_ub = tmp_size[0] * tmp_size[1];
    if (loop_ub - 1 >= 0) {
      std::memcpy(&localB->satPosEcef[0], &tmp_data[0], static_cast<uint32_T>
                  (loop_ub) * sizeof(real_T));
    }
  } else {
    int32_T loop_ub_tmp;
    localDW->SFunction_DIMS2[0] = rtu_GnssNavBus_DIMS1->TOW;
    localDW->SFunction_DIMS2[1] = 3;
    loop_ub_tmp = rtu_GnssNavBus_DIMS1->TOW * 3;
    localDW->SFunction_DIMS3[0] = rtu_GnssNavBus_DIMS1->TOW;
    localDW->SFunction_DIMS3[1] = 3;
    if (loop_ub_tmp - 1 >= 0) {
      std::memset(&localB->satPosEcef[0], 0, static_cast<uint32_T>(loop_ub_tmp) *
                  sizeof(real_T));
    }

    if (loop_ub_tmp - 1 >= 0) {
      std::memset(&localB->satVelEcef[0], 0, static_cast<uint32_T>(loop_ub_tmp) *
                  sizeof(real_T));
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
