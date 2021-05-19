#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>

class Player: public QObject,  public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QString sprite;
    int frame = 1;
    int frameMax;
    int wave = 5;
protected:
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool shooted = false;
public:
    QString action;
    bool shooting = false;
    QTimer* moveTimer;
    QTimer* focusTimer;
    QTimer* animationTimer;
    Player();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void shoot();
public slots:
    void autofocus();
    void move();
    void animation();
    void zombieSpawn();
};

#endif // PLAYER_HPP
