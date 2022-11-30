#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>

#include "PlayerMoveRight.h"

PlayerMoveRight::PlayerMoveRight()
{
    hinh=1;
    QTimer * timeDraw = new QTimer();
    connect(timeDraw,SIGNAL(timeout()),this,SLOT(drawPlayerMoveRight()));
    timeDraw->start(20);
}

void PlayerMoveRight::drawPlayerMoveRight()
{
    QPixmap hinh1(":/images/dataset/character_move_right/playerMoveRight1.png");
    QPixmap hinh2(":/images/dataset/character_move_right/playerMoveRight2.png");
    QPixmap hinh3(":/images/dataset/character_move_right/playerMoveRight3.png");
    QPixmap hinh4(":/images/dataset/character_move_right/playerMoveRight4.png");

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
