#include "iiwa.h"

namespace iiwa{

    iiwa::iiwa(){
        joint_sub = nh.subscribe("/kuka_iiwa/joint_states", 10, &iiwa::joint_position_cb, this);
        cmd_pub[0] = nh.advertise<std_msgs::Float64>("/kuka_iiwa/joint1_position_controller/command", 1);
        cmd_pub[1] = nh.advertise<std_msgs::Float64>("/kuka_iiwa/joint2_position_controller/command", 1);
        cmd_pub[2] = nh.advertise<std_msgs::Float64>("/kuka_iiwa/joint3_position_controller/command", 1);
        cmd_pub[3] = nh.advertise<std_msgs::Float64>("/kuka_iiwa/joint4_position_controller/command", 1);
        cmd_pub[4] = nh.advertise<std_msgs::Float64>("/kuka_iiwa/joint5_position_controller/command", 1);
        cmd_pub[5] = nh.advertise<std_msgs::Float64>("/kuka_iiwa/joint6_position_controller/command", 1);
        cmd_pub[6] = nh.advertise<std_msgs::Float64>("/kuka_iiwa/joint7_position_controller/command", 1);

        Te.setZero(4,4); Qe.setZero(4,1);
        qd.setZero(7,1); qd_dot.setZero(7,1); actual_pose.setZero(6,1);
        desired_pose.setZero(6,1); desired_vel.setZero(6,1), q.setZero(7,1);
    }

    void iiwa::joint_position_cb(sensor_msgs::JointState joint_state){
        for(int i=0; i<7; i++) q(i)=joint_state.position[i];
    }

    void iiwa::goto_position(){
        ros::Rate r(100);

	    std_msgs::Float64 cmd[7];

        while(ros::ok()){
            for(int i=0; i<7; i++) {
 			    cmd[i].data = qd(i);
                float e = fabs( cmd[i].data - q(i) );
                if(e > 0.0002) cmd_pub[i].publish (cmd[i]);
                ros::spinOnce();
		    }
            r.sleep();
        }
    }

    void iiwa::ctrl_loop(){

        ros::Rate r(100); 
        Matrix<float,7,6> PseudoJ;  PseudoJ.setZero(7,6);
        Matrix<float,3,3> Rot_d;    Rot_d.setZero(3,3);
        Matrix<float,6,6> K;        K.setIdentity(6,6); K(3,3) = 15; K(4,4) = 15; K(5,5) = 15;
        Matrix<float,7,7> In;       In.setIdentity(7,7);
        Matrix<float,7,1> q0_dot;   q0_dot.setZero(7,1);
        Matrix<float,3,1> RPY;      RPY.setZero(3,1);
        Matrix<float,6,1> error;    error.setZero(6,1);
        Matrix<float,6,7> J;        J.setZero(6,7);
        Matrix<float,4,1> Qd;       Qd.setZero(4,1);
        ofstream ErrorFile;         ErrorFile.open("/home/fabio/ros_ws/src/controller/Traiettoria/ErrorFile.txt", std::ofstream::out | std::ofstream::trunc);
        ofstream QdFile;            QdFile.open("/home/fabio/ros_ws/src/controller/Traiettoria/QdFile.txt", std::ofstream::out | std::ofstream::trunc);
        ofstream QFile;             QFile.open("/home/fabio/ros_ws/src/controller/Traiettoria/QFile.txt", std::ofstream::out | std::ofstream::trunc);
        ofstream ActualPoseFile;    ActualPoseFile.open("/home/fabio/ros_ws/src/controller/Traiettoria/ActualPoseFile.txt", std::ofstream::out | std::ofstream::trunc);

        float Dt = .01;

        while(ros::ok()){ 
            //direct kinematics
            Te = kin.get_Te(q);
            Qe = kin.MatToQuat(Te.block(0,0,3,3));
            RPY = kin.Quat2RPY(Qe);
            actual_pose << Te(0,3),Te(1,3), Te(2,3), RPY(0), RPY(1), RPY(2);
            ActualPoseFile << actual_pose << endl;

            //desired angle computation
            Rot_d = kin.RPY2Mat(desired_pose.block(3,0,3,1));
            Qd = kin.MatToQuat(Rot_d);
           
            //error computation
            error.block(0,0,3,1) = desired_pose.block(0,0,3,1) - Te.block(0,3,3,1);
            error.block(3,0,3,1) = kin.QuatErr(Qd,Qe);
            ErrorFile << error << endl;
            

            //Jacobian and Manipulability measurement
            J = kin.get_J(q);
            q0_dot = kin.get_W(q);
            PseudoJ = J.transpose()*((J*J.transpose()).inverse());

            //CLIK I
            qd_dot = PseudoJ*(desired_vel+K*error) + (In-PseudoJ*J)*q0_dot;  //task secondario per redundancy
            //qd_dot = PseudoJ*(desired_vel+K*error); //senza task secondario per ridondanza
            qd = qd + qd_dot*Dt;
            QdFile << qd << endl; QFile << q <<endl;
            r.sleep();
            ros::spinOnce();
        }
        
        ErrorFile.close(); ActualPoseFile.close();
        QdFile.close(); QFile.close();    
        
    }

    void iiwa::init_robot(){
        qd << 0.5 , 0.5, 0.5, 0.5, 0.5, 0.5, 0.5;
        Matrix<float,3,1> RPY; 
        ros::spinOnce();
        usleep(100);
        float max_e  = 1000;
	    std_msgs::Float64 cmd[7];

        do{
            max_e = -1000;
            for(int i=0; i<7; i++) {
 			    cmd[i].data = qd(i);
                float e = fabs( cmd[i].data - q(i) );
                if(e > 0.002) cmd_pub[i].publish (cmd[i]);
                max_e = (max_e < e) ? e : max_e;
                ros::spinOnce();
                usleep(100);
		    }
        }
        while(abs(max_e) > 0.02);

        Te = kin.get_Te(q);
        Qe = kin.MatToQuat(Te.block(0,0,3,3));
        RPY = kin.Quat2RPY(Qe);
        actual_pose << Te(0,3),Te(1,3), Te(2,3), RPY(0), RPY(1), RPY(2);

        desired_pose = actual_pose;
        
    }

    void iiwa::run() {   
        
	    boost::thread goto_position_t( &iiwa::goto_position, this);  //esegue posa
	    boost::thread ctrl_loop_t ( &iiwa::ctrl_loop, this);  // calcola posa
    }   

    void iiwa::set_desired_pose(Matrix<float,6,1> PosDes){
        desired_pose = PosDes;
    }
    
    void iiwa::set_desired_vel(Matrix<float,6,1> VelDes){
        desired_vel = VelDes;
    }

}
