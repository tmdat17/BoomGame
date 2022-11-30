#ifndef PLAYERMOVETOP_H
#define PLAYERMOVETOP_H

#include <QGraphicsPixmapItem>
#include <QObject>

class PlayerMoveTop: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    PlayerMoveTop();
    int hinh;
public slots:
    void drawPlayerMoveTop();

};

#endif // PLAYERMOVETOP_H
