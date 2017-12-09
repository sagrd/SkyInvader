#include "boss.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "game.h"
#include <typeinfo>
#include "include.h"
#include <QVector>
#include <QPointF>
#include <QPolygon>
#include "player.h"
#include "bullet.h"
#include "missileenemy.h"
#include <QDebug>

extern Game *game;

Boss::Boss(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
  game->bossExist = true;
  setZValue(-0.1);
  setPos(game->displayWidth/2  , -250);
  setPixmap(QPixmap(":/images/Sprites/warrior.png"));


  //create point vector and pl
  QVector <QPointF> points;
  points<<QPoint(0,0)<<QPoint(0,game->displayHeight)<<QPoint(game->displayWidth,game->displayHeight)
       <<QPoint(game->displayWidth,0);
  QPolygonF attackRect(points);

  attack_area = new QGraphicsPolygonItem(attackRect, this);
  attack_area->setPen(QPen(Qt::transparent));
  //attack_area->setPen(QPen(Qt::DotLine));

  QPointF poly_center(1900,game->displayHeight/2 - 290);
  //relative to scene rather to the tower
  poly_center = mapToScene(poly_center);
  //center of tower
  QPointF tower_center(x()+50,y()+80); //tower center = 50,35
  QLineF ln(poly_center,tower_center);
  //shifting the polygon
  attack_area->setPos(x()+ln.dx(),y()+ln.dy());

 // connect a  timer to attack target
  QTimer *shootTimer = new QTimer();
  connect(shootTimer, SIGNAL(timeout()), this, SLOT(acquire_target()));
  shootTimer->start(1000);

//timer to move ship
 QTimer *timer = new QTimer();
 connect(timer, SIGNAL(timeout()),this, SLOT(move()));
 timer->start(50);

}

double Boss::distanceTo(QGraphicsItem *item){
  QLineF ln(pos(),item->pos());
return ln.length();
}

void Boss::fire(){


  //line betweenn these two points
  //by default attack dest is 0,0
  QLineF ln(QPointF(x()+45,y()+45),attack_dest);
  //angle the line makes with horizontal
  int angle = ln.angle() * (-1); // makes clockwise

  MissileEnemy *missile = new MissileEnemy();
  missile->setPos(x()+50,y()+80);
  missile->setRotation(angle);
  scene()->addItem(missile);
}

void Boss::move(){

  QList<QGraphicsItem *> colliding_items = collidingItems();
  for (int i=0, n=colliding_items.size();i<n; ++i){
      if (typeid(*(colliding_items[i])) == typeid(Player)){

          game->health->decrease();
          if(game->player){
              game->player->setPixmap(QPixmap(":/images/Sprites/player_hit.png"));
              game->player->playerHit = 1;
          }
          scene()->removeItem(this);
          //scene()->removeItem(colliding_items[i]);
          delete this;
          return;
        }
     }
 //move Ship right
 if(x() < (game->displayWidth - 220)){
    setPos(x() + Include::randomInInterval(0,3),y() + Include::randomInInterval(0,3));
 }

  else{
          setPos(x(),y()+Include::randomInInterval(-3,3));
          if(game->isPlayerAlive == false){
              if(pos().x() < game->displayWidth + 400){
                  setPos(x() + 6, y()+Include::randomInInterval(-3,3));
            }
   }
  }
}

void Boss::acquire_target(){

  QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();
  //ship is always colliding in attack area
  if(colliding_items.size() == 1){
    has_target = false;
    return;
  }

  QPointF closest_pt;
  double closest_distance = 2000;
  for (int i=0, n=colliding_items.size();i<n; ++i){
      if (typeid(*(colliding_items[i])) == typeid(Player)){
          double dist = distanceTo(colliding_items[i]);
          if(dist < closest_distance){
            closest_pt = colliding_items[i]->pos();
            has_target = true;
            attack_dest = closest_pt;
            fire();
          }
        }
     }


}
