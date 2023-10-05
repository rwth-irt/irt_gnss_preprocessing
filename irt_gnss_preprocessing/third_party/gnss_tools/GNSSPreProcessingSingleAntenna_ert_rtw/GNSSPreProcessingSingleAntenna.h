//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GNSSPreProcessingSingleAntenna.h
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
#ifndef RTW_HEADER_GNSSPreProcessingSingleAntenna_h_
#define RTW_HEADER_GNSSPreProcessingSingleAntenna_h_
#include "rtwtypes.h"
#include "GNSSPreProce_CalculateDayofYear.h"
#include "GNSSPreProcessingSingleAntenna_types.h"
#include "CalculateSatelliteClockCorrecti.h"
#include "CalculateSatellitePositionandVe.h"
#include "GNSS_TimeCorrectionCarrierphase.h"
#include "GNSSPr_TimeCorrectionDeltarange.h"
#include "GNSSP_TimeCorrectionPseudorange.h"
#include "rt_sys_GPSFrequencyStream_13.h"
#include "GPSFrequencyStream.h"
#include "GNS_NavigationDataConversionGPS.h"
#include "CalculateDifferentialCorrection.h"
#include "CalculateDualfrequencyCorrectio.h"
#include "CalculateKlobucharModelCorrecti.h"
#include "CalculateTroposphericCorrection.h"
#include "GN_CreateSatelliteElevationMask.h"
#include "ApplyDifferentialCorrectionMask.h"
#include "SimplifyandMaskGPSMeasurementBu.h"
#include "GalileoFrequencyStream.h"
#include "GNS_NavigationDataConversionGAL.h"
#include "CalculateDifferentialCorrecti_l.h"
#include "CalculateTroposphericCorrecti_h.h"
#include "ApplyDifferentialCorrectionMa_b.h"
#include "SimplifyandMaskGALMeasurementBu.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtw_modelmap.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals for system '<S55>/Apply Elevation and NaN and Zero Mask'
struct B_ApplyElevationandNaNandZero_T {
  GNSS_Measurement measurementFrequencyCorrectedMa;
                               // '<S55>/Apply Elevation and NaN and Zero Mask'
};

// Block states (default storage) for system '<S55>/Apply Elevation and NaN and Zero Mask' 
struct DW_ApplyElevationandNaNandZer_T {
  GNSS_Measurement_size SFunction_DIMS2;
                               // '<S55>/Apply Elevation and NaN and Zero Mask'
  uint16_T nanerrs;            // '<S55>/Apply Elevation and NaN and Zero Mask'
};

// Block signals (default storage)
struct B_GNSSPreProcessingSingleAnte_T {
  s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T expl_temp;
  s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T expl_temp_m;
  real_T P_data[1600];
  real_T q_data[1600];
  real_T s_data[1600];
  real_T matrix_pseudorange_variance_dat[1600];
  real_T S_data[1600];
  real_T f_data[1600];
  real_T A_data[1600];
  real_T in1_data[1600];
  gnssraw_measurement_t GpsMeasurementBus;
                                      // '<S3>/GNSS Measurement Epoch Splitter'
  gnssraw_measurement_t GalMeasurementBus;
                                      // '<S3>/GNSS Measurement Epoch Splitter'
  real_T GPSGalileoPosition[1000];
  emxArray__GNSS_Measurement_GN_T r;
  emxArray__GNSS_Measurement_GN_T r1;
  emxArray__GNSS_Measurement_GN_T galileo_measurement_temp;
  GNSS_Measurement GnssMeasurementBus; // '<S3>/Merge GNSS Measurement'
  GNSS_Measurement GNSS_measurement_out;// '<S118>/Fault Exclusion'
  GNSS_Measurement dummy_GNSS_Measurement_Bus;// '<S3>/Dummy GNSS Measurement'
  GNSS_Measurement galileo_measurement_temp_data;
  GNSS_Measurement GpsMeasurementB;    // '<S3>/MATLAB Function'
  GNSS_Measurement GalMeasurementB;    // '<S3>/MATLAB Function'
  GNSS_Measurement measurementBusL1_WL;
                                     // '<S51>/Calculate Wide Lane Combination'
  GNSS_Measurement measurementFrequencyCorrect;
                              // '<S111>/Apply Elevation and NaN and Zero Mask'
  GNSS_Measurement GNSS_Measurement_out;// '<S118>/Weighted RAIM Parity'
  GNSS_Measurement measurementFrequencyCorre_i;
                         // '<S55>/Apply Non Dual Frequency GPS Satellite Mask'
  real_T b_H_data[800];
  real_T b_A_data[800];
  parameters_gnss_t BusConversion_InsertedFor_Mer_p;
  parameters_gnss_t parameters_gnss;   // '<S125>/choose correction mode'
  real_T time_receive;                 // '<S12>/Bus Selector'
  real_T satellite_position[120];      // '<S12>/Bus Selector'
  real_T satellite_velocity[120];      // '<S12>/Bus Selector'
  real_T pseudorange[40];              // '<S12>/Bus Selector'
  real_T pseudorange_raw[40];          // '<S12>/Bus Selector'
  real_T pseudorange_satclk_corrected[40];// '<S12>/Bus Selector'
  real_T deltarange[40];               // '<S12>/Bus Selector'
  real_T deltarange_raw[40];           // '<S12>/Bus Selector'
  real_T deltarange_satclk_corrected[40];// '<S12>/Bus Selector'
  real_T variance_pseudorange[40];     // '<S12>/Bus Selector'
  real_T variance_pseudorange_measured[40];// '<S12>/Bus Selector'
  real_T variance_deltarange[40];      // '<S12>/Bus Selector'
  real_T carrierphase[40];             // '<S12>/Bus Selector'
  real_T carrierphase_raw[40];         // '<S12>/Bus Selector'
  real_T carrierphase_satclk_corrected[40];// '<S12>/Bus Selector'
  real_T variance_carrierphase_measured[40];// '<S12>/Bus Selector'
  real_T CN0[40];                      // '<S12>/Bus Selector'
  real_T base_position[3];             // '<S12>/Bus Selector'
  real_T time_receive_b;               // '<S11>/Bus Selector'
  real_T satellite_position_o[120];    // '<S11>/Bus Selector'
  real_T satellite_velocity_p[120];    // '<S11>/Bus Selector'
  real_T pseudorange_l[40];            // '<S11>/Bus Selector'
  real_T pseudorange_raw_k[40];        // '<S11>/Bus Selector'
  real_T pseudorange_satclk_corrected_a[40];// '<S11>/Bus Selector'
  real_T deltarange_h[40];             // '<S11>/Bus Selector'
  real_T deltarange_raw_k[40];         // '<S11>/Bus Selector'
  real_T deltarange_satclk_corrected_n[40];// '<S11>/Bus Selector'
  real_T variance_pseudorange_g[40];   // '<S11>/Bus Selector'
  real_T variance_pseudorange_measured_i[40];// '<S11>/Bus Selector'
  real_T variance_deltarange_n[40];    // '<S11>/Bus Selector'
  real_T carrierphase_a[40];           // '<S11>/Bus Selector'
  real_T carrierphase_raw_c[40];       // '<S11>/Bus Selector'
  real_T carrierphase_satclk_corrected_m[40];// '<S11>/Bus Selector'
  real_T variance_carrierphase_measure_o[40];// '<S11>/Bus Selector'
  real_T CN0_f[40];                    // '<S11>/Bus Selector'
  real_T base_position_b[3];           // '<S11>/Bus Selector'
  real32_T locktime[40];               // '<S12>/Bus Selector'
  real32_T locktime_k[40];             // '<S11>/Bus Selector'
  uint16_T PRN[40];                    // '<S12>/Bus Selector'
  uint16_T PRN_i[40];                  // '<S107>/Bus Selector'
  uint16_T PRN_b[40];                  // '<S11>/Bus Selector'
  uint16_T SvidCarrierInUse[40];     // '<S51>/Calculate Wide Lane Combination'
  boolean_T LogicalOperator2;          // '<S70>/Logical Operator2'
  boolean_T LogicalOperator1;          // '<S23>/Logical Operator1'
  B_SimplifyandMaskGALMeasureme_T sf_SimplifyandMaskGALMeasuremen;
                               // '<S12>/Simplify and Mask GAL Measurement Bus'
  B_ApplyDifferentialCorrecti_e_T sf_ApplyDifferentialCorrectio_b;
                                // '<S111>/Apply Differential Correction Mask1'
  B_CreateSatelliteElevationMas_T sf_CreateSatelliteElevationMa_a;
                                    // '<S110>/Create Satellite Elevation Mask'
  B_CalculateTroposphericCorr_h_T sf_CalculateTroposphericCorre_h;
                                  // '<S70>/Calculate Tropospheric Corrections'
  B_CalculateDifferentialCorr_g_T sf_CalculateDifferentialCorre_l;
                                  // '<S70>/Calculate Differential Corrections'
  B_NavigationDataConversionGAL_T sf_NavigationDataConversionGAL;
                                      // '<S12>/Navigation Data Conversion GAL'
  B_Galileosinglefrequencystrea_T GalileoE5bstream;// '<S12>/Galileo E5b stream' 
  B_Galileosinglefrequencystrea_T GalileoE5astream;// '<S12>/Galileo E5a stream' 
  B_Galileosinglefrequencystrea_T GalileoE5stream;// '<S12>/Galileo E5 stream'
  B_Galileosinglefrequencystrea_T GalileoE1stream;// '<S12>/Galileo E1 stream'
  B_SimplifyandMaskGPSMeasureme_T sf_SimplifyandMaskGPSMeasuremen;
                               // '<S11>/Simplify and Mask GPS Measurement Bus'
  B_ApplyElevationandNaNandZero_T sf_ApplyElevationandNaNandZeroM;
                               // '<S55>/Apply Elevation and NaN and Zero Mask'
  B_ApplyDifferentialCorrection_T sf_ApplyDifferentialCorrectionM;
                                 // '<S55>/Apply Differential Correction Mask1'
  B_CreateSatelliteElevationMas_T sf_CreateSatelliteElevationMask;
                                     // '<S54>/Create Satellite Elevation Mask'
  B_CalculateTroposphericCorrec_T sf_CalculateTroposphericCorrect;
                                  // '<S23>/Calculate Tropospheric Corrections'
  B_CalculateKlobucharModelCorr_T sf_CalculateKlobucharModelCorre;
                                // '<S51>/Calculate Klobuchar Model Correction'
  B_CalculateDualfrequencyCorre_T sf_CalculateDualfrequencyCorrec;
                  // '<S51>/Calculate Dualfrequency Correction with L1 and L2C'
  B_CalculateDifferentialCorrec_T sf_CalculateDifferentialCorrect;
                                  // '<S23>/Calculate Differential Corrections'
  B_NavigationDataConversionGPS_T sf_NavigationDataConversionGPS;
                                      // '<S11>/Navigation Data Conversion GPS'
  B_GPSsinglefrequencystream_GN_T GPSL5Stream;// '<S11>/GPS L5 Stream'
  B_GPSsinglefrequencystream_GN_T GPSL2CStream;// '<S11>/GPS L2C Stream'
  B_GPSsinglefrequencystream_GN_T GPSL1Stream;// '<S11>/GPS L1 Stream'
};

