#include "healthpop.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "game.h"
#include <typeinfo>
#include "include.h"

extern Game *game;

HealthPop::HealthPop(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
  //set random number
  int random_number = (rand() % game->displayHeight );
  setPos(game->displayWidth  , random_number);
  setPixmap(QPixmap(":/images/healthInc.png"));

 QTimer *timer = new QTimer();
 connect(timer, SIGNAL(timeout()),this, SLOT(move()));

 //every rand ms timeout signal will be emitted and enemy will move
 timer->start(50);

}

void HealthPop::move(){

  QList<QGraphicsItem *> colliding_items = collidingItems();
  for (int i=0, n=colliding_items.size();i<n; ++i){
      if (typeid(*(colliding_items[i])) == typeid(Player)){
          //decrease the health
          game->health->increase();
          //remove them both from scene (still exists on heap)
          //scene()->removeItem(colliding_items[i]); aka player
          scene()->removeItem(this);
          //delete them both
          //delete colliding_items[i];
          delete this;
          return;
        }
     }
 //move Enemy right
 setPos(x()-15,y());

 if(pos().x () < (-50)){
     scene()->removeItem(this);
     delete this;
   }
}
