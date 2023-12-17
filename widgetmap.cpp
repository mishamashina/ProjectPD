#include "widgetmap.h"

WidgetMap::WidgetMap(QWidget *parent)
    : QWidget{parent}
{

}

void WidgetMap::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "keyPressEvent";

    if (event->key() == Qt::Key_Plus)
    {
        qDebug() << "Нажат +";

        checkedPlus = true;

        checkedMinus = false;
        checkedDown = false;
        checkedUp = false;
        checkedRight = false;
        checkedLeft = false;

        countPlus += 1;
        scalePlusAll = teky + scalePlus;
        teky = scalePlusAll;

        update();
    }

    if (event->key() == Qt::Key_Minus)
    {
        qDebug() << "Нажат -";

        checkedMinus = true;

        checkedPlus = false;
        checkedDown = false;
        checkedUp = false;
        checkedRight = false;
        checkedLeft = false;

        countMinus +=1;
        scaleMinusAll = teky - scaleMinus;
        teky = scaleMinusAll;

        update();
    }
    if (event->key() == Qt::Key_Up)
    {
        qDebug() << "Нажат Key_Up";

        checkedUp = true;

        checkedPlus = false;
        checkedMinus = false;
        checkedDown = false;
        checkedRight = false;
        checkedLeft = false;

        countUp += 10;


        //teky += scalePlus*10;


    }
    if (event->key() == Qt::Key_Down)
    {
        qDebug() << "Нажат Key_Down";

        checkedDown = true;

        checkedPlus = false;
        checkedMinus = false;
        checkedUp = false;
        checkedRight = false;
        checkedLeft = false;

        countDown += 1;

    }
    if (event->key() == Qt::Key_Right)
    {
        qDebug() << "Нажат Key_Right";

        checkedRight = true;

        checkedPlus = false;
        checkedMinus = false;
        checkedDown = false;
        checkedUp = false;
        checkedLeft = false;

        countRight += 1;

    }
    if (event->key() == Qt::Key_Left)
    {
        qDebug() << "Нажат Key_Left";

        checkedLeft = true;

        checkedPlus = false;
        checkedMinus = false;
        checkedDown = false;
        checkedRight = false;
        checkedUp = false;

        countLeft += 1;

    }
}

void WidgetMap::paintEvent(QPaintEvent *event)
{
    qDebug() << "QPaintEvent";
    Q_UNUSED(event);
    QPainter painter(this);

    this->setFocusPolicy(Qt::TabFocus);

    myImage.load("/home/kroninberg/links/projects/misha-pd/map.jpg");

    if (myImage.load("/home/kroninberg/links/projects/misha-pd/map.jpg"))
    {
        qDebug() << "Download successful else";
    }
    else
    {
        qDebug() << "Download failed";
    }

    qDebug() << myImage.size() << painter.viewport();
    painter.begin(&myImage);
    painter.drawRect(painter.viewport());


//    QTransform myTransform;

//    myImage = myImage.transformed(myTransform.translate(100,0));

    //painter.translate(-411/2,-391/2);
    if (checkedMinus)
    {
        painter.scale(scaleMinusAll,scaleMinusAll);
        painter.drawImage(painter.viewport(), myImage);
        qDebug() << "Вошло checkedMinus";
        qDebug() << "scaleMinus" << scaleMinusAll;
    }
    else if (checkedPlus)
    {
        painter.scale(scalePlusAll,scalePlusAll);
        painter.drawImage(painter.viewport(), myImage);
        qDebug() << "Вошло checkedPlus";
        qDebug() << "scalePlus" << scalePlusAll;
    }
    else if (checkedUp)
    {
//        QTransform myTransform;

//        myImage.transformed(myTransform.translate(30,0));
        qDebug() << "Вошло checkedUp";
        qDebug() << "scalePlus" << scalePlusAll;
    }
    else if (checkedDown)
    {
        qDebug() << "Вошло checkedDown";
        qDebug() << "scalePlus" << scalePlusAll;
    }
    else if (checkedRight)
    {
        qDebug() << "Вошло checkedRight";
        qDebug() << "scalePlus" << scalePlusAll;
    }
    else if (checkedLeft)
    {
        qDebug() << "Вошло checkedLeft";
        qDebug() << "scalePlus" << scalePlusAll;
    }
    else
    {
        painter.drawImage(painter.viewport(), myImage);
        qDebug() << "Вошло ELSE";
    }
    painter.end();
}
