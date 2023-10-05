//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GNSSPreProcessingDualAntenna.h
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
#ifndef RTW_HEADER_GNSSPreProcessingDualAntenna_h_
#define RTW_HEADER_GNSSPreProcessingDualAntenna_h_
#include "rtwtypes.h"
#include "GNSSPreProcessingDualAntenna_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model GNSSPreProcessingDualAntenna
class GNSSPreProcessingDualAntenna final
{
    // public data and function members
  public:
    // Block signals for system '<Root>/Calculate User Position with LMS'
    struct B_CalculateUserPositionwithLM_T
    {
        real_T H_data[160];
        real_T H_data_m[160];
        real_T b_A_data[160];
        real_T delta_rho_data[40];
        real_T bvec_data[40];
        real_T b_B_data[40];
        real_T b_A_data_c[16];
        real_T dv[9];
        real_T user_state[4];
        real_T residuum[4];
        real_T dv1[4];
        real_T dv2[4];
        real_T tau_data[4];
        real_T work[4];
        real_T vn1[4];
        real_T vn2[4];
        real_T satellite_position[3];
        real_T satellite_position_k[3];
        real_T in3[3];
        real_T in4[3];
        real_T N;
        real_T y;
        real_T scale;
        real_T absxk;
        real_T t;
        real_T d;
        real_T d1;
        real_T smax;
        real_T s;
        real_T temp2;
        real_T smax_c;
        real_T s_b;
        real_T scale_p;
        real_T absxk_c;
        real_T t_f;
        real_T satellite_position_tmp;
        real_T d2;
        real_T in3_tmp;
        real_T scale_g;
        real_T a;
        real_T b;
        int32_T rtu_gnss_measurement_DIMS1[2];
        int32_T H_size[2];
        int32_T H_size_g[2];
        int32_T b_A_size[2];
        int8_T ipiv[4];
        int8_T jpvt[4];
        int32_T iter;
        int32_T c;
        int32_T delta_rho_size;
        int32_T rtu_gnss_measurement_DIMS1_m;
        int32_T rtu_gnss_measurement_DIMS1_n;
        int32_T bvec_size_idx_0;
        int32_T rtu_gnss_measurement_DIMS1_idx_;
        int32_T jj;
        int32_T j;
        int32_T kAcol;
        int32_T n;
        int32_T jA;
        int32_T e;
        int32_T vectorUB;
        int32_T rankA;
        int32_T maxmn;
        int32_T minmana;
        int32_T ii;
        int32_T mmi;
        int32_T pvt;
        int32_T itemp;
        int32_T e_i;
        int32_T b_ix;
        int32_T c_k;
        int32_T p;
        int32_T ia;
        int32_T jA_l;
        int32_T temp_tmp;
        int32_T kend;
        int32_T k;
        int8_T ipiv_j;
    };

    // Block states (default storage) for system '<S5>/Calculate Day of Year'
    struct DW_CalculateDayofYear_GNSSPre_T
    {
        real_T doy;                    // '<S5>/Calculate Day of Year'
    };

    // Block signals for system '<S5>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles'
    struct B_ConvertGNSSMeasuremendVaria_T
    {
        real_T rtu_GNSSMeasurementVariable_dat[120];
        real_T elevation_angle_data[40];
        real_T azimuth_angle_data[40];
        real_T e_unit_tmp[9];
        real_T user_Position_ecef[3];
        real_T e_unit[3];
        real_T n_unit[3];
        real_T u_unit[3];
        real_T line_of_sight[3];
        real_T N;
        real_T scale;
        real_T t;
        real_T d;
        real_T u_unit_c;
        int32_T rtu_GNSSMeasurementVariable_siz[2];
        int32_T nb;
        int32_T i;
        int32_T loop_ub;
        int32_T loop_ub_c;
        int32_T elevation_angle_size;
        int32_T azimuth_angle_size;
        int32_T rtu_GNSSMeasurementVariab_DIMS1;
        int32_T i_p;
        int32_T i_c;
        int32_T loop_ub_f;
        int32_T i1;
        int32_T i2;
        int32_T stride_0_1;
    };

    // Block signals for system '<S5>/Dummy GNSS Measurement'
    struct B_DummyGNSSMeasurement_GNSSPr_T
    {
        GNSS_Measurement dummy_GNSS_Measurement_Bus;// '<S5>/Dummy GNSS Measurement'
    };

    // Block states (default storage) for system '<S5>/Dummy GNSS Measurement'
    struct DW_DummyGNSSMeasurement_GNSSP_T
    {
        GNSS_Measurement_size SFunction_DIMS2;// '<S5>/Dummy GNSS Measurement'
    };

    // Block signals for system '<S5>/Fuse'
    struct B_Fuse_GNSSPreProcessingDualA_T
    {
        uint16_T y[40];                // '<S5>/Fuse'
        uint16_T tmp_data[40];
    };

    // Block states (default storage) for system '<S5>/Fuse'
    struct DW_Fuse_GNSSPreProcessingDual_T
    {
        int32_T SFunction_DIMS2;       // '<S5>/Fuse'
    };

    // Block signals for system '<S5>/GNSS Measurement Epoch Splitter'
    struct B_GNSSMeasurementEpochSplitte_T
    {
        int8_T x_data[40];
        int8_T y_data[40];
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
        boolean_T t[40];
        boolean_T u[40];
        boolean_T v[40];
        boolean_T w[40];
        boolean_T v_m[40];
    };

    // Block signals for system '<S32>/Calculate Satellite Clock Correction'
    struct B_CalculateSatelliteClockCorr_T
    {
        real_T timeEmissionCorrected[40];// '<S32>/Calculate Satellite Clock Correction'
        real_T deltaTimeSV[40];        // '<S32>/Calculate Satellite Clock Correction'
        real_T drTimeCorr[40];         // '<S32>/Calculate Satellite Clock Correction'
        real_T t_sv_emission_data[40];
        real_T t_d_data[40];
        real_T t_k_data[40];
        real_T E_k_data[40];
        real_T n_0_data[40];
        real_T M_k_data[40];
        real_T tmp_data[40];
        real_T in2_data[40];
        boolean_T x_data[40];
        real_T t_d;
        real_T varargin_1;
        real_T d;
        real_T d1;
        real_T d2;
        int32_T t_sv_emission_size[2];
        int32_T t_d_size[2];
        int32_T t_k_size[2];
        int32_T E_k_size[2];
        int32_T n_0_size[2];
        int32_T M_k_size[2];
        int32_T i;
        int32_T k;
        int32_T loop_ub;
        int32_T scalarLB;
        int32_T vectorUB;
        int32_T tmp_size;
        int32_T i_m;
        int32_T stride_0_1;
        int32_T stride_1_1;
        int32_T loop_ub_c;
        int32_T in2_size_idx_1;
        int32_T i1;
        int32_T stride_0_1_k;
        int32_T stride_1_1_c;
        int32_T stride_2_1;
        int32_T stride_3_1;
        int32_T stride_4_1;
        int32_T stride_5_1;
        int32_T stride_6_1;
        int32_T stride_7_1;
        int32_T loop_ub_b;
        int32_T i2;
        int32_T stride_0_1_p;
        int32_T stride_1_1_cv;
        int32_T stride_2_1_f;
        int32_T stride_3_1_g;
        int32_T loop_ub_g;
        int32_T i3;
        int32_T stride_0_1_m;
        int32_T stride_1_1_n;
        int32_T stride_2_1_p;
        int32_T loop_ub_l;
        int32_T i4;
        int32_T stride_0_0;
        int32_T stride_1_0;
        int32_T stride_2_0;
        int32_T loop_ub_j;
        int32_T i5;
        int32_T stride_0_1_d;
        int32_T stride_1_1_g;
        int32_T stride_2_1_l;
        int32_T loop_ub_d;
        int32_T i6;
        int32_T stride_0_0_d;
        int32_T stride_1_0_l;
        int32_T loop_ub_o;
        int32_T i7;
        int32_T stride_0_0_b;
        int32_T stride_1_0_n;
        int32_T loop_ub_bs;
        int32_T i8;
        int32_T stride_0_1_l;
        int32_T stride_1_1_h;
        int32_T loop_ub_bn;
        int32_T i9;
        int32_T stride_0_1_da;
        int32_T stride_1_1_e;
        int32_T loop_ub_bj;
        boolean_T y;
    };

    // Block states (default storage) for system '<S32>/Calculate Satellite Clock Correction'
    struct DW_CalculateSatelliteClockCor_T
    {
        int32_T SFunction_DIMS2;       // '<S32>/Calculate Satellite Clock Correction'
        int32_T SFunction_DIMS3;       // '<S32>/Calculate Satellite Clock Correction'
        int32_T SFunction_DIMS4;       // '<S32>/Calculate Satellite Clock Correction'
    };

    // Block signals for system '<S32>/Calculate Satellite Position and Velocity'
    struct B_CalculateSatellitePositiona_T
    {
        real_T satPosEcef[120];        // '<S32>/Calculate Satellite Position and Velocity'
        real_T satVelEcef[120];        // '<S32>/Calculate Satellite Position and Velocity'
        real_T satPosEcef_data[120];
        real_T satVelEcef_data[120];
        real_T tmp_data[120];
        real_T rtu_timeEmissionCorrected_data[40];
        real_T t_k_data[40];
        real_T cosinus_E_k_data[40];
        real_T sinus_E_k_data[40];
        real_T sin2PHI_k_data[40];
        real_T cos2PHI_k_data[40];
        real_T r_k_data[40];
        real_T i_k_data[40];
        real_T cosinus_u_k_data[40];
        real_T cosinus_i_k_data[40];
        real_T sinus_lambda_k_data[40];
        real_T PHI_k_Dot_data[40];
        real_T u_k_Dot_data[40];
        real_T E_k_Dot_data[40];
        real_T c_data[40];
        real_T X_k_tmp_data[40];
        real_T d_data[40];
        real_T M_k_data[40];
        real_T eps_data[40];
        real_T E_k_old_data[40];
        real_T in2_data[40];
        real_T in2_data_m[40];
        real_T in1_data[40];
        real_T tmp_data_c[40];
        real_T in2_data_k[40];
        real_T in5_data[40];
        real_T tmp_data_cx[40];
        real_T in2_data_b[40];
        real_T in2_data_p[40];
        real_T tmp_data_cv[40];
        real_T tmp_data_f[40];
        real_T in1_data_g[40];
        real_T in1_data_g1[40];
        real_T in2_data_me[40];
        real_T in2_data_n[40];
        real_T in2_data_pp[40];
        real_T in2_data_l[40];
        real_T in1_data_j[40];
        real_T rtu_GnssNavBus_data[37];
        real_T rtu_GnssNavBus_data_d[37];
        real_T rtu_GnssNavBus_data_g[37];
        real_T rtu_GnssNavBus_data_l[37];
        real_T rtu_GnssNavBus_data_dh[37];
        real_T rtu_GnssNavBus_data_dy[37];
        real_T rtu_GnssNavBus_data_lx[37];
        real_T rtu_GnssNavBus_data_o[37];
        real_T rtu_GnssNavBus_data_b[37];
        real_T rtu_GnssNavBus_data_n[37];
        real_T rtu_GnssNavBus_data_bs[37];
        real_T rtu_GnssNavBus_data_ln[37];
        real_T rtu_GnssNavBus_data_h[37];
        real_T rtu_GnssNavBus_data_bn[37];
        real_T rtu_GnssNavBus_data_da[37];
        real_T rtu_GnssNavBus_data_e[37];
        real_T f_data[37];
        real_T g_data[37];
        real_T n_0_data[37];
        real_T in1_data_b[37];
        real_T sv_pos_tmp[9];
        real_T dv[9];
        boolean_T x_data[40];
        real_T sv_pos_tmp_j[3];
        real_T y_user;
        real_T z_user;
        real_T N;
        real_T sinus_lambda_k;
        real_T varargin_1;
        real_T varargin_1_f;
        real_T varargin_1_a;
        real_T varargin_1_j;
        real_T varargin_1_jz;
        real_T d;
        real_T d1;
        int32_T satPosEcef_size[2];
        int32_T satVelEcef_size[2];
        int32_T tmp_size[2];
        int32_T rtu_GnssNavBus_size[2];
        int32_T rtu_GnssNavBus_size_o[2];
        int32_T rtu_GnssNavBus_size_n[2];
        int32_T rtu_GnssNavBus_size_i[2];
        int32_T rtu_GnssNavBus_size_oy[2];
        int32_T rtu_GnssNavBus_size_nv[2];
        int32_T rtu_GnssNavBus_size_m[2];
        int32_T rtu_GnssNavBus_size_c[2];
        int32_T rtu_GnssNavBus_size_md[2];
        int32_T rtu_GnssNavBus_size_m3[2];
        int32_T rtu_GnssNavBus_size_j[2];
        int32_T rtu_GnssNavBus_size_h[2];
        int32_T rtu_GnssNavBus_size_c0[2];
        int32_T rtu_GnssNavBus_size_ct[2];
        int32_T rtu_GnssNavBus_size_p[2];
        int32_T rtu_GnssNavBus_size_p5[2];
        int32_T rtu_timeEmissionCorrected_size[2];
        int32_T t_k_size[2];
        int32_T cosinus_E_k_size[2];
        int32_T sinus_E_k_size[2];
        int32_T sin2PHI_k_size[2];
        int32_T cos2PHI_k_size[2];
        int32_T r_k_size[2];
        int32_T i_k_size[2];
        int32_T cosinus_u_k_size[2];
        int32_T cosinus_i_k_size[2];
        int32_T sinus_lambda_k_size[2];
        int32_T PHI_k_Dot_size[2];
        int32_T u_k_Dot_size[2];
        int32_T E_k_Dot_size[2];
        int32_T c_size[2];
        int32_T X_k_tmp_size[2];
        int32_T d_size[2];
        int32_T f_size[2];
        int32_T g_size[2];
        int32_T n_0_size[2];
        int32_T M_k_size[2];
        int32_T E_k_old_size[2];
        int32_T in2_size[2];
        int32_T in1_size[2];
        int32_T tmp_size_a[2];
        int32_T in2_size_e[2];
        int32_T in5_size[2];
        int32_T loop_ub;
        int32_T i;
        int32_T loop_ub_tmp;
        int32_T loop_ub_a;
        int32_T scalarLB;
        int32_T vectorUB;
        int32_T transport_angle_size;
        int32_T t_k_data_tmp;
        int32_T scalarLB_tmp;
        int32_T i_a;
        int32_T loop_ub_i;
        int32_T scalarLB_l;
        int32_T vectorUB_o;
        int32_T eps_size_idx_1;
        int32_T varargin_1_tmp;
        int32_T i1;
        int32_T stride_0_1;
        int32_T stride_1_1;
        int32_T stride_2_1;
        int32_T loop_ub_o;
        int32_T in2_size_idx_1;
        int32_T i2;
        int32_T stride_0_1_i;
        int32_T stride_1_1_f;
        int32_T stride_2_1_i;
        int32_T loop_ub_f;
        int32_T loop_ub_g;
        int32_T r_data_tmp;
        int32_T f;
        int32_T k;
        int32_T i3;
        int32_T i4;
        int32_T i5;
        int32_T stride_0_1_c;
        int32_T stride_1_1_o;
        int32_T stride_2_1_l;
        int32_T loop_ub_m;
        int32_T i6;
        int32_T stride_0_1_m;
        int32_T stride_1_1_c;
        int32_T stride_2_1_f;
        int32_T stride_3_1;
        int32_T stride_4_1;
        int32_T stride_5_1;
        int32_T stride_6_1;
        int32_T stride_7_1;
        int32_T stride_8_1;
        int32_T loop_ub_p;
        int32_T tmp_size_idx_1;
        int32_T i7;
        int32_T stride_0_1_e;
        int32_T stride_1_1_o4;
        int32_T stride_2_1_h;
        int32_T loop_ub_l;
        int32_T in2_size_idx_1_h;
        int32_T i8;
        int32_T stride_0_1_me;
        int32_T stride_1_1_m;
        int32_T loop_ub_h;
        int32_T in2_size_idx_1_c;
        int32_T i9;
        int32_T stride_0_1_k;
        int32_T stride_1_1_p;
        int32_T stride_2_1_p;
        int32_T stride_3_1_p;
        int32_T stride_4_1_a;
        int32_T stride_5_1_j;
        int32_T loop_ub_e;
        int32_T tmp_size_idx_1_o;
        int32_T i10;
        int32_T stride_0_1_b;
        int32_T stride_1_1_a;
        int32_T stride_2_1_g;
        int32_T stride_3_1_e;
        int32_T stride_4_1_f;
        int32_T stride_5_1_h;
        int32_T loop_ub_ei;
        int32_T tmp_size_idx_1_c;
        int32_T i11;
        int32_T stride_0_1_a;
        int32_T stride_1_1_d;
        int32_T stride_2_1_a;
        int32_T stride_3_1_pb;
        int32_T stride_4_1_m;
        int32_T loop_ub_o3;
        int32_T in1_size_idx_1;
        int32_T i12;
        int32_T stride_0_1_n;
        int32_T stride_1_1_l;
        int32_T stride_2_1_pe;
        int32_T stride_3_1_pt;
        int32_T loop_ub_ft;
        int32_T in1_size_idx_1_i;
        int32_T i13;
        int32_T stride_0_1_o;
        int32_T stride_1_1_k;
        int32_T stride_2_1_ie;
        int32_T stride_3_1_o;
        int32_T loop_ub_m4;
        int32_T in2_size_idx_1_cu;
        int32_T i14;
        int32_T stride_0_1_f;
        int32_T stride_1_1_h;
        int32_T stride_2_1_m;
        int32_T stride_3_1_a;
        int32_T loop_ub_k;
        int32_T in2_size_idx_1_p;
        int32_T i15;
        int32_T stride_0_1_bp;
        int32_T stride_1_1_ch;
        int32_T loop_ub_n;
        int32_T in1_size_idx_1_ij;
        int32_T i16;
        int32_T stride_0_1_my;
        int32_T stride_1_1_j;
        int32_T stride_2_1_e;
        int32_T loop_ub_mv;
        int32_T in2_size_idx_1_m;
        int32_T i17;
        int32_T stride_0_1_j;
        int32_T stride_1_1_fo;
        int32_T loop_ub_a5;
        int32_T in2_size_idx_1_g;
        int32_T i18;
        int32_T stride_0_1_nr;
        int32_T stride_1_1_d3;
        int32_T loop_ub_na;
        int32_T in1_size_idx_1_c;
        int32_T i19;
        int32_T stride_0_1_fx;
        int32_T stride_1_1_pm;
        int32_T stride_2_1_p2;
        int32_T loop_ub_nj;
        int32_T i20;
        int32_T stride_0_1_kt;
        int32_T stride_1_1_n;
        int32_T stride_2_1_o;
        int32_T loop_ub_gg;
        int32_T i21;
        int32_T stride_0_0;
        int32_T stride_1_0;
        int32_T stride_2_0;
        int32_T stride_3_0;
        int32_T stride_4_0;
        int32_T stride_5_0;
        int32_T stride_6_0;
        int32_T stride_7_0;
        int32_T stride_8_0;
        int32_T in1_idx_0;
        int32_T i22;
        int32_T stride_0_0_c;
        int32_T stride_1_0_c;
        int32_T stride_2_0_m;
        int32_T stride_3_0_j;
        int32_T stride_4_0_k;
        int32_T stride_5_0_m;
        int32_T stride_6_0_p;
        int32_T stride_7_0_d;
        int32_T stride_8_0_g;
        int32_T in2_idx_0;
        int32_T i23;
        int32_T stride_0_1_c3;
        int32_T stride_1_1_cx;
        int32_T stride_2_1_if;
        int32_T stride_3_1_d;
        int32_T stride_4_1_g;
        int32_T stride_5_1_l;
        int32_T stride_6_1_f;
        int32_T loop_ub_d;
        int32_T b;
        int32_T k_j;
        int32_T scalarLB_i;
        int32_T vectorUB_h;
        int32_T b_n;
        int32_T k_o;
        int32_T scalarLB_c;
        int32_T vectorUB_b;
        int8_T csz_idx_1;
        boolean_T y;
        boolean_T d_e;
        boolean_T e;
    };

    // Block states (default storage) for system '<S32>/Calculate Satellite Position and Velocity'
    struct DW_CalculateSatellitePosition_T
    {
        int32_T SFunction_DIMS2[2];    // '<S32>/Calculate Satellite Position and Velocity'
        int32_T SFunction_DIMS3[2];    // '<S32>/Calculate Satellite Position and Velocity'
    };

    // Block signals for system '<S32>/Time Correction Carrierphase'
    struct B_TimeCorrectionCarrierphase__T
    {
        real_T carrierphaseCorrected[40];// '<S32>/Time Correction Carrierphase'
        real_T tmp_data[40];
        real_T Lambda0;
    };

    // Block states (default storage) for system '<S32>/Time Correction Carrierphase'
    struct DW_TimeCorrectionCarrierphase_T
    {
        int32_T SFunction_DIMS2;       // '<S32>/Time Correction Carrierphase'
    };

    // Block signals for system '<S32>/Time Correction Deltarange'
    struct B_TimeCorrectionDeltarange_GN_T
    {
        real_T deltarangeCorrected[40];// '<S32>/Time Correction Deltarange'
        real_T tmp_data[40];
    };

    // Block states (default storage) for system '<S32>/Time Correction Deltarange'
    struct DW_TimeCorrectionDeltarange_G_T
    {
        int32_T SFunction_DIMS2;       // '<S32>/Time Correction Deltarange'
    };

    // Block signals for system '<S32>/Time Correction Pseudorange'
    struct B_TimeCorrectionPseudorange_G_T
    {
        real_T pseudorangeCorrected[40];// '<S32>/Time Correction Pseudorange'
        real_T tmp_data[40];
    };

    // Block states (default storage) for system '<S32>/Time Correction Pseudorange'
    struct DW_TimeCorrectionPseudorange__T
    {
        int32_T SFunction_DIMS2;       // '<S32>/Time Correction Pseudorange'
    };

    // Block signals for system '<S24>/Signal Noise Variance'
    struct B_SignalNoiseVariance_GNSSPre_T
    {
        real_T variancePseudorange[40];// '<S24>/Signal Noise Variance'
        real_T varianceDeltarange[40]; // '<S24>/Signal Noise Variance'
        real_T varargin_2_tmp_data[40];
        real_T tmp_data[40];
    };

    // Block states (default storage) for system '<S24>/Signal Noise Variance'
    struct DW_SignalNoiseVariance_GNSSPr_T
    {
        int32_T SFunction_DIMS2;       // '<S24>/Signal Noise Variance'
        int32_T SFunction_DIMS3;       // '<S24>/Signal Noise Variance'
    };

    // Block signals for system '<S17>/GPS L1 Stream'
    struct B_GPSsinglefrequencystream_GN_T
    {
        real_T timeOfWeekIn;           // '<S24>/timeOfWeekIn'
        real_T carrierToNoiseRatio[40];// '<S24>/carrierToNoiseRatio '
        real_T pr_sigma[40];           // '<S24>/pr_sigma '
        real_T cp_sigma[40];           // '<S24>/cp_sigma '
        real_T base_position[3];       // '<S24>/base_position'
        real32_T Locktime[40];         // '<S24>/locktime'
        uint16_T PRN[40];              // '<S24>/SVID'
        int32_T i;
        B_SignalNoiseVariance_GNSSPre_T sf_SignalNoiseVariance;// '<S24>/Signal Noise Variance'
        B_TimeCorrectionPseudorange_G_T sf_TimeCorrectionPseudorange;// '<S32>/Time Correction Pseudorange'
        B_TimeCorrectionDeltarange_GN_T sf_TimeCorrectionDeltarange;// '<S32>/Time Correction Deltarange'
        B_TimeCorrectionCarrierphase__T sf_TimeCorrectionCarrierphase;// '<S32>/Time Correction Carrierphase'
        B_CalculateSatellitePositiona_T sf_CalculateSatellitePositionan;// '<S32>/Calculate Satellite Position and Velocity' 
        B_CalculateSatelliteClockCorr_T sf_CalculateSatelliteClockCorre;// '<S32>/Calculate Satellite Clock Correction'
    };

    // Block states (default storage) for system '<S17>/GPS L1 Stream'
    struct DW_GPSsinglefrequencystream_G_T
    {
        int32_T SVID_DIMS1;            // '<S24>/SVID'
        int32_T carrierToNoiseRatio_DIMS1;// '<S24>/carrierToNoiseRatio '
        int32_T pr_sigma_DIMS1;        // '<S24>/pr_sigma '
        int32_T cp_sigma_DIMS1;        // '<S24>/cp_sigma '
        int32_T locktime_DIMS1;        // '<S24>/locktime'
        DW_SignalNoiseVariance_GNSSPr_T sf_SignalNoiseVariance;// '<S24>/Signal Noise Variance'
        DW_TimeCorrectionPseudorange__T sf_TimeCorrectionPseudorange;// '<S32>/Time Correction Pseudorange'
        DW_TimeCorrectionDeltarange_G_T sf_TimeCorrectionDeltarange;// '<S32>/Time Correction Deltarange'
        DW_TimeCorrectionCarrierphase_T sf_TimeCorrectionCarrierphase;// '<S32>/Time Correction Carrierphase'
        DW_CalculateSatellitePosition_T sf_CalculateSatellitePositionan;// '<S32>/Calculate Satellite Position and Velocity' 
        DW_CalculateSatelliteClockCor_T sf_CalculateSatelliteClockCorre;// '<S32>/Calculate Satellite Clock Correction'
    };

    // Block signals for system '<S17>/Navigation Data Conversion GPS'
    struct B_NavigationDataConversionGPS_T
    {
        gnssops_navigation_data GpsNavBusReshaped;// '<S17>/Navigation Data Conversion GPS'
    };

    // Block states (default storage) for system '<S17>/Navigation Data Conversion GPS'
    struct DW_NavigationDataConversionGP_T
    {
        gnssops_navigation_data_size SFunction_DIMS2;// '<S17>/Navigation Data Conversion GPS'
    };

    // Block signals for system '<S29>/Calculate Differential Corrections'
    struct B_CalculateDifferentialCorrec_T
    {
        real_T real_delta_data[111];
        real_T b_a_data[111];
        real_T diffPseudorangeCorrection[40];// '<S29>/Calculate Differential Corrections'
        real_T b_data[40];
        real_T in1_data[40];
        real_T navdata_DELTA_N_data[37];
        real_T navdata_M_0_data[37];
        real_T navdata_E_data[37];
        real_T navdata_SQRT_A_data[37];
        real_T navdata_T_oe_data[37];
        real_T real_range_data[37];
        real_T t_sv_emission_data[37];
        real_T t_d_data[37];
        real_T t_k_data[37];
        real_T E_k_data[37];
        real_T n_0_data[37];
        real_T E_k_old_data[37];
        real_T rtu_gpsNavDataBusL1_data[37];
        real_T rtu_gpsNavDataBusL1_data_m[37];
        real_T rtu_gpsNavDataBusL1_data_c[37];
        real_T rtu_gpsNavDataBusL1_data_k[37];
        real_T rtu_gpsNavDataBusL1_data_cx[37];
        real_T rtu_gpsNavDataBusL1_data_b[37];
        real_T rtu_gpsNavDataBusL1_data_p[37];
        real_T in1_data_c[37];
        real_T in1_data_f[37];
        real_T in1_data_g[37];
        real_T in1_data_g1[37];
        real_T in1_data_m[37];
        real_T in1_data_n[37];
        real_T in1_data_p[37];
        real_T in1_data_l[37];
        real_T in1_data_j[37];
        real_T in1_data_d[37];
        real_T in1_data_gu[37];
        real_T in9_data[37];
        real_T t_k_data_l[37];
        real_T cosinus_E_k_data[37];
        real_T sinus_E_k_data[37];
        real_T PHI_k_data[37];
        real_T sin2PHI_k_data[37];
        real_T cos2PHI_k_data[37];
        real_T r_k_data[37];
        real_T i_k_data[37];
        real_T cosinus_u_k_data[37];
        real_T cosinus_i_k_data[37];
        real_T sinus_lambda_k_data[37];
        real_T PHI_k_Dot_data[37];
        real_T r_k_Dot_data[37];
        real_T E_k_Dot_data[37];
        real_T y_tmp_data[37];
        real_T c_data[37];
        real_T X_k_tmp_data[37];
        real_T d_data[37];
        real_T f_data[37];
        real_T tmp_data[37];
        real_T M_k_data[37];
        real_T eps_data[37];
        real_T E_k_old_data_d[37];
        real_T in2_data[37];
        real_T in2_data_d[37];
        real_T in5_data[37];
        real_T tmp_data_l[37];
        real_T in2_data_o[37];
        real_T in5_data_b[37];
        real_T in1_data_nu[37];
        real_T in2_data_b[37];
        real_T in1_data_ln[37];
        real_T tmp_data_h[37];
        real_T in1_data_b[37];
        real_T in1_data_da[37];
        real_T in2_data_e[37];
        real_T in2_data_bj[37];
        real_T in1_data_jz[37];
        real_T in2_data_f[37];
        real_T in1_data_a[37];
        real_T in2_data_j[37];
        real_T in2_data_jz[37];
        real_T in2_data_o4[37];
        int32_T iidx_data[40];
        int32_T b_idx_data[40];
        int32_T iwork_data[40];
        int32_T iia_data[37];
        int32_T iib_data[37];
        uint16_T maskDiffCorr[40];     // '<S29>/Calculate Differential Corrections'
        uint16_T a_data[40];
        uint16_T vwork_data[40];
        uint16_T b_x_data[40];
        real_T sv_pos_tmp[9];
        real_T dv[9];
        boolean_T t_k_data_n[37];
        boolean_T eps_data_i[37];
        real_T sv_pos_tmp_o[3];
        uint16_T x4[4];
        real_T t_d;
        real_T y_user;
        real_T z_user;
        real_T N;
        real_T sinus_lambda_k;
        real_T varargin_1;
        real_T varargin_1_n;
        real_T varargin_1_m;
        real_T varargin_1_c;
        real_T in2_tmp;
        real_T varargin_1_md;
        real_T d;
        real_T d1;
        real_T varargin_1_m3;
        int32_T navdata_DELTA_N_size[2];
        int32_T navdata_M_0_size[2];
        int32_T navdata_E_size[2];
        int32_T navdata_SQRT_A_size[2];
        int32_T navdata_T_oe_size[2];
        int32_T real_delta_size[2];
        int32_T t_sv_emission_size[2];
        int32_T t_d_size[2];
        int32_T t_k_size[2];
        int32_T E_k_size[2];
        int32_T n_0_size[2];
        int32_T E_k_old_size[2];
        int32_T t_k_size_j[2];
        int32_T rtu_gpsNavDataBusL1_size[2];
        int32_T rtu_gpsNavDataBusL1_size_h[2];
        int32_T rtu_gpsNavDataBusL1_size_c[2];
        int32_T rtu_gpsNavDataBusL1_size_ct[2];
        int32_T rtu_gpsNavDataBusL1_size_p[2];
        int32_T rtu_gpsNavDataBusL1_size_p5[2];
        int32_T rtu_gpsNavDataBusL1_size_a[2];
        int32_T t_sv_emission_size_e[2];
        int32_T in1_size[2];
        int32_T in1_size_a[2];
        int32_T in1_size_as[2];
        int32_T in1_size_i[2];
        int32_T in1_size_l[2];
        int32_T in1_size_o[2];
        int32_T in1_size_o2[2];
        int32_T in1_size_ip[2];
        int32_T in1_size_f[2];
        int32_T in1_size_iz[2];
        int32_T in1_size_ff[2];
        int32_T in9_size[2];
        int32_T t_k_size_g[2];
        int32_T cosinus_E_k_size[2];
        int32_T sinus_E_k_size[2];
        int32_T PHI_k_size[2];
        int32_T sin2PHI_k_size[2];
        int32_T cos2PHI_k_size[2];
        int32_T r_k_size[2];
        int32_T i_k_size[2];
        int32_T cosinus_u_k_size[2];
        int32_T cosinus_i_k_size[2];
        int32_T sinus_lambda_k_size[2];
        int32_T PHI_k_Dot_size[2];
        int32_T r_k_Dot_size[2];
        int32_T E_k_Dot_size[2];
        int32_T y_tmp_size[2];
        int32_T c_size[2];
        int32_T X_k_tmp_size[2];
        int32_T d_size[2];
        int32_T f_size[2];
        int32_T tmp_size[2];
        int32_T M_k_size[2];
        int32_T E_k_old_size_c[2];
        int32_T eps_size[2];
        int32_T in2_size[2];
        int32_T in5_size[2];
        int32_T tmp_size_o[2];
        int32_T in2_size_l[2];
        int32_T in5_size_m[2];
        int8_T idx4[4];
        int8_T perm[4];
        int32_T i;
        int32_T k;
        int32_T acoef;
        int32_T vstride;
        int32_T xoffset;
        int32_T scalarLB;
        int32_T real_range_size;
        int32_T iidx_size;
        int32_T iia_size;
        int32_T iib_size;
        int32_T a_size;
        int32_T rtu_gpsNavDataBusL1_DIMS1;
        int32_T i_m;
        int32_T loop_ub;
        int32_T stride_0_1;
        int32_T stride_1_1;
        int32_T loop_ub_c;
        int32_T scalarLB_f;
        int32_T vectorUB;
        int32_T transport_angle_size;
        int32_T t_k_data_tmp;
        int32_T scalarLB_tmp;
        int32_T i_p;
        int32_T loop_ub_e;
        int32_T scalarLB_o;
        int32_T vectorUB_h;
        int32_T eps_size_idx_1;
        int32_T varargin_1_tmp;
        int32_T i1;
        int32_T stride_0_1_l;
        int32_T stride_1_1_h;
        int32_T stride_2_1;
        int32_T loop_ub_m;
        int32_T in2_size_idx_1;
        int32_T i2;
        int32_T stride_0_1_m;
        int32_T stride_1_1_h3;
        int32_T stride_2_1_c;
        int32_T loop_ub_k;
        int32_T loop_ub_p;
        int32_T r_data_tmp;
        int32_T f;
        int32_T k_p;
        int32_T i3;
        int32_T i4;
        int32_T i5;
        int32_T stride_0_1_p;
        int32_T stride_1_1_a;
        int32_T stride_2_1_j;
        int32_T loop_ub_ek;
        int32_T dim;
        int32_T vstride_o;
        int32_T b;
        int32_T b_i;
        int32_T nDone;
        int32_T nLeft;
        int32_T i1_b;
        int32_T i2_a;
        int32_T i3_g;
        int32_T i4_e;
        int32_T i6;
        int32_T b_x_size;
        int32_T vwork_size_idx_0;
        int32_T nQuartets_tmp;
        int32_T p;
        int32_T q;
        int32_T i7;
        int32_T stride_0_1_f;
        int32_T stride_1_1_h2;
        int32_T stride_2_1_e;
        int32_T loop_ub_ch;
        int32_T in1_size_idx_1;
        int32_T i8;
        int32_T stride_0_1_a;
        int32_T stride_1_1_d;
        int32_T loop_ub_a;
        int32_T in2_size_idx_1_p;
        int32_T i9;
        int32_T stride_0_1_ms;
        int32_T stride_1_1_o;
        int32_T loop_ub_n;
        int32_T in1_size_idx_1_l;
        int32_T i10;
        int32_T stride_0_1_pe;
        int32_T stride_1_1_p;
        int32_T stride_2_1_f;
        int32_T stride_3_1;
        int32_T stride_4_1;
        int32_T stride_5_1;
        int32_T loop_ub_i;
        int32_T tmp_size_idx_1;
        int32_T i11;
        int32_T stride_0_1_o;
        int32_T stride_1_1_k;
        int32_T stride_2_1_i;
        int32_T stride_3_1_o;
        int32_T stride_4_1_m;
        int32_T loop_ub_cu;
        int32_T in1_size_idx_1_f;
        int32_T i12;
        int32_T stride_0_1_h;
        int32_T stride_1_1_m;
        int32_T stride_2_1_a;
        int32_T stride_3_1_k;
        int32_T loop_ub_pc;
        int32_T in1_size_idx_1_b;
        int32_T i13;
        int32_T stride_0_1_c;
        int32_T stride_1_1_n;
        int32_T stride_2_1_ij;
        int32_T stride_3_1_m;
        int32_T loop_ub_j;
        int32_T in2_size_idx_1_e;
        int32_T i14;
        int32_T stride_0_1_mv;
        int32_T stride_1_1_m0;
        int32_T stride_2_1_jg;
        int32_T stride_3_1_f;
        int32_T loop_ub_a5;
        int32_T in2_size_idx_1_g;
        int32_T i15;
        int32_T stride_0_1_n;
        int32_T stride_1_1_d3;
        int32_T stride_2_1_n;
        int32_T loop_ub_cg;
        int32_T in1_size_idx_1_fx;
        int32_T i16;
        int32_T stride_0_1_pm;
        int32_T stride_1_1_p2;
        int32_T loop_ub_nj;
        int32_T in2_size_idx_1_k;
        int32_T i17;
        int32_T stride_0_1_n3;
        int32_T stride_1_1_oy;
        int32_T loop_ub_g;
        int32_T in1_size_idx_1_c;
        int32_T i18;
        int32_T stride_0_1_cj;
        int32_T stride_1_1_m1;
        int32_T stride_2_1_jp;
        int32_T stride_3_1_kn;
        int32_T stride_4_1_mx;
        int32_T stride_5_1_p;
        int32_T i19;
        int32_T i20;
        int32_T stride_0_1_d;
        int32_T stride_1_1_g;
        int32_T i21;
        int32_T stride_0_1_c3;
        int32_T stride_1_1_c;
        int32_T stride_2_1_if;
        int32_T stride_3_1_d;
        int32_T stride_4_1_g;
        int32_T stride_5_1_l;
        int32_T stride_6_1;
        int32_T stride_7_1;
        int32_T stride_8_1;
        int32_T loop_ub_f;
        int32_T i22;
        int32_T stride_0_1_db;
        int32_T stride_1_1_j;
        int32_T stride_2_1_i3;
        int32_T loop_ub_h;
        int32_T i23;
        int32_T stride_0_1_nm;
        int32_T stride_1_1_o3;
        int32_T stride_2_1_ch;
        int32_T loop_ub_b;
        int32_T i24;
        int32_T stride_0_0;
        int32_T stride_1_0;
        int32_T stride_2_0;
        int32_T stride_3_0;
        int32_T stride_4_0;
        int32_T stride_5_0;
        int32_T stride_6_0;
        int32_T stride_7_0;
        int32_T stride_8_0;
        int32_T in1_idx_0;
        int32_T i25;
        int32_T stride_0_0_e;
        int32_T stride_1_0_d;
        int32_T stride_2_0_i;
        int32_T stride_3_0_g;
        int32_T stride_4_0_n;
        int32_T stride_5_0_l;
        int32_T stride_6_0_c;
        int32_T stride_7_0_n;
        int32_T stride_8_0_p;
        int32_T in2_idx_0;
        int32_T i26;
        int32_T stride_0_1_dk;
        int32_T stride_1_1_oi;
        int32_T stride_2_1_jr;
        int32_T stride_3_1_c;
        int32_T stride_4_1_h;
        int32_T stride_5_1_d;
        int32_T loop_ub_c5;
        int32_T i27;
        int32_T stride_0_1_pw;
        int32_T stride_1_1_pi;
        int32_T stride_2_1_a4;
        int32_T stride_3_1_ow;
        int32_T stride_4_1_j;
        int32_T stride_5_1_pi;
        int32_T stride_6_1_o;
        int32_T loop_ub_l;
        int32_T ix;
        int32_T b_k;
        int32_T k_j;
        int32_T scalarLB_fz;
        int32_T vectorUB_c;
        int32_T b_f;
        int32_T k_n;
        int32_T scalarLB_i;
        int32_T vectorUB_l;
        int8_T csz_idx_1;
        boolean_T d_i;
        boolean_T e;
    };

