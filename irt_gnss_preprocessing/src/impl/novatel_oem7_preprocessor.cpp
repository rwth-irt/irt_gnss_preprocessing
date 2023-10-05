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

#include "impl/novatel_oem7_preprocessor.h"

namespace irt_gnss_preprocessing
{

  void
  NovatelOEM7PreProcessor::initialize(rclcpp::Node &node, const std::string &receiver_type)
  {
    node_ptr_ = &node;
    receiver_type_ = receiver_type;

    this->initializeCommons();

    RosParameter<int> buffer_size("GNSSPreprocessor.default_buffer_size",
                                  5,
                                  *node_ptr_);
    bestpos_sub_.subscribe(node_ptr_, "/novatel/oem7/bestpos");
    bestvel_sub_.subscribe(node_ptr_, "/novatel/oem7/bestvel");
    heading_sub_.subscribe(node_ptr_, "/novatel/oem7/dualantennaheading");
    clockmodel_sub_.subscribe(node_ptr_, "/novatel/oem7/clockmodel");

    gal_clock_msg_buffer_.resize_buffer(buffer_size.value());
    gal_iono_msg_buffer_.resize_buffer(buffer_size.value());
    oem7_time_msg_buffer_.resize_buffer(buffer_size.value());
    oem7_rx_status_msg_buffer_.resize_buffer(buffer_size.value());
    ion_utc_msg_buffer_.resize_buffer(buffer_size.value());
    // CircularDataBuffer<novatel_oem7_msgs::msg::GPSEPHEM> gps_ephem_buffer_;
    navicsysclock_msg_buffer_.resize_buffer(buffer_size.value());
    best_pos_msg_buffer_.resize_buffer(buffer_size.value());
    best_vel_msg_buffer_.resize_buffer(buffer_size.value());
    heading_msg_buffer_.resize_buffer(buffer_size.value());
    clockmodel_msg_buffer_.resize_buffer(buffer_size.value());

    // ToDo: in gnss_preprocessor.h
    CircularDataBuffer<HCS_Measurement> hcs_mesa_ant_main_buffer_;
    CircularDataBuffer<HCS_Measurement> hcs_mesa_ant_aux_buffer_;

    RosParameter<int>msg_lower_bound("GNSSPreprocessor.msg_lower_bound", 50000000, *node_ptr_);
    RosParameter<int>range_sync_queue_size("GNSSPreprocessor.range_sync_queue_size", 10, *node_ptr_);
    RosParameter<int>solution_sync_queue_size("GNSSPreprocessor.solution_sync_queue_size", 10, *node_ptr_);

    oem7_sol_sync_ = std::make_unique<message_filters::Synchronizer<OEM7SolSyncPolicy>>(OEM7SolSyncPolicy(solution_sync_queue_size.value()),
                                                                                        bestpos_sub_,
                                                                                        bestvel_sub_,
                                                                                        heading_sub_,
                                                                                        clockmodel_sub_);
    oem7_sol_sync_->setAgePenalty(0.);
    oem7_sol_sync_->registerCallback(
        std::bind(&NovatelOEM7PreProcessor::onOEM7SolutionMsgCb, this, _1, _2, _3, _4));
    oem7_sol_sync_->setInterMessageLowerBound(0, rclcpp::Duration(0, msg_lower_bound.value()));
    oem7_sol_sync_->setInterMessageLowerBound(1, rclcpp::Duration(0, msg_lower_bound.value()));
    oem7_sol_sync_->setInterMessageLowerBound(2, rclcpp::Duration(0, msg_lower_bound.value()));
    oem7_sol_sync_->setInterMessageLowerBound(3, rclcpp::Duration(0, msg_lower_bound.value()));

#if USE_DUAL_ANTENNA
    range_main_sub_.subscribe(node_ptr_, "/novatel/oem7/range");
    range_aux_sub_.subscribe(node_ptr_, "/novatel/oem7/range_aux");
    dual_range_sync_ = std::make_unique<message_filters::Synchronizer<OEM7DualRangeSyncPolicy>>(OEM7DualRangeSyncPolicy(range_sync_queue_size.value()),
                                                                                                range_main_sub_,
                                                                                                range_aux_sub_);
    dual_range_sync_->registerCallback(std::bind(&NovatelOEM7PreProcessor::onOEM7RangeMsgCb, this, _1, _2));
    dual_range_sync_->setAgePenalty(0.1);
    dual_range_sync_->setInterMessageLowerBound(0, rclcpp::Duration(0, 70000000));
    dual_range_sync_->setInterMessageLowerBound(1, rclcpp::Duration(0, 40000000));
    //dual_range_sync_->setMaxIntervalDuration(rclcpp::Duration(0, 2000000));
    gnss_preprocessor_ = std::make_unique<GNSSPreProcessingDualAntenna>();
    dd_dualantenna_preprocessor_ = std::make_unique<GNSSPreProcessingDualAntenna>();
    dd_dualantenna_preprocessor_->initialize();

#else
    range_main_sub_ = node_ptr_->create_subscription<novatel_oem7_msgs::msg::RANGE>("/novatel/oem7/range",
                                                                                    rclcpp::SystemDefaultsQoS(),
                                                                                    [this](
                                                                                        const novatel_oem7_msgs::msg::RANGE::ConstSharedPtr msg)
                                                                                    {
                                                                                      this->onOEM7RangeMsgCb(msg);
                                                                                    });
    gnss_preprocessor_ = std::make_unique<GNSS_preprocessingModelClass>();
#endif
    gnss_preprocessor_->initialize();

#if USE_GNSS_RTK_DD
    dd_rtcm_preprocessor_ = std::make_unique<DDRTCM>();
    dd_rtcm_preprocessor_->initialize();
#endif
    gal_fnav_ephem_sub_ = node_ptr_->create_subscription<novatel_oem7_msgs::msg::GALFNAVEPHEMERIS>("/novatel/oem7/galFnavEphemeris",
                                                                                                   rclcpp::SensorDataQoS(),
                                                                                                   [this](const novatel_oem7_msgs::msg::GALFNAVEPHEMERIS::ConstSharedPtr msg)
                                                                                                   {
                                                                                                     this->onOEM7GALFNavEphemMsgCb(msg);
                                                                                                   },
                                                                                                   *commonSubOpt_);

    gal_inav_ephem_sub_ = node_ptr_->create_subscription<novatel_oem7_msgs::msg::GALINAVEPHEMERIS>("/novatel/oem7/galInavEphemeris",
                                                                                                    rclcpp::SensorDataQoS(),
                                                                                                    [this](const novatel_oem7_msgs::msg::GALINAVEPHEMERIS::ConstSharedPtr msg)
                                                                                                    {
                                                                                                      this->onOEM7GALINavEphemMsgCb(msg);
                                                                                                    },
                                                                                                   *commonSubOpt_);

     gal_clock_sub_ = node_ptr_->create_subscription<novatel_oem7_msgs::msg::GALCLOCK>("/novatel/oem7/galclock",
                                                                                       rclcpp::SensorDataQoS(),
                                                                                       [this](
                                                                                           const novatel_oem7_msgs::msg::GALCLOCK::ConstSharedPtr msg)
                                                                                       {
                                                                                         this->onOEM7GALClockMsgCb(msg);
                                                                                       },
                                                                                       *commonSubOpt_);

     gal_iono_sub_ = node_ptr_->create_subscription<novatel_oem7_msgs::msg::GALIONO>("/novatel/oem7/galiono",
                                                                                     rclcpp::SensorDataQoS(),
                                                                                     [this](
                                                                                         const novatel_oem7_msgs::msg::GALIONO::ConstSharedPtr msg)
                                                                                     {
                                                                                       this->onOEM7GALIonoMsgCb(msg);
                                                                                     },
                                                                                     *commonSubOpt_);

     gps_ephem_sub_ = node_ptr_->create_subscription<novatel_oem7_msgs::msg::GPSEPHEM>("/novatel/oem7/gpsephem",
                                                                                       rclcpp::SensorDataQoS(),
                                                                                       [this](
                                                                                           const novatel_oem7_msgs::msg::GPSEPHEM::ConstSharedPtr msg)
                                                                                       {
                                                                                         this->onOEM7GPSEphemMsgCb(msg);
                                                                                       },
                                                                                       *commonSubOpt_);

     ionutc_sub_ = node_ptr_->create_subscription<novatel_oem7_msgs::msg::IONUTC>("/novatel/oem7/ionutc",
                                                                                  rclcpp::SensorDataQoS(),
                                                                                  [this](
                                                                                      const novatel_oem7_msgs::msg::IONUTC::ConstSharedPtr msg)
                                                                                  {
                                                                                    this->onOEM7IONUTCMsgCb(msg);
                                                                                  },
                                                                                  *commonSubOpt_);

     time_sub_ = node_ptr_->create_subscription<novatel_oem7_msgs::msg::TIME>("/novatel/oem7/time",
                                                                              rclcpp::SensorDataQoS(),
                                                                              [this](
                                                                                  const novatel_oem7_msgs::msg::TIME::ConstSharedPtr msg)
                                                                              {
                                                                                this->onOEM7TimeMsgCb(msg);
                                                                              },
                                                                              *commonSubOpt_);

     rxstatus_sub_ = node_ptr_->create_subscription<novatel_oem7_msgs::msg::RXSTATUS>("/novatel/oem7/rxstatus",
                                                                                      rclcpp::SensorDataQoS(),
                                                                                      [this](
                                                                                          const novatel_oem7_msgs::msg::RXSTATUS::ConstSharedPtr msg)
                                                                                      {
                                                                                        this->onOEM7RxStatusMsgCb(msg);
                                                                                      },
                                                                                      *commonSubOpt_);

     navicsysclock_sub_ = node_ptr_->create_subscription<novatel_oem7_msgs::msg::NAVICSYSCLOCK>("/novatel/oem7/navicsysclock",
                                                                                                rclcpp::SensorDataQoS(),

                                                                                                [this](const novatel_oem7_msgs::msg::NAVICSYSCLOCK::ConstSharedPtr msg) -> void
                                                                                                {
                                                                                                  navicsysclock_msg_buffer_.update_buffer(*msg, rclcpp::Time(msg->header.stamp));
                                                                                                },
                                                                                                *commonSubOpt_);
    oem7_to_pvt_geodetic_converter_ = std::make_unique<ConvertOEM7ToPvtGeodetic>();
    oem7_to_pvt_geodetic_converter_->initialize();
    oem7_to_meas_epoch_converter_ = std::make_unique<ConvertOEM7RangeToMeasEpochRAW>();
    oem7_to_meas_epoch_converter_->initialize();
    oem7_to_gal_fnav_converter_ = std::make_unique<ConvertOEM7ToGalFnavBus>();
    oem7_to_gal_fnav_converter_->initialize();
    oem7_to_gal_inav_converter_ = std::make_unique<ConvertOEM7ToGalInavBus>();
    oem7_to_gal_inav_converter_->initialize();
    oem7_to_gal_iono_converter_ = std::make_unique<ConvertOEM7ToGalIonBus>();
    oem7_to_gal_iono_converter_->initialize();
    oem7_to_galgstgps_converter_ = std::make_unique<ConvertOEM7ToGalGstGpsBus>();
    oem7_to_galgstgps_converter_->initialize();
    oem7_to_gps_iono_converter_ = std::make_unique<ConvertOEM7ToGpsIonBus>();
    oem7_to_gps_iono_converter_->initialize();
    oem7_to_gps_nav_converter_ = std::make_unique<ConvertOEM7ToGpsNavBus>();
    oem7_to_gps_nav_converter_->initialize();
    oem7_get_sat_info_ = std::make_unique<getSatInfoNovAtel>();
    oem7_get_sat_info_->initialize();
  }

