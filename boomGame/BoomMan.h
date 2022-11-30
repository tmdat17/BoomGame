#ifndef BOOMMAN_H
#define BOOMMAN_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>

class BoomMan: public QObject ,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    BoomMan();
    int hinh;
    void keyPressEvent(QKeyEvent * events);
public slots:
    void spawn();
    void spawnHeart();
    void collision_boomman();
    void pick_a_heart();
    void drawBoomMan();
};

#endif // BOOMMAN_H
