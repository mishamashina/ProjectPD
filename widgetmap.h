#ifndef WIDGETMAP_H
#define WIDGETMAP_H

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

    void initImage(QImage myImage);

signals:

};

#endif // WIDGETMAP_H
