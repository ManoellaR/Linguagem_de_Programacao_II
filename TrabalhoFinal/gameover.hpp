#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include <QDialog>
#include <QMovie>

namespace Ui {
class GameOver;
}

class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = nullptr);
    ~GameOver();

private:
    Ui::GameOver *ui;
    QMovie *background;
};

#endif // GAMEOVER_HPP
