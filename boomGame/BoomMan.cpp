#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>
#include <QMovie>
#include <QBitmap>
#include <QPixmap>
#include <typeinfo>
#include <QList>
#include <QTimer>
#include <QMediaPlayer>

#include "Boom.h"
#include "Enemy.h"
#include "BoomMan.h"
#include "Game.h"

//BoomMan::BoomMan(){
//    QLabel * label = new QLabel();
//    label->setWindowFlags(Qt::FramelessWindowHint);
//    label->setMask((new QPixmap(":/images/dataset/character_stand_still/character_stand_still.gif"))->mask());
//    QMovie *movie = new QMovie(":/images/dataset/character_stand_still/character_stand_still.gif");
//    label->setMovie(movie);
//    movie->start();

//    label->show();

//}

extern Game * game; // there is an external global object called game

BoomMan::BoomMan(){

    QTimer * timeCollision = new QTimer();
    connect(timeCollision,SIGNAL(timeout()),this,SLOT(collision_boomman()));
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

void BoomMan::collision_boomman(){
    // handle colliding

   // QMediaPlayer * music = new QMediaPlayer();
    QList<QGraphicsItem *> list = collidingItems() ;

    foreach(QGraphicsItem * i , list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item)
        {
           QMediaPlayer * music = new QMediaPlayer();
           game->health->decrease();
           music->setMedia(QUrl("qrc:/sounds/music/explosion.mp3"));
           music->play();
           if (game->health->getHealth() == 0){
               // remove them both
               scene()->removeItem(item);
               delete item;
               scene()->removeItem(this);
               delete this;
           }else {
               scene()->removeItem(item);
               delete item;
           }

        }
    }

}
