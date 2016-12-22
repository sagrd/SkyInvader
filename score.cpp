#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
  score = 0;

  //draw the text
  setPlainText(QString("Score: ") + QString::number(score));
  setDefaultTextColor(Qt::blue);
  setFont(QFont("times",16));
}

void Score::increase()
{
  score++;
  //draw the text
  setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
  return score;
}
