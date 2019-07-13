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
