// Copyright 2021 Institute of Automatic Control RWTH Aachen University
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: Haoming Zhang (h.zhang@irt.rwth-aachen.de)
//


#ifndef IRT_GNSS_PREPROCESSING_GNSS_PREPROCESSOR_H
#define IRT_GNSS_PREPROCESSING_GNSS_PREPROCESSOR_H

#pragma once

#include <rclcpp/rclcpp.hpp>
#include <vector>
#include <algorithm>
#include <mutex>
#include <chrono>
#include <boost/circular_buffer.hpp>
#include <irt_nav_common/navigation_tools.h>
#include <irt_nav_common/navigation_tool_ros.h>
#include <irt_nav_msgs/msg/rtcml1_e1.hpp>
#include <irt_nav_msgs/msg/gnss_obs_pre_processed.hpp>
#include <irt_nav_msgs/msg/gnss_obs.hpp>
#include <irt_nav_msgs/msg/gnss_correction.hpp>
#include <irt_nav_msgs/msg/pva_geodetic.hpp>
#include <std_msgs/msg/header.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <irt_nav_msgs/msg/sol_ls.hpp>
#include <irt_nav_msgs/msg/pvtls.hpp>
#include <irt_nav_msgs/msg/residual.hpp>
#include <irt_nav_msgs/msg/residuals.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>

#include "gnss_preprocessor_types.h"
#include "ros_parameter.h"
#include "sigslot/signal.hpp"
#include "rapidcsv.h"


using namespace utils;
using namespace std::placeholders;

namespace irt_gnss_preprocessing
{
    class GNSSPreprocessor {

    protected: // protected variables
        std::string receiver_type_;
        rclcpp::Node* node_ptr_;
        rclcpp::Subscription<irt_nav_msgs::msg::RTCML1E1>::SharedPtr rtcmv3_L1E1_sub_;
        rclcpp::Publisher<irt_nav_msgs::msg::GNSSObsPreProcessed>::SharedPtr gnss_obs_pub_;
        //rclcpp::Publisher<irt_nav_msgs::msg::GNSSObsPreProcessed>::SharedPtr gnss_obs_raw_pub_;
        rclcpp::Publisher<irt_nav_msgs::msg::PVAGeodetic>::SharedPtr pvt_pub_;
        rclcpp::Publisher<irt_nav_msgs::msg::PVTLS>::SharedPtr lspvt_pub_;
        rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr user_estimation_sub_;
        rclcpp::Publisher<sensor_msgs::msg::NavSatFix>::SharedPtr ls_ant_main_pub_;
        rclcpp::Publisher<irt_nav_msgs::msg::Residuals>::SharedPtr ls_residuals_pub_;

        rclcpp::CallbackGroup::SharedPtr commonCallbackGroup_;
        std::shared_ptr<rclcpp::SubscriptionOptions> commonSubOpt_;

        CircularDataBuffer<GNSSMeasurementPreProcessed> gnss_obs_buffer_;
        CircularDataBuffer<gnssraw_measurement_t> gnss_obs_raw_ant_main_buffer_;

        CircularDataBuffer<gnssraw_pvt_geodetic_t> pvt_geodetic_buffer_;
        CircularDataBuffer<gnssraw_gal_nav_t> gal_inav_ephemeris_buffer_;
        CircularDataBuffer<gnssraw_gal_nav_t> gal_fnav_ephemeris_buffer_;
        CircularDataBuffer<gnssraw_gal_ion_t> gal_ion_buffer_;
        CircularDataBuffer<gnssraw_ggto_t>   gal_gst_gps_buffer_;
        std::map<double, std::map<int, bool>> LOSLoopUpTable_;
        //CircularDataBuffer<gnssraw_gps_nav_t> gps_nav_ephemeris_buffer_;

        std::mutex mutex_gps_ephem_;
        gnssraw_gps_nav_t gps_nav_ephemeris_buffer_{};

        std::mutex mutex_gal_ephem_;
        gnssraw_gal_nav_t gal_nav_ephemeris_buffer_{};

        CircularDataBuffer<gnssraw_gps_ion_t> gps_ion_buffer_;

        CircularDataBuffer<DD_RTCM_3_3_L1_E1_t> rtcm_buffer_;
        CircularDataBuffer<UserEstimation_T> user_estimation_buffer_;
        parameters_integrity_t parameters_integrity_;
        parameters_gnss_t parameters_gnss_;
        parameters_gnss_t parameters_gnss_DD_dualantenna_;
        parameters_gnss_t parameters_gnss_DD_rtcm_;
        uint8_t ggto_sync_mode_ = 1;
        bool use_mode_switch_logic_ = false;
        bool enable_dual_antenna_DD_ = false;
        bool enable_rtcm_DD_ = false;
        bool use_measured_variance_ = false;
        bool enable_gnss_merge_ = true;
        std::atomic_bool pub_gnss_obs_;
        double dual_antenna_heading_offset_ = -90.0;
        double print_info_duration_ = 1; // 5s


#if USE_DUAL_ANTENNA
        CircularDataBuffer<gnssraw_measurement_t> gnss_obs_raw_ant_aux_buffer_;
        // HCS_Measurement hcs_ant_aux_;
        std::unique_ptr<GNSSPreProcessingDualAntenna> gnss_preprocessor_;
        std::unique_ptr<GNSSPreProcessingDualAntenna> dd_dualantenna_preprocessor_;
#else
        std::unique_ptr<GNSS_preprocessingModelClass> gnss_preprocessor_;
#endif
        sigslot::signal<irt_nav_msgs::msg::GNSSObsPreProcessed> signal_new_gnss_obs_;

#if USE_GNSS_RTK_DD
        std::unique_ptr<DDRTCM> dd_rtcm_preprocessor_;
        CircularDataBuffer<gnssraw_measurement_t> gnss_obs_raw_DD_rtcm_buffer_;
#endif

