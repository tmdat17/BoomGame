#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>

#include "FlashUp.h"

FlashUp::FlashUp()
{
    hinh=1;
    QTimer * timeDraw = new QTimer();
    connect(timeDraw,SIGNAL(timeout()),this,SLOT(drawFlashUp()));
    timeDraw->start(50);
}

void FlashUp::drawFlashUp()
{
    QPixmap hinh1(":/images/dataset/flashUp/flash1-up.png");
    QPixmap hinh2(":/images/dataset/flashUp/flash2-up.png");
    QPixmap hinh3(":/images/dataset/flashUp/flash3-up.png");
    QPixmap hinh4(":/images/dataset/flashUp/flash4-up.png");
    QPixmap hinh5(":/images/dataset/flashUp/flash5-up.png");

    switch(hinh){
        case 1:{
            setPixmap(hinh1.scaled(90,90));
            hinh = 2;
            break;
        }
        case 2:{
            setPixmap(hinh2.scaled(90,90));
            hinh = 3;
            break;
        }
        case 3:{
            setPixmap(hinh3.scaled(90,90));
            hinh = 4;
            break;
        }
        case 4:{
            setPixmap(hinh4.scaled(90,90));
            hinh = 5;
            break;
        }
        case 5:{
            setPixmap(hinh5.scaled(90,90));
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
