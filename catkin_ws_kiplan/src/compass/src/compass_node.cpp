/***
 * This example expects the serial port has a loopback on it.
 *
 * Alternatively, you could use an Arduino:
 *
 * <pre>
 *  void setup() {
 *    Serial.begin(<insert your baudrate here>);
 *  }
 *
 *  void loop() {
 *    if (Serial.available()) {
 *      Serial.write(Serial.read());
 *    }
 *  }
 * </pre>
 */

#include <iostream>
#include <string>
#include <cstddef>
#include <sstream>
#include <vector>
#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Empty.h>

serial::Serial ser;

std::vector<std::string> split (std::string s, std::string delimiter) {
    std::size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void write_callback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO_STREAM("Writing to serial port" << msg->data);
    ser.write(msg->data);
}

int main (int argc, char** argv){
    ros::init(argc, argv, "compass_node");
    ros::NodeHandle nh;

    ros::Subscriber write_sub = nh.subscribe("writeoo", 1000, write_callback);
    ros::Publisher read_pub = nh.advertise<std_msgs::String>("read_compass", 10);

    try
    {
        ser.setPort("/dev/ttyCCM0");
        ser.setBaudrate(57600);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
        ser.setTimeout(to);
        ser.open();
    }
    catch (serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port ");
        return -1;
    }

    if(ser.isOpen()){
        ROS_INFO_STREAM("Serial Port initialized");
    }else{
        return -1;
    }

    ros::Rate loop_rate(10);
    while(ros::ok()){

        ros::spinOnce();

        if(ser.available()){
            std_msgs::String result;

            std::string s = ser.read(ser.available());

            std::string key ("YPR");
            std::string comma (",");
            std::string equal ("=");

            std::vector<std::string> v = split (s, key);

            if(v.size() > 0){
                for(int i = v.size()-1; i >=0; i--){
                    std::size_t pos0 = v[i].find(equal);
                    std::size_t pos1 = v[i].find(comma);
                    if (pos0!=std::string::npos && pos1!=std::string::npos){
                        std::string str = v[i].substr(pos0+1,pos1-pos0-1);
                        float df = std::atof(str.c_str());
                        ROS_INFO_STREAM("Read Compass: " << df);
                        result.data = str;
                        read_pub.publish(result);
                        break;
                    }else continue;

                }
            }
        }
        loop_rate.sleep();

    }
}