    protected: // protected methods

        template<typename T>
        static irt_nav_msgs::msg::GNSSObs makeGNSSObsROSMsg(const T& gnss_obs, size_t num_obs){
            // Pls pay attention, base_pos of gnss_obs won't be copied to msg::GNSSObs

          irt_nav_msgs::msg::GNSSObs msg;
          msg.time_receive = gnss_obs.time_receive;

          // the MATLAB has output GNSS_Measurement with variables, only effective (non NaN) values should be put into ros msg

          msg.satelite_vec.resize(num_obs);
          msg.satelite_pos.resize(num_obs);
          msg.prn.resize(num_obs);
          msg.pseudorange.resize(num_obs);
          msg.pseudorange_raw.resize(num_obs);
          msg.pseudorange_satclk_corrected.resize(num_obs);
          msg.pseudorange_var.resize(num_obs);
          msg.pseudorange_var_measured.resize(num_obs);
          msg.deltarange.resize(num_obs);
          msg.deltarange_raw.resize(num_obs);
          msg.deltarange_satclk_corrected.resize(num_obs);
          msg.deltarange_var.resize(num_obs);
          msg.carrierphase.resize(num_obs);
          msg.carrierphase_raw.resize(num_obs);
          msg.carrierphase_satclk_corrected.resize(num_obs);
          msg.carrierphase_var_measured.resize(num_obs);
          //msg.locktime.resize(num_obs);
          msg.cn0.resize(num_obs);
          msg.elevation_angle.resize(num_obs);
          msg.azimuth_angle.resize(num_obs);

          std::copy(std::begin(gnss_obs.PRN), std::begin(gnss_obs.PRN) + num_obs, msg.prn.begin());
          std::copy(std::begin(gnss_obs.pseudorange), std::begin(gnss_obs.pseudorange) + num_obs, msg.pseudorange.begin());
          std::copy(std::begin(gnss_obs.pseudorange_raw), std::begin(gnss_obs.pseudorange_raw) + num_obs, msg.pseudorange_raw.begin());
          std::copy(std::begin(gnss_obs.pseudorange_satclk_corrected), std::begin(gnss_obs.pseudorange_satclk_corrected) + num_obs, msg.pseudorange_satclk_corrected.begin());
          std::copy(std::begin(gnss_obs.deltarange), std::begin(gnss_obs.deltarange) + num_obs, msg.deltarange.begin());
          std::copy(std::begin(gnss_obs.deltarange_raw), std::begin(gnss_obs.deltarange_raw) + num_obs, msg.deltarange_raw.begin());
          std::copy(std::begin(gnss_obs.deltarange_satclk_corrected), std::begin(gnss_obs.deltarange_satclk_corrected) + num_obs, msg.deltarange_satclk_corrected.begin());
          std::copy(std::begin(gnss_obs.variance_pseudorange), std::begin(gnss_obs.variance_pseudorange) + num_obs, msg.pseudorange_var.begin());
          std::copy(std::begin(gnss_obs.variance_deltarange), std::begin(gnss_obs.variance_deltarange) + num_obs, msg.deltarange_var.begin());
          std::copy(std::begin(gnss_obs.variance_pseudorange_measured), std::begin(gnss_obs.variance_pseudorange_measured) + num_obs, msg.pseudorange_var_measured.begin());
          std::copy(std::begin(gnss_obs.variance_carrierphase_measured), std::begin(gnss_obs.variance_carrierphase_measured) + num_obs, msg.carrierphase_var_measured.begin());
          std::copy(std::begin(gnss_obs.carrierphase), std::begin(gnss_obs.carrierphase) + num_obs, msg.carrierphase.begin());
          std::copy(std::begin(gnss_obs.carrierphase_raw), std::begin(gnss_obs.carrierphase_raw) + num_obs, msg.carrierphase_raw.begin());
          std::copy(std::begin(gnss_obs.carrierphase_satclk_corrected), std::begin(gnss_obs.carrierphase_satclk_corrected) + num_obs, msg.carrierphase_satclk_corrected.begin());
          //std::copy(std::begin(gnss_obs.locktime), std::begin(gnss_obs.locktime) + num_obs, msg.locktime.begin());
          std::copy(std::begin(gnss_obs.CN0), std::begin(gnss_obs.CN0) + num_obs, msg.cn0.begin());
          std::copy(std::begin(gnss_obs.elevation_angle), std::begin(gnss_obs.elevation_angle) + num_obs, msg.elevation_angle.begin());
          std::copy(std::begin(gnss_obs.azimuth_angle), std::begin(gnss_obs.azimuth_angle) + num_obs, msg.azimuth_angle.begin());

          for(size_t i = 0; i < num_obs; i++)
          {
            msg.locktime.template emplace_back(int(gnss_obs.locktime[i] * 10) / 10.);
          }
          for(size_t i = 0; i < num_obs; i ++)
          {
              msg.satelite_pos[i].x = gnss_obs.satellite_position[i];
              msg.satelite_pos[i].y = gnss_obs.satellite_position[i + 40];
              msg.satelite_pos[i].z = gnss_obs.satellite_position[i + 40 * 2];
              msg.satelite_vec[i].x = gnss_obs.satellite_velocity[i];
              msg.satelite_vec[i].y = gnss_obs.satellite_velocity[i + 40];
              msg.satelite_vec[i].z = gnss_obs.satellite_velocity[i + 40 * 2];
          }
          
          msg.base_pos.x = gnss_obs.base_position[0];
          msg.base_pos.y = gnss_obs.base_position[1];
          msg.base_pos.z = gnss_obs.base_position[2];
          return msg;
        }


