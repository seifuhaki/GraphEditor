#ifndef LAYER_H
#define LAYER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QImage>
#include <QDebug>
#include <cmath>
#include <cstring>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

enum Transparency { TRANSPARENT, OPAQUE };

const double PI = acos(-1);
const double EPS = 1e-6;

class Layer
{
private:
    string name;
    // name of this layer
    int id;
    // the ID of this layer
    Transparency visionType;
    // The type of how this Layer is seen.
    // TRANSPARENT : only the valued pixels will be mapped on the screen
    // OPAQUE: all pixels of this layer will be mapped
    bool visibility;
    // determine whether this layer should be mapped
    int width, height;
    // Size
    int minRow, minCol;
    // Position of this layer on the Canvas
    double angle;
    // rotation
    Mat M, valued, thumbNail;
public:
    static int layerCount;
    friend class LayerGroup;
    friend class LayerBasic;
    // To write other operations of different types
    // you can add other friend classes

    Layer();
    ~Layer();
    Layer(Layer& l);
    Layer(string FILE_PATH, string name, Transparency visionType, bool visibility = 1, int minRow = 0, int minCol = 0);
    Layer(string name, Transparency visionType, int width, int height, bool visibility, int minRow, int minCol, Mat M);

    Layer& operator= (Layer& l);

    void create(string FILE_PATH, string name, Transparency visionType, bool visibility = 1, int minRow = 0, int minCol = 0);
    void create(Mat M, string name, Transparency visionType, bool visibility = 1, int minRow = 0, int minCol = 0);
    void create(string name, Transparency visionType = OPAQUE, int width = 0, int height = 0, bool visibility = 1, int minRow = 0, int minCol = 0);

    void set_name(string name) { this->name = name; }
    string get_name() { return this->name; }

    void set_id(int id) { this->id = id; }
    int get_id() { return this->id; }

    void set_minRow(int x) { this->minRow = x; }
    int get_minRow() { return this->minRow; }

    void set_minCol(int x) { this->minCol = x; }
    int get_minCol() { return this->minCol; }

    int get_width() { return this->width; }

    int get_height() { return this->height; }

    void set_visionType(Transparency tsp) { this->visionType = tsp; }
    Transparency get_visionType() { return this->visionType; }

    void set_visibility(bool vis) { this->visibility = vis; }
    bool get_visibility() { return this->visibility; }

    void clear_valued()
    {
        valued = Mat(valued.rows, valued.cols, CV_8UC1, Scalar(0));
    }
    void fill_valued()
    {
        valued = Mat(valued.rows, valued.cols, CV_8UC1, Scalar(255));
    }

    QImage toQImage_ref(QImage::Format format) {
        return QImage(M.data, M.cols, M.rows, static_cast<int>(M.step), format);
    }

    void set_angle(double theta) { angle = PI * theta / 180; }
    QImage getThumbNail(int height, int width);
};

#endif // LAYER_H
