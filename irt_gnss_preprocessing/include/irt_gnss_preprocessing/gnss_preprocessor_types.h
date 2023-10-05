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

//
// Created by haoming on 09.12.21.
//

#ifndef IRT_GNSS_PREPROCESSING_GNSS_PREPROCESSOR_TYPES_H
#define IRT_GNSS_PREPROCESSING_GNSS_PREPROCESSOR_TYPES_H
#pragma once

#include <rclcpp/rclcpp.hpp>
#include <rclcpp/time.hpp>
#include <rclcpp/duration.hpp>
#include <chrono>
#include <boost/circular_buffer.hpp>
//#ifdef USE_DUAL_ANTENNA
#include "gnss_tools/GNSSPreProcessingDualAntenna_ert_rtw/GNSSPreProcessingDualAntenna_types.h"
#include "gnss_tools/GNSSPreProcessingDualAntenna_ert_rtw/GNSSPreProcessingDualAntenna.h"
//#else
#include "gnss_tools/GNSSPreProcessingSingleAntenna_ert_rtw/GNSSPreProcessingSingleAntenna_types.h"
#include "gnss_tools/GNSSPreProcessingSingleAntenna_ert_rtw/GNSSPreProcessingSingleAntenna.h"
//#endif
#ifdef USE_GNSS_RTK_DD
#include "gnss_tools/DDRTCM_ert_rtw/DDRTCM.h"
#endif


namespace irt_gnss_preprocessing
{
    typedef std::lock_guard<std::mutex> MutexLockguard;
    typedef std::array<double, 7> UserEstimation_T;

    template <typename BufferType>
    struct CircularDataBuffer{
        boost::circular_buffer<BufferType> buffer;
        boost::circular_buffer<rclcpp::Time> time_buffer;
        boost::circular_buffer<double> duration_buffer;
        std::mutex mutex_;

        void resize_buffer(uint new_size)
        {
          MutexLockguard lock(mutex_);
          buffer.resize(new_size);
          time_buffer.resize(new_size);
          duration_buffer.resize(new_size);
          buffer_size = new_size;
        }
        void update_buffer(BufferType new_buffer, const rclcpp::Time& t_msg, const rclcpp::Time& t_now = rclcpp::Time()) {
          MutexLockguard lock(mutex_);
          buffer.push_back(new_buffer);
          counter ++;
          time_buffer.push_back(t_now);
          if (t_now.seconds() != 0)
          {
            duration_buffer.push_back((t_now - t_msg).nanoseconds() / 1e9);
          }
        }

        BufferType get_last_buffer() {
          MutexLockguard lock(mutex_);
          return buffer.back();
        }

        std::pair<BufferType, rclcpp::Time> get_last_buffer_with_time()
        {
          MutexLockguard lock(mutex_);
          return {buffer.back(), time_buffer.back()};
        }

        BufferType get_buffer(const rclcpp::Time& t){
          MutexLockguard lock(mutex_);
          std::vector<std::pair<uint64_T , BufferType>> buffer_map;

          for(uint i = 0; i < buffer_size; i++)
          {
            buffer_map.template emplace_back(std::make_pair((t - time_buffer[i], buffer[i])));
          }

          std::sort(buffer_map.begin(), buffer_map.end(), [](const std::pair<uint64_T, BufferType> &a,
                                                             const std::pair<uint64_T, BufferType> &b)
          {
            return a.first > b.first;
          });

          return buffer_map.back().second;
            // ToDo: to be implemented
        }

        BufferType get_buffer(uint id){
          MutexLockguard lock(mutex_);
          if (id > buffer.size())
          {
            std::cout << "Wrong Buffer ID: " << id << " last buffer is returned!" << std::endl;
            return get_last_buffer();
          }
          return buffer.at(id);
        }
        std::atomic<uint64_t> counter = 0;
        uint buffer_size = 3;
    };

