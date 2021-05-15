#ifndef GAME_HPP
#define GAME_HPP

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include "player.hpp"

class Game : public QGraphicsView
{
public:
    double lineAngle;
    double lineAnglePressed;
    Player * player;
    QTimer * spawnTimer;
    QGraphicsScene * scene;
    Game();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
public slots:
    void zombieSpawn();
};

#endif // GAME_HPP
