#include "layergroup.h"

Mat rst;

LayerGroup::LayerGroup(int maxHeight, int maxWidth)
{
    layerNum = 2;
    this->maxHeight = maxHeight;
    this->maxWidth = maxWidth;
    vec_id.clear();
    vec_layer.clear();

    LayerPtr bottom = new Layer, up = new Layer;
    bottom->create(tr("Bottom Layer").toStdString(), OPAQUE, maxWidth, maxHeight, 1, 0, 0);
    up->create(tr("Top Layer").toStdString(), TRANSPARENT, maxWidth, maxHeight, 1, 0, 0);
    up->clear_valued();

    vec_id.push_back(bottom->id);
    vec_layer.push_back(bottom);

    vec_id.push_back(up->id);
    vec_layer.push_back(up);
}

LayerGroup::LayerGroup(string file_name, string name)
{
    layerNum = 3;
    LayerPtr bottom = new Layer, mid = new Layer, up = new Layer;
    mid->create(file_name, name, OPAQUE);
    maxHeight = mid->height;
    maxWidth = mid->width;

    bottom->create(tr("Bottom Layer").toStdString(), OPAQUE, maxWidth, maxHeight, 1, 0, 0);
    up->create(tr("Top Layer").toStdString(), TRANSPARENT, maxWidth, maxHeight, 1, 0, 0);
    up->clear_valued();

    vec_id.clear();
    vec_id.push_back(bottom->id);
    vec_id.push_back(mid->id);
    vec_id.push_back(up->id);

    vec_layer.clear();
    vec_layer.push_back(bottom);
    vec_layer.push_back(mid);
    vec_layer.push_back(up);
}

LayerGroup::~LayerGroup()
{
    for(vector<Layer*>::iterator it = vec_layer.begin(); it != vec_layer.end(); it++)
        delete *it;
}

bool LayerGroup::insert(Layer layer, int id)
{
    LayerPtr pl = new Layer(layer);

    if (id == vec_id[layerNum - 1])
        return 0;
    if (id == -1)
    {
        layerNum++;
        vec_id.push_back(layer.id);
        vec_layer.push_back(pl);
        swap(vec_id[layerNum - 1], vec_id[layerNum - 2]);
        swap(vec_layer[layerNum - 1], vec_layer[layerNum - 2]);
        emit inserted(id);
        return 1;
    }
    else
    {
        int place = -1;
        vector<int>::iterator it_id = vec_id.begin();
        vector<Layer*>::iterator it_layer = vec_layer.begin();
        for (int i = 0; i < layerNum; i++)
        {
            it_id++;
            it_layer++;
            if (vec_id[i] == id)
            {
                place = i;
                break;
            }
        }
        if (place == -1)
            return 0;
        layerNum++;
        vec_id.insert(it_id, id);
        vec_layer.insert(it_layer, pl);
        emit inserted(id);
        return 1;
    }
}

bool LayerGroup::remove(int id)
{
    int p = -1;
    for(int i = 0; i < vec_id.size(); i++)
    {
        if (vec_id[i] == id) { p = i; break; }
    }
    if (p == -1) return 0;
    vector<int>::iterator it_id = vec_id.begin();
    vector<LayerPtr>::iterator it_layer = vec_layer.begin();
    for(int i = 0; i < vec_id.size(); i++, it_id++, it_layer++)
    {
        if (vec_id[i] == id)
        {
            layerNum--;
            vec_id.erase(it_id);
            vec_layer.erase(it_layer);
            break;
        }
    }
    emit removed(id);
    return 1;
}

QImage LayerGroup::get_preview()
{
    rst = Mat(this->maxHeight, this->maxWidth, CV_8UC3, Scalar(255, 255, 255));
    qDebug() << this->maxHeight << ' ' << this->maxWidth << endl;

    for(int i = 0; i < vec_layer.size(); i++)
    {
        if (!vec_layer[i]->visibility) continue;
        LayerPtr l = vec_layer[i];
        int halfRows = l->M.rows / 2;
        int halfCols = l->M.cols / 2;
        for(int x = 0; x < l->M.rows; x++)
        {
            for(int y = 0; y < l->M.cols; y++)
            {
                int xx = l->minRow + halfRows - (y - halfCols) * sin(l->angle) + (x - halfRows) * cos(l->angle);
                int yy = l->minCol + halfCols + (y - halfCols) * cos(l->angle) + (x - halfRows) * sin(l->angle);
                if (xx >= maxHeight || yy >= maxWidth)
                    continue;
                if (xx < 0 || yy < 0)
                    continue;
                bool flag = 0;
                if (l->visionType == OPAQUE || l->valued.at<uchar>(x, y) > 0)
                    flag = 1;
                if (flag)
                {
                    rst.at<Vec3b>(xx, yy) = l->M.at<Vec3b>(x, y);
                    if (fabs(l->angle) > EPS && fabs(l->angle - PI) > EPS)
                    {
                        if (xx > 0) rst.at<Vec3b>(xx-1, yy) = l->M.at<Vec3b>(x, y);
                        if (yy > 0) rst.at<Vec3b>(xx, yy-1) = l->M.at<Vec3b>(x, y);
                    }
                }
            }
        }
    }

//    imshow("test", rst);
    return QImage(rst.data, rst.cols, rst.rows, static_cast<int>(rst.step), QImage::Format_RGB888).rgbSwapped();
}

bool LayerGroup::reorder(vector<int> new_id)
{
    if (vec_id.size() != new_id.size())
        return 0;
    for (int i = 0; i < new_id.size(); i++)
    {
        int p = -1;
        for (int j = 0; j < i; j++)
            if (new_id[j] == new_id[i]) return 0;
        for (int j = 0; j < vec_id.size(); j++)
        {
            if (vec_id[j] == new_id[i])
            {
                p = j; break;
            }
        }
        if (p == -1)
            return 0;
    }
    for (int i = 0; i < vec_id.size(); i++)
    {
        if (vec_id[i] == new_id[i])
            continue;
        int pos = -1;
        for (int j = i + 1; j < vec_id.size(); j++)
        {
            if (vec_id[j] == new_id[i])
            {
                pos = j;
                break;
            }
        }
        swap(vec_id[i], vec_id[pos]);
        swap(vec_layer[i], vec_layer[pos]);
    }
    return 1;
}

vector<int> LayerGroup::get_vec_id()
{
    return vec_id;
}

vector<LayerPtr>& LayerGroup::get_vec_layer()
{
    return vec_layer;
}
