#include "serialportreader.h"
#include <QCoreApplication>
#include <QDebug>


SerialPortReader::SerialPortReader(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPortReader::handleReadyRead);//когда что-то приходит на порт мы читаем
}

void SerialPortReader::handleReadyRead()
{

    m_readData.clear();
    m_readData.append(m_serialPort->readAll());
    qDebug() << m_readData;

    if(m_readData.contains('\n')) m_readData.remove(m_readData.indexOf('\n'), 1);
    if(m_readData.contains('\r')) m_readData.remove(m_readData.indexOf('\r'), 1);
    if(m_readData.length() == 0) return;
    QString ID;
    QString value;
    if(m_readData.contains(' ')){
        ID = m_readData.split(' ')[0];
        value = m_readData.split(' ')[1];
    } else {
        ID = "all";
        value = m_readData;
    }
    //qDebug() << "!!! " << ID << " " << value << " " << value.toDouble();
    emit portOut(ID, value);
};
