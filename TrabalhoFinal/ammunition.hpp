#ifndef AMMUNITION_HPP
#define AMMUNITION_HPP

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Ammunition: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int frame = 1;
    QTimer* animationTimer;
    QPixmap sprite;
public:
    Ammunition();
public slots:
    void animation();
};

#endif // AMMUNITION_HPP
