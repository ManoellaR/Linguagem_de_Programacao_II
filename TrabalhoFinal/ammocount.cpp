#include "ammocount.hpp"
#include <QFont>
#include "game.hpp"

extern Game* game;

AmmoCount::AmmoCount()
{
    ammoCount = 25;
    ammoTotal = 75;
    setPlainText(QString::number(ammoCount) + QString("/") + QString::number(ammoTotal));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));

    spawnTimer = new QTimer();
    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnAmmo()));
    spawnTimer->start(30000);
}

void AmmoCount::reload()
{
    if(ammoTotal > 0){
        int difference = 25 - ammoCount;
        ammoCount += difference;
        ammoTotal -= difference;
        update();
    }
}

void AmmoCount::increase()
{
    ammoTotal += 25;
    update();
}

void AmmoCount::decrease()
{
    ammoCount--;
    update();
}

void AmmoCount::update()
{
    setPlainText(QString("Ammo: ") + QString::number(ammoCount) + QString("/") + QString::number(ammoTotal));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));
}

int AmmoCount::getAmmoCount()
{
    return ammoCount;
}

void AmmoCount::spawnAmmo()
{
    Ammunition * ammo = new Ammunition();
    scene()->addItem(ammo);
}