// Block states (default storage) for system '<Root>'
struct DW_GNSSPreProcessingSingleAnt_T {
  GNSS_Measurement_size BusConversion_InsertedFor_Merge;// synthesized block
  GNSS_Measurement_size BusConversion_InsertedFor_Mer_f;// synthesized block
  GNSS_Measurement_size BusConversion_InsertedFor_Conve;// synthesized block
  GNSS_Measurement_size BusConversion_InsertedFor_Con_b;// synthesized block
  GNSS_Measurement_size SFunction_DIMS2;// '<S3>/Merge GNSS Measurement'
  GNSS_Measurement_size SFunction_DIMS2_b;// '<S3>/MATLAB Function'
  GNSS_Measurement_size SFunction_DIMS3;// '<S3>/MATLAB Function'
  GNSS_Measurement_size SFunction_DIMS2_m;// '<S117>/switch GNSS Measurements'
  GNSS_Measurement_size BusAssignment_DIMS1;// '<S118>/Bus Assignment'
  GNSS_Measurement_size SFunction_DIMS6;// '<S118>/Weighted RAIM Parity'
  GNSS_Measurement_size SFunction_DIMS2_b5;// '<S118>/Fault Exclusion'
  GNSS_Measurement_size SFunction_DIMS2_j;// '<S13>/CalcDOP'
  GNSS_Measurement_size BusConversion_InsertedFor_Calcu;// synthesized block
  GNSS_Measurement_size BusConversion_InsertedFor_Cal_o;// synthesized block
  GNSS_Measurement_size BusConversion_InsertedFor_Cal_k;// synthesized block
  GNSS_Measurement_size BusConversion_InsertedFor_Cal_b;// synthesized block
  GNSS_Measurement_size BusAssignment2_DIMS1;// '<S107>/Bus Assignment2'
  GNSS_Measurement_size BusAssignment1_DIMS1;// '<S70>/Bus Assignment1'
  GNSS_Measurement_size SFunction_DIMS2_h;
                              // '<S111>/Apply Elevation and NaN and Zero Mask'
  GNSS_Measurement_size SFunction_DIMS2_l;
                  // '<S107>/Calculate Dualfrequency Correction with E1 and E5'
  GNSS_Measurement_size BusConversion_InsertedFor_Cal_p;// synthesized block
  GNSS_Measurement_size BusConversion_InsertedFor_Cal_m;// synthesized block
  GNSS_Measurement_size BusConversion_InsertedFor_Cal_d;// synthesized block
  GNSS_Measurement_size BusConversion_InsertedFor_Ca_kn;// synthesized block
  GNSS_Measurement_size BusAssignment2_DIMS1_i;// '<S51>/Bus Assignment2'
  GNSS_Measurement_size BusAssignment2_DIMS1_h;// '<S23>/Bus Assignment2'
  GNSS_Measurement_size SFunction_DIMS2_hh;
                         // '<S55>/Apply Non Dual Frequency GPS Satellite Mask'
  GNSS_Measurement_size SFunction_DIMS3_o;
                                     // '<S51>/Calculate Wide Lane Combination'
  GNSS_Measurement_size SFunction_DIMS2_p;// '<S3>/Dummy GNSS Measurement'
  GNSS_Measurement_size SFunction_DIMS2_hhl;
           // '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'
  real_T DelayInput1_DSTATE;           // '<S128>/Delay Input1'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S124>/Discrete-Time Integrator'
  real_T userposBuffer[1000];          // '<S3>/Merge GNSS Measurement'
  real_T writeIdx;                     // '<S3>/Merge GNSS Measurement'
  real_T BUFFER[80];                   // '<S118>/Fault Exclusion'
  real_T sys_clock_last_loop;          // '<S118>/Fault Exclusion'
  int32_T SFunction_DIMS2_d;           // '<S118>/calculate Variance'
  int32_T BusSelector1_DIMS1;          // '<S107>/Bus Selector1'
  int32_T BusSelector_DIMS1;           // '<S70>/Bus Selector'
  int32_T BusSelector_DIMS2[2];        // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS3[2];        // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS4;           // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS5;           // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS6;           // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS7;           // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS8;           // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS9;           // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS10;          // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS11;          // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS12;          // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS13;          // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS14;          // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS15;          // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS16;          // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS17;          // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS18;          // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS19;          // '<S12>/Bus Selector'
  int32_T BusSelector_DIMS1_g;         // '<S107>/Bus Selector'
  int32_T SFunction_DIMS3_e;
                  // '<S107>/Calculate Dualfrequency Correction with E1 and E5'
  int32_T BusSelector1_DIMS1_f;        // '<S51>/Bus Selector1'
  int32_T BusSelector2_DIMS1;          // '<S23>/Bus Selector2'
  int32_T BusSelector_DIMS2_a[2];      // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS3_a[2];      // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS4_b;         // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS5_e;         // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS6_d;         // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS7_i;         // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS8_m;         // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS9_i;         // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS10_f;        // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS11_c;        // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS12_i;        // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS13_j;        // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS14_f;        // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS15_g;        // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS16_k;        // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS17_d;        // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS18_o;        // '<S11>/Bus Selector'
  int32_T BusSelector_DIMS19_a;        // '<S11>/Bus Selector'
  int32_T SFunction_DIMS2_ho;        // '<S51>/Calculate Wide Lane Combination'
  int32_T SFunction_DIMS2_px;          // '<S3>/Fuse'
  uint32_T temporalCounter_i1;         // '<S125>/choose correction mode'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S124>/Discrete-Time Integrator'
  uint8_T is_c130_lib_GNSSPreProcessing;// '<S125>/choose correction mode'
  uint8_T is_DGPS;                     // '<S125>/choose correction mode'
  uint8_T is_Dualfrequency;            // '<S125>/choose correction mode'
  uint8_T is_active_c130_lib_GNSSPreProce;// '<S125>/choose correction mode'
  boolean_T Memory_PreviousInput;      // '<S129>/Memory'
  boolean_T BUFFER_not_empty;          // '<S118>/Fault Exclusion'
  DW_SimplifyandMaskGALMeasurem_T sf_SimplifyandMaskGALMeasuremen;
                               // '<S12>/Simplify and Mask GAL Measurement Bus'
  DW_ApplyDifferentialCorrect_l_T sf_ApplyDifferentialCorrectio_b;
                                // '<S111>/Apply Differential Correction Mask1'
  DW_CreateSatelliteElevationMa_T sf_CreateSatelliteElevationMa_a;
                                    // '<S110>/Create Satellite Elevation Mask'
  DW_CalculateTroposphericCor_c_T sf_CalculateTroposphericCorre_h;
                                  // '<S70>/Calculate Tropospheric Corrections'
  DW_CalculateDifferentialCor_o_T sf_CalculateDifferentialCorre_l;
                                  // '<S70>/Calculate Differential Corrections'
  DW_NavigationDataConversionGA_T sf_NavigationDataConversionGAL;
                                      // '<S12>/Navigation Data Conversion GAL'
  DW_Galileosinglefrequencystre_T GalileoE5bstream;// '<S12>/Galileo E5b stream' 
  DW_Galileosinglefrequencystre_T GalileoE5astream;// '<S12>/Galileo E5a stream' 
  DW_Galileosinglefrequencystre_T GalileoE5stream;// '<S12>/Galileo E5 stream'
  DW_Galileosinglefrequencystre_T GalileoE1stream;// '<S12>/Galileo E1 stream'
  DW_SimplifyandMaskGPSMeasurem_T sf_SimplifyandMaskGPSMeasuremen;
                               // '<S11>/Simplify and Mask GPS Measurement Bus'
  DW_ApplyElevationandNaNandZer_T sf_ApplyElevationandNaNandZeroM;
                               // '<S55>/Apply Elevation and NaN and Zero Mask'
  DW_ApplyDifferentialCorrectio_T sf_ApplyDifferentialCorrectionM;
                                 // '<S55>/Apply Differential Correction Mask1'
  DW_CreateSatelliteElevationMa_T sf_CreateSatelliteElevationMask;
                                     // '<S54>/Create Satellite Elevation Mask'
  DW_CalculateTroposphericCorre_T sf_CalculateTroposphericCorrect;
                                  // '<S23>/Calculate Tropospheric Corrections'
  DW_CalculateKlobucharModelCor_T sf_CalculateKlobucharModelCorre;
                                // '<S51>/Calculate Klobuchar Model Correction'
  DW_CalculateDualfrequencyCorr_T sf_CalculateDualfrequencyCorrec;
                  // '<S51>/Calculate Dualfrequency Correction with L1 and L2C'
  DW_CalculateDifferentialCorre_T sf_CalculateDifferentialCorrect;
                                  // '<S23>/Calculate Differential Corrections'
  DW_NavigationDataConversionGP_T sf_NavigationDataConversionGPS;
                                      // '<S11>/Navigation Data Conversion GPS'
  DW_GPSsinglefrequencystream_G_T GPSL5Stream;// '<S11>/GPS L5 Stream'
  DW_GPSsinglefrequencystream_G_T GPSL2CStream;// '<S11>/GPS L2C Stream'
  DW_GPSsinglefrequencystream_G_T GPSL1Stream;// '<S11>/GPS L1 Stream'
  DW_CalculateDayofYear_GNSSPre_T sf_CalculateDayofYear;// '<S3>/Calculate Day of Year' 
};

// External inputs (root inport signals with default storage)
struct ExtU_GNSSPreProcessingSingleA_T {
  gnssraw_measurement_t MeasurementEpochBus;// '<Root>/MeasurementEpochBus'
  gnssraw_gps_nav_t GPSNavBus;         // '<Root>/GPSNavBus'
  gnssraw_gps_ion_t GPSIONBus;         // '<Root>/GPSIONBus'
  gnssraw_gal_nav_t GALNavBus;         // '<Root>/GALNavBus'
  gnssraw_gal_ion_t GALIONBus;         // '<Root>/GALIONBus'
  gnssraw_ggto_t GALGSTGPSBus;         // '<Root>/GALGSTGPSBus'
  DD_RTCM_3_3_L1_E1_t RTCM_3_3_L1_E1_Bus;// '<Root>/RTCM_3_3_L1_E1_Bus'
  real_T usePosLLHArray[3];            // '<Root>/usePosLLHArray'
  real_T ClockErrorArray;              // '<Root>/ClockErrorArray'
  parameters_gnss_t GNSSParametersBus; // '<Root>/GNSSParametersBus'
  parameters_integrity_t IntegrityParametersBus;// '<Root>/IntegrityParametersBus' 
  real_T useModeSwitchLogic;           // '<Root>/useModeSwitchLogic'
  real_T enableGGTO;                   // '<Root>/enableGGTO'
  boolean_T enableGNSSMerge;           // '<Root>/enableGNSSMerge'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_GNSSPreProcessingSingleA_T {
  GNSSMeasurementFixed GNSSMeasurementBus;// '<Root>/GNSSMeasurementBus'
  real_T GNSSMeasurementSize;          // '<Root>/GNSSMeasurementSize'
  uint16_T SVIDCarrierUse[40];         // '<Root>/SVIDCarrierUse'
  real_T integrityFlag;                // '<Root>/integrityFlag'
  real_T deltaSystemTimeGnss;          // '<Root>/deltaSystemTimeGnss'
  boolean_T isGGTOValid;               // '<Root>/isGGTOValid'
  real_T DOP[2];                       // '<Root>/DOP'
  real_T faultyPRNs[80];               // '<Root>/faultyPRNs'
  GNSSMeasurementFixed GPSMeasurementBus;// '<Root>/GPSMeasurementBus'
  real_T GPSMeasurementSize;           // '<Root>/GPSMeasurementSize'
  GNSSMeasurementFixed GALMeasurementBus;// '<Root>/GALMeasurementBus'
  real_T GALMeasurementSize1;          // '<Root>/GALMeasurementSize1'
  LeastSquareSolution LeastSqureSolutionAntMain;// '<Root>/LeastSqureSolutionAntMain' 
  real_T diffPsedorangeCorrections[40];// '<Root>/diffPsedorangeCorrections'
  uint16_T diffSVIDCorrections[40];    // '<Root>/diffSVIDCorrections'
  boolean_T GPSGALCorrected[2];        // '<Root>/GPSGALCorrected'
  real_T GPSGALCorrectionMode;         // '<Root>/GPSGALCorrectionMode'
};

// External output sizes (for root outports fed by signals with variable sizes)
struct ExtYSize_GNSSPreProcessingSin_T {
  int32_T SFunction_DIMS2_px;          // '<Root>/SVIDCarrierUse'
};

// Parameters (default storage)
struct P_GNSSPreProcessingSingleAnte_T_ {
  real_T table_chi_square[80];         // Variable: table_chi_square
                                          //  Referenced by: '<S118>/Weighted RAIM Parity'

  real_T table_sigma_noise_GNSSReceiver[4];
                                     // Variable: table_sigma_noise_GNSSReceiver
                                        //  Referenced by: '<S118>/calculate Variance'

  real_T CompareToConstant1_const;   // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S53>/Constant'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S109>/Constant'

  real_T CompareToConstant_const_p; // Mask Parameter: CompareToConstant_const_p
                                       //  Referenced by: '<S127>/Constant'

  real_T GPSL2CStream_enable_SatClockCor;
                              // Mask Parameter: GPSL2CStream_enable_SatClockCor
                                 //  Referenced by: '<S11>/GPS L2C Stream'

  real_T GPSL5Stream_enable_SatClockCorr;
                              // Mask Parameter: GPSL5Stream_enable_SatClockCorr
                                 //  Referenced by: '<S11>/GPS L5 Stream'

  real_T GPSL1Stream_enable_SatClockCorr;
                              // Mask Parameter: GPSL1Stream_enable_SatClockCorr
                                 //  Referenced by: '<S11>/GPS L1 Stream'

  real_T GalileoE1stream_enable_SatClock;
                              // Mask Parameter: GalileoE1stream_enable_SatClock
                                 //  Referenced by: '<S12>/Galileo E1 stream'

  real_T GalileoE5astream_enable_SatCloc;
                              // Mask Parameter: GalileoE5astream_enable_SatCloc
                                 //  Referenced by: '<S12>/Galileo E5a stream'

  real_T GalileoE5bstream_enable_SatCloc;
                              // Mask Parameter: GalileoE5bstream_enable_SatCloc
                                 //  Referenced by: '<S12>/Galileo E5b stream'

  real_T GalileoE5stream_enable_SatClock;
                              // Mask Parameter: GalileoE5stream_enable_SatClock
                                 //  Referenced by: '<S12>/Galileo E5 stream'

  real_T DetectChange_vinit;           // Mask Parameter: DetectChange_vinit
                                          //  Referenced by: '<S128>/Delay Input1'

  boolean_T SRFlipFlop_initial_condition;
                                 // Mask Parameter: SRFlipFlop_initial_condition
                                    //  Referenced by: '<S129>/Memory'

  GNSS_Measurement GNSS_Measurement_out_Y0;
                                  // Computed Parameter: GNSS_Measurement_out_Y0
                                     //  Referenced by: '<S118>/GNSS_Measurement_out'

