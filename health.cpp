#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
  //initialize the score to 0
  health = 3;

  //draw the text
  setPlainText(QString("Health: ")+ QString::number(health));
  setDefaultTextColor(Qt::red);
  setFont(QFont("times",16));

}

void Health::decrease(){
  health--;
  setPlainText(QString("Health: ")+ QString::number(health));
}

void Health::increase(){
  health++;
  setPlainText(QString("Health: ")+ QString::number(health));
}

int Health::getHealth(){
  return health;
}
