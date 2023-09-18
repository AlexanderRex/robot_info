// robot_info_class.cpp

#include "robot_info_class.h"

RobotInfo::RobotInfo(std::string desc, std::string serial, std::string ip,
                     std::string firmware)
    : robot_description(desc), serial_number(serial), ip_address(ip),
      firmware_version(firmware) {
  pub = nh.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 1000);
}

void RobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;

  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;

  pub.publish(msg);
}
