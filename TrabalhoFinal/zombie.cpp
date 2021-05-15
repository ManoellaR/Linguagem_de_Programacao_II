#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include <qmath.h>

#include "game.hpp"
#include "zombie.hpp"

extern Game * game;

Zombie::Zombie()
{
    int random_numberx = rand() % 1280;
    int random_numbery = rand() % 720;
    int decision = rand() % 4;
    if(decision == 1){
        setPos(random_numberx,0);
    }
    if(decision == 2){
        setPos(0, random_numbery);
    }
    if(decision == 3){
        setPos(random_numberx,720);
    }
    if(decision == 4){
        setPos(1280, random_numbery);
    }
    setPixmap(QPixmap(":/images/zombie-TEMPORARY.png"));
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(17);
}

void Zombie::move()
{
    line = QLineF(QPointF(x(), y()), game->player->pos());
    PlayerAngle = -1 * line.angle();
    setRotation(PlayerAngle);
    setPos(x() + (qCos(qDegreesToRadians(PlayerAngle))*2), y() + (qSin(qDegreesToRadians(PlayerAngle)))*2);
}
