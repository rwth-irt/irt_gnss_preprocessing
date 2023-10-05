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


#ifndef IRT_GNSS_PREPROCESSING_NOVATEL_OEM7_PREPROCESSOR_H
#define IRT_GNSS_PREPROCESSING_NOVATEL_OEM7_PREPROCESSOR_H

#pragma once

#include <rclcpp/rclcpp.hpp>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/sync_policies/exact_time.h>
#include <message_filters/subscriber.h>
#include <boost/circular_buffer.hpp>

#include "gnss_preprocessor.h"
//#include "gnss_tools/novatel/ConvertOEM7ToPvtGeodetic_ert_rtw/ConvertOEM7ToPvtGeodetic_types.h"
#include "gnss_tools/novatel/ConvertOEM7ToGalGstGpsBus_ert_rtw/ConvertOEM7ToGalGstGpsBus_types.h"
#include "gnss_tools/novatel/ConvertOEM7ToGalFnavBus_ert_rtw/ConvertOEM7ToGalFnavBus_types.h"
#include "gnss_tools/novatel/ConvertOEM7ToGalInavBus_ert_rtw/ConvertOEM7ToGalInavBus_types.h"
#include "gnss_tools/novatel/ConvertOEM7ToGalIonBus_ert_rtw/ConvertOEM7ToGalIonBus_types.h"
#include "gnss_tools/novatel/ConvertOEM7ToGpsNavBus_ert_rtw/ConvertOEM7ToGpsNavBus_types.h"
#include "gnss_tools/novatel/ConvertOEM7ToGpsIonBus_ert_rtw/ConvertOEM7ToGpsIonBus_types.h"
#include "gnss_tools/novatel/ConvertOEM7RangeToMeasEpochRAW_ert_rtw/ConvertOEM7RangeToMeasEpochRAW_types.h"
//gnsspreprocessor - header for oem7 to preprocessorinput
#include "gnss_tools/novatel/ConvertOEM7ToPvtGeodetic_ert_rtw/ConvertOEM7ToPvtGeodetic.h"
#include "gnss_tools/novatel/ConvertOEM7ToGalGstGpsBus_ert_rtw/ConvertOEM7ToGalGstGpsBus.h"
#include "gnss_tools/novatel/ConvertOEM7ToGalFnavBus_ert_rtw/ConvertOEM7ToGalFnavBus.h"
#include "gnss_tools/novatel/ConvertOEM7ToGalInavBus_ert_rtw/ConvertOEM7ToGalInavBus.h"
#include "gnss_tools/novatel/ConvertOEM7ToGalIonBus_ert_rtw/ConvertOEM7ToGalIonBus.h"
#include "gnss_tools/novatel/ConvertOEM7ToGpsNavBus_ert_rtw/ConvertOEM7ToGpsNavBus.h"
#include "gnss_tools/novatel/ConvertOEM7ToGpsIonBus_ert_rtw/ConvertOEM7ToGpsIonBus.h"
#include "gnss_tools/novatel/ConvertOEM7RangeToMeasEpochRAW_ert_rtw/ConvertOEM7RangeToMeasEpochRAW.h"
#include "gnss_tools/novatel/getSatInfoNovAtel_ert_rtw/getSatInfoNovAtel.h"


//novatel
#include <novatel_oem7_msgs/msg/bestpos.hpp>
#include <novatel_oem7_msgs/msg/bestvel.hpp>
#include <novatel_oem7_msgs/msg/clockmodel.hpp>
#include <novatel_oem7_msgs/msg/dualantennaheading.hpp>
#include <novatel_oem7_msgs/msg/galclock.hpp>
#include <novatel_oem7_msgs/msg/galfnavephemeris.hpp>
#include <novatel_oem7_msgs/msg/galinavephemeris.hpp>
#include <novatel_oem7_msgs/msg/galiono.hpp>
#include <novatel_oem7_msgs/msg/gpsephem.hpp>
#include <novatel_oem7_msgs/msg/ionutc.hpp>
#include <novatel_oem7_msgs/msg/range.hpp>
#include <novatel_oem7_msgs/msg/range_data.hpp>
#include <novatel_oem7_msgs/msg/oem7_header.hpp>
#include <novatel_oem7_msgs/msg/rxstatus.hpp>
#include <novatel_oem7_msgs/msg/time.hpp>
#include <novatel_oem7_msgs/msg/solution_source.hpp>
#include <novatel_oem7_msgs/msg/solution_status.hpp>
#include <novatel_oem7_msgs/msg/best_extended_solution_status.hpp>
#include <novatel_oem7_msgs/msg/navicsysclock.hpp>

