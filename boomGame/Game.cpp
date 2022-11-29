#include <Game.h>
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QPainter>
#include <QMediaPlayer>
#include <QMediaPlaylist>


Game::Game(QWidget *parent){
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,570); // set width height for scene
//    scene->setBackgroundBrush((QBrush(QImage(":/images/dataset/background/map_midlane1046x1046.jpg"))));
    scene->setBackgroundBrush((QBrush(QImage(":/images/dataset/background/bg1.png"))));

    // create a map
//    map = new Map();

    // create player
    player = new BoomMan();
    player->setPixmap(QPixmap(":/images/dataset/character_stand_still/character_stand_still.gif"));
    player->setPos(scene->width()/2,scene->height()/2);

//    // make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add the player to the scene
    scene->addItem(player);

    // create the score
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(x(),y()+30);
    scene->addItem(health);

    heart = new Heart();
    scene->addItem(heart);

    // spwan enemies
   QTimer * timer = new QTimer();
   int numEnemy = 0;
   for(int i=0; i <= numEnemy; i++){
       QObject::connect(timer, SIGNAL(timeout()),player,SLOT(spawn()));
       timer->start(1000);
   }

   int random_time_heart = rand() % (15000 - 8000 + 1) + 8000;
   qDebug("time heart: %d  ", random_time_heart);
   // spawn hearts
   QTimer * timerHeart = new QTimer();
   int numHeart = 1;
   for(int i=0; i <= numHeart; i++){
       QObject::connect(timerHeart, SIGNAL(timeout()),player,SLOT(spawnHeart()));
       timerHeart->start(random_time_heart);
   }

   // play background music

      QMediaPlaylist *playlist = new QMediaPlaylist();
      playlist->addMedia(QUrl("qrc:/sounds/music/musicBg.mp3"));
      playlist->setPlaybackMode(QMediaPlaylist::Loop);

      QMediaPlayer *music = new QMediaPlayer();
      music->setPlaylist(playlist);
      music->play();


   // add a view
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();

}
