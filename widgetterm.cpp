#include "widgetterm.h"

WidgetTerm::WidgetTerm(QWidget *parent)
    : QWidget{parent}
{
    checkedMinimal = false;
    checkedClassic = true;
    checkedCombine = false;
    checkedGradient = false;
}

void WidgetTerm::ValueTerm(int value)
{
    num_lb = value / 4;
    numb_lbPovorot = value;
    num_lbString = QString::number(num_lb);
    num_lbPovorotString = QString::number(numb_lbPovorot);
    update();
}

void WidgetTerm::boolMinimal(bool checked)
{
    qDebug() << "Зашло boolMinimal";
    checkedMinimal = checked;
    if (checkedClassic == true){emit signalMinimalClassic();}
    if (checkedCombine == true){emit signalMinimalCombine();}
    if (checkedGradient == true){emit signalMinimalGradient();}

    checkedClassic = false;
    checkedCombine = false;
    checkedGradient = false;
    update();
}

void WidgetTerm::boolClassic(bool checked)
{
    qDebug() << "Зашел boolClassic";

    checkedClassic = checked;
    if (checkedMinimal == true){emit signalClassicMinimal();}
    if (checkedCombine == true){emit signalClassicCombine();}
    if (checkedGradient == true){emit signalMinimalGradient();}

    checkedMinimal = false;
    checkedCombine = false;
    checkedGradient = false;

    update();
}

void WidgetTerm::boolCombine(bool checked)
{
    qDebug() << "Зашло boolCombine";
    checkedCombine = checked;
    if (checkedMinimal == true){emit signalCombineMinimal();}
    if (checkedClassic == true){emit signalCombineClassic();}
    if (checkedGradient == true){emit signalMinimalGradient();}

    checkedMinimal = false;
    checkedClassic = false;
    checkedGradient = false;
    update();
}

void WidgetTerm::boolGradient(bool checked)
{
    qDebug() << "Зашло boolGradient";
    checkedGradient = checked;
    if (checkedMinimal == true){emit signalGradientMinimal();}
    if (checkedClassic == true){emit signalGradientClassic();}
    if (checkedCombine == true){emit signalGradientCombine();}
    checkedMinimal = false;
    checkedClassic = false;
    checkedCombine = false;
    update();

}

void WidgetTerm::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QRect r(0,0, this->width(), this->height());
    //QPoint cent = r.center();
    QPoint cent1(210,185);
    QPoint cent2(560,185);
    painter.drawRect(r);

    qDebug() << "checkedMinimal TERM" << checkedMinimal;
    qDebug() << "checkedClassic TERM" << checkedClassic;
    qDebug() << "checkedCombine TERM" << checkedCombine;
    qDebug() << "checkedGradient TERM" << checkedGradient;

    QFont font("Ubuntu", 20, QFont::Bold);
    QFont font2("Ubuntu", 15);

    QPoint p11(270,220+30); //120 // 280,280
    QPoint p22(290,150+30);
    QPoint p3(260, 90+30);
    QPoint p4(200, 70+30);
    QPoint p5(120, 90+30);
    QPoint p6(100, 150+30);
    QPoint p7(120, 220+30); // 0
    QPoint k(200,140+140);

    QPoint p11cent2(270+350,220+30); //120 // 280,280
    QPoint p22cent2(290+350,150+30);
    QPoint p3cent2(260+350, 90+30);
    QPoint p4cent2(200+350, 70+30);
    QPoint p5cent2(120+350, 90+30);
    QPoint p6cent2(100+350, 150+30);
    QPoint p7cent2(120+350, 220+30); // 0
    QPoint kcent2(200+350,140+140);

    if (checkedGradient)
    {
        qDebug() << "num_lb" <<num_lb;
        int widgetHeight = height();
        int y = widgetHeight / 2 - 100;
        int width = 40;
        int height = 200;
        int fillHeight = 160;

        painter.setPen(Qt::black);
        painter.setFont(QFont("Ubuntu", 16));
        painter.drawText(50, 250, "°C");

        // Рисование термометра - серая часть
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::darkGray);
        painter.drawRect(75,75, width, height);

        // Отрисовка шкалы - белая часть
//        painter.setBrush(Qt::white);
//        painter.drawRect(75, 75 + height, width, 10);

        //painter.setBrush(Qt::yellow);

        for (int i = 0; i <= 10; ++i) {
            int tickY = y + height + i * (-height / 10);
            painter.drawLine(75, tickY, 75 + width, tickY);
        }

