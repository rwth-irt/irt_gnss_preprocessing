//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: DDR_NavigationDataConversionGAL.cpp
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
#include "DDRTCM_types.h"
#include "DDRTCM.h"
#include <emmintrin.h>
#include "rtwtypes.h"
#include "DDR_NavigationDataConversionGAL.h"

//
// Output and update for atomic system:
//    '<S17>/Navigation Data Conversion GAL'
//    '<S144>/Navigation Data Conversion GAL'
//
void DDRTCM::DDR_NavigationDataConversionGAL(const gnssraw_gal_nav_t
  *rtu_GAL_NAV_raw_Bus, B_NavigationDataConversionGAL_T *localB,
  DW_NavigationDataConversionGA_T *localDW)
{
  __m128d tmp;
  __m128d tmp_0;
  localDW->SFunction_DIMS2.TOW = 36;
  localDW->SFunction_DIMS2.WNc = 36;
  localDW->SFunction_DIMS2.SVID = 36;
  localDW->SFunction_DIMS2.T_gd = 36;
  localDW->SFunction_DIMS2.T_oc = 36;
  for (int32_T i{0}; i < 36; i++) {
    localB->GAL_NavigationData_Bus.TOW[i] = rtu_GAL_NAV_raw_Bus->TOW[i];
    localB->GAL_NavigationData_Bus.WNc[i] = rtu_GAL_NAV_raw_Bus->WNc[i];
    localB->GAL_NavigationData_Bus.SVID[i] = rtu_GAL_NAV_raw_Bus->SVID[i];
    localB->GAL_NavigationData_Bus.T_gd[i] = 0.0;
    localB->GAL_NavigationData_Bus.T_oc[i] = rtu_GAL_NAV_raw_Bus->T_oc[i];
  }

  localDW->SFunction_DIMS2.A_f2 = 36;
  localDW->SFunction_DIMS2.A_f1 = 36;
  localDW->SFunction_DIMS2.A_f0 = 36;
  localDW->SFunction_DIMS2.C_rs = 36;
  localDW->SFunction_DIMS2.DELTA_N = 36;
  localDW->SFunction_DIMS2.M_0 = 36;
  for (int32_T i{0}; i <= 34; i += 2) {
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->A_f2[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.A_f2[i], tmp);
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->A_f1[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.A_f1[i], tmp);
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->A_f0[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.A_f0[i], tmp);
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->C_rs[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.C_rs[i], tmp);
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->DELTA_N[i]);
    tmp_0 = _mm_set1_pd(3.1415926535898);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.DELTA_N[i], _mm_mul_pd(tmp,
      tmp_0));
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->M_0[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.M_0[i], _mm_mul_pd(tmp, tmp_0));
  }

  localDW->SFunction_DIMS2.C_uc = 36;
  localDW->SFunction_DIMS2.E = 36;
  localDW->SFunction_DIMS2.C_us = 36;
  localDW->SFunction_DIMS2.SQRT_A = 36;
  localDW->SFunction_DIMS2.T_oe = 36;
  for (int32_T i{0}; i < 36; i++) {
    localB->GAL_NavigationData_Bus.C_uc[i] = rtu_GAL_NAV_raw_Bus->C_uc[i];
    localB->GAL_NavigationData_Bus.E[i] = rtu_GAL_NAV_raw_Bus->E[i];
    localB->GAL_NavigationData_Bus.C_us[i] = rtu_GAL_NAV_raw_Bus->C_us[i];
    localB->GAL_NavigationData_Bus.SQRT_A[i] = rtu_GAL_NAV_raw_Bus->SQRT_A[i];
    localB->GAL_NavigationData_Bus.T_oe[i] = rtu_GAL_NAV_raw_Bus->T_oe[i];
  }

  localDW->SFunction_DIMS2.C_ic = 36;
  localDW->SFunction_DIMS2.OMEGA_0 = 36;
  localDW->SFunction_DIMS2.C_is = 36;
  localDW->SFunction_DIMS2.I_0 = 36;
  localDW->SFunction_DIMS2.C_rc = 36;
  localDW->SFunction_DIMS2.omega = 36;
  localDW->SFunction_DIMS2.OMEGADOT = 36;
  localDW->SFunction_DIMS2.IDOT = 36;
  for (int32_T i{0}; i <= 34; i += 2) {
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->C_ic[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.C_ic[i], tmp);
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->OMEGA_0[i]);
    tmp_0 = _mm_set1_pd(3.1415926535898);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.OMEGA_0[i], _mm_mul_pd(tmp,
      tmp_0));
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->C_is[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.C_is[i], tmp);
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->I_0[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.I_0[i], _mm_mul_pd(tmp, tmp_0));
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->C_rc[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.C_rc[i], tmp);
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->omega[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.omega[i], _mm_mul_pd(tmp,
      tmp_0));
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->OMEGADOT[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.OMEGADOT[i], _mm_mul_pd(tmp,
      tmp_0));
    tmp = _mm_loadu_pd(&rtu_GAL_NAV_raw_Bus->IDOT[i]);
    _mm_storeu_pd(&localB->GAL_NavigationData_Bus.IDOT[i], _mm_mul_pd(tmp, tmp_0));
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
