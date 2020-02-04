#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "firsttester");

  ros::NodeHandle nh;

  

  ros::spinOnce();

  return 0;
}
