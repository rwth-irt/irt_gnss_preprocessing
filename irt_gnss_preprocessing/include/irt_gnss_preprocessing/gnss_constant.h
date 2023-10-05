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

#ifndef IRT_GNSS_PREPROCESSING_GNSS_CONSTANT_H
#define IRT_GNSS_PREPROCESSING_GNSS_CONSTANT_H

namespace irt_gnss_preprocessing::constant
{

  static constexpr double RAD2SEMICIRCLES = 1 / M_PI;
    // some parameters are adapted from RTKLIB
  #define MAXFREQ     7                   /* max N_FREQ */

  #define FREQ1       1.57542E9           /* L1/E1  frequency (Hz) */
  #define FREQ2       1.22760E9           /* L2     frequency (Hz) */
  #define FREQ5       1.17645E9           /* L5/E5a frequency (Hz) */
  #define FREQ6       1.27875E9           /* E6/LEX frequency (Hz) */
  #define FREQ7       1.20714E9           /* E5b    frequency (Hz) */
  #define FREQ8       1.191795E9          /* E5a+b  frequency (Hz) */
  #define FREQ9       2.492028E9          /* S      frequency (Hz) */
  #define FREQ1_GLO   1.60200E9           /* GLONASS G1 base frequency (Hz) */
  #define DFRQ1_GLO   0.56250E6           /* GLONASS G1 bias frequency (Hz/n) */
  #define FREQ2_GLO   1.24600E9           /* GLONASS G2 base frequency (Hz) */
  #define DFRQ2_GLO   0.43750E6           /* GLONASS G2 bias frequency (Hz/n) */
  #define FREQ3_GLO   1.202025E9          /* GLONASS G3 frequency (Hz) */
  #define FREQ1_BDS   1.561098E9          /* BeiDou B1 frequency (Hz) */
  #define FREQ2_BDS   1.20714E9           /* BeiDou B2 frequency (Hz) */
  #define FREQ3_BDS   1.26852E9           /* BeiDou B3 frequency (Hz) */

  #define SYS_NONE    0x00                /* navigation system: none */
  #define SYS_GPS     0x01                /* navigation system: GPS */
  #define SYS_SBS     0x02                /* navigation system: SBAS */
  #define SYS_GLO     0x04                /* navigation system: GLONASS */
  #define SYS_GAL     0x08                /* navigation system: Galileo */
  #define SYS_QZS     0x10                /* navigation system: QZSS */
  #define SYS_BDS     0x20                /* navigation system: BeiDou */
  #define SYS_IRN     0x40                /* navigation system: IRNSS */
  #define SYS_LEO     0x80                /* navigation system: LEO */
  #define SYS_ALL     0xFF                /* navigation system: all */

  #define T_SYS_GPS       0               /* time system: GPS time */
  #define T_SYS_UTC       1               /* time system: UTC */
  #define T_SYS_GLO       2               /* time system: GLONASS time */
  #define T_SYS_GAL       3               /* time system: Galileo time */
  #define T_SYS_QZS       4               /* time system: QZSS time */
  #define T_SYS_BDS       5               /* time system: BeiDou time */

  #ifndef N_FREQ
  #define N_FREQ          3                   /* number of carrier frequencies */
  #endif
  #define N_FREQ_GLO      2                   /* number of carrier frequencies of GLONASS */

  #define MIN_PRN_GPS     1                   /* min satellite PRN number of GPS */
  #define MAX_PRN_GPS     32                  /* max satellite PRN number of GPS */
  #define N_SAT_GPS       (MAX_PRN_GPS-MIN_PRN_GPS+1) /* number of GPS satellites */
  #define N_SYS_GPS       1

      // #define MIN_PRN_GLO     38                   /* min satellite slot number of GLONASS */ For UM4B0
      // #define MAX_PRN_GLO     61                  /* max satellite slot number of GLONASS */  For UM4B0
  #define MIN_PRN_GLO     1                   /* min satellite slot number of GLONASS */
  #define MAX_PRN_GLO     27                  /* max satellite slot number of GLONASS */
  #define N_SAT_GLO       (MAX_PRN_GLO-MIN_PRN_GLO+1) /* number of GLONASS satellites */
  #define N_SYS_GLO       1

  #define MIN_PRN_GAL     1                   /* min satellite PRN number of Galileo */
  #define MAX_PRN_GAL     38                  /* max satellite PRN number of Galileo */
  #define N_SAT_GAL       (MAX_PRN_GAL-MIN_PRN_GAL+1) /* number of Galileo satellites */
  #define N_SYS_GAL       1

