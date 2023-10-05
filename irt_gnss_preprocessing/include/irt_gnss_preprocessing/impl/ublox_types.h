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
// Created by haoming on 27.01.23.
//

#ifndef IRT_GNSS_PREPROCESSING_UBLOX_TYPES_H
#define IRT_GNSS_PREPROCESSING_UBLOX_TYPES_H

#pragma once

#include <tuple>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
#include <iomanip>
#include <eigen3/Eigen/Dense>

#include <ublox_msgs/msg/rxm_sfrbx.hpp>
#include <ublox_msgs/msg/rxm_rawx.hpp>
#include <ublox_msgs/msg/nav_pvt.hpp>
#include <ublox_msgs/msg/rxm_measx.hpp>
#include <ublox_msgs/msg/nav_orb.hpp>
#include <ublox_msgs/msg/nav_relposned9.hpp>
#include <ublox_msgs/msg/nav_timegal.hpp>
#include <ublox_msgs/msg/nav_timeutc.hpp>
#include <ublox_msgs/msg/nav_status.hpp>
#include <ublox_msgs/msg/nav_sig.hpp>
#include <ublox_msgs/msg/nav_clock.hpp>


#include "gnss_preprocessor.h"
#include "gnss_preprocessor_types.h"
#include "gnss_constant.h"

namespace irt_gnss_preprocessing::Ublox
{
    using namespace irt_gnss_preprocessing::constant;

    static constexpr uint32_t MSG_HEADER_LEN = 6;
    static constexpr uint8_t UBX_SYNC_1 = 0xB5;        // ubx message sync code 1
    static constexpr uint8_t UBX_SYNC_2 = 0x62;        // ubx message sync code 2
    static constexpr uint16_t UBX_ACK_ACK_ID = 0x0501;          // ubx message id: message Acknowledged
    static constexpr uint16_t UBX_ACK_NAK_ID = 0x0500;          // ubx message id: message Not-Acknowledged
    static constexpr uint16_t UBX_CFG_VALSET_ID = 0x068A;       // ubx message id: sets values corresponding to provided key-value pairs within a transaction
    static constexpr uint16_t UBX_RXMSFRBX_ID = 0x0213;      // ubx message id: raw subframe data
    static constexpr uint16_t UBX_RXMRAWX_ID = 0x0215;       // ubx message id: multi-gnss raw meas data
    static constexpr uint16_t UBX_NAVPOS_ID = 0x0107;        // ubx message id: Navigation Position Velocity Time Solution
    static constexpr uint16_t UBX_TIM_TP_ID = 0x0D01;        // ubx message id:  information on the timing of the next pulse
    static constexpr uint16_t UBX_UNKNOWN_ID = 0x0000;        // ubx message id:  unknown or unsupported message

    static constexpr uint32_t UBX_PVT_PAYLOAD_LEN = 92;

    static constexpr uint8_t CPSTD_VALID = 10;         // carrier-phase std threshold for cycle clip detection
    static constexpr uint8_t LLI_SLIP = 0x01;          // LLI: cycle-slip
    static constexpr uint8_t LLI_HALFC = 0x02;         // LLI: half-cycle not resovled
    static constexpr double lam_carr[MAXFREQ]=         // carrier wave length (m)
        {
            LIGHT_SPEED/FREQ1,LIGHT_SPEED/FREQ2,LIGHT_SPEED/FREQ5,LIGHT_SPEED/FREQ6,LIGHT_SPEED/FREQ7,
            LIGHT_SPEED/FREQ8,LIGHT_SPEED/FREQ9
        };
    static constexpr uint8_t GPS_WEEK_ROLLOVER_N = 2;  // TODO: assuming 2 GPS week rollovers
    static constexpr uint8_t PREAMB_CNAV = 0x8B;      // cnav preamble

