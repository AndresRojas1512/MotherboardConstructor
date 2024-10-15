#include "polygonmodel.hpp"

const std::vector<Vertex> PolygonModel::getVertices()
{
    return this->vertices;
}

const std::vector<Facet> PolygonModel::getFacets()
{
    return this->facets;
}

PolygonModel::model_t PolygonModel::getModelType()
{
    return this->modelType;
}

void PolygonModel::setModelType(model_t modelTypeParam)
{
    this->modelType = modelTypeParam;
}

void PolygonModel::setUsedCell(int xCellParam, int yCellParam, double zCellParam)
{
    this->xCell = xCellParam;
    this->yCell = yCellParam;
    this->zCell = zCellParam;
}

int PolygonModel::getUsedXCell()
{
    return this->xCell;
}

int PolygonModel::getUsedYCell()
{
    return this->yCell;
}

int PolygonModel::getUsedZCell()
{
    return this->zCell;
}

int PolygonModel::getModelWidth()
{
    return this->modelWidth;
}
void PolygonModel::setModelWidth(int modelWidthParam)
{
    this->modelWidth = modelWidthParam;
}

int PolygonModel::getModelLength()
{
    return this->modelLength;
}

void PolygonModel::setModelLength(int modelLengthParam)
{
    this->modelLength = modelLengthParam;
}

size_t PolygonModel::getModelIndex()
{
    return this->modelIndex;
}

void PolygonModel::setModelIndex(size_t modelIndexParam)
{
    this->modelIndex = modelIndexParam;
}

QString PolygonModel::getModelName()
{
    return this->modelName;
}

void PolygonModel::setModelName(QString modelNameParam)
{
    this->modelName = modelNameParam;
}