    // Block states (default storage) for system '<S29>/Calculate Differential Corrections'
    struct DW_CalculateDifferentialCorre_T
    {
        emxArray_real_T_40_GNSSPrePro_T delta_pr2;// '<S29>/Calculate Differential Corrections'
        emxArray_uint16_T_37_GNSSPreP_T PRNs;// '<S29>/Calculate Differential Corrections'
        real_T old_t;                  // '<S29>/Calculate Differential Corrections'
        int32_T SFunction_DIMS2;       // '<S29>/Calculate Differential Corrections'
        int32_T SFunction_DIMS3;       // '<S29>/Calculate Differential Corrections'
        boolean_T delta_pr2_not_empty; // '<S29>/Calculate Differential Corrections'
    };

    // Block signals for system '<S57>/Calculate Dualfrequency Correction with L1 and L2C'
    struct B_CalculateDualfrequencyCorre_T
    {
        GNSS_Measurement measurementFrequencyBus;// '<S57>/Calculate Dualfrequency Correction with L1 and L2C'
        real_T fixed_f1[150];
        real_T fixed_f2[150];
        int32_T l_data[150];
        real_T dualFrequencyCorrection[40];// '<S57>/Calculate Dualfrequency Correction with L1 and L2C'
        uint16_T fixed_PRN[150];
        int32_T iia_data[40];
        int32_T iib_data[40];
        boolean_T g_data[150];
        uint8_T h_data[150];
        uint8_T k_data[150];
        uint16_T SvidDualFrequencyCorrected[40];// '<S57>/Calculate Dualfrequency Correction with L1 and L2C'
        uint16_T tmp_data[40];
        int8_T idx2_data[40];
        int8_T idx1_data[40];
        real_T d;
        real_T d1;
        int32_T c;
        int32_T i;
        int32_T rtu_measurementBusL1;
        int32_T loop_ub;
        int32_T vectorUB;
        int32_T iia_size;
        int32_T iib_size;
        int32_T tmp_size;
        int32_T rtu_measurementBusL1_DIMS1;
        int32_T rtu_measurementBusL2C_DIMS1;
        int32_T h_size_idx_0;
        int32_T ncmax;
        int32_T nc;
    };

    // Block states (default storage) for system '<S57>/Calculate Dualfrequency Correction with L1 and L2C'
    struct DW_CalculateDualfrequencyCorr_T
    {
        GNSS_Measurement_size SFunction_DIMS2;// '<S57>/Calculate Dualfrequency Correction with L1 and L2C'
        int32_T SFunction_DIMS3;       // '<S57>/Calculate Dualfrequency Correction with L1 and L2C'
        int32_T SFunction_DIMS4;       // '<S57>/Calculate Dualfrequency Correction with L1 and L2C'
    };

    // Block signals for system '<S57>/Calculate Klobuchar Model Correction'
    struct B_CalculateKlobucharModelCorr_T
    {
        real_T klobucharCorrection[40];// '<S57>/Calculate Klobuchar Model Correction'
        real_T elevationAngle_data[40];
        real_T central_angle;
        real_T latitude_ipp;
        real_T longitude_ipp;
    };

    // Block states (default storage) for system '<S57>/Calculate Klobuchar Model Correction'
    struct DW_CalculateKlobucharModelCor_T
    {
        int32_T SFunction_DIMS2;       // '<S57>/Calculate Klobuchar Model Correction'
    };

    // Block signals for system '<S29>/Calculate Tropospheric Corrections'
    struct B_CalculateTroposphericCorrec_T
    {
        real_T troposphericDelay[40];  // '<S29>/Calculate Tropospheric Corrections'
        real_T pressure_data[40];
        real_T temperature_data[40];
        real_T water_vapour_pressure_data[40];
        real_T beta_data[40];
        real_T lambda_data[40];
        real_T d_data[40];
        real_T y_data[40];
        real_T x_data[40];
        real_T b_b_data[40];
        real_T x_tmp_data[40];
        real_T in2_data[40];
        real_T dv[5];
        real_T dv1[5];
        real_T dv2[2];
        real_T dv3[2];
        real_T dv4[2];
        real_T dv5[2];
        real_T dv6[2];
        real_T dv7[2];
        real_T dv8[2];
        real_T dv9[2];
        real_T latitude;
        real_T cosinus_day;
        real_T d;
        real_T varargout_1;
        real_T in2_tmp;
        real_T d1;
        real_T d2;
        real_T r;
        int32_T k;
        int32_T loop_ub;
        int32_T vectorUB;
        int32_T pressure_size;
        int32_T temperature_size;
        int32_T water_vapour_pressure_size;
        int32_T beta_size;
        int32_T lambda_size;
        int32_T d_size;
        int32_T y_size;
        int32_T x_size;
        int32_T b_b_size;
        int32_T x_tmp_size;
        int32_T SFunction_DIMS2_tmp_tmp;
        int32_T i;
        int32_T stride_0_0;
        int32_T stride_1_0;
        int32_T stride_2_0;
        int32_T stride_3_0;
        int32_T stride_4_0;
        int32_T stride_5_0;
        int32_T stride_6_0;
        int32_T stride_7_0;
        int32_T stride_8_0;
        int32_T stride_9_0;
    };

    // Block states (default storage) for system '<S29>/Calculate Tropospheric Corrections'
    struct DW_CalculateTroposphericCorre_T
    {
        int32_T SFunction_DIMS2;       // '<S29>/Calculate Tropospheric Corrections'
    };

    // Block signals for system '<S60>/Create Satellite Elevation Mask'
    struct B_CreateSatelliteElevationMas_T
    {
        real_T elevationAngle[40];     // '<S60>/Create Satellite Elevation Mask'
        real_T azimuthAngle[40];       // '<S60>/Create Satellite Elevation Mask'
        real_T e_unit_tmp[9];
        boolean_T elevationMask[40];   // '<S60>/Create Satellite Elevation Mask'
        boolean_T tmp_data[40];
        real_T user_Position_ecef[3];
        real_T e_unit[3];
        real_T n_unit[3];
        real_T u_unit[3];
        real_T line_of_sight[3];
        real_T elevation_Angle_Limit;
        real_T N;
        real_T scale;
        real_T t;
        real_T d;
        real_T u_unit_m;
        int32_T nz;
        int32_T c;
        int32_T b_k;
        int32_T loop_ub;
        int32_T tmp_size;
        int32_T rtu_satPosEcef_DIMS1_idx_0;
        int32_T i;
        int32_T stride_0_0;
        int32_T loop_ub_c;
        int32_T i1;
        int32_T i2;
        int32_T stride_0_1;
        int8_T b[2];
    };

    // Block states (default storage) for system '<S60>/Create Satellite Elevation Mask'
    struct DW_CreateSatelliteElevationMa_T
    {
        int32_T SFunction_DIMS2;       // '<S60>/Create Satellite Elevation Mask'
        int32_T SFunction_DIMS3;       // '<S60>/Create Satellite Elevation Mask'
        int32_T SFunction_DIMS4;       // '<S60>/Create Satellite Elevation Mask'
    };

    // Block signals for system '<S61>/Apply Differential Correction Mask1'
    struct B_ApplyDifferentialCorrection_T
    {
        GNSS_Measurement GPS_measurement_Bus_masked;// '<S61>/Apply Differential Correction Mask1'
        real_T tmp_data[40];
        int32_T iia_data[40];
        int32_T iib_data[40];
        uint16_T a__1_data[40];
        int32_T loop_ub;
        int32_T i;
        int32_T i1;
        int32_T loop_ub_m;
        int32_T a__1_size;
    };

    // Block states (default storage) for system '<S61>/Apply Differential Correction Mask1'
    struct DW_ApplyDifferentialCorrectio_T
    {
        GNSS_Measurement_size SFunction_DIMS2;// '<S61>/Apply Differential Correction Mask1'
    };

    // Block signals for system '<S61>/Apply Elevation and NaN and Zero Mask'
    struct B_ApplyElevationandNaNandZero_T
    {
        GNSS_Measurement measurementFrequencyCorrectedMa;// '<S61>/Apply Elevation and NaN and Zero Mask'
        boolean_T rtu_measurementFrequencyCorrect[120];
        boolean_T rtu_measurementFrequencyCorre_c[120];
        boolean_T rtu_measurementFrequencyCorre_k[120];
        boolean_T rtu_measurementFrequencyCorr_cx[120];
        boolean_T in5_data[120];
        boolean_T tmp_data[120];
        int8_T b_data[40];
        int8_T c_data[40];
        int8_T d_data[40];
        int8_T e_data[40];
        int8_T f_data[40];
        int8_T g_data[40];
        int8_T h_data[40];
        int8_T i_data[40];
        int8_T j_data[40];
        int8_T k_data[40];
        int8_T l_data[40];
        int8_T m_data[40];
        int8_T n_data[40];
        int8_T o_data[40];
        int8_T p_data[40];
        int8_T q_data[40];
        int8_T r_data[40];
        int8_T s_data[40];
        boolean_T nan_mask_data[40];
        boolean_T mask_all_data[40];
        boolean_T tmp_data_b[40];
        boolean_T rtu_measurementFrequencyCorre_p[40];
        boolean_T nan_mask_data_c[40];
        boolean_T tmp_data_f[40];
        boolean_T tmp_data_g[40];
        boolean_T tmp_data_g1[40];
        boolean_T in5_data_m[40];
        boolean_T tmp_data_n[40];
        boolean_T tmp_data_p[40];
        boolean_T tmp_data_l[40];
        boolean_T tmp_data_j[40];
        boolean_T tmp_data_d[40];
        int32_T rtu_measurementFrequencyCorre_g[2];
        int32_T rtu_measurementFrequencyCorre_l[2];
        int32_T rtu_measurementFrequencyCorre_d[2];
        int32_T rtu_measurementFrequencyCorr_dy[2];
        int32_T in5_size[2];
        int32_T tmp_size[2];
        int32_T b_i;
        int32_T rtu_measurementFrequencyC_DIMS1;
        int32_T loop_ub_tmp;
        int32_T loop_ub_tmp_o;
        int32_T nan_mask_size;
        int32_T mask_all_size;
        int32_T tmp_size_b;
        int32_T tmp_size_n;
        int32_T rtu_measurementFrequencyCorre_b;
        int32_T rtu_measurementFrequencyCorr_ln;
        int32_T nan_mask_size_h;
        int32_T tmp_size_bn;
        int32_T tmp_size_d;
        int32_T tmp_size_e;
        int32_T tmp_size_bj;
        int32_T tmp_size_j;
        int32_T b_size_idx_0;
        int32_T unnamed_idx_0;
        int32_T loop_ub_tmp_tmp;
        int32_T i;
        uint32_T u;
    };

    // Block states (default storage) for system '<S61>/Apply Elevation and NaN and Zero Mask'
    struct DW_ApplyElevationandNaNandZer_T
    {
        GNSS_Measurement_size SFunction_DIMS2;// '<S61>/Apply Elevation and NaN and Zero Mask'
        uint16_T nanerrs;              // '<S61>/Apply Elevation and NaN and Zero Mask'
    };

    // Block signals for system '<S17>/Simplify and Mask GPS Measurement Bus'
    struct B_SimplifyandMaskGPSMeasureme_T
    {
        emxArray__gnssops_navigation__T r;
        emxArray__gnssops_navigation__T r1;
        emxArray__gnssops_navigation__T r2;
        b_gnssops_navigation_data_GNS_T expl_temp;
        gnssops_navigation_data navdata_L1;// '<S17>/Simplify and Mask GPS Measurement Bus'
        gnssops_navigation_data navdata_L2C;// '<S17>/Simplify and Mask GPS Measurement Bus'
        gnssops_navigation_data navdata_L5;// '<S17>/Simplify and Mask GPS Measurement Bus'
        gnssops_navigation_data r3;
        real_T tmp_pr_data[200];
        real_T tmp_pr_sigma_data[200];
        real_T tmp_cp_data[200];
        real_T tmp_cp_sigma_data[200];
        real_T gnss_freq_Matrix_data[200];
        real_T tmp_dr_data[200];
        real_T in2_data[200];
        real32_T tmp_Locktime_data[200];
        real_T pr_L1[40];              // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T pr_sigma_L1[40];        // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T dr_L1[40];              // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T cn0_L1[40];             // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T cp_L1[40];              // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T cp_sigma_L1[40];        // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T pr_L2C[40];             // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T pr_sigma_L2C[40];       // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T dr_L2C[40];             // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T cn0_L2C[40];            // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T cp_L2C[40];             // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T cp_sigma_L2C[40];       // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T pr_L5[40];              // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T pr_sigma_L5[40];        // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T dr_L5[40];              // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T cn0_L5[40];             // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T cp_L5[40];              // '<S17>/Simplify and Mask GPS Measurement Bus'
        real_T cp_sigma_L5[40];        // '<S17>/Simplify and Mask GPS Measurement Bus'
        uint8_T tmp_type_data[200];
        uint8_T fb_data[200];
        uint8_T gb_data[200];
        uint8_T hb_data[200];
        uint8_T ib_data[200];
        uint8_T jb_data[200];
        uint8_T kb_data[200];
        uint8_T lb_data[200];
        uint8_T mb_data[200];
        uint8_T nb_data[200];
        uint8_T ob_data[200];
        uint8_T pb_data[200];
        uint8_T qb_data[200];
        uint8_T rb_data[200];
        uint8_T sb_data[200];
        uint8_T tb_data[200];
        uint8_T ub_data[200];
        uint8_T vb_data[200];
        uint8_T wb_data[200];
        uint8_T xb_data[200];
        uint8_T yb_data[200];
        uint8_T ac_data[200];
        boolean_T L1_mask_data[200];
        boolean_T L2C_mask_data[200];
        boolean_T L5_mask_data[200];
        int32_T iidx_data[40];
        int32_T iwork_data[40];
        real32_T Locktime_L1[40];      // '<S17>/Simplify and Mask GPS Measurement Bus'
        real32_T Locktime_L2C[40];     // '<S17>/Simplify and Mask GPS Measurement Bus'
        real32_T Locktime_L5[40];      // '<S17>/Simplify and Mask GPS Measurement Bus'
        uint16_T svid_L1[40];          // '<S17>/Simplify and Mask GPS Measurement Bus'
        uint16_T svid_L2C[40];         // '<S17>/Simplify and Mask GPS Measurement Bus'
        uint16_T svid_L5[40];          // '<S17>/Simplify and Mask GPS Measurement Bus'
        uint16_T tmp_svid_data[40];
        uint16_T a__1_data[40];
        uint16_T f_data[40];
        uint16_T h_data[40];
        uint16_T l_data[40];
        uint16_T b_x_data[40];
        uint16_T xwork_data[40];
        int8_T n_data[40];
        int8_T o_data[40];
        int8_T p_data[40];
        int8_T q_data[40];
        int8_T r_data[40];
        int8_T s_data[40];
        int8_T t_data[40];
        int8_T u_data[40];
        int8_T v_data[40];
        int8_T w_data[40];
        int8_T x_data[40];
        int8_T y_data[40];
        int8_T ab_data[40];
        int8_T bb_data[40];
        int8_T cb_data[40];
        int8_T db_data[40];
        int8_T eb_data[40];
        boolean_T mask_available_SV_data[40];
        boolean_T dc[40];
        boolean_T bv[40];
        boolean_T mask_navdata_L1_data[37];
        int8_T b_data[37];
        int8_T c_data[37];
        int8_T d_data[37];
        int8_T e_data[37];
        int8_T f_data_m[37];
        int8_T g_data[37];
        int8_T h_data_c[37];
        int8_T i_data[37];
        int8_T j_data[37];
        int8_T k_data[37];
        int8_T l_data_k[37];
        int8_T m_data[37];
        int8_T n_data_c[37];
        int8_T o_data_b[37];
        int8_T p_data_p[37];
        int8_T q_data_c[37];
        int8_T r_data_f[37];
        int8_T s_data_g[37];
        int8_T t_data_g[37];
        int8_T u_data_m[37];
        int8_T v_data_n[37];
        int8_T w_data_p[37];
        int8_T x_data_l[37];
        int8_T y_data_j[37];
        int32_T ec_data[4];
        uint16_T x4[4];
        real_T TOW;                    // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T gnss_freq_Matrix_size[2];
        int32_T a__1_size[2];
        int32_T L1_mask_size[2];
        int32_T L2C_mask_size[2];
        int32_T L5_mask_size[2];
        int32_T u_size[2];
        int32_T db_size[2];
        int32_T ec_size[2];
        int32_T b_x_size[2];
        int8_T idx4[4];
        int8_T perm[4];
        int32_T trueCount;
        int32_T c_i;
        int32_T tmp_svid;
        int32_T loop_ub;
        int32_T mask_navdata_L1_size;
        int32_T n_size_idx_1;
        int32_T o_size_idx_1;
        int32_T w_size_idx_1;
        int32_T c_trueCount_tmp;
        boolean_T rtu_GpsMeasurementBus[4];
    };

    // Block states (default storage) for system '<S17>/Simplify and Mask GPS Measurement Bus'
    struct DW_SimplifyandMaskGPSMeasurem_T
    {
        gnssops_navigation_data_size SFunction_DIMS4;// '<S17>/Simplify and Mask GPS Measurement Bus'
        gnssops_navigation_data_size SFunction_DIMS13;// '<S17>/Simplify and Mask GPS Measurement Bus'
        gnssops_navigation_data_size SFunction_DIMS22;// '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS3;       // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS5;       // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS6;       // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS7;       // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS8;       // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS9;       // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS10;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS11;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS12;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS14;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS15;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS16;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS17;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS18;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS19;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS20;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS21;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS23;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS24;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS25;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS26;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS27;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS28;      // '<S17>/Simplify and Mask GPS Measurement Bus'
        int32_T SFunction_DIMS29;      // '<S17>/Simplify and Mask GPS Measurement Bus'
    };

    // Block signals for system '<S5>/GPS'
    struct B_GPS_GNSSPreProcessingDualAn_T
    {
        GNSS_Measurement BusConversion_InsertedFor_d;
        GNSS_Measurement measurementBusL1_WL;// '<S57>/Calculate Wide Lane Combination'
        GNSS_Measurement measurementFrequencyCorrect;// '<S61>/Apply Non Dual Frequency GPS Satellite Mask'
        gnssraw_gps_nav_t BusConversion_InsertedFor_N;
        real_T deltarange_satclk_corrected[40];// '<S17>/Bus Selector'
        real_T variance_pseudorange[40];// '<S17>/Bus Selector'
        real_T variance_pseudorange_measured[40];// '<S17>/Bus Selector'
        real_T variance_deltarange[40];// '<S17>/Bus Selector'
        real_T carrierphase[40];       // '<S17>/Bus Selector'
        real_T carrierphase_raw[40];   // '<S17>/Bus Selector'
        real_T carrierphase_satclk_corrected[40];// '<S17>/Bus Selector'
        real_T variance_carrierphase_measured[40];// '<S17>/Bus Selector'
        real_T CN0[40];                // '<S17>/Bus Selector'
        int32_T iia_data[40];
        int32_T iib_data[40];
        uint16_T a__1_data[40];
        gnssraw_gps_ion_t BusConversion_InsertedFor_o;
        real_T time_receive;           // '<S17>/Bus Selector'
        real_T satellite_position[120];// '<S17>/Bus Selector'
        real_T satellite_velocity[120];// '<S17>/Bus Selector'
        real_T pseudorange[40];        // '<S17>/Bus Selector'
        real_T pseudorange_raw[40];    // '<S17>/Bus Selector'
        real_T pseudorange_satclk_corrected[40];// '<S17>/Bus Selector'
        real_T deltarange[40];         // '<S17>/Bus Selector'
        real_T deltarange_raw[40];     // '<S17>/Bus Selector'
        real_T base_position[3];       // '<S17>/Bus Selector'
        real32_T locktime[40];         // '<S17>/Bus Selector'
        uint16_T PRN[40];              // '<S17>/Bus Selector'
        uint16_T SvidCarrierInUse[40]; // '<S57>/Calculate Wide Lane Combination'
        real_T removedSats;            // '<S60>/Create Satellite Elevation Mask'
        int32_T i;
        int32_T loop_ub;
        int32_T scalarLB;
        int32_T vectorUB;
        int32_T iia_size;
        int32_T iib_size;
        int32_T a__1_size;
        int32_T SVID_DIMS1;
        int32_T SVID_DIMS1_m;
        int32_T SFunction_DIMS2;
        int32_T SFunction_DIMS4;
        int32_T unnamed_idx_0;
        int32_T unnamed_idx_0_c;
        int32_T BusSelector_DIMS9_tmp_tmp;
        int32_T BusSelector_DIMS10_tmp_tmp;
        int32_T BusSelector_DIMS11_tmp_tmp;
        int32_T BusSelector_DIMS12_tmp_tmp;
        int32_T BusSelector_DIMS13_tmp_tmp;
        int32_T BusSelector_DIMS14_tmp_tmp;
        int32_T BusSelector_DIMS15_tmp_tmp;
        int32_T BusSelector_DIMS16_tmp_tmp;
        int32_T BusSelector_DIMS17_tmp_tmp;
        int32_T BusSelector_DIMS18_tmp_tmp;
        int32_T BusSelector_DIMS19_tmp_tmp;
        int32_T ncmax;
        int32_T nc;
        int32_T iafirst;
        int32_T ialast;
        int32_T ibfirst;
        int32_T iblast;
        int32_T b_ialast;
        int32_T b_iblast;
        int32_T i_k;
        int32_T stride_0_0;
        int32_T stride_1_0;
        int32_T loop_ub_c;
        parameters_gps_t parameters_gps_Bus;// '<S27>/MATLAB Function1'
        uint16_T nan_errCnt;           // '<S61>/Apply Elevation and NaN and Zero Mask'
        uint16_T ak;
        uint16_T bk;
        boolean_T LogicalOperator1;    // '<S29>/Logical Operator1'
        boolean_T enableDualFrequencyCorrecti;// '<S57>/MATLAB Function'
        boolean_T enableKlobucharCorrection;// '<S57>/MATLAB Function'
        boolean_T LogicalOperator2_g;  // '<S27>/Logical Operator2'
        boolean_T MeasurementCorrected;// '<S61>/Apply Differential Correction Mask1'
        B_SimplifyandMaskGPSMeasureme_T sf_SimplifyandMaskGPSMeasuremen;// '<S17>/Simplify and Mask GPS Measurement Bus' 
        B_ApplyElevationandNaNandZero_T sf_ApplyElevationandNaNandZeroM;// '<S61>/Apply Elevation and NaN and Zero Mask' 
        B_ApplyDifferentialCorrection_T sf_ApplyDifferentialCorrectionM;// '<S61>/Apply Differential Correction Mask1'
        B_CreateSatelliteElevationMas_T sf_CreateSatelliteElevationMask;// '<S60>/Create Satellite Elevation Mask'
        B_CalculateTroposphericCorrec_T sf_CalculateTroposphericCorrect;// '<S29>/Calculate Tropospheric Corrections'
        B_CalculateKlobucharModelCorr_T sf_CalculateKlobucharModelCorre;// '<S57>/Calculate Klobuchar Model Correction'
        B_CalculateDualfrequencyCorre_T sf_CalculateDualfrequencyCorrec;// '<S57>/Calculate Dualfrequency Correction with L1 and L2C' 
        B_CalculateDifferentialCorrec_T sf_CalculateDifferentialCorrect;// '<S29>/Calculate Differential Corrections'
        B_NavigationDataConversionGPS_T sf_NavigationDataConversionGPS;// '<S17>/Navigation Data Conversion GPS'
        B_GPSsinglefrequencystream_GN_T GPSL5Stream;// '<S17>/GPS L5 Stream'
        B_GPSsinglefrequencystream_GN_T GPSL2CStream;// '<S17>/GPS L2C Stream'
        B_GPSsinglefrequencystream_GN_T GPSL1Stream;// '<S17>/GPS L1 Stream'
    };

    // Block states (default storage) for system '<S5>/GPS'
    struct DW_GPS_GNSSPreProcessingDualA_T
    {
        GNSS_Measurement_size BusConversion_InsertedFor_Calcu;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Cal_c;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Cal_l;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Cal_i;// synthesized block
        GNSS_Measurement_size BusAssignment2_DIMS1;// '<S57>/Bus Assignment2'
        GNSS_Measurement_size BusAssignment2_DIMS1_j;// '<S29>/Bus Assignment2'
        GNSS_Measurement_size SFunction_DIMS2;// '<S61>/Apply Non Dual Frequency GPS Satellite Mask'
        GNSS_Measurement_size SFunction_DIMS3;// '<S57>/Calculate Wide Lane Combination'
        int32_T BusSelector1_DIMS1;    // '<S57>/Bus Selector1'
        int32_T BusSelector2_DIMS1;    // '<S29>/Bus Selector2'
        int32_T BusSelector_DIMS2[2];  // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS3[2];  // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS4;     // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS5;     // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS6;     // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS7;     // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS8;     // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS9;     // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS10;    // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS11;    // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS12;    // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS13;    // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS14;    // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS15;    // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS16;    // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS17;    // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS18;    // '<S17>/Bus Selector'
        int32_T BusSelector_DIMS19;    // '<S17>/Bus Selector'
        int32_T SFunction_DIMS2_k;     // '<S57>/Calculate Wide Lane Combination'
        DW_SimplifyandMaskGPSMeasurem_T sf_SimplifyandMaskGPSMeasuremen;// '<S17>/Simplify and Mask GPS Measurement Bus' 
        DW_ApplyElevationandNaNandZer_T sf_ApplyElevationandNaNandZeroM;// '<S61>/Apply Elevation and NaN and Zero Mask' 
        DW_ApplyDifferentialCorrectio_T sf_ApplyDifferentialCorrectionM;// '<S61>/Apply Differential Correction Mask1'
        DW_CreateSatelliteElevationMa_T sf_CreateSatelliteElevationMask;// '<S60>/Create Satellite Elevation Mask'
        DW_CalculateTroposphericCorre_T sf_CalculateTroposphericCorrect;// '<S29>/Calculate Tropospheric Corrections'
        DW_CalculateKlobucharModelCor_T sf_CalculateKlobucharModelCorre;// '<S57>/Calculate Klobuchar Model Correction'
        DW_CalculateDualfrequencyCorr_T sf_CalculateDualfrequencyCorrec;// '<S57>/Calculate Dualfrequency Correction with L1 and L2C' 
        DW_CalculateDifferentialCorre_T sf_CalculateDifferentialCorrect;// '<S29>/Calculate Differential Corrections'
        DW_NavigationDataConversionGP_T sf_NavigationDataConversionGPS;// '<S17>/Navigation Data Conversion GPS'
        DW_GPSsinglefrequencystream_G_T GPSL5Stream;// '<S17>/GPS L5 Stream'
        DW_GPSsinglefrequencystream_G_T GPSL2CStream;// '<S17>/GPS L2C Stream'
        DW_GPSsinglefrequencystream_G_T GPSL1Stream;// '<S17>/GPS L1 Stream'
    };

    // Block signals for system '<S18>/Galileo E1 stream'
    struct B_Galileosinglefrequencystrea_T
    {
        real_T TOW;                    // '<S71>/TOW'
        real_T CN0[40];                // '<S71>/CN0'
        real_T measured_pr_sigma[40];  // '<S71>/measured_pr_sigma'
        real_T measured_cp_sigma[40];  // '<S71>/measured_cp_sigma'
        real_T basePosition[3];        // '<S71>/basePos'
        real32_T Locktime[40];         // '<S71>/locktime'
        uint16_T PRN[40];              // '<S71>/SVID'
        int32_T i;
        B_SignalNoiseVariance_GNSSPre_T sf_SignalNoiseVariance;// '<S71>/Signal Noise Variance'
        B_TimeCorrectionPseudorange_G_T sf_TimeCorrectionPseudorange;// '<S81>/Time Correction Pseudorange'
        B_TimeCorrectionDeltarange_GN_T sf_TimeCorrectionDeltarange;// '<S81>/Time Correction Deltarange'
        B_TimeCorrectionCarrierphase__T sf_TimeCorrectionCarrierphase;// '<S81>/Time Correction Carrierphase'
        B_CalculateSatellitePositiona_T sf_CalculateSatellitePositionan;// '<S81>/Calculate Satellite Position and Velocity' 
        B_CalculateSatelliteClockCorr_T sf_CalculateSatelliteClockCorre;// '<S81>/Calculate Satellite Clock Correction'
    };

