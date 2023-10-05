//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ApplyDifferentialCorrectionMask.cpp
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
#include "ApplyDifferentialCorrectionMask.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <cstring>

// Function for MATLAB Function: '<S55>/Apply Differential Correction Mask1'
void GNSS_preprocessingModelClass::GNSSPreProcessingS_do_vectors_h(const
  uint16_T a_data[], const int32_T *a_size, const uint16_T b_data[], const
  int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[],
  int32_T *ia_size, int32_T ib_data[], int32_T *ib_size)
{
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T nc;
  int32_T ncmax;
  if (*a_size <= *b_size) {
    ncmax = *a_size;
  } else {
    ncmax = *b_size;
  }

  *c_size = ncmax;
  *ia_size = ncmax;
  *ib_size = ncmax;
  nc = 0;
  iafirst = 0;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= *a_size) && (iblast <= *b_size)) {
    int32_T b_ialast;
    int32_T b_iblast;
    uint16_T ak;
    uint16_T bk;
    b_ialast = ialast;
    ak = a_data[ialast - 1];
    while ((b_ialast < *a_size) && (a_data[b_ialast] == ak)) {
      b_ialast++;
    }

    ialast = b_ialast;
    b_iblast = iblast;
    bk = b_data[iblast - 1];
    while ((b_iblast < *b_size) && (b_data[b_iblast] == bk)) {
      b_iblast++;
    }

    iblast = b_iblast;
    if (ak == bk) {
      nc++;
      c_data[nc - 1] = ak;
      ia_data[nc - 1] = iafirst + 1;
      ib_data[nc - 1] = ibfirst + 1;
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      ialast = b_ialast + 1;
      iafirst = b_ialast;
    } else {
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    }
  }

  if (ncmax > 0) {
    if (nc < 1) {
      *ia_size = 0;
      *ib_size = 0;
      *c_size = 0;
    } else {
      *ia_size = nc;
      *ib_size = nc;
      *c_size = nc;
    }
  }
}

void GNSS_preprocessingModelClass::GNSSPrePro_binary_expand_op_n0q(real_T
  in1_data[], int32_T *in1_size, const GNSS_Measurement *in2, const int32_T
  in4_data[], const int32_T *in4_size, const real_T in5[40], const int32_T
  in7_data[], const int32_T *in7_size)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  *in1_size = *in7_size == 1 ? *in4_size : *in7_size;
  stride_0_0 = (*in4_size != 1);
  stride_1_0 = (*in7_size != 1);
  loop_ub = *in7_size == 1 ? *in4_size : *in7_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2->pseudorange[in4_data[i * stride_0_0] - 1] -
      in5[in7_data[i * stride_1_0] - 1];
  }
}

void GNSS_preprocessingModelClass::GNSSPreProc_binary_expand_op_n0(real_T
  in1_data[], int32_T *in1_size, const GNSS_Measurement *in2, const int32_T
  in4_data[], const int32_T *in4_size, const real_T in5[40], const int32_T
  in7_data[], const int32_T *in7_size)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  *in1_size = *in7_size == 1 ? *in4_size : *in7_size;
  stride_0_0 = (*in4_size != 1);
  stride_1_0 = (*in7_size != 1);
  loop_ub = *in7_size == 1 ? *in4_size : *in7_size;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2->carrierphase[in4_data[i * stride_0_0] - 1] -
      in5[in7_data[i * stride_1_0] - 1] / 0.19029367279836487;
  }
}

