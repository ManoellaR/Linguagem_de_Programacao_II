#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include <qmath.h>

#include "game.hpp"
#include "zombie.hpp"
#include "bullet.hpp"

extern Game * game;

Zombie::Zombie()
{
    option = rand() % 2;
    if(option == 1) life = 2;
    if(option == 2) life = 3;
    sprite = ":/zombie-animations/zombie"+ QString::number(option) + "-run-right1.png";;
    QPixmap pixmap(sprite);
    setPixmap(pixmap);
    setOffset(-pixmap.width() / 2, -pixmap.height() / 2);

    int random_numberx = rand() % 1260;
    int random_numbery = rand() % 700;
    int decision = rand() % 4;
    if(decision == 1){
        setPos(random_numberx,5);
    }
    if(decision == 2){
        setPos(5, random_numbery);
    }
    if(decision == 3){
        setPos(random_numberx,700);
    }
    if(decision == 4){
        setPos(1260, random_numbery);
    }

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(17);

    action = "run";
    animationTimer = new QTimer();
    connect(animationTimer, SIGNAL(timeout()), this, SLOT(animation()));
    animationTimer->start(100);
}

void Zombie::move()
{
    QList<QGraphicsItem *> colliding_item = collidingItems();
    for(int i = 0, n = colliding_item.size(); i < n; i++){
        if(typeid(*(colliding_item[i]))== typeid(Player)){
            action = "attack";
            game->health->decrease();
            scene()->removeItem(this);
            delete timer;
            delete this;
            return;
        }
        if(typeid((colliding_item[i]))== typeid(Bullet))
        {
            scene()->removeItem(colliding_item[i]);
            delete colliding_item[i];
            life--;

            if (life <= 0){
                action = "death";
               delete this;
           }
        }
    }

    line = QLineF(QPointF(x(), y()), game->player->pos());
    PlayerAngle = -1 * line.angle();
    //setRotation(PlayerAngle);
    setPos(x() + (qCos(qDegreesToRadians(PlayerAngle))*2), y() + (qSin(qDegreesToRadians(PlayerAngle)))*2);
}

void Zombie::animation()
{
    if(action == "run") frameMax = 8;
    if(action == "attack") frameMax = 6;
    if(action == "death") frameMax = 8;
    if((PlayerAngle >= -90) || (PlayerAngle < -270)){
        if(frame > frameMax) frame = 1;
        sprite = ":/zombie-animations/zombie"+ QString::number(option) + "-" + action + "-right" + QString::number(frame) + ".png";
        setPixmap(sprite);
        frame ++;
    }
    if((PlayerAngle < -90) && (PlayerAngle >= -270)){
        if(frame > frameMax) frame = 1;
        sprite = ":/zombie-animations/zombie"+ QString::number(option) + "-" + action + "-left" + QString::number(frame) + ".png";
        setPixmap(sprite);
        frame ++;
    }
}
