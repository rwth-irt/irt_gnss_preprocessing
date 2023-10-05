//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ConvertOEM7RangeToMeasEpochRAW.cpp
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
#include "ConvertOEM7RangeToMeasEpochRAW.h"
#include "rtwtypes.h"
#include <cstring>
#include <emmintrin.h>
#include <cmath>

// Function for MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'
void ConvertOEM7RangeToMeasEpochRAW::ConvertOEM7RangeT_unique_vector(const
  real_T a_data[], const int32_T *a_size, real_T b_data[], int32_T *b_size)
{
  int32_T i;
  int32_T khi;
  if (static_cast<int8_T>(*a_size) - 1 >= 0) {
    std::memset(&ConvertOEM7RangeToMeasEpochRA_B.idx_data[0], 0, static_cast<
                int8_T>(*a_size) * sizeof(int32_T));
  }

  if (*a_size != 0) {
    for (khi = 1; khi <= (*a_size + 1) - 2; khi += 2) {
      if (a_data[khi - 1] <= a_data[khi]) {
        ConvertOEM7RangeToMeasEpochRA_B.idx_data[khi - 1] = khi;
        ConvertOEM7RangeToMeasEpochRA_B.idx_data[khi] = khi + 1;
      } else {
        ConvertOEM7RangeToMeasEpochRA_B.idx_data[khi - 1] = khi + 1;
        ConvertOEM7RangeToMeasEpochRA_B.idx_data[khi] = khi;
      }
    }

    if ((*a_size & 1U) != 0U) {
      ConvertOEM7RangeToMeasEpochRA_B.idx_data[*a_size - 1] = *a_size;
    }

    i = 2;
    while (i < (*a_size + 1) - 1) {
      int32_T i2;
      int32_T j;
      i2 = i << 1;
      j = 1;
      khi = i + 1;
      while (khi < *a_size + 1) {
        int32_T c_k;
        int32_T kEnd;
        int32_T p;
        int32_T q;
        int32_T qEnd;
        p = j;
        q = khi;
        qEnd = j + i2;
        if (qEnd > *a_size + 1) {
          qEnd = *a_size + 1;
        }

        c_k = 0;
        kEnd = qEnd - j;
        while (c_k + 1 <= kEnd) {
          int32_T khi_tmp;
          int32_T tmp;
          khi_tmp = ConvertOEM7RangeToMeasEpochRA_B.idx_data[q - 1];
          tmp = ConvertOEM7RangeToMeasEpochRA_B.idx_data[p - 1];
          if (a_data[tmp - 1] <= a_data[khi_tmp - 1]) {
            ConvertOEM7RangeToMeasEpochRA_B.iwork_data[c_k] = tmp;
            p++;
            if (p == khi) {
              while (q < qEnd) {
                c_k++;
                ConvertOEM7RangeToMeasEpochRA_B.iwork_data[c_k] =
                  ConvertOEM7RangeToMeasEpochRA_B.idx_data[q - 1];
                q++;
              }
            }
          } else {
            ConvertOEM7RangeToMeasEpochRA_B.iwork_data[c_k] = khi_tmp;
            q++;
            if (q == qEnd) {
              while (p < khi) {
                c_k++;
                ConvertOEM7RangeToMeasEpochRA_B.iwork_data[c_k] =
                  ConvertOEM7RangeToMeasEpochRA_B.idx_data[p - 1];
                p++;
              }
            }
          }

          c_k++;
        }

        for (khi = 0; khi < kEnd; khi++) {
          ConvertOEM7RangeToMeasEpochRA_B.idx_data[(j + khi) - 1] =
            ConvertOEM7RangeToMeasEpochRA_B.iwork_data[khi];
        }

        j = qEnd;
        khi = qEnd + i;
      }

      i = i2;
    }
  }

  for (khi = 0; khi < *a_size; khi++) {
    b_data[khi] = a_data[ConvertOEM7RangeToMeasEpochRA_B.idx_data[khi] - 1];
  }

  khi = 0;
  i = 1;
  while (i <= *a_size) {
    ConvertOEM7RangeToMeasEpochRA_B.x_c = b_data[i - 1];
    do {
      i++;
    } while (!((i > *a_size) || (b_data[i - 1] !=
               ConvertOEM7RangeToMeasEpochRA_B.x_c)));

    khi++;
    b_data[khi - 1] = ConvertOEM7RangeToMeasEpochRA_B.x_c;
  }

  if (khi < 1) {
    *b_size = 0;
  } else {
    *b_size = khi;
  }
}

