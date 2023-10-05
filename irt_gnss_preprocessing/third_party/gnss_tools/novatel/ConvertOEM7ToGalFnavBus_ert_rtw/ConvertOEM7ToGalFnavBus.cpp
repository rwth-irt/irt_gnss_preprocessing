//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGalFnavBus.cpp
//
// Code generated for Simulink model 'ConvertOEM7ToGalFnavBus'.
//
// Model version                  : 2.4
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 20:11:23 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ConvertOEM7ToGalFnavBus.h"
#include "rtwtypes.h"

// Model step function
void ConvertOEM7ToGalFnavBus::step()
{
  int32_T i;
  int32_T ii_size_idx_0;
  int32_T trueCount;
  uint8_T tmp_data[36];
  boolean_T exitg1;

  // MATLAB Function: '<Root>/OEM7 ToGalFnavBus'
  trueCount = 0;
  for (i = 0; i < 36; i++) {
    uint32_T tmp;
    boolean_T c;

    // Outport: '<Root>/GalFnavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7 ToGalFnavBus'
    //   Inport: '<Root>/Oem7GalFnavEphemerisBus'
    //   MATLAB Function: '<Root>/OEM7 ToGalFnavBus'

    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.TOW[i] = static_cast<real_T>
      (ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.header_ms[i]) * 0.001;
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.WNc[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.header_week[i];

    // MATLAB Function: '<Root>/OEM7 ToGalFnavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7 ToGalFnavBus'
    //   Inport: '<Root>/Oem7GalFnavEphemerisBus'

    tmp = ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.SatId[i];
    if (tmp > 255U) {
      tmp = 255U;
    }

    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.SVID[i] = static_cast<uint8_T>(tmp);
    c = (ConvertOEM7ToGalFnavBus_Y.GalFnavBus.SVID[i] != 0);
    if (c) {
      trueCount++;
    }

    ConvertOEM7ToGalFnavBus_B.c[i] = c;
  }

  // MATLAB Function: '<Root>/OEM7 ToGalFnavBus'
  ii_size_idx_0 = trueCount;
  trueCount = 0;
  for (i = 0; i < 36; i++) {
    if (ConvertOEM7ToGalFnavBus_B.c[i]) {
      ConvertOEM7ToGalFnavBus_B.ii_data[trueCount] = static_cast<int8_T>(i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < ii_size_idx_0; trueCount++) {
    i = static_cast<int32_T>
      (ConvertOEM7ToGalFnavBus_Y.GalFnavBus.SVID[ConvertOEM7ToGalFnavBus_B.ii_data
       [trueCount] - 1] + 70U);
    if (static_cast<uint32_T>(i) > 255U) {
      i = 255;
    }

    tmp_data[trueCount] = static_cast<uint8_T>(i);
  }

  for (trueCount = 0; trueCount < ii_size_idx_0; trueCount++) {
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.SVID[ConvertOEM7ToGalFnavBus_B.ii_data[trueCount]
      - 1] = tmp_data[trueCount];
  }

  for (i = 0; i < 36; i++) {
    // Outport: '<Root>/GalFnavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7 ToGalFnavBus'
    //   Inport: '<Root>/Oem7GalFnavEphemerisBus'
    //   MATLAB Function: '<Root>/OEM7 ToGalFnavBus'

    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.SQRT_A[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.RootA[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.M_0[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.M0[i] *
      0.31830988618378997;
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.E[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Ecc[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.I_0[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.I0[i] *
      0.31830988618378997;
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.omega[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Omega[i] *
      0.31830988618378997;
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.OMEGA_0[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Omega0[i] *
      0.31830988618378997;
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.OMEGADOT[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.OmegaDot[i] *
      0.31830988618378997;
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.IDOT[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.IDot[i] *
      0.31830988618378997;
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.DELTA_N[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.DeltaN[i] *
      0.31830988618378997;
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_uc[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Cuc[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_us[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Cus[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_rc[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Crc[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_rs[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Crs[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_ic[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Cic[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_is[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Cis[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.T_oc[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.T0c[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.T_oe[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.T0e[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.A_f2[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Af2[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.A_f1[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Af1[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.A_f0[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.Af0[i];
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.WNt_oc[i] = 0U;
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.WNt_oe[i] = 0U;
    ConvertOEM7ToGalFnavBus_Y.GalFnavBus.IODnav[i] =
      ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.IODnav[i];

    // MATLAB Function: '<Root>/OEM7 ToGalFnavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7 ToGalFnavBus'
    //   Inport: '<Root>/Oem7GalFnavEphemerisBus'

    ConvertOEM7ToGalFnavBus_B.c[i] =
      ((ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.E5aHealth[i] != 0) ||
       (ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.E5aDVS[i] != 0));
    ConvertOEM7ToGalFnavBus_B.b[i] =
      (ConvertOEM7ToGalFnavBus_U.Oem7GalFnavEphemerisBus.SISA_Index[i] == 255);
  }

  // MATLAB Function: '<Root>/OEM7 ToGalFnavBus' incorporates:
  //   Outport: '<Root>/GalFnavBus'

  i = 0;
  trueCount = 0;
  exitg1 = false;
  while ((!exitg1) && (trueCount < 36)) {
    if (ConvertOEM7ToGalFnavBus_B.c[trueCount] ||
        ConvertOEM7ToGalFnavBus_B.b[trueCount]) {
      i++;
      ConvertOEM7ToGalFnavBus_B.ii_data[i - 1] = static_cast<int8_T>(trueCount +
        1);
      if (i >= 36) {
        exitg1 = true;
      } else {
        trueCount++;
      }
    } else {
      trueCount++;
    }
  }

  if (i < 1) {
    i = 0;
  }

  if (i != 0) {
    for (trueCount = 0; trueCount < i; trueCount++) {
      int8_T ii;
      ii = ConvertOEM7ToGalFnavBus_B.ii_data[trueCount];
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.TOW[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.WNc[ii - 1] = 0U;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.SVID[ii - 1] = 0U;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.SQRT_A[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.M_0[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.E[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.I_0[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.omega[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.OMEGA_0[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.OMEGADOT[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.IDOT[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.DELTA_N[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_uc[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_us[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_rc[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_rs[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_ic[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.C_is[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.T_oc[ii - 1] = 0U;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.T_oe[ii - 1] = 0U;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.A_f2[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.A_f1[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.A_f0[ii - 1] = 0.0;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.WNt_oc[ii - 1] = 0U;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.WNt_oe[ii - 1] = 0U;
      ConvertOEM7ToGalFnavBus_Y.GalFnavBus.IODnav[ii - 1] = 0U;
    }
  }
}

// Model initialize function
void ConvertOEM7ToGalFnavBus::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void ConvertOEM7ToGalFnavBus::terminate()
{
  // (no terminate code required)
}

// Constructor
ConvertOEM7ToGalFnavBus::ConvertOEM7ToGalFnavBus() :
  ConvertOEM7ToGalFnavBus_U(),
  ConvertOEM7ToGalFnavBus_Y(),
  ConvertOEM7ToGalFnavBus_B(),
  ConvertOEM7ToGalFnavBus_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
ConvertOEM7ToGalFnavBus::~ConvertOEM7ToGalFnavBus()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
ConvertOEM7ToGalFnavBus::RT_MODEL_ConvertOEM7ToGalFnav_T
  * ConvertOEM7ToGalFnavBus::getRTM()
{
  return (&ConvertOEM7ToGalFnavBus_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
