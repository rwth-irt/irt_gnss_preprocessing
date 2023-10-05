//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GNSSPreProcessingSingleAntenna.cpp
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
#include "GNSSPreProcessingSingleAntenna.h"
#include "GNSSPreProcessingSingleAntenna_types.h"
#include "rtwtypes.h"
#include <cstring>
#include <cmath>
#include <emmintrin.h>
#include "GNSSPreProcessingSingleAntenna_private.h"
#include "rt_defines.h"
#include "GNSSPreProcessingSingleAntenna_capi.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Named constants for Chart: '<S125>/choose correction mode'
const uint8_T GNSSPr_IN_GPS_Klobuchar_Galileo{ 3U };

const uint8_T GNSSPreProc_IN_waiting_for_RTCM{ 4U };

const uint8_T GNSSPreProce_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T GNSSPreProcess_IN_Dualfrequency{ 2U };

const uint8_T GNSSPreProcessi_IN_DGPS_Galileo{ 1U };

const uint8_T GNSSPreProcessingS_IN_DGPS_only{ 2U };

const uint8_T GNSSPreProcessingSingle_IN_DGPS{ 1U };

const uint8_T GNSSPre_IN_Waiting_for_more_sat{ 3U };

const uint8_T GN_IN_GPS_Dualfrequency_Galileo{ 1U };

const uint8_T GN_IN_Waiting_for_more_dual_sat{ 2U };

void GNSS_preprocessingModelClass::GNSSPreProcess_binary_expand_op(real_T in1[3],
  const real_T in2_data[], const int32_T in2_size[2], int32_T in3, const real_T
  in4[3])
{
  int32_T stride_0_1;
  stride_0_1 = (in2_size[1] != 1);
  in1[0] = in2_data[in3] - in4[0];
  in1[1] = in2_data[in2_size[0] * stride_0_1 + in3] - in4[1];
  in1[2] = in2_data[(stride_0_1 << 1) * in2_size[0] + in3] - in4[2];
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = std::atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

// Function for MATLAB Function: '<S3>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles'
void GNSS_preprocessingModelClass::calculate_Satellite_Elevation_A(const real_T
  user_Position_llh[3], const real_T satellite_Position_ecef_data[], const
  int32_T satellite_Position_ecef_size[2], real_T elevation_Angle_data[],
  int32_T *elevation_Angle_size, real_T azimuth_Angle_data[], int32_T
  *azimuth_Angle_size)
{
  real_T e_unit_tmp[9];
  real_T e_unit[3];
  real_T line_of_sight[3];
  real_T n_unit[3];
  real_T u_unit[3];
  real_T user_Position_ecef[3];
  real_T N;
  real_T scale;
  real_T t;
  real_T tmp;
  real_T u_unit_0;
  int32_T loop_ub;
  *elevation_Angle_size = satellite_Position_ecef_size[0];
  loop_ub = satellite_Position_ecef_size[0];
  if (loop_ub - 1 >= 0) {
    std::memset(&elevation_Angle_data[0], 0, static_cast<uint32_T>(loop_ub) *
                sizeof(real_T));
  }

  *azimuth_Angle_size = satellite_Position_ecef_size[0];
  loop_ub = satellite_Position_ecef_size[0];
  if (loop_ub - 1 >= 0) {
    std::memset(&azimuth_Angle_data[0], 0, static_cast<uint32_T>(loop_ub) *
                sizeof(real_T));
  }

  scale = std::cos(user_Position_llh[0]);
  N = 6.3995936257584924E+6 / std::sqrt(scale * scale * 0.0067394967422761756 +
    1.0);
  t = std::cos(user_Position_llh[1]);
  user_Position_ecef[0] = (N + user_Position_llh[2]) * scale * t;
  u_unit_0 = std::sin(user_Position_llh[1]);
  user_Position_ecef[1] = (N + user_Position_llh[2]) * std::cos
    (user_Position_llh[0]) * u_unit_0;
  tmp = std::sin(user_Position_llh[0]);
  user_Position_ecef[2] = (0.99330562000985889 * N + user_Position_llh[2]) * tmp;
  e_unit_tmp[0] = -u_unit_0;
  e_unit_tmp[1] = t;
  e_unit_tmp[2] = 0.0;
  e_unit_tmp[3] = -tmp * t;
  e_unit_tmp[4] = -std::sin(user_Position_llh[0]) * u_unit_0;
  e_unit_tmp[5] = scale;
  e_unit_tmp[6] = scale * t;
  e_unit_tmp[7] = scale * u_unit_0;
  e_unit_tmp[8] = tmp;
  for (int32_T i_0{0}; i_0 <= 0; i_0 += 2) {
    __m128d tmp_0;
    __m128d tmp_1;
    __m128d tmp_2;
    __m128d tmp_3;
    __m128d tmp_4;
    __m128d tmp_5;
    __m128d tmp_6;
    tmp_0 = _mm_loadu_pd(&e_unit_tmp[i_0]);
    tmp_3 = _mm_set1_pd(0.0);
    tmp_4 = _mm_mul_pd(tmp_0, tmp_3);
    tmp_1 = _mm_loadu_pd(&e_unit_tmp[i_0 + 3]);
    tmp_5 = _mm_mul_pd(tmp_1, tmp_3);
    tmp_2 = _mm_loadu_pd(&e_unit_tmp[i_0 + 6]);
    tmp_6 = _mm_mul_pd(tmp_2, tmp_3);
    _mm_storeu_pd(&e_unit[i_0], _mm_add_pd(tmp_6, _mm_add_pd(tmp_5, _mm_add_pd
      (tmp_3, tmp_0))));
    tmp_0 = _mm_add_pd(tmp_4, tmp_3);
    _mm_storeu_pd(&n_unit[i_0], _mm_add_pd(tmp_6, _mm_add_pd(tmp_0, tmp_1)));
    _mm_storeu_pd(&u_unit[i_0], _mm_add_pd(_mm_add_pd(tmp_5, tmp_0), tmp_2));
  }

  for (int32_T i_0{2}; i_0 < 3; i_0++) {
    scale = e_unit_tmp[i_0];
    N = scale;
    u_unit_0 = scale * 0.0;
    scale = e_unit_tmp[i_0 + 3];
    N += scale * 0.0;
    t = u_unit_0 + scale;
    u_unit_0 += scale * 0.0;
    scale = e_unit_tmp[i_0 + 6];
    e_unit[i_0] = scale * 0.0 + N;
    n_unit[i_0] = scale * 0.0 + t;
    u_unit[i_0] = u_unit_0 + scale;
  }

  loop_ub = satellite_Position_ecef_size[0];
  for (int32_T i{0}; i < loop_ub; i++) {
    if (satellite_Position_ecef_size[1] == 3) {
      for (int32_T i_0{0}; i_0 < 3; i_0++) {
        line_of_sight[i_0] =
          satellite_Position_ecef_data[satellite_Position_ecef_size[0] * i_0 + i]
          - user_Position_ecef[i_0];
      }
    } else {
      GNSSPreProcess_binary_expand_op(line_of_sight,
        satellite_Position_ecef_data, satellite_Position_ecef_size, i,
        user_Position_ecef);
    }

    scale = 3.3121686421112381E-170;
    N = std::abs(line_of_sight[0]);
    if (N > 3.3121686421112381E-170) {
      u_unit_0 = 1.0;
      scale = N;
    } else {
      t = N / 3.3121686421112381E-170;
      u_unit_0 = t * t;
    }

    N = std::abs(line_of_sight[1]);
    if (N > scale) {
      t = scale / N;
      u_unit_0 = u_unit_0 * t * t + 1.0;
      scale = N;
    } else {
      t = N / scale;
      u_unit_0 += t * t;
    }

    N = std::abs(line_of_sight[2]);
    if (N > scale) {
      t = scale / N;
      u_unit_0 = u_unit_0 * t * t + 1.0;
      scale = N;
    } else {
      t = N / scale;
      u_unit_0 += t * t;
    }

    u_unit_0 = scale * std::sqrt(u_unit_0);
    line_of_sight[0] /= u_unit_0;
    line_of_sight[1] /= u_unit_0;
    line_of_sight[2] /= u_unit_0;
    elevation_Angle_data[i] = std::asin((line_of_sight[0] * u_unit[0] +
      line_of_sight[1] * u_unit[1]) + line_of_sight[2] * u_unit[2]);
    azimuth_Angle_data[i] = rt_atan2d_snf((line_of_sight[0] * e_unit[0] +
      line_of_sight[1] * e_unit[1]) + line_of_sight[2] * e_unit[2],
      (line_of_sight[0] * n_unit[0] + line_of_sight[1] * n_unit[1]) +
      line_of_sight[2] * n_unit[2]);
  }
}

//
// Output and update for atomic system:
//    '<S3>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles'
//    '<S3>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles1'
//    '<S3>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles2'
//
void GNSS_preprocessingModelClass::ConvertGNSSMeasuremendVariableT(const
  GNSS_Measurement *rtu_GNSSMeasurementVariable, const GNSS_Measurement_size
  *rtu_GNSSMeasurementVariab_DIMS1, const real_T rtu_user_pos_llh[3],
  GNSSMeasurementFixed *rty_GNSSMeasurementFixed, real_T
  *rty_sizeOfMesasurements)
{
  real_T rtu_GNSSMeasurementVariable_dat[120];
  real_T azimuth_angle_data[40];
  real_T elevation_angle_data[40];
  int32_T rtu_GNSSMeasurementVariable_siz[2];
  int32_T i;
  int32_T loop_ub;
  int32_T loop_ub_0;
  int32_T nb;
  int32_T rtu_GNSSMeasurementVariab_DIM_0;
  std::memset(&rty_GNSSMeasurementFixed->satellite_position[0], 0, 120U * sizeof
              (real_T));
  std::memset(&rty_GNSSMeasurementFixed->satellite_velocity[0], 0, 120U * sizeof
              (real_T));
  std::memset(&rty_GNSSMeasurementFixed->PRN[0], 0, 40U * sizeof(uint16_T));
  std::memset(&rty_GNSSMeasurementFixed->pseudorange[0], 0, 40U * sizeof(real_T));
  std::memset(&rty_GNSSMeasurementFixed->pseudorange_raw[0], 0, 40U * sizeof
              (real_T));
  std::memset(&rty_GNSSMeasurementFixed->pseudorange_satclk_corrected[0], 0, 40U
              * sizeof(real_T));
  std::memset(&rty_GNSSMeasurementFixed->deltarange[0], 0, 40U * sizeof(real_T));
  std::memset(&rty_GNSSMeasurementFixed->deltarange_raw[0], 0, 40U * sizeof
              (real_T));
  std::memset(&rty_GNSSMeasurementFixed->deltarange_satclk_corrected[0], 0, 40U *
              sizeof(real_T));
  std::memset(&rty_GNSSMeasurementFixed->variance_pseudorange[0], 0, 40U *
              sizeof(real_T));
  std::memset(&rty_GNSSMeasurementFixed->variance_pseudorange_measured[0], 0,
              40U * sizeof(real_T));
  std::memset(&rty_GNSSMeasurementFixed->variance_deltarange[0], 0, 40U * sizeof
              (real_T));
  std::memset(&rty_GNSSMeasurementFixed->carrierphase[0], 0, 40U * sizeof(real_T));
  std::memset(&rty_GNSSMeasurementFixed->carrierphase_raw[0], 0, 40U * sizeof
              (real_T));
  std::memset(&rty_GNSSMeasurementFixed->carrierphase_satclk_corrected[0], 0,
              40U * sizeof(real_T));
  std::memset(&rty_GNSSMeasurementFixed->variance_carrierphase_measured[0], 0,
              40U * sizeof(real_T));
  std::memset(&rty_GNSSMeasurementFixed->locktime[0], 0, 40U * sizeof(real32_T));
  std::memset(&rty_GNSSMeasurementFixed->CN0[0], 0, 40U * sizeof(real_T));
  std::memset(&rty_GNSSMeasurementFixed->elevation_angle[0], 0, 40U * sizeof
              (real_T));
  std::memset(&rty_GNSSMeasurementFixed->azimuth_angle[0], 0, 40U * sizeof
              (real_T));
  rty_GNSSMeasurementFixed->time_receive =
    rtu_GNSSMeasurementVariable->time_receive;
  rtu_GNSSMeasurementVariab_DIM_0 =
    rtu_GNSSMeasurementVariab_DIMS1->satellite_position[0];
  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  loop_ub_0 = rtu_GNSSMeasurementVariab_DIMS1->satellite_position[1];
  for (i = 0; i < loop_ub_0; i++) {
    for (nb = 0; nb <= loop_ub; nb++) {
      rty_GNSSMeasurementFixed->satellite_position[nb + 40 * i] =
        rtu_GNSSMeasurementVariable->
        satellite_position[rtu_GNSSMeasurementVariab_DIM_0 * i + nb];
    }
  }

  rtu_GNSSMeasurementVariab_DIM_0 =
    rtu_GNSSMeasurementVariab_DIMS1->satellite_velocity[0];
  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  loop_ub_0 = rtu_GNSSMeasurementVariab_DIMS1->satellite_velocity[1];
  for (i = 0; i < loop_ub_0; i++) {
    for (nb = 0; nb <= loop_ub; nb++) {
      rty_GNSSMeasurementFixed->satellite_velocity[nb + 40 * i] =
        rtu_GNSSMeasurementVariable->
        satellite_velocity[rtu_GNSSMeasurementVariab_DIM_0 * i + nb];
    }
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->PRN[0],
                &rtu_GNSSMeasurementVariable->PRN[0], static_cast<uint32_T>
                (loop_ub + 1) * sizeof(uint16_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->CN0[0],
                &rtu_GNSSMeasurementVariable->CN0[0], static_cast<uint32_T>
                (loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->locktime[0],
                &rtu_GNSSMeasurementVariable->locktime[0], static_cast<uint32_T>
                (loop_ub + 1) * sizeof(real32_T));
  }

  rty_GNSSMeasurementFixed->base_position[0] =
    rtu_GNSSMeasurementVariable->base_position[0];
  rty_GNSSMeasurementFixed->base_position[1] =
    rtu_GNSSMeasurementVariable->base_position[1];
  rty_GNSSMeasurementFixed->base_position[2] =
    rtu_GNSSMeasurementVariable->base_position[2];
  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->pseudorange[0],
                &rtu_GNSSMeasurementVariable->pseudorange[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->pseudorange_raw[0],
                &rtu_GNSSMeasurementVariable->pseudorange_raw[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->pseudorange_satclk_corrected[0],
                &rtu_GNSSMeasurementVariable->pseudorange_satclk_corrected[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->deltarange[0],
                &rtu_GNSSMeasurementVariable->deltarange[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->deltarange_raw[0],
                &rtu_GNSSMeasurementVariable->deltarange_raw[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->deltarange_satclk_corrected[0],
                &rtu_GNSSMeasurementVariable->deltarange_satclk_corrected[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->carrierphase[0],
                &rtu_GNSSMeasurementVariable->carrierphase[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->carrierphase_raw[0],
                &rtu_GNSSMeasurementVariable->carrierphase_raw[0], static_cast<
                uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->carrierphase_satclk_corrected[0],
                &rtu_GNSSMeasurementVariable->carrierphase_satclk_corrected[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->variance_pseudorange[0],
                &rtu_GNSSMeasurementVariable->variance_pseudorange[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->variance_deltarange[0],
                &rtu_GNSSMeasurementVariable->variance_deltarange[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->variance_pseudorange_measured[0],
                &rtu_GNSSMeasurementVariable->variance_pseudorange_measured[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  if (loop_ub >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->variance_carrierphase_measured[0],
                &rtu_GNSSMeasurementVariable->variance_carrierphase_measured[0],
                static_cast<uint32_T>(loop_ub + 1) * sizeof(real_T));
  }

  rtu_GNSSMeasurementVariab_DIM_0 =
    rtu_GNSSMeasurementVariab_DIMS1->satellite_position[0];
  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    loop_ub = -1;
  } else {
    loop_ub = rtu_GNSSMeasurementVariab_DIMS1->PRN - 1;
  }

  loop_ub_0 = rtu_GNSSMeasurementVariab_DIMS1->satellite_position[1];
  rtu_GNSSMeasurementVariable_siz[0] = loop_ub + 1;
  rtu_GNSSMeasurementVariable_siz[1] =
    rtu_GNSSMeasurementVariab_DIMS1->satellite_position[1];
  for (i = 0; i < loop_ub_0; i++) {
    for (nb = 0; nb <= loop_ub; nb++) {
      rtu_GNSSMeasurementVariable_dat[nb + (loop_ub + 1) * i] =
        rtu_GNSSMeasurementVariable->
        satellite_position[rtu_GNSSMeasurementVariab_DIM_0 * i + nb];
    }
  }

  calculate_Satellite_Elevation_A(rtu_user_pos_llh,
    rtu_GNSSMeasurementVariable_dat, rtu_GNSSMeasurementVariable_siz,
    elevation_angle_data, &i, azimuth_angle_data, &nb);
  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    nb = 0;
  } else {
    nb = rtu_GNSSMeasurementVariab_DIMS1->PRN;
  }

  if (nb - 1 >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->elevation_angle[0],
                &elevation_angle_data[0], static_cast<uint32_T>(nb) * sizeof
                (real_T));
  }

  if (rtu_GNSSMeasurementVariab_DIMS1->PRN < 1) {
    nb = 0;
  } else {
    nb = rtu_GNSSMeasurementVariab_DIMS1->PRN;
  }

  if (nb - 1 >= 0) {
    std::memcpy(&rty_GNSSMeasurementFixed->azimuth_angle[0],
                &azimuth_angle_data[0], static_cast<uint32_T>(nb) * sizeof
                (real_T));
  }

  *rty_sizeOfMesasurements = rtu_GNSSMeasurementVariab_DIMS1->PRN;
}

// Function for MATLAB Function: '<S55>/Apply Elevation and NaN and Zero Mask'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_any_g(const
  boolean_T x_data[], const int32_T x_size[2], boolean_T y_data[], int32_T
  *y_size)
{
  int32_T c;
  int32_T i1;
  int32_T i2;
  int32_T vstride;
  *y_size = static_cast<int8_T>(x_size[0]);
  vstride = static_cast<int8_T>(x_size[0]);
  if (vstride - 1 >= 0) {
    std::memset(&y_data[0], 0, static_cast<uint32_T>(vstride) * sizeof(boolean_T));
  }

  vstride = x_size[0];
  i2 = (x_size[1] - 1) * x_size[0];
  i1 = 0;
  c = x_size[0];
  for (int32_T j{0}; j < c; j++) {
    int32_T ix;
    boolean_T exitg1;
    i1++;
    i2++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && ((vstride > 0) && (ix <= i2))) {
      if (x_data[ix - 1]) {
        y_data[j] = true;
        exitg1 = true;
      } else {
        ix += vstride;
      }
    }
  }
}

// Function for MATLAB Function: '<S55>/Apply Elevation and NaN and Zero Mask'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_any_gf(const
  boolean_T x_data[], const int32_T *x_size, boolean_T y_data[], int32_T *y_size)
{
  int32_T c;
  int32_T i1;
  int32_T i2;
  *y_size = static_cast<int8_T>(*x_size);
  if (static_cast<int8_T>(*x_size) - 1 >= 0) {
    std::memset(&y_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>(*x_size))
                * sizeof(boolean_T));
  }

  i1 = 0;
  i2 = 0;
  c = *x_size;
  for (int32_T j{0}; j < c; j++) {
    int32_T ix;
    boolean_T exitg1;
    i1++;
    i2++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && ((*x_size > 0) && (ix <= i2))) {
      if (x_data[ix - 1]) {
        y_data[j] = true;
        exitg1 = true;
      } else {
        ix += *x_size;
      }
    }
  }
}

void GNSS_preprocessingModelClass::GNSSPrePro_binary_expand_op_ixk(boolean_T
  in1_data[], int32_T *in1_size, const GNSS_Measurement *in2, const
  GNSS_Measurement_size *in3)
{
  int32_T tmp_size[2];
  int32_T in3_idx_0;
  int32_T in3_idx_1;
  int32_T loop_ub;
  int32_T stride_2_0;
  int32_T tmp_size_0;
  int32_T tmp_size_1;
  int32_T tmp_size_2;
  boolean_T tmp_data[120];
  boolean_T tmp_data_0[40];
  boolean_T tmp_data_1[40];
  boolean_T tmp_data_2[40];
  boolean_T tmp_data_3[40];
  tmp_size[0] = in3->satellite_position[0];
  tmp_size[1] = in3->satellite_position[1];
  loop_ub = in3->satellite_position[0] * in3->satellite_position[1];
  for (tmp_size_2 = 0; tmp_size_2 < loop_ub; tmp_size_2++) {
    tmp_data[tmp_size_2] = std::isnan(in2->satellite_position[tmp_size_2]);
  }

  GNSSPreProcessingSingleAn_any_g(tmp_data, tmp_size, tmp_data_0, &tmp_size_0);
  tmp_size[0] = in3->satellite_velocity[0];
  tmp_size[1] = in3->satellite_velocity[1];
  loop_ub = in3->satellite_velocity[0] * in3->satellite_velocity[1];
  for (tmp_size_2 = 0; tmp_size_2 < loop_ub; tmp_size_2++) {
    tmp_data[tmp_size_2] = std::isnan(in2->satellite_velocity[tmp_size_2]);
  }

  GNSSPreProcessingSingleAn_any_g(tmp_data, tmp_size, tmp_data_1, &tmp_size_1);
  loop_ub = in3->pseudorange;
  for (tmp_size_2 = 0; tmp_size_2 < loop_ub; tmp_size_2++) {
    tmp_data_2[tmp_size_2] = std::isnan(in2->pseudorange[tmp_size_2]);
  }

  GNSSPreProcessingSingleA_any_gf(tmp_data_2, &in3->pseudorange, tmp_data_3,
    &tmp_size_2);
  *in1_size = tmp_size_2 == 1 ? tmp_size_1 == 1 ? tmp_size_0 : tmp_size_1 :
    tmp_size_2;
  in3_idx_0 = (tmp_size_0 != 1);
  in3_idx_1 = (tmp_size_1 != 1);
  stride_2_0 = (tmp_size_2 != 1);
  loop_ub = tmp_size_2 == 1 ? tmp_size_1 == 1 ? tmp_size_0 : tmp_size_1 :
    tmp_size_2;
  for (tmp_size_2 = 0; tmp_size_2 < loop_ub; tmp_size_2++) {
    in1_data[tmp_size_2] = ((!tmp_data_0[tmp_size_2 * in3_idx_0]) &&
      (!tmp_data_1[tmp_size_2 * in3_idx_1]) && (!tmp_data_3[tmp_size_2 *
      stride_2_0]));
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_ix(boolean_T
  in1_data[], int32_T *in1_size, const boolean_T in2[40], const int32_T *in3,
  const boolean_T in4_data[], const int32_T *in4_size, const GNSS_Measurement
  *in5, const GNSS_Measurement_size *in6)
{
  int32_T in5_size[2];
  int32_T in6_idx_0;
  int32_T in6_idx_1;
  int32_T loop_ub;
  int32_T stride_2_0;
  int32_T stride_3_0;
  int32_T stride_4_0;
  int32_T tmp_size;
  int32_T tmp_size_0;
  int32_T tmp_size_1;
  boolean_T in5_data[120];
  boolean_T in5_data_0[40];
  boolean_T tmp_data[40];
  boolean_T tmp_data_0[40];
  boolean_T tmp_data_1[40];
  in5_size[0] = in6->satellite_position[0];
  in5_size[1] = in6->satellite_position[1];
  loop_ub = in6->satellite_position[0] * in6->satellite_position[1];
  for (tmp_size_1 = 0; tmp_size_1 < loop_ub; tmp_size_1++) {
    in5_data[tmp_size_1] = (in5->satellite_position[tmp_size_1] == 0.0);
  }

  GNSSPreProcessingSingleAn_any_g(in5_data, in5_size, tmp_data, &tmp_size);
  in5_size[0] = in6->satellite_velocity[0];
  in5_size[1] = in6->satellite_velocity[1];
  loop_ub = in6->satellite_velocity[0] * in6->satellite_velocity[1];
  for (tmp_size_1 = 0; tmp_size_1 < loop_ub; tmp_size_1++) {
    in5_data[tmp_size_1] = (in5->satellite_velocity[tmp_size_1] == 0.0);
  }

  GNSSPreProcessingSingleAn_any_g(in5_data, in5_size, tmp_data_0, &tmp_size_0);
  loop_ub = in6->pseudorange;
  for (tmp_size_1 = 0; tmp_size_1 < loop_ub; tmp_size_1++) {
    in5_data_0[tmp_size_1] = (in5->pseudorange[tmp_size_1] < 1.0E+6);
  }

  GNSSPreProcessingSingleA_any_gf(in5_data_0, &in6->pseudorange, tmp_data_1,
    &tmp_size_1);
  *in1_size = (tmp_size_1 == 1 ? tmp_size_0 == 1 ? tmp_size : tmp_size_0 :
               tmp_size_1) == 1 ? *in4_size == 1 ? *in3 : *in4_size : tmp_size_1
    == 1 ? tmp_size_0 == 1 ? tmp_size : tmp_size_0 : tmp_size_1;
  in6_idx_0 = (*in3 != 1);
  in6_idx_1 = (*in4_size != 1);
  stride_2_0 = (tmp_size != 1);
  stride_3_0 = (tmp_size_0 != 1);
  stride_4_0 = (tmp_size_1 != 1);
  loop_ub = (tmp_size_1 == 1 ? tmp_size_0 == 1 ? tmp_size : tmp_size_0 :
             tmp_size_1) == 1 ? *in4_size == 1 ? *in3 : *in4_size : tmp_size_1 ==
    1 ? tmp_size_0 == 1 ? tmp_size : tmp_size_0 : tmp_size_1;
  for (tmp_size_1 = 0; tmp_size_1 < loop_ub; tmp_size_1++) {
    in1_data[tmp_size_1] = (in2[tmp_size_1 * in6_idx_0] && in4_data[tmp_size_1 *
      in6_idx_1] && ((!tmp_data[tmp_size_1 * stride_2_0]) &&
                     (!tmp_data_0[tmp_size_1 * stride_3_0]) &&
                     (!tmp_data_1[tmp_size_1 * stride_4_0])));
  }
}

// Function for MATLAB Function: '<S55>/Apply Elevation and NaN and Zero Mask'
boolean_T GNSS_preprocessingModelClass::GNSSPreProcessingSingle_any_gfc(const
  boolean_T x_data[], const int32_T *x_size)
{
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= *x_size)) {
    if (x_data[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  return y;
}

// Output and update for atomic system: '<S55>/Apply Elevation and NaN and Zero Mask'
void GNSS_preprocessingModelClass::ApplyElevationandNaNandZeroMask(const
  GNSS_Measurement *rtu_measurementFrequencyCorrect, const GNSS_Measurement_size
  *rtu_measurementFrequencyC_DIMS1, const boolean_T rtu_elevationMask[40], const
  int32_T *rtu_elevationMask_DIMS1, uint16_T *rty_nan_errCnt,
  B_ApplyElevationandNaNandZero_T *localB, DW_ApplyElevationandNaNandZer_T
  *localDW)
{
  int32_T rtu_measurementFrequencyCorre_5[2];
  int32_T rtu_measurementFrequencyCorre_6[2];
  int32_T rtu_measurementFrequencyCorre_7[2];
  int32_T rtu_measurementFrequencyCorre_9[2];
  int32_T b_i;
  int32_T loop_ub_tmp;
  int32_T loop_ub_tmp_0;
  int32_T nan_mask_size;
  int32_T nan_mask_size_0;
  int32_T rtu_measurementFrequencyC_DIM_0;
  int32_T rtu_measurementFrequencyCorre_8;
  int32_T tmp_size;
  int32_T tmp_size_0;
  int32_T tmp_size_1;
  int32_T tmp_size_2;
  int8_T b_data[40];
  int8_T c_data[40];
  int8_T d_data[40];
  int8_T e_data[40];
  int8_T f_data[40];
  int8_T g_data[40];
  int8_T h_data[40];
  int8_T i_data[40];
  int8_T j_data[40];
  int8_T k_data[40];
  int8_T l_data[40];
  int8_T m_data[40];
  int8_T n_data[40];
  int8_T o_data[40];
  int8_T p_data[40];
  int8_T q_data[40];
  int8_T r_data[40];
  int8_T s_data[40];
  boolean_T rtu_measurementFrequencyCorre_0[120];
  boolean_T rtu_measurementFrequencyCorre_1[120];
  boolean_T rtu_measurementFrequencyCorre_2[120];
  boolean_T rtu_measurementFrequencyCorre_4[120];
  boolean_T mask_all_data[40];
  boolean_T nan_mask_data[40];
  boolean_T nan_mask_data_0[40];
  boolean_T rtu_measurementFrequencyCorre_3[40];
  boolean_T tmp_data[40];
  boolean_T tmp_data_0[40];
  rtu_measurementFrequencyCorre_5[0] =
    rtu_measurementFrequencyC_DIMS1->satellite_position[0];
  rtu_measurementFrequencyCorre_5[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_position[1];
  loop_ub_tmp = rtu_measurementFrequencyC_DIMS1->satellite_position[0] *
    rtu_measurementFrequencyC_DIMS1->satellite_position[1];
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    rtu_measurementFrequencyCorre_0[b_i] = std::isnan
      (rtu_measurementFrequencyCorrect->satellite_position[b_i]);
  }

  rtu_measurementFrequencyCorre_6[0] =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[0];
  rtu_measurementFrequencyCorre_6[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[1];
  loop_ub_tmp_0 = rtu_measurementFrequencyC_DIMS1->satellite_velocity[0] *
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[1];
  for (b_i = 0; b_i < loop_ub_tmp_0; b_i++) {
    rtu_measurementFrequencyCorre_1[b_i] = std::isnan
      (rtu_measurementFrequencyCorrect->satellite_velocity[b_i]);
  }

  rtu_measurementFrequencyCorre_7[0] =
    rtu_measurementFrequencyC_DIMS1->satellite_position[0];
  rtu_measurementFrequencyCorre_7[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_position[1];
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    rtu_measurementFrequencyCorre_2[b_i] = std::isnan
      (rtu_measurementFrequencyCorrect->satellite_position[b_i]);
  }

  GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_2,
    rtu_measurementFrequencyCorre_7, nan_mask_data_0, &nan_mask_size_0);
  rtu_measurementFrequencyCorre_7[0] =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[0];
  rtu_measurementFrequencyCorre_7[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[1];
  for (b_i = 0; b_i < loop_ub_tmp_0; b_i++) {
    rtu_measurementFrequencyCorre_2[b_i] = std::isnan
      (rtu_measurementFrequencyCorrect->satellite_velocity[b_i]);
  }

  tmp_size = rtu_measurementFrequencyC_DIMS1->pseudorange;
  rtu_measurementFrequencyC_DIM_0 = rtu_measurementFrequencyC_DIMS1->pseudorange;
  for (b_i = 0; b_i < rtu_measurementFrequencyC_DIM_0; b_i++) {
    tmp_data[b_i] = std::isnan(rtu_measurementFrequencyCorrect->pseudorange[b_i]);
  }

  GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_0,
    rtu_measurementFrequencyCorre_5, tmp_data_0, &b_i);
  GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_1,
    rtu_measurementFrequencyCorre_6, tmp_data_0,
    &rtu_measurementFrequencyC_DIM_0);
  GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_2,
    rtu_measurementFrequencyCorre_7, tmp_data_0, &tmp_size_1);
  GNSSPreProcessingSingleA_any_gf(tmp_data,
    &rtu_measurementFrequencyC_DIMS1->pseudorange, tmp_data_0, &tmp_size_2);
  if ((b_i == rtu_measurementFrequencyC_DIM_0) && ((nan_mask_size_0 == 1 ?
        tmp_size_1 : nan_mask_size_0) == tmp_size_2)) {
    rtu_measurementFrequencyCorre_5[0] =
      rtu_measurementFrequencyC_DIMS1->satellite_position[0];
    rtu_measurementFrequencyCorre_5[1] =
      rtu_measurementFrequencyC_DIMS1->satellite_position[1];
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      rtu_measurementFrequencyCorre_0[b_i] = std::isnan
        (rtu_measurementFrequencyCorrect->satellite_position[b_i]);
    }

    GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_0,
      rtu_measurementFrequencyCorre_5, nan_mask_data_0, &nan_mask_size_0);
    rtu_measurementFrequencyCorre_5[0] =
      rtu_measurementFrequencyC_DIMS1->satellite_velocity[0];
    rtu_measurementFrequencyCorre_5[1] =
      rtu_measurementFrequencyC_DIMS1->satellite_velocity[1];
    for (b_i = 0; b_i < loop_ub_tmp_0; b_i++) {
      rtu_measurementFrequencyCorre_0[b_i] = std::isnan
        (rtu_measurementFrequencyCorrect->satellite_velocity[b_i]);
    }

    GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_0,
      rtu_measurementFrequencyCorre_5, tmp_data, &tmp_size);
    tmp_size_0 = rtu_measurementFrequencyC_DIMS1->pseudorange;
    rtu_measurementFrequencyC_DIM_0 =
      rtu_measurementFrequencyC_DIMS1->pseudorange;
    for (b_i = 0; b_i < rtu_measurementFrequencyC_DIM_0; b_i++) {
      tmp_data_0[b_i] = std::isnan(rtu_measurementFrequencyCorrect->
        pseudorange[b_i]);
    }

    GNSSPreProcessingSingleA_any_gf(tmp_data_0,
      &rtu_measurementFrequencyC_DIMS1->pseudorange,
      rtu_measurementFrequencyCorre_3, &rtu_measurementFrequencyCorre_8);
    nan_mask_size = nan_mask_size_0;
    for (b_i = 0; b_i < nan_mask_size_0; b_i++) {
      nan_mask_data[b_i] = ((!nan_mask_data_0[b_i]) && (!tmp_data[b_i]) &&
                            (!rtu_measurementFrequencyCorre_3[b_i]));
    }
  } else {
    GNSSPrePro_binary_expand_op_ixk(nan_mask_data, &nan_mask_size,
      rtu_measurementFrequencyCorrect, rtu_measurementFrequencyC_DIMS1);
  }

  rtu_measurementFrequencyCorre_5[0] =
    rtu_measurementFrequencyC_DIMS1->satellite_position[0];
  rtu_measurementFrequencyCorre_5[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_position[1];
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    rtu_measurementFrequencyCorre_0[b_i] =
      (rtu_measurementFrequencyCorrect->satellite_position[b_i] == 0.0);
  }

  rtu_measurementFrequencyCorre_6[0] =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[0];
  rtu_measurementFrequencyCorre_6[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[1];
  for (b_i = 0; b_i < loop_ub_tmp_0; b_i++) {
    rtu_measurementFrequencyCorre_1[b_i] =
      (rtu_measurementFrequencyCorrect->satellite_velocity[b_i] == 0.0);
  }

  rtu_measurementFrequencyCorre_7[0] =
    rtu_measurementFrequencyC_DIMS1->satellite_position[0];
  rtu_measurementFrequencyCorre_7[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_position[1];
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    rtu_measurementFrequencyCorre_2[b_i] =
      (rtu_measurementFrequencyCorrect->satellite_position[b_i] == 0.0);
  }

  GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_2,
    rtu_measurementFrequencyCorre_7, nan_mask_data_0, &nan_mask_size_0);
  rtu_measurementFrequencyCorre_7[0] =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[0];
  rtu_measurementFrequencyCorre_7[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[1];
  for (b_i = 0; b_i < loop_ub_tmp_0; b_i++) {
    rtu_measurementFrequencyCorre_2[b_i] =
      (rtu_measurementFrequencyCorrect->satellite_velocity[b_i] == 0.0);
  }

  rtu_measurementFrequencyCorre_8 = rtu_measurementFrequencyC_DIMS1->pseudorange;
  rtu_measurementFrequencyC_DIM_0 = rtu_measurementFrequencyC_DIMS1->pseudorange;
  for (b_i = 0; b_i < rtu_measurementFrequencyC_DIM_0; b_i++) {
    rtu_measurementFrequencyCorre_3[b_i] =
      (rtu_measurementFrequencyCorrect->pseudorange[b_i] < 1.0E+6);
  }

  rtu_measurementFrequencyCorre_9[0] =
    rtu_measurementFrequencyC_DIMS1->satellite_position[0];
  rtu_measurementFrequencyCorre_9[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_position[1];
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    rtu_measurementFrequencyCorre_4[b_i] =
      (rtu_measurementFrequencyCorrect->satellite_position[b_i] == 0.0);
  }

  GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_4,
    rtu_measurementFrequencyCorre_9, tmp_data, &tmp_size);
  rtu_measurementFrequencyCorre_9[0] =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[0];
  rtu_measurementFrequencyCorre_9[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[1];
  for (b_i = 0; b_i < loop_ub_tmp_0; b_i++) {
    rtu_measurementFrequencyCorre_4[b_i] =
      (rtu_measurementFrequencyCorrect->satellite_velocity[b_i] == 0.0);
  }

  GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_4,
    rtu_measurementFrequencyCorre_9, tmp_data_0, &tmp_size_0);
  rtu_measurementFrequencyC_DIM_0 = rtu_measurementFrequencyC_DIMS1->pseudorange;
  for (b_i = 0; b_i < rtu_measurementFrequencyC_DIM_0; b_i++) {
    nan_mask_data_0[b_i] = (rtu_measurementFrequencyCorrect->pseudorange[b_i] <
      1.0E+6);
  }

  GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_0,
    rtu_measurementFrequencyCorre_5, tmp_data, &b_i);
  GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_1,
    rtu_measurementFrequencyCorre_6, tmp_data, &rtu_measurementFrequencyC_DIM_0);
  GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_2,
    rtu_measurementFrequencyCorre_7, tmp_data, &tmp_size_1);
  GNSSPreProcessingSingleA_any_gf(rtu_measurementFrequencyCorre_3,
    &rtu_measurementFrequencyCorre_8, tmp_data, &tmp_size_2);
  GNSSPreProcessingSingleA_any_gf(nan_mask_data_0,
    &rtu_measurementFrequencyC_DIMS1->pseudorange, tmp_data,
    &rtu_measurementFrequencyCorre_8);
  if ((*rtu_elevationMask_DIMS1 == nan_mask_size) && (b_i ==
       rtu_measurementFrequencyC_DIM_0) && ((nan_mask_size_0 == 1 ? tmp_size_1 :
        nan_mask_size_0) == tmp_size_2) && (((tmp_size == 1 ? tmp_size_0 :
         tmp_size) == 1 ? rtu_measurementFrequencyCorre_8 : tmp_size == 1 ?
        tmp_size_0 : tmp_size) == (*rtu_elevationMask_DIMS1 == 1 ? nan_mask_size
        : *rtu_elevationMask_DIMS1))) {
    rtu_measurementFrequencyCorre_5[0] =
      rtu_measurementFrequencyC_DIMS1->satellite_position[0];
    rtu_measurementFrequencyCorre_5[1] =
      rtu_measurementFrequencyC_DIMS1->satellite_position[1];
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      rtu_measurementFrequencyCorre_0[b_i] =
        (rtu_measurementFrequencyCorrect->satellite_position[b_i] == 0.0);
    }

    GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_0,
      rtu_measurementFrequencyCorre_5, nan_mask_data_0, &nan_mask_size_0);
    rtu_measurementFrequencyCorre_5[0] =
      rtu_measurementFrequencyC_DIMS1->satellite_velocity[0];
    rtu_measurementFrequencyCorre_5[1] =
      rtu_measurementFrequencyC_DIMS1->satellite_velocity[1];
    for (b_i = 0; b_i < loop_ub_tmp_0; b_i++) {
      rtu_measurementFrequencyCorre_0[b_i] =
        (rtu_measurementFrequencyCorrect->satellite_velocity[b_i] == 0.0);
    }

    GNSSPreProcessingSingleAn_any_g(rtu_measurementFrequencyCorre_0,
      rtu_measurementFrequencyCorre_5, tmp_data, &tmp_size);
    rtu_measurementFrequencyC_DIM_0 =
      rtu_measurementFrequencyC_DIMS1->pseudorange;
    for (b_i = 0; b_i < rtu_measurementFrequencyC_DIM_0; b_i++) {
      rtu_measurementFrequencyCorre_3[b_i] =
        (rtu_measurementFrequencyCorrect->pseudorange[b_i] < 1.0E+6);
    }

    GNSSPreProcessingSingleA_any_gf(rtu_measurementFrequencyCorre_3,
      &rtu_measurementFrequencyC_DIMS1->pseudorange, tmp_data_0, &tmp_size_0);
    loop_ub_tmp = *rtu_elevationMask_DIMS1;
    for (b_i = 0; b_i < *rtu_elevationMask_DIMS1; b_i++) {
      mask_all_data[b_i] = (rtu_elevationMask[b_i] && nan_mask_data[b_i] &&
                            ((!nan_mask_data_0[b_i]) && (!tmp_data[b_i]) &&
        (!tmp_data_0[b_i])));
    }
  } else {
    GNSSPreProc_binary_expand_op_ix(mask_all_data, &loop_ub_tmp,
      rtu_elevationMask, rtu_elevationMask_DIMS1, nan_mask_data, &nan_mask_size,
      rtu_measurementFrequencyCorrect, rtu_measurementFrequencyC_DIMS1);
  }

  localB->measurementFrequencyCorrectedMa.time_receive =
    rtu_measurementFrequencyCorrect->time_receive;
  nan_mask_size_0 = loop_ub_tmp - 1;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  tmp_size = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      b_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.satellite_position[0] = tmp_size;
  localDW->SFunction_DIMS2.satellite_position[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_position[1];
  loop_ub_tmp_0 = rtu_measurementFrequencyC_DIMS1->satellite_position[0];
  tmp_size_0 = localDW->SFunction_DIMS2.satellite_position[0];
  rtu_measurementFrequencyC_DIM_0 =
    rtu_measurementFrequencyC_DIMS1->satellite_position[1];
  for (b_i = 0; b_i < rtu_measurementFrequencyC_DIM_0; b_i++) {
    for (loop_ub_tmp = 0; loop_ub_tmp < tmp_size; loop_ub_tmp++) {
      localB->measurementFrequencyCorrectedMa.satellite_position[loop_ub_tmp +
        tmp_size_0 * b_i] = rtu_measurementFrequencyCorrect->satellite_position
        [(loop_ub_tmp_0 * b_i + b_data[loop_ub_tmp]) - 1];
    }
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  tmp_size = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      c_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.satellite_velocity[0] = tmp_size;
  localDW->SFunction_DIMS2.satellite_velocity[1] =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[1];
  loop_ub_tmp_0 = rtu_measurementFrequencyC_DIMS1->satellite_velocity[0];
  tmp_size_0 = localDW->SFunction_DIMS2.satellite_velocity[0];
  rtu_measurementFrequencyC_DIM_0 =
    rtu_measurementFrequencyC_DIMS1->satellite_velocity[1];
  for (b_i = 0; b_i < rtu_measurementFrequencyC_DIM_0; b_i++) {
    for (loop_ub_tmp = 0; loop_ub_tmp < tmp_size; loop_ub_tmp++) {
      localB->measurementFrequencyCorrectedMa.satellite_velocity[loop_ub_tmp +
        tmp_size_0 * b_i] = rtu_measurementFrequencyCorrect->satellite_velocity
        [(loop_ub_tmp_0 * b_i + c_data[loop_ub_tmp]) - 1];
    }
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      d_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.PRN = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.PRN[b_i] =
      rtu_measurementFrequencyCorrect->PRN[d_data[b_i] - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      e_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.pseudorange = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.pseudorange[b_i] =
      rtu_measurementFrequencyCorrect->pseudorange[e_data[b_i] - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      f_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.pseudorange_raw = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.pseudorange_raw[b_i] =
      rtu_measurementFrequencyCorrect->pseudorange_raw[f_data[b_i] - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      g_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.pseudorange_satclk_corrected = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.pseudorange_satclk_corrected[b_i] =
      rtu_measurementFrequencyCorrect->pseudorange_satclk_corrected[g_data[b_i]
      - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      h_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.deltarange = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.deltarange[b_i] =
      rtu_measurementFrequencyCorrect->deltarange[h_data[b_i] - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      i_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.deltarange_raw = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.deltarange_raw[b_i] =
      rtu_measurementFrequencyCorrect->deltarange_raw[i_data[b_i] - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      j_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.deltarange_satclk_corrected = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.deltarange_satclk_corrected[b_i] =
      rtu_measurementFrequencyCorrect->deltarange_satclk_corrected[j_data[b_i] -
      1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      k_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.variance_pseudorange = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.variance_pseudorange[b_i] =
      rtu_measurementFrequencyCorrect->variance_pseudorange[k_data[b_i] - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      l_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.variance_pseudorange_measured = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.variance_pseudorange_measured[b_i] =
      rtu_measurementFrequencyCorrect->variance_pseudorange_measured[l_data[b_i]
      - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      m_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.variance_deltarange = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.variance_deltarange[b_i] =
      rtu_measurementFrequencyCorrect->variance_deltarange[m_data[b_i] - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      n_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.carrierphase = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.carrierphase[b_i] =
      rtu_measurementFrequencyCorrect->carrierphase[n_data[b_i] - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      o_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.carrierphase_raw = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.carrierphase_raw[b_i] =
      rtu_measurementFrequencyCorrect->carrierphase_raw[o_data[b_i] - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      p_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.carrierphase_satclk_corrected = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.carrierphase_satclk_corrected[b_i] =
      rtu_measurementFrequencyCorrect->carrierphase_satclk_corrected[p_data[b_i]
      - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      q_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.variance_carrierphase_measured = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.variance_carrierphase_measured[b_i] =
      rtu_measurementFrequencyCorrect->variance_carrierphase_measured[q_data[b_i]
      - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      r_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.locktime = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.locktime[b_i] =
      rtu_measurementFrequencyCorrect->locktime[r_data[b_i] - 1];
  }

  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      loop_ub_tmp_0++;
    }
  }

  loop_ub_tmp = loop_ub_tmp_0;
  loop_ub_tmp_0 = 0;
  for (b_i = 0; b_i <= nan_mask_size_0; b_i++) {
    if (mask_all_data[b_i]) {
      s_data[loop_ub_tmp_0] = static_cast<int8_T>(b_i + 1);
      loop_ub_tmp_0++;
    }
  }

  localDW->SFunction_DIMS2.CN0 = loop_ub_tmp;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    localB->measurementFrequencyCorrectedMa.CN0[b_i] =
      rtu_measurementFrequencyCorrect->CN0[s_data[b_i] - 1];
  }

  localB->measurementFrequencyCorrectedMa.base_position[0] =
    rtu_measurementFrequencyCorrect->base_position[0];
  localB->measurementFrequencyCorrectedMa.base_position[1] =
    rtu_measurementFrequencyCorrect->base_position[1];
  localB->measurementFrequencyCorrectedMa.base_position[2] =
    rtu_measurementFrequencyCorrect->base_position[2];
  for (b_i = 0; b_i < nan_mask_size; b_i++) {
    nan_mask_data_0[b_i] = !nan_mask_data[b_i];
  }

  if (GNSSPreProcessingSingle_any_gfc(nan_mask_data_0, &nan_mask_size)) {
    uint32_T tmp;
    tmp = localDW->nanerrs + 1U;
    if (localDW->nanerrs + 1U > 65535U) {
      tmp = 65535U;
    }

    localDW->nanerrs = static_cast<uint16_T>(tmp);
  }

  *rty_nan_errCnt = localDW->nanerrs;
}

// Function for MATLAB Function: '<S51>/Calculate Wide Lane Combination'
void GNSS_preprocessingModelClass::GNSSPreProcessing_do_vectors_ig(const
  uint16_T a_data[], const int32_T *a_size, const uint16_T b_data[], const
  int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[],
  int32_T *ia_size, int32_T ib_data[], int32_T *ib_size)
{
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T nc;
  int32_T ncmax;
  if (*a_size <= *b_size) {
    ncmax = *a_size;
  } else {
    ncmax = *b_size;
  }

  *c_size = ncmax;
  *ia_size = ncmax;
  *ib_size = ncmax;
  nc = 0;
  iafirst = 0;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= *a_size) && (iblast <= *b_size)) {
    int32_T b_ialast;
    int32_T b_iblast;
    uint16_T ak;
    uint16_T bk;
    b_ialast = ialast;
    ak = a_data[ialast - 1];
    while ((b_ialast < *a_size) && (a_data[b_ialast] == ak)) {
      b_ialast++;
    }

    ialast = b_ialast;
    b_iblast = iblast;
    bk = b_data[iblast - 1];
    while ((b_iblast < *b_size) && (b_data[b_iblast] == bk)) {
      b_iblast++;
    }

    iblast = b_iblast;
    if (ak == bk) {
      nc++;
      c_data[nc - 1] = ak;
      ia_data[nc - 1] = iafirst + 1;
      ib_data[nc - 1] = ibfirst + 1;
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      ialast = b_ialast + 1;
      iafirst = b_ialast;
    } else {
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    }
  }

  if (ncmax > 0) {
    if (nc < 1) {
      *ia_size = 0;
      *ib_size = 0;
      *c_size = 0;
    } else {
      *ia_size = nc;
      *ib_size = nc;
      *c_size = nc;
    }
  }
}

void GNSS_preprocessingModelClass::GNSSPrePr_binary_expand_op_fr3p
  (GNSS_Measurement *in1, const int32_T in3_data[], const int32_T *in3_size,
   const real_T in4[40], const real_T in6[40], const int32_T in8_data[], const
   int32_T *in8_size)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // Outputs for Enabled SubSystem: '<S3>/GPS' incorporates:
  //   EnablePort: '<S11>/Enable'

  // MATLAB Function: '<S51>/Calculate Wide Lane Combination' incorporates:
  //   BusCreator generated from: '<S51>/Calculate Wide Lane Combination'

  stride_0_0 = (*in3_size != 1);
  stride_1_0 = (*in8_size != 1);
  loop_ub = *in8_size == 1 ? *in3_size : *in8_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1->carrierphase[in3_data[i] - 1] = in4[in3_data[i * stride_0_0] - 1] -
      in6[in8_data[i * stride_1_0] - 1];
  }

  // End of MATLAB Function: '<S51>/Calculate Wide Lane Combination'
  // End of Outputs for SubSystem: '<S3>/GPS'
}

// Function for MATLAB Function: '<S107>/Calculate Dualfrequency Correction with E1 and E5'
boolean_T GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_any_a(const
  real_T x_data[], const int32_T *x_size)
{
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= *x_size)) {
    if (!(x_data[ix - 1] == 0.0)) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S107>/Calculate Dualfrequency Correction with E1 and E5'
void GNSS_preprocessingModelClass::GNSSPreProce_calcCorrection_g0j(const real_T
  prf1_data[], const uint16_T PRN1_data[], const int32_T *PRN1_size, const
  real_T prf2_data[], const uint16_T PRN2_data[], const int32_T *PRN2_size,
  real_T Corr_f1_data[], int32_T *Corr_f1_size)
{
  real_T fixed_f1[150];
  real_T fixed_f2[150];
  int32_T l_data[150];
  int32_T c;
  int32_T i;
  int32_T j;
  int32_T l_size_idx_0;
  int32_T loop_ub;
  uint16_T fixed_PRN[150];
  uint16_T PRN1;
  int8_T idx1_data[40];
  int8_T idx2_data[40];
  uint8_T h_data[150];
  uint8_T k_data[150];
  boolean_T g_data[150];
  std::memset(&fixed_f1[0], 0, 150U * sizeof(real_T));
  std::memset(&fixed_f2[0], 0, 150U * sizeof(real_T));
  std::memset(&fixed_PRN[0], 0, 150U * sizeof(uint16_T));
  *Corr_f1_size = static_cast<int8_T>(*PRN1_size);
  if (static_cast<int8_T>(*PRN1_size) - 1 >= 0) {
    std::memset(&Corr_f1_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>
      (*PRN1_size)) * sizeof(real_T));
  }

  if (*PRN1_size - 1 >= 0) {
    std::memset(&idx2_data[0], 0, static_cast<uint32_T>(*PRN1_size) * sizeof
                (int8_T));
  }

  if (*PRN1_size - 1 >= 0) {
    std::memset(&idx1_data[0], 0, static_cast<uint32_T>(*PRN1_size) * sizeof
                (int8_T));
  }

  c = *PRN1_size;
  for (i = 0; i < c; i++) {
    loop_ub = *PRN2_size;
    for (j = 0; j < loop_ub; j++) {
      if (PRN1_data[i] == PRN2_data[j]) {
        idx1_data[i] = static_cast<int8_T>(i + 1);
        idx2_data[i] = static_cast<int8_T>(j + 1);
      }
    }
  }

  i = *PRN1_size;
  for (c = 0; c < i; c++) {
    int8_T idx1;
    int8_T idx2;
    PRN1 = PRN1_data[c];
    idx2 = idx2_data[c];
    idx1 = idx1_data[c];
    if ((idx1 != 0) && (idx2 != 0)) {
      real_T tmp_1;
      tmp_1 = prf1_data[idx1 - 1];
      if (tmp_1 != 0.0) {
        real_T tmp_2;
        tmp_2 = prf2_data[idx2 - 1];
        if (tmp_2 != 0.0) {
          fixed_PRN[PRN1 - 1] = PRN1;
          fixed_f1[PRN1 - 1] = tmp_1;
          fixed_f2[PRN1 - 1] = tmp_2;
        }
      }
    }
  }

  for (j = 0; j <= 148; j += 2) {
    __m128d tmp;
    __m128d tmp_0;
    tmp = _mm_loadu_pd(&fixed_f2[j]);
    tmp_0 = _mm_loadu_pd(&fixed_f1[j]);
    _mm_storeu_pd(&fixed_f2[j], _mm_div_pd(_mm_mul_pd(_mm_mul_pd(_mm_sub_pd(tmp,
      tmp_0), _mm_set1_pd(-1.7686752926678988)), _mm_set1_pd(1.57542E+9)),
      _mm_set1_pd(1.191795E+9)));
  }

  for (c = 0; c < i; c++) {
    int32_T h_size_idx_0;
    PRN1 = PRN1_data[c];
    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        loop_ub++;
      }
    }

    h_size_idx_0 = loop_ub;
    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        h_data[loop_ub] = static_cast<uint8_T>(j + 1);
        loop_ub++;
      }
    }

    for (j = 0; j < h_size_idx_0; j++) {
      g_data[j] = (fixed_PRN[h_data[j] - 1] == PRN1);
    }

    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        k_data[loop_ub] = static_cast<uint8_T>(j + 1);
        loop_ub++;
      }
    }

    loop_ub = h_size_idx_0 - 1;
    j = 0;
    for (h_size_idx_0 = 0; h_size_idx_0 <= loop_ub; h_size_idx_0++) {
      if (g_data[h_size_idx_0]) {
        j++;
      }
    }

    l_size_idx_0 = j;
    j = 0;
    for (h_size_idx_0 = 0; h_size_idx_0 <= loop_ub; h_size_idx_0++) {
      if (g_data[h_size_idx_0]) {
        l_data[j] = h_size_idx_0 + 1;
        j++;
      }
    }

    for (j = 0; j < l_size_idx_0; j++) {
      fixed_f1[j] = fixed_PRN[k_data[l_data[j] - 1] - 1];
    }

    if (GNSSPreProcessingSingleAn_any_a(fixed_f1, &l_size_idx_0)) {
      Corr_f1_data[c] = fixed_f2[PRN1 - 1];
    }
  }
}

// Function for MATLAB Function: '<S107>/Calculate Dualfrequency Correction with E1 and E5'
void GNSS_preprocessingModelClass::GNSSPreProcessin_calcCorrection(const real_T
  prf1_data[], const uint16_T PRN1_data[], const int32_T *PRN1_size, const
  real_T prf2_data[], const uint16_T PRN2_data[], const int32_T *PRN2_size,
  real_T Corr_f1_data[], int32_T *Corr_f1_size)
{
  real_T fixed_f1[150];
  real_T fixed_f2[150];
  int32_T l_data[150];
  int32_T c;
  int32_T i;
  int32_T j;
  int32_T l_size_idx_0;
  int32_T loop_ub;
  uint16_T fixed_PRN[150];
  uint16_T PRN1;
  int8_T idx1_data[40];
  int8_T idx2_data[40];
  uint8_T h_data[150];
  uint8_T k_data[150];
  boolean_T g_data[150];
  std::memset(&fixed_f1[0], 0, 150U * sizeof(real_T));
  std::memset(&fixed_f2[0], 0, 150U * sizeof(real_T));
  std::memset(&fixed_PRN[0], 0, 150U * sizeof(uint16_T));
  *Corr_f1_size = static_cast<int8_T>(*PRN1_size);
  if (static_cast<int8_T>(*PRN1_size) - 1 >= 0) {
    std::memset(&Corr_f1_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>
      (*PRN1_size)) * sizeof(real_T));
  }

  if (*PRN1_size - 1 >= 0) {
    std::memset(&idx2_data[0], 0, static_cast<uint32_T>(*PRN1_size) * sizeof
                (int8_T));
  }

  if (*PRN1_size - 1 >= 0) {
    std::memset(&idx1_data[0], 0, static_cast<uint32_T>(*PRN1_size) * sizeof
                (int8_T));
  }

  c = *PRN1_size;
  for (i = 0; i < c; i++) {
    loop_ub = *PRN2_size;
    for (j = 0; j < loop_ub; j++) {
      if (PRN1_data[i] == PRN2_data[j]) {
        idx1_data[i] = static_cast<int8_T>(i + 1);
        idx2_data[i] = static_cast<int8_T>(j + 1);
      }
    }
  }

  i = *PRN1_size;
  for (c = 0; c < i; c++) {
    int8_T idx1;
    int8_T idx2;
    PRN1 = PRN1_data[c];
    idx2 = idx2_data[c];
    idx1 = idx1_data[c];
    if ((idx1 != 0) && (idx2 != 0)) {
      real_T tmp_1;
      tmp_1 = prf1_data[idx1 - 1];
      if (tmp_1 != 0.0) {
        real_T tmp_2;
        tmp_2 = prf2_data[idx2 - 1];
        if (tmp_2 != 0.0) {
          fixed_PRN[PRN1 - 1] = PRN1;
          fixed_f1[PRN1 - 1] = tmp_1;
          fixed_f2[PRN1 - 1] = tmp_2;
        }
      }
    }
  }

  for (j = 0; j <= 148; j += 2) {
    __m128d tmp;
    __m128d tmp_0;
    tmp = _mm_loadu_pd(&fixed_f2[j]);
    tmp_0 = _mm_loadu_pd(&fixed_f1[j]);
    _mm_storeu_pd(&fixed_f2[j], _mm_div_pd(_mm_mul_pd(_mm_mul_pd(_mm_sub_pd(tmp,
      tmp_0), _mm_set1_pd(1.688113621199123)), _mm_set1_pd(1.17645E+9)),
      _mm_set1_pd(1.57542E+9)));
  }

  for (c = 0; c < i; c++) {
    int32_T h_size_idx_0;
    PRN1 = PRN1_data[c];
    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        loop_ub++;
      }
    }

    h_size_idx_0 = loop_ub;
    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        h_data[loop_ub] = static_cast<uint8_T>(j + 1);
        loop_ub++;
      }
    }

    for (j = 0; j < h_size_idx_0; j++) {
      g_data[j] = (fixed_PRN[h_data[j] - 1] == PRN1);
    }

    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        k_data[loop_ub] = static_cast<uint8_T>(j + 1);
        loop_ub++;
      }
    }

    loop_ub = h_size_idx_0 - 1;
    j = 0;
    for (h_size_idx_0 = 0; h_size_idx_0 <= loop_ub; h_size_idx_0++) {
      if (g_data[h_size_idx_0]) {
        j++;
      }
    }

    l_size_idx_0 = j;
    j = 0;
    for (h_size_idx_0 = 0; h_size_idx_0 <= loop_ub; h_size_idx_0++) {
      if (g_data[h_size_idx_0]) {
        l_data[j] = h_size_idx_0 + 1;
        j++;
      }
    }

    for (j = 0; j < l_size_idx_0; j++) {
      fixed_f1[j] = fixed_PRN[k_data[l_data[j] - 1] - 1];
    }

    if (GNSSPreProcessingSingleAn_any_a(fixed_f1, &l_size_idx_0)) {
      Corr_f1_data[c] = fixed_f2[PRN1 - 1];
    }
  }
}

// Function for MATLAB Function: '<S107>/Calculate Dualfrequency Correction with E1 and E5'
boolean_T GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_any_aa(const
  boolean_T x_data[], const int32_T *x_size)
{
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= *x_size)) {
    if (x_data[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S107>/Calculate Dualfrequency Correction with E1 and E5'
void GNSS_preprocessingModelClass::GNSSPreProcess_calcCorrection_g(const real_T
  prf1_data[], const uint16_T PRN1_data[], const int32_T *PRN1_size, const
  real_T prf2_data[], const uint16_T PRN2_data[], const int32_T *PRN2_size,
  real_T Corr_f1_data[], int32_T *Corr_f1_size)
{
  real_T fixed_f1[150];
  real_T fixed_f2[150];
  int32_T l_data[150];
  int32_T c;
  int32_T i;
  int32_T j;
  int32_T l_size_idx_0;
  int32_T loop_ub;
  uint16_T fixed_PRN[150];
  uint16_T PRN1;
  int8_T idx1_data[40];
  int8_T idx2_data[40];
  uint8_T h_data[150];
  uint8_T k_data[150];
  boolean_T g_data[150];
  std::memset(&fixed_f1[0], 0, 150U * sizeof(real_T));
  std::memset(&fixed_f2[0], 0, 150U * sizeof(real_T));
  std::memset(&fixed_PRN[0], 0, 150U * sizeof(uint16_T));
  *Corr_f1_size = static_cast<int8_T>(*PRN1_size);
  if (static_cast<int8_T>(*PRN1_size) - 1 >= 0) {
    std::memset(&Corr_f1_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>
      (*PRN1_size)) * sizeof(real_T));
  }

  if (*PRN1_size - 1 >= 0) {
    std::memset(&idx2_data[0], 0, static_cast<uint32_T>(*PRN1_size) * sizeof
                (int8_T));
  }

  if (*PRN1_size - 1 >= 0) {
    std::memset(&idx1_data[0], 0, static_cast<uint32_T>(*PRN1_size) * sizeof
                (int8_T));
  }

  c = *PRN1_size;
  for (i = 0; i < c; i++) {
    loop_ub = *PRN2_size;
    for (j = 0; j < loop_ub; j++) {
      if (PRN1_data[i] == PRN2_data[j]) {
        idx1_data[i] = static_cast<int8_T>(i + 1);
        idx2_data[i] = static_cast<int8_T>(j + 1);
      }
    }
  }

  i = *PRN1_size;
  for (c = 0; c < i; c++) {
    int8_T idx1;
    int8_T idx2;
    PRN1 = PRN1_data[c];
    idx2 = idx2_data[c];
    idx1 = idx1_data[c];
    if ((idx1 != 0) && (idx2 != 0)) {
      real_T tmp_1;
      tmp_1 = prf1_data[idx1 - 1];
      if (tmp_1 != 0.0) {
        real_T tmp_2;
        tmp_2 = prf2_data[idx2 - 1];
        if (tmp_2 != 0.0) {
          fixed_PRN[PRN1 - 1] = PRN1;
          fixed_f1[PRN1 - 1] = tmp_1;
          fixed_f2[PRN1 - 1] = tmp_2;
        }
      }
    }
  }

  for (j = 0; j <= 148; j += 2) {
    __m128d tmp;
    __m128d tmp_0;
    tmp = _mm_loadu_pd(&fixed_f2[j]);
    tmp_0 = _mm_loadu_pd(&fixed_f1[j]);
    _mm_storeu_pd(&fixed_f2[j], _mm_div_pd(_mm_mul_pd(_mm_mul_pd(_mm_sub_pd(tmp,
      tmp_0), _mm_set1_pd(1.8558006535947713)), _mm_set1_pd(1.20714E+9)),
      _mm_set1_pd(1.57542E+9)));
  }

  for (c = 0; c < i; c++) {
    int32_T h_size_idx_0;
    PRN1 = PRN1_data[c];
    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        loop_ub++;
      }
    }

    h_size_idx_0 = loop_ub;
    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        h_data[loop_ub] = static_cast<uint8_T>(j + 1);
        loop_ub++;
      }
    }

    for (j = 0; j < h_size_idx_0; j++) {
      g_data[j] = (fixed_PRN[h_data[j] - 1] == PRN1);
    }

    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        k_data[loop_ub] = static_cast<uint8_T>(j + 1);
        loop_ub++;
      }
    }

    loop_ub = h_size_idx_0 - 1;
    j = 0;
    for (h_size_idx_0 = 0; h_size_idx_0 <= loop_ub; h_size_idx_0++) {
      if (g_data[h_size_idx_0]) {
        j++;
      }
    }

    l_size_idx_0 = j;
    j = 0;
    for (h_size_idx_0 = 0; h_size_idx_0 <= loop_ub; h_size_idx_0++) {
      if (g_data[h_size_idx_0]) {
        l_data[j] = h_size_idx_0 + 1;
        j++;
      }
    }

    for (j = 0; j < l_size_idx_0; j++) {
      fixed_f1[j] = fixed_PRN[k_data[l_data[j] - 1] - 1];
    }

    if (GNSSPreProcessingSingleAn_any_a(fixed_f1, &l_size_idx_0)) {
      Corr_f1_data[c] = fixed_f2[PRN1 - 1];
    }
  }
}

// Function for MATLAB Function: '<S107>/Calculate Dualfrequency Correction with E1 and E5'
void GNSS_preprocessingModelClass::GNSSPreProces_calcCorrection_g0(const real_T
  prf1_data[], const uint16_T PRN1_data[], const int32_T *PRN1_size, const
  real_T prf2_data[], const uint16_T PRN2_data[], const int32_T *PRN2_size,
  real_T Corr_f1_data[], int32_T *Corr_f1_size)
{
  real_T fixed_f1[150];
  real_T fixed_f2[150];
  int32_T l_data[150];
  int32_T c;
  int32_T i;
  int32_T j;
  int32_T l_size_idx_0;
  int32_T loop_ub;
  uint16_T fixed_PRN[150];
  uint16_T PRN1;
  int8_T idx1_data[40];
  int8_T idx2_data[40];
  uint8_T h_data[150];
  uint8_T k_data[150];
  boolean_T g_data[150];
  std::memset(&fixed_f1[0], 0, 150U * sizeof(real_T));
  std::memset(&fixed_f2[0], 0, 150U * sizeof(real_T));
  std::memset(&fixed_PRN[0], 0, 150U * sizeof(uint16_T));
  *Corr_f1_size = static_cast<int8_T>(*PRN1_size);
  if (static_cast<int8_T>(*PRN1_size) - 1 >= 0) {
    std::memset(&Corr_f1_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>
      (*PRN1_size)) * sizeof(real_T));
  }

  if (*PRN1_size - 1 >= 0) {
    std::memset(&idx2_data[0], 0, static_cast<uint32_T>(*PRN1_size) * sizeof
                (int8_T));
  }

  if (*PRN1_size - 1 >= 0) {
    std::memset(&idx1_data[0], 0, static_cast<uint32_T>(*PRN1_size) * sizeof
                (int8_T));
  }

  c = *PRN1_size;
  for (i = 0; i < c; i++) {
    loop_ub = *PRN2_size;
    for (j = 0; j < loop_ub; j++) {
      if (PRN1_data[i] == PRN2_data[j]) {
        idx1_data[i] = static_cast<int8_T>(i + 1);
        idx2_data[i] = static_cast<int8_T>(j + 1);
      }
    }
  }

  i = *PRN1_size;
  for (c = 0; c < i; c++) {
    int8_T idx1;
    int8_T idx2;
    PRN1 = PRN1_data[c];
    idx2 = idx2_data[c];
    idx1 = idx1_data[c];
    if ((idx1 != 0) && (idx2 != 0)) {
      real_T tmp_1;
      tmp_1 = prf1_data[idx1 - 1];
      if (tmp_1 != 0.0) {
        real_T tmp_2;
        tmp_2 = prf2_data[idx2 - 1];
        if (tmp_2 != 0.0) {
          fixed_PRN[PRN1 - 1] = PRN1;
          fixed_f1[PRN1 - 1] = tmp_1;
          fixed_f2[PRN1 - 1] = tmp_2;
        }
      }
    }
  }

  for (j = 0; j <= 148; j += 2) {
    __m128d tmp;
    __m128d tmp_0;
    tmp = _mm_loadu_pd(&fixed_f2[j]);
    tmp_0 = _mm_loadu_pd(&fixed_f1[j]);
    _mm_storeu_pd(&fixed_f2[j], _mm_div_pd(_mm_mul_pd(_mm_mul_pd(_mm_sub_pd(tmp,
      tmp_0), _mm_set1_pd(1.7686752926678988)), _mm_set1_pd(1.191795E+9)),
      _mm_set1_pd(1.57542E+9)));
  }

  for (c = 0; c < i; c++) {
    int32_T h_size_idx_0;
    PRN1 = PRN1_data[c];
    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        loop_ub++;
      }
    }

    h_size_idx_0 = loop_ub;
    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        h_data[loop_ub] = static_cast<uint8_T>(j + 1);
        loop_ub++;
      }
    }

    for (j = 0; j < h_size_idx_0; j++) {
      g_data[j] = (fixed_PRN[h_data[j] - 1] == PRN1);
    }

    loop_ub = 0;
    for (j = 0; j < 150; j++) {
      if (fixed_PRN[j] != 0) {
        k_data[loop_ub] = static_cast<uint8_T>(j + 1);
        loop_ub++;
      }
    }

    loop_ub = h_size_idx_0 - 1;
    j = 0;
    for (h_size_idx_0 = 0; h_size_idx_0 <= loop_ub; h_size_idx_0++) {
      if (g_data[h_size_idx_0]) {
        j++;
      }
    }

    l_size_idx_0 = j;
    j = 0;
    for (h_size_idx_0 = 0; h_size_idx_0 <= loop_ub; h_size_idx_0++) {
      if (g_data[h_size_idx_0]) {
        l_data[j] = h_size_idx_0 + 1;
        j++;
      }
    }

    for (j = 0; j < l_size_idx_0; j++) {
      fixed_f1[j] = fixed_PRN[k_data[l_data[j] - 1] - 1];
    }

    if (GNSSPreProcessingSingleAn_any_a(fixed_f1, &l_size_idx_0)) {
      Corr_f1_data[c] = fixed_f2[PRN1 - 1];
    }
  }
}

// Function for MATLAB Function: '<S111>/Apply Elevation and NaN and Zero Mask'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_any_m(const
  boolean_T x_data[], const int32_T x_size[2], boolean_T y_data[], int32_T
  *y_size)
{
  int32_T c;
  int32_T i1;
  int32_T i2;
  int32_T vstride;
  *y_size = static_cast<int8_T>(x_size[0]);
  vstride = static_cast<int8_T>(x_size[0]);
  if (vstride - 1 >= 0) {
    std::memset(&y_data[0], 0, static_cast<uint32_T>(vstride) * sizeof(boolean_T));
  }

  vstride = x_size[0];
  i2 = (x_size[1] - 1) * x_size[0];
  i1 = 0;
  c = x_size[0];
  for (int32_T j{0}; j < c; j++) {
    int32_T ix;
    boolean_T exitg1;
    i1++;
    i2++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && ((vstride > 0) && (ix <= i2))) {
      if (x_data[ix - 1]) {
        y_data[j] = true;
        exitg1 = true;
      } else {
        ix += vstride;
      }
    }
  }
}

// Function for MATLAB Function: '<S111>/Apply Elevation and NaN and Zero Mask'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_any_m4(const
  boolean_T x_data[], const int32_T *x_size, boolean_T y_data[], int32_T *y_size)
{
  int32_T c;
  int32_T i1;
  int32_T i2;
  *y_size = static_cast<int8_T>(*x_size);
  if (static_cast<int8_T>(*x_size) - 1 >= 0) {
    std::memset(&y_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>(*x_size))
                * sizeof(boolean_T));
  }

  i1 = 0;
  i2 = 0;
  c = *x_size;
  for (int32_T j{0}; j < c; j++) {
    int32_T ix;
    boolean_T exitg1;
    i1++;
    i2++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && ((*x_size > 0) && (ix <= i2))) {
      if (x_data[ix - 1]) {
        y_data[j] = true;
        exitg1 = true;
      } else {
        ix += *x_size;
      }
    }
  }
}

void GNSS_preprocessingModelClass::GNSSPrePro_binary_expand_op_fr3(boolean_T
  in1_data[], int32_T *in1_size, const boolean_T in2[40], int32_T in3, const
  boolean_T in4_data[], const int32_T *in4_size, const boolean_T in5_data[],
  const int32_T *in5_size, const boolean_T in6_data[], const int32_T *in6_size,
  const boolean_T in7_data[], const int32_T *in7_size, const boolean_T in8_data[],
  const int32_T *in8_size)
{
  int32_T in2_size_idx_0;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T stride_2_0;
  int32_T stride_3_0;
  int32_T stride_4_0;
  int32_T stride_5_0;
  int32_T stride_6_0;
  boolean_T in2_data[40];

  // Outputs for Enabled SubSystem: '<S3>/Galileo' incorporates:
  //   EnablePort: '<S12>/Enable'

  // MATLAB Function: '<S111>/Apply Elevation and NaN and Zero Mask'
  in2_size_idx_0 = (*in8_size == 1 ? *in7_size == 1 ? *in6_size : *in7_size :
                    *in8_size) == 1 ? (*in5_size == 1 ? *in4_size == 1 ?
    *in1_size : *in4_size : *in5_size) == 1 ? in3 : *in5_size == 1 ? *in4_size ==
    1 ? *in1_size : *in4_size : *in5_size : *in8_size == 1 ? *in7_size == 1 ?
    *in6_size : *in7_size : *in8_size;
  stride_0_0 = (in3 != 1);
  stride_1_0 = (*in1_size != 1);
  stride_2_0 = (*in4_size != 1);
  stride_3_0 = (*in5_size != 1);
  stride_4_0 = (*in6_size != 1);
  stride_5_0 = (*in7_size != 1);
  stride_6_0 = (*in8_size != 1);
  loop_ub = (*in8_size == 1 ? *in7_size == 1 ? *in6_size : *in7_size : *in8_size)
    == 1 ? (*in5_size == 1 ? *in4_size == 1 ? *in1_size : *in4_size : *in5_size)
    == 1 ? in3 : *in5_size == 1 ? *in4_size == 1 ? *in1_size : *in4_size :
    *in5_size : *in8_size == 1 ? *in7_size == 1 ? *in6_size : *in7_size :
    *in8_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in2_data[i] = (in2[i * stride_0_0] && ((!in1_data[i * stride_1_0]) &&
      (!in4_data[i * stride_2_0]) && (!in5_data[i * stride_3_0])) &&
                   ((!in6_data[i * stride_4_0]) && (!in7_data[i * stride_5_0]) &&
                    (!in8_data[i * stride_6_0])));
  }

  *in1_size = in2_size_idx_0;
  if (in2_size_idx_0 - 1 >= 0) {
    std::memcpy(&in1_data[0], &in2_data[0], static_cast<uint32_T>(in2_size_idx_0)
                * sizeof(boolean_T));
  }

  // End of MATLAB Function: '<S111>/Apply Elevation and NaN and Zero Mask'
  // End of Outputs for SubSystem: '<S3>/Galileo'
}

void GNSS_preprocessingModelClass::emxConvertDynamicMatrixToEmx_40
  (emxArray_real_T_40x3_GNSSPreP_T *emx, const real_T data[120], const int32_T
   size[2])
{
  std::memcpy(&emx->data, (void *)data, sizeof(real_T) * static_cast<uint32_T>
              (size[0] * size[1]));
  std::memcpy(&emx->size, (void *)size, sizeof(int32_T) << 1U);
}

void GNSS_preprocessingModelClass::emxConvertDynamicMatrixToEmx__f
  (emxArray_uint16_T_40_GNSSPreP_T *emx, const uint16_T data[40], const int32_T *
   size)
{
  std::memcpy(&emx->data, (void *)data, sizeof(uint16_T) * static_cast<uint32_T>
              (*size));
  std::memcpy(&emx->size, (void *)size, sizeof(int32_T));
}

void GNSS_preprocessingModelClass::emxConvertDynamicMatrixToEmx_fr
  (emxArray_real_T_40_GNSSPrePro_T *emx, const real_T data[40], const int32_T
   *size)
{
  std::memcpy(&emx->data, (void *)data, sizeof(real_T) * static_cast<uint32_T>
              (*size));
  std::memcpy(&emx->size, (void *)size, sizeof(int32_T));
}

void GNSS_preprocessingModelClass::emxConvertDynamicMatrixToEm_fr3
  (emxArray_real32_T_40_GNSSPreP_T *emx, const real32_T data[40], const int32_T *
   size)
{
  std::memcpy(&emx->data, (void *)data, sizeof(real32_T) * static_cast<uint32_T>
              (*size));
  std::memcpy(&emx->size, (void *)size, sizeof(int32_T));
}

void GNSS_preprocessingModelClass::emxConvertStructToEmx_GNSS_Meas
  (emxArray__GNSS_Measurement_GN_T *emx, const GNSS_Measurement *data, const
   GNSS_Measurement_size *size)
{
  std::memcpy(&emx->time_receive, &data->time_receive, static_cast<uint32_T>
              (sizeof(real_T)));
  emxConvertDynamicMatrixToEmx_40(&emx->satellite_position,
    data->satellite_position, size->satellite_position);
  emxConvertDynamicMatrixToEmx_40(&emx->satellite_velocity,
    data->satellite_velocity, size->satellite_velocity);
  emxConvertDynamicMatrixToEmx__f(&emx->PRN, data->PRN, &size->PRN);
  emxConvertDynamicMatrixToEmx_fr(&emx->pseudorange, data->pseudorange,
    &size->pseudorange);
  emxConvertDynamicMatrixToEmx_fr(&emx->pseudorange_raw, data->pseudorange_raw,
    &size->pseudorange_raw);
  emxConvertDynamicMatrixToEmx_fr(&emx->pseudorange_satclk_corrected,
    data->pseudorange_satclk_corrected, &size->pseudorange_satclk_corrected);
  emxConvertDynamicMatrixToEmx_fr(&emx->deltarange, data->deltarange,
    &size->deltarange);
  emxConvertDynamicMatrixToEmx_fr(&emx->deltarange_raw, data->deltarange_raw,
    &size->deltarange_raw);
  emxConvertDynamicMatrixToEmx_fr(&emx->deltarange_satclk_corrected,
    data->deltarange_satclk_corrected, &size->deltarange_satclk_corrected);
  emxConvertDynamicMatrixToEmx_fr(&emx->variance_pseudorange,
    data->variance_pseudorange, &size->variance_pseudorange);
  emxConvertDynamicMatrixToEmx_fr(&emx->variance_pseudorange_measured,
    data->variance_pseudorange_measured, &size->variance_pseudorange_measured);
  emxConvertDynamicMatrixToEmx_fr(&emx->variance_deltarange,
    data->variance_deltarange, &size->variance_deltarange);
  emxConvertDynamicMatrixToEmx_fr(&emx->carrierphase, data->carrierphase,
    &size->carrierphase);
  emxConvertDynamicMatrixToEmx_fr(&emx->carrierphase_raw, data->carrierphase_raw,
    &size->carrierphase_raw);
  emxConvertDynamicMatrixToEmx_fr(&emx->carrierphase_satclk_corrected,
    data->carrierphase_satclk_corrected, &size->carrierphase_satclk_corrected);
  emxConvertDynamicMatrixToEmx_fr(&emx->variance_carrierphase_measured,
    data->variance_carrierphase_measured, &size->variance_carrierphase_measured);
  emxConvertDynamicMatrixToEm_fr3(&emx->locktime, data->locktime,
    &size->locktime);
  emxConvertDynamicMatrixToEmx_fr(&emx->CN0, data->CN0, &size->CN0);
  std::memcpy(&emx->base_position, &data->base_position, static_cast<uint32_T>
              (sizeof(real_T [3])));
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
void GNSS_preprocessingModelClass::GNSSPreProcessingS_mergeMyBus_c(const
  emxArray__GNSS_Measurement_GN_T *varargin_1, const
  emxArray__GNSS_Measurement_GN_T *varargin_2, s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T
  *outputBus)
{
  int32_T loop_ub;
  int32_T loop_ub_0;
  int8_T empty_non_axis_sizes_0[2];
  int8_T empty_non_axis_sizes_1[2];
  int8_T sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  outputBus->time_receive = varargin_1->time_receive;
  outputBus->base_position[0] = varargin_1->base_position[0];
  outputBus->base_position[1] = varargin_1->base_position[1];
  outputBus->base_position[2] = varargin_1->base_position[2];
  if ((varargin_1->satellite_position.size[0] != 0) &&
      (varargin_1->satellite_position.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_position.size[1]);
  } else if ((varargin_2->satellite_position.size[0] != 0) &&
             (varargin_2->satellite_position.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_position.size[1]);
  } else if (varargin_2->satellite_position.size[1] >
             varargin_1->satellite_position.size[1]) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_position.size[1]);
  } else {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_position.size[1]);
  }

  empty_non_axis_sizes = (sizes_idx_1 == 0);
  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_position.size[0]);
  } else if ((varargin_1->satellite_position.size[0] != 0) &&
             (varargin_1->satellite_position.size[1] != 0)) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_position.size[0]);
  } else {
    empty_non_axis_sizes_0[0] = 0;
  }

  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_position.size[0]);
  } else if ((varargin_2->satellite_position.size[0] != 0) &&
             (varargin_2->satellite_position.size[1] != 0)) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_position.size[0]);
  } else {
    empty_non_axis_sizes_1[0] = 0;
  }

  outputBus->satellite_position.size[0] = empty_non_axis_sizes_0[0] +
    empty_non_axis_sizes_1[0];
  outputBus->satellite_position.size[1] = sizes_idx_1;
  loop_ub = sizes_idx_1;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    loop_ub_0 = empty_non_axis_sizes_0[0];
    for (int32_T i{0}; i < loop_ub_0; i++) {
      outputBus->satellite_position.data[i + outputBus->satellite_position.size
        [0] * i_0] = varargin_1->satellite_position.data[empty_non_axis_sizes_0
        [0] * i_0 + i];
    }
  }

  loop_ub = sizes_idx_1;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    loop_ub_0 = empty_non_axis_sizes_1[0];
    for (int32_T i{0}; i < loop_ub_0; i++) {
      outputBus->satellite_position.data[(i + empty_non_axis_sizes_0[0]) +
        outputBus->satellite_position.size[0] * i_0] =
        varargin_2->satellite_position.data[empty_non_axis_sizes_1[0] * i_0 + i];
    }
  }

  if ((varargin_1->satellite_velocity.size[0] != 0) &&
      (varargin_1->satellite_velocity.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_velocity.size[1]);
  } else if ((varargin_2->satellite_velocity.size[0] != 0) &&
             (varargin_2->satellite_velocity.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_velocity.size[1]);
  } else if (varargin_2->satellite_velocity.size[1] >
             varargin_1->satellite_velocity.size[1]) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_velocity.size[1]);
  } else {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_velocity.size[1]);
  }

  empty_non_axis_sizes = (sizes_idx_1 == 0);
  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_velocity.size[0]);
  } else if ((varargin_1->satellite_velocity.size[0] != 0) &&
             (varargin_1->satellite_velocity.size[1] != 0)) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_velocity.size[0]);
  } else {
    empty_non_axis_sizes_0[0] = 0;
  }

  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_velocity.size[0]);
  } else if ((varargin_2->satellite_velocity.size[0] != 0) &&
             (varargin_2->satellite_velocity.size[1] != 0)) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_velocity.size[0]);
  } else {
    empty_non_axis_sizes_1[0] = 0;
  }

  outputBus->satellite_velocity.size[0] = empty_non_axis_sizes_0[0] +
    empty_non_axis_sizes_1[0];
  outputBus->satellite_velocity.size[1] = sizes_idx_1;
  loop_ub = sizes_idx_1;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    loop_ub_0 = empty_non_axis_sizes_0[0];
    for (int32_T i{0}; i < loop_ub_0; i++) {
      outputBus->satellite_velocity.data[i + outputBus->satellite_velocity.size
        [0] * i_0] = varargin_1->satellite_velocity.data[empty_non_axis_sizes_0
        [0] * i_0 + i];
    }
  }

  loop_ub = sizes_idx_1;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    loop_ub_0 = empty_non_axis_sizes_1[0];
    for (int32_T i{0}; i < loop_ub_0; i++) {
      outputBus->satellite_velocity.data[(i + empty_non_axis_sizes_0[0]) +
        outputBus->satellite_velocity.size[0] * i_0] =
        varargin_2->satellite_velocity.data[empty_non_axis_sizes_1[0] * i_0 + i];
    }
  }

  outputBus->PRN.size = varargin_1->PRN.size + varargin_2->PRN.size;
  if (varargin_1->PRN.size - 1 >= 0) {
    std::memcpy(&outputBus->PRN.data[0], &varargin_1->PRN.data[0],
                static_cast<uint32_T>(varargin_1->PRN.size) * sizeof(uint16_T));
  }

  loop_ub = varargin_2->PRN.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->PRN.data[i_0 + varargin_1->PRN.size] = varargin_2->PRN.data[i_0];
  }

  outputBus->pseudorange.size = varargin_1->pseudorange.size +
    varargin_2->pseudorange.size;
  if (varargin_1->pseudorange.size - 1 >= 0) {
    std::memcpy(&outputBus->pseudorange.data[0], &varargin_1->pseudorange.data[0],
                static_cast<uint32_T>(varargin_1->pseudorange.size) * sizeof
                (real_T));
  }

  loop_ub = varargin_2->pseudorange.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->pseudorange.data[i_0 + varargin_1->pseudorange.size] =
      varargin_2->pseudorange.data[i_0];
  }

  outputBus->pseudorange_raw.size = varargin_1->pseudorange_raw.size +
    varargin_2->pseudorange_raw.size;
  if (varargin_1->pseudorange_raw.size - 1 >= 0) {
    std::memcpy(&outputBus->pseudorange_raw.data[0],
                &varargin_1->pseudorange_raw.data[0], static_cast<uint32_T>
                (varargin_1->pseudorange_raw.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->pseudorange_raw.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->pseudorange_raw.data[i_0 + varargin_1->pseudorange_raw.size] =
      varargin_2->pseudorange_raw.data[i_0];
  }

  outputBus->pseudorange_satclk_corrected.size =
    varargin_1->pseudorange_satclk_corrected.size +
    varargin_2->pseudorange_satclk_corrected.size;
  if (varargin_1->pseudorange_satclk_corrected.size - 1 >= 0) {
    std::memcpy(&outputBus->pseudorange_satclk_corrected.data[0],
                &varargin_1->pseudorange_satclk_corrected.data[0],
                static_cast<uint32_T>
                (varargin_1->pseudorange_satclk_corrected.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->pseudorange_satclk_corrected.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->pseudorange_satclk_corrected.data[i_0 +
      varargin_1->pseudorange_satclk_corrected.size] =
      varargin_2->pseudorange_satclk_corrected.data[i_0];
  }

  outputBus->deltarange.size = varargin_1->deltarange.size +
    varargin_2->deltarange.size;
  if (varargin_1->deltarange.size - 1 >= 0) {
    std::memcpy(&outputBus->deltarange.data[0], &varargin_1->deltarange.data[0],
                static_cast<uint32_T>(varargin_1->deltarange.size) * sizeof
                (real_T));
  }

  loop_ub = varargin_2->deltarange.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->deltarange.data[i_0 + varargin_1->deltarange.size] =
      varargin_2->deltarange.data[i_0];
  }

  outputBus->deltarange_raw.size = varargin_1->deltarange_raw.size +
    varargin_2->deltarange_raw.size;
  if (varargin_1->deltarange_raw.size - 1 >= 0) {
    std::memcpy(&outputBus->deltarange_raw.data[0],
                &varargin_1->deltarange_raw.data[0], static_cast<uint32_T>
                (varargin_1->deltarange_raw.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->deltarange_raw.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->deltarange_raw.data[i_0 + varargin_1->deltarange_raw.size] =
      varargin_2->deltarange_raw.data[i_0];
  }

  outputBus->deltarange_satclk_corrected.size =
    varargin_1->deltarange_satclk_corrected.size +
    varargin_2->deltarange_satclk_corrected.size;
  if (varargin_1->deltarange_satclk_corrected.size - 1 >= 0) {
    std::memcpy(&outputBus->deltarange_satclk_corrected.data[0],
                &varargin_1->deltarange_satclk_corrected.data[0],
                static_cast<uint32_T>
                (varargin_1->deltarange_satclk_corrected.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->deltarange_satclk_corrected.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->deltarange_satclk_corrected.data[i_0 +
      varargin_1->deltarange_satclk_corrected.size] =
      varargin_2->deltarange_satclk_corrected.data[i_0];
  }

  outputBus->variance_pseudorange.size = varargin_1->variance_pseudorange.size +
    varargin_2->variance_pseudorange.size;
  if (varargin_1->variance_pseudorange.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_pseudorange.data[0],
                &varargin_1->variance_pseudorange.data[0], static_cast<uint32_T>
                (varargin_1->variance_pseudorange.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->variance_pseudorange.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->variance_pseudorange.data[i_0 +
      varargin_1->variance_pseudorange.size] =
      varargin_2->variance_pseudorange.data[i_0];
  }

  outputBus->variance_pseudorange_measured.size =
    varargin_1->variance_pseudorange_measured.size +
    varargin_2->variance_pseudorange_measured.size;
  if (varargin_1->variance_pseudorange_measured.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_pseudorange_measured.data[0],
                &varargin_1->variance_pseudorange_measured.data[0],
                static_cast<uint32_T>
                (varargin_1->variance_pseudorange_measured.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->variance_pseudorange_measured.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->variance_pseudorange_measured.data[i_0 +
      varargin_1->variance_pseudorange_measured.size] =
      varargin_2->variance_pseudorange_measured.data[i_0];
  }

  outputBus->variance_deltarange.size = varargin_1->variance_deltarange.size +
    varargin_2->variance_deltarange.size;
  if (varargin_1->variance_deltarange.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_deltarange.data[0],
                &varargin_1->variance_deltarange.data[0], static_cast<uint32_T>
                (varargin_1->variance_deltarange.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->variance_deltarange.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->variance_deltarange.data[i_0 +
      varargin_1->variance_deltarange.size] =
      varargin_2->variance_deltarange.data[i_0];
  }

  outputBus->carrierphase.size = varargin_1->carrierphase.size +
    varargin_2->carrierphase.size;
  if (varargin_1->carrierphase.size - 1 >= 0) {
    std::memcpy(&outputBus->carrierphase.data[0], &varargin_1->
                carrierphase.data[0], static_cast<uint32_T>
                (varargin_1->carrierphase.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->carrierphase.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->carrierphase.data[i_0 + varargin_1->carrierphase.size] =
      varargin_2->carrierphase.data[i_0];
  }

  outputBus->carrierphase_raw.size = varargin_1->carrierphase_raw.size +
    varargin_2->carrierphase_raw.size;
  if (varargin_1->carrierphase_raw.size - 1 >= 0) {
    std::memcpy(&outputBus->carrierphase_raw.data[0],
                &varargin_1->carrierphase_raw.data[0], static_cast<uint32_T>
                (varargin_1->carrierphase_raw.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->carrierphase_raw.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->carrierphase_raw.data[i_0 + varargin_1->carrierphase_raw.size] =
      varargin_2->carrierphase_raw.data[i_0];
  }

  outputBus->carrierphase_satclk_corrected.size =
    varargin_1->carrierphase_satclk_corrected.size +
    varargin_2->carrierphase_satclk_corrected.size;
  if (varargin_1->carrierphase_satclk_corrected.size - 1 >= 0) {
    std::memcpy(&outputBus->carrierphase_satclk_corrected.data[0],
                &varargin_1->carrierphase_satclk_corrected.data[0], static_cast<
                uint32_T>(varargin_1->carrierphase_satclk_corrected.size) *
                sizeof(real_T));
  }

  loop_ub = varargin_2->carrierphase_satclk_corrected.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->carrierphase_satclk_corrected.data[i_0 +
      varargin_1->carrierphase_satclk_corrected.size] =
      varargin_2->carrierphase_satclk_corrected.data[i_0];
  }

  outputBus->variance_carrierphase_measured.size =
    varargin_1->variance_carrierphase_measured.size +
    varargin_2->variance_carrierphase_measured.size;
  if (varargin_1->variance_carrierphase_measured.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_carrierphase_measured.data[0],
                &varargin_1->variance_carrierphase_measured.data[0],
                static_cast<uint32_T>
                (varargin_1->variance_carrierphase_measured.size) * sizeof
                (real_T));
  }

  loop_ub = varargin_2->variance_carrierphase_measured.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->variance_carrierphase_measured.data[i_0 +
      varargin_1->variance_carrierphase_measured.size] =
      varargin_2->variance_carrierphase_measured.data[i_0];
  }

  outputBus->locktime.size = varargin_1->locktime.size +
    varargin_2->locktime.size;
  if (varargin_1->locktime.size - 1 >= 0) {
    std::memcpy(&outputBus->locktime.data[0], &varargin_1->locktime.data[0],
                static_cast<uint32_T>(varargin_1->locktime.size) * sizeof
                (real32_T));
  }

  loop_ub = varargin_2->locktime.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->locktime.data[i_0 + varargin_1->locktime.size] =
      varargin_2->locktime.data[i_0];
  }

  outputBus->CN0.size = varargin_1->CN0.size + varargin_2->CN0.size;
  if (varargin_1->CN0.size - 1 >= 0) {
    std::memcpy(&outputBus->CN0.data[0], &varargin_1->CN0.data[0],
                static_cast<uint32_T>(varargin_1->CN0.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->CN0.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->CN0.data[i_0 + varargin_1->CN0.size] = varargin_2->CN0.data[i_0];
  }
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
real_T GNSS_preprocessingModelClass::GNSSPreProces_GGTO_delta_T_GNSS(real_T
  GalGstGps_Bus_A_1G, real_T GalGstGps_Bus_A_0G, uint32_T GalGstGps_Bus_t_oG,
  uint8_T GalGstGps_Bus_WN_oG, real_T GSTTOW, real_T GSTWNc)
{
  real_T delta_week;
  if (std::isnan(GSTWNc)) {
    delta_week = (rtNaN);
  } else if (std::isinf(GSTWNc)) {
    delta_week = (rtNaN);
  } else if (GSTWNc == 0.0) {
    delta_week = 0.0;
  } else {
    delta_week = std::fmod(GSTWNc, 64.0);
    if (delta_week == 0.0) {
      delta_week = 0.0;
    } else if (GSTWNc < 0.0) {
      delta_week += 64.0;
    }
  }

  delta_week -= static_cast<real_T>(GalGstGps_Bus_WN_oG);
  if (delta_week > 31.0) {
    delta_week -= std::floor(delta_week / 31.0) * 31.0;
  } else if (delta_week < -31.0) {
    delta_week += std::floor(delta_week / 31.0) * 31.0;
  }

  return ((GSTTOW - static_cast<real_T>(GalGstGps_Bus_t_oG)) + 604800.0 *
          delta_week) * GalGstGps_Bus_A_1G + GalGstGps_Bus_A_0G;
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingl_isMember(const
  uint16_T a_data[], const int32_T *a_size, boolean_T tf_data[], int32_T
  *tf_size)
{
  int32_T loop_ub;
  *tf_size = static_cast<int8_T>(*a_size);
  if (static_cast<int8_T>(*a_size) - 1 >= 0) {
    std::memset(&tf_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>
      (*a_size)) * sizeof(boolean_T));
  }

  loop_ub = *a_size;
  for (int32_T k{0}; k < loop_ub; k++) {
    int32_T ihi;
    int32_T ilo;
    int32_T n;
    uint16_T x;
    boolean_T exitg1;
    x = a_data[k];
    n = 0;
    ilo = 1;
    ihi = 33;
    exitg1 = false;
    while ((!exitg1) && (ihi >= ilo)) {
      int32_T imid;
      imid = (ilo >> 1) + (ihi >> 1);
      if (((ilo & 1) == 1) && ((ihi & 1) == 1)) {
        imid++;
      }

      if (imid + 69 == x) {
        n = imid;
        exitg1 = true;
      } else if (x < imid + 69) {
        ihi = imid - 1;
      } else {
        ilo = imid + 1;
      }
    }

    if (n > 0) {
      while ((n - 1 > 0) && (n + 68 == x)) {
        n--;
      }
    }

    if (n > 0) {
      tf_data[k] = true;
    }
  }
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
void GNSS_preprocessingModelClass::GNSSPreProcessingSin_isMember_d(const
  uint16_T a_data[], const int32_T *a_size, boolean_T tf_data[], int32_T
  *tf_size)
{
  int32_T loop_ub;
  *tf_size = static_cast<int8_T>(*a_size);
  if (static_cast<int8_T>(*a_size) - 1 >= 0) {
    std::memset(&tf_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>
      (*a_size)) * sizeof(boolean_T));
  }

  loop_ub = *a_size;
  for (int32_T k{0}; k < loop_ub; k++) {
    int32_T ihi;
    int32_T ilo;
    int32_T n;
    uint16_T x;
    boolean_T exitg1;
    x = a_data[k];
    n = 0;
    ilo = 1;
    ihi = 37;
    exitg1 = false;
    while ((!exitg1) && (ihi >= ilo)) {
      int32_T imid;
      imid = (ilo >> 1) + (ihi >> 1);
      if (((ilo & 1) == 1) && ((ihi & 1) == 1)) {
        imid++;
      }

      if (x == imid) {
        n = imid;
        exitg1 = true;
      } else if (x < imid) {
        ihi = imid - 1;
      } else {
        ilo = imid + 1;
      }
    }

    if (n > 0) {
      while ((n - 1 > 0) && (n - 1 == x)) {
        n--;
      }
    }

    if (n > 0) {
      tf_data[k] = true;
    }
  }
}

// Function for MATLAB Function: '<Root>/Calculate User Position with LMS'
real_T GNSS_preprocessingModelClass::GNSSPreProcessingSingleAnt_norm(const
  real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = std::abs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = std::abs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = std::abs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * std::sqrt(y);
}

void GNSS_preprocessingModelClass::GNSSPre_binary_expand_op_fr3pus(real_T
  in1_data[], int32_T in2, const real_T in3_data[], const real_T in4_data[],
  const int32_T in4_size[2], const real_T in5[4])
{
  real_T in4[3];
  int32_T stride_0_0;
  stride_0_0 = (in4_size[1] != 1);
  in4[0] = in4_data[in2] - in5[0];
  in4[1] = in4_data[in4_size[0] * stride_0_0 + in2] - in5[1];
  in4[2] = in4_data[(stride_0_0 << 1) * in4_size[0] + in2] - in5[2];
  in1_data[in2] = in3_data[in2] - (GNSSPreProcessingSingleAnt_norm(in4) + in5[3]);
}

void GNSS_preprocessingModelClass::GNSSPreP_binary_expand_op_fr3pu(real_T
  in1_data[], const int32_T in1_size[2], int32_T in2, const real_T in3_data[],
  const int32_T in3_size[2], const real_T in4[4])
{
  real_T in3[3];
  real_T in3_tmp;
  real_T tmp;
  int32_T stride_0_0;
  stride_0_0 = (in3_size[1] != 1);
  in3_tmp = in3_data[in2] - in4[0];
  in3[0] = in3_tmp;
  in3[1] = in3_data[in3_size[0] * stride_0_0 + in2] - in4[1];
  in3[2] = in3_data[(stride_0_0 << 1) * in3_size[0] + in2] - in4[2];
  tmp = GNSSPreProcessingSingleAnt_norm(in3);
  stride_0_0 = (in3_size[1] != 1);
  in1_data[in2] = -in3_tmp / tmp;
  in1_data[in2 + in1_size[0]] = -(in3_data[in3_size[0] * stride_0_0 + in2] -
    in4[1]) / tmp;
  in1_data[in2 + (in1_size[0] << 1)] = -(in3_data[(stride_0_0 << 1) * in3_size[0]
    + in2] - in4[2]) / tmp;
  in1_data[in2 + in1_size[0] * 3] = 1.0;
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
void GNSS_preprocessingModelClass::GNSSPreProcessingSi_getJacobi_o(const real_T
  satellite_position_data[], const int32_T satellite_position_size[2], const
  real_T pseudorange_data[], const int32_T *pseudorange_size, const real_T
  user_state[4], real_T delta_rho_data[], int32_T *delta_rho_size, real_T
  H_data[], int32_T H_size[2], real_T residuum[4])
{
  real_T satellite_position[3];
  real_T satellite_position_0[3];
  real_T satellite_position_tmp;
  int32_T c;
  int32_T loop_ub;
  *delta_rho_size = *pseudorange_size;
  if (*pseudorange_size - 1 >= 0) {
    std::memset(&delta_rho_data[0], 0, static_cast<uint32_T>(*pseudorange_size) *
                sizeof(real_T));
  }

  H_size[0] = *pseudorange_size;
  H_size[1] = 4;
  loop_ub = *pseudorange_size << 2;
  if (loop_ub - 1 >= 0) {
    std::memset(&H_data[0], 0, static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  loop_ub = *pseudorange_size;
  for (int32_T H{0}; H < loop_ub; H++) {
    if (satellite_position_size[1] == 3) {
      for (c = 0; c < 3; c++) {
        satellite_position_tmp =
          satellite_position_data[satellite_position_size[0] * c + H] -
          user_state[c];
        satellite_position[c] = satellite_position_tmp;
        satellite_position_0[c] = satellite_position_tmp;
      }

      delta_rho_data[H] = pseudorange_data[H] - (GNSSPreProcessingSingleAnt_norm
        (satellite_position) + user_state[3]);
      satellite_position_tmp = GNSSPreProcessingSingleAnt_norm
        (satellite_position_0);
      for (c = 0; c < 3; c++) {
        H_data[H + H_size[0] * c] =
          -(satellite_position_data[satellite_position_size[0] * c + H] -
            user_state[c]) / satellite_position_tmp;
      }

      H_data[H + H_size[0] * 3] = 1.0;
    } else {
      GNSSPre_binary_expand_op_fr3pus(delta_rho_data, H, pseudorange_data,
        satellite_position_data, satellite_position_size, user_state);
      GNSSPreP_binary_expand_op_fr3pu(H_data, H_size, H, satellite_position_data,
        satellite_position_size, user_state);
    }
  }

  residuum[0] = 0.0;
  residuum[1] = 0.0;
  residuum[2] = 0.0;
  residuum[3] = 0.0;
  c = H_size[0];
  for (loop_ub = 0; loop_ub < c; loop_ub++) {
    satellite_position_tmp = delta_rho_data[loop_ub];
    residuum[0] += H_data[loop_ub] * satellite_position_tmp;
    residuum[1] += H_data[H_size[0] + loop_ub] * satellite_position_tmp;
    residuum[2] += H_data[(H_size[0] << 1) + loop_ub] * satellite_position_tmp;
    residuum[3] += H_data[3 * H_size[0] + loop_ub] * satellite_position_tmp;
  }
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
real_T GNSS_preprocessingModelClass::GNSSPreProcessingSingl_xnrm2_ks(int32_T n,
  const real_T x_data[], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x_data[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k{ix0}; k <= kend; k++) {
        real_T absxk;
        absxk = std::abs(x_data[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = std::sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = std::sqrt(b * b + 1.0) * a;
  } else if (std::isnan(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
void GNSS_preprocessingModelClass::GNSSPreProcessingSin_qrsolve_g2(const real_T
  A_data[], const int32_T A_size[2], const real_T B_data[], const int32_T
  *B_size, real_T Y[4])
{
  __m128d tmp_0;
  real_T b_A_data[320];
  real_T b_B_data[80];
  real_T tau_data[4];
  real_T vn1[4];
  real_T vn2[4];
  real_T work[4];
  real_T s;
  real_T smax;
  int32_T b_A_size[2];
  int32_T ii;
  int32_T itemp;
  int32_T jA;
  int32_T maxmn;
  int32_T minmana;
  int32_T mmi;
  int32_T rankA;
  int8_T jpvt[4];
  rankA = A_size[0];
  b_A_size[0] = A_size[0];
  minmana = A_size[0] << 2;
  if (minmana - 1 >= 0) {
    std::memcpy(&b_A_data[0], &A_data[0], static_cast<uint32_T>(minmana) *
                sizeof(real_T));
  }

  if (A_size[0] <= 4) {
    minmana = A_size[0];
  } else {
    minmana = 4;
  }

  if (minmana - 1 >= 0) {
    std::memset(&tau_data[0], 0, static_cast<uint32_T>(minmana) * sizeof(real_T));
  }

  if (A_size[0] == 0) {
    jpvt[0] = 1;
    jpvt[1] = 2;
    jpvt[2] = 3;
    jpvt[3] = 4;
  } else {
    minmana = A_size[0];
    jpvt[0] = 1;
    work[0] = 0.0;
    smax = GNSSPreProcessingSingl_xnrm2_ks(A_size[0], A_data, 1);
    vn2[0] = smax;
    vn1[0] = smax;
    jpvt[1] = 2;
    work[1] = 0.0;
    smax = GNSSPreProcessingSingl_xnrm2_ks(A_size[0], A_data, A_size[0] + 1);
    vn2[1] = smax;
    vn1[1] = smax;
    jpvt[2] = 3;
    work[2] = 0.0;
    smax = GNSSPreProcessingSingl_xnrm2_ks(A_size[0], A_data, (A_size[0] << 1) +
      1);
    vn2[2] = smax;
    vn1[2] = smax;
    jpvt[3] = 4;
    work[3] = 0.0;
    smax = GNSSPreProcessingSingl_xnrm2_ks(A_size[0], A_data, 3 * A_size[0] + 1);
    vn2[3] = smax;
    vn1[3] = smax;
    if (A_size[0] <= 4) {
      maxmn = A_size[0];
    } else {
      maxmn = 4;
    }

    for (int32_T e_i{0}; e_i < maxmn; e_i++) {
      int32_T b_ix;
      int32_T c_k;
      int32_T pvt;
      int32_T temp_tmp;
      jA = e_i * minmana;
      ii = jA + e_i;
      mmi = rankA - e_i;
      itemp = 4 - e_i;
      pvt = 0;
      if (4 - e_i > 1) {
        smax = std::abs(vn1[e_i]);
        for (b_ix = 2; b_ix <= itemp; b_ix++) {
          s = std::abs(vn1[(e_i + b_ix) - 1]);
          if (s > smax) {
            pvt = b_ix - 1;
            smax = s;
          }
        }
      }

      pvt += e_i;
      if (pvt != e_i) {
        b_ix = pvt * minmana;
        for (c_k = 0; c_k < rankA; c_k++) {
          temp_tmp = b_ix + c_k;
          smax = b_A_data[temp_tmp];
          itemp = jA + c_k;
          b_A_data[temp_tmp] = b_A_data[itemp];
          b_A_data[itemp] = smax;
        }

        itemp = jpvt[pvt];
        jpvt[pvt] = jpvt[e_i];
        jpvt[e_i] = static_cast<int8_T>(itemp);
        vn1[pvt] = vn1[e_i];
        vn2[pvt] = vn2[e_i];
      }

      if (e_i + 1 < rankA) {
        s = b_A_data[ii];
        pvt = ii + 2;
        tau_data[e_i] = 0.0;
        if (mmi > 0) {
          smax = GNSSPreProcessingSingl_xnrm2_ks(mmi - 1, b_A_data, ii + 2);
          if (smax != 0.0) {
            smax = rt_hypotd_snf(b_A_data[ii], smax);
            if (b_A_data[ii] >= 0.0) {
              smax = -smax;
            }

            if (std::abs(smax) < 1.0020841800044864E-292) {
              b_ix = 0;
              c_k = ii + mmi;
              do {
                b_ix++;
                itemp = (((((c_k - ii) - 1) / 2) << 1) + ii) + 2;
                jA = itemp - 2;
                for (temp_tmp = pvt; temp_tmp <= jA; temp_tmp += 2) {
                  tmp_0 = _mm_loadu_pd(&b_A_data[temp_tmp - 1]);
                  _mm_storeu_pd(&b_A_data[temp_tmp - 1], _mm_mul_pd(tmp_0,
                    _mm_set1_pd(9.9792015476736E+291)));
                }

                for (temp_tmp = itemp; temp_tmp <= c_k; temp_tmp++) {
                  b_A_data[temp_tmp - 1] *= 9.9792015476736E+291;
                }

                smax *= 9.9792015476736E+291;
                s *= 9.9792015476736E+291;
              } while ((std::abs(smax) < 1.0020841800044864E-292) && (b_ix < 20));

              smax = rt_hypotd_snf(s, GNSSPreProcessingSingl_xnrm2_ks(mmi - 1,
                b_A_data, ii + 2));
              if (s >= 0.0) {
                smax = -smax;
              }

              tau_data[e_i] = (smax - s) / smax;
              s = 1.0 / (s - smax);
              itemp = (((((c_k - ii) - 1) / 2) << 1) + ii) + 2;
              jA = itemp - 2;
              for (temp_tmp = pvt; temp_tmp <= jA; temp_tmp += 2) {
                tmp_0 = _mm_loadu_pd(&b_A_data[temp_tmp - 1]);
                _mm_storeu_pd(&b_A_data[temp_tmp - 1], _mm_mul_pd(tmp_0,
                  _mm_set1_pd(s)));
              }

              for (temp_tmp = itemp; temp_tmp <= c_k; temp_tmp++) {
                b_A_data[temp_tmp - 1] *= s;
              }

              for (itemp = 0; itemp < b_ix; itemp++) {
                smax *= 1.0020841800044864E-292;
              }

              s = smax;
            } else {
              tau_data[e_i] = (smax - b_A_data[ii]) / smax;
              s = 1.0 / (b_A_data[ii] - smax);
              b_ix = ii + mmi;
              itemp = (((((b_ix - ii) - 1) / 2) << 1) + ii) + 2;
              jA = itemp - 2;
              for (c_k = pvt; c_k <= jA; c_k += 2) {
                tmp_0 = _mm_loadu_pd(&b_A_data[c_k - 1]);
                _mm_storeu_pd(&b_A_data[c_k - 1], _mm_mul_pd(tmp_0, _mm_set1_pd
                  (s)));
              }

              for (c_k = itemp; c_k <= b_ix; c_k++) {
                b_A_data[c_k - 1] *= s;
              }

              s = smax;
            }
          }
        }

        b_A_data[ii] = s;
      } else {
        tau_data[e_i] = 0.0;
      }

      if (e_i + 1 < 4) {
        smax = b_A_data[ii];
        b_A_data[ii] = 1.0;
        jA = (ii + minmana) + 1;
        if (tau_data[e_i] != 0.0) {
          boolean_T exitg2;
          itemp = mmi - 1;
          pvt = (ii + mmi) - 1;
          while ((itemp + 1 > 0) && (b_A_data[pvt] == 0.0)) {
            itemp--;
            pvt--;
          }

          pvt = 3 - e_i;
          exitg2 = false;
          while ((!exitg2) && (pvt > 0)) {
            int32_T exitg1;
            b_ix = (pvt - 1) * minmana + jA;
            c_k = b_ix;
            do {
              exitg1 = 0;
              if (c_k <= b_ix + itemp) {
                if (b_A_data[c_k - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  c_k++;
                }
              } else {
                pvt--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          pvt--;
        } else {
          itemp = -1;
          pvt = -1;
        }

        if (itemp + 1 > 0) {
          if (pvt + 1 != 0) {
            std::memset(&work[0], 0, static_cast<uint32_T>(pvt + 1) * sizeof
                        (real_T));
            b_ix = 0;
            c_k = minmana * pvt + jA;
            for (temp_tmp = jA; minmana < 0 ? temp_tmp >= c_k : temp_tmp <= c_k;
                 temp_tmp += minmana) {
              int32_T p;
              s = 0.0;
              p = temp_tmp + itemp;
              for (int32_T ia{temp_tmp}; ia <= p; ia++) {
                s += b_A_data[(ii + ia) - temp_tmp] * b_A_data[ia - 1];
              }

              work[b_ix] += s;
              b_ix++;
            }
          }

          if (!(-tau_data[e_i] == 0.0)) {
            for (b_ix = 0; b_ix <= pvt; b_ix++) {
              s = work[b_ix];
              if (s != 0.0) {
                s *= -tau_data[e_i];
                c_k = itemp + jA;
                for (temp_tmp = jA; temp_tmp <= c_k; temp_tmp++) {
                  b_A_data[temp_tmp - 1] += b_A_data[(ii + temp_tmp) - jA] * s;
                }
              }

              jA += minmana;
            }
          }
        }

        b_A_data[ii] = smax;
      }

      for (ii = e_i + 2; ii < 5; ii++) {
        itemp = (ii - 1) * minmana + e_i;
        smax = vn1[ii - 1];
        if (smax != 0.0) {
          real_T temp2;
          s = std::abs(b_A_data[itemp]) / smax;
          s = 1.0 - s * s;
          if (s < 0.0) {
            s = 0.0;
          }

          temp2 = smax / vn2[ii - 1];
          temp2 = temp2 * temp2 * s;
          if (temp2 <= 1.4901161193847656E-8) {
            if (e_i + 1 < rankA) {
              vn1[ii - 1] = GNSSPreProcessingSingl_xnrm2_ks(mmi - 1, b_A_data,
                itemp + 2);
              vn2[ii - 1] = vn1[ii - 1];
            } else {
              vn1[ii - 1] = 0.0;
              vn2[ii - 1] = 0.0;
            }
          } else {
            vn1[ii - 1] = smax * std::sqrt(s);
          }
        }
      }
    }
  }

  rankA = 0;
  if (A_size[0] < 4) {
    minmana = A_size[0];
    maxmn = 4;
  } else {
    minmana = 4;
    maxmn = A_size[0];
  }

  if (minmana > 0) {
    while ((rankA < minmana) && (!(std::abs(b_A_data[b_A_size[0] * rankA + rankA])
             <= 2.2204460492503131E-15 * static_cast<real_T>(maxmn) * std::abs
             (b_A_data[0])))) {
      rankA++;
    }
  }

  if (*B_size - 1 >= 0) {
    std::memcpy(&b_B_data[0], &B_data[0], static_cast<uint32_T>(*B_size) *
                sizeof(real_T));
  }

  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  Y[3] = 0.0;
  minmana = A_size[0];
  if (A_size[0] <= 4) {
    maxmn = A_size[0];
  } else {
    maxmn = 4;
  }

  for (int32_T e_i{0}; e_i < maxmn; e_i++) {
    smax = tau_data[e_i];
    if (smax != 0.0) {
      s = b_B_data[e_i];
      for (mmi = e_i + 2; mmi <= minmana; mmi++) {
        s += b_A_data[(b_A_size[0] * e_i + mmi) - 1] * b_B_data[mmi - 1];
      }

      s *= smax;
      if (s != 0.0) {
        b_B_data[e_i] -= s;
        itemp = (((((minmana - e_i) - 1) / 2) << 1) + e_i) + 2;
        jA = itemp - 2;
        for (mmi = e_i + 2; mmi <= jA; mmi += 2) {
          __m128d tmp;
          tmp_0 = _mm_loadu_pd(&b_A_data[(b_A_size[0] * e_i + mmi) - 1]);
          tmp = _mm_loadu_pd(&b_B_data[mmi - 1]);
          _mm_storeu_pd(&b_B_data[mmi - 1], _mm_sub_pd(tmp, _mm_mul_pd(tmp_0,
            _mm_set1_pd(s))));
        }

        for (mmi = itemp; mmi <= minmana; mmi++) {
          b_B_data[mmi - 1] -= b_A_data[(b_A_size[0] * e_i + mmi) - 1] * s;
        }
      }
    }
  }

  for (minmana = 0; minmana < rankA; minmana++) {
    Y[jpvt[minmana] - 1] = b_B_data[minmana];
  }

  for (minmana = rankA; minmana >= 1; minmana--) {
    maxmn = jpvt[minmana - 1] - 1;
    ii = (minmana - 1) * b_A_size[0];
    Y[maxmn] /= b_A_data[(minmana + ii) - 1];
    for (int32_T e_i{0}; e_i <= minmana - 2; e_i++) {
      mmi = jpvt[e_i] - 1;
      Y[mmi] -= b_A_data[e_i + ii] * Y[maxmn];
    }
  }
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
void GNSS_preprocessingModelClass::GNSSPreProcessing_mldivide_e2x2(const real_T
  A_data[], const int32_T A_size[2], real_T B_data[], int32_T *B_size)
{
  real_T b_A_data[16];
  real_T tmp[4];
  int8_T ipiv[4];
  if (A_size[0] == 0) {
    *B_size = 4;
    B_data[0] = 0.0;
    B_data[1] = 0.0;
    B_data[2] = 0.0;
    B_data[3] = 0.0;
  } else if (*B_size == 0) {
    *B_size = 4;
    B_data[0] = 0.0;
    B_data[1] = 0.0;
    B_data[2] = 0.0;
    B_data[3] = 0.0;
  } else if (A_size[0] == 4) {
    int32_T jj;
    int32_T kAcol;
    std::memcpy(&b_A_data[0], &A_data[0], sizeof(real_T) << 4U);
    ipiv[0] = 1;
    ipiv[1] = 2;
    ipiv[2] = 3;
    ipiv[3] = 4;
    for (int32_T j{0}; j < 3; j++) {
      real_T smax;
      int32_T jA;
      int32_T n;
      int32_T vectorUB;
      int8_T ipiv_0;
      ipiv_0 = ipiv[j];
      jj = j * 5;
      n = 4 - j;
      jA = 0;
      smax = std::abs(b_A_data[jj]);
      for (kAcol = 2; kAcol <= n; kAcol++) {
        real_T s;
        s = std::abs(b_A_data[(jj + kAcol) - 1]);
        if (s > smax) {
          jA = kAcol - 1;
          smax = s;
        }
      }

      if (b_A_data[jj + jA] != 0.0) {
        if (jA != 0) {
          kAcol = j + jA;
          ipiv_0 = static_cast<int8_T>(kAcol + 1);
          smax = b_A_data[j];
          b_A_data[j] = b_A_data[kAcol];
          b_A_data[kAcol] = smax;
          smax = b_A_data[j + 4];
          b_A_data[j + 4] = b_A_data[kAcol + 4];
          b_A_data[kAcol + 4] = smax;
          smax = b_A_data[j + 8];
          b_A_data[j + 8] = b_A_data[kAcol + 8];
          b_A_data[kAcol + 8] = smax;
          smax = b_A_data[j + 12];
          b_A_data[j + 12] = b_A_data[kAcol + 12];
          b_A_data[kAcol + 12] = smax;
        }

        n = (jj - j) + 4;
        jA = (((((n - jj) - 1) / 2) << 1) + jj) + 2;
        vectorUB = jA - 2;
        for (kAcol = jj + 2; kAcol <= vectorUB; kAcol += 2) {
          __m128d tmp_0;
          tmp_0 = _mm_loadu_pd(&b_A_data[kAcol - 1]);
          _mm_storeu_pd(&b_A_data[kAcol - 1], _mm_div_pd(tmp_0, _mm_set1_pd
            (b_A_data[jj])));
        }

        for (kAcol = jA; kAcol <= n; kAcol++) {
          b_A_data[kAcol - 1] /= b_A_data[jj];
        }
      }

      jA = jj + 6;
      vectorUB = 2 - j;
      for (kAcol = 0; kAcol <= vectorUB; kAcol++) {
        smax = b_A_data[((kAcol << 2) + jj) + 4];
        if (smax != 0.0) {
          int32_T e;
          e = (jA - j) + 2;
          for (n = jA; n <= e; n++) {
            b_A_data[n - 1] += b_A_data[((jj + n) - jA) + 1] * -smax;
          }
        }

        jA += 4;
      }

      if (j + 1 != ipiv_0) {
        smax = B_data[j];
        B_data[j] = B_data[ipiv_0 - 1];
        B_data[ipiv_0 - 1] = smax;
      }

      ipiv[j] = ipiv_0;
    }

    for (int32_T j{0}; j < 4; j++) {
      kAcol = j << 2;
      if (B_data[j] != 0.0) {
        for (jj = j + 2; jj < 5; jj++) {
          B_data[jj - 1] -= b_A_data[(jj + kAcol) - 1] * B_data[j];
        }
      }
    }

    for (int32_T j{3}; j >= 0; j--) {
      kAcol = j << 2;
      if (B_data[j] != 0.0) {
        B_data[j] /= b_A_data[j + kAcol];
        for (jj = 0; jj < j; jj++) {
          B_data[jj] -= b_A_data[jj + kAcol] * B_data[j];
        }
      }
    }
  } else {
    GNSSPreProcessingSin_qrsolve_g2(A_data, A_size, B_data, B_size, tmp);
    *B_size = 4;
    B_data[0] = tmp[0];
    B_data[1] = tmp[1];
    B_data[2] = tmp[2];
    B_data[3] = tmp[3];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_plus_f(real_T in1[4],
  const real_T in2_data[], const int32_T *in2_size)
{
  int32_T stride_0_0;

  // MATLAB Function: '<Root>/Calculate User Position with LMS'
  stride_0_0 = (*in2_size != 1);
  in1[0] += in2_data[0];
  in1[1] += in2_data[stride_0_0];
  in1[2] += in2_data[stride_0_0 << 1];
  in1[3] += in2_data[3 * stride_0_0];
}

void GNSS_preprocessingModelClass::G_binary_expand_op_fr3pusohsll5(real_T
  in1_data[], int32_T in2, const real_T in3_data[], const real_T in4_data[],
  const int32_T in4_size[2], const real_T in5[5])
{
  real_T in4[3];
  int32_T stride_0_0;
  stride_0_0 = (in4_size[1] != 1);
  in4[0] = in4_data[in2] - in5[0];
  in4[1] = in4_data[in4_size[0] * stride_0_0 + in2] - in5[1];
  in4[2] = in4_data[(stride_0_0 << 1) * in4_size[0] + in2] - in5[2];
  in1_data[in2] = in3_data[in2] - (GNSSPreProcessingSingleAnt_norm(in4) + in5[3]);
}

void GNSS_preprocessingModelClass::GN_binary_expand_op_fr3pusohsll(real_T
  in1_data[], const int32_T in1_size[2], int32_T in2, const real_T in3_data[],
  const int32_T in3_size[2], const real_T in4[5])
{
  real_T in3[3];
  real_T in3_tmp;
  real_T tmp;
  int32_T stride_0_0;
  stride_0_0 = (in3_size[1] != 1);
  in3_tmp = in3_data[in2] - in4[0];
  in3[0] = in3_tmp;
  in3[1] = in3_data[in3_size[0] * stride_0_0 + in2] - in4[1];
  in3[2] = in3_data[(stride_0_0 << 1) * in3_size[0] + in2] - in4[2];
  tmp = GNSSPreProcessingSingleAnt_norm(in3);
  stride_0_0 = (in3_size[1] != 1);
  in1_data[in2] = -in3_tmp / tmp;
  in1_data[in2 + in1_size[0]] = -(in3_data[in3_size[0] * stride_0_0 + in2] -
    in4[1]) / tmp;
  in1_data[in2 + (in1_size[0] << 1)] = -(in3_data[(stride_0_0 << 1) * in3_size[0]
    + in2] - in4[2]) / tmp;
  in1_data[in2 + in1_size[0] * 3] = 1.0;
  in1_data[in2 + (in1_size[0] << 2)] = 0.0;
}

void GNSS_preprocessingModelClass::binary_expand_op_fr3pusohsll5rb(real_T
  in1_data[], int32_T in2, const real_T in3_data[], const real_T in4_data[],
  const int32_T in4_size[2], const real_T in5[5])
{
  real_T in4[3];
  int32_T stride_0_0;
  stride_0_0 = (in4_size[1] != 1);
  in4[0] = in4_data[in2] - in5[0];
  in4[1] = in4_data[in4_size[0] * stride_0_0 + in2] - in5[1];
  in4[2] = in4_data[(stride_0_0 << 1) * in4_size[0] + in2] - in5[2];
  in1_data[in2] = in3_data[in2] - (GNSSPreProcessingSingleAnt_norm(in4) + in5[4]);
}

void GNSS_preprocessingModelClass::binary_expand_op_fr3pusohsll5r(real_T
  in1_data[], const int32_T in1_size[2], int32_T in2, const real_T in3_data[],
  const int32_T in3_size[2], const real_T in4[5])
{
  real_T in3[3];
  real_T in3_tmp;
  real_T tmp;
  int32_T stride_0_0;
  stride_0_0 = (in3_size[1] != 1);
  in3_tmp = in3_data[in2] - in4[0];
  in3[0] = in3_tmp;
  in3[1] = in3_data[in3_size[0] * stride_0_0 + in2] - in4[1];
  in3[2] = in3_data[(stride_0_0 << 1) * in3_size[0] + in2] - in4[2];
  tmp = GNSSPreProcessingSingleAnt_norm(in3);
  stride_0_0 = (in3_size[1] != 1);
  in1_data[in2] = -in3_tmp / tmp;
  in1_data[in2 + in1_size[0]] = -(in3_data[in3_size[0] * stride_0_0 + in2] -
    in4[1]) / tmp;
  in1_data[in2 + (in1_size[0] << 1)] = -(in3_data[(stride_0_0 << 1) * in3_size[0]
    + in2] - in4[2]) / tmp;
  in1_data[in2 + in1_size[0] * 3] = 0.0;
  in1_data[in2 + (in1_size[0] << 2)] = 1.0;
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
void GNSS_preprocessingModelClass::GNSSPreProc_getJacobiMultiKonst(const real_T
  satellite_position_sys1_data[], const int32_T satellite_position_sys1_size[2],
  const real_T satellite_position_sys2_data[], const int32_T
  satellite_position_sys2_size[2], const real_T pseudorange_sys1_data[], const
  int32_T *pseudorange_sys1_size, const real_T pseudorange_sys2_data[], const
  int32_T *pseudorange_sys2_size, const real_T user_state[5], real_T
  delta_rho_data[], int32_T *delta_rho_size, real_T H_data[], int32_T H_size[2],
  real_T residuum[5])
{
  real_T H_sys1_data[400];
  real_T H_sys2_data[400];
  real_T delta_rho_sys1_data[80];
  real_T delta_rho_sys2_data[80];
  real_T satellite_position_sys1[3];
  real_T satellite_position_sys1_0[3];
  real_T satellite_position_sys1_tmp;
  int32_T H_sys1_size[2];
  int32_T H_sys2_size[2];
  int32_T H_sys1;
  int32_T delta_rho_sys2_size;
  int32_T i;
  int32_T loop_ub;
  if (*pseudorange_sys1_size - 1 >= 0) {
    std::memset(&delta_rho_sys1_data[0], 0, static_cast<uint32_T>
                (*pseudorange_sys1_size) * sizeof(real_T));
  }

  delta_rho_sys2_size = *pseudorange_sys2_size;
  if (*pseudorange_sys2_size - 1 >= 0) {
    std::memset(&delta_rho_sys2_data[0], 0, static_cast<uint32_T>
                (*pseudorange_sys2_size) * sizeof(real_T));
  }

  H_sys1_size[0] = *pseudorange_sys1_size;
  H_sys1_size[1] = 5;
  loop_ub = *pseudorange_sys1_size * 5;
  if (loop_ub - 1 >= 0) {
    std::memset(&H_sys1_data[0], 0, static_cast<uint32_T>(loop_ub) * sizeof
                (real_T));
  }

  loop_ub = *pseudorange_sys1_size;
  for (H_sys1 = 0; H_sys1 < loop_ub; H_sys1++) {
    if (satellite_position_sys1_size[1] == 3) {
      for (i = 0; i < 3; i++) {
        satellite_position_sys1_tmp =
          satellite_position_sys1_data[satellite_position_sys1_size[0] * i +
          H_sys1] - user_state[i];
        satellite_position_sys1[i] = satellite_position_sys1_tmp;
        satellite_position_sys1_0[i] = satellite_position_sys1_tmp;
      }

      delta_rho_sys1_data[H_sys1] = pseudorange_sys1_data[H_sys1] -
        (GNSSPreProcessingSingleAnt_norm(satellite_position_sys1) + user_state[3]);
      satellite_position_sys1_tmp = GNSSPreProcessingSingleAnt_norm
        (satellite_position_sys1_0);
      for (i = 0; i < 3; i++) {
        H_sys1_data[H_sys1 + H_sys1_size[0] * i] =
          -(satellite_position_sys1_data[satellite_position_sys1_size[0] * i +
            H_sys1] - user_state[i]) / satellite_position_sys1_tmp;
      }

      H_sys1_data[H_sys1 + H_sys1_size[0] * 3] = 1.0;
      H_sys1_data[H_sys1 + (H_sys1_size[0] << 2)] = 0.0;
    } else {
      G_binary_expand_op_fr3pusohsll5(delta_rho_sys1_data, H_sys1,
        pseudorange_sys1_data, satellite_position_sys1_data,
        satellite_position_sys1_size, user_state);
      GN_binary_expand_op_fr3pusohsll(H_sys1_data, H_sys1_size, H_sys1,
        satellite_position_sys1_data, satellite_position_sys1_size, user_state);
    }
  }

  H_sys2_size[0] = *pseudorange_sys2_size;
  H_sys2_size[1] = 5;
  loop_ub = *pseudorange_sys2_size * 5;
  if (loop_ub - 1 >= 0) {
    std::memset(&H_sys2_data[0], 0, static_cast<uint32_T>(loop_ub) * sizeof
                (real_T));
  }

  loop_ub = *pseudorange_sys2_size;
  for (H_sys1 = 0; H_sys1 < loop_ub; H_sys1++) {
    if (satellite_position_sys2_size[1] == 3) {
      for (i = 0; i < 3; i++) {
        satellite_position_sys1_tmp =
          satellite_position_sys2_data[satellite_position_sys2_size[0] * i +
          H_sys1] - user_state[i];
        satellite_position_sys1[i] = satellite_position_sys1_tmp;
        satellite_position_sys1_0[i] = satellite_position_sys1_tmp;
      }

      delta_rho_sys2_data[H_sys1] = pseudorange_sys2_data[H_sys1] -
        (GNSSPreProcessingSingleAnt_norm(satellite_position_sys1) + user_state[4]);
      satellite_position_sys1_tmp = GNSSPreProcessingSingleAnt_norm
        (satellite_position_sys1_0);
      for (i = 0; i < 3; i++) {
        H_sys2_data[H_sys1 + H_sys2_size[0] * i] =
          -(satellite_position_sys2_data[satellite_position_sys2_size[0] * i +
            H_sys1] - user_state[i]) / satellite_position_sys1_tmp;
      }

      H_sys2_data[H_sys1 + H_sys2_size[0] * 3] = 0.0;
      H_sys2_data[H_sys1 + (H_sys2_size[0] << 2)] = 1.0;
    } else {
      binary_expand_op_fr3pusohsll5rb(delta_rho_sys2_data, H_sys1,
        pseudorange_sys2_data, satellite_position_sys2_data,
        satellite_position_sys2_size, user_state);
      binary_expand_op_fr3pusohsll5r(H_sys2_data, H_sys2_size, H_sys1,
        satellite_position_sys2_data, satellite_position_sys2_size, user_state);
    }
  }

  H_size[0] = H_sys1_size[0] + H_sys2_size[0];
  H_size[1] = 5;
  loop_ub = H_sys1_size[0];
  H_sys1 = H_sys2_size[0];
  for (i = 0; i < 5; i++) {
    for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
      H_data[i_0 + H_size[0] * i] = H_sys1_data[H_sys1_size[0] * i + i_0];
    }

    for (int32_T i_0{0}; i_0 < H_sys1; i_0++) {
      H_data[(i_0 + H_sys1_size[0]) + H_size[0] * i] = H_sys2_data[H_sys2_size[0]
        * i + i_0];
    }
  }

  *delta_rho_size = *pseudorange_sys1_size + *pseudorange_sys2_size;
  if (*pseudorange_sys1_size - 1 >= 0) {
    std::memcpy(&delta_rho_data[0], &delta_rho_sys1_data[0],
                static_cast<uint32_T>(*pseudorange_sys1_size) * sizeof(real_T));
  }

  for (i = 0; i < delta_rho_sys2_size; i++) {
    delta_rho_data[i + *pseudorange_sys1_size] = delta_rho_sys2_data[i];
  }

  for (i = 0; i < 5; i++) {
    residuum[i] = 0.0;
  }

  i = H_size[0];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    for (H_sys1 = 0; H_sys1 < 5; H_sys1++) {
      residuum[H_sys1] += H_data[H_sys1 * H_size[0] + loop_ub] *
        delta_rho_data[loop_ub];
    }
  }
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
real_T GNSS_preprocessingModelClass::GNSSPreProcessingSingle_xnrm2_k(int32_T n,
  const real_T x_data[], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x_data[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k{ix0}; k <= kend; k++) {
        real_T absxk;
        absxk = std::abs(x_data[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
void GNSS_preprocessingModelClass::GNSSPreProcessingSing_qrsolve_g(const real_T
  A_data[], const int32_T A_size[2], const real_T B_data[], const int32_T
  *B_size, real_T Y[5])
{
  __m128d tmp_0;
  real_T b_B_data[160];
  real_T tau_data[5];
  real_T vn1[5];
  real_T vn2[5];
  real_T work[5];
  real_T s;
  real_T smax;
  int32_T b_A_size[2];
  int32_T ii;
  int32_T itemp;
  int32_T jA;
  int32_T maxmn;
  int32_T minmana;
  int32_T mmi;
  int32_T rankA;
  int8_T jpvt[5];
  rankA = A_size[0];
  b_A_size[0] = A_size[0];
  minmana = A_size[0] * 5;
  if (minmana - 1 >= 0) {
    std::memcpy(&GNSSPreProcessingSingleAntenn_B.b_A_data[0], &A_data[0],
                static_cast<uint32_T>(minmana) * sizeof(real_T));
  }

  if (A_size[0] <= 5) {
    minmana = A_size[0];
  } else {
    minmana = 5;
  }

  if (minmana - 1 >= 0) {
    std::memset(&tau_data[0], 0, static_cast<uint32_T>(minmana) * sizeof(real_T));
  }

  if (A_size[0] == 0) {
    for (rankA = 0; rankA < 5; rankA++) {
      jpvt[rankA] = static_cast<int8_T>(rankA + 1);
    }
  } else {
    minmana = A_size[0];
    for (maxmn = 0; maxmn < 5; maxmn++) {
      jpvt[maxmn] = static_cast<int8_T>(maxmn + 1);
      work[maxmn] = 0.0;
      smax = GNSSPreProcessingSingle_xnrm2_k(rankA, A_data, maxmn * minmana + 1);
      vn2[maxmn] = smax;
      vn1[maxmn] = smax;
    }

    if (A_size[0] <= 5) {
      maxmn = A_size[0];
    } else {
      maxmn = 5;
    }

    for (int32_T e_i{0}; e_i < maxmn; e_i++) {
      int32_T b_ix;
      int32_T c_k;
      int32_T pvt;
      int32_T temp_tmp;
      jA = e_i * minmana;
      ii = jA + e_i;
      mmi = rankA - e_i;
      itemp = 5 - e_i;
      pvt = 0;
      if (5 - e_i > 1) {
        smax = std::abs(vn1[e_i]);
        for (b_ix = 2; b_ix <= itemp; b_ix++) {
          s = std::abs(vn1[(e_i + b_ix) - 1]);
          if (s > smax) {
            pvt = b_ix - 1;
            smax = s;
          }
        }
      }

      pvt += e_i;
      if (pvt != e_i) {
        b_ix = pvt * minmana;
        for (c_k = 0; c_k < rankA; c_k++) {
          temp_tmp = b_ix + c_k;
          smax = GNSSPreProcessingSingleAntenn_B.b_A_data[temp_tmp];
          itemp = jA + c_k;
          GNSSPreProcessingSingleAntenn_B.b_A_data[temp_tmp] =
            GNSSPreProcessingSingleAntenn_B.b_A_data[itemp];
          GNSSPreProcessingSingleAntenn_B.b_A_data[itemp] = smax;
        }

        itemp = jpvt[pvt];
        jpvt[pvt] = jpvt[e_i];
        jpvt[e_i] = static_cast<int8_T>(itemp);
        vn1[pvt] = vn1[e_i];
        vn2[pvt] = vn2[e_i];
      }

      if (e_i + 1 < rankA) {
        s = GNSSPreProcessingSingleAntenn_B.b_A_data[ii];
        pvt = ii + 2;
        tau_data[e_i] = 0.0;
        if (mmi > 0) {
          smax = GNSSPreProcessingSingle_xnrm2_k(mmi - 1,
            GNSSPreProcessingSingleAntenn_B.b_A_data, ii + 2);
          if (smax != 0.0) {
            smax = rt_hypotd_snf(GNSSPreProcessingSingleAntenn_B.b_A_data[ii],
                                 smax);
            if (GNSSPreProcessingSingleAntenn_B.b_A_data[ii] >= 0.0) {
              smax = -smax;
            }

            if (std::abs(smax) < 1.0020841800044864E-292) {
              b_ix = 0;
              c_k = ii + mmi;
              do {
                b_ix++;
                itemp = (((((c_k - ii) - 1) / 2) << 1) + ii) + 2;
                jA = itemp - 2;
                for (temp_tmp = pvt; temp_tmp <= jA; temp_tmp += 2) {
                  tmp_0 = _mm_loadu_pd
                    (&GNSSPreProcessingSingleAntenn_B.b_A_data[temp_tmp - 1]);
                  _mm_storeu_pd
                    (&GNSSPreProcessingSingleAntenn_B.b_A_data[temp_tmp - 1],
                     _mm_mul_pd(tmp_0, _mm_set1_pd(9.9792015476736E+291)));
                }

                for (temp_tmp = itemp; temp_tmp <= c_k; temp_tmp++) {
                  GNSSPreProcessingSingleAntenn_B.b_A_data[temp_tmp - 1] *=
                    9.9792015476736E+291;
                }

                smax *= 9.9792015476736E+291;
                s *= 9.9792015476736E+291;
              } while ((std::abs(smax) < 1.0020841800044864E-292) && (b_ix < 20));

              smax = rt_hypotd_snf(s, GNSSPreProcessingSingle_xnrm2_k(mmi - 1,
                GNSSPreProcessingSingleAntenn_B.b_A_data, ii + 2));
              if (s >= 0.0) {
                smax = -smax;
              }

              tau_data[e_i] = (smax - s) / smax;
              s = 1.0 / (s - smax);
              itemp = (((((c_k - ii) - 1) / 2) << 1) + ii) + 2;
              jA = itemp - 2;
              for (temp_tmp = pvt; temp_tmp <= jA; temp_tmp += 2) {
                tmp_0 = _mm_loadu_pd
                  (&GNSSPreProcessingSingleAntenn_B.b_A_data[temp_tmp - 1]);
                _mm_storeu_pd(&GNSSPreProcessingSingleAntenn_B.b_A_data[temp_tmp
                              - 1], _mm_mul_pd(tmp_0, _mm_set1_pd(s)));
              }

              for (temp_tmp = itemp; temp_tmp <= c_k; temp_tmp++) {
                GNSSPreProcessingSingleAntenn_B.b_A_data[temp_tmp - 1] *= s;
              }

              for (itemp = 0; itemp < b_ix; itemp++) {
                smax *= 1.0020841800044864E-292;
              }

              s = smax;
            } else {
              tau_data[e_i] = (smax -
                               GNSSPreProcessingSingleAntenn_B.b_A_data[ii]) /
                smax;
              s = 1.0 / (GNSSPreProcessingSingleAntenn_B.b_A_data[ii] - smax);
              b_ix = ii + mmi;
              itemp = (((((b_ix - ii) - 1) / 2) << 1) + ii) + 2;
              jA = itemp - 2;
              for (c_k = pvt; c_k <= jA; c_k += 2) {
                tmp_0 = _mm_loadu_pd
                  (&GNSSPreProcessingSingleAntenn_B.b_A_data[c_k - 1]);
                _mm_storeu_pd(&GNSSPreProcessingSingleAntenn_B.b_A_data[c_k - 1],
                              _mm_mul_pd(tmp_0, _mm_set1_pd(s)));
              }

              for (c_k = itemp; c_k <= b_ix; c_k++) {
                GNSSPreProcessingSingleAntenn_B.b_A_data[c_k - 1] *= s;
              }

              s = smax;
            }
          }
        }

        GNSSPreProcessingSingleAntenn_B.b_A_data[ii] = s;
      } else {
        tau_data[e_i] = 0.0;
      }

      if (e_i + 1 < 5) {
        smax = GNSSPreProcessingSingleAntenn_B.b_A_data[ii];
        GNSSPreProcessingSingleAntenn_B.b_A_data[ii] = 1.0;
        jA = (ii + minmana) + 1;
        if (tau_data[e_i] != 0.0) {
          boolean_T exitg2;
          itemp = mmi - 1;
          pvt = (ii + mmi) - 1;
          while ((itemp + 1 > 0) &&
                 (GNSSPreProcessingSingleAntenn_B.b_A_data[pvt] == 0.0)) {
            itemp--;
            pvt--;
          }

          pvt = 4 - e_i;
          exitg2 = false;
          while ((!exitg2) && (pvt > 0)) {
            int32_T exitg1;
            b_ix = (pvt - 1) * minmana + jA;
            c_k = b_ix;
            do {
              exitg1 = 0;
              if (c_k <= b_ix + itemp) {
                if (GNSSPreProcessingSingleAntenn_B.b_A_data[c_k - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  c_k++;
                }
              } else {
                pvt--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          pvt--;
        } else {
          itemp = -1;
          pvt = -1;
        }

        if (itemp + 1 > 0) {
          if (pvt + 1 != 0) {
            std::memset(&work[0], 0, static_cast<uint32_T>(pvt + 1) * sizeof
                        (real_T));
            b_ix = 0;
            c_k = minmana * pvt + jA;
            for (temp_tmp = jA; minmana < 0 ? temp_tmp >= c_k : temp_tmp <= c_k;
                 temp_tmp += minmana) {
              int32_T p;
              s = 0.0;
              p = temp_tmp + itemp;
              for (int32_T ia{temp_tmp}; ia <= p; ia++) {
                s += GNSSPreProcessingSingleAntenn_B.b_A_data[(ii + ia) -
                  temp_tmp] * GNSSPreProcessingSingleAntenn_B.b_A_data[ia - 1];
              }

              work[b_ix] += s;
              b_ix++;
            }
          }

          if (!(-tau_data[e_i] == 0.0)) {
            for (b_ix = 0; b_ix <= pvt; b_ix++) {
              s = work[b_ix];
              if (s != 0.0) {
                s *= -tau_data[e_i];
                c_k = itemp + jA;
                for (temp_tmp = jA; temp_tmp <= c_k; temp_tmp++) {
                  GNSSPreProcessingSingleAntenn_B.b_A_data[temp_tmp - 1] +=
                    GNSSPreProcessingSingleAntenn_B.b_A_data[(ii + temp_tmp) -
                    jA] * s;
                }
              }

              jA += minmana;
            }
          }
        }

        GNSSPreProcessingSingleAntenn_B.b_A_data[ii] = smax;
      }

      for (ii = e_i + 2; ii < 6; ii++) {
        itemp = (ii - 1) * minmana + e_i;
        smax = vn1[ii - 1];
        if (smax != 0.0) {
          real_T temp2;
          s = std::abs(GNSSPreProcessingSingleAntenn_B.b_A_data[itemp]) / smax;
          s = 1.0 - s * s;
          if (s < 0.0) {
            s = 0.0;
          }

          temp2 = smax / vn2[ii - 1];
          temp2 = temp2 * temp2 * s;
          if (temp2 <= 1.4901161193847656E-8) {
            if (e_i + 1 < rankA) {
              vn1[ii - 1] = GNSSPreProcessingSingle_xnrm2_k(mmi - 1,
                GNSSPreProcessingSingleAntenn_B.b_A_data, itemp + 2);
              vn2[ii - 1] = vn1[ii - 1];
            } else {
              vn1[ii - 1] = 0.0;
              vn2[ii - 1] = 0.0;
            }
          } else {
            vn1[ii - 1] = smax * std::sqrt(s);
          }
        }
      }
    }
  }

  rankA = 0;
  if (A_size[0] < 5) {
    minmana = A_size[0];
    maxmn = 5;
  } else {
    minmana = 5;
    maxmn = A_size[0];
  }

  if (minmana > 0) {
    while ((rankA < minmana) && (!(std::abs
             (GNSSPreProcessingSingleAntenn_B.b_A_data[b_A_size[0] * rankA +
              rankA]) <= 2.2204460492503131E-15 * static_cast<real_T>(maxmn) *
             std::abs(GNSSPreProcessingSingleAntenn_B.b_A_data[0])))) {
      rankA++;
    }
  }

  if (*B_size - 1 >= 0) {
    std::memcpy(&b_B_data[0], &B_data[0], static_cast<uint32_T>(*B_size) *
                sizeof(real_T));
  }

  for (minmana = 0; minmana < 5; minmana++) {
    Y[minmana] = 0.0;
  }

  minmana = A_size[0];
  if (A_size[0] <= 5) {
    maxmn = A_size[0];
  } else {
    maxmn = 5;
  }

  for (int32_T e_i{0}; e_i < maxmn; e_i++) {
    smax = tau_data[e_i];
    if (smax != 0.0) {
      s = b_B_data[e_i];
      for (mmi = e_i + 2; mmi <= minmana; mmi++) {
        s += GNSSPreProcessingSingleAntenn_B.b_A_data[(b_A_size[0] * e_i + mmi)
          - 1] * b_B_data[mmi - 1];
      }

      s *= smax;
      if (s != 0.0) {
        b_B_data[e_i] -= s;
        itemp = (((((minmana - e_i) - 1) / 2) << 1) + e_i) + 2;
        jA = itemp - 2;
        for (mmi = e_i + 2; mmi <= jA; mmi += 2) {
          __m128d tmp;
          tmp_0 = _mm_loadu_pd(&GNSSPreProcessingSingleAntenn_B.b_A_data
                               [(b_A_size[0] * e_i + mmi) - 1]);
          tmp = _mm_loadu_pd(&b_B_data[mmi - 1]);
          _mm_storeu_pd(&b_B_data[mmi - 1], _mm_sub_pd(tmp, _mm_mul_pd(tmp_0,
            _mm_set1_pd(s))));
        }

        for (mmi = itemp; mmi <= minmana; mmi++) {
          b_B_data[mmi - 1] -= GNSSPreProcessingSingleAntenn_B.b_A_data
            [(b_A_size[0] * e_i + mmi) - 1] * s;
        }
      }
    }
  }

  for (minmana = 0; minmana < rankA; minmana++) {
    Y[jpvt[minmana] - 1] = b_B_data[minmana];
  }

  for (minmana = rankA; minmana >= 1; minmana--) {
    maxmn = jpvt[minmana - 1] - 1;
    ii = (minmana - 1) * b_A_size[0];
    Y[maxmn] /= GNSSPreProcessingSingleAntenn_B.b_A_data[(minmana + ii) - 1];
    for (int32_T e_i{0}; e_i <= minmana - 2; e_i++) {
      mmi = jpvt[e_i] - 1;
      Y[mmi] -= GNSSPreProcessingSingleAntenn_B.b_A_data[e_i + ii] * Y[maxmn];
    }
  }
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
void GNSS_preprocessingModelClass::GNSSPreProcessingS_mldivide_e2x(const real_T
  A_data[], const int32_T A_size[2], real_T B_data[], int32_T *B_size)
{
  real_T b_A_data[25];
  real_T tmp[5];
  int8_T ipiv[5];
  if (A_size[0] == 0) {
    *B_size = 5;
    for (int32_T kAcol{0}; kAcol < 5; kAcol++) {
      B_data[kAcol] = 0.0;
    }
  } else if (*B_size == 0) {
    *B_size = 5;
    for (int32_T kAcol{0}; kAcol < 5; kAcol++) {
      B_data[kAcol] = 0.0;
    }
  } else if (A_size[0] == 5) {
    int32_T jj;
    int32_T kAcol;
    std::memcpy(&b_A_data[0], &A_data[0], 25U * sizeof(real_T));
    for (kAcol = 0; kAcol < 5; kAcol++) {
      ipiv[kAcol] = static_cast<int8_T>(kAcol + 1);
    }

    for (int32_T j{0}; j < 4; j++) {
      real_T smax;
      int32_T b_temp_tmp;
      int32_T jA;
      int32_T n;
      int8_T ipiv_0;
      ipiv_0 = ipiv[j];
      jj = j * 6;
      n = 5 - j;
      jA = 0;
      smax = std::abs(b_A_data[jj]);
      for (kAcol = 2; kAcol <= n; kAcol++) {
        real_T s;
        s = std::abs(b_A_data[(jj + kAcol) - 1]);
        if (s > smax) {
          jA = kAcol - 1;
          smax = s;
        }
      }

      if (b_A_data[jj + jA] != 0.0) {
        if (jA != 0) {
          jA += j;
          ipiv_0 = static_cast<int8_T>(jA + 1);
          for (n = 0; n < 5; n++) {
            b_temp_tmp = n * 5 + j;
            smax = b_A_data[b_temp_tmp];
            kAcol = n * 5 + jA;
            b_A_data[b_temp_tmp] = b_A_data[kAcol];
            b_A_data[kAcol] = smax;
          }
        }

        n = (jj - j) + 5;
        jA = (((((n - jj) - 1) / 2) << 1) + jj) + 2;
        b_temp_tmp = jA - 2;
        for (kAcol = jj + 2; kAcol <= b_temp_tmp; kAcol += 2) {
          __m128d tmp_0;
          tmp_0 = _mm_loadu_pd(&b_A_data[kAcol - 1]);
          _mm_storeu_pd(&b_A_data[kAcol - 1], _mm_div_pd(tmp_0, _mm_set1_pd
            (b_A_data[jj])));
        }

        for (kAcol = jA; kAcol <= n; kAcol++) {
          b_A_data[kAcol - 1] /= b_A_data[jj];
        }
      }

      jA = jj + 7;
      b_temp_tmp = 3 - j;
      for (kAcol = 0; kAcol <= b_temp_tmp; kAcol++) {
        smax = b_A_data[(kAcol * 5 + jj) + 5];
        if (smax != 0.0) {
          int32_T e;
          e = (jA - j) + 3;
          for (n = jA; n <= e; n++) {
            b_A_data[n - 1] += b_A_data[((jj + n) - jA) + 1] * -smax;
          }
        }

        jA += 5;
      }

      if (j + 1 != ipiv_0) {
        smax = B_data[j];
        B_data[j] = B_data[ipiv_0 - 1];
        B_data[ipiv_0 - 1] = smax;
      }

      ipiv[j] = ipiv_0;
    }

    for (int32_T j{0}; j < 5; j++) {
      kAcol = 5 * j;
      if (B_data[j] != 0.0) {
        for (jj = j + 2; jj < 6; jj++) {
          B_data[jj - 1] -= b_A_data[(jj + kAcol) - 1] * B_data[j];
        }
      }
    }

    for (int32_T j{4}; j >= 0; j--) {
      kAcol = 5 * j;
      if (B_data[j] != 0.0) {
        B_data[j] /= b_A_data[j + kAcol];
        for (jj = 0; jj < j; jj++) {
          B_data[jj] -= b_A_data[jj + kAcol] * B_data[j];
        }
      }
    }
  } else {
    GNSSPreProcessingSing_qrsolve_g(A_data, A_size, B_data, B_size, tmp);
    *B_size = 5;
    for (int32_T kAcol{0}; kAcol < 5; kAcol++) {
      B_data[kAcol] = tmp[kAcol];
    }
  }
}

void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_plus_fr(real_T in1[5],
  const real_T in2_data[], const int32_T *in2_size)
{
  int32_T stride_0_0;
  stride_0_0 = (*in2_size != 1);
  for (int32_T i{0}; i < 5; i++) {
    in1[i] += in2_data[i * stride_0_0];
  }
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
real_T GNSS_preprocessingModelClass::GNSSPr_calc_delta_T_GNSS_system(const
  real_T gnss_measurement_satellite_posi[], const int32_T
  gnss_measurement_satellite_po_0[2], const uint16_T gnss_measurement_PRN_data[],
  const int32_T *gnss_measurement_PRN_size, const real_T
  gnss_measurement_pseudorange_da[], const int32_T
  *gnss_measurement_pseudorange_si)
{
  real_T H_data[320];
  real_T satellite_position_galileo_data[240];
  real_T satellite_position_gps_data[240];
  real_T delta_rho_data[160];
  real_T pseudorange_galileo_data[80];
  real_T pseudorange_gps_data[80];
  real_T GPSGalileoPosition_data[5];
  real_T b_residuum[5];
  real_T b_user_state[5];
  real_T residuum[4];
  real_T tmp[4];
  real_T user_state[4];
  real_T absxk;
  real_T delta_t;
  real_T scale;
  int32_T H_size[2];
  int32_T b_H_size[2];
  int32_T satellite_position_galileo_size[2];
  int32_T delta_rho_size;
  int32_T g_size_idx_0;
  int32_T i_tmp;
  int32_T iter;
  int32_T l_size;
  int32_T pseudorange_gps_size;
  int8_T g_data[80];
  int8_T h_data[80];
  int8_T i_data[80];
  int8_T j_data[80];
  boolean_T l_data[80];
  boolean_T l_data_0[80];
  if (*gnss_measurement_pseudorange_si > 5) {
    real_T b_t;
    real_T t;
    int32_T exitg1;
    boolean_T guard1{ false };

    GNSSPreProcessingSingl_isMember(gnss_measurement_PRN_data,
      gnss_measurement_PRN_size, l_data_0, &l_size);
    guard1 = false;
    if (GNSSPreProcessingSingleA_any_aa(l_data_0, &l_size)) {
      GNSSPreProcessingSin_isMember_d(gnss_measurement_PRN_data,
        gnss_measurement_PRN_size, l_data, &iter);
      if (GNSSPreProcessingSingleA_any_aa(l_data, &iter)) {
        for (int32_T i{0}; i < 5; i++) {
          b_user_state[i] = 0.0;
        }

        i_tmp = iter - 1;
        delta_rho_size = 0;
        for (iter = 0; iter <= i_tmp; iter++) {
          if (l_data[iter]) {
            delta_rho_size++;
          }
        }

        g_size_idx_0 = delta_rho_size;
        delta_rho_size = 0;
        for (iter = 0; iter <= i_tmp; iter++) {
          if (l_data[iter]) {
            g_data[delta_rho_size] = static_cast<int8_T>(iter + 1);
            delta_rho_size++;
          }
        }

        H_size[0] = g_size_idx_0;
        H_size[1] = gnss_measurement_satellite_po_0[1];
        delta_rho_size = gnss_measurement_satellite_po_0[1];
        for (int32_T i{0}; i < delta_rho_size; i++) {
          for (iter = 0; iter < g_size_idx_0; iter++) {
            satellite_position_gps_data[iter + g_size_idx_0 * i] =
              gnss_measurement_satellite_posi[(gnss_measurement_satellite_po_0[0]
              * i + g_data[iter]) - 1];
          }
        }

        delta_rho_size = 0;
        for (iter = 0; iter <= i_tmp; iter++) {
          if (l_data[iter]) {
            delta_rho_size++;
          }
        }

        g_size_idx_0 = delta_rho_size;
        delta_rho_size = 0;
        for (iter = 0; iter <= i_tmp; iter++) {
          if (l_data[iter]) {
            h_data[delta_rho_size] = static_cast<int8_T>(iter + 1);
            delta_rho_size++;
          }
        }

        pseudorange_gps_size = g_size_idx_0;
        for (int32_T i{0}; i < g_size_idx_0; i++) {
          pseudorange_gps_data[i] = gnss_measurement_pseudorange_da[h_data[i] -
            1];
        }

        i_tmp = l_size - 1;
        delta_rho_size = 0;
        for (iter = 0; iter <= i_tmp; iter++) {
          if (l_data_0[iter]) {
            delta_rho_size++;
          }
        }

        g_size_idx_0 = delta_rho_size;
        delta_rho_size = 0;
        for (iter = 0; iter <= i_tmp; iter++) {
          if (l_data_0[iter]) {
            i_data[delta_rho_size] = static_cast<int8_T>(iter + 1);
            delta_rho_size++;
          }
        }

        satellite_position_galileo_size[0] = g_size_idx_0;
        satellite_position_galileo_size[1] = gnss_measurement_satellite_po_0[1];
        delta_rho_size = gnss_measurement_satellite_po_0[1];
        for (int32_T i{0}; i < delta_rho_size; i++) {
          for (iter = 0; iter < g_size_idx_0; iter++) {
            satellite_position_galileo_data[iter + g_size_idx_0 * i] =
              gnss_measurement_satellite_posi[(gnss_measurement_satellite_po_0[0]
              * i + i_data[iter]) - 1];
          }
        }

        delta_rho_size = 0;
        for (iter = 0; iter <= i_tmp; iter++) {
          if (l_data_0[iter]) {
            delta_rho_size++;
          }
        }

        g_size_idx_0 = delta_rho_size;
        delta_rho_size = 0;
        for (iter = 0; iter <= i_tmp; iter++) {
          if (l_data_0[iter]) {
            j_data[delta_rho_size] = static_cast<int8_T>(iter + 1);
            delta_rho_size++;
          }
        }

        for (int32_T i{0}; i < g_size_idx_0; i++) {
          pseudorange_galileo_data[i] = gnss_measurement_pseudorange_da[j_data[i]
            - 1];
        }

        for (int32_T i{0}; i < 5; i++) {
          GPSGalileoPosition_data[i] = 0.0;
        }

        GNSSPreProc_getJacobiMultiKonst(satellite_position_gps_data, H_size,
          satellite_position_galileo_data, satellite_position_galileo_size,
          pseudorange_gps_data, &pseudorange_gps_size, pseudorange_galileo_data,
          &g_size_idx_0, GPSGalileoPosition_data, delta_rho_data,
          &delta_rho_size, GNSSPreProcessingSingleAntenn_B.b_H_data, b_H_size,
          b_residuum);
        iter = 0;
        do {
          exitg1 = 0;
          scale = 0.0;
          absxk = 3.3121686421112381E-170;
          for (int32_T i{0}; i < 5; i++) {
            t = std::abs(b_residuum[i]);
            if (t > absxk) {
              b_t = absxk / t;
              scale = scale * b_t * b_t + 1.0;
              absxk = t;
            } else {
              b_t = t / absxk;
              scale += b_t * b_t;
            }
          }

          scale = absxk * std::sqrt(scale);
          if ((scale > 0.01) && (iter < 1000)) {
            GNSSPreProcessingS_mldivide_e2x
              (GNSSPreProcessingSingleAntenn_B.b_H_data, b_H_size,
               delta_rho_data, &delta_rho_size);
            if (delta_rho_size == 5) {
              for (int32_T i{0}; i <= 2; i += 2) {
                __m128d tmp_0;
                __m128d tmp_1;
                tmp_0 = _mm_loadu_pd(&b_user_state[i]);
                tmp_1 = _mm_loadu_pd(&delta_rho_data[i]);
                _mm_storeu_pd(&b_user_state[i], _mm_add_pd(tmp_0, tmp_1));
              }

              for (int32_T i{4}; i < 5; i++) {
                b_user_state[i] += delta_rho_data[i];
              }
            } else {
              GNSSPreProcessingSingle_plus_fr(b_user_state, delta_rho_data,
                &delta_rho_size);
            }

            GNSSPreProc_getJacobiMultiKonst(satellite_position_gps_data, H_size,
              satellite_position_galileo_data, satellite_position_galileo_size,
              pseudorange_gps_data, &pseudorange_gps_size,
              pseudorange_galileo_data, &g_size_idx_0, b_user_state,
              delta_rho_data, &delta_rho_size,
              GNSSPreProcessingSingleAntenn_B.b_H_data, b_H_size, b_residuum);
            iter++;
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);

        delta_rho_size = 5;
        for (int32_T i{0}; i < 5; i++) {
          GPSGalileoPosition_data[i] = b_user_state[i];
        }
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      user_state[0] = 0.0;
      tmp[0] = 0.0;
      user_state[1] = 0.0;
      tmp[1] = 0.0;
      user_state[2] = 0.0;
      tmp[2] = 0.0;
      user_state[3] = 0.0;
      tmp[3] = 0.0;
      GNSSPreProcessingSi_getJacobi_o(gnss_measurement_satellite_posi,
        gnss_measurement_satellite_po_0, gnss_measurement_pseudorange_da,
        gnss_measurement_pseudorange_si, tmp, pseudorange_gps_data,
        &pseudorange_gps_size, H_data, H_size, residuum);
      delta_rho_size = pseudorange_gps_size;
      if (pseudorange_gps_size - 1 >= 0) {
        std::memcpy(&delta_rho_data[0], &pseudorange_gps_data[0],
                    static_cast<uint32_T>(pseudorange_gps_size) * sizeof(real_T));
      }

      iter = 0;
      do {
        exitg1 = 0;
        scale = 3.3121686421112381E-170;
        absxk = std::abs(residuum[0]);
        if (absxk > 3.3121686421112381E-170) {
          b_t = 1.0;
          scale = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          b_t = t * t;
        }

        absxk = std::abs(residuum[1]);
        if (absxk > scale) {
          t = scale / absxk;
          b_t = b_t * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          b_t += t * t;
        }

        absxk = std::abs(residuum[2]);
        if (absxk > scale) {
          t = scale / absxk;
          b_t = b_t * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          b_t += t * t;
        }

        absxk = std::abs(residuum[3]);
        if (absxk > scale) {
          t = scale / absxk;
          b_t = b_t * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          b_t += t * t;
        }

        b_t = scale * std::sqrt(b_t);
        if ((b_t > 1.0E-15) && (iter < 1000)) {
          if (delta_rho_size - 1 >= 0) {
            std::memcpy(&pseudorange_gps_data[0], &delta_rho_data[0],
                        static_cast<uint32_T>(delta_rho_size) * sizeof(real_T));
          }

          GNSSPreProcessing_mldivide_e2x2(H_data, H_size, pseudorange_gps_data,
            &pseudorange_gps_size);
          if (pseudorange_gps_size == 4) {
            user_state[0] += pseudorange_gps_data[0];
            user_state[1] += pseudorange_gps_data[1];
            user_state[2] += pseudorange_gps_data[2];
            user_state[3] += pseudorange_gps_data[3];
          } else {
            GNSSPreProcessingSingleA_plus_f(user_state, pseudorange_gps_data,
              &pseudorange_gps_size);
          }

          GNSSPreProcessingSi_getJacobi_o(gnss_measurement_satellite_posi,
            gnss_measurement_satellite_po_0, gnss_measurement_pseudorange_da,
            gnss_measurement_pseudorange_si, user_state, pseudorange_gps_data,
            &pseudorange_gps_size, H_data, H_size, residuum);
          delta_rho_size = pseudorange_gps_size;
          if (pseudorange_gps_size - 1 >= 0) {
            std::memcpy(&delta_rho_data[0], &pseudorange_gps_data[0],
                        static_cast<uint32_T>(pseudorange_gps_size) * sizeof
                        (real_T));
          }

          iter++;
        } else {
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      delta_rho_size = 4;
      GPSGalileoPosition_data[0] = user_state[0];
      GPSGalileoPosition_data[1] = user_state[1];
      GPSGalileoPosition_data[2] = user_state[2];
      GPSGalileoPosition_data[3] = user_state[3];
    }

    if (delta_rho_size > 4) {
      GNSSPreProcessingSingleAntenn_B.GPSGalileoPosition[0] =
        GPSGalileoPosition_data[0];
      GNSSPreProcessingSingleAntenn_B.GPSGalileoPosition[200] =
        GPSGalileoPosition_data[1];
      GNSSPreProcessingSingleAntenn_B.GPSGalileoPosition[400] =
        GPSGalileoPosition_data[2];
      GNSSPreProcessingSingleAntenn_B.GPSGalileoPosition[600] =
        GPSGalileoPosition_data[3];
      GNSSPreProcessingSingleAntenn_B.GPSGalileoPosition[800] =
        GPSGalileoPosition_data[4];
      for (int32_T i{0}; i < 199; i++) {
        for (iter = 0; iter < 5; iter++) {
          delta_rho_size = 200 * iter + i;
          GNSSPreProcessingSingleAntenn_B.GPSGalileoPosition[delta_rho_size + 1]
            = GNSSPreProcessingSingleAnten_DW.userposBuffer[delta_rho_size];
        }
      }

      std::memcpy(&GNSSPreProcessingSingleAnten_DW.userposBuffer[0],
                  &GNSSPreProcessingSingleAntenn_B.GPSGalileoPosition[0], 1000U *
                  sizeof(real_T));
      GNSSPreProcessingSingleAnten_DW.writeIdx++;
      if (GNSSPreProcessingSingleAnten_DW.writeIdx > 200.0) {
        GNSSPreProcessingSingleAnten_DW.writeIdx = 200.0;
      }
    }
  }

  if (GNSSPreProcessingSingleAnten_DW.writeIdx == 1.0) {
    delta_t = 0.0;
  } else {
    i_tmp = static_cast<int32_T>(GNSSPreProcessingSingleAnten_DW.writeIdx - 1.0);
    scale = GNSSPreProcessingSingleAnten_DW.userposBuffer[600];
    absxk = GNSSPreProcessingSingleAnten_DW.userposBuffer[800];
    for (delta_rho_size = 2; delta_rho_size <= i_tmp; delta_rho_size++) {
      scale += GNSSPreProcessingSingleAnten_DW.userposBuffer[delta_rho_size +
        599];
      absxk += GNSSPreProcessingSingleAnten_DW.userposBuffer[delta_rho_size +
        799];
    }

    delta_t = (scale / static_cast<real_T>(static_cast<int32_T>
                (GNSSPreProcessingSingleAnten_DW.writeIdx - 1.0)) - absxk /
               static_cast<real_T>(static_cast<int32_T>
                (GNSSPreProcessingSingleAnten_DW.writeIdx - 1.0))) /
      2.99792458E+8;
  }

  return delta_t;
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
void GNSS_preprocessingModelClass::GNSSPreProcessing_mergeMyBus_cs(const
  s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T *varargin_1, const
  emxArray__GNSS_Measurement_GN_T *varargin_2, s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T
  *outputBus)
{
  int32_T loop_ub;
  int32_T loop_ub_0;
  int8_T empty_non_axis_sizes_0[2];
  int8_T empty_non_axis_sizes_1[2];
  int8_T sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  outputBus->time_receive = varargin_1->time_receive;
  outputBus->base_position[0] = varargin_1->base_position[0];
  outputBus->base_position[1] = varargin_1->base_position[1];
  outputBus->base_position[2] = varargin_1->base_position[2];
  if ((varargin_1->satellite_position.size[0] != 0) &&
      (varargin_1->satellite_position.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_position.size[1]);
  } else if ((varargin_2->satellite_position.size[0] != 0) &&
             (varargin_2->satellite_position.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_position.size[1]);
  } else if (varargin_2->satellite_position.size[1] >
             varargin_1->satellite_position.size[1]) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_position.size[1]);
  } else {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_position.size[1]);
  }

  empty_non_axis_sizes = (sizes_idx_1 == 0);
  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_position.size[0]);
  } else if ((varargin_1->satellite_position.size[0] != 0) &&
             (varargin_1->satellite_position.size[1] != 0)) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_position.size[0]);
  } else {
    empty_non_axis_sizes_0[0] = 0;
  }

  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_position.size[0]);
  } else if ((varargin_2->satellite_position.size[0] != 0) &&
             (varargin_2->satellite_position.size[1] != 0)) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_position.size[0]);
  } else {
    empty_non_axis_sizes_1[0] = 0;
  }

  outputBus->satellite_position.size[0] = empty_non_axis_sizes_0[0] +
    empty_non_axis_sizes_1[0];
  outputBus->satellite_position.size[1] = sizes_idx_1;
  loop_ub = sizes_idx_1;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    loop_ub_0 = empty_non_axis_sizes_0[0];
    for (int32_T i{0}; i < loop_ub_0; i++) {
      outputBus->satellite_position.data[i + outputBus->satellite_position.size
        [0] * i_0] = varargin_1->satellite_position.data[empty_non_axis_sizes_0
        [0] * i_0 + i];
    }
  }

  loop_ub = sizes_idx_1;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    loop_ub_0 = empty_non_axis_sizes_1[0];
    for (int32_T i{0}; i < loop_ub_0; i++) {
      outputBus->satellite_position.data[(i + empty_non_axis_sizes_0[0]) +
        outputBus->satellite_position.size[0] * i_0] =
        varargin_2->satellite_position.data[empty_non_axis_sizes_1[0] * i_0 + i];
    }
  }

  if ((varargin_1->satellite_velocity.size[0] != 0) &&
      (varargin_1->satellite_velocity.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_velocity.size[1]);
  } else if ((varargin_2->satellite_velocity.size[0] != 0) &&
             (varargin_2->satellite_velocity.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_velocity.size[1]);
  } else if (varargin_2->satellite_velocity.size[1] >
             varargin_1->satellite_velocity.size[1]) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_velocity.size[1]);
  } else {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_velocity.size[1]);
  }

  empty_non_axis_sizes = (sizes_idx_1 == 0);
  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_velocity.size[0]);
  } else if ((varargin_1->satellite_velocity.size[0] != 0) &&
             (varargin_1->satellite_velocity.size[1] != 0)) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_velocity.size[0]);
  } else {
    empty_non_axis_sizes_0[0] = 0;
  }

  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_velocity.size[0]);
  } else if ((varargin_2->satellite_velocity.size[0] != 0) &&
             (varargin_2->satellite_velocity.size[1] != 0)) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_velocity.size[0]);
  } else {
    empty_non_axis_sizes_1[0] = 0;
  }

  outputBus->satellite_velocity.size[0] = empty_non_axis_sizes_0[0] +
    empty_non_axis_sizes_1[0];
  outputBus->satellite_velocity.size[1] = sizes_idx_1;
  loop_ub = sizes_idx_1;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    loop_ub_0 = empty_non_axis_sizes_0[0];
    for (int32_T i{0}; i < loop_ub_0; i++) {
      outputBus->satellite_velocity.data[i + outputBus->satellite_velocity.size
        [0] * i_0] = varargin_1->satellite_velocity.data[empty_non_axis_sizes_0
        [0] * i_0 + i];
    }
  }

  loop_ub = sizes_idx_1;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    loop_ub_0 = empty_non_axis_sizes_1[0];
    for (int32_T i{0}; i < loop_ub_0; i++) {
      outputBus->satellite_velocity.data[(i + empty_non_axis_sizes_0[0]) +
        outputBus->satellite_velocity.size[0] * i_0] =
        varargin_2->satellite_velocity.data[empty_non_axis_sizes_1[0] * i_0 + i];
    }
  }

  outputBus->PRN.size = varargin_1->PRN.size + varargin_2->PRN.size;
  if (varargin_1->PRN.size - 1 >= 0) {
    std::memcpy(&outputBus->PRN.data[0], &varargin_1->PRN.data[0],
                static_cast<uint32_T>(varargin_1->PRN.size) * sizeof(uint16_T));
  }

  loop_ub = varargin_2->PRN.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->PRN.data[i_0 + varargin_1->PRN.size] = varargin_2->PRN.data[i_0];
  }

  outputBus->pseudorange.size = varargin_1->pseudorange.size +
    varargin_2->pseudorange.size;
  if (varargin_1->pseudorange.size - 1 >= 0) {
    std::memcpy(&outputBus->pseudorange.data[0], &varargin_1->pseudorange.data[0],
                static_cast<uint32_T>(varargin_1->pseudorange.size) * sizeof
                (real_T));
  }

  loop_ub = varargin_2->pseudorange.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->pseudorange.data[i_0 + varargin_1->pseudorange.size] =
      varargin_2->pseudorange.data[i_0];
  }

  outputBus->pseudorange_raw.size = varargin_1->pseudorange_raw.size +
    varargin_2->pseudorange_raw.size;
  if (varargin_1->pseudorange_raw.size - 1 >= 0) {
    std::memcpy(&outputBus->pseudorange_raw.data[0],
                &varargin_1->pseudorange_raw.data[0], static_cast<uint32_T>
                (varargin_1->pseudorange_raw.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->pseudorange_raw.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->pseudorange_raw.data[i_0 + varargin_1->pseudorange_raw.size] =
      varargin_2->pseudorange_raw.data[i_0];
  }

  outputBus->pseudorange_satclk_corrected.size =
    varargin_1->pseudorange_satclk_corrected.size +
    varargin_2->pseudorange_satclk_corrected.size;
  if (varargin_1->pseudorange_satclk_corrected.size - 1 >= 0) {
    std::memcpy(&outputBus->pseudorange_satclk_corrected.data[0],
                &varargin_1->pseudorange_satclk_corrected.data[0],
                static_cast<uint32_T>
                (varargin_1->pseudorange_satclk_corrected.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->pseudorange_satclk_corrected.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->pseudorange_satclk_corrected.data[i_0 +
      varargin_1->pseudorange_satclk_corrected.size] =
      varargin_2->pseudorange_satclk_corrected.data[i_0];
  }

  outputBus->deltarange.size = varargin_1->deltarange.size +
    varargin_2->deltarange.size;
  if (varargin_1->deltarange.size - 1 >= 0) {
    std::memcpy(&outputBus->deltarange.data[0], &varargin_1->deltarange.data[0],
                static_cast<uint32_T>(varargin_1->deltarange.size) * sizeof
                (real_T));
  }

  loop_ub = varargin_2->deltarange.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->deltarange.data[i_0 + varargin_1->deltarange.size] =
      varargin_2->deltarange.data[i_0];
  }

  outputBus->deltarange_raw.size = varargin_1->deltarange_raw.size +
    varargin_2->deltarange_raw.size;
  if (varargin_1->deltarange_raw.size - 1 >= 0) {
    std::memcpy(&outputBus->deltarange_raw.data[0],
                &varargin_1->deltarange_raw.data[0], static_cast<uint32_T>
                (varargin_1->deltarange_raw.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->deltarange_raw.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->deltarange_raw.data[i_0 + varargin_1->deltarange_raw.size] =
      varargin_2->deltarange_raw.data[i_0];
  }

  outputBus->deltarange_satclk_corrected.size =
    varargin_1->deltarange_satclk_corrected.size +
    varargin_2->deltarange_satclk_corrected.size;
  if (varargin_1->deltarange_satclk_corrected.size - 1 >= 0) {
    std::memcpy(&outputBus->deltarange_satclk_corrected.data[0],
                &varargin_1->deltarange_satclk_corrected.data[0],
                static_cast<uint32_T>
                (varargin_1->deltarange_satclk_corrected.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->deltarange_satclk_corrected.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->deltarange_satclk_corrected.data[i_0 +
      varargin_1->deltarange_satclk_corrected.size] =
      varargin_2->deltarange_satclk_corrected.data[i_0];
  }

  outputBus->variance_pseudorange.size = varargin_1->variance_pseudorange.size +
    varargin_2->variance_pseudorange.size;
  if (varargin_1->variance_pseudorange.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_pseudorange.data[0],
                &varargin_1->variance_pseudorange.data[0], static_cast<uint32_T>
                (varargin_1->variance_pseudorange.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->variance_pseudorange.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->variance_pseudorange.data[i_0 +
      varargin_1->variance_pseudorange.size] =
      varargin_2->variance_pseudorange.data[i_0];
  }

  outputBus->variance_pseudorange_measured.size =
    varargin_1->variance_pseudorange_measured.size +
    varargin_2->variance_pseudorange_measured.size;
  if (varargin_1->variance_pseudorange_measured.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_pseudorange_measured.data[0],
                &varargin_1->variance_pseudorange_measured.data[0],
                static_cast<uint32_T>
                (varargin_1->variance_pseudorange_measured.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->variance_pseudorange_measured.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->variance_pseudorange_measured.data[i_0 +
      varargin_1->variance_pseudorange_measured.size] =
      varargin_2->variance_pseudorange_measured.data[i_0];
  }

  outputBus->variance_deltarange.size = varargin_1->variance_deltarange.size +
    varargin_2->variance_deltarange.size;
  if (varargin_1->variance_deltarange.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_deltarange.data[0],
                &varargin_1->variance_deltarange.data[0], static_cast<uint32_T>
                (varargin_1->variance_deltarange.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->variance_deltarange.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->variance_deltarange.data[i_0 +
      varargin_1->variance_deltarange.size] =
      varargin_2->variance_deltarange.data[i_0];
  }

  outputBus->carrierphase.size = varargin_1->carrierphase.size +
    varargin_2->carrierphase.size;
  if (varargin_1->carrierphase.size - 1 >= 0) {
    std::memcpy(&outputBus->carrierphase.data[0], &varargin_1->
                carrierphase.data[0], static_cast<uint32_T>
                (varargin_1->carrierphase.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->carrierphase.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->carrierphase.data[i_0 + varargin_1->carrierphase.size] =
      varargin_2->carrierphase.data[i_0];
  }

  outputBus->carrierphase_raw.size = varargin_1->carrierphase_raw.size +
    varargin_2->carrierphase_raw.size;
  if (varargin_1->carrierphase_raw.size - 1 >= 0) {
    std::memcpy(&outputBus->carrierphase_raw.data[0],
                &varargin_1->carrierphase_raw.data[0], static_cast<uint32_T>
                (varargin_1->carrierphase_raw.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->carrierphase_raw.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->carrierphase_raw.data[i_0 + varargin_1->carrierphase_raw.size] =
      varargin_2->carrierphase_raw.data[i_0];
  }

  outputBus->carrierphase_satclk_corrected.size =
    varargin_1->carrierphase_satclk_corrected.size +
    varargin_2->carrierphase_satclk_corrected.size;
  if (varargin_1->carrierphase_satclk_corrected.size - 1 >= 0) {
    std::memcpy(&outputBus->carrierphase_satclk_corrected.data[0],
                &varargin_1->carrierphase_satclk_corrected.data[0], static_cast<
                uint32_T>(varargin_1->carrierphase_satclk_corrected.size) *
                sizeof(real_T));
  }

  loop_ub = varargin_2->carrierphase_satclk_corrected.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->carrierphase_satclk_corrected.data[i_0 +
      varargin_1->carrierphase_satclk_corrected.size] =
      varargin_2->carrierphase_satclk_corrected.data[i_0];
  }

  outputBus->variance_carrierphase_measured.size =
    varargin_1->variance_carrierphase_measured.size +
    varargin_2->variance_carrierphase_measured.size;
  if (varargin_1->variance_carrierphase_measured.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_carrierphase_measured.data[0],
                &varargin_1->variance_carrierphase_measured.data[0],
                static_cast<uint32_T>
                (varargin_1->variance_carrierphase_measured.size) * sizeof
                (real_T));
  }

  loop_ub = varargin_2->variance_carrierphase_measured.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->variance_carrierphase_measured.data[i_0 +
      varargin_1->variance_carrierphase_measured.size] =
      varargin_2->variance_carrierphase_measured.data[i_0];
  }

  outputBus->locktime.size = varargin_1->locktime.size +
    varargin_2->locktime.size;
  if (varargin_1->locktime.size - 1 >= 0) {
    std::memcpy(&outputBus->locktime.data[0], &varargin_1->locktime.data[0],
                static_cast<uint32_T>(varargin_1->locktime.size) * sizeof
                (real32_T));
  }

  loop_ub = varargin_2->locktime.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->locktime.data[i_0 + varargin_1->locktime.size] =
      varargin_2->locktime.data[i_0];
  }

  outputBus->CN0.size = varargin_1->CN0.size + varargin_2->CN0.size;
  if (varargin_1->CN0.size - 1 >= 0) {
    std::memcpy(&outputBus->CN0.data[0], &varargin_1->CN0.data[0],
                static_cast<uint32_T>(varargin_1->CN0.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->CN0.size;
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    outputBus->CN0.data[i_0 + varargin_1->CN0.size] = varargin_2->CN0.data[i_0];
  }
}

// Function for MATLAB Function: '<S3>/Merge GNSS Measurement'
void GNSS_preprocessingModelClass::GNSSPreProcessingSin_mergeMyBus(const
  emxArray__GNSS_Measurement_GN_T *varargin_1, const
  emxArray__GNSS_Measurement_GN_T *varargin_2, const
  emxArray__GNSS_Measurement_GN_T *varargin_3, s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T
  *outputBus)
{
  real_T outputBus_data[360];
  int32_T i;
  int32_T loop_ub;
  int32_T loop_ub_0;
  int32_T outputBus_size_idx_0;
  int8_T empty_non_axis_sizes_0[2];
  int8_T empty_non_axis_sizes_1[2];
  int8_T sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  outputBus->time_receive = varargin_1->time_receive;
  outputBus->base_position[0] = varargin_1->base_position[0];
  outputBus->base_position[1] = varargin_1->base_position[1];
  outputBus->base_position[2] = varargin_1->base_position[2];
  if ((varargin_1->satellite_position.size[0] != 0) &&
      (varargin_1->satellite_position.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_position.size[1]);
  } else if ((varargin_2->satellite_position.size[0] != 0) &&
             (varargin_2->satellite_position.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_position.size[1]);
  } else if (varargin_2->satellite_position.size[1] >
             varargin_1->satellite_position.size[1]) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_position.size[1]);
  } else {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_position.size[1]);
  }

  empty_non_axis_sizes = (sizes_idx_1 == 0);
  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_position.size[0]);
  } else if ((varargin_1->satellite_position.size[0] != 0) &&
             (varargin_1->satellite_position.size[1] != 0)) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_position.size[0]);
  } else {
    empty_non_axis_sizes_0[0] = 0;
  }

  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_position.size[0]);
  } else if ((varargin_2->satellite_position.size[0] != 0) &&
             (varargin_2->satellite_position.size[1] != 0)) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_position.size[0]);
  } else {
    empty_non_axis_sizes_1[0] = 0;
  }

  outputBus->satellite_position.size[0] = empty_non_axis_sizes_0[0] +
    empty_non_axis_sizes_1[0];
  outputBus->satellite_position.size[1] = sizes_idx_1;
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    loop_ub_0 = empty_non_axis_sizes_0[0];
    for (int32_T outputBus_0{0}; outputBus_0 < loop_ub_0; outputBus_0++) {
      outputBus->satellite_position.data[outputBus_0 +
        outputBus->satellite_position.size[0] * i] =
        varargin_1->satellite_position.data[empty_non_axis_sizes_0[0] * i +
        outputBus_0];
    }
  }

  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    loop_ub_0 = empty_non_axis_sizes_1[0];
    for (int32_T outputBus_0{0}; outputBus_0 < loop_ub_0; outputBus_0++) {
      outputBus->satellite_position.data[(outputBus_0 + empty_non_axis_sizes_0[0])
        + outputBus->satellite_position.size[0] * i] =
        varargin_2->satellite_position.data[empty_non_axis_sizes_1[0] * i +
        outputBus_0];
    }
  }

  if ((varargin_1->satellite_velocity.size[0] != 0) &&
      (varargin_1->satellite_velocity.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_velocity.size[1]);
  } else if ((varargin_2->satellite_velocity.size[0] != 0) &&
             (varargin_2->satellite_velocity.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_velocity.size[1]);
  } else if (varargin_2->satellite_velocity.size[1] >
             varargin_1->satellite_velocity.size[1]) {
    sizes_idx_1 = static_cast<int8_T>(varargin_2->satellite_velocity.size[1]);
  } else {
    sizes_idx_1 = static_cast<int8_T>(varargin_1->satellite_velocity.size[1]);
  }

  empty_non_axis_sizes = (sizes_idx_1 == 0);
  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_velocity.size[0]);
  } else if ((varargin_1->satellite_velocity.size[0] != 0) &&
             (varargin_1->satellite_velocity.size[1] != 0)) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (varargin_1->satellite_velocity.size[0]);
  } else {
    empty_non_axis_sizes_0[0] = 0;
  }

  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_velocity.size[0]);
  } else if ((varargin_2->satellite_velocity.size[0] != 0) &&
             (varargin_2->satellite_velocity.size[1] != 0)) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_2->satellite_velocity.size[0]);
  } else {
    empty_non_axis_sizes_1[0] = 0;
  }

  outputBus->satellite_velocity.size[0] = empty_non_axis_sizes_0[0] +
    empty_non_axis_sizes_1[0];
  outputBus->satellite_velocity.size[1] = sizes_idx_1;
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    loop_ub_0 = empty_non_axis_sizes_0[0];
    for (int32_T outputBus_0{0}; outputBus_0 < loop_ub_0; outputBus_0++) {
      outputBus->satellite_velocity.data[outputBus_0 +
        outputBus->satellite_velocity.size[0] * i] =
        varargin_1->satellite_velocity.data[empty_non_axis_sizes_0[0] * i +
        outputBus_0];
    }
  }

  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    loop_ub_0 = empty_non_axis_sizes_1[0];
    for (int32_T outputBus_0{0}; outputBus_0 < loop_ub_0; outputBus_0++) {
      outputBus->satellite_velocity.data[(outputBus_0 + empty_non_axis_sizes_0[0])
        + outputBus->satellite_velocity.size[0] * i] =
        varargin_2->satellite_velocity.data[empty_non_axis_sizes_1[0] * i +
        outputBus_0];
    }
  }

  outputBus->PRN.size = varargin_1->PRN.size + varargin_2->PRN.size;
  if (varargin_1->PRN.size - 1 >= 0) {
    std::memcpy(&outputBus->PRN.data[0], &varargin_1->PRN.data[0],
                static_cast<uint32_T>(varargin_1->PRN.size) * sizeof(uint16_T));
  }

  loop_ub = varargin_2->PRN.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->PRN.data[i + varargin_1->PRN.size] = varargin_2->PRN.data[i];
  }

  outputBus->pseudorange.size = varargin_1->pseudorange.size +
    varargin_2->pseudorange.size;
  if (varargin_1->pseudorange.size - 1 >= 0) {
    std::memcpy(&outputBus->pseudorange.data[0], &varargin_1->pseudorange.data[0],
                static_cast<uint32_T>(varargin_1->pseudorange.size) * sizeof
                (real_T));
  }

  loop_ub = varargin_2->pseudorange.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->pseudorange.data[i + varargin_1->pseudorange.size] =
      varargin_2->pseudorange.data[i];
  }

  outputBus->pseudorange_raw.size = varargin_1->pseudorange_raw.size +
    varargin_2->pseudorange_raw.size;
  if (varargin_1->pseudorange_raw.size - 1 >= 0) {
    std::memcpy(&outputBus->pseudorange_raw.data[0],
                &varargin_1->pseudorange_raw.data[0], static_cast<uint32_T>
                (varargin_1->pseudorange_raw.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->pseudorange_raw.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->pseudorange_raw.data[i + varargin_1->pseudorange_raw.size] =
      varargin_2->pseudorange_raw.data[i];
  }

  outputBus->pseudorange_satclk_corrected.size =
    varargin_1->pseudorange_satclk_corrected.size +
    varargin_2->pseudorange_satclk_corrected.size;
  if (varargin_1->pseudorange_satclk_corrected.size - 1 >= 0) {
    std::memcpy(&outputBus->pseudorange_satclk_corrected.data[0],
                &varargin_1->pseudorange_satclk_corrected.data[0],
                static_cast<uint32_T>
                (varargin_1->pseudorange_satclk_corrected.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->pseudorange_satclk_corrected.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->pseudorange_satclk_corrected.data[i +
      varargin_1->pseudorange_satclk_corrected.size] =
      varargin_2->pseudorange_satclk_corrected.data[i];
  }

  outputBus->deltarange.size = varargin_1->deltarange.size +
    varargin_2->deltarange.size;
  if (varargin_1->deltarange.size - 1 >= 0) {
    std::memcpy(&outputBus->deltarange.data[0], &varargin_1->deltarange.data[0],
                static_cast<uint32_T>(varargin_1->deltarange.size) * sizeof
                (real_T));
  }

  loop_ub = varargin_2->deltarange.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->deltarange.data[i + varargin_1->deltarange.size] =
      varargin_2->deltarange.data[i];
  }

  outputBus->deltarange_raw.size = varargin_1->deltarange_raw.size +
    varargin_2->deltarange_raw.size;
  if (varargin_1->deltarange_raw.size - 1 >= 0) {
    std::memcpy(&outputBus->deltarange_raw.data[0],
                &varargin_1->deltarange_raw.data[0], static_cast<uint32_T>
                (varargin_1->deltarange_raw.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->deltarange_raw.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->deltarange_raw.data[i + varargin_1->deltarange_raw.size] =
      varargin_2->deltarange_raw.data[i];
  }

  outputBus->deltarange_satclk_corrected.size =
    varargin_1->deltarange_satclk_corrected.size +
    varargin_2->deltarange_satclk_corrected.size;
  if (varargin_1->deltarange_satclk_corrected.size - 1 >= 0) {
    std::memcpy(&outputBus->deltarange_satclk_corrected.data[0],
                &varargin_1->deltarange_satclk_corrected.data[0],
                static_cast<uint32_T>
                (varargin_1->deltarange_satclk_corrected.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->deltarange_satclk_corrected.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->deltarange_satclk_corrected.data[i +
      varargin_1->deltarange_satclk_corrected.size] =
      varargin_2->deltarange_satclk_corrected.data[i];
  }

  outputBus->variance_pseudorange.size = varargin_1->variance_pseudorange.size +
    varargin_2->variance_pseudorange.size;
  if (varargin_1->variance_pseudorange.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_pseudorange.data[0],
                &varargin_1->variance_pseudorange.data[0], static_cast<uint32_T>
                (varargin_1->variance_pseudorange.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->variance_pseudorange.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->variance_pseudorange.data[i +
      varargin_1->variance_pseudorange.size] =
      varargin_2->variance_pseudorange.data[i];
  }

  outputBus->variance_pseudorange_measured.size =
    varargin_1->variance_pseudorange_measured.size +
    varargin_2->variance_pseudorange_measured.size;
  if (varargin_1->variance_pseudorange_measured.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_pseudorange_measured.data[0],
                &varargin_1->variance_pseudorange_measured.data[0],
                static_cast<uint32_T>
                (varargin_1->variance_pseudorange_measured.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->variance_pseudorange_measured.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->variance_pseudorange_measured.data[i +
      varargin_1->variance_pseudorange_measured.size] =
      varargin_2->variance_pseudorange_measured.data[i];
  }

  outputBus->variance_deltarange.size = varargin_1->variance_deltarange.size +
    varargin_2->variance_deltarange.size;
  if (varargin_1->variance_deltarange.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_deltarange.data[0],
                &varargin_1->variance_deltarange.data[0], static_cast<uint32_T>
                (varargin_1->variance_deltarange.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->variance_deltarange.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->variance_deltarange.data[i + varargin_1->variance_deltarange.size]
      = varargin_2->variance_deltarange.data[i];
  }

  outputBus->carrierphase.size = varargin_1->carrierphase.size +
    varargin_2->carrierphase.size;
  if (varargin_1->carrierphase.size - 1 >= 0) {
    std::memcpy(&outputBus->carrierphase.data[0], &varargin_1->
                carrierphase.data[0], static_cast<uint32_T>
                (varargin_1->carrierphase.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->carrierphase.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->carrierphase.data[i + varargin_1->carrierphase.size] =
      varargin_2->carrierphase.data[i];
  }

  outputBus->carrierphase_raw.size = varargin_1->carrierphase_raw.size +
    varargin_2->carrierphase_raw.size;
  if (varargin_1->carrierphase_raw.size - 1 >= 0) {
    std::memcpy(&outputBus->carrierphase_raw.data[0],
                &varargin_1->carrierphase_raw.data[0], static_cast<uint32_T>
                (varargin_1->carrierphase_raw.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->carrierphase_raw.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->carrierphase_raw.data[i + varargin_1->carrierphase_raw.size] =
      varargin_2->carrierphase_raw.data[i];
  }

  outputBus->carrierphase_satclk_corrected.size =
    varargin_1->carrierphase_satclk_corrected.size +
    varargin_2->carrierphase_satclk_corrected.size;
  if (varargin_1->carrierphase_satclk_corrected.size - 1 >= 0) {
    std::memcpy(&outputBus->carrierphase_satclk_corrected.data[0],
                &varargin_1->carrierphase_satclk_corrected.data[0], static_cast<
                uint32_T>(varargin_1->carrierphase_satclk_corrected.size) *
                sizeof(real_T));
  }

  loop_ub = varargin_2->carrierphase_satclk_corrected.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->carrierphase_satclk_corrected.data[i +
      varargin_1->carrierphase_satclk_corrected.size] =
      varargin_2->carrierphase_satclk_corrected.data[i];
  }

  outputBus->variance_carrierphase_measured.size =
    varargin_1->variance_carrierphase_measured.size +
    varargin_2->variance_carrierphase_measured.size;
  if (varargin_1->variance_carrierphase_measured.size - 1 >= 0) {
    std::memcpy(&outputBus->variance_carrierphase_measured.data[0],
                &varargin_1->variance_carrierphase_measured.data[0],
                static_cast<uint32_T>
                (varargin_1->variance_carrierphase_measured.size) * sizeof
                (real_T));
  }

  loop_ub = varargin_2->variance_carrierphase_measured.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->variance_carrierphase_measured.data[i +
      varargin_1->variance_carrierphase_measured.size] =
      varargin_2->variance_carrierphase_measured.data[i];
  }

  outputBus->locktime.size = varargin_1->locktime.size +
    varargin_2->locktime.size;
  if (varargin_1->locktime.size - 1 >= 0) {
    std::memcpy(&outputBus->locktime.data[0], &varargin_1->locktime.data[0],
                static_cast<uint32_T>(varargin_1->locktime.size) * sizeof
                (real32_T));
  }

  loop_ub = varargin_2->locktime.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->locktime.data[i + varargin_1->locktime.size] =
      varargin_2->locktime.data[i];
  }

  outputBus->CN0.size = varargin_1->CN0.size + varargin_2->CN0.size;
  if (varargin_1->CN0.size - 1 >= 0) {
    std::memcpy(&outputBus->CN0.data[0], &varargin_1->CN0.data[0],
                static_cast<uint32_T>(varargin_1->CN0.size) * sizeof(real_T));
  }

  loop_ub = varargin_2->CN0.size;
  for (i = 0; i < loop_ub; i++) {
    outputBus->CN0.data[i + varargin_1->CN0.size] = varargin_2->CN0.data[i];
  }

  if ((outputBus->satellite_position.size[0] != 0) &&
      (outputBus->satellite_position.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(outputBus->satellite_position.size[1]);
  } else if ((varargin_3->satellite_position.size[0] != 0) &&
             (varargin_3->satellite_position.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_3->satellite_position.size[1]);
  } else if (varargin_3->satellite_position.size[1] >
             outputBus->satellite_position.size[1]) {
    sizes_idx_1 = static_cast<int8_T>(varargin_3->satellite_position.size[1]);
  } else {
    sizes_idx_1 = static_cast<int8_T>(outputBus->satellite_position.size[1]);
  }

  empty_non_axis_sizes = (sizes_idx_1 == 0);
  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (outputBus->satellite_position.size[0]);
  } else if ((outputBus->satellite_position.size[0] != 0) &&
             (outputBus->satellite_position.size[1] != 0)) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (outputBus->satellite_position.size[0]);
  } else {
    empty_non_axis_sizes_0[0] = 0;
  }

  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_3->satellite_position.size[0]);
  } else if ((varargin_3->satellite_position.size[0] != 0) &&
             (varargin_3->satellite_position.size[1] != 0)) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_3->satellite_position.size[0]);
  } else {
    empty_non_axis_sizes_1[0] = 0;
  }

  outputBus_size_idx_0 = empty_non_axis_sizes_0[0] + empty_non_axis_sizes_1[0];
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    loop_ub_0 = empty_non_axis_sizes_0[0];
    for (int32_T outputBus_0{0}; outputBus_0 < loop_ub_0; outputBus_0++) {
      outputBus_data[outputBus_0 + outputBus_size_idx_0 * i] =
        outputBus->satellite_position.data[empty_non_axis_sizes_0[0] * i +
        outputBus_0];
    }
  }

  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    loop_ub_0 = empty_non_axis_sizes_1[0];
    for (int32_T outputBus_0{0}; outputBus_0 < loop_ub_0; outputBus_0++) {
      outputBus_data[(outputBus_0 + empty_non_axis_sizes_0[0]) +
        outputBus_size_idx_0 * i] = varargin_3->
        satellite_position.data[empty_non_axis_sizes_1[0] * i + outputBus_0];
    }
  }

  outputBus->satellite_position.size[0] = outputBus_size_idx_0;
  outputBus->satellite_position.size[1] = sizes_idx_1;
  loop_ub = outputBus_size_idx_0 * sizes_idx_1;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&outputBus->satellite_position.data[0], &outputBus_data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  if ((outputBus->satellite_velocity.size[0] != 0) &&
      (outputBus->satellite_velocity.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(outputBus->satellite_velocity.size[1]);
  } else if ((varargin_3->satellite_velocity.size[0] != 0) &&
             (varargin_3->satellite_velocity.size[1] != 0)) {
    sizes_idx_1 = static_cast<int8_T>(varargin_3->satellite_velocity.size[1]);
  } else if (varargin_3->satellite_velocity.size[1] >
             outputBus->satellite_velocity.size[1]) {
    sizes_idx_1 = static_cast<int8_T>(varargin_3->satellite_velocity.size[1]);
  } else {
    sizes_idx_1 = static_cast<int8_T>(outputBus->satellite_velocity.size[1]);
  }

  empty_non_axis_sizes = (sizes_idx_1 == 0);
  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (outputBus->satellite_velocity.size[0]);
  } else if ((outputBus->satellite_velocity.size[0] != 0) &&
             (outputBus->satellite_velocity.size[1] != 0)) {
    empty_non_axis_sizes_0[0] = static_cast<int8_T>
      (outputBus->satellite_velocity.size[0]);
  } else {
    empty_non_axis_sizes_0[0] = 0;
  }

  if (empty_non_axis_sizes) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_3->satellite_velocity.size[0]);
  } else if ((varargin_3->satellite_velocity.size[0] != 0) &&
             (varargin_3->satellite_velocity.size[1] != 0)) {
    empty_non_axis_sizes_1[0] = static_cast<int8_T>
      (varargin_3->satellite_velocity.size[0]);
  } else {
    empty_non_axis_sizes_1[0] = 0;
  }

  outputBus_size_idx_0 = empty_non_axis_sizes_0[0] + empty_non_axis_sizes_1[0];
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    loop_ub_0 = empty_non_axis_sizes_0[0];
    for (int32_T outputBus_0{0}; outputBus_0 < loop_ub_0; outputBus_0++) {
      outputBus_data[outputBus_0 + outputBus_size_idx_0 * i] =
        outputBus->satellite_velocity.data[empty_non_axis_sizes_0[0] * i +
        outputBus_0];
    }
  }

  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    loop_ub_0 = empty_non_axis_sizes_1[0];
    for (int32_T outputBus_0{0}; outputBus_0 < loop_ub_0; outputBus_0++) {
      outputBus_data[(outputBus_0 + empty_non_axis_sizes_0[0]) +
        outputBus_size_idx_0 * i] = varargin_3->
        satellite_velocity.data[empty_non_axis_sizes_1[0] * i + outputBus_0];
    }
  }

  outputBus->satellite_velocity.size[0] = outputBus_size_idx_0;
  outputBus->satellite_velocity.size[1] = sizes_idx_1;
  loop_ub = outputBus_size_idx_0 * sizes_idx_1;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&outputBus->satellite_velocity.data[0], &outputBus_data[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  i = outputBus->PRN.size;
  outputBus->PRN.size += varargin_3->PRN.size;
  loop_ub = varargin_3->PRN.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->PRN.data[i + outputBus_0] = varargin_3->PRN.data[outputBus_0];
  }

  i = outputBus->pseudorange.size;
  outputBus->pseudorange.size += varargin_3->pseudorange.size;
  loop_ub = varargin_3->pseudorange.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->pseudorange.data[i + outputBus_0] = varargin_3->
      pseudorange.data[outputBus_0];
  }

  i = outputBus->pseudorange_raw.size;
  outputBus->pseudorange_raw.size += varargin_3->pseudorange_raw.size;
  loop_ub = varargin_3->pseudorange_raw.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->pseudorange_raw.data[i + outputBus_0] =
      varargin_3->pseudorange_raw.data[outputBus_0];
  }

  i = outputBus->pseudorange_satclk_corrected.size;
  outputBus->pseudorange_satclk_corrected.size +=
    varargin_3->pseudorange_satclk_corrected.size;
  loop_ub = varargin_3->pseudorange_satclk_corrected.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->pseudorange_satclk_corrected.data[i + outputBus_0] =
      varargin_3->pseudorange_satclk_corrected.data[outputBus_0];
  }

  i = outputBus->deltarange.size;
  outputBus->deltarange.size += varargin_3->deltarange.size;
  loop_ub = varargin_3->deltarange.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->deltarange.data[i + outputBus_0] = varargin_3->
      deltarange.data[outputBus_0];
  }

  i = outputBus->deltarange_raw.size;
  outputBus->deltarange_raw.size += varargin_3->deltarange_raw.size;
  loop_ub = varargin_3->deltarange_raw.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->deltarange_raw.data[i + outputBus_0] =
      varargin_3->deltarange_raw.data[outputBus_0];
  }

  i = outputBus->deltarange_satclk_corrected.size;
  outputBus->deltarange_satclk_corrected.size +=
    varargin_3->deltarange_satclk_corrected.size;
  loop_ub = varargin_3->deltarange_satclk_corrected.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->deltarange_satclk_corrected.data[i + outputBus_0] =
      varargin_3->deltarange_satclk_corrected.data[outputBus_0];
  }

  i = outputBus->variance_pseudorange.size;
  outputBus->variance_pseudorange.size += varargin_3->variance_pseudorange.size;
  loop_ub = varargin_3->variance_pseudorange.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->variance_pseudorange.data[i + outputBus_0] =
      varargin_3->variance_pseudorange.data[outputBus_0];
  }

  i = outputBus->variance_pseudorange_measured.size;
  outputBus->variance_pseudorange_measured.size +=
    varargin_3->variance_pseudorange_measured.size;
  loop_ub = varargin_3->variance_pseudorange_measured.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->variance_pseudorange_measured.data[i + outputBus_0] =
      varargin_3->variance_pseudorange_measured.data[outputBus_0];
  }

  i = outputBus->variance_deltarange.size;
  outputBus->variance_deltarange.size += varargin_3->variance_deltarange.size;
  loop_ub = varargin_3->variance_deltarange.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->variance_deltarange.data[i + outputBus_0] =
      varargin_3->variance_deltarange.data[outputBus_0];
  }

  i = outputBus->carrierphase.size;
  outputBus->carrierphase.size += varargin_3->carrierphase.size;
  loop_ub = varargin_3->carrierphase.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->carrierphase.data[i + outputBus_0] =
      varargin_3->carrierphase.data[outputBus_0];
  }

  i = outputBus->carrierphase_raw.size;
  outputBus->carrierphase_raw.size += varargin_3->carrierphase_raw.size;
  loop_ub = varargin_3->carrierphase_raw.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->carrierphase_raw.data[i + outputBus_0] =
      varargin_3->carrierphase_raw.data[outputBus_0];
  }

  i = outputBus->carrierphase_satclk_corrected.size;
  outputBus->carrierphase_satclk_corrected.size +=
    varargin_3->carrierphase_satclk_corrected.size;
  loop_ub = varargin_3->carrierphase_satclk_corrected.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->carrierphase_satclk_corrected.data[i + outputBus_0] =
      varargin_3->carrierphase_satclk_corrected.data[outputBus_0];
  }

  i = outputBus->variance_carrierphase_measured.size;
  outputBus->variance_carrierphase_measured.size +=
    varargin_3->variance_carrierphase_measured.size;
  loop_ub = varargin_3->variance_carrierphase_measured.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->variance_carrierphase_measured.data[i + outputBus_0] =
      varargin_3->variance_carrierphase_measured.data[outputBus_0];
  }

  i = outputBus->locktime.size;
  outputBus->locktime.size += varargin_3->locktime.size;
  loop_ub = varargin_3->locktime.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->locktime.data[i + outputBus_0] = varargin_3->
      locktime.data[outputBus_0];
  }

  i = outputBus->CN0.size;
  outputBus->CN0.size += varargin_3->CN0.size;
  loop_ub = varargin_3->CN0.size;
  for (int32_T outputBus_0{0}; outputBus_0 < loop_ub; outputBus_0++) {
    outputBus->CN0.data[i + outputBus_0] = varargin_3->CN0.data[outputBus_0];
  }
}

void GNSS_preprocessingModelClass::GNS_binary_expand_op_fr3pusohsl(real_T in1[3],
  const real_T in2_data[], const int32_T in2_size[2])
{
  int32_T stride_0_1;
  stride_0_1 = (in2_size[1] != 1);
  in1[0] = in2_data[0] - in1[0];
  in1[1] = in2_data[stride_0_1] - in1[1];
  in1[2] = in2_data[stride_0_1 << 1] - in1[2];
}

// Function for MATLAB Function: '<S118>/calculate Variance'
void GNSS_preprocessingModelClass::calculate_Satellite_Elevation_n(const real_T
  user_Position_llh[3], const real_T satellite_Position_ecef_data[], const
  int32_T satellite_Position_ecef_size[2], real_T *elevation_Angle, real_T
  *azimuth_Angle)
{
  real_T elevation_Angle_tmp[9];
  real_T user_Position_ecef[3];
  real_T N;
  real_T a_tmp;
  real_T absxk;
  real_T scale;
  real_T t;
  real_T user_Position_ecef_0;
  real_T user_Position_ecef_1;
  real_T user_Position_ecef_2;
  a_tmp = std::cos(user_Position_llh[0]);
  N = 6.3995936257584924E+6 / std::sqrt(a_tmp * a_tmp * 0.0067394967422761756 +
    1.0);
  user_Position_ecef_1 = std::cos(user_Position_llh[1]);
  user_Position_ecef[0] = (N + user_Position_llh[2]) * a_tmp *
    user_Position_ecef_1;
  user_Position_ecef_0 = std::sin(user_Position_llh[1]);
  user_Position_ecef[1] = (N + user_Position_llh[2]) * std::cos
    (user_Position_llh[0]) * user_Position_ecef_0;
  user_Position_ecef_2 = std::sin(user_Position_llh[0]);
  user_Position_ecef[2] = (0.99330562000985889 * N + user_Position_llh[2]) *
    user_Position_ecef_2;
  if (satellite_Position_ecef_size[1] == 3) {
    for (int32_T i{0}; i <= 0; i += 2) {
      __m128d tmp;
      tmp = _mm_loadu_pd(&user_Position_ecef[i]);
      _mm_storeu_pd(&user_Position_ecef[i], _mm_sub_pd(_mm_loadu_pd
        (&satellite_Position_ecef_data[i]), tmp));
    }

    for (int32_T i{2}; i < 3; i++) {
      user_Position_ecef[i] = satellite_Position_ecef_data[i] -
        user_Position_ecef[i];
    }
  } else {
    GNS_binary_expand_op_fr3pusohsl(user_Position_ecef,
      satellite_Position_ecef_data, satellite_Position_ecef_size);
  }

  scale = 3.3121686421112381E-170;
  absxk = std::abs(user_Position_ecef[0]);
  if (absxk > 3.3121686421112381E-170) {
    N = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    N = t * t;
  }

  absxk = std::abs(user_Position_ecef[1]);
  if (absxk > scale) {
    t = scale / absxk;
    N = N * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    N += t * t;
  }

  absxk = std::abs(user_Position_ecef[2]);
  if (absxk > scale) {
    t = scale / absxk;
    N = N * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    N += t * t;
  }

  N = scale * std::sqrt(N);
  elevation_Angle_tmp[0] = -user_Position_ecef_0;
  elevation_Angle_tmp[1] = user_Position_ecef_1;
  elevation_Angle_tmp[2] = 0.0;
  elevation_Angle_tmp[3] = -user_Position_ecef_2 * user_Position_ecef_1;
  elevation_Angle_tmp[4] = -std::sin(user_Position_llh[0]) *
    user_Position_ecef_0;
  elevation_Angle_tmp[5] = a_tmp;
  elevation_Angle_tmp[6] = a_tmp * user_Position_ecef_1;
  elevation_Angle_tmp[7] = a_tmp * user_Position_ecef_0;
  elevation_Angle_tmp[8] = user_Position_ecef_2;
  user_Position_ecef_0 = 0.0;
  a_tmp = 0.0;
  user_Position_ecef_1 = 0.0;
  for (int32_T i{0}; i < 3; i++) {
    user_Position_ecef_2 = user_Position_ecef[i] / N;
    scale = elevation_Angle_tmp[i + 3];
    absxk = scale * 0.0;
    t = elevation_Angle_tmp[i + 6];
    user_Position_ecef_0 += ((elevation_Angle_tmp[i] * 0.0 + absxk) + t) *
      user_Position_ecef_2;
    t *= 0.0;
    a_tmp += ((absxk + elevation_Angle_tmp[i]) + t) * user_Position_ecef_2;
    user_Position_ecef_1 += ((elevation_Angle_tmp[i] * 0.0 + scale) + t) *
      user_Position_ecef_2;
    user_Position_ecef[i] = user_Position_ecef_2;
  }

  *elevation_Angle = std::asin(user_Position_ecef_0);
  *azimuth_Angle = rt_atan2d_snf(a_tmp, user_Position_ecef_1);
}

// Function for MATLAB Function: '<S118>/Fault Exclusion'
boolean_T GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_any_l(const
  boolean_T x[40])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 40)) {
    if (x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S118>/Fault Exclusion'
void GNSS_preprocessingModelClass::GNSSPreProcessingSin_eml_find_l(const
  boolean_T x[40], int32_T i_data[], int32_T i_size[2])
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  i_size[0] = 1;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 40)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 40) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (idx < 1) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

// Function for MATLAB Function: '<S118>/Fault Exclusion'
void GNSS_preprocessingModelClass::GNSSPreProcessingSi_eml_find_le(const
  boolean_T x_data[], const int32_T x_size[2], int32_T i_data[], int32_T i_size
  [2])
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  i_size[0] = 1;
  i_size[1] = x_size[1];
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x_size[1] - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= x_size[1]) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (x_size[1] == 1) {
    if (idx == 0) {
      i_size[0] = 1;
      i_size[1] = 0;
    }
  } else if (idx < 1) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

// Function for MATLAB Function: '<S118>/Fault Exclusion'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_merge_a(int32_T
  idx_data[], real_T x_data[], int32_T offset, int32_T np, int32_T nq, int32_T
  iwork_data[], real_T xwork_data[])
{
  if (nq != 0) {
    int32_T iout;
    int32_T offset1;
    int32_T p;
    int32_T q;
    offset1 = np + nq;
    for (q = 0; q < offset1; q++) {
      iout = offset + q;
      iwork_data[q] = idx_data[iout];
      xwork_data[q] = x_data[iout];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < offset1) {
          q++;
        } else {
          offset1 = iout - p;
          for (q = p + 1; q <= np; q++) {
            iout = offset1 + q;
            idx_data[iout] = iwork_data[q - 1];
            x_data[iout] = xwork_data[q - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

// Function for MATLAB Function: '<S118>/Fault Exclusion'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_sort_np(real_T
  x_data[], int32_T x_size[2], int32_T idx_data[], int32_T idx_size[2])
{
  real_T b_x_data[40];
  real_T xwork_data[40];
  real_T x4[4];
  int32_T iwork_data[40];
  int32_T b_x_size[2];
  int32_T n;
  int8_T idx4[4];
  int8_T perm[4];
  b_x_size[1] = x_size[1];
  n = x_size[1];
  if (n - 1 >= 0) {
    std::memcpy(&b_x_data[0], &x_data[0], static_cast<uint32_T>(n) * sizeof
                (real_T));
  }

  idx_size[0] = 1;
  idx_size[1] = x_size[1];
  n = x_size[1];
  if (n - 1 >= 0) {
    std::memset(&idx_data[0], 0, static_cast<uint32_T>(n) * sizeof(int32_T));
  }

  if (x_size[1] != 0) {
    int32_T bLen;
    int32_T i2;
    int32_T i3;
    int32_T i4;
    int32_T ib;
    int32_T nTail;
    int32_T quartetOffset;
    int32_T wOffset;
    idx_size[0] = 1;
    idx_size[1] = x_size[1];
    n = x_size[1];
    if (n - 1 >= 0) {
      std::memset(&idx_data[0], 0, static_cast<uint32_T>(n) * sizeof(int32_T));
    }

    b_x_size[1] = x_size[1];
    n = x_size[1];
    if (n - 1 >= 0) {
      std::memcpy(&b_x_data[0], &x_data[0], static_cast<uint32_T>(n) * sizeof
                  (real_T));
    }

    n = x_size[1] - 1;
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    quartetOffset = x_size[1];
    if (quartetOffset - 1 >= 0) {
      std::memset(&xwork_data[0], 0, static_cast<uint32_T>(quartetOffset) *
                  sizeof(real_T));
    }

    bLen = 0;
    ib = -1;
    nTail = x_size[1];
    for (wOffset = 0; wOffset < nTail; wOffset++) {
      real_T tmp_0;
      tmp_0 = b_x_data[wOffset];
      if (std::isnan(tmp_0)) {
        quartetOffset = n - bLen;
        idx_data[quartetOffset] = wOffset + 1;
        xwork_data[quartetOffset] = tmp_0;
        bLen++;
      } else {
        ib++;
        idx4[ib] = static_cast<int8_T>(wOffset + 1);
        x4[ib] = tmp_0;
        if (ib + 1 == 4) {
          real_T tmp;
          quartetOffset = wOffset - bLen;
          if (x4[0] <= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }

          if (x4[2] <= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }

          tmp_0 = x4[ib - 1];
          tmp = x4[i3 - 1];
          if (tmp_0 <= tmp) {
            tmp_0 = x4[i2 - 1];
            if (tmp_0 <= tmp) {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(i2);
              perm[2] = static_cast<int8_T>(i3);
              perm[3] = static_cast<int8_T>(i4);
            } else if (tmp_0 <= x4[i4 - 1]) {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(i3);
              perm[2] = static_cast<int8_T>(i2);
              perm[3] = static_cast<int8_T>(i4);
            } else {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(i3);
              perm[2] = static_cast<int8_T>(i4);
              perm[3] = static_cast<int8_T>(i2);
            }
          } else {
            tmp = x4[i4 - 1];
            if (tmp_0 <= tmp) {
              if (x4[i2 - 1] <= tmp) {
                perm[0] = static_cast<int8_T>(i3);
                perm[1] = static_cast<int8_T>(ib);
                perm[2] = static_cast<int8_T>(i2);
                perm[3] = static_cast<int8_T>(i4);
              } else {
                perm[0] = static_cast<int8_T>(i3);
                perm[1] = static_cast<int8_T>(ib);
                perm[2] = static_cast<int8_T>(i4);
                perm[3] = static_cast<int8_T>(i2);
              }
            } else {
              perm[0] = static_cast<int8_T>(i3);
              perm[1] = static_cast<int8_T>(i4);
              perm[2] = static_cast<int8_T>(ib);
              perm[3] = static_cast<int8_T>(i2);
            }
          }

          idx_data[quartetOffset - 3] = idx4[perm[0] - 1];
          idx_data[quartetOffset - 2] = idx4[perm[1] - 1];
          idx_data[quartetOffset - 1] = idx4[perm[2] - 1];
          idx_data[quartetOffset] = idx4[perm[3] - 1];
          b_x_data[quartetOffset - 3] = x4[perm[0] - 1];
          b_x_data[quartetOffset - 2] = x4[perm[1] - 1];
          b_x_data[quartetOffset - 1] = x4[perm[2] - 1];
          b_x_data[quartetOffset] = x4[perm[3] - 1];
          ib = -1;
        }
      }
    }

    i4 = x_size[1] - bLen;
    if (ib + 1 > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      switch (ib + 1) {
       case 1:
        perm[0] = 1;
        break;

       case 2:
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
        break;

       default:
        if (x4[0] <= x4[1]) {
          if (x4[1] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 2;
            perm[2] = 3;
          } else if (x4[0] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 3;
            perm[2] = 2;
          } else {
            perm[0] = 3;
            perm[1] = 1;
            perm[2] = 2;
          }
        } else if (x4[0] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 1;
          perm[2] = 3;
        } else if (x4[1] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 3;
          perm[2] = 1;
        } else {
          perm[0] = 3;
          perm[1] = 2;
          perm[2] = 1;
        }
        break;
      }

      i2 = static_cast<uint8_T>(ib + 1);
      for (nTail = 0; nTail < i2; nTail++) {
        int8_T perm_0;
        perm_0 = perm[nTail];
        i3 = ((i4 - ib) + nTail) - 1;
        idx_data[i3] = idx4[perm_0 - 1];
        b_x_data[i3] = x4[perm_0 - 1];
      }
    }

    ib = bLen >> 1;
    for (nTail = 0; nTail < ib; nTail++) {
      i2 = i4 + nTail;
      i3 = idx_data[i2];
      quartetOffset = n - nTail;
      idx_data[i2] = idx_data[quartetOffset];
      idx_data[quartetOffset] = i3;
      b_x_data[i2] = xwork_data[quartetOffset];
      b_x_data[quartetOffset] = xwork_data[i2];
    }

    if ((static_cast<uint32_T>(bLen) & 1U) != 0U) {
      n = i4 + ib;
      b_x_data[n] = xwork_data[n];
    }

    if (i4 > 1) {
      quartetOffset = x_size[1];
      if (quartetOffset - 1 >= 0) {
        std::memset(&iwork_data[0], 0, static_cast<uint32_T>(quartetOffset) *
                    sizeof(int32_T));
      }

      quartetOffset = i4 >> 2;
      bLen = 4;
      while (quartetOffset > 1) {
        if ((static_cast<uint32_T>(quartetOffset) & 1U) != 0U) {
          quartetOffset--;
          wOffset = bLen * quartetOffset;
          nTail = i4 - wOffset;
          if (nTail > bLen) {
            GNSSPreProcessingSingle_merge_a(idx_data, b_x_data, wOffset, bLen,
              nTail - bLen, iwork_data, xwork_data);
          }
        }

        nTail = bLen << 1;
        quartetOffset >>= 1;
        for (wOffset = 0; wOffset < quartetOffset; wOffset++) {
          GNSSPreProcessingSingle_merge_a(idx_data, b_x_data, wOffset * nTail,
            bLen, bLen, iwork_data, xwork_data);
        }

        bLen = nTail;
      }

      if (i4 > bLen) {
        GNSSPreProcessingSingle_merge_a(idx_data, b_x_data, 0, bLen, i4 - bLen,
          iwork_data, xwork_data);
      }
    }
  }

  x_size[0] = 1;
  x_size[1] = b_x_size[1];
  n = b_x_size[1];
  if (n - 1 >= 0) {
    std::memcpy(&x_data[0], &b_x_data[0], static_cast<uint32_T>(n) * sizeof
                (real_T));
  }
}

// Function for MATLAB Function: '<S118>/Fault Exclusion'
void GNSS_preprocessingModelClass::GNSSPreProcessingS_eml_find_lei(const
  boolean_T x_data[], const int32_T *x_size, int32_T i_data[], int32_T *i_size)
{
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  idx = 0;
  *i_size = *x_size;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= *x_size - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= *x_size) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (*x_size == 1) {
    if (idx == 0) {
      *i_size = 0;
    }
  } else if (idx < 1) {
    *i_size = 0;
  } else {
    *i_size = idx;
  }
}

// Function for MATLAB Function: '<S118>/Fault Exclusion'
void GNSS_preprocessingModelClass::GNSSPreProcessing_eml_find_leix(const real_T
  x_data[], const int32_T x_size[2], int32_T i_data[], int32_T i_size[2])
{
  int32_T idx;
  int32_T ii;
  int32_T k;
  boolean_T exitg1;
  k = (x_size[1] >= 1);
  idx = 0;
  i_size[0] = 1;
  i_size[1] = k;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x_size[1] - 1)) {
    if (x_data[ii] != 0.0) {
      idx = 1;
      i_data[0] = ii + 1;
      exitg1 = true;
    } else {
      ii++;
    }
  }

  if (k == 1) {
    if (idx == 0) {
      i_size[0] = 1;
      i_size[1] = 0;
    }
  } else {
    i_size[1] = (idx >= 1);
  }
}

// Function for MATLAB Function: '<S118>/Fault Exclusion'
void GNSS_preprocessingModelClass::GNSSPreProcessin_nullAssignment(real_T
  x_data[], int32_T x_size[2], const int32_T idx_data[], const int32_T idx_size
  [2])
{
  int32_T b_size_idx_1;
  int32_T c;
  int32_T k0;
  int32_T nxout;
  boolean_T b_data[40];
  b_size_idx_1 = x_size[1];
  nxout = x_size[1];
  if (nxout - 1 >= 0) {
    std::memset(&b_data[0], 0, static_cast<uint32_T>(nxout) * sizeof(boolean_T));
  }

  nxout = idx_size[1];
  for (int32_T b_k{0}; b_k < nxout; b_k++) {
    b_data[idx_data[b_k] - 1] = true;
  }

  nxout = 0;
  for (int32_T b_k{0}; b_k < b_size_idx_1; b_k++) {
    nxout += b_data[b_k];
  }

  nxout = x_size[1] - nxout;
  k0 = -1;
  c = x_size[1];
  for (int32_T b_k{0}; b_k < c; b_k++) {
    if ((b_k + 1 > b_size_idx_1) || (!b_data[b_k])) {
      k0++;
      x_data[k0] = x_data[b_k];
    }
  }

  if (nxout < 1) {
    x_size[1] = 0;
  } else {
    x_size[1] = nxout;
  }
}

// Function for MATLAB Function: '<Root>/Calculate User Position with LMS'
void GNSS_preprocessingModelClass::GNSSPreProcessingSing_getJacobi(const real_T
  satellite_position_data[], const int32_T satellite_position_size[2], const
  real_T pseudorange_data[], const int32_T *pseudorange_size, const real_T
  user_state[4], real_T delta_rho_data[], int32_T *delta_rho_size, real_T
  H_data[], int32_T H_size[2], real_T residuum[4])
{
  real_T satellite_position[3];
  real_T satellite_position_0[3];
  real_T satellite_position_tmp;
  int32_T c;
  int32_T loop_ub;
  *delta_rho_size = *pseudorange_size;
  if (*pseudorange_size - 1 >= 0) {
    std::memset(&delta_rho_data[0], 0, static_cast<uint32_T>(*pseudorange_size) *
                sizeof(real_T));
  }

  H_size[0] = *pseudorange_size;
  H_size[1] = 4;
  loop_ub = *pseudorange_size << 2;
  if (loop_ub - 1 >= 0) {
    std::memset(&H_data[0], 0, static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  loop_ub = *pseudorange_size;
  for (int32_T H{0}; H < loop_ub; H++) {
    if (satellite_position_size[1] == 3) {
      for (c = 0; c < 3; c++) {
        satellite_position_tmp =
          satellite_position_data[satellite_position_size[0] * c + H] -
          user_state[c];
        satellite_position[c] = satellite_position_tmp;
        satellite_position_0[c] = satellite_position_tmp;
      }

      delta_rho_data[H] = pseudorange_data[H] - (GNSSPreProcessingSingleAnt_norm
        (satellite_position) + user_state[3]);
      satellite_position_tmp = GNSSPreProcessingSingleAnt_norm
        (satellite_position_0);
      for (c = 0; c < 3; c++) {
        H_data[H + H_size[0] * c] =
          -(satellite_position_data[satellite_position_size[0] * c + H] -
            user_state[c]) / satellite_position_tmp;
      }

      H_data[H + H_size[0] * 3] = 1.0;
    } else {
      GNSSPre_binary_expand_op_fr3pus(delta_rho_data, H, pseudorange_data,
        satellite_position_data, satellite_position_size, user_state);
      GNSSPreP_binary_expand_op_fr3pu(H_data, H_size, H, satellite_position_data,
        satellite_position_size, user_state);
    }
  }

  residuum[0] = 0.0;
  residuum[1] = 0.0;
  residuum[2] = 0.0;
  residuum[3] = 0.0;
  c = H_size[0];
  for (loop_ub = 0; loop_ub < c; loop_ub++) {
    satellite_position_tmp = delta_rho_data[loop_ub];
    residuum[0] += H_data[loop_ub] * satellite_position_tmp;
    residuum[1] += H_data[H_size[0] + loop_ub] * satellite_position_tmp;
    residuum[2] += H_data[(H_size[0] << 1) + loop_ub] * satellite_position_tmp;
    residuum[3] += H_data[3 * H_size[0] + loop_ub] * satellite_position_tmp;
  }
}

// Function for MATLAB Function: '<Root>/Calculate User Position with LMS'
real_T GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_xnrm2(int32_T n,
  const real_T x_data[], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x_data[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k{ix0}; k <= kend; k++) {
        real_T absxk;
        absxk = std::abs(x_data[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<Root>/Calculate User Position with LMS'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_qrsolve(const real_T
  A_data[], const int32_T A_size[2], const real_T B_data[], const int32_T
  *B_size, real_T Y[4])
{
  __m128d tmp_0;
  real_T b_A_data[160];
  real_T b_B_data[40];
  real_T tau_data[4];
  real_T vn1[4];
  real_T vn2[4];
  real_T work[4];
  real_T s;
  real_T smax;
  int32_T b_A_size[2];
  int32_T ii;
  int32_T itemp;
  int32_T jA;
  int32_T maxmn;
  int32_T minmana;
  int32_T mmi;
  int32_T rankA;
  int8_T jpvt[4];
  rankA = A_size[0];
  b_A_size[0] = A_size[0];
  minmana = A_size[0] << 2;
  if (minmana - 1 >= 0) {
    std::memcpy(&b_A_data[0], &A_data[0], static_cast<uint32_T>(minmana) *
                sizeof(real_T));
  }

  if (A_size[0] <= 4) {
    minmana = A_size[0];
  } else {
    minmana = 4;
  }

  if (minmana - 1 >= 0) {
    std::memset(&tau_data[0], 0, static_cast<uint32_T>(minmana) * sizeof(real_T));
  }

  if (A_size[0] == 0) {
    jpvt[0] = 1;
    jpvt[1] = 2;
    jpvt[2] = 3;
    jpvt[3] = 4;
  } else {
    minmana = A_size[0];
    jpvt[0] = 1;
    work[0] = 0.0;
    smax = GNSSPreProcessingSingleAn_xnrm2(A_size[0], A_data, 1);
    vn2[0] = smax;
    vn1[0] = smax;
    jpvt[1] = 2;
    work[1] = 0.0;
    smax = GNSSPreProcessingSingleAn_xnrm2(A_size[0], A_data, A_size[0] + 1);
    vn2[1] = smax;
    vn1[1] = smax;
    jpvt[2] = 3;
    work[2] = 0.0;
    smax = GNSSPreProcessingSingleAn_xnrm2(A_size[0], A_data, (A_size[0] << 1) +
      1);
    vn2[2] = smax;
    vn1[2] = smax;
    jpvt[3] = 4;
    work[3] = 0.0;
    smax = GNSSPreProcessingSingleAn_xnrm2(A_size[0], A_data, 3 * A_size[0] + 1);
    vn2[3] = smax;
    vn1[3] = smax;
    if (A_size[0] <= 4) {
      maxmn = A_size[0];
    } else {
      maxmn = 4;
    }

    for (int32_T e_i{0}; e_i < maxmn; e_i++) {
      int32_T b_ix;
      int32_T c_k;
      int32_T pvt;
      int32_T temp_tmp;
      jA = e_i * minmana;
      ii = jA + e_i;
      mmi = rankA - e_i;
      itemp = 4 - e_i;
      pvt = 0;
      if (4 - e_i > 1) {
        smax = std::abs(vn1[e_i]);
        for (b_ix = 2; b_ix <= itemp; b_ix++) {
          s = std::abs(vn1[(e_i + b_ix) - 1]);
          if (s > smax) {
            pvt = b_ix - 1;
            smax = s;
          }
        }
      }

      pvt += e_i;
      if (pvt != e_i) {
        b_ix = pvt * minmana;
        for (c_k = 0; c_k < rankA; c_k++) {
          temp_tmp = b_ix + c_k;
          smax = b_A_data[temp_tmp];
          itemp = jA + c_k;
          b_A_data[temp_tmp] = b_A_data[itemp];
          b_A_data[itemp] = smax;
        }

        itemp = jpvt[pvt];
        jpvt[pvt] = jpvt[e_i];
        jpvt[e_i] = static_cast<int8_T>(itemp);
        vn1[pvt] = vn1[e_i];
        vn2[pvt] = vn2[e_i];
      }

      if (e_i + 1 < rankA) {
        s = b_A_data[ii];
        pvt = ii + 2;
        tau_data[e_i] = 0.0;
        if (mmi > 0) {
          smax = GNSSPreProcessingSingleAn_xnrm2(mmi - 1, b_A_data, ii + 2);
          if (smax != 0.0) {
            smax = rt_hypotd_snf(b_A_data[ii], smax);
            if (b_A_data[ii] >= 0.0) {
              smax = -smax;
            }

            if (std::abs(smax) < 1.0020841800044864E-292) {
              b_ix = 0;
              c_k = ii + mmi;
              do {
                b_ix++;
                itemp = (((((c_k - ii) - 1) / 2) << 1) + ii) + 2;
                jA = itemp - 2;
                for (temp_tmp = pvt; temp_tmp <= jA; temp_tmp += 2) {
                  tmp_0 = _mm_loadu_pd(&b_A_data[temp_tmp - 1]);
                  _mm_storeu_pd(&b_A_data[temp_tmp - 1], _mm_mul_pd(tmp_0,
                    _mm_set1_pd(9.9792015476736E+291)));
                }

                for (temp_tmp = itemp; temp_tmp <= c_k; temp_tmp++) {
                  b_A_data[temp_tmp - 1] *= 9.9792015476736E+291;
                }

                smax *= 9.9792015476736E+291;
                s *= 9.9792015476736E+291;
              } while ((std::abs(smax) < 1.0020841800044864E-292) && (b_ix < 20));

              smax = rt_hypotd_snf(s, GNSSPreProcessingSingleAn_xnrm2(mmi - 1,
                b_A_data, ii + 2));
              if (s >= 0.0) {
                smax = -smax;
              }

              tau_data[e_i] = (smax - s) / smax;
              s = 1.0 / (s - smax);
              itemp = (((((c_k - ii) - 1) / 2) << 1) + ii) + 2;
              jA = itemp - 2;
              for (temp_tmp = pvt; temp_tmp <= jA; temp_tmp += 2) {
                tmp_0 = _mm_loadu_pd(&b_A_data[temp_tmp - 1]);
                _mm_storeu_pd(&b_A_data[temp_tmp - 1], _mm_mul_pd(tmp_0,
                  _mm_set1_pd(s)));
              }

              for (temp_tmp = itemp; temp_tmp <= c_k; temp_tmp++) {
                b_A_data[temp_tmp - 1] *= s;
              }

              for (itemp = 0; itemp < b_ix; itemp++) {
                smax *= 1.0020841800044864E-292;
              }

              s = smax;
            } else {
              tau_data[e_i] = (smax - b_A_data[ii]) / smax;
              s = 1.0 / (b_A_data[ii] - smax);
              b_ix = ii + mmi;
              itemp = (((((b_ix - ii) - 1) / 2) << 1) + ii) + 2;
              jA = itemp - 2;
              for (c_k = pvt; c_k <= jA; c_k += 2) {
                tmp_0 = _mm_loadu_pd(&b_A_data[c_k - 1]);
                _mm_storeu_pd(&b_A_data[c_k - 1], _mm_mul_pd(tmp_0, _mm_set1_pd
                  (s)));
              }

              for (c_k = itemp; c_k <= b_ix; c_k++) {
                b_A_data[c_k - 1] *= s;
              }

              s = smax;
            }
          }
        }

        b_A_data[ii] = s;
      } else {
        tau_data[e_i] = 0.0;
      }

      if (e_i + 1 < 4) {
        smax = b_A_data[ii];
        b_A_data[ii] = 1.0;
        jA = (ii + minmana) + 1;
        if (tau_data[e_i] != 0.0) {
          boolean_T exitg2;
          itemp = mmi - 1;
          pvt = (ii + mmi) - 1;
          while ((itemp + 1 > 0) && (b_A_data[pvt] == 0.0)) {
            itemp--;
            pvt--;
          }

          pvt = 3 - e_i;
          exitg2 = false;
          while ((!exitg2) && (pvt > 0)) {
            int32_T exitg1;
            b_ix = (pvt - 1) * minmana + jA;
            c_k = b_ix;
            do {
              exitg1 = 0;
              if (c_k <= b_ix + itemp) {
                if (b_A_data[c_k - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  c_k++;
                }
              } else {
                pvt--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          pvt--;
        } else {
          itemp = -1;
          pvt = -1;
        }

        if (itemp + 1 > 0) {
          if (pvt + 1 != 0) {
            std::memset(&work[0], 0, static_cast<uint32_T>(pvt + 1) * sizeof
                        (real_T));
            b_ix = 0;
            c_k = minmana * pvt + jA;
            for (temp_tmp = jA; minmana < 0 ? temp_tmp >= c_k : temp_tmp <= c_k;
                 temp_tmp += minmana) {
              int32_T p;
              s = 0.0;
              p = temp_tmp + itemp;
              for (int32_T ia{temp_tmp}; ia <= p; ia++) {
                s += b_A_data[(ii + ia) - temp_tmp] * b_A_data[ia - 1];
              }

              work[b_ix] += s;
              b_ix++;
            }
          }

          if (!(-tau_data[e_i] == 0.0)) {
            for (b_ix = 0; b_ix <= pvt; b_ix++) {
              s = work[b_ix];
              if (s != 0.0) {
                s *= -tau_data[e_i];
                c_k = itemp + jA;
                for (temp_tmp = jA; temp_tmp <= c_k; temp_tmp++) {
                  b_A_data[temp_tmp - 1] += b_A_data[(ii + temp_tmp) - jA] * s;
                }
              }

              jA += minmana;
            }
          }
        }

        b_A_data[ii] = smax;
      }

      for (ii = e_i + 2; ii < 5; ii++) {
        itemp = (ii - 1) * minmana + e_i;
        smax = vn1[ii - 1];
        if (smax != 0.0) {
          real_T temp2;
          s = std::abs(b_A_data[itemp]) / smax;
          s = 1.0 - s * s;
          if (s < 0.0) {
            s = 0.0;
          }

          temp2 = smax / vn2[ii - 1];
          temp2 = temp2 * temp2 * s;
          if (temp2 <= 1.4901161193847656E-8) {
            if (e_i + 1 < rankA) {
              vn1[ii - 1] = GNSSPreProcessingSingleAn_xnrm2(mmi - 1, b_A_data,
                itemp + 2);
              vn2[ii - 1] = vn1[ii - 1];
            } else {
              vn1[ii - 1] = 0.0;
              vn2[ii - 1] = 0.0;
            }
          } else {
            vn1[ii - 1] = smax * std::sqrt(s);
          }
        }
      }
    }
  }

  rankA = 0;
  if (A_size[0] < 4) {
    minmana = A_size[0];
    maxmn = 4;
  } else {
    minmana = 4;
    maxmn = A_size[0];
  }

  if (minmana > 0) {
    while ((rankA < minmana) && (!(std::abs(b_A_data[b_A_size[0] * rankA + rankA])
             <= 2.2204460492503131E-15 * static_cast<real_T>(maxmn) * std::abs
             (b_A_data[0])))) {
      rankA++;
    }
  }

  if (*B_size - 1 >= 0) {
    std::memcpy(&b_B_data[0], &B_data[0], static_cast<uint32_T>(*B_size) *
                sizeof(real_T));
  }

  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  Y[3] = 0.0;
  minmana = A_size[0];
  if (A_size[0] <= 4) {
    maxmn = A_size[0];
  } else {
    maxmn = 4;
  }

  for (int32_T e_i{0}; e_i < maxmn; e_i++) {
    smax = tau_data[e_i];
    if (smax != 0.0) {
      s = b_B_data[e_i];
      for (mmi = e_i + 2; mmi <= minmana; mmi++) {
        s += b_A_data[(b_A_size[0] * e_i + mmi) - 1] * b_B_data[mmi - 1];
      }

      s *= smax;
      if (s != 0.0) {
        b_B_data[e_i] -= s;
        itemp = (((((minmana - e_i) - 1) / 2) << 1) + e_i) + 2;
        jA = itemp - 2;
        for (mmi = e_i + 2; mmi <= jA; mmi += 2) {
          __m128d tmp;
          tmp_0 = _mm_loadu_pd(&b_A_data[(b_A_size[0] * e_i + mmi) - 1]);
          tmp = _mm_loadu_pd(&b_B_data[mmi - 1]);
          _mm_storeu_pd(&b_B_data[mmi - 1], _mm_sub_pd(tmp, _mm_mul_pd(tmp_0,
            _mm_set1_pd(s))));
        }

        for (mmi = itemp; mmi <= minmana; mmi++) {
          b_B_data[mmi - 1] -= b_A_data[(b_A_size[0] * e_i + mmi) - 1] * s;
        }
      }
    }
  }

  for (minmana = 0; minmana < rankA; minmana++) {
    Y[jpvt[minmana] - 1] = b_B_data[minmana];
  }

  for (minmana = rankA; minmana >= 1; minmana--) {
    maxmn = jpvt[minmana - 1] - 1;
    ii = (minmana - 1) * b_A_size[0];
    Y[maxmn] /= b_A_data[(minmana + ii) - 1];
    for (int32_T e_i{0}; e_i <= minmana - 2; e_i++) {
      mmi = jpvt[e_i] - 1;
      Y[mmi] -= b_A_data[e_i + ii] * Y[maxmn];
    }
  }
}

// Function for MATLAB Function: '<Root>/Calculate User Position with LMS'
void GNSS_preprocessingModelClass::GNSSPreProcessingSin_mldivide_a(const real_T
  A_data[], const int32_T A_size[2], real_T B_data[], int32_T *B_size)
{
  real_T b_A_data[16];
  real_T tmp[4];
  int8_T ipiv[4];
  if (A_size[0] == 0) {
    *B_size = 4;
    B_data[0] = 0.0;
    B_data[1] = 0.0;
    B_data[2] = 0.0;
    B_data[3] = 0.0;
  } else if (*B_size == 0) {
    *B_size = 4;
    B_data[0] = 0.0;
    B_data[1] = 0.0;
    B_data[2] = 0.0;
    B_data[3] = 0.0;
  } else if (A_size[0] == 4) {
    int32_T jj;
    int32_T kAcol;
    std::memcpy(&b_A_data[0], &A_data[0], sizeof(real_T) << 4U);
    ipiv[0] = 1;
    ipiv[1] = 2;
    ipiv[2] = 3;
    ipiv[3] = 4;
    for (int32_T j{0}; j < 3; j++) {
      real_T smax;
      int32_T jA;
      int32_T n;
      int32_T vectorUB;
      int8_T ipiv_0;
      ipiv_0 = ipiv[j];
      jj = j * 5;
      n = 4 - j;
      jA = 0;
      smax = std::abs(b_A_data[jj]);
      for (kAcol = 2; kAcol <= n; kAcol++) {
        real_T s;
        s = std::abs(b_A_data[(jj + kAcol) - 1]);
        if (s > smax) {
          jA = kAcol - 1;
          smax = s;
        }
      }

      if (b_A_data[jj + jA] != 0.0) {
        if (jA != 0) {
          kAcol = j + jA;
          ipiv_0 = static_cast<int8_T>(kAcol + 1);
          smax = b_A_data[j];
          b_A_data[j] = b_A_data[kAcol];
          b_A_data[kAcol] = smax;
          smax = b_A_data[j + 4];
          b_A_data[j + 4] = b_A_data[kAcol + 4];
          b_A_data[kAcol + 4] = smax;
          smax = b_A_data[j + 8];
          b_A_data[j + 8] = b_A_data[kAcol + 8];
          b_A_data[kAcol + 8] = smax;
          smax = b_A_data[j + 12];
          b_A_data[j + 12] = b_A_data[kAcol + 12];
          b_A_data[kAcol + 12] = smax;
        }

        n = (jj - j) + 4;
        jA = (((((n - jj) - 1) / 2) << 1) + jj) + 2;
        vectorUB = jA - 2;
        for (kAcol = jj + 2; kAcol <= vectorUB; kAcol += 2) {
          __m128d tmp_0;
          tmp_0 = _mm_loadu_pd(&b_A_data[kAcol - 1]);
          _mm_storeu_pd(&b_A_data[kAcol - 1], _mm_div_pd(tmp_0, _mm_set1_pd
            (b_A_data[jj])));
        }

        for (kAcol = jA; kAcol <= n; kAcol++) {
          b_A_data[kAcol - 1] /= b_A_data[jj];
        }
      }

      jA = jj + 6;
      vectorUB = 2 - j;
      for (kAcol = 0; kAcol <= vectorUB; kAcol++) {
        smax = b_A_data[((kAcol << 2) + jj) + 4];
        if (smax != 0.0) {
          int32_T e;
          e = (jA - j) + 2;
          for (n = jA; n <= e; n++) {
            b_A_data[n - 1] += b_A_data[((jj + n) - jA) + 1] * -smax;
          }
        }

        jA += 4;
      }

      if (j + 1 != ipiv_0) {
        smax = B_data[j];
        B_data[j] = B_data[ipiv_0 - 1];
        B_data[ipiv_0 - 1] = smax;
      }

      ipiv[j] = ipiv_0;
    }

    for (int32_T j{0}; j < 4; j++) {
      kAcol = j << 2;
      if (B_data[j] != 0.0) {
        for (jj = j + 2; jj < 5; jj++) {
          B_data[jj - 1] -= b_A_data[(jj + kAcol) - 1] * B_data[j];
        }
      }
    }

    for (int32_T j{3}; j >= 0; j--) {
      kAcol = j << 2;
      if (B_data[j] != 0.0) {
        B_data[j] /= b_A_data[j + kAcol];
        for (jj = 0; jj < j; jj++) {
          B_data[jj] -= b_A_data[jj + kAcol] * B_data[j];
        }
      }
    }
  } else {
    GNSSPreProcessingSingle_qrsolve(A_data, A_size, B_data, B_size, tmp);
    *B_size = 4;
    B_data[0] = tmp[0];
    B_data[1] = tmp[1];
    B_data[2] = tmp[2];
    B_data[3] = tmp[3];
  }
}

void GNSS_preprocessingModelClass::GNSSPr_binary_expand_op_fr3puso(real_T in1[3],
  real_T in2, real_T in3, const int8_T in4[3], real_T in5, real_T in6, const
  int8_T in7[3], const real_T in8[4], const real_T in9_data[], const int32_T
  in9_size[2], int32_T in10, const int32_T in11_size[2])
{
  real_T in2_0[9];
  real_T in2_1[9];
  real_T in5_0[9];
  real_T in8_0[3];
  int32_T stride_0_0;
  in2_0[0] = in2;
  in2_0[3] = -in3;
  in2_0[6] = 0.0;
  in2_0[1] = in3;
  in2_0[4] = in2;
  in2_0[7] = 0.0;
  in5_0[0] = in5;
  in5_0[3] = 0.0;
  in5_0[6] = in6;
  in2_0[2] = in4[0];
  in5_0[1] = in7[0];
  in2_0[5] = in4[1];
  in5_0[4] = in7[1];
  in2_0[8] = in4[2];
  in5_0[7] = in7[2];
  in5_0[2] = -in6;
  in5_0[5] = 0.0;
  in5_0[8] = in5;
  stride_0_0 = (in11_size[1] != 1);
  for (int32_T i_0{0}; i_0 < 3; i_0++) {
    for (int32_T i{0}; i < 3; i++) {
      int32_T in2_tmp;
      in2_tmp = 3 * i_0 + i;
      in2_1[in2_tmp] = 0.0;
      in2_1[in2_tmp] += in5_0[3 * i] * in2_0[i_0];
      in2_1[in2_tmp] += in5_0[3 * i + 1] * in2_0[i_0 + 3];
      in2_1[in2_tmp] += in5_0[3 * i + 2] * in2_0[i_0 + 6];
    }

    in8_0[i_0] = in8[i_0] - in9_data[i_0 * stride_0_0 * in9_size[0] + in10];
  }

  for (int32_T i_0{0}; i_0 <= 0; i_0 += 2) {
    __m128d tmp;
    __m128d tmp_0;
    _mm_storeu_pd(&in1[i_0], _mm_set1_pd(0.0));
    tmp = _mm_loadu_pd(&in2_1[i_0]);
    tmp_0 = _mm_loadu_pd(&in1[i_0]);
    _mm_storeu_pd(&in1[i_0], _mm_add_pd(_mm_mul_pd(tmp, _mm_set1_pd(in8_0[0])),
      tmp_0));
    tmp = _mm_loadu_pd(&in2_1[i_0 + 3]);
    tmp_0 = _mm_loadu_pd(&in1[i_0]);
    _mm_storeu_pd(&in1[i_0], _mm_add_pd(_mm_mul_pd(tmp, _mm_set1_pd(in8_0[1])),
      tmp_0));
    tmp = _mm_loadu_pd(&in2_1[i_0 + 6]);
    tmp_0 = _mm_loadu_pd(&in1[i_0]);
    _mm_storeu_pd(&in1[i_0], _mm_add_pd(_mm_mul_pd(tmp, _mm_set1_pd(in8_0[2])),
      tmp_0));
  }

  for (int32_T i_0{2}; i_0 < 3; i_0++) {
    in1[i_0] = 0.0;
    in1[i_0] += in2_1[i_0] * in8_0[0];
    in1[i_0] += in2_1[i_0 + 3] * in8_0[1];
    in1[i_0] += in2_1[i_0 + 6] * in8_0[2];
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAnte_inv(const real_T
  x_data[], const int32_T x_size[2], real_T y_data[], int32_T y_size[2])
{
  int8_T ipiv_data[40];
  int8_T p_data[40];
  if ((x_size[0] == 0) || (x_size[1] == 0)) {
    int32_T b_yk;
    y_size[0] = x_size[0];
    y_size[1] = x_size[1];
    b_yk = x_size[0] * x_size[1];
    if (b_yk - 1 >= 0) {
      std::memcpy(&y_data[0], &x_data[0], static_cast<uint32_T>(b_yk) * sizeof
                  (real_T));
    }
  } else {
    int32_T A_size_idx_0;
    int32_T b_yk;
    int32_T jA;
    int32_T jj;
    int32_T jy;
    int32_T kAcol;
    int32_T ldap1;
    int32_T mmj;
    int32_T n;
    int32_T pipk;
    int32_T smax_tmp;
    n = x_size[0];
    y_size[0] = x_size[0];
    y_size[1] = x_size[1];
    b_yk = x_size[0] * x_size[1];
    std::memset(&y_data[0], 0, static_cast<uint32_T>(b_yk) * sizeof(real_T));
    A_size_idx_0 = x_size[0];
    std::memcpy(&GNSSPreProcessingSingleAntenn_B.A_data[0], &x_data[0],
                static_cast<uint32_T>(b_yk) * sizeof(real_T));
    ldap1 = x_size[0];
    mmj = x_size[0];
    ipiv_data[0] = 1;
    b_yk = 1;
    for (pipk = 2; pipk <= ldap1; pipk++) {
      b_yk++;
      ipiv_data[pipk - 1] = static_cast<int8_T>(b_yk);
    }

    ldap1 = x_size[0];
    if (x_size[0] - 1 <= x_size[0]) {
      b_yk = x_size[0] - 1;
    } else {
      b_yk = x_size[0];
    }

    for (pipk = 0; pipk < b_yk; pipk++) {
      real_T smax;
      int32_T mmj_tmp;
      mmj_tmp = n - pipk;
      jj = (ldap1 + 1) * pipk;
      if (mmj_tmp < 1) {
        kAcol = -1;
      } else {
        kAcol = 0;
        if (mmj_tmp > 1) {
          smax = std::abs(GNSSPreProcessingSingleAntenn_B.A_data[jj]);
          for (jy = 2; jy <= mmj_tmp; jy++) {
            real_T s;
            s = std::abs(GNSSPreProcessingSingleAntenn_B.A_data[(jj + jy) - 1]);
            if (s > smax) {
              kAcol = jy - 1;
              smax = s;
            }
          }
        }
      }

      if (GNSSPreProcessingSingleAntenn_B.A_data[jj + kAcol] != 0.0) {
        if (kAcol != 0) {
          kAcol += pipk;
          ipiv_data[pipk] = static_cast<int8_T>(kAcol + 1);
          for (jy = 0; jy < n; jy++) {
            smax_tmp = jy * n;
            jA = smax_tmp + pipk;
            smax = GNSSPreProcessingSingleAntenn_B.A_data[jA];
            smax_tmp += kAcol;
            GNSSPreProcessingSingleAntenn_B.A_data[jA] =
              GNSSPreProcessingSingleAntenn_B.A_data[smax_tmp];
            GNSSPreProcessingSingleAntenn_B.A_data[smax_tmp] = smax;
          }
        }

        kAcol = jj + mmj_tmp;
        jy = (((((kAcol - jj) - 1) / 2) << 1) + jj) + 2;
        jA = jy - 2;
        for (smax_tmp = jj + 2; smax_tmp <= jA; smax_tmp += 2) {
          __m128d tmp;
          tmp = _mm_loadu_pd(&GNSSPreProcessingSingleAntenn_B.A_data[smax_tmp -
                             1]);
          _mm_storeu_pd(&GNSSPreProcessingSingleAntenn_B.A_data[smax_tmp - 1],
                        _mm_div_pd(tmp, _mm_set1_pd
            (GNSSPreProcessingSingleAntenn_B.A_data[jj])));
        }

        for (smax_tmp = jy; smax_tmp <= kAcol; smax_tmp++) {
          GNSSPreProcessingSingleAntenn_B.A_data[smax_tmp - 1] /=
            GNSSPreProcessingSingleAntenn_B.A_data[jj];
        }
      }

      kAcol = mmj_tmp - 1;
      jy = jj + n;
      jA = (jj + ldap1) + 2;
      for (smax_tmp = 0; smax_tmp < kAcol; smax_tmp++) {
        smax = GNSSPreProcessingSingleAntenn_B.A_data[smax_tmp * n + jy];
        if (smax != 0.0) {
          int32_T m;
          m = (mmj_tmp + jA) - 1;
          for (int32_T ijA{jA}; ijA < m; ijA++) {
            GNSSPreProcessingSingleAntenn_B.A_data[ijA - 1] +=
              GNSSPreProcessingSingleAntenn_B.A_data[((jj + ijA) - jA) + 1] *
              -smax;
          }
        }

        jA += n;
      }
    }

    ldap1 = x_size[0];
    p_data[0] = 1;
    b_yk = 1;
    for (pipk = 2; pipk <= ldap1; pipk++) {
      b_yk++;
      p_data[pipk - 1] = static_cast<int8_T>(b_yk);
    }

    for (b_yk = 0; b_yk < mmj; b_yk++) {
      int8_T ipiv;
      ipiv = ipiv_data[b_yk];
      if (ipiv > b_yk + 1) {
        pipk = p_data[ipiv - 1];
        p_data[ipiv - 1] = p_data[b_yk];
        p_data[b_yk] = static_cast<int8_T>(pipk);
      }
    }

    ldap1 = x_size[0];
    for (b_yk = 0; b_yk < ldap1; b_yk++) {
      pipk = p_data[b_yk] - 1;
      jy = (p_data[b_yk] - 1) * y_size[0];
      y_data[b_yk + jy] = 1.0;
      for (mmj = b_yk + 1; mmj <= n; mmj++) {
        kAcol = (y_size[0] * pipk + mmj) - 1;
        if (y_data[kAcol] != 0.0) {
          for (jj = mmj + 1; jj <= n; jj++) {
            smax_tmp = (jj + jy) - 1;
            y_data[smax_tmp] -= GNSSPreProcessingSingleAntenn_B.A_data[((mmj - 1)
              * A_size_idx_0 + jj) - 1] * y_data[kAcol];
          }
        }
      }
    }

    b_yk = x_size[0];
    for (pipk = 0; pipk < b_yk; pipk++) {
      mmj = n * pipk - 1;
      for (jj = n; jj >= 1; jj--) {
        kAcol = (jj - 1) * n;
        ldap1 = jj + mmj;
        if (y_data[ldap1] != 0.0) {
          y_data[ldap1] /= GNSSPreProcessingSingleAntenn_B.A_data[(jj + kAcol) -
            1];
          for (jy = 0; jy <= jj - 2; jy++) {
            jA = (jy + mmj) + 1;
            y_data[jA] -= GNSSPreProcessingSingleAntenn_B.A_data[jy + kAcol] *
              y_data[ldap1];
          }
        }
      }
    }
  }
}

void GNSS_preprocessingModelClass::GNSSP_binary_expand_op_fr3pusoh(real_T in1[3],
  const real_T in2[4], const real_T in3_data[], const int32_T in3_size[2],
  int32_T in4, const int32_T in5_size[2])
{
  int32_T stride_0_1;
  stride_0_1 = (in5_size[1] != 1);
  in1[0] = in2[0] - in3_data[in4];
  in1[1] = in2[1] - in3_data[in3_size[0] * stride_0_1 + in4];
  in1[2] = in2[2] - in3_data[(stride_0_1 << 1) * in3_size[0] + in4];
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSin_mldivide_d(const real_T
  A[16], const real_T B_data[], const int32_T B_size[2], real_T Y_data[],
  int32_T Y_size[2])
{
  real_T b_A[16];
  int8_T ipiv[4];
  if (B_size[1] == 0) {
    Y_size[0] = 4;
    Y_size[1] = 0;
  } else {
    real_T smax;
    int32_T a;
    int32_T b_i;
    int32_T b_j;
    int32_T jA;
    int32_T jBcol;
    int32_T jj;
    int32_T kAcol;
    std::memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
    ipiv[0] = 1;
    ipiv[1] = 2;
    ipiv[2] = 3;
    ipiv[3] = 4;
    for (b_j = 0; b_j < 3; b_j++) {
      jj = b_j * 5;
      jA = 4 - b_j;
      a = 0;
      smax = std::abs(b_A[jj]);
      for (jBcol = 2; jBcol <= jA; jBcol++) {
        real_T s;
        s = std::abs(b_A[(jj + jBcol) - 1]);
        if (s > smax) {
          a = jBcol - 1;
          smax = s;
        }
      }

      if (b_A[jj + a] != 0.0) {
        if (a != 0) {
          jA = b_j + a;
          ipiv[b_j] = static_cast<int8_T>(jA + 1);
          smax = b_A[b_j];
          b_A[b_j] = b_A[jA];
          b_A[jA] = smax;
          smax = b_A[b_j + 4];
          b_A[b_j + 4] = b_A[jA + 4];
          b_A[jA + 4] = smax;
          smax = b_A[b_j + 8];
          b_A[b_j + 8] = b_A[jA + 8];
          b_A[jA + 8] = smax;
          smax = b_A[b_j + 12];
          b_A[b_j + 12] = b_A[jA + 12];
          b_A[jA + 12] = smax;
        }

        jA = (jj - b_j) + 4;
        a = (((((jA - jj) - 1) / 2) << 1) + jj) + 2;
        jBcol = a - 2;
        for (b_i = jj + 2; b_i <= jBcol; b_i += 2) {
          __m128d tmp;
          tmp = _mm_loadu_pd(&b_A[b_i - 1]);
          _mm_storeu_pd(&b_A[b_i - 1], _mm_div_pd(tmp, _mm_set1_pd(b_A[jj])));
        }

        for (b_i = a; b_i <= jA; b_i++) {
          b_A[b_i - 1] /= b_A[jj];
        }
      }

      jA = jj + 6;
      a = 2 - b_j;
      for (jBcol = 0; jBcol <= a; jBcol++) {
        smax = b_A[((jBcol << 2) + jj) + 4];
        if (smax != 0.0) {
          b_i = (jA - b_j) + 2;
          for (kAcol = jA; kAcol <= b_i; kAcol++) {
            b_A[kAcol - 1] += b_A[((jj + kAcol) - jA) + 1] * -smax;
          }
        }

        jA += 4;
      }
    }

    Y_size[0] = 4;
    Y_size[1] = B_size[1];
    jA = B_size[1] << 2;
    std::memcpy(&Y_data[0], &B_data[0], static_cast<uint32_T>(jA) * sizeof
                (real_T));
    for (b_j = 0; b_j < 3; b_j++) {
      int8_T ipiv_0;
      ipiv_0 = ipiv[b_j];
      if (b_j + 1 != ipiv_0) {
        jj = B_size[1];
        for (jA = 0; jA < jj; jA++) {
          smax = Y_data[(jA << 2) + b_j];
          Y_data[b_j + (jA << 2)] = Y_data[((jA << 2) + ipiv_0) - 1];
          Y_data[(ipiv_0 + (jA << 2)) - 1] = smax;
        }
      }
    }

    jA = B_size[1];
    for (a = 0; a < jA; a++) {
      jBcol = a << 2;
      for (b_i = 0; b_i < 4; b_i++) {
        kAcol = b_i << 2;
        b_j = b_i + jBcol;
        if (Y_data[b_j] != 0.0) {
          for (int32_T c_i{b_i + 2}; c_i < 5; c_i++) {
            jj = (c_i + jBcol) - 1;
            Y_data[jj] -= b_A[(c_i + kAcol) - 1] * Y_data[b_j];
          }
        }
      }
    }

    jA = B_size[1];
    for (a = 0; a < jA; a++) {
      jBcol = a << 2;
      for (b_i = 3; b_i >= 0; b_i--) {
        kAcol = b_i << 2;
        b_j = b_i + jBcol;
        if (Y_data[b_j] != 0.0) {
          Y_data[b_j] /= b_A[b_i + kAcol];
          for (int32_T c_i{0}; c_i < b_i; c_i++) {
            jj = c_i + jBcol;
            Y_data[jj] -= b_A[c_i + kAcol] * Y_data[b_j];
          }
        }
      }
    }
  }
}

void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_minus_f(real_T
  in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
  in2_size[2])
{
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T in1_size_idx_0;
  int32_T in1_size_idx_1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in1_size_idx_0 = in2_size[0] == 1 ? in1_size[0] : in2_size[0];
  in1_size_idx_1 = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
  stride_0_0 = (in1_size[0] != 1);
  stride_0_1 = (in1_size[1] != 1);
  stride_1_0 = (in2_size[0] != 1);
  stride_1_1 = (in2_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  loop_ub = in2_size[1] == 1 ? in1_size[1] : in2_size[1];
  for (int32_T i_0{0}; i_0 < loop_ub; i_0++) {
    int32_T loop_ub_0;
    loop_ub_0 = in2_size[0] == 1 ? in1_size[0] : in2_size[0];
    for (int32_T i{0}; i < loop_ub_0; i++) {
      GNSSPreProcessingSingleAntenn_B.in1_data[i + in1_size_idx_0 * i_0] =
        in1_data[i * stride_0_0 + in1_size[0] * aux_0_1] - in2_data[i *
        stride_1_0 + in2_size[0] * aux_1_1];
    }

    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }

  in1_size[0] = in1_size_idx_0;
  in1_size[1] = in1_size_idx_1;
  for (int32_T i_0{0}; i_0 < in1_size_idx_1; i_0++) {
    for (int32_T i{0}; i < in1_size_idx_0; i++) {
      in1_data[i + in1_size[0] * i_0] =
        GNSSPreProcessingSingleAntenn_B.in1_data[in1_size_idx_0 * i_0 + i];
    }
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_mtimes(const real_T
  A_data[], const int32_T A_size[2], const real_T B_data[], real_T C_data[],
  int32_T *C_size)
{
  int32_T b;
  *C_size = A_size[0];
  b = A_size[0];
  if (b - 1 >= 0) {
    std::memset(&C_data[0], 0, static_cast<uint32_T>(b) * sizeof(real_T));
  }

  b = A_size[1];
  for (int32_T i{0}; i < b; i++) {
    int32_T aoffset;
    int32_T d;
    int32_T scalarLB;
    int32_T vectorUB;
    aoffset = i * A_size[0];
    d = A_size[0];
    scalarLB = (A_size[0] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T b_i{0}; b_i <= vectorUB; b_i += 2) {
      __m128d tmp;
      tmp = _mm_loadu_pd(&C_data[b_i]);
      _mm_storeu_pd(&C_data[b_i], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&A_data[aoffset + b_i]), _mm_set1_pd(B_data[i])), tmp));
    }

    for (int32_T b_i{scalarLB}; b_i < d; b_i++) {
      C_data[b_i] += A_data[aoffset + b_i] * B_data[i];
    }
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
real_T GNSS_preprocessingModelClass::GNSSPreProcessingSingle_maximum(const
  real_T x_data[], const int32_T *x_size)
{
  real_T ex;
  int32_T last;
  last = *x_size;
  if (static_cast<uint8_T>(*x_size - 1) + 1 <= 2) {
    if (static_cast<uint8_T>(*x_size - 1) + 1 == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[*x_size - 1];
      if (x_data[0] < ex) {
      } else if (std::isnan(x_data[0])) {
        if (!std::isnan(ex)) {
        } else {
          ex = x_data[0];
        }
      } else {
        ex = x_data[0];
      }
    }
  } else {
    int32_T idx;
    int32_T k;
    if (!std::isnan(x_data[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= *x_size)) {
        if (!std::isnan(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      for (k = idx + 1; k <= last; k++) {
        real_T tmp;
        tmp = x_data[k - 1];
        if (ex < tmp) {
          ex = tmp;
        }
      }
    }
  }

  return ex;
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProces_RAIM_detect_Fault(const real_T
  e_GNSS_Measurement_satellite_po[], const int32_T
  e_GNSS_Measurement_satellite__0[2], const real_T
  e_GNSS_Measurement_pseudorange_[], const int32_T
  *e_GNSS_Measurement_pseudorang_0, const real_T
  e_GNSS_Measurement_variance_pse[], const real_T user_position_llh[3], real_T
  clockerror, const real_T b_table_chi_square[80], real_T m, real_T
  *test_statistic, real_T *threshold, real_T *HPL, real_T H_data[], int32_T
  H_size[2], real_T W_data[], int32_T W_size[2], real_T y_data[], int32_T
  *y_size)
{
  static const int8_T ab[3]{ 0, 0, 1 };

  static const int8_T bb[3]{ 0, 1, 0 };

  __m128d tmp_0;
  __m128d tmp_1;
  __m128d tmp_2;
  real_T A_data[160];
  real_T b_y_data[160];
  real_T satellitePosition_ecef_data[120];
  real_T d_y_data[40];
  real_T pseudorange_pre_data[40];
  real_T c_y[16];
  real_T cosinus_lambda[9];
  real_T cosinus_lambda_0[9];
  real_T cosinus_phi_0[9];
  real_T user_state_pre[4];
  real_T position_llh[3];
  real_T satellitePosition_ned[3];
  real_T user_state_pre_0[3];
  real_T N;
  real_T cosinus_phi;
  real_T oldh;
  real_T sinus_lambda;
  int32_T A_size[2];
  int32_T S_size[2];
  int32_T f_size[2];
  int32_T matrix_pseudorange_variance_siz[2];
  int32_T satellitePosition_ecef_size[2];
  int32_T aoffset;
  int32_T b_aoffset;
  int32_T boffset;
  int32_T cb_size_idx_0;
  int32_T coffset;
  int32_T h_size;
  int32_T k;
  int32_T loop_ub;
  int8_T h_data[40];
  boolean_T cb_data[40];
  sinus_lambda = std::cos(user_position_llh[0]);
  N = 6.3995936257584924E+6 / std::sqrt(sinus_lambda * sinus_lambda *
    0.0067394967422761756 + 1.0);
  user_state_pre[0] = (N + user_position_llh[2]) * sinus_lambda * std::cos
    (user_position_llh[1]);
  user_state_pre[1] = (N + user_position_llh[2]) * std::cos(user_position_llh[0])
    * std::sin(user_position_llh[1]);
  user_state_pre[2] = (0.99330562000985889 * N + user_position_llh[2]) * std::
    sin(user_position_llh[0]);
  user_state_pre[3] = clockerror;
  cb_size_idx_0 = *e_GNSS_Measurement_pseudorang_0;
  loop_ub = *e_GNSS_Measurement_pseudorang_0;
  for (k = 0; k < loop_ub; k++) {
    cb_data[k] = std::isnan(e_GNSS_Measurement_pseudorange_[k]);
  }

  for (k = 0; k < cb_size_idx_0; k++) {
    cb_data[k] = !cb_data[k];
  }

  k = *e_GNSS_Measurement_pseudorang_0 - 1;
  cb_size_idx_0 = 0;
  for (coffset = 0; coffset <= k; coffset++) {
    if (cb_data[coffset]) {
      cb_size_idx_0++;
    }
  }

  h_size = cb_size_idx_0;
  cb_size_idx_0 = 0;
  for (coffset = 0; coffset <= k; coffset++) {
    if (cb_data[coffset]) {
      h_data[cb_size_idx_0] = static_cast<int8_T>(coffset + 1);
      cb_size_idx_0++;
    }
  }

  if (h_size < 1) {
    loop_ub = -1;
  } else {
    loop_ub = h_size - 1;
  }

  satellitePosition_ecef_size[0] = loop_ub + 1;
  satellitePosition_ecef_size[1] = e_GNSS_Measurement_satellite__0[1];
  cb_size_idx_0 = e_GNSS_Measurement_satellite__0[1];
  for (k = 0; k < cb_size_idx_0; k++) {
    for (boffset = 0; boffset <= loop_ub; boffset++) {
      satellitePosition_ecef_data[boffset + (loop_ub + 1) * k] =
        e_GNSS_Measurement_satellite_po[e_GNSS_Measurement_satellite__0[0] * k +
        boffset];
    }
  }

  sinus_lambda = std::sqrt(user_state_pre[0] * user_state_pre[0] +
    user_state_pre[1] * user_state_pre[1]);
  cosinus_phi = std::atan(user_state_pre[2] / (sinus_lambda *
    -0.99664718933525243 * 0.0033528106647474805));
  N = 0.1;
  oldh = 0.0;
  k = 0;
  while ((std::abs(N - oldh) > 1.0E-12) && (k < 3000)) {
    real_T b_N;
    oldh = N;
    cosinus_phi = std::cos(cosinus_phi);
    b_N = 6.3995936257584924E+6 / std::sqrt(cosinus_phi * cosinus_phi *
      0.0067394967422764341 + 1.0);
    cosinus_phi = std::atan(user_state_pre[2] / ((1.0 - 0.0066943799901413165 *
      b_N / (b_N + N)) * sinus_lambda));
    N = sinus_lambda / std::cos(cosinus_phi) - b_N;
    k++;
  }

  position_llh[0] = cosinus_phi * 57.295779513082323 * 0.017453292519943295;
  position_llh[1] = rt_atan2d_snf(user_state_pre[1], user_state_pre[0]) *
    57.295779513082323 * 0.017453292519943295;
  position_llh[2] = N;
  H_size[0] = h_size;
  H_size[1] = 4;
  loop_ub = h_size << 2;
  if (loop_ub - 1 >= 0) {
    std::memset(&H_data[0], 0, static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  for (coffset = 0; coffset < h_size; coffset++) {
    sinus_lambda = std::sin(position_llh[1]);
    N = std::cos(position_llh[1]);
    oldh = std::sin((1.5707963267948966 - position_llh[0]) - 3.1415926535897931);
    cosinus_phi = std::cos((1.5707963267948966 - position_llh[0]) -
      3.1415926535897931);
    if (e_GNSS_Measurement_satellite__0[1] == 3) {
      cosinus_lambda[0] = N;
      cosinus_lambda[3] = -sinus_lambda;
      cosinus_lambda[6] = 0.0;
      cosinus_lambda[1] = sinus_lambda;
      cosinus_lambda[4] = N;
      cosinus_lambda[7] = 0.0;
      cosinus_phi_0[0] = cosinus_phi;
      cosinus_phi_0[3] = 0.0;
      cosinus_phi_0[6] = oldh;
      cosinus_lambda[2] = 0.0;
      cosinus_phi_0[1] = 0.0;
      cosinus_lambda[5] = 0.0;
      cosinus_phi_0[4] = 1.0;
      cosinus_lambda[8] = 1.0;
      cosinus_phi_0[7] = 0.0;
      cosinus_phi_0[2] = -oldh;
      cosinus_phi_0[5] = 0.0;
      cosinus_phi_0[8] = cosinus_phi;
      for (k = 0; k < 3; k++) {
        for (boffset = 0; boffset < 3; boffset++) {
          loop_ub = 3 * boffset + k;
          cosinus_lambda_0[loop_ub] = 0.0;
          cosinus_lambda_0[loop_ub] += cosinus_phi_0[3 * k] *
            cosinus_lambda[boffset];
          cosinus_lambda_0[loop_ub] += cosinus_phi_0[3 * k + 1] *
            cosinus_lambda[boffset + 3];
          cosinus_lambda_0[loop_ub] += cosinus_phi_0[3 * k + 2] *
            cosinus_lambda[boffset + 6];
        }

        user_state_pre_0[k] = user_state_pre[k] -
          satellitePosition_ecef_data[satellitePosition_ecef_size[0] * k +
          coffset];
      }

      for (k = 0; k <= 0; k += 2) {
        tmp_0 = _mm_loadu_pd(&cosinus_lambda_0[k]);
        tmp_1 = _mm_loadu_pd(&cosinus_lambda_0[k + 3]);
        tmp_2 = _mm_loadu_pd(&cosinus_lambda_0[k + 6]);
        _mm_storeu_pd(&satellitePosition_ned[k], _mm_add_pd(_mm_mul_pd(tmp_2,
          _mm_set1_pd(user_state_pre_0[2])), _mm_add_pd(_mm_mul_pd(tmp_1,
          _mm_set1_pd(user_state_pre_0[1])), _mm_add_pd(_mm_mul_pd(tmp_0,
          _mm_set1_pd(user_state_pre_0[0])), _mm_set1_pd(0.0)))));
      }

      for (k = 2; k < 3; k++) {
        satellitePosition_ned[k] = (cosinus_lambda_0[k + 3] * user_state_pre_0[1]
          + cosinus_lambda_0[k] * user_state_pre_0[0]) + cosinus_lambda_0[k + 6]
          * user_state_pre_0[2];
      }
    } else {
      GNSSPr_binary_expand_op_fr3puso(satellitePosition_ned, N, sinus_lambda, ab,
        cosinus_phi, oldh, bb, user_state_pre, satellitePosition_ecef_data,
        satellitePosition_ecef_size, coffset, e_GNSS_Measurement_satellite__0);
    }

    sinus_lambda = 3.3121686421112381E-170;
    N = std::abs(satellitePosition_ned[0]);
    if (N > 3.3121686421112381E-170) {
      cosinus_phi = 1.0;
      sinus_lambda = N;
    } else {
      oldh = N / 3.3121686421112381E-170;
      cosinus_phi = oldh * oldh;
    }

    N = std::abs(satellitePosition_ned[1]);
    if (N > sinus_lambda) {
      oldh = sinus_lambda / N;
      cosinus_phi = cosinus_phi * oldh * oldh + 1.0;
      sinus_lambda = N;
    } else {
      oldh = N / sinus_lambda;
      cosinus_phi += oldh * oldh;
    }

    N = std::abs(satellitePosition_ned[2]);
    if (N > sinus_lambda) {
      oldh = sinus_lambda / N;
      cosinus_phi = cosinus_phi * oldh * oldh + 1.0;
      sinus_lambda = N;
    } else {
      oldh = N / sinus_lambda;
      cosinus_phi += oldh * oldh;
    }

    cosinus_phi = sinus_lambda * std::sqrt(cosinus_phi);
    H_data[coffset] = satellitePosition_ned[0] / cosinus_phi;
    H_data[coffset + H_size[0]] = satellitePosition_ned[1] / cosinus_phi;
    H_data[coffset + (H_size[0] << 1)] = satellitePosition_ned[2] / cosinus_phi;
    H_data[coffset + H_size[0] * 3] = 1.0;
  }

  if (h_size < 1) {
    cb_size_idx_0 = 0;
  } else {
    cb_size_idx_0 = h_size;
  }

  matrix_pseudorange_variance_siz[0] = static_cast<int8_T>(cb_size_idx_0);
  matrix_pseudorange_variance_siz[1] = static_cast<int8_T>(cb_size_idx_0);
  loop_ub = static_cast<int8_T>(cb_size_idx_0) * static_cast<int8_T>
    (cb_size_idx_0);
  if (loop_ub - 1 >= 0) {
    std::memset
      (&GNSSPreProcessingSingleAntenn_B.matrix_pseudorange_variance_dat[0], 0,
       static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  for (k = 0; k < cb_size_idx_0; k++) {
    GNSSPreProcessingSingleAntenn_B.matrix_pseudorange_variance_dat[k +
      static_cast<int8_T>(cb_size_idx_0) * k] =
      e_GNSS_Measurement_variance_pse[k];
  }

  GNSSPreProcessingSingleAnte_inv
    (GNSSPreProcessingSingleAntenn_B.matrix_pseudorange_variance_dat,
     matrix_pseudorange_variance_siz, W_data, W_size);
  if (h_size - 1 >= 0) {
    std::memset(&pseudorange_pre_data[0], 0, static_cast<uint32_T>(h_size) *
                sizeof(real_T));
  }

  for (cb_size_idx_0 = 0; cb_size_idx_0 < h_size; cb_size_idx_0++) {
    if (e_GNSS_Measurement_satellite__0[1] == 3) {
      position_llh[0] = user_state_pre[0] -
        satellitePosition_ecef_data[cb_size_idx_0];
      position_llh[1] = user_state_pre[1] -
        satellitePosition_ecef_data[cb_size_idx_0 + satellitePosition_ecef_size
        [0]];
      position_llh[2] = user_state_pre[2] - satellitePosition_ecef_data
        [(satellitePosition_ecef_size[0] << 1) + cb_size_idx_0];
    } else {
      GNSSP_binary_expand_op_fr3pusoh(position_llh, user_state_pre,
        satellitePosition_ecef_data, satellitePosition_ecef_size, cb_size_idx_0,
        e_GNSS_Measurement_satellite__0);
    }

    sinus_lambda = 3.3121686421112381E-170;
    N = std::abs(position_llh[0]);
    if (N > 3.3121686421112381E-170) {
      cosinus_phi = 1.0;
      sinus_lambda = N;
    } else {
      oldh = N / 3.3121686421112381E-170;
      cosinus_phi = oldh * oldh;
    }

    N = std::abs(position_llh[1]);
    if (N > sinus_lambda) {
      oldh = sinus_lambda / N;
      cosinus_phi = cosinus_phi * oldh * oldh + 1.0;
      sinus_lambda = N;
    } else {
      oldh = N / sinus_lambda;
      cosinus_phi += oldh * oldh;
    }

    N = std::abs(position_llh[2]);
    if (N > sinus_lambda) {
      oldh = sinus_lambda / N;
      cosinus_phi = cosinus_phi * oldh * oldh + 1.0;
      sinus_lambda = N;
    } else {
      oldh = N / sinus_lambda;
      cosinus_phi += oldh * oldh;
    }

    pseudorange_pre_data[cb_size_idx_0] = sinus_lambda * std::sqrt(cosinus_phi)
      + clockerror;
  }

  *y_size = h_size;
  for (k = 0; k < h_size; k++) {
    y_data[k] = e_GNSS_Measurement_pseudorange_[h_data[k] - 1] -
      pseudorange_pre_data[k];
  }

  k = W_size[1];
  for (cb_size_idx_0 = 0; cb_size_idx_0 < k; cb_size_idx_0++) {
    coffset = cb_size_idx_0 << 2;
    boffset = cb_size_idx_0 * W_size[0];
    b_y_data[coffset] = 0.0;
    b_y_data[coffset + 1] = 0.0;
    b_y_data[coffset + 2] = 0.0;
    b_y_data[coffset + 3] = 0.0;
    loop_ub = H_size[0];
    for (aoffset = 0; aoffset < loop_ub; aoffset++) {
      sinus_lambda = W_data[boffset + aoffset];
      b_y_data[coffset] += H_data[aoffset] * sinus_lambda;
      b_y_data[coffset + 1] += H_data[H_size[0] + aoffset] * sinus_lambda;
      b_y_data[coffset + 2] += H_data[(H_size[0] << 1) + aoffset] * sinus_lambda;
      b_y_data[coffset + 3] += H_data[3 * H_size[0] + aoffset] * sinus_lambda;
    }
  }

  k = W_size[1];
  for (cb_size_idx_0 = 0; cb_size_idx_0 < 4; cb_size_idx_0++) {
    coffset = cb_size_idx_0 << 2;
    boffset = cb_size_idx_0 * H_size[0];
    c_y[coffset] = 0.0;
    c_y[coffset + 1] = 0.0;
    c_y[coffset + 2] = 0.0;
    c_y[coffset + 3] = 0.0;
    for (loop_ub = 0; loop_ub < k; loop_ub++) {
      aoffset = loop_ub << 2;
      sinus_lambda = H_data[boffset + loop_ub];
      c_y[coffset] += b_y_data[aoffset] * sinus_lambda;
      c_y[coffset + 1] += b_y_data[aoffset + 1] * sinus_lambda;
      c_y[coffset + 2] += b_y_data[aoffset + 2] * sinus_lambda;
      c_y[coffset + 3] += b_y_data[aoffset + 3] * sinus_lambda;
    }
  }

  A_size[0] = 4;
  A_size[1] = h_size;
  for (k = 0; k < h_size; k++) {
    A_data[k << 2] = H_data[k];
    A_data[1 + (k << 2)] = H_data[k + H_size[0]];
    A_data[2 + (k << 2)] = H_data[(H_size[0] << 1) + k];
    A_data[3 + (k << 2)] = H_data[H_size[0] * 3 + k];
  }

  GNSSPreProcessingSin_mldivide_d(c_y, A_data, A_size, b_y_data,
    satellitePosition_ecef_size);
  k = W_size[1];
  for (cb_size_idx_0 = 0; cb_size_idx_0 < k; cb_size_idx_0++) {
    coffset = cb_size_idx_0 << 2;
    boffset = cb_size_idx_0 * W_size[0];
    A_data[coffset] = 0.0;
    A_data[coffset + 1] = 0.0;
    A_data[coffset + 2] = 0.0;
    A_data[coffset + 3] = 0.0;
    loop_ub = satellitePosition_ecef_size[1];
    for (aoffset = 0; aoffset < loop_ub; aoffset++) {
      b_aoffset = aoffset << 2;
      sinus_lambda = W_data[boffset + aoffset];
      A_data[coffset] += b_y_data[b_aoffset] * sinus_lambda;
      A_data[coffset + 1] += b_y_data[b_aoffset + 1] * sinus_lambda;
      A_data[coffset + 2] += b_y_data[b_aoffset + 2] * sinus_lambda;
      A_data[coffset + 3] += b_y_data[b_aoffset + 3] * sinus_lambda;
    }
  }

  S_size[0] = h_size;
  S_size[1] = h_size;
  loop_ub = h_size * h_size;
  if (loop_ub - 1 >= 0) {
    std::memset(&GNSSPreProcessingSingleAntenn_B.S_data[0], 0,
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  if (h_size > 0) {
    for (cb_size_idx_0 = 0; cb_size_idx_0 < h_size; cb_size_idx_0++) {
      GNSSPreProcessingSingleAntenn_B.S_data[cb_size_idx_0 + S_size[0] *
        cb_size_idx_0] = 1.0;
    }
  }

  f_size[0] = h_size;
  f_size[1] = W_size[1];
  boffset = W_size[1];
  for (loop_ub = 0; loop_ub < boffset; loop_ub++) {
    aoffset = loop_ub * h_size;
    b_aoffset = loop_ub << 2;
    cb_size_idx_0 = (h_size / 2) << 1;
    coffset = cb_size_idx_0 - 2;
    for (k = 0; k <= coffset; k += 2) {
      __m128d tmp;
      tmp_0 = _mm_loadu_pd(&H_data[k]);
      tmp_1 = _mm_loadu_pd(&H_data[H_size[0] + k]);
      tmp_2 = _mm_loadu_pd(&H_data[(H_size[0] << 1) + k]);
      tmp = _mm_loadu_pd(&H_data[3 * H_size[0] + k]);
      _mm_storeu_pd(&GNSSPreProcessingSingleAntenn_B.f_data[aoffset + k],
                    _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd(tmp_0,
        _mm_set1_pd(A_data[b_aoffset])), _mm_mul_pd(tmp_1, _mm_set1_pd
        (A_data[b_aoffset + 1]))), _mm_mul_pd(tmp_2, _mm_set1_pd
        (A_data[b_aoffset + 2]))), _mm_mul_pd(tmp, _mm_set1_pd(A_data[b_aoffset
        + 3]))));
    }

    for (k = cb_size_idx_0; k < h_size; k++) {
      GNSSPreProcessingSingleAntenn_B.f_data[aoffset + k] = ((H_data[H_size[0] +
        k] * A_data[b_aoffset + 1] + H_data[k] * A_data[b_aoffset]) + H_data
        [(H_size[0] << 1) + k] * A_data[b_aoffset + 2]) + H_data[3 * H_size[0] +
        k] * A_data[b_aoffset + 3];
    }
  }

  if (h_size == W_size[1]) {
    loop_ub = h_size * h_size;
    cb_size_idx_0 = (loop_ub / 2) << 1;
    coffset = cb_size_idx_0 - 2;
    for (boffset = 0; boffset <= coffset; boffset += 2) {
      tmp_0 = _mm_loadu_pd(&GNSSPreProcessingSingleAntenn_B.S_data[boffset]);
      tmp_1 = _mm_loadu_pd(&GNSSPreProcessingSingleAntenn_B.f_data[boffset]);
      _mm_storeu_pd(&GNSSPreProcessingSingleAntenn_B.S_data[boffset], _mm_sub_pd
                    (tmp_0, tmp_1));
    }

    for (boffset = cb_size_idx_0; boffset < loop_ub; boffset++) {
      GNSSPreProcessingSingleAntenn_B.S_data[boffset] -=
        GNSSPreProcessingSingleAntenn_B.f_data[boffset];
    }
  } else {
    GNSSPreProcessingSingle_minus_f(GNSSPreProcessingSingleAntenn_B.S_data,
      S_size, GNSSPreProcessingSingleAntenn_B.f_data, f_size);
  }

  GNSSPreProcessingSingleA_mtimes(GNSSPreProcessingSingleAntenn_B.S_data, S_size,
    y_data, pseudorange_pre_data, &boffset);
  aoffset = W_size[1];
  k = W_size[1];
  for (cb_size_idx_0 = 0; cb_size_idx_0 < k; cb_size_idx_0++) {
    coffset = cb_size_idx_0 * W_size[0];
    d_y_data[cb_size_idx_0] = 0.0;
    for (loop_ub = 0; loop_ub < boffset; loop_ub++) {
      d_y_data[cb_size_idx_0] += W_data[coffset + loop_ub] *
        pseudorange_pre_data[loop_ub];
    }
  }

  sinus_lambda = 0.0;
  for (k = 0; k < aoffset; k++) {
    sinus_lambda += d_y_data[k] * pseudorange_pre_data[k];
  }

  *test_statistic = std::sqrt(sinus_lambda);
  cosinus_phi = static_cast<real_T>(h_size) - m;
  *threshold = std::sqrt(b_table_chi_square[static_cast<int32_T>(cosinus_phi) -
    1]);
  if (h_size - 1 >= 0) {
    std::memset(&pseudorange_pre_data[0], 0, static_cast<uint32_T>(h_size) *
                sizeof(real_T));
  }

  for (cb_size_idx_0 = 0; cb_size_idx_0 < h_size; cb_size_idx_0++) {
    sinus_lambda = A_data[cb_size_idx_0 << 2];
    N = A_data[(cb_size_idx_0 << 2) + 1];
    pseudorange_pre_data[cb_size_idx_0] = std::sqrt((sinus_lambda * sinus_lambda
      + N * N) / GNSSPreProcessingSingleAntenn_B.S_data[S_size[0] *
      cb_size_idx_0 + cb_size_idx_0]) * std::sqrt
      (GNSSPreProcessingSingleAntenn_B.matrix_pseudorange_variance_dat[matrix_pseudorange_variance_siz
       [0] * cb_size_idx_0 + cb_size_idx_0]);
  }

  *HPL = std::sqrt(b_table_chi_square[static_cast<int32_T>(cosinus_phi) + 39] /
                   cosinus_phi) * GNSSPreProcessingSingle_maximum
    (pseudorange_pre_data, &h_size);
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_sqrt_f(real_T
  x_data[], const int32_T x_size[2])
{
  int32_T b_tmp;
  int32_T scalarLB;
  int32_T vectorUB;
  b_tmp = x_size[0] * x_size[1];
  scalarLB = (b_tmp / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T k{0}; k <= vectorUB; k += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&x_data[k]);
    _mm_storeu_pd(&x_data[k], _mm_sqrt_pd(tmp));
  }

  for (int32_T k{scalarLB}; k < b_tmp; k++) {
    x_data[k] = std::sqrt(x_data[k]);
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingl_mtimes_c(const real_T
  A_data[], const int32_T A_size[2], const real_T B_data[], const int32_T
  B_size[2], real_T C_data[], int32_T C_size[2])
{
  int32_T c;
  int32_T mc;
  mc = A_size[0] - 1;
  C_size[0] = A_size[0];
  C_size[1] = 4;
  c = A_size[1];
  for (int32_T j{0}; j < 4; j++) {
    int32_T boffset;
    int32_T coffset;
    coffset = (mc + 1) * j;
    boffset = j * B_size[0];
    if (mc >= 0) {
      std::memset(&C_data[coffset], 0, static_cast<uint32_T>(((mc + coffset) -
        coffset) + 1) * sizeof(real_T));
    }

    for (int32_T i{0}; i < c; i++) {
      real_T bkj;
      int32_T aoffset;
      int32_T scalarLB;
      int32_T tmp_0;
      int32_T vectorUB;
      aoffset = i * A_size[0];
      bkj = B_data[boffset + i];
      scalarLB = ((mc + 1) / 2) << 1;
      vectorUB = scalarLB - 2;
      for (int32_T b_i{0}; b_i <= vectorUB; b_i += 2) {
        __m128d tmp;
        tmp_0 = coffset + b_i;
        tmp = _mm_loadu_pd(&C_data[tmp_0]);
        _mm_storeu_pd(&C_data[tmp_0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
          (&A_data[aoffset + b_i]), _mm_set1_pd(bkj)), tmp));
      }

      for (int32_T b_i{scalarLB}; b_i <= mc; b_i++) {
        tmp_0 = coffset + b_i;
        C_data[tmp_0] += A_data[aoffset + b_i] * bkj;
      }
    }
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_xgemv_i(int32_T m,
  int32_T n, const real_T A_data[], int32_T ia0, int32_T lda, const real_T
  x_data[], int32_T ix0, real_T y[4])
{
  if (n != 0) {
    int32_T b;
    int32_T iy;
    if (n - 1 >= 0) {
      std::memset(&y[0], 0, static_cast<uint32_T>(n) * sizeof(real_T));
    }

    iy = 0;
    b = (n - 1) * lda + ia0;
    for (int32_T b_iy{ia0}; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (int32_T ia{b_iy}; ia < d; ia++) {
        c += x_data[((ix0 + ia) - b_iy) - 1] * A_data[ia - 1];
      }

      y[iy] += c;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingle_xgerc_i(int32_T m,
  int32_T n, real_T alpha1, int32_T ix0, const real_T y[4], real_T A_data[],
  int32_T ia0, int32_T lda)
{
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    for (int32_T j{0}; j < n; j++) {
      real_T temp;
      temp = y[j];
      if (temp != 0.0) {
        int32_T b;
        temp *= alpha1;
        b = m + jA;
        for (int32_T ijA{jA}; ijA < b; ijA++) {
          A_data[ijA - 1] += A_data[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += lda;
    }
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingl_xgeqrf_j(real_T
  A_data[], const int32_T A_size[2], real_T tau_data[], int32_T *tau_size)
{
  real_T work[4];
  int32_T m;
  int32_T minmana;
  int32_T minmn;
  m = A_size[0];
  if (A_size[0] <= 4) {
    minmana = A_size[0];
  } else {
    minmana = 4;
  }

  if (A_size[0] <= 4) {
    minmn = A_size[0];
  } else {
    minmn = 4;
  }

  *tau_size = minmana;
  if (minmana - 1 >= 0) {
    std::memset(&tau_data[0], 0, static_cast<uint32_T>(minmana) * sizeof(real_T));
  }

  if ((A_size[0] != 0) && (minmn >= 1)) {
    minmana = A_size[0];
    work[0] = 0.0;
    work[1] = 0.0;
    work[2] = 0.0;
    work[3] = 0.0;
    for (int32_T i{0}; i < minmn; i++) {
      real_T xnorm;
      int32_T coltop;
      int32_T ii;
      int32_T ix0;
      int32_T mmi;
      int32_T mmip1;
      int32_T vectorUB;
      ii = i * minmana + i;
      mmi = m - i;
      if (i + 1 < m) {
        real_T atmp;
        atmp = A_data[ii];
        ix0 = ii + 2;
        tau_data[i] = 0.0;
        if (mmi > 0) {
          xnorm = GNSSPreProcessingSingleAn_xnrm2(mmi - 1, A_data, ii + 2);
          if (xnorm != 0.0) {
            xnorm = rt_hypotd_snf(A_data[ii], xnorm);
            if (A_data[ii] >= 0.0) {
              xnorm = -xnorm;
            }

            if (std::abs(xnorm) < 1.0020841800044864E-292) {
              __m128d tmp;
              int32_T d;
              int32_T knt;
              knt = 0;
              d = ii + mmi;
              do {
                knt++;
                coltop = (((((d - ii) - 1) / 2) << 1) + ii) + 2;
                vectorUB = coltop - 2;
                for (mmip1 = ix0; mmip1 <= vectorUB; mmip1 += 2) {
                  tmp = _mm_loadu_pd(&A_data[mmip1 - 1]);
                  _mm_storeu_pd(&A_data[mmip1 - 1], _mm_mul_pd(tmp, _mm_set1_pd
                    (9.9792015476736E+291)));
                }

                for (mmip1 = coltop; mmip1 <= d; mmip1++) {
                  A_data[mmip1 - 1] *= 9.9792015476736E+291;
                }

                xnorm *= 9.9792015476736E+291;
                atmp *= 9.9792015476736E+291;
              } while ((std::abs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

              xnorm = rt_hypotd_snf(atmp, GNSSPreProcessingSingleAn_xnrm2(mmi -
                1, A_data, ii + 2));
              if (atmp >= 0.0) {
                xnorm = -xnorm;
              }

              tau_data[i] = (xnorm - atmp) / xnorm;
              atmp = 1.0 / (atmp - xnorm);
              d = ii + mmi;
              coltop = (((((d - ii) - 1) / 2) << 1) + ii) + 2;
              vectorUB = coltop - 2;
              for (mmip1 = ix0; mmip1 <= vectorUB; mmip1 += 2) {
                tmp = _mm_loadu_pd(&A_data[mmip1 - 1]);
                _mm_storeu_pd(&A_data[mmip1 - 1], _mm_mul_pd(tmp, _mm_set1_pd
                  (atmp)));
              }

              for (mmip1 = coltop; mmip1 <= d; mmip1++) {
                A_data[mmip1 - 1] *= atmp;
              }

              for (ix0 = 0; ix0 < knt; ix0++) {
                xnorm *= 1.0020841800044864E-292;
              }

              atmp = xnorm;
            } else {
              tau_data[i] = (xnorm - A_data[ii]) / xnorm;
              atmp = 1.0 / (A_data[ii] - xnorm);
              mmip1 = ii + mmi;
              coltop = (((((mmip1 - ii) - 1) / 2) << 1) + ii) + 2;
              vectorUB = coltop - 2;
              for (int32_T knt{ix0}; knt <= vectorUB; knt += 2) {
                __m128d tmp;
                tmp = _mm_loadu_pd(&A_data[knt - 1]);
                _mm_storeu_pd(&A_data[knt - 1], _mm_mul_pd(tmp, _mm_set1_pd(atmp)));
              }

              for (int32_T knt{coltop}; knt <= mmip1; knt++) {
                A_data[knt - 1] *= atmp;
              }

              atmp = xnorm;
            }
          }
        }

        A_data[ii] = atmp;
      } else {
        tau_data[i] = 0.0;
      }

      if (i + 1 < 4) {
        xnorm = A_data[ii];
        A_data[ii] = 1.0;
        ix0 = (ii + minmana) + 1;
        if (tau_data[i] != 0.0) {
          boolean_T exitg2;
          mmip1 = ii + mmi;
          while ((mmi > 0) && (A_data[mmip1 - 1] == 0.0)) {
            mmi--;
            mmip1--;
          }

          mmip1 = 3 - i;
          exitg2 = false;
          while ((!exitg2) && (mmip1 > 0)) {
            int32_T exitg1;
            coltop = (mmip1 - 1) * minmana + ix0;
            vectorUB = coltop;
            do {
              exitg1 = 0;
              if (vectorUB <= (coltop + mmi) - 1) {
                if (A_data[vectorUB - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  vectorUB++;
                }
              } else {
                mmip1--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          mmi = 0;
          mmip1 = 0;
        }

        if (mmi > 0) {
          GNSSPreProcessingSingle_xgemv_i(mmi, mmip1, A_data, ix0, minmana,
            A_data, ii + 1, work);
          GNSSPreProcessingSingle_xgerc_i(mmi, mmip1, -tau_data[i], ii + 1, work,
            A_data, ix0, minmana);
        }

        A_data[ii] = xnorm;
      }
    }
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
real_T GNSS_preprocessingModelClass::GNSSPreProcessingSingle_xnrm2_a(int32_T n,
  const real_T x_data[], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x_data[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k{ix0}; k <= kend; k++) {
        real_T absxk;
        absxk = std::abs(x_data[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_xgemv(int32_T m,
  int32_T n, const real_T A_data[], int32_T ia0, int32_T lda, const real_T
  x_data[], int32_T ix0, real_T y_data[])
{
  if (n != 0) {
    int32_T b;
    int32_T iy;
    if (n - 1 >= 0) {
      std::memset(&y_data[0], 0, static_cast<uint32_T>(n) * sizeof(real_T));
    }

    iy = 0;
    b = (n - 1) * lda + ia0;
    for (int32_T b_iy{ia0}; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (int32_T ia{b_iy}; ia < d; ia++) {
        c += x_data[((ix0 + ia) - b_iy) - 1] * A_data[ia - 1];
      }

      y_data[iy] += c;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAn_xgerc(int32_T m,
  int32_T n, real_T alpha1, int32_T ix0, const real_T y_data[], real_T A_data[],
  int32_T ia0, int32_T lda)
{
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    for (int32_T j{0}; j < n; j++) {
      real_T temp;
      temp = y_data[j];
      if (temp != 0.0) {
        int32_T b;
        temp *= alpha1;
        b = m + jA;
        for (int32_T ijA{jA}; ijA < b; ijA++) {
          A_data[ijA - 1] += A_data[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += lda;
    }
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_xgeqrf(real_T
  A_data[], const int32_T A_size[2], real_T tau_data[], int32_T *tau_size)
{
  real_T work_data[40];
  int32_T m;
  int32_T minmana;
  int32_T minmn;
  int32_T n;
  m = A_size[0];
  n = A_size[1];
  if (A_size[0] <= A_size[1]) {
    minmana = A_size[0];
  } else {
    minmana = A_size[1];
  }

  if (A_size[0] <= A_size[1]) {
    minmn = A_size[0];
  } else {
    minmn = A_size[1];
  }

  *tau_size = minmana;
  if (minmana - 1 >= 0) {
    std::memset(&tau_data[0], 0, static_cast<uint32_T>(minmana) * sizeof(real_T));
  }

  if ((A_size[0] != 0) && (A_size[1] != 0) && (minmn >= 1)) {
    int32_T ii;
    minmana = A_size[0];
    ii = A_size[1];
    if (ii - 1 >= 0) {
      std::memset(&work_data[0], 0, static_cast<uint32_T>(ii) * sizeof(real_T));
    }

    for (int32_T i{0}; i < minmn; i++) {
      real_T xnorm;
      int32_T coltop;
      int32_T ix0;
      int32_T mmi;
      int32_T mmip1;
      int32_T vectorUB;
      ii = i * minmana + i;
      mmi = m - i;
      if (i + 1 < m) {
        real_T atmp;
        atmp = A_data[ii];
        ix0 = ii + 2;
        tau_data[i] = 0.0;
        if (mmi > 0) {
          xnorm = GNSSPreProcessingSingle_xnrm2_a(mmi - 1, A_data, ii + 2);
          if (xnorm != 0.0) {
            xnorm = rt_hypotd_snf(A_data[ii], xnorm);
            if (A_data[ii] >= 0.0) {
              xnorm = -xnorm;
            }

            if (std::abs(xnorm) < 1.0020841800044864E-292) {
              __m128d tmp;
              int32_T d;
              int32_T knt;
              knt = 0;
              d = ii + mmi;
              do {
                knt++;
                coltop = (((((d - ii) - 1) / 2) << 1) + ii) + 2;
                vectorUB = coltop - 2;
                for (mmip1 = ix0; mmip1 <= vectorUB; mmip1 += 2) {
                  tmp = _mm_loadu_pd(&A_data[mmip1 - 1]);
                  _mm_storeu_pd(&A_data[mmip1 - 1], _mm_mul_pd(tmp, _mm_set1_pd
                    (9.9792015476736E+291)));
                }

                for (mmip1 = coltop; mmip1 <= d; mmip1++) {
                  A_data[mmip1 - 1] *= 9.9792015476736E+291;
                }

                xnorm *= 9.9792015476736E+291;
                atmp *= 9.9792015476736E+291;
              } while ((std::abs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

              xnorm = rt_hypotd_snf(atmp, GNSSPreProcessingSingle_xnrm2_a(mmi -
                1, A_data, ii + 2));
              if (atmp >= 0.0) {
                xnorm = -xnorm;
              }

              tau_data[i] = (xnorm - atmp) / xnorm;
              atmp = 1.0 / (atmp - xnorm);
              d = ii + mmi;
              coltop = (((((d - ii) - 1) / 2) << 1) + ii) + 2;
              vectorUB = coltop - 2;
              for (mmip1 = ix0; mmip1 <= vectorUB; mmip1 += 2) {
                tmp = _mm_loadu_pd(&A_data[mmip1 - 1]);
                _mm_storeu_pd(&A_data[mmip1 - 1], _mm_mul_pd(tmp, _mm_set1_pd
                  (atmp)));
              }

              for (mmip1 = coltop; mmip1 <= d; mmip1++) {
                A_data[mmip1 - 1] *= atmp;
              }

              for (ix0 = 0; ix0 < knt; ix0++) {
                xnorm *= 1.0020841800044864E-292;
              }

              atmp = xnorm;
            } else {
              tau_data[i] = (xnorm - A_data[ii]) / xnorm;
              atmp = 1.0 / (A_data[ii] - xnorm);
              mmip1 = ii + mmi;
              coltop = (((((mmip1 - ii) - 1) / 2) << 1) + ii) + 2;
              vectorUB = coltop - 2;
              for (int32_T knt{ix0}; knt <= vectorUB; knt += 2) {
                __m128d tmp;
                tmp = _mm_loadu_pd(&A_data[knt - 1]);
                _mm_storeu_pd(&A_data[knt - 1], _mm_mul_pd(tmp, _mm_set1_pd(atmp)));
              }

              for (int32_T knt{coltop}; knt <= mmip1; knt++) {
                A_data[knt - 1] *= atmp;
              }

              atmp = xnorm;
            }
          }
        }

        A_data[ii] = atmp;
      } else {
        tau_data[i] = 0.0;
      }

      if (i + 1 < n) {
        xnorm = A_data[ii];
        A_data[ii] = 1.0;
        ix0 = (ii + minmana) + 1;
        if (tau_data[i] != 0.0) {
          boolean_T exitg2;
          mmip1 = ii + mmi;
          while ((mmi > 0) && (A_data[mmip1 - 1] == 0.0)) {
            mmi--;
            mmip1--;
          }

          mmip1 = (n - i) - 1;
          exitg2 = false;
          while ((!exitg2) && (mmip1 > 0)) {
            int32_T exitg1;
            coltop = (mmip1 - 1) * minmana + ix0;
            vectorUB = coltop;
            do {
              exitg1 = 0;
              if (vectorUB <= (coltop + mmi) - 1) {
                if (A_data[vectorUB - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  vectorUB++;
                }
              } else {
                mmip1--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          mmi = 0;
          mmip1 = 0;
        }

        if (mmi > 0) {
          GNSSPreProcessingSingleAn_xgemv(mmi, mmip1, A_data, ix0, minmana,
            A_data, ii + 1, work_data);
          GNSSPreProcessingSingleAn_xgerc(mmi, mmip1, -tau_data[i], ii + 1,
            work_data, A_data, ix0, minmana);
        }

        A_data[ii] = xnorm;
      }
    }
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleAnten_qr(const real_T
  A_data[], const int32_T A_size[2], real_T Q_data[], int32_T Q_size[2], real_T
  R_data[], int32_T R_size[2])
{
  real_T b_A_data[160];
  real_T b_tau_data[40];
  real_T work_data[40];
  real_T b_work[4];
  real_T tau_data[4];
  int32_T b_A_size[2];
  int32_T l_i;
  int32_T m;
  m = A_size[0];
  Q_size[0] = static_cast<int8_T>(A_size[0]);
  Q_size[1] = static_cast<int8_T>(A_size[0]);
  R_size[0] = A_size[0];
  R_size[1] = 4;
  if (A_size[0] > 4) {
    int32_T b_ia;
    int32_T b_itau;
    for (b_itau = 0; b_itau < 4; b_itau++) {
      for (l_i = 0; l_i < m; l_i++) {
        Q_data[l_i + Q_size[0] * b_itau] = A_data[A_size[0] * b_itau + l_i];
      }
    }

    for (b_itau = 5; b_itau <= m; b_itau++) {
      for (l_i = 0; l_i < m; l_i++) {
        Q_data[l_i + Q_size[0] * (b_itau - 1)] = 0.0;
      }
    }

    GNSSPreProcessingSingleA_xgeqrf(Q_data, Q_size, b_tau_data, &l_i);
    for (b_itau = 0; b_itau < 4; b_itau++) {
      for (l_i = 0; l_i <= b_itau; l_i++) {
        R_data[l_i + R_size[0] * b_itau] = Q_data[Q_size[0] * b_itau + l_i];
      }

      for (l_i = b_itau + 2; l_i <= m; l_i++) {
        R_data[(l_i + R_size[0] * b_itau) - 1] = 0.0;
      }
    }

    b_itau = A_size[0] - 1;
    for (l_i = 4; l_i <= b_itau; l_i++) {
      b_ia = l_i * m;
      std::memset(&Q_data[b_ia], 0, static_cast<uint32_T>((m + b_ia) - b_ia) *
                  sizeof(real_T));
      Q_data[b_ia + l_i] = 1.0;
    }

    l_i = static_cast<int8_T>(Q_size[1]);
    if (l_i - 1 >= 0) {
      std::memset(&work_data[0], 0, static_cast<uint32_T>(l_i) * sizeof(real_T));
    }

    for (b_itau = 3; b_itau >= 0; b_itau--) {
      int32_T b_lastv;
      int32_T c_lastc;
      int32_T lastv;
      int32_T lastv_tmp;
      l_i = b_itau * m + b_itau;
      Q_data[l_i] = 1.0;
      lastv_tmp = m - b_itau;
      lastv = lastv_tmp;
      b_ia = (l_i + m) + 1;
      if (b_tau_data[b_itau] != 0.0) {
        boolean_T exitg2;
        b_lastv = l_i + lastv_tmp;
        while ((lastv > 0) && (Q_data[b_lastv - 1] == 0.0)) {
          lastv--;
          b_lastv--;
        }

        b_lastv = lastv_tmp - 1;
        exitg2 = false;
        while ((!exitg2) && (b_lastv > 0)) {
          int32_T b_coltop;
          int32_T exitg1;
          c_lastc = (b_lastv - 1) * m + b_ia;
          b_coltop = c_lastc;
          do {
            exitg1 = 0;
            if (b_coltop <= (c_lastc + lastv) - 1) {
              if (Q_data[b_coltop - 1] != 0.0) {
                exitg1 = 1;
              } else {
                b_coltop++;
              }
            } else {
              b_lastv--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        b_lastv = 0;
      }

      if (lastv > 0) {
        GNSSPreProcessingSingleAn_xgemv(lastv, b_lastv, Q_data, b_ia, m, Q_data,
          l_i + 1, work_data);
        GNSSPreProcessingSingleAn_xgerc(lastv, b_lastv, -b_tau_data[b_itau], l_i
          + 1, work_data, Q_data, b_ia, m);
      }

      b_ia = (l_i + m) - b_itau;
      lastv = (((((b_ia - l_i) - 1) / 2) << 1) + l_i) + 2;
      b_lastv = lastv - 2;
      for (c_lastc = l_i + 2; c_lastc <= b_lastv; c_lastc += 2) {
        __m128d tmp;
        tmp = _mm_loadu_pd(&Q_data[c_lastc - 1]);
        _mm_storeu_pd(&Q_data[c_lastc - 1], _mm_mul_pd(tmp, _mm_set1_pd
          (-b_tau_data[b_itau])));
      }

      for (c_lastc = lastv; c_lastc <= b_ia; c_lastc++) {
        Q_data[c_lastc - 1] *= -b_tau_data[b_itau];
      }

      Q_data[l_i] = 1.0 - b_tau_data[b_itau];
      for (b_ia = 0; b_ia < b_itau; b_ia++) {
        Q_data[(l_i - b_ia) - 1] = 0.0;
      }
    }
  } else {
    int32_T b_ia;
    int32_T b_itau;
    b_A_size[0] = A_size[0];
    b_A_size[1] = 4;
    l_i = A_size[0] << 2;
    if (l_i - 1 >= 0) {
      std::memcpy(&b_A_data[0], &A_data[0], static_cast<uint32_T>(l_i) * sizeof
                  (real_T));
    }

    GNSSPreProcessingSingl_xgeqrf_j(b_A_data, b_A_size, tau_data, &l_i);
    b_itau = A_size[0];
    for (l_i = 0; l_i < b_itau; l_i++) {
      for (b_ia = 0; b_ia <= l_i; b_ia++) {
        R_data[b_ia + R_size[0] * l_i] = b_A_data[b_A_size[0] * l_i + b_ia];
      }

      for (b_ia = l_i + 2; b_ia <= m; b_ia++) {
        R_data[(b_ia + R_size[0] * l_i) - 1] = 0.0;
      }
    }

    b_itau = A_size[0] + 1;
    for (l_i = b_itau; l_i < 5; l_i++) {
      for (b_ia = 0; b_ia < m; b_ia++) {
        R_data[b_ia + R_size[0] * (l_i - 1)] = b_A_data[(l_i - 1) * b_A_size[0]
          + b_ia];
      }
    }

    if (A_size[0] >= 1) {
      b_itau = A_size[0] - 1;
      for (l_i = m; l_i <= b_itau; l_i++) {
        b_ia = l_i * m;
        if (m - 1 >= 0) {
          std::memset(&b_A_data[b_ia], 0, static_cast<uint32_T>((m + b_ia) -
            b_ia) * sizeof(real_T));
        }

        b_A_data[b_ia + l_i] = 1.0;
      }

      b_itau = A_size[0] - 1;
      b_work[0] = 0.0;
      b_work[1] = 0.0;
      b_work[2] = 0.0;
      b_work[3] = 0.0;
      for (l_i = A_size[0]; l_i >= 1; l_i--) {
        int32_T lastv;
        b_ia = (l_i - 1) * m + l_i;
        if (l_i < m) {
          int32_T b_coltop;
          int32_T b_lastv;
          int32_T c_lastc;
          int32_T lastv_tmp;
          b_A_data[b_ia - 1] = 1.0;
          c_lastc = (m - l_i) - 1;
          lastv_tmp = b_ia + m;
          if (tau_data[b_itau] != 0.0) {
            boolean_T exitg2;
            b_lastv = c_lastc + 2;
            c_lastc += b_ia;
            while ((b_lastv > 0) && (b_A_data[c_lastc] == 0.0)) {
              b_lastv--;
              c_lastc--;
            }

            c_lastc = m - l_i;
            exitg2 = false;
            while ((!exitg2) && (c_lastc > 0)) {
              int32_T exitg1;
              b_coltop = (c_lastc - 1) * m + lastv_tmp;
              lastv = b_coltop;
              do {
                exitg1 = 0;
                if (lastv <= (b_coltop + b_lastv) - 1) {
                  if (b_A_data[lastv - 1] != 0.0) {
                    exitg1 = 1;
                  } else {
                    lastv++;
                  }
                } else {
                  c_lastc--;
                  exitg1 = 2;
                }
              } while (exitg1 == 0);

              if (exitg1 == 1) {
                exitg2 = true;
              }
            }
          } else {
            b_lastv = 0;
            c_lastc = 0;
          }

          if (b_lastv > 0) {
            GNSSPreProcessingSingle_xgemv_i(b_lastv, c_lastc, b_A_data,
              lastv_tmp, m, b_A_data, b_ia, b_work);
            GNSSPreProcessingSingle_xgerc_i(b_lastv, c_lastc, -tau_data[b_itau],
              b_ia, b_work, b_A_data, lastv_tmp, m);
          }

          c_lastc = lastv_tmp - l_i;
          lastv = ((((c_lastc - b_ia) / 2) << 1) + b_ia) + 1;
          b_lastv = lastv - 2;
          for (b_coltop = b_ia + 1; b_coltop <= b_lastv; b_coltop += 2) {
            __m128d tmp;
            tmp = _mm_loadu_pd(&b_A_data[b_coltop - 1]);
            _mm_storeu_pd(&b_A_data[b_coltop - 1], _mm_mul_pd(tmp, _mm_set1_pd
              (-tau_data[b_itau])));
          }

          for (b_coltop = lastv; b_coltop <= c_lastc; b_coltop++) {
            b_A_data[b_coltop - 1] *= -tau_data[b_itau];
          }
        }

        b_A_data[b_ia - 1] = 1.0 - tau_data[b_itau];
        for (lastv = 0; lastv <= l_i - 2; lastv++) {
          b_A_data[(b_ia - lastv) - 2] = 0.0;
        }

        b_itau--;
      }
    }

    b_itau = A_size[0];
    for (l_i = 0; l_i < b_itau; l_i++) {
      for (b_ia = 0; b_ia < m; b_ia++) {
        Q_data[b_ia + Q_size[0] * l_i] = b_A_data[b_A_size[0] * l_i + b_ia];
      }
    }
  }
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
real_T GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_norm_j(const
  real_T x_data[], const int32_T *x_size)
{
  real_T y;
  if (*x_size == 0) {
    y = 0.0;
  } else {
    y = 0.0;
    if (*x_size == 1) {
      y = std::abs(x_data[0]);
    } else {
      real_T scale;
      int32_T b;
      scale = 3.3121686421112381E-170;
      b = *x_size;
      for (int32_T k{0}; k < b; k++) {
        real_T absxk;
        absxk = std::abs(x_data[k]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_fr(real_T
  in1_data[], const int32_T in1_size[2], int32_T in2, const real_T in3_data[],
  const int32_T *in3_size, real_T in4, const real_T in5_data[], const int32_T
  in5_size[2])
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S117>/MATLAB Function' incorporates:
  //   SubSystem: '<S117>/GNSS Fault Detection Identification Exclusion'

  // MATLAB Function: '<S118>/Weighted RAIM Parity'
  stride_0_0 = (*in3_size != 1);
  stride_1_0 = (in5_size[0] != 1);
  loop_ub = in5_size[0] == 1 ? *in3_size : in5_size[0];
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i + in1_size[0] * in2] = in3_data[i * stride_0_0] - in5_data[i *
      stride_1_0 + in5_size[0] * in2] * in4;
  }

  // End of MATLAB Function: '<S118>/Weighted RAIM Parity'
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
real_T GNSS_preprocessingModelClass::GNSSPreProcessingSingleAnte_sum(const
  real_T x_data[], const int32_T x_size[2])
{
  real_T y;
  int32_T vlen;
  vlen = x_size[1];
  if (x_size[1] == 0) {
    y = 0.0;
  } else {
    y = x_data[0];
    for (int32_T k{2}; k <= vlen; k++) {
      y += x_data[k - 1];
    }
  }

  return y;
}

// Function for MATLAB Function: '<S118>/Weighted RAIM Parity'
void GNSS_preprocessingModelClass::GNSSPreProcessingSingleA_sort_e(real_T
  x_data[], int32_T x_size[2], int32_T idx_data[], int32_T idx_size[2])
{
  real_T b_x_data[40];
  real_T xwork_data[40];
  real_T x4[4];
  int32_T iwork_data[40];
  int32_T b_x_size[2];
  int32_T n;
  int8_T idx4[4];
  int8_T perm[4];
  b_x_size[1] = x_size[1];
  n = x_size[1];
  if (n - 1 >= 0) {
    std::memcpy(&b_x_data[0], &x_data[0], static_cast<uint32_T>(n) * sizeof
                (real_T));
  }

  idx_size[0] = 1;
  idx_size[1] = x_size[1];
  n = x_size[1];
  if (n - 1 >= 0) {
    std::memset(&idx_data[0], 0, static_cast<uint32_T>(n) * sizeof(int32_T));
  }

  if (x_size[1] != 0) {
    int32_T bLen;
    int32_T i2;
    int32_T i3;
    int32_T i4;
    int32_T ib;
    int32_T nTail;
    int32_T quartetOffset;
    int32_T wOffset;
    idx_size[0] = 1;
    idx_size[1] = x_size[1];
    n = x_size[1];
    if (n - 1 >= 0) {
      std::memset(&idx_data[0], 0, static_cast<uint32_T>(n) * sizeof(int32_T));
    }

    b_x_size[1] = x_size[1];
    n = x_size[1];
    if (n - 1 >= 0) {
      std::memcpy(&b_x_data[0], &x_data[0], static_cast<uint32_T>(n) * sizeof
                  (real_T));
    }

    n = x_size[1] - 1;
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    quartetOffset = x_size[1];
    if (quartetOffset - 1 >= 0) {
      std::memset(&xwork_data[0], 0, static_cast<uint32_T>(quartetOffset) *
                  sizeof(real_T));
    }

    bLen = 0;
    ib = -1;
    nTail = x_size[1];
    for (wOffset = 0; wOffset < nTail; wOffset++) {
      real_T tmp_0;
      tmp_0 = b_x_data[wOffset];
      if (std::isnan(tmp_0)) {
        quartetOffset = n - bLen;
        idx_data[quartetOffset] = wOffset + 1;
        xwork_data[quartetOffset] = tmp_0;
        bLen++;
      } else {
        ib++;
        idx4[ib] = static_cast<int8_T>(wOffset + 1);
        x4[ib] = tmp_0;
        if (ib + 1 == 4) {
          real_T tmp;
          quartetOffset = wOffset - bLen;
          if (x4[0] <= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }

          if (x4[2] <= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }

          tmp_0 = x4[ib - 1];
          tmp = x4[i3 - 1];
          if (tmp_0 <= tmp) {
            tmp_0 = x4[i2 - 1];
            if (tmp_0 <= tmp) {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(i2);
              perm[2] = static_cast<int8_T>(i3);
              perm[3] = static_cast<int8_T>(i4);
            } else if (tmp_0 <= x4[i4 - 1]) {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(i3);
              perm[2] = static_cast<int8_T>(i2);
              perm[3] = static_cast<int8_T>(i4);
            } else {
              perm[0] = static_cast<int8_T>(ib);
              perm[1] = static_cast<int8_T>(i3);
              perm[2] = static_cast<int8_T>(i4);
              perm[3] = static_cast<int8_T>(i2);
            }
          } else {
            tmp = x4[i4 - 1];
            if (tmp_0 <= tmp) {
              if (x4[i2 - 1] <= tmp) {
                perm[0] = static_cast<int8_T>(i3);
                perm[1] = static_cast<int8_T>(ib);
                perm[2] = static_cast<int8_T>(i2);
                perm[3] = static_cast<int8_T>(i4);
              } else {
                perm[0] = static_cast<int8_T>(i3);
                perm[1] = static_cast<int8_T>(ib);
                perm[2] = static_cast<int8_T>(i4);
                perm[3] = static_cast<int8_T>(i2);
              }
            } else {
              perm[0] = static_cast<int8_T>(i3);
              perm[1] = static_cast<int8_T>(i4);
              perm[2] = static_cast<int8_T>(ib);
              perm[3] = static_cast<int8_T>(i2);
            }
          }

          idx_data[quartetOffset - 3] = idx4[perm[0] - 1];
          idx_data[quartetOffset - 2] = idx4[perm[1] - 1];
          idx_data[quartetOffset - 1] = idx4[perm[2] - 1];
          idx_data[quartetOffset] = idx4[perm[3] - 1];
          b_x_data[quartetOffset - 3] = x4[perm[0] - 1];
          b_x_data[quartetOffset - 2] = x4[perm[1] - 1];
          b_x_data[quartetOffset - 1] = x4[perm[2] - 1];
          b_x_data[quartetOffset] = x4[perm[3] - 1];
          ib = -1;
        }
      }
    }

    i4 = x_size[1] - bLen;
    if (ib + 1 > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      switch (ib + 1) {
       case 1:
        perm[0] = 1;
        break;

       case 2:
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
        break;

       default:
        if (x4[0] <= x4[1]) {
          if (x4[1] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 2;
            perm[2] = 3;
          } else if (x4[0] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 3;
            perm[2] = 2;
          } else {
            perm[0] = 3;
            perm[1] = 1;
            perm[2] = 2;
          }
        } else if (x4[0] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 1;
          perm[2] = 3;
        } else if (x4[1] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 3;
          perm[2] = 1;
        } else {
          perm[0] = 3;
          perm[1] = 2;
          perm[2] = 1;
        }
        break;
      }

      i2 = static_cast<uint8_T>(ib + 1);
      for (nTail = 0; nTail < i2; nTail++) {
        int8_T perm_0;
        perm_0 = perm[nTail];
        i3 = ((i4 - ib) + nTail) - 1;
        idx_data[i3] = idx4[perm_0 - 1];
        b_x_data[i3] = x4[perm_0 - 1];
      }
    }

    ib = bLen >> 1;
    for (nTail = 0; nTail < ib; nTail++) {
      i2 = i4 + nTail;
      i3 = idx_data[i2];
      quartetOffset = n - nTail;
      idx_data[i2] = idx_data[quartetOffset];
      idx_data[quartetOffset] = i3;
      b_x_data[i2] = xwork_data[quartetOffset];
      b_x_data[quartetOffset] = xwork_data[i2];
    }

    if ((static_cast<uint32_T>(bLen) & 1U) != 0U) {
      n = i4 + ib;
      b_x_data[n] = xwork_data[n];
    }

    if (i4 > 1) {
      quartetOffset = x_size[1];
      if (quartetOffset - 1 >= 0) {
        std::memset(&iwork_data[0], 0, static_cast<uint32_T>(quartetOffset) *
                    sizeof(int32_T));
      }

      quartetOffset = i4 >> 2;
      bLen = 4;
      while (quartetOffset > 1) {
        if ((static_cast<uint32_T>(quartetOffset) & 1U) != 0U) {
          quartetOffset--;
          wOffset = bLen * quartetOffset;
          nTail = i4 - wOffset;
          if (nTail > bLen) {
            GNSSPreProcessingSingle_merge_a(idx_data, b_x_data, wOffset, bLen,
              nTail - bLen, iwork_data, xwork_data);
          }
        }

        nTail = bLen << 1;
        quartetOffset >>= 1;
        for (wOffset = 0; wOffset < quartetOffset; wOffset++) {
          GNSSPreProcessingSingle_merge_a(idx_data, b_x_data, wOffset * nTail,
            bLen, bLen, iwork_data, xwork_data);
        }

        bLen = nTail;
      }

      if (i4 > bLen) {
        GNSSPreProcessingSingle_merge_a(idx_data, b_x_data, 0, bLen, i4 - bLen,
          iwork_data, xwork_data);
      }
    }
  }

  x_size[0] = 1;
  x_size[1] = b_x_size[1];
  n = b_x_size[1];
  if (n - 1 >= 0) {
    std::memcpy(&x_data[0], &b_x_data[0], static_cast<uint32_T>(n) * sizeof
                (real_T));
  }
}

// Model step function
void GNSS_preprocessingModelClass::step()
{
  static const real_T h[36]{ 5.0, 0.4529, 10.0, 0.3553, 15.0, 0.3063, 20.0,
    0.2638, 25.0, 0.2593, 30.0, 0.2555, 35.0, 0.2504, 40.0, 0.2438, 45.0, 0.2396,
    50.0, 0.2359, 55.0, 0.2339, 60.0, 0.2302, 65.0, 0.2295, 70.0, 0.2278, 75.0,
    0.2297, 80.0, 0.231, 85.0, 0.2274, 90.0, 0.2277 };

  __m128d tmp_0;
  __m128d tmp_1;
  __m128d tmp_2;
  GNSS_Measurement_size galileo_measurement_temp_elems_;
  GNSS_Measurement_size *tmp_9;
  GNSS_Measurement_size *tmp_a;
  parameters_galileo_t rtb_parameters_galileo_Bus;
  parameters_gps_t rtb_parameters_gps_Bus;
  real_T H_data[160];
  real_T H_data_0[160];
  real_T rtb_GnssMeasurementBase_satel_0[120];
  real_T rtb_GnssMeasurementBase_satelli[120];
  real_T rtb_measurementFrequency_Bus__0[120];
  real_T rtb_measurementFrequency_Bus_sa[120];
  real_T tmp_data_5[80];
  real_T bvec_data[40];
  real_T delta_rho_data[40];
  real_T indx_to_exclude_data[40];
  real_T rtb_Add1[40];
  real_T rtb_BusConversion_InsertedFor_0[40];
  real_T rtb_BusConversion_InsertedFor_1[40];
  real_T rtb_BusConversion_InsertedFor_2[40];
  real_T rtb_BusConversion_InsertedFor_3[40];
  real_T rtb_BusConversion_InsertedFor_4[40];
  real_T rtb_BusConversion_InsertedFor_5[40];
  real_T rtb_BusConversion_InsertedFor_6[40];
  real_T rtb_BusConversion_InsertedFor_7[40];
  real_T rtb_BusConversion_InsertedFor_8[40];
  real_T rtb_BusConversion_InsertedFor_9[40];
  real_T rtb_dualFrequencyCorrection[40];
  real_T rtb_measurementFrequency_Bus_CN[40];
  real_T rtb_measurementFrequency_Bus__1[40];
  real_T rtb_measurementFrequency_Bus__2[40];
  real_T rtb_measurementFrequency_Bus__3[40];
  real_T rtb_measurementFrequency_Bus__4[40];
  real_T rtb_measurementFrequency_Bus__5[40];
  real_T rtb_measurementFrequency_Bus__6[40];
  real_T rtb_measurementFrequency_Bus__7[40];
  real_T rtb_measurementFrequency_Bus_ca[40];
  real_T rtb_measurementFrequency_Bus_de[40];
  real_T rtb_measurementFrequency_Bus_ps[40];
  real_T rtb_measurementFrequency_Bus_va[40];
  real_T variance_pseudorange[40];
  real_T Q[16];
  real_T y[16];
  real_T Qtemp[9];
  real_T Rot[9];
  real_T Rot_0[9];
  real_T residuum[4];
  real_T tmp[4];
  real_T user_state[4];
  real_T tmp_data_2[3];
  real_T TOW;
  real_T WNc;
  real_T d_a;
  real_T rtb_dayOfYear;
  real_T rtb_elevation_mask;
  real_T rtb_removedSats_g;
  real_T s;
  int32_T e_data_0[40];
  int32_T iia_data[40];
  int32_T iidx_data[40];
  int32_T indx_to_isolate_data[40];
  int32_T k_data_2[40];
  int32_T H_size[2];
  int32_T H_size_0[2];
  int32_T P_satellite_fault_size[2];
  int32_T idxPRN_size[2];
  int32_T iidx_size[2];
  int32_T indx_to_exclude_size[2];
  int32_T k_size[2];
  int32_T rtb_measurementFrequency_Bus__9[2];
  int32_T s_size[2];
  int32_T tmp_size[2];
  int32_T x_size[2];
  int32_T BusSelector_DIMS12_i_tmp_tmp;
  int32_T BusSelector_DIMS18_o_tmp_tmp;
  int32_T BusSelector_DIMS19_a_tmp_tmp;
  int32_T SVID_DIMS1;
  int32_T SVID_DIMS1_0;
  int32_T a__1_size;
  int32_T boffset;
  int32_T c_nz;
  int32_T coffset;
  int32_T i2;
  int32_T iter;
  int32_T kAcol;
  int32_T nz;
  int32_T o_size_idx_0;
  int32_T p_size_idx_0;
  int32_T partialTrueCount;
  int32_T tmp_3;
  int32_T tmp_4;
  int32_T tmp_5;
  int32_T tmp_6;
  int32_T tmp_7;
  int32_T tmp_8;
  int32_T trueCount;
  int32_T vlen;
  real32_T rtb_measurementFrequency_Bus_lo[40];
  real32_T tmp_data[40];
  uint16_T PRNsE1E5_data[40];
  uint16_T PRNsE1E5aE1E5b_intersect_data[40];
  uint16_T PRNsE1E5a_data[40];
  uint16_T a__1_data[40];
  uint16_T tmp_data_3[40];
  uint16_T tmp_data_4[40];
  uint16_T rtb_nan_errCnt;
  int8_T ab_data[40];
  int8_T b_data_0[40];
  int8_T bb_data[40];
  int8_T c_data_0[40];
  int8_T cb_data[40];
  int8_T d_data_0[40];
  int8_T db_data[40];
  int8_T e_data[40];
  int8_T f_data[40];
  int8_T f_data_0[40];
  int8_T g_data[40];
  int8_T h_data[40];
  int8_T h_data_0[40];
  int8_T hb_data[40];
  int8_T i_data[40];
  int8_T i_data_0[40];
  int8_T ib_data[40];
  int8_T j_data[40];
  int8_T j_data_0[40];
  int8_T j_data_1[40];
  int8_T jb_data[40];
  int8_T k_data[40];
  int8_T k_data_0[40];
  int8_T k_data_1[40];
  int8_T kb_data[40];
  int8_T l_data[40];
  int8_T l_data_0[40];
  int8_T l_data_1[40];
  int8_T lb_data[40];
  int8_T m_data[40];
  int8_T m_data_0[40];
  int8_T m_data_1[40];
  int8_T mb_data[40];
  int8_T n_data[40];
  int8_T n_data_0[40];
  int8_T n_data_1[40];
  int8_T nb_data[40];
  int8_T o_data[40];
  int8_T o_data_0[40];
  int8_T o_data_1[40];
  int8_T ob_data[40];
  int8_T p_data[40];
  int8_T p_data_0[40];
  int8_T p_data_1[40];
  int8_T p_data_2[40];
  int8_T pb_data[40];
  int8_T q_data[40];
  int8_T q_data_0[40];
  int8_T q_data_1[40];
  int8_T r_data[40];
  int8_T r_data_0[40];
  int8_T s_data[40];
  int8_T s_data_0[40];
  int8_T t_data[40];
  int8_T u_data[40];
  int8_T v_data[40];
  int8_T w_data[40];
  int8_T ii_data[18];
  int8_T ipiv[4];
  int8_T p[4];
  boolean_T c_x_data[200];
  boolean_T rtb_measurementFrequency_Bus__8[120];
  boolean_T b_data[40];
  boolean_T c_data[40];
  boolean_T d_data[40];
  boolean_T mask_all_data[40];
  boolean_T rtb_Add1_data[40];
  boolean_T tmp_data_0[40];
  boolean_T tmp_data_1[40];
  boolean_T x_0[18];
  boolean_T x[4];
  boolean_T exitg1;
  boolean_T rtb_FixPtRelationalOperator;
  boolean_T rtb_MeasurementCorrected;
  boolean_T rtb_enableDualFrequencyCorrecti;
  boolean_T rtb_enableKlobucharCorrection;
  boolean_T rtb_enable_SatPosVel_calculatio;
  boolean_T rtb_enable_WL_correction;
  boolean_T rtb_enable_differential_correct;
  boolean_T rtb_enable_galileo;
  boolean_T rtb_enable_galileo_e1;
  boolean_T rtb_enable_galileo_e5;
  boolean_T rtb_enable_galileo_e5a;
  boolean_T rtb_enable_galileo_e5b;
  boolean_T rtb_enable_gps_l1;
  boolean_T rtb_enable_gps_l2;
  boolean_T rtb_enable_ionospheric_correcti;
  boolean_T rtb_enable_tropospheric_correct;
  boolean_T rtb_use_measured_variance;

  // MATLAB Function: '<S3>/GNSS Measurement Epoch Splitter' incorporates:
  //   Inport: '<Root>/MeasurementEpochBus'

  GN_GNSSMeasurementEpochSplitter
    (&GNSSPreProcessingSingleAntenn_U.MeasurementEpochBus, &WNc, &TOW,
     &GNSSPreProcessingSingleAntenn_B.GpsMeasurementBus,
     &GNSSPreProcessingSingleAntenn_B.GalMeasurementBus);

  // MATLAB Function: '<S3>/Calculate Day of Year'
  GNSSPreProce_CalculateDayofYear(WNc, TOW, &rtb_dayOfYear,
    &GNSSPreProcessingSingleAnten_DW.sf_CalculateDayofYear);

  // MATLAB Function: '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus' 
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.satellite_position[0] = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.satellite_position[1] = 3;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.satellite_velocity[0] = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.satellite_velocity[1] = 3;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.pseudorange = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.pseudorange_raw = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.pseudorange_satclk_corrected
    = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.deltarange = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.deltarange_raw = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.deltarange_satclk_corrected
    = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.variance_pseudorange = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.variance_pseudorange_measured
    = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.variance_deltarange = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.carrierphase = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.carrierphase_raw = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.carrierphase_satclk_corrected
    = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.variance_carrierphase_measured
    = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.PRN = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.locktime = 40;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hhl.CN0 = 40;

  // MATLAB Function: '<S3>/MATLAB Function' incorporates:
  //   Inport: '<Root>/RTCM_3_3_L1_E1_Bus'
  //   MATLAB Function: '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'

  GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.time_receive =
    GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.TOW;
  trueCount = 0;
  for (coffset = 0; coffset < 40; coffset++) {
    // MATLAB Function: '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus' incorporates:
    //   Inport: '<Root>/RTCM_3_3_L1_E1_Bus'

    rtb_nan_errCnt =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.SVID[coffset];
    tmp_data[coffset] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.locktime[coffset];

    // MATLAB Function: '<S3>/MATLAB Function' incorporates:
    //   MATLAB Function: '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'

    rtb_MeasurementCorrected = (rtb_nan_errCnt >= 1);
    rtb_FixPtRelationalOperator = (rtb_nan_errCnt <= 37);
    d_data[coffset] = (rtb_nan_errCnt >= 71);
    mask_all_data[coffset] = (rtb_nan_errCnt <= 106);
    if (rtb_MeasurementCorrected && rtb_FixPtRelationalOperator) {
      trueCount++;
    }

    // MATLAB Function: '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus' 
    a__1_data[coffset] = rtb_nan_errCnt;

    // MATLAB Function: '<S3>/MATLAB Function' incorporates:
    //   MATLAB Function: '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'

    b_data[coffset] = rtb_MeasurementCorrected;
    c_data[coffset] = rtb_FixPtRelationalOperator;
  }

  // MATLAB Function: '<S3>/MATLAB Function' incorporates:
  //   Inport: '<Root>/RTCM_3_3_L1_E1_Bus'
  //   MATLAB Function: '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.satellite_position[0] =
    trueCount;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.satellite_position[1] = 1;
  if (trueCount - 1 >= 0) {
    std::memset
      (&GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.satellite_position[0], 0,
       static_cast<uint32_T>(trueCount) * sizeof(real_T));
  }

  vlen = 0;
  for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
    if (b_data[partialTrueCount] && c_data[partialTrueCount]) {
      vlen++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.satellite_velocity[0] = vlen;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.satellite_velocity[1] = 1;
  if (vlen - 1 >= 0) {
    std::memset
      (&GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.satellite_velocity[0], 0,
       static_cast<uint32_T>(vlen) * sizeof(real_T));
  }

  kAcol = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (b_data[trueCount] && c_data[trueCount]) {
      kAcol++;
    }
  }

  nz = kAcol;
  kAcol = 0;
  for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
    if (b_data[partialTrueCount] && c_data[partialTrueCount]) {
      h_data[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
      kAcol++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.PRN = nz;
  for (vlen = 0; vlen < nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.PRN[vlen] =
      a__1_data[h_data[vlen] - 1];
  }

  kAcol = 0;
  for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
    if (b_data[partialTrueCount] && c_data[partialTrueCount]) {
      kAcol++;
    }
  }

  nz = kAcol;
  kAcol = 0;
  for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
    if (b_data[partialTrueCount] && c_data[partialTrueCount]) {
      i_data[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
      kAcol++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.pseudorange = nz;
  for (vlen = 0; vlen < nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.pseudorange[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Pseudorange[i_data[vlen]
      - 1];
  }

  kAcol = 0;
  for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
    if (b_data[partialTrueCount] && c_data[partialTrueCount]) {
      kAcol++;
    }
  }

  i2 = kAcol;
  kAcol = 0;
  for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
    if (b_data[partialTrueCount] && c_data[partialTrueCount]) {
      j_data[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
      kAcol++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.pseudorange_raw = i2;
  for (vlen = 0; vlen < i2; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.pseudorange_raw[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Pseudorange[j_data[vlen]
      - 1];
  }

  vlen = 0;
  for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
    if (b_data[partialTrueCount] && c_data[partialTrueCount]) {
      vlen++;
    }
  }

  trueCount = 0;
  for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
    if (b_data[partialTrueCount] && c_data[partialTrueCount]) {
      k_data[trueCount] = static_cast<int8_T>(partialTrueCount + 1);
      trueCount++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.pseudorange_satclk_corrected
    = vlen;
  c_nz = vlen;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.pseudorange_satclk_corrected[
      vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Pseudorange[k_data[vlen]
      - 1];
  }

  kAcol = 0;
  for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
    if (b_data[partialTrueCount] && c_data[partialTrueCount]) {
      kAcol++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.deltarange = kAcol;
  if (kAcol - 1 >= 0) {
    std::memset(&GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.deltarange[0],
                0, static_cast<uint32_T>(kAcol) * sizeof(real_T));
  }

  partialTrueCount = 0;
  for (vlen = 0; vlen < 40; vlen++) {
    if (b_data[vlen] && c_data[vlen]) {
      partialTrueCount++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.deltarange_raw =
    partialTrueCount;
  if (partialTrueCount - 1 >= 0) {
    std::memset(&GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.deltarange_raw
                [0], 0, static_cast<uint32_T>(partialTrueCount) * sizeof(real_T));
  }

  nz = 0;
  for (vlen = 0; vlen < 40; vlen++) {
    if (b_data[vlen] && c_data[vlen]) {
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.deltarange_satclk_corrected =
    nz;
  if (nz - 1 >= 0) {
    std::memset
      (&GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.deltarange_satclk_corrected
       [0], 0, static_cast<uint32_T>(nz) * sizeof(real_T));
  }

  nz = 0;
  for (vlen = 0; vlen < 40; vlen++) {
    if (b_data[vlen] && c_data[vlen]) {
      nz++;
    }
  }

  o_size_idx_0 = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      o_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.variance_pseudorange =
    o_size_idx_0;
  for (vlen = 0; vlen < o_size_idx_0; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.variance_pseudorange[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.CN0[o_data[vlen] - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      nz++;
    }
  }

  p_size_idx_0 = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      p_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.variance_pseudorange_measured
    = p_size_idx_0;
  for (vlen = 0; vlen < p_size_idx_0; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.variance_pseudorange_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.CN0[p_data[vlen] - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      q_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.variance_deltarange = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.variance_deltarange[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.CN0[q_data[vlen] - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      r_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.carrierphase = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.carrierphase[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Carrier[r_data[vlen] -
      1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      s_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.carrierphase_raw = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.carrierphase_raw[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Carrier[s_data[vlen] -
      1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      t_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.carrierphase_satclk_corrected
    = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.carrierphase_satclk_corrected
      [vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Carrier[t_data[vlen] -
      1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      u_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.variance_carrierphase_measured
    = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.variance_carrierphase_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.CN0[u_data[vlen] - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      v_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.locktime = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.locktime[vlen] =
      tmp_data[v_data[vlen] - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (b_data[i2] && c_data[i2]) {
      w_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b.CN0 = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.CN0[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.CN0[w_data[vlen] - 1];
  }

  GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.base_position[0] =
    GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.base[0];
  GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.base_position[1] =
    GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.base[1];
  GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.base_position[2] =
    GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.base[2];
  GNSSPreProcessingSingleAntenn_B.GalMeasurementB.time_receive =
    GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.TOW;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.satellite_position[0] = nz;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.satellite_position[1] = 1;
  if (nz - 1 >= 0) {
    std::memset
      (&GNSSPreProcessingSingleAntenn_B.GalMeasurementB.satellite_position[0], 0,
       static_cast<uint32_T>(nz) * sizeof(real_T));
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.satellite_velocity[0] = nz;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.satellite_velocity[1] = 1;
  if (nz - 1 >= 0) {
    std::memset
      (&GNSSPreProcessingSingleAntenn_B.GalMeasurementB.satellite_velocity[0], 0,
       static_cast<uint32_T>(nz) * sizeof(real_T));
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      ab_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.PRN = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.PRN[vlen] =
      a__1_data[ab_data[vlen] - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      bb_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.pseudorange = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.pseudorange[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Pseudorange[bb_data[vlen]
      - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      cb_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.pseudorange_raw = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.pseudorange_raw[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Pseudorange[cb_data[vlen]
      - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      db_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.pseudorange_satclk_corrected =
    c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.pseudorange_satclk_corrected[
      vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Pseudorange[db_data[vlen]
      - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.deltarange = nz;
  if (nz - 1 >= 0) {
    std::memset(&GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange[0],
                0, static_cast<uint32_T>(nz) * sizeof(real_T));
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.deltarange_raw = nz;
  if (nz - 1 >= 0) {
    std::memset(&GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange_raw
                [0], 0, static_cast<uint32_T>(nz) * sizeof(real_T));
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.deltarange_satclk_corrected =
    nz;
  if (nz - 1 >= 0) {
    std::memset
      (&GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange_satclk_corrected
       [0], 0, static_cast<uint32_T>(nz) * sizeof(real_T));
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      hb_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.variance_pseudorange = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_pseudorange[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.CN0[hb_data[vlen] - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      ib_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.variance_pseudorange_measured =
    c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_pseudorange_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.CN0[ib_data[vlen] - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      jb_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.variance_deltarange = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_deltarange[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.CN0[jb_data[vlen] - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      kb_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.carrierphase = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Carrier[kb_data[vlen] -
      1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      lb_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.carrierphase_raw = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase_raw[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Carrier[lb_data[vlen] -
      1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      mb_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.carrierphase_satclk_corrected =
    c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase_satclk_corrected
      [vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.Carrier[mb_data[vlen] -
      1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nb_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.variance_carrierphase_measured
    = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_carrierphase_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.CN0[nb_data[vlen] - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      ob_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.locktime = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.locktime[vlen] =
      tmp_data[ob_data[vlen] - 1];
  }

  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      nz++;
    }
  }

  c_nz = nz;
  nz = 0;
  for (i2 = 0; i2 < 40; i2++) {
    if (d_data[i2] && mask_all_data[i2]) {
      pb_data[nz] = static_cast<int8_T>(i2 + 1);
      nz++;
    }
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3.CN0 = c_nz;
  for (vlen = 0; vlen < c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.CN0[vlen] =
      GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.CN0[pb_data[vlen] - 1];
  }

  GNSSPreProcessingSingleAntenn_B.GalMeasurementB.base_position[0] =
    GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.base[0];
  GNSSPreProcessingSingleAntenn_B.GalMeasurementB.base_position[1] =
    GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.base[1];
  GNSSPreProcessingSingleAntenn_B.GalMeasurementB.base_position[2] =
    GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.base[2];

  // Outputs for Atomic SubSystem: '<S3>/Mode Switch'
  // RelationalOperator: '<S128>/FixPt Relational Operator' incorporates:
  //   Inport: '<Root>/RTCM_3_3_L1_E1_Bus'
  //   MATLAB Function: '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'
  //   UnitDelay: '<S128>/Delay Input1'
  //
  //  Block description for '<S128>/Delay Input1':
  //
  //   Store in Global RAM

  rtb_FixPtRelationalOperator =
    (GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.TOW !=
     GNSSPreProcessingSingleAnten_DW.DelayInput1_DSTATE);

  // DiscreteIntegrator: '<S124>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S124>/Constant1'

  if (rtb_FixPtRelationalOperator &&
      (GNSSPreProcessingSingleAnten_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    GNSSPreProcessingSingleAnten_DW.DiscreteTimeIntegrator_DSTATE =
      GNSSPreProcessingSingleAntenn_P.Constant1_Value;
  }

  // Memory: '<S129>/Memory'
  rtb_MeasurementCorrected =
    GNSSPreProcessingSingleAnten_DW.Memory_PreviousInput;

  // CombinatorialLogic: '<S129>/Logic' incorporates:
  //   Constant: '<S127>/Constant'
  //   DiscreteIntegrator: '<S124>/Discrete-Time Integrator'
  //   Memory: '<S129>/Memory'
  //   RelationalOperator: '<S127>/Compare'

  GNSSPreProcessingSingleAnten_DW.Memory_PreviousInput =
    GNSSPreProcessingSingleAntenn_P.Logic_table[(((static_cast<uint32_T>
    (rtb_FixPtRelationalOperator) << 1) +
    (GNSSPreProcessingSingleAnten_DW.DiscreteTimeIntegrator_DSTATE >
     GNSSPreProcessingSingleAntenn_P.CompareToConstant_const_p)) << 1) +
    GNSSPreProcessingSingleAnten_DW.Memory_PreviousInput];

  // MATLAB Function: '<S16>/Measurement Epoch Splitter' incorporates:
  //   BusCreator generated from: '<S16>/Measurement Epoch Splitter'
  //   Inport: '<Root>/MeasurementEpochBus'

  for (vlen = 0; vlen < 40; vlen++) {
    rtb_MeasurementCorrected =
      (GNSSPreProcessingSingleAntenn_U.MeasurementEpochBus.SVID[vlen] >= 1);
    rtb_enable_gps_l1 =
      (GNSSPreProcessingSingleAntenn_U.MeasurementEpochBus.SVID[vlen] <= 37);
    d_data[vlen] = (rtb_MeasurementCorrected && rtb_enable_gps_l1);
    b_data[vlen] = rtb_MeasurementCorrected;
    c_data[vlen] = rtb_enable_gps_l1;
  }

  nz = d_data[0];
  for (trueCount = 0; trueCount < 39; trueCount++) {
    nz += d_data[trueCount + 1];
  }

  trueCount = 0;
  for (coffset = 0; coffset < 40; coffset++) {
    if (b_data[coffset] && c_data[coffset]) {
      trueCount++;
    }
  }

  partialTrueCount = 0;
  for (coffset = 0; coffset < 40; coffset++) {
    if (b_data[coffset] && c_data[coffset]) {
      f_data[partialTrueCount] = static_cast<int8_T>(coffset + 1);
      partialTrueCount++;
    }
  }

  for (vlen = 0; vlen < trueCount; vlen++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      c_x_data[partialTrueCount + 5 * vlen] =
        (GNSSPreProcessingSingleAntenn_U.MeasurementEpochBus.Type[(f_data[vlen]
          - 1) * 5 + partialTrueCount] == 3);
    }
  }

  if (static_cast<int8_T>(trueCount) - 1 >= 0) {
    std::memset(&b_data[0], 0, static_cast<uint32_T>(static_cast<int8_T>
      (trueCount)) * sizeof(boolean_T));
  }

  i2 = 1;
  for (c_nz = 0; c_nz < trueCount; c_nz++) {
    vlen = i2 + 4;
    coffset = i2;
    i2 += 5;
    exitg1 = false;
    while ((!exitg1) && (coffset <= vlen)) {
      if (c_x_data[coffset - 1]) {
        b_data[c_nz] = true;
        exitg1 = true;
      } else {
        coffset++;
      }
    }
  }

  vlen = static_cast<int8_T>(trueCount);
  if (static_cast<int8_T>(trueCount) == 0) {
    i2 = 0;
  } else {
    i2 = b_data[0];
    for (c_nz = 2; c_nz <= vlen; c_nz++) {
      i2 += b_data[c_nz - 1];
    }
  }

  for (vlen = 0; vlen < 40; vlen++) {
    d_data[vlen] =
      ((GNSSPreProcessingSingleAntenn_U.MeasurementEpochBus.SVID[vlen] >= 71) &&
       (GNSSPreProcessingSingleAntenn_U.MeasurementEpochBus.SVID[vlen] <= 102));
  }

  c_nz = d_data[0];
  for (coffset = 0; coffset < 39; coffset++) {
    c_nz += d_data[coffset + 1];
  }

  // Sum: '<S125>/Sum' incorporates:
  //   MATLAB Function: '<S16>/Measurement Epoch Splitter'

  i2 += c_nz;

  // Chart: '<S125>/choose correction mode' incorporates:
  //   Constant: '<S125>/Constant2'
  //   Constant: '<S125>/Constant3'
  //   Constant: '<S125>/Constant4'
  //   Constant: '<S125>/Constant5'
  //   Constant: '<S125>/Constant6'
  //   Inport: '<Root>/GNSSParametersBus'
  //   MATLAB Function: '<S16>/Measurement Epoch Splitter'

  if (GNSSPreProcessingSingleAnten_DW.temporalCounter_i1 < MAX_uint32_T) {
    GNSSPreProcessingSingleAnten_DW.temporalCounter_i1++;
  }

  if (GNSSPreProcessingSingleAnten_DW.is_active_c130_lib_GNSSPreProce == 0U) {
    GNSSPreProcessingSingleAnten_DW.is_active_c130_lib_GNSSPreProce = 1U;
    GNSSPreProcessingSingleAntenn_B.parameters_gnss =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus;
    GNSSPreProcessingSingleAnten_DW.is_c130_lib_GNSSPreProcessing =
      GNSSPr_IN_GPS_Klobuchar_Galileo;
  } else {
    switch (GNSSPreProcessingSingleAnten_DW.is_c130_lib_GNSSPreProcessing) {
     case GNSSPreProcessingSingle_IN_DGPS:
      switch (GNSSPreProcessingSingleAnten_DW.is_DGPS) {
       case GNSSPreProcessi_IN_DGPS_Galileo:
        if (!GNSSPreProcessingSingleAnten_DW.Memory_PreviousInput) {
          GNSSPreProcessingSingleAnten_DW.is_DGPS =
            GNSSPreProc_IN_waiting_for_RTCM;
          GNSSPreProcessingSingleAnten_DW.temporalCounter_i1 = 0U;
        } else if (nz >= GNSSPreProcessingSingleAntenn_P.Constant3_Value) {
          GNSSPreProcessingSingleAnten_DW.is_DGPS =
            GNSSPreProcessingS_IN_DGPS_only;
        } else {
          // Outport: '<Root>/GPSGALCorrectionMode'
          GNSSPreProcessingSingleAntenn_Y.GPSGALCorrectionMode = 2.0;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps = true;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l1 =
            true;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l2 =
            false;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo
            = true;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_differential_correction
            = true;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_ionospheric_correction
            = false;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_tropospheric_correction
            = false;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e1
            = true;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5
            = true;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5a
            = true;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5b
            = true;
        }
        break;

       case GNSSPreProcessingS_IN_DGPS_only:
        if (!GNSSPreProcessingSingleAnten_DW.Memory_PreviousInput) {
          GNSSPreProcessingSingleAnten_DW.is_DGPS =
            GNSSPreProc_IN_waiting_for_RTCM;
          GNSSPreProcessingSingleAnten_DW.temporalCounter_i1 = 0U;
        } else if ((nz < GNSSPreProcessingSingleAntenn_P.Constant3_Value) && (nz
                    >= GNSSPreProcessingSingleAntenn_P.Constant4_Value)) {
          GNSSPreProcessingSingleAnten_DW.is_DGPS =
            GNSSPre_IN_Waiting_for_more_sat;
          GNSSPreProcessingSingleAnten_DW.temporalCounter_i1 = 0U;
        } else if (nz < GNSSPreProcessingSingleAntenn_P.Constant4_Value) {
          GNSSPreProcessingSingleAnten_DW.is_DGPS =
            GNSSPreProcessi_IN_DGPS_Galileo;
        } else {
          // Outport: '<Root>/GPSGALCorrectionMode'
          GNSSPreProcessingSingleAntenn_Y.GPSGALCorrectionMode = 1.0;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps = true;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l1 =
            true;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l2 =
            false;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo
            = false;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_differential_correction
            = true;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_ionospheric_correction
            = false;
          GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_tropospheric_correction
            = false;
        }
        break;

       case GNSSPre_IN_Waiting_for_more_sat:
        if (nz < GNSSPreProcessingSingleAntenn_P.Constant4_Value) {
          GNSSPreProcessingSingleAnten_DW.is_DGPS =
            GNSSPreProcessi_IN_DGPS_Galileo;
        } else if (nz >= GNSSPreProcessingSingleAntenn_P.Constant3_Value) {
          GNSSPreProcessingSingleAnten_DW.is_DGPS =
            GNSSPreProcessingS_IN_DGPS_only;
        } else if (GNSSPreProcessingSingleAnten_DW.temporalCounter_i1 >=
                   static_cast<uint32_T>(std::ceil
                    (GNSSPreProcessingSingleAntenn_P.Constant2_Value * 10.0))) {
          GNSSPreProcessingSingleAnten_DW.is_DGPS =
            GNSSPreProcessi_IN_DGPS_Galileo;
        } else if (!GNSSPreProcessingSingleAnten_DW.Memory_PreviousInput) {
          GNSSPreProcessingSingleAnten_DW.is_DGPS =
            GNSSPreProc_IN_waiting_for_RTCM;
          GNSSPreProcessingSingleAnten_DW.temporalCounter_i1 = 0U;
        } else {
          // Outport: '<Root>/GPSGALCorrectionMode'
          GNSSPreProcessingSingleAntenn_Y.GPSGALCorrectionMode = 1.5;
        }
        break;

       default:
        // case IN_waiting_for_RTCM:
        if (GNSSPreProcessingSingleAnten_DW.Memory_PreviousInput) {
          GNSSPreProcessingSingleAnten_DW.is_DGPS =
            GNSSPreProcessingS_IN_DGPS_only;
        } else if (GNSSPreProcessingSingleAnten_DW.temporalCounter_i1 >=
                   static_cast<uint32_T>(std::ceil
                    (GNSSPreProcessingSingleAntenn_P.Constant2_Value * 10.0))) {
          GNSSPreProcessingSingleAnten_DW.is_DGPS =
            GNSSPreProce_IN_NO_ACTIVE_CHILD;
          GNSSPreProcessingSingleAnten_DW.is_c130_lib_GNSSPreProcessing =
            GNSSPreProcess_IN_Dualfrequency;
          GNSSPreProcessingSingleAnten_DW.is_Dualfrequency =
            GN_IN_GPS_Dualfrequency_Galileo;
        } else {
          // Outport: '<Root>/GPSGALCorrectionMode'
          GNSSPreProcessingSingleAntenn_Y.GPSGALCorrectionMode = 2.5;
        }
        break;
      }
      break;

     case GNSSPreProcess_IN_Dualfrequency:
      if (GNSSPreProcessingSingleAnten_DW.Memory_PreviousInput) {
        GNSSPreProcessingSingleAnten_DW.is_Dualfrequency =
          GNSSPreProce_IN_NO_ACTIVE_CHILD;
        GNSSPreProcessingSingleAnten_DW.is_c130_lib_GNSSPreProcessing =
          GNSSPreProcessingSingle_IN_DGPS;
        GNSSPreProcessingSingleAnten_DW.is_DGPS =
          GNSSPreProcessingS_IN_DGPS_only;
      } else {
        switch (GNSSPreProcessingSingleAnten_DW.is_Dualfrequency) {
         case GN_IN_GPS_Dualfrequency_Galileo:
          if (i2 < GNSSPreProcessingSingleAntenn_P.Constant6_Value) {
            GNSSPreProcessingSingleAnten_DW.is_Dualfrequency =
              GNSSPreProce_IN_NO_ACTIVE_CHILD;
            GNSSPreProcessingSingleAnten_DW.is_c130_lib_GNSSPreProcessing =
              GNSSPr_IN_GPS_Klobuchar_Galileo;
          } else if ((i2 < GNSSPreProcessingSingleAntenn_P.Constant5_Value) &&
                     (i2 >= GNSSPreProcessingSingleAntenn_P.Constant6_Value)) {
            GNSSPreProcessingSingleAnten_DW.is_Dualfrequency =
              GN_IN_Waiting_for_more_dual_sat;
            GNSSPreProcessingSingleAnten_DW.temporalCounter_i1 = 0U;
          } else {
            // Outport: '<Root>/GPSGALCorrectionMode'
            GNSSPreProcessingSingleAntenn_Y.GPSGALCorrectionMode = 3.0;
            GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps =
              true;
            GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo
              = true;
            GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_differential_correction
              = false;
            GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l1 =
              true;
            GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l2 =
              true;
            GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_ionospheric_correction
              = true;
            GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_tropospheric_correction
              = true;
            GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e1
              = true;
            GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5
              = true;
            GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5a
              = true;
            GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5b
              = true;
          }
          break;

         default:
          // case IN_Waiting_for_more_dual_sat:
          if (i2 >= GNSSPreProcessingSingleAntenn_P.Constant5_Value) {
            GNSSPreProcessingSingleAnten_DW.is_Dualfrequency =
              GN_IN_GPS_Dualfrequency_Galileo;
          } else if ((i2 < GNSSPreProcessingSingleAntenn_P.Constant6_Value) ||
                     (GNSSPreProcessingSingleAnten_DW.temporalCounter_i1 >=
                      static_cast<uint32_T>(std::ceil
                       (GNSSPreProcessingSingleAntenn_P.Constant2_Value * 10.0))))
          {
            GNSSPreProcessingSingleAnten_DW.is_Dualfrequency =
              GNSSPreProce_IN_NO_ACTIVE_CHILD;
            GNSSPreProcessingSingleAnten_DW.is_c130_lib_GNSSPreProcessing =
              GNSSPr_IN_GPS_Klobuchar_Galileo;
          } else {
            // Outport: '<Root>/GPSGALCorrectionMode'
            GNSSPreProcessingSingleAntenn_Y.GPSGALCorrectionMode = 3.5;
          }
          break;
        }
      }
      break;

     default:
      // case IN_GPS_Klobuchar_Galileo:
      if (i2 >= GNSSPreProcessingSingleAntenn_P.Constant5_Value) {
        GNSSPreProcessingSingleAnten_DW.is_c130_lib_GNSSPreProcessing =
          GNSSPreProcess_IN_Dualfrequency;
        GNSSPreProcessingSingleAnten_DW.is_Dualfrequency =
          GN_IN_GPS_Dualfrequency_Galileo;
      } else if (GNSSPreProcessingSingleAnten_DW.Memory_PreviousInput) {
        GNSSPreProcessingSingleAnten_DW.is_c130_lib_GNSSPreProcessing =
          GNSSPreProcessingSingle_IN_DGPS;
        GNSSPreProcessingSingleAnten_DW.is_DGPS =
          GNSSPreProcessingS_IN_DGPS_only;
      } else {
        // Outport: '<Root>/GPSGALCorrectionMode'
        GNSSPreProcessingSingleAntenn_Y.GPSGALCorrectionMode = 4.0;
        GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps = true;
        GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo =
          true;
        GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l1 = true;
        GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l2 =
          false;
        GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_differential_correction
          = false;
        GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_ionospheric_correction
          = true;
        GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_tropospheric_correction
          = true;
        GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e1
          = true;
        GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5
          = true;
        GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5a
          = true;
        GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5b
          = true;
      }
      break;
    }
  }

  // End of Chart: '<S125>/choose correction mode'

  // Update for UnitDelay: '<S128>/Delay Input1' incorporates:
  //   Inport: '<Root>/RTCM_3_3_L1_E1_Bus'
  //   MATLAB Function: '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'
  //
  //  Block description for '<S128>/Delay Input1':
  //
  //   Store in Global RAM

  GNSSPreProcessingSingleAnten_DW.DelayInput1_DSTATE =
    GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.TOW;

  // Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S124>/Constant'

  GNSSPreProcessingSingleAnten_DW.DiscreteTimeIntegrator_DSTATE +=
    GNSSPreProcessingSingleAntenn_P.DiscreteTimeIntegrator_gainval *
    GNSSPreProcessingSingleAntenn_P.Constant_Value;
  GNSSPreProcessingSingleAnten_DW.DiscreteTimeIntegrator_PrevRese = static_cast<
    int8_T>(rtb_FixPtRelationalOperator);

  // End of Outputs for SubSystem: '<S3>/Mode Switch'

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_1_Threshold) {
    rtb_FixPtRelationalOperator =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps;
  } else {
    rtb_FixPtRelationalOperator =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gps.enable_gps;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_2_Threshold) {
    rtb_enable_gps_l1 =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l1;
  } else {
    rtb_enable_gps_l1 =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gps.enable_gps_l1;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_3_Threshold) {
    rtb_enable_gps_l2 =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l2;
  } else {
    rtb_enable_gps_l2 =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gps.enable_gps_l2;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_4_Threshold) {
    rtb_enable_galileo =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo;
  } else {
    rtb_enable_galileo =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.galileo.enable_galileo;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_5_Threshold) {
    rtb_enable_galileo_e1 =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e1;
  } else {
    rtb_enable_galileo_e1 =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.galileo.enable_galileo_e1;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_6_Threshold) {
    rtb_enable_galileo_e5a =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5a;
  } else {
    rtb_enable_galileo_e5a =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.galileo.enable_galileo_e5a;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_7_Threshold) {
    rtb_enable_galileo_e5b =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5b;
  } else {
    rtb_enable_galileo_e5b =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.galileo.enable_galileo_e5b;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_8_Threshold) {
    rtb_enable_galileo_e5 =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5;
  } else {
    rtb_enable_galileo_e5 =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.galileo.enable_galileo_e5;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_19_Threshold) {
    rtb_elevation_mask =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.elevation_mask;
  } else {
    rtb_elevation_mask =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.elevation_mask;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_21_Threshold) {
    rtb_enable_differential_correct =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_differential_correction;
  } else {
    rtb_enable_differential_correct =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.enable_differential_correction;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_22_Threshold) {
    rtb_enable_tropospheric_correct =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_tropospheric_correction;
  } else {
    rtb_enable_tropospheric_correct =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.enable_tropospheric_correction;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_23_Threshold) {
    rtb_enable_ionospheric_correcti =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_ionospheric_correction;
  } else {
    rtb_enable_ionospheric_correcti =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.enable_ionospheric_correction;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_24_Threshold) {
    rtb_enable_SatPosVel_calculatio =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_SatPosVel_calculation;
  } else {
    rtb_enable_SatPosVel_calculatio =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.enable_SatPosVel_calculation;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_25_Threshold) {
    rtb_enable_WL_correction =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_WL_correction;
  } else {
    rtb_enable_WL_correction =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.enable_WL_correction;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_26_Threshold) {
    rtb_use_measured_variance =
      GNSSPreProcessingSingleAntenn_B.parameters_gnss.use_measured_variance;
  } else {
    rtb_use_measured_variance =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.use_measured_variance;
  }

  // Outputs for Enabled SubSystem: '<S3>/GPS' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (rtb_FixPtRelationalOperator) {
    boolean_T rtb_LogicalOperator2_n;

    // MATLAB Function: '<S11>/Navigation Data Conversion GPS' incorporates:
    //   Inport: '<Root>/GPSNavBus'

    GNS_NavigationDataConversionGPS(&GNSSPreProcessingSingleAntenn_U.GPSNavBus,
      &GNSSPreProcessingSingleAntenn_B.sf_NavigationDataConversionGPS,
      &GNSSPreProcessingSingleAnten_DW.sf_NavigationDataConversionGPS);

    // MATLAB Function: '<S21>/MATLAB Function1' incorporates:
    //   BusCreator generated from: '<S21>/MATLAB Function1'
    //   Constant: '<S11>/L5_basedProcessing'

    if (!GNSSPreProcessingSingleAntenn_P.L5_basedProcessing_Value) {
      rtb_parameters_gps_Bus.enable_gps = true;
      rtb_parameters_gps_Bus.enable_gps_l1 = true;
      rtb_parameters_gps_Bus.enable_gps_l2 = rtb_enable_gps_l2;
    } else {
      rtb_parameters_gps_Bus.enable_gps = true;
      rtb_parameters_gps_Bus.enable_gps_l1 = false;
      rtb_parameters_gps_Bus.enable_gps_l2 = rtb_enable_gps_l2;
    }

    // End of MATLAB Function: '<S21>/MATLAB Function1'

    // MATLAB Function: '<S11>/Simplify and Mask GPS Measurement Bus'
    SimplifyandMaskGPSMeasurementBu
      (&GNSSPreProcessingSingleAntenn_B.GpsMeasurementBus,
       &GNSSPreProcessingSingleAntenn_B.sf_NavigationDataConversionGPS.GpsNavBusReshaped,
       &GNSSPreProcessingSingleAnten_DW.sf_NavigationDataConversionGPS.SFunction_DIMS2,
       &rtb_parameters_gps_Bus,
       &GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen);

    // MATLAB Function: '<S23>/Calculate Differential Corrections' incorporates:
    //   Inport: '<Root>/usePosLLHArray'

    CalculateDifferentialCorrection
      (&GNSSPreProcessingSingleAntenn_B.GpsMeasurementB,
       &GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b,
       &GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.navdata_L1,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS4,
       GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
       &GNSSPreProcessingSingleAntenn_B.sf_CalculateDifferentialCorrect,
       &GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorrect);

    // Outputs for Enabled SubSystem: '<S11>/GPS L2C Stream'
    // Outputs for Enabled SubSystem: '<S11>/GPS L2C Stream'
    // SignalConversion generated from: '<S19>/Enable' incorporates:
    //   Constant: '<S11>/Base Position Dummy'
    //   Inport: '<Root>/usePosLLHArray'

    GNSSPr_GPSsinglefrequencystream(rtb_parameters_gps_Bus.enable_gps_l2,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.TOW,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.svid_L2C,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS12,
      &GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.navdata_L2C,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS13,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.pr_L2C,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS14,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.dr_L2C,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS16,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.cn0_L2C,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS17,
      GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.cp_L2C,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS18,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.Locktime_L2C,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS20,
      GNSSPreProcessingSingleAntenn_P.BasePositionDummy_Value,
      rtb_enable_SatPosVel_calculatio, rtb_use_measured_variance,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.pr_sigma_L2C,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS15,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.cp_sigma_L2C,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS19,
      GNSSPreProcessingSingleAntenn_P.GPSL2CStream_enable_SatClockCor,
      &GNSSPreProcessingSingleAntenn_B.GPSL2CStream,
      &GNSSPreProcessingSingleAnten_DW.GPSL2CStream,
      &GNSSPreProcessingSingleAntenn_P.GPSL2CStream);

    // End of Outputs for SubSystem: '<S11>/GPS L2C Stream'
    // End of Outputs for SubSystem: '<S11>/GPS L2C Stream'

    // BusCreator generated from: '<S51>/Calculate Dualfrequency Correction with L1 and L2C' incorporates:
    //   SignalConversion generated from: '<S19>/SVID'

    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.satellite_position
      [0] =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.satellite_position
      [1] =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.satellite_velocity
      [0] =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.satellite_velocity
      [1] =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.PRN =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.SVID_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.pseudorange =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.pseudorange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS14;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.deltarange =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.deltarange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS16;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.deltarange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.variance_pseudorange
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_SignalNoiseVariance.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.variance_pseudorange_measured
      = GNSSPreProcessingSingleAnten_DW.GPSL2CStream.pr_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.variance_deltarange
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_SignalNoiseVariance.SFunction_DIMS3;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.carrierphase
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.carrierphase_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS18;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.variance_carrierphase_measured
      = GNSSPreProcessingSingleAnten_DW.GPSL2CStream.cp_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.locktime =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.locktime_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p.CN0 =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.carrierToNoiseRatio_DIMS1;
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.time_receive =
      GNSSPreProcessingSingleAntenn_B.GPSL2CStream.timeOfWeekIn;
    c_nz =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0] *
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.satellite_position[0],
         &GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_CalculateSatellitePositionan.satPosEcef
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    c_nz =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0] *
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.satellite_velocity[0],
         &GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_CalculateSatellitePositionan.satVelEcef
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.SVID_DIMS1; vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.PRN[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL2CStream.PRN[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.pseudorange[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS14;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.pseudorange_raw[vlen] =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.pr_L2C[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.pseudorange_satclk_corrected
        [vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.deltarange[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_TimeCorrectionDeltarange.deltarangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS16;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.deltarange_raw[vlen] =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.dr_L2C[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.deltarange_satclk_corrected
        [vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_TimeCorrectionDeltarange.deltarangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_SignalNoiseVariance.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.variance_pseudorange[vlen]
        =
        GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_SignalNoiseVariance.variancePseudorange
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.pr_sigma_DIMS1; vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.variance_pseudorange_measured
        [vlen] = GNSSPreProcessingSingleAntenn_B.GPSL2CStream.pr_sigma[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_SignalNoiseVariance.SFunction_DIMS3;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.variance_deltarange[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_SignalNoiseVariance.varianceDeltarange
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.carrierphase[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS18;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.carrierphase_raw[vlen] =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.cp_L2C[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.carrierphase_satclk_corrected
        [vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.cp_sigma_DIMS1; vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.variance_carrierphase_measured
        [vlen] = GNSSPreProcessingSingleAntenn_B.GPSL2CStream.cp_sigma[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.locktime_DIMS1; vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.locktime[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL2CStream.Locktime[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL2CStream.carrierToNoiseRatio_DIMS1;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.CN0[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL2CStream.carrierToNoiseRatio[vlen];
    }

    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.base_position[0] =
      GNSSPreProcessingSingleAntenn_B.GPSL2CStream.base_position[0];
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.base_position[1] =
      GNSSPreProcessingSingleAntenn_B.GPSL2CStream.base_position[1];
    GNSSPreProcessingSingleAntenn_B.GpsMeasurementB.base_position[2] =
      GNSSPreProcessingSingleAntenn_B.GPSL2CStream.base_position[2];

    // Outputs for Enabled SubSystem: '<S11>/GPS L5 Stream'
    // Outputs for Enabled SubSystem: '<S11>/GPS L5 Stream'
    // Constant: '<S11>/Add Trigger Here' incorporates:
    //   Constant: '<S11>/Base Position Dummy'
    //   Inport: '<Root>/usePosLLHArray'

    GNSSPr_GPSsinglefrequencystream
      (GNSSPreProcessingSingleAntenn_P.AddTriggerHere_Value,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.TOW,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.svid_L5,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS21,
       &GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.navdata_L5,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS22,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.pr_L5,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS23,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.dr_L5,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS25,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.cn0_L5,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS26,
       GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.cp_sigma_L5,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS28,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.Locktime_L5,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS29,
       GNSSPreProcessingSingleAntenn_P.BasePositionDummy_Value,
       rtb_enable_SatPosVel_calculatio, rtb_use_measured_variance,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.pr_sigma_L5,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS24,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.cp_L5,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS27,
       GNSSPreProcessingSingleAntenn_P.GPSL5Stream_enable_SatClockCorr,
       &GNSSPreProcessingSingleAntenn_B.GPSL5Stream,
       &GNSSPreProcessingSingleAnten_DW.GPSL5Stream,
       &GNSSPreProcessingSingleAntenn_P.GPSL5Stream);

    // End of Outputs for SubSystem: '<S11>/GPS L5 Stream'
    // End of Outputs for SubSystem: '<S11>/GPS L5 Stream'

    // BusCreator generated from: '<S51>/Calculate Dualfrequency Correction with L1 and L2C' 
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.satellite_position
      [0] =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.satellite_position
      [1] =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.satellite_velocity
      [0] =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.satellite_velocity
      [1] =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.PRN =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.SVID_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.pseudorange =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.pseudorange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS23;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.deltarange =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.deltarange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS25;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.deltarange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.variance_pseudorange
      =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_SignalNoiseVariance.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.variance_pseudorange_measured
      = GNSSPreProcessingSingleAnten_DW.GPSL5Stream.pr_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.variance_deltarange
      =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_SignalNoiseVariance.SFunction_DIMS3;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.carrierphase
      =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.carrierphase_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS28;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.variance_carrierphase_measured
      = GNSSPreProcessingSingleAnten_DW.GPSL5Stream.cp_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.locktime =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.locktime_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_m.CN0 =
      GNSSPreProcessingSingleAnten_DW.GPSL5Stream.carrierToNoiseRatio_DIMS1;

    // MATLAB Function: '<S51>/MATLAB Function' incorporates:
    //   BusCreator generated from: '<S51>/MATLAB Function'

    rtb_enableDualFrequencyCorrecti = false;
    rtb_enableKlobucharCorrection = false;
    if (!rtb_enable_differential_correct) {
      rtb_MeasurementCorrected = !rtb_enable_gps_l2;
      if (rtb_enable_gps_l1 && rtb_MeasurementCorrected &&
          rtb_enable_ionospheric_correcti) {
        rtb_enableKlobucharCorrection = true;
      } else if (rtb_enable_gps_l1 && (!rtb_MeasurementCorrected) &&
                 rtb_enable_ionospheric_correcti) {
        rtb_enableDualFrequencyCorrecti = true;
      }
    }

    // End of MATLAB Function: '<S51>/MATLAB Function'

    // Outputs for Enabled SubSystem: '<S11>/GPS L1 Stream'
    // Outputs for Enabled SubSystem: '<S11>/GPS L1 Stream'
    // SignalConversion generated from: '<S18>/Enable' incorporates:
    //   Constant: '<S11>/Base Position Dummy'
    //   Inport: '<Root>/usePosLLHArray'

    GNSSPr_GPSsinglefrequencystream(rtb_parameters_gps_Bus.enable_gps_l1,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.TOW,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.svid_L1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS3,
      &GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.navdata_L1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS4,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.pr_L1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS5,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.dr_L1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS7,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.cn0_L1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS8,
      GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.cp_L1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS9,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.Locktime_L1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS11,
      GNSSPreProcessingSingleAntenn_P.BasePositionDummy_Value,
      rtb_enable_SatPosVel_calculatio, rtb_use_measured_variance,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.pr_sigma_L1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS6,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.cp_sigma_L1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS10,
      GNSSPreProcessingSingleAntenn_P.GPSL1Stream_enable_SatClockCorr,
      &GNSSPreProcessingSingleAntenn_B.GPSL1Stream,
      &GNSSPreProcessingSingleAnten_DW.GPSL1Stream,
      &GNSSPreProcessingSingleAntenn_P.GPSL1Stream);

    // End of Outputs for SubSystem: '<S11>/GPS L1 Stream'
    // End of Outputs for SubSystem: '<S11>/GPS L1 Stream'

    // BusCreator generated from: '<S51>/Calculate Wide Lane Combination' incorporates:
    //   MATLAB Function: '<S51>/Calculate Wide Lane Combination'
    //   SignalConversion generated from: '<S18>/SVID'

    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.satellite_position
      [0] =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.satellite_position
      [1] =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.satellite_velocity
      [0] =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.satellite_velocity
      [1] =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.PRN =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.SVID_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.pseudorange =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.pseudorange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS5;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.deltarange =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.deltarange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS7;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.deltarange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.variance_pseudorange
      =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_SignalNoiseVariance.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.variance_pseudorange_measured
      = GNSSPreProcessingSingleAnten_DW.GPSL1Stream.pr_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.variance_deltarange
      =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_SignalNoiseVariance.SFunction_DIMS3;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.carrierphase
      =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.carrierphase_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS9;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.variance_carrierphase_measured
      = GNSSPreProcessingSingleAnten_DW.GPSL1Stream.cp_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.locktime =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.locktime_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.CN0 =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.carrierToNoiseRatio_DIMS1;
    c_nz =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0] *
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.satellite_position[
         0],
         &GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_CalculateSatellitePositionan.satPosEcef
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    c_nz =
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0] *
      GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.satellite_velocity[
         0],
         &GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_CalculateSatellitePositionan.satVelEcef
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.GPSL1Stream.SVID_DIMS1;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.PRN[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.PRN[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.pseudorange[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS5;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.pseudorange_raw[vlen] =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.pr_L1[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.pseudorange_satclk_corrected
        [vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.deltarange[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_TimeCorrectionDeltarange.deltarangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS7;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.deltarange_raw[vlen] =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.dr_L1[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.deltarange_satclk_corrected
        [vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_TimeCorrectionDeltarange.deltarangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_SignalNoiseVariance.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.variance_pseudorange[vlen]
        =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_SignalNoiseVariance.variancePseudorange
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.pr_sigma_DIMS1; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.variance_pseudorange_measured
        [vlen] = GNSSPreProcessingSingleAntenn_B.GPSL1Stream.pr_sigma[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_SignalNoiseVariance.SFunction_DIMS3;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.variance_deltarange[vlen]
        =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_SignalNoiseVariance.varianceDeltarange
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.carrierphase[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS9;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.carrierphase_raw[vlen]
        =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGPSMeasuremen.cp_L1[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.carrierphase_satclk_corrected
        [vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.cp_sigma_DIMS1; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.variance_carrierphase_measured
        [vlen] = GNSSPreProcessingSingleAntenn_B.GPSL1Stream.cp_sigma[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.locktime_DIMS1; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.locktime[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.Locktime[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GPSL1Stream.carrierToNoiseRatio_DIMS1;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.CN0[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.carrierToNoiseRatio[vlen];
    }

    // BusCreator generated from: '<S51>/Calculate Wide Lane Combination'
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.satellite_position
      [0] =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.satellite_position
      [1] =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.satellite_velocity
      [0] =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.satellite_velocity
      [1] =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.PRN =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.SVID_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.pseudorange =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.pseudorange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS14;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.deltarange =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.deltarange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS16;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.deltarange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.variance_pseudorange
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_SignalNoiseVariance.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.variance_pseudorange_measured
      = GNSSPreProcessingSingleAnten_DW.GPSL2CStream.pr_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.variance_deltarange
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_SignalNoiseVariance.SFunction_DIMS3;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.carrierphase
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.carrierphase_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGPSMeasuremen.SFunction_DIMS18;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.variance_carrierphase_measured
      = GNSSPreProcessingSingleAnten_DW.GPSL2CStream.cp_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.locktime =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.locktime_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Ca_kn.CN0 =
      GNSSPreProcessingSingleAnten_DW.GPSL2CStream.carrierToNoiseRatio_DIMS1;

    // MATLAB Function: '<S51>/Calculate Wide Lane Combination' incorporates:
    //   BusCreator generated from: '<S51>/Calculate Wide Lane Combination'
    //   SignalConversion generated from: '<S18>/SVID'
    //   SignalConversion generated from: '<S19>/SVID'

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3_o =
      GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d;
    GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.time_receive =
      GNSSPreProcessingSingleAntenn_B.GPSL1Stream.timeOfWeekIn;
    GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.base_position[0] =
      GNSSPreProcessingSingleAntenn_B.GPSL1Stream.base_position[0];
    GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.base_position[1] =
      GNSSPreProcessingSingleAntenn_B.GPSL1Stream.base_position[1];
    GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.base_position[2] =
      GNSSPreProcessingSingleAntenn_B.GPSL1Stream.base_position[2];
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_ho =
      GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.PRN;
    for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.GPSL1Stream.SVID_DIMS1;
         vlen++) {
      GNSSPreProcessingSingleAntenn_B.SvidCarrierInUse[vlen] =
        GNSSPreProcessingSingleAntenn_B.GPSL1Stream.PRN[vlen];
    }

    if (rtb_enable_WL_correction) {
      SVID_DIMS1 = GNSSPreProcessingSingleAnten_DW.GPSL1Stream.SVID_DIMS1;
      SVID_DIMS1_0 = GNSSPreProcessingSingleAnten_DW.GPSL2CStream.SVID_DIMS1;
      GNSSPreProcessing_do_vectors_ig
        (GNSSPreProcessingSingleAntenn_B.GPSL1Stream.PRN, &SVID_DIMS1,
         GNSSPreProcessingSingleAntenn_B.GPSL2CStream.PRN, &SVID_DIMS1_0,
         a__1_data, &a__1_size, iia_data, &p_size_idx_0, indx_to_isolate_data,
         &i2);
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_ho = a__1_size;
      if (a__1_size - 1 >= 0) {
        std::memcpy(&GNSSPreProcessingSingleAntenn_B.SvidCarrierInUse[0],
                    &a__1_data[0], static_cast<uint32_T>(a__1_size) * sizeof
                    (uint16_T));
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3_o.carrierphase =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_d.carrierphase;
      boffset =
        (GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2
         / 2) << 1;
      kAcol = boffset - 2;
      for (vlen = 0; vlen <= kAcol; vlen += 2) {
        tmp_2 = _mm_loadu_pd
          (&GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
           [vlen]);
        _mm_storeu_pd
          (&GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.carrierphase[vlen],
           _mm_div_pd(_mm_mul_pd(tmp_2, _mm_set1_pd(0.19029367279836487)),
                      _mm_set1_pd(0.86191840032200562)));
      }

      for (vlen = boffset; vlen <
           GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.carrierphase[vlen] =
          GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
          [vlen] * 0.19029367279836487 / 0.86191840032200562;
      }

      if (p_size_idx_0 == i2) {
        for (vlen = 0; vlen < p_size_idx_0; vlen++) {
          nz = iia_data[vlen];
          GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.carrierphase[nz -
            1] =
            GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
            [nz - 1] -
            GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
            [indx_to_isolate_data[vlen] - 1];
        }
      } else {
        GNSSPrePr_binary_expand_op_fr3p
          (&GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL, iia_data,
           &p_size_idx_0,
           GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected,
           GNSSPreProcessingSingleAntenn_B.GPSL2CStream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected,
           indx_to_isolate_data, &i2);
      }
    }

    // MATLAB Function: '<S51>/Calculate Dualfrequency Correction with L1 and L2C' 
    CalculateDualfrequencyCorrectio
      (&GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL,
       &GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3_o,
       &GNSSPreProcessingSingleAntenn_B.GpsMeasurementB,
       &GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_p,
       rtb_enableDualFrequencyCorrecti,
       &GNSSPreProcessingSingleAntenn_B.sf_CalculateDualfrequencyCorrec,
       &GNSSPreProcessingSingleAnten_DW.sf_CalculateDualfrequencyCorrec);

    // MATLAB Function: '<S54>/Create Satellite Elevation Mask' incorporates:
    //   Constant: '<S53>/Constant'
    //   Inport: '<Root>/usePosLLHArray'
    //   Logic: '<S23>/Logical Operator2'
    //   RelationalOperator: '<S53>/Compare'

    GN_CreateSatelliteElevationMask
      (GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
       (GNSSPreProcessingSingleAntenn_U.usePosLLHArray[0] !=
        GNSSPreProcessingSingleAntenn_P.CompareToConstant1_const) &&
       (GNSSPreProcessingSingleAntenn_U.usePosLLHArray[1] !=
        GNSSPreProcessingSingleAntenn_P.CompareToConstant1_const) &&
       (GNSSPreProcessingSingleAntenn_U.usePosLLHArray[2] !=
        GNSSPreProcessingSingleAntenn_P.CompareToConstant1_const),
       GNSSPreProcessingSingleAntenn_B.GPSL1Stream.sf_CalculateSatellitePositionan.satPosEcef,
       GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_CalculateSatellitePositionan.SFunction_DIMS2,
       rtb_elevation_mask, &rtb_removedSats_g,
       &GNSSPreProcessingSingleAntenn_B.sf_CreateSatelliteElevationMask,
       &GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMask);

    // BusSelector: '<S51>/Bus Selector1'
    nz =
      GNSSPreProcessingSingleAnten_DW.sf_CalculateDualfrequencyCorrec.SFunction_DIMS2.pseudorange;
    GNSSPreProcessingSingleAnten_DW.BusSelector1_DIMS1_f =
      GNSSPreProcessingSingleAnten_DW.sf_CalculateDualfrequencyCorrec.SFunction_DIMS2.pseudorange;

    // MATLAB Function: '<S51>/Calculate Klobuchar Model Correction' incorporates:
    //   Inport: '<Root>/GPSIONBus'
    //   Inport: '<Root>/usePosLLHArray'

    CalculateKlobucharModelCorrecti
      (GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
       GNSSPreProcessingSingleAntenn_B.sf_CreateSatelliteElevationMask.elevationAngle,
       &GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMask.SFunction_DIMS3,
       GNSSPreProcessingSingleAntenn_B.sf_CreateSatelliteElevationMask.azimuthAngle,
       GNSSPreProcessingSingleAnten_DW.GPSL1Stream.sf_CalculateSatellitePositionan.SFunction_DIMS2,
       GNSSPreProcessingSingleAntenn_B.GPSL1Stream.timeOfWeekIn,
       &GNSSPreProcessingSingleAntenn_U.GPSIONBus, rtb_enableKlobucharCorrection,
       &GNSSPreProcessingSingleAntenn_B.sf_CalculateKlobucharModelCorre,
       &GNSSPreProcessingSingleAnten_DW.sf_CalculateKlobucharModelCorre);

    // BusAssignment: '<S51>/Bus Assignment2' incorporates:
    //   SignalConversion generated from: '<S70>/Bus Assignment1'

    GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1_i =
      GNSSPreProcessingSingleAnten_DW.sf_CalculateDualfrequencyCorrec.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1_i.pseudorange =
      GNSSPreProcessingSingleAnten_DW.BusSelector1_DIMS1_f;
    GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL =
      GNSSPreProcessingSingleAntenn_B.sf_CalculateDualfrequencyCorrec.measurementFrequencyBus;

    // BusSelector: '<S51>/Bus Selector1'
    boffset =
      (GNSSPreProcessingSingleAnten_DW.sf_CalculateDualfrequencyCorrec.SFunction_DIMS2.pseudorange
       / 2) << 1;
    kAcol = boffset - 2;

    // BusAssignment: '<S51>/Bus Assignment2' incorporates:
    //   BusSelector: '<S51>/Bus Selector1'
    //   SignalConversion generated from: '<S70>/Bus Assignment1'
    //   Sum: '<S51>/Add1'

    for (vlen = 0; vlen <= kAcol; vlen += 2) {
      tmp_2 = _mm_loadu_pd
        (&GNSSPreProcessingSingleAntenn_B.sf_CalculateDualfrequencyCorrec.measurementFrequencyBus.pseudorange
         [vlen]);
      tmp_0 = _mm_loadu_pd
        (&GNSSPreProcessingSingleAntenn_B.sf_CalculateDualfrequencyCorrec.dualFrequencyCorrection
         [vlen]);
      tmp_1 = _mm_loadu_pd
        (&GNSSPreProcessingSingleAntenn_B.sf_CalculateKlobucharModelCorre.klobucharCorrection
         [vlen]);
      _mm_storeu_pd
        (&GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.pseudorange[vlen],
         _mm_sub_pd(_mm_sub_pd(tmp_2, tmp_0), tmp_1));
    }

    for (vlen = boffset; vlen < nz; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.pseudorange[vlen] =
        (GNSSPreProcessingSingleAntenn_B.sf_CalculateDualfrequencyCorrec.measurementFrequencyBus.pseudorange
         [vlen] -
         GNSSPreProcessingSingleAntenn_B.sf_CalculateDualfrequencyCorrec.dualFrequencyCorrection
         [vlen]) -
        GNSSPreProcessingSingleAntenn_B.sf_CalculateKlobucharModelCorre.klobucharCorrection
        [vlen];
    }

    // Logic: '<S21>/Logical Operator2' incorporates:
    //   Logic: '<S21>/Logical Operator'

    rtb_LogicalOperator2_n = (rtb_enable_tropospheric_correct &&
      (!rtb_enable_differential_correct));

    // MATLAB Function: '<S23>/Calculate Tropospheric Corrections' incorporates:
    //   Inport: '<Root>/usePosLLHArray'

    CalculateTroposphericCorrection(rtb_dayOfYear, rtb_LogicalOperator2_n,
      GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
      GNSSPreProcessingSingleAntenn_B.sf_CreateSatelliteElevationMask.elevationAngle,
      &GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMask.SFunction_DIMS3,
      &GNSSPreProcessingSingleAntenn_B.sf_CalculateTroposphericCorrect,
      &GNSSPreProcessingSingleAnten_DW.sf_CalculateTroposphericCorrect);

    // BusSelector: '<S23>/Bus Selector2'
    GNSSPreProcessingSingleAnten_DW.BusSelector2_DIMS1 =
      GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1_i.pseudorange;

    // BusAssignment: '<S23>/Bus Assignment2'
    GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1_h =
      GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1_i;
    GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1_h.pseudorange =
      GNSSPreProcessingSingleAnten_DW.BusSelector2_DIMS1;

    // BusSelector: '<S23>/Bus Selector2' incorporates:
    //   BusAssignment: '<S23>/Bus Assignment2'

    c_nz = GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1_i.pseudorange -
      1;
    boffset =
      (GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1_i.pseudorange / 2) <<
      1;
    kAcol = boffset - 2;

    // BusAssignment: '<S23>/Bus Assignment2' incorporates:
    //   BusSelector: '<S23>/Bus Selector2'
    //   SignalConversion generated from: '<S70>/Bus Assignment1'
    //   Sum: '<S23>/Add1'

    for (vlen = 0; vlen <= kAcol; vlen += 2) {
      tmp_2 = _mm_loadu_pd
        (&GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.pseudorange[vlen]);
      tmp_0 = _mm_loadu_pd
        (&GNSSPreProcessingSingleAntenn_B.sf_CalculateTroposphericCorrect.troposphericDelay
         [vlen]);
      _mm_storeu_pd
        (&GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.pseudorange[vlen],
         _mm_sub_pd(tmp_2, tmp_0));
    }

    for (vlen = boffset; vlen <= c_nz; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL.pseudorange[vlen] -=
        GNSSPreProcessingSingleAntenn_B.sf_CalculateTroposphericCorrect.troposphericDelay
        [vlen];
    }

    // MATLAB Function: '<S55>/Apply Elevation and NaN and Zero Mask'
    ApplyElevationandNaNandZeroMask
      (&GNSSPreProcessingSingleAntenn_B.measurementBusL1_WL,
       &GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1_h,
       GNSSPreProcessingSingleAntenn_B.sf_CreateSatelliteElevationMask.elevationMask,
       &GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMask.SFunction_DIMS2,
       &rtb_nan_errCnt,
       &GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM,
       &GNSSPreProcessingSingleAnten_DW.sf_ApplyElevationandNaNandZeroM);

    // MATLAB Function: '<S55>/Apply Non Dual Frequency GPS Satellite Mask'
    if (rtb_enableDualFrequencyCorrecti) {
      boffset =
        GNSSPreProcessingSingleAnten_DW.sf_ApplyElevationandNaNandZeroM.SFunction_DIMS2.PRN;
      vlen =
        GNSSPreProcessingSingleAnten_DW.sf_CalculateDualfrequencyCorrec.SFunction_DIMS4;
      GNSSPreProcessing_do_vectors_ig
        (GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.PRN,
         &boffset,
         GNSSPreProcessingSingleAntenn_B.sf_CalculateDualfrequencyCorrec.SvidDualFrequencyCorrected,
         &vlen, a__1_data, &a__1_size, iia_data, &p_size_idx_0,
         indx_to_isolate_data, &i2);
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.time_receive =
        GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.time_receive;
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.satellite_position[0] =
        p_size_idx_0;
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.satellite_position[1] =
        GNSSPreProcessingSingleAnten_DW.sf_ApplyElevationandNaNandZeroM.SFunction_DIMS2.satellite_position
        [1];
      s_size[0] =
        GNSSPreProcessingSingleAnten_DW.sf_ApplyElevationandNaNandZeroM.SFunction_DIMS2.satellite_position
        [0];
      coffset =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.satellite_position[0];
      c_nz =
        GNSSPreProcessingSingleAnten_DW.sf_ApplyElevationandNaNandZeroM.SFunction_DIMS2.satellite_position
        [1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        for (partialTrueCount = 0; partialTrueCount < p_size_idx_0;
             partialTrueCount++) {
          GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.satellite_position
            [partialTrueCount + coffset * vlen] =
            GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.satellite_position
            [(s_size[0] * vlen + iia_data[partialTrueCount]) - 1];
        }
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.satellite_velocity[0] =
        p_size_idx_0;
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.satellite_velocity[1] =
        GNSSPreProcessingSingleAnten_DW.sf_ApplyElevationandNaNandZeroM.SFunction_DIMS2.satellite_velocity
        [1];
      s_size[0] =
        GNSSPreProcessingSingleAnten_DW.sf_ApplyElevationandNaNandZeroM.SFunction_DIMS2.satellite_velocity
        [0];
      coffset =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.satellite_velocity[0];
      c_nz =
        GNSSPreProcessingSingleAnten_DW.sf_ApplyElevationandNaNandZeroM.SFunction_DIMS2.satellite_velocity
        [1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        for (partialTrueCount = 0; partialTrueCount < p_size_idx_0;
             partialTrueCount++) {
          GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.satellite_velocity
            [partialTrueCount + coffset * vlen] =
            GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.satellite_velocity
            [(s_size[0] * vlen + iia_data[partialTrueCount]) - 1];
        }
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.PRN = p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.PRN[vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.PRN
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.pseudorange =
        p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.pseudorange[vlen]
          =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.pseudorange
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.pseudorange_raw =
        p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.pseudorange_raw
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.pseudorange_raw
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.pseudorange_satclk_corrected
        = p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.pseudorange_satclk_corrected
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.pseudorange
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.deltarange =
        p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.deltarange[vlen]
          =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.deltarange
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.deltarange_raw =
        p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.deltarange_raw
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.deltarange_raw
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.deltarange_satclk_corrected
        = p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.deltarange_satclk_corrected
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.deltarange_satclk_corrected
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.variance_pseudorange =
        p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.variance_pseudorange
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.variance_pseudorange
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.variance_pseudorange_measured
        = p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.variance_pseudorange_measured
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.variance_pseudorange_measured
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.variance_deltarange =
        p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.variance_deltarange
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.variance_deltarange
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.carrierphase =
        p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.carrierphase[
          vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.carrierphase
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.carrierphase_raw =
        p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.carrierphase_raw
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.carrierphase_raw
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.carrierphase_satclk_corrected
        = p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.carrierphase_satclk_corrected
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.carrierphase_satclk_corrected
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.variance_carrierphase_measured
        = p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.variance_carrierphase_measured
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.variance_carrierphase_measured
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.locktime = p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.locktime[vlen]
          =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.locktime
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh.CN0 = p_size_idx_0;
      for (vlen = 0; vlen < p_size_idx_0; vlen++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.CN0[vlen] =
          GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.CN0
          [iia_data[vlen] - 1];
      }

      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.base_position
        [0] =
        GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.base_position
        [0];
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.base_position
        [1] =
        GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.base_position
        [1];
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.base_position
        [2] =
        GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa.base_position
        [2];
    } else {
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh =
        GNSSPreProcessingSingleAnten_DW.sf_ApplyElevationandNaNandZeroM.SFunction_DIMS2;
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i =
        GNSSPreProcessingSingleAntenn_B.sf_ApplyElevationandNaNandZeroM.measurementFrequencyCorrectedMa;
    }

    // End of MATLAB Function: '<S55>/Apply Non Dual Frequency GPS Satellite Mask' 

    // MATLAB Function: '<S55>/Apply Differential Correction Mask1' incorporates:
    //   Inport: '<Root>/RTCM_3_3_L1_E1_Bus'
    //   MATLAB Function: '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'

    ApplyDifferentialCorrectionMask
      (&GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i,
       &GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_hh,
       GNSSPreProcessingSingleAntenn_B.sf_CalculateDifferentialCorrect.diffPseudorangeCorrection,
       GNSSPreProcessingSingleAntenn_B.sf_CalculateDifferentialCorrect.maskDiffCorr,
       &GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorrect.SFunction_DIMS3,
       rtb_enable_differential_correct,
       GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.base,
       &rtb_MeasurementCorrected,
       &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM,
       &GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM);

    // BusSelector: '<S11>/Bus Selector'
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2_a[0] =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.satellite_position
      [0];
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2_a[1] =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.satellite_position
      [1];
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3_a[0] =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.satellite_velocity
      [0];
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3_a[1] =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.satellite_velocity
      [1];
    nz =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.PRN;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4_b =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.PRN;
    vlen =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.pseudorange;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5_e =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.pseudorange;
    trueCount =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.pseudorange_raw;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6_d =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.pseudorange_raw;
    i2 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.pseudorange_satclk_corrected;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7_i =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.pseudorange_satclk_corrected;
    kAcol =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.deltarange;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8_m =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.deltarange;
    boffset =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.deltarange_raw;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9_i =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.deltarange_raw;
    partialTrueCount =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.deltarange_satclk_corrected;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10_f =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.deltarange_satclk_corrected;
    coffset =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.variance_pseudorange;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11_c =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.variance_pseudorange;
    BusSelector_DIMS12_i_tmp_tmp =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.variance_pseudorange_measured;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12_i =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.variance_pseudorange_measured;
    o_size_idx_0 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.variance_deltarange;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13_j =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.variance_deltarange;
    p_size_idx_0 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.carrierphase;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14_f =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.carrierphase;
    a__1_size =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.carrierphase_raw;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15_g =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.carrierphase_raw;
    SVID_DIMS1 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.carrierphase_satclk_corrected;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16_k =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.carrierphase_satclk_corrected;
    SVID_DIMS1_0 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.variance_carrierphase_measured;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17_d =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.variance_carrierphase_measured;
    BusSelector_DIMS18_o_tmp_tmp =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.locktime;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18_o =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.locktime;
    BusSelector_DIMS19_a_tmp_tmp =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.CN0;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19_a =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.CN0;

    // BusSelector: '<S11>/Bus Selector'
    GNSSPreProcessingSingleAntenn_B.time_receive_b =
      GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.time_receive;

    // BusSelector: '<S11>/Bus Selector'
    c_nz =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.satellite_position
      [0] *
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.satellite_position
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.satellite_position_o[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.satellite_position
                  [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    c_nz =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.satellite_velocity
      [0] *
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectionM.SFunction_DIMS2.satellite_velocity
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.satellite_velocity_p[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.satellite_velocity
                  [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    if (nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.PRN_b[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.PRN
                  [0], static_cast<uint32_T>(nz) * sizeof(uint16_T));
    }

    if (vlen - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.pseudorange_l[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.pseudorange
                  [0], static_cast<uint32_T>(vlen) * sizeof(real_T));
    }

    if (trueCount - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.pseudorange_raw_k[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.pseudorange_raw
                  [0], static_cast<uint32_T>(trueCount) * sizeof(real_T));
    }

    if (i2 - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.pseudorange_satclk_corrected_a[0],
         &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.pseudorange_satclk_corrected
         [0], static_cast<uint32_T>(i2) * sizeof(real_T));
    }

    if (kAcol - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.deltarange_h[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.deltarange
                  [0], static_cast<uint32_T>(kAcol) * sizeof(real_T));
    }

    if (boffset - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.deltarange_raw_k[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.deltarange_raw
                  [0], static_cast<uint32_T>(boffset) * sizeof(real_T));
    }

    if (partialTrueCount - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.deltarange_satclk_corrected_n[0],
         &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.deltarange_satclk_corrected
         [0], static_cast<uint32_T>(partialTrueCount) * sizeof(real_T));
    }

    if (coffset - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.variance_pseudorange_g[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.variance_pseudorange
                  [0], static_cast<uint32_T>(coffset) * sizeof(real_T));
    }

    if (BusSelector_DIMS12_i_tmp_tmp - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.variance_pseudorange_measured_i[0],
         &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.variance_pseudorange_measured
         [0], static_cast<uint32_T>(BusSelector_DIMS12_i_tmp_tmp) * sizeof
         (real_T));
    }

    if (o_size_idx_0 - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.variance_deltarange_n[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.variance_deltarange
                  [0], static_cast<uint32_T>(o_size_idx_0) * sizeof(real_T));
    }

    if (p_size_idx_0 - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.carrierphase_a[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.carrierphase
                  [0], static_cast<uint32_T>(p_size_idx_0) * sizeof(real_T));
    }

    if (a__1_size - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.carrierphase_raw_c[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.carrierphase_raw
                  [0], static_cast<uint32_T>(a__1_size) * sizeof(real_T));
    }

    if (SVID_DIMS1 - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.carrierphase_satclk_corrected_m[0],
         &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.carrierphase_satclk_corrected
         [0], static_cast<uint32_T>(SVID_DIMS1) * sizeof(real_T));
    }

    if (SVID_DIMS1_0 - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.variance_carrierphase_measure_o[0],
         &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.variance_carrierphase_measured
         [0], static_cast<uint32_T>(SVID_DIMS1_0) * sizeof(real_T));
    }

    if (BusSelector_DIMS18_o_tmp_tmp - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.locktime_k[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.locktime
                  [0], static_cast<uint32_T>(BusSelector_DIMS18_o_tmp_tmp) *
                  sizeof(real32_T));
    }

    if (BusSelector_DIMS19_a_tmp_tmp - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.CN0_f[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.CN0
                  [0], static_cast<uint32_T>(BusSelector_DIMS19_a_tmp_tmp) *
                  sizeof(real_T));
    }

    // BusSelector: '<S11>/Bus Selector'
    GNSSPreProcessingSingleAntenn_B.base_position_b[0] =
      GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.base_position
      [0];
    GNSSPreProcessingSingleAntenn_B.base_position_b[1] =
      GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.base_position
      [1];
    GNSSPreProcessingSingleAntenn_B.base_position_b[2] =
      GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectionM.GPS_measurement_Bus_masked.base_position
      [2];

    // Logic: '<S23>/Logical Operator1' incorporates:
    //   Logic: '<S23>/Logical Operator'
    //   Logic: '<S23>/Logical Operator3'

    GNSSPreProcessingSingleAntenn_B.LogicalOperator1 = ((rtb_LogicalOperator2_n &&
      (rtb_enableDualFrequencyCorrecti || rtb_enableKlobucharCorrection)) ||
      rtb_MeasurementCorrected);
  }

  // End of Outputs for SubSystem: '<S3>/GPS'

  // Outputs for Enabled SubSystem: '<S3>/Galileo' incorporates:
  //   EnablePort: '<S12>/Enable'

  if (rtb_enable_galileo) {
    // MATLAB Function: '<S12>/Navigation Data Conversion GAL' incorporates:
    //   Inport: '<Root>/GALNavBus'

    GNS_NavigationDataConversionGAL(&GNSSPreProcessingSingleAntenn_U.GALNavBus,
      &GNSSPreProcessingSingleAntenn_B.sf_NavigationDataConversionGAL,
      &GNSSPreProcessingSingleAnten_DW.sf_NavigationDataConversionGAL);

    // MATLAB Function: '<S64>/MATLAB Function1' incorporates:
    //   BusCreator generated from: '<S64>/MATLAB Function1'
    //   Constant: '<S12>/E5_basedProcessing'

    if (!GNSSPreProcessingSingleAntenn_P.E5_basedProcessing_Value) {
      rtb_parameters_galileo_Bus.enable_galileo = true;
      rtb_parameters_galileo_Bus.enable_galileo_e1 = true;
      rtb_parameters_galileo_Bus.enable_galileo_e5a = rtb_enable_galileo_e5a;
      rtb_parameters_galileo_Bus.enable_galileo_e5b = rtb_enable_galileo_e5b;
      rtb_parameters_galileo_Bus.enable_galileo_e5 = rtb_enable_galileo_e5;
    } else {
      rtb_parameters_galileo_Bus.enable_galileo = true;
      rtb_parameters_galileo_Bus.enable_galileo_e1 = rtb_enable_galileo_e1;
      rtb_parameters_galileo_Bus.enable_galileo_e5a = rtb_enable_galileo_e5a;
      rtb_parameters_galileo_Bus.enable_galileo_e5b = rtb_enable_galileo_e5b;
      rtb_parameters_galileo_Bus.enable_galileo_e5 = true;
    }

    // End of MATLAB Function: '<S64>/MATLAB Function1'

    // MATLAB Function: '<S12>/Simplify and Mask GAL Measurement Bus'
    SimplifyandMaskGALMeasurementBu
      (&GNSSPreProcessingSingleAntenn_B.GalMeasurementBus,
       &GNSSPreProcessingSingleAntenn_B.sf_NavigationDataConversionGAL.GAL_NavigationData_Bus,
       &GNSSPreProcessingSingleAnten_DW.sf_NavigationDataConversionGAL.SFunction_DIMS2,
       &rtb_parameters_galileo_Bus,
       &GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen);

    // MATLAB Function: '<S70>/Calculate Differential Corrections' incorporates:
    //   Inport: '<Root>/usePosLLHArray'

    CalculateDifferentialCorrecti_l
      (&GNSSPreProcessingSingleAntenn_B.GalMeasurementB,
       &GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3,
       &GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.navdata_e1,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS4,
       GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
       &GNSSPreProcessingSingleAntenn_B.sf_CalculateDifferentialCorre_l,
       &GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorre_l);

    // Outputs for Enabled SubSystem: '<S12>/Galileo E1 stream'
    // Outputs for Enabled SubSystem: '<S12>/Galileo E1 stream'
    // SignalConversion generated from: '<S65>/Enable' incorporates:
    //   Constant: '<S12>/Base Position Dummy'
    //   Constant: '<S12>/E5_basedProcessing'
    //   Inport: '<Root>/usePosLLHArray'

    GN_Galileosinglefrequencystream(rtb_parameters_galileo_Bus.enable_galileo_e1,
      GNSSPreProcessingSingleAntenn_P.E5_basedProcessing_Value,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.TOW,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.svid_e1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS3,
      &GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.navdata_e1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS4,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.pr_e1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS5,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.dr_e1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS7,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cn0_e1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS8,
      GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cp_e1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS9,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.locktime_e1,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS11,
      GNSSPreProcessingSingleAntenn_P.BasePositionDummy_Value_d,
      rtb_enable_SatPosVel_calculatio, rtb_use_measured_variance,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.pr_e1_sigma,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS6,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cp_e1_sigma,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS10,
      GNSSPreProcessingSingleAntenn_P.GalileoE1stream_enable_SatClock,
      &GNSSPreProcessingSingleAntenn_B.GalileoE1stream,
      &GNSSPreProcessingSingleAnten_DW.GalileoE1stream,
      &GNSSPreProcessingSingleAntenn_P.GalileoE1stream);

    // End of Outputs for SubSystem: '<S12>/Galileo E1 stream'
    // End of Outputs for SubSystem: '<S12>/Galileo E1 stream'

    // MATLAB Function: '<S110>/Create Satellite Elevation Mask' incorporates:
    //   Constant: '<S109>/Constant'
    //   Inport: '<Root>/usePosLLHArray'
    //   Logic: '<S70>/Logical Operator1'
    //   RelationalOperator: '<S109>/Compare'

    GN_CreateSatelliteElevationMask
      (GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
       (GNSSPreProcessingSingleAntenn_U.usePosLLHArray[0] !=
        GNSSPreProcessingSingleAntenn_P.CompareToConstant_const) &&
       (GNSSPreProcessingSingleAntenn_U.usePosLLHArray[1] !=
        GNSSPreProcessingSingleAntenn_P.CompareToConstant_const) &&
       (GNSSPreProcessingSingleAntenn_U.usePosLLHArray[2] !=
        GNSSPreProcessingSingleAntenn_P.CompareToConstant_const),
       GNSSPreProcessingSingleAntenn_B.GalileoE1stream.sf_CalculateSatellitePositionan.satPosEcef,
       GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_CalculateSatellitePositionan.SFunction_DIMS2,
       rtb_elevation_mask, &rtb_removedSats_g,
       &GNSSPreProcessingSingleAntenn_B.sf_CreateSatelliteElevationMa_a,
       &GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMa_a);

    // BusCreator generated from: '<S107>/Calculate Dualfrequency Correction with E1 and E5' incorporates:
    //   SignalConversion generated from: '<S65>/SVID'

    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.satellite_position
      [0] =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.satellite_position
      [1] =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.satellite_velocity
      [0] =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.satellite_velocity
      [1] =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.PRN =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.pseudorange =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.pseudorange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS5;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.deltarange =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.deltarange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS7;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.deltarange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.variance_pseudorange
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_SignalNoiseVariance.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.variance_pseudorange_measured
      = GNSSPreProcessingSingleAnten_DW.GalileoE1stream.measured_pr_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.variance_deltarange
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_SignalNoiseVariance.SFunction_DIMS3;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.carrierphase
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.carrierphase_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS9;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.variance_carrierphase_measured
      = GNSSPreProcessingSingleAnten_DW.GalileoE1stream.measured_cp_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.locktime =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.locktime_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.CN0 =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.CN0_DIMS1;
    c_nz =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0] *
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy(&rtb_GnssMeasurementBase_satelli[0],
                  &GNSSPreProcessingSingleAntenn_B.GalileoE1stream.sf_CalculateSatellitePositionan.satPosEcef
                  [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    c_nz =
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0] *
      GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy(&rtb_GnssMeasurementBase_satel_0[0],
                  &GNSSPreProcessingSingleAntenn_B.GalileoE1stream.sf_CalculateSatellitePositionan.satVelEcef
                  [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1; vlen++) {
      a__1_data[vlen] = GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
         vlen++) {
      variance_pseudorange[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS5;
         vlen++) {
      rtb_dualFrequencyCorrection[vlen] =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.pr_e1[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
         vlen++) {
      delta_rho_data[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.sf_TimeCorrectionDeltarange.deltarangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS7;
         vlen++) {
      rtb_BusConversion_InsertedFor_0[vlen] =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.dr_e1[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
         vlen++) {
      rtb_BusConversion_InsertedFor_1[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.sf_TimeCorrectionDeltarange.deltarangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_SignalNoiseVariance.SFunction_DIMS2;
         vlen++) {
      rtb_BusConversion_InsertedFor_2[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.sf_SignalNoiseVariance.variancePseudorange
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.measured_pr_sigma_DIMS1;
         vlen++) {
      rtb_BusConversion_InsertedFor_3[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.measured_pr_sigma[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_SignalNoiseVariance.SFunction_DIMS3;
         vlen++) {
      rtb_BusConversion_InsertedFor_4[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.sf_SignalNoiseVariance.varianceDeltarange
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
         vlen++) {
      rtb_BusConversion_InsertedFor_5[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS9;
         vlen++) {
      rtb_BusConversion_InsertedFor_6[vlen] =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cp_e1[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
         vlen++) {
      rtb_BusConversion_InsertedFor_7[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.measured_cp_sigma_DIMS1;
         vlen++) {
      rtb_BusConversion_InsertedFor_8[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.measured_cp_sigma[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.locktime_DIMS1; vlen++)
    {
      tmp_data[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.Locktime[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE1stream.CN0_DIMS1; vlen++) {
      rtb_BusConversion_InsertedFor_9[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.CN0[vlen];
    }

    // Outputs for Enabled SubSystem: '<S12>/Galileo E5a stream'
    // Outputs for Enabled SubSystem: '<S12>/Galileo E5a stream'
    // SignalConversion generated from: '<S67>/Enable' incorporates:
    //   Constant: '<S12>/Base Position Dummy'
    //   Constant: '<S12>/E5_basedProcessing'
    //   Inport: '<Root>/usePosLLHArray'

    GN_Galileosinglefrequencystream
      (rtb_parameters_galileo_Bus.enable_galileo_e5a,
       GNSSPreProcessingSingleAntenn_P.E5_basedProcessing_Value,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.TOW,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.svid_e5a,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS12,
       &GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.navdata_e5a,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS13,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.pr_e5a,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS14,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.dr_e5a,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS16,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cn0_e5a,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS17,
       GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cp_e5a,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS18,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.locktime_e5a,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS20,
       GNSSPreProcessingSingleAntenn_P.BasePositionDummy_Value_d,
       rtb_enable_SatPosVel_calculatio, rtb_use_measured_variance,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.pr_e5a_sigma,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS15,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cp_e5a_sigma,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS19,
       GNSSPreProcessingSingleAntenn_P.GalileoE5astream_enable_SatCloc,
       &GNSSPreProcessingSingleAntenn_B.GalileoE5astream,
       &GNSSPreProcessingSingleAnten_DW.GalileoE5astream,
       &GNSSPreProcessingSingleAntenn_P.GalileoE5astream);

    // End of Outputs for SubSystem: '<S12>/Galileo E5a stream'
    // End of Outputs for SubSystem: '<S12>/Galileo E5a stream'

    // BusCreator generated from: '<S107>/Calculate Dualfrequency Correction with E1 and E5' 
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.satellite_position
      [0] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.satellite_position
      [1] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.satellite_velocity
      [0] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.satellite_velocity
      [1] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.PRN =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.SVID_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.pseudorange =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.pseudorange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS14;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.deltarange =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.deltarange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS16;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.deltarange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.variance_pseudorange
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_SignalNoiseVariance.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.variance_pseudorange_measured
      = GNSSPreProcessingSingleAnten_DW.GalileoE5astream.measured_pr_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.variance_deltarange
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_SignalNoiseVariance.SFunction_DIMS3;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.carrierphase
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.carrierphase_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS18;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.variance_carrierphase_measured
      = GNSSPreProcessingSingleAnten_DW.GalileoE5astream.measured_cp_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.locktime =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.locktime_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_o.CN0 =
      GNSSPreProcessingSingleAnten_DW.GalileoE5astream.CN0_DIMS1;

    // Outputs for Enabled SubSystem: '<S12>/Galileo E5b stream'
    // Outputs for Enabled SubSystem: '<S12>/Galileo E5b stream'
    // SignalConversion generated from: '<S68>/Enable' incorporates:
    //   Constant: '<S12>/Base Position Dummy'
    //   Constant: '<S12>/E5_basedProcessing'
    //   Inport: '<Root>/usePosLLHArray'

    GN_Galileosinglefrequencystream
      (rtb_parameters_galileo_Bus.enable_galileo_e5b,
       GNSSPreProcessingSingleAntenn_P.E5_basedProcessing_Value,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.TOW,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.svid_e5b,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS21,
       &GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.navdata_e5b,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS22,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.pr_e5b,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS23,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.dr_e5b,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS25,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cn0_e5b,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS26,
       GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cp_e5b,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS27,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.locktime_e5b,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS29,
       GNSSPreProcessingSingleAntenn_P.BasePositionDummy_Value_d,
       rtb_enable_SatPosVel_calculatio, rtb_use_measured_variance,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.pr_e5b_sigma,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS24,
       GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cp_e5b_sigma,
       &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS28,
       GNSSPreProcessingSingleAntenn_P.GalileoE5bstream_enable_SatCloc,
       &GNSSPreProcessingSingleAntenn_B.GalileoE5bstream,
       &GNSSPreProcessingSingleAnten_DW.GalileoE5bstream,
       &GNSSPreProcessingSingleAntenn_P.GalileoE5bstream);

    // End of Outputs for SubSystem: '<S12>/Galileo E5b stream'
    // End of Outputs for SubSystem: '<S12>/Galileo E5b stream'

    // BusCreator generated from: '<S107>/Calculate Dualfrequency Correction with E1 and E5' 
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.satellite_position
      [0] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.satellite_position
      [1] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.satellite_velocity
      [0] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.satellite_velocity
      [1] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.PRN =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.SVID_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.pseudorange =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.pseudorange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS23;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.deltarange =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.deltarange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS25;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.deltarange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.variance_pseudorange
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_SignalNoiseVariance.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.variance_pseudorange_measured
      = GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.measured_pr_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.variance_deltarange
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_SignalNoiseVariance.SFunction_DIMS3;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.carrierphase
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.carrierphase_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS27;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.variance_carrierphase_measured
      = GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.measured_cp_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.locktime =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.locktime_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_k.CN0 =
      GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.CN0_DIMS1;

    // Outputs for Enabled SubSystem: '<S12>/Galileo E5 stream'
    // Outputs for Enabled SubSystem: '<S12>/Galileo E5 stream'
    // SignalConversion generated from: '<S66>/Enable' incorporates:
    //   Constant: '<S12>/Base Position Dummy'
    //   Constant: '<S12>/E5_basedProcessing'
    //   Inport: '<Root>/usePosLLHArray'

    GN_Galileosinglefrequencystream(rtb_parameters_galileo_Bus.enable_galileo_e5,
      GNSSPreProcessingSingleAntenn_P.E5_basedProcessing_Value,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.TOW,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.svid_e5,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS30,
      &GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.navdata_e5,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS31,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.pr_e5,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS32,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.dr_e5,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS34,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cn0_e5,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS35,
      GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cp_e5,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS36,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.locktime_e5,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS38,
      GNSSPreProcessingSingleAntenn_P.BasePositionDummy_Value_d,
      rtb_enable_SatPosVel_calculatio, rtb_use_measured_variance,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.pr_e5_sigma,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS33,
      GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cp_e5_sigma,
      &GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS37,
      GNSSPreProcessingSingleAntenn_P.GalileoE5stream_enable_SatClock,
      &GNSSPreProcessingSingleAntenn_B.GalileoE5stream,
      &GNSSPreProcessingSingleAnten_DW.GalileoE5stream,
      &GNSSPreProcessingSingleAntenn_P.GalileoE5stream);

    // End of Outputs for SubSystem: '<S12>/Galileo E5 stream'
    // End of Outputs for SubSystem: '<S12>/Galileo E5 stream'

    // BusCreator generated from: '<S107>/Calculate Dualfrequency Correction with E1 and E5' incorporates:
    //   SignalConversion generated from: '<S66>/SVID'

    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.satellite_position
      [0] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.satellite_position
      [1] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.satellite_velocity
      [0] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.satellite_velocity
      [1] =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.PRN =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.SVID_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.pseudorange =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.pseudorange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS32;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.deltarange =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.deltarange_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS34;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.deltarange_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.variance_pseudorange
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_SignalNoiseVariance.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.variance_pseudorange_measured
      = GNSSPreProcessingSingleAnten_DW.GalileoE5stream.measured_pr_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.variance_deltarange
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_SignalNoiseVariance.SFunction_DIMS3;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.carrierphase
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.carrierphase_raw
      =
      GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS36;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.variance_carrierphase_measured
      = GNSSPreProcessingSingleAnten_DW.GalileoE5stream.measured_cp_sigma_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.locktime =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.locktime_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.CN0 =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.CN0_DIMS1;
    c_nz =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [0] *
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_CalculateSatellitePositionan.SFunction_DIMS2
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy(&rtb_measurementFrequency_Bus_sa[0],
                  &GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_CalculateSatellitePositionan.satPosEcef
                  [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    c_nz =
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [0] *
      GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_CalculateSatellitePositionan.SFunction_DIMS3
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy(&rtb_measurementFrequency_Bus__0[0],
                  &GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_CalculateSatellitePositionan.satVelEcef
                  [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.SVID_DIMS1; vlen++) {
      GNSSPreProcessingSingleAntenn_B.PRN_i[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.PRN[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
         vlen++) {
      rtb_Add1[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS32;
         vlen++) {
      rtb_measurementFrequency_Bus_ps[vlen] =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.pr_e5[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
         vlen++) {
      rtb_measurementFrequency_Bus_de[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_TimeCorrectionDeltarange.deltarangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS34;
         vlen++) {
      rtb_measurementFrequency_Bus__1[vlen] =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.dr_e5[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionDeltarange.SFunction_DIMS2;
         vlen++) {
      rtb_measurementFrequency_Bus__2[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_TimeCorrectionDeltarange.deltarangeCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_SignalNoiseVariance.SFunction_DIMS2;
         vlen++) {
      rtb_measurementFrequency_Bus_va[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_SignalNoiseVariance.variancePseudorange
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.measured_pr_sigma_DIMS1;
         vlen++) {
      rtb_measurementFrequency_Bus__3[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.measured_pr_sigma[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_SignalNoiseVariance.SFunction_DIMS3;
         vlen++) {
      rtb_measurementFrequency_Bus__4[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_SignalNoiseVariance.varianceDeltarange
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
         vlen++) {
      rtb_measurementFrequency_Bus_ca[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.sf_SimplifyandMaskGALMeasuremen.SFunction_DIMS36;
         vlen++) {
      rtb_measurementFrequency_Bus__5[vlen] =
        GNSSPreProcessingSingleAntenn_B.sf_SimplifyandMaskGALMeasuremen.cp_e5[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionCarrierphase.SFunction_DIMS2;
         vlen++) {
      rtb_measurementFrequency_Bus__6[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_TimeCorrectionCarrierphase.carrierphaseCorrected
        [vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.measured_cp_sigma_DIMS1;
         vlen++) {
      rtb_measurementFrequency_Bus__7[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.measured_cp_sigma[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.locktime_DIMS1; vlen++)
    {
      rtb_measurementFrequency_Bus_lo[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.Locktime[vlen];
    }

    for (vlen = 0; vlen <
         GNSSPreProcessingSingleAnten_DW.GalileoE5stream.CN0_DIMS1; vlen++) {
      rtb_measurementFrequency_Bus_CN[vlen] =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.CN0[vlen];
    }

    // MATLAB Function: '<S64>/MATLAB Function'
    x[0] = rtb_parameters_galileo_Bus.enable_galileo_e1;
    x[1] = rtb_parameters_galileo_Bus.enable_galileo_e5a;
    x[2] = rtb_parameters_galileo_Bus.enable_galileo_e5b;
    x[3] = rtb_parameters_galileo_Bus.enable_galileo_e5;
    c_nz = 0;
    nz = 0;
    exitg1 = false;
    while ((!exitg1) && (nz < 4)) {
      if (x[nz]) {
        c_nz++;
        if (c_nz >= 4) {
          exitg1 = true;
        } else {
          nz++;
        }
      } else {
        nz++;
      }
    }

    // Logic: '<S64>/Logical Operator'
    rtb_MeasurementCorrected = !rtb_enable_differential_correct;

    // MATLAB Function: '<S64>/MATLAB Function'
    if (c_nz < 1) {
      c_nz = 0;
    }

    // Logic: '<S107>/Logical Operator' incorporates:
    //   Logic: '<S64>/Logical Operator3'
    //   Logic: '<S64>/Logical Operator4'
    //   Logic: '<S64>/Logical Operator5'
    //   MATLAB Function: '<S64>/MATLAB Function'

    rtb_enableDualFrequencyCorrecti = ((c_nz > 1) || ((!rtb_MeasurementCorrected)
      || (!rtb_enable_ionospheric_correcti)));

    // MATLAB Function: '<S107>/Calculate Dualfrequency Correction with E1 and E5' incorporates:
    //   BusCreator generated from: '<S107>/Calculate Dualfrequency Correction with E1 and E5'
    //   Constant: '<S12>/E5_basedProcessing'
    //   SignalConversion generated from: '<S65>/SVID'
    //   SignalConversion generated from: '<S66>/SVID'
    //   SignalConversion generated from: '<S67>/SVID'
    //   SignalConversion generated from: '<S68>/SVID'

    if (rtb_enableDualFrequencyCorrecti) {
      if (!GNSSPreProcessingSingleAntenn_P.E5_basedProcessing_Value) {
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_l =
          GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu;

        // MATLAB Function: '<S111>/Apply Elevation and NaN and Zero Mask' incorporates:
        //   BusCreator generated from: '<S107>/Calculate Dualfrequency Correction with E1 and E5'

        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.time_receive
          = GNSSPreProcessingSingleAntenn_B.GalileoE1stream.TOW;
        std::memcpy(&rtb_measurementFrequency_Bus_sa[0],
                    &rtb_GnssMeasurementBase_satelli[0], 120U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus__0[0],
                    &rtb_GnssMeasurementBase_satel_0[0], 120U * sizeof(real_T));
        std::memcpy(&GNSSPreProcessingSingleAntenn_B.PRN_i[0], &a__1_data[0],
                    40U * sizeof(uint16_T));
        std::memcpy(&rtb_Add1[0], &variance_pseudorange[0], 40U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus_ps[0],
                    &rtb_dualFrequencyCorrection[0], 40U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus_de[0], &delta_rho_data[0], 40U
                    * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus__1[0],
                    &rtb_BusConversion_InsertedFor_0[0], 40U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus__2[0],
                    &rtb_BusConversion_InsertedFor_1[0], 40U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus_va[0],
                    &rtb_BusConversion_InsertedFor_2[0], 40U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus__3[0],
                    &rtb_BusConversion_InsertedFor_3[0], 40U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus__4[0],
                    &rtb_BusConversion_InsertedFor_4[0], 40U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus_ca[0],
                    &rtb_BusConversion_InsertedFor_5[0], 40U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus__5[0],
                    &rtb_BusConversion_InsertedFor_6[0], 40U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus__6[0],
                    &rtb_BusConversion_InsertedFor_7[0], 40U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus__7[0],
                    &rtb_BusConversion_InsertedFor_8[0], 40U * sizeof(real_T));
        std::memcpy(&rtb_measurementFrequency_Bus_lo[0], &tmp_data[0], 40U *
                    sizeof(real32_T));
        std::memcpy(&rtb_measurementFrequency_Bus_CN[0],
                    &rtb_BusConversion_InsertedFor_9[0], 40U * sizeof(real_T));

        // MATLAB Function: '<S111>/Apply Elevation and NaN and Zero Mask' incorporates:
        //   BusCreator generated from: '<S107>/Calculate Dualfrequency Correction with E1 and E5'

        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
          [0] = GNSSPreProcessingSingleAntenn_B.GalileoE1stream.basePosition[0];
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
          [1] = GNSSPreProcessingSingleAntenn_B.GalileoE1stream.basePosition[1];
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
          [2] = GNSSPreProcessingSingleAntenn_B.GalileoE1stream.basePosition[2];
        SVID_DIMS1_0 =
          GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
        vlen = GNSSPreProcessingSingleAnten_DW.GalileoE5astream.SVID_DIMS1;
        GNSSPreProcessing_do_vectors_ig
          (GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN, &SVID_DIMS1_0,
           GNSSPreProcessingSingleAntenn_B.GalileoE5astream.PRN, &vlen,
           PRNsE1E5a_data, &SVID_DIMS1, iia_data, &p_size_idx_0,
           indx_to_isolate_data, &i2);
        SVID_DIMS1_0 =
          GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
        vlen = GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.SVID_DIMS1;
        GNSSPreProcessing_do_vectors_ig
          (GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN, &SVID_DIMS1_0,
           GNSSPreProcessingSingleAntenn_B.GalileoE5bstream.PRN, &vlen,
           a__1_data, &a__1_size, iia_data, &p_size_idx_0, indx_to_isolate_data,
           &i2);
        vlen = GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
        kAcol = GNSSPreProcessingSingleAnten_DW.GalileoE5stream.SVID_DIMS1;
        GNSSPreProcessing_do_vectors_ig
          (GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN, &vlen,
           GNSSPreProcessingSingleAntenn_B.GalileoE5stream.PRN, &kAcol,
           PRNsE1E5_data, &SVID_DIMS1_0, iia_data, &p_size_idx_0,
           indx_to_isolate_data, &i2);
        if (SVID_DIMS1 != 0) {
          vlen = GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
          kAcol = GNSSPreProcessingSingleAnten_DW.GalileoE5astream.SVID_DIMS1;
          GNSSPreProcessin_calcCorrection(variance_pseudorange,
            GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN, &vlen,
            GNSSPreProcessingSingleAntenn_B.GalileoE5astream.sf_TimeCorrectionPseudorange.pseudorangeCorrected,
            GNSSPreProcessingSingleAntenn_B.GalileoE5astream.PRN, &kAcol,
            delta_rho_data, &p_size_idx_0);
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3_e = p_size_idx_0;
          if (p_size_idx_0 - 1 >= 0) {
            std::memcpy(&rtb_dualFrequencyCorrection[0], &delta_rho_data[0],
                        static_cast<uint32_T>(p_size_idx_0) * sizeof(real_T));
          }
        } else {
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3_e =
            GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.pseudorange;
          c_nz =
            GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.pseudorange;
          boffset =
            (GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.pseudorange
             / 2) << 1;
          kAcol = boffset - 2;
          for (vlen = 0; vlen <= kAcol; vlen += 2) {
            tmp_2 = _mm_loadu_pd(&variance_pseudorange[vlen]);
            _mm_storeu_pd(&rtb_dualFrequencyCorrection[vlen], _mm_mul_pd
                          (_mm_set1_pd(0.0), tmp_2));
          }

          for (vlen = boffset; vlen < c_nz; vlen++) {
            rtb_dualFrequencyCorrection[vlen] = 0.0 * variance_pseudorange[vlen];
          }
        }

        if (a__1_size != 0) {
          GNSSPreProcessing_do_vectors_ig(PRNsE1E5a_data, &SVID_DIMS1, a__1_data,
            &a__1_size, PRNsE1E5aE1E5b_intersect_data, &boffset, iia_data,
            &p_size_idx_0, indx_to_isolate_data, &i2);
          for (coffset = 0; coffset < a__1_size; coffset++) {
            rtb_nan_errCnt = a__1_data[coffset];
            for (vlen = 0; vlen < boffset; vlen++) {
              b_data[vlen] = (PRNsE1E5aE1E5b_intersect_data[vlen] ==
                              rtb_nan_errCnt);
            }

            if (!GNSSPreProcessingSingleA_any_aa(b_data, &boffset)) {
              for (vlen = 0; vlen <
                   GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
                   vlen++) {
                mask_all_data[vlen] =
                  (GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN[vlen] ==
                   rtb_nan_errCnt);
              }

              for (vlen = 0; vlen <
                   GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
                   vlen++) {
                b_data[vlen] =
                  (GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN[vlen] ==
                   rtb_nan_errCnt);
              }

              for (vlen = 0; vlen <
                   GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.SVID_DIMS1;
                   vlen++) {
                c_data[vlen] =
                  (GNSSPreProcessingSingleAntenn_B.GalileoE5bstream.PRN[vlen] ==
                   rtb_nan_errCnt);
              }

              for (vlen = 0; vlen <
                   GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.SVID_DIMS1;
                   vlen++) {
                d_data[vlen] =
                  (GNSSPreProcessingSingleAntenn_B.GalileoE5bstream.PRN[vlen] ==
                   rtb_nan_errCnt);
              }

              kAcol = GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1
                - 1;
              trueCount = 0;
              for (partialTrueCount = 0; partialTrueCount <= kAcol;
                   partialTrueCount++) {
                if (mask_all_data[partialTrueCount]) {
                  trueCount++;
                }
              }

              i2 = trueCount;
              partialTrueCount = 0;
              for (vlen = 0; vlen <= kAcol; vlen++) {
                if (mask_all_data[vlen]) {
                  j_data_0[partialTrueCount] = static_cast<int8_T>(vlen + 1);
                  partialTrueCount++;
                }
              }

              kAcol = GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1
                - 1;
              vlen = 0;
              for (trueCount = 0; trueCount <= kAcol; trueCount++) {
                if (b_data[trueCount]) {
                  vlen++;
                }
              }

              BusSelector_DIMS12_i_tmp_tmp = vlen;
              trueCount = 0;
              for (partialTrueCount = 0; partialTrueCount <= kAcol;
                   partialTrueCount++) {
                if (b_data[partialTrueCount]) {
                  k_data_0[trueCount] = static_cast<int8_T>(partialTrueCount + 1);
                  trueCount++;
                }
              }

              vlen = GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.SVID_DIMS1
                - 1;
              kAcol = 0;
              for (partialTrueCount = 0; partialTrueCount <= vlen;
                   partialTrueCount++) {
                if (c_data[partialTrueCount]) {
                  kAcol++;
                }
              }

              o_size_idx_0 = kAcol;
              kAcol = 0;
              for (partialTrueCount = 0; partialTrueCount <= vlen;
                   partialTrueCount++) {
                if (c_data[partialTrueCount]) {
                  l_data[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
                  kAcol++;
                }
              }

              nz = GNSSPreProcessingSingleAnten_DW.GalileoE5bstream.SVID_DIMS1 -
                1;
              vlen = 0;
              for (partialTrueCount = 0; partialTrueCount <= nz;
                   partialTrueCount++) {
                if (d_data[partialTrueCount]) {
                  vlen++;
                }
              }

              kAcol = vlen;
              trueCount = 0;
              for (partialTrueCount = 0; partialTrueCount <= nz;
                   partialTrueCount++) {
                if (d_data[partialTrueCount]) {
                  m_data[trueCount] = static_cast<int8_T>(partialTrueCount + 1);
                  trueCount++;
                }
              }

              for (vlen = 0; vlen < i2; vlen++) {
                rtb_BusConversion_InsertedFor_0[vlen] =
                  variance_pseudorange[j_data_0[vlen] - 1];
              }

              for (vlen = 0; vlen < BusSelector_DIMS12_i_tmp_tmp; vlen++) {
                tmp_data_3[vlen] =
                  GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN[k_data_0[vlen]
                  - 1];
              }

              for (vlen = 0; vlen < o_size_idx_0; vlen++) {
                rtb_BusConversion_InsertedFor_1[vlen] =
                  GNSSPreProcessingSingleAntenn_B.GalileoE5bstream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
                  [l_data[vlen] - 1];
              }

              for (vlen = 0; vlen < kAcol; vlen++) {
                tmp_data_4[vlen] =
                  GNSSPreProcessingSingleAntenn_B.GalileoE5bstream.PRN[m_data[vlen]
                  - 1];
              }

              GNSSPreProcess_calcCorrection_g(rtb_BusConversion_InsertedFor_0,
                tmp_data_3, &BusSelector_DIMS12_i_tmp_tmp,
                rtb_BusConversion_InsertedFor_1, tmp_data_4, &kAcol,
                delta_rho_data, &p_size_idx_0);
              nz = 0;
              for (vlen = 0; vlen <
                   GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
                   vlen++) {
                if (mask_all_data[vlen]) {
                  rtb_dualFrequencyCorrection[vlen] = delta_rho_data[nz];
                  nz++;
                }
              }
            }
          }
        }

        if (SVID_DIMS1_0 != 0) {
          GNSSPreProcessing_do_vectors_ig(PRNsE1E5a_data, &SVID_DIMS1,
            PRNsE1E5_data, &SVID_DIMS1_0, a__1_data, &a__1_size, iia_data,
            &p_size_idx_0, indx_to_isolate_data, &i2);
          for (coffset = 0; coffset < SVID_DIMS1_0; coffset++) {
            rtb_nan_errCnt = PRNsE1E5_data[coffset];
            boffset = a__1_size;
            for (vlen = 0; vlen < a__1_size; vlen++) {
              b_data[vlen] = (a__1_data[vlen] == rtb_nan_errCnt);
            }

            if (!GNSSPreProcessingSingleA_any_aa(b_data, &a__1_size)) {
              for (vlen = 0; vlen <
                   GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
                   vlen++) {
                mask_all_data[vlen] =
                  (GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN[vlen] ==
                   rtb_nan_errCnt);
              }

              for (vlen = 0; vlen <
                   GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
                   vlen++) {
                b_data[vlen] =
                  (GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN[vlen] ==
                   rtb_nan_errCnt);
              }

              for (vlen = 0; vlen <
                   GNSSPreProcessingSingleAnten_DW.GalileoE5stream.SVID_DIMS1;
                   vlen++) {
                c_data[vlen] =
                  (GNSSPreProcessingSingleAntenn_B.GalileoE5stream.PRN[vlen] ==
                   rtb_nan_errCnt);
              }

              for (vlen = 0; vlen <
                   GNSSPreProcessingSingleAnten_DW.GalileoE5stream.SVID_DIMS1;
                   vlen++) {
                d_data[vlen] =
                  (GNSSPreProcessingSingleAntenn_B.GalileoE5stream.PRN[vlen] ==
                   rtb_nan_errCnt);
              }

              vlen = GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1
                - 1;
              kAcol = 0;
              for (partialTrueCount = 0; partialTrueCount <= vlen;
                   partialTrueCount++) {
                if (mask_all_data[partialTrueCount]) {
                  kAcol++;
                }
              }

              BusSelector_DIMS12_i_tmp_tmp = kAcol;
              kAcol = 0;
              for (partialTrueCount = 0; partialTrueCount <= vlen;
                   partialTrueCount++) {
                if (mask_all_data[partialTrueCount]) {
                  n_data[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
                  kAcol++;
                }
              }

              nz = GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1 -
                1;
              kAcol = 0;
              for (partialTrueCount = 0; partialTrueCount <= nz;
                   partialTrueCount++) {
                if (b_data[partialTrueCount]) {
                  kAcol++;
                }
              }

              o_size_idx_0 = kAcol;
              kAcol = 0;
              for (partialTrueCount = 0; partialTrueCount <= nz;
                   partialTrueCount++) {
                if (b_data[partialTrueCount]) {
                  o_data_0[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
                  kAcol++;
                }
              }

              nz = GNSSPreProcessingSingleAnten_DW.GalileoE5stream.SVID_DIMS1 -
                1;
              kAcol = 0;
              for (vlen = 0; vlen <= nz; vlen++) {
                if (c_data[vlen]) {
                  kAcol++;
                }
              }

              p_size_idx_0 = kAcol;
              kAcol = 0;
              for (vlen = 0; vlen <= nz; vlen++) {
                if (c_data[vlen]) {
                  p_data_0[kAcol] = static_cast<int8_T>(vlen + 1);
                  kAcol++;
                }
              }

              nz = GNSSPreProcessingSingleAnten_DW.GalileoE5stream.SVID_DIMS1 -
                1;
              partialTrueCount = 0;
              for (vlen = 0; vlen <= nz; vlen++) {
                if (d_data[vlen]) {
                  partialTrueCount++;
                }
              }

              trueCount = 0;
              for (vlen = 0; vlen <= nz; vlen++) {
                if (d_data[vlen]) {
                  q_data_0[trueCount] = static_cast<int8_T>(vlen + 1);
                  trueCount++;
                }
              }

              for (vlen = 0; vlen < BusSelector_DIMS12_i_tmp_tmp; vlen++) {
                rtb_BusConversion_InsertedFor_0[vlen] =
                  variance_pseudorange[n_data[vlen] - 1];
              }

              BusSelector_DIMS12_i_tmp_tmp = o_size_idx_0;
              for (vlen = 0; vlen < o_size_idx_0; vlen++) {
                tmp_data_3[vlen] =
                  GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN[o_data_0[vlen]
                  - 1];
              }

              for (vlen = 0; vlen < p_size_idx_0; vlen++) {
                rtb_BusConversion_InsertedFor_1[vlen] =
                  GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
                  [p_data_0[vlen] - 1];
              }

              kAcol = partialTrueCount;
              for (vlen = 0; vlen < partialTrueCount; vlen++) {
                tmp_data_4[vlen] =
                  GNSSPreProcessingSingleAntenn_B.GalileoE5stream.PRN[q_data_0[vlen]
                  - 1];
              }

              GNSSPreProces_calcCorrection_g0(rtb_BusConversion_InsertedFor_0,
                tmp_data_3, &o_size_idx_0, rtb_BusConversion_InsertedFor_1,
                tmp_data_4, &partialTrueCount, delta_rho_data, &p_size_idx_0);
              nz = 0;
              for (i2 = 0; i2 <
                   GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
                   i2++) {
                if (mask_all_data[i2]) {
                  rtb_dualFrequencyCorrection[i2] = delta_rho_data[nz];
                  nz++;
                }
              }
            }
          }
        }
      } else {
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_l =
          GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b;

        // MATLAB Function: '<S111>/Apply Elevation and NaN and Zero Mask' incorporates:
        //   BusCreator generated from: '<S107>/Calculate Dualfrequency Correction with E1 and E5'

        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.time_receive
          = GNSSPreProcessingSingleAntenn_B.GalileoE5stream.TOW;
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
          [0] = GNSSPreProcessingSingleAntenn_B.GalileoE5stream.basePosition[0];
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
          [1] = GNSSPreProcessingSingleAntenn_B.GalileoE5stream.basePosition[1];
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
          [2] = GNSSPreProcessingSingleAntenn_B.GalileoE5stream.basePosition[2];
        SVID_DIMS1_0 =
          GNSSPreProcessingSingleAnten_DW.GalileoE5stream.SVID_DIMS1;
        vlen = GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
        GNSSPreProcessing_do_vectors_ig
          (GNSSPreProcessingSingleAntenn_B.GalileoE5stream.PRN, &SVID_DIMS1_0,
           GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN, &vlen, a__1_data,
           &a__1_size, iia_data, &p_size_idx_0, indx_to_isolate_data, &i2);
        if (a__1_size != 0) {
          SVID_DIMS1_0 =
            GNSSPreProcessingSingleAnten_DW.GalileoE5stream.SVID_DIMS1;
          vlen = GNSSPreProcessingSingleAnten_DW.GalileoE1stream.SVID_DIMS1;
          GNSSPreProce_calcCorrection_g0j
            (GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_TimeCorrectionPseudorange.pseudorangeCorrected,
             GNSSPreProcessingSingleAntenn_B.GalileoE5stream.PRN, &SVID_DIMS1_0,
             variance_pseudorange,
             GNSSPreProcessingSingleAntenn_B.GalileoE1stream.PRN, &vlen,
             delta_rho_data, &p_size_idx_0);
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3_e = p_size_idx_0;
          if (p_size_idx_0 - 1 >= 0) {
            std::memcpy(&rtb_dualFrequencyCorrection[0], &delta_rho_data[0],
                        static_cast<uint32_T>(p_size_idx_0) * sizeof(real_T));
          }
        } else {
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3_e =
            GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.pseudorange;
          boffset =
            (GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2
             / 2) << 1;
          kAcol = boffset - 2;
          for (vlen = 0; vlen <= kAcol; vlen += 2) {
            tmp_2 = _mm_loadu_pd
              (&GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
               [vlen]);
            _mm_storeu_pd(&rtb_dualFrequencyCorrection[vlen], _mm_mul_pd
                          (_mm_set1_pd(0.0), tmp_2));
          }

          for (vlen = boffset; vlen <
               GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
               vlen++) {
            rtb_dualFrequencyCorrection[vlen] = 0.0 *
              GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
              [vlen];
          }
        }
      }
    } else if (!GNSSPreProcessingSingleAntenn_P.E5_basedProcessing_Value) {
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_l =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu;

      // MATLAB Function: '<S111>/Apply Elevation and NaN and Zero Mask' incorporates:
      //   BusCreator generated from: '<S107>/Calculate Dualfrequency Correction with E1 and E5'

      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.time_receive =
        GNSSPreProcessingSingleAntenn_B.GalileoE1stream.TOW;
      std::memcpy(&rtb_measurementFrequency_Bus_sa[0],
                  &rtb_GnssMeasurementBase_satelli[0], 120U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus__0[0],
                  &rtb_GnssMeasurementBase_satel_0[0], 120U * sizeof(real_T));
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.PRN_i[0], &a__1_data[0], 40U *
                  sizeof(uint16_T));
      std::memcpy(&rtb_Add1[0], &variance_pseudorange[0], 40U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus_ps[0],
                  &rtb_dualFrequencyCorrection[0], 40U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus_de[0], &delta_rho_data[0], 40U *
                  sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus__1[0],
                  &rtb_BusConversion_InsertedFor_0[0], 40U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus__2[0],
                  &rtb_BusConversion_InsertedFor_1[0], 40U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus_va[0],
                  &rtb_BusConversion_InsertedFor_2[0], 40U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus__3[0],
                  &rtb_BusConversion_InsertedFor_3[0], 40U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus__4[0],
                  &rtb_BusConversion_InsertedFor_4[0], 40U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus_ca[0],
                  &rtb_BusConversion_InsertedFor_5[0], 40U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus__5[0],
                  &rtb_BusConversion_InsertedFor_6[0], 40U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus__6[0],
                  &rtb_BusConversion_InsertedFor_7[0], 40U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus__7[0],
                  &rtb_BusConversion_InsertedFor_8[0], 40U * sizeof(real_T));
      std::memcpy(&rtb_measurementFrequency_Bus_lo[0], &tmp_data[0], 40U *
                  sizeof(real32_T));
      std::memcpy(&rtb_measurementFrequency_Bus_CN[0],
                  &rtb_BusConversion_InsertedFor_9[0], 40U * sizeof(real_T));

      // MATLAB Function: '<S111>/Apply Elevation and NaN and Zero Mask' incorporates:
      //   BusCreator generated from: '<S107>/Calculate Dualfrequency Correction with E1 and E5'

      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
        [0] = GNSSPreProcessingSingleAntenn_B.GalileoE1stream.basePosition[0];
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
        [1] = GNSSPreProcessingSingleAntenn_B.GalileoE1stream.basePosition[1];
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
        [2] = GNSSPreProcessingSingleAntenn_B.GalileoE1stream.basePosition[2];
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3_e =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.pseudorange;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.pseudorange;
      boffset =
        (GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Calcu.pseudorange
         / 2) << 1;
      kAcol = boffset - 2;
      for (vlen = 0; vlen <= kAcol; vlen += 2) {
        tmp_2 = _mm_loadu_pd(&variance_pseudorange[vlen]);
        _mm_storeu_pd(&rtb_dualFrequencyCorrection[vlen], _mm_mul_pd(_mm_set1_pd
          (0.0), tmp_2));
      }

      for (vlen = boffset; vlen < c_nz; vlen++) {
        rtb_dualFrequencyCorrection[vlen] = 0.0 * variance_pseudorange[vlen];
      }
    } else {
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_l =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b;

      // MATLAB Function: '<S111>/Apply Elevation and NaN and Zero Mask' incorporates:
      //   BusCreator generated from: '<S107>/Calculate Dualfrequency Correction with E1 and E5'

      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.time_receive =
        GNSSPreProcessingSingleAntenn_B.GalileoE5stream.TOW;
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
        [0] = GNSSPreProcessingSingleAntenn_B.GalileoE5stream.basePosition[0];
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
        [1] = GNSSPreProcessingSingleAntenn_B.GalileoE5stream.basePosition[1];
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.base_position
        [2] = GNSSPreProcessingSingleAntenn_B.GalileoE5stream.basePosition[2];
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS3_e =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Cal_b.pseudorange;
      boffset =
        (GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2
         / 2) << 1;
      kAcol = boffset - 2;
      for (vlen = 0; vlen <= kAcol; vlen += 2) {
        tmp_2 = _mm_loadu_pd
          (&GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
           [vlen]);
        _mm_storeu_pd(&rtb_dualFrequencyCorrection[vlen], _mm_mul_pd(_mm_set1_pd
          (0.0), tmp_2));
      }

      for (vlen = boffset; vlen <
           GNSSPreProcessingSingleAnten_DW.GalileoE5stream.sf_TimeCorrectionPseudorange.SFunction_DIMS2;
           vlen++) {
        rtb_dualFrequencyCorrection[vlen] = 0.0 *
          GNSSPreProcessingSingleAntenn_B.GalileoE5stream.sf_TimeCorrectionPseudorange.pseudorangeCorrected
          [vlen];
      }
    }

    // End of MATLAB Function: '<S107>/Calculate Dualfrequency Correction with E1 and E5' 

    // BusSelector: '<S107>/Bus Selector1'
    GNSSPreProcessingSingleAnten_DW.BusSelector1_DIMS1 =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_l.pseudorange;

    // BusAssignment: '<S107>/Bus Assignment2'
    GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1 =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_l;
    GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1.pseudorange =
      GNSSPreProcessingSingleAnten_DW.BusSelector1_DIMS1;

    // Logic: '<S64>/Logical Operator2'
    rtb_enableKlobucharCorrection = (rtb_enable_tropospheric_correct &&
      rtb_MeasurementCorrected);

    // MATLAB Function: '<S70>/Calculate Tropospheric Corrections' incorporates:
    //   Inport: '<Root>/usePosLLHArray'

    CalculateTroposphericCorrecti_h(rtb_dayOfYear, rtb_enableKlobucharCorrection,
      GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
      GNSSPreProcessingSingleAntenn_B.sf_CreateSatelliteElevationMa_a.elevationAngle,
      &GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMa_a.SFunction_DIMS3,
      &GNSSPreProcessingSingleAntenn_B.sf_CalculateTroposphericCorre_h,
      &GNSSPreProcessingSingleAnten_DW.sf_CalculateTroposphericCorre_h);

    // BusSelector: '<S70>/Bus Selector'
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS1 =
      GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1.pseudorange;

    // BusSelector: '<S107>/Bus Selector1' incorporates:
    //   Sum: '<S70>/Add1'

    c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_l.pseudorange - 1;
    boffset = (GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_l.pseudorange / 2)
      << 1;
    kAcol = boffset - 2;

    // Sum: '<S70>/Add1' incorporates:
    //   BusSelector: '<S107>/Bus Selector1'
    //   Sum: '<S107>/Add1'

    for (vlen = 0; vlen <= kAcol; vlen += 2) {
      tmp_2 = _mm_loadu_pd(&rtb_Add1[vlen]);
      tmp_0 = _mm_loadu_pd(&rtb_dualFrequencyCorrection[vlen]);
      tmp_1 = _mm_loadu_pd
        (&GNSSPreProcessingSingleAntenn_B.sf_CalculateTroposphericCorre_h.troposphericDelay
         [vlen]);
      _mm_storeu_pd(&rtb_Add1[vlen], _mm_sub_pd(_mm_sub_pd(tmp_2, tmp_0), tmp_1));
    }

    for (vlen = boffset; vlen <= c_nz; vlen++) {
      rtb_Add1[vlen] = (rtb_Add1[vlen] - rtb_dualFrequencyCorrection[vlen]) -
        GNSSPreProcessingSingleAntenn_B.sf_CalculateTroposphericCorre_h.troposphericDelay
        [vlen];
    }

    // BusAssignment: '<S70>/Bus Assignment1' incorporates:
    //   SignalConversion generated from: '<S70>/Bus Assignment1'

    GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1 =
      GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1;
    GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.pseudorange =
      GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS1;

    // MATLAB Function: '<S111>/Apply Elevation and NaN and Zero Mask' incorporates:
    //   BusAssignment: '<S107>/Bus Assignment2'
    //   BusAssignment: '<S70>/Bus Assignment1'
    //   Sum: '<S70>/Add1'

    rtb_measurementFrequency_Bus__9[0] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_position[0];
    rtb_measurementFrequency_Bus__9[1] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_position[1];
    nz =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_position[0]
      * GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_position
      [1];
    for (c_nz = 0; c_nz < nz; c_nz++) {
      rtb_measurementFrequency_Bus__8[c_nz] = std::isnan
        (rtb_measurementFrequency_Bus_sa[c_nz]);
    }

    GNSSPreProcessingSingleAn_any_m(rtb_measurementFrequency_Bus__8,
      rtb_measurementFrequency_Bus__9, mask_all_data, &kAcol);
    rtb_measurementFrequency_Bus__9[0] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_velocity[0];
    rtb_measurementFrequency_Bus__9[1] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_velocity[1];
    i2 =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_velocity[0]
      * GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_velocity
      [1];
    for (c_nz = 0; c_nz < i2; c_nz++) {
      rtb_measurementFrequency_Bus__8[c_nz] = std::isnan
        (rtb_measurementFrequency_Bus__0[c_nz]);
    }

    GNSSPreProcessingSingleAn_any_m(rtb_measurementFrequency_Bus__8,
      rtb_measurementFrequency_Bus__9, b_data, &boffset);
    c_nz = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS1;
    for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS1;
         vlen++) {
      c_data[vlen] = std::isnan(rtb_Add1[vlen]);
    }

    GNSSPreProcessingSingleA_any_m4(c_data, &c_nz, d_data, &p_size_idx_0);
    rtb_measurementFrequency_Bus__9[0] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_position[0];
    rtb_measurementFrequency_Bus__9[1] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_position[1];
    for (vlen = 0; vlen < nz; vlen++) {
      rtb_measurementFrequency_Bus__8[vlen] =
        (rtb_measurementFrequency_Bus_sa[vlen] == 0.0);
    }

    GNSSPreProcessingSingleAn_any_m(rtb_measurementFrequency_Bus__8,
      rtb_measurementFrequency_Bus__9, c_data, &c_nz);
    rtb_measurementFrequency_Bus__9[0] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_velocity[0];
    rtb_measurementFrequency_Bus__9[1] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_velocity[1];
    for (vlen = 0; vlen < i2; vlen++) {
      rtb_measurementFrequency_Bus__8[vlen] =
        (rtb_measurementFrequency_Bus__0[vlen] == 0.0);
    }

    GNSSPreProcessingSingleAn_any_m(rtb_measurementFrequency_Bus__8,
      rtb_measurementFrequency_Bus__9, tmp_data_0, &BusSelector_DIMS12_i_tmp_tmp);
    i2 = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS1;
    for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS1;
         vlen++) {
      rtb_Add1_data[vlen] = (rtb_Add1[vlen] < 1.0E+6);
    }

    GNSSPreProcessingSingleA_any_m4(rtb_Add1_data, &i2, tmp_data_1, &SVID_DIMS1);
    if ((kAcol == boffset) && ((kAcol == 1 ? boffset : kAcol) == p_size_idx_0) &&
        (((kAcol == 1 ? boffset : kAcol) == 1 ? p_size_idx_0 : kAcol == 1 ?
          boffset : kAcol) ==
         GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMa_a.SFunction_DIMS2)
        && (c_nz == BusSelector_DIMS12_i_tmp_tmp) && ((c_nz == 1 ?
          BusSelector_DIMS12_i_tmp_tmp : c_nz) == SVID_DIMS1) &&
        ((GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMa_a.SFunction_DIMS2
          == 1 ? (kAcol == 1 ? boffset : kAcol) == 1 ? p_size_idx_0 : kAcol == 1
          ? boffset : kAcol :
          GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMa_a.SFunction_DIMS2)
         == ((c_nz == 1 ? BusSelector_DIMS12_i_tmp_tmp : c_nz) == 1 ? SVID_DIMS1
             : c_nz == 1 ? BusSelector_DIMS12_i_tmp_tmp : c_nz))) {
      kAcol =
        GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMa_a.SFunction_DIMS2;
      for (vlen = 0; vlen <
           GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMa_a.SFunction_DIMS2;
           vlen++) {
        mask_all_data[vlen] =
          (GNSSPreProcessingSingleAntenn_B.sf_CreateSatelliteElevationMa_a.elevationMask
           [vlen] && ((!mask_all_data[vlen]) && (!b_data[vlen]) && (!d_data[vlen]))
           && ((!c_data[vlen]) && (!tmp_data_0[vlen]) && (!tmp_data_1[vlen])));
      }
    } else {
      GNSSPrePro_binary_expand_op_fr3(mask_all_data, &kAcol,
        GNSSPreProcessingSingleAntenn_B.sf_CreateSatelliteElevationMa_a.elevationMask,
        GNSSPreProcessingSingleAnten_DW.sf_CreateSatelliteElevationMa_a.SFunction_DIMS2,
        b_data, &boffset, d_data, &p_size_idx_0, c_data, &c_nz, tmp_data_0,
        &BusSelector_DIMS12_i_tmp_tmp, tmp_data_1, &SVID_DIMS1);
    }

    boffset = kAcol - 1;
    trueCount = 0;
    for (coffset = 0; coffset <= boffset; coffset++) {
      if (mask_all_data[coffset]) {
        trueCount++;
      }
    }

    partialTrueCount = 0;
    for (c_nz = 0; c_nz <= boffset; c_nz++) {
      if (mask_all_data[c_nz]) {
        b_data_0[partialTrueCount] = static_cast<int8_T>(c_nz + 1);
        partialTrueCount++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.satellite_position[0] =
      trueCount;
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.satellite_position[1] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_position[1];
    s_size[0] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_position[0];
    coffset =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.satellite_position[0];
    c_nz =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_position[1];
    for (vlen = 0; vlen < c_nz; vlen++) {
      for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount
           ++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.satellite_position
          [partialTrueCount + coffset * vlen] = rtb_measurementFrequency_Bus_sa
          [(s_size[0] * vlen + b_data_0[partialTrueCount]) - 1];
      }
    }

    vlen = 0;
    for (partialTrueCount = 0; partialTrueCount <= boffset; partialTrueCount++)
    {
      if (mask_all_data[partialTrueCount]) {
        vlen++;
      }
    }

    nz = vlen;
    trueCount = 0;
    for (vlen = 0; vlen <= boffset; vlen++) {
      if (mask_all_data[vlen]) {
        c_data_0[trueCount] = static_cast<int8_T>(vlen + 1);
        trueCount++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.satellite_velocity[0] = nz;
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.satellite_velocity[1] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_velocity[1];
    s_size[0] =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_velocity[0];
    coffset =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.satellite_velocity[0];
    c_nz =
      GNSSPreProcessingSingleAnten_DW.BusAssignment1_DIMS1.satellite_velocity[1];
    for (vlen = 0; vlen < c_nz; vlen++) {
      for (partialTrueCount = 0; partialTrueCount < nz; partialTrueCount++) {
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.satellite_velocity
          [partialTrueCount + coffset * vlen] = rtb_measurementFrequency_Bus__0
          [(s_size[0] * vlen + c_data_0[partialTrueCount]) - 1];
      }
    }

    kAcol = 0;
    for (trueCount = 0; trueCount <= boffset; trueCount++) {
      if (mask_all_data[trueCount]) {
        kAcol++;
      }
    }

    nz = kAcol;
    kAcol = 0;
    for (partialTrueCount = 0; partialTrueCount <= boffset; partialTrueCount++)
    {
      if (mask_all_data[partialTrueCount]) {
        d_data_0[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
        kAcol++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.PRN = nz;
    for (vlen = 0; vlen < nz; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.PRN[vlen] =
        GNSSPreProcessingSingleAntenn_B.PRN_i[d_data_0[vlen] - 1];
    }

    kAcol = 0;
    for (partialTrueCount = 0; partialTrueCount <= boffset; partialTrueCount++)
    {
      if (mask_all_data[partialTrueCount]) {
        kAcol++;
      }
    }

    nz = kAcol;
    kAcol = 0;
    for (partialTrueCount = 0; partialTrueCount <= boffset; partialTrueCount++)
    {
      if (mask_all_data[partialTrueCount]) {
        e_data[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
        kAcol++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.pseudorange = nz;
    for (vlen = 0; vlen < nz; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.pseudorange[vlen]
        = rtb_Add1[e_data[vlen] - 1];
    }

    kAcol = 0;
    for (partialTrueCount = 0; partialTrueCount <= boffset; partialTrueCount++)
    {
      if (mask_all_data[partialTrueCount]) {
        kAcol++;
      }
    }

    nz = kAcol;
    kAcol = 0;
    for (partialTrueCount = 0; partialTrueCount <= boffset; partialTrueCount++)
    {
      if (mask_all_data[partialTrueCount]) {
        f_data_0[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
        kAcol++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.pseudorange_raw = nz;
    for (vlen = 0; vlen < nz; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.pseudorange_raw
        [vlen] = rtb_measurementFrequency_Bus_ps[f_data_0[vlen] - 1];
    }

    vlen = 0;
    for (partialTrueCount = 0; partialTrueCount <= boffset; partialTrueCount++)
    {
      if (mask_all_data[partialTrueCount]) {
        vlen++;
      }
    }

    trueCount = 0;
    for (partialTrueCount = 0; partialTrueCount <= boffset; partialTrueCount++)
    {
      if (mask_all_data[partialTrueCount]) {
        g_data[trueCount] = static_cast<int8_T>(partialTrueCount + 1);
        trueCount++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.pseudorange_satclk_corrected
      = vlen;
    c_nz = vlen;
    for (vlen = 0; vlen < c_nz; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.pseudorange_satclk_corrected
        [vlen] = rtb_Add1[g_data[vlen] - 1];
    }

    kAcol = 0;
    for (partialTrueCount = 0; partialTrueCount <= boffset; partialTrueCount++)
    {
      if (mask_all_data[partialTrueCount]) {
        kAcol++;
      }
    }

    nz = kAcol;
    kAcol = 0;
    for (partialTrueCount = 0; partialTrueCount <= boffset; partialTrueCount++)
    {
      if (mask_all_data[partialTrueCount]) {
        h_data_0[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
        kAcol++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.deltarange = nz;
    for (vlen = 0; vlen < nz; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.deltarange[vlen]
        = rtb_measurementFrequency_Bus_de[h_data_0[vlen] - 1];
    }

    partialTrueCount = 0;
    for (vlen = 0; vlen <= boffset; vlen++) {
      if (mask_all_data[vlen]) {
        partialTrueCount++;
      }
    }

    trueCount = 0;
    for (vlen = 0; vlen <= boffset; vlen++) {
      if (mask_all_data[vlen]) {
        i_data_0[trueCount] = static_cast<int8_T>(vlen + 1);
        trueCount++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.deltarange_raw =
      partialTrueCount;
    for (vlen = 0; vlen < partialTrueCount; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.deltarange_raw[
        vlen] = rtb_measurementFrequency_Bus__1[i_data_0[vlen] - 1];
    }

    nz = 0;
    for (vlen = 0; vlen <= boffset; vlen++) {
      if (mask_all_data[vlen]) {
        nz++;
      }
    }

    i2 = nz;
    nz = 0;
    for (vlen = 0; vlen <= boffset; vlen++) {
      if (mask_all_data[vlen]) {
        j_data_1[nz] = static_cast<int8_T>(vlen + 1);
        nz++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.deltarange_satclk_corrected
      = i2;
    for (vlen = 0; vlen < i2; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.deltarange_satclk_corrected
        [vlen] = rtb_measurementFrequency_Bus__2[j_data_1[vlen] - 1];
    }

    nz = 0;
    for (vlen = 0; vlen <= boffset; vlen++) {
      if (mask_all_data[vlen]) {
        nz++;
      }
    }

    BusSelector_DIMS12_i_tmp_tmp = nz;
    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        k_data_1[nz] = static_cast<int8_T>(i2 + 1);
        nz++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.variance_pseudorange =
      BusSelector_DIMS12_i_tmp_tmp;
    for (vlen = 0; vlen < BusSelector_DIMS12_i_tmp_tmp; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.variance_pseudorange
        [vlen] = rtb_measurementFrequency_Bus_va[k_data_1[vlen] - 1];
    }

    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        nz++;
      }
    }

    o_size_idx_0 = nz;
    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        l_data_0[nz] = static_cast<int8_T>(i2 + 1);
        nz++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.variance_pseudorange_measured
      = o_size_idx_0;
    for (vlen = 0; vlen < o_size_idx_0; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.variance_pseudorange_measured
        [vlen] = rtb_measurementFrequency_Bus__3[l_data_0[vlen] - 1];
    }

    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        nz++;
      }
    }

    kAcol = nz;
    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        m_data_0[nz] = static_cast<int8_T>(i2 + 1);
        nz++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.variance_deltarange =
      kAcol;
    for (vlen = 0; vlen < kAcol; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.variance_deltarange
        [vlen] = rtb_measurementFrequency_Bus__4[m_data_0[vlen] - 1];
    }

    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        nz++;
      }
    }

    BusSelector_DIMS12_i_tmp_tmp = nz;
    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        n_data_0[nz] = static_cast<int8_T>(i2 + 1);
        nz++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.carrierphase =
      BusSelector_DIMS12_i_tmp_tmp;
    for (vlen = 0; vlen < BusSelector_DIMS12_i_tmp_tmp; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.carrierphase[vlen]
        = rtb_measurementFrequency_Bus_ca[n_data_0[vlen] - 1];
    }

    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        nz++;
      }
    }

    o_size_idx_0 = nz;
    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        o_data_1[nz] = static_cast<int8_T>(i2 + 1);
        nz++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.carrierphase_raw =
      o_size_idx_0;
    for (vlen = 0; vlen < o_size_idx_0; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.carrierphase_raw
        [vlen] = rtb_measurementFrequency_Bus__5[o_data_1[vlen] - 1];
    }

    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        nz++;
      }
    }

    p_size_idx_0 = nz;
    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        p_data_1[nz] = static_cast<int8_T>(i2 + 1);
        nz++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.carrierphase_satclk_corrected
      = p_size_idx_0;
    for (vlen = 0; vlen < p_size_idx_0; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.carrierphase_satclk_corrected
        [vlen] = rtb_measurementFrequency_Bus__6[p_data_1[vlen] - 1];
    }

    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        nz++;
      }
    }

    c_nz = nz;
    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        q_data_1[nz] = static_cast<int8_T>(i2 + 1);
        nz++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.variance_carrierphase_measured
      = c_nz;
    for (vlen = 0; vlen < c_nz; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.variance_carrierphase_measured
        [vlen] = rtb_measurementFrequency_Bus__7[q_data_1[vlen] - 1];
    }

    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        nz++;
      }
    }

    c_nz = nz;
    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        r_data_0[nz] = static_cast<int8_T>(i2 + 1);
        nz++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.locktime = c_nz;
    for (vlen = 0; vlen < c_nz; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.locktime[vlen]
        = rtb_measurementFrequency_Bus_lo[r_data_0[vlen] - 1];
    }

    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        nz++;
      }
    }

    c_nz = nz;
    nz = 0;
    for (i2 = 0; i2 <= boffset; i2++) {
      if (mask_all_data[i2]) {
        s_data_0[nz] = static_cast<int8_T>(i2 + 1);
        nz++;
      }
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h.CN0 = c_nz;
    for (vlen = 0; vlen < c_nz; vlen++) {
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect.CN0[vlen] =
        rtb_measurementFrequency_Bus_CN[s_data_0[vlen] - 1];
    }

    // MATLAB Function: '<S111>/Apply Differential Correction Mask1' incorporates:
    //   Inport: '<Root>/RTCM_3_3_L1_E1_Bus'
    //   MATLAB Function: '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'

    ApplyDifferentialCorrectionMa_b
      (&GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorrect,
       &GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_h,
       GNSSPreProcessingSingleAntenn_B.sf_CalculateDifferentialCorre_l.diffPseudorangeCorrection,
       GNSSPreProcessingSingleAntenn_B.sf_CalculateDifferentialCorre_l.maskDiffCorr,
       &GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorre_l.SFunction_DIMS3,
       rtb_enable_differential_correct,
       GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus.base,
       &rtb_MeasurementCorrected,
       &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b,
       &GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b);

    // BusSelector: '<S12>/Bus Selector'
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2[0] =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.satellite_position
      [0];
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2[1] =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.satellite_position
      [1];
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3[0] =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.satellite_velocity
      [0];
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3[1] =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.satellite_velocity
      [1];
    nz =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.PRN;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.PRN;
    vlen =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.pseudorange;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.pseudorange;
    trueCount =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.pseudorange_raw;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.pseudorange_raw;
    i2 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.pseudorange_satclk_corrected;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.pseudorange_satclk_corrected;
    kAcol =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.deltarange;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.deltarange;
    boffset =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.deltarange_raw;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.deltarange_raw;
    partialTrueCount =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.deltarange_satclk_corrected;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.deltarange_satclk_corrected;
    coffset =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.variance_pseudorange;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.variance_pseudorange;
    BusSelector_DIMS12_i_tmp_tmp =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.variance_pseudorange_measured;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.variance_pseudorange_measured;
    o_size_idx_0 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.variance_deltarange;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.variance_deltarange;
    p_size_idx_0 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.carrierphase;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.carrierphase;
    a__1_size =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.carrierphase_raw;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.carrierphase_raw;
    SVID_DIMS1 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.carrierphase_satclk_corrected;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.carrierphase_satclk_corrected;
    SVID_DIMS1_0 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.variance_carrierphase_measured;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.variance_carrierphase_measured;
    BusSelector_DIMS18_o_tmp_tmp =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.locktime;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.locktime;
    BusSelector_DIMS19_a_tmp_tmp =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.CN0;
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19 =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.CN0;

    // BusSelector: '<S12>/Bus Selector'
    GNSSPreProcessingSingleAntenn_B.time_receive =
      GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.time_receive;

    // BusSelector: '<S12>/Bus Selector'
    c_nz =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.satellite_position
      [0] *
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.satellite_position
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.satellite_position[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.satellite_position
                  [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    c_nz =
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.satellite_velocity
      [0] *
      GNSSPreProcessingSingleAnten_DW.sf_ApplyDifferentialCorrectio_b.SFunction_DIMS2.satellite_velocity
      [1];
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.satellite_velocity[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.satellite_velocity
                  [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    if (nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.PRN[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.PRN
                  [0], static_cast<uint32_T>(nz) * sizeof(uint16_T));
    }

    if (vlen - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.pseudorange[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.pseudorange
                  [0], static_cast<uint32_T>(vlen) * sizeof(real_T));
    }

    if (trueCount - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.pseudorange_raw[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.pseudorange_raw
                  [0], static_cast<uint32_T>(trueCount) * sizeof(real_T));
    }

    if (i2 - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.pseudorange_satclk_corrected
                  [0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.pseudorange_satclk_corrected
                  [0], static_cast<uint32_T>(i2) * sizeof(real_T));
    }

    if (kAcol - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.deltarange[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.deltarange
                  [0], static_cast<uint32_T>(kAcol) * sizeof(real_T));
    }

    if (boffset - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.deltarange_raw[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.deltarange_raw
                  [0], static_cast<uint32_T>(boffset) * sizeof(real_T));
    }

    if (partialTrueCount - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.deltarange_satclk_corrected[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.deltarange_satclk_corrected
                  [0], static_cast<uint32_T>(partialTrueCount) * sizeof(real_T));
    }

    if (coffset - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.variance_pseudorange[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.variance_pseudorange
                  [0], static_cast<uint32_T>(coffset) * sizeof(real_T));
    }

    if (BusSelector_DIMS12_i_tmp_tmp - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.variance_pseudorange_measured[0],
         &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.variance_pseudorange_measured
         [0], static_cast<uint32_T>(BusSelector_DIMS12_i_tmp_tmp) * sizeof
         (real_T));
    }

    if (o_size_idx_0 - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.variance_deltarange[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.variance_deltarange
                  [0], static_cast<uint32_T>(o_size_idx_0) * sizeof(real_T));
    }

    if (p_size_idx_0 - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.carrierphase[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.carrierphase
                  [0], static_cast<uint32_T>(p_size_idx_0) * sizeof(real_T));
    }

    if (a__1_size - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.carrierphase_raw[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.carrierphase_raw
                  [0], static_cast<uint32_T>(a__1_size) * sizeof(real_T));
    }

    if (SVID_DIMS1 - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.carrierphase_satclk_corrected[0],
         &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.carrierphase_satclk_corrected
         [0], static_cast<uint32_T>(SVID_DIMS1) * sizeof(real_T));
    }

    if (SVID_DIMS1_0 - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.variance_carrierphase_measured[0],
         &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.variance_carrierphase_measured
         [0], static_cast<uint32_T>(SVID_DIMS1_0) * sizeof(real_T));
    }

    if (BusSelector_DIMS18_o_tmp_tmp - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.locktime[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.locktime
                  [0], static_cast<uint32_T>(BusSelector_DIMS18_o_tmp_tmp) *
                  sizeof(real32_T));
    }

    if (BusSelector_DIMS19_a_tmp_tmp - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.CN0[0],
                  &GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.CN0
                  [0], static_cast<uint32_T>(BusSelector_DIMS19_a_tmp_tmp) *
                  sizeof(real_T));
    }

    // BusSelector: '<S12>/Bus Selector'
    GNSSPreProcessingSingleAntenn_B.base_position[0] =
      GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.base_position
      [0];
    GNSSPreProcessingSingleAntenn_B.base_position[1] =
      GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.base_position
      [1];
    GNSSPreProcessingSingleAntenn_B.base_position[2] =
      GNSSPreProcessingSingleAntenn_B.sf_ApplyDifferentialCorrectio_b.GPS_measurement_Bus_masked.base_position
      [2];

    // BusSelector: '<S107>/Bus Selector'
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS1_g =
      GNSSPreProcessingSingleAnten_DW.BusAssignment2_DIMS1.PRN;

    // Logic: '<S70>/Logical Operator2' incorporates:
    //   Logic: '<S70>/Logical Operator'

    GNSSPreProcessingSingleAntenn_B.LogicalOperator2 =
      ((rtb_enableKlobucharCorrection && rtb_enableDualFrequencyCorrecti) ||
       rtb_MeasurementCorrected);
  }

  // End of Outputs for SubSystem: '<S3>/Galileo'

  // MATLAB Function: '<S3>/Fuse' incorporates:
  //   BusSelector: '<S107>/Bus Selector'

  a__1_size = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_ho +
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS1_g;
  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_ho; vlen
       ++) {
    a__1_data[vlen] = GNSSPreProcessingSingleAntenn_B.SvidCarrierInUse[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS1_g;
       vlen++) {
    a__1_data[vlen + GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_ho] =
      GNSSPreProcessingSingleAntenn_B.PRN_i[vlen];
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_px = a__1_size;

  // Outport: '<Root>/SVIDCarrierUse' incorporates:
  //   MATLAB Function: '<S3>/Fuse'

  if (a__1_size - 1 >= 0) {
    std::memcpy(&GNSSPreProcessingSingleAntenn_Y.SVIDCarrierUse[0], &a__1_data[0],
                static_cast<uint32_T>(a__1_size) * sizeof(uint16_T));
  }

  // End of Outport: '<Root>/SVIDCarrierUse'
  for (coffset = 0; coffset < 40; coffset++) {
    // Outport: '<Root>/diffPsedorangeCorrections' incorporates:
    //   MATLAB Function: '<S3>/mergeDiffCorrections'

    GNSSPreProcessingSingleAntenn_Y.diffPsedorangeCorrections[coffset] = 0.0;

    // Outport: '<Root>/diffSVIDCorrections' incorporates:
    //   MATLAB Function: '<S3>/mergeDiffCorrections'

    GNSSPreProcessingSingleAntenn_Y.diffSVIDCorrections[coffset] = MAX_uint16_T;
  }

  // MATLAB Function: '<S3>/mergeDiffCorrections' incorporates:
  //   Outport: '<Root>/diffPsedorangeCorrections'
  //   Outport: '<Root>/diffSVIDCorrections'

  if (GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorrect.SFunction_DIMS3
      < 1) {
    c_nz = -1;
  } else {
    c_nz =
      GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorrect.SFunction_DIMS3
      - 1;
  }

  if (c_nz >= 0) {
    std::memcpy(&GNSSPreProcessingSingleAntenn_Y.diffSVIDCorrections[0],
                &GNSSPreProcessingSingleAntenn_B.sf_CalculateDifferentialCorrect.maskDiffCorr
                [0], static_cast<uint32_T>(c_nz + 1) * sizeof(uint16_T));
  }

  c_nz = static_cast<int8_T>
    (GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorre_l.SFunction_DIMS3)
    - 1;
  for (vlen = 0; vlen <= c_nz; vlen++) {
    f_data[vlen] = static_cast<int8_T>(static_cast<int8_T>(vlen +
      static_cast<int8_T>
      (GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorrect.SFunction_DIMS3))
      + 1);
  }

  if (GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorre_l.SFunction_DIMS3
      < 1) {
    c_nz = -1;
  } else {
    c_nz =
      GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorre_l.SFunction_DIMS3
      - 1;
  }

  for (vlen = 0; vlen <= c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_Y.diffSVIDCorrections[f_data[vlen] - 1] =
      GNSSPreProcessingSingleAntenn_B.sf_CalculateDifferentialCorre_l.maskDiffCorr
      [vlen];
  }

  if (GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorrect.SFunction_DIMS3
      < 1) {
    c_nz = -1;
  } else {
    c_nz =
      GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorrect.SFunction_DIMS3
      - 1;
  }

  if (c_nz >= 0) {
    std::memcpy(&GNSSPreProcessingSingleAntenn_Y.diffPsedorangeCorrections[0],
                &GNSSPreProcessingSingleAntenn_B.sf_CalculateDifferentialCorrect.diffPseudorangeCorrection
                [0], static_cast<uint32_T>(c_nz + 1) * sizeof(real_T));
  }

  if (GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorre_l.SFunction_DIMS3
      < 1) {
    c_nz = -1;
  } else {
    c_nz =
      GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorre_l.SFunction_DIMS3
      - 1;
  }

  for (vlen = 0; vlen <= c_nz; vlen++) {
    GNSSPreProcessingSingleAntenn_Y.diffPsedorangeCorrections[f_data[vlen] - 1] =
      GNSSPreProcessingSingleAntenn_B.sf_CalculateDifferentialCorre_l.diffPseudorangeCorrection
      [vlen];
  }

  // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
  //   BusSelector: '<S11>/Bus Selector'

  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_position
    [0] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2_a[0];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_velocity
    [0] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3_a[0];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_position
    [1] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2_a[1];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_velocity
    [1] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3_a[1];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.PRN =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4_b;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.pseudorange =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5_e;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.pseudorange_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6_d;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.pseudorange_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7_i;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8_m;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9_i;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10_f;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_pseudorange
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11_c;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_pseudorange_measured
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12_i;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_deltarange
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13_j;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14_f;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15_g;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16_k;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_carrierphase_measured
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17_d;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.locktime =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18_o;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.CN0 =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19_a;
  GNSSPreProcessingSingleAntenn_B.GalMeasurementB.time_receive =
    GNSSPreProcessingSingleAntenn_B.time_receive_b;
  c_nz = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2_a[0] *
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2_a[1];
  if (c_nz - 1 >= 0) {
    std::memcpy
      (&GNSSPreProcessingSingleAntenn_B.GalMeasurementB.satellite_position[0],
       &GNSSPreProcessingSingleAntenn_B.satellite_position_o[0],
       static_cast<uint32_T>(c_nz) * sizeof(real_T));
  }

  c_nz = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3_a[0] *
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3_a[1];
  if (c_nz - 1 >= 0) {
    std::memcpy
      (&GNSSPreProcessingSingleAntenn_B.GalMeasurementB.satellite_velocity[0],
       &GNSSPreProcessingSingleAntenn_B.satellite_velocity_p[0],
       static_cast<uint32_T>(c_nz) * sizeof(real_T));
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4_b;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.PRN[vlen] =
      GNSSPreProcessingSingleAntenn_B.PRN_b[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5_e;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.pseudorange[vlen] =
      GNSSPreProcessingSingleAntenn_B.pseudorange_l[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6_d;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.pseudorange_raw[vlen] =
      GNSSPreProcessingSingleAntenn_B.pseudorange_raw_k[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7_i;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.pseudorange_satclk_corrected[
      vlen] =
      GNSSPreProcessingSingleAntenn_B.pseudorange_satclk_corrected_a[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8_m;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange[vlen] =
      GNSSPreProcessingSingleAntenn_B.deltarange_h[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9_i;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange_raw[vlen] =
      GNSSPreProcessingSingleAntenn_B.deltarange_raw_k[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10_f;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange_satclk_corrected[vlen]
      = GNSSPreProcessingSingleAntenn_B.deltarange_satclk_corrected_n[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11_c;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_pseudorange[vlen] =
      GNSSPreProcessingSingleAntenn_B.variance_pseudorange_g[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12_i;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_pseudorange_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.variance_pseudorange_measured_i[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13_j;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_deltarange[vlen] =
      GNSSPreProcessingSingleAntenn_B.variance_deltarange_n[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14_f;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase[vlen] =
      GNSSPreProcessingSingleAntenn_B.carrierphase_a[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15_g;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase_raw[vlen] =
      GNSSPreProcessingSingleAntenn_B.carrierphase_raw_c[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16_k;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase_satclk_corrected
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.carrierphase_satclk_corrected_m[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17_d;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_carrierphase_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.variance_carrierphase_measure_o[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18_o;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.locktime[vlen] =
      GNSSPreProcessingSingleAntenn_B.locktime_k[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19_a;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB.CN0[vlen] =
      GNSSPreProcessingSingleAntenn_B.CN0_f[vlen];
  }

  GNSSPreProcessingSingleAntenn_B.GalMeasurementB.base_position[0] =
    GNSSPreProcessingSingleAntenn_B.base_position_b[0];
  GNSSPreProcessingSingleAntenn_B.GalMeasurementB.base_position[1] =
    GNSSPreProcessingSingleAntenn_B.base_position_b[1];
  GNSSPreProcessingSingleAntenn_B.GalMeasurementB.base_position[2] =
    GNSSPreProcessingSingleAntenn_B.base_position_b[2];

  // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
  //   BusSelector: '<S12>/Bus Selector'
  //   MATLAB Function: '<S3>/Merge GNSS Measurement'

  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.satellite_position
    [0] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2[0];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.satellite_velocity
    [0] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3[0];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.satellite_position
    [1] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2[1];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.satellite_velocity
    [1] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3[1];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.PRN =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.pseudorange =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.pseudorange_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.pseudorange_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.deltarange =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.deltarange_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.deltarange_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.variance_pseudorange
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.variance_pseudorange_measured
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.variance_deltarange
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.carrierphase =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.carrierphase_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.carrierphase_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.variance_carrierphase_measured
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.locktime =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f.CN0 =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19;
  GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.time_receive =
    GNSSPreProcessingSingleAntenn_B.time_receive;
  nz = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2[0] *
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2[1];
  if (nz - 1 >= 0) {
    std::memcpy
      (&GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.satellite_position
       [0], &GNSSPreProcessingSingleAntenn_B.satellite_position[0],
       static_cast<uint32_T>(nz) * sizeof(real_T));
  }

  i2 = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3[0] *
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3[1];
  if (i2 - 1 >= 0) {
    std::memcpy
      (&GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.satellite_velocity
       [0], &GNSSPreProcessingSingleAntenn_B.satellite_velocity[0],
       static_cast<uint32_T>(i2) * sizeof(real_T));
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.PRN[vlen] =
      GNSSPreProcessingSingleAntenn_B.PRN[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.pseudorange[vlen]
      = GNSSPreProcessingSingleAntenn_B.pseudorange[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.pseudorange_raw[vlen]
      = GNSSPreProcessingSingleAntenn_B.pseudorange_raw[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.pseudorange_satclk_corrected
      [vlen] = GNSSPreProcessingSingleAntenn_B.pseudorange_satclk_corrected[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.deltarange[vlen]
      = GNSSPreProcessingSingleAntenn_B.deltarange[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.deltarange_raw[vlen]
      = GNSSPreProcessingSingleAntenn_B.deltarange_raw[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.deltarange_satclk_corrected
      [vlen] = GNSSPreProcessingSingleAntenn_B.deltarange_satclk_corrected[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.variance_pseudorange
      [vlen] = GNSSPreProcessingSingleAntenn_B.variance_pseudorange[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.variance_pseudorange_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.variance_pseudorange_measured[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.variance_deltarange
      [vlen] = GNSSPreProcessingSingleAntenn_B.variance_deltarange[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.carrierphase[vlen]
      = GNSSPreProcessingSingleAntenn_B.carrierphase[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.carrierphase_raw[
      vlen] = GNSSPreProcessingSingleAntenn_B.carrierphase_raw[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.carrierphase_satclk_corrected
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.carrierphase_satclk_corrected[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.variance_carrierphase_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.variance_carrierphase_measured[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.locktime[vlen] =
      GNSSPreProcessingSingleAntenn_B.locktime[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.CN0[vlen] =
      GNSSPreProcessingSingleAntenn_B.CN0[vlen];
  }

  GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.base_position[0] =
    GNSSPreProcessingSingleAntenn_B.base_position[0];
  GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.base_position[1] =
    GNSSPreProcessingSingleAntenn_B.base_position[1];
  GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i.base_position[2] =
    GNSSPreProcessingSingleAntenn_B.base_position[2];

  // MATLAB Function: '<S3>/Dummy GNSS Measurement'
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.time_receive = 0.0;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.satellite_position
    [0] = 0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.satellite_position[0] = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.satellite_velocity[0] = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.satellite_position[1] = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.satellite_velocity[1] = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.satellite_velocity
    [0] = 0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.PRN = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.PRN[0] = 0U;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.pseudorange = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.pseudorange[0] =
    0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.pseudorange_raw = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.pseudorange_raw[0] =
    0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.pseudorange_satclk_corrected
    = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.pseudorange_satclk_corrected
    [0] = 0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.deltarange = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.deltarange[0] = 0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.deltarange_raw = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.deltarange_raw[0] =
    0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.deltarange_satclk_corrected =
    1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.deltarange_satclk_corrected
    [0] = 0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.variance_pseudorange = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.variance_pseudorange
    [0] = 0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.variance_pseudorange_measured
    = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.variance_pseudorange_measured
    [0] = 0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.variance_deltarange = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.variance_deltarange[
    0] = 0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.carrierphase = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.carrierphase[0] =
    0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.carrierphase_raw = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.carrierphase_raw[0]
    = 0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.carrierphase_satclk_corrected
    = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.carrierphase_satclk_corrected
    [0] = 0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.variance_carrierphase_measured
    = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.variance_carrierphase_measured
    [0] = 0.0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.locktime = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.locktime[0] = 0.0F;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p.CN0 = 1;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.CN0[0] = 0.0;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.base_position[0] =
    0.0;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.base_position[1] =
    0.0;
  GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus.base_position[2] =
    0.0;

  // BusCreator generated from: '<S3>/Merge GNSS Measurement'
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gps.enable_gps
    = rtb_FixPtRelationalOperator;
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gps.enable_gps_l1
    = rtb_enable_gps_l1;
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gps.enable_gps_l2
    = rtb_enable_gps_l2;

  // BusCreator generated from: '<S3>/Merge GNSS Measurement'
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.galileo.enable_galileo
    = rtb_enable_galileo;
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.galileo.enable_galileo_e1
    = rtb_enable_galileo_e1;
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.galileo.enable_galileo_e5a
    = rtb_enable_galileo_e5a;
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.galileo.enable_galileo_e5b
    = rtb_enable_galileo_e5b;
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.galileo.enable_galileo_e5
    = rtb_enable_galileo_e5;

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_9_Threshold) {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement'
    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.enable_gate
      = GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.enable_gate;
  } else {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
    //   Inport: '<Root>/GNSSParametersBus'

    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.enable_gate
      = GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gate.enable_gate;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_10_Threshold) {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement'
    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl1
      = GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl1;
  } else {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
    //   Inport: '<Root>/GNSSParametersBus'

    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl1
      = GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gate.prn_psl1;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_11_Threshold) {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement'
    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl2
      = GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl2;
  } else {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
    //   Inport: '<Root>/GNSSParametersBus'

    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl2
      = GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gate.prn_psl2;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_12_Threshold) {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement'
    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl3
      = GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl3;
  } else {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
    //   Inport: '<Root>/GNSSParametersBus'

    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl3
      = GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gate.prn_psl3;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_13_Threshold) {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement'
    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl4
      = GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl4;
  } else {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
    //   Inport: '<Root>/GNSSParametersBus'

    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl4
      = GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gate.prn_psl4;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_14_Threshold) {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement'
    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl5
      = GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl5;
  } else {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
    //   Inport: '<Root>/GNSSParametersBus'

    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl5
      = GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gate.prn_psl5;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_15_Threshold) {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement'
    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl6
      = GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl6;
  } else {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
    //   Inport: '<Root>/GNSSParametersBus'

    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl6
      = GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gate.prn_psl6;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_16_Threshold) {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement'
    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl7
      = GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl7;
  } else {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
    //   Inport: '<Root>/GNSSParametersBus'

    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl7
      = GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gate.prn_psl7;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_17_Threshold) {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement'
    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl8
      = GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl8;
  } else {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
    //   Inport: '<Root>/GNSSParametersBus'

    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl8
      = GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gate.prn_psl8;
  }

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_18_Threshold) {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement'
    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl9
      = GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl9;
  } else {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
    //   Inport: '<Root>/GNSSParametersBus'

    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.prn_psl9
      = GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gate.prn_psl9;
  }

  // BusCreator generated from: '<S3>/Merge GNSS Measurement'
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.elevation_mask
    = rtb_elevation_mask;

  // Switch generated from: '<S3>/Switch' incorporates:
  //   Inport: '<Root>/useModeSwitchLogic'

  if (GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic >
      GNSSPreProcessingSingleAntenn_P.Switch_20_Threshold) {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement'
    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.enable_galileo_timebase
      = GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_galileo_timebase;
  } else {
    // BusCreator generated from: '<S3>/Merge GNSS Measurement' incorporates:
    //   Inport: '<Root>/GNSSParametersBus'

    GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.enable_galileo_timebase
      =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.enable_galileo_timebase;
  }

  // BusCreator generated from: '<S3>/Merge GNSS Measurement'
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.enable_differential_correction
    = rtb_enable_differential_correct;
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.enable_tropospheric_correction
    = rtb_enable_tropospheric_correct;
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.enable_ionospheric_correction
    = rtb_enable_ionospheric_correcti;
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.enable_SatPosVel_calculation
    = rtb_enable_SatPosVel_calculatio;
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.enable_WL_correction
    = rtb_enable_WL_correction;
  GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.use_measured_variance
    = rtb_use_measured_variance;

  // MATLAB Function: '<S3>/Merge GNSS Measurement' incorporates:
  //   BusCreator generated from: '<S3>/Merge GNSS Measurement'
  //   BusSelector: '<S11>/Bus Selector'
  //   BusSelector: '<S12>/Bus Selector'
  //   Inport: '<Root>/GALGSTGPSBus'
  //   Inport: '<Root>/enableGGTO'
  //   Inport: '<Root>/enableGNSSMerge'
  //
  rtb_FixPtRelationalOperator = false;
  rtb_dayOfYear = 0.0;
  rtb_MeasurementCorrected =
    (GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gps.enable_gps
     &&
     GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.galileo.enable_galileo);
  if (rtb_MeasurementCorrected &&
      GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.enable_gate
      && GNSSPreProcessingSingleAntenn_U.enableGNSSMerge) {
    tmp_9 = &GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge;
    tmp_a = &GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f;
    GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data =
      GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus;
    galileo_measurement_temp_elems_ =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p;
    emxConvertStructToEmx_GNSS_Meas(&GNSSPreProcessingSingleAntenn_B.r,
      &GNSSPreProcessingSingleAntenn_B.GalMeasurementB, tmp_9);
    emxConvertStructToEmx_GNSS_Meas(&GNSSPreProcessingSingleAntenn_B.r1,
      &GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i, tmp_a);
    emxConvertStructToEmx_GNSS_Meas
      (&GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp,
       &GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data,
       &galileo_measurement_temp_elems_);
    GNSSPreProcessingSin_mergeMyBus(&GNSSPreProcessingSingleAntenn_B.r,
      &GNSSPreProcessingSingleAntenn_B.r1,
      &GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp,
      &GNSSPreProcessingSingleAntenn_B.expl_temp_m);
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.time_receive =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.time_receive;
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[0];
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[1];
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[0]
      * GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_position
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_velocity[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[0];
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_velocity[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[1];
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[0]
      * GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_velocity
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.PRN =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(uint16_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange_satclk_corrected =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_pseudorange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_pseudorange_measured
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange_measured
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_deltarange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_deltarange[
         0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_carrierphase_measured
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_carrierphase_measured
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.locktime =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.locktime[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(real32_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.CN0 =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.CN0[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[0];
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[1];
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[2] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[2];
  } else if (rtb_MeasurementCorrected &&
             GNSSPreProcessingSingleAntenn_U.enableGNSSMerge) {
    if (!(GNSSPreProcessingSingleAntenn_U.enableGGTO != 0.0)) {
      tmp_9 = &GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge;
      tmp_a = &GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f;
      emxConvertStructToEmx_GNSS_Meas(&GNSSPreProcessingSingleAntenn_B.r,
        &GNSSPreProcessingSingleAntenn_B.GalMeasurementB, tmp_9);
      emxConvertStructToEmx_GNSS_Meas(&GNSSPreProcessingSingleAntenn_B.r1,
        &GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i, tmp_a);
      GNSSPreProcessingS_mergeMyBus_c(&GNSSPreProcessingSingleAntenn_B.r,
        &GNSSPreProcessingSingleAntenn_B.r1,
        &GNSSPreProcessingSingleAntenn_B.expl_temp_m);
      rtb_dayOfYear = GNSSPr_calc_delta_T_GNSS_system
        (GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.data,
         GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size,
         GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.data,
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.size,
         GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.data,
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.size) *
        2.99792458E+8;
    } else {
      rtb_FixPtRelationalOperator = true;
      rtb_dayOfYear = GNSSPreProces_GGTO_delta_T_GNSS
        (GNSSPreProcessingSingleAntenn_U.GALGSTGPSBus.A_1G,
         GNSSPreProcessingSingleAntenn_U.GALGSTGPSBus.A_0G,
         GNSSPreProcessingSingleAntenn_U.GALGSTGPSBus.t_oG,
         GNSSPreProcessingSingleAntenn_U.GALGSTGPSBus.WN_oG, TOW, WNc) *
        2.99792458E+8;
    }

    if (GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.enable_galileo_timebase)
    {
      GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data =
        GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i;
      galileo_measurement_temp_elems_ =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f;
      GNSSPreProcessingSingleAntenn_B.expl_temp.time_receive =
        GNSSPreProcessingSingleAntenn_B.time_receive_b;
      GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_position.size[0] =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_position
        [0];
      GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_position.size[1] =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_position
        [1];
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_position
        [0] *
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_position
        [1];
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_position.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.satellite_position[0],
           static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_velocity.size[0] =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_velocity
        [0];
      GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_velocity.size[1] =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_velocity
        [1];
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_velocity
        [0] *
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_velocity
        [1];
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_velocity.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.satellite_velocity[0],
           static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.PRN.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.PRN;
      c_nz = GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.PRN;
      if (c_nz - 1 >= 0) {
        std::memcpy(&GNSSPreProcessingSingleAntenn_B.expl_temp.PRN.data[0],
                    &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.PRN[0],
                    static_cast<uint32_T>(c_nz) * sizeof(uint16_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange.size =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5_e;
      boffset = (GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5_e / 2) << 1;
      kAcol = boffset - 2;
      for (vlen = 0; vlen <= kAcol; vlen += 2) {
        tmp_2 = _mm_loadu_pd(&GNSSPreProcessingSingleAntenn_B.pseudorange_l[vlen]);
        _mm_storeu_pd
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange.data[vlen],
           _mm_sub_pd(tmp_2, _mm_set1_pd(rtb_dayOfYear)));
      }

      for (vlen = boffset; vlen <
           GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5_e; vlen++) {
        GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange.data[vlen] =
          GNSSPreProcessingSingleAntenn_B.pseudorange_l[vlen] - rtb_dayOfYear;
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange_raw.size =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6_d;
      boffset = (GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6_d / 2) << 1;
      kAcol = boffset - 2;
      for (vlen = 0; vlen <= kAcol; vlen += 2) {
        tmp_2 = _mm_loadu_pd
          (&GNSSPreProcessingSingleAntenn_B.pseudorange_raw_k[vlen]);
        _mm_storeu_pd
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange_raw.data[vlen],
           _mm_sub_pd(tmp_2, _mm_set1_pd(rtb_dayOfYear)));
      }

      for (vlen = boffset; vlen <
           GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6_d; vlen++) {
        GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange_raw.data[vlen] =
          GNSSPreProcessingSingleAntenn_B.pseudorange_raw_k[vlen] -
          rtb_dayOfYear;
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange_satclk_corrected.size
        = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7_i;
      boffset = (GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7_i / 2) << 1;
      kAcol = boffset - 2;
      for (vlen = 0; vlen <= kAcol; vlen += 2) {
        tmp_2 = _mm_loadu_pd
          (&GNSSPreProcessingSingleAntenn_B.pseudorange_satclk_corrected_a[vlen]);
        _mm_storeu_pd
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange_satclk_corrected.data
           [vlen], _mm_sub_pd(tmp_2, _mm_set1_pd(rtb_dayOfYear)));
      }

      for (vlen = boffset; vlen <
           GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7_i; vlen++) {
        GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange_satclk_corrected.data
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.pseudorange_satclk_corrected_a[vlen] -
          rtb_dayOfYear;
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange;
      if (c_nz - 1 >= 0) {
        std::memcpy(&GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange.data[0],
                    &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange
                    [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange_raw.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange_raw;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange_raw;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange_raw.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange_raw[0],
           static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange_satclk_corrected.size
        =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange_satclk_corrected;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange_satclk_corrected;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange_satclk_corrected.data
           [0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange_satclk_corrected
           [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.variance_pseudorange.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_pseudorange;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_pseudorange;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.variance_pseudorange.data
           [0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_pseudorange[
           0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.variance_pseudorange_measured.size
        =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_pseudorange_measured;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_pseudorange_measured;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.variance_pseudorange_measured.data
           [0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_pseudorange_measured
           [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.variance_deltarange.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_deltarange;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_deltarange;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.variance_deltarange.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_deltarange
           [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase[0],
           static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase_raw.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase_raw;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase_raw;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase_raw.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase_raw[0],
           static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase_satclk_corrected.size
        =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase_satclk_corrected;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase_satclk_corrected;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase_satclk_corrected.data
           [0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase_satclk_corrected
           [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.variance_carrierphase_measured.size
        =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_carrierphase_measured;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_carrierphase_measured;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.variance_carrierphase_measured.data
           [0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_carrierphase_measured
           [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.locktime.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.locktime;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.locktime;
      if (c_nz - 1 >= 0) {
        std::memcpy(&GNSSPreProcessingSingleAntenn_B.expl_temp.locktime.data[0],
                    &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.locktime[0],
                    static_cast<uint32_T>(c_nz) * sizeof(real32_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.CN0.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.CN0;
      c_nz = GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.CN0;
      if (c_nz - 1 >= 0) {
        std::memcpy(&GNSSPreProcessingSingleAntenn_B.expl_temp.CN0.data[0],
                    &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.CN0[0],
                    static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.base_position[0] =
        GNSSPreProcessingSingleAntenn_B.base_position_b[0];
      GNSSPreProcessingSingleAntenn_B.expl_temp.base_position[1] =
        GNSSPreProcessingSingleAntenn_B.base_position_b[1];
      GNSSPreProcessingSingleAntenn_B.expl_temp.base_position[2] =
        GNSSPreProcessingSingleAntenn_B.base_position_b[2];
    } else {
      GNSSPreProcessingSingleAntenn_B.expl_temp.time_receive =
        GNSSPreProcessingSingleAntenn_B.time_receive_b;
      GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_position.size[0] =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_position
        [0];
      GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_position.size[1] =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_position
        [1];
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_position
        [0] *
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_position
        [1];
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_position.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.satellite_position[0],
           static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_velocity.size[0] =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_velocity
        [0];
      GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_velocity.size[1] =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_velocity
        [1];
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_velocity
        [0] *
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.satellite_velocity
        [1];
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.satellite_velocity.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.satellite_velocity[0],
           static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.PRN.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.PRN;
      c_nz = GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.PRN;
      if (c_nz - 1 >= 0) {
        std::memcpy(&GNSSPreProcessingSingleAntenn_B.expl_temp.PRN.data[0],
                    &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.PRN[0],
                    static_cast<uint32_T>(c_nz) * sizeof(uint16_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.pseudorange;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.pseudorange;
      if (c_nz - 1 >= 0) {
        std::memcpy(&GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange.data
                    [0],
                    &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.pseudorange[
                    0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange_raw.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.pseudorange_raw;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.pseudorange_raw;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange_raw.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.pseudorange_raw[0],
           static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange_satclk_corrected.size
        =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.pseudorange_satclk_corrected;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.pseudorange_satclk_corrected;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.pseudorange_satclk_corrected.data
           [0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.pseudorange_satclk_corrected
           [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange;
      if (c_nz - 1 >= 0) {
        std::memcpy(&GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange.data[0],
                    &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange
                    [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange_raw.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange_raw;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange_raw;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange_raw.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange_raw[0],
           static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange_satclk_corrected.size
        =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange_satclk_corrected;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.deltarange_satclk_corrected;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.deltarange_satclk_corrected.data
           [0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.deltarange_satclk_corrected
           [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.variance_pseudorange.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_pseudorange;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_pseudorange;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.variance_pseudorange.data
           [0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_pseudorange[
           0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.variance_pseudorange_measured.size
        =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_pseudorange_measured;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_pseudorange_measured;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.variance_pseudorange_measured.data
           [0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_pseudorange_measured
           [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.variance_deltarange.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_deltarange;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_deltarange;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.variance_deltarange.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_deltarange
           [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase[0],
           static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase_raw.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase_raw;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase_raw;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase_raw.data[0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase_raw[0],
           static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase_satclk_corrected.size
        =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase_satclk_corrected;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.carrierphase_satclk_corrected;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.carrierphase_satclk_corrected.data
           [0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.carrierphase_satclk_corrected
           [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.variance_carrierphase_measured.size
        =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_carrierphase_measured;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.variance_carrierphase_measured;
      if (c_nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.expl_temp.variance_carrierphase_measured.data
           [0],
           &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.variance_carrierphase_measured
           [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.locktime.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.locktime;
      c_nz =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.locktime;
      if (c_nz - 1 >= 0) {
        std::memcpy(&GNSSPreProcessingSingleAntenn_B.expl_temp.locktime.data[0],
                    &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.locktime[0],
                    static_cast<uint32_T>(c_nz) * sizeof(real32_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.CN0.size =
        GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.CN0;
      c_nz = GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge.CN0;
      if (c_nz - 1 >= 0) {
        std::memcpy(&GNSSPreProcessingSingleAntenn_B.expl_temp.CN0.data[0],
                    &GNSSPreProcessingSingleAntenn_B.GalMeasurementB.CN0[0],
                    static_cast<uint32_T>(c_nz) * sizeof(real_T));
      }

      GNSSPreProcessingSingleAntenn_B.expl_temp.base_position[0] =
        GNSSPreProcessingSingleAntenn_B.base_position_b[0];
      GNSSPreProcessingSingleAntenn_B.expl_temp.base_position[1] =
        GNSSPreProcessingSingleAntenn_B.base_position_b[1];
      GNSSPreProcessingSingleAntenn_B.expl_temp.base_position[2] =
        GNSSPreProcessingSingleAntenn_B.base_position_b[2];
      GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.time_receive
        = GNSSPreProcessingSingleAntenn_B.time_receive;
      galileo_measurement_temp_elems_.satellite_position[0] =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2[0];
      galileo_measurement_temp_elems_.satellite_position[1] =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2[1];
      if (nz - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.satellite_position
           [0], &GNSSPreProcessingSingleAntenn_B.satellite_position[0],
           static_cast<uint32_T>(nz) * sizeof(real_T));
      }

      galileo_measurement_temp_elems_.satellite_velocity[0] =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3[0];
      galileo_measurement_temp_elems_.satellite_velocity[1] =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3[1];
      if (i2 - 1 >= 0) {
        std::memcpy
          (&GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.satellite_velocity
           [0], &GNSSPreProcessingSingleAntenn_B.satellite_velocity[0],
           static_cast<uint32_T>(i2) * sizeof(real_T));
      }

      galileo_measurement_temp_elems_.PRN =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.PRN[vlen] =
          GNSSPreProcessingSingleAntenn_B.PRN[vlen];
      }

      galileo_measurement_temp_elems_.pseudorange =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5;
      boffset = (GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5 / 2) << 1;
      kAcol = boffset - 2;
      for (vlen = 0; vlen <= kAcol; vlen += 2) {
        tmp_2 = _mm_loadu_pd(&GNSSPreProcessingSingleAntenn_B.pseudorange[vlen]);
        _mm_storeu_pd
          (&GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.pseudorange
           [vlen], _mm_add_pd(tmp_2, _mm_set1_pd(rtb_dayOfYear)));
      }

      for (vlen = boffset; vlen <
           GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5; vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.pseudorange
          [vlen] = GNSSPreProcessingSingleAntenn_B.pseudorange[vlen] +
          rtb_dayOfYear;
      }

      galileo_measurement_temp_elems_.pseudorange_raw =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6;
      boffset = (GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6 / 2) << 1;
      kAcol = boffset - 2;
      for (vlen = 0; vlen <= kAcol; vlen += 2) {
        tmp_2 = _mm_loadu_pd
          (&GNSSPreProcessingSingleAntenn_B.pseudorange_raw[vlen]);
        _mm_storeu_pd
          (&GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.pseudorange_raw
           [vlen], _mm_add_pd(tmp_2, _mm_set1_pd(rtb_dayOfYear)));
      }

      for (vlen = boffset; vlen <
           GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6; vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.pseudorange_raw
          [vlen] = GNSSPreProcessingSingleAntenn_B.pseudorange_raw[vlen] +
          rtb_dayOfYear;
      }

      galileo_measurement_temp_elems_.pseudorange_satclk_corrected =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7;
      boffset = (GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7 / 2) << 1;
      kAcol = boffset - 2;
      for (vlen = 0; vlen <= kAcol; vlen += 2) {
        tmp_2 = _mm_loadu_pd
          (&GNSSPreProcessingSingleAntenn_B.pseudorange_satclk_corrected[vlen]);
        _mm_storeu_pd
          (&GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.pseudorange_satclk_corrected
           [vlen], _mm_add_pd(tmp_2, _mm_set1_pd(rtb_dayOfYear)));
      }

      for (vlen = boffset; vlen <
           GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7; vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.pseudorange_satclk_corrected
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.pseudorange_satclk_corrected[vlen] +
          rtb_dayOfYear;
      }

      galileo_measurement_temp_elems_.deltarange =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.deltarange[
          vlen] = GNSSPreProcessingSingleAntenn_B.deltarange[vlen];
      }

      galileo_measurement_temp_elems_.deltarange_raw =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.deltarange_raw
          [vlen] = GNSSPreProcessingSingleAntenn_B.deltarange_raw[vlen];
      }

      galileo_measurement_temp_elems_.deltarange_satclk_corrected =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.deltarange_satclk_corrected
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.deltarange_satclk_corrected[vlen];
      }

      galileo_measurement_temp_elems_.variance_pseudorange =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.variance_pseudorange
          [vlen] = GNSSPreProcessingSingleAntenn_B.variance_pseudorange[vlen];
      }

      galileo_measurement_temp_elems_.variance_pseudorange_measured =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.variance_pseudorange_measured
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.variance_pseudorange_measured[vlen];
      }

      galileo_measurement_temp_elems_.variance_deltarange =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.variance_deltarange
          [vlen] = GNSSPreProcessingSingleAntenn_B.variance_deltarange[vlen];
      }

      galileo_measurement_temp_elems_.carrierphase =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.carrierphase
          [vlen] = GNSSPreProcessingSingleAntenn_B.carrierphase[vlen];
      }

      galileo_measurement_temp_elems_.carrierphase_raw =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.carrierphase_raw
          [vlen] = GNSSPreProcessingSingleAntenn_B.carrierphase_raw[vlen];
      }

      galileo_measurement_temp_elems_.carrierphase_satclk_corrected =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.carrierphase_satclk_corrected
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.carrierphase_satclk_corrected[vlen];
      }

      galileo_measurement_temp_elems_.variance_carrierphase_measured =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.variance_carrierphase_measured
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.variance_carrierphase_measured[vlen];
      }

      galileo_measurement_temp_elems_.locktime =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.locktime[vlen]
          = GNSSPreProcessingSingleAntenn_B.locktime[vlen];
      }

      galileo_measurement_temp_elems_.CN0 =
        GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19;
      for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19;
           vlen++) {
        GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.CN0[vlen] =
          GNSSPreProcessingSingleAntenn_B.CN0[vlen];
      }

      GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.base_position
        [0] = GNSSPreProcessingSingleAntenn_B.base_position[0];
      GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.base_position
        [1] = GNSSPreProcessingSingleAntenn_B.base_position[1];
      GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data.base_position
        [2] = GNSSPreProcessingSingleAntenn_B.base_position[2];
    }

    emxConvertStructToEmx_GNSS_Meas
      (&GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp,
       &GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp_data,
       &galileo_measurement_temp_elems_);
    GNSSPreProcessing_mergeMyBus_cs(&GNSSPreProcessingSingleAntenn_B.expl_temp,
      &GNSSPreProcessingSingleAntenn_B.galileo_measurement_temp,
      &GNSSPreProcessingSingleAntenn_B.expl_temp_m);
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.time_receive =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.time_receive;
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[0];
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[1];
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[0]
      * GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_position
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_velocity[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[0];
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_velocity[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[1];
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[0]
      * GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_velocity
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.PRN =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(uint16_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange_satclk_corrected =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_pseudorange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_pseudorange_measured
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange_measured
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_deltarange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_deltarange[
         0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_carrierphase_measured
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_carrierphase_measured
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.locktime =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.locktime[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(real32_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.CN0 =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.CN0[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[0];
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[1];
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[2] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[2];
  } else if
      (GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gps.enable_gps
       &&
       GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.enable_gate
       && GNSSPreProcessingSingleAntenn_U.enableGNSSMerge) {
    tmp_9 = &GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge;
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i =
      GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus;
    tmp_a = &GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p;
    emxConvertStructToEmx_GNSS_Meas(&GNSSPreProcessingSingleAntenn_B.r,
      &GNSSPreProcessingSingleAntenn_B.GalMeasurementB, tmp_9);
    emxConvertStructToEmx_GNSS_Meas(&GNSSPreProcessingSingleAntenn_B.r1,
      &GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i, tmp_a);
    GNSSPreProcessingS_mergeMyBus_c(&GNSSPreProcessingSingleAntenn_B.r,
      &GNSSPreProcessingSingleAntenn_B.r1,
      &GNSSPreProcessingSingleAntenn_B.expl_temp_m);
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.time_receive =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.time_receive;
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[0];
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[1];
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[0]
      * GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_position
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_velocity[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[0];
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_velocity[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[1];
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[0]
      * GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_velocity
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.PRN =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(uint16_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange_satclk_corrected =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_pseudorange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_pseudorange_measured
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange_measured
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_deltarange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_deltarange[
         0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_carrierphase_measured
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_carrierphase_measured
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.locktime =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.locktime[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(real32_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.CN0 =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.CN0[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[0];
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[1];
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[2] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[2];
  } else if
      (GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.galileo.enable_galileo
       &&
       GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.enable_gate
       && GNSSPreProcessingSingleAntenn_U.enableGNSSMerge) {
    GNSSPreProcessingSingleAntenn_B.GalMeasurementB =
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i;
    tmp_9 = &GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f;
    GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i =
      GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus;
    tmp_a = &GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p;
    emxConvertStructToEmx_GNSS_Meas(&GNSSPreProcessingSingleAntenn_B.r,
      &GNSSPreProcessingSingleAntenn_B.GalMeasurementB, tmp_9);
    emxConvertStructToEmx_GNSS_Meas(&GNSSPreProcessingSingleAntenn_B.r1,
      &GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i, tmp_a);
    GNSSPreProcessingS_mergeMyBus_c(&GNSSPreProcessingSingleAntenn_B.r,
      &GNSSPreProcessingSingleAntenn_B.r1,
      &GNSSPreProcessingSingleAntenn_B.expl_temp_m);
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.time_receive =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.time_receive;
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[0];
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[1];
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[0]
      * GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.size[1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_position
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_position.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_velocity[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[0];
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_velocity[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[1];
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[0]
      * GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.size[1];
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_velocity
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.satellite_velocity.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.PRN =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.PRN.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(uint16_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange_satclk_corrected
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.pseudorange_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.deltarange_satclk_corrected =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.deltarange_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_pseudorange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_pseudorange_measured
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange_measured
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_pseudorange_measured.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_deltarange =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_deltarange[
         0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_deltarange.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase_raw =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase_raw[0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_raw.data[0],
         static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.carrierphase_satclk_corrected
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase_satclk_corrected
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.carrierphase_satclk_corrected.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.variance_carrierphase_measured
      =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.size;
    c_nz =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.size;
    if (c_nz - 1 >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_carrierphase_measured
         [0],
         &GNSSPreProcessingSingleAntenn_B.expl_temp_m.variance_carrierphase_measured.data
         [0], static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.locktime =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.locktime[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.locktime.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(real32_T));
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.CN0 =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.size;
    c_nz = GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.size;
    if (c_nz - 1 >= 0) {
      std::memcpy(&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.CN0[0],
                  &GNSSPreProcessingSingleAntenn_B.expl_temp_m.CN0.data[0],
                  static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[0] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[0];
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[1] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[1];
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[2] =
      GNSSPreProcessingSingleAntenn_B.expl_temp_m.base_position[2];
  } else if
      (GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gps.enable_gps)
  {
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2 =
      GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge;
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus =
      GNSSPreProcessingSingleAntenn_B.GalMeasurementB;
  } else if
      (GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.galileo.enable_galileo)
  {
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2 =
      GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Mer_f;
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus =
      GNSSPreProcessingSingleAntenn_B.measurementFrequencyCorre_i;
  } else if
      (GNSSPreProcessingSingleAntenn_B.BusConversion_InsertedFor_Mer_p.gate.enable_gate)
  {
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2 =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_p;
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus =
      GNSSPreProcessingSingleAntenn_B.dummy_GNSS_Measurement_Bus;
  } else {
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2 =
      GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Merge;
    GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus =
      GNSSPreProcessingSingleAntenn_B.GalMeasurementB;
  }

  // Outport: '<Root>/deltaSystemTimeGnss' incorporates:
  //   MATLAB Function: '<S3>/Merge GNSS Measurement'

  GNSSPreProcessingSingleAntenn_Y.deltaSystemTimeGnss = rtb_dayOfYear;

  // Outport: '<Root>/isGGTOValid' incorporates:
  //   MATLAB Function: '<S3>/Merge GNSS Measurement'

  GNSSPreProcessingSingleAntenn_Y.isGGTOValid = rtb_FixPtRelationalOperator;

  // MATLAB Function: '<S117>/MATLAB Function' incorporates:
  //   BusAssignment: '<S118>/Bus Assignment'
  //   BusCreator generated from: '<S117>/MATLAB Function'
  //   BusCreator generated from: '<S118>/calculate Variance'
  //   Inport: '<Root>/GNSSParametersBus'
  //   Inport: '<Root>/IntegrityParametersBus'
  //   MATLAB Function: '<S118>/Weighted RAIM Parity'
  //   MATLAB Function: '<S118>/calculate Variance'

  if (GNSSPreProcessingSingleAntenn_U.IntegrityParametersBus.enable_integrity) {
    // Outputs for Function Call SubSystem: '<S117>/GNSS Fault Detection Identification Exclusion' 
    rtb_MeasurementCorrected =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gps.enable_gps_l1;
    rtb_FixPtRelationalOperator =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.gps.enable_gps_l2;
    rtb_enable_gps_l1 =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.galileo.enable_galileo_e1;
    rtb_enable_gps_l2 =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.galileo.enable_galileo_e5a;
    rtb_enable_galileo =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.galileo.enable_galileo_e5b;
    rtb_enable_galileo_e1 =
      GNSSPreProcessingSingleAntenn_U.GNSSParametersBus.galileo.enable_galileo_e5;

    // MATLAB Function: '<S118>/calculate Variance' incorporates:
    //   BusCreator generated from: '<S118>/calculate Variance'
    //   Inport: '<Root>/GNSSParametersBus'
    //   Inport: '<Root>/usePosLLHArray'

    for (coffset = 0; coffset < 40; coffset++) {
      variance_pseudorange[coffset] = (rtNaN);
    }

    switch (static_cast<int32_T>
            (GNSSPreProcessingSingleAntenn_U.IntegrityParametersBus.raim_parameter.VarianceMode))
    {
     case 1:
      if (GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange < 1) {
        iter = 0;
      } else {
        iter = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange;
      }

      for (vlen = 0; vlen < iter; vlen++) {
        variance_pseudorange[vlen] = 4.0;
      }
      break;

     case 2:
      boffset = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange;
      if (GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange - 1 >= 0)
      {
        tmp_8 =
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[0];
        iter =
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[1];
      }

      for (coffset = 0; coffset < boffset; coffset++) {
        if ((GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
             1) &&
            (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
             37)) {
          WNc = 0.85;
        } else if
            ((GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
              71) &&
             (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
              102)) {
          WNc = 0.85;
        } else if
            (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
             120) {
          if (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
              140) {
            WNc = 0.85;
          } else {
            WNc = 1.0E+20;
          }
        } else {
          WNc = 1.0E+20;
        }

        tmp_size[0] = 1;
        tmp_size[1] =
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[1];
        for (vlen = 0; vlen < iter; vlen++) {
          tmp_data_2[vlen] =
            GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_position
            [tmp_8 * vlen + coffset];
        }

        calculate_Satellite_Elevation_n
          (GNSSPreProcessingSingleAntenn_U.usePosLLHArray, tmp_data_2, tmp_size,
           &TOW, &rtb_removedSats_g);
        if ((GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
             1) &&
            (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
             37)) {
          if (rtb_MeasurementCorrected && rtb_FixPtRelationalOperator) {
            rtb_dayOfYear = 0.0;
          } else {
            rtb_dayOfYear = (rt_powd_snf(0.53 - TOW / 3.1415926535897931, 3.0) *
                             16.0 + 1.0) * 0.4;
          }
        } else if
            (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
             71) {
          if (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
              102) {
            if (rtb_enable_gps_l1 && (rtb_enable_gps_l2 || rtb_enable_galileo ||
                 rtb_enable_galileo_e1)) {
              rtb_dayOfYear = 0.0;
            } else {
              rtb_dayOfYear = 2.0;
            }
          } else {
            rtb_dayOfYear = 1.0E+20;
          }
        } else {
          rtb_dayOfYear = 1.0E+20;
        }

        if (TOW >= 0.069813170079773182) {
          rtb_elevation_mask = std::sin(TOW);
          rtb_elevation_mask = 1.001 / std::sqrt(rtb_elevation_mask *
            rtb_elevation_mask + 0.002001);
        } else if ((TOW < 0.069813170079773182) && (TOW >= 0.034906585039886591))
        {
          s = std::sin(TOW);
          rtb_elevation_mask = 4.0 - TOW * 180.0 / 3.1415926535897931;
          rtb_elevation_mask = 1.001 / std::sqrt(s * s + 0.002001) *
            (rtb_elevation_mask * rtb_elevation_mask * 0.015 + 1.0);
        } else {
          rtb_removedSats_g = std::sin(TOW);
          rtb_elevation_mask = 4.0 - TOW * 180.0 / 3.1415926535897931;
          rtb_elevation_mask = 1.001 / std::sqrt(rtb_removedSats_g *
            rtb_removedSats_g + 0.002001) * (rtb_elevation_mask *
            rtb_elevation_mask * 0.015 + 1.0);
        }

        rtb_elevation_mask *= 0.12;
        if ((GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
             1) &&
            (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
             37)) {
          if (rtb_MeasurementCorrected && rtb_FixPtRelationalOperator) {
            rtb_removedSats_g = std::sqrt(5.11 *
              GNSSPreProcessingSingleAntenn_P.table_sigma_noise_GNSSReceiver[0]
              + 1.59 *
              GNSSPreProcessingSingleAntenn_P.table_sigma_noise_GNSSReceiver[1]);
          } else {
            rtb_removedSats_g =
              GNSSPreProcessingSingleAntenn_P.table_sigma_noise_GNSSReceiver[0];
          }
        } else if
            (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
             71) {
          if (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
              102) {
            if (rtb_enable_gps_l1 && (rtb_enable_gps_l2 || rtb_enable_galileo ||
                 rtb_enable_galileo_e1)) {
              rtb_removedSats_g = std::sqrt(5.11 *
                GNSSPreProcessingSingleAntenn_P.table_sigma_noise_GNSSReceiver[2]
                + 1.59 *
                GNSSPreProcessingSingleAntenn_P.table_sigma_noise_GNSSReceiver[3]);
            } else {
              rtb_removedSats_g =
                GNSSPreProcessingSingleAntenn_P.table_sigma_noise_GNSSReceiver[2];
            }
          } else {
            rtb_removedSats_g = 1.0E+20;
          }
        } else {
          rtb_removedSats_g = 1.0E+20;
        }

        TOW = std::exp(-TOW * 180.0 / 31.415926535897931) * 0.53 + 0.3;
        variance_pseudorange[coffset] = (((WNc * WNc + rtb_dayOfYear *
          rtb_dayOfYear) + rtb_elevation_mask * rtb_elevation_mask) +
          rtb_removedSats_g * rtb_removedSats_g) + TOW * TOW;
      }
      break;

     case 3:
      boffset = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange;
      if (GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange - 1 >= 0)
      {
        tmp_8 =
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[0];
        iter =
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[1];
      }

      for (coffset = 0; coffset < boffset; coffset++) {
        if ((GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
             1) &&
            (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
             37)) {
          WNc = 0.75;
        } else if
            ((GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
              71) &&
             (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
              102)) {
          WNc = 0.96;
        } else if
            (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
             120) {
          if (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
              140) {
            WNc = 0.3;
          } else {
            WNc = 1.0;
          }
        } else {
          WNc = 1.0;
        }

        tmp_size[0] = 1;
        tmp_size[1] =
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[1];
        for (vlen = 0; vlen < iter; vlen++) {
          tmp_data_2[vlen] =
            GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_position
            [tmp_8 * vlen + coffset];
        }

        calculate_Satellite_Elevation_n
          (GNSSPreProcessingSingleAntenn_U.usePosLLHArray, tmp_data_2, tmp_size,
           &rtb_dayOfYear, &TOW);
        if ((GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
             1) &&
            (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
             37)) {
          if (rtb_MeasurementCorrected && rtb_FixPtRelationalOperator) {
            TOW = 0.0;
          } else {
            TOW = (rt_powd_snf(0.53 - rtb_dayOfYear / 3.1415926535897931, 3.0) *
                   16.0 + 1.0) * 0.4;
          }
        } else if
            (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
             71) {
          if (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
              102) {
            if (rtb_enable_gps_l1 && (rtb_enable_gps_l2 || rtb_enable_galileo ||
                 rtb_enable_galileo_e1)) {
              TOW = 0.0;
            } else {
              TOW = 2.0;
            }
          } else {
            TOW = 1.0E+20;
          }
        } else {
          TOW = 1.0E+20;
        }

        if (rtb_dayOfYear >= 0.069813170079773182) {
          d_a = std::sin(rtb_dayOfYear);
          rtb_elevation_mask = 1.001 / std::sqrt(d_a * d_a + 0.002001);
        } else if ((rtb_dayOfYear < 0.069813170079773182) && (rtb_dayOfYear >=
                    0.034906585039886591)) {
          rtb_elevation_mask = std::sin(rtb_dayOfYear);
          rtb_elevation_mask = ((4.0 - (rtb_dayOfYear + 57.295779513082323)) *
                                (4.0 - (rtb_dayOfYear + 57.295779513082323)) *
                                0.015 + 1.0) * (1.001 / std::sqrt
            (rtb_elevation_mask * rtb_elevation_mask + 0.002001));
        } else {
          s = std::sin(rtb_dayOfYear);
          rtb_elevation_mask = ((4.0 - (rtb_dayOfYear + 57.295779513082323)) *
                                (4.0 - (rtb_dayOfYear + 57.295779513082323)) *
                                0.015 + 1.0) * (1.001 / std::sqrt(s * s +
            0.002001));
        }

        rtb_elevation_mask *= 0.12;
        if ((GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
             1) &&
            (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
             37)) {
          rtb_removedSats_g = -rtb_dayOfYear * 180.0;
          rtb_dayOfYear = std::exp(rtb_removedSats_g / 31.415926535897931) *
            0.53 + 0.13;
          rtb_removedSats_g = std::exp(rtb_removedSats_g / 21.676989309769574) *
            0.43 + 0.15;
          if (rtb_MeasurementCorrected && rtb_FixPtRelationalOperator) {
            rtb_removedSats_g = std::sqrt((rtb_dayOfYear * rtb_dayOfYear +
              rtb_removedSats_g * rtb_removedSats_g) * 8.8700043010625738);
            rtb_dayOfYear = 0.0;
          }
        } else if
            ((GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] >=
              71) &&
             (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[coffset] <=
              102)) {
          for (vlen = 0; vlen < 18; vlen++) {
            x_0[vlen] = (5.0 * static_cast<real_T>(vlen) + 5.0 < rtb_dayOfYear +
                         57.295779513082323);
          }

          c_nz = 0;
          vlen = 0;
          exitg1 = false;
          while ((!exitg1) && (vlen < 18)) {
            if (x_0[vlen]) {
              c_nz++;
              ii_data[c_nz - 1] = static_cast<int8_T>(vlen + 1);
              if (c_nz >= 18) {
                exitg1 = true;
              } else {
                vlen++;
              }
            } else {
              vlen++;
            }
          }

          if (c_nz < 1) {
            c_nz = 0;
          }

          if (c_nz == 0) {
            rtb_removedSats_g = 2.0;
            rtb_dayOfYear = 0.0;
          } else {
            vlen = ii_data[c_nz - 1];
            c_nz = (vlen - 1) << 1;
            vlen <<= 1;
            rtb_removedSats_g = h[vlen];
            s = h[c_nz];
            rtb_removedSats_g = (((rtb_dayOfYear + 57.295779513082323) - s) *
                                 h[c_nz + 1] + (rtb_removedSats_g -
              (rtb_dayOfYear + 57.295779513082323)) * h[vlen + 1]) /
              (rtb_removedSats_g - s);
            rtb_dayOfYear = 0.0;
          }
        } else {
          rtb_removedSats_g = 1.0E+20;
          rtb_dayOfYear = 1.0E+20;
        }

        variance_pseudorange[coffset] = (((WNc * WNc + TOW * TOW) +
          rtb_elevation_mask * rtb_elevation_mask) + rtb_removedSats_g *
          rtb_removedSats_g) + rtb_dayOfYear * rtb_dayOfYear;
      }
      break;

     case 4:
      if (GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange < 1) {
        coffset = 0;
      } else {
        coffset = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange;
      }

      boffset = (coffset / 2) << 1;
      kAcol = boffset - 2;
      for (vlen = 0; vlen <= kAcol; vlen += 2) {
        tmp_2 = _mm_loadu_pd
          (&GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange
           [vlen]);
        _mm_storeu_pd(&variance_pseudorange[vlen], _mm_mul_pd(tmp_2, _mm_set1_pd
          (160000.0)));
      }

      for (vlen = boffset; vlen < coffset; vlen++) {
        variance_pseudorange[vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange
          [vlen] * 160000.0;
      }
      break;
    }

    if (GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange < 1) {
      coffset = -1;
    } else {
      coffset = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange - 1;
    }

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_d = coffset + 1;

    // BusAssignment: '<S118>/Bus Assignment'
    GNSSPreProcessingSingleAnten_DW.BusAssignment_DIMS1 =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2;
    GNSSPreProcessingSingleAnten_DW.BusAssignment_DIMS1.variance_pseudorange =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_d;
    if (coffset >= 0) {
      std::memcpy
        (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_pseudorange
         [0], &variance_pseudorange[0], static_cast<uint32_T>(coffset + 1) *
         sizeof(real_T));
    }

    WNc =
      GNSSPreProcessingSingleAntenn_U.IntegrityParametersBus.raim_parameter.P_BayesThreshold;
    TOW =
      GNSSPreProcessingSingleAntenn_U.IntegrityParametersBus.raim_parameter.numVar;

    // MATLAB Function: '<S118>/Weighted RAIM Parity' incorporates:
    //   BusAssignment: '<S118>/Bus Assignment'
    //   BusCreator generated from: '<S118>/Weighted RAIM Parity'
    //   MATLAB Function: '<S118>/calculate Variance'

    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6 =
      GNSSPreProcessingSingleAnten_DW.BusAssignment_DIMS1;
    std::memcpy
      (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position
       [0],
       &GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_position[0],
       120U * sizeof(real_T));
    std::memcpy(&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.PRN[0],
                &GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[0], 40U *
                sizeof(uint16_T));
    std::memcpy
      (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange[0],
       &GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange[0], 40U *
       sizeof(real_T));
    iter = 0;
    for (coffset = 0; coffset < 80; coffset++) {
      // Outport: '<Root>/faultyPRNs' incorporates:
      //   MATLAB Function: '<S118>/Weighted RAIM Parity'

      GNSSPreProcessingSingleAntenn_Y.faultyPRNs[coffset] = (rtNaN);
    }

    // MATLAB Function: '<S118>/Weighted RAIM Parity' incorporates:
    //   BusCreator generated from: '<S118>/Weighted RAIM Parity'
    //   Inport: '<Root>/ClockErrorArray'
    //   Inport: '<Root>/usePosLLHArray'
    //   Outport: '<Root>/faultyPRNs'

    c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange;
    for (vlen = 0; vlen < c_nz; vlen++) {
      mask_all_data[vlen] = std::isnan
        (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange[vlen]);
    }

    c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange;
    for (vlen = 0; vlen < c_nz; vlen++) {
      mask_all_data[vlen] = !mask_all_data[vlen];
    }

    kAcol = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange - 1;
    trueCount = 0;
    for (coffset = 0; coffset <= kAcol; coffset++) {
      if (mask_all_data[coffset]) {
        trueCount++;
      }
    }

    c_nz = trueCount;
    rtb_FixPtRelationalOperator = true;
    rtb_elevation_mask = 0.0;
    while ((c_nz > TOW) && rtb_FixPtRelationalOperator) {
      rtb_FixPtRelationalOperator = false;
      iter = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange;
      GNSSPreProces_RAIM_detect_Fault
        (GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position,
         GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.satellite_position,
         GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange, &iter,
         GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_pseudorange,
         GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
         GNSSPreProcessingSingleAntenn_U.ClockErrorArray,
         GNSSPreProcessingSingleAntenn_P.table_chi_square, TOW, &rtb_dayOfYear,
         &rtb_removedSats_g, &s, H_data, H_size,
         GNSSPreProcessingSingleAntenn_B.q_data, rtb_measurementFrequency_Bus__9,
         delta_rho_data, &p_size_idx_0);
      if (s >
          GNSSPreProcessingSingleAntenn_U.IntegrityParametersBus.raim_parameter.HAL)
      {
        iter = 0;
      } else if (rtb_dayOfYear > rtb_removedSats_g) {
        iter = 2;
      } else {
        iter = 1;
      }

      if ((c_nz > TOW + 1.0) && (iter == 2)) {
        for (vlen = 0; vlen < 80; vlen++) {
          tmp_data_5[vlen] = (rtNaN);
        }

        c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange;
        for (vlen = 0; vlen < c_nz; vlen++) {
          mask_all_data[vlen] = std::isnan
            (GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange[vlen]);
        }

        c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange;
        for (vlen = 0; vlen < c_nz; vlen++) {
          mask_all_data[vlen] = !mask_all_data[vlen];
        }

        tmp_8 = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange - 1;
        kAcol = 0;
        for (partialTrueCount = 0; partialTrueCount <= tmp_8; partialTrueCount++)
        {
          if (mask_all_data[partialTrueCount]) {
            kAcol++;
          }
        }

        BusSelector_DIMS12_i_tmp_tmp = kAcol;
        GNSSPreProcessingSingleA_sqrt_f(GNSSPreProcessingSingleAntenn_B.q_data,
          rtb_measurementFrequency_Bus__9);
        GNSSPreProcessingSingl_mtimes_c(GNSSPreProcessingSingleAntenn_B.q_data,
          rtb_measurementFrequency_Bus__9, H_data, H_size, H_data_0, tmp_size);
        GNSSPreProcessingSingleAnten_qr(H_data_0, tmp_size,
          GNSSPreProcessingSingleAntenn_B.s_data, s_size, H_data, H_size);
        rtb_dayOfYear = (static_cast<real_T>(s_size[1]) + 1.0) -
          (static_cast<real_T>(kAcol) - TOW);
        if (rtb_dayOfYear > s_size[1]) {
          boffset = 0;
          partialTrueCount = 0;
        } else {
          boffset = static_cast<int32_T>(rtb_dayOfYear) - 1;
          partialTrueCount = s_size[1];
        }

        c_nz = partialTrueCount - boffset;
        k_size[0] = c_nz;
        k_size[1] = s_size[0];
        kAcol = s_size[0];
        for (vlen = 0; vlen < kAcol; vlen++) {
          for (partialTrueCount = 0; partialTrueCount < c_nz; partialTrueCount++)
          {
            GNSSPreProcessingSingleAntenn_B.P_data[partialTrueCount + c_nz *
              vlen] = GNSSPreProcessingSingleAntenn_B.s_data[(boffset +
              partialTrueCount) * s_size[0] + vlen];
          }
        }

        GNSSPreProcessingSingleA_mtimes(GNSSPreProcessingSingleAntenn_B.q_data,
          rtb_measurementFrequency_Bus__9, delta_rho_data,
          rtb_BusConversion_InsertedFor_1, &SVID_DIMS1);
        GNSSPreProcessingSingleA_mtimes(GNSSPreProcessingSingleAntenn_B.P_data,
          k_size, rtb_BusConversion_InsertedFor_1, delta_rho_data, &p_size_idx_0);
        indx_to_exclude_size[0] = 1;
        indx_to_exclude_size[1] = static_cast<int8_T>
          (BusSelector_DIMS12_i_tmp_tmp);
        rtb_measurementFrequency_Bus__9[0] = static_cast<int8_T>(c_nz);
        rtb_measurementFrequency_Bus__9[1] = static_cast<int8_T>(s_size[0]);
        tmp_8 = static_cast<int8_T>(c_nz) * static_cast<int8_T>(s_size[0]);
        if (tmp_8 - 1 >= 0) {
          std::memset(&GNSSPreProcessingSingleAntenn_B.q_data[0], 0,
                      static_cast<uint32_T>(tmp_8) * sizeof(real_T));
        }

        s_size[0] = static_cast<int8_T>(c_nz);
        s_size[1] = static_cast<int8_T>(k_size[1]);
        if (tmp_8 - 1 >= 0) {
          std::memset(&GNSSPreProcessingSingleAntenn_B.s_data[0], 0,
                      static_cast<uint32_T>(tmp_8) * sizeof(real_T));
        }

        for (partialTrueCount = 0; partialTrueCount <
             BusSelector_DIMS12_i_tmp_tmp; partialTrueCount++) {
          tmp_8 = k_size[0];
          c_nz = k_size[0];
          for (vlen = 0; vlen < c_nz; vlen++) {
            rtb_BusConversion_InsertedFor_0[vlen] =
              GNSSPreProcessingSingleAntenn_B.P_data[k_size[0] *
              partialTrueCount + vlen];
          }

          d_a = GNSSPreProcessingSingleA_norm_j(rtb_BusConversion_InsertedFor_0,
            &tmp_8);
          c_nz = k_size[0];
          boffset = (k_size[0] / 2) << 1;
          kAcol = boffset - 2;
          for (vlen = 0; vlen <= kAcol; vlen += 2) {
            tmp_2 = _mm_loadu_pd(&GNSSPreProcessingSingleAntenn_B.P_data[k_size
                                 [0] * partialTrueCount + vlen]);
            _mm_storeu_pd(&GNSSPreProcessingSingleAntenn_B.q_data[vlen +
                          rtb_measurementFrequency_Bus__9[0] * partialTrueCount],
                          _mm_div_pd(tmp_2, _mm_set1_pd(d_a)));
          }

          for (vlen = boffset; vlen < c_nz; vlen++) {
            GNSSPreProcessingSingleAntenn_B.q_data[vlen +
              rtb_measurementFrequency_Bus__9[0] * partialTrueCount] =
              GNSSPreProcessingSingleAntenn_B.P_data[k_size[0] *
              partialTrueCount + vlen] / d_a;
          }

          rtb_dayOfYear = 0.0;
          for (vlen = 0; vlen < p_size_idx_0; vlen++) {
            rtb_dayOfYear +=
              GNSSPreProcessingSingleAntenn_B.q_data[rtb_measurementFrequency_Bus__9
              [0] * partialTrueCount + vlen] * delta_rho_data[vlen];
          }

          if (p_size_idx_0 == rtb_measurementFrequency_Bus__9[0]) {
            boffset = (p_size_idx_0 / 2) << 1;
            kAcol = boffset - 2;
            for (vlen = 0; vlen <= kAcol; vlen += 2) {
              tmp_2 = _mm_loadu_pd
                (&GNSSPreProcessingSingleAntenn_B.q_data[rtb_measurementFrequency_Bus__9
                 [0] * partialTrueCount + vlen]);
              tmp_0 = _mm_loadu_pd(&delta_rho_data[vlen]);
              _mm_storeu_pd(&GNSSPreProcessingSingleAntenn_B.s_data[vlen +
                            s_size[0] * partialTrueCount], _mm_sub_pd(tmp_0,
                _mm_mul_pd(_mm_set1_pd(rtb_dayOfYear), tmp_2)));
            }

            for (vlen = boffset; vlen < p_size_idx_0; vlen++) {
              GNSSPreProcessingSingleAntenn_B.s_data[vlen + s_size[0] *
                partialTrueCount] = delta_rho_data[vlen] -
                GNSSPreProcessingSingleAntenn_B.q_data[rtb_measurementFrequency_Bus__9
                [0] * partialTrueCount + vlen] * rtb_dayOfYear;
            }
          } else {
            GNSSPreProc_binary_expand_op_fr
              (GNSSPreProcessingSingleAntenn_B.s_data, s_size, partialTrueCount,
               delta_rho_data, &p_size_idx_0, rtb_dayOfYear,
               GNSSPreProcessingSingleAntenn_B.q_data,
               rtb_measurementFrequency_Bus__9);
          }

          rtb_dayOfYear = 0.0;
          c_nz = s_size[0];
          for (vlen = 0; vlen < c_nz; vlen++) {
            s = GNSSPreProcessingSingleAntenn_B.s_data[s_size[0] *
              partialTrueCount + vlen];
            rtb_dayOfYear += -0.5 * s * s;
          }

          indx_to_exclude_data[partialTrueCount] = 1.0 / d_a * std::exp
            (rtb_dayOfYear);
        }

        rtb_dayOfYear = GNSSPreProcessingSingleAnte_sum(indx_to_exclude_data,
          indx_to_exclude_size);
        if (rtb_dayOfYear == 0.0) {
          P_satellite_fault_size[0] = 1;
          P_satellite_fault_size[1] = static_cast<int8_T>
            (BusSelector_DIMS12_i_tmp_tmp);
          if (BusSelector_DIMS12_i_tmp_tmp - 1 >= 0) {
            std::memset(&variance_pseudorange[0], 0, static_cast<uint32_T>
                        (BusSelector_DIMS12_i_tmp_tmp) * sizeof(real_T));
          }

          rtb_MeasurementCorrected = false;
        } else {
          P_satellite_fault_size[0] = 1;
          P_satellite_fault_size[1] = static_cast<int8_T>
            (BusSelector_DIMS12_i_tmp_tmp);
          boffset = (BusSelector_DIMS12_i_tmp_tmp / 2) << 1;
          kAcol = boffset - 2;
          for (partialTrueCount = 0; partialTrueCount <= kAcol; partialTrueCount
               += 2) {
            tmp_2 = _mm_loadu_pd(&indx_to_exclude_data[partialTrueCount]);
            _mm_storeu_pd(&variance_pseudorange[partialTrueCount], _mm_div_pd
                          (tmp_2, _mm_set1_pd(rtb_dayOfYear)));
          }

          for (partialTrueCount = boffset; partialTrueCount <
               BusSelector_DIMS12_i_tmp_tmp; partialTrueCount++) {
            variance_pseudorange[partialTrueCount] =
              indx_to_exclude_data[partialTrueCount] / rtb_dayOfYear;
          }

          rtb_MeasurementCorrected = true;
        }

        GNSSPreProcessingSingleA_sort_e(variance_pseudorange,
          P_satellite_fault_size, iia_data, tmp_size);
        tmp_8 = tmp_size[1];
        c_nz = tmp_size[1];
        if (c_nz - 1 >= 0) {
          std::memcpy(&indx_to_isolate_data[0], &iia_data[0],
                      static_cast<uint32_T>(c_nz) * sizeof(int32_T));
        }

        boffset = 1;
        rtb_dayOfYear = 0.0;
        s = 0.0;
        while (rtb_MeasurementCorrected && (static_cast<real_T>
                (BusSelector_DIMS12_i_tmp_tmp) - rtb_dayOfYear > TOW + 1.0) &&
               (BusSelector_DIMS12_i_tmp_tmp > boffset - 1) && (s < WNc) &&
               (rtb_dayOfYear <
                GNSSPreProcessingSingleAntenn_U.IntegrityParametersBus.raim_parameter.maxNumToIdentifyOnce))
        {
          kAcol = tmp_8 - boffset;
          partialTrueCount = indx_to_isolate_data[kAcol];
          p_size_idx_0 = s_size[0];
          c_nz = s_size[0];
          for (vlen = 0; vlen < c_nz; vlen++) {
            delta_rho_data[vlen] = GNSSPreProcessingSingleAntenn_B.s_data
              [(partialTrueCount - 1) * s_size[0] + vlen];
          }

          if (GNSSPreProcessingSingleA_norm_j(delta_rho_data, &p_size_idx_0) <
              rtb_removedSats_g * 5.0) {
            d_a = variance_pseudorange[P_satellite_fault_size[1] - boffset];
            s += d_a;
            c_nz = (static_cast<int32_T>(rtb_dayOfYear + 1.0) - 1) << 1;
            tmp_data_5[c_nz] =
              GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.PRN[indx_to_isolate_data
              [kAcol] - 1];
            tmp_data_5[c_nz + 1] = d_a;
            rtb_dayOfYear++;
          }

          boffset++;
        }

        if (!(s < WNc)) {
          rtb_FixPtRelationalOperator = true;
          if (rtb_dayOfYear < 40.0) {
            if (rtb_dayOfYear < 1.0) {
              c_nz = -1;
            } else {
              c_nz = static_cast<int32_T>(rtb_dayOfYear) - 1;
            }

            for (vlen = 0; vlen <= c_nz; vlen++) {
              coffset = vlen << 1;
              boffset = (static_cast<int32_T>((static_cast<real_T>(vlen) + 1.0)
                          + rtb_elevation_mask) - 1) << 1;
              GNSSPreProcessingSingleAntenn_Y.faultyPRNs[boffset] =
                tmp_data_5[coffset];
              GNSSPreProcessingSingleAntenn_Y.faultyPRNs[boffset + 1] =
                tmp_data_5[coffset + 1];
            }
          }

          rtb_elevation_mask += rtb_dayOfYear;
          kAcol = 0;
          for (vlen = 0; vlen < 40; vlen++) {
            rtb_MeasurementCorrected = !std::isnan(tmp_data_5[vlen << 1]);
            if (rtb_MeasurementCorrected) {
              kAcol++;
            }

            b_data[vlen] = rtb_MeasurementCorrected;
          }

          tmp_8 = kAcol;
          kAcol = 0;
          for (trueCount = 0; trueCount < 40; trueCount++) {
            if (b_data[trueCount]) {
              e_data_0[kAcol] = trueCount + 1;
              kAcol++;
            }
          }

          c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange;
          for (vlen = 0; vlen < c_nz; vlen++) {
            mask_all_data[vlen] = std::isnan
              (GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange[vlen]);
          }

          c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange;
          for (vlen = 0; vlen < c_nz; vlen++) {
            mask_all_data[vlen] = !mask_all_data[vlen];
          }

          vlen = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange - 1;
          kAcol = 0;
          for (partialTrueCount = 0; partialTrueCount <= vlen; partialTrueCount
               ++) {
            if (mask_all_data[partialTrueCount]) {
              kAcol++;
            }
          }

          if (kAcol < 1) {
            P_satellite_fault_size[0] = 1;
            P_satellite_fault_size[1] = 0;
          } else {
            P_satellite_fault_size[0] = 1;
            P_satellite_fault_size[1] = kAcol;
            c_nz = kAcol - 1;
            for (vlen = 0; vlen <= c_nz; vlen++) {
              variance_pseudorange[vlen] = static_cast<real_T>(vlen) + 1.0;
            }
          }

          if (tmp_8 != 0) {
            trueCount = static_cast<int8_T>(tmp_8);
            c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.PRN;
            for (partialTrueCount = 0; partialTrueCount < trueCount;
                 partialTrueCount++) {
              rtb_dayOfYear = tmp_data_5[(e_data_0[partialTrueCount] - 1) << 1];
              boffset = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.PRN;
              for (vlen = 0; vlen < c_nz; vlen++) {
                b_data[vlen] =
                  (GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.PRN[vlen]
                   == rtb_dayOfYear);
              }

              GNSSPreProcessingS_eml_find_lei(b_data, &boffset, iia_data,
                &p_size_idx_0);
              for (vlen = 0; vlen < p_size_idx_0; vlen++) {
                delta_rho_data[vlen] = iia_data[vlen];
              }

              if (p_size_idx_0 == 0) {
                indx_to_isolate_data[partialTrueCount] = 0;
              } else {
                indx_to_isolate_data[partialTrueCount] = static_cast<int32_T>
                  (delta_rho_data[0]);
              }
            }

            tmp_size[0] = 1;
            tmp_size[1] = static_cast<int8_T>(tmp_8);
            std::memcpy(&iia_data[0], &indx_to_isolate_data[0],
                        static_cast<uint32_T>(static_cast<int8_T>(tmp_8)) *
                        sizeof(int32_T));
            GNSSPreProcessin_nullAssignment(variance_pseudorange,
              P_satellite_fault_size, iia_data, tmp_size);
          }

          s_size[0] =
            GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.satellite_position[0];
          c_nz =
            GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.satellite_position[1];
          tmp_8 = P_satellite_fault_size[1];
          for (vlen = 0; vlen < c_nz; vlen++) {
            kAcol = P_satellite_fault_size[1];
            for (partialTrueCount = 0; partialTrueCount < kAcol;
                 partialTrueCount++) {
              rtb_GnssMeasurementBase_satelli[partialTrueCount + tmp_8 * vlen] =
                GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position
                [(s_size[0] * vlen + static_cast<int32_T>
                  (variance_pseudorange[partialTrueCount])) - 1];
            }
          }

          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.satellite_position[0] =
            P_satellite_fault_size[1];
          c_nz = P_satellite_fault_size[1] *
            GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.satellite_position[1];
          if (c_nz - 1 >= 0) {
            std::memcpy
              (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position
               [0], &rtb_GnssMeasurementBase_satelli[0], static_cast<uint32_T>
               (c_nz) * sizeof(real_T));
          }

          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.satellite_velocity[0] =
            P_satellite_fault_size[1];
          c_nz = P_satellite_fault_size[1];
          for (vlen = 0; vlen < c_nz; vlen++) {
            a__1_data[vlen] =
              GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.PRN[
              static_cast<int32_T>(variance_pseudorange[vlen]) - 1];
          }

          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.PRN =
            P_satellite_fault_size[1];
          c_nz = P_satellite_fault_size[1];
          if (c_nz - 1 >= 0) {
            std::memcpy
              (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.PRN[0],
               &a__1_data[0], static_cast<uint32_T>(c_nz) * sizeof(uint16_T));
          }

          c_nz = P_satellite_fault_size[1];
          for (vlen = 0; vlen < c_nz; vlen++) {
            delta_rho_data[vlen] =
              GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange[
              static_cast<int32_T>(variance_pseudorange[vlen]) - 1];
          }

          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange =
            P_satellite_fault_size[1];
          c_nz = P_satellite_fault_size[1];
          if (c_nz - 1 >= 0) {
            std::memcpy
              (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange[
               0], &delta_rho_data[0], static_cast<uint32_T>(c_nz) * sizeof
               (real_T));
          }

          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange_raw =
            P_satellite_fault_size[1];
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange_satclk_corrected
            = P_satellite_fault_size[1];
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.deltarange =
            P_satellite_fault_size[1];
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.deltarange_raw =
            P_satellite_fault_size[1];
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.deltarange_satclk_corrected
            = P_satellite_fault_size[1];
          c_nz = P_satellite_fault_size[1];
          for (vlen = 0; vlen < c_nz; vlen++) {
            delta_rho_data[vlen] =
              GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_pseudorange
              [static_cast<int32_T>(variance_pseudorange[vlen]) - 1];
          }

          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.variance_pseudorange =
            P_satellite_fault_size[1];
          c_nz = P_satellite_fault_size[1];
          if (c_nz - 1 >= 0) {
            std::memcpy
              (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_pseudorange
               [0], &delta_rho_data[0], static_cast<uint32_T>(c_nz) * sizeof
               (real_T));
          }

          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.variance_pseudorange_measured
            = P_satellite_fault_size[1];
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.variance_deltarange =
            P_satellite_fault_size[1];
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.carrierphase =
            P_satellite_fault_size[1];
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.carrierphase_raw =
            P_satellite_fault_size[1];
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.carrierphase_satclk_corrected
            = P_satellite_fault_size[1];
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.variance_carrierphase_measured
            = P_satellite_fault_size[1];
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.locktime =
            P_satellite_fault_size[1];
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.CN0 =
            P_satellite_fault_size[1];
        }
      }

      c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange;
      for (vlen = 0; vlen < c_nz; vlen++) {
        mask_all_data[vlen] = std::isnan
          (GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange[vlen]);
      }

      c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange;
      for (vlen = 0; vlen < c_nz; vlen++) {
        mask_all_data[vlen] = !mask_all_data[vlen];
      }

      kAcol = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS6.pseudorange - 1;
      vlen = 0;
      for (c_nz = 0; c_nz <= kAcol; c_nz++) {
        if (mask_all_data[c_nz]) {
          vlen++;
        }
      }

      c_nz = vlen;
    }

    // Outport: '<Root>/integrityFlag' incorporates:
    //   MATLAB Function: '<S118>/Weighted RAIM Parity'

    GNSSPreProcessingSingleAntenn_Y.integrityFlag = iter;

    // DigitalClock: '<S118>/Digital Clock'
    WNc = (((&GNSSPreProcessingSingleAnten_M)->Timing.clockTick0) * 0.1);

    // MATLAB Function: '<S118>/Fault Exclusion' incorporates:
    //   Outport: '<Root>/faultyPRNs'

    trueCount = 0;
    for (vlen = 0; vlen < 40; vlen++) {
      rtb_MeasurementCorrected = !std::isnan
        (GNSSPreProcessingSingleAntenn_Y.faultyPRNs[vlen << 1]);
      if (rtb_MeasurementCorrected) {
        trueCount++;
      }

      b_data[vlen] = rtb_MeasurementCorrected;
    }

    iidx_size[1] = trueCount;
    partialTrueCount = 0;
    for (trueCount = 0; trueCount < 40; trueCount++) {
      if (b_data[trueCount]) {
        iidx_data[partialTrueCount] = trueCount + 1;
        partialTrueCount++;
      }
    }

    if (!GNSSPreProcessingSingleAnten_DW.BUFFER_not_empty) {
      GNSSPreProcessingSingleAnten_DW.BUFFER_not_empty = true;
      GNSSPreProcessingSingleAnten_DW.sys_clock_last_loop = WNc;
    }

    if (!std::isnan(GNSSPreProcessingSingleAnten_DW.BUFFER[0])) {
      for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
        b_data[partialTrueCount] = !std::isnan
          (GNSSPreProcessingSingleAnten_DW.BUFFER[partialTrueCount << 1]);
      }

      trueCount = 0;
      kAcol = 0;
      for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
        if (b_data[partialTrueCount]) {
          k_data_2[trueCount] = partialTrueCount + 1;
          trueCount++;
        }

        rtb_MeasurementCorrected = !std::isnan
          (GNSSPreProcessingSingleAnten_DW.BUFFER[partialTrueCount << 1]);
        if (rtb_MeasurementCorrected) {
          kAcol++;
        }

        b_data[partialTrueCount] = rtb_MeasurementCorrected;
      }

      iter = kAcol;
      kAcol = 0;
      for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
        if (b_data[partialTrueCount]) {
          l_data_1[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
          kAcol++;
        }
      }

      for (vlen = 0; vlen < iter; vlen++) {
        variance_pseudorange[vlen] = (GNSSPreProcessingSingleAnten_DW.BUFFER
          [((l_data_1[vlen] - 1) << 1) + 1] + WNc) -
          GNSSPreProcessingSingleAnten_DW.sys_clock_last_loop;
      }

      for (vlen = 0; vlen < iter; vlen++) {
        GNSSPreProcessingSingleAnten_DW.BUFFER[((k_data_2[vlen] - 1) << 1) + 1] =
          variance_pseudorange[vlen];
      }
    }

    if (iidx_size[1] != 0) {
      boffset = iidx_size[1];
      for (coffset = 0; coffset < boffset; coffset++) {
        rtb_dayOfYear = GNSSPreProcessingSingleAntenn_Y.faultyPRNs
          [(iidx_data[coffset] - 1) << 1];
        for (vlen = 0; vlen < 40; vlen++) {
          b_data[vlen] = (GNSSPreProcessingSingleAnten_DW.BUFFER[vlen << 1] ==
                          rtb_dayOfYear);
        }

        if (!GNSSPreProcessingSingleAn_any_l(b_data)) {
          for (vlen = 0; vlen < 40; vlen++) {
            b_data[vlen] = std::isnan
              (GNSSPreProcessingSingleAnten_DW.BUFFER[vlen << 1]);
          }

          GNSSPreProcessingSin_eml_find_l(b_data, k_data_2, k_size);
          c_nz = k_size[1];
          for (vlen = 0; vlen < c_nz; vlen++) {
            rtb_dualFrequencyCorrection[vlen] = k_data_2[vlen];
          }

          if (k_size[1] != 0) {
            iter = (static_cast<int32_T>(rtb_dualFrequencyCorrection[0]) - 1) <<
              1;
            GNSSPreProcessingSingleAnten_DW.BUFFER[iter] = rtb_dayOfYear;
            GNSSPreProcessingSingleAnten_DW.BUFFER[iter + 1] = 0.0;
          }
        } else {
          for (vlen = 0; vlen < 40; vlen++) {
            b_data[vlen] = (GNSSPreProcessingSingleAnten_DW.BUFFER[vlen << 1] ==
                            rtb_dayOfYear);
          }

          GNSSPreProcessingSin_eml_find_l(b_data, k_data_2, k_size);
          c_nz = k_size[1];
          for (vlen = 0; vlen < c_nz; vlen++) {
            rtb_dualFrequencyCorrection[vlen] = k_data_2[vlen];
          }

          if (k_size[1] != 0) {
            GNSSPreProcessingSingleAnten_DW.BUFFER[((static_cast<int32_T>
              (rtb_dualFrequencyCorrection[0]) - 1) << 1) + 1] = 0.0;
          }
        }
      }
    }

    if (!std::isnan(GNSSPreProcessingSingleAnten_DW.BUFFER[0])) {
      kAcol = 0;
      for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
        rtb_MeasurementCorrected = !std::isnan
          (GNSSPreProcessingSingleAnten_DW.BUFFER[partialTrueCount << 1]);
        if (rtb_MeasurementCorrected) {
          kAcol++;
        }

        b_data[partialTrueCount] = rtb_MeasurementCorrected;
      }

      iter = kAcol;
      kAcol = 0;
      for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
        if (b_data[partialTrueCount]) {
          m_data_1[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
          kAcol++;
        }
      }

      x_size[0] = 1;
      x_size[1] = iter;
      for (vlen = 0; vlen < iter; vlen++) {
        b_data[vlen] = (GNSSPreProcessingSingleAnten_DW.BUFFER[((m_data_1[vlen]
          - 1) << 1) + 1] <=
                        GNSSPreProcessingSingleAntenn_U.IntegrityParametersBus.raim_parameter.TTE);
      }

      GNSSPreProcessingSi_eml_find_le(b_data, x_size, k_data_2, k_size);
      c_nz = k_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        rtb_dualFrequencyCorrection[vlen] = k_data_2[vlen];
      }

      if (k_size[1] != 0) {
        tmp_8 = k_size[1];
        c_nz = k_size[1];
        for (vlen = 0; vlen < c_nz; vlen++) {
          partialTrueCount = (static_cast<int32_T>
                              (rtb_dualFrequencyCorrection[vlen]) - 1) << 1;
          tmp_data_5[vlen << 1] =
            GNSSPreProcessingSingleAnten_DW.BUFFER[partialTrueCount];
          tmp_data_5[1 + (vlen << 1)] =
            GNSSPreProcessingSingleAnten_DW.BUFFER[partialTrueCount + 1];
        }

        for (vlen = 0; vlen < tmp_8; vlen++) {
          iter = vlen << 1;
          GNSSPreProcessingSingleAnten_DW.BUFFER[iter] = tmp_data_5[vlen << 1];
          GNSSPreProcessingSingleAnten_DW.BUFFER[iter + 1] = tmp_data_5[(vlen <<
            1) + 1];
        }

        if (k_size[1] + 1 > 40) {
          boffset = 0;
          iter = 0;
        } else {
          boffset = k_size[1];
          iter = 40;
        }

        c_nz = iter - boffset;
        for (vlen = 0; vlen < c_nz; vlen++) {
          iter = (boffset + vlen) << 1;
          GNSSPreProcessingSingleAnten_DW.BUFFER[iter] = (rtNaN);
          GNSSPreProcessingSingleAnten_DW.BUFFER[iter + 1] = (rtNaN);
        }
      } else {
        for (coffset = 0; coffset < 80; coffset++) {
          GNSSPreProcessingSingleAnten_DW.BUFFER[coffset] = (rtNaN);
        }
      }
    }

    if (!std::isnan(GNSSPreProcessingSingleAnten_DW.BUFFER[0])) {
      kAcol = 0;
      for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
        rtb_MeasurementCorrected = !std::isnan
          (GNSSPreProcessingSingleAnten_DW.BUFFER[partialTrueCount << 1]);
        if (rtb_MeasurementCorrected) {
          kAcol++;
        }

        b_data[partialTrueCount] = rtb_MeasurementCorrected;
      }

      iter = kAcol;
      kAcol = 0;
      for (partialTrueCount = 0; partialTrueCount < 40; partialTrueCount++) {
        if (b_data[partialTrueCount]) {
          n_data_1[kAcol] = static_cast<int8_T>(partialTrueCount + 1);
          kAcol++;
        }
      }

      idxPRN_size[0] = 1;
      idxPRN_size[1] = iter;
      for (vlen = 0; vlen < iter; vlen++) {
        rtb_dualFrequencyCorrection[vlen] =
          GNSSPreProcessingSingleAnten_DW.BUFFER[((n_data_1[vlen] - 1) << 1) + 1];
      }

      GNSSPreProcessingSingle_sort_np(rtb_dualFrequencyCorrection, idxPRN_size,
        iidx_data, iidx_size);
      c_nz = iidx_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        indx_to_exclude_data[vlen] = iidx_data[vlen];
      }

      c_nz = iidx_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        variance_pseudorange[vlen] = GNSSPreProcessingSingleAnten_DW.BUFFER[(
          static_cast<int32_T>(indx_to_exclude_data[vlen]) - 1) << 1];
      }

      c_nz = iidx_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAnten_DW.BUFFER[vlen << 1] =
          variance_pseudorange[vlen];
      }

      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAnten_DW.BUFFER[(vlen << 1) + 1] =
          rtb_dualFrequencyCorrection[vlen];
      }
    }

    GNSSPreProcessingSingleAnten_DW.sys_clock_last_loop = WNc;
    c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange;
    for (vlen = 0; vlen < c_nz; vlen++) {
      mask_all_data[vlen] = std::isnan
        (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange[vlen]);
    }

    c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange;
    for (vlen = 0; vlen < c_nz; vlen++) {
      mask_all_data[vlen] = !mask_all_data[vlen];
    }

    kAcol = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.pseudorange - 1;
    vlen = 0;
    for (partialTrueCount = 0; partialTrueCount <= kAcol; partialTrueCount++) {
      if (mask_all_data[partialTrueCount]) {
        vlen++;
      }
    }

    o_size_idx_0 = vlen;
    if (vlen < 1) {
      idxPRN_size[0] = 1;
      idxPRN_size[1] = 0;
    } else {
      idxPRN_size[0] = 1;
      idxPRN_size[1] = vlen;
      c_nz = vlen - 1;
      for (vlen = 0; vlen <= c_nz; vlen++) {
        rtb_dualFrequencyCorrection[vlen] = static_cast<real_T>(vlen) + 1.0;
      }
    }

    if (!GNSSPreProcessingSingleAntenn_U.IntegrityParametersBus.enable_GNSS_exclusion)
    {
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5 =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2;
      GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out =
        GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus;
    } else {
      if (o_size_idx_0 > 6) {
        kAcol = 0;
        for (vlen = 0; vlen < 40; vlen++) {
          rtb_MeasurementCorrected = !std::isnan
            (GNSSPreProcessingSingleAnten_DW.BUFFER[vlen << 1]);
          if (rtb_MeasurementCorrected) {
            kAcol++;
          }

          b_data[vlen] = rtb_MeasurementCorrected;
        }

        iter = kAcol;
        kAcol = 0;
        for (vlen = 0; vlen < 40; vlen++) {
          if (b_data[vlen]) {
            p_data_2[kAcol] = static_cast<int8_T>(vlen + 1);
            kAcol++;
          }
        }

        if (iter != 0) {
          partialTrueCount = static_cast<int8_T>(iter);
          indx_to_exclude_size[0] = 1;
          indx_to_exclude_size[1] = static_cast<int8_T>(iter);
          c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.PRN;
          for (coffset = 0; coffset < partialTrueCount; coffset++) {
            rtb_dayOfYear = GNSSPreProcessingSingleAnten_DW.BUFFER
              [(p_data_2[coffset] - 1) << 1];
            BusSelector_DIMS12_i_tmp_tmp =
              GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.PRN;
            for (vlen = 0; vlen < c_nz; vlen++) {
              tmp_data_0[vlen] =
                (GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN[vlen] ==
                 rtb_dayOfYear);
            }

            GNSSPreProcessingS_eml_find_lei(tmp_data_0,
              &BusSelector_DIMS12_i_tmp_tmp, iia_data, &p_size_idx_0);
            if (p_size_idx_0 == 0) {
              indx_to_exclude_data[coffset] = 0.0;
            } else {
              indx_to_exclude_data[coffset] = iia_data[0];
            }
          }

          GNSSPreProcessing_eml_find_leix(indx_to_exclude_data,
            indx_to_exclude_size, &a__1_size, tmp_size);
          if (tmp_size[1] != 0) {
            kAcol = static_cast<int8_T>(iter) - 1;
            partialTrueCount = 0;
            for (vlen = 0; vlen <= kAcol; vlen++) {
              if (indx_to_exclude_data[vlen] != 0.0) {
                partialTrueCount++;
              }
            }

            trueCount = 0;
            for (vlen = 0; vlen <= kAcol; vlen++) {
              WNc = indx_to_exclude_data[vlen];
              if (WNc != 0.0) {
                indx_to_exclude_data[trueCount] = WNc;
                trueCount++;
              }
            }

            if (o_size_idx_0 - partialTrueCount >= 6) {
              iidx_size[0] = 1;
              iidx_size[1] = partialTrueCount;
              for (vlen = 0; vlen < partialTrueCount; vlen++) {
                iidx_data[vlen] = static_cast<int32_T>(indx_to_exclude_data[vlen]);
              }

              GNSSPreProcessin_nullAssignment(rtb_dualFrequencyCorrection,
                idxPRN_size, iidx_data, iidx_size);
            } else {
              iidx_size[0] = 1;
              iidx_size[1] = o_size_idx_0 - 6;
              for (vlen = 0; vlen <= o_size_idx_0 - 7; vlen++) {
                iidx_data[vlen] = static_cast<int32_T>(indx_to_exclude_data[vlen]);
              }

              GNSSPreProcessin_nullAssignment(rtb_dualFrequencyCorrection,
                idxPRN_size, iidx_data, iidx_size);
            }
          }
        }
      }

      GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.time_receive =
        GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.time_receive;
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.satellite_position[0] =
        idxPRN_size[1];
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.satellite_position[1] =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[1];
      s_size[0] =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position[0];
      coffset =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.satellite_position[0];
      c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_position
        [1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        kAcol = idxPRN_size[1];
        for (partialTrueCount = 0; partialTrueCount < kAcol; partialTrueCount++)
        {
          GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.satellite_position
            [partialTrueCount + coffset * vlen] =
            GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_position
            [(s_size[0] * vlen + static_cast<int32_T>
              (rtb_dualFrequencyCorrection[partialTrueCount])) - 1];
        }
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.satellite_velocity[0] =
        idxPRN_size[1];
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.satellite_velocity[1] =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_velocity[1];
      s_size[0] =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_velocity[0];
      coffset =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.satellite_velocity[0];
      c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2.satellite_velocity
        [1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        kAcol = idxPRN_size[1];
        for (partialTrueCount = 0; partialTrueCount < kAcol; partialTrueCount++)
        {
          GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.satellite_velocity
            [partialTrueCount + coffset * vlen] =
            GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.satellite_velocity
            [(s_size[0] * vlen + static_cast<int32_T>
              (rtb_dualFrequencyCorrection[partialTrueCount])) - 1];
        }
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.PRN = idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.PRN[vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.PRN
          [static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.pseudorange =
        idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.pseudorange[vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange[
          static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.pseudorange_raw =
        idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.pseudorange_raw[vlen]
          = GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange_raw[
          static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.pseudorange_satclk_corrected
        = idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.pseudorange_satclk_corrected
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.pseudorange_satclk_corrected
          [static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.deltarange =
        idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.deltarange[vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange[
          static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.deltarange_raw =
        idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.deltarange_raw[vlen]
          = GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange_raw[
          static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.deltarange_satclk_corrected
        = idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.deltarange_satclk_corrected
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.deltarange_satclk_corrected
          [static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.variance_pseudorange =
        idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.variance_pseudorange
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange
          [static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.variance_pseudorange_measured
        = idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.variance_pseudorange_measured
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_pseudorange_measured
          [static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.variance_deltarange =
        idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.variance_deltarange[
          vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_deltarange[
          static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.carrierphase =
        idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.carrierphase[vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase[
          static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.carrierphase_raw =
        idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.carrierphase_raw[vlen]
          = GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase_raw[
          static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.carrierphase_satclk_corrected
        = idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.carrierphase_satclk_corrected
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.carrierphase_satclk_corrected
          [static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.variance_carrierphase_measured
        = idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.variance_carrierphase_measured
          [vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.variance_carrierphase_measured
          [static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.locktime = idxPRN_size
        [1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.locktime[vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.locktime[
          static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.CN0 = idxPRN_size[1];
      c_nz = idxPRN_size[1];
      for (vlen = 0; vlen < c_nz; vlen++) {
        GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.CN0[vlen] =
          GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.CN0
          [static_cast<int32_T>(rtb_dualFrequencyCorrection[vlen]) - 1];
      }

      GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.base_position[0] =
        GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[0];
      GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.base_position[1] =
        GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[1];
      GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out.base_position[2] =
        GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus.base_position[2];
    }

    // End of MATLAB Function: '<S118>/Fault Exclusion'
    // End of Outputs for SubSystem: '<S117>/GNSS Fault Detection Identification Exclusion' 

    // MATLAB Function: '<S117>/switch GNSS Measurements'
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5;
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out =
      GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out;
  } else {
    // MATLAB Function: '<S117>/switch GNSS Measurements'
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2;
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out =
      GNSSPreProcessingSingleAntenn_B.GnssMeasurementBus;
  }

  // End of MATLAB Function: '<S117>/MATLAB Function'

  // MATLAB Function: '<Root>/Calculate User Position with LMS'
  if (GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.pseudorange >= 4) {
    user_state[0] = 0.0;
    user_state[1] = 0.0;
    user_state[2] = 0.0;
    user_state[3] = 0.0;
    s_size[0] =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[0];
    s_size[1] =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[1];
    tmp[0] = 0.0;
    tmp[1] = 0.0;
    tmp[2] = 0.0;
    tmp[3] = 0.0;
    vlen = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.pseudorange;
    GNSSPreProcessingSing_getJacobi
      (GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position,
       s_size, GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange,
       &vlen, tmp, delta_rho_data, &p_size_idx_0, H_data, H_size, residuum);
    iter = 0;
    int32_T exitg2;
    do {
      exitg2 = 0;
      WNc = 3.3121686421112381E-170;
      TOW = std::abs(residuum[0]);
      if (TOW > 3.3121686421112381E-170) {
        rtb_elevation_mask = 1.0;
        WNc = TOW;
      } else {
        rtb_dayOfYear = TOW / 3.3121686421112381E-170;
        rtb_elevation_mask = rtb_dayOfYear * rtb_dayOfYear;
      }

      TOW = std::abs(residuum[1]);
      if (TOW > WNc) {
        rtb_dayOfYear = WNc / TOW;
        rtb_elevation_mask = rtb_elevation_mask * rtb_dayOfYear * rtb_dayOfYear
          + 1.0;
        WNc = TOW;
      } else {
        rtb_dayOfYear = TOW / WNc;
        rtb_elevation_mask += rtb_dayOfYear * rtb_dayOfYear;
      }

      TOW = std::abs(residuum[2]);
      if (TOW > WNc) {
        rtb_dayOfYear = WNc / TOW;
        rtb_elevation_mask = rtb_elevation_mask * rtb_dayOfYear * rtb_dayOfYear
          + 1.0;
        WNc = TOW;
      } else {
        rtb_dayOfYear = TOW / WNc;
        rtb_elevation_mask += rtb_dayOfYear * rtb_dayOfYear;
      }

      TOW = std::abs(residuum[3]);
      if (TOW > WNc) {
        rtb_dayOfYear = WNc / TOW;
        rtb_elevation_mask = rtb_elevation_mask * rtb_dayOfYear * rtb_dayOfYear
          + 1.0;
        WNc = TOW;
      } else {
        rtb_dayOfYear = TOW / WNc;
        rtb_elevation_mask += rtb_dayOfYear * rtb_dayOfYear;
      }

      rtb_elevation_mask = WNc * std::sqrt(rtb_elevation_mask);
      if ((rtb_elevation_mask > 0.001) && (iter < 1000)) {
        GNSSPreProcessingSin_mldivide_a(H_data, H_size, delta_rho_data,
          &p_size_idx_0);
        if (p_size_idx_0 == 4) {
          user_state[0] += delta_rho_data[0];
          user_state[1] += delta_rho_data[1];
          user_state[2] += delta_rho_data[2];
          user_state[3] += delta_rho_data[3];
        } else {
          GNSSPreProcessingSingleA_plus_f(user_state, delta_rho_data,
            &p_size_idx_0);
        }

        s_size[0] =
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[0];
        s_size[1] =
          GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[1];
        vlen = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.pseudorange;
        GNSSPreProcessingSing_getJacobi
          (GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position,
           s_size,
           GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange,
           &vlen, user_state, delta_rho_data, &p_size_idx_0, H_data, H_size,
           residuum);
        iter++;
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    tmp_8 = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.pseudorange;
    iter = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.pseudorange;
    if (GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.pseudorange - 1 >= 0)
    {
      tmp_7 =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_velocity[0];
    }

    for (vlen = 0; vlen < iter; vlen++) {
      bvec_data[vlen] =
        ((GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_velocity
          [vlen + tmp_7] * H_data[vlen + H_size[0]] +
          GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_velocity
          [vlen] * H_data[vlen]) +
         GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_velocity[
         (tmp_7 << 1) + vlen] * H_data[(H_size[0] << 1) + vlen]) +
        GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.deltarange[vlen];
    }

    p_size_idx_0 = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.pseudorange;
    if (tmp_8 - 1 >= 0) {
      std::memcpy(&delta_rho_data[0], &bvec_data[0], static_cast<uint32_T>(tmp_8)
                  * sizeof(real_T));
    }

    if (GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.pseudorange < 1) {
      c_nz = -1;
    } else {
      c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.pseudorange - 1;
    }

    H_size_0[0] = c_nz + 1;
    H_size_0[1] = 4;
    for (vlen = 0; vlen < 4; vlen++) {
      for (partialTrueCount = 0; partialTrueCount <= c_nz; partialTrueCount++) {
        H_data_0[partialTrueCount + (c_nz + 1) * vlen] = H_data[H_size[0] * vlen
          + partialTrueCount];
      }
    }

    GNSSPreProcessingSin_mldivide_a(H_data_0, H_size_0, delta_rho_data,
      &p_size_idx_0);
    TOW = std::sqrt(user_state[0] * user_state[0] + user_state[1] * user_state[1]);
    rtb_removedSats_g = std::atan(user_state[2] / (TOW * -0.99664718933525243 *
      0.0033528106647474805));
    WNc = 0.1;
    rtb_dayOfYear = 0.0;
    trueCount = 0;
    while ((std::abs(WNc - rtb_dayOfYear) > 1.0E-12) && (trueCount < 3000)) {
      rtb_dayOfYear = WNc;
      rtb_elevation_mask = std::cos(rtb_removedSats_g);
      rtb_elevation_mask = 6.3995936257584924E+6 / std::sqrt(rtb_elevation_mask *
        rtb_elevation_mask * 0.0067394967422764341 + 1.0);
      rtb_removedSats_g = std::atan(user_state[2] / ((1.0 -
        0.0066943799901413165 * rtb_elevation_mask / (rtb_elevation_mask + WNc))
        * TOW));
      WNc = TOW / std::cos(rtb_removedSats_g) - rtb_elevation_mask;
      trueCount++;
    }

    TOW = rtb_removedSats_g * 57.295779513082323 * 0.017453292519943295;
    rtb_elevation_mask = rt_atan2d_snf(user_state[1], user_state[0]) *
      57.295779513082323 * 0.017453292519943295;
    rtb_removedSats_g = std::sin(rtb_elevation_mask);
    s = std::cos(rtb_elevation_mask);
    d_a = std::cos(TOW);
    rtb_dayOfYear = -std::sin(TOW);
    Rot[0] = rtb_dayOfYear * s;
    Rot[3] = rtb_dayOfYear * rtb_removedSats_g;
    Rot[6] = d_a;
    Rot[1] = -rtb_removedSats_g;
    Rot[4] = s;
    Rot[7] = 0.0;
    Rot[2] = -d_a * s;
    Rot[5] = -std::cos(TOW) * rtb_removedSats_g;
    Rot[8] = rtb_dayOfYear;
    for (vlen = 0; vlen <= 0; vlen += 2) {
      _mm_storeu_pd
        (&GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
         [vlen], _mm_set1_pd(0.0));
      tmp_2 = _mm_loadu_pd(&Rot[vlen]);
      tmp_0 = _mm_loadu_pd
        (&GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
         [vlen]);
      _mm_storeu_pd
        (&GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
         [vlen], _mm_add_pd(_mm_mul_pd(tmp_2, _mm_set1_pd(delta_rho_data[0])),
                            tmp_0));
      tmp_2 = _mm_loadu_pd(&Rot[vlen + 3]);
      tmp_0 = _mm_loadu_pd
        (&GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
         [vlen]);
      _mm_storeu_pd
        (&GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
         [vlen], _mm_add_pd(_mm_mul_pd(tmp_2, _mm_set1_pd(delta_rho_data[1])),
                            tmp_0));
      tmp_2 = _mm_loadu_pd(&Rot[vlen + 6]);
      tmp_0 = _mm_loadu_pd
        (&GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
         [vlen]);
      _mm_storeu_pd
        (&GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
         [vlen], _mm_add_pd(_mm_mul_pd(tmp_2, _mm_set1_pd(delta_rho_data[2])),
                            tmp_0));
    }

    for (vlen = 2; vlen < 3; vlen++) {
      GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
        [vlen] = 0.0;
      GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
        [vlen] += Rot[vlen] * delta_rho_data[0];
      GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
        [vlen] += Rot[vlen + 3] * delta_rho_data[1];
      GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
        [vlen] += Rot[vlen + 6] * delta_rho_data[2];
    }

    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
      [2] = 0.0;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.solution_available
      = true;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_position_llh
      [0] = TOW;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_position_llh
      [1] = rtb_elevation_mask;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_position_llh
      [2] = WNc;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.receiver_clock_bias
      = 1.0E+10;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.receiver_clock_drift
      = delta_rho_data[3];
  } else {
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.solution_available
      = false;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_position_llh
      [0] = 0.0;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
      [0] = 0.0;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_position_llh
      [1] = 0.0;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
      [1] = 0.0;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_position_llh
      [2] = 0.0;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.user_velocity_ned
      [2] = 0.0;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.receiver_clock_bias
      = 0.0;
    GNSSPreProcessingSingleAntenn_Y.LeastSqureSolutionAntMain.receiver_clock_drift
      = 0.0;
  }

  // End of MATLAB Function: '<Root>/Calculate User Position with LMS'

  // MATLAB Function: '<S3>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles2' incorporates:
  //   Inport: '<Root>/usePosLLHArray'
  //   Outport: '<Root>/GNSSMeasurementBus'
  //   Outport: '<Root>/GNSSMeasurementSize'

  ConvertGNSSMeasuremendVariableT
    (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out,
     &GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m,
     GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
     &GNSSPreProcessingSingleAntenn_Y.GNSSMeasurementBus,
     &GNSSPreProcessingSingleAntenn_Y.GNSSMeasurementSize);

  // MATLAB Function: '<S13>/CalcDOP' incorporates:
  //   Inport: '<Root>/usePosLLHArray'

  if ((GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[0]
       != 0) &&
      (GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[1]
       != 0) &&
      (GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.time_receive != 0.0))
  {
    TOW = std::cos(GNSSPreProcessingSingleAntenn_U.usePosLLHArray[0]);
    rtb_elevation_mask = 6.3995936257584924E+6 / std::sqrt(TOW * TOW *
      0.0067394967422761756 + 1.0);
    rtb_dayOfYear = rtb_elevation_mask +
      GNSSPreProcessingSingleAntenn_U.usePosLLHArray[2];
    WNc = rtb_dayOfYear * TOW * std::cos
      (GNSSPreProcessingSingleAntenn_U.usePosLLHArray[1]);
    TOW = rtb_dayOfYear * TOW * std::sin
      (GNSSPreProcessingSingleAntenn_U.usePosLLHArray[1]);
    rtb_elevation_mask = (0.99330562000985889 * rtb_elevation_mask +
                          GNSSPreProcessingSingleAntenn_U.usePosLLHArray[2]) *
      std::sin(GNSSPreProcessingSingleAntenn_U.usePosLLHArray[0]);
    H_size[0] =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[0];
    c_nz = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position
      [0] << 2;
    if (c_nz - 1 >= 0) {
      std::memset(&H_data[0], 0, static_cast<uint32_T>(c_nz) * sizeof(real_T));
    }

    boffset =
      GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[0];
    if (GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[0]
        - 1 >= 0) {
      tmp_6 =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[0];
      tmp_5 =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[0];
      tmp_3 =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[0];
      tmp_4 =
        GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position[0];
    }

    for (iter = 0; iter < boffset; iter++) {
      rtb_removedSats_g =
        GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position[iter]
        - WNc;
      s =
        GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position[iter
        + tmp_6] - TOW;
      d_a =
        GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position
        [(tmp_5 << 1) + iter] - rtb_elevation_mask;
      rtb_dayOfYear = std::sqrt((rtb_removedSats_g * rtb_removedSats_g + s * s)
        + d_a * d_a);
      H_data[iter] =
        (GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position[
         iter] - WNc) / rtb_dayOfYear;
      H_data[iter + H_size[0]] =
        (GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position[
         iter + tmp_3] - TOW) / rtb_dayOfYear;
      H_data[iter + (H_size[0] << 1)] =
        (GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position[
         (tmp_4 << 1) + iter] - rtb_elevation_mask) / rtb_dayOfYear;
      H_data[iter + H_size[0] * 3] = 1.0;
    }

    iter = GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m.satellite_position
      [0];
    for (vlen = 0; vlen < 4; vlen++) {
      coffset = vlen << 2;
      boffset = vlen * H_size[0];
      y[coffset] = 0.0;
      y[coffset + 1] = 0.0;
      y[coffset + 2] = 0.0;
      y[coffset + 3] = 0.0;
      for (c_nz = 0; c_nz < iter; c_nz++) {
        rtb_dayOfYear = H_data[boffset + c_nz];
        y[coffset] += H_data[c_nz] * rtb_dayOfYear;
        y[coffset + 1] += H_data[H_size[0] + c_nz] * rtb_dayOfYear;
        y[coffset + 2] += H_data[(H_size[0] << 1) + c_nz] * rtb_dayOfYear;
        y[coffset + 3] += H_data[3 * H_size[0] + c_nz] * rtb_dayOfYear;
      }
    }

    std::memset(&Q[0], 0, sizeof(real_T) << 4U);
    ipiv[0] = 1;
    ipiv[1] = 2;
    ipiv[2] = 3;
    for (iter = 0; iter < 3; iter++) {
      c_nz = iter * 5;
      vlen = 4 - iter;
      coffset = 0;
      rtb_dayOfYear = std::abs(y[c_nz]);
      for (boffset = 2; boffset <= vlen; boffset++) {
        s = std::abs(y[(c_nz + boffset) - 1]);
        if (s > rtb_dayOfYear) {
          coffset = boffset - 1;
          rtb_dayOfYear = s;
        }
      }

      if (y[c_nz + coffset] != 0.0) {
        if (coffset != 0) {
          vlen = iter + coffset;
          ipiv[iter] = static_cast<int8_T>(vlen + 1);
          rtb_dayOfYear = y[iter];
          y[iter] = y[vlen];
          y[vlen] = rtb_dayOfYear;
          rtb_dayOfYear = y[iter + 4];
          y[iter + 4] = y[vlen + 4];
          y[vlen + 4] = rtb_dayOfYear;
          rtb_dayOfYear = y[iter + 8];
          y[iter + 8] = y[vlen + 8];
          y[vlen + 8] = rtb_dayOfYear;
          rtb_dayOfYear = y[iter + 12];
          y[iter + 12] = y[vlen + 12];
          y[vlen + 12] = rtb_dayOfYear;
        }

        coffset = (c_nz - iter) + 4;
        boffset = (((((coffset - c_nz) - 1) / 2) << 1) + c_nz) + 2;
        kAcol = boffset - 2;
        for (vlen = c_nz + 2; vlen <= kAcol; vlen += 2) {
          tmp_2 = _mm_loadu_pd(&y[vlen - 1]);
          _mm_storeu_pd(&y[vlen - 1], _mm_div_pd(tmp_2, _mm_set1_pd(y[c_nz])));
        }

        for (vlen = boffset; vlen <= coffset; vlen++) {
          y[vlen - 1] /= y[c_nz];
        }
      }

      vlen = c_nz + 6;
      coffset = 2 - iter;
      for (boffset = 0; boffset <= coffset; boffset++) {
        rtb_dayOfYear = y[((boffset << 2) + c_nz) + 4];
        if (rtb_dayOfYear != 0.0) {
          partialTrueCount = (vlen - iter) + 2;
          for (kAcol = vlen; kAcol <= partialTrueCount; kAcol++) {
            y[kAcol - 1] += y[((c_nz + kAcol) - vlen) + 1] * -rtb_dayOfYear;
          }
        }

        vlen += 4;
      }
    }

    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    if (ipiv[0] > 1) {
      iter = p[ipiv[0] - 1];
      p[ipiv[0] - 1] = 1;
      p[0] = static_cast<int8_T>(iter);
    }

    if (ipiv[1] > 2) {
      iter = p[ipiv[1] - 1];
      p[ipiv[1] - 1] = p[1];
      p[1] = static_cast<int8_T>(iter);
    }

    if (ipiv[2] > 3) {
      iter = p[ipiv[2] - 1];
      p[ipiv[2] - 1] = p[2];
      p[2] = static_cast<int8_T>(iter);
    }

    for (coffset = 0; coffset < 4; coffset++) {
      iter = (p[coffset] - 1) << 2;
      Q[coffset + iter] = 1.0;
      for (boffset = coffset + 1; boffset < 5; boffset++) {
        vlen = (iter + boffset) - 1;
        if (Q[vlen] != 0.0) {
          for (c_nz = boffset + 1; c_nz < 5; c_nz++) {
            partialTrueCount = (iter + c_nz) - 1;
            Q[partialTrueCount] -= y[(((boffset - 1) << 2) + c_nz) - 1] * Q[vlen];
          }
        }
      }
    }

    for (c_nz = 0; c_nz < 4; c_nz++) {
      coffset = c_nz << 2;
      for (boffset = 3; boffset >= 0; boffset--) {
        kAcol = boffset << 2;
        vlen = boffset + coffset;
        rtb_dayOfYear = Q[vlen];
        if (rtb_dayOfYear != 0.0) {
          Q[vlen] = rtb_dayOfYear / y[boffset + kAcol];
          for (partialTrueCount = 0; partialTrueCount < boffset;
               partialTrueCount++) {
            iter = partialTrueCount + coffset;
            Q[iter] -= y[partialTrueCount + kAcol] * Q[vlen];
          }
        }
      }
    }

    d_a = std::sqrt(WNc * WNc + TOW * TOW);
    s = std::atan(rtb_elevation_mask / (d_a * -0.99664718933525243 *
      0.0033528106647474805));
    rtb_removedSats_g = 0.1;
    rtb_dayOfYear = 0.0;
    trueCount = 0;
    while ((std::abs(rtb_removedSats_g - rtb_dayOfYear) > 1.0E-12) && (trueCount
            < 3000)) {
      real_T b_N;
      rtb_dayOfYear = rtb_removedSats_g;
      s = std::cos(s);
      b_N = 6.3995936257584924E+6 / std::sqrt(s * s * 0.0067394967422764341 +
        1.0);
      s = std::atan(rtb_elevation_mask / ((1.0 - 0.0066943799901413165 * b_N /
        (b_N + rtb_removedSats_g)) * d_a));
      rtb_removedSats_g = d_a / std::cos(s) - b_N;
      trueCount++;
    }

    rtb_dayOfYear = s * 57.295779513082323 / 180.0 * 3.1415926535897931;
    rtb_elevation_mask = rt_atan2d_snf(TOW, WNc) * 57.295779513082323 / 180.0 *
      3.1415926535897931;
    WNc = std::cos(rtb_elevation_mask);
    TOW = std::sin(rtb_dayOfYear);
    rtb_elevation_mask = std::sin(rtb_elevation_mask);
    rtb_dayOfYear = std::cos(rtb_dayOfYear);
    Rot[0] = -rtb_elevation_mask;
    Rot[3] = -(TOW * WNc);
    Rot[6] = rtb_dayOfYear * WNc;
    Rot[1] = WNc;
    Rot[4] = -(TOW * rtb_elevation_mask);
    Rot[7] = rtb_dayOfYear * rtb_elevation_mask;
    Rot[2] = 0.0;
    Rot[5] = rtb_dayOfYear;
    Rot[8] = TOW;
    for (vlen = 0; vlen < 3; vlen++) {
      for (partialTrueCount = 0; partialTrueCount < 3; partialTrueCount++) {
        iter = 3 * partialTrueCount + vlen;
        Rot_0[iter] = 0.0;
        c_nz = partialTrueCount << 2;
        Rot_0[iter] += Rot[3 * vlen] * Q[c_nz];
        Rot_0[iter] += Rot[3 * vlen + 1] * Q[c_nz + 1];
        Rot_0[iter] += Rot[3 * vlen + 2] * Q[c_nz + 2];
      }

      for (partialTrueCount = 0; partialTrueCount < 3; partialTrueCount++) {
        iter = 3 * partialTrueCount + vlen;
        Qtemp[iter] = 0.0;
        Qtemp[iter] += Rot[3 * partialTrueCount] * Rot_0[vlen];
        Qtemp[iter] += Rot[3 * partialTrueCount + 1] * Rot_0[vlen + 3];
        Qtemp[iter] += Rot[3 * partialTrueCount + 2] * Rot_0[vlen + 6];
      }
    }

    if ((Qtemp[0] < 0.0) || (Qtemp[4] < 0.0) || (Qtemp[8] < 0.0)) {
      // Outport: '<Root>/DOP'
      GNSSPreProcessingSingleAntenn_Y.DOP[1] = (rtNaN);
      GNSSPreProcessingSingleAntenn_Y.DOP[0] = (rtNaN);
    } else {
      // Outport: '<Root>/DOP'
      GNSSPreProcessingSingleAntenn_Y.DOP[1] = std::sqrt(Qtemp[8]);
      GNSSPreProcessingSingleAntenn_Y.DOP[0] = std::sqrt(Qtemp[0] + Qtemp[4]);
    }
  } else {
    // Outport: '<Root>/DOP'
    GNSSPreProcessingSingleAntenn_Y.DOP[0] = (rtNaN);
    GNSSPreProcessingSingleAntenn_Y.DOP[1] = (rtNaN);
  }

  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_j =
    GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_m;

  // End of MATLAB Function: '<S13>/CalcDOP'

  // BusCreator generated from: '<S3>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles1' incorporates:
  //   BusSelector: '<S12>/Bus Selector'

  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.satellite_position
    [0] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2[0];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.satellite_velocity
    [0] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3[0];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.satellite_position
    [1] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2[1];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.satellite_velocity
    [1] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3[1];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.PRN =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.pseudorange =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.pseudorange_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.pseudorange_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.deltarange =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.deltarange_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.deltarange_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.variance_pseudorange
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.variance_pseudorange_measured
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.variance_deltarange
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.carrierphase =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.carrierphase_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.carrierphase_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.variance_carrierphase_measured
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.locktime =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve.CN0 =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19;
  GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.time_receive =
    GNSSPreProcessingSingleAntenn_B.time_receive;
  if (nz - 1 >= 0) {
    std::memcpy
      (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position
       [0], &GNSSPreProcessingSingleAntenn_B.satellite_position[0], static_cast<
       uint32_T>(nz) * sizeof(real_T));
  }

  if (i2 - 1 >= 0) {
    std::memcpy
      (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_velocity
       [0], &GNSSPreProcessingSingleAntenn_B.satellite_velocity[0], static_cast<
       uint32_T>(i2) * sizeof(real_T));
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.PRN[vlen] =
      GNSSPreProcessingSingleAntenn_B.PRN[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange[vlen] =
      GNSSPreProcessingSingleAntenn_B.pseudorange[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange_raw[vlen] =
      GNSSPreProcessingSingleAntenn_B.pseudorange_raw[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange_satclk_corrected
      [vlen] = GNSSPreProcessingSingleAntenn_B.pseudorange_satclk_corrected[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.deltarange[vlen] =
      GNSSPreProcessingSingleAntenn_B.deltarange[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.deltarange_raw[vlen] =
      GNSSPreProcessingSingleAntenn_B.deltarange_raw[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.deltarange_satclk_corrected
      [vlen] = GNSSPreProcessingSingleAntenn_B.deltarange_satclk_corrected[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_pseudorange[vlen]
      = GNSSPreProcessingSingleAntenn_B.variance_pseudorange[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_pseudorange_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.variance_pseudorange_measured[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_deltarange[vlen]
      = GNSSPreProcessingSingleAntenn_B.variance_deltarange[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.carrierphase[vlen] =
      GNSSPreProcessingSingleAntenn_B.carrierphase[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.carrierphase_raw[vlen] =
      GNSSPreProcessingSingleAntenn_B.carrierphase_raw[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.carrierphase_satclk_corrected
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.carrierphase_satclk_corrected[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_carrierphase_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.variance_carrierphase_measured[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.locktime[vlen] =
      GNSSPreProcessingSingleAntenn_B.locktime[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19; vlen
       ++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.CN0[vlen] =
      GNSSPreProcessingSingleAntenn_B.CN0[vlen];
  }

  GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.base_position[0] =
    GNSSPreProcessingSingleAntenn_B.base_position[0];
  GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.base_position[1] =
    GNSSPreProcessingSingleAntenn_B.base_position[1];
  GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.base_position[2] =
    GNSSPreProcessingSingleAntenn_B.base_position[2];

  // MATLAB Function: '<S3>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles1' incorporates:
  //   Inport: '<Root>/usePosLLHArray'
  //   Outport: '<Root>/GALMeasurementBus'
  //   Outport: '<Root>/GALMeasurementSize1'

  ConvertGNSSMeasuremendVariableT
    (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out,
     &GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Conve,
     GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
     &GNSSPreProcessingSingleAntenn_Y.GALMeasurementBus,
     &GNSSPreProcessingSingleAntenn_Y.GALMeasurementSize1);

  // Outport: '<Root>/GPSGALCorrected'
  GNSSPreProcessingSingleAntenn_Y.GPSGALCorrected[0] =
    GNSSPreProcessingSingleAntenn_B.LogicalOperator1;
  GNSSPreProcessingSingleAntenn_Y.GPSGALCorrected[1] =
    GNSSPreProcessingSingleAntenn_B.LogicalOperator2;

  // BusCreator generated from: '<S3>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles' incorporates:
  //   BusSelector: '<S11>/Bus Selector'

  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.satellite_position
    [0] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2_a[0];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.satellite_velocity
    [0] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3_a[0];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.satellite_position
    [1] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2_a[1];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.satellite_velocity
    [1] = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3_a[1];
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.PRN =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4_b;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.pseudorange =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5_e;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.pseudorange_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6_d;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.pseudorange_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7_i;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.deltarange =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8_m;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.deltarange_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9_i;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.deltarange_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10_f;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.variance_pseudorange
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11_c;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.variance_pseudorange_measured
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12_i;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.variance_deltarange
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13_j;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.carrierphase =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14_f;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.carrierphase_raw
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15_g;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.carrierphase_satclk_corrected
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16_k;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.variance_carrierphase_measured
    = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17_d;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.locktime =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18_o;
  GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b.CN0 =
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19_a;
  GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.time_receive =
    GNSSPreProcessingSingleAntenn_B.time_receive_b;
  c_nz = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2_a[0] *
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS2_a[1];
  if (c_nz - 1 >= 0) {
    std::memcpy
      (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_position
       [0], &GNSSPreProcessingSingleAntenn_B.satellite_position_o[0],
       static_cast<uint32_T>(c_nz) * sizeof(real_T));
  }

  c_nz = GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3_a[0] *
    GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS3_a[1];
  if (c_nz - 1 >= 0) {
    std::memcpy
      (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.satellite_velocity
       [0], &GNSSPreProcessingSingleAntenn_B.satellite_velocity_p[0],
       static_cast<uint32_T>(c_nz) * sizeof(real_T));
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS4_b;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.PRN[vlen] =
      GNSSPreProcessingSingleAntenn_B.PRN_b[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS5_e;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange[vlen] =
      GNSSPreProcessingSingleAntenn_B.pseudorange_l[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS6_d;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange_raw[vlen] =
      GNSSPreProcessingSingleAntenn_B.pseudorange_raw_k[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS7_i;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.pseudorange_satclk_corrected
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.pseudorange_satclk_corrected_a[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS8_m;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.deltarange[vlen] =
      GNSSPreProcessingSingleAntenn_B.deltarange_h[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS9_i;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.deltarange_raw[vlen] =
      GNSSPreProcessingSingleAntenn_B.deltarange_raw_k[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS10_f;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.deltarange_satclk_corrected
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.deltarange_satclk_corrected_n[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS11_c;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_pseudorange[vlen]
      = GNSSPreProcessingSingleAntenn_B.variance_pseudorange_g[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS12_i;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_pseudorange_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.variance_pseudorange_measured_i[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS13_j;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_deltarange[vlen]
      = GNSSPreProcessingSingleAntenn_B.variance_deltarange_n[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS14_f;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.carrierphase[vlen] =
      GNSSPreProcessingSingleAntenn_B.carrierphase_a[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS15_g;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.carrierphase_raw[vlen] =
      GNSSPreProcessingSingleAntenn_B.carrierphase_raw_c[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS16_k;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.carrierphase_satclk_corrected
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.carrierphase_satclk_corrected_m[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS17_d;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.variance_carrierphase_measured
      [vlen] =
      GNSSPreProcessingSingleAntenn_B.variance_carrierphase_measure_o[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS18_o;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.locktime[vlen] =
      GNSSPreProcessingSingleAntenn_B.locktime_k[vlen];
  }

  for (vlen = 0; vlen < GNSSPreProcessingSingleAnten_DW.BusSelector_DIMS19_a;
       vlen++) {
    GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.CN0[vlen] =
      GNSSPreProcessingSingleAntenn_B.CN0_f[vlen];
  }

  GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.base_position[0] =
    GNSSPreProcessingSingleAntenn_B.base_position_b[0];
  GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.base_position[1] =
    GNSSPreProcessingSingleAntenn_B.base_position_b[1];
  GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out.base_position[2] =
    GNSSPreProcessingSingleAntenn_B.base_position_b[2];

  // MATLAB Function: '<S3>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles' incorporates:
  //   Inport: '<Root>/usePosLLHArray'
  //   Outport: '<Root>/GPSMeasurementBus'
  //   Outport: '<Root>/GPSMeasurementSize'

  ConvertGNSSMeasuremendVariableT
    (&GNSSPreProcessingSingleAntenn_B.GNSS_Measurement_out,
     &GNSSPreProcessingSingleAnten_DW.BusConversion_InsertedFor_Con_b,
     GNSSPreProcessingSingleAntenn_U.usePosLLHArray,
     &GNSSPreProcessingSingleAntenn_Y.GPSMeasurementBus,
     &GNSSPreProcessingSingleAntenn_Y.GPSMeasurementSize);

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.1, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  (&GNSSPreProcessingSingleAnten_M)->Timing.clockTick0++;
}

// Model initialize function
void GNSS_preprocessingModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // Initialize DataMapInfo substructure containing ModelMap for C API
  GNSSPreProcessingSingleAntenna_InitializeDataMapInfo
    ((&GNSSPreProcessingSingleAnten_M));

  // SystemInitialize for Atomic SubSystem: '<S3>/Mode Switch'
  // InitializeConditions for UnitDelay: '<S128>/Delay Input1'
  //
  //  Block description for '<S128>/Delay Input1':
  //
  //   Store in Global RAM

  GNSSPreProcessingSingleAnten_DW.DelayInput1_DSTATE =
    GNSSPreProcessingSingleAntenn_P.DetectChange_vinit;

  // InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S124>/Constant1'

  GNSSPreProcessingSingleAnten_DW.DiscreteTimeIntegrator_DSTATE =
    GNSSPreProcessingSingleAntenn_P.Constant1_Value;
  GNSSPreProcessingSingleAnten_DW.DiscreteTimeIntegrator_PrevRese = 2;

  // InitializeConditions for Memory: '<S129>/Memory'
  GNSSPreProcessingSingleAnten_DW.Memory_PreviousInput =
    GNSSPreProcessingSingleAntenn_P.SRFlipFlop_initial_condition;

  // SystemInitialize for Chart: '<S125>/choose correction mode'
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps = false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l1 = false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gps.enable_gps_l2 = false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo = false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e1 =
    false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5a =
    false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5b =
    false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.galileo.enable_galileo_e5 =
    false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.enable_gate = false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl1 = 0U;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl2 = 0U;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl3 = 0U;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl4 = 0U;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl5 = 0U;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl6 = 0U;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl7 = 0U;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl8 = 0U;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.gate.prn_psl9 = 0U;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.elevation_mask = 0.0;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_galileo_timebase =
    false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_differential_correction
    = false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_tropospheric_correction
    = false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_ionospheric_correction =
    false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_SatPosVel_calculation =
    false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.enable_WL_correction = false;
  GNSSPreProcessingSingleAntenn_B.parameters_gnss.use_measured_variance = false;

  // End of SystemInitialize for SubSystem: '<S3>/Mode Switch'

  // SystemInitialize for Enabled SubSystem: '<S3>/GPS'
  // SystemInitialize for MATLAB Function: '<S23>/Calculate Differential Corrections' 
  CalculateDifferentialCorre_Init
    (&GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorrect);

  // SystemInitialize for Enabled SubSystem: '<S11>/GPS L2C Stream'
  G_GPSsinglefrequencystream_Init(&GNSSPreProcessingSingleAntenn_B.GPSL2CStream,
    &GNSSPreProcessingSingleAntenn_P.GPSL2CStream);

  // End of SystemInitialize for SubSystem: '<S11>/GPS L2C Stream'

  // SystemInitialize for Enabled SubSystem: '<S11>/GPS L5 Stream'
  G_GPSsinglefrequencystream_Init(&GNSSPreProcessingSingleAntenn_B.GPSL5Stream,
    &GNSSPreProcessingSingleAntenn_P.GPSL5Stream);

  // End of SystemInitialize for SubSystem: '<S11>/GPS L5 Stream'

  // SystemInitialize for Enabled SubSystem: '<S11>/GPS L1 Stream'
  G_GPSsinglefrequencystream_Init(&GNSSPreProcessingSingleAntenn_B.GPSL1Stream,
    &GNSSPreProcessingSingleAntenn_P.GPSL1Stream);

  // End of SystemInitialize for SubSystem: '<S11>/GPS L1 Stream'

  // SystemInitialize for BusSelector: '<S11>/Bus Selector' incorporates:
  //   Outport: '<S11>/timeOfWeek'

  GNSSPreProcessingSingleAntenn_B.time_receive_b =
    GNSSPreProcessingSingleAntenn_P.timeOfWeek_Y0;

  // SystemInitialize for BusSelector: '<S11>/Bus Selector' incorporates:
  //   Outport: '<S11>/basePosition'

  GNSSPreProcessingSingleAntenn_B.base_position_b[0] =
    GNSSPreProcessingSingleAntenn_P.basePosition_Y0;
  GNSSPreProcessingSingleAntenn_B.base_position_b[1] =
    GNSSPreProcessingSingleAntenn_P.basePosition_Y0;
  GNSSPreProcessingSingleAntenn_B.base_position_b[2] =
    GNSSPreProcessingSingleAntenn_P.basePosition_Y0;

  // SystemInitialize for Logic: '<S23>/Logical Operator1' incorporates:
  //   Outport: '<S11>/GPSMeasurementCorrected'

  GNSSPreProcessingSingleAntenn_B.LogicalOperator1 =
    GNSSPreProcessingSingleAntenn_P.GPSMeasurementCorrected_Y0;

  // End of SystemInitialize for SubSystem: '<S3>/GPS'

  // SystemInitialize for Enabled SubSystem: '<S3>/Galileo'
  // SystemInitialize for MATLAB Function: '<S70>/Calculate Differential Corrections' 
  CalculateDifferentialCor_j_Init
    (&GNSSPreProcessingSingleAnten_DW.sf_CalculateDifferentialCorre_l);

  // SystemInitialize for Enabled SubSystem: '<S12>/Galileo E1 stream'
  Galileosinglefrequencystre_Init
    (&GNSSPreProcessingSingleAntenn_B.GalileoE1stream,
     &GNSSPreProcessingSingleAntenn_P.GalileoE1stream);

  // End of SystemInitialize for SubSystem: '<S12>/Galileo E1 stream'

  // SystemInitialize for Enabled SubSystem: '<S12>/Galileo E5a stream'
  Galileosinglefrequencystre_Init
    (&GNSSPreProcessingSingleAntenn_B.GalileoE5astream,
     &GNSSPreProcessingSingleAntenn_P.GalileoE5astream);

  // End of SystemInitialize for SubSystem: '<S12>/Galileo E5a stream'

  // SystemInitialize for Enabled SubSystem: '<S12>/Galileo E5b stream'
  Galileosinglefrequencystre_Init
    (&GNSSPreProcessingSingleAntenn_B.GalileoE5bstream,
     &GNSSPreProcessingSingleAntenn_P.GalileoE5bstream);

  // End of SystemInitialize for SubSystem: '<S12>/Galileo E5b stream'

  // SystemInitialize for Enabled SubSystem: '<S12>/Galileo E5 stream'
  Galileosinglefrequencystre_Init
    (&GNSSPreProcessingSingleAntenn_B.GalileoE5stream,
     &GNSSPreProcessingSingleAntenn_P.GalileoE5stream);

  // End of SystemInitialize for SubSystem: '<S12>/Galileo E5 stream'

  // SystemInitialize for BusSelector: '<S12>/Bus Selector' incorporates:
  //   Outport: '<S12>/time receive'

  GNSSPreProcessingSingleAntenn_B.time_receive =
    GNSSPreProcessingSingleAntenn_P.timereceive_Y0;

  // SystemInitialize for BusSelector: '<S12>/Bus Selector' incorporates:
  //   Outport: '<S12>/basePosition'

  GNSSPreProcessingSingleAntenn_B.base_position[0] =
    GNSSPreProcessingSingleAntenn_P.basePosition_Y0_a;
  GNSSPreProcessingSingleAntenn_B.base_position[1] =
    GNSSPreProcessingSingleAntenn_P.basePosition_Y0_a;
  GNSSPreProcessingSingleAntenn_B.base_position[2] =
    GNSSPreProcessingSingleAntenn_P.basePosition_Y0_a;

  // SystemInitialize for Logic: '<S70>/Logical Operator2' incorporates:
  //   Outport: '<S12>/GALMeasurementCorrected'

  GNSSPreProcessingSingleAntenn_B.LogicalOperator2 =
    GNSSPreProcessingSingleAntenn_P.GALMeasurementCorrected_Y0;

  // End of SystemInitialize for SubSystem: '<S3>/Galileo'

  // SystemInitialize for MATLAB Function: '<S3>/Merge GNSS Measurement'
  GNSSPreProcessingSingleAnten_DW.writeIdx = 1.0;

  // SystemInitialize for MATLAB Function: '<S117>/MATLAB Function' incorporates:
  //   SubSystem: '<S117>/GNSS Fault Detection Identification Exclusion'

  // SystemInitialize for Outport: '<S118>/GNSS_Measurement_out'
  GNSSPreProcessingSingleAntenn_B.GNSS_measurement_out =
    GNSSPreProcessingSingleAntenn_P.GNSS_Measurement_out_Y0;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.satellite_position[0] = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.satellite_velocity[0] = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.satellite_position[1] = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.satellite_velocity[1] = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.PRN = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.pseudorange = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.pseudorange_raw = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.pseudorange_satclk_corrected
    = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.deltarange = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.deltarange_raw = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.deltarange_satclk_corrected
    = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.variance_pseudorange = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.variance_pseudorange_measured
    = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.variance_deltarange = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.carrierphase = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.carrierphase_raw = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.carrierphase_satclk_corrected
    = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.variance_carrierphase_measured
    = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.locktime = 1;
  GNSSPreProcessingSingleAnten_DW.SFunction_DIMS2_b5.CN0 = 1;

  // SystemInitialize for Outport: '<Root>/integrityFlag' incorporates:
  //   Outport: '<S118>/alert'

  GNSSPreProcessingSingleAntenn_Y.integrityFlag =
    GNSSPreProcessingSingleAntenn_P.alert_Y0;
  for (int32_T i{0}; i < 80; i++) {
    // SystemInitialize for MATLAB Function: '<S118>/Fault Exclusion'
    GNSSPreProcessingSingleAnten_DW.BUFFER[i] = (rtNaN);

    // SystemInitialize for Outport: '<Root>/faultyPRNs' incorporates:
    //   Outport: '<S118>/PRNs_identified'

    GNSSPreProcessingSingleAntenn_Y.faultyPRNs[i] =
      GNSSPreProcessingSingleAntenn_P.PRNs_identified_Y0;
  }
}

// Model terminate function
void GNSS_preprocessingModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
GNSS_preprocessingModelClass::GNSS_preprocessingModelClass() :
  GNSSPreProcessingSingleAntenn_U(),
  GNSSPreProcessingSingleAntenn_Y(),
  GNSSPreProcessingSingleAntenn_B(),
  GNSSPreProcessingSingleAnten_DW(),
  GNSSPreProcessingSingleAnten_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
GNSS_preprocessingModelClass::~GNSS_preprocessingModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_GNSSPreProcessingSin_T * GNSS_preprocessingModelClass::getRTM()
{
  return (&GNSSPreProcessingSingleAnten_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
