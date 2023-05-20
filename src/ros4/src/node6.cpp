#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<string>
using namespace std;

//char publish_data[100];

void callback(const std_msgs::String::ConstPtr& ptr)
{
//publish_data=("%s",msg->data.c_str());
      cout<<(ptr->data.c_str())<<endl;
//return publish_data;
}

int main(int argc,char **argv)
{
ros::init(argc,argv,"Subscriber1");
ros::init(argc,argv,"Publisher1");
ros::NodeHandle nh;
ros::Subscriber sub = nh.subscribe("chat1",1000,callback);
ros::Publisher chat_pub = nh.advertise<std_msgs::String>("chat1",1000);

ros::Rate loop_rate(10);
int count = 0;
while(ros::ok())
{
std_msgs::String msg;
string message;
cout<<"Ready to take input\n";
getline(cin,message);
cout<<"\" "<<message<<" \""<<" will be sent\n";
msg.data = message;
//std::stringstream ss;
//publish_data("%s",msg.data.c_str());
chat_pub.publish(msg);
ros::spinOnce();
loop_rate.sleep();
count++;
}

ros::spin();
return 0;
}

