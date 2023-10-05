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

#include <algorithm>
#include <functional>
#include "impl/ublox_f9p_preprocessor.h"

namespace irt_gnss_preprocessing
{
    void irt_gnss_preprocessing::UbloxPreProcessor::initialize(rclcpp::Node &node, const std::string &receiver_type) {
      node_ptr_ = &node;
      receiver_type_ = receiver_type;

      ubx_common_ = std::make_unique<irt_gnss_preprocessing::Ublox::UbloxCommon>();

      this->initializeCommons();

      gnss_preprocessor_ = std::make_unique<GNSSPreProcessingDualAntenna>();
      RosParameter<int> buffer_size("GNSSPreprocessor.default_buffer_size",
                                    5,
                                    *node_ptr_);

      buffer_nav_pvt_.resize_buffer(buffer_size.value());
      buffer_nav_rel_pos_.resize_buffer(buffer_size.value());
      buffer_nav_orb_.resize_buffer(buffer_size.value());
      buffer_nav_clock_.resize_buffer(buffer_size.value());
      buffer_nav_sig_.resize_buffer(buffer_size.value());
      buffer_nav_time_gal_.resize_buffer(buffer_size.value());
      ephem_gps_buffer_.resize_buffer(buffer_size.value());
      ephem_gal_buffer_.resize_buffer(buffer_size.value());
      ephem_bds_buffer_.resize_buffer(buffer_size.value());
      ephem_glo_buffer_.resize_buffer(buffer_size.value());

      sub_nav_pvt_ = node_ptr_->create_subscription<ublox_msgs::msg::NavPVT>(
          "/ublox/navpvt",
          rclcpp::SystemDefaultsQoS(),
          [this](const ublox_msgs::msg::NavPVT::SharedPtr msg)->void
          {
            this->onUbloxNavPVTMsgCb(msg);
          }
          );
      sub_nav_rel_pos_ = node_ptr_->create_subscription<ublox_msgs::msg::NavRELPOSNED9>(
          "/ublox/navrelposned",
          rclcpp::SystemDefaultsQoS(),
          [this](const ublox_msgs::msg::NavRELPOSNED9::SharedPtr msg)->void
          {
              this->onUbloxNavRELPOSENEDMsgCb(msg);
          }
          );

      sub_rxm_sfrbx_ = node_ptr_->create_subscription<ublox_msgs::msg::RxmSFRBX>(
          "/ublox/rxmsfrbx",
          rclcpp::SystemDefaultsQoS(),
          [this](const ublox_msgs::msg::RxmSFRBX::SharedPtr msg)->void
          {
              this->onUbloxRxmSFRBXMsgCb(msg);
          }
          );

      sub_rxm_rawx_ = node_ptr_->create_subscription<ublox_msgs::msg::RxmRAWX>(
          "/ublox/rxmrawx",
          rclcpp::SystemDefaultsQoS(),
          [this](const ublox_msgs::msg::RxmRAWX::SharedPtr msg)->void
          {
              this->onUbloxRxmRAWxMsgCb(msg);
          }
          );

      sub_nav_orb_ = node_ptr_->create_subscription<ublox_msgs::msg::NavORB>(
          "/ublox/navorb",
          rclcpp::SystemDefaultsQoS(),
          [this](const ublox_msgs::msg::NavORB::SharedPtr msg)->void
          {
              this->onUbloxNavORBMsgCb(msg);
          }
          );

      sub_nav_clock_ = node_ptr_->create_subscription<ublox_msgs::msg::NavCLOCK>(
          "/ublox/navclock",
          rclcpp::SystemDefaultsQoS(),
          [this](const ublox_msgs::msg::NavCLOCK::SharedPtr msg)->void
          {
              this->onUbloxNavCLOCKMsgCb(msg);
          }
          );

      node_ptr_->create_subscription<ublox_msgs::msg::NavSIG>(
          "/ublox/navsig",
          rclcpp::SystemDefaultsQoS(),
          [this](const ublox_msgs::msg::NavSIG::SharedPtr msg) -> void {
              this->onUbloxNavSIGMsgCb(msg);
          }
      );

      sub_nav_time_gal_ = node_ptr_->create_subscription<ublox_msgs::msg::NavTIMEGAL>(
          "/ublox/navtimegal",
          rclcpp::SystemDefaultsQoS(),
          [this](const ublox_msgs::msg::NavTIMEGAL::SharedPtr msg)->void
          {
              this->onUbloxNavTIMEGALMsgCb(msg);
          }
          );

      pvt_sync_thread_ = std::make_unique<std::thread>(
          [this]()->void
          {
            static uint32_t last_tow = 0;
            while(rclcpp::ok())
            {
              std::unique_lock<std::mutex> lg(pvt_mutex_);
              pvt_cv_.wait(lg, [&]{
                  auto navpvt = buffer_nav_pvt_.get_last_buffer();
                  auto navrelpos = buffer_nav_rel_pos_.get_last_buffer();
                  auto navclock = buffer_nav_clock_.get_last_buffer();
                  std::vector<uint32_t> tow_vector = {navpvt.i_tow, navrelpos.i_tow, navclock.i_tow};

                  if(std::all_of(tow_vector.begin(), tow_vector.end(), [&] (uint32_t i) {return i == tow_vector[0];}) &&
                     std::all_of(tow_vector.begin(), tow_vector.end(), [&] (uint32_t i) {return i > last_tow;}))
                  {
                    last_tow = navpvt.i_tow;
                    return true;
                  }else
                    return false;
              });

              auto [pvt, pvt_ts] = buffer_nav_pvt_.get_last_buffer_with_time();
              auto [relpos, relpos_ts] = buffer_nav_rel_pos_.get_last_buffer_with_time();
              auto [clock, clock_ts] = buffer_nav_clock_.get_last_buffer_with_time();

              gnssraw_pvt_geodetic_t pvt_sbf{};

              pvt_sbf.TOW = double(pvt.i_tow) * 0.001;
              pvt_sbf.WNc = 0;
              pvt_sbf.phi = double(pvt.lat) * 1e-7 * D2R;
              pvt_sbf.lambda = double(pvt.lon) * 1e-7 * D2R;
              pvt_sbf.h = double(pvt.h_msl) * 1e-3;
              pvt_sbf.h_var = double(pvt.v_acc) * 1e-3;
              pvt_sbf.lambda_var = pvt_sbf.phi_var = double(pvt.h_acc) * 1e-3;
              pvt_sbf.Ve = double(pvt.vel_e) * 1e-3;
              pvt_sbf.Vn = double(pvt.vel_n) * 1e-3;
              pvt_sbf.Vu = double(pvt.vel_d) * -1e-3;
              pvt_sbf.RxClkBias = double(clock.clk_b) * LIGHT_SPEED * 1e-9;
              pvt_sbf.RxClkBiasVar = double(clock.t_acc) * LIGHT_SPEED * 1e-9;
              pvt_sbf.RxClkDrift = double(clock.clk_d) * LIGHT_SPEED * 1e-9;
              


            }
          });
    }

