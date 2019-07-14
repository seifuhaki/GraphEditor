/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_open;
    QAction *action_new;
    QAction *action_save;
    QAction *action_saveas;
    QAction *action_exit;
    QAction *action_geometry;
    QAction *action_special;
    QAction *action_paint;
    QAction *action__layer;
    QWidget *centralWidget;
    QDoubleSpinBox *doubleSpinBox_2;
    QMenuBar *menuBar;
    QMenu *menu21;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dock_layer;
    QWidget *dockWidgetContents_9;
    QDockWidget *dock_paint;
    QWidget *dockWidgetContents_2;
    QPushButton *pushButton_choose;
    QPushButton *pushButton_line;
    QPushButton *pushButton_ciecle;
    QPushButton *pushButton_rectangle;
    QPushButton *pushButton_cut;
    QPushButton *pushButton_eraser;
    QPushButton *pushButton_color;
    QPushButton *pushButton_translation;
    QComboBox *combox_pensize;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_mode;
    QLabel *label_4;
    QComboBox *comboBox_solid;
    QPushButton *pushButton_pen;
    QDockWidget *dock_geometry;
    QWidget *dockWidgetContents_8;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QComboBox *comboBox_direction;
    QLabel *label_31;
    QPushButton *pushButton_turn_h;
    QPushButton *pushButton_turn_v;
    QLabel *label_32;
    QLineEdit *lineEdit_degree;
    QLabel *label_33;
    QPushButton *confrim_size;
    QPushButton *confirm_rotate;
    QPushButton *clockwise_90;
    QPushButton *anticlockwise_90;
    QDoubleSpinBox *doubleSpinBox_length;
    QDoubleSpinBox *doubleSpinBox_width;
    QDockWidget *dock_center;
    QWidget *dockWidgetContents;
    QDockWidget *dock_special;
    QWidget *dockWidgetContents_3;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_histogram;
    QLabel *label_13;
    QLabel *label_14;
    QSlider *horizontalSlider_filter;
    QComboBox *comboBox__filter;
    QLabel *label_16;
    QComboBox *comboBox__filter_2;
    QPushButton *confirm_filter_2;
    QPushButton *confirm_filter;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(10000, 10000);
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon);
        action_new = new QAction(MainWindow);
        action_new->setObjectName(QString::fromUtf8("action_new"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_new->setIcon(icon1);
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon2);
        action_saveas = new QAction(MainWindow);
        action_saveas->setObjectName(QString::fromUtf8("action_saveas"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/saveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_saveas->setIcon(icon3);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon4);
        action_geometry = new QAction(MainWindow);
        action_geometry->setObjectName(QString::fromUtf8("action_geometry"));
        action_special = new QAction(MainWindow);
        action_special->setObjectName(QString::fromUtf8("action_special"));
        action_paint = new QAction(MainWindow);
        action_paint->setObjectName(QString::fromUtf8("action_paint"));
        action__layer = new QAction(MainWindow);
        action__layer->setObjectName(QString::fromUtf8("action__layer"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        doubleSpinBox_2 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(0, 0, 101, 21));
        doubleSpinBox_2->setMinimum(0.100000000000000);
        doubleSpinBox_2->setMaximum(10.000000000000000);
        doubleSpinBox_2->setSingleStep(0.100000000000000);
        doubleSpinBox_2->setValue(1.000000000000000);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 10000, 21));
        menu21 = new QMenu(menuBar);
        menu21->setObjectName(QString::fromUtf8("menu21"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dock_layer = new QDockWidget(MainWindow);
        dock_layer->setObjectName(QString::fromUtf8("dock_layer"));
        dock_layer->setMinimumSize(QSize(400, 300));
        dock_layer->setMaximumSize(QSize(400, 300));
        dock_layer->setStyleSheet(QString::fromUtf8(""));
        dockWidgetContents_9 = new QWidget();
        dockWidgetContents_9->setObjectName(QString::fromUtf8("dockWidgetContents_9"));
        dock_layer->setWidget(dockWidgetContents_9);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dock_layer);
        dock_paint = new QDockWidget(MainWindow);
        dock_paint->setObjectName(QString::fromUtf8("dock_paint"));
        dock_paint->setMinimumSize(QSize(98, 850));
        dock_paint->setMaximumSize(QSize(100, 900));
        dock_paint->setAutoFillBackground(false);
        dock_paint->setStyleSheet(QString::fromUtf8(""));
        dock_paint->setFloating(false);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        pushButton_choose = new QPushButton(dockWidgetContents_2);
        pushButton_choose->setObjectName(QString::fromUtf8("pushButton_choose"));
        pushButton_choose->setGeometry(QRect(20, 10, 51, 41));
        pushButton_choose->setStyleSheet(QString::fromUtf8("image: url(:/move.png);"));
        pushButton_line = new QPushButton(dockWidgetContents_2);
        pushButton_line->setObjectName(QString::fromUtf8("pushButton_line"));
        pushButton_line->setGeometry(QRect(20, 190, 51, 41));
        pushButton_line->setStyleSheet(QString::fromUtf8("image: url(:/line.png);"));
        pushButton_ciecle = new QPushButton(dockWidgetContents_2);
        pushButton_ciecle->setObjectName(QString::fromUtf8("pushButton_ciecle"));
        pushButton_ciecle->setGeometry(QRect(20, 250, 51, 41));
        pushButton_ciecle->setStyleSheet(QString::fromUtf8("image: url(:/ellipse.png);"));
        pushButton_rectangle = new QPushButton(dockWidgetContents_2);
        pushButton_rectangle->setObjectName(QString::fromUtf8("pushButton_rectangle"));
        pushButton_rectangle->setGeometry(QRect(20, 310, 51, 41));
        pushButton_rectangle->setStyleSheet(QString::fromUtf8("image: url(:/rectangle.png);"));
        pushButton_cut = new QPushButton(dockWidgetContents_2);
        pushButton_cut->setObjectName(QString::fromUtf8("pushButton_cut"));
        pushButton_cut->setGeometry(QRect(20, 370, 51, 41));
        pushButton_cut->setStyleSheet(QString::fromUtf8("image: url(:/cut.png)"));
        pushButton_eraser = new QPushButton(dockWidgetContents_2);
        pushButton_eraser->setObjectName(QString::fromUtf8("pushButton_eraser"));
        pushButton_eraser->setGeometry(QRect(20, 430, 51, 41));
        pushButton_eraser->setStyleSheet(QString::fromUtf8("image: url(:/eraser.png);"));
        pushButton_color = new QPushButton(dockWidgetContents_2);
        pushButton_color->setObjectName(QString::fromUtf8("pushButton_color"));
        pushButton_color->setGeometry(QRect(20, 490, 51, 41));
        pushButton_color->setStyleSheet(QString::fromUtf8("image:url(:/color.png)"));
        pushButton_translation = new QPushButton(dockWidgetContents_2);
        pushButton_translation->setObjectName(QString::fromUtf8("pushButton_translation"));
        pushButton_translation->setGeometry(QRect(20, 70, 51, 41));
        pushButton_translation->setStyleSheet(QString::fromUtf8("image: url(:/translation.png);"));
        combox_pensize = new QComboBox(dockWidgetContents_2);
        combox_pensize->addItem(QString());
        combox_pensize->addItem(QString());
        combox_pensize->addItem(QString());
        combox_pensize->addItem(QString());
        combox_pensize->addItem(QString());
        combox_pensize->addItem(QString());
        combox_pensize->addItem(QString());
        combox_pensize->addItem(QString());
        combox_pensize->addItem(QString());
        combox_pensize->addItem(QString());
        combox_pensize->setObjectName(QString::fromUtf8("combox_pensize"));
        combox_pensize->setGeometry(QRect(20, 580, 41, 31));
        label = new QLabel(dockWidgetContents_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 550, 61, 31));
        label_2 = new QLabel(dockWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 580, 41, 31));
        label_3 = new QLabel(dockWidgetContents_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 630, 61, 31));
        comboBox_mode = new QComboBox(dockWidgetContents_2);
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->addItem(QString());
        comboBox_mode->setObjectName(QString::fromUtf8("comboBox_mode"));
        comboBox_mode->setGeometry(QRect(10, 660, 81, 41));
        label_4 = new QLabel(dockWidgetContents_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 720, 61, 31));
        comboBox_solid = new QComboBox(dockWidgetContents_2);
        comboBox_solid->addItem(QString());
        comboBox_solid->addItem(QString());
        comboBox_solid->setObjectName(QString::fromUtf8("comboBox_solid"));
        comboBox_solid->setGeometry(QRect(10, 750, 81, 41));
        pushButton_pen = new QPushButton(dockWidgetContents_2);
        pushButton_pen->setObjectName(QString::fromUtf8("pushButton_pen"));
        pushButton_pen->setGeometry(QRect(20, 130, 51, 41));
        pushButton_pen->setStyleSheet(QString::fromUtf8("image: url(:/pen.png);"));
        dock_paint->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dock_paint);
        dock_geometry = new QDockWidget(MainWindow);
        dock_geometry->setObjectName(QString::fromUtf8("dock_geometry"));
        dock_geometry->setMinimumSize(QSize(400, 400));
        dock_geometry->setMaximumSize(QSize(400, 900));
        dock_geometry->setAutoFillBackground(false);
        dock_geometry->setStyleSheet(QString::fromUtf8(""));
        dock_geometry->setFloating(false);
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName(QString::fromUtf8("dockWidgetContents_8"));
        label_25 = new QLabel(dockWidgetContents_8);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 40, 81, 21));
        label_26 = new QLabel(dockWidgetContents_8);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(90, 70, 81, 21));
        label_27 = new QLabel(dockWidgetContents_8);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(310, 40, 16, 16));
        label_28 = new QLabel(dockWidgetContents_8);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(310, 70, 16, 16));
        label_29 = new QLabel(dockWidgetContents_8);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(10, 120, 81, 21));
        comboBox_direction = new QComboBox(dockWidgetContents_8);
        comboBox_direction->addItem(QString());
        comboBox_direction->addItem(QString());
        comboBox_direction->setObjectName(QString::fromUtf8("comboBox_direction"));
        comboBox_direction->setGeometry(QRect(90, 120, 101, 22));
        label_31 = new QLabel(dockWidgetContents_8);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(10, 210, 81, 20));
        pushButton_turn_h = new QPushButton(dockWidgetContents_8);
        pushButton_turn_h->setObjectName(QString::fromUtf8("pushButton_turn_h"));
        pushButton_turn_h->setGeometry(QRect(90, 210, 101, 31));
        pushButton_turn_v = new QPushButton(dockWidgetContents_8);
        pushButton_turn_v->setObjectName(QString::fromUtf8("pushButton_turn_v"));
        pushButton_turn_v->setGeometry(QRect(200, 210, 101, 31));
        label_32 = new QLabel(dockWidgetContents_8);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(90, 40, 81, 21));
        lineEdit_degree = new QLineEdit(dockWidgetContents_8);
        lineEdit_degree->setObjectName(QString::fromUtf8("lineEdit_degree"));
        lineEdit_degree->setGeometry(QRect(200, 120, 101, 22));
        label_33 = new QLabel(dockWidgetContents_8);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(310, 120, 16, 16));
        confrim_size = new QPushButton(dockWidgetContents_8);
        confrim_size->setObjectName(QString::fromUtf8("confrim_size"));
        confrim_size->setGeometry(QRect(330, 60, 51, 21));
        confirm_rotate = new QPushButton(dockWidgetContents_8);
        confirm_rotate->setObjectName(QString::fromUtf8("confirm_rotate"));
        confirm_rotate->setGeometry(QRect(330, 120, 51, 21));
        clockwise_90 = new QPushButton(dockWidgetContents_8);
        clockwise_90->setObjectName(QString::fromUtf8("clockwise_90"));
        clockwise_90->setGeometry(QRect(90, 160, 101, 31));
        anticlockwise_90 = new QPushButton(dockWidgetContents_8);
        anticlockwise_90->setObjectName(QString::fromUtf8("anticlockwise_90"));
        anticlockwise_90->setGeometry(QRect(200, 160, 101, 31));
        doubleSpinBox_length = new QDoubleSpinBox(dockWidgetContents_8);
        doubleSpinBox_length->setObjectName(QString::fromUtf8("doubleSpinBox_length"));
        doubleSpinBox_length->setGeometry(QRect(200, 40, 101, 21));
        doubleSpinBox_length->setMinimum(0.100000000000000);
        doubleSpinBox_length->setMaximum(10.000000000000000);
        doubleSpinBox_length->setSingleStep(0.100000000000000);
        doubleSpinBox_length->setValue(1.000000000000000);
        doubleSpinBox_width = new QDoubleSpinBox(dockWidgetContents_8);
        doubleSpinBox_width->setObjectName(QString::fromUtf8("doubleSpinBox_width"));
        doubleSpinBox_width->setGeometry(QRect(200, 70, 101, 21));
        doubleSpinBox_width->setMinimum(0.100000000000000);
        doubleSpinBox_width->setMaximum(10.000000000000000);
        doubleSpinBox_width->setSingleStep(0.100000000000000);
        doubleSpinBox_width->setValue(1.000000000000000);
        dock_geometry->setWidget(dockWidgetContents_8);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dock_geometry);
        dock_center = new QDockWidget(MainWindow);
        dock_center->setObjectName(QString::fromUtf8("dock_center"));
        dock_center->setMinimumSize(QSize(650, 800));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dock_center->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dock_center);
        dock_special = new QDockWidget(MainWindow);
        dock_special->setObjectName(QString::fromUtf8("dock_special"));
        dock_special->setMinimumSize(QSize(400, 400));
        dock_special->setMaximumSize(QSize(400, 900));
        dock_special->setLayoutDirection(Qt::LeftToRight);
        dock_special->setStyleSheet(QString::fromUtf8(""));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        label_11 = new QLabel(dockWidgetContents_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 40, 61, 31));
        label_12 = new QLabel(dockWidgetContents_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 100, 61, 31));
        pushButton_histogram = new QPushButton(dockWidgetContents_3);
        pushButton_histogram->setObjectName(QString::fromUtf8("pushButton_histogram"));
        pushButton_histogram->setGeometry(QRect(110, 40, 101, 31));
        label_13 = new QLabel(dockWidgetContents_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(110, 100, 71, 31));
        label_14 = new QLabel(dockWidgetContents_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(110, 150, 81, 31));
        horizontalSlider_filter = new QSlider(dockWidgetContents_3);
        horizontalSlider_filter->setObjectName(QString::fromUtf8("horizontalSlider_filter"));
        horizontalSlider_filter->setGeometry(QRect(200, 158, 91, 16));
        horizontalSlider_filter->setOrientation(Qt::Horizontal);
        comboBox__filter = new QComboBox(dockWidgetContents_3);
        comboBox__filter->addItem(QString());
        comboBox__filter->addItem(QString());
        comboBox__filter->addItem(QString());
        comboBox__filter->addItem(QString());
        comboBox__filter->addItem(QString());
        comboBox__filter->addItem(QString());
        comboBox__filter->setObjectName(QString::fromUtf8("comboBox__filter"));
        comboBox__filter->setGeometry(QRect(200, 100, 91, 31));
        label_16 = new QLabel(dockWidgetContents_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 250, 81, 31));
        comboBox__filter_2 = new QComboBox(dockWidgetContents_3);
        comboBox__filter_2->addItem(QString());
        comboBox__filter_2->addItem(QString());
        comboBox__filter_2->addItem(QString());
        comboBox__filter_2->addItem(QString());
        comboBox__filter_2->setObjectName(QString::fromUtf8("comboBox__filter_2"));
        comboBox__filter_2->setGeometry(QRect(110, 250, 91, 31));
        confirm_filter_2 = new QPushButton(dockWidgetContents_3);
        confirm_filter_2->setObjectName(QString::fromUtf8("confirm_filter_2"));
        confirm_filter_2->setGeometry(QRect(210, 250, 81, 31));
        confirm_filter = new QPushButton(dockWidgetContents_3);
        confirm_filter->setObjectName(QString::fromUtf8("confirm_filter"));
        confirm_filter->setGeometry(QRect(110, 200, 91, 31));
        dock_special->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dock_special);
        dock_geometry->raise();
        dock_center->raise();
        dock_special->raise();
        dock_paint->raise();

        menuBar->addAction(menu21->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu21->addAction(action_new);
        menu21->addAction(action_open);
        menu21->addSeparator();
        menu21->addAction(action_save);
        menu21->addAction(action_saveas);
        menu21->addSeparator();
        menu21->addAction(action_exit);
        menu_2->addAction(action_geometry);
        menu_2->addAction(action_special);
        menu_2->addAction(action_paint);
        menu_2->addAction(action__layer);
        mainToolBar->addAction(action_new);
        mainToolBar->addAction(action_open);
        mainToolBar->addAction(action_save);
        mainToolBar->addAction(action_saveas);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GraphEditor", nullptr));
        action_open->setText(QCoreApplication::translate("MainWindow", "&\346\211\223\345\274\200", nullptr));
        action_new->setText(QCoreApplication::translate("MainWindow", "&\346\226\260\345\273\272", nullptr));
        action_save->setText(QCoreApplication::translate("MainWindow", "&\344\277\235\345\255\230", nullptr));
        action_saveas->setText(QCoreApplication::translate("MainWindow", "&\345\217\246\345\255\230\344\270\272", nullptr));
        action_exit->setText(QCoreApplication::translate("MainWindow", "&\345\205\263\351\227\255", nullptr));
        action_geometry->setText(QCoreApplication::translate("MainWindow", "&\345\207\240\344\275\225\345\217\230\346\215\242", nullptr));
        action_special->setText(QCoreApplication::translate("MainWindow", "&\347\211\271\346\256\212\346\225\210\346\236\234", nullptr));
        action_paint->setText(QCoreApplication::translate("MainWindow", "&\347\273\230\345\233\276\345\267\245\345\205\267", nullptr));
        action__layer->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\261\202", nullptr));
        menu21->setTitle(QCoreApplication::translate("MainWindow", "&\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "&\350\247\206\345\233\276", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "&\345\270\256\345\212\251", nullptr));
        dock_layer->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\261\202", nullptr));
#if QT_CONFIG(tooltip)
        dock_paint->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        dock_paint->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\347\256\261", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_choose->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_choose->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_line->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_line->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_ciecle->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_ciecle->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_rectangle->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_rectangle->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_cut->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_cut->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_eraser->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_eraser->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_color->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_color->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_translation->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_translation->setText(QString());
        combox_pensize->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        combox_pensize->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        combox_pensize->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        combox_pensize->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        combox_pensize->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        combox_pensize->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        combox_pensize->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        combox_pensize->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));
        combox_pensize->setItemText(8, QCoreApplication::translate("MainWindow", "9", nullptr));
        combox_pensize->setItemText(9, QCoreApplication::translate("MainWindow", "10", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "\347\262\227\347\273\206", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "px", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\250\241\345\274\217", nullptr));
        comboBox_mode->setItemText(0, QCoreApplication::translate("MainWindow", "\347\273\230\345\233\276", nullptr));
        comboBox_mode->setItemText(1, QCoreApplication::translate("MainWindow", "\346\251\241\347\232\256\346\223\246", nullptr));
        comboBox_mode->setItemText(2, QCoreApplication::translate("MainWindow", "\345\217\215\346\251\241\347\232\256\346\223\246", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "\347\224\273\347\254\224", nullptr));
        comboBox_solid->setItemText(0, QCoreApplication::translate("MainWindow", "\347\251\272\345\277\203", nullptr));
        comboBox_solid->setItemText(1, QCoreApplication::translate("MainWindow", "\345\256\236\345\277\203", nullptr));

#if QT_CONFIG(whatsthis)
        pushButton_pen->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/\344\277\235\345\255\230.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_pen->setText(QString());
        dock_geometry->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\207\240\344\275\225\345\217\230\346\215\242", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\247\345\260\217", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\256\275\345\272\246\357\274\232", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\345\200\215", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\345\200\215", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\346\227\213\350\275\254", nullptr));
        comboBox_direction->setItemText(0, QCoreApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\210", nullptr));
        comboBox_direction->setItemText(1, QCoreApplication::translate("MainWindow", "\351\200\206\346\227\266\351\222\210", nullptr));

        label_31->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\347\277\273\350\275\254", nullptr));
        pushButton_turn_h->setText(QCoreApplication::translate("MainWindow", "\346\260\264\345\271\263\347\277\273\350\275\254", nullptr));
        pushButton_turn_v->setText(QCoreApplication::translate("MainWindow", "\345\236\202\347\233\264\347\277\273\350\275\254", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\351\225\277\345\272\246\357\274\232", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        confrim_size->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244", nullptr));
        confirm_rotate->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244", nullptr));
        clockwise_90->setText(QCoreApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\21090\302\260", nullptr));
        anticlockwise_90->setText(QCoreApplication::translate("MainWindow", "\351\200\206\346\227\266\351\222\21090\302\260", nullptr));
        dock_center->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\204\347\220\206", nullptr));
        dock_special->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\211\271\346\256\212\346\225\210\346\236\234", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\273\244\351\225\234", nullptr));
        pushButton_histogram->setText(QCoreApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276\346\230\276\347\244\272", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\346\273\244\351\225\234\346\225\210\346\236\234", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\346\273\244\351\225\234\347\250\213\345\272\246", nullptr));
        comboBox__filter->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));
        comboBox__filter->setItemText(1, QCoreApplication::translate("MainWindow", "\345\276\204\345\220\221\346\250\241\347\263\212", nullptr));
        comboBox__filter->setItemText(2, QCoreApplication::translate("MainWindow", "\346\211\251\346\225\243", nullptr));
        comboBox__filter->setItemText(3, QCoreApplication::translate("MainWindow", "\347\276\275\345\214\226", nullptr));
        comboBox__filter->setItemText(4, QCoreApplication::translate("MainWindow", "\346\200\200\346\227\247", nullptr));
        comboBox__filter->setItemText(5, QCoreApplication::translate("MainWindow", "\351\273\221\347\231\275", nullptr));

        label_16->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\346\273\244\346\263\242", nullptr));
        comboBox__filter_2->setItemText(0, QCoreApplication::translate("MainWindow", "\345\235\207\345\200\274\346\273\244\346\263\242", nullptr));
        comboBox__filter_2->setItemText(1, QCoreApplication::translate("MainWindow", "\351\253\230\346\226\257\346\273\244\346\263\242", nullptr));
        comboBox__filter_2->setItemText(2, QCoreApplication::translate("MainWindow", "\344\270\255\345\200\274\346\273\244\346\263\242", nullptr));
        comboBox__filter_2->setItemText(3, QCoreApplication::translate("MainWindow", "\345\217\214\350\276\271\346\273\244\346\263\242", nullptr));

        confirm_filter_2->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244", nullptr));
        confirm_filter->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
