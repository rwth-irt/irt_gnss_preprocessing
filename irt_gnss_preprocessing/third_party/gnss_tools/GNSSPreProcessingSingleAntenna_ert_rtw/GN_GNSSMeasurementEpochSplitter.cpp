//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GN_GNSSMeasurementEpochSplitter.cpp
//
// Code generated for Simulink model 'GNSSPreProcessingSingleAntenna'.
//
// Model version                  : 7.0
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Jan 26 20:34:15 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "GNSSPreProcessingSingleAntenna_types.h"
#include "rtwtypes.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <cstring>
#include "GN_GNSSMeasurementEpochSplitter.h"

// Function for MATLAB Function: '<S3>/GNSS Measurement Epoch Splitter'
int32_T GNSS_preprocessingModelClass::GNSSPrePr_combineVectorElements(const
  boolean_T x[40])
{
  int32_T y;
  y = x[0];
  for (int32_T k{0}; k < 39; k++) {
    y += x[k + 1];
  }

  return y;
}

// Output and update for atomic system: '<S3>/GNSS Measurement Epoch Splitter'
void GNSS_preprocessingModelClass::GN_GNSSMeasurementEpochSplitter(const
  gnssraw_measurement_t *rtu_MeasurementEpochBus, real_T *rty_WNc, real_T
  *rty_TOW, gnssraw_measurement_t *rty_GpsMeasurementBus, gnssraw_measurement_t *
  rty_GalMeasurementBus)
{
  int32_T i;
  int32_T partialTrueCount;
  int32_T trueCount;
  int32_T x_size_idx_1;
  int8_T ab_data[40];
  int8_T bb_data[40];
  int8_T cb_data[40];
  int8_T db_data[40];
  int8_T eb_data[40];
  int8_T fb_data[40];
  int8_T gb_data[40];
  int8_T hb_data[40];
  int8_T ib_data[40];
  int8_T jb_data[40];
  int8_T kb_data[40];
  int8_T lb_data[40];
  int8_T mb_data[40];
  int8_T nb_data[40];
  int8_T ob_data[40];
  int8_T pb_data[40];
  int8_T x_data[40];
  int8_T y_data[40];
  boolean_T t[40];
  boolean_T u[40];
  boolean_T v[40];
  boolean_T v_0[40];
  boolean_T w[40];
  boolean_T v_1;
  boolean_T w_0;
  std::memset(&rty_GpsMeasurementBus->SVID[0], 0, 40U * sizeof(uint16_T));
  std::memset(&rty_GpsMeasurementBus->Pseudorange[0], 0, 200U * sizeof(real_T));
  std::memset(&rty_GpsMeasurementBus->Pseudorange_Sigma[0], 0, 200U * sizeof
              (real_T));
  std::memset(&rty_GpsMeasurementBus->Doppler[0], 0, 200U * sizeof(real_T));
  std::memset(&rty_GpsMeasurementBus->Type[0], 255, 200U * sizeof(uint8_T));
  std::memset(&rty_GpsMeasurementBus->Carrier[0], 0, 200U * sizeof(real_T));
  std::memset(&rty_GpsMeasurementBus->Carrier_Sigma[0], 0, 200U * sizeof(real_T));
  std::memset(&rty_GpsMeasurementBus->CN0[0], 0, 200U * sizeof(real_T));
  std::memset(&rty_GpsMeasurementBus->Locktime[0], 0, 200U * sizeof(real32_T));
  std::memset(&rty_GalMeasurementBus->SVID[0], 0, 40U * sizeof(uint16_T));
  std::memset(&rty_GalMeasurementBus->Pseudorange[0], 0, 200U * sizeof(real_T));
  std::memset(&rty_GalMeasurementBus->Pseudorange_Sigma[0], 0, 200U * sizeof
              (real_T));
  std::memset(&rty_GalMeasurementBus->Doppler[0], 0, 200U * sizeof(real_T));
  std::memset(&rty_GalMeasurementBus->Type[0], 255, 200U * sizeof(uint8_T));
  std::memset(&rty_GalMeasurementBus->Carrier[0], 0, 200U * sizeof(real_T));
  std::memset(&rty_GalMeasurementBus->Carrier_Sigma[0], 0, 200U * sizeof(real_T));
  std::memset(&rty_GalMeasurementBus->CN0[0], 0, 200U * sizeof(real_T));
  std::memset(&rty_GalMeasurementBus->Locktime[0], 0, 200U * sizeof(real32_T));
  for (trueCount = 0; trueCount < 40; trueCount++) {
    v_1 = (rtu_MeasurementEpochBus->SVID[trueCount] >= 1);
    w_0 = (rtu_MeasurementEpochBus->SVID[trueCount] <= 37);
    v_0[trueCount] = (v_1 && w_0);
    v[trueCount] = v_1;
    w[trueCount] = w_0;
  }

  i = GNSSPrePr_combineVectorElements(v_0);
  rty_GpsMeasurementBus->TOW = rtu_MeasurementEpochBus->TOW;
  rty_GpsMeasurementBus->WNc = rtu_MeasurementEpochBus->WNc;
  if (i < 0) {
    i = 0;
  } else if (i > 255) {
    i = 255;
  }

  rty_GpsMeasurementBus->N = static_cast<uint8_T>(i);
  trueCount = 0;
  for (i = 0; i < 40; i++) {
    v_1 = (rtu_MeasurementEpochBus->SVID[i] >= 71);
    w_0 = (rtu_MeasurementEpochBus->SVID[i] <= 102);
    t[i] = (v_1 && w_0);
    if (v[i] && w[i]) {
      trueCount++;
    }

    v_0[i] = v_1;
    u[i] = w_0;
  }

  i = GNSSPrePr_combineVectorElements(t);
  x_size_idx_1 = trueCount;
  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      x_data[partialTrueCount] = static_cast<int8_T>(trueCount + 1);
      partialTrueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    rty_GpsMeasurementBus->SVID[trueCount] = rtu_MeasurementEpochBus->
      SVID[x_data[trueCount] - 1];
  }

  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      partialTrueCount++;
    }
  }

  x_size_idx_1 = partialTrueCount;
  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      y_data[partialTrueCount] = static_cast<int8_T>(trueCount + 1);
      partialTrueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GpsMeasurementBus->Pseudorange[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Pseudorange[(y_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      partialTrueCount++;
    }
  }

  x_size_idx_1 = partialTrueCount;
  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      ab_data[partialTrueCount] = static_cast<int8_T>(trueCount + 1);
      partialTrueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GpsMeasurementBus->Pseudorange_Sigma[partialTrueCount + 5 * trueCount]
        = rtu_MeasurementEpochBus->Pseudorange_Sigma[(ab_data[trueCount] - 1) *
        5 + partialTrueCount];
    }
  }

  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      partialTrueCount++;
    }
  }

  x_size_idx_1 = partialTrueCount;
  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      bb_data[partialTrueCount] = static_cast<int8_T>(trueCount + 1);
      partialTrueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GpsMeasurementBus->Doppler[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Doppler[(bb_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      partialTrueCount++;
    }
  }

  x_size_idx_1 = partialTrueCount;
  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      cb_data[partialTrueCount] = static_cast<int8_T>(trueCount + 1);
      partialTrueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GpsMeasurementBus->Type[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Type[(cb_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      partialTrueCount++;
    }
  }

  x_size_idx_1 = partialTrueCount;
  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      db_data[partialTrueCount] = static_cast<int8_T>(trueCount + 1);
      partialTrueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GpsMeasurementBus->Carrier[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Carrier[(db_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      partialTrueCount++;
    }
  }

  x_size_idx_1 = partialTrueCount;
  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      eb_data[partialTrueCount] = static_cast<int8_T>(trueCount + 1);
      partialTrueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GpsMeasurementBus->Carrier_Sigma[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Carrier_Sigma[(eb_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      partialTrueCount++;
    }
  }

  x_size_idx_1 = partialTrueCount;
  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      fb_data[partialTrueCount] = static_cast<int8_T>(trueCount + 1);
      partialTrueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GpsMeasurementBus->CN0[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->CN0[(fb_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      partialTrueCount++;
    }
  }

  x_size_idx_1 = partialTrueCount;
  partialTrueCount = 0;
  for (trueCount = 0; trueCount < 40; trueCount++) {
    if (v[trueCount] && w[trueCount]) {
      gb_data[partialTrueCount] = static_cast<int8_T>(trueCount + 1);
      partialTrueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GpsMeasurementBus->Locktime[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Locktime[(gb_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  rty_GalMeasurementBus->TOW = rtu_MeasurementEpochBus->TOW;
  rty_GalMeasurementBus->WNc = rtu_MeasurementEpochBus->WNc;
  if (i < 0) {
    i = 0;
  } else if (i > 255) {
    i = 255;
  }

  rty_GalMeasurementBus->N = static_cast<uint8_T>(i);
  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      trueCount++;
    }
  }

  partialTrueCount = trueCount;
  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      hb_data[trueCount] = static_cast<int8_T>(i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < partialTrueCount; trueCount++) {
    rty_GalMeasurementBus->SVID[trueCount] = rtu_MeasurementEpochBus->
      SVID[hb_data[trueCount] - 1];
  }

  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      trueCount++;
    }
  }

  x_size_idx_1 = trueCount;
  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      ib_data[trueCount] = static_cast<int8_T>(i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GalMeasurementBus->Pseudorange[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Pseudorange[(ib_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      trueCount++;
    }
  }

  x_size_idx_1 = trueCount;
  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      jb_data[trueCount] = static_cast<int8_T>(i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GalMeasurementBus->Pseudorange_Sigma[partialTrueCount + 5 * trueCount]
        = rtu_MeasurementEpochBus->Pseudorange_Sigma[(jb_data[trueCount] - 1) *
        5 + partialTrueCount];
    }
  }

  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      trueCount++;
    }
  }

  x_size_idx_1 = trueCount;
  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      kb_data[trueCount] = static_cast<int8_T>(i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GalMeasurementBus->Doppler[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Doppler[(kb_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      trueCount++;
    }
  }

  x_size_idx_1 = trueCount;
  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      lb_data[trueCount] = static_cast<int8_T>(i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GalMeasurementBus->Type[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Type[(lb_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      trueCount++;
    }
  }

  x_size_idx_1 = trueCount;
  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      mb_data[trueCount] = static_cast<int8_T>(i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GalMeasurementBus->Carrier[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Carrier[(mb_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      trueCount++;
    }
  }

  x_size_idx_1 = trueCount;
  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      nb_data[trueCount] = static_cast<int8_T>(i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GalMeasurementBus->Carrier_Sigma[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Carrier_Sigma[(nb_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      trueCount++;
    }
  }

  x_size_idx_1 = trueCount;
  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      ob_data[trueCount] = static_cast<int8_T>(i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GalMeasurementBus->CN0[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->CN0[(ob_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      trueCount++;
    }
  }

  x_size_idx_1 = trueCount;
  trueCount = 0;
  for (i = 0; i < 40; i++) {
    if (v_0[i] && u[i]) {
      pb_data[trueCount] = static_cast<int8_T>(i + 1);
      trueCount++;
    }
  }

  for (trueCount = 0; trueCount < x_size_idx_1; trueCount++) {
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      rty_GalMeasurementBus->Locktime[partialTrueCount + 5 * trueCount] =
        rtu_MeasurementEpochBus->Locktime[(pb_data[trueCount] - 1) * 5 +
        partialTrueCount];
    }
  }

  *rty_WNc = rtu_MeasurementEpochBus->WNc;
  *rty_TOW = rtu_MeasurementEpochBus->TOW;
}

//
// File trailer for generated code.
//
// [EOF]
//
