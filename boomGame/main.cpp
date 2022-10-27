#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QGraphicsPixmapItem>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,500,900); // set width height for scene


    // create an item to add to the scene
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(80,500,50,90);

    QGraphicsPixmapItem * pixmapItem = new QGraphicsPixmapItem();

    pixmapItem->setPixmap(QPixmap(":/images/dataset/character_stand_still/character_stand_still.gif"));


    // add the item to the scene
    scene->addItem(rect);

   // scene->addItem(pixmapItem);

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();
    return a.exec();
}
