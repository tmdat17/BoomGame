#ifndef PLAYERMOVEDOWN_H
#define PLAYERMOVEDOWN_H

#include <QGraphicsPixmapItem>
#include <QObject>

class PlayerMoveDown: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT


public:
    PlayerMoveDown();
    int hinh;
public slots:
    void drawPlayerMoveDown();

};

#endif // PLAYERMOVEDOWN_H
