#ifndef FACADE_HPP
#define FACADE_HPP

#include <QGraphicsView>
#include "/usr/include/eigen3/Eigen/Dense"
#include "components.hpp"

class Drawer
{
public:
    void zBuffer(SceneInfinite *scene, size_t bufferHeight, size_t bufferWidth);
    void zBufferModel(std::vector<Facet> &facets, std::vector<Vertex> vertices, Eigen::Matrix4f &trMatrix, size_t color, SceneInfinite *scene, size_t bufferWidth, size_t bufferHeight);
    void shadowMapModel();

    QGraphicsScene *drawScene();
};

#endif // FACADE_HPP
