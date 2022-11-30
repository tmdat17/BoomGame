#include <QTimer>
#include <QGraphicsScene>
#include <typeinfo>
#include <QList>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPixmap>

#include "Boom.h"
#include "Enemy.h"
#include "Game.h"
#include "Explosion.h"

extern Game * game; // there is an external global object called game

Boom::Boom(){
     setPos(x(),y());
     // connect
     QTimer * timer = new QTimer();
     connect(timer,SIGNAL(timeout()),this,SLOT(bomb_Explode()));
     timer->start(5000);

     QTimer * timeCollision = new QTimer();
     connect(timeCollision,SIGNAL(timeout()),this,SLOT(collision_bomb()));
     timeCollision->start(10);

     hinh=1;
     QTimer * timeDraw = new QTimer();
     connect(timeDraw,SIGNAL(timeout()),this,SLOT(drawBomb()));
     timeDraw->start(50);
}

void Boom::bomb_Explode(){
    scene()->removeItem(this);
    delete this;
    qDebug("Bomb Timeout!!");
}

void Boom::collision_bomb(){
    QList<QGraphicsItem *> list = collidingItems() ;

    foreach(QGraphicsItem * i , list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item)
        {

            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/sounds/music/mario_coin.mp3"));
            music->play();
            Explosion *explo = new Explosion();
            explo->setPos(x(), y());
            scene()->addItem(explo);

            // increase score when bomb and enemy collision
            game->score->increase();

            // remove them both
            scene()->removeItem(item);
            scene()->removeItem(this);
            // delete them both
            qDebug("Bomb Collision!!");
            delete item;
            delete this;

        }
    }
}

void Boom::drawBomb(){
    QPixmap hinh1(":/images/dataset/boom/bom1.png");
    QPixmap hinh2(":/images/dataset/boom/bom2.png");
    QPixmap hinh3(":/images/dataset/boom/bom3.png");
    QPixmap hinh4(":/images/dataset/boom/bom4.png");
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
            hinh = 1;
            break;
        }
        default:{
            break;
        }
    }
}
