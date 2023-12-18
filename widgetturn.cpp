#include "widgetturn.h"
#include <QPainter>
#include <QTimer>

WidgetTurn::WidgetTurn(QWidget *parent, bool isRight)
    : QWidget{parent}, isRight(isRight), blinkFlag(false)
{
}

void WidgetTurn::switchState(){
    if(isOn) isOn = false;
    else {
        isOn = true;
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(blinkSlot()));
        timer->start(500);
    }
    update();
}

void WidgetTurn::blinkSlot(){
    if(blinkFlag) blinkFlag = false;
    else blinkFlag = true;
    update();
}

void WidgetTurn::switchDirection(){
    if(isRight) isRight = false;
    else isRight = true;
    update();
}

void WidgetTurn::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);

    // Масштабирование
    QPoint extremePoint(60, 50);
    double sx = 1. * width()/extremePoint.x();
    double sy = 1. * height()/extremePoint.y();
    painter.scale(std::min(sx, sy), std::min(sx, sy));

    if(!isRight){
        painter.translate(60, 50);
        painter.rotate(180);
    }

    QPolygon arrow;
    arrow << QPoint(10, 20) << QPoint(30, 20) << QPoint(30, 10) << QPoint(50, 25) << QPoint(30, 40) << QPoint(30, 30) << QPoint(10, 30);

    if(isOn){
        if(blinkFlag){
            painter.setBrush(Qt::green);
            painter.drawPolygon(arrow);
        } else {
            painter.setBrush(Qt::darkGreen);
            painter.drawPolygon(arrow);
        }
    } else {
        painter.setBrush(Qt::darkGreen);
        painter.drawPolygon(arrow);
    }
}
