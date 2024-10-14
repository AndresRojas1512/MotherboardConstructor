#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <iostream>
#include <vector>
#include "mathelements.hpp"

enum component_t
{
    Motherboard,
    GPU,
    RAM
};

class Vertex
{
private:
    Point3D position;
    std::vector<size_t> facets;

public:
    Vertex() { };
    Vertex(Point3D &positionParam, std::vector<size_t> &facetsParam) : position(positionParam), facets(facetsParam) { }
    Vertex(Point3D &positionParam) : position(positionParam) { }

    // getters
    const Point3D &getPostion() const;
    const std::vector<size_t> getFacets();

    // setters
    void setPosition(Point3D positionParam);
    void setFacets(std::vector<size_t> facetsParam);
};

class Facet
{
private:
    std::vector<size_t> vertices;

public:
    Facet() {}
    Facet(std::vector<size_t> verticesParam) : vertices(verticesParam) { }

    // getter
    const std::vector<size_t> getVertices();
};

class PolygonModel
{
private:
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    std::string componentName;

    // define the position
    size_t modelNum;
    component_t componentType;
public:
    PolygonModel() { }
    PolygonModel(std::vector<Vertex> verticesParam, std::vector<Facet> facetsParam) : vertices(verticesParam), facets(facetsParam) { }
    PolygonModel(std::vector<Vertex> verticesParam, std::vector<Facet> facetsParam, std::string nameParam) : vertices(verticesParam), facets(facetsParam), componentName(nameParam) { }

    ~PolygonModel() { };

    // getters
    const std::vector<Vertex> getVertices();
    const std::vector<Facet> getFacets();
    component_t getComponentType();
};

class Light // TODO
{
private:
    std::vector<std::vector<double>> shadowMap;
    Eigen::Matrix4f transformationMatrix;
    int xAngle;
    int yAngle;

public:
    Light(Eigen::Matrix4f &trMatrix);
    Light() { };
};

class SceneInfinite
{
    SceneInfinite();
    SceneInfinite(size_t widthParam, size_t heightParam);

    operator bool() const;

    // getters
    size_t getWidth();

    // setters
};

#endif // COMPONENTS_HPP
