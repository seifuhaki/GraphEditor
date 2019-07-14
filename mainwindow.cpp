#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget* p = takeCentralWidget();
    if(p)
        delete p;
    setDockNestingEnabled(true);
    setCentralWidget(ui->dock_center);
    addDockWidget(Qt::LeftDockWidgetArea, ui->dock_paint);
    addDockWidget(Qt::RightDockWidgetArea, ui->dock_geometry);
    addDockWidget(Qt::RightDockWidgetArea, ui->dock_special);
    addDockWidget(Qt::RightDockWidgetArea, ui->dock_layer);
    splitDockWidget(ui->dock_paint, ui->dock_center, Qt::Horizontal);     // 水平
    splitDockWidget(ui->dock_geometry, ui->dock_layer, Qt::Vertical);      // 垂直

    // 合并窗口
    tabifyDockWidget(ui->dock_geometry, ui->dock_special);

    ui->dock_geometry->raise();             //指定窗口置于最前

    ConnectFile();
    InitImage();        // 初始化图像QLabel
    InitLayerView();
    ConnectAction();    // Initialize the action connection
    ConnectLayer();

    //皮肤！
    QFile styleSheet("./qss/main.qss");
    if (!styleSheet.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    ui->dock_geometry->setStyleSheet(styleSheet.readAll());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ConnectFile()
{
    connect(ui->action_new, SIGNAL(triggered()), this, SLOT(NewFile()));
    connect(ui->action_open, SIGNAL(triggered()), this, SLOT(OpenFile()));
    connect(ui->action_save, SIGNAL(triggered()), this, SLOT(SaveFile()));
    connect(ui->action_exit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->action_saveas, SIGNAL(triggered()), this, SLOT(SaveasFile()));
}
void MainWindow::ConnectAction(){
    connect(ui->pushButton_choose,SIGNAL(clicked()),this,SLOT(SetActionDrag()));
    connect(imgLabel,SIGNAL(dragged(QPoint,QPoint)),this,SLOT(DragSlot(QPoint,QPoint)));
    connect(imgLabel,SIGNAL(moved(QPoint,QPoint)),this,SLOT(MoveSlot(QPoint,QPoint)));
    connect(ui->pushButton_line,SIGNAL(clicked()),this,SLOT(Lines()));
    connect(ui->pushButton_ciecle,SIGNAL(clicked()),this,SLOT(Circles()));
    connect(ui->pushButton_rectangle,SIGNAL(clicked()),this,SLOT(Rect()));
    connect(ui->pushButton_cut,SIGNAL(clicked()),this,SLOT(Tailor()));
    connect(ui->pushButton_eraser,SIGNAL(clicked()),this,SLOT(Erase()));
    connect(ui->confirm_filter_2,SIGNAL(clicked()),this,SLOT(Blur()));
    connect(ui->pushButton_histogram,SIGNAL(clicked()),this,SLOT(Hist()));
    connect(ui->clockwise_90,SIGNAL(clicked()),this,SLOT(Rotate90()));
    connect(ui->anticlockwise_90,SIGNAL(clicked()),this,SLOT(AntiRotate90()));
    connect(ui->confirm_rotate,SIGNAL(clicked()),this,SLOT(Rotate()));
    connect(ui->confrim_size,SIGNAL(clicked()),this,SLOT(Resize()));
    connect(ui->pushButton_color,SIGNAL(clicked()),this,SLOT(CallColorDialog()));
    connect(ui->pushButton_translation,SIGNAL(clicked()),this,SLOT(Translation()));
    connect(ui->pushButton_turn_h,SIGNAL(clicked()),this,SLOT(TrunH()));
    connect(ui->pushButton_turn_v,SIGNAL(clicked()),this,SLOT(TrunV()));
    connect(ui->confirm_filter,SIGNAL(clicked()),this,SLOT(Filter()));
    connect(ui->pushButton_pen,SIGNAL(clicked()),this,SLOT(UsePainter()));
}
void MainWindow::ConnectLayer(){
    connect(layer_group_,SIGNAL(inserted(int)),layer_table_,SLOT(addNewLayer(int)),Qt::UniqueConnection);
    connect(layer_table_,SIGNAL(tableDataChanged()),this,SLOT(RefreshView()),Qt::UniqueConnection);
    connect(layer_table_,SIGNAL(currentLayerChanged(int)),this,SLOT(ChangeCurrentLayer(int)),Qt::UniqueConnection);
    connect(layer_table_,SIGNAL(tableDeleteLayer(int)),this,SLOT(RemoveLayer(int)),Qt::UniqueConnection);
    connect(layer_table_,SIGNAL(tableLayerResorted(int,int)),this,SLOT(ResortLayer(int,int)),Qt::UniqueConnection);
    connect(layer_table_,SIGNAL(tableLayerCreated()),this,SLOT(CreateLayer()),Qt::UniqueConnection);
}
void MainWindow::DisconnectLayer(){
    disconnect(layer_group_);
    disconnect(layer_table_);
}
void MainWindow::SetActionDrag(){
    if (action_mode_!=DRAG_PREVIEW) action_mode_ = DRAG_PREVIEW;
    else action_mode_ = NO_ACTION;
}
//初始化
void MainWindow::InitImage()
{
    imgLabel = new ImageQLabel(ui->dock_center);
    imgLabel->setScaledContents(true);  // 设置QLabel自动适应图像大小
    //滚动条
    scroll_area_ = new QScrollArea(this);
    scroll_area_->setBackgroundRole(QPalette::Dark);
    scroll_area_->setAlignment(Qt::AlignCenter);
    scroll_area_->setWidget(imgLabel);
    scroll_area_->setMouseTracking(false);
    ui->dock_center->setWidget(scroll_area_);
}

void MainWindow::InitLayerView(){
    layer_group_ = new LayerGroup();
    layer_table_ = new LayerTableView(&layer_group_->get_vec_layer());
    ui->dock_layer->setWidget(layer_table_);
}
//新建
void MainWindow::NewFile()
{
    DisconnectLayer();
    if (layer_group_!=nullptr) delete layer_group_;
    layer_group_ = new LayerGroup;
    layer_table_->setModel(new LayerTableModel(&layer_group_->get_vec_layer()));
    layer_table_->resizeRowsToContents();
    InitLayerView();
    ConnectLayer();
    current_layer_ = layer_group_->get_vec_layer()[1];
    MainWindow::RefreshView();

}
//打开
void MainWindow::OpenFile()
{
    QString path = QFileDialog::getOpenFileName(this, "选择图像", ".", "Images(*.jpg *.png *.bmp)");                            // 文件选择框
    if (!path.isEmpty())
    {
        qDebug()<<path<<endl;
        Layer layer(path.toStdString(),tr("Untitled Layer").toStdString(),OPAQUE,true,0,0);
        layer_group_->insert(layer);
        if (layer_group_->get_vec_id().size()==3) {
            layer_group_->set_maxWidth(max(layer_group_->get_maxWidth(),layer.get_width()));
            layer_group_->set_maxHeight(max(layer_group_->get_maxHeight(),layer.get_height()));
        }
        current_layer_ = layer_group_->get_vec_layer()[1];
    }
    MainWindow::RefreshView();
}
//保存
void MainWindow::SaveFile()
{
    //判断新建or打开
    if (current_path_.isEmpty())
    {
        QString path = QFileDialog::getSaveFileName(this, "Save", ".", "Images(*.jpg *.png *.bmp)");
        if (!path.isEmpty())
            current_path_ = path;
    }
    //读取
    QImage img = layer_group_->get_preview();
    img.save(current_path_);
}
//另存为
void MainWindow::SaveasFile()
{

    QString path = QFileDialog::getSaveFileName(this,"SaveAs", ".", "Images(*.jpg *.png *.bmp)");
    if (!path.isEmpty())
    {
        QImage img = layer_group_->get_preview();
        img.save(path);
        current_path_ = path;
    }
}
void MainWindow::RefreshView()
{
    if (layer_group_==nullptr) imgLabel->clear();
    else {
        QImage preview = layer_group_->get_preview();
        imgLabel->SetPreview(QPixmap::fromImage(preview));
        imgLabel->RefreshView();
    }
}
void MainWindow::ChangeCurrentLayer(int index){
    vector<Layer *> *layerlist =&layer_group_->get_vec_layer();
    if (!layerlist||index>=layerlist->size()) return;
    current_layer_ = layerlist->at(index);
}
void MainWindow::RemoveLayer(int index){
    layer_group_->remove(layer_group_->get_vec_id().at(index));
    RefreshView();
}
void MainWindow::ResortLayer(int index1,int index2){
    vector<int> vec_id=layer_group_->get_vec_id();
    swap(vec_id[index1],vec_id[index2]);
    layer_group_->reorder(vec_id);
    layer_table_->RefreshTable();
    RefreshView();
}
void MainWindow::CreateLayer() {
    Layer new_layer;
    new_layer.create(tr("Untitled Layer").toStdString(),OPAQUE,layer_group_->get_maxWidth(),layer_group_->get_maxHeight());
    new_layer.clear_valued();
    layer_group_->insert(new_layer);
    layer_table_->RefreshTable();
    RefreshView();
}
void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (QApplication::keyboardModifiers()==Qt::ControlModifier){
        qreal delta_level = event->angleDelta().y();
        delta_level/=8*360;
        imgLabel->SetZoomLevel(delta_level);
    }
}
void MainWindow::DragSlot(QPoint startpoint,QPoint endpoint)
{
    QPoint delta = endpoint - startpoint;
    Point s,e;

    s.x=startpoint.x();
    s.y=startpoint.y();
    e.x=endpoint.x();
    e.y=endpoint.y();
    double zoom_level = imgLabel->GetZoomLevel();
    s/=zoom_level;
    e/=zoom_level;
    s.x-=current_layer_->get_minCol();
    e.x-=current_layer_->get_minCol();
    s.y-=current_layer_->get_minRow();
    e.y-=current_layer_->get_minRow();
    if(s.x>e.x)
    {
        rect.x=e.x;
    }
    else
    {
        rect.x=s.x;
    }
    if(s.y<e.y)
    {
        rect.y=s.y;
    }
    else
    {
        rect.y=e.y;
    }
    rect.height=abs(s.y-e.y);
    rect.width=abs(e.x-s.x);

    switch (action_mode_)
    {
    case DRAG_PREVIEW:
        Scroll(delta);
        break;
    case DRAW_LINES:
        if(ui->comboBox_mode->currentIndex()==0)
        {
            DrawType.layerLine(*current_layer_,s,e,painter_color_,1,ui->combox_pensize->currentIndex()+1);
        }
        else if(ui->comboBox_mode->currentIndex()==1)
        {
            DrawType.layerLine(*current_layer_,s,e,Scalar(255),0,ui->combox_pensize->currentIndex()+1);
        }
        RefreshView();
        break;
    case DRAW_CIRCLE:
        if(ui->comboBox_mode->currentIndex()==0)
        {
            if(ui->comboBox_solid->currentIndex()==0)
            {
                DrawType.layerCircle(*current_layer_,s,(int)sqrt((s.x-e.x)*(s.x-e.x)+(s.y-e.y)*(s.y-e.y)),painter_color_,1,ui->combox_pensize->currentIndex()+1);
            }
            else if(ui->comboBox_solid->currentIndex()==1)
            {
                DrawType.layerCircle(*current_layer_,s,(int)sqrt((s.x-e.x)*(s.x-e.x)+(s.y-e.y)*(s.y-e.y)),painter_color_,1,-1);
            }

        }
        else if(ui->comboBox_mode->currentIndex()==1)
        {
            DrawType.layerCircle(*current_layer_,s,(int)sqrt((s.x-e.x)*(s.x-e.x)+(s.y-e.y)*(s.y-e.y)), Scalar(255),0);
        }
        RefreshView();
        break;
    case DRAW_RECT:
        if(ui->comboBox_mode->currentIndex()==0)
        {
            if(ui->comboBox_solid->currentIndex()==0)
            {
                DrawType.layerRect(*current_layer_, rect, painter_color_, 1, ui->combox_pensize->currentIndex()+1);
            }
            else if(ui->comboBox_solid->currentIndex()==1)
            {
                DrawType.layerRect(*current_layer_,rect,painter_color_, 1,-1);
            }
        }
        else if(ui->comboBox_mode->currentIndex()==1)
        {
            DrawType.layerRect(*current_layer_,rect,Scalar(255),0);
        }

        RefreshView();
        break;
    case TAILOR:
        DrawType.layerTailoring(*current_layer_, rect);
        RefreshView();
        break;
    case ERASE_RECT:
        DrawType.layerRect(*current_layer_,rect,Scalar(255),0);
        RefreshView();
        break;
    case ERASE_CIRCLE:
        DrawType.layerCircle(*current_layer_,s,(int)sqrt((s.x-e.x)*(s.x-e.x)+(s.y-e.y)*(s.y-e.y)), Scalar(255),0);
        RefreshView();
        break;
    case TRANSLATION:
        DrawType.layerTranslation(*current_layer_,e.x-s.x,e.y-s.y);
        RefreshView();
        break;
    default:
        RefreshView();
        break;
    }
}
void MainWindow::MoveSlot(QPoint startpoint,QPoint endpoint){
    QPoint delta = endpoint - startpoint;
    int pen_size = ui->combox_pensize->currentIndex()+1;
    Point s,e;
    s.x=startpoint.x();
    s.y=startpoint.y();
    e.x=endpoint.x();
    e.y=endpoint.y();
    double zoom_level = imgLabel->GetZoomLevel();
    s/=zoom_level;
    e/=zoom_level;
    s.x-=current_layer_->get_minCol();
    e.x-=current_layer_->get_minCol();
    s.y-=current_layer_->get_minRow();
    e.y-=current_layer_->get_minRow();
    switch (action_mode_) {
    case PAINTER:
        DrawType.layerLine(*current_layer_,s,e,painter_color_,1,pen_size);
        break;
    case ERASE:
        DrawType.layerLine(*current_layer_,s,e,Scalar(255),0,pen_size);
        break;
    default:
        break;
    }
}
void MainWindow::Scroll(QPoint delta)
{
    QScrollBar* h_bar = scroll_area_->horizontalScrollBar();
    QScrollBar* v_bar = scroll_area_->verticalScrollBar();
    qDebug()<<"h_bar: "<<h_bar->value()<<",v_bar: "<<v_bar->value()<<"delta: "<<delta<<endl;
    h_bar->setValue(h_bar->value()-delta.x());
    v_bar->setValue(v_bar->value()-delta.y());
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if (event->key()==Qt::Key_0&&QApplication::keyboardModifiers()==Qt::ControlModifier){
        imgLabel->ResetZoom();
    }
}

