#ifndef FLASHUP_H
#define FLASHUP_H

#include <QGraphicsPixmapItem>
#include <QObject>

class FlashUp: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    FlashUp();
    int hinh;
public slots:
    void drawFlashUp();

};

#endif // FLASHUP_H
