#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include "widgetst.h"

int main(int argc, char *argv[])
{
    QApplication coreApplication(argc, argv);
    MainWindow w;

    WidgetST wid;
    wid.update();

    w.show();

    return coreApplication.exec();
}
