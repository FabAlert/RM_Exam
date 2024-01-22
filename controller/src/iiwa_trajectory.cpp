#include "iiwa_trajectory.h"

namespace iiwa_trajectory{

   iiwa_trajectory::iiwa_trajectory(Matrix<float,6,7> vp, Matrix<float,7,1> t){
        Via_Points = vp;
        Time = t;
    }

    Matrix<float,3,1>iiwa_trajectory::GenTrapezoidalTraj(float qi, float qf, float t, float tf){
    
    Matrix<float,3,1> desired_pos;
    
    float qc_dot = 1.5*(qf-qi)/tf;
    float qc_dot2 = (qc_dot*qc_dot)/(qi-qf+qc_dot*tf);
    float tc = (qi - qf + qc_dot*tf)/qc_dot;

    if(t<=tc){
       desired_pos(0) = qi+0.5*qc_dot2*t*t;
       desired_pos(1) = qc_dot2*t;
       desired_pos(2) = qc_dot2;}
    else if((t>tc)&&(t<=(tf-tc))){
       desired_pos(0) = qi+qc_dot2*tc*(t-tc/2);
       desired_pos(1) = qc_dot2*tc;
       desired_pos(2) = 0;}
    else if((t>(tf-tc))&&(t<=tf)){
       desired_pos(0) = qf-0.5*qc_dot2*(tf-t)*(tf-t);
       desired_pos(1) = -qc_dot2*t+qc_dot2*tf;
       desired_pos(2) = -qc_dot2;}
    else{
       desired_pos(0) = qf;
       desired_pos(1) = 0;
       desired_pos(2) = 0;}

    return desired_pos;  
   }


   Matrix<float,6,3>iiwa_trajectory::GenTraj(float t){
      
      Matrix<float,3,1> xd; Matrix<float,3,1> yd; Matrix<float,3,1> zd;
      Matrix<float,3,1> rolld; Matrix<float,3,1> pitchd; Matrix<float,3,1> yawd;
      Matrix<float,6,3> SentMsg;
      int index = 0;
      
      float t01 = Time(1)+Time(0);
      float t02 = t01+Time(2);
      float t03 = t02+Time(3);
      float t04 = t03+Time(4);
      float t05 = t04+Time(5);

      if (t>=Time(0) && t<t01) index = 0;
      else if (t>=t01 && t<t02){index = 1; t = t-t01;}
      else if (t>=t02 && t<t03){index = 2; t = t-t02;}
      else if (t>=t03 && t<t04){index = 3; t = t-t03;}
      else if (t>=t04 && t<t05){index = 4; t = t-t04;}
      else if (t>=t05){index = 5; t = t-t05;}
   
      xd = GenTrapezoidalTraj(Via_Points(0,index),Via_Points(0,index+1),t,Time(index+1));
      yd = GenTrapezoidalTraj(Via_Points(1,index),Via_Points(1,index+1),t,Time(index+1));
      zd = GenTrapezoidalTraj(Via_Points(2,index),Via_Points(2,index+1),t,Time(index+1));
      rolld = GenTrapezoidalTraj(Via_Points(3,index),Via_Points(3,index+1),t,Time(index+1));
      pitchd = GenTrapezoidalTraj(Via_Points(4,index),Via_Points(4,index+1),t,Time(index+1));
      yawd = GenTrapezoidalTraj(Via_Points(5,index),Via_Points(5,index+1),t,Time(index+1));

      SentMsg.col(0) << xd(0), yd(0), zd(0), rolld(0), pitchd(0), yawd(0); //Pos
      SentMsg.col(1) << xd(1), yd(1), zd(1), rolld(1), pitchd(1), yawd(1); //Vel
      SentMsg.col(2) << xd(2), yd(2), zd(2), rolld(2), pitchd(2), yawd(2); //Acc
      
      
      return SentMsg;
   }
   
   Matrix<float,6,1> iiwa_trajectory::GenSinForce(float t, Matrix<float,3,1> f, Matrix<float,3,1> a, Matrix<float,3,1> ph){
       
      Matrix<float,6,1> ForceGen; ForceGen.setZero(6,1);

      ForceGen(0) = a(0)*sin(2*M_PI*f(0)*t + ph(0));
      ForceGen(1) = a(1)*sin(2*M_PI*f(1)*t + ph(1));
      ForceGen(2) = a(2)*sin(2*M_PI*f(2)*t + ph(2));

      return ForceGen;

   }
   
   Matrix<float,6,1> iiwa_trajectory::GenLinForce(Matrix<float,3,1> a){

      Matrix<float,6,1> ForceGen; ForceGen.setZero(6,1);

      ForceGen(0) = a(0);
      ForceGen(1) = a(1);
      ForceGen(2) = a(2);

      return ForceGen;
   }

   Matrix<float,6,1> iiwa_trajectory::GenAngForce(float t, Matrix<float,3,1> a){

      Matrix<float,6,1> ForceGen; ForceGen.setZero(6,1);

      return ForceGen;

   }


}