  real_T timeOfWeek_Y0;                // Computed Parameter: timeOfWeek_Y0
                                          //  Referenced by: '<S11>/timeOfWeek'

  real_T basePosition_Y0;              // Computed Parameter: basePosition_Y0
                                          //  Referenced by: '<S11>/basePosition'

  real_T BasePositionDummy_Value[3];   // Expression: [0 0 0]'
                                          //  Referenced by: '<S11>/Base Position Dummy'

  real_T timereceive_Y0;               // Computed Parameter: timereceive_Y0
                                          //  Referenced by: '<S12>/time receive'

  real_T basePosition_Y0_a;            // Computed Parameter: basePosition_Y0_a
                                          //  Referenced by: '<S12>/basePosition'

  real_T BasePositionDummy_Value_d[3]; // Expression: [0 0 0]'
                                          //  Referenced by: '<S12>/Base Position Dummy'

  real_T alert_Y0;                     // Computed Parameter: alert_Y0
                                          //  Referenced by: '<S118>/alert'

  real_T HPL_Y0;                       // Computed Parameter: HPL_Y0
                                          //  Referenced by: '<S118>/HPL'

  real_T test_statistic_Y0;            // Computed Parameter: test_statistic_Y0
                                          //  Referenced by: '<S118>/test_statistic'

  real_T PRNs_identified_Y0;           // Computed Parameter: PRNs_identified_Y0
                                          //  Referenced by: '<S118>/PRNs_identified'

  real_T PRNs_to_exclude_Y0;           // Computed Parameter: PRNs_to_exclude_Y0
                                          //  Referenced by: '<S118>/PRNs_to_exclude'

  real_T PRNs_excluded_Y0;             // Computed Parameter: PRNs_excluded_Y0
                                          //  Referenced by: '<S118>/PRNs_excluded'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S124>/Constant1'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S124>/Discrete-Time Integrator'

  real_T Constant2_Value;              // Expression: 5
                                          //  Referenced by: '<S125>/Constant2'

  real_T Constant3_Value;              // Expression: 5
                                          //  Referenced by: '<S125>/Constant3'

  real_T Constant4_Value;              // Expression: 3
                                          //  Referenced by: '<S125>/Constant4'

  real_T Constant5_Value;              // Expression: 4
                                          //  Referenced by: '<S125>/Constant5'

  real_T Constant6_Value;              // Expression: 3
                                          //  Referenced by: '<S125>/Constant6'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S124>/Constant'

  real_T Switch_1_Threshold;           // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_2_Threshold;           // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_3_Threshold;           // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_4_Threshold;           // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_5_Threshold;           // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_6_Threshold;           // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_7_Threshold;           // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_8_Threshold;           // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_9_Threshold;           // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_10_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_11_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_12_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_13_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_14_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_15_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_16_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_17_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_18_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_19_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_20_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_21_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_22_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_23_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_24_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_25_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  real_T Switch_26_Threshold;          // Expression: 0
                                          //  Referenced by: '<S3>/Switch'

  boolean_T GPSMeasurementCorrected_Y0;
                               // Computed Parameter: GPSMeasurementCorrected_Y0
                                  //  Referenced by: '<S11>/GPSMeasurementCorrected'

  boolean_T L5_basedProcessing_Value;
                                 // Computed Parameter: L5_basedProcessing_Value
                                    //  Referenced by: '<S11>/L5_basedProcessing'

  boolean_T AddTriggerHere_Value;      // Expression: false
                                          //  Referenced by: '<S11>/Add Trigger Here'

  boolean_T Constant_Value_j;          // Expression: false
                                          //  Referenced by: '<S51>/Constant'

  boolean_T GALMeasurementCorrected_Y0;
                               // Computed Parameter: GALMeasurementCorrected_Y0
                                  //  Referenced by: '<S12>/GALMeasurementCorrected'

  boolean_T E5_basedProcessing_Value;
                                 // Computed Parameter: E5_basedProcessing_Value
                                    //  Referenced by: '<S12>/E5_basedProcessing'

  boolean_T Logic_table[16];           // Computed Parameter: Logic_table
                                          //  Referenced by: '<S129>/Logic'

  P_Galileosinglefrequencystrea_T GalileoE5bstream;// '<S12>/Galileo E5b stream' 
  P_Galileosinglefrequencystrea_T GalileoE5astream;// '<S12>/Galileo E5a stream' 
  P_Galileosinglefrequencystrea_T GalileoE5stream;// '<S12>/Galileo E5 stream'
  P_Galileosinglefrequencystrea_T GalileoE1stream;// '<S12>/Galileo E1 stream'
  P_GPSsinglefrequencystream_GN_T GPSL5Stream;// '<S11>/GPS L5 Stream'
  P_GPSsinglefrequencystream_GN_T GPSL2CStream;// '<S11>/GPS L2C Stream'
  P_GPSsinglefrequencystream_GN_T GPSL1Stream;// '<S11>/GPS L1 Stream'
};

// Real-time Model Data Structure
struct tag_RTM_GNSSPreProcessingSing_T {
  const char_T * volatile errorStatus;

  //
  //  DataMapInfo:
  //  The following substructure contains information regarding
  //  structures generated in the model's C API.

  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
  } Timing;
};

// Function to get C API Model Mapping Static Info
extern const rtwCAPI_ModelMappingStaticInfo*
  GNSSPreProcessingSingleAntenna_GetCAPIStaticMap(void);

// Class declaration for model GNSSPreProcessingSingleAntenna
class GNSS_preprocessingModelClass final
{
  // public data and function members
 public:
  // Copy Constructor
  GNSS_preprocessingModelClass(GNSS_preprocessingModelClass const&) = delete;

  // Assignment Operator
  GNSS_preprocessingModelClass& operator= (GNSS_preprocessingModelClass const&)
    & = delete;

  // Move Constructor
  GNSS_preprocessingModelClass(GNSS_preprocessingModelClass &&) = delete;

  // Move Assignment Operator
  GNSS_preprocessingModelClass& operator= (GNSS_preprocessingModelClass &&) =
    delete;

  // Real-Time Model get method
  RT_MODEL_GNSSPreProcessingSin_T * getRTM();

  // External inputs
  ExtU_GNSSPreProcessingSingleA_T GNSSPreProcessingSingleAntenn_U;

  // External outputs
  ExtY_GNSSPreProcessingSingleA_T GNSSPreProcessingSingleAntenn_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  GNSS_preprocessingModelClass();

  // Destructor
  ~GNSS_preprocessingModelClass();

  // private data and function members
 private:
  // Block signals
  B_GNSSPreProcessingSingleAnte_T GNSSPreProcessingSingleAntenn_B;

  // Block states
  DW_GNSSPreProcessingSingleAnt_T GNSSPreProcessingSingleAnten_DW;

  // Tunable parameters
  static P_GNSSPreProcessingSingleAnte_T GNSSPreProcessingSingleAntenn_P;

  // private member function(s) for subsystem '<S3>/Calculate Day of Year'
  static void GNSSPreProce_CalculateDayofYear(real_T rtu_WNc, real_T rtu_TOW,
    real_T *rty_dayOfYear, DW_CalculateDayofYear_GNSSPre_T *localDW);

  // private member function(s) for subsystem '<S3>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles'
  void ConvertGNSSMeasuremendVariableT(const GNSS_Measurement
    *rtu_GNSSMeasurementVariable, const GNSS_Measurement_size
    *rtu_GNSSMeasurementVariab_DIMS1, const real_T rtu_user_pos_llh[3],
    GNSSMeasurementFixed *rty_GNSSMeasurementFixed, real_T
    *rty_sizeOfMesasurements);
  void GNSSPreProcess_binary_expand_op(real_T in1[3], const real_T in2_data[],
    const int32_T in2_size[2], int32_T in3, const real_T in4[3]);
  void calculate_Satellite_Elevation_A(const real_T user_Position_llh[3], const
    real_T satellite_Position_ecef_data[], const int32_T
    satellite_Position_ecef_size[2], real_T elevation_Angle_data[], int32_T
    *elevation_Angle_size, real_T azimuth_Angle_data[], int32_T
    *azimuth_Angle_size);

  // private member function(s) for subsystem '<S3>/GNSS Measurement Epoch Splitter'
  void GN_GNSSMeasurementEpochSplitter(const gnssraw_measurement_t
    *rtu_MeasurementEpochBus, real_T *rty_WNc, real_T *rty_TOW,
    gnssraw_measurement_t *rty_GpsMeasurementBus, gnssraw_measurement_t
    *rty_GalMeasurementBus);
  int32_T GNSSPrePr_combineVectorElements(const boolean_T x[40]);

