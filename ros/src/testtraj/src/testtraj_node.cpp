#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "firsttester");

  ros::NodeHandle nh;

  ros::Publisher test_pub = nh.advertise<trajectory_msgs::JointTrajectory>("/ariac/arm1/arm/command", 1);

  trajectory_msgs::JointTrajectory testTraj;
  trajectory_msgs::JointTrajectoryPoint point1;
  trajectory_msgs::JointTrajectoryPoint point2;
  trajectory_msgs::JointTrajectoryPoint point3;

  testTraj.joint_names = {"linear_arm_actuator_joint", "shoulder_pan_joint", "shoulder_lift_joint", "elbow_joint", "wrist_1_joint", "wrist_2_joint", "wrist_3_joint"};

  point1.time_from_start = ros::Duration(2);
  point1.positions = {0.15, 3.14, -1.570, 2.14, 3.1, -1.59, 0.126};

  point2.time_from_start = ros::Duration(4);
  point2.positions = {-0.35, 3.14, -0.6, 2.3, 3.0, -1.59, 0.126};

  point3.time_from_start = ros::Duration(6);
  point3.positions = {-0.35, 3.14, -0.5, 2.3, 3.05, -1.59, 0.126};

  testTraj.points = {point1, point2, point3};

  ros::Duration(.5).sleep();
  test_pub.publish(testTraj);

  ros::spinOnce();

  return 0;
}
