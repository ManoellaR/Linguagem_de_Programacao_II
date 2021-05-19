#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <QGraphicsPixmapItem>
#include <QObject>

class Zombie: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QString sprite;
    int frame = 1;
    int frameMax;
    int option;
    int life;
    QTimer* timer;
    QTimer* animationTimer;
    QLineF line;
    double PlayerAngle;
public:
    Zombie();
    QString action;
public slots:
    void move();
    void animation();
};

#endif // ZOMBIE_HPP
