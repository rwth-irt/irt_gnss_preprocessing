//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateSatelliteClockCorrecti.cpp
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
#include "CalculateSatelliteClockCorrecti.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <emmintrin.h>
#include "GNSSPreProcessingSingleAntenna_private.h"
#include <cmath>
#include <cstring>

void GNSS_preprocessingModelClass::GNSS_binary_expand_op_hmra2j23d(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const gnssops_navigation_data *in3, const
  gnssops_navigation_data_size *in4)
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1_size[0] = 1;
  in1_size[1] = in4->T_oc == 1 ? in2_size[1] : in4->T_oc;
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in4->T_oc != 1);
  loop_ub = in4->T_oc == 1 ? in2_size[1] : in4->T_oc;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_1] - in3->T_oc[i * stride_1_1];
  }
}

void GNSS_preprocessingModelClass::GNSSP_binary_expand_op_hmra2j23(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const gnssops_navigation_data *in3, const
  gnssops_navigation_data_size *in4)
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1_size[0] = 1;
  in1_size[1] = in4->T_oe == 1 ? in2_size[1] : in4->T_oe;
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in4->T_oe != 1);
  loop_ub = in4->T_oe == 1 ? in2_size[1] : in4->T_oe;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_1] - in3->T_oe[i * stride_1_1];
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (std::isinf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
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
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
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

void GNSS_preprocessingModelClass::GNSSPr_binary_expand_op_hmra2j2(real_T
  in1_data[], int32_T in1_size[2], const gnssops_navigation_data *in2, const
  gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  in1_size[0] = 1;
  in1_size[1] = (in5_size[1] == 1 ? in3->DELTA_N == 1 ? in4_size[1] :
                 in3->DELTA_N : in5_size[1]) == 1 ? in3->M_0 : in5_size[1] == 1 ?
    in3->DELTA_N == 1 ? in4_size[1] : in3->DELTA_N : in5_size[1];
  stride_0_1 = (in3->M_0 != 1);
  stride_1_1 = (in4_size[1] != 1);
  stride_2_1 = (in3->DELTA_N != 1);
  stride_3_1 = (in5_size[1] != 1);
  loop_ub = (in5_size[1] == 1 ? in3->DELTA_N == 1 ? in4_size[1] : in3->DELTA_N :
             in5_size[1]) == 1 ? in3->M_0 : in5_size[1] == 1 ? in3->DELTA_N == 1
    ? in4_size[1] : in3->DELTA_N : in5_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    real_T tmp;
    tmp = in5_data[i * stride_3_1];
    in1_data[i] = ((tmp - static_cast<real_T>(tmp > 302400.0) * 604800.0) +
                   static_cast<real_T>(tmp < -302400.0) * 604800.0) *
      (in4_data[i * stride_1_1] + in2->DELTA_N[i * stride_2_1]) + in2->M_0[i *
      stride_0_1];
  }
}

void GNSS_preprocessingModelClass::GNSSPre_binary_expand_op_hmra2j(real_T
  in1_data[], int32_T in1_size[2], const gnssops_navigation_data *in2, const
  gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T
  in4_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  in1_size[0] = 1;
  in1_size[1] = (in4_size[1] == 1 ? in3->E : in4_size[1]) == 1 ? in3->E :
    in4_size[1] == 1 ? in3->E : in4_size[1];
  stride_0_1 = (in3->E != 1);
  stride_1_1 = (in3->E != 1);
  stride_2_1 = (in4_size[1] != 1);
  loop_ub = (in4_size[1] == 1 ? in3->E : in4_size[1]) == 1 ? in3->E : in4_size[1]
    == 1 ? in3->E : in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = static_cast<real_T>(in2->E[i * stride_0_1] > 0.8) *
      3.1415926535897931 + static_cast<real_T>(in2->E[i * stride_1_1] <= 0.8) *
      in4_data[i * stride_2_1];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProce_binary_expand_op_h(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2], const gnssops_navigation_data *in3, const
  gnssops_navigation_data_size *in4, const real_T in5_data[], const int32_T
  in5_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  in1_size[0] = 1;
  in1_size[1] = (in5_size[1] == 1 ? in4->E : in5_size[1]) == 1 ? in2_size[1] :
    in5_size[1] == 1 ? in4->E : in5_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in4->E != 1);
  stride_2_1 = (in5_size[1] != 1);
  loop_ub = (in5_size[1] == 1 ? in4->E : in5_size[1]) == 1 ? in2_size[1] :
    in5_size[1] == 1 ? in4->E : in5_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in3->E[i * stride_1_1] * in5_data[i * stride_2_1] + in2_data[i
      * stride_0_1];
  }
}

