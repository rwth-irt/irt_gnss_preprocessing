//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_sys_GPSFrequencyStream_13.cpp
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
#include "rt_sys_GPSFrequencyStream_13.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <emmintrin.h>
#include "GNSSPreProcessingSingleAntenna_private.h"
#include <cstring>

//
// Output and update for atomic system:
//    '<S18>/Signal Noise Variance'
//    '<S19>/Signal Noise Variance'
//    '<S20>/Signal Noise Variance'
//    '<S65>/Signal Noise Variance'
//    '<S66>/Signal Noise Variance'
//    '<S67>/Signal Noise Variance'
//    '<S68>/Signal Noise Variance'
//
void GNSS_preprocessingModelClass::GNSSPreProc_SignalNoiseVariance(const real_T
  rtu_carrierToNoiseRatio[40], const int32_T *rtu_carrierToNoiseRatio_DIMS1,
  boolean_T rtu_use_measured_variance, const real_T rtu_pr_sigma[40], const
  int32_T *rtu_pr_sigma_DIMS1, const real_T rtu_cp_sigma[40], const int32_T
  *rtu_cp_sigma_DIMS1, B_SignalNoiseVariance_GNSSPre_T *localB,
  DW_SignalNoiseVariance_GNSSPr_T *localDW)
{
  real_T tmp_data[40];
  real_T varargin_2_tmp_data[40];
  if (rtu_use_measured_variance) {
    localDW->SFunction_DIMS2 = *rtu_pr_sigma_DIMS1;
    for (int32_T i{0}; i < *rtu_pr_sigma_DIMS1; i++) {
      localB->variancePseudorange[i] = rtu_pr_sigma[i];
    }

    localDW->SFunction_DIMS3 = *rtu_cp_sigma_DIMS1;
    for (int32_T i{0}; i < *rtu_cp_sigma_DIMS1; i++) {
      localB->varianceDeltarange[i] = rtu_cp_sigma[i];
    }
  } else {
    int32_T scalarLB;
    int32_T varargin_2_tmp_size_idx_0;
    int32_T vectorUB;
    varargin_2_tmp_size_idx_0 = *rtu_carrierToNoiseRatio_DIMS1;
    scalarLB = (*rtu_carrierToNoiseRatio_DIMS1 / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T i{0}; i <= vectorUB; i += 2) {
      __m128d tmp;
      tmp = _mm_loadu_pd(&rtu_carrierToNoiseRatio[i]);
      _mm_storeu_pd(&varargin_2_tmp_data[i], _mm_div_pd(_mm_mul_pd(tmp,
        _mm_set1_pd(-1.0)), _mm_set1_pd(10.0)));
    }

    for (int32_T i{scalarLB}; i < *rtu_carrierToNoiseRatio_DIMS1; i++) {
      varargin_2_tmp_data[i] = -rtu_carrierToNoiseRatio[i] / 10.0;
    }

    for (int32_T i{0}; i < varargin_2_tmp_size_idx_0; i++) {
      tmp_data[i] = rt_powd_snf(10.0, varargin_2_tmp_data[i]);
    }

    localDW->SFunction_DIMS2 = *rtu_carrierToNoiseRatio_DIMS1;
    if (*rtu_carrierToNoiseRatio_DIMS1 - 1 >= 0) {
      std::memcpy(&localB->variancePseudorange[0], &tmp_data[0], static_cast<
                  uint32_T>(*rtu_carrierToNoiseRatio_DIMS1) * sizeof(real_T));
    }

    for (int32_T i{0}; i < varargin_2_tmp_size_idx_0; i++) {
      tmp_data[i] = rt_powd_snf(10.0, varargin_2_tmp_data[i]);
    }

    localDW->SFunction_DIMS3 = *rtu_carrierToNoiseRatio_DIMS1;
    if (*rtu_carrierToNoiseRatio_DIMS1 - 1 >= 0) {
      std::memcpy(&localB->varianceDeltarange[0], &tmp_data[0],
                  static_cast<uint32_T>(*rtu_carrierToNoiseRatio_DIMS1) * sizeof
                  (real_T));
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
