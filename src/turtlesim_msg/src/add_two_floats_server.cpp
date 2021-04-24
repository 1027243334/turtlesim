#include "ros/ros.h"
#include "turtlesim_msg/AddTwoFloats.h"

// Show function uses AddTwoInts service to add turtle.x and turtle.y
bool add(turtlesim_msg::AddTwoFloats::Request &req,
          turtlesim_msg::AddTwoFloats::Response &res)
{
  res.sum = req.a + req.b;
  ROS_INFO("AddTwoFloats service is called successfully.");
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_floats_server");
  ros::NodeHandle n;

  ros::ServiceServer service=n.advertiseService("add_two_floats", add);
  ROS_INFO("Ready to add two floats.");
  ros::spin();

  return 0;
}
