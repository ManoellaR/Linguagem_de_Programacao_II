#ifndef HEART_HPP
#define HEART_HPP

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Heart: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int frame = 1;
    QTimer* animationTimer;
    QPixmap sprite;
public:
    Heart();
public slots:
    void animation();
};

#endif // HEART_HPP
