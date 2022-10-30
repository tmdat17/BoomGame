#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>

class Tile: public QGraphicsPixmapItem{
public:
    Tile();
    Tile(int x, int y);
};

#endif // TILE_H
