 #include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "game.h"
#include <QDebug>


extern Game *game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

  setPixmap(QPixmap(":/images/Sprites/bullet_const.png"));

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()),this, SLOT(move()));
  timer->start(50);

}

void Bullet::move(){
  //move bullet right
  setPos(x()+30,y());
  if((pos().x () > scene()->width()) || (pos().x () < 0) || (pos().y () > scene()->height()) ||(pos().y ()< 0 )){
      scene()->removeItem(this);
      delete this;
      if(game->isPlayerAlive == false){
          return;
      }
      game->player->noOfBullet--;
      game->player->bulletPixmap();

    }
  if(game->isPlayerAlive == false){
      return;
  }
  //on collision destroy both
  QList<QGraphicsItem *> colliding_items = collidingItems();
  for (int i=0, n=colliding_items.size();i<n; ++i){
      if (typeid(*(colliding_items[i])) == typeid(Enemy)){

          game->score->increase();

          //remove them both from scene (still exists on heap)
          scene()->removeItem(colliding_items[i]);
          scene()->removeItem(this);
          game->player->noOfBullet--;
          game->player->bulletPixmap();
          //delete them both
          delete colliding_items[i];

          delete this;
          return;
        }
      else if (typeid(*(colliding_items[i])) == typeid(Ship)){

          game->score->increase();

          //remove them both from scene (still exists on heap)
          scene()->removeItem(colliding_items[i]);
          scene()->removeItem(this);
          game->player->bulletPixmap();

          //delete them both
          delete colliding_items[i];
          delete this;
          return;
        }
      else if (typeid(*(colliding_items[i])) == typeid(Boss)){

          game->score->increase();

          //remove them both from scene (still exists on heap)
          scene()->removeItem(this);
          game->player->noOfBullet--;
          game->player->bulletPixmap();
          game->boss->bossHealth--;

          //delete them both
          delete this;
          return;
        }
    }


}
