#include "components.hpp"

// PolygonModel

const std::vector<Vertex> PolygonModel::getVertices()
{
    return this->vertices;
}

const std::vector<Facet> PolygonModel::getFacets()
{
    return this->facets;
}

PolygonModel::model_t PolygonModel::geModelType()
{
    return this->modelType;
}

void PolygonModel::setModelType(PolygonModel::model_t modelTypeParam)
{
    this->modelType = modelTypeParam;
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

// Scene infinite

SceneInfinite::SceneInfinite(size_t widthParam, size_t heightParam)
{
    this->width = widthParam;
    this->height = heightParam;

    componentsNum = 0;
    lightsNum = 0;

    initUsedZCells();
    toCenter();
}

void SceneInfinite::initUsedZCells()
{
    this->usedZCells.resize(this->getHeight());
    for(size_t i = 0; i < this->getHeight(); i++)
    {
        this->usedZCells[i].resize(this->getWidth());
        for (size_t j = 0; j < this->getWidth(); j++)
        {
            this->usedZCells[i][j].resize(1, 0);
        }
    }
}

size_t SceneInfinite::getWidth()
{
    return this->width;
}

size_t SceneInfinite::getHeight()
{
    return this->height;
}

void SceneInfinite::clearUsedZCells(size_t index)
{
    // TODO
}

size_t SceneInfinite::getComponentsNum()
{
    return this->componentsNum;
}

PolygonModel &SceneInfinite::getComponent(size_t index)
{
    return this->components.at(index);
}

void SceneInfinite::setComponent(size_t index, PolygonModel &component)
{
    this->components.at(index) = component;
}

void SceneInfinite::addComponent(PolygonModel &component)
{
    this->componentsNum++;
    components.push_back(component);
    // TODO: control z cells
}

void SceneInfinite::deleteComponent(size_t index)
{
    if (index < this->components.size())
    {
        // TODO
    }
}


void SceneInfinite::toCenter()
{
    Point3D startPoint(BASE_START);
    Eigen::Matrix4f matrix;
    matrix << 1, 0, 0, 0,
              0, 1, 0, 0,
              0, 0, 1, 0,
              0, 0, 0, 1;

    matrix(3, 0) = X_CENTER - startPoint.getXCoord() - this->getWidth() * SIZE_SC / 2;
    matrix(3, 1) = Y_CENTER - startPoint.getYCoord() - this->getHeight() * SIZE_SC / 2;
    matrix(3, 2) = 0;
    this->transformationMatrix = matrix;
}
