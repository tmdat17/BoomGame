#ifndef BOOM_H
#define BOOM_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Boom: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Boom();
public slots:
    void bomb_Explode();
    void collision_bomb();
};

#endif // BOOM_H
