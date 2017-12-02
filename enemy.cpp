#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "game.h"
#include <typeinfo>
#include "include.h"

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
  setZValue(-0.1);
    //set random number
  randomMovePixel = Include::randomInInterval(8,15);
  random_number = Include::randomInInterval(10,550);
  setPos(game->displayWidth  , random_number);
 //drawing the rectangle
  int randomPlane = (rand() % 4);
  switch (randomPlane){
    case 0:{
      setPixmap(QPixmap(":/images/Sprites/enemy_fly.png"));
      break;
     }
    case 1:{
      setPixmap(QPixmap(":/images/Sprites/enemyII_fly.png"));
      break;
     }
    case 2:{
      setPixmap(QPixmap(":/images/Sprites/enemyIII_fly.png"));
      break;
     }
    case 3:{
      setPixmap(QPixmap(":/images/Sprites/enemyIV_fly.png"));
      break;
     }

  }


 QTimer *timer = new QTimer();
 connect(timer, SIGNAL(timeout()),this, SLOT(move()));

 //every rand ms timeout signal will be emitted and enemy will move
 timer->start(50);

}

void Enemy::move(){

  QList<QGraphicsItem *> colliding_items = collidingItems();
  for (int i=0, n=colliding_items.size();i<n; ++i){
      if (typeid(*(colliding_items[i])) == typeid(Player)){
          //decrease the health
          game->health->decrease();
          if(game->player){
              game->player->setPixmap(QPixmap(":/images/Sprites/player_hit.png"));
              game->player->playerHit = 1;
          }
          scene()->removeItem(this);
          //delete them both
          //delete colliding_items[i];
          delete this;
          return;
        }
     }
 //move Enemy right
 setPos(x()-randomMovePixel,y());

 if(pos().x () < (-100)){
     scene()->removeItem(this);
     delete this;
   }
}
