#ifndef PLAYERMOVELEFT_H
#define PLAYERMOVELEFT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class PlayerMoveLeft: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    PlayerMoveLeft();
    int hinh;
public slots:
    void drawPlayerMoveLeft();

};

#endif // PLAYERMOVELEFT_H