    static constexpr double P2_5  = 0.03125;               // 2^-5
    static constexpr double P2_6  = 0.015625;              // 2^-6
    static constexpr double P2_11 = 4.882812500000000E-04; // 2^-11
    static constexpr double P2_15 = 3.051757812500000E-05; // 2^-15
    static constexpr double P2_17 = 7.629394531250000E-06; // 2^-17
    static constexpr double P2_19 = 1.907348632812500E-06; // 2^-19
    static constexpr double P2_20 = 9.536743164062500E-07; // 2^-20
    static constexpr double P2_21 = 4.768371582031250E-07; // 2^-21
    static constexpr double P2_23 = 1.192092895507810E-07; // 2^-23
    static constexpr double P2_24 = 5.960464477539063E-08; // 2^-24
    static constexpr double P2_27 = 7.450580596923828E-09; // 2^-27
    static constexpr double P2_29 = 1.862645149230957E-09; // 2^-29
    static constexpr double P2_30 = 9.313225746154785E-10; // 2^-30
    static constexpr double P2_31 = 4.656612873077393E-10; // 2^-31
    static constexpr double P2_32 = 2.328306436538696E-10; // 2^-32
    static constexpr double P2_33 = 1.164153218269348E-10; // 2^-33
    static constexpr double P2_34 = 5.820766091346740E-11; // 2^-34
    static constexpr double P2_35 = 2.910383045673370E-11; // 2^-35
    static constexpr double P2_38 = 3.637978807091710E-12; // 2^-38
    static constexpr double P2_39 = 1.818989403545856E-12; // 2^-39
    static constexpr double P2_40 = 9.094947017729280E-13; // 2^-40
    static constexpr double P2_43 = 1.136868377216160E-13; // 2^-43
    static constexpr double P2_46 = 1.421085471520200E-14; // 2^-46
    static constexpr double P2_48 = 3.552713678800501E-15; // 2^-48
    static constexpr double P2_50 = 8.881784197001252E-16; // 2^-50
    static constexpr double P2_55 = 2.775557561562891E-17; // 2^-55
    static constexpr double P2_59 = 1.734723475976810E-18; // 2^-59
    static constexpr double P2_66 = 1.355252715606881E-20; // 2^-66

