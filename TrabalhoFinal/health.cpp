#include "health.hpp"
#include "game.hpp"

extern Game* game;

Health::Health()
{
    heartCount = 3;
    setPixmap(QPixmap(":/images/Heart3.png"));
    setPos(0, 0);
}

void Health::increase()
{
    if(heartCount < 3){
        heartCount++;
        update();
    }
}

void Health::decrease()
{
    if(heartCount > 0){
        heartCount--;
        update();
    }
    if(heartCount == 0){
        game->player->action = "death";
        game->spawnTimer->stop();
        game->hide();
        heartCount = 3;
        update();
        game->player->action = "run";
    }
}

void Health::update()
{
    if(heartCount == 1){
        setPixmap(QPixmap(":/images/Heart1.png"));
    }
    if(heartCount == 2){
        setPixmap(QPixmap(":/images/Heart2.png"));
    }
    if(heartCount == 3){
        setPixmap(QPixmap(":/images/Heart3.png"));
    }
    if(heartCount < 3){
        QTimer::singleShot(15000, this, SLOT(spawnHeart()));
    }
}

void Health::spawnHeart()
{
    Heart * heart = new Heart();
    scene()->addItem(heart);
}
