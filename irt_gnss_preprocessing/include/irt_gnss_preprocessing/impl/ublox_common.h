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

#ifndef IRT_GNSS_PREPROCESSING_UBLOX_COMMON_H
#define IRT_GNSS_PREPROCESSING_UBLOX_COMMON_H

#pragma once

#include <map>
#include <mutex>
#include <glog/logging.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <libgen.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <memory>
#include <rclcpp/rclcpp.hpp>

#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/sync_policies/exact_time.h>
#include <message_filters/subscriber.h>
#include <boost/circular_buffer.hpp>

#include "gnss_utils.h"
#include "gnss_constant.h"
#include "ublox_types.h"

namespace irt_gnss_preprocessing::Ublox
{
    using namespace irt_gnss_preprocessing::utils;

    class UbloxCommon
    {
    public:
        typedef std::unique_ptr<UbloxCommon> UniquePtr;

        explicit UbloxCommon() = default;

        inline void set_curr_time(uint32_t week, double tow)
        {
          std::lock_guard<std::mutex> lg(mutex_);
          curr_time_ =  gpst2time(week, tow);
        }

        inline int decode_GPS_subframe(const std::vector<uint32_t>& dwrd,
                                        const EphemPtr& ephem)
        {
          if(dwrd.size() != 10)
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"),
                               "UBLOX: Can't decode gps subframe with size: " << dwrd.size());
            return -1;
          }

          uint32_t words[10];

          for(size_t i = 0; i < 10; i++)
            words[i] = dwrd[i] & 0x3FFFFFFF;

          uint32_t subframe_id = (words[1]>>2) & 0x07; //words[1]对应第二个word，是HOW. (ref.IS-GPS-200M P.108)