void GNSS_preprocessingModelClass::GNSSPreP_binary_expand_op_hmra2(real_T
  in1_data[], int32_T in1_size[2], const gnssops_navigation_data *in2, const
  gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2])
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
  in1_size[0] = 1;
  in1_size[1] = (in5_size[1] == 1 ? in3->SQRT_A == 1 ? in3->E : in3->SQRT_A :
                 in5_size[1]) == 1 ? (in4_size[1] == 1 ? in3->A_f2 : in4_size[1])
    == 1 ? (in4_size[1] == 1 ? in3->A_f1 : in4_size[1]) == 1 ? in3->A_f0 :
    in4_size[1] == 1 ? in3->A_f1 : in4_size[1] : in4_size[1] == 1 ? in3->A_f2 :
    in4_size[1] : in5_size[1] == 1 ? in3->SQRT_A == 1 ? in3->E : in3->SQRT_A :
    in5_size[1];
  stride_0_1 = (in3->A_f0 != 1);
  stride_1_1 = (in3->A_f1 != 1);
  stride_2_1 = (in4_size[1] != 1);
  stride_3_1 = (in3->A_f2 != 1);
  stride_4_1 = (in4_size[1] != 1);
  stride_5_1 = (in3->E != 1);
  stride_6_1 = (in3->SQRT_A != 1);
  stride_7_1 = (in5_size[1] != 1);
  loop_ub = (in5_size[1] == 1 ? in3->SQRT_A == 1 ? in3->E : in3->SQRT_A :
             in5_size[1]) == 1 ? (in4_size[1] == 1 ? in3->A_f2 : in4_size[1]) ==
    1 ? (in4_size[1] == 1 ? in3->A_f1 : in4_size[1]) == 1 ? in3->A_f0 :
    in4_size[1] == 1 ? in3->A_f1 : in4_size[1] : in4_size[1] == 1 ? in3->A_f2 :
    in4_size[1] : in5_size[1] == 1 ? in3->SQRT_A == 1 ? in3->E : in3->SQRT_A :
    in5_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = in4_data[i * stride_4_1];
    in1_data[i] = ((in2->A_f1[i * stride_1_1] * in4_data[i * stride_2_1] +
                    in2->A_f0[i * stride_0_1]) + in2->A_f2[i * stride_3_1] *
                   (varargin_1 * varargin_1)) + in2->E[i * stride_5_1] *
      -4.44280763339306E-10 * in2->SQRT_A[i * stride_6_1] * in5_data[i *
      stride_7_1];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_minus(real_T
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

void GNSS_preprocessingModelClass::GNSSPrePr_binary_expand_op_hmra(real_T
  in1_data[], int32_T *in1_size, const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3[110], const gnssops_navigation_data *in4, const
  gnssops_navigation_data_size *in5)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  *in1_size = in5->SVID == 1 ? in2_size[1] : in5->SVID;
  stride_0_0 = (in2_size[1] != 1);
  stride_1_0 = (in5->SVID != 1);
  loop_ub = in5->SVID == 1 ? in2_size[1] : in5->SVID;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in3[static_cast<int32_T>(in4->SVID[i * stride_1_0]) - 1] +
      in2_data[i * stride_0_0];
  }
}