// Output and update for atomic system: '<S55>/Apply Differential Correction Mask1'
void GNSS_preprocessingModelClass::ApplyDifferentialCorrectionMask(const
  GNSS_Measurement *rtu_GpsMeasurementBus, const GNSS_Measurement_size
  *rtu_GpsMeasurementBus_DIMS1, const real_T rtu_diffPseudorangeCorrections[40],
  const uint16_T rtu_diffCorrAvailableSvid[40], const int32_T
  *rtu_diffCorrAvailableSvidS1_DIM, boolean_T rtu_enableDiffCorrection, const
  real_T rtu_rtcm_base_position[3], boolean_T *rty_MeasurementCorrected,
  B_ApplyDifferentialCorrection_T *localB, DW_ApplyDifferentialCorrectio_T
  *localDW)
{
  real_T tmp_data[40];
  int32_T iia_data[40];
  int32_T iib_data[40];
  int32_T a__1_size;
  int32_T iia_size;
  int32_T iib_size;
  int32_T tmp_size;
  uint16_T a__1_data[40];
  *rty_MeasurementCorrected = true;
  if ((*rtu_diffCorrAvailableSvidS1_DIM > 3) && rtu_enableDiffCorrection) {
    int32_T loop_ub;
    int32_T rtu_GpsMeasurementBus_DIMS1_idx;
    int32_T tmp;
    GNSSPreProcessingS_do_vectors_h(rtu_diffCorrAvailableSvid,
      rtu_diffCorrAvailableSvidS1_DIM, rtu_GpsMeasurementBus->PRN,
      &rtu_GpsMeasurementBus_DIMS1->PRN, a__1_data, &a__1_size, iia_data,
      &iia_size, iib_data, &iib_size);
    localB->GPS_measurement_Bus_masked.time_receive =
      rtu_GpsMeasurementBus->time_receive;
    localDW->SFunction_DIMS2.satellite_position[0] = iib_size;
    localDW->SFunction_DIMS2.satellite_position[1] =
      rtu_GpsMeasurementBus_DIMS1->satellite_position[1];
    rtu_GpsMeasurementBus_DIMS1_idx =
      rtu_GpsMeasurementBus_DIMS1->satellite_position[0];
    tmp = localDW->SFunction_DIMS2.satellite_position[0];
    loop_ub = rtu_GpsMeasurementBus_DIMS1->satellite_position[1];
    for (a__1_size = 0; a__1_size < loop_ub; a__1_size++) {
      for (tmp_size = 0; tmp_size < iib_size; tmp_size++) {
        localB->GPS_measurement_Bus_masked.satellite_position[tmp_size + tmp *
          a__1_size] = rtu_GpsMeasurementBus->satellite_position
          [(rtu_GpsMeasurementBus_DIMS1_idx * a__1_size + iib_data[tmp_size]) -
          1];
      }
    }

    localDW->SFunction_DIMS2.satellite_velocity[0] = iib_size;
    localDW->SFunction_DIMS2.satellite_velocity[1] =
      rtu_GpsMeasurementBus_DIMS1->satellite_velocity[1];
    rtu_GpsMeasurementBus_DIMS1_idx =
      rtu_GpsMeasurementBus_DIMS1->satellite_velocity[0];
    tmp = localDW->SFunction_DIMS2.satellite_velocity[0];
    loop_ub = rtu_GpsMeasurementBus_DIMS1->satellite_velocity[1];
    for (a__1_size = 0; a__1_size < loop_ub; a__1_size++) {
      for (tmp_size = 0; tmp_size < iib_size; tmp_size++) {
        localB->GPS_measurement_Bus_masked.satellite_velocity[tmp_size + tmp *
          a__1_size] = rtu_GpsMeasurementBus->satellite_velocity
          [(rtu_GpsMeasurementBus_DIMS1_idx * a__1_size + iib_data[tmp_size]) -
          1];
      }
    }

    localDW->SFunction_DIMS2.PRN = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.PRN[a__1_size] =
        rtu_GpsMeasurementBus->PRN[iib_data[a__1_size] - 1];
    }

    if (iib_size == iia_size) {
      tmp_size = iib_size;
      for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
        tmp_data[a__1_size] = rtu_GpsMeasurementBus->
          pseudorange[iib_data[a__1_size] - 1] -
          rtu_diffPseudorangeCorrections[iia_data[a__1_size] - 1];
      }
    } else {
      GNSSPrePro_binary_expand_op_n0q(tmp_data, &tmp_size, rtu_GpsMeasurementBus,
        iib_data, &iib_size, rtu_diffPseudorangeCorrections, iia_data, &iia_size);
    }

    localDW->SFunction_DIMS2.pseudorange = tmp_size;
    if (tmp_size - 1 >= 0) {
      std::memcpy(&localB->GPS_measurement_Bus_masked.pseudorange[0], &tmp_data
                  [0], static_cast<uint32_T>(tmp_size) * sizeof(real_T));
    }

    localDW->SFunction_DIMS2.pseudorange_raw = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.pseudorange_raw[a__1_size] =
        rtu_GpsMeasurementBus->pseudorange_raw[iib_data[a__1_size] - 1];
    }

    localDW->SFunction_DIMS2.pseudorange_satclk_corrected = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.pseudorange_satclk_corrected[a__1_size]
        = rtu_GpsMeasurementBus->pseudorange_satclk_corrected[iib_data[a__1_size]
        - 1];
    }

    localDW->SFunction_DIMS2.deltarange = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.deltarange[a__1_size] =
        rtu_GpsMeasurementBus->deltarange[iib_data[a__1_size] - 1];
    }

    localDW->SFunction_DIMS2.deltarange_raw = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.deltarange_raw[a__1_size] =
        rtu_GpsMeasurementBus->deltarange_raw[iib_data[a__1_size] - 1];
    }

    localDW->SFunction_DIMS2.deltarange_satclk_corrected = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.deltarange_satclk_corrected[a__1_size] =
        rtu_GpsMeasurementBus->deltarange_satclk_corrected[iib_data[a__1_size] -
        1];
    }

    localDW->SFunction_DIMS2.variance_pseudorange = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.variance_pseudorange[a__1_size] =
        rtu_GpsMeasurementBus->variance_pseudorange[iib_data[a__1_size] - 1];
    }

    localDW->SFunction_DIMS2.variance_pseudorange_measured = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.variance_pseudorange_measured[a__1_size]
        = rtu_GpsMeasurementBus->
        variance_pseudorange_measured[iib_data[a__1_size] - 1];
    }

    localDW->SFunction_DIMS2.variance_deltarange = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.variance_deltarange[a__1_size] =
        rtu_GpsMeasurementBus->variance_deltarange[iib_data[a__1_size] - 1];
    }

    if (iib_size == iia_size) {
      tmp_size = iib_size;
      for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
        tmp_data[a__1_size] = rtu_GpsMeasurementBus->
          carrierphase[iib_data[a__1_size] - 1] -
          rtu_diffPseudorangeCorrections[iia_data[a__1_size] - 1] /
          0.19029367279836487;
      }
    } else {
      GNSSPreProc_binary_expand_op_n0(tmp_data, &tmp_size, rtu_GpsMeasurementBus,
        iib_data, &iib_size, rtu_diffPseudorangeCorrections, iia_data, &iia_size);
    }

    localDW->SFunction_DIMS2.carrierphase = tmp_size;
    if (tmp_size - 1 >= 0) {
      std::memcpy(&localB->GPS_measurement_Bus_masked.carrierphase[0],
                  &tmp_data[0], static_cast<uint32_T>(tmp_size) * sizeof(real_T));
    }

    localDW->SFunction_DIMS2.carrierphase_raw = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.carrierphase_raw[a__1_size] =
        rtu_GpsMeasurementBus->carrierphase_raw[iib_data[a__1_size] - 1];
    }

    localDW->SFunction_DIMS2.carrierphase_satclk_corrected = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.carrierphase_satclk_corrected[a__1_size]
        = rtu_GpsMeasurementBus->
        carrierphase_satclk_corrected[iib_data[a__1_size] - 1];
    }

    localDW->SFunction_DIMS2.variance_carrierphase_measured = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->
        GPS_measurement_Bus_masked.variance_carrierphase_measured[a__1_size] =
        rtu_GpsMeasurementBus->variance_carrierphase_measured[iib_data[a__1_size]
        - 1];
    }

    localDW->SFunction_DIMS2.locktime = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.locktime[a__1_size] =
        rtu_GpsMeasurementBus->locktime[iib_data[a__1_size] - 1];
    }

    localDW->SFunction_DIMS2.CN0 = iib_size;
    for (a__1_size = 0; a__1_size < iib_size; a__1_size++) {
      localB->GPS_measurement_Bus_masked.CN0[a__1_size] =
        rtu_GpsMeasurementBus->CN0[iib_data[a__1_size] - 1];
    }

    localB->GPS_measurement_Bus_masked.base_position[0] =
      rtu_rtcm_base_position[0];
    localB->GPS_measurement_Bus_masked.base_position[1] =
      rtu_rtcm_base_position[1];
    localB->GPS_measurement_Bus_masked.base_position[2] =
      rtu_rtcm_base_position[2];
  } else {
    localDW->SFunction_DIMS2 = *rtu_GpsMeasurementBus_DIMS1;
    localB->GPS_measurement_Bus_masked = *rtu_GpsMeasurementBus;
    *rty_MeasurementCorrected = false;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
