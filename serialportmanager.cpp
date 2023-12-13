#include "serialportmanager.h"
#include <QDebug>

SerialPortManager::SerialPortManager()
{
    QList<QSerialPortInfo> portsInfo = QSerialPortInfo::availablePorts();
    for(auto portInfo : portsInfo){
        QSerialPort *t = serialPortInit(portInfo.portName());
        if(t != nullptr) serialPorts.append(t);
    }
}

QSerialPort *SerialPortManager::serialPortInit(QString portName,
                            qint32 baud ,
                            QSerialPort::DataBits bits ,
                            QSerialPort::StopBits sbits ,
                            QSerialPort::Parity parity ,
                            QSerialPort::FlowControl flow){
    QSerialPort *portToInit = new QSerialPort();

    portToInit ->setPortName(portName);
    portToInit ->setBaudRate(baud);
    portToInit ->setDataBits(bits);
    portToInit ->setStopBits(sbits);
    portToInit ->setParity(parity);
    portToInit ->setFlowControl(flow);

    bool result = portToInit->open(QIODevice::ReadOnly);

    if (!result) {
        qDebug() << "Failed to open port: " << portToInit->portName() << ", error: " << portToInit->errorString();
        return nullptr;
    } else {
        qDebug() << "Connected to " << portToInit->portName();
        return portToInit;
    }
}

SerialPortManager::~SerialPortManager()
{
    for(auto port : getSerialPorts()) {
        port->close();
    }
}

QList<QSerialPort*> SerialPortManager::getSerialPorts() const
{
    return this->serialPorts;
}
