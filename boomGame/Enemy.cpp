#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScene>
#include <typeinfo>
#include <QList>
#include <QPixmap>
#include <QTransform>

#include "BoomMan.h"
#include "Enemy.h"
#include "Game.h"

extern Game * game; // there is an external global object called game

Enemy::Enemy(){
    // draw the enemy
    QPixmap pic(":/images/dataset/bullets/bullet_no_bg.png");
    setPixmap(QPixmap(pic.scaled(50,50,Qt::KeepAspectRatio)));


    // set random position
    int random_move = rand() % 8;
//    qDebug("so random: %d", random_move);
    int random_numberX;
    int random_numberY;


    // goc trai tren
    if(random_move==0){
        QPixmap p2 = pic.transformed(QTransform().rotate(215));
        setPixmap(QPixmap(p2.scaled(68,68,Qt::KeepAspectRatio)));
        random_numberX = rand() % (200 - 0 + 1) + 0;    //random (0,200)

        setPos(random_numberX,0);
    }
    // goc phai tren
    else if (random_move == 1){
        QPixmap p2 = pic.transformed(QTransform().rotate(-35));
        setPixmap(QPixmap(p2.scaled(68,68,Qt::KeepAspectRatio)));
        random_numberX = rand() % (950 - 750 + 1) + 750;    //random (950,750)
        setPos(random_numberX, 0);
    }

    // goc duoi trai
    else if (random_move == 2){
        QPixmap p2 = pic.transformed(QTransform().rotate(145));
        setPixmap(QPixmap(p2.scaled(68,68,Qt::KeepAspectRatio)));
        random_numberY = rand() % (550 - 450 + 1) + 450;    //random (450,550)
        setPos(0, random_numberY);
    }

    // goc duoi phai
    else if (random_move == 3){
        QPixmap p2 = pic.transformed(QTransform().rotate(45));
        setPixmap(QPixmap(p2.scaled(68,68,Qt::KeepAspectRatio)));
        random_numberX = rand() % (950 - 850 + 1) + 850;    //random (850,950)
        random_numberY = rand() % (550 - 450 + 1) + 450;    //random (450,550)

        setPos(random_numberX, random_numberY);
    }

    // ben trai
    else if (random_move == 4){
        QPixmap p2 = pic.transformed(QTransform().rotate(180));
        setPixmap(QPixmap(p2.scaled(50,50,Qt::KeepAspectRatio)));
        random_numberY = rand() % (350 - 150 + 1) + 150;    //random (150,350)
        setPos(0, random_numberY);
    }
    // ben phai
    else if (random_move == 5){
        // hinh goc enemy huong ben phai nen truong hop nay khong xet
        random_numberY = rand() % (350 - 150 + 1) + 150;    //random (150,350)
        setPos(950, random_numberY);
    }

    // ben tren
    else if (random_move == 6){
        QPixmap p2 = pic.transformed(QTransform().rotate(-90));
        setPixmap(QPixmap(p2.scaled(50,50,Qt::KeepAspectRatio)));
        random_numberX = rand() % (800 - 500 + 1) + 500;    //random (500,800)
        setPos(random_numberX, 0);
    }

    // ben duoi
    else if (random_move == 7){
        QPixmap p2 = pic.transformed(QTransform().rotate(90));
        setPixmap(QPixmap(p2.scaled(50,50,Qt::KeepAspectRatio)));
        random_numberX = rand() % (800 - 500 + 1) + 500;    //random (500,800)
        setPos(random_numberX, 550);
    }

     // connect
     QTimer * timer = new QTimer();
     if(random_move == 0){
         if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top_left()));
             timer->start(40);
         }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top_left()));
             timer->start(20);
         }
         else{
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top_left()));
             timer->start(60);
         }
     }
     else if(random_move == 1){
         if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top_right()));
             timer->start(40);
         }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top_right()));
             timer->start(20);
         }
         else{
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top_right()));
             timer->start(60);
         }
     }
     else if(random_move == 2){
         if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom_left()));
             timer->start(40);
         }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom_left()));
             timer->start(20);
         }
         else{
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom_left()));
             timer->start(60);
         }


     }
     else if(random_move == 3){
         if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom_right()));
             timer->start(40);
         }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom_right()));
             timer->start(20);
         }
         else{
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom_right()));
             timer->start(60);
         }


     }
     else if(random_move == 4){
         if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_left()));
             timer->start(40);
         }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_left()));
             timer->start(20);
         }
         else{
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_left()));
             timer->start(60);
         }


     }
     else if(random_move == 5){
         if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_right()));
             timer->start(40);
         }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_right()));
             timer->start(20);
         }
         else{
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_right()));
             timer->start(60);
         }

     }
     else if(random_move == 6){
         if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top()));
             timer->start(40);
         }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top()));
             timer->start(20);
         }
         else{
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_top()));
             timer->start(60);
         }



     }
     else if(random_move == 7){
         if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom()));
             timer->start(40);
         }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom()));
             timer->start(20);
         }
         else{
             connect(timer,SIGNAL(timeout()),this,SLOT(move_from_bottom()));
             timer->start(60);
         }

     }
}

