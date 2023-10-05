//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToGalIonBus.h
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
#ifndef RTW_HEADER_ConvertOEM7ToGalIonBus_h_
#define RTW_HEADER_ConvertOEM7ToGalIonBus_h_
#include "rtwtypes.h"
#include "ConvertOEM7ToGalIonBus_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model ConvertOEM7ToGalIonBus
class ConvertOEM7ToGalIonBus final
{
  // public data and function members
 public:
  // External inputs (root inport signals with default storage)
  struct ExtU_ConvertOEM7ToGalIonBus_T {
    OEM7_GalIono Oem7GalIonoBus;       // '<Root>/Oem7GalIonoBus'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_ConvertOEM7ToGalIonBus_T {
    gnssraw_gal_ion_t GalIonBus;       // '<Root>/GalIonBus'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_ConvertOEM7ToGalIonB_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  ConvertOEM7ToGalIonBus(ConvertOEM7ToGalIonBus const&) = delete;

  // Assignment Operator
  ConvertOEM7ToGalIonBus& operator= (ConvertOEM7ToGalIonBus const&) & = delete;

  // Move Constructor
  ConvertOEM7ToGalIonBus(ConvertOEM7ToGalIonBus &&) = delete;

  // Move Assignment Operator
  ConvertOEM7ToGalIonBus& operator= (ConvertOEM7ToGalIonBus &&) = delete;

  // Real-Time Model get method
  ConvertOEM7ToGalIonBus::RT_MODEL_ConvertOEM7ToGalIonB_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_ConvertOEM7ToGalIonBus_T
    *pExtU_ConvertOEM7ToGalIonBus_T)
  {
    ConvertOEM7ToGalIonBus_U = *pExtU_ConvertOEM7ToGalIonBus_T;
  }

  // Root outports get method
  const ExtY_ConvertOEM7ToGalIonBus_T &getExternalOutputs() const
  {
    return ConvertOEM7ToGalIonBus_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  ConvertOEM7ToGalIonBus();

  // Destructor
  ~ConvertOEM7ToGalIonBus();

  // private data and function members
 private:
  // External inputs
  ExtU_ConvertOEM7ToGalIonBus_T ConvertOEM7ToGalIonBus_U;

  // External outputs
  ExtY_ConvertOEM7ToGalIonBus_T ConvertOEM7ToGalIonBus_Y;

  // Real-Time Model
  RT_MODEL_ConvertOEM7ToGalIonB_T ConvertOEM7ToGalIonBus_M;
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
//  '<Root>' : 'ConvertOEM7ToGalIonBus'
//  '<S1>'   : 'ConvertOEM7ToGalIonBus/OEM7 ToGALIonoBus'

#endif                                 // RTW_HEADER_ConvertOEM7ToGalIonBus_h_

//
// File trailer for generated code.
//
// [EOF]
//
