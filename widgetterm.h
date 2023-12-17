#pragma once

#include <QWidget>
#include <QPainter>
#include <QDebug>

class WidgetTerm: public QWidget
{
    Q_OBJECT
public:
    explicit WidgetTerm(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int num_lb;
    QString num_lbString;
    int numb_lbPovorot;
    int i = 10;
    int radiusx = 140;
    QString num_lbPovorotString;

    bool checkedMinimal;
    bool checkedClassic;
    bool checkedCombine;
    bool checkedGradient;

public slots:
    void ValueTerm(int value);
    void boolMinimal(bool checked);
    void boolClassic(bool checked);
    void boolCombine(bool checked);
    void boolGradient(bool checed);

signals:
    void signalMinimalClassic();
    void signalMinimalCombine();
    void signalMinimalGradient();

    void signalClassicMinimal();
    void signalClassicCombine();
    void signalClassicGradient();

    void signalCombineClassic();
    void signalCombineMinimal();
    void signalCombineGradient();

    void signalGradientClassic();
    void signalGradientMinimal();
    void signalGradientCombine();
};