          // ref.IS-GPS-200M P.97
          if (subframe_id < 1 || subframe_id > 5)
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"),
                               "UBLOX: rxmsfrbx subframe id error: sat=" << ephem->sat << " id=" << subframe_id);
            return -1;
          }
          uint32_t subframe_pos = (subframe_id - 1) * 30;  // 240 bits for each subframe

          // now set bits to subframe buffer
          for (size_t i = 0; i < 10; i++)
            setbitu(subfrm_[ephem->sat] + subframe_pos, 24 * i, 24, words[i]);

          if (subframe_id == 3)
            return decode_GPS_ephem(ephem);
          //todo id==4或5的子帧数据处理
          // if (subframe_id ==4 || subframe_id ==5)
          return -1;
        }

        inline int decode_GAL_subframe(const std::vector<uint32_t>& dwrd,
                                        const EphemPtr& ephem)
        {
          if(dwrd.size() < 8)
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"),
                               "UBLOX: Can't decode gal subframe with size: " << dwrd.size());
            return -1;
          }

          uint8_t buff[32], crc_buff[26] = {0};
          int i = 0, j;
          uint32_t k, part1, page1, part2, page2, type;

          std::memcpy(&buff, dwrd.data(), sizeof(std::uint8_t) * dwrd.size());

          part1 = getbitu(buff, 0, 1);
          page1 = getbitu(buff   , 1, 1);
          part2 = getbitu(buff+16, 0, 1);
          page2 = getbitu(buff+16, 1, 1);

          /* skip alert page */
          if (page1== 1 || page2== 1) return -1;

          /* test even-odd parts */
          if (part1!=0||part2!=1)
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"), "Ublox: ubx rawsfrbx gal page even/odd error: sat=" << ephem->sat);
            return false;
          }
          /* test crc (4(pad) + 114 + 82 bits) */
          for (i=0,j=  4;i<15;i++,j+=8) setbitu(crc_buff,j,8,getbitu(buff   ,i*8,8));
          for (i=0,j=118;i<11;i++,j+=8) setbitu(crc_buff,j,8,getbitu(buff+16,i*8,8));
          if (crc24q(crc_buff,25) != getbitu(buff+16,82,24))
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"), "UBlox: ubx rawsfrbx gal page crc error: sat=" << ephem->sat);
            return false;
          }
          type=getbitu(buff,2,6); /* word type */

          /* skip word except for ephemeris, iono, utc parameters */
          if (type>6) return -1;

          /* clear word 0-6 flags */
          if (type==2) subfrm_[ephem->sat-1][112]=0;

          /* save page data (112:even + 16:odd bits) to frame buffer */
          k=type*16;
          for (i=0,j=2;i<14;i++,j+=8) subfrm_[ephem->sat-1][k++]=getbitu(buff   ,j,8);
          for (i=0,j=2;i< 2;i++,j+=8) subfrm_[ephem->sat-1][k++]=getbitu(buff+16,j,8);

          /* test word 0-6 flags */
          subfrm_[ephem->sat-1][112]|=(1<<type);
          if (subfrm_[ephem->sat-1][112]!=0x7F) return -1;

          return decode_GAL_ephem(ephem); // I/NAV;
        }

        inline int decode_BDS_subframe(const std::vector<uint32_t>& dwrd,
                                       const EphemPtr& ephem,
                                       uint32_t prn,
                                       std::vector<double> &iono_params)
        {
          if(dwrd.size() != 10)
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"),
                               "UBLOX: Can't decode BDS subframe with size: " << dwrd.size());
            return -1;
          }

          uint32_t words[10];

          for(size_t i = 0; i < 10; i++)
            words[i] = dwrd[i] & 0x3FFFFFFF;

          uint32_t i, id, pgn;
          id= (words[0]>>12) & 0x07; /* subframe id (3bit) */

          if (id<1||5<id)
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"),
                               "UBLOX: ubx rawsfrbx subfrm id error: sat=" << ephem->sat);
            return -1;
          }

          if (prn>5&&prn<59) { /* IGSO/MEO  */

            for (i=0;i<10;i++) {
              setbitu(subfrm_[ephem->sat-1]+(id-1)*38,i*30,30,words[i]);
            }
            if (id!=3) return -1;

            /* decode beidou D1 ephemeris */
            decode_BDS_D1_ephem(ephem, iono_params);
          }
          else { /* GEO (C01-05, C59-63) */
            if (id!=1) return -1; //只解析子帧1的d2电文

            /* subframe 1 */
            pgn=(words[1]>>14)&0x0F; /* page number (4bit) */
            if (pgn<1||10<pgn) {
              RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"),
                                 "UBLOX: ubx rawsfrbx page number error: sat=" << ephem->sat);
              return -1;
            }
            for (i=0;i<10;i++) {
              setbitu(subfrm_[ephem->sat-1]+(pgn-1)*38,i*30,30,words[i]);
            }
            if (pgn!=10) return -1;

            /* decode beidou D2 ephemeris */
            // 也可以给d2加上iono_params decode_BDS_D2_ephem(ephem, iono_params);
            decode_BDS_D2_ephem(ephem);
          }
          return 0;
        }

        inline int decode_GLO_subframe(const std::vector<uint32_t>& dwrd,
                                       const GloEphemPtr& ephem)
        {
          const auto *p = reinterpret_cast<const uint8_t*>(dwrd.data());
          uint32_t i,j,k,  m;
          uint8_t buff[64], *fid;

          for (i=k=0;i<4;i++,p+=4) for (j=0;j<4;j++) {
              buff[k++]=p[3-j];
            }

          /* test hamming of glonass string */
          if (!test_glostr(buff))
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"), "UBlox: ubx rawsfrbx glo string hamming error: sat=" << ephem->sat);
            return -1;
          }
          m=getbitu(buff,1,4); // 15个string，超出15或小于1会报错
          if (m<1||15<m)
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"), "UBlox: ubx rawsfrbx glo string no error: sat=" << ephem->sat);
            return -1;
          }
          /* flush frame buffer if frame-id changed */
          fid=subfrm_[ephem->sat-1]+150;
          if (fid[0] != buff[12] || fid[1] != buff[13]) {
            for (i = 0; i < 4; i++)
              memset(subfrm_[ephem->sat - 1] + i * 10, 0, 10);
            memcpy(fid,buff+12,2); /* save frame-id */
          }
          memcpy(subfrm_[ephem->sat-1] + (m-1) * 10, buff, 10);

          if (m!=4) return 0;
          /* decode glonass ephemeris strings */
          decode_GLO_ephem(ephem);
          return 0;
        }


    private:
        double  lock_time_rec_[MAX_SAT][N_FREQ]; /* lock time (s) */
        uint8_t halfc_rec_[MAX_SAT][N_FREQ];    /* half-cycle add flag */
        uint8_t subfrm_[MAX_SAT][380];     /* subframe buffer */
        gtime_t curr_time_;
        std::mutex mutex_;

    private:
        int decode_GPS_ephem(const EphemPtr& ephem)
        {
          uint8_t *frame_buf = subfrm_[ephem->sat];
          // check if subframe1,2,3 are received or not
          for (uint32_t i = 0; i < 3; ++i)
          {
            if (getbitu(frame_buf+30*i, 43, 3) != i+1)
              return static_cast<int>(i+1);
            if (i != 0 && (getbitu(frame_buf+30*i-30, 24, 17)+1) != getbitu(frame_buf+30*i, 24, 17))
              return -2;      // z count discontinue
          }
          // LOG(FATAL) << "decoding  GPS ephem";
          // decode subframe 1
          double tow          = getbitu(frame_buf, 24, 17) * 6.0; // truncated tow count unit (6 sec), tow count unit (1.5 sec)
          uint32_t off = 48;
          uint32_t week       = getbitu(frame_buf, off, 10);          off += 10;

          off += 2; // skip signal code
          uint8_t urai        = getbitu(frame_buf, off, 4);           off += 4;
          ephem->ura          = (urai < 6) ? pow(2, urai/2.0+1) : (1<<(urai-2));
          ephem->health       = getbitu(frame_buf, off, 6);           off += 6;
          uint32_t iodc0      = getbitu(frame_buf, off, 2);           off += 2;
          off += 1+87;
          int tgd             = getbits(frame_buf, off, 8);           off += 8;
          uint32_t iodc1      = getbitu(frame_buf, off, 8);           off += 8;
          double toc          = getbitu(frame_buf, off, 16) * 16.0;   off += 16;
          ephem->af2          = getbits(frame_buf, off, 8)  * P2_55;  off += 8;
          ephem->af1          = getbits(frame_buf, off, 16) * P2_43;  off += 16;
          ephem->af0          = getbits(frame_buf, off, 22) * P2_31;

          ephem->tgd[0]       = (tgd == -128 ? 0.0 : tgd*P2_31);// 10000000表示
          ephem->iodc         = (iodc0<<8) + iodc1;
          // ephem->week      = adjgpsweek(week);
          ephem->week         = week + 1024 * GPS_WEEK_ROLLOVER_N;     // adjust GPS week
          ephem->ttr          = gpst2time(ephem->week, tow);
          ephem->toc          = gpst2time(ephem->week, toc);

          // decode subframe 2
          frame_buf += 30; // offset 30bytes
          off = 48;
          ephem->iode         = getbitu(frame_buf, off, 8);                   off += 8;
          ephem->crs          = getbits(frame_buf, off, 16) * P2_5;           off += 16;
          ephem->delta_n      = getbits(frame_buf, off, 16) * P2_43*SC2RAD;   off += 16;
          ephem->M0           = getbits(frame_buf, off, 32) * P2_31*SC2RAD;   off += 32;
          ephem->cuc          = getbits(frame_buf, off, 16) * P2_29;          off += 16;
          ephem->e            = getbitu(frame_buf, off, 32) * P2_33;          off += 32;
          ephem->cus          = getbits(frame_buf, off, 16) * P2_29;          off += 16;
          double sqrtA        = getbitu(frame_buf, off, 32) * P2_19;          off += 32;
          ephem->toe_tow      = getbitu(frame_buf, off, 16) * 16.0;           off += 16;
          ephem->A            = sqrtA * sqrtA;

          // decode subframe 3
          frame_buf += 30;
          off = 48;
          ephem->cic          = getbits(frame_buf, off, 16) * P2_29;          off += 16;
          ephem->OMG0         = getbits(frame_buf, off, 32) * P2_31*SC2RAD;   off += 32;
          ephem->cis          = getbits(frame_buf, off, 16) * P2_29;          off += 16;
          ephem->i0           = getbits(frame_buf, off, 32) * P2_31*SC2RAD;   off += 32;
          ephem->crc          = getbits(frame_buf, off, 16) * P2_5;           off += 16;
          ephem->omg          = getbits(frame_buf, off, 32) * P2_31*SC2RAD;   off += 32;
          ephem->OMG_dot      = getbits(frame_buf, off, 24) * P2_43*SC2RAD;   off += 24;
          uint32_t iode       = getbitu(frame_buf, off, 8);                   off += 8;
          ephem->i_dot        = getbits(frame_buf, off, 14) * P2_43*SC2RAD;

          /* check iode and iodc consistency */
          if (iode != ephem->iode || iode != (ephem->iodc & 0xFF)) return -1;

          /* adjustment for week handover */
          tow = time2gpst(ephem->ttr, &ephem->week);
          toc = time2gpst(ephem->toc, nullptr);
          if      (ephem->toe_tow < tow-302400.0) {ephem->week++; tow -= 604800.0;}
          else if (ephem->toe_tow > tow+302400.0) {ephem->week--; tow += 604800.0;}
          ephem->toe = gpst2time(ephem->week, ephem->toe_tow);
          ephem->toc = gpst2time(ephem->week, toc);
          ephem->ttr = gpst2time(ephem->week, tow);
          //curr_time = ephem->ttr;      // update current time
          return 0;
        }

        int decode_GAL_ephem(const EphemPtr& ephem)
        {
          // I/NAV message
          double tow,toc,tt,sqrtA, toes;
          uint32_t i,time_f,svid,e5b_hs,e1b_hs,e5b_dvs,e1b_dvs,type[6],iod_nav[4];
          int week;
          uint8_t *buff = subfrm_[ephem->sat-1];
          i=0; /* word type 0 */
          type[0]    =getbitu(buff,i, 6);              i+= 6;
          time_f     =getbitu(buff,i, 2);              i+= 2+88;
          week       =getbitu(buff,i,12);              i+=12; /* gst-week */
          tow        =getbitu(buff,i,20);

          i=128; /* I/NAV word type 1  */
          type[1]    =getbitu(buff,i, 6);              i+= 6;
          iod_nav[0] =getbitu(buff,i,10);              i+=10;
          toes       =getbitu(buff,i,14)*60.0;         i+=14;
          ephem->M0  =getbits(buff,i,32)*P2_31*SC2RAD; i+=32;
          ephem->e   =getbitu(buff,i,32)*P2_33;        i+=32;
          sqrtA      =getbitu(buff,i,32)*P2_19;

          i=128*2; /* word type 2 */
          type[2]    =getbitu(buff,i, 6);              i+= 6;
          iod_nav[1] =getbitu(buff,i,10);              i+=10;
          ephem->OMG0=getbits(buff,i,32)*P2_31*SC2RAD; i+=32;
          ephem->i0  =getbits(buff,i,32)*P2_31*SC2RAD; i+=32;
          ephem->omg =getbits(buff,i,32)*P2_31*SC2RAD; i+=32;
          ephem->i_dot=getbits(buff,i,14)*P2_43*SC2RAD;

          i=128*3; /* word type 3 */
          type[3]         =getbitu(buff,i, 6);              i+= 6;
          iod_nav[2]      =getbitu(buff,i,10);              i+=10;
          ephem->OMG_dot  =getbits(buff,i,24)*P2_43*SC2RAD; i+=24;
          ephem->delta_n  =getbits(buff,i,16)*P2_43*SC2RAD; i+=16;
          ephem->cuc      =getbits(buff,i,16)*P2_29;        i+=16;
          ephem->cus      =getbits(buff,i,16)*P2_29;        i+=16;
          ephem->crc      =getbits(buff,i,16)*P2_5;         i+=16;
          ephem->crs      =getbits(buff,i,16)*P2_5;         i+=16;
          uint32_t sisa   =getbitu(buff,i, 8);
          if (sisa < 50)       ephem->ura = 0.01*sisa;
          else if (sisa < 75)  ephem->ura = 0.5+0.02*(sisa-50);
          else if (sisa < 100) ephem->ura = 1.0+0.04*(sisa-75);
          else if (sisa < 125) ephem->ura = 2.0+0.16*(sisa-100);
          else                 ephem->ura = -1.0;

          i=128*4; /* word type 4 */
          type[4]         =getbitu(buff,i, 6);              i+= 6;
          iod_nav[3]      =getbitu(buff,i,10);              i+=10;
          svid            =getbitu(buff,i, 6);              i+= 6;
          ephem->cic      =getbits(buff,i,16)*P2_29;        i+=16;
          ephem->cis      =getbits(buff,i,16)*P2_29;        i+=16;
          toc             =getbitu(buff,i,14)*60.0;         i+=14;
          ephem->af0      =getbits(buff,i,31)*P2_34;        i+=31;
          ephem->af1      =getbits(buff,i,21)*P2_46;        i+=21;
          ephem->af2      =getbits(buff,i, 6)*P2_59;

          i=128*5; /* word type 5 */
          type[5]         =getbitu(buff,i, 6);              i+= 6+41;
          ephem->tgd[0]   =getbits(buff,i,10)*P2_32;        i+=10; /* BGD E5a/E1 */
          ephem->tgd[1]   =getbits(buff,i,10)*P2_32;        i+=10; /* BGD E5b/E1 */
          e5b_hs          =getbitu(buff,i, 2);              i+= 2;
          e1b_hs          =getbitu(buff,i, 2);              i+= 2;
          e5b_dvs         =getbitu(buff,i, 1);              i+= 1;
          e1b_dvs         =getbitu(buff,i, 1);

          /* test word types */
          if (type[0]!=0||type[1]!=1||type[2]!=2||type[3]!=3||type[4]!=4||type[5]!=5)
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"), "UBlox: decode gal inav error: type=" << type[0] << ' ' << type[1]
                       << ' ' << type[2] << ' ' << ' ' << type[3] << ' '  << type[4]
                       << ' ' << type[5]);
            return -1;
          }
          /* test word type 0 time field */
          if (time_f!=2)
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"), "UBlox: decode_gal_inav error: word0-time=" << time_f);
            return -1;
          }
          /* test consistency of iod_nav */
          if (iod_nav[0]!=iod_nav[1]||iod_nav[0]!=iod_nav[2]||iod_nav[0]!=iod_nav[3]) {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"), "UBlox: decode_gal_inav error: ionav=" << iod_nav[0] << ' '
                       << iod_nav[1] << ' ' << iod_nav[2] << ' ' << iod_nav[3]);

            return -1;
          }
          if (ephem->sat != sat_no(SYS_GAL,svid))
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"), "UBlox: decode_gal_inav svid error: svid=" << svid);
            return -1;
          }
          ephem->A=sqrtA*sqrtA;
          ephem->iode=ephem->iodc=iod_nav[0];
          ephem->health=(e5b_hs<<7)|(e5b_dvs<<6)|(e1b_hs<<1)|e1b_dvs;
          ephem->ttr=gst2time(week,tow);
          tt=time_diff(gst2time(week,toes),ephem->ttr); /* week complient to toe */
          if      (tt> 302400.0) week--;
          else if (tt<-302400.0) week++;
          ephem->toe=gst2time(week,toes);
          ephem->toc=gst2time(week,toc);
          ephem->toe_tow = time2gpst(ephem->toe, &ephem->week);
          ephem->code =(1<<0)|(1<<9); /* data source = i/nav e1b, af0-2,toc,sisa for e5b-e1 */
          //curr_time = ephem->ttr;      // update current time
          memset(subfrm_[ephem->sat-1], 0, 380);
          return 0;
        }

        int decode_BDS_D2_ephem(const EphemPtr& ephem)
        {
          double toc_bds,sqrtA;
          uint32_t f1p4,cucp5,ep6,cicp7,i0p8,OMGdp9,omgp10;
          uint32_t bdt_week,toes,sow1,sow3,sow4,sow5,sow6,sow7,sow8,sow9,sow10;
          int i,f1p3,cucp4,ep5,cicp6,i0p7,OMGdp8,omgp9;
          uint32_t pgn1,pgn3,pgn4,pgn5,pgn6,pgn7,pgn8,pgn9,pgn10;

          // LOG(INFO) << "decode_bds_d2";
          uint8_t *buff = subfrm_[ephem->sat-1];
          i=8*38*0; /* page 1 */
          pgn1            =getbitu (buff,i+ 42, 4);
          sow1            =getbitu2(buff,i+ 18, 8,i+ 30,12);
          ephem->health   =getbitu (buff,i+ 46, 1); /* SatH1 */
          ephem->iodc     =getbitu (buff,i+ 47, 5); /* AODC */
          uint8_t urai    =getbitu (buff,i+ 60, 4);
          ephem->ura      = (urai < 6) ? pow(2, urai/2.0+1) : (1<<(urai-2));
          bdt_week        =getbitu (buff,i+ 64,13); /* week in BDT */
          toc_bds         =getbitu2(buff,i+ 77, 5,i+ 90,12)*8.0;
          ephem->tgd[0]   =getbits (buff,i+102,10)*0.1*1E-9;
          ephem->tgd[1]   =getbits (buff,i+120,10)*0.1*1E-9;

          //缺少page2

          i=8*38*2; /* page 3 */
          pgn3            =getbitu (buff,i+ 42, 4);
          sow3            =getbitu2(buff,i+ 18, 8,i+ 30,12);
          ephem->af0      =getbits2(buff,i+100,12,i+120,12)*P2_33;
          f1p3            =getbits (buff,i+132,4);

          i=8*38*3; /* page 4 */
          pgn4            =getbitu (buff,i+ 42, 4);
          sow4            =getbitu2(buff,i+ 18, 8,i+ 30,12);
          f1p4            =getbitu2(buff,i+ 46, 6,i+ 60,12);
          ephem->af2      =getbits2(buff,i+ 72,10,i+ 90, 1)*P2_66;
          ephem->iode     =getbitu (buff,i+ 91, 5); /* AODE */
          ephem->delta_n  =getbits (buff,i+ 96,16)*P2_43*SC2RAD;
          cucp4           =getbits (buff,i+120,14);

          i=8*38*4; /* page 5 */
          pgn5            =getbitu (buff,i+ 42, 4);
          sow5            =getbitu2(buff,i+ 18, 8,i+ 30,12);
          cucp5           =getbitu (buff,i+ 46, 4);
          ephem->M0       =getbits3(buff,i+ 50, 2,i+ 60,22,i+ 90, 8)*P2_31*SC2RAD;
          ephem->cus      =getbits2(buff,i+ 98,14,i+120, 4)*P2_31;
          ep5             =getbits (buff,i+124,10);

          i=8*38*5; /* page 6 */
          pgn6            =getbitu (buff,i+ 42, 4);
          sow6            =getbitu2(buff,i+ 18, 8,i+ 30,12);
          ep6             =getbitu2(buff,i+ 46, 6,i+ 60,16);
          sqrtA           =getbitu3(buff,i+ 76, 6,i+ 90,22,i+120,4)*P2_19;
          cicp6           =getbits (buff,i+124,10);
          ephem->A        =sqrtA*sqrtA;

          i=8*38*6; /* page 7 */
          pgn7            =getbitu (buff,i+ 42, 4);
          sow7            =getbitu2(buff,i+ 18, 8,i+ 30,12);
          cicp7           =getbitu2(buff,i+ 46, 6,i+ 60, 2);
          ephem->cis      =getbits (buff,i+ 62,18)*P2_31;
          toes            =getbitu2(buff,i+ 80, 2,i+ 90,15)*8.0;
          i0p7            =getbits2(buff,i+105, 7,i+120,14);

          i=8*38*7; /* page 8 */
          pgn8            =getbitu (buff,i+ 42, 4);
          sow8            =getbitu2(buff,i+ 18, 8,i+ 30,12);
          i0p8            =getbitu2(buff,i+ 46, 6,i+ 60, 5);
          ephem->crc      =getbits2(buff,i+ 65,17,i+ 90, 1)*P2_6;
          ephem->crs      =getbits (buff,i+ 91,18)*P2_6;
          OMGdp8          =getbits2(buff,i+109, 3,i+120,16);

          i=8*38*8; /* page 9 */
          pgn9            =getbitu (buff,i+ 42, 4);
          sow9            =getbitu2(buff,i+ 18, 8,i+ 30,12);
          OMGdp9          =getbitu (buff,i+ 46, 5);
          ephem->OMG0     =getbits3(buff,i+ 51, 1,i+ 60,22,i+ 90, 9)*P2_31*SC2RAD;
          omgp9           =getbits2(buff,i+ 99,13,i+120,14);

          i=8*38*9; /* page 10 */
          pgn10           =getbitu (buff,i+ 42, 4);
          sow10           =getbitu2(buff,i+ 18, 8,i+ 30,12);
          omgp10          =getbitu (buff,i+ 46, 5);
          ephem->i_dot    =getbits2(buff,i+ 51, 1,i+ 60,13)*P2_43*SC2RAD;

          /* check consistency of page numbers, sows and toe/toc */
          if (pgn1!=1||pgn3!=3||pgn4!=4||pgn5!=5||pgn6!=6||pgn7!=7||pgn8!=8||pgn9!=9||
              pgn10!=10) {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"),
                               "UBLOX: decode_bds_d2 error: pgn=" << pgn1 << ' ' << pgn3 << ' '
                       << pgn4 << ' ' << pgn5 << ' ' << pgn6 << ' ' << pgn7 << ' '
                       << pgn8 << ' ' << pgn9 << ' ' << pgn10);
            return -1;
          }
          if (sow3!=sow1+6||sow4!=sow3+3||sow5!=sow4+3||sow6!=sow5+3||
              sow7!=sow6+3||sow8!=sow7+3||sow9!=sow8+3||sow10!=sow9+3) {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"),
                               "UBLOX: decode_bds_d2 error: sow=" << sow1 << ' ' << sow3 << ' '
                       << sow4 << ' ' << sow5 << ' ' << sow6 << ' ' << sow7 << ' '
                       << sow8 << ' ' << sow9 << ' ' << sow10);
            return -1;
          }
          if (toc_bds!=toes) {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"),
                               "UBLOX: decode_bds_d2 error: toe=" << toes << " toc=" << toc_bds);
            return -1;
          }
          ephem->af1      = merge_two_s(f1p3  ,f1p4  ,18)*P2_50;
          ephem->cuc      = merge_two_s(cucp4 ,cucp5 , 4)*P2_31;
          ephem->e        = merge_two_s(ep5   ,ep6   ,22)*P2_33;
          ephem->cic      = merge_two_s(cicp6 ,cicp7 , 8)*P2_31;
          ephem->i0       = merge_two_s(i0p7  ,i0p8  ,11)*P2_31*SC2RAD;
          ephem->OMG_dot  = merge_two_s(OMGdp8,OMGdp9, 5)*P2_43*SC2RAD;
          ephem->omg      = merge_two_s(omgp9 ,omgp10, 5)*P2_31*SC2RAD;

          ephem->ttr      = bdt2time(bdt_week,sow1);
          ephem->ttr      = time_add(ephem->ttr, 14.0);
          if      (toes>sow1+302400.0) bdt_week++;
          else if (toes<sow1-302400.0) bdt_week--;
          ephem->toe      = bdt2time(bdt_week,toes);
          ephem->toe      = time_add(ephem->toe, 14.0);
          ephem->toe_tow  = time2gpst(ephem->toe, &ephem->week);
          ephem->toc      = bdt2time(bdt_week,toc_bds);
          ephem->toc      = time_add(ephem->toc, 14.0);
          ephem->code     = 0; /* data source = unknown */
          //curr_time       = ephem->ttr;      // update current time
          return 0;
        }

        int decode_BDS_D1_ephem(const EphemPtr& ephem, std::vector<double> &iono_params)
        {
          std::vector<double> tmp_iono_params;
          double toc_bds,sqrtA;
          uint32_t bdt_week,toes,toe1,toe2,sow1,sow2,sow3;
          uint32_t i,frn1,frn2,frn3;
          // LOG(INFO) << "decode_bds_d1";
          uint8_t *buff = subfrm_[ephem->sat-1];
          i=8*38*0; /* subframe 1 */
          frn1            =getbitu (buff,i+ 15, 3);
          sow1            =getbitu2(buff,i+ 18, 8,i+30,12);
          ephem->health   =getbitu (buff,i+ 42, 1); /* SatH1 */
          ephem->iodc     =getbitu (buff,i+ 43, 5); /* AODC */
          uint8_t urai    =getbitu (buff,i+ 48, 4);
          ephem->ura      = (urai < 6) ? pow(2, urai/2.0+1) : (1<<(urai-2));
          bdt_week        =getbitu (buff,i+ 60,13); /* week in BDT */
          toc_bds         =getbitu2(buff,i+ 73, 9,i+ 90, 8)*8.0;
          ephem->tgd[0]   =getbits (buff,i+ 98,10)*0.1*1E-9;
          ephem->tgd[1]   =getbits2(buff,i+108, 4,i+120, 6)*0.1*1E-9;
          tmp_iono_params.push_back(getbits (buff, i+126, 8)*P2_30); //alpha_0
          tmp_iono_params.push_back(getbits (buff, i+134, 8)*P2_27); //alpha_1
          tmp_iono_params.push_back(getbits (buff, i+150, 8)*P2_24); //alpha_2
          tmp_iono_params.push_back(getbits (buff, i+158, 8)*P2_24); //alpha_3
          tmp_iono_params.push_back(getbits2(buff,i+166, 6,i+180, 2)*(1<<11)); //beta_0
          tmp_iono_params.push_back(getbits (buff, i+182, 8)*(1<<14)); //beta_1
          tmp_iono_params.push_back(getbits (buff, i+190, 8)*(1<<16)); //beta_2
          tmp_iono_params.push_back(getbits2(buff,i+198, 4,i+210, 4)*(1<<16)); //beta_3
          ephem->af2      =getbits (buff,i+214,11)*P2_66;
          ephem->af0      =getbits2(buff,i+225, 7,i+240,17)*P2_33;
          ephem->af1      =getbits2(buff,i+257, 5,i+270,17)*P2_50;
          ephem->iode     =getbitu (buff,i+287, 5); /* AODE */

          i=8*38*1; /* subframe 2 */
          frn2            =getbitu (buff,i+ 15, 3);
          sow2            =getbitu2(buff,i+ 18, 8,i+30,12);
          ephem->delta_n  =getbits2(buff,i+ 42,10,i+ 60, 6)*P2_43*SC2RAD;
          ephem->cuc      =getbits2(buff,i+ 66,16,i+ 90, 2)*P2_31;
          ephem->M0       =getbits2(buff,i+ 92,20,i+120,12)*P2_31*SC2RAD;
          ephem->e        =getbitu2(buff,i+132,10,i+150,22)*P2_33;
          ephem->cus      =getbits (buff,i+180,18)*P2_31;
          ephem->crc      =getbits2(buff,i+198, 4,i+210,14)*P2_6;
          ephem->crs      =getbits2(buff,i+224, 8,i+240,10)*P2_6;
          sqrtA           =getbitu2(buff,i+250,12,i+270,20)*P2_19;
          toe1            =getbitu (buff,i+290, 2); /* TOE 2-MSB */
          ephem->A        =sqrtA*sqrtA;

          i=8*38*2; /* subframe 3 */
          frn3            =getbitu (buff,i+ 15, 3);
          sow3            =getbitu2(buff,i+ 18, 8,i+30,12);
          toe2            =getbitu2(buff,i+ 42,10,i+ 60, 5); /* TOE 5-LSB */
          ephem->i0       =getbits2(buff,i+ 65,17,i+ 90,15)*P2_31*SC2RAD;
          ephem->cic      =getbits2(buff,i+105, 7,i+120,11)*P2_31;
          ephem->OMG_dot  =getbits2(buff,i+131,11,i+150,13)*P2_43*SC2RAD;
          ephem->cis      =getbits2(buff,i+163, 9,i+180, 9)*P2_31;
          ephem->i_dot    =getbits2(buff,i+189,13,i+210, 1)*P2_43*SC2RAD;
          ephem->OMG0     =getbits2(buff,i+211,21,i+240,11)*P2_31*SC2RAD;
          ephem->omg      =getbits2(buff,i+251,11,i+270,21)*P2_31*SC2RAD;
          toes            =merge_two_u(toe1,toe2,15)*8.0;

          /* check consistency of subframe numbers, sows and toe/toc */
          if (frn1!=1||frn2!=2||frn3!=3)
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"),
                               "UBLOX: decode_bds_d1 error: frn=" << frn1 << ' ' << frn2 << ' ' << frn3);
            return -1;
          }
          if (sow2!=sow1+6||sow3!=sow2+6)
          {
            // LOG(ERROR) << "decode_bds_d1 error: sow=" << sow1 << ' ' << sow2 << ' ' << sow3;
            return -1;
          }
          if (toc_bds!=toes) //没懂
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"),
                               "UBLOX: decode_bds_d1 error: toe=" << toes << " toc=" << toc_bds);
            return -1;
          }
          ephem->ttr      = bdt2time(bdt_week,sow1);
          ephem->ttr      = time_add(ephem->ttr, 14.0);
          if      (toes>sow1+302400.0) bdt_week--;
          else if (toes<sow1-302400.0) bdt_week++;
          ephem->toe      = bdt2time(bdt_week,toes);
          ephem->toe      = time_add(ephem->toe, 14.0);
          ephem->toe_tow  = time2gpst(ephem->toe, &(ephem->week));
          ephem->toc      = bdt2time(bdt_week,toc_bds);
          ephem->toc      = time_add(ephem->toc, 14.0);
          ephem->code     = 0; /* data source = unknown */
          //curr_time       = ephem->ttr;      // update current time
          iono_params.swap(tmp_iono_params);
          return 0;
        }

        int decode_GLO_ephem(const GloEphemPtr& glo_ephem)
        {
          double tow,tod,tof,toe;
          uint32_t tk_h,tk_m,tk_s,tb,slot;
          uint32_t week;
          uint32_t i=1,frn1,frn2,frn3,frn4;

          // LOG(INFO) << "decode_glostr";
          uint8_t *buff = subfrm_[glo_ephem->sat-1];
          /* frame 1 (equal to string 1)*/
          frn1                =getbitu(buff,i, 4);           i+= 4+2;
          getbitu(buff,i, 2);           i+= 2;       // skip
          tk_h                =getbitu(buff,i, 5);           i+= 5;
          tk_m                =getbitu(buff,i, 6);           i+= 6;
          tk_s                =getbitu(buff,i, 1)*30;        i+= 1;
          glo_ephem->vel[0]   =getbitg(buff,i,24)*P2_20*1E3; i+=24;
          glo_ephem->acc[0]   =getbitg(buff,i, 5)*P2_30*1E3; i+= 5;
          glo_ephem->pos[0]   =getbitg(buff,i,27)*P2_11*1E3; i+=27+4;

          /* frame 2 */
          frn2                =getbitu(buff,i, 4);           i+= 4;       // frn equals to strin number
          glo_ephem->health   =getbitu(buff,i, 3);           i+= 3;
          getbitu(buff,i, 1);           i+= 1;       // skip
          tb                  =getbitu(buff,i, 7);           i+= 7+5;
          glo_ephem->vel[1]   =getbitg(buff,i,24)*P2_20*1E3; i+=24;
          glo_ephem->acc[1]   =getbitg(buff,i, 5)*P2_30*1E3; i+= 5;
          glo_ephem->pos[1]   =getbitg(buff,i,27)*P2_11*1E3; i+=27+4;

          /* frame 3 */
          frn3                =getbitu(buff,i, 4);           i+= 4;
          getbitu(buff,i, 1);           i+= 1;       // skip
          glo_ephem->gamma    =getbitg(buff,i,11)*P2_40;     i+=11+1;
          getbitu(buff,i, 2);           i+= 2;       // skip
          getbitu(buff,i, 1);           i+= 1;       // skip
          glo_ephem->vel[2]   =getbitg(buff,i,24)*P2_20*1E3; i+=24;
          glo_ephem->acc[2]   =getbitg(buff,i, 5)*P2_30*1E3; i+= 5;
          glo_ephem->pos[2]   =getbitg(buff,i,27)*P2_11*1E3; i+=27+4;

          /* frame 4 */
          frn4                    =getbitu(buff,i, 4);           i+= 4;
          glo_ephem->tau_n        =getbitg(buff,i,22)*P2_30;     i+=22;
          glo_ephem->delta_tau_n  =getbitg(buff,i, 5)*P2_30;     i+= 5;
          glo_ephem->age          =getbitu(buff,i, 5);           i+= 5+14;
          getbitu(buff,i, 1);           i+= 1;   // skip
          uint32_t ft             =getbitu(buff,i, 4);           i+= 4+3;
          getbitu(buff,i,11);           i+=11;   // skip
          slot                    =getbitu(buff,i, 5);           i+= 5;
          getbitu(buff,i, 2);                    // skip

          if (ft == 2)        glo_ephem->ura = 2.5;
          else if (ft < 5)    glo_ephem->ura = ft+1.0;
          else if (ft == 5)   glo_ephem->ura = 7.0;
          else if (ft < 10)   glo_ephem->ura = 10.0+(ft-6)*2.0;
          else if (ft < 15)   glo_ephem->ura = 1 << (ft-5);
          else                glo_ephem->ura = -1.0;

          if (frn1!=1||frn2!=2||frn3!=3||frn4!=4)
          {
            // LOG(ERROR) << "decode_GLO_ephem error: frn=" << frn1 << ' '
            //            << frn2 << ' ' << frn3 << ' ' << frn4;
            return -1;
          }
          if (glo_ephem->sat != sat_no(SYS_GLO,slot))
          {
            RCLCPP_WARN_STREAM(rclcpp::get_logger("GNSSPreProcessorStandaloneNode"), "UBlox: decode_GLO_ephem error: slot=" << slot);
            return -1;
          }
          glo_ephem->iode=tb;
          tow=time2gpst(gpst2utc(curr_time_), &week);
          tod=fmod(tow,86400.0); tow-=tod;
          tof=tk_h*3600.0+tk_m*60.0+tk_s-10800.0; /* lt->utc */ //tof: message frame time
          if      (tof<tod-43200.0) tof+=86400.0;
          else if (tof>tod+43200.0) tof-=86400.0;
          glo_ephem->ttr=utc2gpst(gpst2time(week,tow+tof));
          toe=tb*900.0-10800.0; /* lt->utc */
          if      (toe<tod-43200.0) toe+=86400.0;
          else if (toe>tod+43200.0) toe-=86400.0;
          glo_ephem->toe=utc2gpst(gpst2time(week,tow+toe)); /* utc->gpst */
          return 0;
        }

        inline static void setbitu(uint8_t *buff, const uint32_t pos, const uint32_t len, uint32_t data)
        {
          if (len == 0 || len > 32)   return;
          uint32_t mask = 1u << (len-1);
          for (uint32_t i = pos; i < pos+len; ++i, mask>>=1)
          {
            if (data & mask)
              buff[i/8] |= (1u<<(7-i%8));
            else
              buff[i/8] &= ~(1u<<(7-i%8));
          }
        };

        inline static uint32_t getbitu(const uint8_t *buff, const uint32_t pos, const uint32_t len)
        {
          uint32_t bits = 0;
          for (size_t i = pos; i < pos+len; ++i)
            bits = (bits<<1) + ((buff[i/8]>>(7-i%8))&1u);
          return bits;
        };

        inline static int getbits(const uint8_t *buff, const uint32_t pos, const uint32_t len)
        {
          uint32_t bits = getbitu(buff, pos, len);
          if (len == 0 || len >= 32 || !(bits&(1u<<(len-1)))) return (int)bits;
          return (int)(bits|(~0u<<len));  // extend sign
        };

        /* get two component bits ----------------------------------------------------*/
        inline static uint32_t getbitu2(const uint8_t *buff, const uint32_t p1, const uint32_t l1,
                          const uint32_t p2, const uint32_t l2)
        {
          return (getbitu(buff,p1,l1)<<l2)+getbitu(buff,p2,l2);
        };

        inline int getbits2(const uint8_t *buff, const uint32_t p1, const uint32_t l1,
                     const uint32_t p2, const uint32_t l2) const
        {
          if (getbitu(buff,p1,1))
            return (int)((getbits(buff,p1,l1)<<l2)+getbitu(buff,p2,l2));
          else
            return (int)getbitu2(buff,p1,l1,p2,l2);
        };

        /* get three component bits --------------------------------------------------*/
        inline static uint32_t getbitu3(const uint8_t *buff, const uint32_t p1, const uint32_t l1,
                          const uint32_t p2, const uint32_t l2, const uint32_t p3, const uint32_t l3)
        {
          return (getbitu(buff,p1,l1)<<(l2+l3))+(getbitu(buff,p2,l2)<<l3)+ getbitu(buff,p3,l3);
        };

        static inline int getbits3(const uint8_t *buff, const uint32_t p1, const uint32_t l1, const uint32_t p2,
                     const uint32_t l2, const uint32_t p3, const uint32_t l3)
        {
          if (getbitu(buff,p1,1))
            return (int)((getbits(buff,p1,l1)<<(l2+l3))+
                         (getbitu(buff,p2,l2)<<l3)+getbitu(buff,p3,l3));
          else
            return (int)getbitu3(buff,p1,l1,p2,l2,p3,l3);
        };

        inline static double getbitg(const uint8_t *buff, const int pos, const int len)
        {
          double value=getbitu(buff,pos+1,len-1);
          return getbitu(buff,pos,1)?-value:value;
        };

        inline static uint32_t merge_two_u(const uint32_t a, const uint32_t b, const uint32_t n)
        {
          return (a<<n)+b;
        };
        inline static int merge_two_s(const int a, const uint8_t b, const int n)
        {
          return (int)((a<<n)+b);
        };

        inline static bool check_checksum(const uint8_t *data, const uint32_t size)
        {
          uint8_t cka = 0, ckb = 0;
          for (uint32_t i = 2;i < size-2; ++i)
          {
            cka += data[i];
            ckb += cka;
          }
          return cka == data[size-2] && ckb == data[size-1];
        };

        inline static bool verify_msg(const uint8_t *data, const size_t len)
        {
          if (len < 8)  // ubx header length is 6, checksum length is 2
          {
            LOG(ERROR) << "Invalid message length ";
            return false;
          }

          if (data[0] != 0xB5 || data[1] != 0x62)
          {
            LOG(ERROR) << "Invalid ublox message preamble.";
            return false;
          }

          uint16_t payload_len = *reinterpret_cast<const uint16_t*>(data+4);
          if (len != payload_len + MSG_HEADER_LEN + 2)
          {
            LOG(ERROR) << "Invalid message length.";
            return false;
          }

          if (!check_checksum(data, len))
          {
            //LOG(ERROR) << "Invalid checksum.\n";
            return false;
          }

          return true;
        };

        inline static void set_checksum(uint8_t *data, const uint32_t size)
        {
          uint8_t cka = 0, ckb = 0;
          for (uint32_t i = 2; i < size-2; ++i)
          {
            cka += data[i];
            ckb += cka;
          }
          data[size-2] = cka;
          data[size-1] = ckb;
        };

        inline uint32_t crc24q(const uint8_t *data, const uint32_t size) const
        {
          uint32_t crc = 0;
          for (uint32_t i = 0; i < size; ++i)
            crc = ( (crc<<8) & 0xFFFFFF) ^ tbl_CRC24Q[ (crc>>16) ^ data[i]];
          return crc;
        }

        inline int test_glostr(const uint8_t *data)
        {
          static const uint8_t xor_8bit[256]={ /* xor of 8 bits */
              0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,
              1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,
              1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,
              0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,
              1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,
              0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,
              0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,
              1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0
          };
          static const uint8_t mask_hamming[][12]={ /* mask of hamming codes */
              {0x55,0x55,0x5A,0xAA,0xAA,0xAA,0xB5,0x55,0x6A,0xD8,0x08},
              {0x66,0x66,0x6C,0xCC,0xCC,0xCC,0xD9,0x99,0xB3,0x68,0x10},
              {0x87,0x87,0x8F,0x0F,0x0F,0x0F,0x1E,0x1E,0x3C,0x70,0x20},
              {0x07,0xF8,0x0F,0xF0,0x0F,0xF0,0x1F,0xE0,0x3F,0x80,0x40},
              {0xF8,0x00,0x0F,0xFF,0xF0,0x00,0x1F,0xFF,0xC0,0x00,0x80},
              {0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x01,0x00},
              {0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00},
              {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8}
          };
          uint8_t cs = 0;
          int n = 0;

          for (uint32_t i = 0; i < 8; ++i)
          {
            for (uint32_t j = 0, cs = 0; j < 11; ++j)
              cs ^= xor_8bit[data[j]&mask_hamming[i][j]];
            if (cs) n++;
          }
          return n==0 || (n==2 && cs);
        }

    };
}



#endif //IRT_GNSS_PREPROCESSING_UBLOX_COMMON_H
