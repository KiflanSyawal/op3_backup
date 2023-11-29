#include "ros/ros.h"
#include "std_msgs/String.h"

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <libgen.h>
#include <signal.h>
#include <time.h> // log
#include <pthread.h>
#include <termios.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <errno.h>
#include <fcntl.h>
#include <sstream>

int baca;
int mag;
int nani;
char buf2[32];

void IMUData();

void IMUData() {
    baca = open("/dev/ttyCCM0", O_RDWR | O_NOCTTY);
	struct termios toptions;
	tcgetattr(baca, &toptions);
	cfsetispeed(&toptions, B115200);
	cfsetospeed(&toptions, B115200);
	toptions.c_cflag &= ~PARENB;
	toptions.c_cflag &= ~CSTOPB;
	toptions.c_cflag &= ~CSIZE;
	toptions.c_cflag |= CS8;
    toptions.c_cflag &= ~CRTSCTS;
	toptions.c_cflag |= CREAD | CLOCAL;
	toptions.c_iflag &= ~(IXON | IXOFF | IXANY);
	toptions.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
	toptions.c_oflag &= ~OPOST;
	toptions.c_cc[VMIN] = 1;
	toptions.c_cc[VTIME] = 0;
	tcsetattr(baca, TCSANOW, &toptions);
	// tcflush(baca, TCIOFLUSH);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker_cpp_node");
    ros::NodeHandle nh;
    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 10);
    ros::Rate loop_rate(30);
    IMUData();
    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        
            nani = read(baca, &buf2, 32);
            mag = atoi(buf2);
            ss << mag;
            msg.data = ss.str();

        ROS_INFO("Arah String : %s", msg.data.c_str());
        ROS_INFO("Arah Int: %d", mag);
            // std::cout<<"arah robot: "<<mag<<std::endl;

        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
