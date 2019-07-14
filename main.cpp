#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QElapsedTimer>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator; //新建翻译类
    translator.load(":/resources/PhotoStall_zh_CN"); //导入生成的文件
    a.installTranslator(&translator); //装入
    //皮肤！
    QFile qss(":/main.qss");

    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());

    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
