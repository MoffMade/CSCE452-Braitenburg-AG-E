#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGenericMatrix>
#include <QMouseEvent>
#include <Braitenburg_GUI.h>
#include <vector>

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene simulatorScene;
    QVector<LightSource*> lights;
    QVector<QPoint>lightPoints;
    QVector<std::string> robots; //Replace string with Robot class

};

#endif // MAINWINDOW_H
