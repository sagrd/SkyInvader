#include "missileenemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> //qSin, qCos, qTan takes in degrees
#include <QDebug>
#include "game.h"
#include <typeinfo>

extern Game *game;

MissileEnemy::MissileEnemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
  //set Pixmap
  setPixmap(QPixmap(":images/Sprites/missile_const.png"));

  //connect to timer
  QTimer *move_timer = new QTimer();
  connect(move_timer, SIGNAL(timeout()),this, SLOT(move()));
  move_timer->start(50);
}

void MissileEnemy::move(){
  //moving bullet in a line on certain angle
  int STEP_SIZE =30; //no. of pixals moved at a time
  double theta = rotation(); //rotation() returns in degrees

  double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
  double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

  //setting the position of bullet
  setPos(x()+dx, y()+dy);

  QList<QGraphicsItem *> colliding_items = collidingItems();
  for (int i=0, n=colliding_items.size();i<n; ++i){
      if (typeid(*(colliding_items[i])) == typeid(Player)){

          game->health->decrease();

          //remove them both from scene (still exists on heap)
          scene()->removeItem(this);

          //delete them both
          //delete colliding_items[i];
          delete this;
          return;
        }
    }
 // qDebug() << "fired";
  if((pos().x () > scene()->width()) || (pos().x () < 0) || (pos().y () > scene()->height()) ||(pos().y ()< 0 )){
      scene()->removeItem(this);
      delete this;
    }

}