// move goc trai tren xuong goc phai duoi
void Enemy::move_from_top_left(){
    if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
        setPos(x()+25, y() + 15);
        if(pos().x() > 950 || pos().y() > 500){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from top left is deleted");
        }
    }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
        setPos(x()+28, y() + 18);
        if(pos().x() > 950 || pos().y() > 500){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from top left is deleted");
        }
    }else{
        setPos(x()+20, y() + 10);
        if(pos().x() > 950 || pos().y() > 500){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from top left is deleted");
        }
    }

}

// move goc phai tren xuong goc phai duoi
void Enemy::move_from_top_right(){
    if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
        setPos(x()-25, y() + 15);
        if(pos().x()+30 < 0 || pos().y() > 500){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from top right is deleted");
        }
    }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
        setPos(x()-28, y() + 18);
        if(pos().x()+30 < 0 || pos().y() > 500){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from top right is deleted");
        }
    }else{
        setPos(x()-20, y() + 10);
        if(pos().x()+30 < 0 || pos().y() > 500){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from top right is deleted");
        }
    }


}

// move goc trai duoi len goc phai tren
void Enemy::move_from_bottom_left(){
    if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
        setPos(x()+25, y() - 15);
        if(pos().x() > 950 || pos().y()+30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from top right is deleted");
        }
    }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
        setPos(x()+28, y() - 18);
        if(pos().x() > 950 || pos().y()+30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from top right is deleted");
        }
    }else{
        setPos(x()+20, y() - 10);
        if(pos().x() > 950 || pos().y()+30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from bottom left is deleted");
        }
    }


}

// move goc phai duoi len goc trai tren
void Enemy::move_from_bottom_right(){
    if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
        setPos(x()-25, y() - 15);
        if(pos().x()+30 < 0 || pos().y()+30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from bottom right is deleted");
        }
    }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
        setPos(x()-28, y() - 18);
        if(pos().x()+30 < 0 || pos().y()+30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from bottom right is deleted");
        }
    }else{
        setPos(x()-20, y() - 10);
        if(pos().x()+30 < 0 || pos().y()+30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from bottom right is deleted");
        }
    }


}

void Enemy::move_from_left(){
    if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
        setPos(x()+25, y());
        if(pos().x() > 950){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from left is deleted");
        }
    }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
        setPos(x()+28, y());
        if(pos().x() > 950){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from left is deleted");
        }
    }else{
        setPos(x()+20, y());
        if(pos().x() > 950){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from left is deleted");
        }
    }


}

void Enemy::move_from_right(){
    if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
        setPos(x()-25, y());
        if(pos().x() + 30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from right is deleted");
        }
    }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
        setPos(x()-28, y());
        if(pos().x() + 30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from right is deleted");
        }
    }else{
        setPos(x()-20, y());
        if(pos().x() + 30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from right is deleted");
        }
    }

}

void Enemy::move_from_top(){
    if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
        setPos(x(), y()+25);
        if(pos().y() > 500){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from top is deleted");
        }
    }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
        setPos(x(), y()+28);
        if(pos().y() > 500){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from top is deleted");
        }
    }else{
        setPos(x(), y()+20);
        if(pos().y() > 500){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from top is deleted");
        }
    }


}

void Enemy::move_from_bottom(){
    if((game->health->getHealth() >= 10 && game->health->getHealth() < 15) || (game->score->getScore() >= 10 && game->score->getScore() < 15)){
        setPos(x(), y()-25);
        if(pos().y() + 30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from bottom is deleted");
        }
    }else if(game->health->getHealth() >= 15 || game->score->getScore() >= 15){
        setPos(x(), y()-28);
        if(pos().y() + 30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from bottom is deleted");
        }
    }else{
        setPos(x(), y()-20);
        if(pos().y() + 30 < 0){
            scene()->removeItem(this);
            delete this;
            //qDebug("enemy from bottom is deleted");
        }
    }


}
