#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>

#include "PlayerVsEnemy.h"

PlayerVsEnemy::PlayerVsEnemy()
{
    hinh=1;
    QTimer * timeDraw = new QTimer();
    connect(timeDraw,SIGNAL(timeout()),this,SLOT(drawPlayerVsEnemy()));
    timeDraw->start(50);
}

void PlayerVsEnemy::drawPlayerVsEnemy()
{
    QPixmap hinh1(":/images/dataset/playerVsEnemy/playerEx1.png");
    QPixmap hinh2(":/images/dataset/playerVsEnemy/playerEx2.png");
    QPixmap hinh3(":/images/dataset/playerVsEnemy/playerEx3.png");
    QPixmap hinh4(":/images/dataset/playerVsEnemy/playerEx4.png");
    QPixmap hinh5(":/images/dataset/playerVsEnemy/playerEx5.png");
    QPixmap hinh6(":/images/dataset/playerVsEnemy/playerEx6.png");
    QPixmap hinh7(":/images/dataset/playerVsEnemy/playerEx7.png");
    QPixmap hinh8(":/images/dataset/playerVsEnemy/playerEx8.png");
    QPixmap hinh9(":/images/dataset/playerVsEnemy/playerEx9.png");
    QPixmap hinh10(":/images/dataset/playerVsEnemy/playerEx10.png");

    switch(hinh){
        case 1:{
            setPixmap(hinh1.scaled(80,80));
            hinh = 2;
            break;
        }
        case 2:{
            setPixmap(hinh2.scaled(80,80));
            hinh = 3;
            break;
        }
        case 3:{
            setPixmap(hinh3.scaled(80,80));
            hinh = 4;
            break;
        }
        case 4:{
            setPixmap(hinh4.scaled(80,80));
            hinh = 5;
            break;
        }
        case 5:{
            setPixmap(hinh5.scaled(80,80));
            hinh = 6;
            break;
        }
        case 6:{
            setPixmap(hinh6.scaled(80,80));
            hinh = 7;
            break;
        }
        case 7:{
            setPixmap(hinh7.scaled(80,80));
            hinh = 8;
            break;
        }
        case 8:{
            setPixmap(hinh8.scaled(80,80));
            hinh = 9;
            break;
        }
        case 9:{
            setPixmap(hinh9.scaled(80,80));
            hinh = 10;
            break;
        }
        case 10:{
            setPixmap(hinh10.scaled(80,80));
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
