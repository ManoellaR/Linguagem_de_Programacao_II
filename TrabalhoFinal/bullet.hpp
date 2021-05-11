#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject,public QGraphicsRectItem
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