    static constexpr unsigned int tbl_CRC24Q[] = {
        0x000000,0x864CFB,0x8AD50D,0x0C99F6,0x93E6E1,0x15AA1A,0x1933EC,0x9F7F17,
        0xA18139,0x27CDC2,0x2B5434,0xAD18CF,0x3267D8,0xB42B23,0xB8B2D5,0x3EFE2E,
        0xC54E89,0x430272,0x4F9B84,0xC9D77F,0x56A868,0xD0E493,0xDC7D65,0x5A319E,
        0x64CFB0,0xE2834B,0xEE1ABD,0x685646,0xF72951,0x7165AA,0x7DFC5C,0xFBB0A7,
        0x0CD1E9,0x8A9D12,0x8604E4,0x00481F,0x9F3708,0x197BF3,0x15E205,0x93AEFE,
        0xAD50D0,0x2B1C2B,0x2785DD,0xA1C926,0x3EB631,0xB8FACA,0xB4633C,0x322FC7,
        0xC99F60,0x4FD39B,0x434A6D,0xC50696,0x5A7981,0xDC357A,0xD0AC8C,0x56E077,
        0x681E59,0xEE52A2,0xE2CB54,0x6487AF,0xFBF8B8,0x7DB443,0x712DB5,0xF7614E,
        0x19A3D2,0x9FEF29,0x9376DF,0x153A24,0x8A4533,0x0C09C8,0x00903E,0x86DCC5,
        0xB822EB,0x3E6E10,0x32F7E6,0xB4BB1D,0x2BC40A,0xAD88F1,0xA11107,0x275DFC,
        0xDCED5B,0x5AA1A0,0x563856,0xD074AD,0x4F0BBA,0xC94741,0xC5DEB7,0x43924C,
        0x7D6C62,0xFB2099,0xF7B96F,0x71F594,0xEE8A83,0x68C678,0x645F8E,0xE21375,
        0x15723B,0x933EC0,0x9FA736,0x19EBCD,0x8694DA,0x00D821,0x0C41D7,0x8A0D2C,
        0xB4F302,0x32BFF9,0x3E260F,0xB86AF4,0x2715E3,0xA15918,0xADC0EE,0x2B8C15,
        0xD03CB2,0x567049,0x5AE9BF,0xDCA544,0x43DA53,0xC596A8,0xC90F5E,0x4F43A5,
        0x71BD8B,0xF7F170,0xFB6886,0x7D247D,0xE25B6A,0x641791,0x688E67,0xEEC29C,
        0x3347A4,0xB50B5F,0xB992A9,0x3FDE52,0xA0A145,0x26EDBE,0x2A7448,0xAC38B3,
        0x92C69D,0x148A66,0x181390,0x9E5F6B,0x01207C,0x876C87,0x8BF571,0x0DB98A,
        0xF6092D,0x7045D6,0x7CDC20,0xFA90DB,0x65EFCC,0xE3A337,0xEF3AC1,0x69763A,
        0x578814,0xD1C4EF,0xDD5D19,0x5B11E2,0xC46EF5,0x42220E,0x4EBBF8,0xC8F703,
        0x3F964D,0xB9DAB6,0xB54340,0x330FBB,0xAC70AC,0x2A3C57,0x26A5A1,0xA0E95A,
        0x9E1774,0x185B8F,0x14C279,0x928E82,0x0DF195,0x8BBD6E,0x872498,0x016863,
        0xFAD8C4,0x7C943F,0x700DC9,0xF64132,0x693E25,0xEF72DE,0xE3EB28,0x65A7D3,
        0x5B59FD,0xDD1506,0xD18CF0,0x57C00B,0xC8BF1C,0x4EF3E7,0x426A11,0xC426EA,
        0x2AE476,0xACA88D,0xA0317B,0x267D80,0xB90297,0x3F4E6C,0x33D79A,0xB59B61,
        0x8B654F,0x0D29B4,0x01B042,0x87FCB9,0x1883AE,0x9ECF55,0x9256A3,0x141A58,
        0xEFAAFF,0x69E604,0x657FF2,0xE33309,0x7C4C1E,0xFA00E5,0xF69913,0x70D5E8,
        0x4E2BC6,0xC8673D,0xC4FECB,0x42B230,0xDDCD27,0x5B81DC,0x57182A,0xD154D1,
        0x26359F,0xA07964,0xACE092,0x2AAC69,0xB5D37E,0x339F85,0x3F0673,0xB94A88,
        0x87B4A6,0x01F85D,0x0D61AB,0x8B2D50,0x145247,0x921EBC,0x9E874A,0x18CBB1,
        0xE37B16,0x6537ED,0x69AE1B,0xEFE2E0,0x709DF7,0xF6D10C,0xFA48FA,0x7C0401,
        0x42FA2F,0xC4B6D4,0xC82F22,0x4E63D9,0xD11CCE,0x575035,0x5BC9C3,0xDD8538
    };

    enum UbloxGNSSSys
    {
        GPS = 0,
        Galileo = 2,
        Beidou = 3,
        QZSS = 5,
        GLONASS = 6
    };

    struct UbloxObs
    {
        uint8_t         gnss_id{};
        std::string     gnss_sys;
        uint8_t         sv_id{};
        uint8_t         sbf_freq_id{};
        std::string     freq;
        double          cn0{};
        double          pr{};
        double          cp{};
        double          dr{};
        double          pr_stdev{};
        double          cp_stdev{};
        double          dr_stdev{};
        uint8_t         trk_stat{};
        uint8_t         sig_id{};
        uint8_t         reserved1{};
        double          lock_time{};
    };

    struct UbloxMeasEpoch
    {
        double                   timestamp{};   // received timestamp
        double                   tow{};
        uint16_t                 week_number{};
        int8_t                   leap_s{};
        uint8_t                  num_obs{};
        uint8_t                  rec_stat{};
        std::array<uint8_t, 2>   reserved1{};
        std::vector<UbloxObs>    obs;
    };

