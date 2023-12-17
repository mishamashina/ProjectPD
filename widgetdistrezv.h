#pragma once

#include <QWidget>
#include <QPainter>
#include <QDebug>

class widgetdistRezv : public QWidget
{
    Q_OBJECT
public:
    widgetdistRezv(QWidget *parent = nullptr);
    int value;
    int  ColorPick1;
    QString  ColorPick1string;
    int  ColorPick2;
    QString  ColorPick2string;
    int  ColorPick3;
    QString  ColorPick3string;
    int  ColorPick4;
    QString  ColorPick4string;
    int  ColorPick5;
    QString  ColorPick5string;
    int  ColorPick6;
    QString  ColorPick6string;
    int  ColorPick7;
    QString  ColorPick7string;
    int  ColorPick8;
    QString  ColorPick8string;
    void paintEvent(QPaintEvent *event);
    bool checkedStatic;
    bool checkedDynamic;

public slots:
    void distRezv(QByteArray m_readData);
    void boolStatic(bool checked);
    void boolDynamic(bool checked);

signals:
    void signalDynamicStatic();
    void signalStaticDynamic();
};
