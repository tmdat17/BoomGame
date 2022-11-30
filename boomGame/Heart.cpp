#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScene>
#include <typeinfo>
#include <QList>
#include <QPixmap>
#include <QTransform>
#include <math.h>

#include "Heart.h"
#include "BoomMan.h"
#include "Enemy.h"
#include "Game.h"

extern Game * game; // there is an external global object called game
Heart::Heart(){
    QPixmap pic(":/images/dataset/hearts/heart.png");
    setPixmap(QPixmap(pic.scaled(50,50,Qt::KeepAspectRatio)));

    // set random position
    int random_move = rand() % 8;
    qDebug("so Heart random: %d", random_move);
    int random_numberX;
    int random_numberY;

    // goc trai tren
    if(random_move==0){
        random_numberX = rand() % (200 - 0 + 1) + 0;    //random (0,200)
        setPos(random_numberX,0);
    }
    // goc phai tren
    else if (random_move == 1){
        random_numberX = rand() % (950 - 750 + 1) + 750;    //random (950,750)
        setPos(random_numberX, 0);
    }

    // goc duoi trai
    else if (random_move == 2){
        random_numberY = rand() % (550 - 450 + 1) + 450;    //random (450,550)
        setPos(0, random_numberY);
    }

    // goc duoi phai
    else if (random_move == 3){
        random_numberX = rand() % (950 - 850 + 1) + 850;    //random (850,950)
        random_numberY = rand() % (550 - 450 + 1) + 450;    //random (450,550)

        setPos(random_numberX, random_numberY);
    }

    // ben trai
    else if (random_move == 4){

        random_numberY = rand() % (350 - 150 + 1) + 150;    //random (150,350)
        setPos(0, random_numberY);
    }
    // ben phai
    else if (random_move == 5){

        random_numberY = rand() % (350 - 150 + 1) + 150;    //random (150,350)
        setPos(950, random_numberY);
    }

    // ben tren
    else if (random_move == 6){
        random_numberX = rand() % (800 - 500 + 1) + 500;    //random (500,800)
        setPos(random_numberX, 0);
    }

    // ben duoi
    else if (random_move == 7){
        random_numberX = rand() % (800 - 500 + 1) + 500;    //random (500,800)
        setPos(random_numberX, 550);
    }
    // connect
    qDebug("heart:  %d",random_move);
    QTimer * timer = new QTimer();
    if(random_move == 0){
        connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top_left()));
        timer->start(30);

    }
    else if(random_move == 1){

        connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top_right()));
        timer->start(30);

    }
    else if(random_move == 2){
        connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom_left()));
        timer->start(30);

    }
    else if(random_move == 3){
        connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom_right()));
        timer->start(30);

    }
    else if(random_move == 4){
        connect(timer,SIGNAL(timeout()),this,SLOT(move_from_left()));
        timer->start(30);

    }
    else if(random_move == 5){
        connect(timer,SIGNAL(timeout()),this,SLOT(move_from_right()));
        timer->start(30);

    }
    else if(random_move == 6){
        connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top()));
        timer->start(30);

    }
    else if(random_move == 7){
        connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom()));
        timer->start(30);

    }
}

// move goc trai tren xuong goc phai duoi
void Heart::move_from_top_left(){
//    setPos(x()+5, y() + 5);

    int random_x = rand() % 10;
    int random_y = rand() % 10;
    setPos(x()+random_x, y() + random_y);
    if(pos().x() > 950 || pos().y() > 500){
        scene()->removeItem(this);
        delete this;
        //qDebug("enemy from top left is deleted");
    }
}

// move goc phai tren xuong goc phai duoi
void Heart::move_from_top_right(){
    int random_x = rand() % 10;
    int random_y = rand() % 10;
    setPos(x()-random_x, y() + random_y);
    if(pos().x()+10 < 0 || pos().y() > 565){
        scene()->removeItem(this);
        delete this;
        //qDebug("enemy from top right is deleted");
    }
}

// move goc trai duoi len goc phai tren
void Heart::move_from_bottom_left(){
    int random_x = rand() % 10;
    int random_y = rand() % 10;
    setPos(x()+random_x, y() - random_y);
    if(pos().x() > 995 || pos().y()+5 < 0){
        scene()->removeItem(this);
        delete this;
        //qDebug("enemy from bottom left is deleted");
    }
}

// move goc phai duoi len goc trai tren
void Heart::move_from_bottom_right(){
    int random_x = rand() % 10;
    int random_y = rand() % 10;
    setPos(x()-random_x, y() - random_y);
    if(pos().x()+5 < 0 || pos().y()+5 < 0){
        scene()->removeItem(this);
        delete this;
        //qDebug("enemy from bottom right is deleted");
    }
}

void Heart::move_from_left(){
    int random_x = rand() % 10;

    setPos(x()+random_x, y());
    if(pos().x() > 995){
        scene()->removeItem(this);
        delete this;
        //qDebug("enemy from left is deleted");
    }
}

void Heart::move_from_right(){
    int random_x = rand() % 10;

    setPos(x()-random_x, y());
    if(pos().x() + 5 < 0){
        scene()->removeItem(this);
        delete this;
        //qDebug("enemy from right is deleted");
    }
}

void Heart::move_from_top(){

    int random_y = rand() % 10;
    setPos(x(), y()+random_y);
    if(pos().y() > 565){
        scene()->removeItem(this);
        delete this;
        //qDebug("enemy from top is deleted");
    }
}

void Heart::move_from_bottom(){

    int random_y = rand() % 10;
    setPos(x(), y()-random_y);
    if(pos().y() + 5 < 0){
        scene()->removeItem(this);
        delete this;
        //qDebug("enemy from bottom is deleted");
    }
}