  #define MIN_PRN_BDS     1                   /* min satellite sat number of BeiDou */
  #define MAX_PRN_BDS     63                  /* max satellite sat number of BeiDou */
  #define N_SAT_BDS       (MAX_PRN_BDS-MIN_PRN_BDS+1) /* number of BeiDou satellites */
  #define N_SYS_BDS       1

  #define N_SYS           (N_SYS_GPS+N_SYS_GLO+N_SYS_GAL++N_SYS_BDS) /* number of systems */

  #define MAX_SAT         (N_SAT_GPS+N_SAT_GLO+N_SAT_GAL+N_SAT_BDS)

  #ifndef MAXOBS
  #define MAXOBS      64                  /* max number of obs in an epoch */
  #endif

      // solution type
      // #define SOL_COMPUTED            0
      // #define SOL_INSUFFICIENT_OBS    1
      // #define NO_CONVERGENCE          2
      // #define COV_TRACE               4

      // extend solution type
      // #define EXT_NONE                0x00
      // #define EXT_RTK                 0x01
      // #define EXT_IONO_BRDC           0x02
      // #define EXT_IONO_SBAS           0x04
      // #define EXT_IONO_IFLC           0x06
      // #define EXT_IONO_DIFF           0x08

      // position(velocity) type
  #define PV_NONE                     0               /* no solution */
  #define PV_FIXED_POS                1
  #define PV_FIXED_HEIGHT             2
  #define PV_DOPPLER_VELOCITY         8
  #define PV_SINGLE                   16
  #define PV_PSR_DIFF                 17
  #define PV_WASS                     18
  #define PV_L1_FLOAT                 32
  #define PV_IONO_FREE_FLOAT          33
  #define PV_NARROW_FLOW              34
  #define PV_L1_INT                   48
  #define PV_WIDE_INT                 49
  #define PV_NARROW_INT               50
  #define PV_INS                      52
  #define PV_INS_PSR_SP               53
  #define PV_INS_PSR_DIFF             54
  #define PV_INS_RTK_FLOAT            55
  #define PV_INS_RTK_FIXED            56

  #define CODE_NONE   0                   /* obs code: none or unknown */
  #define CODE_L1C    1                   /* obs code: L1C/A,G1C/A,E1C (GPS,GLO,GAL,QZS,SBS) */
  #define CODE_L1P    2                   /* obs code: L1P,G1P    (GPS,GLO) */
  #define CODE_L1W    3                   /* obs code: L1 Z-track (GPS) */
  #define CODE_L1Y    4                   /* obs code: L1Y        (GPS) */
  #define CODE_L1M    5                   /* obs code: L1M        (GPS) */
  #define CODE_L1N    6                   /* obs code: L1codeless (GPS) */
  #define CODE_L1S    7                   /* obs code: L1C(D)     (GPS,QZS) */
  #define CODE_L1L    8                   /* obs code: L1C(P)     (GPS,QZS) */
  #define CODE_L1E    9                   /* obs code: L1-SAIF    (QZS) */
  #define CODE_L1A    10                  /* obs code: E1A        (GAL) */
  #define CODE_L1B    11                  /* obs code: E1B        (GAL) */
  #define CODE_L1X    12                  /* obs code: E1B+C,L1C(D+P) (GAL,QZS) */
  #define CODE_L1Z    13                  /* obs code: E1A+B+C,L1SAIF (GAL,QZS) */
  #define CODE_L2C    14                  /* obs code: L2C/A,G1C/A (GPS,GLO) */
  #define CODE_L2D    15                  /* obs code: L2 L1C/A-(P2-P1) (GPS) */
  #define CODE_L2S    16                  /* obs code: L2C(M)     (GPS,QZS) */
  #define CODE_L2L    17                  /* obs code: L2C(L)     (GPS,QZS) */
  #define CODE_L2X    18                  /* obs code: L2C(M+L),B1I+Q (GPS,QZS,CMP) */
  #define CODE_L2P    19                  /* obs code: L2P,G2P    (GPS,GLO) */
  #define CODE_L2W    20                  /* obs code: L2 Z-track (GPS) */
  #define CODE_L2Y    21                  /* obs code: L2Y        (GPS) */
  #define CODE_L2M    22                  /* obs code: L2M        (GPS) */
  #define CODE_L2N    23                  /* obs code: L2codeless (GPS) */
  #define CODE_L5I    24                  /* obs code: L5/E5aI    (GPS,GAL,QZS,SBS) */
  #define CODE_L5Q    25                  /* obs code: L5/E5aQ    (GPS,GAL,QZS,SBS) */
  #define CODE_L5X    26                  /* obs code: L5/E5aI+Q  (GPS,GAL,QZS,SBS) */
  #define CODE_L7I    27                  /* obs code: E5bI,B2I   (GAL,CMP) */
  #define CODE_L7Q    28                  /* obs code: E5bQ,B2Q   (GAL,CMP) */
  #define CODE_L7X    29                  /* obs code: E5bI+Q,B2I+Q (GAL,CMP) */
  #define CODE_L6A    30                  /* obs code: E6A        (GAL) */
  #define CODE_L6B    31                  /* obs code: E6B        (GAL) */
  #define CODE_L6C    32                  /* obs code: E6C        (GAL) */
  #define CODE_L6X    33                  /* obs code: E6B+C,LEXS+L,B3I+Q (GAL,QZS,CMP) */
  #define CODE_L6Z    34                  /* obs code: E6A+B+C    (GAL) */
  #define CODE_L6S    35                  /* obs code: LEXS       (QZS) */
  #define CODE_L6L    36                  /* obs code: LEXL       (QZS) */
  #define CODE_L8I    37                  /* obs code: E5(a+b)I   (GAL) */
  #define CODE_L8Q    38                  /* obs code: E5(a+b)Q   (GAL) */
  #define CODE_L8X    39                  /* obs code: E5(a+b)I+Q (GAL) */
  #define CODE_L2I    40                  /* obs code: B1I        (CMP) */
  #define CODE_L2Q    41                  /* obs code: B1Q        (CMP) */
  #define CODE_L6I    42                  /* obs code: B3I        (CMP) */
  #define CODE_L6Q    43                  /* obs code: B3Q        (CMP) */
  #define CODE_L3I    44                  /* obs code: G3I        (GLO) */
  #define CODE_L3Q    45                  /* obs code: G3Q        (GLO) */
  #define CODE_L3X    46                  /* obs code: G3I+Q      (GLO) */
  #define CODE_L1I    47                  /* obs code: B1I        (BDS) */
  #define CODE_L1Q    48                  /* obs code: B1Q        (BDS) */
  #define MAXCODE     48                  /* max number of obs code */