void MainWindow::Translation()
{
    if(action_mode_!=TRANSLATION) action_mode_ = TRANSLATION;
    else action_mode_ = NO_ACTION;
}

//直线
void MainWindow::Lines()
{
    if (action_mode_!=DRAW_LINES) action_mode_ = DRAW_LINES;
    else action_mode_ = NO_ACTION;
}

//圆
void MainWindow::Circles()
{
    if(action_mode_==ERASE)
    {
        action_mode_ = ERASE_CIRCLE;
    }
    else if (action_mode_!=DRAW_CIRCLE) action_mode_ = DRAW_CIRCLE;
    else action_mode_ = NO_ACTION;
}

//方形
void MainWindow::Rect()
{   if(action_mode_==ERASE)
    {
        action_mode_ = ERASE_RECT;
    }
    else if (action_mode_!=DRAW_RECT) action_mode_ = DRAW_RECT;
    else action_mode_ = NO_ACTION;
}

//裁剪
void MainWindow::Tailor()
{
    if (action_mode_!=TAILOR) action_mode_ = TAILOR;
    else action_mode_ = NO_ACTION;
}

//橡皮
void MainWindow::Erase()
{
    if (action_mode_!=ERASE) action_mode_ = ERASE;
    else action_mode_ = NO_ACTION;
}

