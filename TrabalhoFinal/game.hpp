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
    qreal lineAnglePressed;
    QTimer * lineTimer;
    Player * player;
    QGraphicsScene * scene;
    Game();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    //void drawForeground(QPainter* painter, const QRectF& rect);
};

#endif // GAME_HPP
