#include "player.hpp"
#include "game.hpp"
#include "bullet.hpp"

extern Game* game;

Player::Player()
{
    setPixmap(QPixmap(":/images/survivor-TEMPORARY.png"));

    moveTimer = new QTimer();
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(17);

    focusTimer = new QTimer();
    connect(focusTimer, SIGNAL(timeout()), this, SLOT(autofocus()));
    focusTimer->start(16);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W) moveUp = true;
    if(event->key() == Qt::Key_S) moveDown = true;
    if(event->key() == Qt::Key_A) moveLeft = true;
    if(event->key() == Qt::Key_D) moveRight = true;
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W) moveUp = false;
    if(event->key() == Qt::Key_S) moveDown = false;
    if(event->key() == Qt::Key_A) moveLeft = false;
    if(event->key() == Qt::Key_D) moveRight = false;
}

void Player::move()
{
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

void Player::autofocus()
{
    setFocus();
}

void Player::shoot()
{
    if(!shooted){
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        shooted = true;
        QTimer::singleShot(225, []{game->player->shooted = false;});
    }
}
