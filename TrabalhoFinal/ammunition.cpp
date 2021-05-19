#include "ammunition.hpp"

Ammunition::Ammunition()
{
    sprite = QPixmap(":/images/ammo1.png");
    setPixmap(sprite);
    setPos(rand() % 1240, rand() % 680);

    animationTimer = new QTimer();
    connect(animationTimer, SIGNAL(timeout()), this, SLOT(animation()));
    animationTimer->start(100);
}

void Ammunition::animation()
{
    if(frame > 5) frame = 1;
    sprite = ":/images/ammo" + QString::number(frame) + ".png";
    setPixmap(sprite);
    frame ++;
}
