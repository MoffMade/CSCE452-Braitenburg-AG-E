#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
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
    std::vector<QPoint*> getLights();

private slots:
    void on_addLight_clicked();

    void on_addVehicle_clicked();
private:
    Ui::MainWindow *ui;
    QGraphicsScene simulatorScene;
    std::vector<LightSource*> lights;
    std::vector<std::string> robots; //Replace string with Robot class
};

#endif // MAINWINDOW_H
