#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include "mathelements.hpp"

class Vertex
{
public:
    Vertex() { }; // DONE
    Vertex(Point3D &positionParam, std::vector<size_t> &facetsParam) : position(positionParam), facets(facetsParam) { } // DONE
    Vertex(Point3D &positionParam) : position(positionParam) { } // DONE

    const Point3D &getPostion() const; // DONE
    void setPosition(Point3D positionParam); // DONE

    const std::vector<size_t> getFacets(); // DONE
    void setFacets(std::vector<size_t> facetsParam); // DONE

private:
    Point3D position;
    std::vector<size_t> facets;
};

#endif // VERTEX_HPP
