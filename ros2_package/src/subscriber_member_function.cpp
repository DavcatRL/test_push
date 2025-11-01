// Copyright 2016 Open Source Robotics Foundation, Inc.
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

#include <functional>
#include <memory>
#include <string> 

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
// #include "ros2_package_interfaces/msg/sphere.hpp"


using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
       "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));

    // sphere_subscription_ = this->create_subscription<ros2_package_interfaces::msg::Sphere>(
    //   "Sphere", 10, std::bind(&MinimalSubscriber::sphere_topic_callback, this, _1));  
  }

private:
  void topic_callback(const std_msgs::msg::String & msg) const
  {
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
  }
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

  // void sphere_topic_callback(const ros2_package_interfaces::msg::Sphere & msg) const
  // {
  //   RCLCPP_INFO(this->get_logger(), "Sphere center x: '%s'", std::to_string(msg.center.x).c_str());
  //   RCLCPP_INFO(this->get_logger(), "Sphere center y: '%s'", std::to_string(msg.center.y).c_str());
  //   RCLCPP_INFO(this->get_logger(), "Sphere center z: '%s'", std::to_string(msg.center.z).c_str());
  //   RCLCPP_INFO(this->get_logger(), "Sphere radius: '%s'", std::to_string(msg.radius).c_str());
  // }
  // rclcpp::Subscription<ros2_package_interfaces::msg::Sphere>::SharedPtr sphere_subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
