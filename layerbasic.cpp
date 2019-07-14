#include "layerbasic.h"

LayerBasic::LayerBasic()
{

}

void LayerBasic::layerResize(Layer &layer, double fx, double fy)
{
    Mat src = layer.M;
    Mat dst;
    resize(src,dst,Size(src.cols*fx,src.rows*fy));
    layer.M = dst;
    Mat src1 = layer.valued;
    Mat dst1;
    resize(src1,dst1,Size(src.cols*fx,src.rows*fy));
    layer.valued = dst1;
}

void LayerBasic::layerRotate(Layer& layer,double angle)
{
    layer.angle += PI * angle / 180;
    while(layer.angle > PI * 2)
        layer.angle -= PI * 2;
}

void LayerBasic::layerTranslation(Layer &layer, int x, int y)
{
	layer.minCol += x;
	layer.minRow += y;
}

void LayerBasic::layerFlip(Layer& layer,int flipcode)
{
    Mat src = layer.M;
    Mat dst;
    flip(src,dst,flipcode);
    layer.M = dst;
    Mat src1 = layer.valued;
    Mat dst1;
    flip(src1,dst1,flipcode);
    layer.valued = dst1;
}

Mat LayerBasic::layerCalHist(Layer &layer)
{
    Mat image = layer.M;
    Mat hist;
    int channels[] = {0};
    int dims = 1;
    int histSize[] = {256};
    float granges[] = {0, 255};
    const float *ranges[] = {granges};
    calcHist(&image, 1, channels, Mat(), hist, dims, histSize, ranges);
    return hist;
}

Mat LayerBasic::layerShowHist(Layer &layer)
{
    Mat hist = LayerBasic::layerCalHist(layer);
    Mat showImage(256,256, CV_8U,Scalar(0));
    int i;
    double maxValue = 0;
    minMaxLoc(hist, 0, &maxValue, 0, 0);
    for(i = 0; i < 256; i++)
    {
        float value = hist.at<float>(i);
        int intensity = saturate_cast<int>(256 - 256* (value/maxValue));
        rectangle(showImage, Point(i,256 - 1), Point((i+1)-1, intensity), Scalar(255));
    }
    return showImage;

}

void LayerBasic::layerEqualizeHist(Layer &layer)
{
    Mat src = layer.M;
    Mat dst;
    Mat matArray[3];
    split(src,matArray);
    for(int i=0;i<3;i++)
    {
        equalizeHist(matArray[i],matArray[i]);
    }
    merge(matArray,3,dst);

    layer.M = dst;
}

void LayerBasic::layerBlur(Layer &layer)
{
    Mat src = layer.M;
    Mat dst;
    blur(src,dst,Size(3,3),Point(-1,-1));
    layer.M = dst;
}

void LayerBasic::layerGaussBlur(Layer &layer)
{
    Mat src = layer.M;
    Mat dst;
    GaussianBlur(src,dst,Size(5,5),5,5);
    layer.M = dst;
}

void LayerBasic::layerMedianBlur(Layer &layer)
{
    Mat src = layer.M;
    Mat dst;
    medianBlur(src,dst,5);
    layer.M = dst;
}

void LayerBasic::layerBilateralFilter(Layer &layer)
{
    Mat src = layer.M;
    Mat dst;
    bilateralFilter(src,dst,5,100,3);
    layer.M = dst;
}

void LayerBasic::layerTailoring(Layer &layer,Rect rect)
{
    Mat src= layer.M;
    Mat dst = src(rect);
	layer.minCol = rect.x;
	layer.minRow = rect.y;
	layer.width = rect.width;
	layer.height = rect.height;
    layer.M = dst;
}

void LayerBasic::layerLine(Layer & layer, Point pt1, Point pt2, const Scalar & color,
                           int state, int thickness, int lineType, int shift)
{
	if (state == 1)//draw
	{
		line(layer.M, pt1, pt2, color, thickness, lineType, shift);
		line(layer.valued, pt1, pt2, Scalar(1), thickness, lineType, shift);
	}
	else//erase
	{
        line(layer.M, pt1, pt2, Scalar(255, 255, 255), thickness, lineType, shift);
        line(layer.valued, pt1, pt2, Scalar(0), thickness, lineType, shift);
	}
}