void GNSS_preprocessingModelClass::GNSSPrePro_binary_expand_op_hmr(real_T
  in1_data[], int32_T *in1_size, const gnssops_navigation_data *in2, const
  gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T
  in4_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T stride_2_0;
  *in1_size = (in4_size[1] == 1 ? in3->A_f2 : in4_size[1]) == 1 ? in3->A_f1 :
    in4_size[1] == 1 ? in3->A_f2 : in4_size[1];
  stride_0_0 = (in3->A_f1 != 1);
  stride_1_0 = (in3->A_f2 != 1);
  stride_2_0 = (in4_size[1] != 1);
  loop_ub = (in4_size[1] == 1 ? in3->A_f2 : in4_size[1]) == 1 ? in3->A_f1 :
    in4_size[1] == 1 ? in3->A_f2 : in4_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2->A_f2[i * stride_1_0] * 2.0 * in4_data[i * stride_2_0] +
      in2->A_f1[i * stride_0_0];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_hm(real_T
  in1_data[], int32_T *in1_size, const real_T in2_data[], const int32_T
  in2_size[2], const real_T in3_data[], const int32_T in3_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  *in1_size = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  stride_0_0 = (in2_size[1] != 1);
  stride_1_0 = (in3_size[1] != 1);
  loop_ub = in3_size[1] == 1 ? in2_size[1] : in3_size[1];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_0] - in3_data[i * stride_1_0];
  }
}

