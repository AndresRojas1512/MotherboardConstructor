#include "mathelements.hpp"

// --- Point2D ---

// getters

double Point2D::getXCoord()
{
    return this->xCoord;
}

double Point2D::getYCoord()
{
    return this->yCoord;
}

// setters

void Point2D::setXCoord(double xVal)
{
    this->xCoord = xVal;
}

void Point2D::setYCoord(double yVal)
{
    this->yCoord = yVal;
}

// --- Point3D ---

// getters

double Point3D::getXCoord()
{
    return this->xCoord;
}

double Point3D::getYCoord()
{
    return this->yCoord;
}

double Point3D::getZCoord()
{
    return this->zCoord;
}

// setters

void Point3D::setXCoord(double xVal)
{
    this->xCoord = xVal;
}

void Point3D::setYCoord(double yVal)
{
    this->yCoord = yVal;
}

void Point3D::setZCoord(double zVal)
{
    this->zCoord = zVal;
}

void Point3D::scale(double coeff, double xCenter, double yCenter, double zCenter)
{
    this->xCoord -= xCenter;
    this->yCoord -= yCenter;
    this->zCoord -= zCenter;

    Eigen::Matrix4f scaleMatrix;
    scaleMatrix << coeff, 0, 0, 0,
                    0, coeff, 0, 0,
                    0, 0, coeff, 0,
                    0, 0,     0, 1;
    
    Eigen::MatrixXf coordsVector(1, 4);
    coordsVector << this->xCoord, this->yCoord, this->zCoord, 1;

    coordsVector = coordsVector * scaleMatrix;

    this->xCoord = coordsVector(0, 0) + xCenter;
    this->yCoord = coordsVector(0, 1) + yCenter;
    this->zCoord = coordsVector(0, 2) + zCenter;
}

void Point3D::move(double dx, double dy, double dz)
{
    this->xCoord += dx;
    this->yCoord += dy;
    this->zCoord += dz;
}

void Point3D::rotateX(double angle, double xCenter, double yCenter, double zCenter)
{
    this->xCoord -= xCenter;
    this->yCoord -= yCenter;
    this->zCoord -= zCenter;

    Eigen::Matrix4f rotationMatrix;
    rotationMatrix << 1,          0,           0, 0,
                      0, cos(angle), -sin(angle), 0,
                      0, sin(angle),  cos(angle), 0,
                      0,          0,           0, 1;
    
    Eigen::MatrixXf coordsVector(1, 4);
    coordsVector << this->xCoord, this->yCoord, this->zCoord, 1;

    coordsVector = coordsVector * rotationMatrix;

    this->xCoord = coordsVector(0, 0) + xCenter;
    this->yCoord = coordsVector(0, 1) + yCenter;
    this->zCoord = coordsVector(0, 2) + zCenter;
}

void Point3D::rotateY(double angle, double xCenter, double yCenter, double zCenter)
{
    this->xCoord -= xCenter;
    this->yCoord -= yCenter;
    this->zCoord -= zCenter;

    Eigen::Matrix4f rotationMatrix;
    rotationMatrix << cos(angle),  0, sin(angle), 0,
                      0,           1,          0, 0,
                      -sin(angle), 0, cos(angle), 0,
                      0,           0,          0, 1;
    
    Eigen::MatrixXf coordsVector(1, 4);
    coordsVector << this->xCoord, this->yCoord, this->zCoord, 1;

    coordsVector = coordsVector * rotationMatrix;

    this->xCoord = coordsVector(0, 0) + xCenter;
    this->yCoord = coordsVector(0, 1) + yCenter;
    this->zCoord = coordsVector(0, 2) + zCenter;
}

void Point3D::rotateZ(double angle, double xCenter, double yCenter, double zCenter)
{
    this->xCoord -= xCenter;
    this->yCoord -= yCenter;
    this->zCoord -= zCenter;

    Eigen::Matrix4f rotationMatrix;
    rotationMatrix << cos(angle), -sin(angle), 0, 0,
                      sin(angle),  cos(angle), 0, 0,
                      0,                    0, 1, 0,
                      0,                    0, 0, 1;
    
    Eigen::MatrixXf coordsVector(1, 4);
    coordsVector << this->xCoord, this->yCoord, this->zCoord, 1;

    coordsVector = coordsVector * rotationMatrix;

    this->xCoord = coordsVector(0, 0) + xCenter;
    this->yCoord = coordsVector(0, 1) + yCenter;
    this->zCoord = coordsVector(0, 2) + zCenter;
}