#include "novatel_oem7_types.h"

namespace irt_gnss_preprocessing{

class NovatelOEM7PreProcessor : public GNSSPreprocessor {
private: // private ros variables
    typedef message_filters::sync_policies::ApproximateTime<novatel_oem7_msgs::msg::BESTPOS,
        novatel_oem7_msgs::msg::BESTVEL,
        novatel_oem7_msgs::msg::DUALANTENNAHEADING,
        novatel_oem7_msgs::msg::CLOCKMODEL> OEM7SolSyncPolicy;

    message_filters::Subscriber<novatel_oem7_msgs::msg::BESTPOS> bestpos_sub_;
    message_filters::Subscriber<novatel_oem7_msgs::msg::BESTVEL> bestvel_sub_;
    message_filters::Subscriber<novatel_oem7_msgs::msg::DUALANTENNAHEADING> heading_sub_;
    message_filters::Subscriber<novatel_oem7_msgs::msg::CLOCKMODEL> clockmodel_sub_;
    std::unique_ptr<message_filters::Synchronizer<OEM7SolSyncPolicy>> oem7_sol_sync_;

#if USE_DUAL_ANTENNA
    typedef message_filters::sync_policies::ApproximateTime<novatel_oem7_msgs::msg::RANGE,
                                                                novatel_oem7_msgs::msg::RANGE> OEM7DualRangeSyncPolicy;
        message_filters::Subscriber<novatel_oem7_msgs::msg::RANGE> range_main_sub_;
        message_filters::Subscriber<novatel_oem7_msgs::msg::RANGE> range_aux_sub_;
        std::unique_ptr<message_filters::Synchronizer<OEM7DualRangeSyncPolicy>> dual_range_sync_;
#else
    rclcpp::Subscription<novatel_oem7_msgs::msg::RANGE>::ConstSharedPtr range_main_sub_;
#endif
    rclcpp::Subscription<novatel_oem7_msgs::msg::GALFNAVEPHEMERIS>::SharedPtr gal_fnav_ephem_sub_;
    rclcpp::Subscription<novatel_oem7_msgs::msg::GALINAVEPHEMERIS>::SharedPtr gal_inav_ephem_sub_;
    rclcpp::Subscription<novatel_oem7_msgs::msg::GALCLOCK>::SharedPtr gal_clock_sub_;
    rclcpp::Subscription<novatel_oem7_msgs::msg::GALIONO>::SharedPtr gal_iono_sub_;

    rclcpp::Subscription<novatel_oem7_msgs::msg::TIME>::SharedPtr time_sub_;
    rclcpp::Subscription<novatel_oem7_msgs::msg::GPSEPHEM>::SharedPtr gps_ephem_sub_;
    rclcpp::Subscription<novatel_oem7_msgs::msg::IONUTC>::SharedPtr ionutc_sub_;
    rclcpp::Subscription<novatel_oem7_msgs::msg::RXSTATUS>::SharedPtr rxstatus_sub_;
    rclcpp::Subscription<novatel_oem7_msgs::msg::NAVICSYSCLOCK>::SharedPtr navicsysclock_sub_;

    //CircularDataBuffer<novatel_oem7_msgs::msg::GALFNAVEPHEMERIS> gal_fnav_ephem_buffer_;
    //CircularDataBuffer<novatel_oem7_msgs::msg::GALINAVEPHEMERIS> gal_inav_ephem_buffer_;
    CircularDataBuffer<novatel_oem7_msgs::msg::GALCLOCK> gal_clock_msg_buffer_;
    CircularDataBuffer<novatel_oem7_msgs::msg::GALIONO> gal_iono_msg_buffer_;
    CircularDataBuffer<novatel_oem7_msgs::msg::TIME> oem7_time_msg_buffer_;
    CircularDataBuffer<novatel_oem7_msgs::msg::RXSTATUS> oem7_rx_status_msg_buffer_;
    CircularDataBuffer<novatel_oem7_msgs::msg::IONUTC> ion_utc_msg_buffer_;
    //CircularDataBuffer<novatel_oem7_msgs::msg::GPSEPHEM> gps_ephem_buffer_;
    CircularDataBuffer<novatel_oem7_msgs::msg::NAVICSYSCLOCK> navicsysclock_msg_buffer_;
    CircularDataBuffer<novatel_oem7_msgs::msg::BESTPOS> best_pos_msg_buffer_;
    CircularDataBuffer<novatel_oem7_msgs::msg::BESTVEL> best_vel_msg_buffer_;
    CircularDataBuffer<novatel_oem7_msgs::msg::DUALANTENNAHEADING> heading_msg_buffer_;
    CircularDataBuffer<novatel_oem7_msgs::msg::CLOCKMODEL> clockmodel_msg_buffer_;

