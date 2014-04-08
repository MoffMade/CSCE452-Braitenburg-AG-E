#include "Braitenburg_GUI.h"

LightSource::LightSource(QGraphicsItem* parent):QGraphicsEllipseItem(parent){
    loc=QPointF(0,0);
    setRect(0,0,5,5);
}

LightSource::LightSource(double x, double y, QGraphicsItem* parent):QGraphicsEllipseItem(parent){
    loc=QPointF(x,y);
    setRect(x,y,5,5);
}

QPointF LightSource::getLoc(){
    return loc;
}

void LightSource::setLoc(QPointF newLoc){
    loc=newLoc;
    setRect(loc.x(), loc.y(), 5, 5);
}