    void UbloxPreProcessor::onUbloxRxmRAWxMsgCb(const ublox_msgs::msg::RxmRAWX::SharedPtr msg) {

      auto current_time = rclcpp::Time(node_ptr_->now(), RCL_ROS_TIME);
      auto current_tow = msg->rcv_tow;
      gnssraw_measurement_t meas{};
      auto obs_size = msg->num_meas;
      auto epoch = Ublox::RmxRAWX_to_UbloxMeasEpoch(msg, current_time.seconds());

      ubx_common_->set_curr_time(msg->week, msg->rcv_tow);

      std::vector<uint8_t> svids;

      for(const auto& obs : epoch.obs)
      {
        auto svids_pos = std::find(svids.begin(), svids.end(), obs.sv_id);
        if(svids_pos != svids.end())
          continue;
        svids.emplace_back(obs.sv_id);
      }

      meas.TOW = current_tow;
      meas.WNc = epoch.week_number;

      std::sort(svids.begin(), svids.end());

      for(size_t i = 0; i < svids.size(); i ++)
      {
        auto id = svids[i];
        std::vector<Ublox::UbloxObs> this_obs;
        for(const auto& obs : epoch.obs)
        {
          if(obs.gnss_id == Ublox::UbloxGNSSSys::Beidou ||
             obs.gnss_id == Ublox::UbloxGNSSSys::GLONASS||
              obs.gnss_id == Ublox::UbloxGNSSSys::QZSS)
            continue;

          if(obs.sig_id == 3 || obs.sig_id == 1)
            continue;

          if(obs.sv_id == id)
              this_obs.emplace_back(obs);
        }
        meas.SVID[i] = id;
        for(size_t j = 0; j < this_obs.size(); j++)
        {
          auto& o = this_obs[j];
          meas.Pseudorange[j + i * 40] = o.pr;
          meas.Pseudorange_Sigma[j + i * 40] = o.pr_stdev;
          meas.Doppler[j + i * 40] = o.dr;
          meas.Carrier[j + i * 40] = o.cp;
          meas.Carrier_Sigma[j + i * 40] = o.cp_stdev;
          meas.CN0[j + i * 40] = o.cn0;
          meas.Locktime[j + i * 40] = float(o.lock_time);
          meas.Type[j + i * 40] = o.sbf_freq_id;
        }
      }

      auto gps_ion = gps_ion_buffer_.get_last_buffer();
      auto gal_fnav = gal_fnav_ephemeris_buffer_.get_last_buffer();
      auto gal_ion = gal_ion_buffer_.get_last_buffer();
      auto rtcm = rtcm_buffer_.get_last_buffer();

      ExtU_GNSSPreProcessingSingleA_T input{

        /*
        meas,
        gps_nav_ephemeris_buffer_,
        gps_ion,
        gal_fnav,
        gal_ion,
        rtcm,
        {0, 0, 0},
        0,
        parameters_gnss_,
        parameters_integrity_,
        use_mode_switch_logic_,
        enable_gnss_merge_,
        enable_gnss_merge_
      */
      };






    }

