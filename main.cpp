#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QElapsedTimer>
#include <QTranslator>
//#include "layergroup.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss(":/main.qss");

    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());

    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
