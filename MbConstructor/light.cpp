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
    // two cycles?
}

int Light::getXAngle()
{

}

int Light::getYAngle()
{

}

void Light::setAngles(int xAngleParam, int yAngleParam)
{

}

Eigen::Matrix4f Light::getTrMatrix()
{

}

void Light::setTrMatrix(Eigen::Matrix4f &matrix)
{

}
