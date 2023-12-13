#pragma once

#include <QObject>
#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>


class SerialPortReader : public QObject
{
    Q_OBJECT

public:
    explicit SerialPortReader(QSerialPort *serialPort, QObject *parent = nullptr);
    QSerialPort *m_serialPort = nullptr;
    QByteArray m_readData;

signals:
    void portOut(QString ID, QString value);

public slots:
    void handleReadyRead();
};
