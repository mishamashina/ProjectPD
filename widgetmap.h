#pragma once

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>

class WidgetMap : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetMap(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    QImage myImage;

    int countMinus = 0;
    int countPlus = 0;
    float scaleMinus = 0.03;
    float scaleMinusAll;
    float scalePlus = 0.03;
    float scalePlusAll;
    //int count = 0;
    float teky = 1;

    int countUp = 0;
    int countDown = 0;
    int countRight = 0;
    int countLeft = 0;

    bool checkedMinus = false;
    bool checkedPlus = false;
    bool checkedUp = false;
    bool checkedDown = false;
    bool checkedRight = false;
    bool checkedLeft = false;


signals:

};
