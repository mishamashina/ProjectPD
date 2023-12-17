#include "widgetdistrezv.h"

widgetdistRezv::widgetdistRezv(QWidget *parent)
    : QWidget{parent}
{
    distRezv("12345678");
    checkedStatic = true;
    checkedDynamic = false;
}
void widgetdistRezv::boolStatic(bool checked)
{
    //qDebug() << "Зашло boolStatic";
    checkedStatic = checked;
    if (checkedStatic == true){emit signalStaticDynamic();}
    checkedDynamic = false;
    update();
}

void widgetdistRezv::boolDynamic(bool checked)
{
    //qDebug() << "Зашло boolDynamic";
    checkedDynamic = checked;
    if (checkedDynamic == true){emit signalDynamicStatic();}
    checkedStatic = false;
    update();
}
void widgetdistRezv::distRezv(QByteArray m_readData)
{
    value = m_readData.toInt();
    //qDebug() << "Значение m_readData slot" << m_readData;
    ColorPick8 = value % 10;
    //qDebug() << "Значение ColorPick8" << ColorPick8;
    ColorPick8string = QString::number(ColorPick8);

    ColorPick7 = value / 10 % 10;
    //qDebug() << "Значение ColorPick7" << ColorPick7;
    ColorPick7string = QString::number(ColorPick7);

    ColorPick6 = value / 100 % 10;
    //qDebug() << "Значение ColorPick6" << ColorPick6;
    ColorPick6string = QString::number(ColorPick6);

    ColorPick5 = value / 1000 % 10;
    //qDebug() << "Значение ColorPick5" << ColorPick5;
    ColorPick5string = QString::number(ColorPick5);

    ColorPick4 = value / 10000 % 10;
    //qDebug() << "Значение ColorPick4" << ColorPick4;
    ColorPick4string = QString::number(ColorPick4);

    ColorPick3 = value / 100000 % 10;
    //qDebug() << "Значение ColorPick3" << ColorPick3;
    ColorPick3string = QString::number(ColorPick3);

    ColorPick2 = value / 1000000 % 10;
    //qDebug() << "Значение ColorPick2" << ColorPick2;
    ColorPick2string = QString::number(ColorPick2);

    ColorPick1 = value / 10000000 % 10;
    //qDebug() << "Значение ColorPick1" << ColorPick1;
    ColorPick1string = QString::number(ColorPick1);
    update();
}

