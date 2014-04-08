#include "robot.h"
#include <QPainter>
#include <qmath.h>

Robot::Robot(QVector<Light> *lights, QGenericMatrix<2,2,double> K, QPointF position, QGraphicsItem *parent) :
    QGraphicsItem(parent)
{
    m_lights = lights;
    m_K = K;
    m_theta = 0;


    //objects that are painted to paint a robot
    m_body = boundingRect();

    //left wheel
    double width = m_body.width() / 8;
    double height = m_body.height()/ 4;
    double left = 0;
    double top = (m_body.height() - height) / 2;
    m_leftWheel = QRectF(left, top, width, height);

    //right wheel
    left = m_body.width() - width;
    m_rightWheel = QRectF(left, top, width, height);

    //left sensor
    width = m_body.width() / 16;
    height = m_body.height() / 16;
    left = (m_body.width() - width) / 4;
    top = m_body.height() - height;
    m_leftSensor = QRectF(left, top, width, height);


    //right sensor
    left = 3 * (m_body.width() - width) / 4;
    m_rightSensor = QRectF(left, top, width, height);

    //set position
    setPos(position);

}

QRectF Robot::boundingRect() const
{
    return QRectF(0,0,100,100);   //defines the size of the robots drawing
}

void Robot::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    //set drawing styles
    QPen bodyPen(Qt::black);
    QPen wheelPen(Qt::blue);
    QPen sensorPen(Qt::yellow);
    QBrush bodyBrush(Qt::black,Qt::SolidPattern);
    QBrush wheelBrush(Qt::blue, Qt::SolidPattern);
    QBrush sensorBrush(Qt::yellow, Qt::SolidPattern);

    painter->setPen(bodyPen);
    painter->setBrush(bodyBrush);

    //draw body
    QRectF body = boundingRect();
    painter->drawRect(body);

    //draw wheels
    painter->setPen(wheelPen);
    painter->setBrush(wheelBrush);
    painter->drawRect(m_leftWheel);
    painter->drawRect(m_rightWheel);

    //draw sensors
    painter->setPen(sensorPen);
    painter->setBrush(sensorBrush);
    painter->drawRect(m_leftSensor);
    painter->drawRect(m_rightSensor);
}

void Robot::update()
{
    //get intensities
        //QGenericMatrix<1,1,double> intensity
        //top value is left sensor value, bottom is right sensor value
        QGenericMatrix<1, 2, double> intensity;
        intensity.fill(0);

        //loop over lights
        for(int i = 0; i < m_lights->size(); i++)
        {
            //left intensity += distance(light_i, leftSensorLocation);
            intensity(0,0) += 100 / distance(m_lights->at(i), leftSensorLocation());
            //right intensity += distnace(light_i, rightSensorLocation);
            intensity(1,0) += 100 / distance(m_lights->at(i), rightSensorLocation());
        }
    //run intensities through kmatrix
        //intensity = intensity * K
        intensity = m_K * intensity;
    //drive the bot with the differential steering function. then explode.
        moveRobot(intensity);
    //dtheta = (right - left) / width
    //dx = (right + left)/2 * cos(theta)
    //dy = (right + left)/2 * sin(theta)
        //move(intensity(0,0))
        //move(intensity(0,1))
    //calculate new position
    //calculate new rotation
}


//NOTE: mapToScene takes a point in the object's coordinate system and returns the same point in the scene's coordinate system
QPointF Robot::leftSensorLocation()
{
    return mapToScene(m_leftSensor.center().x(), m_leftSensor.center().y());
}

QPointF Robot::rightSensorLocation()
{
    return mapToScene(m_rightSensor.center().x(), m_rightSensor.center().y());
}

void Robot::moveRobot(QGenericMatrix<1, 2, double> intensity)
{
    //dtheta = (right - left) / width
    double dtheta = (180 / 3.141) * (intensity(1,0) - intensity(0,0)) / m_body.width();

    //dx = (right + left)/2 + cos(theta)
    double dx = (intensity(1,0) + intensity(0,0)) / 2 * (180 / 3.141) * qCos(rotation());

    //dy = (right + left)/2 + sin(theta)
    double dy = (intensity(1,0) + intensity(0,0)) / 2 * (180 / 3.141) * qSin(rotation());

    m_theta += dtheta;
    setRotation(rotation() + dtheta);

    moveBy(dx,dy);
}

double Robot::distance(QPointF p1, QPointF p2)
{
    return qSqrt( (p1.x()-p2.x()) * (p1.x()-p2.x()) + (p1.y()-p2.y()) * (p1.y()-p2.y()) );
}
