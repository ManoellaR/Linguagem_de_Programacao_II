#ifndef AMMUNITION_HPP
#define AMMUNITION_HPP

#include <QGraphicsRectItem>
#include <QObject>

class Ammunition: public QObject, public QGraphicsRectItem
{
public:
    Ammunition();
};

#endif // AMMUNITION_HPP
