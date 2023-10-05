//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CalculateDualfrequencyCorrectio.cpp
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
#include "CalculateDualfrequencyCorrectio.h"
#include "GNSSPreProcessingSingleAntenna.h"
#include <cstring>
#include <emmintrin.h>

// Function for MATLAB Function: '<S51>/Calculate Dualfrequency Correction with L1 and L2C'
void GNSS_preprocessingModelClass::GNSSPreProcessingS_do_vectors_e(const
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

// Output and update for atomic system: '<S51>/Calculate Dualfrequency Correction with L1 and L2C'
void GNSS_preprocessingModelClass::CalculateDualfrequencyCorrectio(const
  GNSS_Measurement *rtu_measurementBusL1, const GNSS_Measurement_size
  *rtu_measurementBusL1_DIMS1, const GNSS_Measurement *rtu_measurementBusL2C,
  const GNSS_Measurement_size *rtu_measurementBusL2C_DIMS1, boolean_T
  rtu_enableDualFrequencyCorrecti, B_CalculateDualfrequencyCorre_T *localB,
  DW_CalculateDualfrequencyCorr_T *localDW)
{
  real_T fixed_f1[150];
  real_T fixed_f2[150];
  int32_T l_data[150];
  int32_T iia_data[40];
  int32_T iib_data[40];
  int32_T c;
  int32_T i;
  int32_T loop_ub;
  int32_T vectorUB;
  uint16_T fixed_PRN[150];
  uint16_T tmp_data[40];
  int8_T idx1_data[40];
  int8_T idx2_data[40];
  uint8_T h_data[150];
  uint8_T k_data[150];
  boolean_T g_data[150];
  localB->measurementFrequencyBus.time_receive =
    rtu_measurementBusL1->time_receive;
  localDW->SFunction_DIMS2.satellite_position[0] =
    rtu_measurementBusL1_DIMS1->satellite_position[0];
  localDW->SFunction_DIMS2.satellite_position[1] =
    rtu_measurementBusL1_DIMS1->satellite_position[1];
  loop_ub = rtu_measurementBusL1_DIMS1->satellite_position[0] *
    rtu_measurementBusL1_DIMS1->satellite_position[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.satellite_position[0],
                &rtu_measurementBusL1->satellite_position[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS2.satellite_velocity[0] =
    rtu_measurementBusL1_DIMS1->satellite_velocity[0];
  localDW->SFunction_DIMS2.satellite_velocity[1] =
    rtu_measurementBusL1_DIMS1->satellite_velocity[1];
  loop_ub = rtu_measurementBusL1_DIMS1->satellite_velocity[0] *
    rtu_measurementBusL1_DIMS1->satellite_velocity[1];
  if (loop_ub - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.satellite_velocity[0],
                &rtu_measurementBusL1->satellite_velocity[0],
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }

  localDW->SFunction_DIMS2.PRN = rtu_measurementBusL1_DIMS1->PRN;
  if (rtu_measurementBusL1_DIMS1->PRN - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.PRN[0],
                &rtu_measurementBusL1->PRN[0], static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->PRN) * sizeof(uint16_T));
  }

  localDW->SFunction_DIMS2.pseudorange = rtu_measurementBusL1_DIMS1->pseudorange;
  if (rtu_measurementBusL1_DIMS1->pseudorange - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.pseudorange[0],
                &rtu_measurementBusL1->pseudorange[0], static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->pseudorange) * sizeof(real_T));
  }

  localDW->SFunction_DIMS2.pseudorange_raw =
    rtu_measurementBusL1_DIMS1->pseudorange_raw;
  if (rtu_measurementBusL1_DIMS1->pseudorange_raw - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.pseudorange_raw[0],
                &rtu_measurementBusL1->pseudorange_raw[0], static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->pseudorange_raw) * sizeof(real_T));
  }

  localDW->SFunction_DIMS2.pseudorange_satclk_corrected =
    rtu_measurementBusL1_DIMS1->pseudorange_satclk_corrected;
  if (rtu_measurementBusL1_DIMS1->pseudorange_satclk_corrected - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.pseudorange_satclk_corrected[0],
                &rtu_measurementBusL1->pseudorange_satclk_corrected[0],
                static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->pseudorange_satclk_corrected) *
                sizeof(real_T));
  }

  localDW->SFunction_DIMS2.deltarange = rtu_measurementBusL1_DIMS1->deltarange;
  if (rtu_measurementBusL1_DIMS1->deltarange - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.deltarange[0],
                &rtu_measurementBusL1->deltarange[0], static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->deltarange) * sizeof(real_T));
  }

  localDW->SFunction_DIMS2.deltarange_raw =
    rtu_measurementBusL1_DIMS1->deltarange_raw;
  if (rtu_measurementBusL1_DIMS1->deltarange_raw - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.deltarange_raw[0],
                &rtu_measurementBusL1->deltarange_raw[0], static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->deltarange_raw) * sizeof(real_T));
  }

  localDW->SFunction_DIMS2.deltarange_satclk_corrected =
    rtu_measurementBusL1_DIMS1->deltarange_satclk_corrected;
  if (rtu_measurementBusL1_DIMS1->deltarange_satclk_corrected - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.deltarange_satclk_corrected[0],
                &rtu_measurementBusL1->deltarange_satclk_corrected[0],
                static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->deltarange_satclk_corrected) *
                sizeof(real_T));
  }

  localDW->SFunction_DIMS2.variance_pseudorange =
    rtu_measurementBusL1_DIMS1->variance_pseudorange;
  if (rtu_measurementBusL1_DIMS1->variance_pseudorange - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.variance_pseudorange[0],
                &rtu_measurementBusL1->variance_pseudorange[0],
                static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->variance_pseudorange) * sizeof
                (real_T));
  }

  localDW->SFunction_DIMS2.variance_pseudorange_measured =
    rtu_measurementBusL1_DIMS1->variance_pseudorange_measured;
  if (rtu_measurementBusL1_DIMS1->variance_pseudorange_measured - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.variance_pseudorange_measured[0],
                &rtu_measurementBusL1->variance_pseudorange_measured[0],
                static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->variance_pseudorange_measured) *
                sizeof(real_T));
  }

  localDW->SFunction_DIMS2.variance_deltarange =
    rtu_measurementBusL1_DIMS1->variance_deltarange;
  if (rtu_measurementBusL1_DIMS1->variance_deltarange - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.variance_deltarange[0],
                &rtu_measurementBusL1->variance_deltarange[0],
                static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->variance_deltarange) * sizeof
                (real_T));
  }

  localDW->SFunction_DIMS2.carrierphase =
    rtu_measurementBusL1_DIMS1->carrierphase;
  if (rtu_measurementBusL1_DIMS1->carrierphase - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.carrierphase[0],
                &rtu_measurementBusL1->carrierphase[0], static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->carrierphase) * sizeof(real_T));
  }

  localDW->SFunction_DIMS2.carrierphase_raw =
    rtu_measurementBusL1_DIMS1->carrierphase_raw;
  if (rtu_measurementBusL1_DIMS1->carrierphase_raw - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.carrierphase_raw[0],
                &rtu_measurementBusL1->carrierphase_raw[0], static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->carrierphase_raw) * sizeof(real_T));
  }

  localDW->SFunction_DIMS2.carrierphase_satclk_corrected =
    rtu_measurementBusL1_DIMS1->carrierphase_satclk_corrected;
  if (rtu_measurementBusL1_DIMS1->carrierphase_satclk_corrected - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.carrierphase_satclk_corrected[0],
                &rtu_measurementBusL1->carrierphase_satclk_corrected[0],
                static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->carrierphase_satclk_corrected) *
                sizeof(real_T));
  }

  localDW->SFunction_DIMS2.variance_carrierphase_measured =
    rtu_measurementBusL1_DIMS1->variance_carrierphase_measured;
  if (rtu_measurementBusL1_DIMS1->variance_carrierphase_measured - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.variance_carrierphase_measured
                [0], &rtu_measurementBusL1->variance_carrierphase_measured[0],
                static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->variance_carrierphase_measured) *
                sizeof(real_T));
  }

  localDW->SFunction_DIMS2.locktime = rtu_measurementBusL1_DIMS1->locktime;
  if (rtu_measurementBusL1_DIMS1->locktime - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.locktime[0],
                &rtu_measurementBusL1->locktime[0], static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->locktime) * sizeof(real32_T));
  }

  localDW->SFunction_DIMS2.CN0 = rtu_measurementBusL1_DIMS1->CN0;
  if (rtu_measurementBusL1_DIMS1->CN0 - 1 >= 0) {
    std::memcpy(&localB->measurementFrequencyBus.CN0[0],
                &rtu_measurementBusL1->CN0[0], static_cast<uint32_T>
                (rtu_measurementBusL1_DIMS1->CN0) * sizeof(real_T));
  }

  localB->measurementFrequencyBus.base_position[0] =
    rtu_measurementBusL1->base_position[0];
  localB->measurementFrequencyBus.base_position[1] =
    rtu_measurementBusL1->base_position[1];
  localB->measurementFrequencyBus.base_position[2] =
    rtu_measurementBusL1->base_position[2];
  if (rtu_enableDualFrequencyCorrecti) {
    GNSSPreProcessingS_do_vectors_e(rtu_measurementBusL1->PRN,
      &rtu_measurementBusL1_DIMS1->PRN, rtu_measurementBusL2C->PRN,
      &rtu_measurementBusL2C_DIMS1->PRN, tmp_data, &i, iia_data, &vectorUB,
      iib_data, &c);
    localDW->SFunction_DIMS4 = i;
    if (i - 1 >= 0) {
      std::memcpy(&localB->SvidDualFrequencyCorrected[0], &tmp_data[0],
                  static_cast<uint32_T>(i) * sizeof(uint16_T));
    }

    if (localDW->SFunction_DIMS4 != 0) {
      std::memset(&fixed_f1[0], 0, 150U * sizeof(real_T));
      std::memset(&fixed_f2[0], 0, 150U * sizeof(real_T));
      std::memset(&fixed_PRN[0], 0, 150U * sizeof(uint16_T));
      localDW->SFunction_DIMS3 = static_cast<int8_T>
        (rtu_measurementBusL1_DIMS1->PRN);
      if (static_cast<int8_T>(rtu_measurementBusL1_DIMS1->PRN) - 1 >= 0) {
        std::memset(&localB->dualFrequencyCorrection[0], 0, static_cast<uint32_T>
                    (static_cast<int8_T>(rtu_measurementBusL1_DIMS1->PRN)) *
                    sizeof(real_T));
      }

      if (rtu_measurementBusL1_DIMS1->PRN - 1 >= 0) {
        std::memset(&idx2_data[0], 0, static_cast<uint32_T>
                    (rtu_measurementBusL1_DIMS1->PRN) * sizeof(int8_T));
      }

      if (rtu_measurementBusL1_DIMS1->PRN - 1 >= 0) {
        std::memset(&idx1_data[0], 0, static_cast<uint32_T>
                    (rtu_measurementBusL1_DIMS1->PRN) * sizeof(int8_T));
      }

      c = rtu_measurementBusL1_DIMS1->PRN;
      for (i = 0; i < c; i++) {
        loop_ub = rtu_measurementBusL2C_DIMS1->PRN;
        for (vectorUB = 0; vectorUB < loop_ub; vectorUB++) {
          if (rtu_measurementBusL1->PRN[i] == rtu_measurementBusL2C->
              PRN[vectorUB]) {
            idx1_data[i] = static_cast<int8_T>(i + 1);
            idx2_data[i] = static_cast<int8_T>(vectorUB + 1);
          }
        }
      }

      vectorUB = rtu_measurementBusL1_DIMS1->PRN;
      for (i = 0; i < vectorUB; i++) {
        int8_T idx1;
        int8_T idx2;
        idx2 = idx2_data[i];
        idx1 = idx1_data[i];
        if ((idx1 != 0) && (idx2 != 0)) {
          real_T tmp_1;
          tmp_1 = rtu_measurementBusL1->pseudorange[idx1 - 1];
          if (tmp_1 != 0.0) {
            real_T tmp_2;
            tmp_2 = rtu_measurementBusL2C->pseudorange[idx2 - 1];
            if (tmp_2 != 0.0) {
              c = rtu_measurementBusL1->PRN[i] - 1;
              fixed_PRN[c] = rtu_measurementBusL1->PRN[i];
              fixed_f1[c] = tmp_1;
              fixed_f2[c] = tmp_2;
            }
          }
        }
      }

      for (c = 0; c <= 148; c += 2) {
        __m128d tmp;
        __m128d tmp_0;
        tmp = _mm_loadu_pd(&fixed_f2[c]);
        tmp_0 = _mm_loadu_pd(&fixed_f1[c]);
        _mm_storeu_pd(&fixed_f2[c], _mm_div_pd(_mm_mul_pd(_mm_mul_pd(_mm_sub_pd
          (tmp, tmp_0), _mm_set1_pd(1.9836839845427221)), _mm_set1_pd(1.2276E+9)),
          _mm_set1_pd(1.57542E+9)));
      }

      vectorUB = rtu_measurementBusL1_DIMS1->PRN;
      for (i = 0; i < vectorUB; i++) {
        int32_T h_size_idx_0;
        int32_T rtu_measurementBusL1_0;
        boolean_T exitg1;
        boolean_T y;
        loop_ub = 0;
        for (c = 0; c < 150; c++) {
          if (fixed_PRN[c] != 0) {
            loop_ub++;
          }
        }

        h_size_idx_0 = loop_ub;
        loop_ub = 0;
        for (c = 0; c < 150; c++) {
          if (fixed_PRN[c] != 0) {
            h_data[loop_ub] = static_cast<uint8_T>(c + 1);
            loop_ub++;
          }
        }

        rtu_measurementBusL1_0 = rtu_measurementBusL1->PRN[i];
        for (c = 0; c < h_size_idx_0; c++) {
          g_data[c] = (fixed_PRN[h_data[c] - 1] == rtu_measurementBusL1_0);
        }

        loop_ub = 0;
        for (c = 0; c < 150; c++) {
          if (fixed_PRN[c] != 0) {
            k_data[loop_ub] = static_cast<uint8_T>(c + 1);
            loop_ub++;
          }
        }

        loop_ub = h_size_idx_0 - 1;
        rtu_measurementBusL1_0 = 0;
        for (c = 0; c <= loop_ub; c++) {
          if (g_data[c]) {
            rtu_measurementBusL1_0++;
          }
        }

        h_size_idx_0 = rtu_measurementBusL1_0;
        rtu_measurementBusL1_0 = 0;
        for (c = 0; c <= loop_ub; c++) {
          if (g_data[c]) {
            l_data[rtu_measurementBusL1_0] = c + 1;
            rtu_measurementBusL1_0++;
          }
        }

        y = false;
        c = 1;
        exitg1 = false;
        while ((!exitg1) && (c <= h_size_idx_0)) {
          if (fixed_PRN[k_data[l_data[c - 1] - 1] - 1] != 0) {
            y = true;
            exitg1 = true;
          } else {
            c++;
          }
        }

        if (y) {
          localB->dualFrequencyCorrection[i] = fixed_f2
            [rtu_measurementBusL1->PRN[i] - 1];
        }
      }
    } else {
      localDW->SFunction_DIMS3 = rtu_measurementBusL1_DIMS1->pseudorange;
      loop_ub = rtu_measurementBusL1_DIMS1->pseudorange;
      i = (rtu_measurementBusL1_DIMS1->pseudorange / 2) << 1;
      vectorUB = i - 2;
      for (c = 0; c <= vectorUB; c += 2) {
        __m128d tmp;
        tmp = _mm_loadu_pd(&rtu_measurementBusL1->pseudorange[c]);
        _mm_storeu_pd(&localB->dualFrequencyCorrection[c], _mm_mul_pd
                      (_mm_set1_pd(0.0), tmp));
      }

      for (c = i; c < loop_ub; c++) {
        localB->dualFrequencyCorrection[c] = 0.0 *
          rtu_measurementBusL1->pseudorange[c];
      }
    }
  } else {
    localDW->SFunction_DIMS3 = rtu_measurementBusL1_DIMS1->pseudorange;
    loop_ub = rtu_measurementBusL1_DIMS1->pseudorange;
    i = (rtu_measurementBusL1_DIMS1->pseudorange / 2) << 1;
    vectorUB = i - 2;
    for (c = 0; c <= vectorUB; c += 2) {
      __m128d tmp;
      tmp = _mm_loadu_pd(&rtu_measurementBusL1->pseudorange[c]);
      _mm_storeu_pd(&localB->dualFrequencyCorrection[c], _mm_mul_pd(_mm_set1_pd
        (0.0), tmp));
    }

    for (c = i; c < loop_ub; c++) {
      localB->dualFrequencyCorrection[c] = 0.0 *
        rtu_measurementBusL1->pseudorange[c];
    }

    localDW->SFunction_DIMS4 = 0;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
