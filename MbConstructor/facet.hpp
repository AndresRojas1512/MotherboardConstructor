#ifndef FACET_HPP
#define FACET_HPP

#include <vector>
#include "mathelements.hpp"

class Facet
{
public:
    Facet() {} // DONE
    Facet(std::vector<size_t> verticesParam) : vertices(verticesParam) { } // DONE

    const std::vector<size_t> getVertices(); // DONE

private:
    std::vector<size_t> vertices;
};

#endif // FACET_HPP