  void
  NovatelOEM7PreProcessor::onOEM7SolutionMsgCb(const novatel_oem7_msgs::msg::BESTPOS::ConstSharedPtr bestpos,
                                               const novatel_oem7_msgs::msg::BESTVEL::ConstSharedPtr bestvel,
                                               const novatel_oem7_msgs::msg::DUALANTENNAHEADING::ConstSharedPtr heading,
                                               const novatel_oem7_msgs::msg::CLOCKMODEL::ConstSharedPtr clockmodel)
  {
    static auto last_printed_time = std::chrono::system_clock::now();

    RCLCPP_DEBUG(node_ptr_->get_logger(), "NovatelOEM7: Got OEM7 Solution Msg!");
    best_pos_msg_buffer_.update_buffer(*bestpos, rclcpp::Time(bestpos->header.stamp, RCL_ROS_TIME));
    best_vel_msg_buffer_.update_buffer(*bestvel, rclcpp::Time(bestvel->header.stamp, RCL_ROS_TIME));
    heading_msg_buffer_.update_buffer(*heading, rclcpp::Time(heading->header.stamp, RCL_ROS_TIME));
    clockmodel_msg_buffer_.update_buffer(*clockmodel, rclcpp::Time(clockmodel->header.stamp, RCL_ROS_TIME));
    ConvertOEM7ToPvtGeodetic::ExtU_ConvertOEM7ToPvtGeodetic_T oem7_to_pvt_geodetic_input = {convertOEM7BestPosMsg(*bestpos),
                                                                                                      convertOEM7BestVelMsg(*bestvel),
                                                                                                      convertOEM7ClockmodelMsg(*clockmodel),
                                                                                                      convertOEM7DualAntennaHeadingMsg(*heading),
                                                                                                      dual_antenna_heading_offset_};
    oem7_to_pvt_geodetic_converter_->setExternalInputs(&oem7_to_pvt_geodetic_input);
    oem7_to_pvt_geodetic_converter_->step();
    auto &oem7_to_pvt_geodetic_output = oem7_to_pvt_geodetic_converter_->getExternalOutputs();
    this->pvt_geodetic_buffer_.update_buffer(oem7_to_pvt_geodetic_output.PvtGeodeticBus, rclcpp::Time(bestpos->header.stamp, RCL_ROS_TIME), node_ptr_->now());

    if(pub_gnss_obs_) {
      irt_nav_msgs::msg::PVAGeodetic pvt_msg;
      pvt_msg.header.stamp = bestpos->header.stamp;
      pvt_msg.tow = oem7_to_pvt_geodetic_output.PvtGeodeticBus.TOW;
      pvt_msg.wnc = oem7_to_pvt_geodetic_output.PvtGeodeticBus.WNc;
      pvt_msg.mode = oem7_to_pvt_geodetic_output.PvtGeodeticBus.Mode;
      pvt_msg.error = oem7_to_pvt_geodetic_output.PvtGeodeticBus.Error;
      pvt_msg.phi_geo = oem7_to_pvt_geodetic_output.PvtGeodeticBus.phi;
      pvt_msg.phi_geo_var = oem7_to_pvt_geodetic_output.PvtGeodeticBus.phi_var;
      pvt_msg.lambda_geo = oem7_to_pvt_geodetic_output.PvtGeodeticBus.lambda;
      pvt_msg.lambda_geo_var = oem7_to_pvt_geodetic_output.PvtGeodeticBus.lambda_var;
      pvt_msg.h_geo = oem7_to_pvt_geodetic_output.PvtGeodeticBus.h;
      pvt_msg.h_geo_var = oem7_to_pvt_geodetic_output.PvtGeodeticBus.h_var;
      pvt_msg.undulation = oem7_to_pvt_geodetic_output.PvtGeodeticBus.Undulation;
      pvt_msg.vn = oem7_to_pvt_geodetic_output.PvtGeodeticBus.Vn;
      pvt_msg.ve = oem7_to_pvt_geodetic_output.PvtGeodeticBus.Ve;
      pvt_msg.vu = oem7_to_pvt_geodetic_output.PvtGeodeticBus.Vu;
      pvt_msg.cog = oem7_to_pvt_geodetic_output.PvtGeodeticBus.COG;
      pvt_msg.trk_gnd = oem7_to_pvt_geodetic_output.PvtGeodeticBus.TrkGND;
      pvt_msg.yaw = oem7_to_pvt_geodetic_output.PvtGeodeticBus.yaw;
      pvt_msg.yaw_var = oem7_to_pvt_geodetic_output.PvtGeodeticBus.yaw_var;
      pvt_msg.pitch_roll = oem7_to_pvt_geodetic_output.PvtGeodeticBus.pitch_roll;
      pvt_msg.pitch_roll_var = oem7_to_pvt_geodetic_output.PvtGeodeticBus.pitch_roll_var;
      pvt_msg.rx_clk_bias = oem7_to_pvt_geodetic_output.PvtGeodeticBus.RxClkBias;
      pvt_msg.rx_clk_drift = oem7_to_pvt_geodetic_output.PvtGeodeticBus.RxClkDrift;
      pvt_msg.rx_clk_bias_var = oem7_to_pvt_geodetic_output.PvtGeodeticBus.RxClkBiasVar;
      pvt_msg.rx_clk_drift_var = oem7_to_pvt_geodetic_output.PvtGeodeticBus.RxClkDriftVar;
      pvt_msg.time_system = oem7_to_pvt_geodetic_output.PvtGeodeticBus.TimeSystem;
      pvt_msg.datum = oem7_to_pvt_geodetic_output.PvtGeodeticBus.Datum;
      pvt_msg.nrsv = oem7_to_pvt_geodetic_output.PvtGeodeticBus.NrSV;
      pvt_msg.nrsv_used = oem7_to_pvt_geodetic_output.PvtGeodeticBus.NrSVUsed;
      pvt_msg.nrsv_used_with_l1 = oem7_to_pvt_geodetic_output.PvtGeodeticBus.NrSVUsedL1;
      pvt_msg.nrsv_used_multi = oem7_to_pvt_geodetic_output.PvtGeodeticBus.NrSVUsedMulti;
      pvt_msg.wa_corr_info = oem7_to_pvt_geodetic_output.PvtGeodeticBus.WACorrInfo;
      pvt_msg.reference_id = oem7_to_pvt_geodetic_output.PvtGeodeticBus.ReferenceID;
      pvt_msg.mean_corr_age = oem7_to_pvt_geodetic_output.PvtGeodeticBus.MeanCorrAge;
      pvt_msg.signal_info = oem7_to_pvt_geodetic_output.PvtGeodeticBus.SignalInfo;
      pvt_msg.alert_flag = oem7_to_pvt_geodetic_output.PvtGeodeticBus.AlertFlag;
      pvt_msg.nr_bases = oem7_to_pvt_geodetic_output.PvtGeodeticBus.NrBases;
      pvt_msg.ppp_info = oem7_to_pvt_geodetic_output.PvtGeodeticBus.PPPInfo;
      pvt_msg.do_not_use_this = oem7_to_pvt_geodetic_output.PvtGeodeticBus.DoNotUseValues;
      pvt_msg.sol_age = bestpos->sol_age;
      pvt_msg.diff_age = bestpos->diff_age;
      pvt_pub_->publish(pvt_msg);
    }

    if(std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - last_printed_time).count() > print_info_duration_) {

      RCLCPP_DEBUG(node_ptr_->get_logger(), "NovAtelOEM7 Solution");
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "------- NovAtelOEM7 Solution: --------");
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Solution Computed: " << (bestpos->sol_status.status == 0 ? "YES" : "NO"));
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Position Type: " << NovAtelOEM7::getOEM7PosType(bestpos->pos_type.type));
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Lat: " << bestpos->lat);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Lat Std: " << bestpos->lat_stdev);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Lon: " << bestpos->lon);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Lon Std: " << bestpos->lon_stdev);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Alt: " << bestpos->hgt);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Alt Std: " << std::to_string(bestpos->hgt_stdev));
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Heading [deg.]: " << oem7_to_pvt_geodetic_output.PvtGeodeticBus.yaw);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Num. SVs: " << std::to_string(bestpos->num_svs));
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Num. Sol. Svs: " << std::to_string(bestpos->num_sol_svs));
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Num. Sol. L1 Svs : " << std::to_string(bestpos->num_sol_l1_svs));
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Num. Sol. Multi. Svs: " << std::to_string(bestpos->num_sol_multi_svs));
      //RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Lat: " << bestpos->lat);
      //RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Lat: " << bestpos->lat);
      //RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Lat: " << bestpos->lat);
      //RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Lat: " << bestpos->lat);
      last_printed_time = std::chrono::system_clock::now();
    }
  }

  void
  NovatelOEM7PreProcessor::onOEM7GALFNavEphemMsgCb(
      const novatel_oem7_msgs::msg::GALFNAVEPHEMERIS::ConstSharedPtr gal_fnav_ephem)
  {
    //RCLCPP_INFO(this->node_ptr_->get_logger(), "-------  On GALFNAVEPHEMERIS msg -------");
    //RCLCPP_INFO_STREAM(this->node_ptr_->get_logger(), "GALFNAVEPHEMERIS SVID: " << unsigned(gal_fnav_ephem->sat_id));

    // gal_fnav_ephem_buffer_.update_buffer(*gal_fnav_ephem);
    uint32_t sat_id = gal_fnav_ephem->sat_id;
    MutexLockguard lg(oem7_gal_fnav_ephem_buffer_mutex_);
    oem7_gal_fnav_ephem_buffer_.header_ms[sat_id - 1] = gal_fnav_ephem->nov_header.gps_week_milliseconds;
    oem7_gal_fnav_ephem_buffer_.header_week[sat_id - 1] = gal_fnav_ephem->nov_header.gps_week_number;
    oem7_gal_fnav_ephem_buffer_.SatId[sat_id - 1] = gal_fnav_ephem->sat_id;
    oem7_gal_fnav_ephem_buffer_.Reserved1[sat_id - 1] = gal_fnav_ephem->reserved1;
    oem7_gal_fnav_ephem_buffer_.E5aHealth[sat_id - 1] = gal_fnav_ephem->e5a_health;
    oem7_gal_fnav_ephem_buffer_.E5aDVS[sat_id - 1] = gal_fnav_ephem->e5a_dvs;
    oem7_gal_fnav_ephem_buffer_.Reserved2[sat_id - 1] = gal_fnav_ephem->reserved2;
    oem7_gal_fnav_ephem_buffer_.Reserved3[sat_id - 1] = gal_fnav_ephem->reserved3;
    oem7_gal_fnav_ephem_buffer_.IODnav[sat_id - 1] = gal_fnav_ephem->iod_nav;
    oem7_gal_fnav_ephem_buffer_.SISA_Index[sat_id - 1] = gal_fnav_ephem->sisa_index;
    oem7_gal_fnav_ephem_buffer_.T0e[sat_id - 1] = gal_fnav_ephem->t0e;
    oem7_gal_fnav_ephem_buffer_.T0c[sat_id - 1] = gal_fnav_ephem->t0c;
    oem7_gal_fnav_ephem_buffer_.M0[sat_id - 1] = gal_fnav_ephem->m0;
    oem7_gal_fnav_ephem_buffer_.DeltaN[sat_id - 1] = gal_fnav_ephem->delta_n;
    oem7_gal_fnav_ephem_buffer_.Ecc[sat_id - 1] = gal_fnav_ephem->ecc;
    oem7_gal_fnav_ephem_buffer_.RootA[sat_id - 1] = gal_fnav_ephem->root_a;
    oem7_gal_fnav_ephem_buffer_.I0[sat_id - 1] = gal_fnav_ephem->i0;
    oem7_gal_fnav_ephem_buffer_.IDot[sat_id - 1] = gal_fnav_ephem->iod_nav;
    oem7_gal_fnav_ephem_buffer_.Omega0[sat_id - 1] = gal_fnav_ephem->omega0;
    oem7_gal_fnav_ephem_buffer_.Omega[sat_id - 1] = gal_fnav_ephem->omega;
    oem7_gal_fnav_ephem_buffer_.OmegaDot[sat_id - 1] = gal_fnav_ephem->omega_dot;
    oem7_gal_fnav_ephem_buffer_.Cuc[sat_id - 1] = gal_fnav_ephem->cuc;
    oem7_gal_fnav_ephem_buffer_.Cus[sat_id - 1] = gal_fnav_ephem->cus;
    oem7_gal_fnav_ephem_buffer_.Crc[sat_id - 1] = gal_fnav_ephem->crc;
    oem7_gal_fnav_ephem_buffer_.Crs[sat_id - 1] = gal_fnav_ephem->crs;
    oem7_gal_fnav_ephem_buffer_.Cic[sat_id - 1] = gal_fnav_ephem->cic;
    oem7_gal_fnav_ephem_buffer_.Cis[sat_id - 1] = gal_fnav_ephem->cis;
    oem7_gal_fnav_ephem_buffer_.Af0[sat_id - 1] = gal_fnav_ephem->af0;
    oem7_gal_fnav_ephem_buffer_.Af1[sat_id - 1] = gal_fnav_ephem->af1;
    oem7_gal_fnav_ephem_buffer_.Af2[sat_id - 1] = gal_fnav_ephem->af2;
    oem7_gal_fnav_ephem_buffer_.E1E5aBGD[sat_id - 1] = gal_fnav_ephem->e1e5a_bgd;

    ConvertOEM7ToGalFnavBus::ExtU_ConvertOEM7ToGalFnavBus_T gal_fnav_input = {oem7_gal_fnav_ephem_buffer_};
    oem7_to_gal_fnav_converter_->setExternalInputs(&gal_fnav_input);
    oem7_to_gal_fnav_converter_->step();
    ConvertOEM7ToGalFnavBus::ExtY_ConvertOEM7ToGalFnavBus_T gal_fnav_output = oem7_to_gal_fnav_converter_->getExternalOutputs();
    this->gal_fnav_ephemeris_buffer_.update_buffer(gal_fnav_output.GalFnavBus, rclcpp::Time(gal_fnav_ephem->header.stamp), node_ptr_->now());

  }

  void
  NovatelOEM7PreProcessor::onOEM7GALINavEphemMsgCb(
      const novatel_oem7_msgs::msg::GALINAVEPHEMERIS::ConstSharedPtr gal_inav_ephem)
  {
    //RCLCPP_INFO(this->node_ptr_->get_logger(), "-------  On GALINAVEPHEMERIS msg -------");
    //RCLCPP_INFO_STREAM(this->node_ptr_->get_logger(), "GALINAVEPHEMERIS SVID: " << unsigned(gal_inav_ephem->sat_id));
    // gal_inav_ephem_buffer_.update_buffer(*gal_inav_ephem);
    uint32_t sat_id = gal_inav_ephem->sat_id;
    MutexLockguard lg(oem7_gal_inav_ephem_buffer_mutex_);
    oem7_gal_inav_ephem_buffer_.SatId[sat_id - 1] = gal_inav_ephem->sat_id;
    oem7_gal_inav_ephem_buffer_.header_week[sat_id - 1] = gal_inav_ephem->nov_header.gps_week_number;
    oem7_gal_inav_ephem_buffer_.header_ms[sat_id - 1] = gal_inav_ephem->nov_header.gps_week_milliseconds;
    oem7_gal_inav_ephem_buffer_.E5bHealth[sat_id - 1] = gal_inav_ephem->e5b_health;
    oem7_gal_inav_ephem_buffer_.E5bDVS[sat_id - 1] = gal_inav_ephem->e5b_dvs;
    oem7_gal_inav_ephem_buffer_.Reserved1[sat_id - 1] = gal_inav_ephem->reserved1;
    oem7_gal_inav_ephem_buffer_.Reserved2[sat_id - 1] = gal_inav_ephem->reserved2;
    oem7_gal_inav_ephem_buffer_.Reserved3[sat_id - 1] = gal_inav_ephem->reserved3;
    oem7_gal_inav_ephem_buffer_.Reserved4[sat_id - 1] = gal_inav_ephem->reserved4;
    oem7_gal_inav_ephem_buffer_.E1bHealth[sat_id - 1] = gal_inav_ephem->e1b_health;
    oem7_gal_inav_ephem_buffer_.E1bDVS[sat_id - 1] = gal_inav_ephem->e1b_dvs;
    oem7_gal_inav_ephem_buffer_.IODnav[sat_id - 1] = gal_inav_ephem->io_dnav;
    oem7_gal_inav_ephem_buffer_.SISA_Index[sat_id - 1] = gal_inav_ephem->sisa_index;
    oem7_gal_inav_ephem_buffer_.INAV_Source[sat_id - 1] = gal_inav_ephem->inav_source;
    oem7_gal_inav_ephem_buffer_.T0e[sat_id - 1] = gal_inav_ephem->t0e;
    oem7_gal_inav_ephem_buffer_.T0c[sat_id - 1] = gal_inav_ephem->t0c;
    oem7_gal_inav_ephem_buffer_.M0[sat_id - 1] = gal_inav_ephem->m0;
    oem7_gal_inav_ephem_buffer_.DeltaN[sat_id - 1] = gal_inav_ephem->delta_n;
    oem7_gal_inav_ephem_buffer_.Ecc[sat_id - 1] = gal_inav_ephem->ecc;
    oem7_gal_inav_ephem_buffer_.RootA[sat_id - 1] = gal_inav_ephem->root_a;
    oem7_gal_inav_ephem_buffer_.I0[sat_id - 1] = gal_inav_ephem->i0;
    oem7_gal_inav_ephem_buffer_.IDot[sat_id - 1] = gal_inav_ephem->i_dot;
    oem7_gal_inav_ephem_buffer_.Omega0[sat_id - 1] = gal_inav_ephem->omega0;
    oem7_gal_inav_ephem_buffer_.Omega[sat_id - 1] = gal_inav_ephem->omega;
    oem7_gal_inav_ephem_buffer_.OmegaDot[sat_id - 1] = gal_inav_ephem->omega_dot;
    oem7_gal_inav_ephem_buffer_.Cuc[sat_id - 1] = gal_inav_ephem->cuc;
    oem7_gal_inav_ephem_buffer_.Cus[sat_id - 1] = gal_inav_ephem->cus;
    oem7_gal_inav_ephem_buffer_.Crc[sat_id - 1] = gal_inav_ephem->crc;
    oem7_gal_inav_ephem_buffer_.Crs[sat_id - 1] = gal_inav_ephem->crs;
    oem7_gal_inav_ephem_buffer_.Cic[sat_id - 1] = gal_inav_ephem->cic;
    oem7_gal_inav_ephem_buffer_.Cis[sat_id - 1] = gal_inav_ephem->cis;
    oem7_gal_inav_ephem_buffer_.Af0[sat_id - 1] = gal_inav_ephem->af0;
    oem7_gal_inav_ephem_buffer_.Af1[sat_id - 1] = gal_inav_ephem->af1;
    oem7_gal_inav_ephem_buffer_.Af2[sat_id - 1] = gal_inav_ephem->af2;
    oem7_gal_inav_ephem_buffer_.E1E5aBGD[sat_id - 1] = gal_inav_ephem->e1e5a_bgd;
    oem7_gal_inav_ephem_buffer_.E1E5bBGD[sat_id - 1] = gal_inav_ephem->e1e5b_bgd;

    ConvertOEM7ToGalInavBus::ExtU_ConvertOEM7ToGalInavBus_T gal_inav_input = {oem7_gal_inav_ephem_buffer_};
    oem7_to_gal_inav_converter_->setExternalInputs(&gal_inav_input);
    oem7_to_gal_inav_converter_->step();
    ConvertOEM7ToGalInavBus::ExtY_ConvertOEM7ToGalInavBus_T gal_inav_output = oem7_to_gal_inav_converter_->getExternalOutputs();
    this->gal_inav_ephemeris_buffer_.update_buffer(gal_inav_output.GalInavBus, rclcpp::Time(gal_inav_ephem->header.stamp, RCL_ROS_TIME), node_ptr_->now());
    gal_nav_ephemeris_buffer_ = gal_inav_output.GalInavBus;
  }

  void
  NovatelOEM7PreProcessor::onOEM7GALClockMsgCb(const novatel_oem7_msgs::msg::GALCLOCK::ConstSharedPtr gal_clock)
  {
    //RCLCPP_INFO(this->node_ptr_->get_logger(), "-------  On onOEM7GALClock msg -------");
    gal_clock_msg_buffer_.update_buffer(*gal_clock, rclcpp::Time(gal_clock->header.stamp));

    ConvertOEM7ToGalGstGpsBus::ExtU_ConvertOEM7ToGalGstGpsBu_T gal_clock_input = {convertOEM7GalClockMsg(*gal_clock)};
    oem7_to_galgstgps_converter_->setExternalInputs(&gal_clock_input);
    oem7_to_galgstgps_converter_->step();
    ConvertOEM7ToGalGstGpsBus::ExtY_ConvertOEM7ToGalGstGpsBu_T gal_clock_output = oem7_to_galgstgps_converter_->getExternalOutputs();
    this->gal_gst_gps_buffer_.update_buffer(gal_clock_output.GalGstGpsBus, rclcpp::Time(gal_clock->header.stamp), node_ptr_->now());
  }

  void
  NovatelOEM7PreProcessor::onOEM7GALIonoMsgCb(const novatel_oem7_msgs::msg::GALIONO::ConstSharedPtr gal_iono)
  {
    //RCLCPP_INFO(node_ptr_->get_logger(), "On GALIONO Msg ...");
    gal_iono_msg_buffer_.update_buffer(*gal_iono, rclcpp::Time(gal_iono->header.stamp));
    ConvertOEM7ToGalIonBus::ExtU_ConvertOEM7ToGalIonBus_T gal_iono_input = {convertOEM7GalIonoMsg(*gal_iono)};
    oem7_to_gal_iono_converter_->setExternalInputs(&gal_iono_input);
    oem7_to_gal_iono_converter_->step();
    ConvertOEM7ToGalIonBus::ExtY_ConvertOEM7ToGalIonBus_T gal_iono_output = oem7_to_gal_iono_converter_->getExternalOutputs();
    this->gal_ion_buffer_.update_buffer(gal_iono_output.GalIonBus, rclcpp::Time(gal_iono->header.stamp), node_ptr_->now());
  }

  void
  NovatelOEM7PreProcessor::onOEM7GPSEphemMsgCb(const novatel_oem7_msgs::msg::GPSEPHEM::ConstSharedPtr gps_ephem)
  {
    //RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "NovatelOEM7: Got GPSEPHEM Msg! sat_id:" << unsigned(gps_ephem->prn));
    uint32_t sat_id = gps_ephem->prn;
    MutexLockguard lg(oem7_gps_ephem_buffer_mutex_);
    oem7_gps_ephem_buffer_.header_ms[sat_id - 1] = gps_ephem->nov_header.gps_week_milliseconds;
    oem7_gps_ephem_buffer_.header_week[sat_id - 1] = gps_ephem->nov_header.gps_week_number;
    oem7_gps_ephem_buffer_.PRN[sat_id - 1] = sat_id;
    oem7_gps_ephem_buffer_.health[sat_id - 1] = gps_ephem->health;
    oem7_gps_ephem_buffer_.IODC[sat_id - 1] = gps_ephem->iodc;
    oem7_gps_ephem_buffer_.IODE2[sat_id - 1] = gps_ephem->iode2;
    oem7_gps_ephem_buffer_.tgd[sat_id - 1] = gps_ephem->tgd;
    oem7_gps_ephem_buffer_.T0c[sat_id - 1] = gps_ephem->toc;
    oem7_gps_ephem_buffer_.Af0[sat_id - 1] = gps_ephem->af0;
    oem7_gps_ephem_buffer_.Af1[sat_id - 1] = gps_ephem->af1;
    oem7_gps_ephem_buffer_.Af2[sat_id - 1] = gps_ephem->af2;
    oem7_gps_ephem_buffer_.Crs[sat_id - 1] = gps_ephem->crs;
    oem7_gps_ephem_buffer_.DeltaN[sat_id - 1] = gps_ephem->delta_n;
    oem7_gps_ephem_buffer_.M0[sat_id - 1] = gps_ephem->m0;
    oem7_gps_ephem_buffer_.Cuc[sat_id - 1] = gps_ephem->cuc;
    oem7_gps_ephem_buffer_.Ecc[sat_id - 1] = gps_ephem->ecc;
    oem7_gps_ephem_buffer_.Cus[sat_id - 1] = gps_ephem->cus;
    oem7_gps_ephem_buffer_.A[sat_id - 1] = gps_ephem->a;
    oem7_gps_ephem_buffer_.T0e[sat_id - 1] = gps_ephem->t0e;
    oem7_gps_ephem_buffer_.Cic[sat_id - 1] = gps_ephem->cic;
    oem7_gps_ephem_buffer_.Omega0[sat_id - 1] = gps_ephem->omega0;
    oem7_gps_ephem_buffer_.Cis[sat_id - 1] = gps_ephem->cis;
    oem7_gps_ephem_buffer_.I0[sat_id - 1] = gps_ephem->i0;
    oem7_gps_ephem_buffer_.Crc[sat_id - 1] = gps_ephem->crc;
    oem7_gps_ephem_buffer_.Omega[sat_id - 1] = gps_ephem->omega;
    oem7_gps_ephem_buffer_.OmegaDot[sat_id - 1] = gps_ephem->omega_dot;
    oem7_gps_ephem_buffer_.IDot[sat_id - 1] = gps_ephem->i_dot;
    oem7_gps_ephem_buffer_.tow[sat_id - 1] = gps_ephem->tow;
    oem7_gps_ephem_buffer_.IODE1[sat_id - 1] = gps_ephem->iode1;
    oem7_gps_ephem_buffer_.week[sat_id - 1] = gps_ephem->week;
    oem7_gps_ephem_buffer_.z_week[sat_id - 1] = gps_ephem->z_week;
    oem7_gps_ephem_buffer_.AS[sat_id - 1] = gps_ephem->a_s;
    oem7_gps_ephem_buffer_.N[sat_id - 1] = gps_ephem->n;
    oem7_gps_ephem_buffer_.URA[sat_id - 1] = gps_ephem->ura;

    ConvertOEM7ToGpsNavBus::ExtU_ConvertOEM7ToGpsNavBus_T input_{};
    input_.Oem7GpsEphemBus = oem7_gps_ephem_buffer_;
    oem7_to_gps_nav_converter_->setExternalInputs(&input_);
    oem7_to_gps_nav_converter_->step();
    ConvertOEM7ToGpsNavBus::ExtY_ConvertOEM7ToGpsNavBus_T output_ = oem7_to_gps_nav_converter_->getExternalOutputs();
    this->gps_nav_ephemeris_buffer_ = output_.GpsNavBus;
  }

  void
  NovatelOEM7PreProcessor::onOEM7IONUTCMsgCb(const novatel_oem7_msgs::msg::IONUTC::ConstSharedPtr ionutc)
  {
    //RCLCPP_INFO(node_ptr_->get_logger(), "On IONUTC Msg ...");
    ion_utc_msg_buffer_.update_buffer(*ionutc, rclcpp::Time(ionutc->header.stamp));

    ConvertOEM7ToGpsIonBus::ExtU_ConvertOEM7ToGpsIonBus_T input_ = {convertOEM7IonUtcMsg(*ionutc)};
    oem7_to_gps_iono_converter_->setExternalInputs(&input_);
    oem7_to_gps_iono_converter_->step();
    ConvertOEM7ToGpsIonBus::ExtY_ConvertOEM7ToGpsIonBus_T output_ = oem7_to_gps_iono_converter_->getExternalOutputs();
    gps_ion_buffer_.update_buffer(output_.GpsIonBus, rclcpp::Time(ionutc->header.stamp), node_ptr_->now());

  }

  void
  NovatelOEM7PreProcessor::onOEM7RxStatusMsgCb(const novatel_oem7_msgs::msg::RXSTATUS::ConstSharedPtr rxstatus)
  {
    RCLCPP_DEBUG(node_ptr_->get_logger(), "NovatelOEM7: Got RXSTATUS Msg!");
    oem7_rx_status_msg_buffer_.update_buffer(*rxstatus, rclcpp::Time(rxstatus->header.stamp));
    printOEM7RxStatus(*rxstatus);
  }

  void
  NovatelOEM7PreProcessor::onOEM7TimeMsgCb(const novatel_oem7_msgs::msg::TIME::ConstSharedPtr oem_time)
  {
    //RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "TIME: TIME:" <<  std::fixed <<rclcpp::Time(oem_time->header.stamp).seconds() << " NOW: " << node_ptr_->now().seconds());

    RCLCPP_DEBUG(node_ptr_->get_logger(), "NovatelOEM7: Got TIME Msg!");
    oem7_time_msg_buffer_.update_buffer(*oem_time, rclcpp::Time(oem_time->header.stamp));
  }

