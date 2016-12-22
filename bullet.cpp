#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <enemy.h>
#include <typeinfo>
#include "game.h"

#include <QDebug>

extern Game *game;


Bullet::Bullet(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
  //draw graphics
  setPixmap(QPixmap(":/images/bullet.png"));

  //connecting signal with slots
  QTimer *timer = new QTimer();
  connect(timer,SIGNAL(timeout()), this,SLOT(move()));
  //arguments- 1. object whose signal you want to connect
  //           2. funcion of signals'
  //           3. this(Bullet)
  //           4. function of slot
  timer->start(50);
}

void Bullet::move(){
  //if bullet collides with enemy delete both
  QList<QGraphicsItem *> colliding_items= collidingItems();

  //collidingItem() returns a list of pointers of all QGraphicsItem that the object is colliding with.
  for (int i=0, n =colliding_items.size(); i<n; ++i){
      if(typeid(*(colliding_items[i]))== typeid(Enemy)){
          //increase the score
          game->score->increase();
          //remove them both
          scene()->removeItem(colliding_items[i]);
          scene()->removeItem(this);
          //delating to free memory
          delete colliding_items[i];
          delete this;
          return;
        }
    }
  //move bullet up
  setPos(x(),y()-10);
  //delating the thrown bullet
  if(pos().y()+ 50 < 0){
      scene()->removeItem(this);
      delete this;
      qDebug()<<"Bullet Deleated";
    }
}
