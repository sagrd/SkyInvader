#include "health.h"
#include <QFont>
#include "game.h"
#include "score.h"

extern Game *game;
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
  //initialize the score to 0
  health = 3;

  //draw the text
  setPlainText(QString::number(health));
  setDefaultTextColor(Qt::red);
  setFont(QFont("times",16));
  setZValue(5);

}

void Health::decrease(){
  if(health > 0){
    health--;
    setPlainText(QString::number(health));
  }else{
      game->isPlayerAlive = false;
      game->prepareToReplay();
      game->displayMainMenu();
    }
}

void Health::increase(){
  health++;
  setPlainText(QString::number(health));
}

int Health::getHealth(){
  return health;
}
