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

#ifndef IRT_GNSS_PREPROCESSING_UBLOX_F9P_PREPROCESSOR_H
#define IRT_GNSS_PREPROCESSING_UBLOX_F9P_PREPROCESSOR_H

#pragma once

#include <thread>
#include <iostream>
#include <condition_variable>
#include "ublox_common.h"

namespace irt_gnss_preprocessing
{
    using namespace irt_gnss_preprocessing::Ublox;
    class UbloxPreProcessor : public GNSSPreprocessor {
    private:
        rclcpp::Subscription<ublox_msgs::msg::NavPVT>::SharedPtr sub_nav_pvt_;
        rclcpp::Subscription<ublox_msgs::msg::NavRELPOSNED9>::SharedPtr sub_nav_rel_pos_;
        rclcpp::Subscription<ublox_msgs::msg::RxmSFRBX>::SharedPtr sub_rxm_sfrbx_;
        rclcpp::Subscription<ublox_msgs::msg::RxmRAWX>::SharedPtr sub_rxm_rawx_;
        rclcpp::Subscription<ublox_msgs::msg::NavORB>::SharedPtr sub_nav_orb_;
        rclcpp::Subscription<ublox_msgs::msg::NavCLOCK>::SharedPtr sub_nav_clock_;
        rclcpp::Subscription<ublox_msgs::msg::NavSIG>::SharedPtr sub_nav_sig_;
        rclcpp::Subscription<ublox_msgs::msg::NavTIMEGAL>::SharedPtr sub_nav_time_gal_;

        CircularDataBuffer<ublox_msgs::msg::NavPVT> buffer_nav_pvt_;
        CircularDataBuffer<ublox_msgs::msg::NavRELPOSNED9> buffer_nav_rel_pos_;
        CircularDataBuffer<ublox_msgs::msg::NavORB> buffer_nav_orb_;
        CircularDataBuffer<ublox_msgs::msg::NavCLOCK> buffer_nav_clock_;
        CircularDataBuffer<ublox_msgs::msg::NavSIG> buffer_nav_sig_;
        CircularDataBuffer<ublox_msgs::msg::NavTIMEGAL> buffer_nav_time_gal_;

        CircularDataBuffer<Ephem> ephem_gps_buffer_;
        CircularDataBuffer<Ephem> ephem_gal_buffer_;
        CircularDataBuffer<Ephem> ephem_bds_buffer_;
        CircularDataBuffer<GloEphem> ephem_glo_buffer_;

        std::condition_variable pvt_cv_;
        std::mutex pvt_mutex_;
        std::unique_ptr<std::thread> pvt_sync_thread_;

        irt_gnss_preprocessing::Ublox::UbloxCommon::UniquePtr ubx_common_{};

    private:
        void onUbloxNavPVTMsgCb(const ublox_msgs::msg::NavPVT::SharedPtr msg);
        void onUbloxNavRELPOSENEDMsgCb(const ublox_msgs::msg::NavRELPOSNED9::SharedPtr msg);
        void onUbloxRxmSFRBXMsgCb(const ublox_msgs::msg::RxmSFRBX::SharedPtr msg);
        void onUbloxRxmRAWxMsgCb(const ublox_msgs::msg::RxmRAWX::SharedPtr msg);
        void onUbloxNavORBMsgCb(const ublox_msgs::msg::NavORB::SharedPtr msg);
        void onUbloxNavCLOCKMsgCb(const ublox_msgs::msg::NavCLOCK::SharedPtr msg);
        void onUbloxNavSIGMsgCb(const ublox_msgs::msg::NavSIG::SharedPtr msg);
        void onUbloxNavTIMEGALMsgCb(const ublox_msgs::msg::NavTIMEGAL::SharedPtr msg);

        void updateGPSEphemBuffer(const EphemPtr& ephem);
        void updateGALEphemBuffer(const EphemPtr& ephem);


    public:
        void
        initialize(rclcpp::Node& node, const std::string& receiver_type) override;

        ~UbloxPreProcessor() override {
          pvt_sync_thread_->join();
        };

    };

}

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(irt_gnss_preprocessing::UbloxPreProcessor, irt_gnss_preprocessing::GNSSPreprocessor)
#endif

