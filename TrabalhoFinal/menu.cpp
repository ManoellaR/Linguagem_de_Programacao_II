#include "menu.hpp"
#include "ui_menu.h"

extern Game * game;

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    //ui->StartButton->setFocusPolicy(Qt::NoFocus);

    background = new QMovie(":/images/menu.gif");
    ui->backgroundlabel->setMovie(background);
    background->start();
}

Menu::~Menu()
{
    delete ui;
}



void Menu::on_StartButton_clicked()
{
    game->show();
}

void Menu::on_ExitButton_clicked()
{

}
