#ifndef BOOM_H
#define BOOM_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Boom: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Boom();
    int hinh;

public slots:
    void bomb_Explode();
    void collision_bomb();
    void drawBomb();

};

#endif // BOOM_H
