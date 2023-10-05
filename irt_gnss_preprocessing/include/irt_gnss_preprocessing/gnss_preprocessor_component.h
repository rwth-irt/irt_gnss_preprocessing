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
// Created by haoming on 27.03.22.
//

#ifndef IRT_GNSS_PREPROCESSING_GNSS_PREPROCESSOR_COMPONENT_H
#define IRT_GNSS_PREPROCESSING_GNSS_PREPROCESSOR_COMPONENT_H

#pragma once

#include <rclcpp/rclcpp.hpp>
#include <pluginlib/class_loader.hpp>
#include "gnss_preprocessor.h"

namespace irt_gnss_preprocessing
{
    class GNSSPreProcessor : public rclcpp::Node
    {
        typedef std::shared_ptr<irt_gnss_preprocessing::GNSSPreprocessor> ReceiverHandlerPtrT;
        pluginlib::ClassLoader<irt_gnss_preprocessing::GNSSPreprocessor> gnss_preprocessor_loader_;
        ReceiverHandlerPtrT receiver_handler_;

    public:
        explicit GNSSPreProcessor(const rclcpp::NodeOptions &opt);
    };
}

#endif //IRT_GNSS_PREPROCESSING_GNSS_PREPROCESSOR_COMPONENT_H