void LayerBasic::layerCircle(Layer & layer, Point center, int radius, const Scalar & color,
                             int state, int thickness, int lineType, int shift)
{
	if (state == 1)
	{
		circle(layer.M, center, radius, color, thickness, lineType, shift);
		circle(layer.valued, center, radius, Scalar(1), thickness, lineType, shift);
	}
	else 
	{
        circle(layer.M, center, radius, Scalar(255, 255, 255), -1, lineType, shift);
        circle(layer.valued, center, radius, Scalar(0), -1, lineType, shift);
	}
}

void LayerBasic::layerRect(Layer & layer, Rect rect, const Scalar & color,
                           int state, int thickness, int lineType, int shift)
{
	if (state == 1)
	{
		rectangle(layer.M, rect, color, thickness, lineType, shift);
		rectangle(layer.valued, rect, Scalar(1), thickness, lineType, shift);
	}
	else
	{
        rectangle(layer.M, rect, Scalar(255, 255, 255), -1, lineType, shift);
        rectangle(layer.valued, rect, Scalar(0), -1, lineType, shift);
	}
}

void LayerBasic::layerNostalgic(Layer &layer)
{
    Mat src = layer.M;
    int width = src.cols;
    int heigh = src.rows;
    Mat img(src.size(), CV_8UC3);
    for (int y = 0; y < heigh; y++)
    {
        uchar* P0 = src.ptr<uchar>(y);
        uchar* P1 = img.ptr<uchar>(y);
        for (int x = 0; x < width; x++)
        {
            float B = P0[3 * x];
            float G = P0[3 * x + 1];
            float R = P0[3 * x + 2];
            float newB = 0.272*R + 0.534*G + 0.131*B;
            float newG = 0.349*R + 0.686*G + 0.168*B;
            float newR = 0.393*R + 0.769*G + 0.189*B;
            if (newB < 0)newB = 0;
            if (newB > 255)newB = 255;
            if (newG < 0)newG = 0;
            if (newG > 255)newG = 255;
            if (newR < 0)newR = 0;
            if (newR > 255)newR = 255;
            P1[3 * x] = (uchar)newB;
            P1[3 * x + 1] = (uchar)newG;
            P1[3 * x + 2] = (uchar)newR;
        }
    }
    layer.M = img;
}

void LayerBasic::layerBlackWhite(Layer &layer)
{
    Mat src = layer.M;
    int width = src.cols;
    int heigh = src.rows;
    Mat img(src.size(), CV_8UC3);
    for (int y = 0; y < heigh; y++)
    {
        uchar* P0 = src.ptr<uchar>(y);
        uchar* P1 = img.ptr<uchar>(y);
        for (int x = 0; x < width; x++)
        {
            float B = P0[3 * x];
            float G = P0[3 * x + 1];
            float R = P0[3 * x + 2];
            float newB = 0.299*R + 0.587*G + 0.114*B;
            float newG = 0.299*R + 0.587*G + 0.114*B;
            float newR = 0.299*R + 0.587*G + 0.114*B;
            if (newB < 0)newB = 0;
            if (newB > 255)newB = 255;
            if (newG < 0)newG = 0;
            if (newG > 255)newG = 255;
            if (newR < 0)newR = 0;
            if (newR > 255)newR = 255;
            P1[3 * x] = (uchar)newB;
            P1[3 * x + 1] = (uchar)newG;
            P1[3 * x + 2] = (uchar)newR;
        }
    }
    layer.M = img;
}

