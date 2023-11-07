#include "serialportmanager.h"
#include <QDebug>

SerialPortManager::SerialPortManager(QString portName,
                                     qint32 baud,
                                     QSerialPort::DataBits bits,
                                     QSerialPort::StopBits sbits,
                                     QSerialPort::Parity parity,
                                     QSerialPort::FlowControl flow)
{
    this->serialPort = new QSerialPort();

    this->portName = portName;

    this->serialPort->setPortName(portName);
    this->serialPort->setBaudRate(baud);
    this->serialPort->setDataBits(bits);
    this->serialPort->setStopBits(sbits);
    this->serialPort->setParity(parity);
    this->serialPort->setFlowControl(flow);

    bool result = this->serialPort->open(QIODevice::ReadOnly);

    if (!result) {
        qDebug() << "Failed to open port: " << this->portName << ", error: " << this->serialPort->errorString();
    } else {
        qDebug() << "Connected to " << this->portName;
    }


}

SerialPortManager::~SerialPortManager()
{
    this->serialPort->close();
}

QSerialPort *SerialPortManager::getSerialPort() const
{
    return this->serialPort;
}
