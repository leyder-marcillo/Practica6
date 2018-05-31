#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    MiEscena= new QGraphicsScene(this);

//    MiEscena->setSceneRect(0,-320,320,320);
        ui->graphicsView->setScene(MiEscena);


    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        MiEscena->setSceneRect(0,-500,1000,500);
//       MiEscena->setSceneRect(-200,-200,300,300);

    QPen mypenRed =QPen(Qt::red);
    QPen mypenBlue=QPen(Qt::blue);

    QLineF TopLine(MiEscena->sceneRect().topLeft(),MiEscena->sceneRect().topRight());
    QLineF LeftLine(MiEscena->sceneRect().topLeft(),MiEscena->sceneRect().bottomLeft());
    QLineF RightLine(MiEscena->sceneRect().topRight(),MiEscena->sceneRect().bottomRight());
    QLineF BottomLine(MiEscena->sceneRect().bottomLeft(),MiEscena->sceneRect().bottomRight() );

    MiEscena->addLine(TopLine,mypenRed);
    MiEscena->addLine(LeftLine,mypenBlue);
    MiEscena->addLine(RightLine,mypenRed);
    MiEscena->addLine(BottomLine,mypenBlue);


    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    srand(time(NULL));
    double x=1+rand() % (1000 -1);
    double y=50+ rand() % (500-50);
    double radio=5+rand() % (30+1-5);
    double vY=1+rand() % (300+1-1);
    double vX=-300+rand() % (300+1+300);
    double masa=50+rand() % (600+1-50);
    float e = 0.5 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1-0.5)));
//    double e=0.7555555;
//    double k=
    float K = 0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.01-0)));


    esferas.append(new pelota(vX,vY,x,y,masa,radio,e,K));
   //cuerpo= new Movimiento(v,x,y,rad);
    MiEscena->addItem(esferas.back());

    timer->start(20);
}
void MainWindow::mover()
{
    for(int i=0; i<esferas.size(); i++)
        esferas.at(i)->ActualizarPos();
}
