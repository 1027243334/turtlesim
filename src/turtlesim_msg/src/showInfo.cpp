#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include "turtlesim_msg/AddTwoFloats.h"
#include "turtlesim_msg/Info.h"

std::string turtle_name;
turtlesim_msg::Info info;
ros::ServiceClient client;

void poseCallback(const turtlesim::PoseConstPtr& msg)
{
  info.x = msg->x;
  info.y = msg->y;
  turtlesim_msg::AddTwoFloats srv;
  srv.request.a = info.x;
  srv.request.b = info.y;
  if (client.call(srv))
  {
    info.sum = srv.response.sum;
    ROS_INFO("turtle_name=%s, x=%f, y=%f, sum=%f", info.name.c_str(), info.x, info.y, info.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_floats");
  }
}

int main(int argc, char **argv)
{
  // Initialize node.
  ros::init(argc, argv, "showInfo");
  if (argc != 2)
  {
    ROS_ERROR("need turtle name as argument"); 
    return -1;
  };
  turtle_name = argv[1];
  info.name = turtle_name;

  // Subsrcibe the pose information of turtle.
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe(turtle_name+"/pose", 10, &poseCallback);

  // Add_two_floats client
  client = n.serviceClient<turtlesim_msg::AddTwoFloats>("add_two_floats");
  ros::spin();

  return 0;
}
