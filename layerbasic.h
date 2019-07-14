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

    // Histogram
    Mat layerCalHist(Layer& layer);
    // 计算直方图
    Mat layerShowHist(Layer& layer);
    // 显示直方图
    void layerEqualizeHist(Layer& layer);
    // 直方图均衡化

    // Filter
    void layerBlur(Layer& layer);
    // 均值滤波
    void layerGaussBlur(Layer& layer);
    // 高斯滤波
    void layerMedianBlur(Layer& layer);
    // 中值滤波
    void layerBilateralFilter(Layer& layer);
    // 双边滤波

    // Tailoring
    void layerTailoring(Layer &layer,Rect rect);
	// 裁剪
    void layerLine(Layer &layer,Point pt1,Point pt2,const Scalar& color,
                   int state=1, int thickness=1,int lineType=8,int shift=0);
    //画线
    void layerCircle(Layer &layer,Point center,int radius, const Scalar& color,
                     int state=1, int thickness=1, int lineType=8, int shift=0);
    //画圆
    void layerRect(Layer &layer, Rect rect, const Scalar& color,
                   int state=1, int thickness=1, int lineType=8, int shift=0);
    //画矩形
	// state = 1,绘图,state = 0,擦除
	// thickness是线条宽度，默认参数是1
	// linetype 是线条种类，默认参数是8
	// shift默认为0

    // 滤镜
    void layerNostalgic(Layer &layer);
    // 怀旧滤镜
    void layerBlackWhite(Layer &layer);
    // 黑白滤镜
    void layerZoomBlur(Layer &layer,int num=40);
    // 径向模糊滤镜
    // num是模糊程度，num越大越模糊
    void layerDiffusion(Layer &layer);
    // 扩散滤镜(毛玻璃效果)
    void layerEclosion(Layer &layer,float mSize = 0.5);
    // mSize∈[0,1]是羽化参数
    // 羽化

};

#endif // LAYERBASIC_H
