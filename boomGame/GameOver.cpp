#include <QTimer>
#include <QPixmap>

#include "GameOver.h"
#include "Game.h"

extern Game * game; // there is an external global object called game

GameOver::GameOver()
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(drawGameOver()));
    timer->start(30);
}

void GameOver::drawGameOver()
{
    if(game->health->getHealth() == 0){
        setPixmap(QPixmap(":/images/dataset/gameOver/gameOver1.png").scaled(500,500));
        setPos(240, 0);
    }
}
