#!/usr/bin/env python3
#  Copyright 2021 Institute of Automatic Control RWTH Aachen University
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#
#  Author: Haoming Zhang (h.zhang@irt.rwth-aachen.de)
#

import os

import yaml
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def get_params(p):
    with open(p, 'r') as f:
        print(yaml.safe_load(f))
        return yaml.safe_load(f)


def generate_launch_description():
    logger = LaunchConfiguration("log_level")
    config_common_path = LaunchConfiguration('config_common_path')
    default_config_common = os.path.join(
        get_package_share_directory('irt_gnss_preprocessing'),
        'config',
        'gnss_preprocessing.yaml'
    )

    declare_config_common_path_cmd = DeclareLaunchArgument(
        'config_common_path',
        default_value=default_config_common,
        description='GNSS_Parameters')

    node_gnss_preprocessing = Node(
        package='irt_gnss_preprocessing',
        executable='node_gnss_preprocessing',
        namespace="irt_gnss_preprocessing",
        name="irt_gnss_preprocessing",
        output='screen',
        emulate_tty=True,
        #arguments=['--ros-args', '--log-level', logger],
        parameters=[
            config_common_path,  # Common parameter
            # Overriding
            #{
            #}
        ],
        remappings=[
            ('/user_estimation', '/deutschland/user_estimation'),
            ('/rtcmL1E1', '/sapos/rtcmL1E1')
        ]
    )
    # Define LaunchDescription variable and return it
    ld = LaunchDescription()
    ld.add_action(declare_config_common_path_cmd)
    ld.add_action(node_gnss_preprocessing)
    ld.add_action(DeclareLaunchArgument(
        "log_level",
        default_value=["error"],
        description="Logging level"))

    return ld
