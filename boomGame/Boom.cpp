#include <QTimer>
#include <QGraphicsScene>
#include <typeinfo>
#include <QList>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "Boom.h"
#include "Enemy.h"
#include "Game.h"

extern Game * game; // there is an external global object called game

Boom::Boom(){
    // draw the boom
     QPixmap pic(":/images/dataset/boom/boom.gif");
     setPixmap(QPixmap(pic.scaled(60,60,Qt::KeepAspectRatio)));
     setPos(x(),y());
     // connect
     QTimer * timer = new QTimer();
     connect(timer,SIGNAL(timeout()),this,SLOT(bomb_Explode()));
     timer->start(5000);

     QTimer * timeCollision = new QTimer();
     connect(timeCollision,SIGNAL(timeout()),this,SLOT(collision_bomb()));
     timeCollision->start(10);

}

void Boom::bomb_Explode(){
    scene()->removeItem(this);
    delete this;
    qDebug("Bomb Timeout!!");
}

void Boom::collision_bomb(){
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/sounds/music/mario_coin.mp3"));
            music->play();

            // increase score when bomb and enemy collision
            game->score->increase();

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            qDebug("Bomb Collision!!");
            delete colliding_items[i];
            delete this;

        }
    }
}
