#pragma once

#include <QWidget>
#include <QPainter>
#include <QDebug>

class WidgetZX : public QWidget
{
    Q_OBJECT
public:
    int num_lb7;
    explicit WidgetZX(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int max_second_datch;
    int first_datch;
    int value_first_datch;
    int second_datch;
    int max_third_datch;
    int value_third_datch;
    QString string_value_first;
    QString string_value_second;
    QString string_value_third;
public slots:
    void ValueZX(int value);

};

