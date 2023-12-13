#include "widgetangle.h"
#include <QPainterPath>

WidgetAngle::WidgetAngle(QWidget *parent)
    : QWidget{parent}
{

}
void WidgetAngle::ValueAngle(int value)
{
    angle = value / 4;
    update();
}

void WidgetAngle::paintEvent(QPaintEvent *event)
{

    Q_UNUSED(event);
    QPainter painter(this);

    //      ФОН

//    QColor backgroundColor(148, 171, 176, 128);
//    painter.setPen(Qt::NoPen);
//    painter.setBrush(backgroundColor);
//    painter.drawRect(0, 0, painter.viewport().width(), painter.viewport().height());


    //      КОЛЁСА ПЕРЕМЕННЫЕ
    QRect r(0,0, this->width(), this->height());
    painter.drawRect(r);

    // Масштабирование
    QPoint extremePoint(530, 290);
    double sx = 1. * width()/extremePoint.x();
    double sy = 1. * height()/extremePoint.y();
    painter.scale(std::min(sx, sy), std::min(sx, sy));

    painter.scale(0.5,0.5);
    int cornerRadius = 13;
    int wheelWidth = 50;
    int wheelHeight = 100;

    int centerLeftWheelsX = 400 + wheelWidth / 2;
    int centerRightWheelsX = centerLeftWheelsX + 200;
    int centerTopWheelsY = 100 + wheelHeight / 2;
    int centerBottomWheelsY = centerTopWheelsY + 300;

    int centerX = centerLeftWheelsX + (centerRightWheelsX - centerLeftWheelsX) / 2;


    //      TРАНСМИССИЯ

    QPen pen(Qt::black);
    pen.setWidth(4);
    painter.setPen(pen);
    painter.drawLine(centerLeftWheelsX, centerTopWheelsY, centerRightWheelsX, centerTopWheelsY);
    painter.drawLine(centerX, centerTopWheelsY, centerX, centerBottomWheelsY);
    painter.drawLine(centerLeftWheelsX, centerBottomWheelsY, centerRightWheelsX, centerBottomWheelsY);


    //    КОРПУС

    QPainterPath path;
    path.moveTo(centerLeftWheelsX - 25, centerTopWheelsY);

    path.lineTo(centerLeftWheelsX, centerTopWheelsY - 100);
    path.lineTo(centerRightWheelsX, centerTopWheelsY - 100);
    path.lineTo(centerRightWheelsX + 25, centerTopWheelsY);
    path.lineTo(centerRightWheelsX + 25,centerBottomWheelsY + 100);
    path.lineTo(centerLeftWheelsX - 25, centerBottomWheelsY + 100);
    path.lineTo(centerLeftWheelsX - 25, centerTopWheelsY);


    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawPath(path);


    /*                           КОЛЁСА И ИХ ЛОГИКА                            */

    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);

    //      ОТРИСОВКА
    // Верхние
    painter.save();
    painter.translate(centerLeftWheelsX, centerTopWheelsY);  // Перемещаем начало координат в центр прямоугольника
    painter.rotate(angle);  // Поворачиваем на заданный угол
    painter.drawRoundedRect(-wheelWidth / 2, -wheelHeight / 2, wheelWidth, wheelHeight, cornerRadius, cornerRadius);  // Рисуем прямоугольник в локальных координатах
    painter.restore();  // Восстанавливаем состояние QPainter

    painter.save();
    painter.translate(centerRightWheelsX, centerTopWheelsY);
    painter.rotate(angle);
    painter.drawRoundedRect(-wheelWidth / 2, -wheelHeight / 2, wheelWidth, wheelHeight, cornerRadius, cornerRadius);
    painter.restore();

    // Нижние
    painter.save();
    painter.translate(centerLeftWheelsX, centerBottomWheelsY);
    painter.rotate(-angle);
    painter.drawRoundedRect(-wheelWidth / 2, -wheelHeight / 2, wheelWidth, wheelHeight, cornerRadius, cornerRadius);
    painter.restore();

    painter.save();
    painter.translate(centerRightWheelsX, centerBottomWheelsY);
    painter.rotate(-angle);
    painter.drawRoundedRect(-wheelWidth / 2, -wheelHeight / 2, wheelWidth, wheelHeight, cornerRadius, cornerRadius);
    painter.restore();



}


