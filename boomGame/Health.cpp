#include "QFont"

#include "Health.h"

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 5;

    // draw the text
    setPlainText(QString("Remaining Health: ") + QString::number(health)); // Score: 0
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times", 16, 75)); //fontStyle, font-size, weight

}

void Health::decrease(){
    health--;
    setPlainText(QString("Remaining Health: ") + QString::number(health)); // Update Health: --
}

void Health::increase(){
    health++;
    setPlainText(QString("Remaining Health: ") + QString::number(health)); // Update Health: ++

}

int Health::getHealth(){
    return health;
}
