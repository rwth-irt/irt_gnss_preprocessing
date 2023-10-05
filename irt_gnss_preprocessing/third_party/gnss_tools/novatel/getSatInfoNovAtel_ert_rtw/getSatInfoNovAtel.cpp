//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: getSatInfoNovAtel.cpp
//
// Code generated for Simulink model 'getSatInfoNovAtel'.
//
// Model version                  : 1.8
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Apr 10 12:41:51 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "getSatInfoNovAtel.h"
#include "rtwtypes.h"

// Model step function
void getSatInfoNovAtel::step()
{
  real_T b_d;
  real_T d;
  int32_T c_d;
  uint32_T b;
  uint32_T b_b;

  // MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW' incorporates:
  //   Inport: '<Root>/OEM7_ChannelTrackingStatus'

  d = 0.0;
  b = ((getSatInfoNovAtel_U.OEM7_ChannelTrackingStatus & 65536U) != 0U);
  if (b != 0U) {
    d = b;
  }

  b = ((getSatInfoNovAtel_U.OEM7_ChannelTrackingStatus & 131072U) != 0U);
  if (b != 0U) {
    d += 2.0 * static_cast<real_T>(b);
  }

  b = ((getSatInfoNovAtel_U.OEM7_ChannelTrackingStatus & 262144U) != 0U);
  if (b != 0U) {
    d += 4.0 * static_cast<real_T>(b);
  }

  if (d < 4.294967296E+9) {
    b = static_cast<uint32_T>(d);
  } else {
    b = MAX_uint32_T;
  }

  if (b > 65535U) {
    b = 65535U;
  }

  d = 1.0;
  b_d = 0.0;
  for (c_d = 0; c_d < 5; c_d++) {
    b_b = ((1U << static_cast<uint8_T>(static_cast<uint8_T>(static_cast<real_T>
              (c_d) + 22.0) - 1) &
            getSatInfoNovAtel_U.OEM7_ChannelTrackingStatus) != 0U);
    if (b_b != 0U) {
      b_d += d * static_cast<real_T>(b_b);
    }

    d *= 2.0;
  }

  if (b_d < 4.294967296E+9) {
    b_b = static_cast<uint32_T>(b_d);
  } else {
    b_b = MAX_uint32_T;
  }

  if (b_b > 65535U) {
    b_b = 65535U;
  }

  c_d = 0;
  if ((getSatInfoNovAtel_U.OEM7_ChannelTrackingStatus & 268435456U) != 0U) {
    c_d = 1;
  }

  switch (static_cast<uint16_T>(b)) {
   case 0:
    switch (static_cast<uint16_T>(b_b)) {
     case 0U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 0U;
      break;

     case 5U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 255U;
      break;

     case 9U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 255U;
      break;

     case 14U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 4U;
      break;

     case 16U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 255U;
      break;

     case 17U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 3U;
      break;

     default:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 255U;
      break;
    }
    break;

   case 3:
    switch (static_cast<uint16_T>(b_b)) {
     case 2U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 17U;
      break;

     case 6U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 255U;
      break;

     case 7U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 255U;
      break;

     case 12U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 20U;
      break;

     case 17U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 21U;
      break;

     case 20U:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 22U;
      break;

     default:
      // Outport: '<Root>/SBFSignalType'
      getSatInfoNovAtel_Y.SBFSignalType = 255U;
      break;
    }
    break;

   default:
    // Outport: '<Root>/SBFSignalType'
    getSatInfoNovAtel_Y.SBFSignalType = 255U;
    break;
  }

  // Outport: '<Root>/SatelliteSystem' incorporates:
  //   MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'

  getSatInfoNovAtel_Y.SatelliteSystem = static_cast<uint16_T>(b);

  // Outport: '<Root>/OEM7SignalType' incorporates:
  //   MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'

  getSatInfoNovAtel_Y.OEM7SignalType = static_cast<uint16_T>(b_b);

  // Outport: '<Root>/SBFObsInfo' incorporates:
  //   MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'

  getSatInfoNovAtel_Y.SBFObsInfo = static_cast<uint16_T>(c_d);
}

// Model initialize function
void getSatInfoNovAtel::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void getSatInfoNovAtel::terminate()
{
  // (no terminate code required)
}

// Constructor
getSatInfoNovAtel::getSatInfoNovAtel() :
  getSatInfoNovAtel_U(),
  getSatInfoNovAtel_Y(),
  getSatInfoNovAtel_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
getSatInfoNovAtel::~getSatInfoNovAtel()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
getSatInfoNovAtel::RT_MODEL_getSatInfoNovAtel_T * getSatInfoNovAtel::getRTM()
{
  return (&getSatInfoNovAtel_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