    inline std::tuple<std::string, uint8_t, std::string> get_ublox_gnss_sys(uint8_t gnss_id, uint8_t sig_id)
    {
      std::string sat_sys = "UNKNOWN", freq = "UNKNOWN";
      uint8_t freq_id = 255;

      switch (gnss_id) {
        case 0:
          sat_sys = "GPS";
          break;
        case 2:
          sat_sys = "Galileo";
          break;
        case 3:
          sat_sys = "Beidou";
          break;
        case 5:
          sat_sys = "QZSS";
          break;
        case 6:
          sat_sys = "GLONASS";
          break;
        default:
          sat_sys = "UNKNOWN";
          break;
      }

      switch (sig_id) {
        case 0: {
          if(gnss_id == 0)
          {
            freq_id = 0;
            freq = "L1C/A";
          } else if(gnss_id == 2)
          {
            freq_id = 16;
            freq = "E1B";
          } else if(gnss_id == 5) {
            freq_id = 6;
            freq = "L1C/A";
          } else if(gnss_id == 6) {
            freq_id = 8;
            freq = "L1C/A";
          } else if(gnss_id == 3) {
            freq_id = 32;
            freq = "B1I D1";
          }
          break;
        }
        case 1: {
          if(gnss_id == 2)
          {
            freq_id = 17;
            freq = "E1C";
          }
          else if(gnss_id == 3) {
            freq_id = 33;
            freq = "B1I D2";
          }
          break;
        }
        case 2: {
          if(gnss_id == 6) {
            freq_id = 8;
            freq = "L2C";
          } else if(gnss_id == 3) {
            freq_id = 34;
            freq = "B2I D1";
          }
          break;
        }
        case 3: {
          if(gnss_id == 0)
          {
            freq_id = 5;
            freq = "L2CL";
          } else if(gnss_id == 3) {
            freq_id = 35;
            freq = "B2I D2";
          }
          break;
        }
        case 4: {
          if(gnss_id == 0)
          {
            freq_id = 3;
            freq = "L2CM";
          } else if(gnss_id == 5)
          {
            freq_id = 27;
            freq = "L2CM";
          }
          break;
        }
        case 5: {
          if(gnss_id == 2)
          {
            freq_id = 20;
            freq = "E5bl";
          } else if(gnss_id == 5)
          {
            freq_id = 28;
            freq = "L2CL";
          }
          break;
        }
        case 6: {
          if(gnss_id == 2)
          {
            freq_id = 21;
            freq = "E5bQ";
          }
          break;
        }
        default: {
          break;
        }
      }

      return {sat_sys, freq_id, freq};
    }


    inline UbloxMeasEpoch RmxRAWX_to_UbloxMeasEpoch(const ublox_msgs::msg::RxmRAWX::SharedPtr msg,
                                             double timestamp)
    {
      UbloxMeasEpoch epoch;
      epoch.timestamp = timestamp;
      epoch.tow = msg->rcv_tow;
      epoch.week_number = msg->week;
      epoch.leap_s = msg->leap_s;
      epoch.num_obs = msg->num_meas;
      epoch.rec_stat = msg->rec_stat;
      std::copy(msg->reserved1.begin(), msg->reserved1.end(), epoch.reserved1.begin());

      for(const auto& obs : msg->meas)
      {
        UbloxObs this_obs;
        this_obs.pr = obs.pr_mes;
        this_obs.dr = obs.do_mes;
        this_obs.cp = obs.cp_mes;
        this_obs.pr_stdev = ldexp(0.01, obs.pr_stdev);
        this_obs.dr_stdev = ldexp(0.002, obs.do_stdev);
        this_obs.cp_stdev = obs.cp_stdev * 0.4;
        this_obs.gnss_id = obs.gnss_id;
        this_obs.sig_id = obs.reserved0;
        auto [sat_sys, freq_id_sbf, freq] = get_ublox_gnss_sys(obs.gnss_id, obs.reserved0);
        this_obs.gnss_sys = sat_sys;
        this_obs.freq = freq;
        this_obs.sbf_freq_id = freq_id_sbf;
        this_obs.lock_time = obs.locktime / 1000.;
        this_obs.cn0 = obs.cno;
        this_obs.trk_stat = obs.trk_stat;
        this_obs.reserved1 = obs.reserved1;

        if(sat_sys == "GPS")
          this_obs.sv_id = obs.sv_id;
        else if(sat_sys == "Galileo")
          this_obs.sv_id = obs.sv_id + 70;

        epoch.obs.emplace_back(this_obs);
      }
      return epoch;
    }

