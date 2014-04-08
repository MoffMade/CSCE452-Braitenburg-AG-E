#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGenericMatrix>
#include <QTimer>
#include "Braitenburg_GUI.h"
#include "robot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector<QPoint>* getLights();


private slots:
    void on_addLight_clicked();
    void on_addVehicle_clicked();
    void timedUpdate();

private:
    Ui::MainWindow *ui;
    QGraphicsScene simulatorScene;
    QVector<LightSource*> lights;
    QVector<QPoint>lightPoints;
    QVector<Robot*> robots; //Replace string with Robot class
    QTimer* updateTimer;

};

#endif // MAINWINDOW_H
