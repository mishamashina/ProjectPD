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
    //qDebug() << "Зашло boolMinimal";
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
    //qDebug() << "Зашел boolClassic";

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
    //qDebug() << "Зашло boolCombine";
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
    //qDebug() << "Зашло boolGradient";
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

    //qDebug() << "checkedMinimal TERM" << checkedMinimal;
    //qDebug() << "checkedClassic TERM" << checkedClassic;
    //qDebug() << "checkedCombine TERM" << checkedCombine;
    //qDebug() << "checkedGradient TERM" << checkedGradient;

    QFont font("Ubuntu", 15, QFont::Bold);
    QFont font2("Ubuntu", 15);
    QFont font3("Ubuntu", 25, QFont::Bold);

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
        QSizeF size(70, 280);
        QPointF pointf1(cent1.rx() - 35, cent1.ry() - 140);
        QRectF rectf1(pointf1, size);

        QPointF pointf2(cent2.rx() - 35, cent2.ry() - 140);
        QRectF rectf2(pointf2, size);

        //qDebug() << rectf1.center();
        //qDebug() << rectf2.center();


        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap));

        if (num_lb < 10)
        {
            QLinearGradient linearGrad(QPointF(210, 185+140), QPointF(210, 185+140 - num_lb*9.3));
            QLinearGradient linearGrad1(QPointF(560, 185+140), QPointF(560, 185+140 - num_lb*9.3));

            linearGrad.setColorAt(0, Qt::green);
            linearGrad.setColorAt(1, QColor(0, 0, 0, 0));

            linearGrad1.setColorAt(0, Qt::green);
            linearGrad1.setColorAt(1, QColor(0, 0, 0, 0));

            painter.setBrush(linearGrad);
            painter.drawRoundedRect(rectf1, 10, 10);

            painter.setBrush(linearGrad1);
            painter.drawRoundedRect(rectf2, 10, 10);
        }
        else if(num_lb < 20)
        {
            QLinearGradient linearGrad(QPointF(210, 185+140), QPointF(210, 185+140 - num_lb*9.3));
            QLinearGradient linearGrad1(QPointF(560, 185+140), QPointF(560, 185+140 - num_lb*9.3));

            linearGrad.setColorAt(0, Qt::yellow);
            linearGrad.setColorAt(1, QColor(0, 0, 0, 0));

            linearGrad1.setColorAt(0, Qt::yellow);
            linearGrad1.setColorAt(1, QColor(0, 0, 0, 0));

            painter.setBrush(linearGrad);
            painter.drawRoundedRect(rectf1, 10, 10);

            painter.setBrush(linearGrad1);
            painter.drawRoundedRect(rectf2, 10, 10);
        }
        else
        {
            QLinearGradient linearGrad(QPointF(210, 185+140), QPointF(210, 185+140 - num_lb*9.3));
            QLinearGradient linearGrad1(QPointF(560, 185+140), QPointF(560, 185+140 - num_lb*9.3));

            linearGrad.setColorAt(0, Qt::red);
            linearGrad.setColorAt(1, QColor(0, 0, 0, 0));

            linearGrad1.setColorAt(0, Qt::red);
            linearGrad1.setColorAt(1, QColor(0, 0, 0, 0));

            painter.setBrush(linearGrad);
            painter.drawRoundedRect(rectf1, 10, 10);

            painter.setBrush(linearGrad1);
            painter.drawRoundedRect(rectf2, 10, 10);
        }

        painter.setFont(font3);

        if (num_lb < 10)
        {
            painter.drawText(QPointF(200, 185+180), num_lbString);
            painter.drawText(QPointF(550, 185+180), num_lbString);
        }

        else
        {
            painter.drawText(QPointF(190, 185+180), num_lbString);
            painter.drawText(QPointF(540, 185+180), num_lbString);
        }

        painter.setFont(font2);
        painter.drawText(QPointF(235, 185+180), "°C");
        painter.drawText(QPointF(585, 185+180), "°C");

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

        painter.setFont(font3);
        painter.setPen(Qt::red);
        if (num_lb < 10)
        {
            painter.drawText(cent1.rx() - 10, cent1.ry(), num_lbString);
            painter.drawText(cent2.rx() - 10, cent2.ry(), num_lbString);
        }
        else
        {
            painter.drawText(cent1.rx() - 20, cent1.ry(), num_lbString);
            painter.drawText(cent2.rx() - 20, cent2.ry(), num_lbString);
        }
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
            QPoint p4(radiusx - 10, 0);
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
            QPoint p4(radiusx - 10, 0);
            painter.drawLine(p3,p4);
        }

        painter.resetTransform();
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
        painter.drawEllipse(cent1, 5, 5);
        painter.drawEllipse(cent2, 5, 5);
    }

    if (checkedCombine)
    {
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
        painter.drawEllipse(cent1, 5, 5);
        painter.drawEllipse(cent2, 5, 5);
        painter.setPen(Qt::black);

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

        painter.setFont(font3);
        painter.setPen(QPen(Qt::red));

        if (num_lb < 10)
        {
            painter.drawText(cent1.rx() - 5, cent1.ry() + 50, num_lbString);
            painter.drawText(cent2.rx() - 5, cent2.ry() + 50, num_lbString);
        }
        else
        {
            painter.drawText(cent1.rx() - 15, cent1.ry() + 50, num_lbString);
            painter.drawText(cent2.rx() - 15, cent2.ry() + 50, num_lbString);
        }

        painter.setPen(QPen(Qt::black));
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
            QPoint p4(radiusx - 10, 0);
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
            QPoint p4(radiusx - 10, 0);
            painter.drawLine(p3,p4);
        }

        painter.resetTransform();
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
        painter.drawEllipse(cent1, 5, 5);
        painter.drawEllipse(cent2, 5, 5);
    }
}
