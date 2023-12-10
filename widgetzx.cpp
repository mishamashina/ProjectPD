#include "widgetzx.h"

WidgetZX::WidgetZX(QWidget *parent): QWidget{parent}
{

}

void WidgetZX::ValueZX(int value)
{

    num_lb7 = value;
    value_first_datch = num_lb7 * 3;
    qDebug() << "value_first_datch" << value_first_datch;
    update();


}


void WidgetZX::paintEvent(QPaintEvent *event)
{
    first_datch =  (value_first_datch * 0.0025510204) * 100;
    qDebug() << "first_datch" << first_datch;
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

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));

    if (first_datch < 33)
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

    QRectF rectangle(90.0, 80.0, 200.0, 50.0);
    painter.drawRoundedRect(rectangle, 30.0, 30.0);
    painter.drawText(40, 40, string_value_first);

    QRectF rectangle1(90.0, 160.0, 200.0, 50.0);
    painter.drawRoundedRect(rectangle1, 30.0, 30.0);
    painter.drawText(40, 60, string_value_second);

    QRectF rectangle2(90.0, 240.0, 200.0, 50.0);
    painter.drawRoundedRect(rectangle2, 30.0, 30.0);
    painter.drawText(40, 80, string_value_third);
}
