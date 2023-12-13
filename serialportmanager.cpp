#include "serialportmanager.h"
#include <QDebug>

SerialPortManager::SerialPortManager()
{
    portsInterrogate();
    /*QTimer *timer = new QTimer(this);		// это должен был быть опрос датчиков по таймеру [может как-нибудь потом]
    timer->setInterval(20000);
    connect(timer, &QTimer::timeout, this, &SerialPortManager::portsInterrogate);
    timer->start();*/
}

void SerialPortManager::portsInterrogate(){
    /*QList<QSerialPortInfo> portsInfo = QSerialPortInfo::availablePorts();
    for(auto initPortName : portsToInit){
        QSerialPort *t = serialPortInit(initPortName);
        if(t != nullptr) serialPorts.append(t);
    }
    portsToInit.clear();
    for(auto portInfo : portsInfo){
        bool isBusy = false;
        for(auto initializedPort : serialPorts){
            if(initializedPort->portName() == portInfo.portName()) isBusy = true;
        }
        if(!isBusy){
            portsToInit.append(portInfo.portName());
        }
    }*/
    QList<QSerialPortInfo> portsInfo = QSerialPortInfo::availablePorts();
    for(auto portInfo : portsInfo){
        bool isBusy = false;
        for(auto initializedPort : serialPorts){
            if(initializedPort->portName() == portInfo.portName()) isBusy = true;
        }
        if(!isBusy){
            QSerialPort *t = serialPortInit(portInfo.portName());
            if(t != nullptr) serialPorts.append(t);
        }
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

    bool result = portToInit->open(QIODevice::ReadWrite);

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
