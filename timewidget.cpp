#include "timewidget.h"
#include <QPainter>
#include <QDateTime>
#include <QTimer>

TimeWidget::TimeWidget(QWidget *parent)
    : QWidget{parent}, dateFlag(true)
{
    QTimer *timer = new QTimer(this);		// это должен был быть опрос датчиков по таймеру [может как-нибудь потом]
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void TimeWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont font = painter.font();
    font.setPixelSize(std::min(height()/2 - 4 , 48));
    painter.setFont(font);
    if(dateFlag){
        painter.drawText(rect(), Qt::AlignCenter, QDateTime::currentDateTime().toString("hh:mm:ss") + '\n' +
                     QDateTime::currentDateTime().toString("MMM d yyyy"));
    } else painter.drawText(rect(), Qt::AlignCenter, QDateTime::currentDateTime().toString("hh:mm:ss"));
}
