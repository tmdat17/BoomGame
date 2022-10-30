#include "BoomMan.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <Boom.h>
#include <Enemy.h>
#include <QDebug>
#include <QLabel>
#include <QMovie>
#include <QBitmap>
#include <QPixmap>

//BoomMan::BoomMan(){
//    QLabel * label = new QLabel();
//    label->setWindowFlags(Qt::FramelessWindowHint);
//    label->setMask((new QPixmap(":/images/dataset/character_stand_still/character_stand_still.gif"))->mask());
//    QMovie *movie = new QMovie(":/images/dataset/character_stand_still/character_stand_still.gif");
//    label->setMovie(movie);
//    movie->start();

//    label->show();

//}

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