void LayerBasic::layerDiffusion(Layer &layer)
{
    Mat src = layer.M;
    int width = src.cols;
    int heigh = src.rows;
    RNG rng;
    Mat img(src.size(), CV_8UC3);
    for (int y = 1; y < heigh - 1; y++)
    {
        uchar* P0 = src.ptr<uchar>(y);
        uchar* P1 = img.ptr<uchar>(y);
        for (int x = 1; x < width - 1; x++)
        {
            int tmp = rng.uniform(0, 9);
            P1[3 * x] = src.at<uchar>(y - 1 + tmp / 3, 3 * (x - 1 + tmp % 3));
            P1[3 * x + 1] = src.at<uchar>(y - 1 + tmp / 3, 3 * (x - 1 + tmp % 3) + 1);
            P1[3 * x + 2] = src.at<uchar>(y - 1 + tmp / 3, 3 * (x - 1 + tmp % 3) + 2);
        }
    }
    layer.M = img;
}

void LayerBasic::layerZoomBlur(Layer &layer,int num)
{
    Mat src = layer.M;
    Mat src1u[3];
    split(src, src1u);

    int width = src.cols;
    int heigh = src.rows;
    Mat img;
    src.copyTo(img);
    Point center(width / 2, heigh / 2);

    for (int y = 0; y < heigh; y++)
    {

        uchar *imgP = img.ptr<uchar>(y);

        for (int x = 0; x < width; x++)
        {
            int R = norm(Point(x, y) - center);
            double angle = atan2((double)(y - center.y), (double)(x - center.x));

            int tmp0 = 0, tmp1 = 0, tmp2 = 0;

            for (int i = 0; i < num; i++)		//num：均值力度 ，i为变化幅度;
            {
                int tmpR = (R - i) > 0 ? (R - i) : 0;

                int newX = tmpR * cos(angle) + center.x;
                int newY = tmpR * sin(angle) + center.y;

                if (newX < 0)newX = 0;
                if (newX > width - 1)newX = width - 1;
                if (newY < 0)newY = 0;
                if (newY > heigh - 1)newY = heigh - 1;

                tmp0 += src1u[0].at<uchar>(newY, newX);
                tmp1 += src1u[1].at<uchar>(newY, newX);
                tmp2 += src1u[2].at<uchar>(newY, newX);

            }
            imgP[3 * x] = (uchar)(tmp0 / num);
            imgP[3 * x + 1] = (uchar)(tmp1 / num);
            imgP[3 * x + 2] = (uchar)(tmp2 / num);
        }
    }
    layer.M = img;
}

void LayerBasic::layerEclosion(Layer &layer,float mSize)
{
    Mat src = layer.M;
    int width = src.cols;
    int heigh = src.rows;
    int centerX = width >> 1;
    int centerY = heigh >> 1;

    int maxV = centerX * centerX + centerY * centerY;
    int minV = (int)(maxV*(1 - mSize));
    int diff = maxV - minV;
    float ratio = width > heigh ? (float)heigh / (float)width : (float)width / (float)heigh;

    Mat img;
    src.copyTo(img);

    Scalar avg = mean(src);
    Mat dst(img.size(), CV_8UC3);
    Mat mask1u[3];
    float tmp, r;
    for (int y = 0; y < heigh; y++)
    {
        uchar* imgP = img.ptr<uchar>(y);
        uchar* dstP = dst.ptr<uchar>(y);
        for (int x = 0; x < width; x++)
        {
            int b = imgP[3 * x];
            int g = imgP[3 * x + 1];
            int r = imgP[3 * x + 2];

            float dx = centerX - x;
            float dy = centerY - y;

            if (width > heigh)
                dx = (dx*ratio);
            else
                dy = (dy*ratio);

            int dstSq = dx * dx + dy * dy;

            float v = ((float)dstSq / diff) * 255;

            r = (int)(r + v);
            g = (int)(g + v);
            b = (int)(b + v);
            r = (r > 255 ? 255 : (r < 0 ? 0 : r));
            g = (g > 255 ? 255 : (g < 0 ? 0 : g));
            b = (b > 255 ? 255 : (b < 0 ? 0 : b));

            dstP[3 * x] = (uchar)b;
            dstP[3 * x + 1] = (uchar)g;
            dstP[3 * x + 2] = (uchar)r;
        }
    }
}

