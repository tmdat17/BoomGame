#ifndef HEART_H
#define HEART_H

#include <QGraphicsPixmapItem>

class Heart: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Heart();
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

#endif // HEART_H
