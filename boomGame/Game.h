#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>

#include <Map.h>
#include <BoomMan.h>
#include <Score.h>
#include <Health.h>

class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);
    QGraphicsScene * scene;
    BoomMan * player;
    Map * map;
    Score * score;
    Health * health;
};

#endif // GAME_H
