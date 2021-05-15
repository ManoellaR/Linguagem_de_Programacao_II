#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>
#include <qmath.h>
#include "bullet.hpp"
#include "zombie.hpp"
#include "game.hpp"

extern Game * game;

Bullet::Bullet()
{
    setRect(0,0,50,10);
    Angle = game->lineAngle;
    setRotation(Angle);
    bulletTimer = new QTimer();
    connect(bulletTimer,SIGNAL(timeout()),this,SLOT(move()));
    bulletTimer->start(17);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_item = collidingItems();
    for(int i = 0, n = colliding_item.size(); i < n; i++){
        if(typeid(*(colliding_item[i]))== typeid(Zombie)){
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);
            delete colliding_item[i];
            delete this;
            return;
        }
    }

    setPos(x() + (qCos(qDegreesToRadians(Angle))*10), y() + (qSin(qDegreesToRadians(Angle))*10));

    if(pos().x() < -10 || pos().x() > 1290)
    {
        if(pos().y() < -10 || pos().y() > 730)
        {
            scene()->removeItem(this);
            delete this;
        }
    }
}
