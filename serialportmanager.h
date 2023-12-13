#pragma once

#include <QSerialPort>
#include <QSerialPortInfo>


class SerialPortManager
{
public:
    SerialPortManager();
    ~SerialPortManager();

    QSerialPort *serialPortInit(QString portName,
                        qint32 baud = QSerialPort::Baud115200,
                        QSerialPort::DataBits bits = QSerialPort::Data8,
                        QSerialPort::StopBits sbits = QSerialPort::OneStop,
                        QSerialPort::Parity parity = QSerialPort::NoParity,
                        QSerialPort::FlowControl flow = QSerialPort::NoFlowControl);
    QList<QSerialPort*> getSerialPorts() const;

private:
    QList<QSerialPort*> serialPorts;
};
