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
    PolygonModel() { } // DONE
    PolygonModel(std::vector<Vertex> verticesParam, std::vector<Facet> facetsParam) : vertices(verticesParam), facets(facetsParam) { } // DONE
    PolygonModel(std::vector<Vertex> verticesParam, std::vector<Facet> facetsParam, std::string nameParam) : vertices(verticesParam), facets(facetsParam), modelName(nameParam) { } // DONE

    ~PolygonModel() { };

    enum model_t
    {
        Motherboard,
        RAM,
        GPU
    };

    const std::vector<Vertex> getVertices(); // DONE

    const std::vector<Facet> getFacets(); // DONE

    model_t geModelType(); // DONE
    void setModelType(model_t modelTypeParam); // DONE

    void setUsedCell(int xCellParam, int yCellParam, double zCellParam); // TODO
    int getUsedXCell(); // TODO
    int getUsedYCell(); // TODO
    int getUsedZCell(); // TODO

    int getModelWidth(); // DONE
    void setModelWidth(int modelWidthParam); // DONE

    int getModelLength(); // DONE
    void setModelLength(int modelLengthParam); // DONE
private:
    int xCell;
    int yCell;
    double zCell;

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    std::string modelName;

    int modelWidth;
    int modelLength;

    size_t modelNum;
    model_t modelType;
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
