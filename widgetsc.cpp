#include "widgetsc.h"
//#include "mainwindow.h"

WidgetSC::WidgetSC(QWidget *parent)
    : QWidget{parent}
{
    checkedMinimal = true;
    checkedClassic = false;
    checkedCombine = false;
}

void WidgetSC::ValueSC(int value)
{
    num_lb13 = value;
    num_lb13string = QString::number(num_lb13);
    update();
}

void WidgetSC::boolMinimal(bool checked)
{
    qDebug() << "Зашло boolMinimal";
    checkedMinimal = checked;
    if (checkedClassic == true){emit signalMinimalClassic();}
    if (checkedCombine == true){emit signalMinimalCombine();}

    checkedClassic = false;
    checkedCombine = false;
    update();
}

void WidgetSC::boolClassic(bool checked)
{
    qDebug() << "Зашел boolClassic";

    checkedClassic = checked;
    if (checkedMinimal == true){emit signalClassicMinimal();}
    if (checkedCombine == true){emit signalClassicCombine();}
    checkedMinimal = false;
    checkedCombine = false;

    update();
}

void WidgetSC::boolCombine(bool checked)
{
    qDebug() << "Зашло boolCombine";
    checkedCombine = checked;
    if (checkedMinimal == true){emit signalCombineMinimal();}
    if (checkedClassic== true){emit signalCombineClassic();}
    checkedMinimal = false;
    checkedClassic = false;
    update();
}

void WidgetSC::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QRect r(0,0, this->width(), this->height());
    QPoint cent = r.center();

    qDebug() << "checkedMinimal SPEED" << checkedMinimal;
    qDebug() << "checkedClassic SPEED" << checkedClassic;
    qDebug() << "checkedCombine SPEED" << checkedCombine;

    if (checkedMinimal)
    {
        QFont font("Ubuntu", 20, QFont::Bold);
        QFont font2("Ubuntu", 40, QFont::Bold);
        painter.setFont(font);

        QPoint km(180,320);
        QPoint c1(cent.rx()- 30, cent.ry()- 30);
        painter.setFont(font);
        painter.drawText(km, "км/ч");

        painter.setFont(font2);

        painter.drawText(c1, num_lb13string);

        painter.drawRect(painter.viewport());

        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
        painter.setBrush(QBrush(QColor(0, 0, 0, 0), Qt::SolidPattern));

        painter.drawEllipse(cent, radiusx, radiusx);
    }

    if (checkedClassic)
    {
        QFont font("Ubuntu", 30, QFont::Bold);
        QFont font2("Ubuntu", 20, QFont::Bold);
        painter.setFont(font);

        QPoint p11(280,320); //120 // 280,280
        QPoint p22(310,170+40);
        QPoint p3(290, 90+40);
        QPoint p4(190, 40+40);
        QPoint p5(80, 90+40);
        QPoint p6(50, 170+40);
        QPoint p7(70, 280+40); // 0
        QPoint k(180,320);

        painter.drawText(p11, "120");
        painter.drawText(p22, "100");
        painter.drawText(p3, "80");
        painter.drawText(p4, "60");
        painter.drawText(p5, "40");
        painter.drawText(p6, "20");
        painter.drawText(p7, "0");

        painter.setFont(font2);

        painter.drawText(k, "км/ч");


        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
        painter.setBrush(QBrush(QColor(0, 0, 0, 0), Qt::SolidPattern));

        painter.drawRect(r);
        painter.drawEllipse(cent, radiusx, radiusx);

        painter.translate(cent);

        QPoint p1(radiusx-20,0);
        QPoint p2(radiusx, 0);
        int i = 10;
        for (int count = 1; count <=36; count++)
        {
            if (count <= 4 || count > 15)
            {
                if (count % 4 == 0)
                {
                    painter.setPen(QPen(Qt::black, 7, Qt::SolidLine, Qt::FlatCap));
                    painter.drawLine(p1, p2);
                    painter.rotate(i);
                }
                else
                {
                    painter.setPen(QPen(Qt::black, 4, Qt::SolidLine, Qt::FlatCap));
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
        painter.translate(cent);
        painter.rotate(-210);
        painter.setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::FlatCap));

        if (num_lb13 != 0)
        {
            painter.rotate(num_lb13*2);
            QPoint p3(0,0);
            QPoint p4(radiusx, 0);
            painter.drawLine(p3,p4);
        }
    }

    if (checkedCombine)
    {
        QFont font("Ubuntu", 30, QFont::Bold);
        QFont font2("Ubuntu", 20, QFont::Bold);
        painter.setFont(font);

        QPoint p11(280,320); //120 // 280,280
        QPoint p22(310,170+40);
        QPoint p3(290, 90+40);
        QPoint p4(190, 40+40);
        QPoint p5(80, 90+40);
        QPoint p6(50, 170+40);
        QPoint p7(70, 280+40); // 0
        QPoint k(180,320);
        QPoint c2(cent.rx()-20, cent.ry()+60);


        painter.drawText(p11, "120");
        painter.drawText(p22, "100");
        painter.drawText(p3, "80");
        painter.drawText(p4, "60");
        painter.drawText(p5, "40");
        painter.drawText(p6, "20");
        painter.drawText(p7, "0");

        painter.drawText(c2, num_lb13string);
        //painter.drawText(c2, "num_lb13string");

        painter.setFont(font2);

        painter.drawText(k, "км/ч");


        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));
        painter.setBrush(QBrush(QColor(0, 0, 0, 0), Qt::SolidPattern));

        painter.drawRect(r);
        painter.drawEllipse(cent, radiusx, radiusx);

        painter.translate(cent);

        QPoint p1(radiusx-20,0);
        QPoint p2(radiusx, 0);
        int i = 10;
        for (int count = 1; count <=36; count++)
        {
            if (count <= 4 || count > 15)
            {
                if (count % 4 == 0)
                {
                    painter.setPen(QPen(Qt::black, 7, Qt::SolidLine, Qt::FlatCap));
                    painter.drawLine(p1, p2);
                    painter.rotate(i);
                }
                else
                {
                    painter.setPen(QPen(Qt::black, 4, Qt::SolidLine, Qt::FlatCap));
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
        painter.translate(cent);
        painter.rotate(-210);
        painter.setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::FlatCap));

        if (num_lb13 != 0)
        {
            painter.rotate(num_lb13*2);
            QPoint p3(0,0);
            QPoint p4(radiusx, 0);
            painter.drawLine(p3,p4);
        }
    }
}