    struct GNSSMeasurementPreProcessed
    {
        GNSSMeasurementFixed gnss_obs_ant_main{};
        real_T pseudorange[40];
        real_T deltarange[40];
        size_t num_meas_ant_main{};
        uint8_t integrity_flag_ant_main{};
        double time_offset_gal_gps{};
        bool is_ggto_valid{};
        bool ant_main_gps_corrected{};
        bool ant_main_gal_corrected{};
        uint8_t DD_idx_sync_ant_main{};
        std::array<double, 2> dop_ant_main{};
        std::array<uint16_t, 80> faulty_svid_ant_main{};
        std::map<uint16_t, double> diff_psr_corrections{};
#ifdef USE_DUAL_ANTENNA
        GNSSMeasurementFixed gnss_obs_ant_aux{};
        size_t num_meas_ant_aux{};
        bool ant_aux_gps_corrected{};
        bool ant_aux_gal_corrected{};
        GNSSMeasurementFixed gnss_obs_DD_dualantenna{};
        size_t num_meas_ant_dd_dualantenna{};
        std::array<uint16_t, 40> svid_carrier_used_DD_dualantenna{};
        uint8_t integrity_flag_ant_aux{};
        uint8_t DD_idx_sync_ant_aux{};
        std::array<double, 2> dop_ant_aux{};
        std::array<uint16_t, 80> faulty_svid_ant_aux{};
        uint8_t ref_sat_svid_gps_dual_antenna{};
        uint8_t ref_sat_svid_gal_dual_antenna{};

#endif
#ifdef USE_GNSS_TIME_DD
        GNSS_Measurement gnss_obs_DD_time{};
#endif

#ifdef USE_GNSS_RTK_DD
        GNSSMeasurementFixed gnss_obs_DD_rtk{};
        size_t num_meas_ant_dd_rtk{};
        std::array<uint16_t, 40> svid_carrier_used_DD_rtcm{};
        double DD_idx_sync_ant_rtk{};
        uint8_t ref_sat_svid_gps_rtk{};
        uint8_t ref_sat_svid_gal_rtk{};
#endif
        bool has_dualantenna{};
        bool has_dualantenna_DD{};
        bool has_rtk_DD{};
        bool has_rtk{};
    };

}

#ifndef DEFINED_TYPEDEF_FOR_gnssraw_pvt_geodetic_t_
#define DEFINED_TYPEDEF_FOR_gnssraw_pvt_geodetic_t_

struct gnssraw_pvt_geodetic_t
{
    real_T TOW;
    uint16_T WNc;
    uint8_T Mode;
    uint8_T Error;
    real_T phi;
    real32_T phi_var;
    real_T lambda;
    real32_T lambda_var;
    real_T h;
    real32_T h_var;
    real32_T Undulation;
    real_T Vn;
    real_T Ve;
    real_T Vu;
    real_T TrkGND;
    real_T COG;
    real32_T yaw;
    real32_T yaw_var;
    real32_T pitch_roll;
    real32_T pitch_roll_var;
    real_T RxClkBias;
    real_T RxClkBiasVar;
    real_T RxClkDrift;
    real_T RxClkDriftVar;
    uint8_T TimeSystem;
    uint8_T Datum;
    uint8_T NrSV;
    uint8_T NrSVUsed;
    uint8_T NrSVUsedL1;
    uint8_T NrSVUsedMulti;
    uint8_T WACorrInfo;
    uint16_T ReferenceID;
    uint16_T MeanCorrAge;
    uint32_T SignalInfo;
    uint8_T AlertFlag;
    uint8_T NrBases;
    uint16_T PPPInfo;
    boolean_T DoNotUseValues;
};
#endif

#ifndef DEFINED_TYPEDEF_FOR_SBF_PVTGeodetic_t_
#define DEFINED_TYPEDEF_FOR_SBF_PVTGeodetic_t_

struct SBF_PVTGeodetic_t
{
    real_T TOW;
    uint16_T WNc;
    uint8_T Mode;
    uint8_T Error;
    real_T phi;
    real32_T phi_sdr;
    real_T lambda;
    real32_T lambda_sdr;
    real_T h;
    real32_T h_sdr;
    real32_T Undulation;
    real32_T Vn;
    real32_T Ve;
    real32_T Vu;
    real32_T COG;
    real32_T Yaw;
    real32_T YawStd;
    real32_T PitchRoll;
    real32_T PitchRollStd;
    real_T RxClkBias;
    real32_T RxClkDrift;
    uint8_T TimeSystem;
    uint8_T Datum;
    uint8_T NrSV;
    uint8_T NrSVUsed;
    uint8_T NrSVUsedL1;
    uint8_T NrSVUsedMulti;
    uint8_T WACorrInfo;
    uint16_T ReferenceID;
    uint16_T MeanCorrAge;
    uint32_T SignalInfo;
    uint8_T AlertFlag;
    uint8_T NrBases;
    uint16_T PPPInfo;
    boolean_T DoNotUseValues;
};

#endif

#endif //DEFINED_TYPEDEF_FOR_gnssraw_pvt_geodetic_t_
