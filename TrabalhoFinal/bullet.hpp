#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer* bulletTimer;
    qreal Angle;
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H
