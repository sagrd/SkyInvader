 #include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "game.h"


extern Game *game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

  setPixmap(QPixmap(":/images/bullet_const.png"));

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()),this, SLOT(move()));
  timer->start(50);

}

void Bullet::move(){
  //on collision destroy both
  QList<QGraphicsItem *> colliding_items = collidingItems();
  for (int i=0, n=colliding_items.size();i<n; ++i){
      if (typeid(*(colliding_items[i])) == typeid(Enemy)){

          game->score->increase();

          //remove them both from scene (still exists on heap)
          scene()->removeItem(colliding_items[i]);
          scene()->removeItem(this);

          //delete them both
          delete colliding_items[i];
          delete this;
          return;
        }
    }

  //move bullet right
  setPos(x()+25,y());
  if((pos().x () > scene()->width()) || (pos().x () < 0) || (pos().y () > scene()->height()) ||(pos().y ()< 0 )){
      scene()->removeItem(this);
      delete this;
    }
}
