#ifndef BOOMMANDIE_H
#define BOOMMANDIE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class BoomManDie: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    BoomManDie();
    int hinh;
public slots:
    void drawPlayerDie();
};

#endif // BOOMMANDIE_H
