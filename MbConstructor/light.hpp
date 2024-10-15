#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <vector>
#include "mathelements.hpp"
#include "config.hpp"

class Light
{
public:
    Light() { } // DONE
    Light(Eigen::Matrix4f &trMatrixParam); // DONE

    std::vector<std::vector<double>> &getShadowMap(); // DONE
    void setShadowMap(std::vector<std::vector<double>> &shadowMapParam);  // TODO
    void clearShadowMap(); // TODO

    int getXAngle(); // TODO
    int getYAngle(); // TODO
    void setAngles(int xAngleParam, int yAngleParam); // TODO

    Eigen::Matrix4f getTrMatrix(); // TODO
    void setTrMatrix(Eigen::Matrix4f &matrix); // TODO
private:
    std::vector<std::vector<double>> shadowMap;
    Eigen::Matrix4f transformationMatrix;
    int xAngle;
    int yAngle;
};

#endif // LIGHT_HPP
