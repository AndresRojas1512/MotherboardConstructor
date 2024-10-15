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
    void setShadowMap(std::vector<std::vector<double>> &shadowMapParam);
    void clearShadowMap(); // DONE

    int getXAngle(); // DONE
    int getYAngle(); // DONE
    void setAngles(int xAngleParam, int yAngleParam); // DONE

    Eigen::Matrix4f getTrMatrix(); // DONE
    void setTrMatrix(Eigen::Matrix4f &matrix); // DONE
private:
    std::vector<std::vector<double>> shadowMap;
    Eigen::Matrix4f transformationMatrix;
    int xAngle;
    int yAngle;
};

#endif // LIGHT_HPP
