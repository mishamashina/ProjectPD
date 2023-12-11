#pragma once

#include <QMainWindow>
#include "serialportmanager.h"
#include "serialportreader.h"
#include "widgetangle.h"
#include "widgetdistrezv.h"
#include "widgetsc.h"
#include "widgetterm.h"
#include "widgetzx.h"

#include <QMainWindow>
#include <QSerialPort>
#include <QDebug>
#include <QPainter>
#include <QAction>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    SerialPortReader* reader;
    SerialPortManager *sm;

    void createActions();
    void createMenus();

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

private:

};
