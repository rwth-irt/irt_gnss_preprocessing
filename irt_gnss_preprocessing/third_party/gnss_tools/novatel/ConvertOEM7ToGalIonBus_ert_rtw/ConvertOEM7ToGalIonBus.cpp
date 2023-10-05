//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGalIonBus.cpp
//
// Code generated for Simulink model 'ConvertOEM7ToGalIonBus'.
//
// Model version                  : 2.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 19:55:17 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ConvertOEM7ToGalIonBus.h"
#include "rtwtypes.h"

// Model step function
void ConvertOEM7ToGalIonBus::step()
{
  // Outport: '<Root>/GalIonBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7 ToGALIonoBus'
  //   Inport: '<Root>/Oem7GalIonoBus'
  //   MATLAB Function: '<Root>/OEM7 ToGALIonoBus'

  ConvertOEM7ToGalIonBus_Y.GalIonBus.TOW = static_cast<real_T>
    (ConvertOEM7ToGalIonBus_U.Oem7GalIonoBus.header_ms) * 0.001;
  ConvertOEM7ToGalIonBus_Y.GalIonBus.WNc =
    ConvertOEM7ToGalIonBus_U.Oem7GalIonoBus.header_week;
  ConvertOEM7ToGalIonBus_Y.GalIonBus.SVID = 0U;
  ConvertOEM7ToGalIonBus_Y.GalIonBus.Source = 0U;
  ConvertOEM7ToGalIonBus_Y.GalIonBus.a_i0 =
    ConvertOEM7ToGalIonBus_U.Oem7GalIonoBus.Ai0;
  ConvertOEM7ToGalIonBus_Y.GalIonBus.a_i1 =
    ConvertOEM7ToGalIonBus_U.Oem7GalIonoBus.Ai1;
  ConvertOEM7ToGalIonBus_Y.GalIonBus.a_i2 =
    ConvertOEM7ToGalIonBus_U.Oem7GalIonoBus.Ai2;
  ConvertOEM7ToGalIonBus_Y.GalIonBus.stormflags = 0U;
}

// Model initialize function
void ConvertOEM7ToGalIonBus::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void ConvertOEM7ToGalIonBus::terminate()
{
  // (no terminate code required)
}

// Constructor
ConvertOEM7ToGalIonBus::ConvertOEM7ToGalIonBus() :
  ConvertOEM7ToGalIonBus_U(),
  ConvertOEM7ToGalIonBus_Y(),
  ConvertOEM7ToGalIonBus_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
ConvertOEM7ToGalIonBus::~ConvertOEM7ToGalIonBus()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
ConvertOEM7ToGalIonBus::RT_MODEL_ConvertOEM7ToGalIonB_T * ConvertOEM7ToGalIonBus::
  getRTM()
{
  return (&ConvertOEM7ToGalIonBus_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
