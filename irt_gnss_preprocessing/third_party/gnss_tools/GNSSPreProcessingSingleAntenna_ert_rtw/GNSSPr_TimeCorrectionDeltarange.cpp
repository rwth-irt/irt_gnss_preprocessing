//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GNSSPr_TimeCorrectionDeltarange.cpp
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
#include "GNSSPr_TimeCorrectionDeltarange.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <cstring>
#include <emmintrin.h>

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_c1(real_T
  in1_data[], int32_T *in1_size, const real_T in2[40], const int32_T *in3, const
  real_T in4[40], const int32_T *in5)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  *in1_size = *in5 == 1 ? *in3 : *in5;
  stride_0_0 = (*in3 != 1);
  stride_1_0 = (*in5 != 1);
  loop_ub = *in5 == 1 ? *in3 : *in5;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in4[i * stride_1_0] * 2.99792458E+8 + in2[i * stride_0_0];
  }
}

//
// Output and update for atomic system:
//    '<S26>/Time Correction Deltarange'
//    '<S34>/Time Correction Deltarange'
//    '<S42>/Time Correction Deltarange'
//    '<S75>/Time Correction Deltarange'
//    '<S83>/Time Correction Deltarange'
//    '<S91>/Time Correction Deltarange'
//    '<S99>/Time Correction Deltarange'
//
void GNSS_preprocessingModelClass::GNSSPr_TimeCorrectionDeltarange(const real_T
  rtu_drTimeCorr[40], const int32_T *rtu_drTimeCorr_DIMS1, const real_T
  rtu_deltarange[40], const int32_T *rtu_deltarange_DIMS1,
  B_TimeCorrectionDeltarange_GN_T *localB, DW_TimeCorrectionDeltarange_G_T
  *localDW)
{
  real_T tmp_data[40];
  int32_T tmp_size;
  if (*rtu_deltarange_DIMS1 == *rtu_drTimeCorr_DIMS1) {
    int32_T scalarLB;
    int32_T vectorUB;
    tmp_size = *rtu_deltarange_DIMS1;
    scalarLB = (*rtu_deltarange_DIMS1 / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T i{0}; i <= vectorUB; i += 2) {
      __m128d tmp;
      __m128d tmp_0;
      tmp = _mm_loadu_pd(&rtu_drTimeCorr[i]);
      tmp_0 = _mm_loadu_pd(&rtu_deltarange[i]);
      _mm_storeu_pd(&tmp_data[i], _mm_add_pd(_mm_mul_pd(tmp, _mm_set1_pd
        (2.99792458E+8)), tmp_0));
    }

    for (int32_T i{scalarLB}; i < *rtu_deltarange_DIMS1; i++) {
      tmp_data[i] = rtu_drTimeCorr[i] * 2.99792458E+8 + rtu_deltarange[i];
    }
  } else {
    GNSSPreProc_binary_expand_op_c1(tmp_data, &tmp_size, rtu_deltarange,
      rtu_deltarange_DIMS1, rtu_drTimeCorr, rtu_drTimeCorr_DIMS1);
  }

  localDW->SFunction_DIMS2 = tmp_size;
  if (tmp_size - 1 >= 0) {
    std::memcpy(&localB->deltarangeCorrected[0], &tmp_data[0], static_cast<
                uint32_T>(tmp_size) * sizeof(real_T));
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
