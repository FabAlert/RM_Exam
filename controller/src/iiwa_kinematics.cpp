 #include <iiwa_kinematics.h>

 namespace iiwa_kinematics {

    iiwa_kinematics::iiwa_kinematics(){}
     

    Matrix<float,6,7> iiwa_kinematics::get_J(Matrix<float,7,1> q){  

        Matrix<float,6,7> J;

        J(0,0) = (2*sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))))/5 - (2*sin(q(0))*sin(q(1)))/5 - (2*cos(q(3))*sin(q(0))*sin(q(1)))/5;
        J(0,1) = cos(q(0))*((2*cos(q(1)))/5 + (2*cos(q(1))*cos(q(3)))/5 + (2*cos(q(2))*sin(q(1))*sin(q(3)))/5);
        J(0,2) = (2*sin(q(3))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2))))/5;
        J(0,3) = (2*cos(q(3))*sin(q(0))*sin(q(2)))/5 - (2*cos(q(0))*sin(q(1))*sin(q(3)))/5 - (2*cos(q(0))*cos(q(1))*cos(q(2))*cos(q(3)))/5;
        J(0,4) = 0;
        J(0,5) = 0;
        J(0,6) = 0;
        J(1,0) = (2*cos(q(0))*sin(q(1)))/5 + (2*sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))))/5 + (2*cos(q(0))*cos(q(3))*sin(q(1)))/5;
        J(1,1) = sin(q(0))*((2*cos(q(1)))/5 + (2*cos(q(1))*cos(q(3)))/5 + (2*cos(q(2))*sin(q(1))*sin(q(3)))/5);
        J(1,2) = -(2*sin(q(3))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2))))/5;
        J(1,3) = -(2*sin(q(0))*sin(q(1))*sin(q(3)))/5 - (2*cos(q(0))*cos(q(3))*sin(q(2)))/5 - (2*cos(q(1))*cos(q(2))*cos(q(3))*sin(q(0)))/5;
        J(1,4) = 0;
        J(1,5) = 0;
        J(1,6) = 0;
        J(2,0) = 0;
        J(2,1) = (2*cos(q(1))*cos(q(2))*sin(q(3)))/5 - (2*cos(q(3))*sin(q(1)))/5 - (2*sin(q(1)))/5;
        J(2,2) = -(2*sin(q(1))*sin(q(2))*sin(q(3)))/5;
        J(2,3) = (2*cos(q(2))*cos(q(3))*sin(q(1)))/5 - (2*cos(q(1))*sin(q(3)))/5;
        J(2,4) = 0;
        J(2,5) = 0;
        J(2,6) = 0;
        J(3,0) = 0;
        J(3,1) = -sin(q(0));
        J(3,2) = cos(q(0))*sin(q(1));
        J(3,3) = cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2));
        J(3,4) = sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) + cos(q(0))*cos(q(3))*sin(q(1));
        J(3,5) = sin(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) - cos(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2)));
        J(3,6) = cos(q(5))*(sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) + cos(q(0))*cos(q(3))*sin(q(1))) - sin(q(5))*(cos(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2))));
        J(4,0) = 0;
        J(4,1) = cos(q(0));
        J(4,2) = sin(q(0))*sin(q(1));
        J(4,3) = cos(q(1))*sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(2));
        J(4,4) = cos(q(3))*sin(q(0))*sin(q(1)) - sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0)));
        J(4,5) = cos(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2))) - sin(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3)));
        J(4,6) = sin(q(5))*(cos(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2)))) - cos(q(5))*(sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - cos(q(3))*sin(q(0))*sin(q(1)));
        J(5,0) = 1;
        J(5,1) = 0;
        J(5,2) = cos(q(1));
        J(5,3) = -sin(q(1))*sin(q(2));
        J(5,4) = cos(q(1))*cos(q(3)) + cos(q(2))*sin(q(1))*sin(q(3));
        J(5,5) = cos(q(4))*sin(q(1))*sin(q(2)) - sin(q(4))*(cos(q(1))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(1)));
        J(5,6) = sin(q(5))*(cos(q(4))*(cos(q(1))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(1))) + sin(q(1))*sin(q(2))*sin(q(4))) + cos(q(5))*(cos(q(1))*cos(q(3)) + cos(q(2))*sin(q(1))*sin(q(3)));
 
        return J;
    }

    Matrix<float,4,4> iiwa_kinematics::get_Te(Matrix<float,7,1> q){  
          
        Matrix<float,4,4> Te;

        Te(0,3) = (2*cos(q(0))*sin(q(1)))/5 + (2*sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))))/5 + (2*cos(q(0))*cos(q(3))*sin(q(1)))/5;
        Te(1,3) = (2*sin(q(0))*sin(q(1)))/5 - (2*sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))))/5 + (2*cos(q(3))*sin(q(0))*sin(q(1)))/5;
        Te(2,3) = (2*cos(q(1)))/5 + (2*cos(q(1))*cos(q(3)))/5 + (2*cos(q(2))*sin(q(1))*sin(q(3)))/5;
        Te(3,3) = 1;
        Te(0,0) = sin(q(6))*(sin(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) - cos(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2)))) - cos(q(6))*(sin(q(5))*(sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) + cos(q(0))*cos(q(3))*sin(q(1))) + cos(q(5))*(cos(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2)))));
        Te(0,1) = cos(q(6))*(sin(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) - cos(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2)))) + sin(q(6))*(sin(q(5))*(sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) + cos(q(0))*cos(q(3))*sin(q(1))) + cos(q(5))*(cos(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2))))); 
        Te(0,2) = cos(q(5))*(sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) + cos(q(0))*cos(q(3))*sin(q(1))) - sin(q(5))*(cos(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2))));
        Te(1,0) = cos(q(6))*(sin(q(5))*(sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - cos(q(3))*sin(q(0))*sin(q(1))) + cos(q(5))*(cos(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2))))) - sin(q(6))*(sin(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) - cos(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2))));
        Te(1,1) = -cos(q(6))*(sin(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) - cos(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2)))) - sin(q(6))*(sin(q(5))*(sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - cos(q(3))*sin(q(0))*sin(q(1))) + cos(q(5))*(cos(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2)))));
        Te(1,2) = sin(q(5))*(cos(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2)))) - cos(q(5))*(sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - cos(q(3))*sin(q(0))*sin(q(1)));
        Te(2,0) = cos(q(6))*(cos(q(5))*(cos(q(4))*(cos(q(1))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(1))) + sin(q(1))*sin(q(2))*sin(q(4))) - sin(q(5))*(cos(q(1))*cos(q(3)) + cos(q(2))*sin(q(1))*sin(q(3)))) - sin(q(6))*(sin(q(4))*(cos(q(1))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(1))) - cos(q(4))*sin(q(1))*sin(q(2)));
        Te(2,1) = -cos(q(6))*(sin(q(4))*(cos(q(1))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(1))) - cos(q(4))*sin(q(1))*sin(q(2))) - sin(q(6))*(cos(q(5))*(cos(q(4))*(cos(q(1))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(1))) + sin(q(1))*sin(q(2))*sin(q(4))) - sin(q(5))*(cos(q(1))*cos(q(3)) + cos(q(2))*sin(q(1))*sin(q(3))));
        Te(2,2) = sin(q(5))*(cos(q(4))*(cos(q(1))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(1))) + sin(q(1))*sin(q(2))*sin(q(4))) + cos(q(5))*(cos(q(1))*cos(q(3)) + cos(q(2))*sin(q(1))*sin(q(3)));
        Te(3,0) = 0;
        Te(3,1) = 0;
        Te(3,2) = 0;
 
        return Te;
    }

    Matrix<float,4,1> iiwa_kinematics::MatToQuat(Matrix<float,3,3> T){

        Matrix<float,4,1> Quat;

        if((T(2,1)-T(1,2))>=0) Quat(1) = 0.5*sqrt(T(0,0)-T(1,1)-T(2,2)+1);
        else Quat(1) = -0.5*sqrt(T(0,0)-T(1,1)-T(2,2)+1);
        if((T(0,2)-T(2,0))>=0) Quat(2) = 0.5*sqrt(T(1,1)-T(0,0)-T(2,2)+1);
        else Quat(2) = -0.5*sqrt(T(1,1)-T(0,0)-T(2,2)+1);
        if((T(1,0)-T(0,1))>=0) Quat(3) = 0.5*sqrt(T(2,2)-T(1,1)-T(0,0)+1);
        else Quat(3) = -0.5*sqrt(T(2,2)-T(1,1)-T(0,0)+1);
        Quat(0) = 0.5*sqrt(T(0,0)+T(1,1)+T(2,2)+1);

        return Quat;
    }

    Matrix<float,7,1> iiwa_kinematics::get_W(Matrix<float,7,1> q){

        Matrix<float,7,1> W;

        Matrix<float,6,7> J = get_J(q);
        Matrix<float,7,6> PseudoJ;
        Matrix<float,6,7> Df1;
        Matrix<float,6,7> Df2;
        Matrix<float,6,7> Df3;
        Matrix<float,6,7> Df4;
        Matrix<float,6,7> Df5;
        Matrix<float,6,7> Df6;

        PseudoJ = J.transpose()*(J*J.transpose()).inverse();
        
        Df1.setZero(6,7);
        Df1(0,0) = -(2*cos(q(0))*sin(q(1)))/5 - (2*sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))))/5 - (2*cos(q(0))*cos(q(3))*sin(q(1)))/5;
        Df1(0,1) = -sin(q(0))*((2*cos(q(1)))/5 + (2*cos(q(1))*cos(q(3)))/5 + (2*cos(q(2))*sin(q(1))*sin(q(3)))/5);
        Df1(0,2) = (2*sin(q(3))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2))))/5;
        Df1(0,3) = (2*sin(q(0))*sin(q(1))*sin(q(3)))/5 + (2*cos(q(0))*cos(q(3))*sin(q(2)))/5 + (2*cos(q(1))*cos(q(2))*cos(q(3))*sin(q(0)))/5;
        Df1(1,0) = (2*sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))))/5 - (2*sin(q(0))*sin(q(1)))/5 - (2*cos(q(3))*sin(q(0))*sin(q(1)))/5;
        Df1(1,1) = cos(q(0))*((2*cos(q(1)))/5 + (2*cos(q(1))*cos(q(3)))/5 + (2*cos(q(2))*sin(q(1))*sin(q(3)))/5);
        Df1(1,2) = (2*sin(q(3))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2))))/5;
        Df1(1,3) = (2*cos(q(3))*sin(q(0))*sin(q(2)))/5 - (2*cos(q(0))*sin(q(1))*sin(q(3)))/5 - (2*cos(q(0))*cos(q(1))*cos(q(2))*cos(q(3)))/5;
        Df1(3,1) = -cos(q(0)); Df1(3,2) = -sin(q(0))*sin(q(1)); Df1(3,3) = cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2));
        Df1(3,4) = sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - cos(q(3))*sin(q(0))*sin(q(1));
        Df1(3,5) = sin(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) - cos(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2)));
        Df1(3,6) = cos(q(5))*(sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - cos(q(3))*sin(q(0))*sin(q(1))) - sin(q(5))*(cos(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2))));
        Df1(4,1) = -sin(q(0)); Df1(4,2) = cos(q(0))*sin(q(1)); 
        Df1(4,3) = cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2));
        Df1(4,4) = sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) + cos(q(0))*cos(q(3))*sin(q(1));
        Df1(4,5) = sin(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) - cos(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2)));
        Df1(4,6) = cos(q(5))*(sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) + cos(q(0))*cos(q(3))*sin(q(1))) - sin(q(5))*(cos(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2))));
        
        Df2.setZero(6,7);
        Df2(0,0) = -(2*cos(q(1))*sin(q(0)))/5 - (2*cos(q(1))*cos(q(3))*sin(q(0)))/5 - (2*cos(q(2))*sin(q(0))*sin(q(1))*sin(q(3)))/5;
        Df2(0,1) = -cos(q(0))*((2*sin(q(1)))/5 + (2*cos(q(3))*sin(q(1)))/5 - (2*cos(q(1))*cos(q(2))*sin(q(3)))/5);
        Df2(0,2) = -(2*cos(q(0))*sin(q(1))*sin(q(2))*sin(q(3)))/5;
        Df2(0,3) = (2*cos(q(0))*cos(q(2))*cos(q(3))*sin(q(1)))/5 - (2*cos(q(0))*cos(q(1))*sin(q(3)))/5;
        Df2(1,0) = (2*cos(q(0))*cos(q(1)))/5 + (2*cos(q(0))*cos(q(1))*cos(q(3)))/5 + (2*cos(q(0))*cos(q(2))*sin(q(1))*sin(q(3)))/5;
        Df2(1,1) = -sin(q(0))*((2*sin(q(1)))/5 + (2*cos(q(3))*sin(q(1)))/5 - (2*cos(q(1))*cos(q(2))*sin(q(3)))/5);
        Df2(1,2) = -(2*sin(q(0))*sin(q(1))*sin(q(2))*sin(q(3)))/5;
        Df2(1,3) = (2*cos(q(2))*cos(q(3))*sin(q(0))*sin(q(1)))/5 - (2*cos(q(1))*sin(q(0))*sin(q(3)))/5;
        Df2(2,1) = -(2*cos(q(1)))/5 - (2*cos(q(1))*cos(q(3)))/5 - (2*cos(q(2))*sin(q(1))*sin(q(3)))/5;
        Df2(2,2) = -(2*cos(q(1))*sin(q(2))*sin(q(3)))/5;
        Df2(2,3) = (2*sin(q(1))*sin(q(3)))/5 + (2*cos(q(1))*cos(q(2))*cos(q(3)))/5;
        Df2(3,2) = cos(q(0))*cos(q(1)); Df2(3,3) = -cos(q(0))*sin(q(1))*sin(q(2));
        Df2(3,4) = cos(q(0))*cos(q(1))*cos(q(3)) + cos(q(0))*cos(q(2))*sin(q(1))*sin(q(3));
        Df2(3,5) = cos(q(0))*cos(q(4))*sin(q(1))*sin(q(2)) - sin(q(4))*(cos(q(0))*cos(q(1))*sin(q(3)) - cos(q(0))*cos(q(2))*cos(q(3))*sin(q(1)));
        Df2(3,6) = cos(q(5))*(cos(q(0))*cos(q(1))*cos(q(3)) + cos(q(0))*cos(q(2))*sin(q(1))*sin(q(3))) + sin(q(5))*(cos(q(4))*(cos(q(0))*cos(q(1))*sin(q(3)) - cos(q(0))*cos(q(2))*cos(q(3))*sin(q(1))) + cos(q(0))*sin(q(1))*sin(q(2))*sin(q(4)));
        Df2(4,2) = cos(q(1))*sin(q(0)); Df2(4,3) = -sin(q(0))*sin(q(1))*sin(q(2)); 
        Df2(4,4) = cos(q(1))*cos(q(3))*sin(q(0)) + cos(q(2))*sin(q(0))*sin(q(1))*sin(q(3));
        Df2(4,5) = cos(q(4))*sin(q(0))*sin(q(1))*sin(q(2)) - sin(q(4))*(cos(q(1))*sin(q(0))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(0))*sin(q(1)));
        Df2(4,6) = sin(q(5))*(cos(q(4))*(cos(q(1))*sin(q(0))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(0))*sin(q(1))) + sin(q(0))*sin(q(1))*sin(q(2))*sin(q(4))) + cos(q(5))*(cos(q(1))*cos(q(3))*sin(q(0)) + cos(q(2))*sin(q(0))*sin(q(1))*sin(q(3)));
        Df2(5,2) = -sin(q(1)); Df2(5,3) = -cos(q(1))*sin(q(2)); Df2(5,4) = cos(q(1))*cos(q(2))*sin(q(3)) - cos(q(3))*sin(q(1));
        Df2(5,5) = sin(q(4))*(sin(q(1))*sin(q(3)) + cos(q(1))*cos(q(2))*cos(q(3))) + cos(q(1))*cos(q(4))*sin(q(2));
        Df2(5,6) = -sin(q(5))*(cos(q(4))*(sin(q(1))*sin(q(3)) + cos(q(1))*cos(q(2))*cos(q(3))) - cos(q(1))*sin(q(2))*sin(q(4))) - cos(q(5))*(cos(q(3))*sin(q(1)) - cos(q(1))*cos(q(2))*sin(q(3)));
        
        Df3.setZero(6,7);
        Df3(0,0) = (2*sin(q(3))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2))))/5;
        Df3(0,1) = -(2*cos(q(0))*sin(q(1))*sin(q(2))*sin(q(3)))/5;
        Df3(0,2) = -(2*sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))))/5;
        Df3(0,3) = (2*cos(q(2))*cos(q(3))*sin(q(0)))/5 + (2*cos(q(0))*cos(q(1))*cos(q(3))*sin(q(2)))/5;
        Df3(1,0) = (2*sin(q(3))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2))))/5;
        Df3(1,1) = -(2*sin(q(0))*sin(q(1))*sin(q(2))*sin(q(3)))/5;
        Df3(1,2) = (2*sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))))/5;
        Df3(1,3) = (2*cos(q(1))*cos(q(3))*sin(q(0))*sin(q(2)))/5 - (2*cos(q(0))*cos(q(2))*cos(q(3)))/5;
        Df3(2,1) = -(2*cos(q(1))*sin(q(2))*sin(q(3)))/5; Df3(2,2) = -(2*cos(q(2))*sin(q(1))*sin(q(3)))/5;
        Df3(2,3) = -(2*cos(q(3))*sin(q(1))*sin(q(2)))/5;
        Df3(3,3) = cos(q(0))*cos(q(1))*cos(q(2)) - sin(q(0))*sin(q(2));
        Df3(3,4) = sin(q(3))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2))); 
        Df3(3,5) = cos(q(4))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) + cos(q(3))*sin(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2)));
        Df3(3,6) = sin(q(5))*(sin(q(4))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(3))*cos(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2)))) + cos(q(5))*sin(q(3))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2)));
        Df3(4,3) = cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0));
        Df3(4,4) = -sin(q(3))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2)));
        Df3(4,5) = -cos(q(4))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - cos(q(3))*sin(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2)));
        Df3(4,6) = -sin(q(5))*(sin(q(4))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - cos(q(3))*cos(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2)))) - cos(q(5))*sin(q(3))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2)));
        Df3(5,3) = -cos(q(2))*sin(q(1)); Df3(5,4) = -sin(q(1))*sin(q(2))*sin(q(3));
        Df3(5,5) = cos(q(2))*cos(q(4))*sin(q(1)) - cos(q(3))*sin(q(1))*sin(q(2))*sin(q(4));
        Df3(5,6) = sin(q(5))*(cos(q(2))*sin(q(1))*sin(q(4)) + cos(q(3))*cos(q(4))*sin(q(1))*sin(q(2))) - cos(q(5))*sin(q(1))*sin(q(2))*sin(q(3));

        Df4.setZero(6,7);
        Df4(0,0) = (2*cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))))/5 + (2*sin(q(0))*sin(q(1))*sin(q(3)))/5;
        Df4(0,1) = -cos(q(0))*((2*cos(q(1))*sin(q(3)))/5 - (2*cos(q(2))*cos(q(3))*sin(q(1)))/5);
        Df4(0,2) = (2*cos(q(3))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2))))/5;
        Df4(0,3) = (2*cos(q(0))*cos(q(1))*cos(q(2))*sin(q(3)))/5 - (2*cos(q(0))*cos(q(3))*sin(q(1)))/5 - (2*sin(q(0))*sin(q(2))*sin(q(3)))/5;   
        Df4(1,0) = (2*cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))))/5 - (2*cos(q(0))*sin(q(1))*sin(q(3)))/5;
        Df4(1,1) = -sin(q(0))*((2*cos(q(1))*sin(q(3)))/5 - (2*cos(q(2))*cos(q(3))*sin(q(1)))/5);
        Df4(1,2) = -(2*cos(q(3))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2))))/5;
        Df4(1,3) = (2*cos(q(0))*sin(q(2))*sin(q(3)))/5 - (2*cos(q(3))*sin(q(0))*sin(q(1)))/5 + (2*cos(q(1))*cos(q(2))*sin(q(0))*sin(q(3)))/5; 
        Df4(2,0) = 0; Df4(2,1) = (2*sin(q(1))*sin(q(3)))/5 + (2*cos(q(1))*cos(q(2))*cos(q(3)))/5;
        Df4(2,2) = -(2*cos(q(3))*sin(q(1))*sin(q(2)))/5; Df4(2,3) = -(2*cos(q(1))*cos(q(3)))/5 - (2*cos(q(2))*sin(q(1))*sin(q(3)))/5;
        Df4(3,4) = cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3));
        Df4(3,5) = -sin(q(4))*(sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) + cos(q(0))*cos(q(3))*sin(q(1)));
        Df4(3,6) = cos(q(5))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) + cos(q(4))*sin(q(5))*(sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) + cos(q(0))*cos(q(3))*sin(q(1)));
        Df4(4,4) = -cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - sin(q(0))*sin(q(1))*sin(q(3));
        Df4(4,5) = sin(q(4))*(sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - cos(q(3))*sin(q(0))*sin(q(1)));
        Df4(4,6) = -cos(q(5))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) - cos(q(4))*sin(q(5))*(sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - cos(q(3))*sin(q(0))*sin(q(1)));
        Df4(5,4) = cos(q(2))*cos(q(3))*sin(q(1)) - cos(q(1))*sin(q(3)); 
        Df4(5,5) = -sin(q(4))*(cos(q(1))*cos(q(3)) + cos(q(2))*sin(q(1))*sin(q(3)));
        Df4(5,6) = cos(q(4))*sin(q(5))*(cos(q(1))*cos(q(3)) + cos(q(2))*sin(q(1))*sin(q(3))) - cos(q(5))*(cos(q(1))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(1)));

        Df5.setZero(6,7);
        Df5(3,5) = cos(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2)));
        Df5(3,6) = sin(q(5))*(sin(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) - cos(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2))));
        Df5(4,5) = -cos(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) - sin(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2)));
        Df5(4,6) = -sin(q(5))*(sin(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) - cos(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2))));
        Df5(5,5) = -cos(q(4))*(cos(q(1))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(1))) - sin(q(1))*sin(q(2))*sin(q(4));
        Df5(5,6) = -sin(q(5))*(sin(q(4))*(cos(q(1))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(1))) - cos(q(4))*sin(q(1))*sin(q(2)));
 
        Df6.setZero(6,7);
        Df6(3,6) = -sin(q(5))*(sin(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) + cos(q(0))*cos(q(3))*sin(q(1))) - cos(q(5))*(cos(q(4))*(cos(q(3))*(sin(q(0))*sin(q(2)) - cos(q(0))*cos(q(1))*cos(q(2))) - cos(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(2))*sin(q(0)) + cos(q(0))*cos(q(1))*sin(q(2))));
        Df6(4,6) = sin(q(5))*(sin(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) - cos(q(3))*sin(q(0))*sin(q(1))) + cos(q(5))*(cos(q(4))*(cos(q(3))*(cos(q(0))*sin(q(2)) + cos(q(1))*cos(q(2))*sin(q(0))) + sin(q(0))*sin(q(1))*sin(q(3))) + sin(q(4))*(cos(q(0))*cos(q(2)) - cos(q(1))*sin(q(0))*sin(q(2))));
        Df6(5,6) = cos(q(5))*(cos(q(4))*(cos(q(1))*sin(q(3)) - cos(q(2))*cos(q(3))*sin(q(1))) + sin(q(1))*sin(q(2))*sin(q(4))) - sin(q(5))*(cos(q(1))*cos(q(3)) + cos(q(2))*sin(q(1))*sin(q(3)));
 

        //float w = (pow((q(0)/5.93),2) + pow((q(1)/4.185),2) + pow((q(2)/5.93),2) + pow((q(3)/4.185),2) + pow((q(4)/5.93),2) + pow((q(5)/4.185),2) + pow((q(6)/6.1),2))/14;
        float w = sqrt((J*J.transpose()).determinant());
        W(0) = w*(Df1*PseudoJ).trace();
        //W(0) = 0;
        W(1) = w*(Df2*PseudoJ).trace();
        W(2) = w*(Df3*PseudoJ).trace();
        W(3) = w*(Df4*PseudoJ).trace();
        W(4) = w*(Df5*PseudoJ).trace();
        W(5) = w*(Df6*PseudoJ).trace();
        W(6) = 0;

         return W;
    }

    Matrix<float,3,1> iiwa_kinematics::QuatErr(Matrix<float,4,1> qd, Matrix<float,4,1> qe){
           
        Matrix<float,3,1> eo;
        Matrix<float,3,3> Sed;

        Sed.setZero(3,3);
        Sed(0,1) = -qd(3); Sed(0,2) = qd(2); Sed(1,0) = qd(3); Sed(1,2) = -qd(1); Sed(2,0) = -qd(2); Sed(2,1) = qd(1); // ho definito operatore antisimmetrico che porca troia è un casino
        eo = qe(0)*qd.block(1,0,3,1) - qd(0)*qe.block(1,0,3,1) - Sed*qe.block(1,0,3,1); //formula siciliano 3.91 tipo errore orientamento per quaternioni

        return eo;
    }

    Matrix<float,3,3> iiwa_kinematics::RPY2Mat(Matrix<float,3,1> rpy){
           
        Matrix<float,3,3> RPY; RPY.setZero(3,3);

        RPY(0,0) = cos(rpy(0))*cos(rpy(1));
        RPY(0,1) = cos(rpy(0))*sin(rpy(1))*sin(rpy(2)) - sin(rpy(0))*cos(rpy(2));
        RPY(0,2) = cos(rpy(0))*sin(rpy(1))*cos(rpy(2)) + sin(rpy(0))*sin(rpy(2));
        RPY(1,0) = sin(rpy(0))*cos(rpy(1));
        RPY(1,1) = sin(rpy(0))*sin(rpy(1))*sin(rpy(2)) + cos(rpy(0))*cos(rpy(2));
        RPY(1,2) = sin(rpy(0))*sin(rpy(1))*cos(rpy(2)) - cos(rpy(0))*sin(rpy(2));
        RPY(2,0) = -sin(rpy(1));
        RPY(2,1) = sin(rpy(2))*cos(rpy(1));
        RPY(2,2) = cos(rpy(2))*cos(rpy(1));

        return RPY;
    }


    Matrix<float,3,1> iiwa_kinematics::Quat2RPY(Matrix<float,4,1> q){

        Matrix<float,3,1> RPY;

        RPY(2) = atan2(2*(q(0)*q(1)+q(2)*q(3)),1-2*(q(1)*q(1)+q(2)*q(2)));
        float sinp = 2*(q(0)*q(2)-q(3)*q(1));
        if(abs(sinp)>=1) RPY(1) = copysign(M_PI_2,sinp);
        else RPY(1) = asin(sinp);
        RPY(0) = atan2(2*(q(0)*q(3)+q(1)*q(2)), 1-2*(q(2)*q(2)+q(3)*q(3)));

        return RPY;
    }

 }