//橡皮
void MainWindow::UsePainter()
{
    if (action_mode_!=PAINTER) action_mode_ = PAINTER;
    else action_mode_ = NO_ACTION;
}

//滤波
void MainWindow::Blur()
{   if(ui->comboBox__filter_2->currentIndex()==0)
    {
        DrawType.layerBlur(*current_layer_);
    }
    else if(ui->comboBox__filter_2->currentIndex()==1)
    {
        DrawType.layerGaussBlur(*current_layer_);
    }
    else if(ui->comboBox__filter_2->currentIndex()==2)
    {
        DrawType.layerMedianBlur(*current_layer_);
    }
    else if(ui->comboBox__filter_2->currentIndex()==3)
    {
        DrawType.layerMedianBlur(*current_layer_);
    }
    RefreshView();
}

//直方图
void MainWindow::Hist()
{
    cv::namedWindow("Histogram");
    cv::imshow("Histogram",DrawType.layerShowHist(*current_layer_));
}

//旋转
void MainWindow::Rotate90()
{
    DrawType.layerRotate(*current_layer_,-90);
    RefreshView();
}

void MainWindow::AntiRotate90()
{
    DrawType.layerRotate(*current_layer_,90);
    RefreshView();
}

void MainWindow::Rotate()
{
    QString str = ui->lineEdit_degree->text();
    double num = str.toDouble();
    if(ui->comboBox_direction->currentIndex()==1)
    {
        DrawType.layerRotate(*current_layer_,num);
    }
    else if(ui->comboBox_direction->currentIndex()==0)
    {
        DrawType.layerRotate(*current_layer_,-num);
    }
    RefreshView();
}

