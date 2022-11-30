#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class GameOver: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    GameOver();
public slots:
    void drawGameOver();
};

#endif // GAMEOVER_H
