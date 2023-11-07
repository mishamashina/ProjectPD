#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H


#include <QObject>
#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class SerialPortReader : public QObject
{
    Q_OBJECT

public:
    explicit SerialPortReader(QSerialPort *serialPort, QObject *parent = nullptr);
    QSerialPort *m_serialPort = nullptr;
    QByteArray m_readData;

signals:

    void ChangeValue(int value);

public slots:
    void handleReadyRead();
};

#endif // SERIALPORTREADER_H
