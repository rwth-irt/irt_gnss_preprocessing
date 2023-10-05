//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGpsIonBus.cpp
//
// Code generated for Simulink model 'ConvertOEM7ToGpsIonBus'.
//
// Model version                  : 2.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 19:54:30 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ConvertOEM7ToGpsIonBus.h"
#include "rtwtypes.h"

// Model step function
void ConvertOEM7ToGpsIonBus::step()
{
  // Outport: '<Root>/GpsIonBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7To GPSIonBus'
  //   Inport: '<Root>/Oem7IonUtcBus'
  //   MATLAB Function: '<Root>/OEM7To GPSIonBus'

  ConvertOEM7ToGpsIonBus_Y.GpsIonBus.TOW = static_cast<real_T>
    (ConvertOEM7ToGpsIonBus_U.Oem7IonUtcBus.header_ms) * 0.001;
  ConvertOEM7ToGpsIonBus_Y.GpsIonBus.WNc =
    ConvertOEM7ToGpsIonBus_U.Oem7IonUtcBus.header_week;
  ConvertOEM7ToGpsIonBus_Y.GpsIonBus.SVID = 0U;
  ConvertOEM7ToGpsIonBus_Y.GpsIonBus.alpha_0 =
    ConvertOEM7ToGpsIonBus_U.Oem7IonUtcBus.a0;
  ConvertOEM7ToGpsIonBus_Y.GpsIonBus.alpha_1 =
    ConvertOEM7ToGpsIonBus_U.Oem7IonUtcBus.a1;
  ConvertOEM7ToGpsIonBus_Y.GpsIonBus.alpha_2 =
    ConvertOEM7ToGpsIonBus_U.Oem7IonUtcBus.a2;
  ConvertOEM7ToGpsIonBus_Y.GpsIonBus.alpha_3 =
    ConvertOEM7ToGpsIonBus_U.Oem7IonUtcBus.a3;
  ConvertOEM7ToGpsIonBus_Y.GpsIonBus.beta_0 =
    ConvertOEM7ToGpsIonBus_U.Oem7IonUtcBus.b0;
  ConvertOEM7ToGpsIonBus_Y.GpsIonBus.beta_1 =
    ConvertOEM7ToGpsIonBus_U.Oem7IonUtcBus.b1;
  ConvertOEM7ToGpsIonBus_Y.GpsIonBus.beta_2 =
    ConvertOEM7ToGpsIonBus_U.Oem7IonUtcBus.b2;
  ConvertOEM7ToGpsIonBus_Y.GpsIonBus.beta_3 =
    ConvertOEM7ToGpsIonBus_U.Oem7IonUtcBus.b3;
}

// Model initialize function
void ConvertOEM7ToGpsIonBus::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void ConvertOEM7ToGpsIonBus::terminate()
{
  // (no terminate code required)
}

// Constructor
ConvertOEM7ToGpsIonBus::ConvertOEM7ToGpsIonBus() :
  ConvertOEM7ToGpsIonBus_U(),
  ConvertOEM7ToGpsIonBus_Y(),
  ConvertOEM7ToGpsIonBus_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
ConvertOEM7ToGpsIonBus::~ConvertOEM7ToGpsIonBus()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
ConvertOEM7ToGpsIonBus::RT_MODEL_ConvertOEM7ToGpsIonB_T * ConvertOEM7ToGpsIonBus::
  getRTM()
{
  return (&ConvertOEM7ToGpsIonBus_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
