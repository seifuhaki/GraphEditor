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
    //InitImage();        // 初始化图像QLabel
    //InitLayerView();
    ConnectAction();    // Initialize the action connection
    //ConnectLayer();

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
    //connect(imgLabel,SIGNAL(dragged(QPoint,QPoint)),this,SLOT(DragSlot(QPoint,QPoint)));
    //connect(imgLabel,SIGNAL(moved(QPoint,QPoint)),this,SLOT(MoveSlot(QPoint,QPoint)));
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
