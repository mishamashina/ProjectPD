#include "widgetst.h"

WidgetST::WidgetST(QWidget *parent)
    : QWidget{parent}
{

}

void WidgetST::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(7);
    pen.setBrush(Qt::black);
    pen.setCapStyle(Qt::FlatCap);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(Qt::lightGray);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    painter.drawEllipse(50, 50, 250, 250);

    QBrush brush1;
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush1);

    painter.drawEllipse(350, 50, 250, 250);
}
