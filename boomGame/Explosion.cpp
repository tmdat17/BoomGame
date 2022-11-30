#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>

#include "Explosion.h"

Explosion::Explosion()
{
    hinh=1;
    QTimer * timeDraw = new QTimer();
    connect(timeDraw,SIGNAL(timeout()),this,SLOT(drawExplosion()));
    timeDraw->start(50);
}

void Explosion::drawExplosion()
{
    QPixmap hinh1(":/images/dataset/bigbang/explo1.png");
    QPixmap hinh2(":/images/dataset/bigbang/explo2.png");
    QPixmap hinh3(":/images/dataset/bigbang/explo3.png");
    QPixmap hinh4(":/images/dataset/bigbang/explo4.png");
    QPixmap hinh5(":/images/dataset/bigbang/explo5.png");
    QPixmap hinh6(":/images/dataset/bigbang/explo6.png");
    QPixmap hinh7(":/images/dataset/bigbang/explo7.png");

    switch(hinh){
        case 1:{
            setPixmap(hinh1.scaled(50,50));
            hinh = 2;
            break;
        }
        case 2:{
            setPixmap(hinh2.scaled(50,50));
            hinh = 3;
            break;
        }
        case 3:{
            setPixmap(hinh3.scaled(50,50));
            hinh = 4;
            break;
        }
        case 4:{
            setPixmap(hinh4.scaled(50,50));
            hinh = 5;
            break;
        }
        case 5:{
            setPixmap(hinh5.scaled(50,50));
            hinh = 6;
            break;
        }
        case 6:{
            setPixmap(hinh6.scaled(50,50));
            hinh = 7;
            break;
        }
        case 7:{
            setPixmap(hinh7.scaled(50,50));
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
