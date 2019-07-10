#ifndef LAYERGROUP_H
#define LAYERGROUP_H

#include "layer.h"
#include <vector>
#include <QObject>
const int defaultSize = 1000;

typedef Layer* LayerPtr;

class LayerGroup : public QObject
{
    Q_OBJECT
private:
    int layerNum;
    int maxHeight, maxWidth;
    vector<int> vec_id;
    vector<Layer*> vec_layer;

signals:
    void inserted(int);
    void removed(int);

public:
    LayerGroup(int maxHeight = defaultSize, int maxWidth = defaultSize);
    LayerGroup(string file_name, string name = "unknown");

    ~LayerGroup();

    // Insert function
    // default is to be inserted at the tail
    // otherwise inserted after layer with id
    // cannot insert after the last layer or before the first layer
    bool insert(Layer layer, int id = -1);

    QImage get_preview();

    // Delete function
    // delete the layer with this->id == id,
    // cannot delete the first and the last layer
    bool remove(int id);

    // given a new layer_id order
    // to reorder vec_id and vec_layer
    bool reorder(vector<int> new_id);

    vector<int> get_vec_id();

    vector<Layer*>& get_vec_layer();

    int get_layernum(){return this->layerNum;}

    void set_maxHeight(int x)
    {
        this->maxHeight = x;
        vec_layer[0]->M = Mat(maxHeight, maxWidth, CV_8UC3, Scalar(255, 255, 255));
        vec_layer[0]->valued = Mat(maxHeight, maxWidth, CV_8UC1, Scalar(255));
    }
    int get_maxHeight() { return this->maxHeight; }

    void set_maxWidth(int x)
    {
        this->maxWidth = x;
        vec_layer[0]->M = Mat(maxHeight, maxWidth, CV_8UC3, Scalar(255, 255, 255));
        vec_layer[0]->valued = Mat(maxHeight, maxWidth, CV_8UC1, Scalar(255));
    }
    int get_maxWidth() { return this->maxWidth; }
};

extern Mat rst;
#endif // LAYERGROUP_H
