//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGalInavBus.cpp
//
// Code generated for Simulink model 'ConvertOEM7ToGalInavBus'.
//
// Model version                  : 2.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 19:56:12 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ConvertOEM7ToGalInavBus.h"
#include "rtwtypes.h"

// Model step function
void ConvertOEM7ToGalInavBus::step()
{
  int32_T i;
  int32_T ii_size_idx_0;
  int32_T trueCount;
  uint8_T tmp_data[36];
  boolean_T exitg1;

  // MATLAB Function: '<Root>/OEM7 GalInavBusToGalInavBus'
  trueCount = 0;
  for (i = 0; i < 36; i++) {
    uint32_T tmp;
    boolean_T c;

    // Outport: '<Root>/GalInavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7 GalInavBusToGalInavBus'
    //   Inport: '<Root>/Oem7GalInavEphemerisBus'
    //   MATLAB Function: '<Root>/OEM7 GalInavBusToGalInavBus'

    ConvertOEM7ToGalInavBus_Y.GalInavBus.TOW[i] = static_cast<real_T>
      (ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.header_ms[i]) * 0.001;
    ConvertOEM7ToGalInavBus_Y.GalInavBus.WNc[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.header_week[i];

    // MATLAB Function: '<Root>/OEM7 GalInavBusToGalInavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7 GalInavBusToGalInavBus'
    //   Inport: '<Root>/Oem7GalInavEphemerisBus'

    tmp = ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.SatId[i];
    if (tmp > 255U) {
      tmp = 255U;
    }

    ConvertOEM7ToGalInavBus_Y.GalInavBus.SVID[i] = static_cast<uint8_T>(tmp);
    c = (ConvertOEM7ToGalInavBus_Y.GalInavBus.SVID[i] != 0);
    if (c) {
      trueCount++;
    }

    ConvertOEM7ToGalInavBus_B.c[i] = c;
  }

  // MATLAB Function: '<Root>/OEM7 GalInavBusToGalInavBus'
  ii_size_idx_0 = trueCount;
  trueCount = 0;
  for (i = 0; i < 36; i++) {
    if (ConvertOEM7ToGalInavBus_B.c[i]) {
      ConvertOEM7ToGalInavBus_B.ii_data[trueCount] = static_cast<int8_T>(i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < ii_size_idx_0; trueCount++) {
    i = static_cast<int32_T>
      (ConvertOEM7ToGalInavBus_Y.GalInavBus.SVID[ConvertOEM7ToGalInavBus_B.ii_data
       [trueCount] - 1] + 70U);
    if (static_cast<uint32_T>(i) > 255U) {
      i = 255;
    }

    tmp_data[trueCount] = static_cast<uint8_T>(i);
  }

  for (trueCount = 0; trueCount < ii_size_idx_0; trueCount++) {
    ConvertOEM7ToGalInavBus_Y.GalInavBus.SVID[ConvertOEM7ToGalInavBus_B.ii_data[trueCount]
      - 1] = tmp_data[trueCount];
  }

  for (i = 0; i < 36; i++) {
    // Outport: '<Root>/GalInavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7 GalInavBusToGalInavBus'
    //   Inport: '<Root>/Oem7GalInavEphemerisBus'
    //   MATLAB Function: '<Root>/OEM7 GalInavBusToGalInavBus'

    ConvertOEM7ToGalInavBus_Y.GalInavBus.SQRT_A[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.RootA[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.M_0[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.M0[i] *
      0.31830988618378997;
    ConvertOEM7ToGalInavBus_Y.GalInavBus.E[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Ecc[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.I_0[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.I0[i] *
      0.31830988618378997;
    ConvertOEM7ToGalInavBus_Y.GalInavBus.omega[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Omega[i] *
      0.31830988618378997;
    ConvertOEM7ToGalInavBus_Y.GalInavBus.OMEGA_0[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Omega0[i] *
      0.31830988618378997;
    ConvertOEM7ToGalInavBus_Y.GalInavBus.OMEGADOT[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.OmegaDot[i] *
      0.31830988618378997;
    ConvertOEM7ToGalInavBus_Y.GalInavBus.IDOT[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.IDot[i] *
      0.31830988618378997;
    ConvertOEM7ToGalInavBus_Y.GalInavBus.DELTA_N[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.DeltaN[i] *
      0.31830988618378997;
    ConvertOEM7ToGalInavBus_Y.GalInavBus.C_uc[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Cuc[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.C_us[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Cus[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.C_rc[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Crc[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.C_rs[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Crs[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.C_ic[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Cic[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.C_is[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Cis[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.T_oc[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.T0c[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.T_oe[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.T0e[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.A_f2[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Af2[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.A_f1[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Af1[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.A_f0[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.Af0[i];
    ConvertOEM7ToGalInavBus_Y.GalInavBus.WNt_oc[i] = 0U;
    ConvertOEM7ToGalInavBus_Y.GalInavBus.WNt_oe[i] = 0U;
    ConvertOEM7ToGalInavBus_Y.GalInavBus.IODnav[i] =
      ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.IODnav[i];

    // MATLAB Function: '<Root>/OEM7 GalInavBusToGalInavBus' incorporates:
    //   BusCreator generated from: '<Root>/OEM7 GalInavBusToGalInavBus'
    //   Inport: '<Root>/Oem7GalInavEphemerisBus'

    ConvertOEM7ToGalInavBus_B.c[i] =
      ((ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.E1bHealth[i] != 0) ||
       (ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.E1bDVS[i] != 0) ||
       (ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.E5bHealth[i] != 0) ||
       (ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.E5bDVS[i] != 0));
    ConvertOEM7ToGalInavBus_B.b[i] =
      (ConvertOEM7ToGalInavBus_U.Oem7GalInavEphemerisBus.SISA_Index[i] == 255);
  }

  // MATLAB Function: '<Root>/OEM7 GalInavBusToGalInavBus' incorporates:
  //   Outport: '<Root>/GalInavBus'

  i = 0;
  trueCount = 0;
  exitg1 = false;
  while ((!exitg1) && (trueCount < 36)) {
    if (ConvertOEM7ToGalInavBus_B.c[trueCount] ||
        ConvertOEM7ToGalInavBus_B.b[trueCount]) {
      i++;
      ConvertOEM7ToGalInavBus_B.ii_data[i - 1] = static_cast<int8_T>(trueCount +
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
      ii = ConvertOEM7ToGalInavBus_B.ii_data[trueCount];
      ConvertOEM7ToGalInavBus_Y.GalInavBus.TOW[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.WNc[ii - 1] = 0U;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.SVID[ii - 1] = 0U;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.SQRT_A[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.M_0[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.E[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.I_0[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.omega[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.OMEGA_0[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.OMEGADOT[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.IDOT[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.DELTA_N[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.C_uc[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.C_us[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.C_rc[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.C_rs[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.C_ic[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.C_is[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.T_oc[ii - 1] = 0U;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.T_oe[ii - 1] = 0U;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.A_f2[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.A_f1[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.A_f0[ii - 1] = 0.0;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.WNt_oc[ii - 1] = 0U;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.WNt_oe[ii - 1] = 0U;
      ConvertOEM7ToGalInavBus_Y.GalInavBus.IODnav[ii - 1] = 0U;
    }
  }
}

// Model initialize function
void ConvertOEM7ToGalInavBus::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void ConvertOEM7ToGalInavBus::terminate()
{
  // (no terminate code required)
}

// Constructor
ConvertOEM7ToGalInavBus::ConvertOEM7ToGalInavBus() :
  ConvertOEM7ToGalInavBus_U(),
  ConvertOEM7ToGalInavBus_Y(),
  ConvertOEM7ToGalInavBus_B(),
  ConvertOEM7ToGalInavBus_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
ConvertOEM7ToGalInavBus::~ConvertOEM7ToGalInavBus()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
ConvertOEM7ToGalInavBus::RT_MODEL_ConvertOEM7ToGalInav_T
  * ConvertOEM7ToGalInavBus::getRTM()
{
  return (&ConvertOEM7ToGalInavBus_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
