//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: DDRT_TimeCorrectionCarrierphase.cpp
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
#include "DDRTCM.h"
#include <cstring>
#include <emmintrin.h>
#include "DDRT_TimeCorrectionCarrierphase.h"

void DDRTCM::DDRTCM_binary_expand_op_g(real_T in1_data[], int32_T *in1_size,
  const real_T in2[40], const int32_T *in3, const real_T in4[40], const int32_T *
  in5, real_T in6)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  *in1_size = *in5 == 1 ? *in3 : *in5;
  stride_0_0 = (*in3 != 1);
  stride_1_0 = (*in5 != 1);
  loop_ub = *in5 == 1 ? *in3 : *in5;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in4[i * stride_1_0] / in6 * 2.99792458E+8 + in2[i * stride_0_0];
  }
}

//
// Output and update for atomic system:
//    '<S31>/Time Correction Carrierphase'
//    '<S39>/Time Correction Carrierphase'
//    '<S47>/Time Correction Carrierphase'
//    '<S80>/Time Correction Carrierphase'
//    '<S88>/Time Correction Carrierphase'
//    '<S96>/Time Correction Carrierphase'
//    '<S104>/Time Correction Carrierphase'
//    '<S158>/Time Correction Carrierphase'
//    '<S166>/Time Correction Carrierphase'
//    '<S174>/Time Correction Carrierphase'
//    ...
//
void DDRTCM::DDRT_TimeCorrectionCarrierphase(const real_T rtu_deltaTimeSV[40],
  const int32_T *rtu_deltaTimeSV_DIMS1, const real_T rtu_carrierphase[40], const
  int32_T *rtu_carrierphase_DIMS1, real_T rtu_Signal_in_Use,
  B_TimeCorrectionCarrierphase__T *localB, DW_TimeCorrectionCarrierphase_T
  *localDW)
{
  int32_T tmp_size;
  if (rtu_Signal_in_Use == 1.0) {
    localB->Lambda0 = 0.19029367279836487;
  } else {
    localB->Lambda0 = 0.24421021342456825;
  }

  if (*rtu_carrierphase_DIMS1 == *rtu_deltaTimeSV_DIMS1) {
    int32_T scalarLB;
    int32_T vectorUB;
    tmp_size = *rtu_carrierphase_DIMS1;
    scalarLB = (*rtu_carrierphase_DIMS1 / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T i{0}; i <= vectorUB; i += 2) {
      __m128d tmp;
      __m128d tmp_0;
      tmp = _mm_loadu_pd(&rtu_deltaTimeSV[i]);
      tmp_0 = _mm_loadu_pd(&rtu_carrierphase[i]);
      _mm_storeu_pd(&localB->tmp_data[i], _mm_add_pd(_mm_mul_pd(_mm_div_pd(tmp,
        _mm_set1_pd(localB->Lambda0)), _mm_set1_pd(2.99792458E+8)), tmp_0));
    }

    for (int32_T i{scalarLB}; i < *rtu_carrierphase_DIMS1; i++) {
      localB->tmp_data[i] = rtu_deltaTimeSV[i] / localB->Lambda0 * 2.99792458E+8
        + rtu_carrierphase[i];
    }
  } else {
    DDRTCM_binary_expand_op_g(localB->tmp_data, &tmp_size, rtu_carrierphase,
      rtu_carrierphase_DIMS1, rtu_deltaTimeSV, rtu_deltaTimeSV_DIMS1,
      localB->Lambda0);
  }

  localDW->SFunction_DIMS2 = tmp_size;
  if (tmp_size - 1 >= 0) {
    std::memcpy(&localB->carrierphaseCorrected[0], &localB->tmp_data[0],
                static_cast<uint32_T>(tmp_size) * sizeof(real_T));
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