    // ToDo: in gnss_preprocessor.h
    CircularDataBuffer<HCS_Measurement> hcs_mesa_ant_main_buffer_;
    CircularDataBuffer<HCS_Measurement> hcs_mesa_ant_aux_buffer_;


private: // private functions
#if USE_DUAL_ANTENNA
    void onOEM7RangeMsgCb(const novatel_oem7_msgs::msg::RANGE::ConstSharedPtr range_main,
                              const novatel_oem7_msgs::msg::RANGE::ConstSharedPtr range_aux);
#else
    void onOEM7RangeMsgCb(const novatel_oem7_msgs::msg::RANGE::ConstSharedPtr range_main);
#endif

    /*
     *
     */
    void onOEM7SolutionMsgCb(const novatel_oem7_msgs::msg::BESTPOS::ConstSharedPtr bestpos,
                             const novatel_oem7_msgs::msg::BESTVEL::ConstSharedPtr bestvel,
                             const novatel_oem7_msgs::msg::DUALANTENNAHEADING::ConstSharedPtr heading,
                             const novatel_oem7_msgs::msg::CLOCKMODEL::ConstSharedPtr clockmodel);


    void test(double test)
    {
      /*
       * @param: test:
       */
    }

    void onOEM7GALFNavEphemMsgCb(const novatel_oem7_msgs::msg::GALFNAVEPHEMERIS::ConstSharedPtr gal_fnav_ephem);

    void onOEM7GALINavEphemMsgCb(const novatel_oem7_msgs::msg::GALINAVEPHEMERIS::ConstSharedPtr gal_inav_ephem);

    void onOEM7GALClockMsgCb(const novatel_oem7_msgs::msg::GALCLOCK::ConstSharedPtr gal_clock);

    void onOEM7GALIonoMsgCb(const novatel_oem7_msgs::msg::GALIONO::ConstSharedPtr gal_iono);

    void onOEM7GPSEphemMsgCb(const novatel_oem7_msgs::msg::GPSEPHEM::ConstSharedPtr gps_ephem);

    void onOEM7IONUTCMsgCb(const novatel_oem7_msgs::msg::IONUTC::ConstSharedPtr ionutc);

    void onOEM7RxStatusMsgCb(const novatel_oem7_msgs::msg::RXSTATUS::ConstSharedPtr rxstatus);

    void onOEM7TimeMsgCb(const novatel_oem7_msgs::msg::TIME::ConstSharedPtr oem_time);

public:
    void
    initialize(rclcpp::Node& node, const std::string& receiver_type) override;

private:  // private (inline) functions
    static inline OEM7_BestPos convertOEM7BestPosMsg(const novatel_oem7_msgs::msg::BESTPOS& msg)
    {
      OEM7_BestPos res{};
      res.header_week = msg.nov_header.gps_week_number;
      res.header_ms = msg.nov_header.gps_week_milliseconds;
      res.sol_stat = msg.sol_status.status;
      res.pos_type = msg.pos_type.type;
      res.lat = msg.lat;
      res.lon = msg.lon;
      res.hgt = msg.hgt;
      res.undulation = msg.undulation;
      res.datum_id_number = msg.datum_id;
      res.lat_sigma = msg.lat_stdev;
      res.lon_sigma = msg.lon_stdev;
      res.hgt_sigma = msg.hgt_stdev;
      std::copy(msg.stn_id.begin(), msg.stn_id.end(), res.stn_id);
      res.diff_age = msg.diff_age;
      res.sol_age = msg.sol_age;
      res.number_svs = msg.num_svs;
      res.number_soln_l1_svs = msg.num_sol_l1_svs;
      res.number_soln_multi_svs = msg.num_sol_multi_svs;
      res.Reserved = msg.reserved;
      res.number_soln_svs = msg.num_sol_svs;
      res.ext_sol_stat = msg.ext_sol_stat.status;
      res.galileo_and_beidou_sig_mask = msg.galileo_beidou_sig_mask;
      res.gps_and_glonass_sig_mask = msg.gps_glonass_sig_mask;
      return res;
    }

