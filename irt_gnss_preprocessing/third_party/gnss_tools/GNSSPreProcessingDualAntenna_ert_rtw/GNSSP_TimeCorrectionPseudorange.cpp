//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GNSSP_TimeCorrectionPseudorange.cpp
//
// Code generated for Simulink model 'GNSSPreProcessingDualAntenna'.
//
// Model version                  : 3.8
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Tue Jan 24 11:01:39 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "rtwtypes.h"
#include "GNSSPreProcessingDualAntenna.h"
#include <cstring>
#include <emmintrin.h>
#include "GNSSP_TimeCorrectionPseudorange.h"

void GNSSPreProcessingDualAntenna::GNSSPreProc_binary_expand_op_l5(real_T in1_data[], int32_T *in1_size, const real_T
    in2[40], const int32_T *in3, const real_T in4[40], const int32_T *in5)
{
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    *in1_size = *in5 == 1 ? *in3 : *in5;
    stride_0_0 = (*in3 != 1);
    stride_1_0 = (*in5 != 1);
    loop_ub = *in5 == 1 ? *in3 : *in5;
    for (int32_T i{0}; i < loop_ub; i++)
    {
        in1_data[i] = in4[i * stride_1_0] * 2.99792458E+8 + in2[i * stride_0_0];
    }
}

//
// Output and update for atomic system:
//    '<S32>/Time Correction Pseudorange'
//    '<S40>/Time Correction Pseudorange'
//    '<S48>/Time Correction Pseudorange'
//    '<S81>/Time Correction Pseudorange'
//    '<S89>/Time Correction Pseudorange'
//    '<S97>/Time Correction Pseudorange'
//    '<S105>/Time Correction Pseudorange'
//    '<S159>/Time Correction Pseudorange'
//    '<S167>/Time Correction Pseudorange'
//    '<S175>/Time Correction Pseudorange'
//    ...
//
void GNSSPreProcessingDualAntenna::GNSSP_TimeCorrectionPseudorange(const real_T rtu_deltaTimeSV[40], const int32_T
    *rtu_deltaTimeSV_DIMS1, const real_T rtu_pseudorange[40], const int32_T *rtu_pseudorange_DIMS1,
    B_TimeCorrectionPseudorange_G_T *localB, DW_TimeCorrectionPseudorange__T *localDW)
{
    int32_T tmp_size;
    if (*rtu_pseudorange_DIMS1 == *rtu_deltaTimeSV_DIMS1)
    {
        int32_T scalarLB;
        int32_T vectorUB;
        tmp_size = *rtu_pseudorange_DIMS1;
        scalarLB = (*rtu_pseudorange_DIMS1 / 2) << 1;
        vectorUB = scalarLB - 2;
        for (int32_T i{0}; i <= vectorUB; i += 2)
        {
            __m128d tmp;
            __m128d tmp_0;
            tmp = _mm_loadu_pd(&rtu_deltaTimeSV[i]);
            tmp_0 = _mm_loadu_pd(&rtu_pseudorange[i]);
            _mm_storeu_pd(&localB->tmp_data[i], _mm_add_pd(_mm_mul_pd(tmp, _mm_set1_pd(2.99792458E+8)), tmp_0));
        }

        for (int32_T i{scalarLB}; i < *rtu_pseudorange_DIMS1; i++)
        {
            localB->tmp_data[i] = rtu_deltaTimeSV[i] * 2.99792458E+8 + rtu_pseudorange[i];
        }
    }
    else
    {
        GNSSPreProc_binary_expand_op_l5(localB->tmp_data, &tmp_size, rtu_pseudorange, rtu_pseudorange_DIMS1,
            rtu_deltaTimeSV, rtu_deltaTimeSV_DIMS1);
    }

    localDW->SFunction_DIMS2 = tmp_size;
    if (tmp_size - 1 >= 0)
    {
        std::memcpy(&localB->pseudorangeCorrected[0], &localB->tmp_data[0], static_cast<uint32_T>(tmp_size) * sizeof
                    (real_T));
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