#if USE_DUAL_ANTENNA
  void
  NovatelOEM7PreProcessor::onOEM7RangeMsgCb(const novatel_oem7_msgs::msg::RANGE::ConstSharedPtr range_main,
                                            const novatel_oem7_msgs::msg::RANGE::ConstSharedPtr range_aux)
  {
    static auto last_printed_time = node_ptr_->now();
    static uint64_t counter = 0;
    RCLCPP_DEBUG(node_ptr_->get_logger(), "RangeCBStart");
    //RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Time of range:" << std::fixed  << rclcpp::Time(range_main->header.stamp).seconds() << " Now: " << node_ptr_->get_clock()->now().seconds());

    //RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "TIME: range:" <<  std::fixed <<rclcpp::Time(range_main->header.stamp).seconds() << " NOW: " << node_ptr_->now().seconds());
    //RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "TIME: range aux:" <<  std::fixed <<rclcpp::Time(range_aux->header.stamp).seconds() << " NOW: " << node_ptr_->now().seconds());

    auto start_cb_time = std::chrono::system_clock::now();
    //RCLCPP_INFO(node_ptr_->get_logger(), "1");
    //oem7_to_meas_epoch_converter_->initialize();
    novatel_oem7_msgs::msg::RANGE range_main_processed = *range_main;


    const auto towNew = double(int(double(range_main_processed.nov_header.gps_week_milliseconds) * 0.01)) / 10.;

    if(!LOSLoopUpTable_.empty()) {
      auto LOSLoopUpIter = LOSLoopUpTable_.find(towNew);
      if(LOSLoopUpIter != LOSLoopUpTable_.end()) {
        auto rangeIter = range_main_processed.ranges.begin();
        while(rangeIter != range_main_processed.ranges.end())
        {
          getSatInfoNovAtel::ExtU_getSatInfoNovAtel_T info_input;
          info_input.OEM7_ChannelTrackingStatus = rangeIter->ch_tr_status;
          oem7_get_sat_info_->setExternalInputs(&info_input);
          oem7_get_sat_info_->step();
          const auto info_output = oem7_get_sat_info_->getExternalOutputs();

          auto prn = rangeIter->prn;
          if (info_output.SatelliteSystem == 3)
            prn += 70;

          auto LOSIter = LOSLoopUpTable_[towNew].find(prn);
          if(LOSIter != LOSLoopUpTable_[towNew].end() && !LOSIter->second) {
            RCLCPP_ERROR_STREAM(node_ptr_->get_logger(), "Sat: " << prn << " and cn0 " << rangeIter->cn0 <<" is denoted as NLOS! It will be erased! ...");
            rangeIter = range_main_processed.ranges.erase(rangeIter);
            continue;
          }
          rangeIter ++;
        }
      }
    }

    //RCLCPP_INFO(node_ptr_->get_logger(), "2");
    ConvertOEM7RangeToMeasEpochRAW::ExtU_ConvertOEM7RangeToMeasEp_T meas_input = {convertOEM7RangeMsg(range_main_processed)};
    oem7_to_meas_epoch_converter_->setExternalInputs(&meas_input);
    oem7_to_meas_epoch_converter_->step();
    ConvertOEM7RangeToMeasEpochRAW::ExtY_ConvertOEM7RangeToMeasEp_T meas_output = oem7_to_meas_epoch_converter_->getExternalOutputs();

    auto measurement_epoch_ant_main = meas_output.MeasurementEpochBus;

    gnss_obs_raw_ant_main_buffer_.update_buffer(measurement_epoch_ant_main, rclcpp::Time(range_main_processed.header.stamp));
    hcs_mesa_ant_main_buffer_.update_buffer(meas_output.HCS_Bus, rclcpp::Time(range_main_processed.header.stamp));

    //RCLCPP_INFO(node_ptr_->get_logger(), "3");
    //oem7_to_meas_epoch_converter_->initialize();
    //RCLCPP_INFO(node_ptr_->get_logger(), "4");
    meas_input.Oem7RangeBus = convertOEM7RangeMsg(*range_aux);
    oem7_to_meas_epoch_converter_->setExternalInputs(&meas_input);
    oem7_to_meas_epoch_converter_->step();
    meas_output = oem7_to_meas_epoch_converter_->getExternalOutputs();

    auto measurement_epoch_ant_aux = meas_output.MeasurementEpochBus;



    gnss_obs_raw_ant_aux_buffer_.update_buffer(measurement_epoch_ant_aux, rclcpp::Time(range_aux->header.stamp));
    hcs_mesa_ant_aux_buffer_.update_buffer(meas_output.HCS_Bus, rclcpp::Time(range_aux->header.stamp));

    oem7_gps_ephem_buffer_mutex_.lock();
    gnssraw_gps_nav_t gps_nav_bus = this->gps_nav_ephemeris_buffer_;
    oem7_gps_ephem_buffer_mutex_.unlock();

    oem7_gal_inav_ephem_buffer_mutex_.lock();
    const auto gal_nav_bus = this->gal_nav_ephemeris_buffer_;
    oem7_gal_inav_ephem_buffer_mutex_.unlock();


    if(parameters_gnss_.gps.enable_gps && !this->checkHaveEphem<gnssraw_gps_nav_t>(gps_nav_bus)) {
      RCLCPP_WARN(node_ptr_->get_logger(), "onOEM7RangeMsgCb: Using GPS measurement but no ephemeris data was received, doing nothing ...");
      return;
    }

    auto gps_ion_bus = this->gps_ion_buffer_.get_last_buffer();
    //if(parameters_gnss_.enable_ionospheric_correction && !this->checkHaveGNSSSingleMeasData<gnssraw_gps_ion_t>(gps_ion_bus)) {
    //  RCLCPP_WARN(node_ptr_->get_logger(), "onOEM7RangeMsgCb: Using GPS ionospheric correction but no ionospheric data was received, doing nothing ...");
    //  return;
   // }

    auto gal_fnav_bus = this->gal_fnav_ephemeris_buffer_.get_last_buffer();
    auto gal_inav_bus = this->gal_inav_ephemeris_buffer_.get_last_buffer();
    auto gal_ion_bus = this->gal_ion_buffer_.get_last_buffer();
    auto gal_gstgps_bus = this->gal_gst_gps_buffer_.get_last_buffer();
    if(parameters_gnss_.galileo.enable_galileo && enable_gnss_merge_)
    {
      if(!this->checkHaveEphem<gnssraw_gal_nav_t>(gal_nav_bus))
      {
        RCLCPP_WARN(node_ptr_->get_logger(), "onOEM7RangeMsgCb: Using Galileo but no I/F ephemeris data was received, doing nothing ...");
        return;
      }

      if(parameters_gnss_.enable_ionospheric_correction && !this->checkHaveGNSSSingleMeasData<gnssraw_gal_ion_t>(gal_ion_bus))
      {
        RCLCPP_WARN(node_ptr_->get_logger(), "onOEM7RangeMsgCb: Using Galileo ionospheric correction but no ionospheric data was received, doing nothing ...");
        return;
      }

      if(ggto_sync_mode_ == 1 && !this->checkHaveGNSSSingleMeasData<gnssraw_ggto_t>(gal_gstgps_bus)) {
        RCLCPP_WARN(node_ptr_->get_logger(), "onOEM7RangeMsgCb: Using GPS / GAL Dual Constellation but no GGTA data was received, doing nothing ...");
        return;
      }

    }

    auto measurement_rtcm = this->rtcm_buffer_.get_last_buffer();

    //gnss_preprocessor_->initialize();
    if((parameters_gnss_.enable_differential_correction || enable_rtcm_DD_) &&!checkHaveEphem<DD_RTCM_3_3_L1_E1_t>(measurement_rtcm)) {
      RCLCPP_ERROR(node_ptr_->get_logger(), "onOEM7RangeMsgCb: needed RTCM but nothing was received!!!");
    }
    GNSSPreProcessingDualAntenna::ExtU_GNSSPreProcessingDualAnt_T preprocessor_input{};
    preprocessor_input.MeasurementEpochBusAntenna1 = measurement_epoch_ant_main;
    preprocessor_input.MeasurementEpochBusAntenna2 = measurement_epoch_ant_aux;
    preprocessor_input.GpsNavBus = gps_nav_bus;
    preprocessor_input.GpsIonBus = gps_ion_bus;
    preprocessor_input.GalFnavBus = gal_fnav_bus;
    preprocessor_input.GalInavBus = gal_inav_bus;
    preprocessor_input.GalIonBus = gal_ion_bus;
    preprocessor_input.GalGstGpsBus = gal_gstgps_bus;
    std::pair<UserEstimation_T, bool> user_est = this->checkUserEstimation();
    std::copy_n(user_est.first.begin(), 3, std::begin(preprocessor_input.UserPosLLHVecAntMain));
    preprocessor_input.UserPosLLHVecAntAux[0] = user_est.first[4];
    preprocessor_input.UserPosLLHVecAntAux[1] = user_est.first[5];
    preprocessor_input.UserPosLLHVecAntAux[2] = user_est.first[6];
    //std::copy_n(user_est.first.begin() + 4, 3, std::begin(preprocessor_input.UserPosLLHVecAntAux));
    preprocessor_input.ClockErrorVec = user_est.first[3];
    preprocessor_input.IntegrityParametersBus = this->parameters_integrity_;
    preprocessor_input.RTCM33L1E1Bus = measurement_rtcm;
    preprocessor_input.GnssParametersBus = this->parameters_gnss_;
    preprocessor_input.UseModeSwitchLogic = this->use_mode_switch_logic_;
    preprocessor_input.EnableGGTO = this->ggto_sync_mode_;
    preprocessor_input.EnableDualAntennaDD = false;
    preprocessor_input.EnableGNSSMerge = this->enable_gnss_merge_;

    gnss_preprocessor_->setExternalInputs(&preprocessor_input);
    gnss_preprocessor_->step();

    GNSSPreProcessingDualAntenna::ExtY_GNSSPreProcessingDualAnt_T preprocessor_output = gnss_preprocessor_->getExternalOutputs();
    //GNSSMeasurementPreProcessed gnss_obs_raw{};
    //gnss_obs_raw.gnss_obs_ant_main = preprocessor_output.GnssMeasurementBusRAWAntMain;
    //gnss_obs_raw.num_meas_ant_main = (size_t)preprocessor_output.GnssMeasurementSizeAntMain;
    //gnss_obs_raw.gnss_obs_ant_aux = preprocessor_output.GnssMeasurementBusRAWAntAux;
    //gnss_obs_raw.num_meas_ant_aux = (size_t)preprocessor_output.GnssMeasurementSizeAntAux;

    RCLCPP_WARN_STREAM(node_ptr_->get_logger(), "Num. of obs. ant main all: " << preprocessor_output.GnssMeasurementSizeAntMain);
    RCLCPP_WARN_STREAM(node_ptr_->get_logger(), "Num. of obs. ant main GPS: " << preprocessor_output.GPSMeasurementSizeAntMain);
    RCLCPP_WARN_STREAM(node_ptr_->get_logger(), "Num. of obs. ant main Galileo: " << preprocessor_output.GALMeasurementSizeAntMain);

      if(preprocessor_output.GnssMeasurementSizeAntMain == 0 || preprocessor_output.GPSMeasurementSizeAntMain < 2) {
          RCLCPP_WARN(node_ptr_->get_logger(), "onOEM7RangeMsgCb: no GPS observation after pre-processing, properly due to insufficient ephemeris data ...");
          return;
      }
    GNSSMeasurementPreProcessed gnss_obs_preprecessed{};
    gnss_obs_preprecessed.gnss_obs_ant_main = preprocessor_output.GnssMeasurementBusAntMain;
    gnss_obs_preprecessed.num_meas_ant_main = (size_t)preprocessor_output.GnssMeasurementSizeAntMain;
    gnss_obs_preprecessed.gnss_obs_ant_aux = preprocessor_output.GnssMeasurementBusAntAux;
    gnss_obs_preprecessed.num_meas_ant_aux = (size_t)preprocessor_output.GnssMeasurementSizeAntAux;
    gnss_obs_preprecessed.has_dualantenna = true;
    std::copy(std::begin(preprocessor_output.DOPAntMain),
              std::end(preprocessor_output.DOPAntMain),
              gnss_obs_preprecessed.dop_ant_main.begin());

    std::copy(std::begin(preprocessor_output.DOPAntAux),
              std::end(preprocessor_output.DOPAntAux),
              gnss_obs_preprecessed.dop_ant_aux.begin());

    std::copy(std::begin(preprocessor_output.faultyPRNsAntMain),
              std::end(preprocessor_output.faultyPRNsAntMain),
              gnss_obs_preprecessed.faulty_svid_ant_main.begin());

    std::copy(std::begin(preprocessor_output.faultyPRNsAntAux),
              std::end(preprocessor_output.faultyPRNsAntAux),
              gnss_obs_preprecessed.faulty_svid_ant_aux.begin());

    gnss_obs_preprecessed.time_offset_gal_gps = preprocessor_output.DeltaSystemTimeGNSSAntMain;
    gnss_obs_preprecessed.is_ggto_valid = preprocessor_output.IsGGTOValidAntMain;
    gnss_obs_preprecessed.integrity_flag_ant_main = (uint8_t)preprocessor_output.IntegrityFlagAntMain;
    gnss_obs_preprecessed.integrity_flag_ant_aux = preprocessor_output.IsGGTOValidAntAux;
    gnss_obs_preprecessed.ant_main_gps_corrected = preprocessor_output.GPSGALCorrectedAntMain[0];
    gnss_obs_preprecessed.ant_main_gal_corrected = preprocessor_output.GPSGALCorrectedAntMain[1];
    gnss_obs_preprecessed.ant_aux_gps_corrected = preprocessor_output.GPSGALCorrectedAntAux[0];
    gnss_obs_preprecessed.ant_aux_gal_corrected = preprocessor_output.GPSGALCorrectedAntAux[1];

    for(size_t i = 0; i < 40; i++) {
      if(preprocessor_output.diffSVIDCorrections[i] != 65535) {
        gnss_obs_preprecessed.diff_psr_corrections.insert(std::make_pair(preprocessor_output.diffSVIDCorrections[i], preprocessor_output.diffPsedorangeCorrections[i]));
      }
    }

    if (this->enable_dual_antenna_DD_) {
      //dd_dualantenna_preprocessor_->initialize();
      GNSSPreProcessingDualAntenna::ExtU_GNSSPreProcessingDualAnt_T dd_dualantenna_input{};
      dd_dualantenna_input.MeasurementEpochBusAntenna1 = measurement_epoch_ant_main;
      dd_dualantenna_input.MeasurementEpochBusAntenna2 = measurement_epoch_ant_aux;
      dd_dualantenna_input.GpsNavBus = gps_nav_bus;
      dd_dualantenna_input.GpsIonBus = gps_ion_bus;
      dd_dualantenna_input.GalInavBus = gal_inav_bus;
      dd_dualantenna_input.GalIonBus = gal_ion_bus;
      dd_dualantenna_input.GalFnavBus = gal_fnav_bus;
      dd_dualantenna_input.GalGstGpsBus = gal_gstgps_bus;
      dd_dualantenna_input.RTCM33L1E1Bus = measurement_rtcm;
      std::copy_n(user_est.first.begin(), 3, std::begin(dd_dualantenna_input.UserPosLLHVecAntMain));
      // TODO: @haoming get the corrected llh for the 2nd ant!
      std::copy_n(user_est.first.begin(), 3, std::begin(dd_dualantenna_input.UserPosLLHVecAntAux));
      dd_dualantenna_input.ClockErrorVec = user_est.first[3];
      dd_dualantenna_input.UseModeSwitchLogic = false;
      dd_dualantenna_input.EnableGGTO = this->ggto_sync_mode_;
      dd_dualantenna_input.GnssParametersBus = parameters_gnss_DD_dualantenna_;
      dd_dualantenna_input.IntegrityParametersBus = parameters_integrity_;
      dd_dualantenna_input.EnableDualAntennaDD = true;

      dd_dualantenna_preprocessor_->setExternalInputs(&dd_dualantenna_input);
      dd_dualantenna_preprocessor_->step();
      GNSSPreProcessingDualAntenna::ExtY_GNSSPreProcessingDualAnt_T dd_dualantenna_output = dd_dualantenna_preprocessor_->getExternalOutputs();

      std::copy(std::begin(preprocessor_output.SVIDUsedDualAntenna),
                std::end(preprocessor_output.SVIDUsedDualAntenna),
                gnss_obs_preprecessed.svid_carrier_used_DD_dualantenna.begin());

      gnss_obs_preprecessed.has_dualantenna_DD = true;
      gnss_obs_preprecessed.num_meas_ant_dd_dualantenna = (size_t)dd_dualantenna_output.GnssMeasurementSizeDDDualantenn;
      gnss_obs_preprecessed.gnss_obs_DD_dualantenna = dd_dualantenna_output.GnssMeasurementDDBus;
      gnss_obs_preprecessed.DD_idx_sync_ant_main = (uint8_t) dd_dualantenna_output.IDXSyncAntanna1;
      gnss_obs_preprecessed.DD_idx_sync_ant_aux = (uint8_t) dd_dualantenna_output.IDXSyncAntanna2;
      gnss_obs_preprecessed.ref_sat_svid_gps_dual_antenna = (uint8_t) dd_dualantenna_output.savidRefSatGPS;
      gnss_obs_preprecessed.ref_sat_svid_gal_dual_antenna = (uint8_t) dd_dualantenna_output.savidRefSatGAL;

    }

    if (this->rtcm_buffer_.counter)
    {
      gnss_obs_preprecessed.has_rtk = true;
    }

    if (this->enable_rtcm_DD_) {
      //dd_rtcm_preprocessor_->initialize();
      DDRTCM::ExtU_DDRTCM_T rtcm_DD_input{};
      rtcm_DD_input.MeasurementEpochBus = measurement_epoch_ant_main;
      rtcm_DD_input.GPSNavBus = gps_nav_bus;
      rtcm_DD_input.GPSIONBus = gps_ion_bus;
      rtcm_DD_input.GALNavBus = gal_inav_bus;
      rtcm_DD_input.GALIONBus = gal_ion_bus;
      rtcm_DD_input.GALGSTGPSBus = gal_gstgps_bus;
      std::copy_n(user_est.first.begin(), 3, std::begin(rtcm_DD_input.usePosLLHArray));
      rtcm_DD_input.ClockErrorArray = user_est.first[3];
      rtcm_DD_input.enableGGTO = false;
      rtcm_DD_input.RTCM_3_3_L1_E1_Bus = measurement_rtcm;
      rtcm_DD_input.useModeSwitchLogic = false;
      rtcm_DD_input.GNSSParametersBus = parameters_gnss_DD_rtcm_;
      rtcm_DD_input.IntegrityParametersBus = parameters_integrity_;

      dd_rtcm_preprocessor_->setExternalInputs(&rtcm_DD_input);
      dd_rtcm_preprocessor_->step();
      DDRTCM::ExtY_DDRTCM_T dd_rtcm_ouput = dd_rtcm_preprocessor_->getExternalOutputs();
      gnss_obs_preprecessed.has_rtk_DD = true;
      std::copy(std::begin(dd_rtcm_ouput.SVIDUsedRCM),
                std::end(dd_rtcm_ouput.SVIDUsedRCM),
                gnss_obs_preprecessed.svid_carrier_used_DD_rtcm.begin());
      gnss_obs_preprecessed.gnss_obs_DD_rtk = dd_rtcm_ouput.GNSSMeasurementBus;
      gnss_obs_preprecessed.num_meas_ant_dd_rtk = (size_t)dd_rtcm_ouput.GnssMeasurementSize;
      gnss_obs_preprecessed.DD_idx_sync_ant_rtk = (uint8_t)dd_rtcm_ouput.idxSyncR; //TODO DD_idx_sync_ant_rtk type double is wrong
      gnss_obs_preprecessed.DD_idx_sync_ant_main = (uint8_t)dd_rtcm_ouput.idxSyncU;
      gnss_obs_preprecessed.ref_sat_svid_gal_rtk = (uint8_t)dd_rtcm_ouput.svidRefSatGAL;
      gnss_obs_preprecessed.ref_sat_svid_gps_rtk = (uint8_t)dd_rtcm_ouput.svidRefSatGPS;

    }
    else
      gnss_obs_preprecessed.has_rtk_DD = false;

    gnss_obs_buffer_.update_buffer(gnss_obs_preprecessed, rclcpp::Time(range_main->header.stamp), node_ptr_->now());
    irt_nav_msgs::msg::GNSSObsPreProcessed gnss_obs_msg = makeGNSSObsPreProcessedROSMsg(gnss_obs_preprecessed);
    //irt_nav_msgs::msg::GNSSObsPreProcessed gnss_obs_raw_msg = makeGNSSObsPreProcessedROSMsg(gnss_obs_raw);

    /*
    for (uint i = 0; i < gnss_obs_msg.gnss_obs_ant_main.prn.size(); i++){
      double error = sqrt(gnss_obs_msg.gnss_obs_ant_main.satelite_pos[i].x * gnss_obs_msg.gnss_obs_ant_main.satelite_pos[i].x +
                          gnss_obs_msg.gnss_obs_ant_main.satelite_pos[i].y * gnss_obs_msg.gnss_obs_ant_main.satelite_pos[i].y +
                          gnss_obs_msg.gnss_obs_ant_main.satelite_pos[i].z * gnss_obs_msg.gnss_obs_ant_main.satelite_pos[i].z);
      std::cout << std::fixed << "SatID: " << gnss_obs_msg.gnss_obs_ant_main.prn[i] << " Norm: " << error << std::endl;
      std::cout << std::fixed << "SatPos.: " << gnss_obs_msg.gnss_obs_ant_main.satelite_pos[i].x << " : " << gnss_obs_msg.gnss_obs_ant_main.satelite_pos[i].y << " : " << gnss_obs_msg.gnss_obs_ant_main.satelite_pos[i].z << std::endl;

    }
    std::cout << ">.................................<" << std::endl;
     */

    gnss_obs_msg.header.stamp = range_main->header.stamp;
    //gnss_obs_raw_msg.header.stamp = range_main->header.stamp;
    gnss_obs_msg.counter = ++counter;
    //gnss_obs_raw_msg.counter = gnss_obs_msg.counter;
    LeastSquareSolution ls_ant_main = preprocessor_output.LeastSqureSolutionAntMain;
    LeastSquareSolution ls_ant_aux = preprocessor_output.LeastSqureSolutionAntAux;

    irt_nav_msgs::msg::Residuals residuals;
    residuals.header = gnss_obs_msg.header;
    for(size_t i = 0; i < gnss_obs_msg.gnss_obs_ant_main.prn.size(); i++)
    {
      irt_nav_msgs::msg::Residual res;
      res.header = gnss_obs_msg.header;
      res.tow = gnss_obs_msg.gnss_obs_ant_main.time_receive;
      res.sat = gnss_obs_msg.gnss_obs_ant_main.prn[i];
      geometry_msgs::msg::Vector3 p2{};
      auto p1 = irt_nav_common::llh2xyz(std::array<double, 3>{ls_ant_main.user_position_llh[0],
                                                              ls_ant_main.user_position_llh[1],
                                                              ls_ant_main.user_position_llh[2]});
      auto this_range = irt_nav_common::ros::calculate_distance(p1,
                                                                   gnss_obs_msg.gnss_obs_ant_main.satelite_pos[i]);
      res.data.emplace_back(this_range - gnss_obs_msg.gnss_obs_ant_main.pseudorange[i]);
      residuals.residuals_ant_main.emplace_back(res);
    }

    for(size_t i = 0; i < gnss_obs_msg.gnss_obs_ant_aux.prn.size(); i++)
    {
      irt_nav_msgs::msg::Residual res;
      res.header = gnss_obs_msg.header;
      res.tow = gnss_obs_msg.gnss_obs_ant_aux.time_receive;
      res.sat = gnss_obs_msg.gnss_obs_ant_aux.prn[i];
      geometry_msgs::msg::Vector3 p2{};
      auto p1 = irt_nav_common::llh2xyz(std::array<double, 3>{ls_ant_aux.user_position_llh[0],
                                                              ls_ant_aux.user_position_llh[1],
                                                              ls_ant_aux.user_position_llh[2]});
      auto this_range = irt_nav_common::ros::calculate_distance(p1,
                                                                gnss_obs_msg.gnss_obs_ant_aux.satelite_pos[i]);
      res.data.emplace_back(this_range - gnss_obs_msg.gnss_obs_ant_aux.pseudorange[i]);
      residuals.residuals_ant_aux.emplace_back(res);
    }
    ls_residuals_pub_->publish(residuals);

    irt_nav_msgs::msg::PVTLS pvt_ls_msg{};
    pvt_ls_msg.header.stamp = range_main->header.stamp;
    std::copy(std::begin(ls_ant_main.user_position_llh), std::end(ls_ant_main.user_position_llh), pvt_ls_msg.ls_ant_main.llh.begin());
    std::copy(std::begin(ls_ant_main.user_velocity_ned), std::end(ls_ant_main.user_velocity_ned), pvt_ls_msg.ls_ant_main.vel_ned.begin());
    std::copy(std::begin(preprocessor_output.DOPAntMain), std::end(preprocessor_output.DOPAntMain), pvt_ls_msg.ls_ant_main.dop.begin());
    std::copy(std::begin(ls_ant_aux.user_position_llh), std::end(ls_ant_aux.user_position_llh), pvt_ls_msg.ls_ant_aux.llh.begin());
    std::copy(std::begin(ls_ant_aux.user_position_llh), std::end(ls_ant_aux.user_position_llh), pvt_ls_msg.ls_ant_aux.llh.begin());
    std::copy(std::begin(preprocessor_output.DOPAntAux), std::end(preprocessor_output.DOPAntAux), pvt_ls_msg.ls_ant_aux.dop.begin());
    pvt_ls_msg.ls_ant_main.receiver_clock_bias = ls_ant_main.receiver_clock_bias;
    pvt_ls_msg.ls_ant_main.receiver_clock_drift = ls_ant_main.receiver_clock_drift;
    pvt_ls_msg.ls_ant_aux.receiver_clock_bias = ls_ant_aux.receiver_clock_bias;
    pvt_ls_msg.ls_ant_aux.receiver_clock_drift = ls_ant_aux.receiver_clock_drift;
    pvt_ls_msg.ls_ant_main.available = ls_ant_main.solution_available;
    pvt_ls_msg.ls_ant_aux.available = ls_ant_aux.solution_available;

    //RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Time of Msg:" << std::fixed << rclcpp::Time(gnss_obs_msg.header.stamp).seconds()  << " Now: " << node_ptr_->get_clock()->now().seconds());

    if (this->pub_gnss_obs_)
    {
      gnss_obs_pub_->publish(gnss_obs_msg);
      lspvt_pub_->publish(pvt_ls_msg);

      sensor_msgs::msg::NavSatFix nav_sat_ant_main;
      nav_sat_ant_main.header.stamp = range_main->header.stamp;
      nav_sat_ant_main.latitude = ls_ant_main.user_position_llh[0] * 180. / M_PI;
      nav_sat_ant_main.longitude = ls_ant_main.user_position_llh[1] * 180. / M_PI;
      nav_sat_ant_main.altitude = ls_ant_main.user_position_llh[2] ;

      ls_ant_main_pub_->publish(nav_sat_ant_main);
      //gnss_obs_raw_pub_->publish(gnss_obs_raw_msg);
    }
    else
      this->signal_new_gnss_obs_(gnss_obs_msg);

    double duration_cb = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - start_cb_time).count();


    if((node_ptr_->now() - last_printed_time).seconds() > print_info_duration_) {
      //RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "------- NovAtelOEM7 Pre-Processing Info: --------");

      std::stringstream faulty_prn_ant1, faulty_prn_ant2;
      faulty_prn_ant1 << "Faulty PRNs AntMain: ";
      faulty_prn_ant2 << "Faulty PRNs AntAux: ";
      for(size_t i = 0; i < 40; i++) {
        if (!std::isnan(preprocessor_output.faultyPRNsAntMain[i * 2]) && preprocessor_output.faultyPRNsAntMain[i * 2])
          faulty_prn_ant1 << std::to_string(preprocessor_output.faultyPRNsAntMain[i * 2]) << " : ";
        if (!std::isnan(preprocessor_output.faultyPRNsAntAux[i * 2]) && preprocessor_output.faultyPRNsAntAux[i * 2])
          faulty_prn_ant2 << std::to_string(preprocessor_output.faultyPRNsAntAux[i * 2]) << " : ";
      }


      RCLCPP_INFO_STREAM(node_ptr_->get_logger(),
                         "Used PVT to pre-process? " << (user_est.second ? "True" : "False"));

      RCLCPP_INFO_STREAM(node_ptr_->get_logger(),
                         "Range Time: " << std::fixed << rclcpp::Time(range_main->header.stamp).seconds()
                                        << "s  GNSSMsgTime: " << rclcpp::Time(gnss_obs_msg.header.stamp).seconds());
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(),
                         "Callback onOEM7Range can be run at " << std::fixed << 1. / duration_cb << " Hz");
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(),
                         "Published at: " << std::fixed << node_ptr_->get_clock()->now().seconds() << "s");

      RCLCPP_INFO_STREAM(node_ptr_->get_logger(),
                         "Faulty PRNs AntMain: " << faulty_prn_ant1.str());

      RCLCPP_INFO_STREAM(node_ptr_->get_logger(),
                         "Faulty PRNs AntAux: " << faulty_prn_ant2.str());

      RCLCPP_INFO_STREAM(node_ptr_->get_logger(),
                         "Least Square Available: " << (ls_ant_main.solution_available ? "True" : "False"));
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(),
                         "Least Square Lat: " << ls_ant_main.user_position_llh[0] * 180 / M_PI);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(),
                         "Least Square Lon: " << ls_ant_main.user_position_llh[1] * 180 / M_PI);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Least Square Alt: " << ls_ant_main.user_position_llh[2]);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Least Square Vel N: " << ls_ant_main.user_velocity_ned[0]);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Least Square Vel E: " << ls_ant_main.user_velocity_ned[1]);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Least Square Vel D: " << ls_ant_main.user_velocity_ned[2]);
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Least Square Clock Bias [m]: " << ls_ant_main.receiver_clock_bias); //TODO maybe ns but not meter
      RCLCPP_INFO_STREAM(node_ptr_->get_logger(), "Least Square Clock Drift [m/s]: " << ls_ant_main.receiver_clock_drift);

      last_printed_time = node_ptr_->now();
    }

    if (duration_cb > 0.1) {
      RCLCPP_WARN_STREAM(node_ptr_->get_logger(),
                         "Callback onOEM7Range takes: " << duration_cb << "s, more than expected 0.1s");
    }
  }
