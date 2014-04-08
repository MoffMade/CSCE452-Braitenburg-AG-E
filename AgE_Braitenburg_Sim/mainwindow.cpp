#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    simulatorScene.setSceneRect(0,0,800,600);
    ui->simulatorView->setScene(&simulatorScene);
    ui->simulatorView->setSceneRect(0,0,800,600);
    ui->simulatorView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addLight_clicked()
{
    //Get X, Y coordinates for light source
    LightSource* newLight=new LightSource(ui->lightX->value(),ui->lightY->value());
    simulatorScene.addItem(newLight);
    lights.push_back(newLight);
    lightPoints.push_back(newLight->getLoc());
}

void MainWindow::on_addVehicle_clicked()
{
    //Allow additional vehicle onto sim space
    std::cout<<"Add Vehicle Pressed.\n";

    double kMatValues[]={ui->kMat00->value(),ui->kMat01->value(),ui->kMat10->value(),ui->kMat11->value()};
    QMatrix2x2 kMat(kMatValues);
    QPoint botLoc=*(new QPoint(ui->botX->value(),ui->botY->value()));
    //Robot* newBot=new Robot(getLights(),kMat,botLoc);
}

QVector<QPoint>* MainWindow::getLights(){
    return &lightPoints;
}
