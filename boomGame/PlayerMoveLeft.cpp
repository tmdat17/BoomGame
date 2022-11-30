#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>

#include "PlayerMoveLeft.h"

PlayerMoveLeft::PlayerMoveLeft()
{
    hinh=1;
    QTimer * timeDraw = new QTimer();
    connect(timeDraw,SIGNAL(timeout()),this,SLOT(drawPlayerMoveLeft()));
    timeDraw->start(20);
}

void PlayerMoveLeft::drawPlayerMoveLeft()
{
    QPixmap hinh1(":/images/dataset/character_move_left/playerMoveLeft1.png");
    QPixmap hinh2(":/images/dataset/character_move_left/playerMoveLeft2.png");
    QPixmap hinh3(":/images/dataset/character_move_left/playerMoveLeft3.png");
    QPixmap hinh4(":/images/dataset/character_move_left/playerMoveLeft4.png");

    switch(hinh){
        case 1:{
            setPixmap(hinh1.scaled(70,70));
            hinh = 2;
            break;
        }
        case 2:{
            setPixmap(hinh2.scaled(70,70));
            hinh = 3;
            break;
        }
        case 3:{
            setPixmap(hinh3.scaled(70,70));
            hinh = 4;
            break;
        }
        case 4:{
            setPixmap(hinh4.scaled(70,70));
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
