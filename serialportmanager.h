
#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include <QSerialPort>


class SerialPortManager
{
public:
    SerialPortManager(QString portName,
                        qint32 baud = QSerialPort::Baud115200,
                        QSerialPort::DataBits bits = QSerialPort::Data8,
                        QSerialPort::StopBits sbits = QSerialPort::OneStop,
                        QSerialPort::Parity parity = QSerialPort::NoParity,
                        QSerialPort::FlowControl flow = QSerialPort::NoFlowControl);
    ~SerialPortManager();

    QSerialPort *getSerialPort() const;

private:
    QSerialPort *serialPort;
    QString portName;
};

#endif // SERIALPORTMANAGER_H
