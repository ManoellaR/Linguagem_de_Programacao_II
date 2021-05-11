#include "game.hpp"
#include <QPainter>
#include <cmath>
#include <QDebug>

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

    lineTimer = new QTimer;
    connect(lineTimer, SIGNAL(timeout()), this, SLOT(mousePressEvent(QMouseEvent*event)));
    lineTimer->start(17);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        player->shooting = true;
        lineAnglePressed = atan2(event->pos().y() - player->pos().y(), event->pos().x() - player->pos().x()) * 180 / M_PI;
        qDebug()<<"atan2: " << lineAnglePressed;
        qDebug()<<"mouse pos: " << event->pos();
    }
}

void Game::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) player->shooting = false;
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    qreal lineAngle = atan2(event->pos().y() - player->pos().y(), event->pos().x() - player->pos().x()) * 180 / M_PI;
    player->setRotation(lineAngle);
}
/*
void Game::drawForeground(QPainter* painter, const QRectF& rect) {
    painter->setPen(QPen(Qt::black, 1));
    painter->drawLine(m_MousePos, player->pos());
}
*/