  // private member function(s) for subsystem '<S26>/Calculate Satellite Clock Correction'
  void CalculateSatelliteClockCorrecti(real_T rtu_TOW, const
    gnssops_navigation_data *rtu_GnssNavBus, const gnssops_navigation_data_size *
    rtu_GnssNavBus_DIMS1, const real_T rtu_pseudorange[40], const int32_T
    *rtu_pseudorange_DIMS1, real_T rtu_enableSatClockCorr, const real_T
    rtu_delta_t_sv_EGNOS[110], B_CalculateSatelliteClockCorr_T *localB,
    DW_CalculateSatelliteClockCor_T *localDW);
  void GNSS_binary_expand_op_hmra2j23d(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const
    gnssops_navigation_data *in3, const gnssops_navigation_data_size *in4);
  void GNSSP_binary_expand_op_hmra2j23(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const
    gnssops_navigation_data *in3, const gnssops_navigation_data_size *in4);
  void GNSSPr_binary_expand_op_hmra2j2(real_T in1_data[], int32_T in1_size[2],
    const gnssops_navigation_data *in2, const gnssops_navigation_data_size *in3,
    const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[],
    const int32_T in5_size[2]);
  void GNSSPre_binary_expand_op_hmra2j(real_T in1_data[], int32_T in1_size[2],
    const gnssops_navigation_data *in2, const gnssops_navigation_data_size *in3,
    const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPreProce_binary_expand_op_h(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const
    gnssops_navigation_data *in3, const gnssops_navigation_data_size *in4, const
    real_T in5_data[], const int32_T in5_size[2]);
  void GNSSPreP_binary_expand_op_hmra2(real_T in1_data[], int32_T in1_size[2],
    const gnssops_navigation_data *in2, const gnssops_navigation_data_size *in3,
    const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[],
    const int32_T in5_size[2]);
  void GNSSPreProcessingSingleAn_minus(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void GNSSPrePr_binary_expand_op_hmra(real_T in1_data[], int32_T *in1_size,
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3[110],
    const gnssops_navigation_data *in4, const gnssops_navigation_data_size *in5);
  void GNSSPrePro_binary_expand_op_hmr(real_T in1_data[], int32_T *in1_size,
    const gnssops_navigation_data *in2, const gnssops_navigation_data_size *in3,
    const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPreProc_binary_expand_op_hm(real_T in1_data[], int32_T *in1_size,
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);

  // private member function(s) for subsystem '<S26>/Calculate Satellite Position and Velocity'
  void CalculateSatellitePositionandVe(real_T rtu_enableSatPosVelCalc, const
    real_T rtu_userPosLlh[3], const gnssops_navigation_data *rtu_GnssNavBus,
    const gnssops_navigation_data_size *rtu_GnssNavBus_DIMS1, const real_T
    rtu_timeEmissionCorrected[40], const int32_T
    *rtu_timeEmissionCorrected_DIMS1, const real_T rtu_delta_satPosECEF_EGNOS
    [330], B_CalculateSatellitePositiona_T *localB,
    DW_CalculateSatellitePosition_T *localDW);
  void GNSSPreProcessingSingle_minus_m(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void correct_Gps_Time_At_Week_Crosso(real_T b_time_data[], int32_T
    b_time_size[2]);
  void GNSSPreProcessingSingleAnt_plus(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void GNSSPreProc_binary_expand_op_n2(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPreProce_binary_expand_op_o(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSPreProce_binary_expand_op_c(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSPreProc_binary_expand_op_az(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSPreProcessingSingl_minus_m5(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void GN_Get_Kepler_Eccentric_Anomaly(const real_T t_k_data[], const int32_T
    t_k_size[2], const real_T Ephemeris_DELTA_N_data[], const int32_T
    Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[], const int32_T
    Ephemeris_M_0_size[2], const real_T Ephemeris_E_data[], const int32_T
    Ephemeris_E_size[2], const real_T Ephemeris_SQRT_A_data[], const int32_T
    Ephemeris_SQRT_A_size[2], real_T E_k_data[], int32_T E_k_size[2], real_T
    E_k_Dot_data[], int32_T E_k_Dot_size[2]);
  void GNSSPreProcessingSingleAnte_cos(real_T x_data[], const int32_T x_size[2]);
  void GNSSPreProcessingSingleAnte_sin(real_T x_data[], const int32_T x_size[2]);
  void GNSSPreProcessingSingle_times_a(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSPreProcessingSingleAnt_sqrt(real_T x_data[], const int32_T x_size[2]);
  void GNSSPreProcessingS_expand_atan2(const real_T a_data[], const int32_T
    a_size[2], const real_T b_data[], const int32_T b_size[2], real_T c_data[],
    int32_T c_size[2]);
  void GNSSPreProcessingSingleAn_atan2(const real_T y_data[], const int32_T
    y_size[2], const real_T x_data[], const int32_T x_size[2], real_T r_data[],
    int32_T r_size[2]);
  void GNSSPreProc_binary_expand_op_ar(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2]);
  void GNSSPreProc_binary_expand_op_a3(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2]);
  void GNSSPreProce_binary_expand_op_f(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2]);
  void GNSSPreProce_binary_expand_op_n(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2]);
  void GNSSPreProce_binary_expand_op_e(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2],
    const real_T in8_data[], const int32_T in8_size[2]);
  void binary_expand_o_ar5npdcmtcc01ob(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPreProcessingSingl_times_ax(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void binary_expand_op_ar5npdcmtcc01o(real_T in1_data[], const real_T in2_data[],
    const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2],
    const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[],
    const int32_T in5_size[2]);
  void binary_expand_op_ar5npdcmtcc01(real_T in1_data[], const int32_T in1_size
    [2], const real_T in2_data[], const int32_T in2_size[2], const real_T
    in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
  void G_binary_expand_op_ar5npdcmtcc0(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GN_binary_expand_op_ar5npdcmtcc(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2]);
  void GNS_binary_expand_op_ar5npdcmtc(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2],
    const real_T in8_data[], const int32_T in8_size[2], const real_T in9_data[],
    const int32_T in9_size[2]);
  void GNSS_binary_expand_op_ar5npdcmt(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2]);
  void GNSSP_binary_expand_op_ar5npdcm(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPr_binary_expand_op_ar5npdc(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPreProcessingSingleAn_times(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void GNSSPre_binary_expand_op_ar5npd(real_T in1_data[], const real_T in2_data[],
    const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2],
    const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[],
    const int32_T in5_size[2], const real_T in6_data[], const int32_T in6_size[2],
    const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[],
    const int32_T in8_size[2], const real_T in9_data[], const int32_T in9_size[2]);
  void GNSSPreP_binary_expand_op_ar5np(real_T in1_data[], const int32_T
    in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const
    real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2],
    const real_T in6_data[], const int32_T in6_size[2], const real_T in7_data[],
    const int32_T in7_size[2], const real_T in8_data[], const int32_T in8_size[2],
    const real_T in9_data[], const int32_T in9_size[2]);
  void GNSSPrePr_binary_expand_op_ar5n(real_T in1_data[], const int32_T
    in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const
    real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
  void GNSSPreProcessingSingleA_sqrt_g(real_T x_data[], const int32_T *x_size);
  void Get_Kepler_Satellite_Position_A(const real_T Ephemeris_C_rs_data[], const
    int32_T Ephemeris_C_rs_size[2], const real_T Ephemeris_DELTA_N_data[], const
    int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[], const
    int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_C_uc_data[], const
    int32_T Ephemeris_C_uc_size[2], const real_T Ephemeris_E_data[], const
    int32_T Ephemeris_E_size[2], const real_T Ephemeris_C_us_data[], const
    int32_T Ephemeris_C_us_size[2], const real_T Ephemeris_SQRT_A_data[], const
    int32_T Ephemeris_SQRT_A_size[2], const real_T Ephemeris_T_oe_data[], const
    int32_T Ephemeris_T_oe_size[2], const real_T Ephemeris_C_ic_data[], const
    int32_T Ephemeris_C_ic_size[2], const real_T Ephemeris_OMEGA_0_data[], const
    int32_T Ephemeris_OMEGA_0_size[2], const real_T Ephemeris_C_is_data[], const
    int32_T Ephemeris_C_is_size[2], const real_T Ephemeris_I_0_data[], const
    int32_T Ephemeris_I_0_size[2], const real_T Ephemeris_C_rc_data[], const
    int32_T Ephemeris_C_rc_size[2], const real_T Ephemeris_omega_data[], const
    int32_T Ephemeris_omega_size[2], const real_T Ephemeris_OMEGADOT_data[],
    const int32_T Ephemeris_OMEGADOT_size[2], const real_T Ephemeris_IDOT_data[],
    const int32_T Ephemeris_IDOT_size[2], const real_T T_emission_data[], const
    int32_T T_emission_size[2], const real_T user_position[3], real_T
    sv_pos_data[], int32_T sv_pos_size[2], real_T sv_vel_data[], int32_T
    sv_vel_size[2]);
  void GNSSPreProce_binary_expand_op_a(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3[330],
    const gnssops_navigation_data *in4, const gnssops_navigation_data_size *in5);

  // private member function(s) for subsystem '<S26>/Time Correction Carrierphase'
  void GNSS_TimeCorrectionCarrierphase(const real_T rtu_deltaTimeSV[40], const
    int32_T *rtu_deltaTimeSV_DIMS1, const real_T rtu_carrierphase[40], const
    int32_T *rtu_carrierphase_DIMS1, real_T rtu_Signal_in_Use,
    B_TimeCorrectionCarrierphase__T *localB, DW_TimeCorrectionCarrierphase_T
    *localDW);
  void GNSSPreProc_binary_expand_op_hj(real_T in1_data[], int32_T *in1_size,
    const real_T in2[40], const int32_T *in3, const real_T in4[40], const
    int32_T *in5, real_T in6);

  // private member function(s) for subsystem '<S26>/Time Correction Deltarange'
  void GNSSPr_TimeCorrectionDeltarange(const real_T rtu_drTimeCorr[40], const
    int32_T *rtu_drTimeCorr_DIMS1, const real_T rtu_deltarange[40], const
    int32_T *rtu_deltarange_DIMS1, B_TimeCorrectionDeltarange_GN_T *localB,
    DW_TimeCorrectionDeltarange_G_T *localDW);
  void GNSSPreProc_binary_expand_op_c1(real_T in1_data[], int32_T *in1_size,
    const real_T in2[40], const int32_T *in3, const real_T in4[40], const
    int32_T *in5);

  // private member function(s) for subsystem '<S26>/Time Correction Pseudorange'
  void GNSSP_TimeCorrectionPseudorange(const real_T rtu_deltaTimeSV[40], const
    int32_T *rtu_deltaTimeSV_DIMS1, const real_T rtu_pseudorange[40], const
    int32_T *rtu_pseudorange_DIMS1, B_TimeCorrectionPseudorange_G_T *localB,
    DW_TimeCorrectionPseudorange__T *localDW);
  void GNSSPreProc_binary_expand_op_cq(real_T in1_data[], int32_T *in1_size,
    const real_T in2[40], const int32_T *in3, const real_T in4[40], const
    int32_T *in5);

  // private member function(s) for subsystem '<S18>/Signal Noise Variance'
  static void GNSSPreProc_SignalNoiseVariance(const real_T
    rtu_carrierToNoiseRatio[40], const int32_T *rtu_carrierToNoiseRatio_DIMS1,
    boolean_T rtu_use_measured_variance, const real_T rtu_pr_sigma[40], const
    int32_T *rtu_pr_sigma_DIMS1, const real_T rtu_cp_sigma[40], const int32_T
    *rtu_cp_sigma_DIMS1, B_SignalNoiseVariance_GNSSPre_T *localB,
    DW_SignalNoiseVariance_GNSSPr_T *localDW);

  // private member function(s) for subsystem '<S11>/GPS L1 Stream'
  static void G_GPSsinglefrequencystream_Init(B_GPSsinglefrequencystream_GN_T
    *localB, P_GPSsinglefrequencystream_GN_T *localP);
  void GNSSPr_GPSsinglefrequencystream(boolean_T rtu_Enable, real_T
    rtu_timeOfWeekIn, const uint16_T rtu_SVID[40], const int32_T *rtu_SVID_DIMS1,
    const gnssops_navigation_data *rtu_GpsNavBus, const
    gnssops_navigation_data_size *rtu_GpsNavBus_DIMS1, const real_T
    rtu_pseudorange[40], const int32_T *rtu_pseudorange_DIMS1, const real_T
    rtu_deltarange[40], const int32_T *rtu_deltarange_DIMS1, const real_T
    rtu_carrierToNoiseRatio[40], const int32_T *rtu_carrierToNoiseRatio_DIMS1,
    const real_T rtu_userPosLlh[3], const real_T rtu_carrierphase[40], const
    int32_T *rtu_carrierphase_DIMS1, const real32_T rtu_locktime[40], const
    int32_T *rtu_locktime_DIMS1, const real_T rtu_base_position[3], boolean_T
    rtu_enable_SatPosVelCalc, boolean_T rtu_use_measured_cariance, const real_T
    rtu_pr_sigma[40], const int32_T *rtu_pr_sigma_DIMS1, const real_T
    rtu_cp_sigma[40], const int32_T *rtu_cp_sigma_DIMS1, real_T
    rtp_enable_SatClockCorr, B_GPSsinglefrequencystream_GN_T *localB,
    DW_GPSsinglefrequencystream_G_T *localDW, P_GPSsinglefrequencystream_GN_T
    *localP);

  // private member function(s) for subsystem '<S11>/Navigation Data Conversion GPS'
  static void GNS_NavigationDataConversionGPS(const gnssraw_gps_nav_t
    *rtu_GpsNavBus, B_NavigationDataConversionGPS_T *localB,
    DW_NavigationDataConversionGP_T *localDW);

  // private member function(s) for subsystem '<S23>/Calculate Differential Corrections'
  static void CalculateDifferentialCorre_Init(DW_CalculateDifferentialCorre_T
    *localDW);
  void CalculateDifferentialCorrection(const GNSS_Measurement
    *rtu_GpsMeasurementB, const GNSS_Measurement_size *rtu_GpsMeasurementB_DIMS1,
    const gnssops_navigation_data *rtu_gpsNavDataBusL1, const
    gnssops_navigation_data_size *rtu_gpsNavDataBusL1_DIMS1, const real_T
    rtu_userPosLlh[3], B_CalculateDifferentialCorrec_T *localB,
    DW_CalculateDifferentialCorre_T *localDW);
  void GNSSPreProcessingSingleAn_merge(int32_T idx_data[], uint16_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], uint16_T
    xwork_data[]);
  void GNSSPreProcessingSingleAnt_sort(uint16_T x_data[], const int32_T *x_size,
    int32_T idx_data[], int32_T *idx_size);
  void GNSSPreProcessingSin_do_vectors(const uint16_T a_data[], const int32_T
    *a_size, const real_T b_data[], const int32_T *b_size, uint16_T c_data[],
    int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
    int32_T *ib_size);
  void GNSSP_binary_expand_op_gd41yrno(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const
    gnssops_navigation_data *in3, const real_T in5_data[], const int32_T
    *in5_size);
  void GNSSPreProcessingSingl_minus_pc(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSPr_binary_expand_op_gd41yrn(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPre_binary_expand_op_gd41yr(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  boolean_T GNSSPreProcessingSingleAnte_any(const boolean_T x_data[], const
    int32_T x_size[2]);
  void GNSSPreProce_binary_expand_op_g(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSPreProcessingSingle_minus_p(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void GNSSPreP_binary_expand_op_gd41y(real_T in1_data[], int32_T in1_size[2],
    const gnssops_navigation_data *in2, const real_T in4_data[], const int32_T
    *in4_size, const real_T in5_data[], const int32_T in5_size[2], const real_T
    in6_data[], const int32_T in6_size[2], const real_T in7_data[], const
    int32_T in7_size[2]);
  void correct_Gps_Time_At_Week_Cros_l(real_T b_time_data[], int32_T
    b_time_size[2]);
  void GNSSPreProcessingSingleA_plus_l(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void GNSSPreProce_binary_expand_op_i(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPreProc_binary_expand_op_ki(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void Get_Kepler_Eccentric_Anomaly_m(const real_T t_k_data[], const int32_T
    t_k_size[2], const real_T Ephemeris_DELTA_N_data[], const int32_T
    Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[], const int32_T
    Ephemeris_M_0_size[2], const real_T Ephemeris_E_data[], const int32_T
    Ephemeris_E_size[2], const real_T Ephemeris_SQRT_A_data[], const int32_T
    Ephemeris_SQRT_A_size[2], real_T E_k_data[], int32_T E_k_size[2], real_T
    E_k_Dot_data[], int32_T E_k_Dot_size[2]);
  void GNSSPreProcessingSingleAn_cos_p(real_T x_data[], const int32_T x_size[2]);
  void GNSSPreProcessingSingleAn_sin_a(real_T x_data[], const int32_T x_size[2]);
  void GNSSPreProcessingSingl_times_iy(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSPreProcessingSingleA_sqrt_h(real_T x_data[], const int32_T x_size[2]);
  void GNSSPreProcessin_expand_atan2_i(const real_T a_data[], const int32_T
    a_size[2], const real_T b_data[], const int32_T b_size[2], real_T c_data[],
    int32_T c_size[2]);
  void GNSSPreProcessingSingle_atan2_e(const real_T y_data[], const int32_T
    y_size[2], const real_T x_data[], const int32_T x_size[2], real_T r_data[],
    int32_T r_size[2]);
  void GNSS_binary_expand_op_gd41yrnol(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2]);
  void GNSSPreProc_binary_expand_op_hr(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2]);
  void GNSSPreProc_binary_expand_op_hw(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2]);
  void GNSSPreProce_binary_expand_op_m(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2]);
  void GNSSPreProc_binary_expand_op_ap(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2],
    const real_T in8_data[], const int32_T in8_size[2]);
  void GNSSPrePro_binary_expand_op_a30(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPreProcessingSing_times_iyg(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void GNSSPreProc_binary_expand_op_pq(real_T in1_data[], const real_T in2_data[],
    const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2],
    const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[],
    const int32_T in5_size[2]);
  void GNSSPreProce_binary_expand_op_j(real_T in1_data[], const int32_T
    in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const
    real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
  void GNSSPreProce_binary_expand_op_d(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSPreProc_binary_expand_op_c3(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2]);
  void GNSSPreProce_binary_expand_op_k(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2],
    const real_T in8_data[], const int32_T in8_size[2], const real_T in9_data[],
    const int32_T in9_size[2], const real_T in10_data[], const int32_T
    in10_size[2]);
  void GNSSPreProce_binary_expand_op_p(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2]);
  void binary_expand_o_gd41yrnolhmfymc(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void binary_expand_op_gd41yrnolhmfym(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPreProcessingSingle_times_i(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void binary_expand_op_gd41yrnolhmfy(real_T in1_data[], const real_T in2_data[],
    const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2],
    const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[],
    const int32_T in5_size[2], const real_T in6_data[], const int32_T in6_size[2],
    const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[],
    const int32_T in8_size[2], const real_T in9_data[], const int32_T in9_size[2]);
  void G_binary_expand_op_gd41yrnolhmf(real_T in1_data[], const int32_T
    in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const
    real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2],
    const real_T in6_data[], const int32_T in6_size[2], const real_T in7_data[],
    const int32_T in7_size[2], const real_T in8_data[], const int32_T in8_size[2],
    const real_T in9_data[], const int32_T in9_size[2]);
  void GN_binary_expand_op_gd41yrnolhm(real_T in1_data[], const int32_T
    in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const
    real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
  void GNSSPreProcessingSingle_sqrt_hf(real_T x_data[], const int32_T *x_size);
  void Get_Kepler_Satellite_Position_g(const real_T Ephemeris_C_rs_data[], const
    int32_T Ephemeris_C_rs_size[2], const real_T Ephemeris_DELTA_N_data[], const
    int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[], const
    int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_C_uc_data[], const
    int32_T Ephemeris_C_uc_size[2], const real_T Ephemeris_E_data[], const
    int32_T Ephemeris_E_size[2], const real_T Ephemeris_C_us_data[], const
    int32_T Ephemeris_C_us_size[2], const real_T Ephemeris_SQRT_A_data[], const
    int32_T Ephemeris_SQRT_A_size[2], const real_T Ephemeris_T_oe_data[], const
    int32_T Ephemeris_T_oe_size[2], const real_T Ephemeris_C_ic_data[], const
    int32_T Ephemeris_C_ic_size[2], const real_T Ephemeris_OMEGA_0_data[], const
    int32_T Ephemeris_OMEGA_0_size[2], const real_T Ephemeris_C_is_data[], const
    int32_T Ephemeris_C_is_size[2], const real_T Ephemeris_I_0_data[], const
    int32_T Ephemeris_I_0_size[2], const real_T Ephemeris_C_rc_data[], const
    int32_T Ephemeris_C_rc_size[2], const real_T Ephemeris_omega_data[], const
    int32_T Ephemeris_omega_size[2], const real_T Ephemeris_OMEGADOT_data[],
    const int32_T Ephemeris_OMEGADOT_size[2], const real_T Ephemeris_IDOT_data[],
    const int32_T Ephemeris_IDOT_size[2], const real_T T_emission_data[], const
    int32_T T_emission_size[2], const real_T user_position[3], real_T
    sv_pos_data[], int32_T sv_pos_size[2], real_T sv_vel_data[], int32_T
    sv_vel_size[2]);
  void GNSSPrePr_binary_expand_op_gd41(const gnssops_navigation_data *in1, const
    real_T in3_data[], const int32_T *in3_size, const real_T in4_data[], const
    int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2],
    const real_T in6_data[], const int32_T in6_size[2], const real_T in7_data[],
    const int32_T in7_size[2], const real_T in8_data[], const int32_T in8_size[2],
    const real_T in9_data[], const int32_T in9_size[2], const real_T in10_data[],
    const int32_T in10_size[2], const real_T in11[3], real_T in12_data[],
    int32_T in12_size[2], real_T in13_data[], int32_T in13_size[2]);
  void GNSSPrePro_binary_expand_op_gd4(real_T in1_data[], int32_T *in1_size,
    const real_T in2_data[], const int32_T in3_data[], const int32_T *in3_size,
    const real_T in4_data[], const int32_T *in4_size);
  void GNSSPreProc_binary_expand_op_gd(real_T in1_data[], int32_T *in1_size,
    const real_T in2_data[], const int32_T in2_size[2]);

  // private member function(s) for subsystem '<S51>/Calculate Dualfrequency Correction with L1 and L2C'
  void CalculateDualfrequencyCorrectio(const GNSS_Measurement
    *rtu_measurementBusL1, const GNSS_Measurement_size
    *rtu_measurementBusL1_DIMS1, const GNSS_Measurement *rtu_measurementBusL2C,
    const GNSS_Measurement_size *rtu_measurementBusL2C_DIMS1, boolean_T
    rtu_enableDualFrequencyCorrecti, B_CalculateDualfrequencyCorre_T *localB,
    DW_CalculateDualfrequencyCorr_T *localDW);
  void GNSSPreProcessingS_do_vectors_e(const uint16_T a_data[], const int32_T
    *a_size, const uint16_T b_data[], const int32_T *b_size, uint16_T c_data[],
    int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
    int32_T *ib_size);

  // private member function(s) for subsystem '<S51>/Calculate Klobuchar Model Correction'
  static void CalculateKlobucharModelCorrecti(const real_T rtu_userPosLlh[3],
    const real_T rtu_elevationAngle[40], const int32_T *rtu_elevationAngle_DIMS1,
    const real_T rtu_azimuthAngle[40], const int32_T rtu_satPosEcef_DIMS1[2],
    real_T rtu_TOW, const gnssraw_gps_ion_t *rtu_GpsIonBus, boolean_T
    rtu_enableKlobucharCorrection, B_CalculateKlobucharModelCorr_T *localB,
    DW_CalculateKlobucharModelCor_T *localDW);

  // private member function(s) for subsystem '<S23>/Calculate Tropospheric Corrections'
  void CalculateTroposphericCorrection(real_T rtu_dayOfYear, boolean_T
    rtu_enableTroposphericCorrectio, const real_T rtu_userPosLlh[3], const
    real_T rtu_elevationAngle[40], const int32_T *rtu_elevationAngle_DIMS1,
    B_CalculateTroposphericCorrec_T *localB, DW_CalculateTroposphericCorre_T
    *localDW);
  real_T GNSSPreProcessingSingle_interp1(const real_T varargin_1[5], const
    real_T varargin_2[5], real_T varargin_3);
  void GNSSPreProcessingS_expand_power(const real_T a_data[], const int32_T
    *a_size, const real_T b_data[], const int32_T *b_size, real_T c_data[],
    int32_T *c_size);
  void GNSSPreProc_binary_expand_op_n5(real_T in1_data[], int32_T *in1_size,
    const real_T in2[40], int32_T in3, const real_T in4_data[], const int32_T
    *in4_size, const real_T in5_data[], const int32_T *in5_size, const real_T
    in6_data[], const int32_T *in6_size, const real_T in7_data[], const int32_T *
    in7_size, const real_T in8_data[], const int32_T *in8_size, const real_T
    in9_data[], const int32_T *in9_size, const real_T in10[40], const int32_T
    *in11, const real_T in12_data[], const int32_T *in12_size);

  // private member function(s) for subsystem '<S54>/Create Satellite Elevation Mask'
  void GN_CreateSatelliteElevationMask(const real_T rtu_userPosLlh[3], boolean_T
    rtu_userPos_isValid, const real_T rtu_satPosEcef[120], const int32_T
    rtu_satPosEcef_DIMS1[2], real_T rtu_elevationMaskingAngle, real_T
    *rty_removedSats, B_CreateSatelliteElevationMas_T *localB,
    DW_CreateSatelliteElevationMa_T *localDW);
  void GNSSPreProc_binary_expand_op_eu(real_T in1[3], const real_T in2[120],
    const int32_T in3[2], int32_T in4, const real_T in5[3]);
  void GNSSPrePro_binary_expand_op_eui(boolean_T in1_data[], int32_T *in1_size,
    const real_T in2[40], int32_T in3, real_T in4, const int8_T in5[2]);

  // private member function(s) for subsystem '<S55>/Apply Differential Correction Mask1'
  void ApplyDifferentialCorrectionMask(const GNSS_Measurement
    *rtu_GpsMeasurementBus, const GNSS_Measurement_size
    *rtu_GpsMeasurementBus_DIMS1, const real_T rtu_diffPseudorangeCorrections[40],
    const uint16_T rtu_diffCorrAvailableSvid[40], const int32_T
    *rtu_diffCorrAvailableSvidS1_DIM, boolean_T rtu_enableDiffCorrection, const
    real_T rtu_rtcm_base_position[3], boolean_T *rty_MeasurementCorrected,
    B_ApplyDifferentialCorrection_T *localB, DW_ApplyDifferentialCorrectio_T
    *localDW);
  void GNSSPreProcessingS_do_vectors_h(const uint16_T a_data[], const int32_T
    *a_size, const uint16_T b_data[], const int32_T *b_size, uint16_T c_data[],
    int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
    int32_T *ib_size);
  void GNSSPrePro_binary_expand_op_n0q(real_T in1_data[], int32_T *in1_size,
    const GNSS_Measurement *in2, const int32_T in4_data[], const int32_T
    *in4_size, const real_T in5[40], const int32_T in7_data[], const int32_T
    *in7_size);
  void GNSSPreProc_binary_expand_op_n0(real_T in1_data[], int32_T *in1_size,
    const GNSS_Measurement *in2, const int32_T in4_data[], const int32_T
    *in4_size, const real_T in5[40], const int32_T in7_data[], const int32_T
    *in7_size);

  // private member function(s) for subsystem '<S55>/Apply Elevation and NaN and Zero Mask'
  void ApplyElevationandNaNandZeroMask(const GNSS_Measurement
    *rtu_measurementFrequencyCorrect, const GNSS_Measurement_size
    *rtu_measurementFrequencyC_DIMS1, const boolean_T rtu_elevationMask[40],
    const int32_T *rtu_elevationMask_DIMS1, uint16_T *rty_nan_errCnt,
    B_ApplyElevationandNaNandZero_T *localB, DW_ApplyElevationandNaNandZer_T
    *localDW);
  void GNSSPreProcessingSingleAn_any_g(const boolean_T x_data[], const int32_T
    x_size[2], boolean_T y_data[], int32_T *y_size);
  void GNSSPreProcessingSingleA_any_gf(const boolean_T x_data[], const int32_T
    *x_size, boolean_T y_data[], int32_T *y_size);
  void GNSSPrePro_binary_expand_op_ixk(boolean_T in1_data[], int32_T *in1_size,
    const GNSS_Measurement *in2, const GNSS_Measurement_size *in3);
  void GNSSPreProc_binary_expand_op_ix(boolean_T in1_data[], int32_T *in1_size,
    const boolean_T in2[40], const int32_T *in3, const boolean_T in4_data[],
    const int32_T *in4_size, const GNSS_Measurement *in5, const
    GNSS_Measurement_size *in6);
  boolean_T GNSSPreProcessingSingle_any_gfc(const boolean_T x_data[], const
    int32_T *x_size);

  // private member function(s) for subsystem '<S11>/Simplify and Mask GPS Measurement Bus'
  void SimplifyandMaskGPSMeasurementBu(const gnssraw_measurement_t
    *rtu_GpsMeasurementBus, const gnssops_navigation_data *rtu_GpsNavBusReshaped,
    const gnssops_navigation_data_size *rtu_GpsNavBusReshaped_DIMS1, const
    parameters_gps_t *rtu_parameters_gps_Bus, B_SimplifyandMaskGPSMeasureme_T
    *localB, DW_SimplifyandMaskGPSMeasurem_T *localDW);
  void GNSSPreProcessingSingleAn_any_k(const boolean_T x[200], boolean_T y[40]);
  void GNSSPreProcessingSingl_eml_find(const boolean_T x[4], int32_T i_data[],
    int32_T i_size[2]);
  void GNSSPreProcessingSingle_merge_o(int32_T idx_data[], uint16_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], uint16_T
    xwork_data[]);
  void GNSSPreProcessingSingleA_sort_n(uint16_T x_data[], int32_T x_size[2],
    int32_T idx_data[], int32_T idx_size[2]);
  boolean_T GNSSPreProcessingSingleA_any_kl(const boolean_T x_data[], const
    int32_T *x_size);
  void GNSSPreProc_binary_expand_op_lw(real_T in1_data[], int32_T in1_size[2],
    const gnssraw_measurement_t *in2, const int8_T in3_data[], const int32_T
    in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const
    int32_T in5_data[], const int8_T in6_data[], const int32_T in6_size[2]);
  void GNSSPreProcessingSingle_any_kle(const boolean_T x_data[], const int32_T
    x_size[2], boolean_T y_data[], int32_T y_size[2]);
  void emxConvertDynamicMatrixToEmx_37(emxArray_real_T_37_GNSSPrePro_T *emx,
    const real_T data[37], const int32_T *size);
  void emxConvertStructToEmx_gnssops_n(emxArray__gnssops_navigation__T *emx,
    const gnssops_navigation_data *data, const gnssops_navigation_data_size
    *size);
  void GNSSPreProce_binary_expand_op_l(boolean_T in1_data[], int32_T *in1_size,
    const gnssops_navigation_data *in2, const gnssops_navigation_data_size *in3,
    const uint16_T in4[40], int32_T in6);
  void GNSSPreP_select_navigation_data(const emxArray__gnssops_navigation__T
    *navigation_data, const boolean_T mask_data[], const int32_T *mask_size,
    b_gnssops_navigation_data_GNS_T *navigation_data_selected);

  // private member function(s) for subsystem '<S12>/Galileo E1 stream'
  static void Galileosinglefrequencystre_Init(B_Galileosinglefrequencystrea_T
    *localB, P_Galileosinglefrequencystrea_T *localP);
  void GN_Galileosinglefrequencystream(boolean_T rtu_Enable, boolean_T
    rtu_E5_basedProcessing, real_T rtu_TOW, const uint16_T rtu_SVID[40], const
    int32_T *rtu_SVID_DIMS1, const gnssops_navigation_data
    *rtu_GAL_NavigationData_Bus, const gnssops_navigation_data_size
    *rtu_GAL_NavigationData_Bu_DIMS1, const real_T rtu_pseudorange[40], const
    int32_T *rtu_pseudorange_DIMS1, const real_T rtu_deltarange[40], const
    int32_T *rtu_deltarange_DIMS1, const real_T rtu_CN0[40], const int32_T
    *rtu_CN0_DIMS1, const real_T rtu_userPos_LLH[3], const real_T
    rtu_carrierPhase[40], const int32_T *rtu_carrierPhase_DIMS1, const real32_T
    rtu_locktime[40], const int32_T *rtu_locktime_DIMS1, const real_T
    rtu_basePos[3], boolean_T rtu_enable_SatPosVelCalc, boolean_T
    rtu_use_measured_variance, const real_T rtu_measured_pr_sigma[40], const
    int32_T *rtu_measured_pr_sigma_DIMS1, const real_T rtu_measured_cp_sigma[40],
    const int32_T *rtu_measured_cp_sigma_DIMS1, real_T rtp_enable_SatClockCorr,
    B_Galileosinglefrequencystrea_T *localB, DW_Galileosinglefrequencystre_T
    *localDW, P_Galileosinglefrequencystrea_T *localP);

  // private member function(s) for subsystem '<S12>/Navigation Data Conversion GAL'
  static void GNS_NavigationDataConversionGAL(const gnssraw_gal_nav_t
    *rtu_GAL_NAV_raw_Bus, B_NavigationDataConversionGAL_T *localB,
    DW_NavigationDataConversionGA_T *localDW);

  // private member function(s) for subsystem '<S70>/Calculate Differential Corrections'
  static void CalculateDifferentialCor_j_Init(DW_CalculateDifferentialCor_o_T
    *localDW);
  void CalculateDifferentialCorrecti_l(const GNSS_Measurement
    *rtu_GalMeasurementB, const GNSS_Measurement_size *rtu_GalMeasurementB_DIMS1,
    const gnssops_navigation_data *rtu_gpsNavDataBusL1, const
    gnssops_navigation_data_size *rtu_gpsNavDataBusL1_DIMS1, const real_T
    rtu_userPosLlh[3], B_CalculateDifferentialCorr_g_T *localB,
    DW_CalculateDifferentialCor_o_T *localDW);
  void GNSSPreProcessingSingle_merge_f(int32_T idx_data[], uint16_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], uint16_T
    xwork_data[]);
  void GNSSPreProcessingSingle_sort_ni(uint16_T x_data[], const int32_T *x_size,
    int32_T idx_data[], int32_T *idx_size);
  void GNSSPreProcessingS_do_vectors_c(const uint16_T a_data[], const int32_T
    *a_size, const real_T b_data[], const int32_T *b_size, uint16_T c_data[],
    int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
    int32_T *ib_size);
  void GNSS_binary_expand_op_espyy15uo(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const
    gnssops_navigation_data *in3, const real_T in5_data[], const int32_T
    *in5_size);
  void GNSSPreProcessingSingl_minus_d4(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSP_binary_expand_op_espyy15u(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPr_binary_expand_op_espyy15(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  boolean_T GNSSPreProcessingSingleA_any_gy(const boolean_T x_data[], const
    int32_T x_size[2]);
  void GNSSPreProc_binary_expand_op_es(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSPreProcessingSingle_minus_d(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void GNSSPre_binary_expand_op_espyy1(real_T in1_data[], int32_T in1_size[2],
    const gnssops_navigation_data *in2, const real_T in4_data[], const int32_T
    *in4_size, const real_T in5_data[], const int32_T in5_size[2], const real_T
    in6_data[], const int32_T in6_size[2], const real_T in7_data[], const
    int32_T in7_size[2]);
  void correct_Gps_Time_At_Week_Cros_i(real_T b_time_data[], int32_T
    b_time_size[2]);
  void GNSSPreProcessingSingleA_plus_o(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void GNSSPreProc_binary_expand_op_ks(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPreProc_binary_expand_op_nz(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void Get_Kepler_Eccentric_Anomaly_b(const real_T t_k_data[], const int32_T
    t_k_size[2], const real_T Ephemeris_DELTA_N_data[], const int32_T
    Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[], const int32_T
    Ephemeris_M_0_size[2], const real_T Ephemeris_E_data[], const int32_T
    Ephemeris_E_size[2], const real_T Ephemeris_SQRT_A_data[], const int32_T
    Ephemeris_SQRT_A_size[2], real_T E_k_data[], int32_T E_k_size[2], real_T
    E_k_Dot_data[], int32_T E_k_Dot_size[2]);
  void GNSSPreProcessingSingleAn_cos_g(real_T x_data[], const int32_T x_size[2]);
  void GNSSPreProcessingSingleAn_sin_g(real_T x_data[], const int32_T x_size[2]);
  void GNSSPreProcessingSingl_times_du(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSPreProcessingSingleA_sqrt_j(real_T x_data[], const int32_T x_size[2]);
  void GNSSPreProcessin_expand_atan2_d(const real_T a_data[], const int32_T
    a_size[2], const real_T b_data[], const int32_T b_size[2], real_T c_data[],
    int32_T c_size[2]);
  void GNSSPreProcessingSingle_atan2_g(const real_T y_data[], const int32_T
    y_size[2], const real_T x_data[], const int32_T x_size[2], real_T r_data[],
    int32_T r_size[2]);
  void GNS_binary_expand_op_espyy15uog(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2]);
  void GNSSPreProc_binary_expand_op_gm(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2]);
  void GNSSPreProc_binary_expand_op_du(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2]);
  void GNSSPreProc_binary_expand_op_ii(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2]);
  void GNSSPreProc_binary_expand_op_ld(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2],
    const real_T in8_data[], const int32_T in8_size[2]);
  void GNSSPreProc_binary_expand_op_ow(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPreProcessingSing_times_duk(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void GNSSPreProc_binary_expand_op_in(real_T in1_data[], const real_T in2_data[],
    const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2],
    const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[],
    const int32_T in5_size[2]);
  void GNSSPreProc_binary_expand_op_kd(real_T in1_data[], const int32_T
    in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const
    real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
  void GNSSPreProc_binary_expand_op_o1(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2]);
  void GNSSPreProc_binary_expand_op_dt(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2]);
  void GNSSPreProc_binary_expand_op_lf(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2],
    const real_T in8_data[], const int32_T in8_size[2], const real_T in9_data[],
    const int32_T in9_size[2], const real_T in10_data[], const int32_T
    in10_size[2]);
  void GNSSPreProc_binary_expand_op_ni(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2],
    const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[],
    const int32_T in6_size[2]);
  void GNSSPreProc_binary_expand_op_j4(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void binary_expand_o_espyy15uognnqac(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2], const real_T in3_data[],
    const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2]);
  void GNSSPreProcessingSingle_times_d(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void binary_expand_op_espyy15uognnqa(real_T in1_data[], const real_T in2_data[],
    const int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2],
    const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[],
    const int32_T in5_size[2], const real_T in6_data[], const int32_T in6_size[2],
    const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[],
    const int32_T in8_size[2], const real_T in9_data[], const int32_T in9_size[2]);
  void binary_expand_op_espyy15uognnq(real_T in1_data[], const int32_T in1_size
    [2], const real_T in2_data[], const int32_T in2_size[2], const real_T
    in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2],
    const real_T in6_data[], const int32_T in6_size[2], const real_T in7_data[],
    const int32_T in7_size[2], const real_T in8_data[], const int32_T in8_size[2],
    const real_T in9_data[], const int32_T in9_size[2]);
  void G_binary_expand_op_espyy15uognn(real_T in1_data[], const int32_T
    in1_size[2], const real_T in2_data[], const int32_T in2_size[2], const
    real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const
    int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
  void GNSSPreProcessingSingle_sqrt_ja(real_T x_data[], const int32_T *x_size);
  void Get_Kepler_Satellite_Position_j(const real_T Ephemeris_C_rs_data[], const
    int32_T Ephemeris_C_rs_size[2], const real_T Ephemeris_DELTA_N_data[], const
    int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[], const
    int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_C_uc_data[], const
    int32_T Ephemeris_C_uc_size[2], const real_T Ephemeris_E_data[], const
    int32_T Ephemeris_E_size[2], const real_T Ephemeris_C_us_data[], const
    int32_T Ephemeris_C_us_size[2], const real_T Ephemeris_SQRT_A_data[], const
    int32_T Ephemeris_SQRT_A_size[2], const real_T Ephemeris_T_oe_data[], const
    int32_T Ephemeris_T_oe_size[2], const real_T Ephemeris_C_ic_data[], const
    int32_T Ephemeris_C_ic_size[2], const real_T Ephemeris_OMEGA_0_data[], const
    int32_T Ephemeris_OMEGA_0_size[2], const real_T Ephemeris_C_is_data[], const
    int32_T Ephemeris_C_is_size[2], const real_T Ephemeris_I_0_data[], const
    int32_T Ephemeris_I_0_size[2], const real_T Ephemeris_C_rc_data[], const
    int32_T Ephemeris_C_rc_size[2], const real_T Ephemeris_omega_data[], const
    int32_T Ephemeris_omega_size[2], const real_T Ephemeris_OMEGADOT_data[],
    const int32_T Ephemeris_OMEGADOT_size[2], const real_T Ephemeris_IDOT_data[],
    const int32_T Ephemeris_IDOT_size[2], const real_T T_emission_data[], const
    int32_T T_emission_size[2], const real_T user_position[3], real_T
    sv_pos_data[], int32_T sv_pos_size[2], real_T sv_vel_data[], int32_T
    sv_vel_size[2]);
  void GNSSPreP_binary_expand_op_espyy(const gnssops_navigation_data *in1, const
    real_T in3_data[], const int32_T *in3_size, const real_T in4_data[], const
    int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2],
    const real_T in6_data[], const int32_T in6_size[2], const real_T in7_data[],
    const int32_T in7_size[2], const real_T in8_data[], const int32_T in8_size[2],
    const real_T in9_data[], const int32_T in9_size[2], const real_T in10_data[],
    const int32_T in10_size[2], const real_T in11[3], real_T in12_data[],
    int32_T in12_size[2], real_T in13_data[], int32_T in13_size[2]);
  void GNSSPrePr_binary_expand_op_espy(real_T in1_data[], int32_T *in1_size,
    const real_T in2_data[], const int32_T in3_data[], const int32_T *in3_size,
    const real_T in4_data[], const int32_T *in4_size);
  void GNSSPrePro_binary_expand_op_esp(real_T in1_data[], int32_T *in1_size,
    const real_T in2_data[], const int32_T in2_size[2]);

  // private member function(s) for subsystem '<S70>/Calculate Tropospheric Corrections'
  void CalculateTroposphericCorrecti_h(real_T rtu_dayOfYear, boolean_T
    rtu_enableTroposphericCorrectio, const real_T rtu_userPos_LLH[3], const
    real_T rtu_elevationAngle[40], const int32_T *rtu_elevationAngle_DIMS1,
    B_CalculateTroposphericCorr_h_T *localB, DW_CalculateTroposphericCor_c_T
    *localDW);
  real_T GNSSPreProcessingSing_interp1_f(const real_T varargin_1[5], const
    real_T varargin_2[5], real_T varargin_3);
  void GNSSPreProcessin_expand_power_g(const real_T a_data[], const int32_T
    *a_size, const real_T b_data[], const int32_T *b_size, real_T c_data[],
    int32_T *c_size);
  void GNSSPreProc_binary_expand_op_fi(real_T in1_data[], int32_T *in1_size,
    const real_T in2[40], int32_T in3, const real_T in4_data[], const int32_T
    *in4_size, const real_T in5_data[], const int32_T *in5_size, const real_T
    in6_data[], const int32_T *in6_size, const real_T in7_data[], const int32_T *
    in7_size, const real_T in8_data[], const int32_T *in8_size, const real_T
    in9_data[], const int32_T *in9_size, const real_T in10[40], const int32_T
    *in11, const real_T in12_data[], const int32_T *in12_size);

  // private member function(s) for subsystem '<S111>/Apply Differential Correction Mask1'
  void ApplyDifferentialCorrectionMa_b(const GNSS_Measurement
    *rtu_GpsMeasurementBus, const GNSS_Measurement_size
    *rtu_GpsMeasurementBus_DIMS1, const real_T rtu_diffPseudorangeCorrections[40],
    const uint16_T rtu_diffCorrAvailableSvid[40], const int32_T
    *rtu_diffCorrAvailableSvidS1_DIM, boolean_T rtu_enableDiffCorrection, const
    real_T rtu_rtcm_base_position[3], boolean_T *rty_MeasurementCorrected,
    B_ApplyDifferentialCorrecti_e_T *localB, DW_ApplyDifferentialCorrect_l_T
    *localDW);
  void GNSSPreProcessingS_do_vectors_i(const uint16_T a_data[], const int32_T
    *a_size, const uint16_T b_data[], const int32_T *b_size, uint16_T c_data[],
    int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
    int32_T *ib_size);
  void GNSSPrePro_binary_expand_op_ok0(real_T in1_data[], int32_T *in1_size,
    const GNSS_Measurement *in2, const int32_T in4_data[], const int32_T
    *in4_size, const real_T in5[40], const int32_T in7_data[], const int32_T
    *in7_size);
  void GNSSPreProc_binary_expand_op_ok(real_T in1_data[], int32_T *in1_size,
    const GNSS_Measurement *in2, const int32_T in4_data[], const int32_T
    *in4_size, const real_T in5[40], const int32_T in7_data[], const int32_T
    *in7_size);

  // private member function(s) for subsystem '<S12>/Simplify and Mask GAL Measurement Bus'
  void SimplifyandMaskGALMeasurementBu(const gnssraw_measurement_t
    *rtu_GAL_Measurement_Bus, const gnssops_navigation_data
    *rtu_GAL_NavigationData_Bus, const gnssops_navigation_data_size
    *rtu_GAL_NavigationData_Bu_DIMS1, const parameters_galileo_t
    *rtu_parameters_galileo, B_SimplifyandMaskGALMeasureme_T *localB,
    DW_SimplifyandMaskGALMeasurem_T *localDW);
  void GNSSPreProcessingSingleAn_any_h(const boolean_T x[200], boolean_T y[40]);
  void GNSSPreProcessingSin_eml_find_i(const boolean_T x[5], int32_T i_data[],
    int32_T i_size[2]);
  void GNSSPreProcessingSingle_merge_i(int32_T idx_data[], uint16_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], uint16_T
    xwork_data[]);
  void GNSSPreProcessingSingleA_sort_d(uint16_T x_data[], int32_T x_size[2],
    int32_T idx_data[], int32_T idx_size[2]);
  boolean_T GNSSPreProcessingSingleA_any_hu(const boolean_T x_data[], const
    int32_T *x_size);
  void GNSSPrePro_binary_expand_op_pmg(real_T in1_data[], int32_T in1_size[2],
    const gnssraw_measurement_t *in2, const int8_T in3_data[], const int32_T
    in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const
    int32_T in5_data[], const int8_T in6_data[], const int32_T in6_size[2]);
  void GNSSPreProcessingSingle_any_hu1(const boolean_T x_data[], const int32_T
    x_size[2], boolean_T y_data[], int32_T y_size[2]);
  void emxConvertDynamicMatrixToEmx__n(emxArray_real_T_37_GNSSPrePro_T *emx,
    const real_T data[37], const int32_T *size);
  void emxConvertStructToEmx_gnssops_p(emxArray__gnssops_navigation__T *emx,
    const gnssops_navigation_data *data, const gnssops_navigation_data_size
    *size);
  void GNSSPreProc_binary_expand_op_pm(boolean_T in1_data[], int32_T *in1_size,
    const gnssops_navigation_data *in2, const gnssops_navigation_data_size *in3,
    const uint16_T in4[40], int32_T in6);
  void GNSSPr_select_navigation_data_a(const emxArray__gnssops_navigation__T
    *navigation_data, const boolean_T mask_data[], const int32_T *mask_size,
    b_gnssops_navigation_data_GNS_T *navigation_data_selected);

  // private member function(s) for subsystem '<Root>'
  void GNSSPreProcessing_do_vectors_ig(const uint16_T a_data[], const int32_T
    *a_size, const uint16_T b_data[], const int32_T *b_size, uint16_T c_data[],
    int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
    int32_T *ib_size);
  void GNSSPrePr_binary_expand_op_fr3p(GNSS_Measurement *in1, const int32_T
    in3_data[], const int32_T *in3_size, const real_T in4[40], const real_T in6
    [40], const int32_T in8_data[], const int32_T *in8_size);
  boolean_T GNSSPreProcessingSingleAn_any_a(const real_T x_data[], const int32_T
    *x_size);
  void GNSSPreProce_calcCorrection_g0j(const real_T prf1_data[], const uint16_T
    PRN1_data[], const int32_T *PRN1_size, const real_T prf2_data[], const
    uint16_T PRN2_data[], const int32_T *PRN2_size, real_T Corr_f1_data[],
    int32_T *Corr_f1_size);
  void GNSSPreProcessin_calcCorrection(const real_T prf1_data[], const uint16_T
    PRN1_data[], const int32_T *PRN1_size, const real_T prf2_data[], const
    uint16_T PRN2_data[], const int32_T *PRN2_size, real_T Corr_f1_data[],
    int32_T *Corr_f1_size);
  boolean_T GNSSPreProcessingSingleA_any_aa(const boolean_T x_data[], const
    int32_T *x_size);
  void GNSSPreProcess_calcCorrection_g(const real_T prf1_data[], const uint16_T
    PRN1_data[], const int32_T *PRN1_size, const real_T prf2_data[], const
    uint16_T PRN2_data[], const int32_T *PRN2_size, real_T Corr_f1_data[],
    int32_T *Corr_f1_size);
  void GNSSPreProces_calcCorrection_g0(const real_T prf1_data[], const uint16_T
    PRN1_data[], const int32_T *PRN1_size, const real_T prf2_data[], const
    uint16_T PRN2_data[], const int32_T *PRN2_size, real_T Corr_f1_data[],
    int32_T *Corr_f1_size);
  void GNSSPreProcessingSingleAn_any_m(const boolean_T x_data[], const int32_T
    x_size[2], boolean_T y_data[], int32_T *y_size);
  void GNSSPreProcessingSingleA_any_m4(const boolean_T x_data[], const int32_T
    *x_size, boolean_T y_data[], int32_T *y_size);
  void GNSSPrePro_binary_expand_op_fr3(boolean_T in1_data[], int32_T *in1_size,
    const boolean_T in2[40], int32_T in3, const boolean_T in4_data[], const
    int32_T *in4_size, const boolean_T in5_data[], const int32_T *in5_size,
    const boolean_T in6_data[], const int32_T *in6_size, const boolean_T
    in7_data[], const int32_T *in7_size, const boolean_T in8_data[], const
    int32_T *in8_size);
  void emxConvertDynamicMatrixToEmx_40(emxArray_real_T_40x3_GNSSPreP_T *emx,
    const real_T data[120], const int32_T size[2]);
  void emxConvertDynamicMatrixToEmx__f(emxArray_uint16_T_40_GNSSPreP_T *emx,
    const uint16_T data[40], const int32_T *size);
  void emxConvertDynamicMatrixToEmx_fr(emxArray_real_T_40_GNSSPrePro_T *emx,
    const real_T data[40], const int32_T *size);
  void emxConvertDynamicMatrixToEm_fr3(emxArray_real32_T_40_GNSSPreP_T *emx,
    const real32_T data[40], const int32_T *size);
  void emxConvertStructToEmx_GNSS_Meas(emxArray__GNSS_Measurement_GN_T *emx,
    const GNSS_Measurement *data, const GNSS_Measurement_size *size);
  void GNSSPreProcessingS_mergeMyBus_c(const emxArray__GNSS_Measurement_GN_T
    *varargin_1, const emxArray__GNSS_Measurement_GN_T *varargin_2,
    s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T *outputBus);
  real_T GNSSPreProces_GGTO_delta_T_GNSS(real_T GalGstGps_Bus_A_1G, real_T
    GalGstGps_Bus_A_0G, uint32_T GalGstGps_Bus_t_oG, uint8_T GalGstGps_Bus_WN_oG,
    real_T GSTTOW, real_T GSTWNc);
  void GNSSPreProcessingSingl_isMember(const uint16_T a_data[], const int32_T
    *a_size, boolean_T tf_data[], int32_T *tf_size);
  void GNSSPreProcessingSin_isMember_d(const uint16_T a_data[], const int32_T
    *a_size, boolean_T tf_data[], int32_T *tf_size);
  real_T GNSSPreProcessingSingleAnt_norm(const real_T x[3]);
  void GNSSPre_binary_expand_op_fr3pus(real_T in1_data[], int32_T in2, const
    real_T in3_data[], const real_T in4_data[], const int32_T in4_size[2], const
    real_T in5[4]);
  void GNSSPreP_binary_expand_op_fr3pu(real_T in1_data[], const int32_T
    in1_size[2], int32_T in2, const real_T in3_data[], const int32_T in3_size[2],
    const real_T in4[4]);
  void GNSSPreProcessingSi_getJacobi_o(const real_T satellite_position_data[],
    const int32_T satellite_position_size[2], const real_T pseudorange_data[],
    const int32_T *pseudorange_size, const real_T user_state[4], real_T
    delta_rho_data[], int32_T *delta_rho_size, real_T H_data[], int32_T H_size[2],
    real_T residuum[4]);
  real_T GNSSPreProcessingSingl_xnrm2_ks(int32_T n, const real_T x_data[],
    int32_T ix0);
  void GNSSPreProcessingSin_qrsolve_g2(const real_T A_data[], const int32_T
    A_size[2], const real_T B_data[], const int32_T *B_size, real_T Y[4]);
  void GNSSPreProcessing_mldivide_e2x2(const real_T A_data[], const int32_T
    A_size[2], real_T B_data[], int32_T *B_size);
  void GNSSPreProcessingSingleA_plus_f(real_T in1[4], const real_T in2_data[],
    const int32_T *in2_size);
  void G_binary_expand_op_fr3pusohsll5(real_T in1_data[], int32_T in2, const
    real_T in3_data[], const real_T in4_data[], const int32_T in4_size[2], const
    real_T in5[5]);
  void GN_binary_expand_op_fr3pusohsll(real_T in1_data[], const int32_T
    in1_size[2], int32_T in2, const real_T in3_data[], const int32_T in3_size[2],
    const real_T in4[5]);
  void binary_expand_op_fr3pusohsll5rb(real_T in1_data[], int32_T in2, const
    real_T in3_data[], const real_T in4_data[], const int32_T in4_size[2], const
    real_T in5[5]);
  void binary_expand_op_fr3pusohsll5r(real_T in1_data[], const int32_T in1_size
    [2], int32_T in2, const real_T in3_data[], const int32_T in3_size[2], const
    real_T in4[5]);
  void GNSSPreProc_getJacobiMultiKonst(const real_T
    satellite_position_sys1_data[], const int32_T satellite_position_sys1_size[2],
    const real_T satellite_position_sys2_data[], const int32_T
    satellite_position_sys2_size[2], const real_T pseudorange_sys1_data[], const
    int32_T *pseudorange_sys1_size, const real_T pseudorange_sys2_data[], const
    int32_T *pseudorange_sys2_size, const real_T user_state[5], real_T
    delta_rho_data[], int32_T *delta_rho_size, real_T H_data[], int32_T H_size[2],
    real_T residuum[5]);
  real_T GNSSPreProcessingSingle_xnrm2_k(int32_T n, const real_T x_data[],
    int32_T ix0);
  void GNSSPreProcessingSing_qrsolve_g(const real_T A_data[], const int32_T
    A_size[2], const real_T B_data[], const int32_T *B_size, real_T Y[5]);
  void GNSSPreProcessingS_mldivide_e2x(const real_T A_data[], const int32_T
    A_size[2], real_T B_data[], int32_T *B_size);
  void GNSSPreProcessingSingle_plus_fr(real_T in1[5], const real_T in2_data[],
    const int32_T *in2_size);
  real_T GNSSPr_calc_delta_T_GNSS_system(const real_T
    gnss_measurement_satellite_posi[], const int32_T
    gnss_measurement_satellite_po_0[2], const uint16_T
    gnss_measurement_PRN_data[], const int32_T *gnss_measurement_PRN_size, const
    real_T gnss_measurement_pseudorange_da[], const int32_T
    *gnss_measurement_pseudorange_si);
  void GNSSPreProcessing_mergeMyBus_cs(const s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T
    *varargin_1, const emxArray__GNSS_Measurement_GN_T *varargin_2,
    s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T *outputBus);
  void GNSSPreProcessingSin_mergeMyBus(const emxArray__GNSS_Measurement_GN_T
    *varargin_1, const emxArray__GNSS_Measurement_GN_T *varargin_2, const
    emxArray__GNSS_Measurement_GN_T *varargin_3, s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T
    *outputBus);
  void GNS_binary_expand_op_fr3pusohsl(real_T in1[3], const real_T in2_data[],
    const int32_T in2_size[2]);
  void calculate_Satellite_Elevation_n(const real_T user_Position_llh[3], const
    real_T satellite_Position_ecef_data[], const int32_T
    satellite_Position_ecef_size[2], real_T *elevation_Angle, real_T
    *azimuth_Angle);
  boolean_T GNSSPreProcessingSingleAn_any_l(const boolean_T x[40]);
  void GNSSPreProcessingSin_eml_find_l(const boolean_T x[40], int32_T i_data[],
    int32_T i_size[2]);
  void GNSSPreProcessingSi_eml_find_le(const boolean_T x_data[], const int32_T
    x_size[2], int32_T i_data[], int32_T i_size[2]);
  void GNSSPreProcessingSingle_merge_a(int32_T idx_data[], real_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T
    xwork_data[]);
  void GNSSPreProcessingSingle_sort_np(real_T x_data[], int32_T x_size[2],
    int32_T idx_data[], int32_T idx_size[2]);
  void GNSSPreProcessingS_eml_find_lei(const boolean_T x_data[], const int32_T
    *x_size, int32_T i_data[], int32_T *i_size);
  void GNSSPreProcessing_eml_find_leix(const real_T x_data[], const int32_T
    x_size[2], int32_T i_data[], int32_T i_size[2]);
  void GNSSPreProcessin_nullAssignment(real_T x_data[], int32_T x_size[2], const
    int32_T idx_data[], const int32_T idx_size[2]);
  void GNSSPreProcessingSing_getJacobi(const real_T satellite_position_data[],
    const int32_T satellite_position_size[2], const real_T pseudorange_data[],
    const int32_T *pseudorange_size, const real_T user_state[4], real_T
    delta_rho_data[], int32_T *delta_rho_size, real_T H_data[], int32_T H_size[2],
    real_T residuum[4]);
  real_T GNSSPreProcessingSingleAn_xnrm2(int32_T n, const real_T x_data[],
    int32_T ix0);
  void GNSSPreProcessingSingle_qrsolve(const real_T A_data[], const int32_T
    A_size[2], const real_T B_data[], const int32_T *B_size, real_T Y[4]);
  void GNSSPreProcessingSin_mldivide_a(const real_T A_data[], const int32_T
    A_size[2], real_T B_data[], int32_T *B_size);
  void GNSSPr_binary_expand_op_fr3puso(real_T in1[3], real_T in2, real_T in3,
    const int8_T in4[3], real_T in5, real_T in6, const int8_T in7[3], const
    real_T in8[4], const real_T in9_data[], const int32_T in9_size[2], int32_T
    in10, const int32_T in11_size[2]);
  void GNSSPreProcessingSingleAnte_inv(const real_T x_data[], const int32_T
    x_size[2], real_T y_data[], int32_T y_size[2]);
  void GNSSP_binary_expand_op_fr3pusoh(real_T in1[3], const real_T in2[4], const
    real_T in3_data[], const int32_T in3_size[2], int32_T in4, const int32_T
    in5_size[2]);
  void GNSSPreProcessingSin_mldivide_d(const real_T A[16], const real_T B_data[],
    const int32_T B_size[2], real_T Y_data[], int32_T Y_size[2]);
  void GNSSPreProcessingSingle_minus_f(real_T in1_data[], int32_T in1_size[2],
    const real_T in2_data[], const int32_T in2_size[2]);
  void GNSSPreProcessingSingleA_mtimes(const real_T A_data[], const int32_T
    A_size[2], const real_T B_data[], real_T C_data[], int32_T *C_size);
  real_T GNSSPreProcessingSingle_maximum(const real_T x_data[], const int32_T
    *x_size);
  void GNSSPreProces_RAIM_detect_Fault(const real_T
    e_GNSS_Measurement_satellite_po[], const int32_T
    e_GNSS_Measurement_satellite__0[2], const real_T
    e_GNSS_Measurement_pseudorange_[], const int32_T
    *e_GNSS_Measurement_pseudorang_0, const real_T
    e_GNSS_Measurement_variance_pse[], const real_T user_position_llh[3], real_T
    clockerror, const real_T b_table_chi_square[80], real_T m, real_T
    *test_statistic, real_T *threshold, real_T *HPL, real_T H_data[], int32_T
    H_size[2], real_T W_data[], int32_T W_size[2], real_T y_data[], int32_T
    *y_size);
  void GNSSPreProcessingSingleA_sqrt_f(real_T x_data[], const int32_T x_size[2]);
  void GNSSPreProcessingSingl_mtimes_c(const real_T A_data[], const int32_T
    A_size[2], const real_T B_data[], const int32_T B_size[2], real_T C_data[],
    int32_T C_size[2]);
  void GNSSPreProcessingSingle_xgemv_i(int32_T m, int32_T n, const real_T
    A_data[], int32_T ia0, int32_T lda, const real_T x_data[], int32_T ix0,
    real_T y[4]);
  void GNSSPreProcessingSingle_xgerc_i(int32_T m, int32_T n, real_T alpha1,
    int32_T ix0, const real_T y[4], real_T A_data[], int32_T ia0, int32_T lda);
  void GNSSPreProcessingSingl_xgeqrf_j(real_T A_data[], const int32_T A_size[2],
    real_T tau_data[], int32_T *tau_size);
  real_T GNSSPreProcessingSingle_xnrm2_a(int32_T n, const real_T x_data[],
    int32_T ix0);
  void GNSSPreProcessingSingleAn_xgemv(int32_T m, int32_T n, const real_T
    A_data[], int32_T ia0, int32_T lda, const real_T x_data[], int32_T ix0,
    real_T y_data[]);
  void GNSSPreProcessingSingleAn_xgerc(int32_T m, int32_T n, real_T alpha1,
    int32_T ix0, const real_T y_data[], real_T A_data[], int32_T ia0, int32_T
    lda);
  void GNSSPreProcessingSingleA_xgeqrf(real_T A_data[], const int32_T A_size[2],
    real_T tau_data[], int32_T *tau_size);
  void GNSSPreProcessingSingleAnten_qr(const real_T A_data[], const int32_T
    A_size[2], real_T Q_data[], int32_T Q_size[2], real_T R_data[], int32_T
    R_size[2]);
  real_T GNSSPreProcessingSingleA_norm_j(const real_T x_data[], const int32_T
    *x_size);
  void GNSSPreProc_binary_expand_op_fr(real_T in1_data[], const int32_T
    in1_size[2], int32_T in2, const real_T in3_data[], const int32_T *in3_size,
    real_T in4, const real_T in5_data[], const int32_T in5_size[2]);
  real_T GNSSPreProcessingSingleAnte_sum(const real_T x_data[], const int32_T
    x_size[2]);
  void GNSSPreProcessingSingleA_sort_e(real_T x_data[], int32_T x_size[2],
    int32_T idx_data[], int32_T idx_size[2]);

  // Real-Time Model
  RT_MODEL_GNSSPreProcessingSin_T GNSSPreProcessingSingleAnten_M;
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
//  '<Root>' : 'GNSSPreProcessingSingleAntenna'
//  '<S1>'   : 'GNSSPreProcessingSingleAntenna/Calculate User Position with LMS'
//  '<S2>'   : 'GNSSPreProcessingSingleAntenna/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'
//  '<S3>'   : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna'
//  '<S4>'   : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Calculate Day of Year'
//  '<S5>'   : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/ConvertGNSSMeasuremendVariableToFixed_CalcAngles'
//  '<S6>'   : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/ConvertGNSSMeasuremendVariableToFixed_CalcAngles1'
//  '<S7>'   : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/ConvertGNSSMeasuremendVariableToFixed_CalcAngles2'
//  '<S8>'   : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Dummy GNSS Measurement'
//  '<S9>'   : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Fuse'
//  '<S10>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GNSS Measurement Epoch Splitter'
//  '<S11>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS'
//  '<S12>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo'
//  '<S13>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS'
//  '<S14>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/MATLAB Function'
//  '<S15>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Merge GNSS Measurement'
//  '<S16>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Mode Switch'
//  '<S17>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/mergeDiffCorrections'
//  '<S18>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream'
//  '<S19>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream'
//  '<S20>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream'
//  '<S21>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS Parameter Logic'
//  '<S22>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Navigation Data Conversion GPS'
//  '<S23>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections'
//  '<S24>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Simplify and Mask GPS Measurement Bus'
//  '<S25>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Enable Satellite Position and Velocity Calculation'
//  '<S26>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction'
//  '<S27>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Signal Noise Variance'
//  '<S28>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S29>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S30>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S31>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S32>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S33>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Enable Satellite Position and Velocity Calculation'
//  '<S34>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction'
//  '<S35>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Signal Noise Variance'
//  '<S36>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S37>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S38>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S39>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S40>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S41>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Enable Satellite Position and Velocity Calculation'
//  '<S42>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction'
//  '<S43>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Signal Noise Variance'
//  '<S44>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S45>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S46>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S47>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S48>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S49>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS Parameter Logic/MATLAB Function1'
//  '<S50>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Differential Corrections'
//  '<S51>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Ionospheric Corrections'
//  '<S52>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Tropospheric Corrections'
//  '<S53>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Compare To Constant1'
//  '<S54>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Create Elevation Mask and calculate Angles'
//  '<S55>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Satellite Masking'
//  '<S56>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Ionospheric Corrections/Calculate Dualfrequency Correction with L1 and L2C'
//  '<S57>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Ionospheric Corrections/Calculate Klobuchar Model Correction'
//  '<S58>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Ionospheric Corrections/Calculate Wide Lane Combination'
//  '<S59>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Ionospheric Corrections/MATLAB Function'
//  '<S60>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Create Elevation Mask and calculate Angles/Create Satellite Elevation Mask'
//  '<S61>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Satellite Masking/Apply Differential Correction Mask1'
//  '<S62>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Satellite Masking/Apply Elevation and NaN and Zero Mask'
//  '<S63>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Satellite Masking/Apply Non Dual Frequency GPS Satellite Mask'
//  '<S64>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/GAL Parameter Logic1'
//  '<S65>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream'
//  '<S66>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream'
//  '<S67>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream'
//  '<S68>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream'
//  '<S69>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Navigation Data Conversion GAL'
//  '<S70>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections'
//  '<S71>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Simplify and Mask GAL Measurement Bus'
//  '<S72>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/GAL Parameter Logic1/MATLAB Function'
//  '<S73>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/GAL Parameter Logic1/MATLAB Function1'
//  '<S74>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Enable Satellite Position and Velocity Calculation'
//  '<S75>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction'
//  '<S76>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Signal Noise Variance'
//  '<S77>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S78>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S79>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S80>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S81>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S82>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Enable Satellite Position and Velocity Calculation'
//  '<S83>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction'
//  '<S84>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Signal Noise Variance'
//  '<S85>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S86>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S87>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S88>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S89>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S90>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Enable Satellite Position and Velocity Calculation'
//  '<S91>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction'
//  '<S92>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Signal Noise Variance'
//  '<S93>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S94>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S95>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S96>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S97>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S98>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Enable Satellite Position and Velocity Calculation'
//  '<S99>'  : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction'
//  '<S100>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Signal Noise Variance'
//  '<S101>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S102>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S103>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S104>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S105>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S106>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Calculate Differential Corrections'
//  '<S107>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Calculate Ionospheric Corrections'
//  '<S108>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Calculate Tropospheric Corrections'
//  '<S109>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Compare To Constant'
//  '<S110>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Create Elevation Mask and calculate Angles'
//  '<S111>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Satellite Masking'
//  '<S112>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Calculate Ionospheric Corrections/Calculate Dualfrequency Correction with E1 and E5'
//  '<S113>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Create Elevation Mask and calculate Angles/Create Satellite Elevation Mask'
//  '<S114>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Satellite Masking/Apply Differential Correction Mask1'
//  '<S115>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Satellite Masking/Apply Elevation and NaN and Zero Mask'
//  '<S116>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/CalcDOP'
//  '<S117>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion'
//  '<S118>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion'
//  '<S119>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/MATLAB Function'
//  '<S120>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/switch GNSS Measurements'
//  '<S121>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion/Fault Exclusion'
//  '<S122>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion/Weighted RAIM Parity'
//  '<S123>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion/calculate Variance'
//  '<S124>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Check RTCM Valid'
//  '<S125>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Choose Correction Method'
//  '<S126>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Measurement Epoch Splitter'
//  '<S127>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Check RTCM Valid/Compare To Constant'
//  '<S128>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Check RTCM Valid/Detect Change'
//  '<S129>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Check RTCM Valid/S-R Flip-Flop'
//  '<S130>' : 'GNSSPreProcessingSingleAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Choose Correction Method/choose correction mode'

#endif                          // RTW_HEADER_GNSSPreProcessingSingleAntenna_h_

//
// File trailer for generated code.
//
// [EOF]
//
