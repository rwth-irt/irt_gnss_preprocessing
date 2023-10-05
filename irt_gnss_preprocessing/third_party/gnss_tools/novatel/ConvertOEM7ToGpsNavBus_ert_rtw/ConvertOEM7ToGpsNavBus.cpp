//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGpsNavBus.cpp
//
// Code generated for Simulink model 'ConvertOEM7ToGpsNavBus'.
//
// Model version                  : 2.3
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 19:53:16 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ConvertOEM7ToGpsNavBus.h"
#include <cstring>
#include <emmintrin.h>
#include <cmath>
#include "rtwtypes.h"

// Model step function
void ConvertOEM7ToGpsNavBus::step()
{
  real_T pp;
  int32_T b_k;
  int32_T i;
  uint32_T tmp;
  boolean_T exitg1;
  for (i = 0; i < 32; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.TOW[i] = static_cast<real_T>
      (ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.header_ms[i]) * 0.001;
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.TOW[i + 32] = 0.0;
  }

  // Outport: '<Root>/GpsNavBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
  //   Inport: '<Root>/Oem7GpsEphemBus'
  //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.WNc[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.header_week[0], sizeof
              (uint16_T) << 5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.WNc[i + 32] = 0U;
  }

  for (i = 0; i < 32; i++) {
    tmp = ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.PRN[i];
    if (tmp > 255U) {
      tmp = 255U;
    }

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.SVID[i] = static_cast<uint8_T>(tmp);
  }

  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.SVID[i + 32] = 0U;
  }

  // MATLAB Function: '<Root>/OEM7ToGpsNavBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
  //   Inport: '<Root>/Oem7GpsEphemBus'

  for (i = 0; i < 32; i++) {
    tmp = ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.health[i];
    if (tmp > 255U) {
      tmp = 255U;
    }

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.Health[i] = static_cast<uint8_T>(tmp);
  }

  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.Health[i + 32] = 0U;
  }

  for (i = 0; i < 32; i++) {
    // MATLAB Function: '<Root>/OEM7ToGpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'

    tmp = ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.IODC[i];
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.IODC[i] = static_cast<uint16_T>(tmp);
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.IODC[i + 32] = 0U;
  }

  for (i = 0; i < 32; i++) {
    // MATLAB Function: '<Root>/OEM7ToGpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'

    tmp = ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.IODE2[i];
    if (tmp > 255U) {
      tmp = 255U;
    }

    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.IODE[i] = static_cast<uint8_T>(tmp);
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.IODE[i + 32] = 0U;
  }

  for (i = 0; i <= 30; i += 2) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    _mm_storeu_pd(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_gd[i], _mm_mul_pd
                  (_mm_loadu_pd(&ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.tgd[i]),
                   _mm_set1_pd(0.31830988618378997)));
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_gd[i + 32] = 0.0;
  }

  for (i = 0; i < 32; i++) {
    // MATLAB Function: '<Root>/OEM7ToGpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'

    pp = std::round(ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.T0c[i]);
    if (pp < 4.294967296E+9) {
      if (pp >= 0.0) {
        // Outport: '<Root>/GpsNavBus'
        ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_oc[i] = static_cast<uint32_T>(pp);
      } else {
        // Outport: '<Root>/GpsNavBus'
        ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_oc[i] = 0U;
      }
    } else {
      // Outport: '<Root>/GpsNavBus'
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_oc[i] = MAX_uint32_T;
    }
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_oc[i + 32] = 0U;
  }

  // Outport: '<Root>/GpsNavBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
  //   Inport: '<Root>/Oem7GpsEphemBus'
  //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.A_f2[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Af2[0], sizeof(real_T) <<
              5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.A_f2[i + 32] = 0.0;
  }

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.A_f1[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Af1[0], sizeof(real_T) <<
              5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.A_f1[i + 32] = 0.0;
  }

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.A_f0[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Af0[0], sizeof(real_T) <<
              5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.A_f0[i + 32] = 0.0;
  }

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_rs[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Crs[0], sizeof(real_T) <<
              5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_rs[i + 32] = 0.0;
  }

  for (i = 0; i <= 30; i += 2) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    _mm_storeu_pd(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.DELTA_N[i], _mm_mul_pd
                  (_mm_loadu_pd
                   (&ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.DeltaN[i]),
                   _mm_set1_pd(0.31830988618378997)));
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.DELTA_N[i + 32] = 0.0;
  }

  for (i = 0; i <= 30; i += 2) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    _mm_storeu_pd(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.M_0[i], _mm_mul_pd
                  (_mm_loadu_pd(&ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.M0[i]),
                   _mm_set1_pd(0.31830988618378997)));
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.M_0[i + 32] = 0.0;
  }

  // Outport: '<Root>/GpsNavBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
  //   Inport: '<Root>/Oem7GpsEphemBus'
  //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_uc[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Cuc[0], sizeof(real_T) <<
              5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_uc[i + 32] = 0.0;
  }

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.E[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Ecc[0], sizeof(real_T) <<
              5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.E[i + 32] = 0.0;
  }

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_us[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Cus[0], sizeof(real_T) <<
              5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_us[i + 32] = 0.0;
  }

  // MATLAB Function: '<Root>/OEM7ToGpsNavBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
  //   Inport: '<Root>/Oem7GpsEphemBus'

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.SQRT_A[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.A[0], sizeof(real_T) <<
              5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.SQRT_A[i + 32] = 0.0;
  }

  for (i = 0; i <= 34; i += 2) {
    __m128d tmp_0;

    // MATLAB Function: '<Root>/OEM7ToGpsNavBus'
    tmp_0 = _mm_loadu_pd(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.SQRT_A[i]);
    _mm_storeu_pd(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.SQRT_A[i], _mm_sqrt_pd
                  (tmp_0));
  }

  // MATLAB Function: '<Root>/OEM7ToGpsNavBus'
  for (i = 36; i < 37; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.SQRT_A[i] = std::sqrt
      (ConvertOEM7ToGpsNavBus_Y.GpsNavBus.SQRT_A[i]);
  }

  for (i = 0; i < 32; i++) {
    // MATLAB Function: '<Root>/OEM7ToGpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'

    pp = std::round(ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.T0e[i]);
    if (pp < 4.294967296E+9) {
      if (pp >= 0.0) {
        // Outport: '<Root>/GpsNavBus'
        ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_oe[i] = static_cast<uint32_T>(pp);
      } else {
        // Outport: '<Root>/GpsNavBus'
        ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_oe[i] = 0U;
      }
    } else {
      // Outport: '<Root>/GpsNavBus'
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_oe[i] = MAX_uint32_T;
    }
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_oe[i + 32] = 0U;
  }

  // Outport: '<Root>/GpsNavBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
  //   Inport: '<Root>/Oem7GpsEphemBus'
  //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_ic[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Cic[0], sizeof(real_T) <<
              5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_ic[i + 32] = 0.0;
  }

  for (i = 0; i <= 30; i += 2) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    _mm_storeu_pd(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.OMEGA_0[i], _mm_mul_pd
                  (_mm_loadu_pd
                   (&ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Omega0[i]),
                   _mm_set1_pd(0.31830988618378997)));
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.OMEGA_0[i + 32] = 0.0;
  }

  // Outport: '<Root>/GpsNavBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
  //   Inport: '<Root>/Oem7GpsEphemBus'
  //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_is[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Cis[0], sizeof(real_T) <<
              5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_is[i + 32] = 0.0;
  }

  for (i = 0; i <= 30; i += 2) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    _mm_storeu_pd(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.I_0[i], _mm_mul_pd
                  (_mm_loadu_pd(&ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.I0[i]),
                   _mm_set1_pd(0.31830988618378997)));
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.I_0[i + 32] = 0.0;
  }

  // Outport: '<Root>/GpsNavBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
  //   Inport: '<Root>/Oem7GpsEphemBus'
  //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

  std::memcpy(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_rc[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Crc[0], sizeof(real_T) <<
              5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_rc[i + 32] = 0.0;
  }

  for (i = 0; i <= 30; i += 2) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    _mm_storeu_pd(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.omega[i], _mm_mul_pd
                  (_mm_loadu_pd
                   (&ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.Omega[i]),
                   _mm_set1_pd(0.31830988618378997)));
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.omega[i + 32] = 0.0;
  }

  for (i = 0; i <= 30; i += 2) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    _mm_storeu_pd(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.OMEGADOT[i], _mm_mul_pd
                  (_mm_loadu_pd
                   (&ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.OmegaDot[i]),
                   _mm_set1_pd(0.31830988618378997)));
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.OMEGADOT[i + 32] = 0.0;
  }

  for (i = 0; i <= 30; i += 2) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
    //   Inport: '<Root>/Oem7GpsEphemBus'
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    _mm_storeu_pd(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.IDOT[i], _mm_mul_pd
                  (_mm_loadu_pd(&ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.IDot[i]),
                   _mm_set1_pd(0.31830988618378997)));
  }

  for (i = 0; i < 5; i++) {
    // Outport: '<Root>/GpsNavBus' incorporates:
    //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

    ConvertOEM7ToGpsNavBus_Y.GpsNavBus.IDOT[i + 32] = 0.0;
  }

  // Outport: '<Root>/GpsNavBus' incorporates:
  //   MATLAB Function: '<Root>/OEM7ToGpsNavBus'

  std::memset(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.WNt_oc[0], 0, 37U * sizeof
              (uint16_T));
  std::memset(&ConvertOEM7ToGpsNavBus_Y.GpsNavBus.WNt_oe[0], 0, 37U * sizeof
              (uint16_T));

  // MATLAB Function: '<Root>/OEM7ToGpsNavBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToGpsNavBus'
  //   Inport: '<Root>/Oem7GpsEphemBus'
  //   Outport: '<Root>/GpsNavBus'

  std::memcpy(&ConvertOEM7ToGpsNavBus_B.iode1Array[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.IODE1[0], sizeof
              (uint32_T) << 5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_B.iode1Array[i + 32] = 0U;
  }

  std::memcpy(&ConvertOEM7ToGpsNavBus_B.iode2Array[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.IODE2[0], sizeof
              (uint32_T) << 5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_B.iode2Array[i + 32] = 0U;
  }

  std::memcpy(&ConvertOEM7ToGpsNavBus_B.iodcArray[0],
              &ConvertOEM7ToGpsNavBus_U.Oem7GpsEphemBus.IODC[0], sizeof(uint32_T)
              << 5U);
  for (i = 0; i < 5; i++) {
    ConvertOEM7ToGpsNavBus_B.iodcArray[i + 32] = 0U;
  }

  for (i = 0; i < 37; i++) {
    real_T d;
    pp = 1.0;
    d = 0.0;
    for (b_k = 0; b_k < 8; b_k++) {
      if ((1U << b_k & ConvertOEM7ToGpsNavBus_B.iodcArray[i]) != 0U) {
        d += pp;
      }

      pp *= 2.0;
    }

    if (d < 4.294967296E+9) {
      ConvertOEM7ToGpsNavBus_B.iodcLsbArray[i] = static_cast<uint32_T>(d);
    } else {
      ConvertOEM7ToGpsNavBus_B.iodcLsbArray[i] = MAX_uint32_T;
    }

    ConvertOEM7ToGpsNavBus_B.healthMaskArray[i] =
      (ConvertOEM7ToGpsNavBus_Y.GpsNavBus.Health[i] != 0);
  }

  i = 0;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 37)) {
    if ((ConvertOEM7ToGpsNavBus_B.iode1Array[b_k] !=
         ConvertOEM7ToGpsNavBus_B.iode2Array[b_k]) ||
        (ConvertOEM7ToGpsNavBus_B.iode1Array[b_k] !=
         ConvertOEM7ToGpsNavBus_B.iodcLsbArray[b_k]) ||
        (ConvertOEM7ToGpsNavBus_B.iode2Array[b_k] !=
         ConvertOEM7ToGpsNavBus_B.iodcLsbArray[b_k]) ||
        ConvertOEM7ToGpsNavBus_B.healthMaskArray[b_k]) {
      i++;
      ConvertOEM7ToGpsNavBus_B.ii_data[i - 1] = static_cast<int8_T>(b_k + 1);
      if (i >= 37) {
        exitg1 = true;
      } else {
        b_k++;
      }
    } else {
      b_k++;
    }
  }

  if (i < 1) {
    i = 0;
  }

  if (i != 0) {
    for (b_k = 0; b_k < i; b_k++) {
      int8_T ii;
      ii = ConvertOEM7ToGpsNavBus_B.ii_data[b_k];
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.TOW[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.WNc[ii - 1] = 0U;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.SVID[ii - 1] = 0U;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.Health[ii - 1] = 0U;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.IODC[ii - 1] = 0U;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.IODE[ii - 1] = 0U;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_gd[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_oc[ii - 1] = 0U;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.A_f2[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.A_f1[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.A_f0[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_rs[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.DELTA_N[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.M_0[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_uc[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.E[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_us[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.SQRT_A[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.T_oe[ii - 1] = 0U;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_ic[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.OMEGA_0[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_is[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.I_0[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.C_rc[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.omega[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.OMEGADOT[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.IDOT[ii - 1] = 0.0;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.WNt_oc[ii - 1] = 0U;
      ConvertOEM7ToGpsNavBus_Y.GpsNavBus.WNt_oe[ii - 1] = 0U;
    }
  }
}

// Model initialize function
void ConvertOEM7ToGpsNavBus::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void ConvertOEM7ToGpsNavBus::terminate()
{
  // (no terminate code required)
}

// Constructor
ConvertOEM7ToGpsNavBus::ConvertOEM7ToGpsNavBus() :
  ConvertOEM7ToGpsNavBus_U(),
  ConvertOEM7ToGpsNavBus_Y(),
  ConvertOEM7ToGpsNavBus_B(),
  ConvertOEM7ToGpsNavBus_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
ConvertOEM7ToGpsNavBus::~ConvertOEM7ToGpsNavBus()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
ConvertOEM7ToGpsNavBus::RT_MODEL_ConvertOEM7ToGpsNavB_T * ConvertOEM7ToGpsNavBus::
  getRTM()
{
  return (&ConvertOEM7ToGpsNavBus_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
