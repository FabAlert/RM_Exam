#include "ros/ros.h"
#include <iostream>
#include "sensor_msgs/JointState.h"
#include "std_msgs/Float64.h"
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/SVD>

#include <sstream>
#include <fstream>
#include <sys/resource.h>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <math.h>
#include <cmath>

#include "iiwa.h"
#include "iiwa_trajectory.h"
#define N_joints 7

using namespace std;
using namespace Eigen;
using namespace iiwa;
using namespace iiwa_trajectory;

int main(int argc, char** argv){

    ros::init(argc, argv ,"kuka_control");
    iiwa::iiwa robot;
    robot.init_robot();
    sleep(1);
    robot.run();
    Matrix<float,6,7> ViaPoints;
    Matrix<float,7,1> time;
    time << 0, 1, 2, 3, 2, 1, 3;
    ViaPoints.col(0) = robot.GetActualPos();

    //TRAIETTORIA QUADRATO IN 3D
    ViaPoints.col(1) << 0.2, 0.2, 0.3, 2, 0.5, 0;
    ViaPoints.col(2) << 0.4, 0.2, 0.4, 1.5, 0.7, 0.5; 
    ViaPoints.col(3) << 0.4, 0.4, 0.5, 1 , 0.5, 1; 
    ViaPoints.col(4) << 0.2, 0.4, 0.4, .5 , 0, .5;
    ViaPoints.col(5) << 0.2, 0.3, 0.3, 0 , 0.3, 0; 
    ViaPoints.col(6) << 0.3, 0.3, 0.3, 0.7 , 0.7, 0.7;
    
    //qua inizializzo i parametri del controllo d'ammettenza 
    Matrix<float,6,6> M; M.setIdentity(6,6); //M = 15*M;
    Matrix<float,6,6> MInv; MInv = M.inverse(); 
    Matrix<float,6,6> D; D.setIdentity(6,6); //D = 5*D;
    Matrix<float,6,6> K; K.setIdentity(6,6); // K = 5*K;
    Matrix<float,12,12> A; A.setZero(12,12);
    Matrix<float,12,6> B; B.setZero(12,6);
    Matrix<float,6,6> eye; eye.setIdentity(6,6); 
    A.block(6,0,6,6) = -K*MInv; A.block(6,6,6,6) = -D*MInv; A.block(0,6,6,6) = eye;
    B.block(6,0,6,6) = MInv; //aggiorno B;

    ofstream DesiredPosFile;     DesiredPosFile.open("/home/fabio/ros_ws/src/controller/Traiettoria/DesiredPosFile.txt", std::ofstream::out | std::ofstream::trunc);
    ofstream DesiredVelFile;     DesiredVelFile.open("/home/fabio/ros_ws/src/controller/Traiettoria/DesiredVelFile.txt", std::ofstream::out | std::ofstream::trunc);
    ofstream CompliancePosFile;  CompliancePosFile.open("/home/fabio/ros_ws/src/controller/Traiettoria/CompliancePosFile.txt", std::ofstream::out | std::ofstream::trunc);
    ofstream ComplianceVelFile;  ComplianceVelFile.open("/home/fabio/ros_ws/src/controller/Traiettoria/ComplianceVelFile.txt", std::ofstream::out | std::ofstream::trunc);
    ofstream ForceFile;          ForceFile.open("/home/fabio/ros_ws/src/controller/Traiettoria/ForceFile.txt", std::ofstream::out | std::ofstream::trunc);


    /*Risolvo un sistema diff del secondo ordine spezzandolo in due del primo ordine
    M*xddot + D*x_dot + K*x = U diventa
    Z = [ x1 x2 ]';  con x1 = x alias differenza tra terna desiderata e compliance e x2 = xdot
    A = [ 1   0;        B = [ 0 Force/M ]';
         K/M D/M];
    risposta impulsiva  = x(k) = A*x(k-1) + B*u(k); ottengo sia pos che vel desiderata 
    */
    
    Matrix<float,6,1> ForceGen; ForceGen.setZero(6,1);
    Matrix<float,12,1> Z; Z.setZero(12,1);
    Matrix<float,12,1> Z0; Z0.setZero(12,1);
    Matrix<float,6,1> CompliancePos; CompliancePos.setZero(6,1);
    Matrix<float,6,1> ComplianceVel; ComplianceVel.setZero(6,1);
    Matrix<float,3,1> ForceAxis; ForceAxis << 0, 0, 0; //0.2, 0.2, 0.4; 
    Matrix<float,3,1> ForcePhase; ForcePhase << 0, 0, 0;
    Matrix<float,3,1> ForceFreq; ForceFreq << 0, 0, 0; //0.5, 0.5, 2;

    
    

    Matrix<float,6,3> SentMsg;

    iiwa_trajectory::iiwa_trajectory Traj(ViaPoints,time); 

    float t = 0;
    float Dt = 0.01;

    ros::Rate r(100);

    while(ros::ok()){

        SentMsg = Traj.GenTraj(t); //genero la traiettoria e le velocità desiderate
        DesiredPosFile << SentMsg.col(0) << endl; 
        DesiredVelFile << SentMsg.col(1) << endl;

        //Genero la forza :Scegleire un tipo di profilo
        //ForceGen = Traj.GenSinForce(t,ForceFreq,ForceAxis,ForcePhase);
        ForceGen = Traj.GenLinForce(ForceAxis);

        ForceFile << ForceGen << endl;
        Z = A*Z0 + B*ForceGen; //1st ODE 
        Z0 = Z0 + Z*Dt;       //Aggiorno stato precedente
        CompliancePos = SentMsg.col(0)-Z0.block(0,0,6,1);  //ottengo nuova pos
        CompliancePosFile << CompliancePos << endl;
        ComplianceVel = SentMsg.col(1)-Z0.block(6,0,6,1);  //ottengo nuova vel
        ComplianceVelFile << ComplianceVel << endl;
        robot.set_desired_pose(CompliancePos);
        robot.set_desired_vel(ComplianceVel);
        t+=0.01;
        
        r.sleep();
    }

    DesiredPosFile.close(); DesiredVelFile.close();
    CompliancePosFile.close(); ComplianceVelFile.close();   
    ForceFile.close();

    return 0;
}
