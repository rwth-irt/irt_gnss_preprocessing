//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: getSatInfoNovAtel.h
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
#ifndef RTW_HEADER_getSatInfoNovAtel_h_
#define RTW_HEADER_getSatInfoNovAtel_h_
#include "rtwtypes.h"
#include "getSatInfoNovAtel_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model getSatInfoNovAtel
class getSatInfoNovAtel final
{
  // public data and function members
 public:
  // External inputs (root inport signals with default storage)
  struct ExtU_getSatInfoNovAtel_T {
    uint32_T OEM7_ChannelTrackingStatus;// '<Root>/OEM7_ChannelTrackingStatus'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_getSatInfoNovAtel_T {
    uint16_T SatelliteSystem;          // '<Root>/SatelliteSystem'
    uint16_T SBFSignalType;            // '<Root>/SBFSignalType'
    uint16_T OEM7SignalType;           // '<Root>/OEM7SignalType'
    uint16_T SBFObsInfo;               // '<Root>/SBFObsInfo'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_getSatInfoNovAtel_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  getSatInfoNovAtel(getSatInfoNovAtel const&) = delete;

  // Assignment Operator
  getSatInfoNovAtel& operator= (getSatInfoNovAtel const&) & = delete;

  // Move Constructor
  getSatInfoNovAtel(getSatInfoNovAtel &&) = delete;

  // Move Assignment Operator
  getSatInfoNovAtel& operator= (getSatInfoNovAtel &&) = delete;

  // Real-Time Model get method
  getSatInfoNovAtel::RT_MODEL_getSatInfoNovAtel_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_getSatInfoNovAtel_T
    *pExtU_getSatInfoNovAtel_T)
  {
    getSatInfoNovAtel_U = *pExtU_getSatInfoNovAtel_T;
  }

  // Root outports get method
  const ExtY_getSatInfoNovAtel_T &getExternalOutputs() const
  {
    return getSatInfoNovAtel_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  getSatInfoNovAtel();

  // Destructor
  ~getSatInfoNovAtel();

  // private data and function members
 private:
  // External inputs
  ExtU_getSatInfoNovAtel_T getSatInfoNovAtel_U;

  // External outputs
  ExtY_getSatInfoNovAtel_T getSatInfoNovAtel_Y;

  // Real-Time Model
  RT_MODEL_getSatInfoNovAtel_T getSatInfoNovAtel_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'getSatInfoNovAtel'
//  '<S1>'   : 'getSatInfoNovAtel/OEM7RangeToMeasEpochRAW'

#endif                                 // RTW_HEADER_getSatInfoNovAtel_h_

//
// File trailer for generated code.
//
// [EOF]
//
