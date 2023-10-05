//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7ToPvtGeodetic.cpp
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
#include "ConvertOEM7ToPvtGeodetic.h"
#include "rtwtypes.h"
#include "ConvertOEM7ToPvtGeodetic_private.h"
#include <cmath>
#include <cfloat>

real_T rt_remd(real_T u0, real_T u1)
{
  real_T y;
  if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
    real_T q;
    q = std::abs(u0 / u1);
    if (std::abs(q - std::floor(q + 0.5)) <= DBL_EPSILON * q) {
      y = 0.0;
    } else {
      y = std::fmod(u0, u1);
    }
  } else {
    y = std::fmod(u0, u1);
  }

  return y;
}

// Model step function
void ConvertOEM7ToPvtGeodetic::step()
{
  real_T absx;
  real_T absx_tmp;
  real_T b_x;
  real_T b_x_tmp;
  int32_T SBF_Error;
  int32_T SBF_Mode;
  real32_T tmp;
  int8_T n;
  boolean_T p;

  // Outport: '<Root>/PvtGeodeticBus' incorporates:
  //   MATLAB Function: '<Root>/OEM7ToPVTGeodetic'

  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.COG = 0.0;

  // Outport: '<Root>/isSynchronizedFlag' incorporates:
  //   MATLAB Function: '<Root>/OEM7ToPVTGeodetic'

  ConvertOEM7ToPvtGeodetic_Y.isSynchronizedFlag = false;

  // MATLAB Function: '<Root>/OEM7ToPVTGeodetic' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToPVTGeodetic'
  //   Inport: '<Root>/OEM7BestPosRAW'
  //   Inport: '<Root>/OEM7BestVelRAW'
  //   Inport: '<Root>/OEM7ClockModelRAW'
  //
  p = false;
  if ((ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.header_ms ==
       ConvertOEM7ToPvtGeodetic_U.OEM7BestVelRAW.header_ms) &&
      (ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.header_ms ==
       ConvertOEM7ToPvtGeodetic_U.OEM7ClockModelRAW.header_ms)) {
    p = true;
  }

  if (p && (ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.header_week ==
            ConvertOEM7ToPvtGeodetic_U.OEM7BestVelRAW.header_week) &&
      (ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.header_week ==
       ConvertOEM7ToPvtGeodetic_U.OEM7ClockModelRAW.header_week)) {
    // Outport: '<Root>/isSynchronizedFlag'
    ConvertOEM7ToPvtGeodetic_Y.isSynchronizedFlag = true;
  }

  switch (ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.pos_type) {
   case 0U:
    SBF_Mode = 0;
    break;

   case 16U:
    SBF_Mode = 1;
    break;

   case 17U:
    SBF_Mode = 2;
    break;

   case 18U:
    SBF_Mode = 6;
    break;

   case 32U:
    SBF_Mode = 5;
    break;

   case 34U:
    SBF_Mode = 5;
    break;

   case 48U:
    SBF_Mode = 4;
    break;

   case 49U:
    SBF_Mode = 4;
    break;

   case 50U:
    SBF_Mode = 4;
    break;

   case 69U:
    SBF_Mode = 10;
    break;

   case 78U:
    SBF_Mode = 10;
    break;

   default:
    SBF_Mode = 11;
    break;
  }

  switch (ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.sol_stat) {
   case 0U:
    SBF_Error = 0;
    break;

   case 1U:
    SBF_Error = 1;
    break;

   case 2U:
    SBF_Error = 5;
    break;

   case 4U:
    SBF_Error = 9;
    break;

   case 6U:
    SBF_Error = 5;
    break;

   case 13U:
    SBF_Error = 9;
    break;

   case 20U:
    SBF_Error = 7;
    break;

   default:
    SBF_Error = 11;
    break;
  }

  // Outport: '<Root>/PvtGeodeticBus' incorporates:
  //   MATLAB Function: '<Root>/OEM7ToPVTGeodetic'

  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Error = static_cast<uint8_T>
    (SBF_Error);

  // MATLAB Function: '<Root>/OEM7ToPVTGeodetic' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToPVTGeodetic'
  //   Inport: '<Root>/OEM7BestPosRAW'
  //   Inport: '<Root>/OEM7BestVelRAW'
  //   Inport: '<Root>/OEM7ClockModelRAW'
  //   Inport: '<Root>/OEM7DualAntennaHeadingRAW'
  //   Inport: '<Root>/headingOffset'
  //
  switch (ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.sol_stat) {
   case 0U:
    tmp = ConvertOEM7ToPvtGeodetic_U.OEM7DualAntennaHeadingRAW.heading +
      static_cast<real32_T>(ConvertOEM7ToPvtGeodetic_U.headingOffset);
    if (tmp > 179.999) {
      // Outport: '<Root>/PvtGeodeticBus'
      ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.COG =
        (ConvertOEM7ToPvtGeodetic_U.OEM7DualAntennaHeadingRAW.heading +
         ConvertOEM7ToPvtGeodetic_U.headingOffset) - 360.0;
    } else if (tmp < -180.0F) {
      // Outport: '<Root>/PvtGeodeticBus'
      ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.COG =
        (ConvertOEM7ToPvtGeodetic_U.OEM7DualAntennaHeadingRAW.heading +
         ConvertOEM7ToPvtGeodetic_U.headingOffset) + 360.0;
    } else {
      // Outport: '<Root>/PvtGeodeticBus'
      ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.COG =
        ConvertOEM7ToPvtGeodetic_U.OEM7DualAntennaHeadingRAW.heading +
        ConvertOEM7ToPvtGeodetic_U.headingOffset;
    }
    break;

   case 1U:
   case 2U:
   case 4U:
   case 6U:
   case 13U:
   case 20U:
    break;
  }

  b_x_tmp = rt_remd(ConvertOEM7ToPvtGeodetic_U.OEM7BestVelRAW.trk_gnd, 360.0);
  b_x = b_x_tmp;
  absx_tmp = std::abs(b_x_tmp);
  absx = absx_tmp;
  if (absx_tmp > 180.0) {
    if (b_x_tmp > 0.0) {
      b_x = b_x_tmp - 360.0;
    } else {
      b_x = b_x_tmp + 360.0;
    }

    absx = std::abs(b_x);
  }

  if (absx <= 45.0) {
    b_x *= 0.017453292519943295;
    n = 0;
  } else if (absx <= 135.0) {
    if (b_x > 0.0) {
      b_x = (b_x - 90.0) * 0.017453292519943295;
      n = 1;
    } else {
      b_x = (b_x + 90.0) * 0.017453292519943295;
      n = -1;
    }
  } else if (b_x > 0.0) {
    b_x = (b_x - 180.0) * 0.017453292519943295;
    n = 2;
  } else {
    b_x = (b_x + 180.0) * 0.017453292519943295;
    n = -2;
  }

  switch (n) {
   case 0:
    b_x = std::cos(b_x);
    break;

   case 1:
    b_x = -std::sin(b_x);
    break;

   case -1:
    b_x = std::sin(b_x);
    break;

   default:
    b_x = -std::cos(b_x);
    break;
  }

  absx = absx_tmp;
  if (absx_tmp > 180.0) {
    if (b_x_tmp > 0.0) {
      b_x_tmp -= 360.0;
    } else {
      b_x_tmp += 360.0;
    }

    absx = std::abs(b_x_tmp);
  }

  if (absx <= 45.0) {
    b_x_tmp *= 0.017453292519943295;
    n = 0;
  } else if (absx <= 135.0) {
    if (b_x_tmp > 0.0) {
      b_x_tmp = (b_x_tmp - 90.0) * 0.017453292519943295;
      n = 1;
    } else {
      b_x_tmp = (b_x_tmp + 90.0) * 0.017453292519943295;
      n = -1;
    }
  } else if (b_x_tmp > 0.0) {
    b_x_tmp = (b_x_tmp - 180.0) * 0.017453292519943295;
    n = 2;
  } else {
    b_x_tmp = (b_x_tmp + 180.0) * 0.017453292519943295;
    n = -2;
  }

  switch (n) {
   case 0:
    b_x_tmp = std::sin(b_x_tmp);
    break;

   case 1:
    b_x_tmp = std::cos(b_x_tmp);
    break;

   case -1:
    b_x_tmp = -std::cos(b_x_tmp);
    break;

   default:
    b_x_tmp = -std::sin(b_x_tmp);
    break;
  }

  switch (ConvertOEM7ToPvtGeodetic_U.OEM7BestVelRAW.sol_stat) {
   case 0U:
    break;

   case 1U:
   case 2U:
   case 4U:
   case 6U:
   case 13U:
   case 20U:
    // Outport: '<Root>/PvtGeodeticBus'
    ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Error = 12U;
    break;

   default:
    // Outport: '<Root>/PvtGeodeticBus'
    ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Error = 12U;
    break;
  }

  if (ConvertOEM7ToPvtGeodetic_U.OEM7ClockModelRAW.status != 0U) {
    // Outport: '<Root>/PvtGeodeticBus'
    ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Error = 13U;
  }

  if (ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.datum_id_number != 61U) {
    // Outport: '<Root>/PvtGeodeticBus'
    ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Error = 14U;
  }

  if (ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.sol_age > 10.0F) {
    // Outport: '<Root>/PvtGeodeticBus'
    ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Error = 15U;
  }

  // Outport: '<Root>/PvtGeodeticBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToPVTGeodetic'
  //   Inport: '<Root>/OEM7BestPosRAW'
  //   Inport: '<Root>/OEM7BestVelRAW'
  //   MATLAB Function: '<Root>/OEM7ToPVTGeodetic'
  //
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.TOW = static_cast<real_T>
    (ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.header_ms) * 0.001;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.WNc =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.header_week;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Mode = static_cast<uint8_T>(SBF_Mode);
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.phi =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.lat * 3.1415926535897931 / 180.0;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.phi_var =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.lat_sigma;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.lambda =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.lon * 3.1415926535897931 / 180.0;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.lambda_var =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.lon_sigma;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.h =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.hgt +
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.undulation;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.h_var =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.hgt_sigma;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Undulation =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.undulation;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Vn =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestVelRAW.hor_spd * b_x;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Ve =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestVelRAW.hor_spd * b_x_tmp;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Vu =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestVelRAW.vert_spd;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.TrkGND =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestVelRAW.trk_gnd;

  // MATLAB Function: '<Root>/OEM7ToPVTGeodetic' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToPVTGeodetic'
  //   Inport: '<Root>/OEM7DualAntennaHeadingRAW'
  //   Inport: '<Root>/headingOffset'

  tmp = ConvertOEM7ToPvtGeodetic_U.OEM7DualAntennaHeadingRAW.heading +
    static_cast<real32_T>(ConvertOEM7ToPvtGeodetic_U.headingOffset);
  if (tmp > 0.0F) {
    // Outport: '<Root>/PvtGeodeticBus'
    ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.yaw = tmp;
  } else {
    // Outport: '<Root>/PvtGeodeticBus'
    ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.yaw = tmp + 360.0F;
  }

  // Outport: '<Root>/PvtGeodeticBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToPVTGeodetic'
  //   Inport: '<Root>/OEM7BestPosRAW'
  //   Inport: '<Root>/OEM7ClockModelRAW'
  //   Inport: '<Root>/OEM7DualAntennaHeadingRAW'
  //   MATLAB Function: '<Root>/OEM7ToPVTGeodetic'
  //
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.yaw_var =
    ConvertOEM7ToPvtGeodetic_U.OEM7DualAntennaHeadingRAW.hdg_std_dev;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.pitch_roll =
    ConvertOEM7ToPvtGeodetic_U.OEM7DualAntennaHeadingRAW.pitch;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.pitch_roll_var =
    ConvertOEM7ToPvtGeodetic_U.OEM7DualAntennaHeadingRAW.ptch_std_dev;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.RxClkBias =
    ConvertOEM7ToPvtGeodetic_U.OEM7ClockModelRAW.bias;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.RxClkBiasVar =
    ConvertOEM7ToPvtGeodetic_U.OEM7ClockModelRAW.bias_variance;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.RxClkDrift =
    ConvertOEM7ToPvtGeodetic_U.OEM7ClockModelRAW.rate;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.RxClkDriftVar =
    ConvertOEM7ToPvtGeodetic_U.OEM7ClockModelRAW.rate_variance;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.TimeSystem = 0U;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.Datum = 0U;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.NrSV =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.number_svs;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.NrSVUsed =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.number_soln_svs;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.NrSVUsedL1 =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.number_soln_l1_svs;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.NrSVUsedMulti =
    ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.number_soln_multi_svs;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.WACorrInfo = 0U;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.ReferenceID = 0U;

  // MATLAB Function: '<Root>/OEM7ToPVTGeodetic' incorporates:
  //   BusCreator generated from: '<Root>/OEM7ToPVTGeodetic'
  //   Inport: '<Root>/OEM7BestPosRAW'

  tmp = std::round(ConvertOEM7ToPvtGeodetic_U.OEM7BestPosRAW.diff_age);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      // Outport: '<Root>/PvtGeodeticBus'
      ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.MeanCorrAge =
        static_cast<uint16_T>(tmp);
    } else {
      // Outport: '<Root>/PvtGeodeticBus'
      ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.MeanCorrAge = 0U;
    }
  } else {
    // Outport: '<Root>/PvtGeodeticBus'
    ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.MeanCorrAge = MAX_uint16_T;
  }

  // Outport: '<Root>/PvtGeodeticBus' incorporates:
  //   MATLAB Function: '<Root>/OEM7ToPVTGeodetic'

  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.SignalInfo = 0U;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.AlertFlag = 0U;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.NrBases = 0U;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.PPPInfo = 0U;
  ConvertOEM7ToPvtGeodetic_Y.PvtGeodeticBus.DoNotUseValues = false;
}

// Model initialize function
void ConvertOEM7ToPvtGeodetic::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void ConvertOEM7ToPvtGeodetic::terminate()
{
  // (no terminate code required)
}

// Constructor
ConvertOEM7ToPvtGeodetic::ConvertOEM7ToPvtGeodetic():
  ConvertOEM7ToPvtGeodetic_U(),
  ConvertOEM7ToPvtGeodetic_Y()
{
  // Currently there is no constructor body generated.
}

// Destructor
ConvertOEM7ToPvtGeodetic::~ConvertOEM7ToPvtGeodetic()
{
  // Currently there is no destructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
