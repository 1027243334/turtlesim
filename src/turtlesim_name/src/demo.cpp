#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#define PI 3.14
 
int main(int argc, char **argv){
  ros::init(argc, argv, "draw_my_name");
  std::string topic = "/turtle1/cmd_vel";
  ros::NodeHandle n;
  ros::Publisher cmdVelPub = n.advertise<geometry_msgs::Twist>(topic, 10);
  ros::Rate loopRate(1);
  ROS_INFO("draw_my_name start...");
  geometry_msgs::Twist speed; 
  int count = 0;
  while (ros::ok()){
    speed.linear.x = 1;
    speed.angular.z = 0;
    count++;
    if(count == 3 || count == 5 || count == 7 || count == 42)
      speed.angular.z = PI/2;
    if(count == 12 || count == 32 || count == 48)
    {  
      speed.linear.x = 0;
      speed.angular.z = PI; 
    }    
    if(count == 16)
    {  
      speed.linear.x = 0;
      speed.angular.z = -3*PI/4;
    }    
    if(count == 21)
    {  
      speed.linear.x = 0;
      speed.angular.z = PI/4;
    }    
    if(count == 23)
    {  
      speed.linear.x = 0;
      speed.angular.z = PI/2;
    }    
    if(count == 29 || count == 52)
    {  
      speed.linear.x = 0;
      speed.angular.z = -PI/2;
    }    
    if(count == 55 || count == 58  || count == 61 || count == 64)
    {  
      speed.linear.x = 0.4;
      speed.angular.z = PI/2;
    }     
    if(count == 66)
      ros::shutdown();
   
    cmdVelPub.publish(speed); 
    //ros::spinOnce();
    loopRate.sleep();
  }
  return 0;
}

