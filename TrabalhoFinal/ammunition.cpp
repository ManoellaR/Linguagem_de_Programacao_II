#include "ammunition.hpp"

Ammunition::Ammunition()
{
    //setPixmap(QPixmap(":/images/Heart.png"));
    setRect(0,0,50,50);
    setPos(rand() % 1240, rand() % 680);
}
