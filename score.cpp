#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
  //initialize the score to 0
  score = 0;

  //draw the text
  setPlainText(QString::number(score));
  setDefaultTextColor(Qt::blue);
  setFont(QFont("times",16));
  setZValue(5);

}

void Score::increase(){
  score++;
  //
  setPlainText(QString::number(score));
}

int Score::getScore(){
  return score;
}
