#ifndef IIWA
#define IIWA

#include "ros/ros.h"
#include "sensor_msgs/JointState.h"
#include "std_msgs/Float64.h"
#include "iiwa_kinematics.h"
#include "boost/thread.hpp"

using namespace std;
using namespace Eigen;
using namespace iiwa_kinematics;

#define d3  0.4
#define d5  0.4

namespace iiwa{
	class iiwa{

    	private:
        	ros::NodeHandle nh;
        	ros::Subscriber joint_sub;
        	ros::Publisher cmd_pub[7]; 
			Matrix<float,7,1> q;
			Matrix<float,6,1> desired_pose;
			Matrix<float,6,1> actual_pose;
			Matrix<float,6,1> desired_vel;
			Matrix<float,4,4> Te;
			Matrix<float,4,1> Qe;
			Matrix<float,7,1> qd;
			Matrix<float,7,1> qd_dot;

    	public:
        	iiwa();
			iiwa_kinematics::iiwa_kinematics kin;
			void init_robot();
			void goto_position();
			Matrix<float,6,1> GetActualPos() {return actual_pose;}
			void joint_position_cb(sensor_msgs::JointState);
			void set_desired_pose(Matrix<float,6,1>);
			void set_desired_vel(Matrix<float,6,1>);
			void ctrl_loop();
			void run();
			
	};
}

#endif