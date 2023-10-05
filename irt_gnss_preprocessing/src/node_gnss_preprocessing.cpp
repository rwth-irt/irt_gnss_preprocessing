#include <cstdio>
#include "gnss_preprocessor_component.h"


int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;

  auto gnss_pre_processor_node = std::make_shared<irt_gnss_preprocessing::GNSSPreProcessor>(options);
  static const size_t THREAD_NUM = 6; // Receive and blocking command service.
  rclcpp::executors::MultiThreadedExecutor executor(rclcpp::ExecutorOptions(), THREAD_NUM);
  executor.add_node(gnss_pre_processor_node);
  executor.spin();
  rclcpp::shutdown();
  return 0;
}


