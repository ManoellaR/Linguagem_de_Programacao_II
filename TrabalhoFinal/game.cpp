#include "game.hpp"
#include <QPainter>
#include <cmath>
#include <QDebug>
#include "zombie.hpp"

Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720);
    //scene->setBackgroundBrush(QBrush(QImage(":/images/starBackground.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);
    setMouseTracking(true);

    player = new Player();
    //player->setRect(0,0,50,50);
    player->setPos(640,360);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(player);
    Zombie* zombie = new Zombie();
    scene->addItem(zombie);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        player->shooting = true;
        QLineF line(player->pos().x(), player->pos().y(), event->pos().x(), event->pos().y());
        lineAnglePressed = -1 * line.angle();
    }
}

void Game::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) player->shooting = false;
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    QLineF line(player->pos().x(), player->pos().y(), event->pos().x(), event->pos().y());
    lineAngle = -1 * line.angle();
    player->setRotation(lineAngle);
}

void Game::zombieSpawn()
{

}
