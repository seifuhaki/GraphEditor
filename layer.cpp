#include "layer.h"

int Layer::layerCount = 0;

Scalar gt(Transparency vt)
{
    return vt == OPAQUE ? Scalar(1) : Scalar(0);
}

Layer::Layer()
{
    name = "unknown";
    visionType = OPAQUE;
    visibility = 1;
    minCol = minRow = 0;
    width = height = 0;
    id = ++layerCount;
    angle = 0;
    M = Mat(0, 0, CV_8UC3, Scalar(255, 255, 255));
    valued = Mat(0, 0, CV_8UC1, Scalar(255));
}

Layer::~Layer()
{
    ~M;
    ~valued;
}

Layer::Layer(Layer& l)
{
    this->name = l.name;
    this->visionType = l.visionType;
    this->visibility = l.visibility;
    this->minCol = l.minCol;
    this->minRow = l.minRow;
    this->width = l.width;
    this->height = l.height;
    this->id = l.id;
    this->angle = l.angle;
    this->M = l.M.clone();
    this->valued = l.valued.clone();
}

Layer::Layer(string FILE_PATH, string name, Transparency visionType, bool visibility, int minRow, int minCol)
    :name(name), visionType(visionType), minCol(minCol), minRow(minRow), visibility(visibility)
{
    M = imread(FILE_PATH);
    valued = Mat(M.rows, M.cols, CV_8UC1, Scalar(255));
    id = ++layerCount;
    width = M.cols;
    height = M.rows;
    angle = 0;
}

Layer::Layer(string name, Transparency visionType, int width, int height, bool visibility, int minRow, int minCol, Mat M)
    :name(name), visionType(visionType), visibility(visibility), width(width), height(height), minCol(minCol), minRow(minRow)
{
    this->M = M.clone();
    valued = Mat(height, width, CV_8UC1, Scalar(255));
    this->angle = 0;
}

Layer& Layer::operator= (Layer& l)
{
    this->name = l.name;
    this->visionType = l.visionType;
    this->visibility = l.visibility;
    this->minCol = l.minCol;
    this->minRow = l.minRow;
    this->width = l.width;
    this->height = l.height;
    this->id = l.id;
    this->M = l.M.clone();
    this->valued = l.valued.clone();
    this->angle = l.angle;

    return *this;
}

void Layer::create(string FILE_PATH, string name, Transparency visionType, bool visibility, int minRow, int minCol)
{
    M = imread(FILE_PATH);
    this->name = name;
    this->visionType = visionType;
    this->visibility = visibility;
    this->minRow = minRow;
    this->minCol = minCol;
    this->angle = 0;
    width = M.cols;
    height = M.rows;
    valued = Mat(M.rows, M.cols, CV_8UC1, Scalar(255));
}

void Layer::create(string name, Transparency visionType, int width, int height, bool visibility, int minRow, int minCol)
{
    M = Mat(height, width, CV_8UC3, Scalar(255, 255, 255));
    valued = Mat(height, width, CV_8UC1, Scalar(255));
    this->name = name;
    this->visionType = visionType;
    this->visibility = visibility;
    this->minRow = minRow;
    this->minCol = minCol;
    this->width = width;
    this->height = height;
    this->angle = 0;
}

void Layer::create(Mat M, string name, Transparency visionType, bool visibility, int minRow, int minCol)
{
    this->M = M.clone();
    valued = Mat(M.rows, M.cols, CV_8UC1, Scalar(255));
    this->name = name;
    this->visionType = visionType;
    this->visibility = visibility;
    this->minRow = minRow;
    this->minCol = minCol;
    this->width = M.cols;
    this->height = M.rows;
    this->angle = 0;
}

QImage Layer::getThumbNail(int width, int height)
{
    resize(M, thumbNail, Size(width, height), 0, 0, INTER_NEAREST);
    return QImage(thumbNail.data, thumbNail.cols, thumbNail.rows, static_cast<int>(thumbNail.step), QImage::Format_RGB888).rgbSwapped();
}
