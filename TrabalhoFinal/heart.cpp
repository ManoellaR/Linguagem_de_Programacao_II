#include "heart.hpp"

Heart::Heart()
{
    sprite = QPixmap(":/images/HealthKit1.png");
    setPixmap(sprite);
    setPos(rand() % 1240, rand() % 680);

    animationTimer = new QTimer();
    connect(animationTimer, SIGNAL(timeout()), this, SLOT(animation()));
    animationTimer->start(100);
}

void Heart::animation()
{
    if(frame > 5) frame = 1;
    sprite = ":/images/HealthKit" + QString::number(frame) + ".png";
    setPixmap(sprite);
    frame ++;
}
