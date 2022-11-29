#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QMovie>
#include <QBitmap>
#include <QPixmap>
#include <typeinfo>
#include <QList>
#include <QTimer>
#include <QMediaPlayer>

#include "Heart.h"
#include "Boom.h"
#include "Enemy.h"
#include "BoomMan.h"
#include "Game.h"

extern Game * game; // there is an external global object called game

BoomMan::BoomMan(){

    QTimer * timeCollision = new QTimer();
    connect(timeCollision,SIGNAL(timeout()),this,SLOT(collision_boomman()));
    timeCollision->start(10);

    connect(timeCollision,SIGNAL(timeout()),this,SLOT(pick_a_heart()));
    timeCollision->start(10);

}

void BoomMan::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if(pos().x() > 35)
            setPos(x()-35,y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x() < 915)
            setPos(x()+35,y());
    }
    else if (event->key() == Qt::Key_Up){
        if(pos().y() > 35)
            setPos(x(),y()-35);
    }
    else if (event->key() == Qt::Key_Down){
        if(pos().y() < 465)
            setPos(x(),y()+35);
    }

    else if (event->key() == Qt::Key_Space){
        // create a boom
        Boom * boom = new Boom();
        boom->setPos(x(),y());
        scene()->addItem(boom);
    }
}

void BoomMan::spawn(){
    // create the enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void BoomMan::spawnHeart(){
     // create the heart
    Heart * heart = new Heart();
    scene()->addItem(heart);
}

void BoomMan::collision_boomman(){
    // handle colliding
    QList<QGraphicsItem *> list = collidingItems() ;

    foreach(QGraphicsItem * i , list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item)
        {

           if (game->health->getHealth() == 1){

               QMediaPlayer * music = new QMediaPlayer();
               game->health->decrease();
               music->setMedia(QUrl("qrc:/sounds/music/challenge_lose.mp3"));
               music->play();
               // remove them both
               scene()->removeItem(item);
               delete item;
               scene()->removeItem(this);
               delete this;

           }else {
               QMediaPlayer * music = new QMediaPlayer();
               game->health->decrease();
               music->setMedia(QUrl("qrc:/sounds/music/explosion.mp3"));
               music->play();
               scene()->removeItem(item);
               delete item;
           }

        }
    }

}

void BoomMan::pick_a_heart(){
    QList<QGraphicsItem *> list = collidingItems() ;
    foreach(QGraphicsItem * i , list){
        Heart * item= dynamic_cast<Heart *>(i);
        if (item)
        {
            QMediaPlayer * music = new QMediaPlayer();
            game->health->increase();
            music->setMedia(QUrl("qrc:/sounds/music/pick_heart.mp3"));
            music->play();
            scene()->removeItem(item);
            delete item;
        }
    }
}