    void UbloxPreProcessor::onUbloxRxmSFRBXMsgCb(const ublox_msgs::msg::RxmSFRBX::SharedPtr msg) {

      auto timestamp = rclcpp::Time(node_ptr_->now(), RCL_ROS_TIME);
      const auto prn = msg->sv_id;
      const auto gnss_id = msg->gnss_id;
      const auto num_words = msg->num_words;
      const auto chn = msg->chn;

      if(gnss_id == UbloxGNSSSys::GPS)
      {
        EphemPtr ephem = std::make_unique<Ephem>();
        if (!ubx_common_->decode_GPS_subframe(msg->dwrd, ephem))
        {
          // decode returns 0 == successfully decoded
          ephem->sat = prn;
          ephem->ttr.time = 0;
          ephem->timestamp = timestamp.seconds();
          ephem_gps_buffer_.update_buffer(*ephem, node_ptr_->now());
          updateGPSEphemBuffer(ephem);
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Ublox Updated GPS Ephemeris with tow: " << ephem->toe_tow);
        }
      }
      else if(gnss_id == UbloxGNSSSys::Galileo)
      {
        EphemPtr ephem = std::make_unique<Ephem>();
        if (!ubx_common_->decode_GAL_subframe(msg->dwrd, ephem))
        {
          // decode returns 0 == successfully decoded
          ephem->sat = prn;
          ephem->ttr.time = 0;
          ephem->timestamp = timestamp.seconds();
          ephem_gal_buffer_.update_buffer(*ephem, node_ptr_->now());
          updateGALEphemBuffer(ephem);
          RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Ublox Updated Galileo Ephemeris with tow: " << ephem->toe_tow);
        }
      }
      else
      {
        auto [sat_sys, freq_id_sbf, freq] = get_ublox_gnss_sys(gnss_id, 0);
        RCLCPP_WARN_STREAM(node_ptr_->get_logger(), "Ublox got subframe for unsupported gnss system: " << sat_sys);
      }
    }


    void UbloxPreProcessor::onUbloxNavORBMsgCb(const ublox_msgs::msg::NavORB::SharedPtr msg) {
      auto timestamp = rclcpp::Time(node_ptr_->now(), RCL_ROS_TIME);
      buffer_nav_orb_.update_buffer(*msg, timestamp);

    }

    void UbloxPreProcessor::onUbloxNavPVTMsgCb(const ublox_msgs::msg::NavPVT::SharedPtr msg){
      auto timestamp = rclcpp::Time(node_ptr_->now(), RCL_ROS_TIME);
      buffer_nav_pvt_.update_buffer(*msg, timestamp);

    }

