#ifndef WIDGETST_H
#define WIDGETST_H

#include <QWidget>
#include <QPainter>

class WidgetST : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetST(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

};

#endif // WIDGETST_H
