#ifndef FLASH_H
#define FLASH_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Flash: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Flash();
    int hinh;
public slots:
    void drawFlash();

};

#endif // FLASH_H
