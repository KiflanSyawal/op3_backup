#include <ros/ros.h>
#include <std_msgs/String.h>

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 3838

int main(int argc, char **argv)
{
    ros::init(argc, argv, "game_controller_node");
    ros::NodeHandle nh;
    ros::Publisher game_pub = nh.advertise<std_msgs::String>("game", 10);
    ros::Rate loop_rate(30);

    // Membuat socket untuk koneksi Wi-Fi
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        ROS_ERROR("Gagal membuat socket");
        return -1;
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(3838);

    // Menghubungkan socket ke alamat server
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        ROS_ERROR("Gagal terhubung ke server");
        return -1;
    }

    while (ros::ok())
    {
        // Menerima data dari Game Controller Referee Box
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received < 0) {
            ROS_ERROR("Gagal menerima data");
            break;
        }
        buffer[bytes_received] = '\0';

        // Membuat pesan ROS dan menerbitkannya ke topik
        std_msgs::String msg;
        msg.data = buffer;
        game_pub.publish(msg);

        ros::spinOnce();
        // Jeda singkat antara setiap iterasi
        usleep(1000);
    }
    // Menutup koneksi Wi-Fi
    close(sockfd);

    return 0;
}