        static irt_nav_msgs::msg::GNSSObsPreProcessed makeGNSSObsPreProcessedROSMsg(const GNSSMeasurementPreProcessed& gnss_obs)
        {
          static double last_rtcm_tow = 0.;
          irt_nav_msgs::msg::GNSSObsPreProcessed msg{};

          msg.gnss_obs_ant_main = makeGNSSObsROSMsg<GNSSMeasurementFixed>(gnss_obs.gnss_obs_ant_main, gnss_obs.num_meas_ant_main);

          msg.time_offset_gal_gps = gnss_obs.time_offset_gal_gps;
          msg.gnss_obs_ant_main.integrity_flag = gnss_obs.integrity_flag_ant_main;
          msg.is_ggto_valid = gnss_obs.is_ggto_valid;
          msg.gnss_obs_ant_main.gps_corrected = gnss_obs.ant_main_gps_corrected;
          msg.gnss_obs_ant_main.gal_corrected = gnss_obs.ant_main_gal_corrected;
          msg.has_rtk = gnss_obs.has_rtk;
          msg.has_dualantenna = gnss_obs.has_dualantenna;

          msg.faulty_prn_aux.resize(0);
          msg.faulty_prn_main.resize(0);

          //faulty sat
          for (size_t i = 0; i < 40; i++) {
            if (!std::isnan(gnss_obs.faulty_svid_ant_main[2 * i])) {

              msg.faulty_prn_main.push_back(gnss_obs.faulty_svid_ant_main[2 * i]);
            }
            else {
              break;
            }
          }

          for (uint8_t &y : msg.faulty_prn_main) {
            for (uint16_t &x : msg.gnss_obs_ant_main.prn){
              if (y == x){
                x = 0;
                break;
              }
            }
          }

          for(const auto& correction : gnss_obs.diff_psr_corrections)
          {
            irt_nav_msgs::msg::GNSSCorrection corr;
            corr.prn = correction.first;
            corr.psr_correction = correction.second;
            msg.gnss_corrections.emplace_back(corr);
          }

#ifdef USE_DUAL_ANTENNA
          msg.gnss_obs_ant_aux = makeGNSSObsROSMsg<GNSSMeasurementFixed>(gnss_obs.gnss_obs_ant_aux, gnss_obs.num_meas_ant_aux);
          msg.gnss_obs_ant_aux.integrity_flag = gnss_obs.integrity_flag_ant_aux;
          msg.gnss_obs_ant_aux.gps_corrected = gnss_obs.ant_aux_gps_corrected;
          msg.gnss_obs_ant_aux.gal_corrected = gnss_obs.ant_aux_gal_corrected;
          //faulty sat aux
          for (size_t i = 0; i < 40; i++) {
            if (!std::isnan(gnss_obs.faulty_svid_ant_aux[2 * i])) {
              msg.faulty_prn_aux.push_back(gnss_obs.faulty_svid_ant_aux[2 * i]);
            }
            else {
              break;
            }
          }

          for (uint8_t &y : msg.faulty_prn_aux) {
            for (uint16_t &x : msg.gnss_obs_ant_aux.prn){
              if (y == x){
                x = 0;
                break;
              }
            }
          }

          if(gnss_obs.has_dualantenna_DD)
          {
            msg.has_dualantenna_dd = true;
            msg.dd_gnss_obs_dualantenna = makeGNSSObsROSMsg<GNSSMeasurementFixed>(gnss_obs.gnss_obs_DD_dualantenna, gnss_obs.num_meas_ant_dd_dualantenna);
            msg.dd_gnss_obs_dualantenna.ref_sat_svid_gps = gnss_obs.ref_sat_svid_gps_dual_antenna;
            msg.dd_gnss_obs_dualantenna.ref_sat_svid_gal = gnss_obs.ref_sat_svid_gal_dual_antenna;
            msg.gnss_obs_ant_main.dd_idx_sync_ref = gnss_obs.DD_idx_sync_ant_main;
            msg.dd_gnss_obs_dualantenna.dd_idx_sync_ref = gnss_obs.DD_idx_sync_ant_aux;
            for(const auto& d : gnss_obs.svid_carrier_used_DD_dualantenna)
            {
              if(std::isnan(d) || !d)
                continue;
              msg.dd_gnss_obs_dualantenna.svid_carrier_used.push_back(d);
            }

            for (uint16_t &x : msg.dd_gnss_obs_dualantenna.prn){
              for (uint8_t &y : msg.faulty_prn_aux) {
                if (y == x){
                  x = 0;
                  break;
                }
              }
              for (uint8_t &y : msg.faulty_prn_main) {
                if (y == x){
                  x = 0;
                  break;
                }
              }
            }

          }
#endif
#ifdef USE_GNSS_TIME_DD
          if(gnss_obs.has_time_DD)
          {
            msg.has_time_dd = true;
            msg.dd_gnss_obs_time = makeGNSSObsROSMsg(gnss_obs.gnss_obs_DD_time);
          }
#endif
#ifdef USE_GNSS_RTK_DD
          if(gnss_obs.has_rtk_DD && gnss_obs.gnss_obs_DD_rtk.time_receive > last_rtcm_tow)
          {
            last_rtcm_tow = gnss_obs.gnss_obs_DD_rtk.time_receive;
            msg.has_rtcm_dd = true;
            msg.dd_gnss_obs_rtcm = makeGNSSObsROSMsg<GNSSMeasurementFixed>(gnss_obs.gnss_obs_DD_rtk, gnss_obs.num_meas_ant_dd_rtk);
            msg.gnss_obs_ant_main.dd_idx_sync_ref = gnss_obs.DD_idx_sync_ant_main;
            msg.dd_gnss_obs_rtcm.dd_idx_sync_ref = gnss_obs.DD_idx_sync_ant_rtk;
            msg.dd_gnss_obs_rtcm.ref_sat_svid_gps = gnss_obs.ref_sat_svid_gps_rtk;
            msg.dd_gnss_obs_rtcm.ref_sat_svid_gal = gnss_obs.ref_sat_svid_gal_rtk;
            msg.dd_gnss_obs_rtcm.base_pos.x = gnss_obs.gnss_obs_DD_rtk.base_position[0];
            msg.dd_gnss_obs_rtcm.base_pos.y = gnss_obs.gnss_obs_DD_rtk.base_position[1];
            msg.dd_gnss_obs_rtcm.base_pos.z = gnss_obs.gnss_obs_DD_rtk.base_position[2];
            for(const auto& d : gnss_obs.svid_carrier_used_DD_rtcm)
            {
              if(std::isnan(d) || !d)
                continue;
              msg.dd_gnss_obs_rtcm.svid_carrier_used.push_back(d);
            }
            //last_rtcm_TOW = gnss_obs.gnss_obs_DD_rtk.time_receive;

            for (uint8_t &y : msg.faulty_prn_main) {
              for (uint16_t &x : msg.dd_gnss_obs_rtcm.prn){
                if (y == x){
                  x = 0;
                  break;
                }
              }
            }

          } else
            msg.has_rtcm_dd = false;
#endif
          return msg;
        }

