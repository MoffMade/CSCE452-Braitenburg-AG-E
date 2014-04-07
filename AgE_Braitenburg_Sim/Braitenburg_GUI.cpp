#include "Braitenburg_GUI.h"

LightSource::LightSource(){
    QGraphicsEllipseItem();
    loc=QPoint(0,0);
    setRect(0,0,8,8);
}

LightSource::LightSource(double x, double y){
    QGraphicsEllipseItem();
    loc=QPoint(x,y);
    setRect(x,y,8,8);
}

QPoint* LightSource::getLoc(){
    return &loc;
}

void LightSource::setLoc(QPoint newLoc){
    loc=newLoc;
    setRect(loc.x(), loc.y(), 8, 8);
}