    // Block states (default storage) for system '<S18>/Galileo E1 stream'
    struct DW_Galileosinglefrequencystre_T
    {
        int32_T SVID_DIMS1;            // '<S71>/SVID'
        int32_T CN0_DIMS1;             // '<S71>/CN0'
        int32_T measured_pr_sigma_DIMS1;// '<S71>/measured_pr_sigma'
        int32_T measured_cp_sigma_DIMS1;// '<S71>/measured_cp_sigma'
        int32_T locktime_DIMS1;        // '<S71>/locktime'
        DW_SignalNoiseVariance_GNSSPr_T sf_SignalNoiseVariance;// '<S71>/Signal Noise Variance'
        DW_TimeCorrectionPseudorange__T sf_TimeCorrectionPseudorange;// '<S81>/Time Correction Pseudorange'
        DW_TimeCorrectionDeltarange_G_T sf_TimeCorrectionDeltarange;// '<S81>/Time Correction Deltarange'
        DW_TimeCorrectionCarrierphase_T sf_TimeCorrectionCarrierphase;// '<S81>/Time Correction Carrierphase'
        DW_CalculateSatellitePosition_T sf_CalculateSatellitePositionan;// '<S81>/Calculate Satellite Position and Velocity' 
        DW_CalculateSatelliteClockCor_T sf_CalculateSatelliteClockCorre;// '<S81>/Calculate Satellite Clock Correction'
    };

    // Block signals for system '<S18>/Navigation Data Conversion GAL'
    struct B_NavigationDataConversionGAL_T
    {
        gnssops_navigation_data GAL_NavigationData_Bus;// '<S18>/Navigation Data Conversion GAL'
    };

    // Block states (default storage) for system '<S18>/Navigation Data Conversion GAL'
    struct DW_NavigationDataConversionGA_T
    {
        gnssops_navigation_data_size SFunction_DIMS2;// '<S18>/Navigation Data Conversion GAL'
    };

    // Block signals for system '<S76>/Calculate Differential Corrections'
    struct B_CalculateDifferentialCorr_m_T
    {
        real_T real_delta_data[111];
        real_T b_a_data[111];
        real_T diffPseudorangeCorrection[40];// '<S76>/Calculate Differential Corrections'
        real_T b_data[40];
        real_T in1_data[40];
        real_T navdata_DELTA_N_data[37];
        real_T navdata_M_0_data[37];
        real_T navdata_E_data[37];
        real_T navdata_SQRT_A_data[37];
        real_T navdata_T_oe_data[37];
        real_T real_range_data[37];
        real_T t_sv_emission_data[37];
        real_T t_d_data[37];
        real_T t_k_data[37];
        real_T E_k_data[37];
        real_T n_0_data[37];
        real_T E_k_old_data[37];
        real_T rtu_gpsNavDataBusL1_data[37];
        real_T rtu_gpsNavDataBusL1_data_m[37];
        real_T rtu_gpsNavDataBusL1_data_c[37];
        real_T rtu_gpsNavDataBusL1_data_k[37];
        real_T rtu_gpsNavDataBusL1_data_cx[37];
        real_T rtu_gpsNavDataBusL1_data_b[37];
        real_T rtu_gpsNavDataBusL1_data_p[37];
        real_T in1_data_c[37];
        real_T in1_data_f[37];
        real_T in1_data_g[37];
        real_T in1_data_g1[37];
        real_T in1_data_m[37];
        real_T in1_data_n[37];
        real_T in1_data_p[37];
        real_T in1_data_l[37];
        real_T in1_data_j[37];
        real_T in1_data_d[37];
        real_T in1_data_gu[37];
        real_T in9_data[37];
        real_T t_k_data_l[37];
        real_T cosinus_E_k_data[37];
        real_T sinus_E_k_data[37];
        real_T PHI_k_data[37];
        real_T sin2PHI_k_data[37];
        real_T cos2PHI_k_data[37];
        real_T r_k_data[37];
        real_T i_k_data[37];
        real_T cosinus_u_k_data[37];
        real_T cosinus_i_k_data[37];
        real_T sinus_lambda_k_data[37];
        real_T PHI_k_Dot_data[37];
        real_T r_k_Dot_data[37];
        real_T E_k_Dot_data[37];
        real_T y_tmp_data[37];
        real_T c_data[37];
        real_T X_k_tmp_data[37];
        real_T d_data[37];
        real_T f_data[37];
        real_T tmp_data[37];
        real_T M_k_data[37];
        real_T eps_data[37];
        real_T E_k_old_data_d[37];
        real_T in2_data[37];
        real_T in2_data_d[37];
        real_T in5_data[37];
        real_T tmp_data_l[37];
        real_T in2_data_o[37];
        real_T in5_data_b[37];
        real_T in1_data_nu[37];
        real_T in2_data_b[37];
        real_T in1_data_ln[37];
        real_T tmp_data_h[37];
        real_T in1_data_b[37];
        real_T in1_data_da[37];
        real_T in2_data_e[37];
        real_T in2_data_bj[37];
        real_T in1_data_jz[37];
        real_T in2_data_f[37];
        real_T in1_data_a[37];
        real_T in2_data_j[37];
        real_T in2_data_jz[37];
        real_T in2_data_o4[37];
        int32_T iidx_data[40];
        int32_T b_idx_data[40];
        int32_T iwork_data[40];
        int32_T iia_data[37];
        int32_T iib_data[37];
        uint16_T maskDiffCorr[40];     // '<S76>/Calculate Differential Corrections'
        uint16_T a_data[40];
        uint16_T vwork_data[40];
        uint16_T b_x_data[40];
        real_T sv_pos_tmp[9];
        real_T dv[9];
        boolean_T t_k_data_n[37];
        boolean_T eps_data_i[37];
        real_T sv_pos_tmp_o[3];
        uint16_T x4[4];
        real_T t_d;
        real_T y_user;
        real_T z_user;
        real_T N;
        real_T sinus_lambda_k;
        real_T varargin_1;
        real_T varargin_1_n;
        real_T varargin_1_m;
        real_T varargin_1_c;
        real_T in2_tmp;
        real_T varargin_1_md;
        real_T d;
        real_T d1;
        real_T varargin_1_m3;
        int32_T navdata_DELTA_N_size[2];
        int32_T navdata_M_0_size[2];
        int32_T navdata_E_size[2];
        int32_T navdata_SQRT_A_size[2];
        int32_T navdata_T_oe_size[2];
        int32_T real_delta_size[2];
        int32_T t_sv_emission_size[2];
        int32_T t_d_size[2];
        int32_T t_k_size[2];
        int32_T E_k_size[2];
        int32_T n_0_size[2];
        int32_T E_k_old_size[2];
        int32_T t_k_size_j[2];
        int32_T rtu_gpsNavDataBusL1_size[2];
        int32_T rtu_gpsNavDataBusL1_size_h[2];
        int32_T rtu_gpsNavDataBusL1_size_c[2];
        int32_T rtu_gpsNavDataBusL1_size_ct[2];
        int32_T rtu_gpsNavDataBusL1_size_p[2];
        int32_T rtu_gpsNavDataBusL1_size_p5[2];
        int32_T rtu_gpsNavDataBusL1_size_a[2];
        int32_T t_sv_emission_size_e[2];
        int32_T in1_size[2];
        int32_T in1_size_a[2];
        int32_T in1_size_as[2];
        int32_T in1_size_i[2];
        int32_T in1_size_l[2];
        int32_T in1_size_o[2];
        int32_T in1_size_o2[2];
        int32_T in1_size_ip[2];
        int32_T in1_size_f[2];
        int32_T in1_size_iz[2];
        int32_T in1_size_ff[2];
        int32_T in9_size[2];
        int32_T t_k_size_g[2];
        int32_T cosinus_E_k_size[2];
        int32_T sinus_E_k_size[2];
        int32_T PHI_k_size[2];
        int32_T sin2PHI_k_size[2];
        int32_T cos2PHI_k_size[2];
        int32_T r_k_size[2];
        int32_T i_k_size[2];
        int32_T cosinus_u_k_size[2];
        int32_T cosinus_i_k_size[2];
        int32_T sinus_lambda_k_size[2];
        int32_T PHI_k_Dot_size[2];
        int32_T r_k_Dot_size[2];
        int32_T E_k_Dot_size[2];
        int32_T y_tmp_size[2];
        int32_T c_size[2];
        int32_T X_k_tmp_size[2];
        int32_T d_size[2];
        int32_T f_size[2];
        int32_T tmp_size[2];
        int32_T M_k_size[2];
        int32_T E_k_old_size_c[2];
        int32_T eps_size[2];
        int32_T in2_size[2];
        int32_T in5_size[2];
        int32_T tmp_size_o[2];
        int32_T in2_size_l[2];
        int32_T in5_size_m[2];
        int8_T idx4[4];
        int8_T perm[4];
        int32_T i;
        int32_T k;
        int32_T acoef;
        int32_T vstride;
        int32_T xoffset;
        int32_T scalarLB;
        int32_T real_range_size;
        int32_T iidx_size;
        int32_T iia_size;
        int32_T iib_size;
        int32_T a_size;
        int32_T rtu_gpsNavDataBusL1_DIMS1;
        int32_T i_m;
        int32_T loop_ub;
        int32_T stride_0_1;
        int32_T stride_1_1;
        int32_T loop_ub_c;
        int32_T scalarLB_f;
        int32_T vectorUB;
        int32_T transport_angle_size;
        int32_T t_k_data_tmp;
        int32_T scalarLB_tmp;
        int32_T i_p;
        int32_T loop_ub_e;
        int32_T scalarLB_o;
        int32_T vectorUB_h;
        int32_T eps_size_idx_1;
        int32_T varargin_1_tmp;
        int32_T i1;
        int32_T stride_0_1_l;
        int32_T stride_1_1_h;
        int32_T stride_2_1;
        int32_T loop_ub_m;
        int32_T in2_size_idx_1;
        int32_T i2;
        int32_T stride_0_1_m;
        int32_T stride_1_1_h3;
        int32_T stride_2_1_c;
        int32_T loop_ub_k;
        int32_T loop_ub_p;
        int32_T r_data_tmp;
        int32_T f;
        int32_T k_p;
        int32_T i3;
        int32_T i4;
        int32_T i5;
        int32_T stride_0_1_p;
        int32_T stride_1_1_a;
        int32_T stride_2_1_j;
        int32_T loop_ub_ek;
        int32_T dim;
        int32_T vstride_o;
        int32_T b;
        int32_T b_i;
        int32_T nDone;
        int32_T nLeft;
        int32_T i1_b;
        int32_T i2_a;
        int32_T i3_g;
        int32_T i4_e;
        int32_T i6;
        int32_T b_x_size;
        int32_T vwork_size_idx_0;
        int32_T nQuartets_tmp;
        int32_T p;
        int32_T q;
        int32_T i7;
        int32_T stride_0_1_f;
        int32_T stride_1_1_h2;
        int32_T stride_2_1_e;
        int32_T loop_ub_ch;
        int32_T in1_size_idx_1;
        int32_T i8;
        int32_T stride_0_1_a;
        int32_T stride_1_1_d;
        int32_T loop_ub_a;
        int32_T in2_size_idx_1_p;
        int32_T i9;
        int32_T stride_0_1_ms;
        int32_T stride_1_1_o;
        int32_T loop_ub_n;
        int32_T in1_size_idx_1_l;
        int32_T i10;
        int32_T stride_0_1_pe;
        int32_T stride_1_1_p;
        int32_T stride_2_1_f;
        int32_T stride_3_1;
        int32_T stride_4_1;
        int32_T stride_5_1;
        int32_T loop_ub_i;
        int32_T tmp_size_idx_1;
        int32_T i11;
        int32_T stride_0_1_o;
        int32_T stride_1_1_k;
        int32_T stride_2_1_i;
        int32_T stride_3_1_o;
        int32_T stride_4_1_m;
        int32_T loop_ub_cu;
        int32_T in1_size_idx_1_f;
        int32_T i12;
        int32_T stride_0_1_h;
        int32_T stride_1_1_m;
        int32_T stride_2_1_a;
        int32_T stride_3_1_k;
        int32_T loop_ub_pc;
        int32_T in1_size_idx_1_b;
        int32_T i13;
        int32_T stride_0_1_c;
        int32_T stride_1_1_n;
        int32_T stride_2_1_ij;
        int32_T stride_3_1_m;
        int32_T loop_ub_j;
        int32_T in2_size_idx_1_e;
        int32_T i14;
        int32_T stride_0_1_mv;
        int32_T stride_1_1_m0;
        int32_T stride_2_1_jg;
        int32_T stride_3_1_f;
        int32_T loop_ub_a5;
        int32_T in2_size_idx_1_g;
        int32_T i15;
        int32_T stride_0_1_n;
        int32_T stride_1_1_d3;
        int32_T stride_2_1_n;
        int32_T loop_ub_cg;
        int32_T in1_size_idx_1_fx;
        int32_T i16;
        int32_T stride_0_1_pm;
        int32_T stride_1_1_p2;
        int32_T loop_ub_nj;
        int32_T in2_size_idx_1_k;
        int32_T i17;
        int32_T stride_0_1_n3;
        int32_T stride_1_1_oy;
        int32_T loop_ub_g;
        int32_T in1_size_idx_1_c;
        int32_T i18;
        int32_T stride_0_1_cj;
        int32_T stride_1_1_m1;
        int32_T stride_2_1_jp;
        int32_T stride_3_1_kn;
        int32_T stride_4_1_mx;
        int32_T stride_5_1_p;
        int32_T i19;
        int32_T i20;
        int32_T stride_0_1_d;
        int32_T stride_1_1_g;
        int32_T i21;
        int32_T stride_0_1_c3;
        int32_T stride_1_1_c;
        int32_T stride_2_1_if;
        int32_T stride_3_1_d;
        int32_T stride_4_1_g;
        int32_T stride_5_1_l;
        int32_T stride_6_1;
        int32_T stride_7_1;
        int32_T stride_8_1;
        int32_T loop_ub_f;
        int32_T i22;
        int32_T stride_0_1_db;
        int32_T stride_1_1_j;
        int32_T stride_2_1_i3;
        int32_T loop_ub_h;
        int32_T i23;
        int32_T stride_0_1_nm;
        int32_T stride_1_1_o3;
        int32_T stride_2_1_ch;
        int32_T loop_ub_b;
        int32_T i24;
        int32_T stride_0_0;
        int32_T stride_1_0;
        int32_T stride_2_0;
        int32_T stride_3_0;
        int32_T stride_4_0;
        int32_T stride_5_0;
        int32_T stride_6_0;
        int32_T stride_7_0;
        int32_T stride_8_0;
        int32_T in1_idx_0;
        int32_T i25;
        int32_T stride_0_0_e;
        int32_T stride_1_0_d;
        int32_T stride_2_0_i;
        int32_T stride_3_0_g;
        int32_T stride_4_0_n;
        int32_T stride_5_0_l;
        int32_T stride_6_0_c;
        int32_T stride_7_0_n;
        int32_T stride_8_0_p;
        int32_T in2_idx_0;
        int32_T i26;
        int32_T stride_0_1_dk;
        int32_T stride_1_1_oi;
        int32_T stride_2_1_jr;
        int32_T stride_3_1_c;
        int32_T stride_4_1_h;
        int32_T stride_5_1_d;
        int32_T loop_ub_c5;
        int32_T i27;
        int32_T stride_0_1_pw;
        int32_T stride_1_1_pi;
        int32_T stride_2_1_a4;
        int32_T stride_3_1_ow;
        int32_T stride_4_1_j;
        int32_T stride_5_1_pi;
        int32_T stride_6_1_o;
        int32_T loop_ub_l;
        int32_T ix;
        int32_T b_k;
        int32_T k_j;
        int32_T scalarLB_fz;
        int32_T vectorUB_c;
        int32_T b_f;
        int32_T k_n;
        int32_T scalarLB_i;
        int32_T vectorUB_l;
        int8_T csz_idx_1;
        boolean_T d_i;
        boolean_T e;
    };

    // Block states (default storage) for system '<S76>/Calculate Differential Corrections'
    struct DW_CalculateDifferentialCor_c_T
    {
        emxArray_real_T_40_GNSSPrePro_T delta_pr2;// '<S76>/Calculate Differential Corrections'
        emxArray_uint16_T_37_GNSSPreP_T PRNs;// '<S76>/Calculate Differential Corrections'
        real_T old_t;                  // '<S76>/Calculate Differential Corrections'
        int32_T SFunction_DIMS2;       // '<S76>/Calculate Differential Corrections'
        int32_T SFunction_DIMS3;       // '<S76>/Calculate Differential Corrections'
        boolean_T delta_pr2_not_empty; // '<S76>/Calculate Differential Corrections'
    };

    // Block signals for system '<S76>/Calculate Tropospheric Corrections'
    struct B_CalculateTroposphericCorr_k_T
    {
        real_T troposphericDelay[40];  // '<S76>/Calculate Tropospheric Corrections'
        real_T pressure_data[40];
        real_T temperature_data[40];
        real_T water_vapour_pressure_data[40];
        real_T beta_data[40];
        real_T lambda_data[40];
        real_T d_data[40];
        real_T y_data[40];
        real_T x_data[40];
        real_T b_b_data[40];
        real_T x_tmp_data[40];
        real_T in2_data[40];
        real_T dv[5];
        real_T dv1[5];
        real_T dv2[2];
        real_T dv3[2];
        real_T dv4[2];
        real_T dv5[2];
        real_T dv6[2];
        real_T dv7[2];
        real_T dv8[2];
        real_T dv9[2];
        real_T latitude;
        real_T cosinus_day;
        real_T d;
        real_T varargout_1;
        real_T in2_tmp;
        real_T d1;
        real_T d2;
        real_T r;
        int32_T k;
        int32_T loop_ub;
        int32_T vectorUB;
        int32_T pressure_size;
        int32_T temperature_size;
        int32_T water_vapour_pressure_size;
        int32_T beta_size;
        int32_T lambda_size;
        int32_T d_size;
        int32_T y_size;
        int32_T x_size;
        int32_T b_b_size;
        int32_T x_tmp_size;
        int32_T SFunction_DIMS2_tmp_tmp;
        int32_T i;
        int32_T stride_0_0;
        int32_T stride_1_0;
        int32_T stride_2_0;
        int32_T stride_3_0;
        int32_T stride_4_0;
        int32_T stride_5_0;
        int32_T stride_6_0;
        int32_T stride_7_0;
        int32_T stride_8_0;
        int32_T stride_9_0;
    };

    // Block states (default storage) for system '<S76>/Calculate Tropospheric Corrections'
    struct DW_CalculateTroposphericCor_o_T
    {
        int32_T SFunction_DIMS2;       // '<S76>/Calculate Tropospheric Corrections'
    };

    // Block signals for system '<S117>/Apply Differential Correction Mask1'
    struct B_ApplyDifferentialCorrecti_g_T
    {
        GNSS_Measurement GPS_measurement_Bus_masked;// '<S117>/Apply Differential Correction Mask1'
        real_T tmp_data[40];
        int32_T iia_data[40];
        int32_T iib_data[40];
        uint16_T a__1_data[40];
        int32_T loop_ub;
        int32_T i;
        int32_T i1;
        int32_T loop_ub_m;
        int32_T a__1_size;
    };

    // Block states (default storage) for system '<S117>/Apply Differential Correction Mask1'
    struct DW_ApplyDifferentialCorrect_n_T
    {
        GNSS_Measurement_size SFunction_DIMS2;// '<S117>/Apply Differential Correction Mask1'
    };

    // Block signals for system '<S18>/Simplify and Mask GAL Measurement Bus'
    struct B_SimplifyandMaskGALMeasureme_T
    {
        emxArray__gnssops_navigation__T r;
        emxArray__gnssops_navigation__T r1;
        emxArray__gnssops_navigation__T r2;
        emxArray__gnssops_navigation__T r3;
        b_gnssops_navigation_data_GNS_T expl_temp;
        gnssops_navigation_data navdata_e1;// '<S18>/Simplify and Mask GAL Measurement Bus'
        gnssops_navigation_data navdata_e5a;// '<S18>/Simplify and Mask GAL Measurement Bus'
        gnssops_navigation_data navdata_e5b;// '<S18>/Simplify and Mask GAL Measurement Bus'
        gnssops_navigation_data navdata_e5;// '<S18>/Simplify and Mask GAL Measurement Bus'
        gnssops_navigation_data r4;
        real_T tmp_pr_data[200];
        real_T tmp_pr_sigma_data[200];
        real_T tmp_cp_data[200];
        real_T tmp_cp_sigma_data[200];
        real_T gnss_freq_Matrix_data[200];
        real_T tmp_dr_data[200];
        real_T in2_data[200];
        real32_T tmp_locktime_data[200];
        real_T pr_e1[40];              // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T pr_e1_sigma[40];        // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T dr_e1[40];              // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cn0_e1[40];             // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cp_e1[40];              // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cp_e1_sigma[40];        // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T pr_e5a[40];             // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T pr_e5a_sigma[40];       // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T dr_e5a[40];             // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cn0_e5a[40];            // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cp_e5a[40];             // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cp_e5a_sigma[40];       // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T pr_e5b[40];             // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T pr_e5b_sigma[40];       // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T dr_e5b[40];             // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cn0_e5b[40];            // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cp_e5b[40];             // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cp_e5b_sigma[40];       // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T pr_e5[40];              // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T pr_e5_sigma[40];        // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T dr_e5[40];              // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cn0_e5[40];             // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cp_e5[40];              // '<S18>/Simplify and Mask GAL Measurement Bus'
        real_T cp_e5_sigma[40];        // '<S18>/Simplify and Mask GAL Measurement Bus'
        uint8_T tmp_type_data[200];
        uint8_T hb_data[200];
        uint8_T ib_data[200];
        uint8_T jb_data[200];
        uint8_T kb_data[200];
        uint8_T lb_data[200];
        uint8_T mb_data[200];
        uint8_T nb_data[200];
        uint8_T ob_data[200];
        uint8_T pb_data[200];
        uint8_T qb_data[200];
        uint8_T rb_data[200];
        uint8_T sb_data[200];
        uint8_T tb_data[200];
        uint8_T ub_data[200];
        uint8_T vb_data[200];
        uint8_T wb_data[200];
        uint8_T xb_data[200];
        uint8_T yb_data[200];
        uint8_T ac_data[200];
        uint8_T bc_data[200];
        uint8_T cc_data[200];
        uint8_T dc_data[200];
        uint8_T ec_data[200];
        uint8_T fc_data[200];
        uint8_T gc_data[200];
        uint8_T hc_data[200];
        uint8_T ic_data[200];
        uint8_T jc_data[200];
        boolean_T e1_mask_data[200];
        boolean_T e5a_mask_data[200];
        boolean_T e5b_mask_data[200];
        boolean_T e5_mask_data[200];
        int32_T iidx_data[40];
        int32_T iwork_data[40];
        real32_T locktime_e1[40];      // '<S18>/Simplify and Mask GAL Measurement Bus'
        real32_T locktime_e5a[40];     // '<S18>/Simplify and Mask GAL Measurement Bus'
        real32_T locktime_e5b[40];     // '<S18>/Simplify and Mask GAL Measurement Bus'
        real32_T locktime_e5[40];      // '<S18>/Simplify and Mask GAL Measurement Bus'
        uint16_T svid_e1[40];          // '<S18>/Simplify and Mask GAL Measurement Bus'
        uint16_T svid_e5a[40];         // '<S18>/Simplify and Mask GAL Measurement Bus'
        uint16_T svid_e5b[40];         // '<S18>/Simplify and Mask GAL Measurement Bus'
        uint16_T svid_e5[40];          // '<S18>/Simplify and Mask GAL Measurement Bus'
        uint16_T tmp_svid_data[40];
        uint16_T a__1_data[40];
        uint16_T f_data[40];
        uint16_T h_data[40];
        uint16_T l_data[40];
        uint16_T n_data[40];
        uint16_T b_x_data[40];
        uint16_T xwork_data[40];
        int8_T p_data[40];
        int8_T q_data[40];
        int8_T r_data[40];
        int8_T s_data[40];
        int8_T t_data[40];
        int8_T u_data[40];
        int8_T v_data[40];
        int8_T w_data[40];
        int8_T x_data[40];
        int8_T y_data[40];
        int8_T ab_data[40];
        int8_T bb_data[40];
        int8_T cb_data[40];
        int8_T db_data[40];
        int8_T eb_data[40];
        int8_T fb_data[40];
        int8_T gb_data[40];
        boolean_T mask_available_SV_data[40];
        boolean_T mc[40];
        boolean_T nc[40];
        boolean_T bv[40];
        boolean_T mask_navdata_e1_data[37];
        int8_T b_data[37];
        int8_T c_data[37];
        int8_T d_data[37];
        int8_T e_data[37];
        int8_T f_data_m[37];
        int8_T g_data[37];
        int8_T h_data_c[37];
        int8_T i_data[37];
        int8_T j_data[37];
        int8_T k_data[37];
        int8_T l_data_k[37];
        int8_T m_data[37];
        int8_T n_data_c[37];
        int8_T o_data[37];
        int8_T p_data_b[37];
        int8_T q_data_p[37];
        int8_T r_data_c[37];
        int8_T s_data_f[37];
        int8_T t_data_g[37];
        int8_T u_data_g[37];
        int8_T v_data_m[37];
        int8_T w_data_n[37];
        int8_T x_data_p[37];
        int8_T y_data_l[37];
        int32_T oc_data[5];
        uint16_T x4[4];
        real_T TOW;                    // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T gnss_freq_Matrix_size[2];
        int32_T a__1_size[2];
        int32_T e1_mask_size[2];
        int32_T e5a_mask_size[2];
        int32_T e5b_mask_size[2];
        int32_T e5_mask_size[2];
        int32_T w_size[2];
        int32_T fb_size[2];
        int32_T oc_size[2];
        int32_T b_x_size[2];
        boolean_T rtu_GAL_Measurement_Bus[5];
        int8_T idx4[4];
        int8_T perm[4];
        int32_T trueCount;
        int32_T c_i;
        int32_T c_trueCount;
        int32_T rtu_GAL_Measurement_Bus_j;
        int32_T loop_ub;
        int32_T mask_navdata_e1_size;
        int32_T p_size_idx_1;
        int32_T q_size_idx_1;
        int32_T c_trueCount_tmp;
    };

    // Block states (default storage) for system '<S18>/Simplify and Mask GAL Measurement Bus'
    struct DW_SimplifyandMaskGALMeasurem_T
    {
        gnssops_navigation_data_size SFunction_DIMS4;// '<S18>/Simplify and Mask GAL Measurement Bus'
        gnssops_navigation_data_size SFunction_DIMS13;// '<S18>/Simplify and Mask GAL Measurement Bus'
        gnssops_navigation_data_size SFunction_DIMS22;// '<S18>/Simplify and Mask GAL Measurement Bus'
        gnssops_navigation_data_size SFunction_DIMS31;// '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS3;       // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS5;       // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS6;       // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS7;       // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS8;       // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS9;       // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS10;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS11;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS12;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS14;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS15;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS16;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS17;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS18;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS19;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS20;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS21;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS23;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS24;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS25;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS26;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS27;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS28;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS29;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS30;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS32;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS33;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS34;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS35;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS36;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS37;      // '<S18>/Simplify and Mask GAL Measurement Bus'
        int32_T SFunction_DIMS38;      // '<S18>/Simplify and Mask GAL Measurement Bus'
    };

