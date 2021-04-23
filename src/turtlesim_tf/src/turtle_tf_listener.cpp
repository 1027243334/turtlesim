#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>
 
int main(int argc, char** argv)
{
    // Initialize the node.
    ros::init(argc, argv, "my_tf_listener");
 
    ros::NodeHandle n;
 
    // Through the service call, spawn the second turtle turtle2.
    ros::service::waitForService("spawn");
    ros::ServiceClient add_turtle = n.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn srv;
    // Set the initial position and name of turtle2.
    // srv.request.x = 5;
    // srv.request.y = 5;
    // srv.request.name = "turtle2";
    add_turtle.call(srv);
 
    // Define the speed control publisher of turtle2.
    ros::Publisher turtle_vel = n.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);
 
    // tf listener
    tf::TransformListener listener;
 
    ros::Rate rate(10.0);

    while (n.ok())
    {
        tf::StampedTransform transform;
        try
        {
            // Find the coordinate transformation between turtle2 and turtle1.
            listener.waitForTransform("/turtle2", "/turtle1", ros::Time(0), ros::Duration(3.0));
            listener.lookupTransform("/turtle2", "/turtle1", ros::Time(0), transform);
        }
        catch (tf::TransformException &ex) 
        {
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }
 
        // According to the coordinate transformation between turtle1 and turtle2, calculate the linear velocity and angular velocity that turtle2 needs to move.
        // And issue a speed control command to make turtle2 move to turtle1.
        geometry_msgs::Twist vel_msg;
        vel_msg.angular.z = 4.0 * atan2(transform.getOrigin().y(), transform.getOrigin().x());
        vel_msg.linear.x = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) + pow(transform.getOrigin().y(), 2));
        turtle_vel.publish(vel_msg);
        rate.sleep();
    }
    return 0;
};
