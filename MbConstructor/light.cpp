#include "light.hpp"

Light::Light(Eigen::Matrix4f &trMatrixParam)
{
    this->transformationMatrix = trMatrixParam;
    for (size_t i = 0; i < LIGHT_X; i++)
    {
        this->shadowMap.push_back(std::vector<double>(LIGHT_Y, 0));
    }
}

std::vector<std::vector<double>> &Light::getShadowMap()
{
    return this->shadowMap;
}

void Light::setShadowMap(std::vector<std::vector<double>> &shadowMapParam)
{
    this->shadowMap = shadowMapParam;
}

void Light::clearShadowMap()
{
    for (size_t i = 0; i < this->shadowMap.size(); i++)
    {
        for (size_t j = 0; j < this->shadowMap.at(0).size(); j++)
        {
            this->shadowMap.at(i).at(j) = 0;
        }
    }
}

int Light::getXAngle()
{
    return this->xAngle;
}

int Light::getYAngle()
{
    return this->yAngle;
}

void Light::setAngles(int xAngleParam, int yAngleParam)
{
    this->xAngle = xAngleParam;
    this->yAngle = yAngleParam;
}

Eigen::Matrix4f Light::getTrMatrix()
{
    return this->transformationMatrix;
}

void Light::setTrMatrix(Eigen::Matrix4f &matrix)
{
    this->transformationMatrix = matrix;
}