    // Block signals for system '<S5>/Galileo'
    struct B_Galileo_GNSSPreProcessingDu_T
    {
        GNSS_Measurement measurementFrequencyCorre_o;// '<S117>/Apply Elevation and NaN and Zero Mask'
        gnssraw_gal_nav_t BusConversion_InsertedFo_ea;
        real_T fixed_f1[150];
        real_T fixed_f2[150];
        real_T fixed_f1_m[150];
        real_T fixed_f2_c[150];
        real_T fixed_f1_k[150];
        real_T fixed_f2_cx[150];
        real_T fixed_f1_b[150];
        real_T fixed_f2_p[150];
        real_T satellite_position[120];// '<S18>/Bus Selector'
        real_T satellite_velocity[120];// '<S18>/Bus Selector'
        real_T rtb_BusConversion_InsertedFo_cv[120];
        real_T rtb_BusConversion_InsertedFo_fq[120];
        real_T rtb_measurementFrequency_Bus_sa[120];
        real_T rtb_measurementFrequency_Bus__g[120];
        int32_T l_data[150];
        int32_T l_data_m[150];
        int32_T l_data_n[150];
        int32_T l_data_p[150];
        real_T pseudorange[40];        // '<S18>/Bus Selector'
        real_T pseudorange_raw[40];    // '<S18>/Bus Selector'
        real_T pseudorange_satclk_corrected[40];// '<S18>/Bus Selector'
        real_T deltarange[40];         // '<S18>/Bus Selector'
        real_T deltarange_raw[40];     // '<S18>/Bus Selector'
        real_T deltarange_satclk_corrected[40];// '<S18>/Bus Selector'
        real_T variance_pseudorange[40];// '<S18>/Bus Selector'
        real_T variance_pseudorange_measured[40];// '<S18>/Bus Selector'
        real_T variance_deltarange[40];// '<S18>/Bus Selector'
        real_T carrierphase[40];       // '<S18>/Bus Selector'
        real_T carrierphase_raw[40];   // '<S18>/Bus Selector'
        real_T carrierphase_satclk_corrected[40];// '<S18>/Bus Selector'
        real_T variance_carrierphase_measured[40];// '<S18>/Bus Selector'
        real_T CN0[40];                // '<S18>/Bus Selector'
        real_T rtb_BusConversion_InsertedFo_ll[40];
        real_T rtb_BusConversion_InsertedFo_jw[40];
        real_T rtb_BusConversion_InsertedFo_dh[40];
        real_T rtb_BusConversion_InsertedFo_gu[40];
        real_T rtb_BusConversion_InsertedFo_ld[40];
        real_T rtb_BusConversion_InsertedF_dha[40];
        real_T rtb_BusConversion_InsertedFo_dy[40];
        real_T rtb_BusConversion_InsertedFo_lx[40];
        real_T rtb_BusConversion_InsertedFo_ow[40];
        real_T rtb_BusConversion_InsertedFor_b[40];
        real_T rtb_BusConversion_InsertedFo_nu[40];
        real_T rtb_BusConversion_InsertedFo_bs[40];
        real_T rtb_measurementFrequency_Bus_ps[40];
        real_T rtb_measurementFrequency_Bus_de[40];
        real_T rtb_measurementFrequency_Bus__b[40];
        real_T rtb_measurementFrequency_Bus__d[40];
        real_T rtb_measurementFrequency_Bus_va[40];
        real_T rtb_measurementFrequency_Bus_bj[40];
        real_T rtb_measurementFrequency_Bus__j[40];
        real_T rtb_measurementFrequency_Bus_ca[40];
        real_T rtb_measurementFrequency_Bus__a[40];
        real_T rtb_measurementFrequency_Bus_ju[40];
        real_T rtb_measurementFrequency_Bus_jz[40];
        real_T rtb_measurementFrequency_Bus_CN[40];
        real_T dualFrequencyCorrection[40];// '<S113>/Calculate Dualfrequency Correction with E1 and E5'
        real_T Add1_m[40];             // '<S76>/Add1'
        uint16_T fixed_PRN[150];
        uint16_T fixed_PRN_n[150];
        uint16_T fixed_PRN_i[150];
        uint16_T fixed_PRN_o[150];
        int32_T iia_data[40];
        int32_T iib_data[40];
        real32_T rtb_BusConversion_InsertedFo_nv[40];
        real32_T rtb_measurementFrequency_Bus_lo[40];
        boolean_T g_data[150];
        uint8_T h_data[150];
        uint8_T k_data[150];
        boolean_T g_data_c[150];
        uint8_T h_data_m[150];
        uint8_T k_data_m[150];
        boolean_T g_data_j[150];
        uint8_T h_data_h[150];
        uint8_T k_data_c[150];
        boolean_T g_data_ct[150];
        uint8_T h_data_p[150];
        uint8_T k_data_p[150];
        boolean_T tmp_data[120];
        boolean_T tmp_data_a[120];
        boolean_T tmp_data_e[120];
        boolean_T rtb_measurementFrequency_Bus_ax[120];
        boolean_T rtb_measurementFrequency_Bus_as[120];
        boolean_T rtb_measurementFrequency_Bus__i[120];
        boolean_T rtb_measurementFrequency_Bus__l[120];
        boolean_T in4_data[120];
        uint16_T PRNsE1E5a_data[40];
        uint16_T PRNsE1E5_data[40];
        uint16_T PRNsE1E5aE1E5b_intersect_data[40];
        uint16_T rtb_BusConversion_InsertedFo_oj[40];
        uint16_T tmp_data_o[40];
        uint16_T tmp_data_i[40];
        int8_T j_data[40];
        int8_T k_data_f[40];
        int8_T l_data_i[40];
        int8_T m_data[40];
        int8_T n_data[40];
        int8_T o_data[40];
        int8_T p_data[40];
        int8_T q_data[40];
        int8_T b_data[40];
        int8_T c_data[40];
        int8_T d_data[40];
        int8_T e_data[40];
        int8_T f_data[40];
        int8_T g_data_f[40];
        int8_T h_data_g[40];
        int8_T i_data[40];
        int8_T j_data_c[40];
        int8_T k_data_o[40];
        int8_T l_data_l[40];
        int8_T m_data_m[40];
        int8_T n_data_m[40];
        int8_T o_data_c[40];
        int8_T p_data_f[40];
        int8_T q_data_p[40];
        int8_T r_data[40];
        int8_T s_data[40];
        int8_T idx2_data[40];
        int8_T idx1_data[40];
        int8_T idx2_data_e[40];
        int8_T idx1_data_o[40];
        int8_T idx2_data_h[40];
        int8_T idx1_data_l[40];
        int8_T idx2_data_h2[40];
        int8_T idx1_data_m[40];
        boolean_T g_data_m[40];
        boolean_T h_data_h3[40];
        boolean_T mask_all_data[40];
        boolean_T tmp_data_c[40];
        boolean_T tmp_data_k[40];
        boolean_T tmp_data_p[40];
        boolean_T PRNsE1E5aE1E5b_intersect_data_p[40];
        boolean_T rtb_Add1_m_data[40];
        boolean_T tmp_data_p4[40];
        boolean_T tmp_data_ap[40];
        boolean_T tmp_data_j[40];
        boolean_T tmp_data_ek[40];
        boolean_T tmp_data_ol[40];
        boolean_T in7_data[40];
        boolean_T tmp_data_b[40];
        real_T time_receive;           // '<S18>/Bus Selector'
        real_T base_position[3];       // '<S18>/Bus Selector'
        real32_T locktime[40];         // '<S18>/Bus Selector'
        uint16_T PRN[40];              // '<S18>/Bus Selector'
        uint16_T PRN_p[40];            // '<S113>/Bus Selector'
        real_T removedSats_g;          // '<S116>/Create Satellite Elevation Mask'
        real_T d;
        real_T d1;
        real_T d2;
        real_T d3;
        real_T d4;
        real_T d5;
        real_T d6;
        real_T d7;
        int32_T tmp_size[2];
        int32_T tmp_size_a[2];
        int32_T tmp_size_g[2];
        int32_T rtb_measurementFrequency_Bus__e[2];
        int32_T rtb_measurementFrequency_Bus__f[2];
        int32_T rtb_measurementFrequency_Bus__h[2];
        int32_T rtb_measurementFrequency_Bus_ei[2];
        int32_T in4_size[2];
        parameters_galileo_t parameters_galileo_Bus;// '<S70>/MATLAB Function1'
        int32_T idx;
        int32_T ii;
        int32_T end;
        int32_T trueCount;
        int32_T i;
        int32_T vectorUB;
        int32_T PRNsE5E1_size;
        int32_T PRNsE1E5a_size;
        int32_T g_size;
        int32_T iia_size;
        int32_T iib_size;
        int32_T mask_all_size;
        int32_T tmp_size_c;
        int32_T PRNsE1E5aE1E5b_intersect_size;
        int32_T rtb_Add1_m_size;
        int32_T tmp_size_ax;
        int32_T rtb_Add1_m_size_d;
        int32_T tmp_size_af;
        int32_T tmp_size_p;
        int32_T SVID_DIMS1;
        int32_T SVID_DIMS1_m;
        int32_T SVID_DIMS1_o;
        int32_T BusConversion_InsertedFor_Calcu;
        int32_T SVID_DIMS1_n;
        int32_T SVID_DIMS1_l;
        int32_T SVID_DIMS1_p;
        int32_T SVID_DIMS1_pt;
        int32_T SVID_DIMS1_f;
        int32_T j_size_idx_0;
        int32_T k_size_idx_0;
        int32_T l_size_idx_0;
        int32_T m_size_idx_0;
        int32_T BusSelector_DIMS13_tmp_tmp;
        int32_T BusSelector_DIMS14_tmp_tmp;
        int32_T BusSelector_DIMS15_tmp_tmp;
        int32_T BusSelector_DIMS16_tmp_tmp;
        int32_T BusSelector_DIMS17_tmp_tmp;
        int32_T BusSelector_DIMS18_tmp_tmp;
        int32_T BusSelector_DIMS19_tmp_tmp;
        int32_T c;
        int32_T j;
        int32_T i_i;
        int32_T loop_ub;
        int32_T fixed_PRN_size;
        int32_T h_size_idx_0;
        int32_T l_size_idx_0_o;
        int32_T ix;
        int32_T c_k;
        int32_T j_i;
        int32_T i_o;
        int32_T loop_ub_m;
        int32_T fixed_PRN_size_c;
        int32_T h_size_idx_0_f;
        int32_T l_size_idx_0_h;
        int32_T c_m;
        int32_T j_a;
        int32_T i_k;
        int32_T loop_ub_p;
        int32_T fixed_PRN_size_b;
        int32_T h_size_idx_0_c;
        int32_T l_size_idx_0_n;
        int32_T c_i;
        int32_T j_m;
        int32_T i_j;
        int32_T loop_ub_e;
        int32_T fixed_PRN_size_m;
        int32_T h_size_idx_0_m;
        int32_T l_size_idx_0_j;
        int32_T i_f;
        int32_T stride_4_0;
        int32_T stride_5_0;
        int32_T stride_6_0;
        int32_T loop_ub_a;
        int32_T in5_idx_0;
        int32_T in5_idx_1;
        int32_T loop_ub_tmp;
        int32_T loop_ub_tmp_g;
        int32_T tmp_size_n;
        int32_T tmp_size_d;
        int32_T tmp_size_na;
        int32_T tmp_size_cg;
        int32_T tmp_size_f;
        int32_T in7_size;
        int32_T tmp_size_pm;
        int32_T vstride;
        int32_T i2;
        int32_T i1;
        int32_T c_p;
        int32_T j_n;
        int32_T ix_k;
        int32_T ncmax;
        int32_T nc;
        int32_T iafirst;
        int32_T ialast;
        int32_T ibfirst;
        int32_T iblast;
        int32_T b_ialast;
        int32_T b_iblast;
        boolean_T x[4];
        uint16_T PRNsE5E1;
        uint16_T PRN1;
        uint16_T PRN1_n;
        uint16_T PRN1_o;
        uint16_T PRN1_g;
        uint16_T ak;
        uint16_T bk;
        int8_T idx1;
        int8_T idx2;
        int8_T idx1_c;
        int8_T idx2_c;
        int8_T idx1_m;
        int8_T idx2_j;
        int8_T idx1_k;
        int8_T idx2_m;
        boolean_T LogicalOperator2;    // '<S76>/Logical Operator2'
        boolean_T MeasurementCorrected_d;// '<S117>/Apply Differential Correction Mask1'
        boolean_T LogicalOperator_j;   // '<S113>/Logical Operator'
        boolean_T LogicalOperator2_o;  // '<S70>/Logical Operator2'
        B_SimplifyandMaskGALMeasureme_T sf_SimplifyandMaskGALMeasuremen;// '<S18>/Simplify and Mask GAL Measurement Bus' 
        B_ApplyDifferentialCorrecti_g_T sf_ApplyDifferentialCorrectionM;// '<S117>/Apply Differential Correction Mask1'
        B_CreateSatelliteElevationMas_T sf_CreateSatelliteElevationMask;// '<S116>/Create Satellite Elevation Mask'
        B_CalculateTroposphericCorr_k_T sf_CalculateTroposphericCorrect;// '<S76>/Calculate Tropospheric Corrections'
        B_CalculateDifferentialCorr_m_T sf_CalculateDifferentialCorrect;// '<S76>/Calculate Differential Corrections'
        B_NavigationDataConversionGAL_T sf_NavigationDataConversionGAL;// '<S18>/Navigation Data Conversion GAL'
        B_Galileosinglefrequencystrea_T GalileoE5bstream;// '<S18>/Galileo E5b stream'
        B_Galileosinglefrequencystrea_T GalileoE5astream;// '<S18>/Galileo E5a stream'
        B_Galileosinglefrequencystrea_T GalileoE5stream;// '<S18>/Galileo E5 stream'
        B_Galileosinglefrequencystrea_T GalileoE1stream;// '<S18>/Galileo E1 stream'
    };

    // Block states (default storage) for system '<S5>/Galileo'
    struct DW_Galileo_GNSSPreProcessingD_T
    {
        GNSS_Measurement_size BusConversion_InsertedFor_Calcu;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Cal_p;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Cal_o;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Cal_f;// synthesized block
        GNSS_Measurement_size BusAssignment2_DIMS1;// '<S113>/Bus Assignment2'
        GNSS_Measurement_size TmpHiddenBufferAtBusAssignment1;// synthesized block
        GNSS_Measurement_size BusAssignment1_DIMS1;// '<S76>/Bus Assignment1'
        GNSS_Measurement_size SFunction_DIMS2;// '<S117>/Apply Elevation and NaN and Zero Mask'
        GNSS_Measurement_size SFunction_DIMS2_n;// '<S113>/Calculate Dualfrequency Correction with E1 and E5'
        int32_T BusSelector1_DIMS1;    // '<S113>/Bus Selector1'
        int32_T BusSelector_DIMS1;     // '<S76>/Bus Selector'
        int32_T BusSelector_DIMS2[2];  // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS3[2];  // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS4;     // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS5;     // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS6;     // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS7;     // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS8;     // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS9;     // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS10;    // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS11;    // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS12;    // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS13;    // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS14;    // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS15;    // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS16;    // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS17;    // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS18;    // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS19;    // '<S18>/Bus Selector'
        int32_T BusSelector_DIMS1_d;   // '<S113>/Bus Selector'
        int32_T SFunction_DIMS3;       // '<S113>/Calculate Dualfrequency Correction with E1 and E5'
        DW_SimplifyandMaskGALMeasurem_T sf_SimplifyandMaskGALMeasuremen;// '<S18>/Simplify and Mask GAL Measurement Bus' 
        DW_ApplyDifferentialCorrect_n_T sf_ApplyDifferentialCorrectionM;// '<S117>/Apply Differential Correction Mask1'
        DW_CreateSatelliteElevationMa_T sf_CreateSatelliteElevationMask;// '<S116>/Create Satellite Elevation Mask'
        DW_CalculateTroposphericCor_o_T sf_CalculateTroposphericCorrect;// '<S76>/Calculate Tropospheric Corrections'
        DW_CalculateDifferentialCor_c_T sf_CalculateDifferentialCorrect;// '<S76>/Calculate Differential Corrections'
        DW_NavigationDataConversionGA_T sf_NavigationDataConversionGAL;// '<S18>/Navigation Data Conversion GAL'
        DW_Galileosinglefrequencystre_T GalileoE5bstream;// '<S18>/Galileo E5b stream'
        DW_Galileosinglefrequencystre_T GalileoE5astream;// '<S18>/Galileo E5a stream'
        DW_Galileosinglefrequencystre_T GalileoE5stream;// '<S18>/Galileo E5 stream'
        DW_Galileosinglefrequencystre_T GalileoE1stream;// '<S18>/Galileo E1 stream'
    };

    // Block signals for system '<S19>/CalcDOP'
    struct B_CalcDOP_GNSSPreProcessingDu_T
    {
        real_T A_data[160];
        real_T Q[16];
        real_T y[16];
        real_T Rot[9];
        real_T Qtemp[9];
        real_T Rot_m[9];
        real_T HDOP;
        real_T VDOP;
        real_T N;
        real_T Range;
        real_T b_userPhi;
        real_T oldh;
        real_T b_N;
        real_T s;
    };

    // Block states (default storage) for system '<S19>/CalcDOP'
    struct DW_CalcDOP_GNSSPreProcessingD_T
    {
        GNSS_Measurement_size SFunction_DIMS2;// '<S19>/CalcDOP'
    };

    // Block signals for system '<S123>/MATLAB Function'
    struct B_MATLABFunction_GNSSPreProce_T
    {
        real_T P_data[1600];
        real_T q_data[1600];
        real_T s_data[1600];
        real_T matrix_pseudorange_variance_dat[1600];
        real_T S_data[1600];
        real_T f_data[1600];
        real_T A_data[1600];
        real_T in1_data[1600];
        GNSS_Measurement GNSS_measurement_out;// '<S124>/Fault Exclusion'
        GNSS_Measurement GNSS_Measurement_out;// '<S124>/Weighted RAIM Parity'
        real_T H_data[160];
        real_T tmp_data[160];
        real_T A_data_c[160];
        real_T b_y_data[160];
        real_T b_A_data[160];
        real_T tmp_data_k[120];
        real_T satellitePosition_ecef_data[120];
        real_T tmp_data_c[80];
        real_T variance_pseudorange[40];
        real_T P_satellite_fault_data[40];
        real_T idxPRN_data[40];
        real_T indx_to_exclude_data[40];
        real_T pseudorange_pre_data[40];
        real_T d_y_data[40];
        real_T b_tau_data[40];
        real_T work_data[40];
        real_T work_data_b[40];
        real_T b_x_data[40];
        real_T xwork_data[40];
        real_T b_x_data_p[40];
        real_T xwork_data_c[40];
        int32_T c_data[40];
        int32_T e_data[40];
        int32_T indx_to_isolate_data[40];
        int32_T iidx_data[40];
        int32_T iwork_data[40];
        int32_T iwork_data_f[40];
        real32_T tmp_data_g[40];
        real_T c_y[16];
        real_T b_A[16];
        uint16_T tmp_data_g1[40];
        real_T cosinus_lambda[9];
        real_T cosinus_phi[9];
        real_T cosinus_lambda_m[9];
        real_T in2[9];
        real_T in5[9];
        real_T in2_n[9];
        real_T elevation_Angle_tmp[9];
        int8_T k_data[40];
        int8_T l_data[40];
        int8_T m_data[40];
        int8_T n_data[40];
        int8_T p_data[40];
        int8_T h_data[40];
        int8_T p_data_p[40];
        int8_T ipiv_data[40];
        boolean_T v_data[40];
        boolean_T cb_data[40];
        real_T user_state_pre[4];
        real_T tau_data[4];
        real_T b_work[4];
        real_T x4[4];
        real_T x4_l[4];
        real_T work[4];
        real_T rtu_1_data[3];
        real_T position_llh[3];
        real_T satellitePosition_ned[3];
        real_T user_state_pre_j[3];
        real_T in8[3];
        real_T user_Position_ecef[3];
        int8_T ii_data[18];
        boolean_T x[18];
        real_T trop_factor;
        real_T sigma_noise;
        real_T sigma_mp;
        real_T threshold;
        real_T numIdentifiedFaults;
        real_T totalProbability;
        real_T s;
        real_T N;
        real_T oldh;
        real_T b_N;
        real_T sinus_lambda;
        real_T cosinus_phi_d;
        real_T atmp;
        real_T xnorm;
        real_T scale;
        real_T absxk;
        real_T t;
        real_T d;
        real_T d1;
        real_T d2;
        real_T d3;
        real_T smax;
        real_T s_g;
        real_T smax_l;
        real_T s_d;
        real_T N_d;
        real_T scale_l;
        real_T absxk_o;
        real_T t_b;
        real_T a_tmp;
        real_T user_Position_ecef_n;
        real_T user_Position_ecef_b;
        real_T user_Position_ecef_l;
        real_T atmp_h;
        real_T xnorm_b;
        real_T scale_d;
        real_T absxk_e;
        real_T t_bj;
        int32_T H_size[2];
        int32_T P_size[2];
        int32_T P_satellite_fault_size[2];
        int32_T q_size[2];
        int32_T indx_to_isolate_size[2];
        int32_T idxPRN_size[2];
        int32_T indx_to_exclude_size[2];
        int32_T iidx_size[2];
        int32_T rtu_1_size[2];
        int32_T tmp_size[2];
        int32_T tmp_size_j[2];
        int32_T satellitePosition_ecef_size[2];
        int32_T matrix_pseudorange_variance_siz[2];
        int32_T A_size[2];
        int32_T S_size[2];
        int32_T f_size[2];
        int32_T b_A_size[2];
        int32_T b_x_size[2];
        int32_T b_x_size_a[2];
        int8_T idx4[4];
        int8_T perm[4];
        int8_T idx4_j[4];
        int8_T perm_j[4];
        int8_T ipiv[4];
        int32_T b;
        int32_T c;
        int32_T idx;
        int32_T b_numMeas;
        int32_T g;
        int32_T i;
        int32_T c_size;
        int32_T v_size;
        int32_T P_size_o;
        int32_T i_n;
        int32_T rtu_1_DIMS1_idx_0;
        int32_T trueCount;
        int32_T k;
        int32_T coffset;
        int32_T boffset;
        int32_T aoffset;
        int32_T b_aoffset;
        int32_T m_i;
        int32_T loop_ub;
        int32_T pseudorange_pre_size;
        int32_T h_size;
        int32_T i1;
        int32_T i2;
        int32_T stride_0_0;
        int32_T in2_tmp;
        int32_T m;
        int32_T b_ia;
        int32_T l_i;
        int32_T b_itau;
        int32_T lastv;
        int32_T b_lastv;
        int32_T c_lastc;
        int32_T b_coltop;
        int32_T tau_size;
        int32_T lastv_tmp;
        int32_T m_ic;
        int32_T n;
        int32_T minmana;
        int32_T minmn;
        int32_T ii;
        int32_T mmi;
        int32_T mmip1;
        int32_T i_o;
        int32_T ix0;
        int32_T knt;
        int32_T d_n;
        int32_T coltop;
        int32_T vectorUB;
        int32_T kend;
        int32_T k_m;
        int32_T n_c;
        int32_T ib;
        int32_T wOffset;
        int32_T quartetOffset;
        int32_T i2_m;
        int32_T i3;
        int32_T n_m;
        int32_T ib_j;
        int32_T wOffset_h;
        int32_T quartetOffset_c;
        int32_T i2_c;
        int32_T i3_p;
        int32_T jj;
        int32_T b_j;
        int32_T b_i;
        int32_T a;
        int32_T jBcol;
        int32_T kAcol;
        int32_T c_i;
        int32_T jA;
        int32_T n_p;
        int32_T pipk;
        int32_T kAcol_a;
        int32_T ldap1;
        int32_T mmj;
        int32_T jj_e;
        int32_T b_yk;
        int32_T jA_a;
        int32_T jy;
        int32_T m_a;
        int32_T ijA;
        int32_T A_size_idx_0;
        int32_T ipiv_data_tmp;
        int32_T mmj_tmp;
        int32_T smax_tmp;
        int32_T m_if;
        int32_T minmana_l;
        int32_T minmn_o;
        int32_T ii_o;
        int32_T mmi_i;
        int32_T mmip1_f;
        int32_T i_i;
        int32_T ix0_f;
        int32_T knt_g;
        int32_T d_c;
        int32_T coltop_o;
        int32_T vectorUB_l;
        int32_T kend_m;
        int32_T k_mj;
        int32_T i3_c;
        int32_T i4;
        int32_T aux_0_1;
        int32_T aux_1_1;
        int32_T stride_0_0_f;
        int32_T stride_1_0;
        int32_T stride_0_1;
        int32_T stride_1_1;
        int32_T loop_ub_p;
        int32_T loop_ub_e;
        int32_T in1_size_idx_0;
        int32_T in1_size_idx_1;
        int32_T aoffset_o;
        int32_T b_h;
        int32_T i_l;
        int32_T d_h;
        int32_T b_i_m;
        int32_T scalarLB;
        int32_T vectorUB_m;
        int8_T ipiv_h;
        int8_T ipiv_c;
        boolean_T doIdentify;
        boolean_T b_doIdentify;
    };

    // Block states (default storage) for system '<S123>/MATLAB Function'
    struct DW_MATLABFunction_GNSSPreProc_T
    {
        GNSS_Measurement_size TmpHiddenBufferAtBusAssignmentI;// synthesized block
        GNSS_Measurement_size BusAssignment_DIMS1;// '<S124>/Bus Assignment'
        GNSS_Measurement_size SFunction_DIMS6;// '<S124>/Weighted RAIM Parity'
        GNSS_Measurement_size SFunction_DIMS2;// '<S124>/Fault Exclusion'
        real_T BUFFER[80];             // '<S124>/Fault Exclusion'
        real_T sys_clock_last_loop;    // '<S124>/Fault Exclusion'
        int32_T SFunction_DIMS2_l;     // '<S124>/calculate Variance'
        boolean_T BUFFER_not_empty;    // '<S124>/Fault Exclusion'
    };

    // Block signals for system '<S123>/switch GNSS Measurements'
    struct B_switchGNSSMeasurements_GNSS_T
    {
        GNSS_Measurement GNSS_Measurement_c;// '<S123>/switch GNSS Measurements'
    };

    // Block states (default storage) for system '<S123>/switch GNSS Measurements'
    struct DW_switchGNSSMeasurements_GNS_T
    {
        GNSS_Measurement_size SFunction_DIMS2;// '<S123>/switch GNSS Measurements'
    };

    // Block signals for system '<S5>/MATLAB Function'
    struct B_MATLABFunction_GNSSPrePro_a_T
    {
        GNSS_Measurement GpsMeasurementB;// '<S5>/MATLAB Function'
        GNSS_Measurement GalMeasurementB;// '<S5>/MATLAB Function'
        real_T tmp_data[120];
        int8_T f_data[40];
        int8_T g_data[40];
        int8_T h_data[40];
        int8_T i_data[40];
        int8_T j_data[40];
        int8_T k_data[40];
        int8_T l_data[40];
        int8_T m_data[40];
        int8_T n_data[40];
        int8_T o_data[40];
        int8_T p_data[40];
        int8_T q_data[40];
        int8_T r_data[40];
        int8_T s_data[40];
        int8_T t_data[40];
        int8_T u_data[40];
        int8_T v_data[40];
        int8_T w_data[40];
        int8_T x_data[40];
        int8_T y_data[40];
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
        boolean_T b_data[40];
        boolean_T c_data[40];
        boolean_T d_data[40];
        boolean_T e_data[40];
    };

    // Block states (default storage) for system '<S5>/MATLAB Function'
    struct DW_MATLABFunction_GNSSPrePr_l_T
    {
        GNSS_Measurement_size SFunction_DIMS2;// '<S5>/MATLAB Function'
        GNSS_Measurement_size SFunction_DIMS3;// '<S5>/MATLAB Function'
    };

    // Block signals for system '<S5>/Merge GNSS Measurement'
    struct B_MergeGNSSMeasurement_GNSSPr_T
    {
        s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T expl_temp;
        s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T expl_temp_m;
        real_T GPSGalileoPosition[1000];
        emxArray__GNSS_Measurement_GN_T r;
        emxArray__GNSS_Measurement_GN_T r1;
        emxArray__GNSS_Measurement_GN_T galileo_measurement_temp;
        GNSS_Measurement GnssMeasurementBus;// '<S5>/Merge GNSS Measurement'
        GNSS_Measurement galileo_measurement_temp_data;
        GNSS_Measurement r2;
        GNSS_Measurement r3;
        real_T b_H_data[800];
        real_T b_A_data[800];
        real_T H_sys1_data[400];
        real_T H_sys2_data[400];
        real_T outputBus_data[360];
        real_T H_data[320];
        real_T b_A_data_c[320];
        real_T satellite_position_gps_data[240];
        real_T satellite_position_galileo_data[240];
        real_T delta_rho_data[160];
        real_T b_B_data[160];
        real_T pseudorange_gps_data[80];
        real_T pseudorange_galileo_data[80];
        real_T delta_rho_sys1_data[80];
        real_T delta_rho_sys2_data[80];
        real_T b_B_data_k[80];
        real_T b_A_data_cx[25];
        real_T b_A_data_b[16];
        int8_T g_data[80];
        int8_T h_data[80];
        int8_T i_data[80];
        int8_T j_data[80];
        boolean_T l_data[80];
        boolean_T l_data_p[80];
        GNSS_Measurement_size galileo_measurement_temp_elems_;
        GNSS_Measurement_size r4;
        GNSS_Measurement_size r5;
        real_T GPSGalileoPosition_data[5];
        real_T b_user_state[5];
        real_T b_residuum[5];
        real_T dv[5];
        real_T tau_data[5];
        real_T work[5];
        real_T vn1[5];
        real_T vn2[5];
        real_T user_state[4];
        real_T residuum[4];
        real_T dv1[4];
        real_T dv2[4];
        real_T tau_data_f[4];
        real_T work_g[4];
        real_T vn1_g[4];
        real_T vn2_m[4];
        real_T satellite_position_sys1[3];
        real_T satellite_position_sys1_n[3];
        real_T in3[3];
        real_T satellite_position[3];
        real_T satellite_position_p[3];
        real_T in3_l[3];
        real_T in3_j[3];
        real_T deltaSystemTimesGnss;
        real_T scale;
        real_T absxk;
        real_T t;
        real_T b_t;
        real_T satellite_position_sys1_tmp;
        real_T d;
        real_T in3_tmp;
        real_T scale_d;
        real_T absxk_g;
        real_T t_l;
        real_T smax;
        real_T s;
        real_T temp2;
        real_T smax_d;
        real_T s_d;
        real_T scale_l;
        real_T absxk_o;
        real_T t_b;
        real_T smax_n;
        real_T s_b;
        real_T temp2_l;
        real_T smax_h;
        real_T s_bn;
        real_T scale_da;
        real_T absxk_e;
        real_T t_bj;
        real_T satellite_position_tmp;
        real_T d1;
        real_T in3_tmp_j;
        real_T a;
        real_T b;
        real_T d2;
        real_T in3_tmp_f;
        int32_T satellite_position_galileo_size[2];
        int32_T H_size[2];
        int32_T b_H_size[2];
        int32_T H_sys1_size[2];
        int32_T H_sys2_size[2];
        int32_T b_A_size[2];
        int32_T b_A_size_a[2];
        int8_T ipiv[5];
        int8_T jpvt[5];
        int8_T ipiv_j[4];
        int8_T jpvt_j[4];
        int32_T expl_temp_o;
        int32_T expl_temp_n;
        int32_T i;
        int32_T loop_ub;
        int32_T iter;
        int32_T i_i;
        int32_T loop_ub_o;
        int32_T pseudorange_gps_size;
        int32_T pseudorange_galileo_size;
        int32_T delta_rho_size;
        int32_T l_size;
        int32_T l_size_n;
        int32_T g_size_idx_0;
        int32_T i_tmp;
        int32_T i_m;
        int32_T H_sys1;
        int32_T loop_ub_c;
        int32_T i1;
        int32_T jj;
        int32_T j;
        int32_T kAcol;
        int32_T n;
        int32_T jA;
        int32_T e;
        int32_T vectorUB;
        int32_T rankA;
        int32_T maxmn;
        int32_T minmana;
        int32_T ii;
        int32_T mmi;
        int32_T pvt;
        int32_T itemp;
        int32_T e_i;
        int32_T b_ix;
        int32_T c_k;
        int32_T p;
        int32_T ia;
        int32_T jA_m;
        int32_T temp_tmp;
        int32_T kend;
        int32_T k;
        int32_T jj_m;
        int32_T j_j;
        int32_T kAcol_h;
        int32_T n_c;
        int32_T jA_c;
        int32_T e_p;
        int32_T b_temp_tmp;
        int32_T rankA_p;
        int32_T maxmn_a;
        int32_T minmana_e;
        int32_T ii_a;
        int32_T mmi_a;
        int32_T pvt_i;
        int32_T itemp_l;
        int32_T e_i_o;
        int32_T b_ix_o;
        int32_T c_k_i;
        int32_T p_f;
        int32_T ia_i;
        int32_T jA_f;
        int32_T temp_tmp_g;
        int32_T kend_c;
        int32_T k_o;
        int8_T ipiv_l;
        int8_T ipiv_m;
        boolean_T b_m;
    };

    // Block states (default storage) for system '<S5>/Merge GNSS Measurement'
    struct DW_MergeGNSSMeasurement_GNSSP_T
    {
        GNSS_Measurement_size SFunction_DIMS2;// '<S5>/Merge GNSS Measurement'
        real_T userposBuffer[1000];    // '<S5>/Merge GNSS Measurement'
        real_T writeIdx;               // '<S5>/Merge GNSS Measurement'
    };

    // Block signals for system '<S5>/Mode Switch'
    struct B_ModeSwitch_GNSSPreProcessin_T
    {
        boolean_T c_x_data[200];
        int8_T f_data[40];
        boolean_T d[40];
        boolean_T e[40];
        boolean_T b_x[40];
    };

    // Block states (default storage) for system '<S5>/Mode Switch'
    struct DW_ModeSwitch_GNSSPreProcessi_T
    {
        real_T DelayInput1_DSTATE;     // '<S134>/Delay Input1'
        real_T DiscreteTimeIntegrator_DSTATE;// '<S130>/Discrete-Time Integrator'
        uint32_T temporalCounter_i1;   // '<S131>/choose correction mode'
        int8_T DiscreteTimeIntegrator_PrevRese;// '<S130>/Discrete-Time Integrator'
        uint8_T is_c130_lib_GNSSPreProcessing;// '<S131>/choose correction mode'
        uint8_T is_DGPS;               // '<S131>/choose correction mode'
        uint8_T is_Dualfrequency;      // '<S131>/choose correction mode'
        uint8_T is_active_c130_lib_GNSSPreProce;// '<S131>/choose correction mode'
        boolean_T Memory_PreviousInput;// '<S135>/Memory'
    };

