#ifndef PLAYERVSENEMY_H
#define PLAYERVSENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class PlayerVsEnemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    PlayerVsEnemy();
    int hinh;
public slots:
    void drawPlayerVsEnemy();
};

#endif // PLAYERVSENEMY_H
