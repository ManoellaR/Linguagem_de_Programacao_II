#include "player.hpp"
#include "game.hpp"
#include "bullet.hpp"
#include "zombie.hpp"
#include <QDebug>

extern Game* game;

Player::Player()
{
    QPixmap pixmap(":/player-animations/idle-right1.png");
    setPixmap(pixmap);
    setOffset(-pixmap.width() / 2, -pixmap.height() / 2);

    moveTimer = new QTimer();
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(30);

    focusTimer = new QTimer();
    connect(focusTimer, SIGNAL(timeout()), this, SLOT(autofocus()));
    focusTimer->start(16);

    action = "idle";
    animationTimer = new QTimer();
    connect(animationTimer, SIGNAL(timeout()), this, SLOT(animation()));
    animationTimer->start(100);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){
        moveUp = true;
        action = "run";
    }
    if(event->key() == Qt::Key_S){
        moveDown = true;
        action = "run";
    }
    if(event->key() == Qt::Key_A){
        moveLeft = true;
        action = "run";
    }
    if(event->key() == Qt::Key_D){
        moveRight = true;
        action = "run";
    }
    if(event->key() == Qt::Key_R && game->ammoCount->getAmmoCount() < 25){
        game->ammoCount->reload();
        action = "reload";
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){
        moveUp = false;
        action = "idle";
    }
    if(event->key() == Qt::Key_S){
        moveDown = false;
        action = "idle";
    }
    if(event->key() == Qt::Key_A){
        moveLeft = false;
        action = "idle";
    }
    if(event->key() == Qt::Key_D){
        moveRight = false;
        action = "idle";
    }
    if(event->key() == Qt::Key_R){
        action = "idle";
    }
}

void Player::move()
{
    QList<QGraphicsItem *> colliding_item = collidingItems();
    for(int i = 0, n = colliding_item.size(); i < n; i++){
        if(typeid(*(colliding_item[i]))== typeid(Heart)){
            game->health->increase();
            scene()->removeItem(colliding_item[i]);
            delete colliding_item[i];
            return;
        }
        if(typeid(*(colliding_item[i]))== typeid(Ammunition)){
            game->ammoCount->increase();
            scene()->removeItem(colliding_item[i]);
            delete colliding_item[i];
            return;
        }
    }

    if(moveUp){
        if(pos().y() - 10 >= 0)
            setPos(pos().x(), pos().y() - 10);
    }
    if(moveDown){
        if(pos().y() - 10 <= 1200)
            setPos(pos().x(), pos().y() + 10);
    }
    if(moveLeft){
        if(pos().x() - 10 >= 0)
            setPos(pos().x() - 10, pos().y());
    }
    if(moveRight){
        if(pos().y() - 10 <= 650)
            setPos(pos().x() + 10, pos().y());
    }
    if(shooting){
        shoot();
    }
}

void Player::animation()
{
    if(action == "idle") frameMax = 5;
    if(action == "reload") frameMax = 6;
    if(action == "run") frameMax = 8;
    if(action == "run-shoot") frameMax = 8;
    if(action == "shoot") frameMax = 3;
    if(action == "hit") frameMax = 3;
    if((game->lineAngle >= -45) || (game->lineAngle < -315)){
        if(frame > frameMax) frame = 1;
        sprite = ":/player-animations/" + action + "-right" + QString::number(frame) + ".png";
        setPixmap(sprite);
        frame ++;
    }
    if((game->lineAngle < -45) && (game->lineAngle >= -135)){
        if(frame > frameMax) frame = 1;
        sprite = ":/player-animations/" + action + "-up" + QString::number(frame) + ".png";
        setPixmap(sprite);
        frame ++;
    }
    if((game->lineAngle < -135) && (game->lineAngle >= -225)){
        if(frame > frameMax) frame = 1;
        sprite = ":/player-animations/" + action + "-left" + QString::number(frame) + ".png";
        setPixmap(sprite);
        frame ++;
    }
    if((game->lineAngle < -225) && (game->lineAngle >= -315)){
        if(frame > frameMax) frame = 1;
        sprite = ":/player-animations/" + action + "-down" + QString::number(frame) + ".png";
        setPixmap(sprite);
        frame ++;
    }
    if(action == "death"){
        sprite = ":/player-animations/" + action + QString::number(frame) + ".png";
        setPixmap(sprite);
        frame ++;
    }
    if(action == "hit"){
        if(frame > frameMax) frame = 1;
        sprite = ":/player-animations/" + action + QString::number(frame) + ".png";
        setPixmap(sprite);
        frame ++;
    }
}

void Player::autofocus()
{
    setFocus();
}

void Player::shoot()
{
    if(game->ammoCount->getAmmoCount() > 0){
        if(!shooted){
            Bullet * bullet = new Bullet();
            bullet->setPos(x(),y());
            scene()->addItem(bullet);
            shooted = true;
            game->ammoCount->decrease();
            QTimer::singleShot(225, []{game->player->shooted = false;});
        }
    }
    else{
        game->ammoCount->reload();
    }
}

void Player::zombieSpawn()
{
    for(int i = 0; i< wave; i++){
        Zombie* zombie = new Zombie();
        scene()->addItem(zombie);
    }
    wave += rand() % 3;
}
