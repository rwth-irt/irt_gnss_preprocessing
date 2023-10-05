//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GNS_NavigationDataConversionGPS.cpp
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
#include "GNSSPreProcessingDualAntenna_types.h"
#include "GNSSPreProcessingDualAntenna.h"
#include <emmintrin.h>
#include "rtwtypes.h"
#include "GNS_NavigationDataConversionGPS.h"

//
// Output and update for atomic system:
//    '<S17>/Navigation Data Conversion GPS'
//    '<S144>/Navigation Data Conversion GPS'
//
void GNSSPreProcessingDualAntenna::GNS_NavigationDataConversionGPS(const gnssraw_gps_nav_t *rtu_GpsNavBus,
    B_NavigationDataConversionGPS_T *localB, DW_NavigationDataConversionGP_T *localDW)
{
    __m128d tmp;
    localDW->SFunction_DIMS2.TOW = 37;
    localDW->SFunction_DIMS2.WNc = 37;
    localDW->SFunction_DIMS2.SVID = 37;
    localDW->SFunction_DIMS2.T_gd = 37;
    localDW->SFunction_DIMS2.T_oc = 37;
    for (int32_T i{0}; i < 37; i++)
    {
        localB->GpsNavBusReshaped.TOW[i] = rtu_GpsNavBus->TOW[i];
        localB->GpsNavBusReshaped.WNc[i] = rtu_GpsNavBus->WNc[i];
        localB->GpsNavBusReshaped.SVID[i] = rtu_GpsNavBus->SVID[i];
        localB->GpsNavBusReshaped.T_gd[i] = rtu_GpsNavBus->T_gd[i];
        localB->GpsNavBusReshaped.T_oc[i] = rtu_GpsNavBus->T_oc[i];
    }

    localDW->SFunction_DIMS2.A_f2 = 37;
    localDW->SFunction_DIMS2.A_f1 = 37;
    localDW->SFunction_DIMS2.A_f0 = 37;
    localDW->SFunction_DIMS2.C_rs = 37;
    localDW->SFunction_DIMS2.DELTA_N = 37;
    for (int32_T i{0}; i <= 34; i += 2)
    {
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->A_f2[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.A_f2[i], tmp);
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->A_f1[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.A_f1[i], tmp);
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->A_f0[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.A_f0[i], tmp);
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->C_rs[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.C_rs[i], tmp);
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->DELTA_N[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.DELTA_N[i], _mm_mul_pd(tmp, _mm_set1_pd(3.1415926535897931)));
    }

    for (int32_T i{36}; i < 37; i++)
    {
        localB->GpsNavBusReshaped.A_f2[i] = rtu_GpsNavBus->A_f2[i];
        localB->GpsNavBusReshaped.A_f1[i] = rtu_GpsNavBus->A_f1[i];
        localB->GpsNavBusReshaped.A_f0[i] = rtu_GpsNavBus->A_f0[i];
        localB->GpsNavBusReshaped.C_rs[i] = rtu_GpsNavBus->C_rs[i];
        localB->GpsNavBusReshaped.DELTA_N[i] = rtu_GpsNavBus->DELTA_N[i] * 3.1415926535897931;
    }

    localDW->SFunction_DIMS2.M_0 = 37;
    for (int32_T i{0}; i <= 34; i += 2)
    {
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->M_0[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.M_0[i], _mm_mul_pd(tmp, _mm_set1_pd(3.1415926535897931)));
    }

    for (int32_T i{36}; i < 37; i++)
    {
        localB->GpsNavBusReshaped.M_0[i] = rtu_GpsNavBus->M_0[i] * 3.1415926535897931;
    }

    localDW->SFunction_DIMS2.C_uc = 37;
    localDW->SFunction_DIMS2.E = 37;
    localDW->SFunction_DIMS2.C_us = 37;
    localDW->SFunction_DIMS2.SQRT_A = 37;
    localDW->SFunction_DIMS2.T_oe = 37;
    for (int32_T i{0}; i < 37; i++)
    {
        localB->GpsNavBusReshaped.C_uc[i] = rtu_GpsNavBus->C_uc[i];
        localB->GpsNavBusReshaped.E[i] = rtu_GpsNavBus->E[i];
        localB->GpsNavBusReshaped.C_us[i] = rtu_GpsNavBus->C_us[i];
        localB->GpsNavBusReshaped.SQRT_A[i] = rtu_GpsNavBus->SQRT_A[i];
        localB->GpsNavBusReshaped.T_oe[i] = rtu_GpsNavBus->T_oe[i];
    }

    localDW->SFunction_DIMS2.C_ic = 37;
    localDW->SFunction_DIMS2.OMEGA_0 = 37;
    for (int32_T i{0}; i <= 34; i += 2)
    {
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->C_ic[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.C_ic[i], tmp);
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->OMEGA_0[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.OMEGA_0[i], _mm_mul_pd(tmp, _mm_set1_pd(3.1415926535897931)));
    }

    for (int32_T i{36}; i < 37; i++)
    {
        localB->GpsNavBusReshaped.C_ic[i] = rtu_GpsNavBus->C_ic[i];
        localB->GpsNavBusReshaped.OMEGA_0[i] = rtu_GpsNavBus->OMEGA_0[i] * 3.1415926535897931;
    }

    localDW->SFunction_DIMS2.C_is = 37;
    localDW->SFunction_DIMS2.I_0 = 37;
    for (int32_T i{0}; i <= 34; i += 2)
    {
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->C_is[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.C_is[i], tmp);
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->I_0[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.I_0[i], _mm_mul_pd(tmp, _mm_set1_pd(3.1415926535897931)));
    }

    for (int32_T i{36}; i < 37; i++)
    {
        localB->GpsNavBusReshaped.C_is[i] = rtu_GpsNavBus->C_is[i];
        localB->GpsNavBusReshaped.I_0[i] = rtu_GpsNavBus->I_0[i] * 3.1415926535897931;
    }

    localDW->SFunction_DIMS2.C_rc = 37;
    localDW->SFunction_DIMS2.omega = 37;
    for (int32_T i{0}; i <= 34; i += 2)
    {
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->C_rc[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.C_rc[i], tmp);
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->omega[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.omega[i], _mm_mul_pd(tmp, _mm_set1_pd(3.1415926535897931)));
    }

    for (int32_T i{36}; i < 37; i++)
    {
        localB->GpsNavBusReshaped.C_rc[i] = rtu_GpsNavBus->C_rc[i];
        localB->GpsNavBusReshaped.omega[i] = rtu_GpsNavBus->omega[i] * 3.1415926535897931;
    }

    localDW->SFunction_DIMS2.OMEGADOT = 37;
    for (int32_T i{0}; i <= 34; i += 2)
    {
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->OMEGADOT[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.OMEGADOT[i], _mm_mul_pd(tmp, _mm_set1_pd(3.1415926535897931)));
    }

    for (int32_T i{36}; i < 37; i++)
    {
        localB->GpsNavBusReshaped.OMEGADOT[i] = rtu_GpsNavBus->OMEGADOT[i] * 3.1415926535897931;
    }

    localDW->SFunction_DIMS2.IDOT = 37;
    for (int32_T i{0}; i <= 34; i += 2)
    {
        tmp = _mm_loadu_pd(&rtu_GpsNavBus->IDOT[i]);
        _mm_storeu_pd(&localB->GpsNavBusReshaped.IDOT[i], _mm_mul_pd(tmp, _mm_set1_pd(3.1415926535897931)));
    }

    for (int32_T i{36}; i < 37; i++)
    {
        localB->GpsNavBusReshaped.IDOT[i] = rtu_GpsNavBus->IDOT[i] * 3.1415926535897931;
    }
}

//
// File trailer for generated code.
//
// [EOF]
//
