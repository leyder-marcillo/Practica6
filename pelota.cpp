#include <QDebug>
#include <QPixmap>
#include "pelota.h"

#define delta 0.1
#define g 10
#define PI 3.14159265358979323846


QRectF pelota::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void pelota::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkMagenta);
    painter->drawEllipse(-r,-r,2*r,2*r);
}

pelota::pelota()
{

}

pelota::pelota(double v_iniX, double v_iniY, double _x, double _y, double _m, double radio, double _e, double _K)
{
    A=PI*pow(radio,2);
    r=radio;
    x=_x;
    y=_y;
    masa=_m;
    viniX=v_iniX;
    viniY=v_iniY;
    aX=0;
    aY=0;
    angulo=0;
    v=0;
    K=_K;
    e=_e;
    vX=0;
    vY=0;
    setPos(x,y);
}
void pelota::CalAceleracion()
{
    if(viniX==0){
        viniX=1;
    }
    angulo=atan2(viniY,viniX);
    aX=(-K*(pow(v,2)*pow(r,2))/masa)*cos(angulo);
    aY=(-K*(pow(v,2)*pow(r,2))/masa)*sin(angulo)-g;
    //    aDx=(-1/(2*masa))*p*v*CD*A*cos(angulo);}
    //    aDy=(-1/(2*masa))*p*v*CD*A*sin(angulo);
}
void pelota::CalVelocidad()
{
    vX=viniX+(aX*delta);
    vY=viniY+(aY*delta);
    viniX=vX;
    viniY=vY;
}
void pelota::ActualizarPos()
{
    v=sqrt(pow(viniX,2)+pow(viniY,2));
    CalAceleracion();
    CalVelocidad();
    x=x+(vX*delta)+((aX*delta*delta)/2);
    y=y+(vY*delta)+((aY*delta*delta)/2);
    //colisiones
    if(x+r>=1000.0 || x<r){
        viniX=-e*vX;
        v=sqrt(pow(viniX,2)+pow(viniY,2));
        angulo=atan2(viniY,viniX);
        x=x+(vX*delta)+((aX*delta*delta)/2);

        if(x+r>1000)
            x=1000-r;
        else
            x=r;
//        while(x+r>=1000.0 || x<r){
//            v=sqrt(pow(viniX,2)+pow(viniY,2));
//            CalAceleracion();
//            CalVelocidad();
//            x=x+(vX*delta)+((aX*delta*delta)/2);
//        }
    }
    if(y+r>500.0 || y<r){
        viniY=-e*vY;
        v=sqrt(pow(viniX,2)+pow(viniY,2));
        angulo=atan2(viniY,viniX);
        y=y+(vY*delta)+((aY*delta*delta)/2);

        if(y+r>500)
            y=500-r;
        else
            y=r;
   }

//        while(y+r>=500.0 || y+r<r){
//            v=sqrt(pow(viniX,2)+pow(viniY,2));
//            CalAceleracion();
//            CalVelocidad();

//            y=y+(vY*delta)+((aY*delta*delta)/2);
//        }
//    }
//    if(y<r)
//        y=r;

    qDebug()<<"posx= "<< x <<"posy= "<< y << endl;

    setPos(x,-y);

}
void pelota::choque()
{
    v=-e*v;
    CalAceleracion();
    CalVelocidad();
    x=x+(vX*delta)+((aX*delta*delta)/2);
    y=y+(vY*delta)+((aY*delta*delta)/2);
}

double pelota::getPosX()
{
    return x;
}

double pelota::getPosY()
{
    return y;
}

double pelota::getAngu()
{
    return angulo;
}

double pelota::getmasa()
{
    return masa;
}
