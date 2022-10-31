#include "QFont"

#include "Score.h"
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16)); //fontStyle, font-size

}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Update Score: ++
}

int Score::getScore(){
    return  score;
}