    // Block signals (default storage)
    struct B_GNSSPreProcessingDualAntenn_T
    {
        real_T b_addRow[6000];
        real_T result_data[3200];
        real_T addRow[2000];
        real_T varargin_1_data[1600];
        real_T varargin_2_data[1600];
        gnssraw_measurement_t GalMeasurementBus;// '<S6>/GNSS Measurement Epoch Splitter'
        gnssraw_measurement_t GpsMeasurementBus;// '<S6>/GNSS Measurement Epoch Splitter'
        real32_T addRow_m[2000];
        GNSS_Measurement GnssMeasurementBase;// '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'
        GNSS_Measurement BusConversion_InsertedFor_Mer_b;
        uint16_T addRow_c[2000];
        real_T dv[150];
        real_T b_addRow_k[120];
        real_T rtb_double_differences_satellit[120];
        real_T rtb_double_differences_satell_b[120];
        real_T dv1[100];
        real_T PRNs_to_exclude_o[80];  // '<S124>/Fault Exclusion'
        real_T PRNs_excluded_h[80];    // '<S124>/Fault Exclusion'
        real_T PRNs_to_exclude[80];    // '<S251>/Fault Exclusion'
        real_T PRNs_excluded[80];      // '<S251>/Fault Exclusion'
        real_T dv2[50];
        real_T addRow_p[40];
        real_T dr_kl_ur_GPS_data[40];
        real_T carrierphase_kl_ur_GPS_data[40];
        real_T a__1_data[40];
        real_T elevation_Angle_data[40];
        real_T pr_kl_ur_GAL_data[40];
        real_T dr_kl_ur_GAL_data[40];
        real_T carrierphase_kl_ur_GAL_data[40];
        real_T elevation_Angle_temp_data[40];
        real_T pseudorangeCorrections[40];// '<S6>/mergeDiffCorrections'
        real_T rtb_double_differences_deltaran[40];
        real_T rtb_double_differences_variance[40];
        real_T rtb_double_differences_varian_g[40];
        real_T rtb_double_differences_varia_g1[40];
        real_T rtb_double_differences_carrierp[40];
        real_T rtb_double_differences_varian_n[40];
        real_T rtb_double_differences_CN0[40];
        int32_T idx_r_data[50];
        int32_T idx_u_data[50];
        int32_T ia_data[40];
        int32_T ib_data[40];
        int32_T idx_u_GPS_data[40];
        int32_T idx_r_GPS_data[40];
        int32_T idx_u_GAL_data[40];
        int32_T b_idx_r_data[40];
        int32_T b_idx_u_data[40];
        real32_T tmp_data[40];
        real32_T rtb_double_differences_locktime[40];
        uint16_T r_SVID[40];
        uint16_T u_SVID[40];
        uint16_T SVID_data[40];
        uint16_T tmp_data_p[40];
        uint16_T SVIDCorrections[40];  // '<S6>/mergeDiffCorrections'
        real_T e_unit_tmp[9];
        boolean_T b_y[50];
        boolean_T b_y_l[50];
        parameters_gnss_t BusConversion_InsertedFor_Me_bw;
        parameters_gnss_t BusConversion_InsertedFor_Mer_l;
        parameters_gnss_t parameters_gnss;// '<S258>/choose correction mode'
        parameters_gnss_t parameters_gnss_i;// '<S131>/choose correction mode'
        int8_T gc_data[40];
        int8_T hc_data[40];
        int8_T ic_data[40];
        int8_T jc_data[40];
        int8_T kc_data[40];
        int8_T lc_data[40];
        int8_T mc_data[40];
        int8_T nc_data[40];
        boolean_T cc_data[40];
        boolean_T dc_data[40];
        boolean_T ec_data[40];
        boolean_T fc[40];
        boolean_T bc_data[40];
        real_T e_unit[3];
        real_T n_unit[3];
        real_T u_unit[3];
        real_T dv3[2];
        real_T HDOP;                   // '<S19>/CalcDOP'
        real_T elevation_mask;         // '<S5>/Switch'
        real_T elevation_mask_g;       // '<S6>/Switch'
        real_T WNc_a;
        real_T TOW_o;
        real_T WNc;
        real_T TOW;
        real_T N;
        real_T y;
        real_T scale;
        real_T absxk;
        real_T t;
        real_T user_Position_ecef_idx_0;
        real_T user_Position_ecef_idx_1;
        real_T line_of_sight_idx_0;
        real_T line_of_sight_idx_1;
        real_T line_of_sight_idx_2;
        int32_T pr_kl_ur_GPS_size[2];
        int32_T dr_kl_ur_GPS_size[2];
        int32_T carrierphase_kl_ur_GPS_size[2];
        int32_T pr_kl_ur_GAL_size[2];
        int32_T dr_kl_ur_GAL_size[2];
        int32_T carrierphase_kl_ur_GAL_size[2];
        int32_T SVID_size[2];
        int32_T bc_size[2];
        int32_T bc_size_j[2];
        int32_T tmp_size[2];
        int32_T c;
        int32_T trueCount;
        int32_T i;
        int32_T b_k;
        int32_T idx_r;
        int32_T idx_u;
        int32_T loop_ub;
        int32_T loop_ub_tmp;
        int32_T loop_ub_tmp_d;
        int32_T loop_ub_tmp_g;
        int32_T loop_ub_tmp_l;
        int32_T loop_ub_tmp_dh;
        int32_T loop_ub_tmp_dy;
        int32_T loop_ub_tmp_lx;
        int32_T loop_ub_tmp_o;
        int32_T ia_size;
        int32_T ib_size;
        int32_T idx_u_GPS_size;
        int32_T idx_r_GPS_size;
        int32_T elevation_Angle_size;
        int32_T idx_u_GAL_size;
        int32_T tmp_size_b;
        int32_T SFunction_DIMS2;
        int32_T SFunction_DIMS2_n;
        int32_T dc_size_idx_1;
        int32_T jc_size_idx_1;
        int32_T kc_size_idx_1;
        int32_T i_b;
        int32_T loop_ub_l;
        int32_T i_h;
        int32_T i1;
        int8_T empty_non_axis_sizes[2];
        int8_T empty_non_axis_sizes_b[2];
        int8_T b_empty_non_axis_sizes[2];
        int8_T c_empty_non_axis_sizes[2];
        int8_T e_empty_non_axis_sizes[2];
        int8_T f_empty_non_axis_sizes[2];
        int8_T sizes_idx_1;
        int8_T i_empty_non_axis_sizes_idx_0;
        uint8_T prn_psl1;              // '<S5>/Switch'
        uint8_T prn_psl2;              // '<S5>/Switch'
        uint8_T prn_psl3;              // '<S5>/Switch'
        uint8_T prn_psl4;              // '<S5>/Switch'
        uint8_T prn_psl5;              // '<S5>/Switch'
        uint8_T prn_psl6;              // '<S5>/Switch'
        uint8_T prn_psl7;              // '<S5>/Switch'
        uint8_T prn_psl8;              // '<S5>/Switch'
        uint8_T prn_psl9;              // '<S5>/Switch'
        uint8_T prn_psl1_c;            // '<S6>/Switch'
        uint8_T prn_psl2_b;            // '<S6>/Switch'
        uint8_T prn_psl3_h;            // '<S6>/Switch'
        uint8_T prn_psl4_f;            // '<S6>/Switch'
        uint8_T prn_psl5_f;            // '<S6>/Switch'
        uint8_T prn_psl6_b;            // '<S6>/Switch'
        uint8_T prn_psl7_h;            // '<S6>/Switch'
        uint8_T prn_psl8_b;            // '<S6>/Switch'
        uint8_T prn_psl9_e;            // '<S6>/Switch'
        boolean_T enable_gps;          // '<S5>/Switch'
        boolean_T enable_gps_l1;       // '<S5>/Switch'
        boolean_T enable_gps_l2;       // '<S5>/Switch'
        boolean_T enable_galileo;      // '<S5>/Switch'
        boolean_T enable_galileo_e1;   // '<S5>/Switch'
        boolean_T enable_galileo_e5a;  // '<S5>/Switch'
        boolean_T enable_galileo_e5b;  // '<S5>/Switch'
        boolean_T enable_galileo_e5;   // '<S5>/Switch'
        boolean_T enable_gate;         // '<S5>/Switch'
        boolean_T enable_galileo_timebase;// '<S5>/Switch'
        boolean_T enable_differential_correct;// '<S5>/Switch'
        boolean_T enable_tropospheric_correct;// '<S5>/Switch'
        boolean_T enable_ionospheric_correcti;// '<S5>/Switch'
        boolean_T enable_SatPosVel_calculatio;// '<S5>/Switch'
        boolean_T enable_WL_correction;// '<S5>/Switch'
        boolean_T use_measured_variance;// '<S5>/Switch'
        boolean_T enable_gps_j;        // '<S6>/Switch'
        boolean_T enable_gps_l1_p;     // '<S6>/Switch'
        boolean_T enable_gps_l2_e;     // '<S6>/Switch'
        boolean_T enable_galileo_b;    // '<S6>/Switch'
        boolean_T enable_galileo_e1_h; // '<S6>/Switch'
        boolean_T enable_galileo_e5a_a;// '<S6>/Switch'
        boolean_T enable_galileo_e5b_m;// '<S6>/Switch'
        boolean_T enable_galileo_e5_p; // '<S6>/Switch'
        boolean_T enable_gate_b;       // '<S6>/Switch'
        boolean_T enable_galileo_timebase_l;// '<S6>/Switch'
        boolean_T enable_differential_corre_p;// '<S6>/Switch'
        boolean_T enable_tropospheric_corre_g;// '<S6>/Switch'
        boolean_T enable_ionospheric_correc_a;// '<S6>/Switch'
        boolean_T enable_SatPosVel_calculat_i;// '<S6>/Switch'
        boolean_T enable_WL_correction_f;// '<S6>/Switch'
        boolean_T use_measured_variance_l;// '<S6>/Switch'
        B_ModeSwitch_GNSSPreProcessin_T ModeSwitch_f;// '<S6>/Mode Switch'
        B_MergeGNSSMeasurement_GNSSPr_T sf_MergeGNSSMeasurement_b;// '<S6>/Merge GNSS Measurement'
        B_MATLABFunction_GNSSPrePro_a_T sf_MATLABFunction_f;// '<S6>/MATLAB Function'
        B_switchGNSSMeasurements_GNSS_T sf_switchGNSSMeasurements_d;// '<S250>/switch GNSS Measurements'
        B_MATLABFunction_GNSSPreProce_T sf_MATLABFunction_o;// '<S250>/MATLAB Function'
        B_CalcDOP_GNSSPreProcessingDu_T sf_CalcDOP_g;// '<S146>/CalcDOP'
        B_Galileo_GNSSPreProcessingDu_T Galileo_h;// '<S6>/Galileo'
        B_GPS_GNSSPreProcessingDualAn_T GPS_o;// '<S6>/GPS'
        B_GNSSMeasurementEpochSplitte_T sf_GNSSMeasurementEpochSplitt_d;// '<S6>/GNSS Measurement Epoch Splitter'
        B_Fuse_GNSSPreProcessingDualA_T sf_Fuse_d;// '<S6>/Fuse'
        B_DummyGNSSMeasurement_GNSSPr_T sf_DummyGNSSMeasurement_p;// '<S6>/Dummy GNSS Measurement'
        B_ConvertGNSSMeasuremendVaria_T sf_ConvertGNSSMeasuremendVar_pc;// '<S6>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles2' 
        B_ConvertGNSSMeasuremendVaria_T sf_ConvertGNSSMeasuremendVari_p;// '<S6>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles1' 
        B_ConvertGNSSMeasuremendVaria_T sf_ConvertGNSSMeasuremendVari_l;// '<S6>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles' 
        B_ModeSwitch_GNSSPreProcessin_T ModeSwitch;// '<S5>/Mode Switch'
        B_MergeGNSSMeasurement_GNSSPr_T sf_MergeGNSSMeasurement;// '<S5>/Merge GNSS Measurement'
        B_MATLABFunction_GNSSPrePro_a_T sf_MATLABFunction_d;// '<S5>/MATLAB Function'
        B_switchGNSSMeasurements_GNSS_T sf_switchGNSSMeasurements;// '<S123>/switch GNSS Measurements'
        B_MATLABFunction_GNSSPreProce_T sf_MATLABFunction;// '<S123>/MATLAB Function'
        B_CalcDOP_GNSSPreProcessingDu_T sf_CalcDOP;// '<S19>/CalcDOP'
        B_Galileo_GNSSPreProcessingDu_T Galileo;// '<S5>/Galileo'
        B_GPS_GNSSPreProcessingDualAn_T GPS;// '<S5>/GPS'
        B_GNSSMeasurementEpochSplitte_T sf_GNSSMeasurementEpochSplitter;// '<S5>/GNSS Measurement Epoch Splitter'
        B_Fuse_GNSSPreProcessingDualA_T sf_Fuse;// '<S5>/Fuse'
        B_DummyGNSSMeasurement_GNSSPr_T sf_DummyGNSSMeasurement;// '<S5>/Dummy GNSS Measurement'
        B_ConvertGNSSMeasuremendVaria_T sf_ConvertGNSSMeasuremendVari_o;// '<S5>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles2' 
        B_ConvertGNSSMeasuremendVaria_T sf_ConvertGNSSMeasuremendVari_f;// '<S5>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles1' 
        B_ConvertGNSSMeasuremendVaria_T sf_ConvertGNSSMeasuremendVariab;// '<S5>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles' 
        B_CalculateUserPositionwithLM_T sf_CalculateUserPositionwithL_h;// '<Root>/Calculate User Position with LMS1'
        B_CalculateUserPositionwithLM_T sf_CalculateUserPositionwithLMS;// '<Root>/Calculate User Position with LMS'
    };

    // Block states (default storage) for system '<Root>'
    struct DW_GNSSPreProcessingDualAnten_T
    {
        sk7S3MUBNIp13xZwazKdzDD_GNSSP_T Buffer_u;// '<S3>/calculate double diff'
        sk7S3MUBNIp13xZwazKdzDD_GNSSP_T Buffer_r;// '<S3>/calculate double diff'
        GNSS_Measurement_size BusConversion_InsertedFor_Merge;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Mer_o;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Mer_k;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Me_kn;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Conve;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Con_f;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Con_p;// synthesized block
        GNSS_Measurement_size BusConversion_InsertedFor_Con_l;// synthesized block
        GNSS_Measurement_size SFunction_DIMS2;// '<Root>/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'
        GNSS_Measurement_size SFunction_DIMS2_b;// '<S3>/calculate double diff'
        int32_T SFunction_DIMS2_j;     // '<Root>/Intersect'
        boolean_T Buffer_r_not_empty;  // '<S3>/calculate double diff'
        DW_ModeSwitch_GNSSPreProcessi_T ModeSwitch_f;// '<S6>/Mode Switch'
        DW_MergeGNSSMeasurement_GNSSP_T sf_MergeGNSSMeasurement_b;// '<S6>/Merge GNSS Measurement'
        DW_MATLABFunction_GNSSPrePr_l_T sf_MATLABFunction_f;// '<S6>/MATLAB Function'
        DW_switchGNSSMeasurements_GNS_T sf_switchGNSSMeasurements_d;// '<S250>/switch GNSS Measurements'
        DW_MATLABFunction_GNSSPreProc_T sf_MATLABFunction_o;// '<S250>/MATLAB Function'
        DW_CalcDOP_GNSSPreProcessingD_T sf_CalcDOP_g;// '<S146>/CalcDOP'
        DW_Galileo_GNSSPreProcessingD_T Galileo_h;// '<S6>/Galileo'
        DW_GPS_GNSSPreProcessingDualA_T GPS_o;// '<S6>/GPS'
        DW_Fuse_GNSSPreProcessingDual_T sf_Fuse_d;// '<S6>/Fuse'
        DW_DummyGNSSMeasurement_GNSSP_T sf_DummyGNSSMeasurement_p;// '<S6>/Dummy GNSS Measurement'
        DW_CalculateDayofYear_GNSSPre_T sf_CalculateDayofYear_j;// '<S6>/Calculate Day of Year'
        DW_ModeSwitch_GNSSPreProcessi_T ModeSwitch;// '<S5>/Mode Switch'
        DW_MergeGNSSMeasurement_GNSSP_T sf_MergeGNSSMeasurement;// '<S5>/Merge GNSS Measurement'
        DW_MATLABFunction_GNSSPrePr_l_T sf_MATLABFunction_d;// '<S5>/MATLAB Function'
        DW_switchGNSSMeasurements_GNS_T sf_switchGNSSMeasurements;// '<S123>/switch GNSS Measurements'
        DW_MATLABFunction_GNSSPreProc_T sf_MATLABFunction;// '<S123>/MATLAB Function'
        DW_CalcDOP_GNSSPreProcessingD_T sf_CalcDOP;// '<S19>/CalcDOP'
        DW_Galileo_GNSSPreProcessingD_T Galileo;// '<S5>/Galileo'
        DW_GPS_GNSSPreProcessingDualA_T GPS;// '<S5>/GPS'
        DW_Fuse_GNSSPreProcessingDual_T sf_Fuse;// '<S5>/Fuse'
        DW_DummyGNSSMeasurement_GNSSP_T sf_DummyGNSSMeasurement;// '<S5>/Dummy GNSS Measurement'
        DW_CalculateDayofYear_GNSSPre_T sf_CalculateDayofYear;// '<S5>/Calculate Day of Year'
    };

    // External inputs (root inport signals with default storage)
    struct ExtU_GNSSPreProcessingDualAnt_T
    {
        gnssraw_measurement_t MeasurementEpochBusAntenna1;// '<Root>/MeasurementEpochBusAntenna1'
        gnssraw_measurement_t MeasurementEpochBusAntenna2;// '<Root>/MeasurementEpochBusAntenna2'
        gnssraw_gps_nav_t GpsNavBus;   // '<Root>/GpsNavBus'
        gnssraw_gps_ion_t GpsIonBus;   // '<Root>/GpsIonBus'
        gnssraw_gal_nav_t GalFnavBus;  // '<Root>/GalFnavBus'
        gnssraw_gal_nav_t GalInavBus;  // '<Root>/GalInavBus'
        gnssraw_gal_ion_t GalIonBus;   // '<Root>/GalIonBus'
        gnssraw_ggto_t GalGstGpsBus;   // '<Root>/GalGstGpsBus'
        real_T UserPosLLHVecAntMain[3];// '<Root>/UserPosLLHVecAntMain'
        real_T ClockErrorVec;          // '<Root>/ClockErrorVec'
        parameters_integrity_t IntegrityParametersBus;// '<Root>/IntegrityParametersBus'
        DD_RTCM_3_3_L1_E1_t RTCM33L1E1Bus;// '<Root>/RTCM33L1E1Bus'
        parameters_gnss_t GnssParametersBus;// '<Root>/GnssParametersBus'
        real_T UseModeSwitchLogic;     // '<Root>/UseModeSwitchLogic'
        real_T EnableGGTO;             // '<Root>/EnableGGTO'
        boolean_T EnableDualAntennaDD; // '<Root>/EnableDualAntennaDD'
        real_T UserPosLLHVecAntAux[3]; // '<Root>/UserPosLLHVecAntAux'
        boolean_T EnableGNSSMerge;     // '<Root>/EnableGNSSMerge'
    };

    // External outputs (root outports fed by signals with default storage)
    struct ExtY_GNSSPreProcessingDualAnt_T
    {
        GNSSMeasurementFixed GnssMeasurementBusAntMain;// '<Root>/GnssMeasurementBusAntMain'
        real_T GnssMeasurementSizeAntMain;// '<Root>/GnssMeasurementSizeAntMain'
        real_T IntegrityFlagAntMain;   // '<Root>/IntegrityFlagAntMain'
        real_T DeltaSystemTimeGNSSAntMain;// '<Root>/DeltaSystemTimeGNSSAntMain'
        boolean_T IsGGTOValidAntMain;  // '<Root>/IsGGTOValidAntMain'
        real_T DOPAntMain[2];          // '<Root>/DOPAntMain'
        real_T faultyPRNsAntMain[80];  // '<Root>/faultyPRNsAntMain'
        GNSSMeasurementFixed GPSMeasurementBusAntMain;// '<Root>/GPSMeasurementBusAntMain'
        real_T GPSMeasurementSizeAntMain;// '<Root>/GPSMeasurementSizeAntMain'
        GNSSMeasurementFixed GALMeasurementBusAntMain;// '<Root>/GALMeasurementBusAntMain'
        real_T GALMeasurementSizeAntMain;// '<Root>/GALMeasurementSizeAntMain'
        LeastSquareSolution LeastSqureSolutionAntMain;// '<Root>/LeastSqureSolutionAntMain'
        GNSSMeasurementFixed GnssMeasurementBusAntAux;// '<Root>/GnssMeasurementBusAntAux'
        real_T GnssMeasurementSizeAntAux;// '<Root>/GnssMeasurementSizeAntAux'
        real_T IntegrityFlagAntAux;    // '<Root>/IntegrityFlagAntAux'
        real_T DeltaSystemTimeGNSSAntAux;// '<Root>/DeltaSystemTimeGNSSAntAux'
        boolean_T IsGGTOValidAntAux;   // '<Root>/IsGGTOValidAntAux'
        real_T DOPAntAux[2];           // '<Root>/DOPAntAux'
        real_T faultyPRNsAntAux[80];   // '<Root>/faultyPRNsAntAux'
        GNSSMeasurementFixed GPSMeasurementBusAntAux;// '<Root>/GPSMeasurementBusAntAux'
        real_T GPSMeasurementSizeAntAux;// '<Root>/GPSMeasurementSizeAntAux'
        GNSSMeasurementFixed GALMeasurementBusAntAux;// '<Root>/GALMeasurementBusAntAux'
        real_T GALMeasurementSizeAntAux;// '<Root>/GALMeasurementSizeAntAux'
        LeastSquareSolution LeastSqureSolutionAntAux;// '<Root>/LeastSqureSolutionAntAux'
        real_T diffPsedorangeCorrections[40];// '<Root>/diffPsedorangeCorrections'
        uint16_T diffSVIDCorrections[40];// '<Root>/diffSVIDCorrections'
        uint16_T SVIDUsedDualAntenna[40];// '<Root>/SVIDUsedDualAntenna'
        GNSSMeasurementFixed GnssMeasurementDDBus;// '<Root>/GnssMeasurementDDBus'
        real_T GnssMeasurementSizeDDDualantenn;// '<Root>/GnssMeasurementSizeDDDualantenn'
        real_T IDXSyncAntanna2;        // '<Root>/IDXSyncAntanna2'
        real_T IDXSyncAntanna1;        // '<Root>/IDXSyncAntanna1'
        uint16_T savidRefSatGPS;       // '<Root>/savidRefSatGPS'
        uint16_T savidRefSatGAL;       // '<Root>/savidRefSatGAL'
        boolean_T GPSGALCorrectedAntMain[2];// '<Root>/GPSGALCorrectedAntMain'
        real_T GPSGALCorrectionModeAntMain;// '<Root>/GPSGALCorrectionModeAntMain'
        boolean_T GPSGALCorrectedAntAux[2];// '<Root>/GPSGALCorrectedAntAux'
        real_T GPSGALCorrectionModeAntAux;// '<Root>/GPSGALCorrectionModeAntAux'
    };

    // External output sizes (for root outports fed by signals with variable sizes)
    struct ExtYSize_GNSSPreProcessingDua_T
    {
        int32_T SFunction_DIMS2_j;     // '<Root>/SVIDUsedDualAntenna'
    };

    // Parameters for system: '<S17>/GPS L1 Stream'
    struct P_GPSsinglefrequencystream_GN_T
    {
        real_T timeOfWeekOut_Y0;       // Computed Parameter: timeOfWeekOut_Y0
                                          //  Referenced by: '<S24>/timeOfWeekOut'

        real_T basePosition_Y0;        // Computed Parameter: basePosition_Y0
                                          //  Referenced by: '<S24>/basePosition'

        real_T delta_satPosECEF_EGNOS_dummy_Va[330];// Expression: zeros(110,3)
                                                       //  Referenced by: '<S24>/delta_satPosECEF_EGNOS_dummy'

        real_T gpsStreamInUse_Value;   // Expression: signal_in_use
                                          //  Referenced by: '<S24>/gpsStreamInUse'

        real_T delta_t_sv_EGNOS_dummy_Value[110];// Expression: zeros(110,1)
                                                    //  Referenced by: '<S24>/delta_t_sv_EGNOS_dummy'

    };

    // Parameters for system: '<S5>/GPS'
    struct P_GPS_GNSSPreProcessingDualAn_T
    {
        real_T CompareToConstant1_const;// Mask Parameter: CompareToConstant1_const
                                           //  Referenced by: '<S59>/Constant'

        real_T GPSL2CStream_enable_SatClockCor;// Mask Parameter: GPSL2CStream_enable_SatClockCor
                                                  //  Referenced by: '<S17>/GPS L2C Stream'

        real_T GPSL5Stream_enable_SatClockCorr;// Mask Parameter: GPSL5Stream_enable_SatClockCorr
                                                  //  Referenced by: '<S17>/GPS L5 Stream'

        real_T GPSL1Stream_enable_SatClockCorr;// Mask Parameter: GPSL1Stream_enable_SatClockCorr
                                                  //  Referenced by: '<S17>/GPS L1 Stream'

        real_T timeOfWeek_Y0;          // Computed Parameter: timeOfWeek_Y0
                                          //  Referenced by: '<S17>/timeOfWeek'

        real_T basePosition_Y0;        // Computed Parameter: basePosition_Y0
                                          //  Referenced by: '<S17>/basePosition'

        real_T BasePositionDummy_Value[3];// Expression: [0 0 0]'
                                             //  Referenced by: '<S17>/Base Position Dummy'

        boolean_T GPSMeasurementCorrected_Y0;// Computed Parameter: GPSMeasurementCorrected_Y0
                                                //  Referenced by: '<S17>/GPSMeasurementCorrected'

        boolean_T L5_basedProcessing_Value;// Computed Parameter: L5_basedProcessing_Value
                                              //  Referenced by: '<S17>/L5_basedProcessing'

        boolean_T AddTriggerHere_Value;// Expression: false
                                          //  Referenced by: '<S17>/Add Trigger Here'

        boolean_T Constant_Value;      // Expression: false
                                          //  Referenced by: '<S57>/Constant'

        P_GPSsinglefrequencystream_GN_T GPSL5Stream;// '<S17>/GPS L5 Stream'
        P_GPSsinglefrequencystream_GN_T GPSL2CStream;// '<S17>/GPS L2C Stream'
        P_GPSsinglefrequencystream_GN_T GPSL1Stream;// '<S17>/GPS L1 Stream'
    };

    // Parameters for system: '<S18>/Galileo E1 stream'
    struct P_Galileosinglefrequencystrea_T
    {
        real_T TOW_Out_Y0;             // Computed Parameter: TOW_Out_Y0
                                          //  Referenced by: '<S71>/TOW_Out'

        real_T basePosition_Y0;        // Computed Parameter: basePosition_Y0
                                          //  Referenced by: '<S71>/basePosition'

        real_T delta_satPosECEF_EGNOS_dummy_Va[330];// Expression: zeros(110,3)
                                                       //  Referenced by: '<S71>/delta_satPosECEF_EGNOS_dummy'

        real_T galileoStreamInUse_Value;// Expression: signal_in_use
                                           //  Referenced by: '<S71>/galileoStreamInUse'

        real_T delta_t_sv_EGNOS_dummy_Value[110];// Expression: zeros(110,1)
                                                    //  Referenced by: '<S71>/delta_t_sv_EGNOS_dummy'

    };

    // Parameters for system: '<S5>/Galileo'
    struct P_Galileo_GNSSPreProcessingDu_T
    {
        real_T CompareToConstant_const;// Mask Parameter: CompareToConstant_const
                                          //  Referenced by: '<S115>/Constant'

        real_T GalileoE1stream_enable_SatClock;// Mask Parameter: GalileoE1stream_enable_SatClock
                                                  //  Referenced by: '<S18>/Galileo E1 stream'

        real_T GalileoE5astream_enable_SatCloc;// Mask Parameter: GalileoE5astream_enable_SatCloc
                                                  //  Referenced by: '<S18>/Galileo E5a stream'

        real_T GalileoE5bstream_enable_SatCloc;// Mask Parameter: GalileoE5bstream_enable_SatCloc
                                                  //  Referenced by: '<S18>/Galileo E5b stream'

        real_T GalileoE5stream_enable_SatClock;// Mask Parameter: GalileoE5stream_enable_SatClock
                                                  //  Referenced by: '<S18>/Galileo E5 stream'

        real_T timereceive_Y0;         // Computed Parameter: timereceive_Y0
                                          //  Referenced by: '<S18>/time receive'

        real_T basePosition_Y0;        // Computed Parameter: basePosition_Y0
                                          //  Referenced by: '<S18>/basePosition'

        real_T BasePositionDummy_Value[3];// Expression: [0 0 0]'
                                             //  Referenced by: '<S18>/Base Position Dummy'

        boolean_T GALMeasurementCorrected_Y0;// Computed Parameter: GALMeasurementCorrected_Y0
                                                //  Referenced by: '<S18>/GALMeasurementCorrected'

        boolean_T E5_basedProcessing_Value;// Computed Parameter: E5_basedProcessing_Value
                                              //  Referenced by: '<S18>/E5_basedProcessing'

        P_Galileosinglefrequencystrea_T GalileoE5bstream;// '<S18>/Galileo E5b stream'
        P_Galileosinglefrequencystrea_T GalileoE5astream;// '<S18>/Galileo E5a stream'
        P_Galileosinglefrequencystrea_T GalileoE5stream;// '<S18>/Galileo E5 stream'
        P_Galileosinglefrequencystrea_T GalileoE1stream;// '<S18>/Galileo E1 stream'
    };

    // Parameters for system: '<S123>/MATLAB Function'
    struct P_MATLABFunction_GNSSPreProce_T
    {
        GNSS_Measurement GNSS_Measurement_out_Y0;// Computed Parameter: GNSS_Measurement_out_Y0
                                                    //  Referenced by: '<S124>/GNSS_Measurement_out'

        real_T alert_Y0;               // Computed Parameter: alert_Y0
                                          //  Referenced by: '<S124>/alert'

        real_T HPL_Y0;                 // Computed Parameter: HPL_Y0
                                          //  Referenced by: '<S124>/HPL'

        real_T test_statistic_Y0;      // Computed Parameter: test_statistic_Y0
                                          //  Referenced by: '<S124>/test_statistic'

        real_T PRNs_identified_Y0;     // Computed Parameter: PRNs_identified_Y0
                                          //  Referenced by: '<S124>/PRNs_identified'

        real_T PRNs_to_exclude_Y0;     // Computed Parameter: PRNs_to_exclude_Y0
                                          //  Referenced by: '<S124>/PRNs_to_exclude'

        real_T PRNs_excluded_Y0;       // Computed Parameter: PRNs_excluded_Y0
                                          //  Referenced by: '<S124>/PRNs_excluded'

    };

    // Parameters for system: '<S5>/Mode Switch'
    struct P_ModeSwitch_GNSSPreProcessin_T
    {
        real_T CompareToConstant_const;// Mask Parameter: CompareToConstant_const
                                          //  Referenced by: '<S133>/Constant'

        real_T DetectChange_vinit;     // Mask Parameter: DetectChange_vinit
                                          //  Referenced by: '<S134>/Delay Input1'

        boolean_T SRFlipFlop_initial_condition;// Mask Parameter: SRFlipFlop_initial_condition
                                                  //  Referenced by: '<S135>/Memory'

        real_T Constant1_Value;        // Expression: 0
                                          //  Referenced by: '<S130>/Constant1'

        real_T DiscreteTimeIntegrator_gainval;// Computed Parameter: DiscreteTimeIntegrator_gainval
                                                 //  Referenced by: '<S130>/Discrete-Time Integrator'

        real_T Constant2_Value;        // Expression: 5
                                          //  Referenced by: '<S131>/Constant2'

        real_T Constant3_Value;        // Expression: 5
                                          //  Referenced by: '<S131>/Constant3'

        real_T Constant4_Value;        // Expression: 3
                                          //  Referenced by: '<S131>/Constant4'

        real_T Constant5_Value;        // Expression: 4
                                          //  Referenced by: '<S131>/Constant5'

        real_T Constant6_Value;        // Expression: 3
                                          //  Referenced by: '<S131>/Constant6'

        real_T Constant_Value;         // Expression: 1
                                          //  Referenced by: '<S130>/Constant'

        boolean_T Logic_table[16];     // Computed Parameter: Logic_table
                                          //  Referenced by: '<S135>/Logic'

    };

    // Parameters (default storage)
    struct P_GNSSPreProcessingDualAntenn_T
    {
        real_T table_chi_square[80];   // Variable: table_chi_square
                                          //  Referenced by:
                                          //    '<S124>/Weighted RAIM Parity'
                                          //    '<S251>/Weighted RAIM Parity'

        real_T table_sigma_noise_GNSSReceiver[4];// Variable: table_sigma_noise_GNSSReceiver
                                                    //  Referenced by:
                                                    //    '<S124>/calculate Variance'
                                                    //    '<S251>/calculate Variance'

        GNSSMeasurementFixed GnssMeasurementDDBus_Y0;// Computed Parameter: GnssMeasurementDDBus_Y0
                                                        //  Referenced by: '<S3>/GnssMeasurementDDBus'

        real_T GnssMeasurementSizeDDDualantenn;// Computed Parameter: GnssMeasurementSizeDDDualantenn
                                                  //  Referenced by: '<S3>/GnssMeasurementSizeDDDualantenn'

        real_T idx_sync_r_Y0;          // Computed Parameter: idx_sync_r_Y0
                                          //  Referenced by: '<S3>/idx_sync_r'

        real_T idx_sync_u_Y0;          // Computed Parameter: idx_sync_u_Y0
                                          //  Referenced by: '<S3>/idx_sync_u'

        real_T Switch_1_Threshold;     // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_2_Threshold;     // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_3_Threshold;     // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_4_Threshold;     // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_5_Threshold;     // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_6_Threshold;     // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_7_Threshold;     // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_8_Threshold;     // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_9_Threshold;     // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_10_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_11_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_12_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_13_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_14_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_15_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_16_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_17_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_18_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_19_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_20_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_21_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_22_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_23_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_24_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_25_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_26_Threshold;    // Expression: 0
                                          //  Referenced by: '<S5>/Switch'

        real_T Switch_1_Threshold_m;   // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_2_Threshold_m;   // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_3_Threshold_m;   // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_4_Threshold_m;   // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_5_Threshold_m;   // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_6_Threshold_m;   // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_7_Threshold_m;   // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_8_Threshold_m;   // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_9_Threshold_m;   // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_10_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_11_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_12_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_13_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_14_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_15_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_16_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_17_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_18_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_19_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_20_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_21_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_22_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_23_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_24_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_25_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        real_T Switch_26_Threshold_m;  // Expression: 0
                                          //  Referenced by: '<S6>/Switch'

        uint16_T svidRefSatGPS_Y0;     // Computed Parameter: svidRefSatGPS_Y0
                                          //  Referenced by: '<S3>/svidRefSatGPS'

        uint16_T svidRefSatGAL_Y0;     // Computed Parameter: svidRefSatGAL_Y0
                                          //  Referenced by: '<S3>/svidRefSatGAL'

        P_ModeSwitch_GNSSPreProcessin_T ModeSwitch_f;// '<S6>/Mode Switch'
        P_MATLABFunction_GNSSPreProce_T sf_MATLABFunction_o;// '<S250>/MATLAB Function'
        P_Galileo_GNSSPreProcessingDu_T Galileo_h;// '<S6>/Galileo'
        P_GPS_GNSSPreProcessingDualAn_T GPS_o;// '<S6>/GPS'
        P_ModeSwitch_GNSSPreProcessin_T ModeSwitch;// '<S5>/Mode Switch'
        P_MATLABFunction_GNSSPreProce_T sf_MATLABFunction;// '<S123>/MATLAB Function'
        P_Galileo_GNSSPreProcessingDu_T Galileo;// '<S5>/Galileo'
        P_GPS_GNSSPreProcessingDualAn_T GPS;// '<S5>/GPS'
    };

    // Real-time Model Data Structure
    struct RT_MODEL_GNSSPreProcessingDua_T
    {
        const char_T * volatile errorStatus;

        //
        //  Timing:
        //  The following substructure contains information regarding
        //  the timing information for the model.

        struct
        {
            uint32_T clockTick0;
        }
        Timing;
    };

    // Copy Constructor
    GNSSPreProcessingDualAntenna(GNSSPreProcessingDualAntenna const&) = delete;

    // Assignment Operator
    GNSSPreProcessingDualAntenna& operator= (GNSSPreProcessingDualAntenna const&) & = delete;

    // Move Constructor
    GNSSPreProcessingDualAntenna(GNSSPreProcessingDualAntenna &&) = delete;

    // Move Assignment Operator
    GNSSPreProcessingDualAntenna& operator= (GNSSPreProcessingDualAntenna &&) = delete;

    // Real-Time Model get method
    GNSSPreProcessingDualAntenna::RT_MODEL_GNSSPreProcessingDua_T * getRTM();

    // Root inports set method
    void setExternalInputs(const ExtU_GNSSPreProcessingDualAnt_T *pExtU_GNSSPreProcessingDualAnt_T)
    {
        GNSSPreProcessingDualAntenna_U = *pExtU_GNSSPreProcessingDualAnt_T;
    }

    // Root outports get method
    const ExtY_GNSSPreProcessingDualAnt_T &getExternalOutputs() const
    {
        return GNSSPreProcessingDualAntenna_Y;
    }

    // model initialize function
    void initialize();

    // model step function
    void step();

    // model terminate function
    static void terminate();

    // Constructor
    GNSSPreProcessingDualAntenna();

    // Destructor
    ~GNSSPreProcessingDualAntenna();

    // private data and function members
  private:
    // External inputs
    ExtU_GNSSPreProcessingDualAnt_T GNSSPreProcessingDualAntenna_U;

    // External outputs
    ExtY_GNSSPreProcessingDualAnt_T GNSSPreProcessingDualAntenna_Y;

    // Block signals
    B_GNSSPreProcessingDualAntenn_T GNSSPreProcessingDualAntenna_B;

    // Block states
    DW_GNSSPreProcessingDualAnten_T GNSSPreProcessingDualAntenna_DW;

    // Tunable parameters
    static P_GNSSPreProcessingDualAntenn_T GNSSPreProcessingDualAntenna_P;

