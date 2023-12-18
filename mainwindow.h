#pragma once

#include <QMainWindow>
#include "serialportmanager.h"
#include "serialportreader.h"
#include "timewidget.h"
#include "widgetangle.h"
#include "widgetdistrezv.h"
#include "widgetsc.h"
#include "widgetterm.h"
#include "widgetzx.h"
#include "widgetmap.h"
#include "widgetturn.h"

#include <QMainWindow>
#include <QSerialPort>
#include <QDebug>
#include <QPainter>
#include <QAction>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<SerialPortReader*> readers;
    SerialPortManager *sm;

    QTabWidget *tabs;
    void mainPanelTab();
    void navigationTab();
    void infoTab();
    void testTab();

    QMenuBar *menuBar;

    void comReaderInit();
    void createActions();
    void createMenus();
    void customizationLogic();

    WidgetAngle *widget;
    WidgetZX *widget_2;
    WidgetSC *widget_3;
    WidgetTerm *widget_4;
    widgetdistRezv *widget_5;
    WidgetMap *widget_6;
    TimeWidget *widget_7;

    QMenu *Speedometer;
    QMenu *DistSensor;
    QMenu *Termometer;
    QMenu *Customization;

    QAction *ClassicSpeed;
    QAction *MinimalSpeed;
    QAction *CombineSpeed;

    QAction *ClassicTerm;
    QAction *MinimalTerm;
    QAction *CombineTerm;
    QAction *GradientTerm;

    QAction *StaticDist;
    QAction *DynamicDist;

public slots:
    void ChangeValue(int value);
    void dataRedist(QString, QString);

private:

};
