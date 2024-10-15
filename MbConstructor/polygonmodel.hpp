#ifndef POLYGONMODEL_HPP
#define POLYGONMODEL_HPP

#include <QString>
#include "mathelements.hpp"
#include "vertex.hpp"
#include "facet.hpp"

class PolygonModel
{
public:
    PolygonModel() { } // DONE
    PolygonModel(std::vector<Vertex> verticesParam, std::vector<Facet> facetsParam) : vertices(verticesParam), facets(facetsParam) { } // DONE
    PolygonModel(std::vector<Vertex> verticesParam, std::vector<Facet> facetsParam, QString nameParam) : vertices(verticesParam), facets(facetsParam), modelName(nameParam) { } // DONE

    ~PolygonModel() { }; // DONE

    enum model_t
    {
        Motherboard,
        RAM,
        GPU
    };

    const std::vector<Vertex> getVertices(); // DONE

    const std::vector<Facet> getFacets(); // DONE

    model_t getModelType(); // DONE
    void setModelType(model_t modelTypeParam); // DONE

    void setUsedCell(int xCellParam, int yCellParam, double zCellParam); // DONE
    int getUsedXCell(); // DONE
    int getUsedYCell(); // DONE
    int getUsedZCell(); // DONE

    int getModelWidth(); // DONE
    void setModelWidth(int modelWidthParam); // DONE

    int getModelLength(); // DONE
    void setModelLength(int modelLengthParam); // DONE

    size_t getModelIndex(); // DONE
    void setModelIndex(size_t modelIndexParam); // DONE

    QString getModelName(); // DONE
    void setModelName(QString modelNameParam); // DONE

private:
    int xCell;
    int yCell;
    double zCell;

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    QString modelName;

    int modelWidth;
    int modelLength;

    size_t modelIndex;
    model_t modelType;
};

#endif // POLYGONMODEL_HPP
