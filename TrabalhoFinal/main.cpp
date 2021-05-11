#include "menu.hpp"
#include "game.hpp"
#include <QApplication>

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    game = new Game();
    w.show();
    return a.exec();
}
