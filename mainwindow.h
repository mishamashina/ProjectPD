#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialportreader.h"
#include "serialportmanager.h"

#include <QMainWindow>
#include <QSerialPort>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
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
    QMenu *Сustomization;

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

#endif // MAINWINDOW_H
