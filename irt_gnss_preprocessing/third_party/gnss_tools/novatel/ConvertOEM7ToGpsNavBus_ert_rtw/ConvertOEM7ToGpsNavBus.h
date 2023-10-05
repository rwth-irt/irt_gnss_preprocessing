//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGpsNavBus.h
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
#ifndef RTW_HEADER_ConvertOEM7ToGpsNavBus_h_
#define RTW_HEADER_ConvertOEM7ToGpsNavBus_h_
#include "rtwtypes.h"
#include "ConvertOEM7ToGpsNavBus_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model ConvertOEM7ToGpsNavBus
class ConvertOEM7ToGpsNavBus final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_ConvertOEM7ToGpsNavBus_T {
    uint32_T iode1Array[37];
    uint32_T iode2Array[37];
    uint32_T iodcArray[37];
    uint32_T iodcLsbArray[37];
    boolean_T healthMaskArray[37];
    int8_T ii_data[37];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_ConvertOEM7ToGpsNavBus_T {
    OEM7_GpsEphem Oem7GpsEphemBus;     // '<Root>/Oem7GpsEphemBus'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_ConvertOEM7ToGpsNavBus_T {
    gnssraw_gps_nav_t GpsNavBus;       // '<Root>/GpsNavBus'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_ConvertOEM7ToGpsNavB_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  ConvertOEM7ToGpsNavBus(ConvertOEM7ToGpsNavBus const&) = delete;

  // Assignment Operator
  ConvertOEM7ToGpsNavBus& operator= (ConvertOEM7ToGpsNavBus const&) & = delete;

  // Move Constructor
  ConvertOEM7ToGpsNavBus(ConvertOEM7ToGpsNavBus &&) = delete;

  // Move Assignment Operator
  ConvertOEM7ToGpsNavBus& operator= (ConvertOEM7ToGpsNavBus &&) = delete;

  // Real-Time Model get method
  ConvertOEM7ToGpsNavBus::RT_MODEL_ConvertOEM7ToGpsNavB_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_ConvertOEM7ToGpsNavBus_T
    *pExtU_ConvertOEM7ToGpsNavBus_T)
  {
    ConvertOEM7ToGpsNavBus_U = *pExtU_ConvertOEM7ToGpsNavBus_T;
  }

  // Root outports get method
  const ExtY_ConvertOEM7ToGpsNavBus_T &getExternalOutputs() const
  {
    return ConvertOEM7ToGpsNavBus_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  ConvertOEM7ToGpsNavBus();

  // Destructor
  ~ConvertOEM7ToGpsNavBus();

  // private data and function members
 private:
  // External inputs
  ExtU_ConvertOEM7ToGpsNavBus_T ConvertOEM7ToGpsNavBus_U;

  // External outputs
  ExtY_ConvertOEM7ToGpsNavBus_T ConvertOEM7ToGpsNavBus_Y;

  // Block signals
  B_ConvertOEM7ToGpsNavBus_T ConvertOEM7ToGpsNavBus_B;

  // Real-Time Model
  RT_MODEL_ConvertOEM7ToGpsNavB_T ConvertOEM7ToGpsNavBus_M;
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
//  '<Root>' : 'ConvertOEM7ToGpsNavBus'
//  '<S1>'   : 'ConvertOEM7ToGpsNavBus/OEM7ToGpsNavBus'

#endif                                 // RTW_HEADER_ConvertOEM7ToGpsNavBus_h_

//
// File trailer for generated code.
//
// [EOF]
//
