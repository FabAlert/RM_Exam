#ifndef IIWA_TRAJECTORY_H
#define IIWA_TRAJECTORY_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <eigen3/Eigen/Geometry>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/SVD>
#include <eigen3/Eigen/Core>

using namespace Eigen;
using namespace std;

namespace iiwa_trajectory{

   class iiwa_trajectory{

   private:
   Matrix<float,6,7> Via_Points;
   Matrix<float,7,1> Time;

   public:
   iiwa_trajectory(Matrix<float,6,7>, Matrix<float,7,1>);
   Matrix<float,3,1> GenTrapezoidalTraj(float, float, float, float);
   Matrix<float,6,3> GenTraj(float);
   Matrix<float,6,1> GenSinForce(float, Matrix<float,3,1>, Matrix<float,3,1>, Matrix<float,3,1>);
   Matrix<float,6,1> GenLinForce(Matrix<float,3,1>);
   Matrix<float,6,1> GenAngForce(float, Matrix<float,3,1>);
   };

}

#endif
