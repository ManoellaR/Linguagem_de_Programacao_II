#ifndef HEALTH_HPP
#define HEALTH_HPP

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include "heart.hpp"

class Health: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int heartCount;
public:
    Health();
    void increase();
    void decrease();
    void update();
public slots:
    void spawnHeart();

};

#endif // HEALTH_HPP
