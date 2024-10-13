#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <iostream>
#include <vector>
#include "mathelements.hpp"

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
public:

};

#endif // COMPONENTS_HPP
