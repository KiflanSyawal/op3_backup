#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

#include <sstream>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cassert>

int isDemoEnabled = 0;

void checkDemoEnabled(const std_msgs::Int32::ConstPtr &msg)
{
    isDemoEnabled = msg->data;
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "gcReceiver");
    ros::NodeHandle n;
    ros::Publisher gcPub = n.advertise<std_msgs::Int32>("gamecontrol", 1000);
    ros::Publisher button_pub_ = n.advertise<std_msgs::String>("/robotis/open_cr/button", 1);

    ros::Subscriber sub = n.subscribe("/robotis/issoccerdemo_enabled", 1000, checkDemoEnabled);

    ros::Rate loop_rate(10);

    ROS_INFO("RECEIVER IS RUNNING");

    // socket
    sockaddr_in si_me, si_other;
    int s;
    assert((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) != -1);
    int port = 3838;
    int broadcast = 1;
    int rState = -1;
    int buflen = 1000;
    int playState = -1;

    setsockopt(s, SOL_SOCKET, SO_BROADCAST,
               &broadcast, sizeof broadcast); 

    memset(&si_me, 0, sizeof(si_me));
    si_me.sin_family = AF_INET; 
    si_me.sin_port = htons(port);
    si_me.sin_addr.s_addr = INADDR_ANY;

    assert(::bind(s, (sockaddr *)&si_me, sizeof(sockaddr)) != -1);

    int count = 0;
    while (ros::ok())
    {
        printf("\n HEAD : ");

        char buf[buflen];
        // memset(buf, 0, 255);
        unsigned slen = sizeof(sockaddr);
        recvfrom(s, buf, sizeof(buf) - 1, 0, (sockaddr *)&si_other, &slen);

        for(int i = 0; i < buflen; i++){
            if(rState == 9){
                
                rState = -1;
                if(playState != buf[i]){
                    playState = buf[i];
                    std::cout << " data: " << playState << ", pre:" << (int)buf[i-1] << ", next:" << (int)buf[i+1] << ", index:" << i;
                    // publish

                    // std_msgs::Int32 msg; 
                    // msg.data = playState;
                    // gcPub.publish(msg);

                    std_msgs::String button_msg;
                    button_msg.data = "start"; 
                    if((playState == 3 && isDemoEnabled != 1)){
                        button_pub_.publish(button_msg);
                        isDemoEnabled = 1;
                    }else if(isDemoEnabled == 1){
                        button_pub_.publish(button_msg);
                        isDemoEnabled = 0;
                    }
                }
            }

            if(rState > 0){
                if(rState == 1 && buf[i] == 'G') rState = 2;
                else if(rState == 2 && buf[i] == 'm') rState = 3;
                else if(rState == 3 && buf[i] == 'e') rState = 4;
                else if(rState >= 4){ 
                    rState++;
                    if((int)buf[i] == 6) rState = 9;
                }
                else rState = -1;
            }else if(buf[i] == 'R'){
                rState = 1;
            }
        }


        
        ros::spinOnce();
        //loop_rate.sleep();
        ++count;
    }
    return 0;
}