    #define MAXLEAPS                64
    inline const double leaps[MAXLEAPS+1][7]={ /* leap seconds (y,m,d,h,m,s,utc-gpst) */
        {2017,1,1,0,0,0,-18},
        {2015,7,1,0,0,0,-17},
        {2012,7,1,0,0,0,-16},
        {2009,1,1,0,0,0,-15},
        {2006,1,1,0,0,0,-14},
        {1999,1,1,0,0,0,-13},
        {1997,7,1,0,0,0,-12},
        {1996,1,1,0,0,0,-11},
        {1994,7,1,0,0,0,-10},
        {1993,7,1,0,0,0, -9},
        {1992,7,1,0,0,0, -8},
        {1991,1,1,0,0,0, -7},
        {1990,1,1,0,0,0, -6},
        {1988,1,1,0,0,0, -5},
        {1985,7,1,0,0,0, -4},
        {1983,7,1,0,0,0, -3},
        {1982,7,1,0,0,0, -2},
        {1981,7,1,0,0,0, -1},
        {0}
    };

    /* System identifier to system code */
    const std::map<uint8_t, uint32_t> char2sys =
        {
            {'G', SYS_GPS},
            {'C', SYS_BDS},
            {'R', SYS_GLO},
            {'E', SYS_GAL}
        };

    /* System map to index */
    const std::map<uint32_t, uint32_t> sys2idx =
        {
            {SYS_GPS, 0},
            {SYS_GLO, 1},
            {SYS_GAL, 2},
            {SYS_BDS, 3}
        };

    /* RINEX frequency encoding to frequency value */
    const std::map<std::string, double> type2freq =
        {
            {"G1", FREQ1},
            {"G2", FREQ2},
            {"G5", FREQ5},
            {"R1", FREQ1_GLO},
            {"R2", FREQ2_GLO},
            {"R3", 1.202025E9},
            {"R4", 1.600995E9},
            {"R6", 1.248060E9},
            {"E1", FREQ1},
            {"E5", FREQ5},
            {"E6", FREQ6},
            {"E7", FREQ7},
            {"E8", FREQ8},
            {"C1", FREQ1},
            {"C2", FREQ1_BDS},
            {"C5", FREQ5},
            {"C6", FREQ3_BDS},
            {"C7", FREQ2_BDS},
            {"C8", FREQ8}
        };

    struct gtime_t
    {
        time_t time;            /* time (s) expressed by standard time_t */
        double sec;             /* fraction of second under 1 s */
    };

    struct EphemBase
    {
        virtual ~EphemBase() = default;
        double      timestamp;
        uint32_t sat;                   /* satellite number */
        gtime_t  ttr;                   /* transmission time in GPST */
        gtime_t  toe;                   /* ephemeris reference time in GPST */
        uint32_t health;                /* satellite health */
        double   ura;                   /* satellite signal accuracy */
        uint32_t iode;
    };
    typedef std::shared_ptr<EphemBase> EphemBasePtr;

    struct GloEphem : EphemBase
    {
        int         freqo;              /* satellite frequency number */
        uint32_t    age;                /* satellite age */
        double      pos[3];             /* satellite position (ecef) (m) */
        double      vel[3];             /* satellite velocity (ecef) (m/s) */
        double      acc[3];             /* satellite acceleration (ecef) (m/s^2) */
        double      tau_n, gamma;       /* SV clock bias (s)/relative freq bias */
        double      delta_tau_n;        /* delay between L1 and L2 (s) */
    };
    typedef std::shared_ptr<GloEphem> GloEphemPtr;

    struct Ephem : EphemBase
    {

        gtime_t     toc;                    /* clock correction reference time in GPST */
        double      toe_tow;                /* toe seconds within the week */
        uint32_t    week;
        uint32_t    iodc;
        uint32_t    code;
        double      A, e, i0, omg, OMG0, M0, delta_n, OMG_dot, i_dot;       /* SV orbit parameters */
        double      cuc, cus, crc, crs, cic, cis;
        double      af0, af1, af2;          /* SV clock parameters */
        double      tgd[2];                 /* group delay parameters */
        /* GPS    :tgd[0]=TGD */
        /* GAL    :tgd[0]=BGD E5a/E1,tgd[1]=BGD E5b/E1 */
        /* BDS    :tgd[0]=BGD1,tgd[1]=BGD2 */
        double A_dot, n_dot;                /* Adot,ndot for CNAV */
    };
    typedef std::shared_ptr<Ephem> EphemPtr;






}
#endif //IRT_GNSS_PREPROCESSING_UBLOX_TYPES_H
