#include "widgetzx.h"

WidgetZX::WidgetZX(QWidget *parent): QWidget{parent}
{

}

void WidgetZX::ValueZX(int value)
{
    num_lb7 = value;
    update();
}


void WidgetZX::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.drawRect(painter.viewport());

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));

    if (num_lb7 < 120 & num_lb7 > 80)
    {
        QLinearGradient linearGrad(QPointF(90, 160), QPointF(num_lb7*2 +90, 160));
        linearGrad.setColorAt(0, Qt::green);
        linearGrad.setColorAt(1, QColor(0, 0, 0, 0));
        painter.setBrush(linearGrad);
    }
    else if(num_lb7 <= 80 & num_lb7 > 40)
    {
        QLinearGradient linearGrad(QPointF(90, 160), QPointF(num_lb7*2 +90, 160));
        linearGrad.setColorAt(0, Qt::yellow);
        linearGrad.setColorAt(1, QColor(0, 0, 0, 0));
        painter.setBrush(linearGrad);
    }
    else if(num_lb7 <= 40)
    {
        QLinearGradient linearGrad(QPointF(90, 160), QPointF(num_lb7*2 +90, 160));
        linearGrad.setColorAt(0, Qt::red);
        linearGrad.setColorAt(1, QColor(0, 0, 0, 0));
        painter.setBrush(linearGrad);
    }

    QRectF rectangle(90.0, 160.0, 200.0, 50.0);
    painter.drawRoundedRect(rectangle, 30.0, 30.0);

}