        std::pair<UserEstimation_T, bool> checkUserEstimation()
        {
          UserEstimation_T userEst{};
          UserEstimation_T receivedUserEst = user_estimation_buffer_.get_last_buffer();
          auto pvt = pvt_geodetic_buffer_.get_last_buffer();

          bool used_pvt = false;

          if(abs(receivedUserEst[0] - pvt.phi) < 0.01 && abs(receivedUserEst[1] - pvt.lambda) < 0.01)
          {
            //RCLCPP_WARN(this->node_ptr_->get_logger(), "User estimation available, using it for preprocessing ...");
            std::copy(receivedUserEst.begin(), receivedUserEst.end(), userEst.begin());
          }
          else
          {
            //RCLCPP_WARN(this->node_ptr_->get_logger(), "User estimation not available, using pvt for preprocessing ...");
            userEst[0] = pvt.phi;
            userEst[1] = pvt.lambda;
            userEst[2] = pvt.h;
            userEst[3] = pvt.RxClkBias; //* 2.99792458e8 * 1e-3;
            userEst[4] = pvt.phi;
            userEst[5] = pvt.lambda;
            userEst[6] = pvt.h;

            used_pvt = true;
          }
          return std::make_pair(userEst, used_pvt);
        }

        template <typename T>
        bool checkHaveEphem(const T& gps_nav)
        {
          size_t effective_meas = 0;
          for(const auto& prn : gps_nav.SVID)
          {
            if(std::isnan(prn) || prn == 0)
              continue;
            effective_meas ++;
          }
          return effective_meas > 0;
        }

        template <typename T>
        bool checkHaveGNSSSingleMeasData(const T& gps_nav)
        {
          return gps_nav.SVID != 0;
        }


    public:
        virtual
        ~GNSSPreprocessor() = default;

        /*
         * Initializes the preprocessor according to receiver type
         */
        virtual void
        initialize(rclcpp::Node& node, const std::string& receiver_type) = 0;

