#ifndef IIWA_KINEMATICS_H
#define IIWA_KINEMATICS_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <eigen3/Eigen/Geometry>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/SVD>
#include <eigen3/Eigen/Core>

using namespace Eigen;
using namespace std;

#define d3  0.4
#define d5  0.4

namespace iiwa_kinematics{
   class iiwa_kinematics{
    public:
    iiwa_kinematics();
    Matrix<float,6,7> get_J(Matrix<float,7,1>);  //Jacobiano
    Matrix<float,4,4> get_Te(Matrix<float,7,1>); //Matrice Trasformazione
    Matrix<float,4,1> MatToQuat(Matrix<float,3,3>); //Trasformazione con Quaternione
    Matrix<float,7,1> get_W(Matrix<float,7,1>);   //misura di manipolabilità
    Matrix<float,3,3> RPY2Mat(Matrix<float,3,1>); // da RPY a Quat;
    Matrix<float,3,1> Quat2RPY(Matrix<float,4,1>); //Da Quat a Eulero
    Matrix<float,3,1> QuatErr(Matrix<float,4,1>, Matrix<float,4,1>); // calcolo errore tra quaternioni
   };
}

#endif