    void UbloxPreProcessor::onUbloxNavRELPOSENEDMsgCb(const ublox_msgs::msg::NavRELPOSNED9::SharedPtr msg){
      auto timestamp = rclcpp::Time(node_ptr_->now(), RCL_ROS_TIME);
      buffer_nav_rel_pos_.update_buffer(*msg, timestamp);

    }

    void UbloxPreProcessor::onUbloxNavCLOCKMsgCb(const ublox_msgs::msg::NavCLOCK::SharedPtr msg){
      auto timestamp = rclcpp::Time(node_ptr_->now(), RCL_ROS_TIME);
      buffer_nav_clock_.update_buffer(*msg, timestamp);
    }

    void UbloxPreProcessor::onUbloxNavSIGMsgCb(const ublox_msgs::msg::NavSIG::SharedPtr msg){

      auto timestamp = rclcpp::Time(node_ptr_->now(), RCL_ROS_TIME);
      buffer_nav_sig_.update_buffer(*msg, timestamp);
    }

    void UbloxPreProcessor::onUbloxNavTIMEGALMsgCb(const ublox_msgs::msg::NavTIMEGAL::SharedPtr msg){
      auto timestamp = rclcpp::Time(node_ptr_->now(), RCL_ROS_TIME);
      buffer_nav_time_gal_.update_buffer(*msg, timestamp);
    }

    void UbloxPreProcessor::updateGPSEphemBuffer(const EphemPtr& ephem) {
      MutexLockguard lg(mutex_gps_ephem_);

      gps_nav_ephemeris_buffer_.TOW[ephem->sat - 1] = ephem->toe_tow;
      gps_nav_ephemeris_buffer_.WNc[ephem->sat - 1] = ephem->week;
      gps_nav_ephemeris_buffer_.SVID[ephem->sat - 1] = ephem->sat;
      gps_nav_ephemeris_buffer_.Health[ephem->sat - 1] = ephem->health;
      gps_nav_ephemeris_buffer_.IODC[ephem->sat - 1] = ephem->iodc;
      gps_nav_ephemeris_buffer_.IODE[ephem->sat - 1] = ephem->iode;
      gps_nav_ephemeris_buffer_.T_gd[ephem->sat - 1] = ephem->tgd[0] * RAD2SEMICIRCLES;
      gps_nav_ephemeris_buffer_.T_oc[ephem->sat - 1] = ephem->toc.time;
      gps_nav_ephemeris_buffer_.A_f0[ephem->sat - 1] = ephem->af0;
      gps_nav_ephemeris_buffer_.A_f1[ephem->sat - 1] = ephem->af1;
      gps_nav_ephemeris_buffer_.A_f2[ephem->sat - 1] = ephem->af2;
      gps_nav_ephemeris_buffer_.C_rs[ephem->sat - 1] = ephem->crs;
      gps_nav_ephemeris_buffer_.DELTA_N[ephem->sat - 1] = ephem->delta_n * RAD2SEMICIRCLES;
      gps_nav_ephemeris_buffer_.M_0[ephem->sat - 1] = ephem->M0 * RAD2SEMICIRCLES;
      gps_nav_ephemeris_buffer_.C_uc[ephem->sat - 1] = ephem->cuc;
      gps_nav_ephemeris_buffer_.E[ephem->sat - 1] = ephem->e;
      gps_nav_ephemeris_buffer_.C_us[ephem->sat - 1] = ephem->cus;
      gps_nav_ephemeris_buffer_.SQRT_A[ephem->sat - 1] = std::sqrt(ephem->A);
      gps_nav_ephemeris_buffer_.T_oe[ephem->sat - 1] = ephem->toe.time;
      gps_nav_ephemeris_buffer_.C_ic[ephem->sat - 1] = ephem->cic;
      gps_nav_ephemeris_buffer_.OMEGA_0[ephem->sat - 1] = ephem->OMG0 * RAD2SEMICIRCLES;
      gps_nav_ephemeris_buffer_.C_is[ephem->sat - 1] = ephem->cis;
      gps_nav_ephemeris_buffer_.I_0[ephem->sat - 1] = ephem->i0 * RAD2SEMICIRCLES;
      gps_nav_ephemeris_buffer_.C_rc[ephem->sat - 1] = ephem->crc;
      gps_nav_ephemeris_buffer_.omega[ephem->sat - 1] = ephem->omg * RAD2SEMICIRCLES;
      gps_nav_ephemeris_buffer_.OMEGADOT[ephem->sat - 1] = ephem->OMG_dot * RAD2SEMICIRCLES;
      gps_nav_ephemeris_buffer_.IDOT[ephem->sat - 1] = ephem->i_dot * RAD2SEMICIRCLES;
      gps_nav_ephemeris_buffer_.WNt_oc[ephem->sat - 1] = ephem->week;
      gps_nav_ephemeris_buffer_.WNt_oe[ephem->sat - 1] = ephem->week;
    }

