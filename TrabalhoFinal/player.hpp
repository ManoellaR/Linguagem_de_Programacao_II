#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>

class Player: public QObject,  public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool shooted = false;
public:
    bool shooting = false;
    QTimer* moveTimer;
    QTimer* focusTimer;
    Player();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void shoot();
public slots:
    void autofocus();
    void move();
};

#endif // PLAYER_HPP
