#ifndef FLASHDOWN_H
#define FLASHDOWN_H

#include <QGraphicsPixmapItem>
#include <QObject>

class FlashDown: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    FlashDown();
    int hinh;
public slots:
    void drawFlashDown();
};

#endif // FLASHDOWN_H