    static inline OEM7_BestVel convertOEM7BestVelMsg(const novatel_oem7_msgs::msg::BESTVEL& msg)
    {
      OEM7_BestVel res{};
      res.header_week = msg.nov_header.gps_week_number;
      res.header_ms = msg.nov_header.gps_week_milliseconds;
      res.sol_stat = msg.sol_status.status;
      res.vel_type = msg.vel_type.type;
      res.latency = msg.latency;
      res.age = msg.diff_age;
      res.hor_spd = msg.hor_speed;
      res.trk_gnd = msg.trk_gnd;
      res.vert_spd = msg.ver_speed;
      res.Reserved = msg.reserved;
      return res;
    }

    static inline OEM7_ClockModel convertOEM7ClockmodelMsg(const novatel_oem7_msgs::msg::CLOCKMODEL& msg)
    {
      OEM7_ClockModel res{};
      res.header_week = msg.nov_header.gps_week_number;
      res.header_ms = msg.nov_header.gps_week_milliseconds;
      res.status = msg.sol_status.status;
      res.reject_count = msg.reject_count;
      res.propagation_time = msg.propagation_time;
      res.update_time = msg.update_time;
      res.bias = msg.bias;
      res.bias_variance = msg.bias_variance;
      res.rate = msg.rate;
      res.rate_variance = msg.rate_variance;
      res.covariance = msg.covariance;
      res.Reserved1 = msg.reserved1;
      res.Reserved2 = msg.reserved2;
      res.Reserved3 = msg.reserved3;
      res.Reserved4 = msg.reserved4;
      res.Reserved5 = msg.reserved5;
      res.Reserved6 = msg.reserved6;
      res.Reserved7 = msg.reserved7;
      res.Reserved8 = msg.reserved8;
      res.instantaneous_bias = msg.instantaneous_bias;
      res.instantaneous_rate = msg.instantaneous_rate;
      return res;
    }

    static inline OEM7_DualAntennaHeading convertOEM7DualAntennaHeadingMsg(const novatel_oem7_msgs::msg::DUALANTENNAHEADING& msg){
      OEM7_DualAntennaHeading res{};
      res.header_week = msg.nov_header.gps_week_number;
      res.header_ms = msg.nov_header.gps_week_milliseconds;
      res.sol_stat = msg.sol_status.status;
      res.pos_type = msg.pos_type.type;
      res.length = msg.length;
      res.pitch = msg.pitch;
      res.Reserved = msg.reserved;
      res.heading = msg.heading;
      res.hdg_std_dev = msg.heading_std_dev;
      res.ptch_std_dev = msg.pitch_std_dev;
      std::copy(msg.rover_stn_id.begin(), msg.rover_stn_id.end(), res.stn_id);
      res.number_svs = msg.num_sv_tracked;
      res.number_obs = msg.num_sv_obs;
      res.number_soln_svs = msg.num_sv_in_sol;
      res.number_multi = msg.num_sv_multi;
      res.sol_source = msg.sol_source;
      res.ext_sol_stat = msg.ext_sol_status;
      res.galileo_and_beidou_sig_mask = msg.galileo_beidou_sig_mask;
      res.gps_and_glonass_sig_mask = msg.galileo_beidou_sig_mask;
      return res;
    }

    static inline OEM7_Range convertOEM7RangeMsg(const novatel_oem7_msgs::msg::RANGE& msg)
    {
      OEM7_Range res{};
      res.header_week = msg.nov_header.gps_week_number;
      res.header_ms = msg.nov_header.gps_week_milliseconds;
      res.number_obs = msg.number_obs;

      for(size_t t = 0; t < res.number_obs; t ++)
      {
        res.prn[t] = msg.ranges[t].prn;
        res.glofreq[t] = msg.ranges[t].glofreq;
        res.psr_sigma[t] = msg.ranges[t].psr_sigma;
        res.psr[t] = msg.ranges[t].psr;
        res.adr[t] = msg.ranges[t].adr;
        res.adr_sigma[t] = msg.ranges[t].adr_sigma;
        res.dopp[t] = msg.ranges[t].dopp;
        res.cn0[t] = msg.ranges[t].cn0;
        res.locktime[t] = msg.ranges[t].locktime;
        res.ch_tr_status[t] = msg.ranges[t].ch_tr_status;
      }
      return res;
    }

