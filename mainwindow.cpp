#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "serialportreader.h"
#include <QByteArray>
#include <QDebug>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Project");

    sm = new SerialPortManager("/dev/ttyACM0");
    reader = new SerialPortReader(sm->getSerialPort());
    reader->handleReadyRead();

    //2 указателя - 2 объекта

    connect(reader, &SerialPortReader::ChangeValue, this, &MainWindow::ChangeValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::paintEvent(QPaintEvent *event)
//{
//    Q_UNUSED(event);
//    QPainter painter(this);

//    QPen pen;
//    pen.setStyle(Qt::SolidLine);
//    pen.setWidth(7);
//    pen.setBrush(Qt::black);
//    pen.setCapStyle(Qt::FlatCap);
//    painter.setPen(pen);

//    QBrush brush;
//    brush.setColor(Qt::lightGray);
//    brush.setStyle(Qt::SolidPattern);
//    painter.setBrush(brush);

//    painter.drawEllipse(50, 50, 250, 250);

//    QBrush brush1;
//    brush.setColor(Qt::gray);
//    brush.setStyle(Qt::SolidPattern);
//    painter.setBrush(brush1);

//    painter.drawEllipse(350, 50, 250, 250);

//}



void MainWindow::ChangeValue(int value)
{
    ui->label->setNum(value);
    ui->label_6->setNum(value);

}
