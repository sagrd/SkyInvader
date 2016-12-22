#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
  health = 3; //initialized value of health

  //draw the text
  setPlainText(QString("Health: ") + QString::number(health));
  setDefaultTextColor(Qt::red);
  setFont(QFont("times",16));
}

void Health::decrease()
{
  health--;
  //draw the text
  setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
  return health;
}