    void UbloxPreProcessor::updateGALEphemBuffer(const EphemPtr &ephem) {
      MutexLockguard lg(mutex_gal_ephem_);
      gal_nav_ephemeris_buffer_.TOW[ephem->sat - 1] = ephem->toe_tow;
      gal_nav_ephemeris_buffer_.WNc[ephem->sat - 1] = ephem->week;
      gal_nav_ephemeris_buffer_.SVID[ephem->sat - 1] = ephem->sat + 70;
      gal_nav_ephemeris_buffer_.SQRT_A[ephem->sat - 1] = std::sqrt(ephem->A);
      gal_nav_ephemeris_buffer_.M_0[ephem->sat - 1] = ephem->M0 * RAD2SEMICIRCLES;
      gal_nav_ephemeris_buffer_.E[ephem->sat - 1] = ephem->e;
      gal_nav_ephemeris_buffer_.I_0[ephem->sat - 1] = ephem->i0 * RAD2SEMICIRCLES;
      gal_nav_ephemeris_buffer_.omega[ephem->sat - 1] = ephem->omg * RAD2SEMICIRCLES;
      gal_nav_ephemeris_buffer_.OMEGA_0[ephem->sat - 1] = ephem->OMG0 * RAD2SEMICIRCLES;
      gal_nav_ephemeris_buffer_.OMEGADOT[ephem->sat - 1] = ephem->OMG_dot * RAD2SEMICIRCLES;
      gal_nav_ephemeris_buffer_.IDOT[ephem->sat - 1] = ephem->i_dot * RAD2SEMICIRCLES;
      gal_nav_ephemeris_buffer_.DELTA_N[ephem->sat - 1] = ephem->delta_n * RAD2SEMICIRCLES;
      gal_nav_ephemeris_buffer_.C_uc[ephem->sat - 1] = ephem->cuc;
      gal_nav_ephemeris_buffer_.C_us[ephem->sat - 1] = ephem->cus;
      gal_nav_ephemeris_buffer_.C_uc[ephem->sat - 1] = ephem->cuc;
      gal_nav_ephemeris_buffer_.C_us[ephem->sat - 1] = ephem->cus;
      gal_nav_ephemeris_buffer_.C_rs[ephem->sat - 1] = ephem->crs;
      gal_nav_ephemeris_buffer_.C_ic[ephem->sat - 1] = ephem->cic;
      gal_nav_ephemeris_buffer_.C_is[ephem->sat - 1] = ephem->cis;
      gal_nav_ephemeris_buffer_.T_oc[ephem->sat - 1] = ephem->toc.time;
      gal_nav_ephemeris_buffer_.T_oe[ephem->sat - 1] = ephem->toe.time;
      gal_nav_ephemeris_buffer_.A_f0[ephem->sat - 1] = ephem->af0;
      gal_nav_ephemeris_buffer_.A_f1[ephem->sat - 1] = ephem->af1;
      gal_nav_ephemeris_buffer_.A_f2[ephem->sat - 1] = ephem->af2;
      gal_nav_ephemeris_buffer_.WNt_oc[ephem->sat - 1] = ephem->week;
      gal_nav_ephemeris_buffer_.WNt_oe[ephem->sat - 1] = ephem->week;
      gal_nav_ephemeris_buffer_.IODnav[ephem->sat - 1] = ephem->iodc;
    }


}