#ifndef MATHELEMENTS_H
#define MATHELEMENTS_H

#include <iostream>
#include <vector>

#include "/usr/include/eigen3/Eigen/Dense"
#include "math.h"

class Point2D
{
    private:
        double xCoord;
        double yCoord;
    
    public:
        // getters
        double getXCoord();
        double getYCoord();

        // setters
        void setXCoord(double xVal);
        void setYCoord(double yVal);
};

class Point3D
{
    private:
        double xCoord;
        double yCoord;
        double zCoord;
    
    public:
        // getters
        double getXCoord();
        double getYCoord();
        double getZCoord();
    
        //setters
        void setXCoord(double xVal);
        void setYCoord(double yVal);
        void setZCoord(double zVal);

        void scale(double coeff, double xCenter, double yCenter, double zCenter);
        void move(double dx, double dy, double dz);
        void rotateX(double angle, double xCenter, double yCenter, double zCenter);
        void rotateY(double angle, double xCenter, double yCenter, double zCenter);
        void rotateZ(double angle, double xCenter, double yCenter, double zCenter);
};

class MathVector
{
    private:
        double xInc;
        double yInc;
        double zInc;
    
    public:
        // getters
        double getXInc();
        double getYInc();
        double getZInc();

        // setters
        void setXInc(double xVal);
        void setYInc(double yVal);
        void setZInc(double zVal);
};

#endif