        void set_user_estimations(const UserEstimation_T& new_estimation)
        {
          user_estimation_buffer_.update_buffer(new_estimation, rclcpp::Time(node_ptr_->now()));
        }

        void getGNSSParameters(const std::string& type, parameters_gnss_t& parameter)
        {
          RosParameter<bool> enable_galileo_timebase(type + "GNSSParameters.enable_galileo_timebase",
                                                     false,
                                                     *node_ptr_);
          RosParameter<bool> enable_differential_correction(type + "GNSSParameters.enable_differential_correction",
                                                            true,
                                                            *node_ptr_);
          RosParameter<bool> enable_tropospheric_correction(type + "GNSSParameters.enable_tropospheric_correction",
                                                            false,
                                                            *node_ptr_);
          RosParameter<bool> enable_SatPosVel_calculation(type + "GNSSParameters.enable_SatPosVel_calculation",
                                                          true,
                                                          *node_ptr_);
          RosParameter<bool> enable_WL_correction(type + "GNSSParameters.enable_WL_correction",
                                                  true,
                                                  *node_ptr_);
          RosParameter<bool> enable_ionospheric_correction(type + "GNSSParameters.enable_ionospheric_correction",
                                                           false,
                                                           *node_ptr_);
          RosParameter<double> elevation_mask(type + "GNSSParameters.elevation_mask",
                                           15.,
                                           *node_ptr_);


          RosParameter<bool> enable_gps(type + "GPSParameters.enable",
                                        true,
                                        *node_ptr_);
          RosParameter<bool> enable_l1(type +"GPSParameters.enable_l1",
                                       true,
                                       *node_ptr_);
          RosParameter<bool> enable_l2(type +"GPSParameters.enable_l2",
                                       false,
                                       *node_ptr_);
          RosParameter<bool> enable_galileo(type +"GalileoParameters.enable",
                                            false,
                                            *node_ptr_);
          RosParameter<bool> enable_e1(type +"GalileoParameters.enable_e1",
                                       true,
                                       *node_ptr_);

          RosParameter<bool> enable_e5(type +"GalileoParameters.enable_e5",
                                       false,
                                       *node_ptr_);

          RosParameter<bool> enable_e5a(type +"GalileoParameters.enable_e5a",
                                        true,
                                        *node_ptr_);

          RosParameter<bool> enable_e5b(type +"GalileoParameters.enable_e5b",
                                        false,
                                        *node_ptr_);

          RosParameter<bool> enable_gate(type +"GateParameters.enable",
                                         false,
                                         *node_ptr_);

          std::vector<double> dummy_prn = {0., 0., 0., 0., 0., 0., 0.};
          //RosParameter<std::vector<double>> prn_flags(type +"GateParameters.prn_flags",
          //                                            dummy_prn,
          //                                            *node_ptr_);

          RosParameter<bool> use_measured_variance(type + "use_measured_variance",
                                                   false,
                                                   *node_ptr_);

          parameter.elevation_mask = elevation_mask.value();
          parameter.enable_SatPosVel_calculation = enable_SatPosVel_calculation.value();
          parameter.enable_differential_correction = enable_differential_correction.value();
          parameter.enable_galileo_timebase = enable_galileo_timebase.value();
          parameter.enable_WL_correction = enable_WL_correction.value();
          parameter.enable_ionospheric_correction = enable_ionospheric_correction.value();
          parameter.enable_tropospheric_correction = enable_tropospheric_correction.value();
          parameter.use_measured_variance = use_measured_variance.value();

          parameter.gps.enable_gps = enable_gps.value();
          parameter.gps.enable_gps_l1 = enable_l1.value();
          parameter.gps.enable_gps_l2 = enable_l2.value();

          parameter.galileo.enable_galileo = enable_galileo.value();
          parameter.galileo.enable_galileo_e1 = enable_e1.value();
          parameter.galileo.enable_galileo_e5 = enable_e5.value();
          parameter.galileo.enable_galileo_e5a = enable_e5a.value();
          parameter.galileo.enable_galileo_e5b = enable_e5b.value();
          parameter.gate.enable_gate = enable_gate.value();

          /*
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "--------------- " << type << " GNSS Parameter Start ---------------");
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Elevation Threshold: " << parameter.elevation_mask);
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Calculate SatPoseVel: " << (parameter.enable_SatPosVel_calculation ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable Ionospheric Correction: " << (parameter.enable_ionospheric_correction ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable Tropospheric Correction: " << (parameter.enable_tropospheric_correction ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable diff. Correction: " << (parameter.enable_differential_correction ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable Galileo Timebase: " << (parameter.enable_galileo_timebase ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable WL Correction: " << (parameter.enable_WL_correction ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Use Measured Variance: " << (parameter.use_measured_variance ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable GPS: " << (parameter.gps.enable_gps ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable GPS L1: " << (parameter.gps.enable_gps_l1 ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable GPS L2: " << (parameter.gps.enable_gps_l2 ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable Galileo: " << (parameter.galileo.enable_galileo ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable Galileo E1: " << (parameter.galileo.enable_galileo_e1 ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable Galileo E5: " << (parameter.galileo.enable_galileo_e5 ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable Galileo E5a: " << (parameter.galileo.enable_galileo_e5a ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable Galileo E5b: " << (parameter.galileo.enable_galileo_e5b ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Enable Gate: " << (parameter.gate.enable_gate ? "True" : "False"));
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "--------------- " << type << " GNSS Parameter End ---------------");
           */
          try
          {
           // parameter.gate.prn_psl1 = prn_flags.value()[0];
            //parameter.gate.prn_psl2 = prn_flags.value()[1];
            //parameter.gate.prn_psl3 = prn_flags.value()[2];
            //parameter.gate.prn_psl4 = prn_flags.value()[3];
           // parameter.gate.prn_psl5 = prn_flags.value()[4];
           // parameter.gate.prn_psl6 = prn_flags.value()[5];
           // parameter.gate.prn_psl7 = prn_flags.value()[6];
           // parameter.gate.prn_psl8 = prn_flags.value()[7];
            //parameter.gate.prn_psl9 = prn_flags.value()[8];

          } catch (std::exception &ex)
          {
            RCLCPP_WARN_STREAM(node_ptr_->get_logger(), "Exception while reading gate prn of measurement type: " << type << " error: " << ex.what());
          }
        }

