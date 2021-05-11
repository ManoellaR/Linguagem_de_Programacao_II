#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>
#include <math.h>
#include "bullet.hpp"
#include "game.hpp"

extern Game * game;

Bullet::Bullet()
{
    setRect(0,0,50,10);
    Angle = game->lineAnglePressed;
    setRotation(Angle);
    bulletTimer = new QTimer();
    connect(bulletTimer,SIGNAL(timeout()),this,SLOT(move()));
    bulletTimer->start(17);
}

void Bullet::move()
{
    if(Angle > 0 && Angle <= 90)
    {
        setPos(x() + (cos(Angle)*10), y() + (sin(Angle)*10));
    }
    if(Angle > 90 && Angle <= 180)
    {
        setPos(x() - (cos(Angle)*10), y() + (sin(Angle)*10));
    }
    if(Angle < 0 && Angle >= -90)
    {
        setPos(x() + (cos(Angle)*10), y() - (sin(Angle)*10));
    }
    if(Angle < -90 && Angle >= -180)
    {
        setPos(x() - (cos(Angle)*10), y() - (sin(Angle)*10));
    }
    if(pos().x() < -10 || pos().x() > 1290)
    {
        if(pos().y() < -10 || pos().y() > 730)
        {
            scene()->removeItem(this);
            delete this;
            qDebug() << "bullet removed";
        }
    }
}
