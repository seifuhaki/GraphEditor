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