        //TODO moveconvert function
        static DD_RTCM_3_3_L1_E1_t convertIRTMSGRTCML1E1(const irt_nav_msgs::msg::RTCML1E1 &msg){

          DD_RTCM_3_3_L1_E1_t ddRTCMMeas{};
          ddRTCMMeas.TOW = msg.tow;
            for(uint i = 0; i < msg.svid.size(); i++){
              ddRTCMMeas.SVID[i] = msg.svid[i];
              ddRTCMMeas.locktime[i] = msg.locktime[i];
              ddRTCMMeas.Carrier[i] = msg.carrier[i];
              ddRTCMMeas.Type[i] = msg.type[i];
              ddRTCMMeas.Pseudorange[i] = msg.pseudorange[i];
              ddRTCMMeas.CN0[i] = ddRTCMMeas.CN0[i];

            }
          ddRTCMMeas.Reference_Station_ID = msg.reference_station_id;
          ddRTCMMeas.base[0] = msg.base[0];
          ddRTCMMeas.base[1] = msg.base[1];
          ddRTCMMeas.base[2] = msg.base[2];
          return ddRTCMMeas;
        }

        void
        initializeCommons()
        {

          // init Callback Groups
          commonCallbackGroup_ = node_ptr_->create_callback_group(rclcpp::CallbackGroupType::Reentrant);

          commonSubOpt_ = std::make_shared<rclcpp::SubscriptionOptions>();
          commonSubOpt_->callback_group = commonCallbackGroup_;

          RosParameter<bool> pub_gnss_obs("GNSSPreprocessor.publish_gnss_obs",
                                          true,
                                          *node_ptr_);
          this->pub_gnss_obs_ = pub_gnss_obs.value();

          RosParameter<double> print_info_duration("GNSSPreprocessor.print_info_duration",
                                          1.0,
                                          *node_ptr_);
          this->print_info_duration_ = print_info_duration.value();

          RosParameter<double> antenna_heading_offset("GNSSPreprocessor.antenna_heading_offset",
                                          -90.,  // heading off set if the main antenna is in the drive direction on the left of aux. antenna
                                          *node_ptr_);
          this->dual_antenna_heading_offset_ = antenna_heading_offset.value();

          RosParameter<bool> use_user_est_from_topic("GNSSPreprocessor.user_estimation_from_topic",
                                                     true,
                                                     *node_ptr_);

          RosParameter<int> buffer_size("GNSSPreprocessor.default_buffer_size",
                                        3,
                                        *node_ptr_);
         // RosParameter<std::map<std::string, int>> buffer_size_map("GNSSPreProcessor.buffer_size", *node_ptr_);

          RosParameter<int> ggto_sync_mode("CommonGNSSParameters.ggto_sync_mode",
                                           1,
                                           *node_ptr_);
          RosParameter<bool> use_mode_switch_logic("CommonGNSSParameters.use_mode_switch_logic",
                                                   false,
                                                   *node_ptr_);

          RosParameter<bool> enable_dual_antenna_dd("GNSSPreprocessor.enable_dual_antenna_dd",
                                                    false,
                                                    *node_ptr_);

          RosParameter<bool> enable_rtcm_dd("GNSSPreprocessor.enable_rtcm_dd",
                                                    false,
                                                    *node_ptr_);

          RosParameter<bool> enable_gnss_merge("GNSSPreprocessor.enable_gnss_merge",
                                            false,
                                            *node_ptr_);

          RCLCPP_INFO(node_ptr_->get_logger(), "--------------------- GNSSTCIntegrator READING NLOS LOOKUPTABLE! ---------------------");
          RosParameter<std::string> NLOSCSVFilePath("GNSSPreprocessor.NLOSCSVFilePath", *node_ptr_);

          if(!NLOSCSVFilePath.value().empty())
          {
            rapidcsv::Document doc(NLOSCSVFilePath.value(), rapidcsv::LabelParams(0, -1));
            const auto rowNum = doc.GetRowCount();
            for(size_t i = 0; i < rowNum; i++)
            {
              const auto tow = double(int(doc.GetCell<double>(0, i) * 10)) / 10.;
              const auto prn = doc.GetCell<int>(1, i);
              const auto isLOS = doc.GetCell<int>(2, i);

              auto tsPos = LOSLoopUpTable_.find(tow);
              if(tsPos == LOSLoopUpTable_.end())
              {
                std::map<int, bool> newLOSVec;
                newLOSVec.insert(std::make_pair(prn, isLOS == 1));
                LOSLoopUpTable_.insert(std::make_pair(tow, newLOSVec));
              }
              else
              {
                LOSLoopUpTable_[tow].insert(std::make_pair(prn, isLOS == 1));
              }
            }
          }

          this->enable_gnss_merge_ = enable_gnss_merge.value();
          this->ggto_sync_mode_ = ggto_sync_mode.value();
          this->use_mode_switch_logic_ = use_mode_switch_logic.value();
          this->enable_dual_antenna_DD_ = enable_dual_antenna_dd.value();
          this->enable_rtcm_DD_ = enable_rtcm_dd.value();

          // get gnss parameters
          this->getGNSSParameters("Common", parameters_gnss_);
          this->getGNSSParameters("DDDualAntenna", parameters_gnss_DD_dualantenna_);
          this->getGNSSParameters("DDRTCM", parameters_gnss_DD_rtcm_);

          RosParameter<bool> enable_integrity("IntegrityParametersCommon.enable",
                                       true,
                                       *node_ptr_);

          RosParameter<bool> enable_gnss_exclusion("IntegrityParametersCommon.enable_gnss_exclusion",
                                       true,
                                       *node_ptr_);

          RosParameter<bool> enable_imu_exclusion("IntegrityParametersCommon.enable_imu_exclusion",
                                       true,
                                       *node_ptr_);

          RosParameter<bool> enable_dvl_exclusion("IntegrityParametersCommon.enable_dvl_exclusion",
                                       true,
                                       *node_ptr_);

          RosParameter<int> hal("RAIMParameters.hal",
                                       25,
                                       *node_ptr_);

          RosParameter<double> p_fa("RAIMParameters.p_fa",
                                       1e-6,
                                       *node_ptr_);

          RosParameter<double> p_md("RAIMParameters.p_md",
                                       1e-3,
                                       *node_ptr_);

          RosParameter<double> p_bayes_threshold("RAIMParameters.p_bayes_threshold",
                                       1.,
                                       *node_ptr_);

          RosParameter<double> tta("RAIMParameters.tta",
                                       0.,
                                       *node_ptr_);

          RosParameter<double> tte("RAIMParameters.tte",
                                       1.,
                                       *node_ptr_);

          RosParameter<int> max_num_obs("RAIMParameters.max_num_obs",
                                       40,
                                       *node_ptr_);

          RosParameter<int> num_var("RAIMParameters.num_var",
                                       4,
                                       *node_ptr_);

          RosParameter<int> max_num_to_identify_onde("RAIMParameters.max_num_to_identify_onde",
                                       1,
                                       *node_ptr_);

          RosParameter<int> variance_mode("RAIMParameters.variance_mode",
                                       1,
                                       *node_ptr_);

          parameters_integrity_.enable_DVL_exclusion = enable_dvl_exclusion.value();
          parameters_integrity_.enable_GNSS_exclusion = enable_gnss_exclusion.value();
          parameters_integrity_.enable_IMU_exclusion = enable_imu_exclusion.value();
          parameters_integrity_.enable_integrity = enable_integrity.value();
          parameters_integrity_.raim_parameter.HAL = hal.value();
          parameters_integrity_.raim_parameter.P_FA = p_fa.value();
          parameters_integrity_.raim_parameter.P_MD = p_md.value();
          parameters_integrity_.raim_parameter.P_BayesThreshold = p_bayes_threshold.value();
          parameters_integrity_.raim_parameter.TTA = tta.value();
          parameters_integrity_.raim_parameter.TTE = tte.value();
          parameters_integrity_.raim_parameter.maxNumMeas = max_num_obs.value();
          parameters_integrity_.raim_parameter.maxNumToIdentifyOnce = max_num_to_identify_onde.value();
          parameters_integrity_.raim_parameter.numVar = num_var.value();
          parameters_integrity_.raim_parameter.VarianceMode = variance_mode.value();

          rtcm_buffer_.resize_buffer(buffer_size.value());
          gnss_obs_buffer_.resize_buffer(buffer_size.value());
          gnss_obs_raw_ant_main_buffer_.resize_buffer(buffer_size.value());

          pvt_geodetic_buffer_.resize_buffer(buffer_size.value());
          gal_inav_ephemeris_buffer_.resize_buffer(buffer_size.value());
          gal_fnav_ephemeris_buffer_.resize_buffer(buffer_size.value());
          gal_ion_buffer_.resize_buffer(buffer_size.value());
          gal_gst_gps_buffer_.resize_buffer(buffer_size.value());
          //gps_nav_ephemeris_buffer_.resize_buffer(buffer_size.value());
          gps_ion_buffer_.resize_buffer(buffer_size.value());

          rtcm_buffer_.resize_buffer(buffer_size.value());
          user_estimation_buffer_.resize_buffer(buffer_size.value());
#if USE_DUAL_ANTENNA
          gnss_obs_raw_ant_aux_buffer_.resize_buffer(buffer_size.value());
#endif
#if USE_GNSS_RTK_DD
          gnss_obs_raw_DD_rtcm_buffer_.resize_buffer(buffer_size.value());
#endif

          if(this->pub_gnss_obs_)
          {
            gnss_obs_pub_ = node_ptr_->create_publisher<irt_nav_msgs::msg::GNSSObsPreProcessed>("gnss_obs_preprocessed",
                                                                                            rclcpp::SensorDataQoS());
            //gnss_obs_raw_pub_ = node_ptr_->create_publisher<irt_nav_msgs::msg::GNSSObsPreProcessed>("gnss_obs_raw",
              //                                                                                  rclcpp::SensorDataQoS());
            pvt_pub_ = node_ptr_->create_publisher<irt_nav_msgs::msg::PVAGeodetic>("PVT",
                                                                               rclcpp::SensorDataQoS());

            lspvt_pub_ = node_ptr_->create_publisher<irt_nav_msgs::msg::PVTLS>("LeastSquarePVT",
                                                                           rclcpp::SensorDataQoS());

            ls_ant_main_pub_ = node_ptr_->create_publisher<sensor_msgs::msg::NavSatFix>("ant_main_ls",
                                                                                        rclcpp::SystemDefaultsQoS());

            ls_residuals_pub_ = node_ptr_->create_publisher<irt_nav_msgs::msg::Residuals>("ls_ant_main_residuals",
                                                                                      rclcpp::SystemDefaultsQoS());

          }

          rtcmv3_L1E1_sub_ = node_ptr_->create_subscription<irt_nav_msgs::msg::RTCML1E1>("/rtcmL1E1",
                                                                                     rclcpp::SensorDataQoS(),
                                                                                     [this](const irt_nav_msgs::msg::RTCML1E1::ConstSharedPtr msg) -> void
                                                                                     {
                                                                                         //RCLCPP_INFO(this->node_ptr_->get_logger(), "-------  On RTCMV3 L1E1 msg -------");
                                                                                         DD_RTCM_3_3_L1_E1_t rtcmdata = convertIRTMSGRTCML1E1(*msg);
                                                                                         //RCLCPP_INFO_STREAM(this->node_ptr_->get_logger(),  ss.str());
                                                                                         this->rtcm_buffer_.update_buffer(rtcmdata, rclcpp::Time(msg->header.stamp));
                                                                                     },
                                                                                     *commonSubOpt_);


          if(use_user_est_from_topic.value()) {
            user_estimation_sub_ = node_ptr_->create_subscription<std_msgs::msg::Float64MultiArray>("/user_estimation",
                                                                                                    rclcpp::SystemDefaultsQoS(),
                                                                                                    [this](
                                                                                                        const std_msgs::msg::Float64MultiArray::ConstSharedPtr msg) -> void {
                                                                                                        RCLCPP_DEBUG(
                                                                                                            node_ptr_->get_logger(),
                                                                                                            "Setting user estimations");

                                                                                                        static rclcpp::Time last_printed_time = node_ptr_->now();
                                                                                                        if((node_ptr_->now() - last_printed_time).seconds() > print_info_duration_)
                                                                                                        {
                                                                                                          RCLCPP_INFO(this->node_ptr_->get_logger(), "-------  On User Estimation msg -------");
                                                                                                          std::stringstream ss;
                                                                                                          for(const auto& s : msg->data)
                                                                                                            ss << std::to_string(s) << " : ";
                                                                                                          RCLCPP_INFO_STREAM(this->node_ptr_->get_logger(), "User Estimation: " << ss.str());
                                                                                                          last_printed_time = node_ptr_->now();
                                                                                                        }

                                                                                                        UserEstimation_T user_estimation{};
                                                                                                        std::copy_n(
                                                                                                            msg->data.begin(),
                                                                                                            7,
                                                                                                            user_estimation.begin());
                                                                                                        user_estimation_buffer_.update_buffer(
                                                                                                            user_estimation, rclcpp::Time(node_ptr_->now(), RCL_ROS_TIME));
                                                                                                    },
                                                                                                    *commonSubOpt_);
          } else {
            RCLCPP_WARN(node_ptr_->get_logger(), "No subscriber for user estimations, please set them manually!");
          }

        }

        void
        register_new_gnss_obs_callback(std::function<void(const irt_nav_msgs::msg::GNSSObsPreProcessed& msg)> cb)
        {
          this->signal_new_gnss_obs_.connect(cb);
        }

       GNSSMeasurementPreProcessed getGNSSObs(uint id = 0)
        {
          return !id ? gnss_obs_buffer_.get_last_buffer() : gnss_obs_buffer_.get_buffer(id);
        }

    };
}

#endif //IRT_GNSS_PREPROCESSING_GNSS_PREPROCESSOR_H
