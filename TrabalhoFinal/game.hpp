#ifndef GAME_HPP
#define GAME_HPP

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include "player.hpp"
#include "health.hpp"
#include "ammocount.hpp"

class Game : public QGraphicsView
{
public:
    double lineAngle;
    double lineAnglePressed;
    Player * player;
    Health * health;
    AmmoCount * ammoCount;
    QTimer * spawnTimer;
    QGraphicsScene * scene;
    Game();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // GAME_HPP