    // private member function(s) for subsystem '<Root>/Calculate User Position with LMS'
    void GN_CalculateUserPositionwithLMS(const GNSS_Measurement *rtu_gnss_measurement, const GNSS_Measurement_size
        *rtu_gnss_measurement_DIMS1, real_T rty_user_position_llh[3], real_T rty_user_velocity_ned[3], real_T
        *rty_receiver_Clock_Bias, real_T *rty_receiver_Clock_Drift, boolean_T *rty_position_Available,
        B_CalculateUserPositionwithLM_T *localB);
    real_T GNSSPreProcessingDualAnten_norm(const real_T x[3], B_CalculateUserPositionwithLM_T *localB);
    void GNSSPreProce_binary_expand_op_k(real_T in1_data[], int32_T in2, const real_T in3_data[], const real_T in4_data[],
        const int32_T in4_size[2], const real_T in5[4], B_CalculateUserPositionwithLM_T *localB);
    void GNSSPreProcess_binary_expand_op(real_T in1_data[], const int32_T in1_size[2], int32_T in2, const real_T
        in3_data[], const int32_T in3_size[2], const real_T in4[4], B_CalculateUserPositionwithLM_T *localB);
    void GNSSPreProcessingDual_getJacobi(const real_T satellite_position_data[], const int32_T satellite_position_size[2],
        const real_T pseudorange_data[], const int32_T *pseudorange_size, const real_T user_state[4], real_T
        delta_rho_data[], int32_T *delta_rho_size, real_T H_data[], int32_T H_size[2], real_T residuum[4],
        B_CalculateUserPositionwithLM_T *localB);
    real_T GNSSPreProcessingDualAnte_xnrm2(int32_T n, const real_T x_data[], int32_T ix0,
        B_CalculateUserPositionwithLM_T *localB);
    real_T GNSSPreProcessing_rt_hypotd_snf(real_T u0, real_T u1, B_CalculateUserPositionwithLM_T *localB);
    void GNSSPreProcessingDualAn_qrsolve(const real_T A_data[], const int32_T A_size[2], const real_T B_data[], const
        int32_T *B_size, real_T Y[4], B_CalculateUserPositionwithLM_T *localB);
    void GNSSPreProcessingDua_mldivide_o(const real_T A_data[], const int32_T A_size[2], real_T B_data[], int32_T
        *B_size, B_CalculateUserPositionwithLM_T *localB);
    void GNSSPreProcessingDualAnten_plus(real_T in1[4], const real_T in2_data[], const int32_T *in2_size);

    // private member function(s) for subsystem '<S5>/Calculate Day of Year'
    static void GNSSPreProce_CalculateDayofYear(real_T rtu_WNc, real_T rtu_TOW, real_T *rty_dayOfYear,
        DW_CalculateDayofYear_GNSSPre_T *localDW);

    // private member function(s) for subsystem '<S5>/ConvertGNSSMeasuremendVariableToFixed_CalcAngles'
    void ConvertGNSSMeasuremendVariableT(const GNSS_Measurement *rtu_GNSSMeasurementVariable, const
        GNSS_Measurement_size *rtu_GNSSMeasurementVariab_DIMS1, const real_T rtu_user_pos_llh[3], GNSSMeasurementFixed
        *rty_GNSSMeasurementFixed, real_T *rty_sizeOfMesasurements, B_ConvertGNSSMeasuremendVaria_T *localB);
    void GNSSPreProce_binary_expand_op_a(real_T in1[3], const real_T in2_data[], const int32_T in2_size[2], int32_T in3,
        const real_T in4[3], B_ConvertGNSSMeasuremendVaria_T *localB);
    real_T GNSSPreProcessing_rt_atan2d_snf(real_T u0, real_T u1, B_ConvertGNSSMeasuremendVaria_T *localB);
    void calculate_Satellite_Elevation_A(const real_T user_Position_llh[3], const real_T satellite_Position_ecef_data[],
        const int32_T satellite_Position_ecef_size[2], real_T elevation_Angle_data[], int32_T *elevation_Angle_size,
        real_T azimuth_Angle_data[], int32_T *azimuth_Angle_size, B_ConvertGNSSMeasuremendVaria_T *localB);

    // private member function(s) for subsystem '<S5>/Dummy GNSS Measurement'
    static void GNSSPrePro_DummyGNSSMeasurement(B_DummyGNSSMeasurement_GNSSPr_T *localB, DW_DummyGNSSMeasurement_GNSSP_T
        *localDW);

    // private member function(s) for subsystem '<S5>/Fuse'
    static void GNSSPreProcessingDualAnten_Fuse(const uint16_T rtu_u1[40], const int32_T *rtu_u1_DIMS1, const uint16_T
        rtu_u2[40], const int32_T *rtu_u2_DIMS1, B_Fuse_GNSSPreProcessingDualA_T *localB,
        DW_Fuse_GNSSPreProcessingDual_T *localDW);

    // private member function(s) for subsystem '<S5>/GNSS Measurement Epoch Splitter'
    void GN_GNSSMeasurementEpochSplitter(const gnssraw_measurement_t *rtu_MeasurementEpochBus, real_T *rty_WNc, real_T
        *rty_TOW, gnssraw_measurement_t *rty_GpsMeasurementBus, gnssraw_measurement_t *rty_GalMeasurementBus,
        B_GNSSMeasurementEpochSplitte_T *localB);
    int32_T GNSSPrePr_combineVectorElements(const boolean_T x[40]);

    // private member function(s) for subsystem '<S32>/Calculate Satellite Clock Correction'
    void CalculateSatelliteClockCorrecti(real_T rtu_TOW, const gnssops_navigation_data *rtu_GnssNavBus, const
        gnssops_navigation_data_size *rtu_GnssNavBus_DIMS1, const real_T rtu_pseudorange[40], const int32_T
        *rtu_pseudorange_DIMS1, real_T rtu_enableSatClockCorr, const real_T rtu_delta_t_sv_EGNOS[110],
        B_CalculateSatelliteClockCorr_T *localB, DW_CalculateSatelliteClockCor_T *localDW);
    void GNSS_binary_expand_op_ngwdjig3x(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const gnssops_navigation_data *in3, const gnssops_navigation_data_size *in4,
        B_CalculateSatelliteClockCorr_T *localB);
    void GNSSP_binary_expand_op_ngwdjig3(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const gnssops_navigation_data *in3, const gnssops_navigation_data_size *in4,
        B_CalculateSatelliteClockCorr_T *localB);
    real_T GNSSPreProcessingDu_rt_powd_snf(real_T u0, real_T u1, B_CalculateSatelliteClockCorr_T *localB);
    void GNSSPr_binary_expand_op_ngwdjig(real_T in1_data[], int32_T in1_size[2], const gnssops_navigation_data *in2,
        const gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T in4_size[2], const real_T
        in5_data[], const int32_T in5_size[2], B_CalculateSatelliteClockCorr_T *localB);
    void GNSSPre_binary_expand_op_ngwdji(real_T in1_data[], int32_T in1_size[2], const gnssops_navigation_data *in2,
        const gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T in4_size[2],
        B_CalculateSatelliteClockCorr_T *localB);
    void GNSSPreProce_binary_expand_op_n(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const gnssops_navigation_data *in3, const gnssops_navigation_data_size *in4, const real_T in5_data[],
        const int32_T in5_size[2], B_CalculateSatelliteClockCorr_T *localB);
    void GNSSPreP_binary_expand_op_ngwdj(real_T in1_data[], int32_T in1_size[2], const gnssops_navigation_data *in2,
        const gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T in4_size[2], const real_T
        in5_data[], const int32_T in5_size[2], B_CalculateSatelliteClockCorr_T *localB);
    void GNSSPreProcessingDualAnte_minus(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateSatelliteClockCorr_T *localB);
    void GNSSPrePr_binary_expand_op_ngwd(real_T in1_data[], int32_T *in1_size, const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3[110], const gnssops_navigation_data *in4, const gnssops_navigation_data_size *in5,
        B_CalculateSatelliteClockCorr_T *localB);
    void GNSSPrePro_binary_expand_op_ngw(real_T in1_data[], int32_T *in1_size, const gnssops_navigation_data *in2, const
        gnssops_navigation_data_size *in3, const real_T in4_data[], const int32_T in4_size[2],
        B_CalculateSatelliteClockCorr_T *localB);
    void GNSSPreProc_binary_expand_op_ng(real_T in1_data[], int32_T *in1_size, const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateSatelliteClockCorr_T *localB);

