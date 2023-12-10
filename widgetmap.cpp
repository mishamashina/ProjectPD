#include "widgetmap.h"

WidgetMap::WidgetMap(QWidget *parent)
    : QWidget{parent}
{
    initImage(myImage);
}

void WidgetMap::initImage(QImage myImage)
{
//    this->setFocusPolicy(Qt::TabFocus);
//    myImage.load("/home/misha/ProjectPD-master/map.jpg");

//    if (myImage.load("/home/misha/ProjectPD-master/map.jpg"))
//    {
//        qDebug() << "Download successful";
//    }
//    else
//    {
//        qDebug() << "Download failed";
//    }

//    qDebug() << myImage.size();

    //update();
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

    if (count == 0)
    {
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

        painter.begin(&myImage);
        painter.drawImage(painter.viewport(), myImage);
        painter.end();

        myImage.save("/home/misha/ProjectPD-master/map_changed.jpg");
        qDebug() << "Копия создана";
        count = 1;
    }
    else
    {
        myImage.load("/home/misha/ProjectPD-master/map_changed.jpg");
        if (myImage.load("/home/misha/ProjectPD-master/map_changed.jpg"))
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

        //painter.translate(-50, 0);

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
//            painter.setWindow(countUp,0,411,391);
//            painter.drawImage(painter.viewport(), myImage);
//            qDebug() << "Вошло checkedUp";
//            qDebug() << "scalePlus" << scalePlusAll;
        }
        else if (checkedDown)
        {
//            painter.scale(scalePlusAll,scalePlusAll);
//            painter.drawImage(painter.viewport(), myImage);
            qDebug() << "Вошло checkedDown";
            qDebug() << "scalePlus" << scalePlusAll;
        }
        else if (checkedRight)
        {
//            painter.scale(scalePlusAll,scalePlusAll);
//            painter.drawImage(painter.viewport(), myImage);
            qDebug() << "Вошло checkedRight";
            qDebug() << "scalePlus" << scalePlusAll;
        }
        else if (checkedLeft)
        {
//            painter.scale(scalePlusAll,scalePlusAll);
//            painter.drawImage(painter.viewport(), myImage);
            qDebug() << "Вошло checkedLeft";
            qDebug() << "scalePlus" << scalePlusAll;
        }
        else
        {
            painter.drawImage(painter.viewport(), myImage);
            qDebug() << "Вошло ELSE";
        }
        painter.resetTransform();
        //painter.save();
        painter.end();
    }


//    qDebug() << painter.viewport();
//    painter.begin(&myImage);
//    painter.drawImage(painter.viewport(), myImage);
//    painter.end();

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