//缩放
void MainWindow::Resize()
{
    DrawType.layerResize(*current_layer_,ui->doubleSpinBox_length->value(),ui->doubleSpinBox_width->value());
    RefreshView();
}

void MainWindow::CallColorDialog(){
    QColorDialog *dlg = new QColorDialog(QColor(painter_color_[2],painter_color_[1],painter_color_[0]));
    connect(dlg,SIGNAL(colorSelected(QColor)),this,SLOT(SetPainterColor(QColor)));
    dlg->exec();
}

void MainWindow::SetPainterColor(QColor new_color) {
    painter_color_ = Scalar(new_color.blue(),new_color.green(),new_color.red());
}

//水平翻转
void MainWindow::TrunH()
{
    DrawType.layerFlip(*current_layer_,1);
    RefreshView();
}

//竖直翻转
void MainWindow::TrunV()
{
    DrawType.layerFlip(*current_layer_,0);
    RefreshView();
}

void MainWindow::Filter()
{
    if(ui->comboBox__filter->currentIndex()==5)
    {
        DrawType.layerBlackWhite(*current_layer_);
    }
    else if(ui->comboBox__filter->currentIndex()==4)
    {
        DrawType.layerNostalgic(*current_layer_);
    }
    else if(ui->comboBox__filter->currentIndex()==3)
    {
        ui->horizontalSlider_filter->setMinimum(0);
        ui->horizontalSlider_filter->setMaximum(100);
        ui->horizontalSlider_filter->setSingleStep(10);
        DrawType.layerEclosion(*current_layer_,(float)ui->horizontalSlider_filter->value()/100);
    }
    else if(ui->comboBox__filter->currentIndex()==2)
    {
        DrawType.layerDiffusion(*current_layer_);
    }
    else if(ui->comboBox__filter->currentIndex()==1)
    {
        ui->horizontalSlider_filter->setMinimum(0);
        ui->horizontalSlider_filter->setMaximum(100);
        ui->horizontalSlider_filter->setSingleStep(10);
        DrawType.layerZoomBlur(*current_layer_,ui->horizontalSlider_filter->value());
    }
    RefreshView();
}
