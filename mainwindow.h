#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>
#include <QScrollArea>
#include <QTextStream>
#include <QKeyEvent>
#include <QWheelEvent>
#include<qscrollbar.h>
#include<QPoint>
#include<QColor>
#include<QColorDialog>
#include "layergroup.h"
#include "imageqlabel.h"
#include "layerbasic.h"
#include "layertableview.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    enum ACTION_TYPE {//different action modes
        NO_ACTION,//doing nothing
        DRAG_PREVIEW,//drag preview image
        DRAW_LINES,
        DRAW_CIRCLE,
        DRAW_RECT,
        TAILOR,
        ERASE,
        ERASE_RECT,
        ERASE_CIRCLE,
        TRANSLATION,
        PAINTER
    };
    QScrollArea *scroll_area_;
    ACTION_TYPE action_mode_;
    Ui::MainWindow *ui;
    LayerGroup *layer_group_=nullptr;//当前处理的图层组
    Layer *current_layer_=nullptr;//当前处理的图层
    Scalar painter_color_;
    LayerBasic DrawType;
    Rect rect;
    //打开文件
    QDockWidget *dock_center;
    QString current_path_;
    ImageQLabel *imgLabel;
    LayerTableView *layer_table_;
    qreal zoom_level_=1.0;
    void InitImage();
    void InitLayerView();
    void ConnectFile();
    void ConnectAction();
    void ConnectLayer();
    void DisconnectLayer();
    virtual void wheelEvent(QWheelEvent * event);
    virtual void keyPressEvent(QKeyEvent * event);
private slots:
    void NewFile();
    void OpenFile();
    void SaveFile();
    void SaveasFile();
    void RefreshView();
    void Scroll(QPoint delta);
    void SetActionDrag();
    void DragSlot(QPoint startpoint,QPoint endpoint);
    void MoveSlot(QPoint startpoint,QPoint endpoint);
    void ChangeCurrentLayer(int index);
    void SetPainterColor(QColor);
    void Lines();
    void Circles();
    void Rect();
    void Tailor();
    void Erase();
    void Blur();
    void Hist();
    void Rotate90();
    void AntiRotate90();
    void Rotate();
    void Resize();
    void CallColorDialog();
    void Translation();
    void RemoveLayer(int);
    void ResortLayer(int,int);
    void CreateLayer();
    void TrunH();
    void TrunV();
    void Filter();
    void UsePainter();
};

#endif // MAINWINDOW_H
