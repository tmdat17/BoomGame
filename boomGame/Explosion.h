#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Explosion: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Explosion();
    int hinh;
public slots:
    void drawExplosion();

};

#endif // EXPLOSION_H
