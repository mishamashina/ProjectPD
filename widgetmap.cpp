#include "widgetmap.h"

WidgetMap::WidgetMap(QWidget *parent)
    : QWidget{parent}
{
    initImage(myImage);
}

void WidgetMap::initImage(QImage myImage)
{
    this->setFocusPolicy(Qt::TabFocus);
    myImage.load("/home/misha/ProjectPD-master/map.jpg");

    if (myImage.load("/home/misha/ProjectPD-master/map.jpg"))
    {
        qDebug() << "Download successful";
    }
    else
    {
        qDebug() << "Download failed";
    }

    qDebug() << myImage.size();

    //return myImage;
    //update();
}

void WidgetMap::keyPressEvent(QKeyEvent *event)
{
    //this->setFocusPolicy(Qt::TabFocus);

    qDebug() << "keyPressEvent";
    //Q_UNUSED(event);

    if (event->key() == Qt::Key_Plus)
    {
        qDebug() << "Нажат +";
    }

    if (event->key() == Qt::Key_Minus)
    {
        qDebug() << "Нажат -";
    }
}

void WidgetMap::paintEvent(QPaintEvent *event)
{
    qDebug() << "QPaintEvent";
    qDebug() << myImage.size();
    Q_UNUSED(event);
    QPainter painter(this);

    qDebug() << painter.viewport();
    //painter.begin(&myImage);
    painter.drawImage(painter.viewport(), myImage);
    //painter.end();

    //qDebug() << myImage.size();
//    QSize mySize = myImage.size();
//    int mySizeHeight = mySize.rheight();
//    int mySizeWidth = mySize.rwidth();
//    mySize.setHeight(mySizeHeight/2);
//    mySize.setWidth(mySizeWidth/2);

//    qDebug() << painter.viewport();
//    painter.begin(&myImage);
//    if (count == 0)
//    {
//        painter.drawImage(painter.viewport(), myImage);
//        count = 1;
//    }
//    else
//    {

//    }



}
