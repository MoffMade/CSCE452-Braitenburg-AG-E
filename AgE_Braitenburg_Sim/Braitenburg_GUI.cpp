#include "Braitenburg_GUI.h"

LightSource::LightSource(QGraphicsItem* parent):QGraphicsEllipseItem(parent){
    loc=QPoint(0,0);
    setRect(0,0,5,5);
}

LightSource::LightSource(double x, double y, QGraphicsItem* parent):QGraphicsEllipseItem(parent){
    loc=QPoint(x,y);
    setRect(x,y,5,5);
}

QPoint LightSource::getLoc(){
    return loc;
}

void LightSource::setLoc(QPoint newLoc){
    loc=newLoc;
    setRect(loc.x(), loc.y(), 5, 5);
}
