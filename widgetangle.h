#ifndef WIDGETANGLE_H
#define WIDGETANGLE_H

#include <QWidget>
#include <QPainter>

class WidgetAngle : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetAngle(QWidget *parent = nullptr);

    int  angle;

    void paintEvent(QPaintEvent *event);
    WidgetAngle *widget;
signals:

public slots:
    void ValueAngle(int value);

};

#endif // WIDGETANGLE_H
