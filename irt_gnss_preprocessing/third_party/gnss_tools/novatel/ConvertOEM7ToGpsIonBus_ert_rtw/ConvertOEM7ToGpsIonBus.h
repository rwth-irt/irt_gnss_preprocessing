//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGpsIonBus.h
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
#ifndef RTW_HEADER_ConvertOEM7ToGpsIonBus_h_
#define RTW_HEADER_ConvertOEM7ToGpsIonBus_h_
#include "rtwtypes.h"
#include "ConvertOEM7ToGpsIonBus_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model ConvertOEM7ToGpsIonBus
class ConvertOEM7ToGpsIonBus final
{
  // public data and function members
 public:
  // External inputs (root inport signals with default storage)
  struct ExtU_ConvertOEM7ToGpsIonBus_T {
    OEM7_IonUtc Oem7IonUtcBus;         // '<Root>/Oem7IonUtcBus'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_ConvertOEM7ToGpsIonBus_T {
    gnssraw_gps_ion_t GpsIonBus;       // '<Root>/GpsIonBus'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_ConvertOEM7ToGpsIonB_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  ConvertOEM7ToGpsIonBus(ConvertOEM7ToGpsIonBus const&) = delete;

  // Assignment Operator
  ConvertOEM7ToGpsIonBus& operator= (ConvertOEM7ToGpsIonBus const&) & = delete;

  // Move Constructor
  ConvertOEM7ToGpsIonBus(ConvertOEM7ToGpsIonBus &&) = delete;

  // Move Assignment Operator
  ConvertOEM7ToGpsIonBus& operator= (ConvertOEM7ToGpsIonBus &&) = delete;

  // Real-Time Model get method
  ConvertOEM7ToGpsIonBus::RT_MODEL_ConvertOEM7ToGpsIonB_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_ConvertOEM7ToGpsIonBus_T
    *pExtU_ConvertOEM7ToGpsIonBus_T)
  {
    ConvertOEM7ToGpsIonBus_U = *pExtU_ConvertOEM7ToGpsIonBus_T;
  }

  // Root outports get method
  const ExtY_ConvertOEM7ToGpsIonBus_T &getExternalOutputs() const
  {
    return ConvertOEM7ToGpsIonBus_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  ConvertOEM7ToGpsIonBus();

  // Destructor
  ~ConvertOEM7ToGpsIonBus();

  // private data and function members
 private:
  // External inputs
  ExtU_ConvertOEM7ToGpsIonBus_T ConvertOEM7ToGpsIonBus_U;

  // External outputs
  ExtY_ConvertOEM7ToGpsIonBus_T ConvertOEM7ToGpsIonBus_Y;

  // Real-Time Model
  RT_MODEL_ConvertOEM7ToGpsIonB_T ConvertOEM7ToGpsIonBus_M;
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
//  '<Root>' : 'ConvertOEM7ToGpsIonBus'
//  '<S1>'   : 'ConvertOEM7ToGpsIonBus/OEM7To GPSIonBus'

#endif                                 // RTW_HEADER_ConvertOEM7ToGpsIonBus_h_

//
// File trailer for generated code.
//
// [EOF]
//
