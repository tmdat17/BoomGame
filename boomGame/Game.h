#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>

#include <BoomMan.h>
#include <Score.h>
#include <Health.h>
#include <Heart.h>
#include <GameOver.h>

class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);
    QGraphicsScene * scene;
    BoomMan * player;

    Score * score;
    Health * health;
    Heart * heart;
    GameOver *gameOver;
};

#endif // GAME_H
