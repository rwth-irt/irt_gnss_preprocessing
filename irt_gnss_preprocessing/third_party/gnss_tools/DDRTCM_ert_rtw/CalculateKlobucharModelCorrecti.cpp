//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateKlobucharModelCorrecti.cpp
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
#include "DDRTCM_private.h"
#include "CalculateKlobucharModelCorrecti.h"

//
// Output and update for atomic system:
//    '<S56>/Calculate Klobuchar Model Correction'
//    '<S183>/Calculate Klobuchar Model Correction'
//
void DDRTCM::CalculateKlobucharModelCorrecti(const real_T rtu_userPosLlh[3],
  const real_T rtu_elevationAngle[40], const int32_T *rtu_elevationAngle_DIMS1,
  const real_T rtu_azimuthAngle[40], const int32_T rtu_satPosEcef_DIMS1[2],
  real_T rtu_TOW, const gnssraw_gps_ion_t *rtu_GpsIonBus, boolean_T
  rtu_enableKlobucharCorrection, B_CalculateKlobucharModelCorr_T *localB,
  DW_CalculateKlobucharModelCor_T *localDW)
{
  if (rtu_enableKlobucharCorrection) {
    if (rtu_satPosEcef_DIMS1[1] == 1) {
      localDW->SFunction_DIMS2 = 1;
      localB->klobucharCorrection[0] = 0.0;
    } else {
      real_T userPosLlh_idx_0;
      real_T userPosLlh_idx_1;
      int32_T SFunction_DIMS2_tmp;
      int32_T vectorUB;
      localDW->SFunction_DIMS2 = rtu_satPosEcef_DIMS1[0];
      userPosLlh_idx_0 = rtu_userPosLlh[0] / 3.1415926535897931;
      userPosLlh_idx_1 = rtu_userPosLlh[1] / 3.1415926535897931;
      SFunction_DIMS2_tmp = (*rtu_elevationAngle_DIMS1 / 2) << 1;
      vectorUB = SFunction_DIMS2_tmp - 2;
      for (int32_T SFunction_DIMS2_tmp_tmp{0}; SFunction_DIMS2_tmp_tmp <=
           vectorUB; SFunction_DIMS2_tmp_tmp += 2) {
        __m128d tmp;
        tmp = _mm_loadu_pd(&rtu_elevationAngle[SFunction_DIMS2_tmp_tmp]);
        _mm_storeu_pd(&localB->elevationAngle_data[SFunction_DIMS2_tmp_tmp],
                      _mm_div_pd(tmp, _mm_set1_pd(3.1415926535897931)));
      }

      for (int32_T SFunction_DIMS2_tmp_tmp{SFunction_DIMS2_tmp};
           SFunction_DIMS2_tmp_tmp < *rtu_elevationAngle_DIMS1;
           SFunction_DIMS2_tmp_tmp++) {
        localB->elevationAngle_data[SFunction_DIMS2_tmp_tmp] =
          rtu_elevationAngle[SFunction_DIMS2_tmp_tmp] / 3.1415926535897931;
      }

      SFunction_DIMS2_tmp = rtu_satPosEcef_DIMS1[0];
      for (int32_T SFunction_DIMS2_tmp_tmp{0}; SFunction_DIMS2_tmp_tmp <
           SFunction_DIMS2_tmp; SFunction_DIMS2_tmp_tmp++) {
        localB->central_angle = 0.0137 / (localB->
          elevationAngle_data[SFunction_DIMS2_tmp_tmp] + 0.11) - 0.022;
        localB->latitude_ipp = localB->central_angle * std::cos
          (rtu_azimuthAngle[SFunction_DIMS2_tmp_tmp]) + userPosLlh_idx_0;
        if (localB->latitude_ipp > 0.416) {
          localB->latitude_ipp = 0.416;
        } else if (localB->latitude_ipp < -0.416) {
          localB->latitude_ipp = -0.416;
        }

        localB->longitude_ipp = localB->central_angle * std::sin
          (rtu_azimuthAngle[SFunction_DIMS2_tmp_tmp]) / std::cos
          (localB->latitude_ipp * 3.1415926535897931) + userPosLlh_idx_1;
        localB->central_angle = 43200.0 * localB->longitude_ipp + rtu_TOW;
        while ((!(localB->central_angle >= 0.0)) || (!(localB->central_angle <=
                 86400.0))) {
          if (localB->central_angle < 0.0) {
            localB->central_angle += 86400.0;
          } else {
            localB->central_angle -= 86400.0;
          }
        }

        localB->latitude_ipp += std::cos((localB->longitude_ipp - 1.617) *
          3.1415926535897931) * 0.064;
        localB->longitude_ipp = ((rtu_GpsIonBus->beta_1 * localB->latitude_ipp +
          rtu_GpsIonBus->beta_0) + rtu_GpsIonBus->beta_2 * localB->latitude_ipp *
          localB->latitude_ipp) + rtu_GpsIonBus->beta_3 * localB->latitude_ipp *
          localB->latitude_ipp * localB->latitude_ipp;
        if (localB->longitude_ipp < 72000.0) {
          localB->longitude_ipp = 72000.0;
        }

        localB->latitude_ipp = ((rtu_GpsIonBus->alpha_1 * localB->latitude_ipp +
          rtu_GpsIonBus->alpha_0) + rtu_GpsIonBus->alpha_2 *
          localB->latitude_ipp * localB->latitude_ipp) + rtu_GpsIonBus->alpha_3 *
          localB->latitude_ipp * localB->latitude_ipp * localB->latitude_ipp;
        if (localB->latitude_ipp < 0.0) {
          localB->latitude_ipp = 0.0;
        }

        localB->central_angle = (localB->central_angle - 50400.0) *
          6.2831853071795862 / localB->longitude_ipp;
        if ((localB->central_angle >= 1.57) || (localB->central_angle <= -1.57))
        {
          localB->central_angle = (rt_powd_snf(0.53 -
            localB->elevationAngle_data[SFunction_DIMS2_tmp_tmp], 3.0) * 16.0 +
            1.0) * 5.0E-9;
        } else {
          localB->longitude_ipp = localB->central_angle * localB->central_angle;
          localB->central_angle = ((localB->longitude_ipp *
            localB->central_angle * localB->central_angle / 24.0 + (1.0 -
            localB->longitude_ipp / 2.0)) * localB->latitude_ipp + 5.0E-9) *
            (rt_powd_snf(0.53 - localB->
                         elevationAngle_data[SFunction_DIMS2_tmp_tmp], 3.0) *
             16.0 + 1.0);
        }

        localB->klobucharCorrection[SFunction_DIMS2_tmp_tmp] =
          localB->central_angle * 2.99792458E+8;
      }
    }
  } else {
    localDW->SFunction_DIMS2 = static_cast<int8_T>(*rtu_elevationAngle_DIMS1);
    if (static_cast<int8_T>(*rtu_elevationAngle_DIMS1) - 1 >= 0) {
      std::memset(&localB->klobucharCorrection[0], 0, static_cast<uint32_T>(
        static_cast<int8_T>(*rtu_elevationAngle_DIMS1)) * sizeof(real_T));
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
