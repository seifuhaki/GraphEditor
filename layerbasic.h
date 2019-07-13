#ifndef LAYERBASIC_H
#define LAYERBASIC_H

#include "layer.h"
#include <QObject>

// It is a friend class of Layer
// you can modify a layer directly

class LayerBasic
{
public:
    LayerBasic();

    // write operations as
    // *** func(Layer& layer, ....);

    // Geometric transformation function
    void layerResize(Layer& layer,double fx,double fy);
    // 放缩
    // fx,fy分别是x轴和y轴放缩的倍数
    void layerRotate(Layer& layer,double angle);
    // 旋转
    // angle 是旋转的角度
    void layerTranslation(Layer& layer,int x,int y);
    // 平移
    // x,y是在x轴y轴平移的距离，向右向上为正
    void layerFlip(Layer& layer,int flipcode);
    // 翻转
    // flipcode=0竖直翻转，flipcode=1水平翻转

};

#endif // LAYERBASIC_H
