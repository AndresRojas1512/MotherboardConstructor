#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <iostream>
#include <vector>
#include "mathelements.hpp"
#include "config.hpp"

class Vertex
{
private:
    Point3D position;
    std::vector<size_t> facets;

public:
    Vertex() { };
    Vertex(Point3D &positionParam, std::vector<size_t> &facetsParam) : position(positionParam), facets(facetsParam) { }
    Vertex(Point3D &positionParam) : position(positionParam) { }

    const Point3D &getPostion() const;
    const std::vector<size_t> getFacets();

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
public:
    enum component_t
    {
        Motherboard,
        GPU,
        RAM
    };
    PolygonModel() { }
    PolygonModel(std::vector<Vertex> verticesParam, std::vector<Facet> facetsParam) : vertices(verticesParam), facets(facetsParam) { }
    PolygonModel(std::vector<Vertex> verticesParam, std::vector<Facet> facetsParam, std::string nameParam) : vertices(verticesParam), facets(facetsParam), componentName(nameParam) { }

    ~PolygonModel() { };

    // getters
    const std::vector<Vertex> getVertices();
    const std::vector<Facet> getFacets();
    component_t getComponentType();

private:
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    std::string componentName;

    size_t modelNum;
    component_t componentType;
};

class Light
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
public:
    SceneInfinite() {} // DONE
    SceneInfinite(size_t widthParam, size_t heightParam); // DONE

    void initUsedZCells(); // DONE
    void clearUsedZCells(size_t index); // TODO

    operator bool() const;

    size_t getWidth();
    size_t getHeight();

    size_t getComponentsNum(); // DONE
    PolygonModel &getComponent(size_t index); // DONE
    void setComponent(size_t index, PolygonModel &component); // DONE
    void addComponent(PolygonModel &component); // DONE
    void deleteComponent(size_t index); // TODO

    void toCenter();

private: // DONE
    size_t width;
    size_t height;

    PolygonModel *motherboardModel = nullptr;

    Eigen::Matrix4f transformationMatrix;

    size_t componentsNum = 0;
    std::vector<PolygonModel> components;

    size_t lightsNum = 0;
    std::vector<Light> lights;

    Point3D center;

    std::vector<std::vector<std::vector<double>>> usedZCells;
};

#endif // COMPONENTS_HPP
