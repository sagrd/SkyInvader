#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"

#include <QDebug>

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent):QObject(),QGraphicsRectItem(parent){
  //sets random position for enemy
  int random_number= rand()%700;
  setPos(random_number,0);

  //draw the rect
  setRect(0,0,100,100);

  //connecting signal with slots
  QTimer *timer = new QTimer();
  connect(timer,SIGNAL(timeout()), this,SLOT(move()));
  timer->start(50);
}

void Enemy::move()
{

  //move enemy down

  setPos(x(),y()+5);
  //delating the thrown bullet
  if(pos().y()>600){
      //decreasing the health
      game->health->decrease();
      scene()->removeItem(this);
      delete this;
      qDebug()<<"Bullet Deleated";
    }
}
