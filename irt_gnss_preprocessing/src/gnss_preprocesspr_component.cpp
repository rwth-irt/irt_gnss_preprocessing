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


#include "gnss_preprocessor_component.h"


namespace irt_gnss_preprocessing
{
    GNSSPreProcessor::GNSSPreProcessor(const rclcpp::NodeOptions &opt)  :
        rclcpp::Node("GNSSPreProcessorStandaloneNode", opt),
        gnss_preprocessor_loader_("irt_gnss_preprocessing", "irt_gnss_preprocessing::GNSSPreprocessor")
    {
      RosParameter<std::string> handler_name("GNSSPreprocessor.gnss_receiver_handler", "NovatelOEM7",*this);

      if (gnss_preprocessor_loader_.isClassAvailable(handler_name.value() + "PreProcessor"))
      {
          receiver_handler_ = gnss_preprocessor_loader_.createSharedInstance(handler_name.value() + "PreProcessor");
          receiver_handler_->initialize(*this, handler_name.value());
      }
      else
      {
        RCLCPP_ERROR(this->get_logger(), "Handler %s not found!", handler_name.value().c_str());
        return;
      }
    }

}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(irt_gnss_preprocessing::GNSSPreProcessor)