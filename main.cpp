#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication coreApplication(argc, argv);
    MainWindow w;
    w.show();

    return coreApplication.exec();
}
