图像编辑器--------分报告
====
一.	分工任务与解决方案
---------
### 1.图层类（Layer.h/cpp）Common Layer
图层类由以下成员组成：<br>
``` 
1. private: 
2.    string name; 
3.    int id; 
4.    Transparency visionType;
5.    bool visibility;
6.    int width, height;
7.    int minRow, minCol;
8.    double angle;
9. Mat M, valued, thumbNail;
10. public:
11.   static int layerCount;
12.   friend class LayerGroup;
13.   friend class LayerBasic;
```
* name为图层名；<br>
* id为图层编号；<br>
* visionType为一名为Transparency的enum，内含两种值TRANSPARENT和OPAQUE，前者表示图层只有valued为1的像素会被渲染；后者表示图层所有像素都会被渲染；<br>
* visibility表示该图层是否会被渲染；<br>
* width、height表示该图层的宽和高，与Mat同步；<br>
* minRow，minCol表示该图层在画布上左下角点的坐标；<br>
* angle表示该图层被旋转的角度；<br>
* M表示该图层的像素矩阵；<br>
* valued表示该图层的为一个像素点是否要被渲染，对于OPAQUE类型的图层来说这个成员的值没有意义；<br>
* thumbNail表示该图层的缩略图，用于在图层列表中显示；<br>
* 静态变量layerCount表示通过非拷贝构造函数创建的图层数，用于给图层提供一一对应的编号；<br>
* LayerGroup是图层组合类；<br>
* LayerBasic是图层操作类。<br>

Layer类提供了以下构造函数，create函数和析构函数。
```
1. Layer();
2. ~Layer();
3. Layer(Layer& l);
4. Layer(string FILE_PATH, string name, Transparency visionType, bool visibility = 1, int minRow = 0, int minCol = 0);
5. Layer(string name, Transparency visionType, int width, int height, bool visibility, int minRow, int minCol, Mat M);
6. Layer& operator= (Layer& l);
7. void create(string FILE_PATH, string name, Transparency visionType, bool visibility = 1, int minRow = 0, int minCol = 0);
8. void create(Mat M, string name, Transparency visionType, bool visibility = 1, int minRow = 0, int minCol = 0);
9. void create(string name, Transparency visionType = OPAQUE, int width = 0, int height = 0, bool visibility = 1, int minRow = 0, int minCol = 0);
```
其中拷贝构造函数和重载运算符“=”采用深拷贝，函数实体如下：
```
1. Layer::Layer(Layer& l)
2. {
3.  this->name = l.name;
4.  this->visionType = l.visionType;
5.  this->visibility = l.visibility;
6.  this->minCol = l.minCol;
7.  this->minRow = l.minRow;
8.  this->width = l.width;
9.  this->height = l.height;
10. this->id = l.id;
11. this->angle = l.angle;
12. this->M = l.M.clone();
13. this->valued = l.valued.clone();
14. }
15.
16. Layer& Layer::operator= (Layer& l)
17. {
18. this->name = l.name;
19. this->visionType = l.visionType;
20. this->visibility = l.visibility;
21. this->minCol = l.minCol;
22. this->minRow = l.minRow;
23. this->width = l.width;
24. this->height = l.height;
25. this->id = l.id;
26. this->M = l.M.clone();
27. this->valued = l.valued.clone();
28. this->angle = l.angle;
29.
30. return *this;
31. }
```
给成员变量提供了存取接口.<br>

同时提供了两个与前端交互的接口，将后端图像处理用的opencv的Mat类与Qt用于显示的图像QImage进行沟通，一个用于显示大图，一个用于显示缩略图：
```
1. QImage toQImage_ref(QImage::Format format) {
2.
3.    return QImage(M.data, M.cols, M.rows, static_cast<int>(M.step), format);
4.  }
5.
6. QImage Layer::getThumbNail(int width, int height)
7.  {
8.    resize(M, thumbNail, Size(width, height), 0, 0, INTER_NEAREST);
9.    return QImage(thumbNail.data, thumbNail.cols, thumbNail.rows, static_cast<int>(thumbNail.step), QImage::Format_RGB888).rgbSwapped();
10. }
```
### 2.

