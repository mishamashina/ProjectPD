    #include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "serialportreader.h"
#include <QByteArray>
#include <QDebug>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Project");

    sm = new SerialPortManager("/dev/ttyACM0");
    reader = new SerialPortReader(sm->getSerialPort());
    reader->handleReadyRead();


    createActions();
    createMenus();


    connect(reader, &SerialPortReader::ChangeValue, this, &MainWindow::ChangeValue);
    connect(reader, &SerialPortReader::ChangeValue, ui->widget_2, &WidgetZX::ValueZX);
    connect(reader, &SerialPortReader::ChangeValue, ui->widget_3, &WidgetSC::ValueSC);
    connect(reader, &SerialPortReader::ChangeValue, ui->widget_4, &WidgetTerm::ValueTerm);
    connect(reader, &SerialPortReader::ValueRezv, ui->widget_5, &widgetdistRezv::distRezv);
    connect(reader, &SerialPortReader::ChangeValue, ui->widget, &WidgetAngle::ValueAngle);;
  //  connect(reader, &SerialPortReader::ValueRezv, this, &MainWindow::distRezv);

    ///////////////////////////////////////////////////////////

    connect(MinimalSpeed, &QAction::triggered, ui->widget_3, &WidgetSC::boolMinimal);
    connect(ClassicSpeed, &QAction::triggered, ui->widget_3, &WidgetSC::boolClassic);
    connect(CombineSpeed, &QAction::triggered, ui->widget_3, &WidgetSC::boolCombine);

    connect(MinimalTerm, &QAction::triggered, ui->widget_4, &WidgetTerm::boolMinimal);
    connect(ClassicTerm, &QAction::triggered, ui->widget_4, &WidgetTerm::boolClassic);
    connect(CombineTerm, &QAction::triggered, ui->widget_4, &WidgetTerm::boolCombine);
    connect(GradientTerm, &QAction::triggered, ui->widget_4, &WidgetTerm::boolGradient);

    connect(StaticDist, &QAction::triggered, ui->widget_5, &widgetdistRezv::boolStatic);
    connect(DynamicDist, &QAction::triggered, ui->widget_5, &widgetdistRezv::boolDynamic);

    ///////////////////////////////////////////////////////////

    connect(ui->widget_3, &WidgetSC::signalClassicMinimal, MinimalSpeed, &QAction::toggle);
    connect(ui->widget_3, &WidgetSC::signalClassicCombine, CombineSpeed, &QAction::toggle);
    //
    connect(ui->widget_4, &WidgetTerm::signalClassicMinimal, MinimalTerm, &QAction::toggle);
    connect(ui->widget_4, &WidgetTerm::signalClassicCombine, CombineTerm, &QAction::toggle);
    connect(ui->widget_4, &WidgetTerm::signalClassicGradient, GradientTerm, &QAction::toggle);
    /////////////////////////////////////////////////////////// Резвых Датчик расстояния

    connect(ui->widget_5, &widgetdistRezv::signalDynamicStatic, StaticDist, &QAction::toggle);
    connect(ui->widget_5, &widgetdistRezv::signalStaticDynamic, DynamicDist, &QAction::toggle);

    ///////////////////////////////////////////////////////////Резвых Датчик расстояния

    //connect(ui->widget_3, &WidgetSC::signalClassicPers, ClassicS, &QAction::setChecked);

    connect(ui->widget_3, &WidgetSC::signalMinimalClassic, ClassicSpeed, &QAction::toggle);
    connect(ui->widget_3, &WidgetSC::signalMinimalCombine, CombineSpeed, &QAction::toggle);
    //
    connect(ui->widget_4, &WidgetTerm::signalMinimalClassic, ClassicTerm, &QAction::toggle);
    connect(ui->widget_4, &WidgetTerm::signalMinimalCombine, CombineTerm, &QAction::toggle);
    connect(ui->widget_4, &WidgetTerm::signalMinimalGradient, GradientTerm, &QAction::toggle);

    //connect(ui->widget_3, &WidgetSC::signalMinimalPers, MinimalS, &QAction::setChecked);

    connect(ui->widget_3, &WidgetSC::signalCombineMinimal, MinimalSpeed, &QAction::toggle);
    connect(ui->widget_3, &WidgetSC::signalCombineClassic, ClassicSpeed, &QAction::toggle);
    //
    connect(ui->widget_4, &WidgetTerm::signalCombineMinimal, MinimalTerm, &QAction::toggle);
    connect(ui->widget_4, &WidgetTerm::signalCombineClassic, ClassicTerm, &QAction::toggle);
    connect(ui->widget_4, &WidgetTerm::signalCombineGradient, GradientTerm, &QAction::toggle);

    connect(ui->widget_4, &WidgetTerm::signalGradientMinimal, MinimalTerm, &QAction::toggle);
    connect(ui->widget_4, &WidgetTerm::signalGradientClassic, ClassicTerm, &QAction::toggle);
    connect(ui->widget_4, &WidgetTerm::signalGradientCombine, CombineTerm, &QAction::toggle);
    //connect(ui->widget_3, &WidgetSC::signalCombinePers, CombineS, &QAction::setChecked);

}

MainWindow::~MainWindow()
{
    delete ui;
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

    ///////////////////////////////////////////////////////////

    StaticDist = new QAction(tr("&Статический"), this);
    StaticDist->setStatusTip(tr("Статический дизайн"));
    StaticDist->setCheckable(true);
    StaticDist->setChecked(true);

    DynamicDist = new QAction(tr("&Динамический"), this);
    DynamicDist->setStatusTip(tr("Динамический дизайн"));
    DynamicDist->setCheckable(true);
}

void MainWindow::createMenus()
{

    Сustomization = menuBar()->addMenu(tr("&Кастомизация"));

    Speedometer = Сustomization->addMenu(tr("&Спидометр"));
    Speedometer->addAction(MinimalSpeed);
    Speedometer->addAction(ClassicSpeed);
    Speedometer->addAction(CombineSpeed);

    Termometer = Сustomization->addMenu(tr("&Термометр"));
    Termometer->addAction(MinimalTerm);
    Termometer->addAction(ClassicTerm);
    Termometer->addAction(CombineTerm);
    Termometer->addAction(GradientTerm);

    DistSensor = Сustomization->addMenu(tr("&Парктроник"));
    DistSensor->addAction(StaticDist);
    DistSensor->addAction(DynamicDist);
}

void MainWindow::ChangeValue(int value)
{
    //ui->label_7->setNum(value);
}

