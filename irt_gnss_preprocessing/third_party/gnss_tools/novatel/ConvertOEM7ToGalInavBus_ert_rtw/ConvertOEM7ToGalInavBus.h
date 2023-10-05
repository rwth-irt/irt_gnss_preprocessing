//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGalInavBus.h
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
#ifndef RTW_HEADER_ConvertOEM7ToGalInavBus_h_
#define RTW_HEADER_ConvertOEM7ToGalInavBus_h_
#include "rtwtypes.h"
#include "ConvertOEM7ToGalInavBus_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model ConvertOEM7ToGalInavBus
class ConvertOEM7ToGalInavBus final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_ConvertOEM7ToGalInavBus_T {
    boolean_T b[36];
    boolean_T c[36];
    int8_T ii_data[36];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_ConvertOEM7ToGalInavBus_T {
    OEM7_GalInavEphemeris Oem7GalInavEphemerisBus;// '<Root>/Oem7GalInavEphemerisBus' 
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_ConvertOEM7ToGalInavBus_T {
    gnssraw_gal_nav_t GalInavBus;      // '<Root>/GalInavBus'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_ConvertOEM7ToGalInav_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  ConvertOEM7ToGalInavBus(ConvertOEM7ToGalInavBus const&) = delete;

  // Assignment Operator
  ConvertOEM7ToGalInavBus& operator= (ConvertOEM7ToGalInavBus const&) & = delete;

  // Move Constructor
  ConvertOEM7ToGalInavBus(ConvertOEM7ToGalInavBus &&) = delete;

  // Move Assignment Operator
  ConvertOEM7ToGalInavBus& operator= (ConvertOEM7ToGalInavBus &&) = delete;

  // Real-Time Model get method
  ConvertOEM7ToGalInavBus::RT_MODEL_ConvertOEM7ToGalInav_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_ConvertOEM7ToGalInavBus_T
    *pExtU_ConvertOEM7ToGalInavBus_T)
  {
    ConvertOEM7ToGalInavBus_U = *pExtU_ConvertOEM7ToGalInavBus_T;
  }

  // Root outports get method
  const ExtY_ConvertOEM7ToGalInavBus_T &getExternalOutputs() const
  {
    return ConvertOEM7ToGalInavBus_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  ConvertOEM7ToGalInavBus();

  // Destructor
  ~ConvertOEM7ToGalInavBus();

  // private data and function members
 private:
  // External inputs
  ExtU_ConvertOEM7ToGalInavBus_T ConvertOEM7ToGalInavBus_U;

  // External outputs
  ExtY_ConvertOEM7ToGalInavBus_T ConvertOEM7ToGalInavBus_Y;

  // Block signals
  B_ConvertOEM7ToGalInavBus_T ConvertOEM7ToGalInavBus_B;

  // Real-Time Model
  RT_MODEL_ConvertOEM7ToGalInav_T ConvertOEM7ToGalInavBus_M;
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
//  '<Root>' : 'ConvertOEM7ToGalInavBus'
//  '<S1>'   : 'ConvertOEM7ToGalInavBus/OEM7 GalInavBusToGalInavBus'

#endif                                 // RTW_HEADER_ConvertOEM7ToGalInavBus_h_

//
// File trailer for generated code.
//
// [EOF]
//
