#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsItem>
#include <QGenericMatrix>

typedef QPoint Light;

struct Position
{
    Position(){}
    Position(double xval, double yval, double thetaval)
    {
        X = xval; Y = yval; theta = thetaval;
    }

    double X;
    double Y;
    double theta;
};

class Robot : public QGraphicsItem
{

private:

    //pointer to light sources
    QVector<Light> *m_lights;

    //current position of the robot, includes x, y, and rotation
    Position m_position;

    //K matrix representation
    QMatrix2x2 m_K;

    //these are rectangles which make up the robot's appearance
    QRectF m_body;
    QRectF m_leftWheel;
    QRectF m_rightWheel;
    QRectF m_leftSensor;
    QRectF m_rightSensor;

    //moves the robot in the scene. takes a 2x1 matrix representing the
    //drive intensity (or speed) of the left and right wheels, respectively
    void moveRobot(QGenericMatrix<1, 2, double> intensity);

    //distance formula
    double distance(QPointF p1, QPointF p2);

public:
    //constructor
    //takes pointer to vector of lights, K matrix, and an initial position.
    //TODO: Qpoint instead of Position, assume angle = 0;
    Robot(QVector<Light> *lights, QMatrix2x2 K, Position position, QGraphicsItem *parent = 0);

    //updates the robot's position and rotation
    void update();

    //returns the center of the left sensor in the coordinate system of the scene
    QPointF leftSensorLocation();

    //returns the center of thre right sensor in the coordinate system of the scene
    QPointF rightSensorLocation();

    //implemented virtual functions from QGraphicsItem;
    //returns a rectange describing the bounds of the drawn object
    QRectF boundingRect() const;

    //paints the object
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

};

#endif // ROBOT_H