  #define EARTH_ECCE_2            6.69437999014e-3    // WGS 84 (Earth eccentricity)^2 (m^2)
  #define EARTH_MEAN_RADIUS       6371009             // Mean R of ellipsoid(m) IU Gedosey& Geophysics
  #define EARTH_SEMI_MAJOR        6378137             // WGS 84 Earth semi-major axis (m)
  #define EARTH_SEMI_MAJOR_GLO    6378136.0           // radius of earth (m)
  #define EARTH_OMG_GLO           7.2921150000e-5     // GLO value of earth's rotation rate (rad/s)
  #define EARTH_OMG_GPS           7.2921151467e-5     // GPS/GAL value of earth's rotation rate (rad/s)
  #define EARTH_OMG_BDS           7.2921150000e-5     // BDS value of earth's rotation rate (rad/s)
  #define MU_GPS                  3.9860050000e14     // gravitational constant (GPS)
  #define MU                      3.9860044180e14     // gravitational constant (GAL, BDS, GLO)
  #define TSTEP                   60.0                // integration step glonass ephemeris (s)
  #define J2_GLO                  1.0826257E-3        // 2nd zonal harmonic of geopot
  #define LIGHT_SPEED             2.99792458e8        // WGS-84 Speed of light in a vacuum (m/s)
  #define GPS_EPHCH_JD            2444244.5           // GPS Epoch in Julian Days
  #define EPH_VALID_SECONDS       7200                // 2 hours ephemeris validity
  #define WEEK_SECONDS            604800              // Seconds within one week
  #define EPSILON_KEPLER          1e-14               // Kepler equation terminate condition
  #define MAX_ITER_KEPLER         30                  // Kepler equation maximum iteration number
  #define EPSILON_PVT             1e-8                // PVT terminate condition
  #define MAX_ITER_PVT            30                  // PVT maximum iteration number
  #define RANGE_FREQ              1                   // Range measurement frequency
  #define R2D                     (180.0/M_PI)        // radius to degree
  #define D2R                     (M_PI/180.0)        // degree to radius
  #define SC2RAD                  3.1415926535898     /* semi-circle to radian (IS-GPS) */
  #define SIN_N5                  -0.0871557427476582 // sin(-5.0 deg)
  #define COS_N5                   0.9961946980917456 // cos(-5.0 deg)

}


#endif //IRT_GNSS_PREPROCESSING_GNSS_CONSTANT_H
