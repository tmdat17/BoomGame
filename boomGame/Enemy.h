#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy();
public slots:
    void move_from_top_left();
    void move_from_top_right();
    void move_from_bottom_left();
    void move_from_bottom_right();
    void move_from_left();
    void move_from_right();
    void move_from_top();
    void move_from_bottom();
};


#endif // ENEMY_H
