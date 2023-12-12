#include "mainwindow.h"
#include <QtWidgets>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
    setWindowTitle("Project");

    sm = new SerialPortManager("/dev/ttyACM0");
    reader = new SerialPortReader(sm->getSerialPort());
    reader->handleReadyRead();

    //widgetsInit();

    QWidget *w = new QWidget(this);
    QGridLayout *layout = new QGridLayout();

    this->setCentralWidget(w);
    widget = new WidgetAngle(w);		// поворот колес
    widget_2 = new WidgetZX(w);			// запас хода
    widget_3 = new WidgetSC(w);			// спидометр
    widget_4 = new WidgetTerm(w);		// температура
    widget_5 = new widgetdistRezv(w);	// парктроник
    widget_6 = new WidgetMap(w);		// карта

    layout->addWidget(widget , 2 , 3 , 1 , 1);
    layout->addWidget(widget_2 , 1 , 2 , 1 , 1);
    layout->addWidget(widget_3 , 1 , 1 , 1 , 1);
    layout->addWidget(widget_4 , 2 , 1 , 1 , 2);
    layout->addWidget(widget_5 , 1 , 3 , 1 , 1);
    layout->addWidget(widget_6 , 1 , 4 , 2 , 2);

    w->setLayout(layout);

    /*
    sm = new SerialPortManager();
    for(auto port : sm->getSerialPorts()){
        readers.append(new SerialPortReader(port));
        connect(readers.last(), SIGNAL(portOut(QString, QString)), this, SLOT(dataRedist(QString, QString))); // слот перекидывающий данные в соответствующий виджет
    }
    */

    createActions();
    createMenus();


    connect(reader, &SerialPortReader::ChangeValue, this, &MainWindow::ChangeValue);
    connect(reader, &SerialPortReader::ChangeValue, widget_2, &WidgetZX::ValueZX);
    connect(reader, &SerialPortReader::ChangeValue, widget_3, &WidgetSC::ValueSC);
    connect(reader, &SerialPortReader::ChangeValue, widget_4, &WidgetTerm::ValueTerm);
    connect(reader, &SerialPortReader::ValueRezv, widget_5, &widgetdistRezv::distRezv);
    connect(reader, &SerialPortReader::ChangeValue, widget, &WidgetAngle::ValueAngle);

  //  connect(reader, &SerialPortReader::ValueRezv, this, &MainWindow::distRezv);

    ///////////////////////////////////////////////////////////

    connect(MinimalSpeed, &QAction::triggered, widget_3, &WidgetSC::boolMinimal);
    connect(ClassicSpeed, &QAction::triggered, widget_3, &WidgetSC::boolClassic);
    connect(CombineSpeed, &QAction::triggered, widget_3, &WidgetSC::boolCombine);

    connect(MinimalTerm, &QAction::triggered, widget_4, &WidgetTerm::boolMinimal);
    connect(ClassicTerm, &QAction::triggered, widget_4, &WidgetTerm::boolClassic);
    connect(CombineTerm, &QAction::triggered, widget_4, &WidgetTerm::boolCombine);
    connect(GradientTerm, &QAction::triggered, widget_4, &WidgetTerm::boolGradient);

    ///////////////////////////////////////////////////////////

    connect(widget_3, &WidgetSC::signalClassicMinimal, MinimalSpeed, &QAction::toggle);
    connect(widget_3, &WidgetSC::signalClassicCombine, CombineSpeed, &QAction::toggle);
    //
    connect(widget_4, &WidgetTerm::signalClassicMinimal, MinimalTerm, &QAction::toggle);
    connect(widget_4, &WidgetTerm::signalClassicCombine, CombineTerm, &QAction::toggle);
    connect(widget_4, &WidgetTerm::signalClassicGradient, GradientTerm, &QAction::toggle);


    //connect(ui->widget_3, &WidgetSC::signalClassicPers, ClassicS, &QAction::setChecked);

    connect(widget_3, &WidgetSC::signalMinimalClassic, ClassicSpeed, &QAction::toggle);
    connect(widget_3, &WidgetSC::signalMinimalCombine, CombineSpeed, &QAction::toggle);
    //
    connect(widget_4, &WidgetTerm::signalMinimalClassic, ClassicTerm, &QAction::toggle);
    connect(widget_4, &WidgetTerm::signalMinimalCombine, CombineTerm, &QAction::toggle);
    connect(widget_4, &WidgetTerm::signalMinimalGradient, GradientTerm, &QAction::toggle);

    //connect(ui->widget_3, &WidgetSC::signalMinimalPers, MinimalS, &QAction::setChecked);

    connect(widget_3, &WidgetSC::signalCombineMinimal, MinimalSpeed, &QAction::toggle);
    connect(widget_3, &WidgetSC::signalCombineClassic, ClassicSpeed, &QAction::toggle);
    //
    connect(widget_4, &WidgetTerm::signalCombineMinimal, MinimalTerm, &QAction::toggle);
    connect(widget_4, &WidgetTerm::signalCombineClassic, ClassicTerm, &QAction::toggle);
    connect(widget_4, &WidgetTerm::signalCombineGradient, GradientTerm, &QAction::toggle);

    connect(widget_4, &WidgetTerm::signalGradientMinimal, MinimalTerm, &QAction::toggle);
    connect(widget_4, &WidgetTerm::signalGradientClassic, ClassicTerm, &QAction::toggle);
    connect(widget_4, &WidgetTerm::signalGradientCombine, CombineTerm, &QAction::toggle);
    //connect(ui->widget_3, &WidgetSC::signalCombinePers, CombineS, &QAction::setChecked);

}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    MinimalSpeed = new QAction(tr("&Минималистический"), this);
    MinimalSpeed->setStatusTip(tr("Минималистический дизайн"));
    MinimalSpeed->setCheckable(true);
    //MinimalSpeed->setChecked(true);

    ClassicSpeed = new QAction(tr("&Классический"), this);
    ClassicSpeed->setStatusTip(tr("Классический дизайн"));
    ClassicSpeed->setCheckable(true);
    ClassicSpeed->setChecked(true);

    CombineSpeed = new QAction(tr("&Комбинированный"), this);
    CombineSpeed->setStatusTip(tr("Комбинированный дизайн"));
    CombineSpeed->setCheckable(true);

    ///////////////////////////////////////////////////////////

    MinimalTerm = new QAction(tr("&Минималистический"), this);
    MinimalTerm->setStatusTip(tr("Минималистический дизайн"));
    MinimalTerm->setCheckable(true);

    ClassicTerm = new QAction(tr("&Классический"), this);
    ClassicTerm->setStatusTip(tr("Классический дизайн"));
    ClassicTerm->setCheckable(true);
    ClassicTerm->setChecked(true);

    CombineTerm = new QAction(tr("&Комбинированный"), this);
    CombineTerm->setStatusTip(tr("Комбинированный дизайн"));
    CombineTerm->setCheckable(true);

    GradientTerm = new QAction(tr("&Градиентный"), this);
    GradientTerm->setStatusTip(tr("Градиентный дизайн"));
    GradientTerm->setCheckable(true);
}

void MainWindow::createMenus()
{

    Customization = menuBar()->addMenu(tr("&Кастомизация"));

    Speedometer = Customization->addMenu(tr("&Спидометр"));
    Speedometer->addAction(MinimalSpeed);
    Speedometer->addAction(ClassicSpeed);
    Speedometer->addAction(CombineSpeed);

    Termometer = Customization->addMenu(tr("&Термометр"));
    Termometer->addAction(MinimalTerm);
    Termometer->addAction(ClassicTerm);
    Termometer->addAction(CombineTerm);
    Termometer->addAction(GradientTerm);

}

void MainWindow::ChangeValue(int value)
{
    //ui->label_7->setNum(value);
}

