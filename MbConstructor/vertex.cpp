#include "vertex.hpp"

const Point3D &Vertex::getPostion() const
{
    return this->position;
}

void Vertex::setPosition(Point3D positionParam)
{
    this->position = positionParam;
}

const std::vector<size_t> Vertex::getFacets()
{
    return this->facets;
}

void Vertex::setFacets(std::vector<size_t> facetsParam)
{
    this->facets = facetsParam;
}
