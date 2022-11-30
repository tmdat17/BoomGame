#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>

#include "BoomManDie.h"

BoomManDie::BoomManDie()
{
    hinh=1;
    QTimer * timeDraw = new QTimer();
    connect(timeDraw,SIGNAL(timeout()),this,SLOT(drawPlayerDie()));
    timeDraw->start(50);
}

void BoomManDie::drawPlayerDie()
{
    QPixmap hinh1(":/images/dataset/character_die/playerDie1.png");
    QPixmap hinh2(":/images/dataset/character_die/playerDie2.png");
    QPixmap hinh3(":/images/dataset/character_die/playerDie3.png");
    QPixmap hinh4(":/images/dataset/character_die/playerDie4.png");
    QPixmap hinh5(":/images/dataset/character_die/playerDie5.png");
    QPixmap hinh6(":/images/dataset/character_die/playerDie6.png");

    switch(hinh){
        case 1:{
            setPixmap(hinh1.scaled(60,60));
            hinh = 2;
            break;
        }
        case 2:{
            setPixmap(hinh2.scaled(60,60));
            hinh = 3;
            break;
        }
        case 3:{
            setPixmap(hinh3.scaled(60,60));
            hinh = 4;
            break;
        }
        case 4:{
            setPixmap(hinh4.scaled(60,60));
            hinh = 5;
            break;
        }
        case 5:{
            setPixmap(hinh5.scaled(60,60));
            hinh = 6;
            break;
        }
        case 6:{
            setPixmap(hinh6.scaled(60,60));
            hinh = 0;
            break;
        }
        case 0:{
            scene()->removeItem(this);
            delete this;
            break;
        }
        default:{
            scene()->removeItem(this);
            delete this;
            break;
        }
    }
}


