#include "facade.hpp"

void Drawer::zBuffer(SceneInfinite *scene, size_t bufferHeight, size_t bufferWidth)
{
    depthBuffer.erase(depthBuffer.begin(), depthBuffer.end());
    borderBuffer.erase(borderBuffer.begin(), borderBuffer.end());

    for (size_t i = 0; i < bufferWidth; i++)
    {
        depthBuffer.push_back(std::vector<double>(bufferHeight, 0));
        borderBuffer.push_back(std::vector<size_t>(bufferHeight, 0));
    }
    PolygonModel component;
    std::vector<Facet> facets;
    std::vector<Vertex> vertices;
    PolygonModel::component_t componentType;

    for (size_t i = 0; i < scene->getComponentsNum(); i++)
    {
        component = scene->getComponent(i);
        facets = component.getFacets();
        vertices = component.getVertices();

        // TODO: handle light source
    }
}
