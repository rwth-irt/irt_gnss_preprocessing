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

#ifndef IRT_GNSS_PREPROCESSING_NOVATEL_OEM7_TYPES_H
#define IRT_GNSS_PREPROCESSING_NOVATEL_OEM7_TYPES_H

#include <cstdio>

namespace irt_gnss_preprocessing::NovAtelOEM7
{
    const unsigned int mask_supply_voltage_status = 0x00000004;
    const unsigned int mask_temperature_status = 0x00000002;
    const unsigned int mask_main_antenna_power_status = 0x00000008;
    const unsigned int mask_cpu_overload = 0x00000080;
    const unsigned int mask_link_overrun = 0x00000800;
    const unsigned int mask_icom1_buffer_overrun = 0x00080000;
    const unsigned int mask_icom2_buffer_overrun = 0x00100000;
    const unsigned int mask_icom3_buffer_overrun = 0x00200000;
    const unsigned int mask_ncom1_buffer_overrun = 0x00400000;

    const unsigned int mask_main_antenna_gain_state = 0x00004000;


    inline std::string getOEM7PosType(uint32_t type)
    {
      switch (type) {
        case 0: return "No Solution!";
        case 16: return "SINGLE";
        case 17: return "PSRDIFF";
        case 18: return "WAAS";
        case 32: return "L1_FLOAT";
        case 34: return "NARROW_FLOAT";
        case 48: return "L1_INT";
        case 49: return "WIDE_INT";
        case 50: return "NARROW_INT";
        case 68: return "PPP_CONVERGING";
        case 69: return "PPP";
        default: return "UNKNOWN OR NOT RELATED";
      }
    }

}





#endif //IRT_GNSS_PREPROCESSING_NOVATEL_OEM7_TYPES_H
