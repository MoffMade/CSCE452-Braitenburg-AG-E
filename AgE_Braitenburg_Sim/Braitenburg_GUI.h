#ifndef BRAITENBURG_GUI_H
#define BRAITENBURG_GUI_H
#include <string>
#include <QPoint>
#include <QGraphicsEllipseItem>

class LightSource : public QGraphicsEllipseItem{

public:
    LightSource(QGraphicsItem* parent = 0);
    LightSource(double x, double y, QGraphicsItem* parent = 0);
    QPointF getLoc();
    void setLoc(QPointF newLoc);

private:
    QPointF loc;
};

#endif // BRAITENBURG_GUI_H
