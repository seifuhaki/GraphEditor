#-------------------------------------------------
#
# Project created by QtCreator 2019-07-08T10:44:17
#
#-------------------------------------------------
RC_ICONS = GraphEditor.ico
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphEditor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        imageqlabel.cpp \
        layer.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        imageqlabel.h \
        layer.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon/icon.qrc \
    qss/qss.qrc

win32 {
    INCLUDEPATH += D:\opencv\opencv\build\include
    INCLUDEPATH += D:\opencv\opencv\build\include\opencv
    INCLUDEPATH += D:\opencv\opencv\build\include\opencv2
    CONFIG(debug,debug|release){
        LIBS+= -LD:\opencv\opencv\build\x64\vc15\lib \
        -lopencv_world346d
    }
    else {
        LIBS+= -LD:\opencv\opencv\build\x64\vc15\lib \
        -lopencv_world346    }
}
unix {
    INCLUDEPATH += /usr/local/include
    INCLUDEPATH += /usr/local/include/opencv
    INCLUDEPATH += /usr/local/include/opencv2
    LIBS += -L/usr/local/lib \
     -lopencv_core \
     -lopencv_highgui \
     -lopencv_imgproc \

    QT_CONFIG -= no-pkg-config
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}