void widgetdistRezv::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.drawRect(painter.viewport());

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(7);

    // Масштабирование
    //qDebug() << width() << ' ' << height();
    QPoint extremePoint(600, 400);
    double sx = 1. * width()/extremePoint.x();
    double sy = 1. * height()/extremePoint.y();
    painter.scale(std::min(sx, sy), std::min(sx, sy));

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    /*
    painter.drawRect(200, 50, 200, 300); //Круглая отрисовка
    painter.drawEllipse(150, 0, 300, 400);
    painter.drawLine(300, 100,300, 0);
    painter.drawLine(350,100, 400, 50);
      painter.drawPie(150,0, 300, 400, 0, 1440);
        painter.drawEllipse(150, 0, 300, 400);
    painter.drawLine(350, 200, 450, 200);*/
    painter.setBrush(Qt::lightGray);
    painter.drawRect(250, 100, 100, 200);

    QPolygon pol_1;
    QPolygon pol_2;
    QPolygon pol_3;
    QPolygon pol_4;
    QPolygon pol_5;
    QPolygon pol_6;
    QPolygon pol_7;
    QPolygon pol_8;
    QPolygon pol_1_1;
    QPolygon pol_2_1;
    QPolygon pol_3_1;
    QPolygon pol_4_1;
    QPolygon pol_5_1;
    QPolygon pol_6_1;
    QPolygon pol_7_1;
    QPolygon pol_8_1;
    QPolygon pol_1_2;
    QPolygon pol_2_2;
    QPolygon pol_3_2;
    QPolygon pol_4_2;
    QPolygon pol_5_2;
    QPolygon pol_6_2;
    QPolygon pol_7_2;
    QPolygon pol_8_2;
    int k1 = 15;
    int k2 = 25;
    //Далеко(Зеленый)
    //Левый-перед
    pol_1 << QPoint(200,50) << QPoint(300,50) << QPoint(300,100) << QPoint(250,100);
    //Правый-перед
    pol_2 << QPoint(400,50) << QPoint(300,50) << QPoint(300,100) << QPoint(350,100);
    //Право-низ
    pol_3 << QPoint(400,350) << QPoint(350,300) << QPoint(350,150) << QPoint(400,150);
    //Лево-низ
    pol_4 << QPoint(200,200) << QPoint(250,200) << QPoint(250,300) << QPoint(200,350);
    //Правый-сзади
    pol_5 << QPoint(350,300) << QPoint(400,350) << QPoint(300,350) << QPoint(300,300);
    //Левый-сзади
    pol_6 << QPoint(250,300) << QPoint(200,350) << QPoint(300,350) << QPoint(300,300);
    //Левый-верх
    pol_7 << QPoint(200,50) << QPoint(200,200) << QPoint(250,200) << QPoint(250,100);
    //Право-верх
    pol_8 << QPoint(350,100) << QPoint(400,50) << QPoint(400,200) << QPoint(350,200);

    //Среднее(Желтый)
    //Левый-перед
    pol_1_1 << QPoint(200-k1,50-k1) << QPoint(300,50-k1) << QPoint(300,100) << QPoint(250,100);
    //Правый-перед
    pol_2_1 << QPoint(400+k1,50-k1) << QPoint(300,50-k1) << QPoint(300,100) << QPoint(350,100);
    //Право-низ
    pol_3_1 << QPoint(400+k1,350+k1) << QPoint(350,300) << QPoint(350,200) << QPoint(400+k1,200);
    //Лево-низ
    pol_4_1 << QPoint(200-k1,200) << QPoint(250,200) << QPoint(250,300) << QPoint(200-k1,350+k1);
    //Правый-сзади
    pol_5_1 << QPoint(350,300) << QPoint(400+k1,350+k1) << QPoint(300,350+k1) << QPoint(300,300);
    //Левый-сзади
    pol_6_1 << QPoint(250,300) << QPoint(200-k1,350+k1) << QPoint(300,350+k1) << QPoint(300,300);
    //Левый-верх
    pol_7_1 << QPoint(200-k1,50-k1) << QPoint(200-k1,200) << QPoint(250,200) << QPoint(250,100);
    //Право-верх
    pol_8_1 << QPoint(350,100) << QPoint(400+k1,50-k1) << QPoint(400+k1,200) << QPoint(350,200);

    //Близко(красный)
    //Левый-перед
    pol_1_2 << QPoint(200-k2,50-k2) << QPoint(300,50-k2) << QPoint(300,100) << QPoint(250,100);
    //Правый-перед
    pol_2_2 << QPoint(400+k2,50-k2) << QPoint(300,50-k2) << QPoint(300,100) << QPoint(350,100);
    //Право-низ
    pol_3_2 << QPoint(400+k2,350+k2) << QPoint(350,300) << QPoint(350,200) << QPoint(400+k2,200);
    //Лево-низ
    pol_4_2 << QPoint(200-k2,200) << QPoint(250,200) << QPoint(250,300) << QPoint(200-k2,350+k2);
    //Правый-сзади
    pol_5_2 << QPoint(350,300) << QPoint(400+k2,350+k2) << QPoint(300,350+k2) << QPoint(300,300);
    //Левый-сзади
    pol_6_2 << QPoint(250,300) << QPoint(200-k2,350+k2) << QPoint(300,350+k2) << QPoint(300,300);
    //Левый-верх
    pol_7_2 << QPoint(200-k2,50-k2) << QPoint(200-k2,200) << QPoint(250,200) << QPoint(250,100);
    //Право-верх
    pol_8_2 << QPoint(350,100) << QPoint(400+k2,50-k2) << QPoint(400+k2,200) << QPoint(350,200);

    if (checkedDynamic)
    {
        //Правый-перед
        if (ColorPick1 < 3)
        {
            painter.setBrush(Qt::red);
            painter.drawPolygon(pol_2_2);
        }
        else if (ColorPick1 > 7)
        {
            painter.setBrush(Qt::green);
            painter.drawPolygon(pol_2);
        }
        else
        {
            painter.setBrush(Qt::yellow);
            painter.drawPolygon(pol_2_1);
        }

        //Правый-сзади
        if (ColorPick5 < 3)
        {

            painter.setBrush(Qt::red);
            painter.drawPolygon(pol_5_2);
        }
        else if (ColorPick5 > 7)
        {
            painter.setBrush(Qt::green);
            painter.drawPolygon(pol_5);
        }
        else
        {
            painter.setBrush(Qt::yellow);
            painter.drawPolygon(pol_5_1);
        }

        //Левый-сзади
        if (ColorPick6 < 3)
        {

            painter.setBrush(Qt::red);
            painter.drawPolygon(pol_6_2);
        }
        else if (ColorPick6 > 7)
        {
            painter.setBrush(Qt::green);
            painter.drawPolygon(pol_6);
        }
        else
        {
            painter.setBrush(Qt::yellow);
            painter.drawPolygon(pol_6_1);
        }

        // Лево

        if (ColorPick2 < 3)
        {
            painter.setBrush(Qt::red);
            painter.drawPolygon(pol_4_2);
        }
        else if (ColorPick2 > 7)
        {
            painter.setBrush(Qt::green);
            painter.drawPolygon(pol_4);
        }
        else
        {
            painter.setBrush(Qt::yellow);
            painter.drawPolygon(pol_4_1);
        }

        //Левый-верх
        if (ColorPick3 < 3)
        {
            painter.setBrush(Qt::red);
            painter.drawPolygon(pol_1_2);
        }
        else if (ColorPick3 > 7)
        {
            painter.setBrush(Qt::green);
            painter.drawPolygon(pol_1);
        }
        else
        {
            painter.setBrush(Qt::yellow);
            painter.drawPolygon(pol_1_1);
        }

        // Право
        if (ColorPick4 < 3)
        {
            painter.setBrush(QBrush(Qt::red));
            painter.drawPolygon(pol_3_2);
        }
        else if (ColorPick4 > 7)
        {
            painter.setBrush(QBrush(Qt::green));
            painter.drawPolygon(pol_3);
        }
        else
        {
            painter.setBrush(QBrush(Qt::yellow));
            painter.drawPolygon(pol_3_1);
        }
        //Левый верх
        if (ColorPick7 < 3)
        {
            painter.setBrush(QBrush(Qt::red));
            painter.drawPolygon(pol_7_2);
        }
        else if (ColorPick7 > 7)
        {
            painter.setBrush(QBrush(Qt::green));
            painter.drawPolygon(pol_7);
        }
        else
        {
            painter.setBrush(QBrush(Qt::yellow));
            painter.drawPolygon(pol_7_1);
        }
        //Правый верх
        if (ColorPick8 < 3)
        {
            painter.setBrush(QBrush(Qt::red));
            painter.drawPolygon(pol_8_2);
        }
        else if (ColorPick8 > 7)
        {
            painter.setBrush(QBrush(Qt::green));
            painter.drawPolygon(pol_8);
        }
        else
        {
            painter.setBrush(QBrush(Qt::yellow));
            painter.drawPolygon(pol_8_1);
        }
    }
        ///////////////////////////////////////////////////////////
    if (checkedStatic)
    {
        //Правый-перед
        if (ColorPick1 < 3)
        {
            painter.setBrush(Qt::red);
            painter.drawPolygon(pol_2);
        }
        else if (ColorPick1 > 7)
        {
            painter.setBrush(Qt::green);
            painter.drawPolygon(pol_2);
        }
        else
        {
            painter.setBrush(Qt::yellow);
            painter.drawPolygon(pol_2);
        }

        //Правый-сзади
        if (ColorPick5 < 3)
        {

            painter.setBrush(Qt::red);
            painter.drawPolygon(pol_5);
        }
        else if (ColorPick5 > 7)
        {
            painter.setBrush(Qt::green);
            painter.drawPolygon(pol_5);
        }
        else
        {
            painter.setBrush(Qt::yellow);
            painter.drawPolygon(pol_5);
        }

        //Левый-сзади
        if (ColorPick6 < 3)
        {

            painter.setBrush(Qt::red);
            painter.drawPolygon(pol_6);
        }
        else if (ColorPick6 > 7)
        {
            painter.setBrush(Qt::green);
            painter.drawPolygon(pol_6);
        }
        else
        {
            painter.setBrush(Qt::yellow);
            painter.drawPolygon(pol_6);
        }

         // Лево

        if (ColorPick2 < 3)
        {
            painter.setBrush(Qt::red);
            painter.drawPolygon(pol_4);
        }
        else if (ColorPick2 > 7)
        {
            painter.setBrush(Qt::green);
            painter.drawPolygon(pol_4);
        }
        else
        {
            painter.setBrush(Qt::yellow);
            painter.drawPolygon(pol_4);
        }

        //Левый-верх
        if (ColorPick3 < 3)
        {
            painter.setBrush(Qt::red);
            painter.drawPolygon(pol_1);
        }
        else if (ColorPick3 > 7)
        {
            painter.setBrush(Qt::green);
            painter.drawPolygon(pol_1);
        }
        else
        {
            painter.setBrush(Qt::yellow);
            painter.drawPolygon(pol_1);
        }

        // Право
        if (ColorPick4 < 3)
        {
            painter.setBrush(QBrush(Qt::red));
            painter.drawPolygon(pol_3);
        }
        else if (ColorPick4 > 7)
        {
            painter.setBrush(QBrush(Qt::green));
            painter.drawPolygon(pol_3);
        }
        else
        {
            painter.setBrush(QBrush(Qt::yellow));
            painter.drawPolygon(pol_3);
        }
        //Левый верх
        if (ColorPick7 < 3)
        {
            painter.setBrush(QBrush(Qt::red));
            painter.drawPolygon(pol_7);
        }
        else if (ColorPick7 > 7)
        {
            painter.setBrush(QBrush(Qt::green));
            painter.drawPolygon(pol_7);
        }
        else
        {
            painter.setBrush(QBrush(Qt::yellow));
            painter.drawPolygon(pol_7);
        }
        //Правый верх
        if (ColorPick8 < 3)
        {
            painter.setBrush(QBrush(Qt::red));
            painter.drawPolygon(pol_8);
        }
        else if (ColorPick8 > 7)
        {
            painter.setBrush(QBrush(Qt::green));
            painter.drawPolygon(pol_8);
        }
        else
        {
            painter.setBrush(QBrush(Qt::yellow));
            painter.drawPolygon(pol_8);
        }
    }
        ///////////////////////////////////////////////////////////
    QFont font("Ubuntu", 30, QFont::Bold);
    painter.setFont(font);

                 // расположение label
    QPoint p27(320, 90); //320 50
    QPoint p28(210, 260); //210 220
    QPoint p29(250, 90);//240 50
    QPoint p30(360, 260);//360 220
    QPoint p31(320, 335);//320 290
    QPoint p32(250, 335);//240 290
    QPoint p33(210, 150);//210 110
    QPoint p34(360, 150);//360 110

    painter.drawText(p27, ColorPick1string);
    painter.drawText(p28, ColorPick2string);
    painter.drawText(p29, ColorPick3string);
    painter.drawText(p30, ColorPick4string);
    painter.drawText(p31, ColorPick5string);
    painter.drawText(p32, ColorPick6string);
    painter.drawText(p33, ColorPick7string);
    painter.drawText(p34, ColorPick8string);

}
