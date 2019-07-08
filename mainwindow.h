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
    QScrollArea *scroll_area_;
    Ui::MainWindow *ui;

    QDockWidget *dock_center;
    QString current_path_;

};

#endif // MAINWINDOW_H
