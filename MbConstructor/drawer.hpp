#ifndef DRAWER_HPP
#define DRAWER_HPP

#include "sceneinfinite.hpp"

class Drawer
{
public:
    void zBuffer(SceneInfinite *scene, size_t bufferHeight, size_t bufferWidth);
    void zBufferModel(std::vector<Facet> &facets, std::vector<Vertex> vertices, Eigen::Matrix4f &trMatrix, size_t color, SceneInfinite *scene, size_t bufferWidth, size_t bufferHeight);
private:
    std::vector<std::vector<double>> depthBuffer;
    std::vector<std::vector<size_t>> borderBuffer;
};

#endif // DRAWER_HPP