//        // Отрисовка текста с текущим значением

        if (numb_lbPovorot < 35) {
            qDebug() << "first";
            fillHeight = 2 * numb_lbPovorot;
            painter.setBrush(Qt::blue);

        } if ((numb_lbPovorot >= 35) && (numb_lbPovorot < 70) ) {
            qDebug() << "second";
            fillHeight = 2 * numb_lbPovorot;
           painter.setBrush(Qt::yellow);

        } if (numb_lbPovorot >= 70) {
           qDebug() << "third";
            fillHeight = 2 * numb_lbPovorot;
            painter.setBrush(Qt::red);


        }

        painter.drawRect(75, 75 + height - fillHeight, width, fillHeight);
        painter.setPen(Qt::black);
        painter.setFont(QFont("Ubuntu", 16));
        painter.drawText(25, 250, num_lbString);
        //second term
        painter.setPen(Qt::black);
        painter.setFont(QFont("Ubuntu", 16));
        painter.drawText(220, 250, "°C");

            // Рисование термометра - серая часть
            painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::darkGray);
        painter.drawRect(150,75, width, height);

        // Отрисовка шкалы - белая часть
        //        painter.setBrush(Qt::white);
        //        painter.drawRect(75, 75 + height, width, 10);

        //painter.setBrush(Qt::yellow);

        for (int i = 0; i <= 10; ++i) {
            int tickY = y + height + i * (-height / 10);
            painter.drawLine(75, tickY, 75 + width, tickY);
        }

        //        // Отрисовка текста с текущим значением

        if (numb_lbPovorot < 35) {
            //qDebug() << "first";
            fillHeight = 2 * numb_lbPovorot;
            painter.setBrush(Qt::blue);

        } if ((numb_lbPovorot >= 35) && (numb_lbPovorot < 70) ) {
            //qDebug() << "second";
            fillHeight = 2 * numb_lbPovorot;
            painter.setBrush(Qt::yellow);

        } if (numb_lbPovorot >= 70) {
            //qDebug() << "third";
            fillHeight = 2 * numb_lbPovorot;
            painter.setBrush(Qt::red);
        }
        painter.drawRect(150, 75 + height - fillHeight, width, fillHeight);
        painter.setPen(Qt::black);
        painter.setFont(QFont("Ubuntu", 16));
        painter.drawText(195, 250, num_lbString);
    }

    if (checkedMinimal)
    {
        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
        painter.setBrush(QBrush(QColor(0, 0, 0, 0), Qt::SolidPattern));

        painter.drawEllipse(cent1, radiusx, radiusx);
        painter.drawEllipse(cent2, radiusx, radiusx);

        painter.setFont(font2);
        painter.drawText(k, "°C");
        painter.drawText(kcent2, "°C");

        painter.setFont(font);
        painter.drawText(cent1.rx() - 20, cent1.ry(), num_lbString);
        painter.drawText(cent2.rx() - 20, cent2.ry(), num_lbString);
    }

    if (checkedClassic)
    {
        painter.setFont(font);

        painter.drawText(p11cent2, "30");
        painter.drawText(p22cent2, "25");
        painter.drawText(p3cent2, "20");
        painter.drawText(p4cent2, "15");
        painter.drawText(p5cent2, "10");
        painter.drawText(p6cent2, "5");
        painter.drawText(p7cent2, "0");

        painter.drawText(p11, "30");
        painter.drawText(p22, "25");
        painter.drawText(p3, "20");
        painter.drawText(p4, "15");
        painter.drawText(p5, "10");
        painter.drawText(p6, "5");
        painter.drawText(p7, "0");

        painter.setFont(font2);
        painter.drawText(k, "°C");
        painter.drawText(kcent2, "°C");

        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
        painter.setBrush(QBrush(QColor(0, 0, 0, 0), Qt::SolidPattern));

        painter.drawEllipse(cent1, radiusx, radiusx);
        painter.drawEllipse(cent2, radiusx, radiusx);

        ///////////////////////////////////////////////////////////////////////////

        painter.translate(cent1);

        QPoint p1(radiusx-20,0);
        QPoint p2(radiusx, 0);
        int i = 10;
        for (int count = 1; count <=36; count++)
        {
            if (count <= 4 || count > 15)
            {
                if (count % 4 == 0)
                {
                    painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::FlatCap));
                    painter.drawLine(p1, p2);
                    painter.rotate(i);
                }
                else
                {
                    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
                    painter.drawLine(p1, p2);
                    painter.rotate(i);
                }
            }
            else
            {
                painter.rotate(i);
            }
        }

        painter.resetTransform();
        painter.translate(cent1);
        painter.rotate(-210);
        painter.setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::FlatCap));

        if (num_lb != 0)
        {
            painter.rotate(numb_lbPovorot*2);
            QPoint p3(0,0);
            QPoint p4(radiusx, 0);
            painter.drawLine(p3,p4);
        }
        ////////////////////////////////////////////////////////////////////////

        painter.resetTransform();
        painter.translate(cent2);

        QPoint p1cent2(radiusx-20,0);
        QPoint p2cent2(radiusx, 0);
        //int i = 10;
        for (int count = 1; count <=36; count++)
        {
            if (count <= 4 || count > 15)
            {
                if (count % 4 == 0)
                {
                    painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::FlatCap));
                    painter.drawLine(p1cent2, p2cent2);
                    painter.rotate(i);
                }
                else
                {
                    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
                    painter.drawLine(p1cent2, p2cent2);
                    painter.rotate(i);
                }
            }
            else
            {
                painter.rotate(i);
            }
        }

        painter.resetTransform();
        painter.translate(cent2);
        painter.rotate(-210);
        painter.setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::FlatCap));

        if (num_lb != 0)
        {
            painter.rotate(numb_lbPovorot*2);
            QPoint p3(0,0);
            QPoint p4(radiusx, 0);
            painter.drawLine(p3,p4);
        }

    }

    if (checkedCombine)
    {
        painter.setFont(font);

        painter.drawText(p11cent2, "30");
        painter.drawText(p22cent2, "25");
        painter.drawText(p3cent2, "20");
        painter.drawText(p4cent2, "15");
        painter.drawText(p5cent2, "10");
        painter.drawText(p6cent2, "5");
        painter.drawText(p7cent2, "0");

        painter.drawText(p11, "30");
        painter.drawText(p22, "25");
        painter.drawText(p3, "20");
        painter.drawText(p4, "15");
        painter.drawText(p5, "10");
        painter.drawText(p6, "5");
        painter.drawText(p7, "0");

        painter.drawText(cent1.rx() - 15, cent1.ry() + 50, num_lbString);
        painter.drawText(cent2.rx() - 15, cent2.ry() + 50, num_lbString);

        painter.setFont(font2);
        painter.drawText(k, "°C");
        painter.drawText(kcent2, "°C");

        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
        painter.setBrush(QBrush(QColor(0, 0, 0, 0), Qt::SolidPattern));

        painter.drawEllipse(cent1, radiusx, radiusx);
        painter.drawEllipse(cent2, radiusx, radiusx);

        ///////////////////////////////////////////////////////////////////////////

        painter.translate(cent1);

        QPoint p1(radiusx-20,0);
        QPoint p2(radiusx, 0);
        int i = 10;
        for (int count = 1; count <=36; count++)
        {
            if (count <= 4 || count > 15)
            {
                if (count % 4 == 0)
                {
                    painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::FlatCap));
                    painter.drawLine(p1, p2);
                    painter.rotate(i);
                }
                else
                {
                    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
                    painter.drawLine(p1, p2);
                    painter.rotate(i);
                }
            }
            else
            {
                painter.rotate(i);
            }
        }

        painter.resetTransform();
        painter.translate(cent1);
        painter.rotate(-210);
        painter.setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::FlatCap));

        if (num_lb != 0)
        {
            painter.rotate(numb_lbPovorot*2);
            QPoint p3(0,0);
            QPoint p4(radiusx, 0);
            painter.drawLine(p3,p4);
        }
        ////////////////////////////////////////////////////////////////////////

        painter.resetTransform();
        painter.translate(cent2);

        QPoint p1cent2(radiusx-20,0);
        QPoint p2cent2(radiusx, 0);
        //int i = 10;
        for (int count = 1; count <=36; count++)
        {
            if (count <= 4 || count > 15)
            {
                if (count % 4 == 0)
                {
                    painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::FlatCap));
                    painter.drawLine(p1cent2, p2cent2);
                    painter.rotate(i);
                }
                else
                {
                    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
                    painter.drawLine(p1cent2, p2cent2);
                    painter.rotate(i);
                }
            }
            else
            {
                painter.rotate(i);
            }
        }

        painter.resetTransform();
        painter.translate(cent2);
        painter.rotate(-210);
        painter.setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::FlatCap));

        if (num_lb != 0)
        {
            painter.rotate(numb_lbPovorot*2);
            QPoint p3(0,0);
            QPoint p4(radiusx, 0);
            painter.drawLine(p3,p4);
        }
    }
}
