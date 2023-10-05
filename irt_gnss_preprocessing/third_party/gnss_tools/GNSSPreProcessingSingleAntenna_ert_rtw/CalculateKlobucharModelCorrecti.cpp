//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateKlobucharModelCorrecti.cpp
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
#include "CalculateKlobucharModelCorrecti.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <cstring>
#include <emmintrin.h>
#include <cmath>
#include "GNSSPreProcessingSingleAntenna_private.h"

// Output and update for atomic system: '<S51>/Calculate Klobuchar Model Correction'
void GNSS_preprocessingModelClass::CalculateKlobucharModelCorrecti(const real_T
  rtu_userPosLlh[3], const real_T rtu_elevationAngle[40], const int32_T
  *rtu_elevationAngle_DIMS1, const real_T rtu_azimuthAngle[40], const int32_T
  rtu_satPosEcef_DIMS1[2], real_T rtu_TOW, const gnssraw_gps_ion_t
  *rtu_GpsIonBus, boolean_T rtu_enableKlobucharCorrection,
  B_CalculateKlobucharModelCorr_T *localB, DW_CalculateKlobucharModelCor_T
  *localDW)
{
  real_T elevationAngle_data[40];
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
        _mm_storeu_pd(&elevationAngle_data[SFunction_DIMS2_tmp_tmp], _mm_div_pd
                      (tmp, _mm_set1_pd(3.1415926535897931)));
      }

      for (int32_T SFunction_DIMS2_tmp_tmp{SFunction_DIMS2_tmp};
           SFunction_DIMS2_tmp_tmp < *rtu_elevationAngle_DIMS1;
           SFunction_DIMS2_tmp_tmp++) {
        elevationAngle_data[SFunction_DIMS2_tmp_tmp] =
          rtu_elevationAngle[SFunction_DIMS2_tmp_tmp] / 3.1415926535897931;
      }

      SFunction_DIMS2_tmp = rtu_satPosEcef_DIMS1[0];
      for (int32_T SFunction_DIMS2_tmp_tmp{0}; SFunction_DIMS2_tmp_tmp <
           SFunction_DIMS2_tmp; SFunction_DIMS2_tmp_tmp++) {
        real_T central_angle;
        real_T latitude_ipp;
        real_T longitude_ipp;
        central_angle = 0.0137 / (elevationAngle_data[SFunction_DIMS2_tmp_tmp] +
          0.11) - 0.022;
        latitude_ipp = central_angle * std::cos
          (rtu_azimuthAngle[SFunction_DIMS2_tmp_tmp]) + userPosLlh_idx_0;
        if (latitude_ipp > 0.416) {
          latitude_ipp = 0.416;
        } else if (latitude_ipp < -0.416) {
          latitude_ipp = -0.416;
        }

        longitude_ipp = central_angle * std::sin
          (rtu_azimuthAngle[SFunction_DIMS2_tmp_tmp]) / std::cos(latitude_ipp *
          3.1415926535897931) + userPosLlh_idx_1;
        central_angle = 43200.0 * longitude_ipp + rtu_TOW;
        while ((!(central_angle >= 0.0)) || (!(central_angle <= 86400.0))) {
          if (central_angle < 0.0) {
            central_angle += 86400.0;
          } else {
            central_angle -= 86400.0;
          }
        }

        latitude_ipp += std::cos((longitude_ipp - 1.617) * 3.1415926535897931) *
          0.064;
        longitude_ipp = ((rtu_GpsIonBus->beta_1 * latitude_ipp +
                          rtu_GpsIonBus->beta_0) + rtu_GpsIonBus->beta_2 *
                         latitude_ipp * latitude_ipp) + rtu_GpsIonBus->beta_3 *
          latitude_ipp * latitude_ipp * latitude_ipp;
        if (longitude_ipp < 72000.0) {
          longitude_ipp = 72000.0;
        }

        latitude_ipp = ((rtu_GpsIonBus->alpha_1 * latitude_ipp +
                         rtu_GpsIonBus->alpha_0) + rtu_GpsIonBus->alpha_2 *
                        latitude_ipp * latitude_ipp) + rtu_GpsIonBus->alpha_3 *
          latitude_ipp * latitude_ipp * latitude_ipp;
        if (latitude_ipp < 0.0) {
          latitude_ipp = 0.0;
        }

        central_angle = (central_angle - 50400.0) * 6.2831853071795862 /
          longitude_ipp;
        if ((central_angle >= 1.57) || (central_angle <= -1.57)) {
          central_angle = (rt_powd_snf(0.53 -
            elevationAngle_data[SFunction_DIMS2_tmp_tmp], 3.0) * 16.0 + 1.0) *
            5.0E-9;
        } else {
          longitude_ipp = central_angle * central_angle;
          central_angle = ((longitude_ipp * central_angle * central_angle / 24.0
                            + (1.0 - longitude_ipp / 2.0)) * latitude_ipp +
                           5.0E-9) * (rt_powd_snf(0.53 -
            elevationAngle_data[SFunction_DIMS2_tmp_tmp], 3.0) * 16.0 + 1.0);
        }

        localB->klobucharCorrection[SFunction_DIMS2_tmp_tmp] = central_angle *
          2.99792458E+8;
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
