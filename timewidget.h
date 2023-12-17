#pragma once

#include <QWidget>

class TimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimeWidget(QWidget *parent = nullptr);
    bool getDateFlag();
    void setDateFlag(bool);
    bool dateFlag;

signals:

public slots:
    void paintEvent(QPaintEvent *) override;
};
