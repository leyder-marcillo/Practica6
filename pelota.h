#ifndef PELOTA_H
#define PELOTA_H

#include<math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QPixmap>


class pelota: public QGraphicsItem
{
private:
    double vX,vY,v,r;
    double viniX,viniY;
    double x,y;
    double angulo;
    double aX,aY;
    double masa,A;
    double K,e;
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    pelota();
    pelota(double v_iniX,double v_iniY,double _x, double _y, double _m,double radio,double _e,double _K);
    void CalVelocidad();
    void CalAceleracion();
    void ActualizarPos();
    void choque();
    double getPosX();
    double getPosY();
    double getAngu();
    double getmasa();
};

#endif // PELOTA_H