    static inline OEM7_GalIono convertOEM7GalIonoMsg(const novatel_oem7_msgs::msg::GALIONO& msg)
    {
      OEM7_GalIono res{};
      res.header_week = msg.nov_header.gps_week_number;
      res.header_ms = msg.nov_header.gps_week_milliseconds;
      res.Ai0 = msg.ai0;
      res.Ai1 = msg.ai1;
      res.Ai2 = msg.ai2;
      res.SF1 = msg.sf1;
      res.SF2 = msg.sf2;
      res.SF3 = msg.sf3;
      res.SF4 = msg.sf4;
      res.SF5 = msg.sf5;
      return res;
    }

    static inline OEM7_GalClock convertOEM7GalClockMsg(const novatel_oem7_msgs::msg::GALCLOCK& msg)
    {
      OEM7_GalClock res{};
      res.header_week = msg.nov_header.gps_week_number;
      res.header_ms = msg.nov_header.gps_week_milliseconds;
      res.A0 = msg.a0;
      res.A1 = msg.a1;
      res.DeltaTls = msg.delta_tls;
      res.Tot = msg.tot;
      res.WNt = msg.wnt;
      res.WNlsf = msg.wnlsf;
      res.DN = msg.dn;
      res.DeltaTlsf = msg.delta_tlsf;
      res.A0g = msg.a0g;
      res.A1g = msg.a1g;
      res.T0g = msg.t0g;
      res.WN0g = msg.wn0g;
      return res;
    }

    static inline OEM7_IonUtc convertOEM7IonUtcMsg(const novatel_oem7_msgs::msg::IONUTC& msg)
    {
      OEM7_IonUtc res{};
      res.header_week = msg.nov_header.gps_week_number;
      res.header_ms = msg.nov_header.gps_week_milliseconds;
      res.a0 = msg.a0;
      res.a1 = msg.a1;
      res.a2 = msg.a2;
      res.a3 = msg.a3;
      res.b0 = msg.b0;
      res.b1 = msg.b1;
      res.b2 = msg.b2;
      res.b3 = msg.b3;
      res.utc_wn = msg.utc_wn;
      res.tot = msg.tot;
      res.A0 = msg.capital_a0;
      res.A1 = msg.capital_a1;
      res.wn_lsf = msg.wn_lsf;
      res.dn = msg.dn;
      res.deltat_ls = msg.delta_tls;
      res.deltat_lsf = msg.delta_tlsg;
      res.Reserved = msg.reserved;
      return res;
    }

    /*
     *
     */
    static inline void printOEM7RxStatus(const novatel_oem7_msgs::msg::RXSTATUS& msg)
    {
      /*
       *
       */
      static auto last_published_time = std::chrono::system_clock::now();

      if(std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - last_published_time).count() > 5)
      {


      }
    }

private: //private gnss variables / objects


    OEM7_GalFnavEphemeris oem7_gal_fnav_ephem_buffer_{};
    std::mutex oem7_gal_fnav_ephem_buffer_mutex_;
    OEM7_GalInavEphemeris oem7_gal_inav_ephem_buffer_{};
    std::mutex oem7_gal_inav_ephem_buffer_mutex_;
    OEM7_GpsEphem oem7_gps_ephem_buffer_{};
    std::mutex oem7_gps_ephem_buffer_mutex_;

    /*
     *
     */
    std::unique_ptr<ConvertOEM7ToPvtGeodetic> oem7_to_pvt_geodetic_converter_;

    std::unique_ptr<ConvertOEM7ToGalFnavBus> oem7_to_gal_fnav_converter_;

    std::unique_ptr<ConvertOEM7ToGalInavBus> oem7_to_gal_inav_converter_;

    std::unique_ptr<ConvertOEM7ToGalIonBus> oem7_to_gal_iono_converter_;

    std::unique_ptr<ConvertOEM7ToGalGstGpsBus> oem7_to_galgstgps_converter_;

    std::unique_ptr<ConvertOEM7ToGpsNavBus> oem7_to_gps_nav_converter_;

    std::unique_ptr<ConvertOEM7ToGpsIonBus> oem7_to_gps_iono_converter_;

    std::unique_ptr<ConvertOEM7RangeToMeasEpochRAW> oem7_to_meas_epoch_converter_;

    std::unique_ptr<getSatInfoNovAtel> oem7_get_sat_info_;

};
}

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(irt_gnss_preprocessing::NovatelOEM7PreProcessor, irt_gnss_preprocessing::GNSSPreprocessor)
#endif //IRT_GNSS_PREPROCESSING_NOVATEL_OEM7_PREPROCESSOR_H
