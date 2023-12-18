#pragma once

#include <QWidget>

class WidgetTurn : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetTurn(QWidget *parent = nullptr, bool isRight=true);
    bool isRight;
    bool isOn;
    bool blinkFlag;
signals:

public slots:
    void switchState();
    void paintEvent(QPaintEvent *) override;
    void blinkSlot();
    void switchDirection();
};