//
// Output and update for atomic system:
//    '<S26>/Calculate Satellite Clock Correction'
//    '<S34>/Calculate Satellite Clock Correction'
//    '<S42>/Calculate Satellite Clock Correction'
//    '<S75>/Calculate Satellite Clock Correction'
//    '<S83>/Calculate Satellite Clock Correction'
//    '<S91>/Calculate Satellite Clock Correction'
//    '<S99>/Calculate Satellite Clock Correction'
//
void GNSS_preprocessingModelClass::CalculateSatelliteClockCorrecti(real_T
  rtu_TOW, const gnssops_navigation_data *rtu_GnssNavBus, const
  gnssops_navigation_data_size *rtu_GnssNavBus_DIMS1, const real_T
  rtu_pseudorange[40], const int32_T *rtu_pseudorange_DIMS1, real_T
  rtu_enableSatClockCorr, const real_T rtu_delta_t_sv_EGNOS[110],
  B_CalculateSatelliteClockCorr_T *localB, DW_CalculateSatelliteClockCor_T
  *localDW)
{
  __m128d tmp;
  __m128d tmp_4;
  __m128d tmp_5;
  real_T E_k_data[40];
  real_T M_k_data[40];
  real_T n_0_data[40];
  real_T t_d_data[40];
  real_T t_k_data[40];
  real_T t_sv_emission_data[40];
  real_T tmp_data[40];
  real_T t_d;
  int32_T E_k_size[2];
  int32_T M_k_size[2];
  int32_T n_0_size[2];
  int32_T t_d_size[2];
  int32_T t_k_size[2];
  int32_T t_sv_emission_size[2];
  int32_T i;
  int32_T k;
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T vectorUB;
  boolean_T x_data[40];
  t_sv_emission_size[0] = 1;
  t_sv_emission_size[1] = *rtu_pseudorange_DIMS1;
  scalarLB = (*rtu_pseudorange_DIMS1 / 2) << 1;
  vectorUB = scalarLB - 2;
  for (k = 0; k <= vectorUB; k += 2) {
    tmp_5 = _mm_loadu_pd(&rtu_pseudorange[k]);
    _mm_storeu_pd(&t_sv_emission_data[k], _mm_sub_pd(_mm_set1_pd(rtu_TOW),
      _mm_div_pd(tmp_5, _mm_set1_pd(2.99792458E+8))));
  }

  for (k = scalarLB; k < *rtu_pseudorange_DIMS1; k++) {
    t_sv_emission_data[k] = rtu_TOW - rtu_pseudorange[k] / 2.99792458E+8;
  }

  if (*rtu_pseudorange_DIMS1 == rtu_GnssNavBus_DIMS1->T_oc) {
    t_d_size[1] = *rtu_pseudorange_DIMS1;
    loop_ub = *rtu_pseudorange_DIMS1;
    scalarLB = (*rtu_pseudorange_DIMS1 / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_5 = _mm_loadu_pd(&t_sv_emission_data[k]);
      tmp_4 = _mm_loadu_pd(&rtu_GnssNavBus->T_oc[k]);
      _mm_storeu_pd(&t_d_data[k], _mm_sub_pd(tmp_5, tmp_4));
    }

    for (k = scalarLB; k < loop_ub; k++) {
      t_d_data[k] = t_sv_emission_data[k] - rtu_GnssNavBus->T_oc[k];
    }
  } else {
    GNSS_binary_expand_op_hmra2j23d(t_d_data, t_d_size, t_sv_emission_data,
      t_sv_emission_size, rtu_GnssNavBus, rtu_GnssNavBus_DIMS1);
  }

  t_d_size[0] = 1;
  loop_ub = t_d_size[1] - 1;
  for (k = 0; k <= loop_ub; k++) {
    t_d = t_d_data[k];
    t_d_data[k] = (t_d - static_cast<real_T>(t_d > 302400.0) * 604800.0) +
      static_cast<real_T>(t_d < -302400.0) * 604800.0;
  }

  if (*rtu_pseudorange_DIMS1 == rtu_GnssNavBus_DIMS1->T_oe) {
    t_k_size[0] = 1;
    t_k_size[1] = *rtu_pseudorange_DIMS1;
    loop_ub = *rtu_pseudorange_DIMS1;
    scalarLB = (*rtu_pseudorange_DIMS1 / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_5 = _mm_loadu_pd(&t_sv_emission_data[k]);
      tmp_4 = _mm_loadu_pd(&rtu_GnssNavBus->T_oe[k]);
      _mm_storeu_pd(&t_k_data[k], _mm_sub_pd(tmp_5, tmp_4));
    }

    for (k = scalarLB; k < loop_ub; k++) {
      t_k_data[k] = t_sv_emission_data[k] - rtu_GnssNavBus->T_oe[k];
    }
  } else {
    GNSSP_binary_expand_op_hmra2j23(t_k_data, t_k_size, t_sv_emission_data,
      t_sv_emission_size, rtu_GnssNavBus, rtu_GnssNavBus_DIMS1);
  }

  n_0_size[0] = 1;
  n_0_size[1] = rtu_GnssNavBus_DIMS1->SQRT_A;
  loop_ub = rtu_GnssNavBus_DIMS1->SQRT_A;
  for (k = 0; k < loop_ub; k++) {
    t_d = rtu_GnssNavBus->SQRT_A[k];
    n_0_data[k] = 3.986005E+14 / rt_powd_snf(t_d * t_d, 3.0);
  }

  i = rtu_GnssNavBus_DIMS1->SQRT_A;
  scalarLB = (rtu_GnssNavBus_DIMS1->SQRT_A / 2) << 1;
  vectorUB = scalarLB - 2;
  for (k = 0; k <= vectorUB; k += 2) {
    tmp_5 = _mm_loadu_pd(&n_0_data[k]);
    _mm_storeu_pd(&n_0_data[k], _mm_sqrt_pd(tmp_5));
  }

  for (k = scalarLB; k < i; k++) {
    n_0_data[k] = std::sqrt(n_0_data[k]);
  }

  if ((rtu_GnssNavBus_DIMS1->SQRT_A == rtu_GnssNavBus_DIMS1->DELTA_N) &&
      ((rtu_GnssNavBus_DIMS1->SQRT_A == 1 ? rtu_GnssNavBus_DIMS1->DELTA_N :
        rtu_GnssNavBus_DIMS1->SQRT_A) == t_k_size[1]) &&
      (((rtu_GnssNavBus_DIMS1->SQRT_A == 1 ? rtu_GnssNavBus_DIMS1->DELTA_N :
         rtu_GnssNavBus_DIMS1->SQRT_A) == 1 ? t_k_size[1] :
        rtu_GnssNavBus_DIMS1->SQRT_A == 1 ? rtu_GnssNavBus_DIMS1->DELTA_N :
        rtu_GnssNavBus_DIMS1->SQRT_A) == rtu_GnssNavBus_DIMS1->M_0)) {
    M_k_size[0] = 1;
    M_k_size[1] = rtu_GnssNavBus_DIMS1->M_0;
    loop_ub = rtu_GnssNavBus_DIMS1->M_0;
    for (k = 0; k < loop_ub; k++) {
      t_d = t_k_data[k];
      M_k_data[k] = ((t_d - static_cast<real_T>(t_d > 302400.0) * 604800.0) +
                     static_cast<real_T>(t_d < -302400.0) * 604800.0) *
        (n_0_data[k] + rtu_GnssNavBus->DELTA_N[k]) + rtu_GnssNavBus->M_0[k];
    }
  } else {
    GNSSPr_binary_expand_op_hmra2j2(M_k_data, M_k_size, rtu_GnssNavBus,
      rtu_GnssNavBus_DIMS1, n_0_data, n_0_size, t_k_data, t_k_size);
  }

  if ((rtu_GnssNavBus_DIMS1->E == M_k_size[1]) && ((rtu_GnssNavBus_DIMS1->E == 1
        ? M_k_size[1] : rtu_GnssNavBus_DIMS1->E) == rtu_GnssNavBus_DIMS1->E)) {
    E_k_size[0] = 1;
    E_k_size[1] = rtu_GnssNavBus_DIMS1->E;
    loop_ub = rtu_GnssNavBus_DIMS1->E;
    for (k = 0; k < loop_ub; k++) {
      E_k_data[k] = static_cast<real_T>(rtu_GnssNavBus->E[k] > 0.8) *
        3.1415926535897931 + static_cast<real_T>(rtu_GnssNavBus->E[k] <= 0.8) *
        M_k_data[k];
    }
  } else {
    GNSSPre_binary_expand_op_hmra2j(E_k_data, E_k_size, rtu_GnssNavBus,
      rtu_GnssNavBus_DIMS1, M_k_data, M_k_size);
  }

  i = 0;
  n_0_size[1] = E_k_size[1];
  loop_ub = E_k_size[1];
  for (k = 0; k < loop_ub; k++) {
    n_0_data[k] = 1.0;
  }

  int32_T exitg1;
  do {
    boolean_T exitg2;
    boolean_T y;
    exitg1 = 0;
    vectorUB = n_0_size[1];
    loop_ub = n_0_size[1];
    for (k = 0; k < loop_ub; k++) {
      x_data[k] = (n_0_data[k] > 1.0E-15);
    }

    y = false;
    k = 1;
    exitg2 = false;
    while ((!exitg2) && (k <= vectorUB)) {
      if (x_data[k - 1]) {
        y = true;
        exitg2 = true;
      } else {
        k++;
      }
    }

    if (y && (i < 20)) {
      t_k_size[0] = 1;
      t_k_size[1] = E_k_size[1];
      loop_ub = E_k_size[1];
      if (loop_ub - 1 >= 0) {
        std::memcpy(&t_k_data[0], &E_k_data[0], static_cast<uint32_T>(loop_ub) *
                    sizeof(real_T));
      }

      n_0_size[0] = 1;
      n_0_size[1] = E_k_size[1];
      loop_ub = E_k_size[1];
      if (loop_ub - 1 >= 0) {
        std::memcpy(&n_0_data[0], &E_k_data[0], static_cast<uint32_T>(loop_ub) *
                    sizeof(real_T));
      }

      scalarLB = E_k_size[1];
      for (k = 0; k < scalarLB; k++) {
        n_0_data[k] = std::sin(n_0_data[k]);
      }

      if ((rtu_GnssNavBus_DIMS1->E == E_k_size[1]) && ((rtu_GnssNavBus_DIMS1->E ==
            1 ? E_k_size[1] : rtu_GnssNavBus_DIMS1->E) == M_k_size[1])) {
        E_k_size[0] = 1;
        E_k_size[1] = M_k_size[1];
        loop_ub = M_k_size[1];
        scalarLB = (M_k_size[1] / 2) << 1;
        vectorUB = scalarLB - 2;
        for (k = 0; k <= vectorUB; k += 2) {
          tmp_5 = _mm_loadu_pd(&rtu_GnssNavBus->E[k]);
          tmp_4 = _mm_loadu_pd(&n_0_data[k]);
          tmp = _mm_loadu_pd(&M_k_data[k]);
          _mm_storeu_pd(&E_k_data[k], _mm_add_pd(_mm_mul_pd(tmp_5, tmp_4), tmp));
        }

        for (k = scalarLB; k < loop_ub; k++) {
          E_k_data[k] = rtu_GnssNavBus->E[k] * n_0_data[k] + M_k_data[k];
        }
      } else {
        GNSSPreProce_binary_expand_op_h(E_k_data, E_k_size, M_k_data, M_k_size,
          rtu_GnssNavBus, rtu_GnssNavBus_DIMS1, n_0_data, n_0_size);
      }

      if (E_k_size[1] == t_k_size[1]) {
        loop_ub = E_k_size[1] - 1;
        t_k_size[0] = 1;
        t_k_size[1] = E_k_size[1];
        scalarLB = (E_k_size[1] / 2) << 1;
        vectorUB = scalarLB - 2;
        for (k = 0; k <= vectorUB; k += 2) {
          tmp_5 = _mm_loadu_pd(&E_k_data[k]);
          tmp_4 = _mm_loadu_pd(&t_k_data[k]);
          _mm_storeu_pd(&t_k_data[k], _mm_sub_pd(tmp_5, tmp_4));
        }

        for (k = scalarLB; k <= loop_ub; k++) {
          t_k_data[k] = E_k_data[k] - t_k_data[k];
        }
      } else {
        GNSSPreProcessingSingleAn_minus(t_k_data, t_k_size, E_k_data, E_k_size);
      }

      n_0_size[1] = t_k_size[1];
      scalarLB = t_k_size[1];
      for (k = 0; k < scalarLB; k++) {
        n_0_data[k] = std::abs(t_k_data[k]);
      }

      i++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  i = E_k_size[1];
  for (k = 0; k < i; k++) {
    E_k_data[k] = std::sin(E_k_data[k]);
  }

  loop_ub = (t_d_size[1] / 2) << 1;
  vectorUB = loop_ub - 2;
  for (k = 0; k <= vectorUB; k += 2) {
    tmp_5 = _mm_loadu_pd(&t_d_data[k]);
    _mm_storeu_pd(&n_0_data[k], _mm_mul_pd(tmp_5, tmp_5));
  }

  vectorUB = loop_ub - 2;
  for (k = 0; k <= vectorUB; k += 2) {
    tmp_5 = _mm_loadu_pd(&t_d_data[k]);
    _mm_storeu_pd(&M_k_data[k], _mm_mul_pd(tmp_5, tmp_5));
  }

  vectorUB = loop_ub - 2;
  for (k = 0; k <= vectorUB; k += 2) {
    tmp_5 = _mm_loadu_pd(&t_d_data[k]);
    _mm_storeu_pd(&n_0_data[k], _mm_mul_pd(tmp_5, tmp_5));
  }

  if ((rtu_GnssNavBus_DIMS1->A_f1 == t_d_size[1]) &&
      ((rtu_GnssNavBus_DIMS1->A_f1 == 1 ? t_d_size[1] :
        rtu_GnssNavBus_DIMS1->A_f1) == rtu_GnssNavBus_DIMS1->A_f0) &&
      (rtu_GnssNavBus_DIMS1->A_f2 == t_d_size[1]) &&
      ((rtu_GnssNavBus_DIMS1->A_f0 == 1 ? rtu_GnssNavBus_DIMS1->A_f1 == 1 ?
        t_d_size[1] : rtu_GnssNavBus_DIMS1->A_f1 : rtu_GnssNavBus_DIMS1->A_f0) ==
       (rtu_GnssNavBus_DIMS1->A_f2 == 1 ? t_d_size[1] :
        rtu_GnssNavBus_DIMS1->A_f2)) && (rtu_GnssNavBus_DIMS1->E ==
       rtu_GnssNavBus_DIMS1->SQRT_A) && ((rtu_GnssNavBus_DIMS1->E == 1 ?
        rtu_GnssNavBus_DIMS1->SQRT_A : rtu_GnssNavBus_DIMS1->E) == E_k_size[1]) &&
      (((rtu_GnssNavBus_DIMS1->A_f0 == 1 ? rtu_GnssNavBus_DIMS1->A_f1 == 1 ?
         t_d_size[1] : rtu_GnssNavBus_DIMS1->A_f1 : rtu_GnssNavBus_DIMS1->A_f0) ==
        1 ? rtu_GnssNavBus_DIMS1->A_f2 == 1 ? t_d_size[1] :
        rtu_GnssNavBus_DIMS1->A_f2 : rtu_GnssNavBus_DIMS1->A_f0 == 1 ?
        rtu_GnssNavBus_DIMS1->A_f1 == 1 ? t_d_size[1] :
        rtu_GnssNavBus_DIMS1->A_f1 : rtu_GnssNavBus_DIMS1->A_f0) ==
       ((rtu_GnssNavBus_DIMS1->E == 1 ? rtu_GnssNavBus_DIMS1->SQRT_A :
         rtu_GnssNavBus_DIMS1->E) == 1 ? E_k_size[1] : rtu_GnssNavBus_DIMS1->E ==
        1 ? rtu_GnssNavBus_DIMS1->SQRT_A : rtu_GnssNavBus_DIMS1->E))) {
    t_k_size[0] = 1;
    t_k_size[1] = rtu_GnssNavBus_DIMS1->A_f0;
    loop_ub = rtu_GnssNavBus_DIMS1->A_f0;
    scalarLB = (rtu_GnssNavBus_DIMS1->A_f0 / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d tmp_0;
      __m128d tmp_1;
      __m128d tmp_2;
      __m128d tmp_3;
      tmp_5 = _mm_loadu_pd(&rtu_GnssNavBus->A_f1[k]);
      tmp_4 = _mm_loadu_pd(&t_d_data[k]);
      tmp = _mm_loadu_pd(&rtu_GnssNavBus->A_f0[k]);
      tmp_0 = _mm_loadu_pd(&rtu_GnssNavBus->A_f2[k]);
      tmp_1 = _mm_loadu_pd(&rtu_GnssNavBus->E[k]);
      tmp_2 = _mm_loadu_pd(&rtu_GnssNavBus->SQRT_A[k]);
      tmp_3 = _mm_loadu_pd(&E_k_data[k]);
      _mm_storeu_pd(&t_k_data[k], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
        (tmp_5, tmp_4), tmp), _mm_mul_pd(_mm_mul_pd(tmp_4, tmp_4), tmp_0)),
        _mm_mul_pd(_mm_mul_pd(_mm_mul_pd(_mm_set1_pd(-4.44280763339306E-10),
        tmp_1), tmp_2), tmp_3)));
    }

    for (k = scalarLB; k < loop_ub; k++) {
      t_d = t_d_data[k];
      t_k_data[k] = ((rtu_GnssNavBus->A_f1[k] * t_d + rtu_GnssNavBus->A_f0[k]) +
                     t_d * t_d * rtu_GnssNavBus->A_f2[k]) +
        -4.44280763339306E-10 * rtu_GnssNavBus->E[k] * rtu_GnssNavBus->SQRT_A[k]
        * E_k_data[k];
    }
  } else {
    GNSSPreP_binary_expand_op_hmra2(t_k_data, t_k_size, rtu_GnssNavBus,
      rtu_GnssNavBus_DIMS1, t_d_data, t_d_size, E_k_data, E_k_size);
  }

  if (rtu_enableSatClockCorr != 0.0) {
    if (t_k_size[1] == rtu_GnssNavBus_DIMS1->SVID) {
      i = t_k_size[1];
      loop_ub = t_k_size[1];
      for (k = 0; k < loop_ub; k++) {
        tmp_data[k] = rtu_delta_t_sv_EGNOS[static_cast<int32_T>
          (rtu_GnssNavBus->SVID[k]) - 1] + t_k_data[k];
      }
    } else {
      GNSSPrePr_binary_expand_op_hmra(tmp_data, &i, t_k_data, t_k_size,
        rtu_delta_t_sv_EGNOS, rtu_GnssNavBus, rtu_GnssNavBus_DIMS1);
    }

    localDW->SFunction_DIMS3 = i;
    if (i - 1 >= 0) {
      std::memcpy(&localB->deltaTimeSV[0], &tmp_data[0], static_cast<uint32_T>(i)
                  * sizeof(real_T));
    }

    if ((rtu_GnssNavBus_DIMS1->A_f2 == t_d_size[1]) &&
        ((rtu_GnssNavBus_DIMS1->A_f2 == 1 ? t_d_size[1] :
          rtu_GnssNavBus_DIMS1->A_f2) == rtu_GnssNavBus_DIMS1->A_f1)) {
      i = rtu_GnssNavBus_DIMS1->A_f1;
      loop_ub = rtu_GnssNavBus_DIMS1->A_f1;
      scalarLB = (rtu_GnssNavBus_DIMS1->A_f1 / 2) << 1;
      vectorUB = scalarLB - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        tmp_5 = _mm_loadu_pd(&rtu_GnssNavBus->A_f2[k]);
        tmp_4 = _mm_loadu_pd(&t_d_data[k]);
        tmp = _mm_loadu_pd(&rtu_GnssNavBus->A_f1[k]);
        _mm_storeu_pd(&tmp_data[k], _mm_add_pd(_mm_mul_pd(_mm_mul_pd(_mm_set1_pd
          (2.0), tmp_5), tmp_4), tmp));
      }

      for (k = scalarLB; k < loop_ub; k++) {
        tmp_data[k] = 2.0 * rtu_GnssNavBus->A_f2[k] * t_d_data[k] +
          rtu_GnssNavBus->A_f1[k];
      }
    } else {
      GNSSPrePro_binary_expand_op_hmr(tmp_data, &i, rtu_GnssNavBus,
        rtu_GnssNavBus_DIMS1, t_d_data, t_d_size);
    }

    localDW->SFunction_DIMS4 = i;
    if (i - 1 >= 0) {
      std::memcpy(&localB->drTimeCorr[0], &tmp_data[0], static_cast<uint32_T>(i)
                  * sizeof(real_T));
    }
  } else {
    k = static_cast<int8_T>(t_k_size[1]);
    localDW->SFunction_DIMS3 = static_cast<int8_T>(t_k_size[1]);
    if (k - 1 >= 0) {
      std::memset(&localB->deltaTimeSV[0], 0, static_cast<uint32_T>(k) * sizeof
                  (real_T));
    }

    i = static_cast<int8_T>(rtu_GnssNavBus_DIMS1->A_f1 == 1 ?
      rtu_GnssNavBus_DIMS1->A_f2 == 1 ? t_d_size[1] : rtu_GnssNavBus_DIMS1->A_f2
      : rtu_GnssNavBus_DIMS1->A_f1);
    localDW->SFunction_DIMS4 = static_cast<int8_T>(rtu_GnssNavBus_DIMS1->A_f1 ==
      1 ? rtu_GnssNavBus_DIMS1->A_f2 == 1 ? t_d_size[1] :
      rtu_GnssNavBus_DIMS1->A_f2 : rtu_GnssNavBus_DIMS1->A_f1);
    if (i - 1 >= 0) {
      std::memset(&localB->drTimeCorr[0], 0, static_cast<uint32_T>(i) * sizeof
                  (real_T));
    }
  }

  if (*rtu_pseudorange_DIMS1 == t_k_size[1]) {
    i = *rtu_pseudorange_DIMS1;
    loop_ub = *rtu_pseudorange_DIMS1;
    scalarLB = (*rtu_pseudorange_DIMS1 / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp_5 = _mm_loadu_pd(&t_sv_emission_data[k]);
      tmp_4 = _mm_loadu_pd(&t_k_data[k]);
      _mm_storeu_pd(&tmp_data[k], _mm_sub_pd(tmp_5, tmp_4));
    }

    for (k = scalarLB; k < loop_ub; k++) {
      tmp_data[k] = t_sv_emission_data[k] - t_k_data[k];
    }
  } else {
    GNSSPreProc_binary_expand_op_hm(tmp_data, &i, t_sv_emission_data,
      t_sv_emission_size, t_k_data, t_k_size);
  }

  localDW->SFunction_DIMS2 = i;
  if (i - 1 >= 0) {
    std::memcpy(&localB->timeEmissionCorrected[0], &tmp_data[0],
                static_cast<uint32_T>(i) * sizeof(real_T));
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
