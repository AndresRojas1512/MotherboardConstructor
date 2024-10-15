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
private:
    std::vector<std::vector<double>> depthBuffer;
    std::vector<std::vector<size_t>> borderBuffer;
};


class Facade
{
public:
    Facade();

    void setSceneInfinite(size_t widthParam, size_t heightParam);
    void changeSceneInfinte(size_t widthParam, size_t heightParam);
    bool isSceneSet();

    QGraphicsScene *drawScene(QRectF rect);
private:
    SceneInfinite *scene = nullptr;
    Drawer *drawer;
};

#endif // FACADE_HPP
