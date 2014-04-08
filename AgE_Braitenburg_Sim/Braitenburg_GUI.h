#ifndef BRAITENBURG_GUI_H
#define BRAITENBURG_GUI_H
#include <string>
#include <QPoint>
#include <QGraphicsEllipseItem>

class LightSource : public QGraphicsEllipseItem{

public:
    LightSource(QGraphicsItem* parent = 0);
    LightSource(double x, double y, QGraphicsItem* parent = 0);
    QPoint getLoc();
    void setLoc(QPoint newLoc);

private:
    QPoint loc;
};

#endif // BRAITENBURG_GUI_H
