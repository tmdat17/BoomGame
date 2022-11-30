#ifndef PLAYERMOVERIGHT_H
#define PLAYERMOVERIGHT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class PlayerMoveRight: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    PlayerMoveRight();
    int hinh;
public slots:
    void drawPlayerMoveRight();

};

#endif // PLAYERMOVERIGHT_H