// Function for MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'
void ConvertOEM7RangeToMeasEpochRAW::ConvertOEM7RangeToMeasEpoch_any(const
  boolean_T x[200], boolean_T y[40])
{
  int32_T i2;
  i2 = 1;
  for (int32_T i{0}; i < 40; i++) {
    int32_T a;
    int32_T ix;
    boolean_T exitg1;
    y[i] = false;
    a = i2 + 4;
    ix = i2;
    i2 += 5;
    exitg1 = false;
    while ((!exitg1) && (ix <= a)) {
      if (x[ix - 1]) {
        y[i] = true;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'
void ConvertOEM7RangeToMeasEpochRAW::ConvertOEM7Range_nullAssignment(real_T
  x_data[], int32_T *x_size, const int32_T idx_data[], const int32_T idx_size[2])
{
  int32_T k0;
  int32_T nxout;
  if (*x_size - 1 >= 0) {
    std::memset(&ConvertOEM7RangeToMeasEpochRA_B.b_data[0], 0, ((*x_size - 1) +
      1) * sizeof(boolean_T));
  }

  for (nxout = 0; nxout < idx_size[1]; nxout++) {
    ConvertOEM7RangeToMeasEpochRA_B.b_data[idx_data[nxout] - 1] = true;
  }

  nxout = 0;
  for (k0 = 0; k0 < *x_size; k0++) {
    nxout += ConvertOEM7RangeToMeasEpochRA_B.b_data[k0];
  }

  nxout = *x_size - nxout;
  k0 = -1;
  for (int32_T k{0}; k < *x_size; k++) {
    if ((k + 1 > *x_size) || (!ConvertOEM7RangeToMeasEpochRA_B.b_data[k])) {
      k0++;
      x_data[k0] = x_data[k];
    }
  }

  if (nxout < 1) {
    *x_size = 0;
  } else {
    *x_size = nxout;
  }
}

// Model step function
void ConvertOEM7RangeToMeasEpochRAW::step()
{
  static const int32_T offsets[4]{ 0, 1, 2, 3 };

  int32_T svidIdx_size;
  int32_T svidToUseList_size;

  // MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'
  std::memset(&ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.SVID[0], 0,
              40U * sizeof(uint16_T));

  // Outport: '<Root>/MeasurementEpochBus' incorporates:
  //   MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'

  std::memset(&ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Pseudorange[0],
              0, 200U * sizeof(real_T));
  std::memset
    (&ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Pseudorange_Sigma[0],
     0, 200U * sizeof(real_T));
  std::memset(&ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Doppler[0], 0,
              200U * sizeof(real_T));
  std::memset(&ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Type[0], 255,
              200U * sizeof(uint8_T));
  std::memset(&ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Carrier[0], 0,
              200U * sizeof(real_T));
  std::memset(&ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.CN0[0], 0,
              200U * sizeof(real_T));
  std::memset(&ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Locktime[0],
              0, 200U * sizeof(real32_T));

  // MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'
  std::memset(&ConvertOEM7RangeToMeasEpochRA_B.MeasurementObsInfo[0], 0, 200U *
              sizeof(int8_T));

  // Outport: '<Root>/MeasurementEpochBus' incorporates:
  //   MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'

  std::memset
    (&ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Carrier_Sigma[0], 0,
     200U * sizeof(real_T));

  // MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW' incorporates:
  //   BusCreator generated from: '<Root>/OEM7RangeToMeasEpochRAW'
  //   Inport: '<Root>/Oem7RangeBus'
  //   Outport: '<Root>/MeasurementEpochBus'

  std::memset(&ConvertOEM7RangeToMeasEpochRA_B.svid[0], 0, 112U * sizeof
              (uint16_T));
  std::memset(&ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[0], 255, 112U *
              sizeof(uint8_T));
  std::memset(&ConvertOEM7RangeToMeasEpochRA_B.SBF_ObsInfo[0], 0, 112U * sizeof
              (int8_T));
  ConvertOEM7RangeToMeasEpochRA_B.i = 0;
  while (ConvertOEM7RangeToMeasEpochRA_B.i <= static_cast<int32_T>
         (ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.number_obs) - 1) {
    uint32_T OEM7_ChannelTrackingStatus_tmp;
    OEM7_ChannelTrackingStatus_tmp =
      ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.ch_tr_status[ConvertOEM7RangeToMeasEpochRA_B.i];
    ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
    if ((OEM7_ChannelTrackingStatus_tmp & 65536U) != 0U) {
      ConvertOEM7RangeToMeasEpochRA_B.idx = 1;
    }

    if ((OEM7_ChannelTrackingStatus_tmp & 131072U) != 0U) {
      ConvertOEM7RangeToMeasEpochRA_B.idx += 2;
    }

    if ((OEM7_ChannelTrackingStatus_tmp & 262144U) != 0U) {
      ConvertOEM7RangeToMeasEpochRA_B.idx += 4;
    }

    ConvertOEM7RangeToMeasEpochRA_B.b_pp = 1.0;
    ConvertOEM7RangeToMeasEpochRA_B.b_d = 0.0;
    for (ConvertOEM7RangeToMeasEpochRA_B.c_d = 0;
         ConvertOEM7RangeToMeasEpochRA_B.c_d < 5;
         ConvertOEM7RangeToMeasEpochRA_B.c_d++) {
      if ((1U << (ConvertOEM7RangeToMeasEpochRA_B.c_d + 21) &
           OEM7_ChannelTrackingStatus_tmp) != 0U) {
        ConvertOEM7RangeToMeasEpochRA_B.b_d +=
          ConvertOEM7RangeToMeasEpochRA_B.b_pp;
      }

      ConvertOEM7RangeToMeasEpochRA_B.b_pp *= 2.0;
    }

    ConvertOEM7RangeToMeasEpochRA_B.c_d = 0;
    if ((OEM7_ChannelTrackingStatus_tmp & 268435456U) != 0U) {
      ConvertOEM7RangeToMeasEpochRA_B.c_d = 1;
    }

    ConvertOEM7RangeToMeasEpochRA_B.d_d = 0;
    if ((OEM7_ChannelTrackingStatus_tmp & 2048U) != 0U) {
      ConvertOEM7RangeToMeasEpochRA_B.d_d = 1;
    }

    switch (static_cast<uint32_T>(ConvertOEM7RangeToMeasEpochRA_B.idx)) {
     case 0U:
      if (ConvertOEM7RangeToMeasEpochRA_B.b_d < 4.294967296E+9) {
        OEM7_ChannelTrackingStatus_tmp = static_cast<uint32_T>
          (ConvertOEM7RangeToMeasEpochRA_B.b_d);
      } else {
        OEM7_ChannelTrackingStatus_tmp = MAX_uint32_T;
      }

      switch (OEM7_ChannelTrackingStatus_tmp) {
       case 0U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = 0U;
        break;

       case 5U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = MAX_uint8_T;
        break;

       case 9U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = MAX_uint8_T;
        break;

       case 14U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = 4U;
        break;

       case 16U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = MAX_uint8_T;
        break;

       case 17U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = 3U;
        break;

       default:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = MAX_uint8_T;
        break;
      }
      break;

     case 3U:
      if (ConvertOEM7RangeToMeasEpochRA_B.b_d < 4.294967296E+9) {
        OEM7_ChannelTrackingStatus_tmp = static_cast<uint32_T>
          (ConvertOEM7RangeToMeasEpochRA_B.b_d);
      } else {
        OEM7_ChannelTrackingStatus_tmp = MAX_uint32_T;
      }

      switch (OEM7_ChannelTrackingStatus_tmp) {
       case 2U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = 17U;
        break;

       case 6U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = MAX_uint8_T;
        break;

       case 7U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = MAX_uint8_T;
        break;

       case 12U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = 20U;
        break;

       case 17U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = 21U;
        break;

       case 20U:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = 22U;
        break;

       default:
        ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
          = MAX_uint8_T;
        break;
      }
      break;

     default:
      ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i]
        = MAX_uint8_T;
      break;
    }

    ConvertOEM7RangeToMeasEpochRA_B.SBF_ObsInfo[ConvertOEM7RangeToMeasEpochRA_B.i]
      = static_cast<int8_T>((static_cast<uint32_T>
      (ConvertOEM7RangeToMeasEpochRA_B.c_d) != 0U) && (static_cast<uint32_T>
      (ConvertOEM7RangeToMeasEpochRA_B.d_d) != 0U));
    ConvertOEM7RangeToMeasEpochRA_B.idx =
      ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[ConvertOEM7RangeToMeasEpochRA_B.i];
    if (ConvertOEM7RangeToMeasEpochRA_B.idx <= 4) {
      ConvertOEM7RangeToMeasEpochRA_B.svid[ConvertOEM7RangeToMeasEpochRA_B.i] =
        ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.prn[ConvertOEM7RangeToMeasEpochRA_B.i];
    }

    if ((ConvertOEM7RangeToMeasEpochRA_B.idx >= 17) &&
        (ConvertOEM7RangeToMeasEpochRA_B.idx <= 22)) {
      OEM7_ChannelTrackingStatus_tmp =
        ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.prn[ConvertOEM7RangeToMeasEpochRA_B.i]
        + 70U;
      if (OEM7_ChannelTrackingStatus_tmp > 65535U) {
        OEM7_ChannelTrackingStatus_tmp = 65535U;
      }

      ConvertOEM7RangeToMeasEpochRA_B.svid[ConvertOEM7RangeToMeasEpochRA_B.i] =
        static_cast<uint16_T>(OEM7_ChannelTrackingStatus_tmp);
    }

    ConvertOEM7RangeToMeasEpochRA_B.i++;
  }

  ConvertOEM7RangeToMeasEpochRA_B.i = 0;
  for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
       ConvertOEM7RangeToMeasEpochRA_B.idx < 112;
       ConvertOEM7RangeToMeasEpochRA_B.idx++) {
    if (ConvertOEM7RangeToMeasEpochRA_B.svid[ConvertOEM7RangeToMeasEpochRA_B.idx]
        != 0) {
      ConvertOEM7RangeToMeasEpochRA_B.i++;
    }
  }

  ConvertOEM7RangeToMeasEpochRA_B.d_d = ConvertOEM7RangeToMeasEpochRA_B.i;
  ConvertOEM7RangeToMeasEpochRA_B.i = 0;
  for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
       ConvertOEM7RangeToMeasEpochRA_B.idx < 112;
       ConvertOEM7RangeToMeasEpochRA_B.idx++) {
    if (ConvertOEM7RangeToMeasEpochRA_B.svid[ConvertOEM7RangeToMeasEpochRA_B.idx]
        != 0) {
      ConvertOEM7RangeToMeasEpochRA_B.ii_data[ConvertOEM7RangeToMeasEpochRA_B.i]
        = static_cast<int8_T>(ConvertOEM7RangeToMeasEpochRA_B.idx + 1);
      ConvertOEM7RangeToMeasEpochRA_B.i++;
    }
  }

  svidIdx_size = ConvertOEM7RangeToMeasEpochRA_B.d_d;
  for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
       ConvertOEM7RangeToMeasEpochRA_B.idx < ConvertOEM7RangeToMeasEpochRA_B.d_d;
       ConvertOEM7RangeToMeasEpochRA_B.idx++) {
    ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data[ConvertOEM7RangeToMeasEpochRA_B.idx]
      =
      ConvertOEM7RangeToMeasEpochRA_B.svid[ConvertOEM7RangeToMeasEpochRA_B.ii_data
      [ConvertOEM7RangeToMeasEpochRA_B.idx] - 1];
  }

  ConvertOEM7RangeT_unique_vector(ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data,
    &svidIdx_size, ConvertOEM7RangeToMeasEpochRA_B.svidToUseList_data,
    &svidToUseList_size);
  ConvertOEM7RangeToMeasEpochRA_B.i = 0;
  while (ConvertOEM7RangeToMeasEpochRA_B.i <= svidToUseList_size - 1) {
    int32_T vectorUB;
    boolean_T exitg1;
    ConvertOEM7RangeToMeasEpochRA_B.b_pp =
      ConvertOEM7RangeToMeasEpochRA_B.svidToUseList_data[ConvertOEM7RangeToMeasEpochRA_B.i];
    for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
         ConvertOEM7RangeToMeasEpochRA_B.idx < 112;
         ConvertOEM7RangeToMeasEpochRA_B.idx++) {
      ConvertOEM7RangeToMeasEpochRA_B.x[ConvertOEM7RangeToMeasEpochRA_B.idx] =
        (ConvertOEM7RangeToMeasEpochRA_B.svid[ConvertOEM7RangeToMeasEpochRA_B.idx]
         == ConvertOEM7RangeToMeasEpochRA_B.b_pp);
    }

    ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
    ConvertOEM7RangeToMeasEpochRA_B.c_d = 0;
    exitg1 = false;
    while ((!exitg1) && (ConvertOEM7RangeToMeasEpochRA_B.c_d < 112)) {
      if (ConvertOEM7RangeToMeasEpochRA_B.x[ConvertOEM7RangeToMeasEpochRA_B.c_d])
      {
        ConvertOEM7RangeToMeasEpochRA_B.idx++;
        ConvertOEM7RangeToMeasEpochRA_B.ii_data[ConvertOEM7RangeToMeasEpochRA_B.idx
          - 1] = static_cast<int8_T>(ConvertOEM7RangeToMeasEpochRA_B.c_d + 1);
        if (ConvertOEM7RangeToMeasEpochRA_B.idx >= 112) {
          exitg1 = true;
        } else {
          ConvertOEM7RangeToMeasEpochRA_B.c_d++;
        }
      } else {
        ConvertOEM7RangeToMeasEpochRA_B.c_d++;
      }
    }

    if (ConvertOEM7RangeToMeasEpochRA_B.idx < 1) {
      ConvertOEM7RangeToMeasEpochRA_B.d_d = 0;
    } else {
      ConvertOEM7RangeToMeasEpochRA_B.d_d = ConvertOEM7RangeToMeasEpochRA_B.idx;
    }

    svidIdx_size = ConvertOEM7RangeToMeasEpochRA_B.d_d;
    for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
         ConvertOEM7RangeToMeasEpochRA_B.idx <
         ConvertOEM7RangeToMeasEpochRA_B.d_d;
         ConvertOEM7RangeToMeasEpochRA_B.idx++) {
      ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data[ConvertOEM7RangeToMeasEpochRA_B.idx]
        =
        ConvertOEM7RangeToMeasEpochRA_B.ii_data[ConvertOEM7RangeToMeasEpochRA_B.idx];
    }

    ConvertOEM7RangeToMeasEpochRA_B.c_d = ConvertOEM7RangeToMeasEpochRA_B.d_d -
      5;
    ConvertOEM7RangeToMeasEpochRA_B.tmp_size[0] = 1;
    ConvertOEM7RangeToMeasEpochRA_B.tmp_size[1] =
      ConvertOEM7RangeToMeasEpochRA_B.d_d - 4;
    ConvertOEM7RangeToMeasEpochRA_B.d_d = ((ConvertOEM7RangeToMeasEpochRA_B.d_d
      - 4) / 4) << 2;
    vectorUB = ConvertOEM7RangeToMeasEpochRA_B.d_d - 4;
    for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
         ConvertOEM7RangeToMeasEpochRA_B.idx <= vectorUB;
         ConvertOEM7RangeToMeasEpochRA_B.idx += 4) {
      _mm_storeu_si128((__m128i *)
                       &ConvertOEM7RangeToMeasEpochRA_B.tmp_data[ConvertOEM7RangeToMeasEpochRA_B.idx],
                       _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
        (ConvertOEM7RangeToMeasEpochRA_B.idx), _mm_loadu_si128((const __m128i *)
        &offsets[0])), _mm_set1_epi32(5)));
    }

    for (ConvertOEM7RangeToMeasEpochRA_B.idx =
         ConvertOEM7RangeToMeasEpochRA_B.d_d;
         ConvertOEM7RangeToMeasEpochRA_B.idx <=
         ConvertOEM7RangeToMeasEpochRA_B.c_d;
         ConvertOEM7RangeToMeasEpochRA_B.idx++) {
      ConvertOEM7RangeToMeasEpochRA_B.tmp_data[ConvertOEM7RangeToMeasEpochRA_B.idx]
        = ConvertOEM7RangeToMeasEpochRA_B.idx + 5;
    }

    ConvertOEM7Range_nullAssignment(ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data,
      &svidIdx_size, ConvertOEM7RangeToMeasEpochRA_B.tmp_data,
      ConvertOEM7RangeToMeasEpochRA_B.tmp_size);
    if (svidIdx_size != 0) {
      ConvertOEM7RangeToMeasEpochRA_B.b_pp = std::round
        (ConvertOEM7RangeToMeasEpochRA_B.svidToUseList_data[ConvertOEM7RangeToMeasEpochRA_B.i]);
      if (ConvertOEM7RangeToMeasEpochRA_B.b_pp < 65536.0) {
        if (ConvertOEM7RangeToMeasEpochRA_B.b_pp >= 0.0) {
          ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.SVID[ConvertOEM7RangeToMeasEpochRA_B.i]
            = static_cast<uint16_T>(ConvertOEM7RangeToMeasEpochRA_B.b_pp);
        } else {
          ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.SVID[ConvertOEM7RangeToMeasEpochRA_B.i]
            = 0U;
        }
      } else {
        ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.SVID[ConvertOEM7RangeToMeasEpochRA_B.i]
          = MAX_uint16_T;
      }

      ConvertOEM7RangeToMeasEpochRA_B.c_d = svidIdx_size;
      for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
           ConvertOEM7RangeToMeasEpochRA_B.idx <
           ConvertOEM7RangeToMeasEpochRA_B.c_d;
           ConvertOEM7RangeToMeasEpochRA_B.idx++) {
        ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Pseudorange[ConvertOEM7RangeToMeasEpochRA_B.idx
          + 5 * ConvertOEM7RangeToMeasEpochRA_B.i] =
          ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.psr[static_cast<int32_T>
          (ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data[ConvertOEM7RangeToMeasEpochRA_B.idx])
          - 1];
      }

      ConvertOEM7RangeToMeasEpochRA_B.c_d = svidIdx_size;
      for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
           ConvertOEM7RangeToMeasEpochRA_B.idx <
           ConvertOEM7RangeToMeasEpochRA_B.c_d;
           ConvertOEM7RangeToMeasEpochRA_B.idx++) {
        ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Pseudorange_Sigma[ConvertOEM7RangeToMeasEpochRA_B.idx
          + 5 * ConvertOEM7RangeToMeasEpochRA_B.i] =
          ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.psr_sigma
          [static_cast<int32_T>
          (ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data[ConvertOEM7RangeToMeasEpochRA_B.idx])
          - 1];
      }

      ConvertOEM7RangeToMeasEpochRA_B.c_d = svidIdx_size;
      for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
           ConvertOEM7RangeToMeasEpochRA_B.idx <
           ConvertOEM7RangeToMeasEpochRA_B.c_d;
           ConvertOEM7RangeToMeasEpochRA_B.idx++) {
        ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Doppler[ConvertOEM7RangeToMeasEpochRA_B.idx
          + 5 * ConvertOEM7RangeToMeasEpochRA_B.i] =
          ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.dopp[static_cast<int32_T>
          (ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data[ConvertOEM7RangeToMeasEpochRA_B.idx])
          - 1];
      }

      ConvertOEM7RangeToMeasEpochRA_B.c_d = svidIdx_size;
      for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
           ConvertOEM7RangeToMeasEpochRA_B.idx <
           ConvertOEM7RangeToMeasEpochRA_B.c_d;
           ConvertOEM7RangeToMeasEpochRA_B.idx++) {
        ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Type[ConvertOEM7RangeToMeasEpochRA_B.idx
          + 5 * ConvertOEM7RangeToMeasEpochRA_B.i] =
          ConvertOEM7RangeToMeasEpochRA_B.SBF_signalType[static_cast<int32_T>
          (ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data[ConvertOEM7RangeToMeasEpochRA_B.idx])
          - 1];
      }

      ConvertOEM7RangeToMeasEpochRA_B.c_d = svidIdx_size;
      for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
           ConvertOEM7RangeToMeasEpochRA_B.idx <
           ConvertOEM7RangeToMeasEpochRA_B.c_d;
           ConvertOEM7RangeToMeasEpochRA_B.idx++) {
        ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Carrier[ConvertOEM7RangeToMeasEpochRA_B.idx
          + 5 * ConvertOEM7RangeToMeasEpochRA_B.i] =
          -ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.adr[static_cast<int32_T>
          (ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data[ConvertOEM7RangeToMeasEpochRA_B.idx])
          - 1];
      }

      ConvertOEM7RangeToMeasEpochRA_B.c_d = svidIdx_size;
      for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
           ConvertOEM7RangeToMeasEpochRA_B.idx <
           ConvertOEM7RangeToMeasEpochRA_B.c_d;
           ConvertOEM7RangeToMeasEpochRA_B.idx++) {
        ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Carrier_Sigma[ConvertOEM7RangeToMeasEpochRA_B.idx
          + 5 * ConvertOEM7RangeToMeasEpochRA_B.i] =
          ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.adr_sigma
          [static_cast<int32_T>
          (ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data[ConvertOEM7RangeToMeasEpochRA_B.idx])
          - 1];
      }

      ConvertOEM7RangeToMeasEpochRA_B.c_d = svidIdx_size;
      for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
           ConvertOEM7RangeToMeasEpochRA_B.idx <
           ConvertOEM7RangeToMeasEpochRA_B.c_d;
           ConvertOEM7RangeToMeasEpochRA_B.idx++) {
        ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.CN0[ConvertOEM7RangeToMeasEpochRA_B.idx
          + 5 * ConvertOEM7RangeToMeasEpochRA_B.i] =
          ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.cn0[static_cast<int32_T>
          (ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data[ConvertOEM7RangeToMeasEpochRA_B.idx])
          - 1];
      }

      ConvertOEM7RangeToMeasEpochRA_B.c_d = svidIdx_size;
      for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
           ConvertOEM7RangeToMeasEpochRA_B.idx <
           ConvertOEM7RangeToMeasEpochRA_B.c_d;
           ConvertOEM7RangeToMeasEpochRA_B.idx++) {
        ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.Locktime[ConvertOEM7RangeToMeasEpochRA_B.idx
          + 5 * ConvertOEM7RangeToMeasEpochRA_B.i] =
          ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.locktime
          [static_cast<int32_T>
          (ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data[ConvertOEM7RangeToMeasEpochRA_B.idx])
          - 1];
      }

      ConvertOEM7RangeToMeasEpochRA_B.c_d = svidIdx_size;
      for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
           ConvertOEM7RangeToMeasEpochRA_B.idx <
           ConvertOEM7RangeToMeasEpochRA_B.c_d;
           ConvertOEM7RangeToMeasEpochRA_B.idx++) {
        ConvertOEM7RangeToMeasEpochRA_B.MeasurementObsInfo[ConvertOEM7RangeToMeasEpochRA_B.idx
          + 5 * ConvertOEM7RangeToMeasEpochRA_B.i] =
          ConvertOEM7RangeToMeasEpochRA_B.SBF_ObsInfo[static_cast<int32_T>
          (ConvertOEM7RangeToMeasEpochRA_B.svidIdx_data[ConvertOEM7RangeToMeasEpochRA_B.idx])
          - 1];
      }
    }

    ConvertOEM7RangeToMeasEpochRA_B.i++;
  }

  ConvertOEM7RangeToMeasEpochRA_Y.timeOfWeek = static_cast<real_T>
    (ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.header_ms) * 0.001;

  // Outport: '<Root>/MeasurementEpochBus' incorporates:
  //   BusCreator generated from: '<Root>/OEM7RangeToMeasEpochRAW'
  //   Inport: '<Root>/Oem7RangeBus'
  //   MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'

  ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.TOW =
    ConvertOEM7RangeToMeasEpochRA_Y.timeOfWeek;
  ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.WNc =
    ConvertOEM7RangeToMeasEpochRA_U.Oem7RangeBus.header_week;
  ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.N = 0U;

  // Outport: '<Root>/HCS_Bus' incorporates:
  //   MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'

  for (ConvertOEM7RangeToMeasEpochRA_B.i = 0; ConvertOEM7RangeToMeasEpochRA_B.i <
       40; ConvertOEM7RangeToMeasEpochRA_B.i++) {
    ConvertOEM7RangeToMeasEpochRA_Y.HCS_Bus.SVID[ConvertOEM7RangeToMeasEpochRA_B.i]
      =
      ConvertOEM7RangeToMeasEpochRA_Y.MeasurementEpochBus.SVID[ConvertOEM7RangeToMeasEpochRA_B.i];
  }

  // MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'
  for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
       ConvertOEM7RangeToMeasEpochRA_B.idx < 200;
       ConvertOEM7RangeToMeasEpochRA_B.idx++) {
    ConvertOEM7RangeToMeasEpochRA_B.MeasurementObsInfo_m[ConvertOEM7RangeToMeasEpochRA_B.idx]
      =
      (ConvertOEM7RangeToMeasEpochRA_B.MeasurementObsInfo[ConvertOEM7RangeToMeasEpochRA_B.idx]
       == 1);
  }

  ConvertOEM7RangeToMeasEpoch_any
    (ConvertOEM7RangeToMeasEpochRA_B.MeasurementObsInfo_m,
     ConvertOEM7RangeToMeasEpochRA_B.bv);

  // Outport: '<Root>/HCS_Bus' incorporates:
  //   MATLAB Function: '<Root>/OEM7RangeToMeasEpochRAW'

  for (ConvertOEM7RangeToMeasEpochRA_B.idx = 0;
       ConvertOEM7RangeToMeasEpochRA_B.idx < 40;
       ConvertOEM7RangeToMeasEpochRA_B.idx++) {
    ConvertOEM7RangeToMeasEpochRA_Y.HCS_Bus.HalfCycleAmbiguity[ConvertOEM7RangeToMeasEpochRA_B.idx]
      = ConvertOEM7RangeToMeasEpochRA_B.bv[ConvertOEM7RangeToMeasEpochRA_B.idx];
  }
}

// Model initialize function
void ConvertOEM7RangeToMeasEpochRAW::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void ConvertOEM7RangeToMeasEpochRAW::terminate()
{
  // (no terminate code required)
}

// Constructor
ConvertOEM7RangeToMeasEpochRAW::ConvertOEM7RangeToMeasEpochRAW() :
  ConvertOEM7RangeToMeasEpochRA_U(),
  ConvertOEM7RangeToMeasEpochRA_Y(),
  ConvertOEM7RangeToMeasEpochRA_B(),
  ConvertOEM7RangeToMeasEpochR_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
ConvertOEM7RangeToMeasEpochRAW::~ConvertOEM7RangeToMeasEpochRAW()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
ConvertOEM7RangeToMeasEpochRAW::RT_MODEL_ConvertOEM7RangeToMe_T
  * ConvertOEM7RangeToMeasEpochRAW::getRTM()
{
  return (&ConvertOEM7RangeToMeasEpochR_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