#else
  void
  NovatelOEM7PreProcessor::onOEM7RangeMsgCb(const novatel_oem7_msgs::msg::RANGE::ConstSharedPtr range_main)
  {
    ConvertOEM7RangeToMeasEpochRAWModelClass::ExtU_ConvertOEM7RangeToMeasEp_T meas_input_ = {convertOEM7RangeMsg(*range_main)};
    oem7_to_meas_epoch_converter_->setExternalInputs(&meas_input_);
    oem7_to_meas_epoch_converter_->step();
    ConvertOEM7RangeToMeasEpochRAWModelClass::ExtY_ConvertOEM7RangeToMeasEp_T meas_output_ = oem7_to_meas_epoch_converter_->getExternalOutputs();
    gnss_obs_raw_ant_main_buffer_.update_buffer(meas_output_.MeasurementEpochBus, rclcpp::Time(range_main->header.stamp), node_ptr_->now());
    hcs_mesa_ant_main_buffer_.update_buffer(meas_output_.HCS_Bus, rclcpp::Time(range_main->header.stamp), node_ptr_->now());
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.MeasurementEpochBus = meas_output_.MeasurementEpochBus;
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.GPSNavBus = this->gps_nav_ephemeris_buffer_.get_last_buffer();
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.GPSIONBus = this->gps_ion_buffer_.get_last_buffer();
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.GALNavBus = this->gal_inav_ephemeris_buffer_.get_last_buffer();
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.GALIONBus = this->gal_ion_buffer_.get_last_buffer();
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.GALGSTGPSBus = this->gal_gst_gps_buffer_.get_last_buffer();
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.RTCM_3_3_L1_E1_Bus = this->rtcm_buffer_.get_last_buffer();
    UserEstimation_T user_pos = user_estimation_buffer_.get_last_buffer();
    std::copy_n(user_pos.begin(), 3, std::begin(gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.usePosLLHArray));
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.ClockErrorArray = user_pos[3];
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.GNSSParametersBus = this->parameters_gnss_;
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.IntegrityParametersBus = this->parameters_integrity_;
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.useModeSwitchLogic = this->use_mode_switch_logic_;
    gnss_preprocessor_->GNSSPreProcessingSingleAntenn_U.enableGGTO = this->ggto_sync_mode_;
    // todo: tic toc
    gnss_preprocessor_->step();
    GNSSMeasurementPreProcessed gnss_obs_preprecessed{};
    gnss_obs_preprecessed.gnss_obs_ant_main = gnss_preprocessor_->GNSSPreProcessingSingleAntenn_Y.GNSSMeasurementBus;
    gnss_obs_preprecessed.is_ggto_valid_ant_main = gnss_preprocessor_->GNSSPreProcessingSingleAntenn_Y.isGGTOValid;
    gnss_obs_preprecessed.integrity_flag_ant_main = gnss_preprocessor_->GNSSPreProcessingSingleAntenn_Y.integrityFlag;
    gnss_obs_preprecessed.time_offset_gal_gps_ant_main = gnss_preprocessor_->GNSSPreProcessingSingleAntenn_Y.deltaSystemTimeGnss;
    std::copy(std::begin(gnss_preprocessor_->GNSSPreProcessingSingleAntenn_Y.SVIDCarrierUse),
              std::end(gnss_preprocessor_->GNSSPreProcessingSingleAntenn_Y.SVIDCarrierUse),
              gnss_obs_preprecessed.svid_carrier_used_ant_main.begin());
    if (this->rtcmv3_L1E1_msg_buffer_.counter)
    {
      gnss_obs_preprecessed.has_rtk = true;
    }
    gnss_obs_buffer_.update_buffer(gnss_obs_preprecessed, rclcpp::Time(range_main->header.stamp), node_ptr_->now());
    irt_nav_msgs::msg::GNSSObsPreProcessed gnss_obs_msg = makeGNSSObsPreProcessedROSMsg(gnss_obs_preprecessed);
    gnss_obs_msg.header.stamp = range_main->header.stamp;
    if (this->pub_gnss_obs_)
    {
      gnss_obs_pub_->publish(gnss_obs_msg);
    }
    else
      this->signal_new_gnss_obs_(gnss_obs_msg);
  };
#endif
}