//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7RangeToMeasEpochRAW.h
//
// Code generated for Simulink model 'ConvertOEM7RangeToMeasEpochRAW'.
//
// Model version                  : 2.5
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Sat Nov 26 21:42:15 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ConvertOEM7RangeToMeasEpochRAW_h_
#define RTW_HEADER_ConvertOEM7RangeToMeasEpochRAW_h_
#include "rtwtypes.h"
#include "ConvertOEM7RangeToMeasEpochRAW_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model ConvertOEM7RangeToMeasEpochRAW
class ConvertOEM7RangeToMeasEpochRAW final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_ConvertOEM7RangeToMeasEpoch_T {
    real_T svidToUseList_data[112];
    real_T svidIdx_data[112];
    int32_T idx_data[112];
    int32_T iwork_data[112];
    int32_T tmp_data[108];
    uint16_T svid[112];
    int8_T MeasurementObsInfo[200];
    boolean_T MeasurementObsInfo_m[200];
    uint8_T SBF_signalType[112];
    int8_T SBF_ObsInfo[112];
    int8_T ii_data[112];
    boolean_T x[112];
    boolean_T b_data[112];
    boolean_T bv[40];
    real_T b_pp;
    real_T b_d;
    real_T x_c;
    int32_T tmp_size[2];
    int32_T c_d;
    int32_T d_d;
    int32_T idx;
    int32_T i;
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_ConvertOEM7RangeToMeasEp_T {
    OEM7_Range Oem7RangeBus;           // '<Root>/Oem7RangeBus'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_ConvertOEM7RangeToMeasEp_T {
    gnssraw_measurement_t MeasurementEpochBus;// '<Root>/MeasurementEpochBus'
    real_T timeOfWeek;                 // '<Root>/timeOfWeek'
    HCS_Measurement HCS_Bus;           // '<Root>/HCS_Bus'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_ConvertOEM7RangeToMe_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  ConvertOEM7RangeToMeasEpochRAW(ConvertOEM7RangeToMeasEpochRAW const&) = delete;

  // Assignment Operator
  ConvertOEM7RangeToMeasEpochRAW& operator= (ConvertOEM7RangeToMeasEpochRAW
    const&) & = delete;

  // Move Constructor
  ConvertOEM7RangeToMeasEpochRAW(ConvertOEM7RangeToMeasEpochRAW &&) = delete;

  // Move Assignment Operator
  ConvertOEM7RangeToMeasEpochRAW& operator= (ConvertOEM7RangeToMeasEpochRAW &&) =
    delete;

  // Real-Time Model get method
  ConvertOEM7RangeToMeasEpochRAW::RT_MODEL_ConvertOEM7RangeToMe_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_ConvertOEM7RangeToMeasEp_T
    *pExtU_ConvertOEM7RangeToMeasEp_T)
  {
    ConvertOEM7RangeToMeasEpochRA_U = *pExtU_ConvertOEM7RangeToMeasEp_T;
  }

  // Root outports get method
  const ExtY_ConvertOEM7RangeToMeasEp_T &getExternalOutputs() const
  {
    return ConvertOEM7RangeToMeasEpochRA_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  ConvertOEM7RangeToMeasEpochRAW();

  // Destructor
  ~ConvertOEM7RangeToMeasEpochRAW();

  // private data and function members
 private:
  // External inputs
  ExtU_ConvertOEM7RangeToMeasEp_T ConvertOEM7RangeToMeasEpochRA_U;

  // External outputs
  ExtY_ConvertOEM7RangeToMeasEp_T ConvertOEM7RangeToMeasEpochRA_Y;

  // Block signals
  B_ConvertOEM7RangeToMeasEpoch_T ConvertOEM7RangeToMeasEpochRA_B;

  // private member function(s) for subsystem '<Root>'
  void ConvertOEM7RangeT_unique_vector(const real_T a_data[], const int32_T
    *a_size, real_T b_data[], int32_T *b_size);
  void ConvertOEM7RangeToMeasEpoch_any(const boolean_T x[200], boolean_T y[40]);
  void ConvertOEM7Range_nullAssignment(real_T x_data[], int32_T *x_size, const
    int32_T idx_data[], const int32_T idx_size[2]);

  // Real-Time Model
  RT_MODEL_ConvertOEM7RangeToMe_T ConvertOEM7RangeToMeasEpochR_M;
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
//  '<Root>' : 'ConvertOEM7RangeToMeasEpochRAW'
//  '<S1>'   : 'ConvertOEM7RangeToMeasEpochRAW/OEM7RangeToMeasEpochRAW'

#endif                          // RTW_HEADER_ConvertOEM7RangeToMeasEpochRAW_h_

//
// File trailer for generated code.
//
// [EOF]
//
