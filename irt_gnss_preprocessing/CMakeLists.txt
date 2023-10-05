cmake_minimum_required(VERSION 3.8)
project(irt_gnss_preprocessing)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -fpermissive -std=c++17)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(pluginlib REQUIRED)
find_package(std_msgs REQUIRED)
find_package(irt_nav_msgs REQUIRED)
find_package(novatel_oem7_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(message_filters REQUIRED)
find_package(irt_nav_common REQUIRED)
find_package(Eigen3 3.3.5 REQUIRED NO_MODULE)

find_package(ublox_msgs REQUIRED)
find_package(ublox_serialization REQUIRED)

find_package(GTSAM REQUIRED)
find_package(GTSAM_UNSTABLE REQUIRED)

set(USE_DUAL_ANTENNA ON)
set(USE_GNSS_TIME_DD OFF)
set(USE_GNSS_RTK_DD ON)

# cmake marcos definitions
if (${USE_DUAL_ANTENNA})
  add_definitions(-DUSE_DUAL_ANTENNA)
endif ()
if (${USE_GNSS_TIME_DD})
  add_definitions(-DUSE_GNSS_TIME_DD)
endif ()
if (${USE_GNSS_RTK_DD})
  add_definitions(-DUSE_GNSS_RTK_DD)
endif ()

set(AMENT_DEPENDENCIES  
    "rclcpp"
    "rclcpp_components"
    "std_msgs"
    "message_filters"
    "sensor_msgs"
    "irt_nav_msgs"
    "novatel_oem7_msgs"
    "pluginlib"
    "irt_nav_common"
    "ublox_msgs"
    "ublox_serialization"
)

# add all subdirectory
add_subdirectory(third_party/gnss_tools)

include_directories(
        include
        include/${PROJECT_NAME}
        third_party
)

add_library(${PROJECT_NAME} SHARED
        src/gnss_utils.cpp
        src/impl/novatel_oem7_preprocessor.cpp
        src/impl/ublox_f9p_preprocessor.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${gnss_tools_lib_list}
    Eigen3::Eigen
    gtsam

)
ament_target_dependencies(
  ${PROJECT_NAME}
  ${AMENT_DEPENDENCIES}
)

add_library(irt_gnss_preprocessing_component SHARED
        src/gnss_preprocesspr_component.cpp
)

ament_target_dependencies(
        irt_gnss_preprocessing_component
        ${AMENT_DEPENDENCIES}
)

target_link_libraries(irt_gnss_preprocessing_component
        ${gnss_tools_lib_list})

rclcpp_components_register_nodes(irt_gnss_preprocessing "irt_gnss_preprocessing::GNSSPreProcessor")

add_executable(node_gnss_preprocessing src/node_gnss_preprocessing.cpp)
target_link_libraries(node_gnss_preprocessing irt_gnss_preprocessing_component)
target_include_directories(node_gnss_preprocessing PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(node_gnss_preprocessing PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  node_gnss_preprocessing
  ${AMENT_DEPENDENCIES}
)

#############
## Install ##
#############
install(TARGETS node_gnss_preprocessing
  DESTINATION lib/${PROJECT_NAME})


ament_export_dependencies(ament_cmake)
ament_export_include_directories(include)
pluginlib_export_plugin_description_file(${PROJECT_NAME} irt_gnss_preprocessing_plugins.xml)

# Install header files
install(DIRECTORY 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/
        ${CMAKE_CURRENT_SOURCE_DIR}/include/sigslot
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/gnss_tools
    DESTINATION include/${PROJECT_NAME}
)


## Mark executables and/or libraries for installation
install(TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin}
        )

install(TARGETS irt_gnss_preprocessing_component
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin}
)


foreach(MODULELIB ${gnss_tools_lib_list})
  install(TARGETS ${MODULELIB}
          LIBRARY DESTINATION lib)
endforeach(MODULELIB)


install(FILES irt_gnss_preprocessing_plugins.xml DESTINATION share)
install(DIRECTORY config DESTINATION share/${PROJECT_NAME} FILES_MATCHING PATTERN "*.yaml")
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME} FILES_MATCHING PATTERN "*.py")
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME} FILES_MATCHING PATTERN "*.launch")

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_export_libraries(zed_camera_component)
ament_export_dependencies(${AMENT_DEPENDENCIES})
ament_package()
