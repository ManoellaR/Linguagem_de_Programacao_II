#ifndef MENU_HPP
#define MENU_HPP

#include <QMainWindow>
#include <QMovie>
#include "game.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_StartButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::Menu *ui;
    QMovie *background;
};
#endif // MENU_HPP
