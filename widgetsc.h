#pragma once

#include <QWidget>
#include <QPainter>
#include <QDebug>

class WidgetSC : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetSC(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int num_lb13;
    QString num_lb13string;
    int i = 10;
    int radiusx = 200;

    bool checkedMinimal;
    bool checkedClassic;
    bool checkedCombine;

public slots:
    void ValueSC(int value);
    void boolMinimal(bool checked);
    void boolClassic(bool checked);
    void boolCombine(bool checked);

signals:
    void signalMinimalClassic();
    void signalMinimalCombine();
    void signalClassicMinimal();
    void signalClassicCombine();
    void signalCombineClassic();
    void signalCombineMinimal();

};
