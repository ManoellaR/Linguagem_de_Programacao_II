#include "game.hpp"
#include <QPainter>
#include <cmath>
#include <QDebug>
#include "zombie.hpp"

Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720);
    scene->setBackgroundBrush(QBrush(QImage(":/images/GameBackground.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);
    setMouseTracking(true);
     QWidget::setCursor(Qt::CrossCursor);

    player = new Player();
    player->setPos(640,360);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(player);

    health = new Health();
    scene->addItem(health);

    ammoCount = new AmmoCount();
    ammoCount->setPos(ammoCount->x(), ammoCount->y()+25);
    scene->addItem(ammoCount);

    spawnTimer = new QTimer();
    connect(spawnTimer, SIGNAL(timeout()), player, SLOT(zombieSpawn()));
    spawnTimer->start(10000);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        player->shooting = true;
        QLineF line(player->pos().x(), player->pos().y(), event->pos().x(), event->pos().y());
        lineAnglePressed = -1 * line.angle();
        player->action = "shoot";
    }
}

void Game::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        player->shooting = false;
        player->action = "idle";
    }
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    QLineF line(player->pos().x(), player->pos().y(), event->pos().x(), event->pos().y());
    lineAngle = -1 * line.angle();
}
