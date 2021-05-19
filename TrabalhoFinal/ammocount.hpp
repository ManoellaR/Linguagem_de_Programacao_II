#ifndef AMMOCOUNT_HPP
#define AMMOCOUNT_HPP

#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QObject>
#include "ammunition.hpp"

class AmmoCount: public QGraphicsTextItem
{
    Q_OBJECT
private:
    int ammoCount;
    int ammoTotal;
public:
    QTimer * spawnTimer;
    AmmoCount();
    void reload();
    void increase();
    void decrease();
    void update();
    int getAmmoCount();
public slots:
    void spawnAmmo();
};

#endif // AMMOCOUNT_HPP
