#ifndef BOOMMAN_H
#define BOOMMAN_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>

class BoomMan: public QObject ,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    BoomMan();
    void keyPressEvent(QKeyEvent * events);
public slots:
    void spawn();
    void collision_boomman();
};

#endif // BOOMMAN_H
