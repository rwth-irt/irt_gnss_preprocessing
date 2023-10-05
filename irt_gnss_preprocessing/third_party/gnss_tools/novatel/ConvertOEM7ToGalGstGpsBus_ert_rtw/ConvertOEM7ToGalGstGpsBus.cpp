//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGalGstGpsBus.cpp
//
// Code generated for Simulink model 'ConvertOEM7ToGalGstGpsBus'.
//
// Model version                  : 2.6
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 20:10:35 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ConvertOEM7ToGalGstGpsBus.h"
#include "rtwtypes.h"

// Model step function
void ConvertOEM7ToGalGstGpsBus::step()
{
  uint32_T tmp;

  // Outport: '<Root>/GalGstGpsBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7 ToGalGstGpsBus'
  //   Inport: '<Root>/Oem7GalClockBus'
  //   MATLAB Function: '<Root>/OEM7 ToGalGstGpsBus'

  ConvertOEM7ToGalGstGpsBus_Y.GalGstGpsBus.TOW = static_cast<real_T>
    (ConvertOEM7ToGalGstGpsBus_U.Oem7GalClockBus.header_ms) * 0.001;
  ConvertOEM7ToGalGstGpsBus_Y.GalGstGpsBus.WNc =
    ConvertOEM7ToGalGstGpsBus_U.Oem7GalClockBus.header_week;
  ConvertOEM7ToGalGstGpsBus_Y.GalGstGpsBus.SVID = MAX_uint8_T;
  ConvertOEM7ToGalGstGpsBus_Y.GalGstGpsBus.Source = 0U;
  ConvertOEM7ToGalGstGpsBus_Y.GalGstGpsBus.A_1G =
    ConvertOEM7ToGalGstGpsBus_U.Oem7GalClockBus.A1g;
  ConvertOEM7ToGalGstGpsBus_Y.GalGstGpsBus.A_0G =
    ConvertOEM7ToGalGstGpsBus_U.Oem7GalClockBus.A0g;
  ConvertOEM7ToGalGstGpsBus_Y.GalGstGpsBus.t_oG =
    ConvertOEM7ToGalGstGpsBus_U.Oem7GalClockBus.T0g;

  // MATLAB Function: '<Root>/OEM7 ToGalGstGpsBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7 ToGalGstGpsBus'
  //   Inport: '<Root>/Oem7GalClockBus'

  tmp = ConvertOEM7ToGalGstGpsBus_U.Oem7GalClockBus.WN0g;
  if (ConvertOEM7ToGalGstGpsBus_U.Oem7GalClockBus.WN0g > 255U) {
    tmp = 255U;
  }

  // Outport: '<Root>/GalGstGpsBus' incorporates:
  //   MATLAB Function: '<Root>/OEM7 ToGalGstGpsBus'

  ConvertOEM7ToGalGstGpsBus_Y.GalGstGpsBus.WN_oG = static_cast<uint8_T>(tmp);
}

// Model initialize function
void ConvertOEM7ToGalGstGpsBus::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void ConvertOEM7ToGalGstGpsBus::terminate()
{
  // (no terminate code required)
}

// Constructor
ConvertOEM7ToGalGstGpsBus::ConvertOEM7ToGalGstGpsBus() :
  ConvertOEM7ToGalGstGpsBus_U(),
  ConvertOEM7ToGalGstGpsBus_Y(),
  ConvertOEM7ToGalGstGpsBus_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
ConvertOEM7ToGalGstGpsBus::~ConvertOEM7ToGalGstGpsBus()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
ConvertOEM7ToGalGstGpsBus::RT_MODEL_ConvertOEM7ToGalGstG_T
  * ConvertOEM7ToGalGstGpsBus::getRTM()
{
  return (&ConvertOEM7ToGalGstGpsBus_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
