#pragma once

#include <QMainWindow>
#include "serialportmanager.h"
#include "serialportreader.h"
#include "widgetangle.h"
#include "widgetdistrezv.h"
#include "widgetsc.h"
#include "widgetterm.h"
#include "widgetzx.h"
#include "widgetmap.h"

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
    //SerialPortReader* reader;
    SerialPortManager *sm;

    void createActions();
    void createMenus();
    //void widgetsInit();

    WidgetAngle *widget;
    WidgetZX *widget_2;
    WidgetSC *widget_3;
    WidgetTerm *widget_4;
    widgetdistRezv *widget_5;
    WidgetMap *widget_6;

    int value;
    int  ColorPick1;
    int  ColorPick2;
    int  ColorPick3;
    int  ColorPick4;
    int  ColorPick5;
    int  ColorPick6;
    int  ColorPick7;
    int  ColorPick8;

    QMenu *Speedometer;
    QMenu *Termometer;
    QMenu *Customization;

    QAction *ClassicSpeed;
    QAction *MinimalSpeed;
    QAction *CombineSpeed;

    QAction *ClassicTerm;
    QAction *MinimalTerm;
    QAction *CombineTerm;
    QAction *GradientTerm;


public slots:
    void ChangeValue(int value);
   // void distRezv(QByteArray m_readData);
  //  void paintEvent(QPaintEvent *event);
    void dataRedist(QString, QString);

private:

};
