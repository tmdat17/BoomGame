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
#include <QWidget>
#include <QGraphicsView>

#include "Heart.h"
#include "Boom.h"
#include "Enemy.h"
#include "BoomMan.h"
#include "Game.h"
#include "Boommandie.h"
#include "PlayerVsEnemy.h"
#include "Flash.h"
#include "FlashLeft.h"
#include "FlashUp.h"
#include "FlashDown.h"
#include "PlayerMoveRight.h"
#include "PlayerMoveDown.h"
#include "PlayerMoveLeft.h"
#include "PlayerMoveTop.h"

extern Game * game; // there is an external global object called game

BoomMan::BoomMan(){
    QTimer * timeCollision = new QTimer();
    connect(timeCollision,SIGNAL(timeout()),this,SLOT(collision_boomman()));
    timeCollision->start(10);

    connect(timeCollision,SIGNAL(timeout()),this,SLOT(pick_a_heart()));
    timeCollision->start(10);

    hinh=1;
    QTimer * timeDraw = new QTimer();
    connect(timeDraw,SIGNAL(timeout()),this,SLOT(drawBoomMan()));
    timeDraw->start(50);
}

void BoomMan::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left){
        if(pos().x() > 35){
            setPos(x()-35,y());
            PlayerMoveLeft *moveLeft = new PlayerMoveLeft();
            moveLeft->setPos(x(), y());
            scene()->addItem(moveLeft);
        }

    }
    // flash trai
    else if (event->key() == Qt::Key_A){
        if(pos().x() > 75){
            setPos(x()-70,y());
            FlashLeft *flashLeft = new FlashLeft();
            flashLeft->setPos(x()+50, y());
            scene()->addItem(flashLeft);
        }

    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x() < 915){
            setPos(x()+35,y());
            PlayerMoveRight *moveRight = new PlayerMoveRight();
            moveRight->setPos(x(), y());
            scene()->addItem(moveRight);
        }

    }

    // flash phai
    else if (event->key() == Qt::Key_D){
        if(pos().x() < 885){
             setPos(x()+70,y());
             Flash *flash = new Flash();
             flash->setPos(x()-50, y());
             scene()->addItem(flash);
        }

    }

    else if (event->key() == Qt::Key_Up){
        if(pos().y() > 35){
            setPos(x(),y()-35);
            PlayerMoveTop *moveTop = new PlayerMoveTop();
            moveTop->setPos(x(), y());
            scene()->addItem(moveTop);
        }

    }
    // flash len
    else if (event->key() == Qt::Key_W){
        if(pos().y() > 70){
            setPos(x(),y()-70);
            FlashUp *flashUp = new FlashUp();
            flashUp->setPos(x(), y()+50);
            scene()->addItem(flashUp);
        }

    }

    else if (event->key() == Qt::Key_Down){
        if(pos().y() < 465){
            setPos(x(),y()+35);
            PlayerMoveDown *moveDown = new PlayerMoveDown();
            moveDown->setPos(x(), y());
            scene()->addItem(moveDown);
        }

    }
    // flash xuong
    else if (event->key() == Qt::Key_S){
        if(pos().y() < 395){
            setPos(x(),y()+70);
            FlashDown *flashDown = new FlashDown();
            flashDown->setPos(x(), y()-50);
            scene()->addItem(flashDown);
        }

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

//    }
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

               BoomManDie *player_die = new BoomManDie();
               player_die->setPos(x(), y());
               scene()->addItem(player_die);

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

               PlayerVsEnemy *player = new PlayerVsEnemy();
               player->setPos(x(), y());
               scene()->addItem(player);

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

void BoomMan::drawBoomMan(){
    QPixmap hinh1(":/images/dataset/character_stand_still/boman1.png");
    QPixmap hinh2(":/images/dataset/character_stand_still/boman2.png");
    QPixmap hinh3(":/images/dataset/character_stand_still/boman3.png");
    QPixmap hinh4(":/images/dataset/character_stand_still/boman4.png");
    QPixmap hinh5(":/images/dataset/character_stand_still/boman5.png");
    QPixmap hinh6(":/images/dataset/character_stand_still/boman6.png");
    QPixmap hinh7(":/images/dataset/character_stand_still/boman7.png");
    QPixmap hinh8(":/images/dataset/character_stand_still/boman8.png");
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
            hinh = 5;
            break;
        }
        case 5:{
            setPixmap(hinh5.scaled(70,70));
            hinh = 6;
            break;
        }
        case 6:{
            setPixmap(hinh6.scaled(70,70));
            hinh = 7;
            break;
        }
        case 7:{
            setPixmap(hinh7.scaled(70,70));
            hinh = 8;
            break;
        }
        case 8:{
            setPixmap(hinh8.scaled(70,70));
            hinh = 1;
            break;
        }
        default:{
            break;
        }
    }
}

