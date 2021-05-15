#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <QGraphicsPixmapItem>
#include <QObject>

class Zombie: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer* timer;
    QLineF line;
    double PlayerAngle;
public:
    Zombie();
public slots:
    void move();
};

#endif // ZOMBIE_HPP
