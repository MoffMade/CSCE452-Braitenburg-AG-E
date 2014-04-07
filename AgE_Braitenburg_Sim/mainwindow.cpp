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
    ui->simulatorView->setSceneRect(0,0,750,550);
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
}

void MainWindow::on_addVehicle_clicked()
{
    //Allow additional vehicle onto sim space
    std::cout<<"Add Vehicle Pressed.\n";
}

std::vector<QPoint*> MainWindow::getLights(){
    std::vector<QPoint*> lightPoints;
    for(int i=0; i<lights.size(); i++){
        lightPoints.push_back(lights[i]->getLoc());
    }
    return lightPoints;
}
