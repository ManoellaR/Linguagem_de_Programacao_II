#include "heart.hpp"

Heart::Heart()
{
    setPixmap(QPixmap(":/images/Heart.png"));
    setPos(rand() % 1240, rand() % 680);
}
