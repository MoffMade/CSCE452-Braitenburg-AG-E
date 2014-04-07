#ifndef BRAITENBURG_GUI_H
#define BRAITENBURG_GUI_H
#include <string>
#include <QPoint>
#include <QGraphicsEllipseItem>

class LightSource : public QGraphicsEllipseItem{

public:
    LightSource();
    LightSource(double x, double y);
    QPoint* getLoc();
    void setLoc(QPoint newLoc);

private:
    QPoint loc;
};

#endif // BRAITENBURG_GUI_H