    // private member function(s) for subsystem '<S32>/Calculate Satellite Position and Velocity'
    void CalculateSatellitePositionandVe(real_T rtu_enableSatPosVelCalc, const real_T rtu_userPosLlh[3], const
        gnssops_navigation_data *rtu_GnssNavBus, const gnssops_navigation_data_size *rtu_GnssNavBus_DIMS1, const real_T
        rtu_timeEmissionCorrected[40], const int32_T *rtu_timeEmissionCorrected_DIMS1, const real_T
        rtu_delta_satPosECEF_EGNOS[330], B_CalculateSatellitePositiona_T *localB, DW_CalculateSatellitePosition_T
        *localDW);
    void GNSSPreProcessingDualAn_minus_p(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2]);
    void correct_Gps_Time_At_Week_Crosso(real_T b_time_data[], int32_T b_time_size[2]);
    real_T GNSSPreProcessing_rt_powd_snf_n(real_T u0, real_T u1, B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProcessingDualAnt_plus_a(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProce_binary_expand_op_i(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProce_binary_expand_op_p(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProce_binary_expand_op_f(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProc_binary_expand_op_lz(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProcessingDualA_minus_pv(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateSatellitePositiona_T *localB);
    void GN_Get_Kepler_Eccentric_Anomaly(const real_T t_k_data[], const int32_T t_k_size[2], const real_T
        Ephemeris_DELTA_N_data[], const int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[], const
        int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_E_data[], const int32_T Ephemeris_E_size[2], const real_T
        Ephemeris_SQRT_A_data[], const int32_T Ephemeris_SQRT_A_size[2], real_T E_k_data[], int32_T E_k_size[2], real_T
        E_k_Dot_data[], int32_T E_k_Dot_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProcessingDualAntenn_cos(real_T x_data[], const int32_T x_size[2]);
    void GNSSPreProcessingDualAntenn_sin(real_T x_data[], const int32_T x_size[2]);
    void GNSSPreProcessingDualAn_times_h(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2]);
    void GNSSPreProcessingDualAnten_sqrt(real_T x_data[], const int32_T x_size[2], B_CalculateSatellitePositiona_T
        *localB);
    real_T GNSSPreProcessi_rt_atan2d_snf_p(real_T u0, real_T u1, B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProcessingD_expand_atan2(const real_T a_data[], const int32_T a_size[2], const real_T b_data[], const
        int32_T b_size[2], real_T c_data[], int32_T c_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProcessingDualAnte_atan2(const real_T y_data[], const int32_T y_size[2], const real_T x_data[], const
        int32_T x_size[2], real_T r_data[], int32_T r_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProc_binary_expand_op_hi(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProce_binary_expand_op_m(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProce_binary_expand_op_l(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProce_binary_expand_op_c(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProc_binary_expand_op_ap(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
        in8_size[2], B_CalculateSatellitePositiona_T *localB);
    void binary_expand_o_hiccmd4tjww0ixx(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProcessingDualA_times_hi(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateSatellitePositiona_T *localB);
    void binary_expand_op_hiccmd4tjww0ix(real_T in1_data[], const real_T in2_data[], const int32_T in2_size[2], const
        real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const real_T
        in5_data[], const int32_T in5_size[2]);
    void binary_expand_op_hiccmd4tjww0i(real_T in1_data[], const int32_T in1_size[2], const real_T in2_data[], const
        int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
    void G_binary_expand_op_hiccmd4tjww0(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateSatellitePositiona_T *localB);
    void GN_binary_expand_op_hiccmd4tjww(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2]);
    void GNS_binary_expand_op_hiccmd4tjw(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
        in8_size[2], const real_T in9_data[], const int32_T in9_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSS_binary_expand_op_hiccmd4tj(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSP_binary_expand_op_hiccmd4t(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPr_binary_expand_op_hiccmd4(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProcessingDualAnte_times(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPre_binary_expand_op_hiccmd(real_T in1_data[], const real_T in2_data[], const int32_T in2_size[2], const
        real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const real_T
        in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const real_T
        in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T in8_size[2], const real_T
        in9_data[], const int32_T in9_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreP_binary_expand_op_hiccm(real_T in1_data[], const int32_T in1_size[2], const real_T in2_data[], const
        int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
        in8_size[2], const real_T in9_data[], const int32_T in9_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPrePr_binary_expand_op_hicc(real_T in1_data[], const int32_T in1_size[2], const real_T in2_data[], const
        int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
    void GNSSPreProcessingDualAnt_sqrt_h(real_T x_data[], const int32_T *x_size, B_CalculateSatellitePositiona_T *localB);
    void Get_Kepler_Satellite_Position_A(const real_T Ephemeris_C_rs_data[], const int32_T Ephemeris_C_rs_size[2], const
        real_T Ephemeris_DELTA_N_data[], const int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[],
        const int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_C_uc_data[], const int32_T Ephemeris_C_uc_size[2],
        const real_T Ephemeris_E_data[], const int32_T Ephemeris_E_size[2], const real_T Ephemeris_C_us_data[], const
        int32_T Ephemeris_C_us_size[2], const real_T Ephemeris_SQRT_A_data[], const int32_T Ephemeris_SQRT_A_size[2],
        const real_T Ephemeris_T_oe_data[], const int32_T Ephemeris_T_oe_size[2], const real_T Ephemeris_C_ic_data[],
        const int32_T Ephemeris_C_ic_size[2], const real_T Ephemeris_OMEGA_0_data[], const int32_T
        Ephemeris_OMEGA_0_size[2], const real_T Ephemeris_C_is_data[], const int32_T Ephemeris_C_is_size[2], const
        real_T Ephemeris_I_0_data[], const int32_T Ephemeris_I_0_size[2], const real_T Ephemeris_C_rc_data[], const
        int32_T Ephemeris_C_rc_size[2], const real_T Ephemeris_omega_data[], const int32_T Ephemeris_omega_size[2],
        const real_T Ephemeris_OMEGADOT_data[], const int32_T Ephemeris_OMEGADOT_size[2], const real_T
        Ephemeris_IDOT_data[], const int32_T Ephemeris_IDOT_size[2], const real_T T_emission_data[], const int32_T
        T_emission_size[2], const real_T user_position[3], real_T sv_pos_data[], int32_T sv_pos_size[2], real_T
        sv_vel_data[], int32_T sv_vel_size[2], B_CalculateSatellitePositiona_T *localB);
    void GNSSPreProce_binary_expand_op_h(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3[330], const gnssops_navigation_data *in4, const gnssops_navigation_data_size *in5);

    // private member function(s) for subsystem '<S32>/Time Correction Carrierphase'
    void GNSS_TimeCorrectionCarrierphase(const real_T rtu_deltaTimeSV[40], const int32_T *rtu_deltaTimeSV_DIMS1, const
        real_T rtu_carrierphase[40], const int32_T *rtu_carrierphase_DIMS1, real_T rtu_Signal_in_Use,
        B_TimeCorrectionCarrierphase__T *localB, DW_TimeCorrectionCarrierphase_T *localDW);
    void GNSSPreProc_binary_expand_op_m1(real_T in1_data[], int32_T *in1_size, const real_T in2[40], const int32_T *in3,
        const real_T in4[40], const int32_T *in5, real_T in6);

    // private member function(s) for subsystem '<S32>/Time Correction Deltarange'
    void GNSSPr_TimeCorrectionDeltarange(const real_T rtu_drTimeCorr[40], const int32_T *rtu_drTimeCorr_DIMS1, const
        real_T rtu_deltarange[40], const int32_T *rtu_deltarange_DIMS1, B_TimeCorrectionDeltarange_GN_T *localB,
        DW_TimeCorrectionDeltarange_G_T *localDW);
    void GNSSPreProc_binary_expand_op_lp(real_T in1_data[], int32_T *in1_size, const real_T in2[40], const int32_T *in3,
        const real_T in4[40], const int32_T *in5);

    // private member function(s) for subsystem '<S32>/Time Correction Pseudorange'
    void GNSSP_TimeCorrectionPseudorange(const real_T rtu_deltaTimeSV[40], const int32_T *rtu_deltaTimeSV_DIMS1, const
        real_T rtu_pseudorange[40], const int32_T *rtu_pseudorange_DIMS1, B_TimeCorrectionPseudorange_G_T *localB,
        DW_TimeCorrectionPseudorange__T *localDW);
    void GNSSPreProc_binary_expand_op_l5(real_T in1_data[], int32_T *in1_size, const real_T in2[40], const int32_T *in3,
        const real_T in4[40], const int32_T *in5);

    // private member function(s) for subsystem '<S24>/Signal Noise Variance'
    static void GNSSPreProc_SignalNoiseVariance(const real_T rtu_carrierToNoiseRatio[40], const int32_T
        *rtu_carrierToNoiseRatio_DIMS1, boolean_T rtu_use_measured_variance, const real_T rtu_pr_sigma[40], const
        int32_T *rtu_pr_sigma_DIMS1, const real_T rtu_cp_sigma[40], const int32_T *rtu_cp_sigma_DIMS1,
        B_SignalNoiseVariance_GNSSPre_T *localB, DW_SignalNoiseVariance_GNSSPr_T *localDW);

    // private member function(s) for subsystem '<S17>/GPS L1 Stream'
    static void G_GPSsinglefrequencystream_Init(B_GPSsinglefrequencystream_GN_T *localB, P_GPSsinglefrequencystream_GN_T
        *localP);
    void GNSSPr_GPSsinglefrequencystream(boolean_T rtu_Enable, real_T rtu_timeOfWeekIn, const uint16_T rtu_SVID[40],
        const int32_T *rtu_SVID_DIMS1, const gnssops_navigation_data *rtu_GpsNavBus, const gnssops_navigation_data_size *
        rtu_GpsNavBus_DIMS1, const real_T rtu_pseudorange[40], const int32_T *rtu_pseudorange_DIMS1, const real_T
        rtu_deltarange[40], const int32_T *rtu_deltarange_DIMS1, const real_T rtu_carrierToNoiseRatio[40], const int32_T
        *rtu_carrierToNoiseRatio_DIMS1, const real_T rtu_userPosLlh[3], const real_T rtu_carrierphase[40], const int32_T
        *rtu_carrierphase_DIMS1, const real32_T rtu_locktime[40], const int32_T *rtu_locktime_DIMS1, const real_T
        rtu_base_position[3], boolean_T rtu_enable_SatPosVelCalc, boolean_T rtu_use_measured_cariance, const real_T
        rtu_pr_sigma[40], const int32_T *rtu_pr_sigma_DIMS1, const real_T rtu_cp_sigma[40], const int32_T
        *rtu_cp_sigma_DIMS1, real_T rtp_enable_SatClockCorr, B_GPSsinglefrequencystream_GN_T *localB,
        DW_GPSsinglefrequencystream_G_T *localDW, P_GPSsinglefrequencystream_GN_T *localP);

    // private member function(s) for subsystem '<S17>/Navigation Data Conversion GPS'
    static void GNS_NavigationDataConversionGPS(const gnssraw_gps_nav_t *rtu_GpsNavBus, B_NavigationDataConversionGPS_T *
        localB, DW_NavigationDataConversionGP_T *localDW);

    // private member function(s) for subsystem '<S29>/Calculate Differential Corrections'
    static void CalculateDifferentialCorre_Init(DW_CalculateDifferentialCorre_T *localDW);
    void CalculateDifferentialCorrection(const GNSS_Measurement *rtu_GpsMeasurementB, const GNSS_Measurement_size
        *rtu_GpsMeasurementB_DIMS1, const gnssops_navigation_data *rtu_gpsNavDataBusL1, const
        gnssops_navigation_data_size *rtu_gpsNavDataBusL1_DIMS1, const real_T rtu_userPosLlh[3],
        B_CalculateDifferentialCorrec_T *localB, DW_CalculateDifferentialCorre_T *localDW);
    void GNSSPreProcessingDualAnte_merge(int32_T idx_data[], uint16_T x_data[], int32_T offset, int32_T np, int32_T nq,
        int32_T iwork_data[], uint16_T xwork_data[], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProcessingDualAnten_sort(uint16_T x_data[], const int32_T *x_size, int32_T idx_data[], int32_T *idx_size,
        B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProcessingDua_do_vectors(const uint16_T a_data[], const int32_T *a_size, const real_T b_data[], const
        int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
        int32_T *ib_size);
    void GNSSP_binary_expand_op_evirnrbr(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const gnssops_navigation_data *in3, const real_T in5_data[], const int32_T *in5_size);
    void GNSSPreProcessingDualA_minus_f4(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2]);
    real_T GNSSPreProcessing_rt_powd_snf_p(real_T u0, real_T u1, B_CalculateDifferentialCorrec_T *localB);
    void GNSSPr_binary_expand_op_evirnrb(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPre_binary_expand_op_evirnr(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateDifferentialCorrec_T *localB);
    boolean_T GNSSPreProcessingDualAntenn_any(const boolean_T x_data[], const int32_T x_size[2],
        B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProce_binary_expand_op_e(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProcessingDualAn_minus_f(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreP_binary_expand_op_evirn(real_T in1_data[], int32_T in1_size[2], const gnssops_navigation_data *in2,
        const real_T in4_data[], const int32_T *in4_size, const real_T in5_data[], const int32_T in5_size[2], const
        real_T in6_data[], const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2],
        B_CalculateDifferentialCorrec_T *localB);
    void correct_Gps_Time_At_Week_Cros_b(real_T b_time_data[], int32_T b_time_size[2]);
    void GNSSPreProcessingDualAnt_plus_d(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProc_binary_expand_op_ai(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProce_binary_expand_op_b(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateDifferentialCorrec_T *localB);
    void Get_Kepler_Eccentric_Anomaly_h(const real_T t_k_data[], const int32_T t_k_size[2], const real_T
        Ephemeris_DELTA_N_data[], const int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[], const
        int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_E_data[], const int32_T Ephemeris_E_size[2], const real_T
        Ephemeris_SQRT_A_data[], const int32_T Ephemeris_SQRT_A_size[2], real_T E_k_data[], int32_T E_k_size[2], real_T
        E_k_Dot_data[], int32_T E_k_Dot_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProcessingDualAnte_cos_p(real_T x_data[], const int32_T x_size[2]);
    void GNSSPreProcessingDualAnte_sin_l(real_T x_data[], const int32_T x_size[2]);
    void GNSSPreProcessingDualA_times_ce(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2]);
    void GNSSPreProcessingDualAnt_sqrt_f(real_T x_data[], const int32_T x_size[2], B_CalculateDifferentialCorrec_T
        *localB);
    real_T GNSSPreProcessi_rt_atan2d_snf_j(real_T u0, real_T u1, B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProcessin_expand_atan2_l(const real_T a_data[], const int32_T a_size[2], const real_T b_data[], const
        int32_T b_size[2], real_T c_data[], int32_T c_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProcessingDualAn_atan2_d(const real_T y_data[], const int32_T y_size[2], const real_T x_data[], const
        int32_T x_size[2], real_T r_data[], int32_T r_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSS_binary_expand_op_evirnrbrc(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProc_binary_expand_op_ka(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProc_binary_expand_op_jl(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProc_binary_expand_op_ik(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProce_binary_expand_op_j(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
        in8_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProc_binary_expand_op_nf(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProcessingDual_times_ce5(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProc_binary_expand_op_ak(real_T in1_data[], const real_T in2_data[], const int32_T in2_size[2], const
        real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const real_T
        in5_data[], const int32_T in5_size[2]);
    void GNSSPreProce_binary_expand_op_o(real_T in1_data[], const int32_T in1_size[2], const real_T in2_data[], const
        int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
    void GNSSPreProc_binary_expand_op_ay(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProc_binary_expand_op_ce(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2]);
    void GNSSPreProce_binary_expand_op_d(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
        in8_size[2], const real_T in9_data[], const int32_T in9_size[2], const real_T in10_data[], const int32_T
        in10_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProce_binary_expand_op_g(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], B_CalculateDifferentialCorrec_T *localB);
    void binary_expand_o_evirnrbrctmpazf(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateDifferentialCorrec_T *localB);
    void binary_expand_op_evirnrbrctmpaz(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPreProcessingDualAn_times_c(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateDifferentialCorrec_T *localB);
    void binary_expand_op_evirnrbrctmpa(real_T in1_data[], const real_T in2_data[], const int32_T in2_size[2], const
        real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const real_T
        in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const real_T
        in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T in8_size[2], const real_T
        in9_data[], const int32_T in9_size[2], B_CalculateDifferentialCorrec_T *localB);
    void G_binary_expand_op_evirnrbrctmp(real_T in1_data[], const int32_T in1_size[2], const real_T in2_data[], const
        int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
        in8_size[2], const real_T in9_data[], const int32_T in9_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GN_binary_expand_op_evirnrbrctm(real_T in1_data[], const int32_T in1_size[2], const real_T in2_data[], const
        int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
    void GNSSPreProcessingDualAn_sqrt_fe(real_T x_data[], const int32_T *x_size, B_CalculateDifferentialCorrec_T *localB);
    void Get_Kepler_Satellite_Position_b(const real_T Ephemeris_C_rs_data[], const int32_T Ephemeris_C_rs_size[2], const
        real_T Ephemeris_DELTA_N_data[], const int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[],
        const int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_C_uc_data[], const int32_T Ephemeris_C_uc_size[2],
        const real_T Ephemeris_E_data[], const int32_T Ephemeris_E_size[2], const real_T Ephemeris_C_us_data[], const
        int32_T Ephemeris_C_us_size[2], const real_T Ephemeris_SQRT_A_data[], const int32_T Ephemeris_SQRT_A_size[2],
        const real_T Ephemeris_T_oe_data[], const int32_T Ephemeris_T_oe_size[2], const real_T Ephemeris_C_ic_data[],
        const int32_T Ephemeris_C_ic_size[2], const real_T Ephemeris_OMEGA_0_data[], const int32_T
        Ephemeris_OMEGA_0_size[2], const real_T Ephemeris_C_is_data[], const int32_T Ephemeris_C_is_size[2], const
        real_T Ephemeris_I_0_data[], const int32_T Ephemeris_I_0_size[2], const real_T Ephemeris_C_rc_data[], const
        int32_T Ephemeris_C_rc_size[2], const real_T Ephemeris_omega_data[], const int32_T Ephemeris_omega_size[2],
        const real_T Ephemeris_OMEGADOT_data[], const int32_T Ephemeris_OMEGADOT_size[2], const real_T
        Ephemeris_IDOT_data[], const int32_T Ephemeris_IDOT_size[2], const real_T T_emission_data[], const int32_T
        T_emission_size[2], const real_T user_position[3], real_T sv_pos_data[], int32_T sv_pos_size[2], real_T
        sv_vel_data[], int32_T sv_vel_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPrePr_binary_expand_op_evir(const gnssops_navigation_data *in1, const real_T in3_data[], const int32_T
        *in3_size, const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2],
        const real_T in6_data[], const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const
        real_T in8_data[], const int32_T in8_size[2], const real_T in9_data[], const int32_T in9_size[2], const real_T
        in10_data[], const int32_T in10_size[2], const real_T in11[3], real_T in12_data[], int32_T in12_size[2], real_T
        in13_data[], int32_T in13_size[2], B_CalculateDifferentialCorrec_T *localB);
    void GNSSPrePro_binary_expand_op_evi(real_T in1_data[], int32_T *in1_size, const real_T in2_data[], const int32_T
        in3_data[], const int32_T *in3_size, const real_T in4_data[], const int32_T *in4_size);
    void GNSSPreProc_binary_expand_op_ev(real_T in1_data[], int32_T *in1_size, const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateDifferentialCorrec_T *localB);

    // private member function(s) for subsystem '<S57>/Calculate Dualfrequency Correction with L1 and L2C'
    void CalculateDualfrequencyCorrectio(const GNSS_Measurement *rtu_measurementBusL1, const GNSS_Measurement_size
        *rtu_measurementBusL1_DIMS1, const GNSS_Measurement *rtu_measurementBusL2C, const GNSS_Measurement_size
        *rtu_measurementBusL2C_DIMS1, boolean_T rtu_enableDualFrequencyCorrecti, B_CalculateDualfrequencyCorre_T *localB,
        DW_CalculateDualfrequencyCorr_T *localDW);
    void GNSSPreProcessingD_do_vectors_k(const uint16_T a_data[], const int32_T *a_size, const uint16_T b_data[], const
        int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
        int32_T *ib_size, B_CalculateDualfrequencyCorre_T *localB);

    // private member function(s) for subsystem '<S57>/Calculate Klobuchar Model Correction'
    static void CalculateKlobucharModelCorrecti(const real_T rtu_userPosLlh[3], const real_T rtu_elevationAngle[40],
        const int32_T *rtu_elevationAngle_DIMS1, const real_T rtu_azimuthAngle[40], const int32_T rtu_satPosEcef_DIMS1[2],
        real_T rtu_TOW, const gnssraw_gps_ion_t *rtu_GpsIonBus, boolean_T rtu_enableKlobucharCorrection,
        B_CalculateKlobucharModelCorr_T *localB, DW_CalculateKlobucharModelCor_T *localDW);

    // private member function(s) for subsystem '<S29>/Calculate Tropospheric Corrections'
    void CalculateTroposphericCorrection(real_T rtu_dayOfYear, boolean_T rtu_enableTroposphericCorrectio, const real_T
        rtu_userPosLlh[3], const real_T rtu_elevationAngle[40], const int32_T *rtu_elevationAngle_DIMS1,
        B_CalculateTroposphericCorrec_T *localB, DW_CalculateTroposphericCorre_T *localDW);
    real_T GNSSPreProcessingDualAn_interp1(const real_T varargin_1[5], const real_T varargin_2[5], real_T varargin_3,
        B_CalculateTroposphericCorrec_T *localB);
    real_T GNSSPreProcessing_rt_powd_snf_b(real_T u0, real_T u1, B_CalculateTroposphericCorrec_T *localB);
    void GNSSPreProcessingD_expand_power(const real_T a_data[], const int32_T *a_size, const real_T b_data[], const
        int32_T *b_size, real_T c_data[], int32_T *c_size, B_CalculateTroposphericCorrec_T *localB);
    void GNSSPreProc_binary_expand_op_gi(real_T in1_data[], int32_T *in1_size, const real_T in2[40], int32_T in3, const
        real_T in4_data[], const int32_T *in4_size, const real_T in5_data[], const int32_T *in5_size, const real_T
        in6_data[], const int32_T *in6_size, const real_T in7_data[], const int32_T *in7_size, const real_T in8_data[],
        const int32_T *in8_size, const real_T in9_data[], const int32_T *in9_size, const real_T in10[40], const int32_T *
        in11, const real_T in12_data[], const int32_T *in12_size, B_CalculateTroposphericCorrec_T *localB);

    // private member function(s) for subsystem '<S60>/Create Satellite Elevation Mask'
    void GN_CreateSatelliteElevationMask(const real_T rtu_userPosLlh[3], boolean_T rtu_userPos_isValid, const real_T
        rtu_satPosEcef[120], const int32_T rtu_satPosEcef_DIMS1[2], real_T rtu_elevationMaskingAngle, real_T
        *rty_removedSats, B_CreateSatelliteElevationMas_T *localB, DW_CreateSatelliteElevationMa_T *localDW);
    void GNSSPreProc_binary_expand_op_pk(real_T in1[3], const real_T in2[120], const int32_T in3[2], int32_T in4, const
        real_T in5[3], B_CreateSatelliteElevationMas_T *localB);
    void GNSSPrePro_binary_expand_op_pkr(boolean_T in1_data[], int32_T *in1_size, const real_T in2[40], int32_T in3,
        real_T in4, const int8_T in5[2], B_CreateSatelliteElevationMas_T *localB);
    real_T GNSSPreProcessi_rt_atan2d_snf_o(real_T u0, real_T u1, B_CreateSatelliteElevationMas_T *localB);

    // private member function(s) for subsystem '<S61>/Apply Differential Correction Mask1'
    void ApplyDifferentialCorrectionMask(const GNSS_Measurement *rtu_GpsMeasurementBus, const GNSS_Measurement_size
        *rtu_GpsMeasurementBus_DIMS1, const real_T rtu_diffPseudorangeCorrections[40], const uint16_T
        rtu_diffCorrAvailableSvid[40], const int32_T *rtu_diffCorrAvailableSvidS1_DIM, boolean_T
        rtu_enableDiffCorrection, const real_T rtu_rtcm_base_position[3], boolean_T *rty_MeasurementCorrected,
        B_ApplyDifferentialCorrection_T *localB, DW_ApplyDifferentialCorrectio_T *localDW);
    void GNSSPreProcessingD_do_vectors_e(const uint16_T a_data[], const int32_T *a_size, const uint16_T b_data[], const
        int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
        int32_T *ib_size);
    void GNSSPrePro_binary_expand_op_eyk(real_T in1_data[], int32_T *in1_size, const GNSS_Measurement *in2, const
        int32_T in4_data[], const int32_T *in4_size, const real_T in5[40], const int32_T in7_data[], const int32_T
        *in7_size);
    void GNSSPreProc_binary_expand_op_ey(real_T in1_data[], int32_T *in1_size, const GNSS_Measurement *in2, const
        int32_T in4_data[], const int32_T *in4_size, const real_T in5[40], const int32_T in7_data[], const int32_T
        *in7_size);

    // private member function(s) for subsystem '<S61>/Apply Elevation and NaN and Zero Mask'
    void ApplyElevationandNaNandZeroMask(const GNSS_Measurement *rtu_measurementFrequencyCorrect, const
        GNSS_Measurement_size *rtu_measurementFrequencyC_DIMS1, const boolean_T rtu_elevationMask[40], const int32_T
        *rtu_elevationMask_DIMS1, uint16_T *rty_nan_errCnt, B_ApplyElevationandNaNandZero_T *localB,
        DW_ApplyElevationandNaNandZer_T *localDW);
    void GNSSPreProcessingDualAnte_any_j(const boolean_T x_data[], const int32_T x_size[2], boolean_T y_data[], int32_T *
        y_size);
    void GNSSPreProcessingDualAnt_any_j4(const boolean_T x_data[], const int32_T *x_size, boolean_T y_data[], int32_T
        *y_size);
    void GNSSPrePro_binary_expand_op_mey(boolean_T in1_data[], int32_T *in1_size, const GNSS_Measurement *in2, const
        GNSS_Measurement_size *in3, B_ApplyElevationandNaNandZero_T *localB);
    void GNSSPreProc_binary_expand_op_me(boolean_T in1_data[], int32_T *in1_size, const boolean_T in2[40], const int32_T
        *in3, const boolean_T in4_data[], const int32_T *in4_size, const GNSS_Measurement *in5, const
        GNSS_Measurement_size *in6, B_ApplyElevationandNaNandZero_T *localB);
    boolean_T GNSSPreProcessingDualAn_any_j43(const boolean_T x_data[], const int32_T *x_size);

    // private member function(s) for subsystem '<S17>/Simplify and Mask GPS Measurement Bus'
    void SimplifyandMaskGPSMeasurementBu(const gnssraw_measurement_t *rtu_GpsMeasurementBus, const
        gnssops_navigation_data *rtu_GpsNavBusReshaped, const gnssops_navigation_data_size *rtu_GpsNavBusReshaped_DIMS1,
        const parameters_gps_t *rtu_parameters_gps_Bus, B_SimplifyandMaskGPSMeasureme_T *localB,
        DW_SimplifyandMaskGPSMeasurem_T *localDW);
    void GNSSPreProcessingDualAnt_any_jv(const boolean_T x[200], boolean_T y[40]);
    void GNSSPreProcessingDualA_eml_find(const boolean_T x[4], int32_T i_data[], int32_T i_size[2]);
    void GNSSPreProcessingDualAn_merge_o(int32_T idx_data[], uint16_T x_data[], int32_T offset, int32_T np, int32_T nq,
        int32_T iwork_data[], uint16_T xwork_data[]);
    void GNSSPreProcessingDualAnt_sort_m(uint16_T x_data[], int32_T x_size[2], int32_T idx_data[], int32_T idx_size[2],
        B_SimplifyandMaskGPSMeasureme_T *localB);
    boolean_T GNSSPreProcessingDualAn_any_jvg(const boolean_T x_data[], const int32_T *x_size);
    void GNSSPrePro_binary_expand_op_jbw(real_T in1_data[], int32_T in1_size[2], const gnssraw_measurement_t *in2, const
        int8_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const int32_T
        in5_data[], const int8_T in6_data[], const int32_T in6_size[2], B_SimplifyandMaskGPSMeasureme_T *localB);
    void GNSSPreProcessingDualA_any_jvgx(const boolean_T x_data[], const int32_T x_size[2], boolean_T y_data[], int32_T
        y_size[2]);
    void emxConvertDynamicMatrixToEmx_37(emxArray_real_T_37_GNSSPrePro_T *emx, const real_T data[37], const int32_T
        *size);
    void emxConvertStructToEmx_gnssops_n(emxArray__gnssops_navigation__T *emx, const gnssops_navigation_data *data,
        const gnssops_navigation_data_size *size);
    void GNSSPreProc_binary_expand_op_jb(boolean_T in1_data[], int32_T *in1_size, const gnssops_navigation_data *in2,
        const gnssops_navigation_data_size *in3, const uint16_T in4[40], int32_T in6);
    void GNSSPreP_select_navigation_data(const emxArray__gnssops_navigation__T *navigation_data, const boolean_T
        mask_data[], const int32_T *mask_size, b_gnssops_navigation_data_GNS_T *navigation_data_selected,
        B_SimplifyandMaskGPSMeasureme_T *localB);

    // private member function(s) for subsystem '<S5>/GPS'
    static void GNSSPreProcessingDualA_GPS_Init(B_GPS_GNSSPreProcessingDualAn_T *localB, DW_GPS_GNSSPreProcessingDualA_T
        *localDW, P_GPS_GNSSPreProcessingDualAn_T *localP);
    void GNSSPreProcessingDualAntenn_GPS(const gnssraw_measurement_t *rtu_MeasurementEpochBus, const real_T
        rtu_GpsNavBus[37], const uint16_T rtu_GpsNavBus_c[37], const uint8_T rtu_GpsNavBus_k[37], const uint8_T
        rtu_GpsNavBus_b[37], const uint16_T rtu_GpsNavBus_h[37], const uint8_T rtu_GpsNavBus_hw[37], const real_T
        rtu_GpsNavBus_j[37], const uint32_T rtu_GpsNavBus_bj[37], const real_T rtu_GpsNavBus_e[37], const real_T
        rtu_GpsNavBus_a[37], const real_T rtu_GpsNavBus_n[37], const real_T rtu_GpsNavBus_nt[37], const real_T
        rtu_GpsNavBus_jc[37], const real_T rtu_GpsNavBus_o[37], const real_T rtu_GpsNavBus_jx[37], const real_T
        rtu_GpsNavBus_i[37], const real_T rtu_GpsNavBus_np[37], const real_T rtu_GpsNavBus_o0[37], const uint32_T
        rtu_GpsNavBus_oi[37], const real_T rtu_GpsNavBus_ic[37], const real_T rtu_GpsNavBus_ob[37], const real_T
        rtu_GpsNavBus_bs[37], const real_T rtu_GpsNavBus_n1[37], const real_T rtu_GpsNavBus_m[37], const real_T
        rtu_GpsNavBus_nb[37], const real_T rtu_GpsNavBus_nm[37], const real_T rtu_GpsNavBus_ia[37], const uint16_T
        rtu_GpsNavBus_ba[37], const uint16_T rtu_GpsNavBus_hv[37], real_T rtu_GpsIonBus, uint16_T rtu_GpsIonBus_a,
        uint8_T rtu_GpsIonBus_l, real_T rtu_GpsIonBus_e, real_T rtu_GpsIonBus_n, real_T rtu_GpsIonBus_l4, real_T
        rtu_GpsIonBus_h, real_T rtu_GpsIonBus_lc, real_T rtu_GpsIonBus_li, real_T rtu_GpsIonBus_i, real_T
        rtu_GpsIonBus_ee, const real_T rtu_userPosLlh[3], real_T rtu_dayOfYear, boolean_T rtu_parameters_gnss_Bus,
        boolean_T rtu_parameters_gnss_Bus_d, boolean_T rtu_parameters_gnss_Bus_a, real_T rtu_parameters_gnss_Bus_m,
        boolean_T rtu_parameters_gnss_Bus_e, boolean_T rtu_parameters_gnss_Bus_fh, boolean_T rtu_parameters_gnss_Bus_kp,
        boolean_T rtu_parameters_gnss_Bus_h, boolean_T rtu_parameters_gnss_Bus_l, boolean_T rtu_parameters_gnss_Bus_ab,
        const GNSS_Measurement *rtu_GpsMeasurementB, const GNSS_Measurement_size *rtu_GpsMeasurementB_DIMS1,
        B_GPS_GNSSPreProcessingDualAn_T *localB, DW_GPS_GNSSPreProcessingDualA_T *localDW,
        P_GPS_GNSSPreProcessingDualAn_T *localP);
    void GNSSPreProcessingD_do_vectors_a(const uint16_T a_data[], const int32_T *a_size, const uint16_T b_data[], const
        int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
        int32_T *ib_size, B_GPS_GNSSPreProcessingDualAn_T *localB);
    void GNSSPreProc_binary_expand_op_fy(GNSS_Measurement *in1, const int32_T in3_data[], const int32_T *in3_size, const
        real_T in4[40], const real_T in6[40], const int32_T in8_data[], const int32_T *in8_size,
        B_GPS_GNSSPreProcessingDualAn_T *localB);

    // private member function(s) for subsystem '<S18>/Galileo E1 stream'
    static void Galileosinglefrequencystre_Init(B_Galileosinglefrequencystrea_T *localB, P_Galileosinglefrequencystrea_T
        *localP);
    void GN_Galileosinglefrequencystream(boolean_T rtu_Enable, boolean_T rtu_E5_basedProcessing, real_T rtu_TOW, const
        uint16_T rtu_SVID[40], const int32_T *rtu_SVID_DIMS1, const gnssops_navigation_data *rtu_GAL_NavigationData_Bus,
        const gnssops_navigation_data_size *rtu_GAL_NavigationData_Bu_DIMS1, const real_T rtu_pseudorange[40], const
        int32_T *rtu_pseudorange_DIMS1, const real_T rtu_deltarange[40], const int32_T *rtu_deltarange_DIMS1, const
        real_T rtu_CN0[40], const int32_T *rtu_CN0_DIMS1, const real_T rtu_userPos_LLH[3], const real_T
        rtu_carrierPhase[40], const int32_T *rtu_carrierPhase_DIMS1, const real32_T rtu_locktime[40], const int32_T
        *rtu_locktime_DIMS1, const real_T rtu_basePos[3], boolean_T rtu_enable_SatPosVelCalc, boolean_T
        rtu_use_measured_variance, const real_T rtu_measured_pr_sigma[40], const int32_T *rtu_measured_pr_sigma_DIMS1,
        const real_T rtu_measured_cp_sigma[40], const int32_T *rtu_measured_cp_sigma_DIMS1, real_T
        rtp_enable_SatClockCorr, B_Galileosinglefrequencystrea_T *localB, DW_Galileosinglefrequencystre_T *localDW,
        P_Galileosinglefrequencystrea_T *localP);

    // private member function(s) for subsystem '<S18>/Navigation Data Conversion GAL'
    static void GNS_NavigationDataConversionGAL(const gnssraw_gal_nav_t *rtu_GAL_NAV_raw_Bus,
        B_NavigationDataConversionGAL_T *localB, DW_NavigationDataConversionGA_T *localDW);

    // private member function(s) for subsystem '<S76>/Calculate Differential Corrections'
    static void CalculateDifferentialCor_p_Init(DW_CalculateDifferentialCor_c_T *localDW);
    void CalculateDifferentialCorrecti_j(const GNSS_Measurement *rtu_GalMeasurementB, const GNSS_Measurement_size
        *rtu_GalMeasurementB_DIMS1, const gnssops_navigation_data *rtu_gpsNavDataBusL1, const
        gnssops_navigation_data_size *rtu_gpsNavDataBusL1_DIMS1, const real_T rtu_userPosLlh[3],
        B_CalculateDifferentialCorr_m_T *localB, DW_CalculateDifferentialCor_c_T *localDW);
    void GNSSPreProcessingDualAn_merge_g(int32_T idx_data[], uint16_T x_data[], int32_T offset, int32_T np, int32_T nq,
        int32_T iwork_data[], uint16_T xwork_data[], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProcessingDualAnt_sort_l(uint16_T x_data[], const int32_T *x_size, int32_T idx_data[], int32_T *idx_size,
        B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProcessingD_do_vectors_f(const uint16_T a_data[], const int32_T *a_size, const real_T b_data[], const
        int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
        int32_T *ib_size);
    void GNSS_binary_expand_op_a5nemerfj(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const gnssops_navigation_data *in3, const real_T in5_data[], const int32_T *in5_size);
    void GNSSPreProcessingDualA_minus_ey(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2]);
    real_T GNSSPreProcessing_rt_powd_snf_m(real_T u0, real_T u1, B_CalculateDifferentialCorr_m_T *localB);
    void GNSSP_binary_expand_op_a5nemerf(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPr_binary_expand_op_a5nemer(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateDifferentialCorr_m_T *localB);
    boolean_T GNSSPreProcessingDualAnte_any_m(const boolean_T x_data[], const int32_T x_size[2],
        B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProc_binary_expand_op_a5(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProcessingDualAn_minus_e(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPre_binary_expand_op_a5neme(real_T in1_data[], int32_T in1_size[2], const gnssops_navigation_data *in2,
        const real_T in4_data[], const int32_T *in4_size, const real_T in5_data[], const int32_T in5_size[2], const
        real_T in6_data[], const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2],
        B_CalculateDifferentialCorr_m_T *localB);
    void correct_Gps_Time_At_Week_Cros_l(real_T b_time_data[], int32_T b_time_size[2]);
    void GNSSPreProcessingDualAnt_plus_l(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProc_binary_expand_op_pn(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPrePro_binary_expand_op_lco(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void Get_Kepler_Eccentric_Anomaly_f(const real_T t_k_data[], const int32_T t_k_size[2], const real_T
        Ephemeris_DELTA_N_data[], const int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[], const
        int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_E_data[], const int32_T Ephemeris_E_size[2], const real_T
        Ephemeris_SQRT_A_data[], const int32_T Ephemeris_SQRT_A_size[2], real_T E_k_data[], int32_T E_k_size[2], real_T
        E_k_Dot_data[], int32_T E_k_Dot_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProcessingDualAnte_cos_e(real_T x_data[], const int32_T x_size[2]);
    void GNSSPreProcessingDualAnte_sin_m(real_T x_data[], const int32_T x_size[2]);
    void GNSSPreProcessingDualA_times_jg(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2]);
    void GNSSPreProcessingDualAnt_sqrt_p(real_T x_data[], const int32_T x_size[2], B_CalculateDifferentialCorr_m_T
        *localB);
    real_T GNSSPreProcess_rt_atan2d_snf_pm(real_T u0, real_T u1, B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProcessin_expand_atan2_p(const real_T a_data[], const int32_T a_size[2], const real_T b_data[], const
        int32_T b_size[2], real_T c_data[], int32_T c_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProcessingDualAn_atan2_i(const real_T y_data[], const int32_T y_size[2], const real_T x_data[], const
        int32_T x_size[2], real_T r_data[], int32_T r_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNS_binary_expand_op_a5nemerfj5(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProc_binary_expand_op_m4(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProc_binary_expand_op_pc(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProc_binary_expand_op_n4(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProc_binary_expand_op_en(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
        in8_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPrePro_binary_expand_op_lrv(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProcessingDual_times_jgg(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProc_binary_expand_op_lr(real_T in1_data[], const real_T in2_data[], const int32_T in2_size[2], const
        real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const real_T
        in5_data[], const int32_T in5_size[2]);
    void GNSSPreProc_binary_expand_op_ow(real_T in1_data[], const int32_T in1_size[2], const real_T in2_data[], const
        int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
    void GNSSPreProc_binary_expand_op_a4(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProc_binary_expand_op_kh(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2]);
    void GNSSPreProc_binary_expand_op_pj(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
        in8_size[2], const real_T in9_data[], const int32_T in9_size[2], const real_T in10_data[], const int32_T
        in10_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProc_binary_expand_op_lc(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProc_binary_expand_op_jt(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void binary_expand_o_a5nemerfj5uawqf(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreProcessingDualAn_times_j(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void binary_expand_op_a5nemerfj5uawq(real_T in1_data[], const real_T in2_data[], const int32_T in2_size[2], const
        real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const real_T
        in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T in6_size[2], const real_T
        in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T in8_size[2], const real_T
        in9_data[], const int32_T in9_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void binary_expand_op_a5nemerfj5uaw(real_T in1_data[], const int32_T in1_size[2], const real_T in2_data[], const
        int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2], const real_T in6_data[], const int32_T
        in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const real_T in8_data[], const int32_T
        in8_size[2], const real_T in9_data[], const int32_T in9_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void G_binary_expand_op_a5nemerfj5ua(real_T in1_data[], const int32_T in1_size[2], const real_T in2_data[], const
        int32_T in2_size[2], const real_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T
        in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
    void GNSSPreProcessingDualAn_sqrt_pb(real_T x_data[], const int32_T *x_size, B_CalculateDifferentialCorr_m_T *localB);
    void Get_Kepler_Satellite_Position_h(const real_T Ephemeris_C_rs_data[], const int32_T Ephemeris_C_rs_size[2], const
        real_T Ephemeris_DELTA_N_data[], const int32_T Ephemeris_DELTA_N_size[2], const real_T Ephemeris_M_0_data[],
        const int32_T Ephemeris_M_0_size[2], const real_T Ephemeris_C_uc_data[], const int32_T Ephemeris_C_uc_size[2],
        const real_T Ephemeris_E_data[], const int32_T Ephemeris_E_size[2], const real_T Ephemeris_C_us_data[], const
        int32_T Ephemeris_C_us_size[2], const real_T Ephemeris_SQRT_A_data[], const int32_T Ephemeris_SQRT_A_size[2],
        const real_T Ephemeris_T_oe_data[], const int32_T Ephemeris_T_oe_size[2], const real_T Ephemeris_C_ic_data[],
        const int32_T Ephemeris_C_ic_size[2], const real_T Ephemeris_OMEGA_0_data[], const int32_T
        Ephemeris_OMEGA_0_size[2], const real_T Ephemeris_C_is_data[], const int32_T Ephemeris_C_is_size[2], const
        real_T Ephemeris_I_0_data[], const int32_T Ephemeris_I_0_size[2], const real_T Ephemeris_C_rc_data[], const
        int32_T Ephemeris_C_rc_size[2], const real_T Ephemeris_omega_data[], const int32_T Ephemeris_omega_size[2],
        const real_T Ephemeris_OMEGADOT_data[], const int32_T Ephemeris_OMEGADOT_size[2], const real_T
        Ephemeris_IDOT_data[], const int32_T Ephemeris_IDOT_size[2], const real_T T_emission_data[], const int32_T
        T_emission_size[2], const real_T user_position[3], real_T sv_pos_data[], int32_T sv_pos_size[2], real_T
        sv_vel_data[], int32_T sv_vel_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPreP_binary_expand_op_a5nem(const gnssops_navigation_data *in1, const real_T in3_data[], const int32_T
        *in3_size, const real_T in4_data[], const int32_T in4_size[2], const real_T in5_data[], const int32_T in5_size[2],
        const real_T in6_data[], const int32_T in6_size[2], const real_T in7_data[], const int32_T in7_size[2], const
        real_T in8_data[], const int32_T in8_size[2], const real_T in9_data[], const int32_T in9_size[2], const real_T
        in10_data[], const int32_T in10_size[2], const real_T in11[3], real_T in12_data[], int32_T in12_size[2], real_T
        in13_data[], int32_T in13_size[2], B_CalculateDifferentialCorr_m_T *localB);
    void GNSSPrePr_binary_expand_op_a5ne(real_T in1_data[], int32_T *in1_size, const real_T in2_data[], const int32_T
        in3_data[], const int32_T *in3_size, const real_T in4_data[], const int32_T *in4_size);
    void GNSSPrePro_binary_expand_op_a5n(real_T in1_data[], int32_T *in1_size, const real_T in2_data[], const int32_T
        in2_size[2], B_CalculateDifferentialCorr_m_T *localB);

    // private member function(s) for subsystem '<S76>/Calculate Tropospheric Corrections'
    void CalculateTroposphericCorrecti_h(real_T rtu_dayOfYear, boolean_T rtu_enableTroposphericCorrectio, const real_T
        rtu_userPos_LLH[3], const real_T rtu_elevationAngle[40], const int32_T *rtu_elevationAngle_DIMS1,
        B_CalculateTroposphericCorr_k_T *localB, DW_CalculateTroposphericCor_o_T *localDW);
    real_T GNSSPreProcessingDual_interp1_c(const real_T varargin_1[5], const real_T varargin_2[5], real_T varargin_3,
        B_CalculateTroposphericCorr_k_T *localB);
    real_T GNSSPreProcessin_rt_powd_snf_ba(real_T u0, real_T u1, B_CalculateTroposphericCorr_k_T *localB);
    void GNSSPreProcessin_expand_power_f(const real_T a_data[], const int32_T *a_size, const real_T b_data[], const
        int32_T *b_size, real_T c_data[], int32_T *c_size, B_CalculateTroposphericCorr_k_T *localB);
    void GNSSPreProc_binary_expand_op_ob(real_T in1_data[], int32_T *in1_size, const real_T in2[40], int32_T in3, const
        real_T in4_data[], const int32_T *in4_size, const real_T in5_data[], const int32_T *in5_size, const real_T
        in6_data[], const int32_T *in6_size, const real_T in7_data[], const int32_T *in7_size, const real_T in8_data[],
        const int32_T *in8_size, const real_T in9_data[], const int32_T *in9_size, const real_T in10[40], const int32_T *
        in11, const real_T in12_data[], const int32_T *in12_size, B_CalculateTroposphericCorr_k_T *localB);

    // private member function(s) for subsystem '<S117>/Apply Differential Correction Mask1'
    void ApplyDifferentialCorrectionMa_b(const GNSS_Measurement *rtu_GpsMeasurementBus, const GNSS_Measurement_size
        *rtu_GpsMeasurementBus_DIMS1, const real_T rtu_diffPseudorangeCorrections[40], const uint16_T
        rtu_diffCorrAvailableSvid[40], const int32_T *rtu_diffCorrAvailableSvidS1_DIM, boolean_T
        rtu_enableDiffCorrection, const real_T rtu_rtcm_base_position[3], boolean_T *rty_MeasurementCorrected,
        B_ApplyDifferentialCorrecti_g_T *localB, DW_ApplyDifferentialCorrect_n_T *localDW);
    void GNSSPreProcessingD_do_vectors_c(const uint16_T a_data[], const int32_T *a_size, const uint16_T b_data[], const
        int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
        int32_T *ib_size);
    void GNSSPrePro_binary_expand_op_pxm(real_T in1_data[], int32_T *in1_size, const GNSS_Measurement *in2, const
        int32_T in4_data[], const int32_T *in4_size, const real_T in5[40], const int32_T in7_data[], const int32_T
        *in7_size);
    void GNSSPreProc_binary_expand_op_px(real_T in1_data[], int32_T *in1_size, const GNSS_Measurement *in2, const
        int32_T in4_data[], const int32_T *in4_size, const real_T in5[40], const int32_T in7_data[], const int32_T
        *in7_size);

    // private member function(s) for subsystem '<S18>/Simplify and Mask GAL Measurement Bus'
    void SimplifyandMaskGALMeasurementBu(const gnssraw_measurement_t *rtu_GAL_Measurement_Bus, const
        gnssops_navigation_data *rtu_GAL_NavigationData_Bus, const gnssops_navigation_data_size
        *rtu_GAL_NavigationData_Bu_DIMS1, const parameters_galileo_t *rtu_parameters_galileo,
        B_SimplifyandMaskGALMeasureme_T *localB, DW_SimplifyandMaskGALMeasurem_T *localDW);
    void GNSSPreProcessingDualAnt_any_jj(const boolean_T x[200], boolean_T y[40]);
    void GNSSPreProcessingDua_eml_find_h(const boolean_T x[5], int32_T i_data[], int32_T i_size[2]);
    void GNSSPreProcessingDualAn_merge_p(int32_T idx_data[], uint16_T x_data[], int32_T offset, int32_T np, int32_T nq,
        int32_T iwork_data[], uint16_T xwork_data[]);
    void GNSSPreProcessingDualAnt_sort_b(uint16_T x_data[], int32_T x_size[2], int32_T idx_data[], int32_T idx_size[2],
        B_SimplifyandMaskGALMeasureme_T *localB);
    boolean_T GNSSPreProcessingDualAn_any_jjs(const boolean_T x_data[], const int32_T *x_size);
    void GNSSPrePro_binary_expand_op_brs(real_T in1_data[], int32_T in1_size[2], const gnssraw_measurement_t *in2, const
        int8_T in3_data[], const int32_T in3_size[2], const real_T in4_data[], const int32_T in4_size[2], const int32_T
        in5_data[], const int8_T in6_data[], const int32_T in6_size[2], B_SimplifyandMaskGALMeasureme_T *localB);
    void GNSSPreProcessingDualA_any_jjst(const boolean_T x_data[], const int32_T x_size[2], boolean_T y_data[], int32_T
        y_size[2]);
    void emxConvertDynamicMatrixToEmx__f(emxArray_real_T_37_GNSSPrePro_T *emx, const real_T data[37], const int32_T
        *size);
    void emxConvertStructToEmx_gnssops_i(emxArray__gnssops_navigation__T *emx, const gnssops_navigation_data *data,
        const gnssops_navigation_data_size *size);
    void GNSSPreProc_binary_expand_op_br(boolean_T in1_data[], int32_T *in1_size, const gnssops_navigation_data *in2,
        const gnssops_navigation_data_size *in3, const uint16_T in4[40], int32_T in6);
    void GNSSPr_select_navigation_data_c(const emxArray__gnssops_navigation__T *navigation_data, const boolean_T
        mask_data[], const int32_T *mask_size, b_gnssops_navigation_data_GNS_T *navigation_data_selected,
        B_SimplifyandMaskGALMeasureme_T *localB);

    // private member function(s) for subsystem '<S5>/Galileo'
    static void GNSSPreProcessingD_Galileo_Init(B_Galileo_GNSSPreProcessingDu_T *localB, DW_Galileo_GNSSPreProcessingD_T
        *localDW, P_Galileo_GNSSPreProcessingDu_T *localP);
    void GNSSPreProcessingDualAn_Galileo(const gnssraw_measurement_t *rtu_GAL_Measurement_Bus, const real_T
        rtu_GAL_NAV_Bus[36], const uint16_T rtu_GAL_NAV_Bus_b[36], const uint8_T rtu_GAL_NAV_Bus_o[36], const real_T
        rtu_GAL_NAV_Bus_f[36], const real_T rtu_GAL_NAV_Bus_n[36], const real_T rtu_GAL_NAV_Bus_og[36], const real_T
        rtu_GAL_NAV_Bus_g[36], const real_T rtu_GAL_NAV_Bus_p[36], const real_T rtu_GAL_NAV_Bus_k[36], const real_T
        rtu_GAL_NAV_Bus_h[36], const real_T rtu_GAL_NAV_Bus_d[36], const real_T rtu_GAL_NAV_Bus_j[36], const real_T
        rtu_GAL_NAV_Bus_fc[36], const real_T rtu_GAL_NAV_Bus_fc3[36], const real_T rtu_GAL_NAV_Bus_bz[36], const real_T
        rtu_GAL_NAV_Bus_m[36], const real_T rtu_GAL_NAV_Bus_ob[36], const real_T rtu_GAL_NAV_Bus_fe[36], const uint32_T
        rtu_GAL_NAV_Bus_i[36], const uint32_T rtu_GAL_NAV_Bus_pj[36], const real_T rtu_GAL_NAV_Bus_fr[36], const real_T
        rtu_GAL_NAV_Bus_gm[36], const real_T rtu_GAL_NAV_Bus_il[36], const uint16_T rtu_GAL_NAV_Bus_l[36], const
        uint16_T rtu_GAL_NAV_Bus_nk[36], const uint16_T rtu_GAL_NAV_Bus_a[36], const real_T rtu_userPos_LLH[3], real_T
        rtu_dayOfYear, boolean_T rtu_parameters_gnss_Bus, boolean_T rtu_parameters_gnss_Bus_b, boolean_T
        rtu_parameters_gnss_Bus_k, boolean_T rtu_parameters_gnss_Bus_e, boolean_T rtu_parameters_gnss_Bus_b0, boolean_T
        rtu_parameters_gnss_Bus_d, boolean_T rtu_parameters_gnss_Bus_i, boolean_T rtu_parameters_gnss_Bus_c, boolean_T
        rtu_parameters_gnss_Bus_h, boolean_T rtu_parameters_gnss_Bus_l, real_T rtu_parameters_gnss_Bus_bi, const
        GNSS_Measurement *rtu_GalMeasurementB, const GNSS_Measurement_size *rtu_GalMeasurementB_DIMS1,
        B_Galileo_GNSSPreProcessingDu_T *localB, DW_Galileo_GNSSPreProcessingD_T *localDW,
        P_Galileo_GNSSPreProcessingDu_T *localP);
    void GNSSPreProcessingD_do_vectors_h(const uint16_T a_data[], const int32_T *a_size, const uint16_T b_data[], const
        int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
        int32_T *ib_size, B_Galileo_GNSSPreProcessingDu_T *localB);
    boolean_T GNSSPreProcessingDualAnte_any_p(const real_T x_data[], const int32_T *x_size,
        B_Galileo_GNSSPreProcessingDu_T *localB);
    void GNSSPreProce_calcCorrection_n5t(const real_T prf1_data[], const uint16_T PRN1_data[], const int32_T *PRN1_size,
        const real_T prf2_data[], const uint16_T PRN2_data[], const int32_T *PRN2_size, real_T Corr_f1_data[], int32_T
        *Corr_f1_size, B_Galileo_GNSSPreProcessingDu_T *localB);
    void GNSSPreProcessingDualAnte_any_c(const boolean_T x_data[], const int32_T x_size[2], boolean_T y_data[], int32_T *
        y_size);
    void GNSSPreProcessin_calcCorrection(const real_T prf1_data[], const uint16_T PRN1_data[], const int32_T *PRN1_size,
        const real_T prf2_data[], const uint16_T PRN2_data[], const int32_T *PRN2_size, real_T Corr_f1_data[], int32_T
        *Corr_f1_size, B_Galileo_GNSSPreProcessingDu_T *localB);
    boolean_T GNSSPreProcessingDualAnt_any_pw(const boolean_T x_data[], const int32_T *x_size);
    void GNSSPreProcess_calcCorrection_n(const real_T prf1_data[], const uint16_T PRN1_data[], const int32_T *PRN1_size,
        const real_T prf2_data[], const uint16_T PRN2_data[], const int32_T *PRN2_size, real_T Corr_f1_data[], int32_T
        *Corr_f1_size, B_Galileo_GNSSPreProcessingDu_T *localB);
    void GNSSPreProces_calcCorrection_n5(const real_T prf1_data[], const uint16_T PRN1_data[], const int32_T *PRN1_size,
        const real_T prf2_data[], const uint16_T PRN2_data[], const int32_T *PRN2_size, real_T Corr_f1_data[], int32_T
        *Corr_f1_size, B_Galileo_GNSSPreProcessingDu_T *localB);
    void GNSSPreProcessingDualAnt_any_cf(const boolean_T x_data[], const int32_T *x_size, boolean_T y_data[], int32_T
        *y_size, B_Galileo_GNSSPreProcessingDu_T *localB);
    void GNSSPreProc_binary_expand_op_oq(boolean_T in1_data[], int32_T *in1_size, const boolean_T in2[40], int32_T in3,
        const real_T in4[120], const GNSS_Measurement_size *in5, const real_T in6[120], const real_T in7[40], int32_T
        in8, B_Galileo_GNSSPreProcessingDu_T *localB);

    // private member function(s) for subsystem '<S19>/CalcDOP'
    static void GNSSPreProcessingDualAn_CalcDOP(const real_T rtu_user_position[3], const GNSS_Measurement
        *rtu_gnssIn_measurement, const GNSS_Measurement_size *rtu_gnssIn_measurement_DIMS1, real_T *rty_HDOP, real_T
        *rty_VDOP, B_CalcDOP_GNSSPreProcessingDu_T *localB, DW_CalcDOP_GNSSPreProcessingD_T *localDW);

    // private member function(s) for subsystem '<S123>/MATLAB Function'
    static void GNSSPreProc_MATLABFunction_Init(real_T *rty_1, real_T *rty_2, real_T *rty_3, real_T rty_4[80], real_T
        rty_5[80], real_T rty_6[80], B_MATLABFunction_GNSSPreProce_T *localB, DW_MATLABFunction_GNSSPreProc_T *localDW,
        P_MATLABFunction_GNSSPreProce_T *localP);
    void GNSSPreProcessin_MATLABFunction(const parameters_integrity_t *rtu_IntegrityParameters, const GNSS_Measurement
        *rtu_1, const GNSS_Measurement_size *rtu_1_DIMS1, boolean_T rtu_3, boolean_T rtu_4, boolean_T rtu_6, boolean_T
        rtu_7, boolean_T rtu_8, boolean_T rtu_9, real_T rtu_28, real_T rtu_31, real_T rtu_33, real_T rtu_35, real_T
        rtu_36, real_T rtu_37, boolean_T rtu_38, const real_T rtu_39[3], real_T rtu_40, boolean_T
        *rty_useOriginalGNSSmeasurement, real_T *rty_1, real_T *rty_2, real_T *rty_3, real_T rty_4[80], real_T rty_5[80],
        real_T rty_6[80], B_MATLABFunction_GNSSPreProce_T *localB, DW_MATLABFunction_GNSSPreProc_T *localDW,
        P_GNSSPreProcessingDualAntenn_T *GNSSPreProcessingDualAntenna_P);
    void GNSSPre_binary_expand_op_fznsyj(real_T in1[3], const real_T in2_data[], const int32_T in2_size[2]);
    void calculate_Satellite_Elevation_j(const real_T user_Position_llh[3], const real_T satellite_Position_ecef_data[],
        const int32_T satellite_Position_ecef_size[2], real_T *elevation_Angle, real_T *azimuth_Angle,
        B_MATLABFunction_GNSSPreProce_T *localB);
    void GNSSPrePro_binary_expand_op_fzn(real_T in1[3], real_T in2, real_T in3, const int8_T in4[3], real_T in5, real_T
        in6, const int8_T in7[3], const real_T in8[4], const real_T in9_data[], const int32_T in9_size[2], int32_T in10,
        const int32_T in11_size[2], B_MATLABFunction_GNSSPreProce_T *localB);
    void GNSSPreProcessingDualAntenn_inv(const real_T x_data[], const int32_T x_size[2], real_T y_data[], int32_T
        y_size[2], B_MATLABFunction_GNSSPreProce_T *localB);
    void GNSSPrePr_binary_expand_op_fzns(real_T in1[3], const real_T in2[4], const real_T in3_data[], const int32_T
        in3_size[2], int32_T in4, const int32_T in5_size[2]);
    void GNSSPreProcessingDua_mldivide_a(const real_T A[16], const real_T B_data[], const int32_T B_size[2], real_T
        Y_data[], int32_T Y_size[2], B_MATLABFunction_GNSSPreProce_T *localB);
    void GNSSPreProcessingDualAn_minus_n(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[], const int32_T
        in2_size[2], B_MATLABFunction_GNSSPreProce_T *localB);
    void GNSSPreProcessingDualAnt_mtimes(const real_T A_data[], const int32_T A_size[2], const real_T B_data[], real_T
        C_data[], int32_T *C_size, B_MATLABFunction_GNSSPreProce_T *localB);
    real_T GNSSPreProcessingDualAn_maximum(const real_T x_data[], const int32_T *x_size);
    void GNSSPreProces_RAIM_detect_Fault(const real_T e_GNSS_Measurement_satellite_po[], const int32_T
        e_GNSS_Measurement_satellite__0[2], const real_T e_GNSS_Measurement_pseudorange_[], const int32_T
        *e_GNSS_Measurement_pseudorang_0, const real_T e_GNSS_Measurement_variance_pse[], const real_T
        user_position_llh[3], real_T clockerror, const real_T b_table_chi_square[80], real_T m, real_T *test_statistic,
        real_T *threshold, real_T *HPL, real_T H_data[], int32_T H_size[2], real_T W_data[], int32_T W_size[2], real_T
        y_data[], int32_T *y_size, B_MATLABFunction_GNSSPreProce_T *localB);
    void GNSSPreProcessingDualAnt_sqrt_a(real_T x_data[], const int32_T x_size[2]);
    void GNSSPreProcessingDualA_mtimes_c(const real_T A_data[], const int32_T A_size[2], const real_T B_data[], const
        int32_T B_size[2], real_T C_data[], int32_T C_size[2]);
    boolean_T GNSSPreProcessingDualAnte_any_a(const boolean_T x[40]);
    real_T GNSSPreProcessingDualAn_xnrm2_l(int32_T n, const real_T x_data[], int32_T ix0,
        B_MATLABFunction_GNSSPreProce_T *localB);
    void GNSSPreProcessingDualAnte_xgemv(int32_T m, int32_T n, const real_T A_data[], int32_T ia0, int32_T lda, const
        real_T x_data[], int32_T ix0, real_T y_data[]);
    void GNSSPreProcessingDualAnte_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const real_T y_data[], real_T
        A_data[], int32_T ia0, int32_T lda);
    void GNSSPreProcessingDualAnt_xgeqrf(real_T A_data[], const int32_T A_size[2], real_T tau_data[], int32_T *tau_size,
        B_MATLABFunction_GNSSPreProce_T *localB);
    real_T GNSSPreProcessingDualA_xnrm2_lz(int32_T n, const real_T x_data[], int32_T ix0,
        B_MATLABFunction_GNSSPreProce_T *localB);
    void GNSSPreProcessingDualAn_xgemv_a(int32_T m, int32_T n, const real_T A_data[], int32_T ia0, int32_T lda, const
        real_T x_data[], int32_T ix0, real_T y[4]);
    void GNSSPreProcessingDualAn_xgerc_p(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const real_T y[4], real_T
        A_data[], int32_T ia0, int32_T lda);
    void GNSSPreProcessingDualA_xgeqrf_d(real_T A_data[], const int32_T A_size[2], real_T tau_data[], int32_T *tau_size,
        B_MATLABFunction_GNSSPreProce_T *localB);
    void GNSSPreProcessingDualAntenna_qr(const real_T A_data[], const int32_T A_size[2], real_T Q_data[], int32_T
        Q_size[2], real_T R_data[], int32_T R_size[2], B_MATLABFunction_GNSSPreProce_T *localB);
    void GNSSPreProcessingDua_eml_find_j(const boolean_T x[40], int32_T i_data[], int32_T i_size[2]);
    void GNSSPreProcessingDu_eml_find_jk(const boolean_T x_data[], const int32_T x_size[2], int32_T i_data[], int32_T
        i_size[2]);
    void GNSSPreProcessingDualAn_merge_b(int32_T idx_data[], real_T x_data[], int32_T offset, int32_T np, int32_T nq,
        int32_T iwork_data[], real_T xwork_data[]);
    void GNSSPreProcessingDualAnt_sort_k(real_T x_data[], int32_T x_size[2], int32_T idx_data[], int32_T idx_size[2],
        B_MATLABFunction_GNSSPreProce_T *localB);
    real_T GNSSPreProcessingDualAntenn_sum(const real_T x_data[], const int32_T x_size[2]);
    void GNSSPreProcessing_eml_find_jkdy(const real_T x_data[], const int32_T x_size[2], int32_T i_data[], int32_T
        i_size[2]);
    real_T GNSSPreProcessingDualAnt_norm_k(const real_T x_data[], const int32_T *x_size);
    void GNSSPreProcessingD_eml_find_jkd(const boolean_T x_data[], const int32_T *x_size, int32_T i_data[], int32_T
        *i_size);
    void GNSSPreProcessingDualAnt_sort_f(real_T x_data[], int32_T x_size[2], int32_T idx_data[], int32_T idx_size[2],
        B_MATLABFunction_GNSSPreProce_T *localB);
    void GNSSPreProcessin_nullAssignment(real_T x_data[], int32_T x_size[2], const int32_T idx_data[], const int32_T
        idx_size[2]);
    void GNSSPreProc_binary_expand_op_fz(real_T in1_data[], const int32_T in1_size[2], int32_T in2, const real_T
        in3_data[], const int32_T *in3_size, real_T in4, const real_T in5_data[], const int32_T in5_size[2]);

    // private member function(s) for subsystem '<S123>/switch GNSS Measurements'
    static void GNSSPreP_switchGNSSMeasurements(boolean_T rtu_useOriginalGNSSmeasurement, const GNSS_Measurement
        *rtu_GNSS_Measurement_orig, const GNSS_Measurement_size *rtu_GNSS_Measurement_orig_DIMS1, const GNSS_Measurement
        *rtu_GNSS_Measurement_FDE, const GNSS_Measurement_size *rtu_GNSS_Measurement_FDE_DIMS1,
        B_switchGNSSMeasurements_GNSS_T *localB, DW_switchGNSSMeasurements_GNS_T *localDW);

    // private member function(s) for subsystem '<S5>/MATLAB Function'
    static void GNSSPreProcess_MATLABFunction_d(const GNSS_Measurement *rtu_GnssMeasurementB, const
        GNSS_Measurement_size *rtu_GnssMeasurementB_DIMS1, B_MATLABFunction_GNSSPrePro_a_T *localB,
        DW_MATLABFunction_GNSSPrePr_l_T *localDW);

    // private member function(s) for subsystem '<S5>/Merge GNSS Measurement'
    static void GNSSP_MergeGNSSMeasurement_Init(DW_MergeGNSSMeasurement_GNSSP_T *localDW);
    void GNSSPrePro_MergeGNSSMeasurement(const GNSS_Measurement *rtu_GpsMeasurementBus, const GNSS_Measurement_size
        *rtu_GpsMeasurementBus_DIMS1, const GNSS_Measurement *rtu_GalMeasurementBus, const GNSS_Measurement_size
        *rtu_GalMeasurementBus_DIMS1, const GNSS_Measurement *rtu_GateMeasurementBus, const GNSS_Measurement_size
        *rtu_GateMeasurementBus_DIMS1, const gnssraw_ggto_t *rtu_GalGstGpsBus, real_T rtu_timeOfWeek, real_T
        rtu_weekNumberCounter, const parameters_gnss_t *rtu_ParametersGnssBus, real_T rtu_enableGGTO, boolean_T
        rtu_enableMerge, real_T *rty_deltaSystemTimesGnss, boolean_T *rty_isValidGgto, B_MergeGNSSMeasurement_GNSSPr_T
        *localB, DW_MergeGNSSMeasurement_GNSSP_T *localDW);
    real_T GNSSPreProces_GGTO_delta_T_GNSS(real_T GalGstGps_Bus_A_1G, real_T GalGstGps_Bus_A_0G, uint32_T
        GalGstGps_Bus_t_oG, uint8_T GalGstGps_Bus_WN_oG, real_T GSTTOW, real_T GSTWNc);
    void emxConvertDynamicMatrixToEmx_40(emxArray_real_T_40x3_GNSSPreP_T *emx, const real_T data[120], const int32_T
        size[2]);
    void emxConvertDynamicMatrixToEmx__e(emxArray_uint16_T_40_GNSSPreP_T *emx, const uint16_T data[40], const int32_T
        *size);
    void emxConvertDynamicMatrixToEmx_eu(emxArray_real_T_40_GNSSPrePro_T *emx, const real_T data[40], const int32_T
        *size);
    void emxConvertDynamicMatrixToEm_eu1(emxArray_real32_T_40_GNSSPreP_T *emx, const real32_T data[40], const int32_T
        *size);
    void emxConvertStructToEmx_GNSS_Meas(emxArray__GNSS_Measurement_GN_T *emx, const GNSS_Measurement *data, const
        GNSS_Measurement_size *size);
    void GNSSPreProcessingD_mergeMyBus_a(const emxArray__GNSS_Measurement_GN_T *varargin_1, const
        emxArray__GNSS_Measurement_GN_T *varargin_2, s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T *outputBus);
    void GNSSPreProcessingDualA_isMember(const uint16_T a_data[], const int32_T *a_size, boolean_T tf_data[], int32_T
        *tf_size);
    boolean_T GNSSPreProcessingDualAnt_any_m3(const boolean_T x_data[], const int32_T *x_size);
    void GNSSPreProcessingDua_isMember_c(const uint16_T a_data[], const int32_T *a_size, boolean_T tf_data[], int32_T
        *tf_size);
    real_T GNSSPreProcessingDualAnt_norm_f(const real_T x[3], B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPr_binary_expand_op_fmdkkr1(real_T in1_data[], int32_T in2, const real_T in3_data[], const real_T in4_data[],
        const int32_T in4_size[2], const real_T in5[4], B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPre_binary_expand_op_fmdkkr(real_T in1_data[], const int32_T in1_size[2], int32_T in2, const real_T
        in3_data[], const int32_T in3_size[2], const real_T in4[4], B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPreProcessingDu_getJacobi_f(const real_T satellite_position_data[], const int32_T satellite_position_size[2],
        const real_T pseudorange_data[], const int32_T *pseudorange_size, const real_T user_state[4], real_T
        delta_rho_data[], int32_T *delta_rho_size, real_T H_data[], int32_T H_size[2], real_T residuum[4],
        B_MergeGNSSMeasurement_GNSSPr_T *localB);
    real_T GNSSPreProcessingDualA_xnrm2_iw(int32_T n, const real_T x_data[], int32_T ix0,
        B_MergeGNSSMeasurement_GNSSPr_T *localB);
    real_T GNSSPreProcessi_rt_hypotd_snf_p(real_T u0, real_T u1, B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPreProcessingDua_qrsolve_ea(const real_T A_data[], const int32_T A_size[2], const real_T B_data[], const
        int32_T *B_size, real_T Y[4], B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPreProcessing_mldivide_gi2s(const real_T A_data[], const int32_T A_size[2], real_T B_data[], int32_T
        *B_size, B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPreProcessingDualAn_plus_nj(real_T in1[4], const real_T in2_data[], const int32_T *in2_size);
    void GNSSPrePro_binary_expand_op_fmd(real_T in1_data[], int32_T in2, const real_T in3_data[], const real_T in4_data[],
        const int32_T in4_size[2], const real_T in5[5], B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPreProc_binary_expand_op_fm(real_T in1_data[], const int32_T in1_size[2], int32_T in2, const real_T
        in3_data[], const int32_T in3_size[2], const real_T in4[5], B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPreP_binary_expand_op_fmdkk(real_T in1_data[], int32_T in2, const real_T in3_data[], const real_T in4_data[],
        const int32_T in4_size[2], const real_T in5[5], B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPrePr_binary_expand_op_fmdk(real_T in1_data[], const int32_T in1_size[2], int32_T in2, const real_T
        in3_data[], const int32_T in3_size[2], const real_T in4[5], B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPreProc_getJacobiMultiKonst(const real_T satellite_position_sys1_data[], const int32_T
        satellite_position_sys1_size[2], const real_T satellite_position_sys2_data[], const int32_T
        satellite_position_sys2_size[2], const real_T pseudorange_sys1_data[], const int32_T *pseudorange_sys1_size,
        const real_T pseudorange_sys2_data[], const int32_T *pseudorange_sys2_size, const real_T user_state[5], real_T
        delta_rho_data[], int32_T *delta_rho_size, real_T H_data[], int32_T H_size[2], real_T residuum[5],
        B_MergeGNSSMeasurement_GNSSPr_T *localB);
    real_T GNSSPreProcessingDualAn_xnrm2_i(int32_T n, const real_T x_data[], int32_T ix0,
        B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPreProcessingDual_qrsolve_e(const real_T A_data[], const int32_T A_size[2], const real_T B_data[], const
        int32_T *B_size, real_T Y[5], B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPreProcessingD_mldivide_gi2(const real_T A_data[], const int32_T A_size[2], real_T B_data[], int32_T
        *B_size, B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPreProcessingDualAnt_plus_n(real_T in1[5], const real_T in2_data[], const int32_T *in2_size);
    real_T GNSSPr_calc_delta_T_GNSS_system(const real_T gnss_measurement_satellite_posi[], const int32_T
        gnss_measurement_satellite_po_0[2], const uint16_T gnss_measurement_PRN_data[], const int32_T
        *gnss_measurement_PRN_size, const real_T gnss_measurement_pseudorange_da[], const int32_T
        *gnss_measurement_pseudorange_si, B_MergeGNSSMeasurement_GNSSPr_T *localB, DW_MergeGNSSMeasurement_GNSSP_T
        *localDW);
    void GNSSPreProcessingDua_mergeMyBus(const emxArray__GNSS_Measurement_GN_T *varargin_1, const
        emxArray__GNSS_Measurement_GN_T *varargin_2, const emxArray__GNSS_Measurement_GN_T *varargin_3,
        s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T *outputBus, B_MergeGNSSMeasurement_GNSSPr_T *localB);
    void GNSSPreProcessing_mergeMyBus_as(const s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T *varargin_1, const
        emxArray__GNSS_Measurement_GN_T *varargin_2, s_p3XDoG4hWh7L3rtSKHmAfC_GNSS_T *outputBus);

    // private member function(s) for subsystem '<S5>/Mode Switch'
    static void GNSSPreProcessi_ModeSwitch_Init(real_T *rty_state_double, parameters_gnss_t *rty_parameters_gnss_Bus,
        DW_ModeSwitch_GNSSPreProcessi_T *localDW, P_ModeSwitch_GNSSPreProcessin_T *localP);
    static void GNSSPreProcessingDua_ModeSwitch(real_T rtu_TOW, const uint16_T rtu_measurementEpoch_Bus_mb[40], const
        uint8_T rtu_measurementEpoch_Bus_f[200], boolean_T rtu_parameters_gnss_Bus_in, boolean_T
        rtu_parameters_gnss_Bus_in_j, boolean_T rtu_parameters_gnss_Bus_in_a, boolean_T rtu_parameters_gnss_Bus_in_l,
        boolean_T rtu_parameters_gnss_Bus_in_lq, boolean_T rtu_parameters_gnss_Bus_in_af, boolean_T
        rtu_parameters_gnss_Bus_in_ae, boolean_T rtu_parameters_gnss_Bus_in_e, boolean_T rtu_parameters_gnss_Bus_in_m,
        uint8_T rtu_parameters_gnss_Bus_in_lk, uint8_T rtu_parameters_gnss_Bus_in_ey, uint8_T
        rtu_parameters_gnss_Bus_in_ef, uint8_T rtu_parameters_gnss_Bus_in_k, uint8_T rtu_parameters_gnss_Bus_in_kh,
        uint8_T rtu_parameters_gnss_Bus_in_lf, uint8_T rtu_parameters_gnss_Bus_in_le, uint8_T
        rtu_parameters_gnss_Bus_in_n, uint8_T rtu_parameters_gnss_Bus_in_o, real_T rtu_parameters_gnss_Bus_in_i,
        boolean_T rtu_parameters_gnss_Bus_in_p, boolean_T rtu_parameters_gnss_Bus_in_no, boolean_T
        rtu_parameters_gnss_Bus_in_jl, boolean_T rtu_parameters_gnss_Bus_in_lu, boolean_T rtu_parameters_gnss_Bus_in_d,
        boolean_T rtu_parameters_gnss_Bus_in_ml, boolean_T rtu_parameters_gnss_Bus_in_b, real_T *rty_state_double,
        parameters_gnss_t *rty_parameters_gnss_Bus, B_ModeSwitch_GNSSPreProcessin_T *localB,
        DW_ModeSwitch_GNSSPreProcessi_T *localDW, P_ModeSwitch_GNSSPreProcessin_T *localP);

    // private member function(s) for subsystem '<S5>/mergeDiffCorrections'
    static void GNSSPrePro_mergeDiffCorrections(const real_T rtu_gpsDiff[40], const uint16_T rtu_gpsSat[40], const
        int32_T *rtu_gpsSat_DIMS1, const real_T rtu_galDiff[40], const uint16_T rtu_galSat[40], const int32_T
        *rtu_galSat_DIMS1, real_T rty_pseudorangeCorrections[40], uint16_T rty_SVIDCorrections[40]);

    // private member function(s) for subsystem '<Root>'
    void GNSSPreProcessingD_do_vectors_b(const uint16_T a_data[], const int32_T *a_size, const uint16_T b_data[], const
        int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
        int32_T *ib_size);
    void GNSSPreProcessingDual_maximum_c(const real_T x[100], real_T ex[2]);
    real_T GNSSPreProcessingDualAn_minimum(const real_T x[2]);
    void GNSSPreProcessingDual_minimum_m(const real_T x[100], real_T ex[2]);
    real_T GNSSPreProcessingDua_maximum_cc(const real_T x[2]);
    void GNSSPreProcessingDua_eml_find_p(const boolean_T x[50], int32_T i_data[], int32_T *i_size);
    void GNSSPreProcessing_do_vectors_cl(const uint16_T a[40], const uint16_T b[40], uint16_T c_data[], int32_T c_size[2],
        int32_T ia_data[], int32_T *ia_size, int32_T ib_data[], int32_T *ib_size);
    boolean_T GNSSPreProcessingDualAnte_any_n(const boolean_T x_data[], const int32_T x_size[2]);
    real_T GNSSPreProcessi_rt_atan2d_snf_m(real_T u0, real_T u1);
    void calculate_Satellite_Elevation_p(const real_T user_Position_llh[3], const real_T satellite_Position_ecef_data[],
        const int32_T satellite_Position_ecef_size[2], real_T elevation_Angle_data[], int32_T *elevation_Angle_size,
        real_T azimuth_Angle_data[], int32_T *azimuth_Angle_size);
    void GNSSPreProcessin_do_vectors_cly(const uint16_T a_data[], const int32_T a_size[2], const uint16_T b_data[],
        const int32_T *b_size, uint16_T c_data[], int32_T *c_size, int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
        int32_T *ib_size);
    void GNSSPreProcessingDu_maximum_ccd(const real_T x_data[], const int32_T *x_size, real_T *ex, int32_T *idx);
    void GNSSPr_binary_expand_op_msuy130(real_T in1_data[], int32_T in1_size[2], const sk7S3MUBNIp13xZwazKdzDD_GNSSP_T
        *in2, const int32_T in3_data[], const int32_T in4_data[], const int32_T *in4_size, int32_T in5, const
        sk7S3MUBNIp13xZwazKdzDD_GNSSP_T *in6, const int32_T in7_data[], const int32_T in8_data[], const int32_T
        *in8_size);
    void GNSSPre_binary_expand_op_msuy13(real_T in1_data[], int32_T in1_size[2], const sk7S3MUBNIp13xZwazKdzDD_GNSSP_T
        *in2, const int32_T in3_data[], const int32_T in4_data[], const int32_T *in4_size, int32_T in5, const
        sk7S3MUBNIp13xZwazKdzDD_GNSSP_T *in6, const int32_T in7_data[], const int32_T in8_data[], const int32_T
        *in8_size);
    void GNSSPreP_binary_expand_op_msuy1(real_T in1_data[], int32_T in1_size[2], const sk7S3MUBNIp13xZwazKdzDD_GNSSP_T
        *in2, const int32_T in3_data[], const int32_T in4_data[], const int32_T *in4_size, int32_T in5, const
        sk7S3MUBNIp13xZwazKdzDD_GNSSP_T *in6, const int32_T in7_data[], const int32_T in8_data[], const int32_T
        *in8_size);
    void GNSSPrePr_binary_expand_op_msuy(real_T in1_data[], int32_T in1_size[2], const sk7S3MUBNIp13xZwazKdzDD_GNSSP_T
        *in2, const int32_T in3_data[], int32_T in4, const sk7S3MUBNIp13xZwazKdzDD_GNSSP_T *in5, const int32_T in6_data[],
        int32_T in7, const int32_T in8_data[], const int32_T *in8_size, const int32_T in9_data[], const int32_T
        *in9_size);
    void GNSSPrePro_binary_expand_op_msu(real_T in1_data[], int32_T in1_size[2], const sk7S3MUBNIp13xZwazKdzDD_GNSSP_T
        *in2, const int32_T in3_data[], int32_T in4, const sk7S3MUBNIp13xZwazKdzDD_GNSSP_T *in5, const int32_T in6_data[],
        int32_T in7, const int32_T in8_data[], const int32_T *in8_size, const int32_T in9_data[], const int32_T
        *in9_size);
    void GNSSPreProc_binary_expand_op_ms(real_T in1_data[], int32_T in1_size[2], const sk7S3MUBNIp13xZwazKdzDD_GNSSP_T
        *in2, const int32_T in3_data[], int32_T in4, const sk7S3MUBNIp13xZwazKdzDD_GNSSP_T *in5, const int32_T in6_data[],
        int32_T in7, const int32_T in8_data[], const int32_T *in8_size, const int32_T in9_data[], const int32_T
        *in9_size);

    // Real-Time Model
    RT_MODEL_GNSSPreProcessingDua_T GNSSPreProcessingDualAntenna_M;
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
//  '<Root>' : 'GNSSPreProcessingDualAntenna'
//  '<S1>'   : 'GNSSPreProcessingDualAntenna/Calculate User Position with LMS'
//  '<S2>'   : 'GNSSPreProcessingDualAntenna/Calculate User Position with LMS1'
//  '<S3>'   : 'GNSSPreProcessingDualAntenna/CalculateDoubleDiffBlock'
//  '<S4>'   : 'GNSSPreProcessingDualAntenna/Convert RTCM3 MSM4 for L1 and E1 to GNSS Measurement Bus'
//  '<S5>'   : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna'
//  '<S6>'   : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1'
//  '<S7>'   : 'GNSSPreProcessingDualAntenna/Intersect'
//  '<S8>'   : 'GNSSPreProcessingDualAntenna/CalculateDoubleDiffBlock/ConvertGNSSMeasuremendVariableToFixed'
//  '<S9>'   : 'GNSSPreProcessingDualAntenna/CalculateDoubleDiffBlock/calculate double diff'
//  '<S10>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Calculate Day of Year'
//  '<S11>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/ConvertGNSSMeasuremendVariableToFixed_CalcAngles'
//  '<S12>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/ConvertGNSSMeasuremendVariableToFixed_CalcAngles1'
//  '<S13>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/ConvertGNSSMeasuremendVariableToFixed_CalcAngles2'
//  '<S14>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Dummy GNSS Measurement'
//  '<S15>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Fuse'
//  '<S16>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GNSS Measurement Epoch Splitter'
//  '<S17>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS'
//  '<S18>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo'
//  '<S19>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS'
//  '<S20>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/MATLAB Function'
//  '<S21>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Merge GNSS Measurement'
//  '<S22>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Mode Switch'
//  '<S23>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/mergeDiffCorrections'
//  '<S24>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream'
//  '<S25>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream'
//  '<S26>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream'
//  '<S27>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS Parameter Logic'
//  '<S28>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Navigation Data Conversion GPS'
//  '<S29>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections'
//  '<S30>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Simplify and Mask GPS Measurement Bus'
//  '<S31>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Enable Satellite Position and Velocity Calculation'
//  '<S32>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction'
//  '<S33>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Signal Noise Variance'
//  '<S34>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S35>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S36>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S37>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S38>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S39>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Enable Satellite Position and Velocity Calculation'
//  '<S40>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction'
//  '<S41>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Signal Noise Variance'
//  '<S42>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S43>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S44>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S45>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S46>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S47>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Enable Satellite Position and Velocity Calculation'
//  '<S48>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction'
//  '<S49>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Signal Noise Variance'
//  '<S50>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S51>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S52>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S53>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S54>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S55>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/GPS Parameter Logic/MATLAB Function1'
//  '<S56>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Differential Corrections'
//  '<S57>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Ionospheric Corrections'
//  '<S58>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Tropospheric Corrections'
//  '<S59>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Compare To Constant1'
//  '<S60>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Create Elevation Mask and calculate Angles'
//  '<S61>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Satellite Masking'
//  '<S62>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Ionospheric Corrections/Calculate Dualfrequency Correction with L1 and L2C'
//  '<S63>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Ionospheric Corrections/Calculate Klobuchar Model Correction'
//  '<S64>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Ionospheric Corrections/Calculate Wide Lane Combination'
//  '<S65>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Calculate Ionospheric Corrections/MATLAB Function'
//  '<S66>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Create Elevation Mask and calculate Angles/Create Satellite Elevation Mask'
//  '<S67>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Satellite Masking/Apply Differential Correction Mask1'
//  '<S68>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Satellite Masking/Apply Elevation and NaN and Zero Mask'
//  '<S69>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/GPS/Observable Corrections/Satellite Masking/Apply Non Dual Frequency GPS Satellite Mask'
//  '<S70>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/GAL Parameter Logic1'
//  '<S71>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream'
//  '<S72>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream'
//  '<S73>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream'
//  '<S74>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream'
//  '<S75>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Navigation Data Conversion GAL'
//  '<S76>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections'
//  '<S77>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Simplify and Mask GAL Measurement Bus'
//  '<S78>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/GAL Parameter Logic1/MATLAB Function'
//  '<S79>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/GAL Parameter Logic1/MATLAB Function1'
//  '<S80>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Enable Satellite Position and Velocity Calculation'
//  '<S81>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction'
//  '<S82>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Signal Noise Variance'
//  '<S83>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S84>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S85>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S86>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S87>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S88>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Enable Satellite Position and Velocity Calculation'
//  '<S89>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction'
//  '<S90>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Signal Noise Variance'
//  '<S91>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S92>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S93>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S94>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S95>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S96>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Enable Satellite Position and Velocity Calculation'
//  '<S97>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction'
//  '<S98>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Signal Noise Variance'
//  '<S99>'  : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S100>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S101>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S102>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S103>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S104>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Enable Satellite Position and Velocity Calculation'
//  '<S105>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction'
//  '<S106>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Signal Noise Variance'
//  '<S107>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S108>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S109>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S110>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S111>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S112>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Calculate Differential Corrections'
//  '<S113>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Calculate Ionospheric Corrections'
//  '<S114>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Calculate Tropospheric Corrections'
//  '<S115>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Compare To Constant'
//  '<S116>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Create Elevation Mask and calculate Angles'
//  '<S117>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Satellite Masking'
//  '<S118>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Calculate Ionospheric Corrections/Calculate Dualfrequency Correction with E1 and E5'
//  '<S119>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Create Elevation Mask and calculate Angles/Create Satellite Elevation Mask'
//  '<S120>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Satellite Masking/Apply Differential Correction Mask1'
//  '<S121>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Galileo/Observable Corrections/Satellite Masking/Apply Elevation and NaN and Zero Mask'
//  '<S122>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/CalcDOP'
//  '<S123>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion'
//  '<S124>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion'
//  '<S125>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/MATLAB Function'
//  '<S126>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/switch GNSS Measurements'
//  '<S127>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion/Fault Exclusion'
//  '<S128>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion/Weighted RAIM Parity'
//  '<S129>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion/calculate Variance'
//  '<S130>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Check RTCM Valid'
//  '<S131>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Choose Correction Method'
//  '<S132>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Measurement Epoch Splitter'
//  '<S133>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Check RTCM Valid/Compare To Constant'
//  '<S134>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Check RTCM Valid/Detect Change'
//  '<S135>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Check RTCM Valid/S-R Flip-Flop'
//  '<S136>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna/Mode Switch/Choose Correction Method/choose correction mode'
//  '<S137>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Calculate Day of Year'
//  '<S138>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/ConvertGNSSMeasuremendVariableToFixed_CalcAngles'
//  '<S139>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/ConvertGNSSMeasuremendVariableToFixed_CalcAngles1'
//  '<S140>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/ConvertGNSSMeasuremendVariableToFixed_CalcAngles2'
//  '<S141>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Dummy GNSS Measurement'
//  '<S142>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Fuse'
//  '<S143>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GNSS Measurement Epoch Splitter'
//  '<S144>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS'
//  '<S145>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo'
//  '<S146>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Integrity GNSS'
//  '<S147>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/MATLAB Function'
//  '<S148>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Merge GNSS Measurement'
//  '<S149>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Mode Switch'
//  '<S150>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/mergeDiffCorrections'
//  '<S151>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L1 Stream'
//  '<S152>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L2C Stream'
//  '<S153>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L5 Stream'
//  '<S154>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS Parameter Logic'
//  '<S155>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Navigation Data Conversion GPS'
//  '<S156>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections'
//  '<S157>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Simplify and Mask GPS Measurement Bus'
//  '<S158>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L1 Stream/Enable Satellite Position and Velocity Calculation'
//  '<S159>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L1 Stream/Satellite Position and PR Time Correction'
//  '<S160>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L1 Stream/Signal Noise Variance'
//  '<S161>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S162>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S163>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S164>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S165>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L1 Stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S166>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L2C Stream/Enable Satellite Position and Velocity Calculation'
//  '<S167>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L2C Stream/Satellite Position and PR Time Correction'
//  '<S168>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L2C Stream/Signal Noise Variance'
//  '<S169>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S170>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S171>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S172>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S173>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L2C Stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S174>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L5 Stream/Enable Satellite Position and Velocity Calculation'
//  '<S175>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L5 Stream/Satellite Position and PR Time Correction'
//  '<S176>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L5 Stream/Signal Noise Variance'
//  '<S177>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S178>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S179>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S180>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S181>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS L5 Stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S182>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/GPS Parameter Logic/MATLAB Function1'
//  '<S183>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Calculate Differential Corrections'
//  '<S184>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Calculate Ionospheric Corrections'
//  '<S185>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Calculate Tropospheric Corrections'
//  '<S186>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Compare To Constant1'
//  '<S187>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Create Elevation Mask and calculate Angles'
//  '<S188>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Satellite Masking'
//  '<S189>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Calculate Ionospheric Corrections/Calculate Dualfrequency Correction with L1 and L2C'
//  '<S190>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Calculate Ionospheric Corrections/Calculate Klobuchar Model Correction'
//  '<S191>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Calculate Ionospheric Corrections/Calculate Wide Lane Combination'
//  '<S192>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Calculate Ionospheric Corrections/MATLAB Function'
//  '<S193>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Create Elevation Mask and calculate Angles/Create Satellite Elevation Mask'
//  '<S194>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Satellite Masking/Apply Differential Correction Mask1'
//  '<S195>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Satellite Masking/Apply Elevation and NaN and Zero Mask'
//  '<S196>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/GPS/Observable Corrections/Satellite Masking/Apply Non Dual Frequency GPS Satellite Mask'
//  '<S197>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/GAL Parameter Logic1'
//  '<S198>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E1 stream'
//  '<S199>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5 stream'
//  '<S200>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5a stream'
//  '<S201>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5b stream'
//  '<S202>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Navigation Data Conversion GAL'
//  '<S203>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Observable Corrections'
//  '<S204>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Simplify and Mask GAL Measurement Bus'
//  '<S205>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/GAL Parameter Logic1/MATLAB Function'
//  '<S206>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/GAL Parameter Logic1/MATLAB Function1'
//  '<S207>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E1 stream/Enable Satellite Position and Velocity Calculation'
//  '<S208>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction'
//  '<S209>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E1 stream/Signal Noise Variance'
//  '<S210>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S211>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S212>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S213>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S214>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E1 stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S215>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5 stream/Enable Satellite Position and Velocity Calculation'
//  '<S216>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction'
//  '<S217>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5 stream/Signal Noise Variance'
//  '<S218>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S219>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S220>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S221>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S222>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5 stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S223>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5a stream/Enable Satellite Position and Velocity Calculation'
//  '<S224>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction'
//  '<S225>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5a stream/Signal Noise Variance'
//  '<S226>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S227>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S228>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S229>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S230>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5a stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S231>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5b stream/Enable Satellite Position and Velocity Calculation'
//  '<S232>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction'
//  '<S233>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5b stream/Signal Noise Variance'
//  '<S234>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Calculate Satellite Clock Correction'
//  '<S235>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Calculate Satellite Position and Velocity'
//  '<S236>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Time Correction Carrierphase'
//  '<S237>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Time Correction Deltarange'
//  '<S238>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Galileo E5b stream/Satellite Position and PR Time Correction/Time Correction Pseudorange'
//  '<S239>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Observable Corrections/Calculate Differential Corrections'
//  '<S240>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Observable Corrections/Calculate Ionospheric Corrections'
//  '<S241>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Observable Corrections/Calculate Tropospheric Corrections'
//  '<S242>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Observable Corrections/Compare To Constant'
//  '<S243>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Observable Corrections/Create Elevation Mask and calculate Angles'
//  '<S244>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Observable Corrections/Satellite Masking'
//  '<S245>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Observable Corrections/Calculate Ionospheric Corrections/Calculate Dualfrequency Correction with E1 and E5'
//  '<S246>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Observable Corrections/Create Elevation Mask and calculate Angles/Create Satellite Elevation Mask'
//  '<S247>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Observable Corrections/Satellite Masking/Apply Differential Correction Mask1'
//  '<S248>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Galileo/Observable Corrections/Satellite Masking/Apply Elevation and NaN and Zero Mask'
//  '<S249>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Integrity GNSS/CalcDOP'
//  '<S250>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Integrity GNSS/GNSS Fault Detection Identification Exclusion'
//  '<S251>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion'
//  '<S252>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Integrity GNSS/GNSS Fault Detection Identification Exclusion/MATLAB Function'
//  '<S253>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Integrity GNSS/GNSS Fault Detection Identification Exclusion/switch GNSS Measurements'
//  '<S254>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion/Fault Exclusion'
//  '<S255>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion/Weighted RAIM Parity'
//  '<S256>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Integrity GNSS/GNSS Fault Detection Identification Exclusion/GNSS Fault Detection Identification Exclusion/calculate Variance'
//  '<S257>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Mode Switch/Check RTCM Valid'
//  '<S258>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Mode Switch/Choose Correction Method'
//  '<S259>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Mode Switch/Measurement Epoch Splitter'
//  '<S260>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Mode Switch/Check RTCM Valid/Compare To Constant'
//  '<S261>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Mode Switch/Check RTCM Valid/Detect Change'
//  '<S262>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Mode Switch/Check RTCM Valid/S-R Flip-Flop'
//  '<S263>' : 'GNSSPreProcessingDualAntenna/GNSSPseudorangeOpsAntenna1/Mode Switch/Choose Correction Method/choose correction mode'

#endif                                 // RTW_HEADER_GNSSPreProcessingDualAntenna_h_

//
// File trailer for generated code.
//
// [EOF]
//
