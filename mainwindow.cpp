#include "mainwindow.h"
#include <QtWidgets>
#include <iostream>
#include <QSizePolicy>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
    setWindowTitle("Project");
    this->resize(1650, 950);

    tabs = new QTabWidget(this);
    this->setCentralWidget(tabs);
    tabs->setTabsClosable(false);

    mainPanelTab();
    navigationTab();
    infoTab();
    testTab();

    comReaderInit();
    createActions();
    createMenus();
    customizationLogic();
}

MainWindow::~MainWindow()
{
}

void MainWindow::mainPanelTab(){
    QWidget *w = new QWidget(tabs);
    tabs->addTab(w, "main panel");

    menuBar = new QMenuBar(w);
    menuBar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    QVBoxLayout *layoutM = new QVBoxLayout();

    QGridLayout *layout = new QGridLayout();

    widget = new WidgetAngle(w);		// поворот колес
    widget_2 = new WidgetZX(w);			// запас хода
    widget_3 = new WidgetSC(w);			// спидометр
    widget_4 = new WidgetTerm(w);		// температура
    widget_5 = new widgetdistRezv(w);	// парктроник
    widget_7 = new TimeWidget(w);		// время

    layout->addWidget(widget , 2 , 3 , 1 , 1);
    layout->addWidget(widget_2 , 1 , 2 , 1 , 1);
    layout->addWidget(widget_3 , 1 , 1 , 1 , 1);
    layout->addWidget(widget_4 , 2 , 1 , 1 , 2);
    layout->addWidget(widget_5 , 1 , 3 , 1 , 1);
    layout->addWidget(widget_7 , 1 , 4 , 1 , 1);

    layoutM->addWidget(menuBar);
    layoutM->addLayout(layout);
    w->setLayout(layoutM);
}

void MainWindow::navigationTab(){
    QWidget *w = new QWidget(tabs);
    tabs->addTab(w, "navigation");

    QGridLayout *layout = new QGridLayout();

    widget_6 = new WidgetMap(w);		// карта

    layout->addWidget(widget_6, 1 , 1 , 1 , 1);

    w->setLayout(layout);
}

void MainWindow::infoTab(){
    QWidget *w = new QWidget(tabs);
    tabs->addTab(w, "info");

    QGridLayout *layout = new QGridLayout();

    QLabel *info = new QLabel("some information", w);

    layout->addWidget(info);

    w->setLayout(layout);
}

void MainWindow::testTab(){
    QWidget *w = new QWidget(tabs);
    tabs->addTab(w, "test");


    QGridLayout *layout = new QGridLayout();
    QLabel *info = new QLabel("here may be some widgets to test", w);

    WidgetTurn *testW = new WidgetTurn(w , false);
    QPushButton *sw = new QPushButton("switch\nstate", w);
    QPushButton *sd = new QPushButton("switch\ndirection", w);
    layout->addWidget(info , 1 , 1 , 1 , 1);
    layout->addWidget(testW , 2 , 1 , 1 , 2);
    layout->addWidget(sw , 3 , 1 , 1 , 1);
    layout->addWidget(sd , 3 , 2 , 1 , 1);

    connect(sw, SIGNAL(clicked(bool)), testW, SLOT(switchState()));
    connect(sd, SIGNAL(clicked(bool)), testW, SLOT(switchDirection()));

    w->setLayout(layout);
}

void MainWindow::comReaderInit(){
    sm = new SerialPortManager();
    for(auto port : sm->getSerialPorts()){
        readers.append(new SerialPortReader(port));
        connect(readers.last(), SIGNAL(portOut(QString, QString)), this, SLOT(dataRedist(QString, QString))); // слот перекидывающий данные в соответствующий виджет
    }
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

    Customization = menuBar->addMenu(tr("&Кастомизация"));

    Speedometer = Customization->addMenu(tr("&Спидометр"));
    Speedometer->addAction(MinimalSpeed);
    Speedometer->addAction(ClassicSpeed);
    Speedometer->addAction(CombineSpeed);

    Termometer = Customization->addMenu(tr("&Термометр"));
    Termometer->addAction(MinimalTerm);
    Termometer->addAction(ClassicTerm);
    Termometer->addAction(CombineTerm);
    Termometer->addAction(GradientTerm);

    DistSensor = Customization->addMenu(tr("&Парктроник"));
    DistSensor->addAction(StaticDist);
    DistSensor->addAction(DynamicDist);
}

void MainWindow::customizationLogic(){
    ///////////////////////////////////////////////////////////

    connect(MinimalSpeed, &QAction::triggered, widget_3, &WidgetSC::boolMinimal);
    connect(ClassicSpeed, &QAction::triggered, widget_3, &WidgetSC::boolClassic);
    connect(CombineSpeed, &QAction::triggered, widget_3, &WidgetSC::boolCombine);

    connect(MinimalTerm, &QAction::triggered, widget_4, &WidgetTerm::boolMinimal);
    connect(ClassicTerm, &QAction::triggered, widget_4, &WidgetTerm::boolClassic);
    connect(CombineTerm, &QAction::triggered, widget_4, &WidgetTerm::boolCombine);
    connect(GradientTerm, &QAction::triggered, widget_4, &WidgetTerm::boolGradient);

    connect(StaticDist, &QAction::triggered, widget_5, &widgetdistRezv::boolStatic);
    connect(DynamicDist, &QAction::triggered, widget_5, &widgetdistRezv::boolDynamic);

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

    /////////////////////////////////////////////////////////// Резвых Датчик расстояния

    connect(widget_5, &widgetdistRezv::signalDynamicStatic, StaticDist, &QAction::toggle);
    connect(widget_5, &widgetdistRezv::signalStaticDynamic, DynamicDist, &QAction::toggle);

    ///////////////////////////////////////////////////////////Резвых Датчик расстояния

}

void MainWindow::ChangeValue(int value)
{
    //ui->label_7->setNum(value);
}

void MainWindow::dataRedist(QString ID, QString value){
    if(ID == "1") this->ChangeValue(value.toDouble());
    else if(ID == "0") widget->ValueAngle(value.toDouble());
    else if(ID == "2") widget_2->ValueZX(value.toDouble());
    else if(ID == "3") widget_3->ValueSC(value.toDouble());
    else if(ID == "4") widget_4->ValueTerm(value.toDouble());
    else if(ID == "10") widget_5->distRezv(value.toUtf8());
    else if(ID == "all") {
        this->ChangeValue(value.toDouble());
        widget->ValueAngle(value.toDouble());
        widget_2->ValueZX(value.toDouble());
        widget_3->ValueSC(value.toDouble());
        widget_4->ValueTerm(value.toDouble());
        widget_5->distRezv(value.toUtf8());
    }
}
