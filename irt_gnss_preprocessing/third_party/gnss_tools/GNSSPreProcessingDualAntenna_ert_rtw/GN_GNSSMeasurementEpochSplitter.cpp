//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GN_GNSSMeasurementEpochSplitter.cpp
//
// Code generated for Simulink model 'GNSSPreProcessingDualAntenna'.
//
// Model version                  : 3.8
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Tue Jan 24 11:01:39 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "GNSSPreProcessingDualAntenna_types.h"
#include "rtwtypes.h"
#include "GNSSPreProcessingDualAntenna.h"
#include "GN_GNSSMeasurementEpochSplitter.h"

// Function for MATLAB Function: '<S5>/GNSS Measurement Epoch Splitter'
int32_T GNSSPreProcessingDualAntenna::GNSSPrePr_combineVectorElements(const boolean_T x[40])
{
    int32_T y;
    y = x[0];
    for (int32_T k{0}; k < 39; k++)
    {
        y += x[k + 1];
    }

    return y;
}

//
// Output and update for atomic system:
//    '<S5>/GNSS Measurement Epoch Splitter'
//    '<S6>/GNSS Measurement Epoch Splitter'
//
void GNSSPreProcessingDualAntenna::GN_GNSSMeasurementEpochSplitter(const gnssraw_measurement_t *rtu_MeasurementEpochBus,
    real_T *rty_WNc, real_T *rty_TOW, gnssraw_measurement_t *rty_GpsMeasurementBus, gnssraw_measurement_t
    *rty_GalMeasurementBus, B_GNSSMeasurementEpochSplitte_T *localB)
{
    int32_T i;
    int32_T nz_tmp;
    int32_T trueCount;
    int32_T x_size_idx_1;
    boolean_T t[40];
    for (i = 0; i < 40; i++)
    {
        rty_GpsMeasurementBus->SVID[i] = 0U;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GpsMeasurementBus->Pseudorange[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GpsMeasurementBus->Pseudorange_Sigma[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GpsMeasurementBus->Doppler[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GpsMeasurementBus->Type[i] = MAX_uint8_T;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GpsMeasurementBus->Carrier[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GpsMeasurementBus->Carrier_Sigma[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GpsMeasurementBus->CN0[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GpsMeasurementBus->Locktime[i] = 0.0F;
    }

    for (i = 0; i < 40; i++)
    {
        rty_GalMeasurementBus->SVID[i] = 0U;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GalMeasurementBus->Pseudorange[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GalMeasurementBus->Pseudorange_Sigma[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GalMeasurementBus->Doppler[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GalMeasurementBus->Type[i] = MAX_uint8_T;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GalMeasurementBus->Carrier[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GalMeasurementBus->Carrier_Sigma[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GalMeasurementBus->CN0[i] = 0.0;
    }

    for (i = 0; i < 200; i++)
    {
        rty_GalMeasurementBus->Locktime[i] = 0.0F;
    }

    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        boolean_T v;
        boolean_T w;
        v = (rtu_MeasurementEpochBus->SVID[nz_tmp] >= 1);
        w = (rtu_MeasurementEpochBus->SVID[nz_tmp] <= 37);
        localB->v_m[nz_tmp] = (v && w);
        localB->v[nz_tmp] = v;
        localB->w[nz_tmp] = w;
        v = (rtu_MeasurementEpochBus->SVID[nz_tmp] >= 71);
        w = (rtu_MeasurementEpochBus->SVID[nz_tmp] <= 102);
        t[nz_tmp] = (v && w);
        localB->t[nz_tmp] = v;
        localB->u[nz_tmp] = w;
    }

    nz_tmp = GNSSPrePr_combineVectorElements(localB->v_m);
    i = GNSSPrePr_combineVectorElements(t);
    rty_GpsMeasurementBus->TOW = rtu_MeasurementEpochBus->TOW;
    rty_GpsMeasurementBus->WNc = rtu_MeasurementEpochBus->WNc;
    if (nz_tmp < 0)
    {
        nz_tmp = 0;
    }
    else if (nz_tmp > 255)
    {
        nz_tmp = 255;
    }

    rty_GpsMeasurementBus->N = static_cast<uint8_T>(nz_tmp);
    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            trueCount++;
        }
    }

    x_size_idx_1 = trueCount;
    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            localB->x_data[trueCount] = static_cast<int8_T>(nz_tmp + 1);
            trueCount++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        rty_GpsMeasurementBus->SVID[nz_tmp] = rtu_MeasurementEpochBus->SVID[localB->x_data[nz_tmp] - 1];
    }

    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            trueCount++;
        }
    }

    x_size_idx_1 = trueCount;
    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            localB->y_data[trueCount] = static_cast<int8_T>(nz_tmp + 1);
            trueCount++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GpsMeasurementBus->Pseudorange[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Pseudorange
                [(localB->y_data[nz_tmp] - 1) * 5 + trueCount];
        }
    }

    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            trueCount++;
        }
    }

    x_size_idx_1 = trueCount;
    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            localB->ab_data[trueCount] = static_cast<int8_T>(nz_tmp + 1);
            trueCount++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GpsMeasurementBus->Pseudorange_Sigma[trueCount + 5 * nz_tmp] =
                rtu_MeasurementEpochBus->Pseudorange_Sigma[(localB->ab_data[nz_tmp] - 1) * 5 + trueCount];
        }
    }

    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            trueCount++;
        }
    }

    x_size_idx_1 = trueCount;
    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            localB->bb_data[trueCount] = static_cast<int8_T>(nz_tmp + 1);
            trueCount++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GpsMeasurementBus->Doppler[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Doppler[(localB->
                bb_data[nz_tmp] - 1) * 5 + trueCount];
        }
    }

    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            trueCount++;
        }
    }

    x_size_idx_1 = trueCount;
    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            localB->cb_data[trueCount] = static_cast<int8_T>(nz_tmp + 1);
            trueCount++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GpsMeasurementBus->Type[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Type[(localB->cb_data[nz_tmp]
                - 1) * 5 + trueCount];
        }
    }

    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            trueCount++;
        }
    }

    x_size_idx_1 = trueCount;
    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            localB->db_data[trueCount] = static_cast<int8_T>(nz_tmp + 1);
            trueCount++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GpsMeasurementBus->Carrier[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Carrier[(localB->
                db_data[nz_tmp] - 1) * 5 + trueCount];
        }
    }

    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            trueCount++;
        }
    }

    x_size_idx_1 = trueCount;
    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            localB->eb_data[trueCount] = static_cast<int8_T>(nz_tmp + 1);
            trueCount++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GpsMeasurementBus->Carrier_Sigma[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Carrier_Sigma
                [(localB->eb_data[nz_tmp] - 1) * 5 + trueCount];
        }
    }

    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            trueCount++;
        }
    }

    x_size_idx_1 = trueCount;
    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            localB->fb_data[trueCount] = static_cast<int8_T>(nz_tmp + 1);
            trueCount++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GpsMeasurementBus->CN0[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->CN0[(localB->fb_data[nz_tmp] -
                1) * 5 + trueCount];
        }
    }

    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            trueCount++;
        }
    }

    x_size_idx_1 = trueCount;
    trueCount = 0;
    for (nz_tmp = 0; nz_tmp < 40; nz_tmp++)
    {
        if (localB->v[nz_tmp] && localB->w[nz_tmp])
        {
            localB->gb_data[trueCount] = static_cast<int8_T>(nz_tmp + 1);
            trueCount++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GpsMeasurementBus->Locktime[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Locktime[(localB->
                gb_data[nz_tmp] - 1) * 5 + trueCount];
        }
    }

    rty_GalMeasurementBus->TOW = rtu_MeasurementEpochBus->TOW;
    rty_GalMeasurementBus->WNc = rtu_MeasurementEpochBus->WNc;
    if (i < 0)
    {
        i = 0;
    }
    else if (i > 255)
    {
        i = 255;
    }

    rty_GalMeasurementBus->N = static_cast<uint8_T>(i);
    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            nz_tmp++;
        }
    }

    trueCount = nz_tmp;
    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            localB->hb_data[nz_tmp] = static_cast<int8_T>(i + 1);
            nz_tmp++;
        }
    }

    for (nz_tmp = 0; nz_tmp < trueCount; nz_tmp++)
    {
        rty_GalMeasurementBus->SVID[nz_tmp] = rtu_MeasurementEpochBus->SVID[localB->hb_data[nz_tmp] - 1];
    }

    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            nz_tmp++;
        }
    }

    x_size_idx_1 = nz_tmp;
    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            localB->ib_data[nz_tmp] = static_cast<int8_T>(i + 1);
            nz_tmp++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GalMeasurementBus->Pseudorange[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Pseudorange
                [(localB->ib_data[nz_tmp] - 1) * 5 + trueCount];
        }
    }

    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            nz_tmp++;
        }
    }

    x_size_idx_1 = nz_tmp;
    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            localB->jb_data[nz_tmp] = static_cast<int8_T>(i + 1);
            nz_tmp++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GalMeasurementBus->Pseudorange_Sigma[trueCount + 5 * nz_tmp] =
                rtu_MeasurementEpochBus->Pseudorange_Sigma[(localB->jb_data[nz_tmp] - 1) * 5 + trueCount];
        }
    }

    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            nz_tmp++;
        }
    }

    x_size_idx_1 = nz_tmp;
    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            localB->kb_data[nz_tmp] = static_cast<int8_T>(i + 1);
            nz_tmp++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GalMeasurementBus->Doppler[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Doppler[(localB->
                kb_data[nz_tmp] - 1) * 5 + trueCount];
        }
    }

    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            nz_tmp++;
        }
    }

    x_size_idx_1 = nz_tmp;
    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            localB->lb_data[nz_tmp] = static_cast<int8_T>(i + 1);
            nz_tmp++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GalMeasurementBus->Type[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Type[(localB->lb_data[nz_tmp]
                - 1) * 5 + trueCount];
        }
    }

    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            nz_tmp++;
        }
    }

    x_size_idx_1 = nz_tmp;
    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            localB->mb_data[nz_tmp] = static_cast<int8_T>(i + 1);
            nz_tmp++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GalMeasurementBus->Carrier[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Carrier[(localB->
                mb_data[nz_tmp] - 1) * 5 + trueCount];
        }
    }

    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            nz_tmp++;
        }
    }

    x_size_idx_1 = nz_tmp;
    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            localB->nb_data[nz_tmp] = static_cast<int8_T>(i + 1);
            nz_tmp++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GalMeasurementBus->Carrier_Sigma[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Carrier_Sigma
                [(localB->nb_data[nz_tmp] - 1) * 5 + trueCount];
        }
    }

    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            nz_tmp++;
        }
    }

    x_size_idx_1 = nz_tmp;
    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            localB->ob_data[nz_tmp] = static_cast<int8_T>(i + 1);
            nz_tmp++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GalMeasurementBus->CN0[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->CN0[(localB->ob_data[nz_tmp] -
                1) * 5 + trueCount];
        }
    }

    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            nz_tmp++;
        }
    }

    x_size_idx_1 = nz_tmp;
    nz_tmp = 0;
    for (i = 0; i < 40; i++)
    {
        if (localB->t[i] && localB->u[i])
        {
            localB->pb_data[nz_tmp] = static_cast<int8_T>(i + 1);
            nz_tmp++;
        }
    }

    for (nz_tmp = 0; nz_tmp < x_size_idx_1; nz_tmp++)
    {
        for (trueCount = 0; trueCount < 5; trueCount++)
        {
            rty_GalMeasurementBus->Locktime[trueCount + 5 * nz_tmp] = rtu_MeasurementEpochBus->Locktime[(localB->
                pb_data[nz_tmp] - 1) * 5 + trueCount];
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
