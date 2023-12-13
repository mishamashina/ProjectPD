#include "widgetzx.h"

WidgetZX::WidgetZX(QWidget *parent): QWidget{parent}
{

}

void WidgetZX::ValueZX(int value)
{

    num_lb7 = value;
    value_first_datch = num_lb7 * 3;
    //qDebug() << "value_first_datch" << value_first_datch;
    update();


}


void WidgetZX::paintEvent(QPaintEvent *event)
{
    first_datch =  (value_first_datch * 0.0025510204) * 100;
    //qDebug() << "first_datch" << first_datch;
    max_second_datch = (24 * 0.08) * 80 + (39 * 0.0833333) * 80;
    second_datch = max_second_datch * (value_first_datch * 0.0025510204);
    max_third_datch = 381;
    value_third_datch = max_third_datch * (value_first_datch * 0.0025510204);
    string_value_first = QString::number(first_datch);
    string_value_third = QString::number(value_third_datch);
    string_value_second = QString::number(second_datch);

    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawRect(painter.viewport());


    // Масштабирование
    QPoint extremePoint(370, 440);
    double sx = 1. * width()/extremePoint.x();
    double sy = 1. * height()/extremePoint.y();
    painter.scale(std::min(sx, sy), std::min(sx, sy));

    QFont font("Ubuntu", 16, QFont::Bold);

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));

    if (first_datch < 33 && first_datch > 0)
    {
        QLinearGradient linearGrad(QPointF(90, 80), QPointF(first_datch*2 +90, 80));
        linearGrad.setColorAt(0, Qt::red);
        linearGrad.setColorAt(1, QColor(0, 0, 0, 0));
        painter.setBrush(linearGrad);
    }
    else if(first_datch > 33 && first_datch < 66)
    {
        QLinearGradient linearGrad(QPointF(90, 80), QPointF(first_datch*2 +90, 80));
        linearGrad.setColorAt(0, Qt::yellow);
        linearGrad.setColorAt(1, QColor(0, 0, 0, 0));
        painter.setBrush(linearGrad);
        }
    else if (first_datch < 91 && first_datch > 66)
    {
        QLinearGradient linearGrad(QPointF(90, 80), QPointF(first_datch*2 +90, 80));
        linearGrad.setColorAt(0, Qt::green);
        linearGrad.setColorAt(1, QColor(0, 0, 0, 0));
        painter.setBrush(linearGrad);
    }
    painter.setFont(font);
    QRectF rectangle(90.0, 80.0, 200.0, 50.0);
    painter.drawRoundedRect(rectangle, 30.0, 30.0);
    painter.drawText(183, 110, string_value_first);
    painter.drawText(130, 70, "Запас хода %");

    QRectF rectangle1(90.0, 200.0, 200.0, 50.0);
    painter.drawRoundedRect(rectangle1, 30.0, 30.0);
    painter.drawText(183, 230, string_value_second);
    painter.drawText(100, 190, "Запас хода 80 км/ч");

    QRectF rectangle2(90.0, 320.0, 200.0, 50.0);
    painter.drawRoundedRect(rectangle2, 30.0, 30.0);
    painter.drawText(183, 350, string_value_third);
    painter.drawText(100, 310, "Запас хода 110 км/ч");
}
