#ifndef FLASHLEFT_H
#define FLASHLEFT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class FlashLeft: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    FlashLeft();
    int hinh;
public slots:
    void drawFlashLeft();

};

#endif // FLASHLEFT_H
