//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGalFnavBus.h
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
#ifndef RTW_HEADER_ConvertOEM7ToGalFnavBus_h_
#define RTW_HEADER_ConvertOEM7ToGalFnavBus_h_
#include "rtwtypes.h"
#include "ConvertOEM7ToGalFnavBus_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model ConvertOEM7ToGalFnavBus
class ConvertOEM7ToGalFnavBus final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_ConvertOEM7ToGalFnavBus_T {
    boolean_T b[36];
    boolean_T c[36];
    int8_T ii_data[36];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_ConvertOEM7ToGalFnavBus_T {
    OEM7_GalFnavEphemeris Oem7GalFnavEphemerisBus;// '<Root>/Oem7GalFnavEphemerisBus' 
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_ConvertOEM7ToGalFnavBus_T {
    gnssraw_gal_nav_t GalFnavBus;      // '<Root>/GalFnavBus'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_ConvertOEM7ToGalFnav_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  ConvertOEM7ToGalFnavBus(ConvertOEM7ToGalFnavBus const&) = delete;

  // Assignment Operator
  ConvertOEM7ToGalFnavBus& operator= (ConvertOEM7ToGalFnavBus const&) & = delete;

  // Move Constructor
  ConvertOEM7ToGalFnavBus(ConvertOEM7ToGalFnavBus &&) = delete;

  // Move Assignment Operator
  ConvertOEM7ToGalFnavBus& operator= (ConvertOEM7ToGalFnavBus &&) = delete;

  // Real-Time Model get method
  ConvertOEM7ToGalFnavBus::RT_MODEL_ConvertOEM7ToGalFnav_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_ConvertOEM7ToGalFnavBus_T
    *pExtU_ConvertOEM7ToGalFnavBus_T)
  {
    ConvertOEM7ToGalFnavBus_U = *pExtU_ConvertOEM7ToGalFnavBus_T;
  }

  // Root outports get method
  const ExtY_ConvertOEM7ToGalFnavBus_T &getExternalOutputs() const
  {
    return ConvertOEM7ToGalFnavBus_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  ConvertOEM7ToGalFnavBus();

  // Destructor
  ~ConvertOEM7ToGalFnavBus();

  // private data and function members
 private:
  // External inputs
  ExtU_ConvertOEM7ToGalFnavBus_T ConvertOEM7ToGalFnavBus_U;

  // External outputs
  ExtY_ConvertOEM7ToGalFnavBus_T ConvertOEM7ToGalFnavBus_Y;

  // Block signals
  B_ConvertOEM7ToGalFnavBus_T ConvertOEM7ToGalFnavBus_B;

  // Real-Time Model
  RT_MODEL_ConvertOEM7ToGalFnav_T ConvertOEM7ToGalFnavBus_M;
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
//  '<Root>' : 'ConvertOEM7ToGalFnavBus'
//  '<S1>'   : 'ConvertOEM7ToGalFnavBus/OEM7 ToGalFnavBus'

#endif                                 // RTW_HEADER_ConvertOEM7ToGalFnavBus_h_

//
// File trailer for generated code.
//
// [EOF]
//
