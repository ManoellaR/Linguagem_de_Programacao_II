#include "gameover.hpp"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);

    background = new QMovie(":/images/gameover.gif");
    ui->gameoverlabel->setMovie(background);
    background->start();
}

GameOver::~GameOver()
{
    delete ui;
}
