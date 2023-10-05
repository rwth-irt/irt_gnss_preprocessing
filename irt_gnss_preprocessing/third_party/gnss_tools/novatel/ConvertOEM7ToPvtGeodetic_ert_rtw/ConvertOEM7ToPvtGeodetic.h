//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToPvtGeodetic.h
//
// Code generated for Simulink model 'ConvertOEM7ToPvtGeodetic'.
//
// Model version                  : 2.34
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Nov 30 12:03:08 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_ConvertOEM7ToPvtGeodetic_h_
#define RTW_HEADER_ConvertOEM7ToPvtGeodetic_h_
#include "rtwtypes.h"
#include "ConvertOEM7ToPvtGeodetic_types.h"

// Class declaration for model ConvertOEM7ToPvtGeodetic
class ConvertOEM7ToPvtGeodetic final
{
  // public data and function members
 public:
  // External inputs (root inport signals with default storage)
  struct ExtU_ConvertOEM7ToPvtGeodetic_T {
    OEM7_BestPos OEM7BestPosRAW;       // '<Root>/OEM7BestPosRAW'
    OEM7_BestVel OEM7BestVelRAW;       // '<Root>/OEM7BestVelRAW'
    OEM7_ClockModel OEM7ClockModelRAW; // '<Root>/OEM7ClockModelRAW'
    OEM7_DualAntennaHeading OEM7DualAntennaHeadingRAW;// '<Root>/OEM7DualAntennaHeadingRAW' 
    real_T headingOffset;              // '<Root>/headingOffset'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_ConvertOEM7ToPvtGeodetic_T {
    gnssraw_pvt_geodetic_t PvtGeodeticBus;// '<Root>/PvtGeodeticBus'
    boolean_T isSynchronizedFlag;      // '<Root>/isSynchronizedFlag'
  };

  // Copy Constructor
  ConvertOEM7ToPvtGeodetic(ConvertOEM7ToPvtGeodetic const&) = delete;

  // Assignment Operator
  ConvertOEM7ToPvtGeodetic& operator= (ConvertOEM7ToPvtGeodetic const&) & =
    delete;

  // Move Constructor
  ConvertOEM7ToPvtGeodetic(ConvertOEM7ToPvtGeodetic &&) = delete;

  // Move Assignment Operator
  ConvertOEM7ToPvtGeodetic& operator= (ConvertOEM7ToPvtGeodetic &&) = delete;

  // Root inports set method
  void setExternalInputs(const ExtU_ConvertOEM7ToPvtGeodetic_T
    *pExtU_ConvertOEM7ToPvtGeodetic_T)
  {
    ConvertOEM7ToPvtGeodetic_U = *pExtU_ConvertOEM7ToPvtGeodetic_T;
  }

  // Root outports get method
  const ExtY_ConvertOEM7ToPvtGeodetic_T &getExternalOutputs() const
  {
    return ConvertOEM7ToPvtGeodetic_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  ConvertOEM7ToPvtGeodetic();

  // Destructor
  ~ConvertOEM7ToPvtGeodetic();

  // private data and function members
 private:
  // External inputs
  ExtU_ConvertOEM7ToPvtGeodetic_T ConvertOEM7ToPvtGeodetic_U;

  // External outputs
  ExtY_ConvertOEM7ToPvtGeodetic_T ConvertOEM7ToPvtGeodetic_Y;
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
//  '<Root>' : 'ConvertOEM7ToPvtGeodetic'
//  '<S1>'   : 'ConvertOEM7ToPvtGeodetic/OEM7ToPVTGeodetic'

#endif                                // RTW_HEADER_ConvertOEM7ToPvtGeodetic_h_

//
// File trailer for generated code.
//
// [EOF]
//
