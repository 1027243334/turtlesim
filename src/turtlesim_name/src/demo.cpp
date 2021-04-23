#include "ros/ros.h"   // ros/ros.h is a useful header file that references most of the commonly used header files in the ROS system.
#include "geometry_msgs/Twist.h"  // A header file for common message.
#define PI 3.14
 
int main(int argc, char **argv){
  ros::init(argc, argv, "draw_my_name");  // Initialize the ROS and define the node name.
  std::string topic = "/turtle1/cmd_vel";  // Define the topic's name.
  ros::NodeHandle n;  // Create a handle for the node of the process.
  ros::Publisher cmdVelPub = n.advertise<geometry_msgs::Twist>(topic, 10);  // Tell the master that we are going to publish a message of geometry_msgs/Twist message type on the topic.
  ros::Rate loopRate(1);  // Use with sleep function to achieve delay.
  ROS_INFO("draw_my_name start...");
  geometry_msgs::Twist speed;  // Declare a geometry_msgs::Twist type object speed, and assign the value of the turtle's speed to this object.
  int count = 0;
  while (ros::ok()){
    speed.linear.x = 1;  // Set the linear velocity to 1m/s, positive means forward, negative means backward.
    speed.angular.z = 0;  // Angular velocity is 0.
    count++;
	// The following code is to write PRT three English letters.
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

