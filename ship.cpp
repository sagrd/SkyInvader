#include "ship.h"
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

Ship::Ship(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
  //setPos(game->displayWidth  , game->displayHeight -150); //ship
  setPos(game->displayWidth  , game->displayHeight/2);
  setPixmap(QPixmap(":/images/city1bef.png"));


  //create point vector and pl
  QVector <QPointF> points;
  points<<QPoint(0,0)<<QPoint(500,0)<<QPoint(500,750)
       <<QPoint(0,750);
  QPolygonF attackRect(points);

  attack_area = new QGraphicsPolygonItem(attackRect, this);
  attack_area->setPen(QPen(Qt::DashLine));

  //QPointF poly_center(1750,600); //NFQ for ship
  QPointF poly_center(1750,600);
  //relative to scene rather to the tower
  poly_center = mapToScene(poly_center);
  //center of tower
  QPointF tower_center(x()+50,y()+35); //tower center = 50,35
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

double Ship::distanceTo(QGraphicsItem *item){
  QLineF ln(pos(),item->pos());
return ln.length();
}

void Ship::fire(){


  //line betweenn these two points
  //by default attack dest is 0,0
  QLineF ln(QPointF(x()+45,y()+45),attack_dest);
  //angle the line makes with horizontal
  int angle = ln.angle() * (-1); // makes clockwise

  MissileEnemy *bullet = new MissileEnemy();
  bullet->setRotation(angle);
  scene()->addItem(bullet);
}

void Ship::move(){

  QList<QGraphicsItem *> colliding_items = collidingItems();
  for (int i=0, n=colliding_items.size();i<n; ++i){
      if (typeid(*(colliding_items[i])) == typeid(Player)){

          game->health->decrease();
          game->health->decrease();
          scene()->removeItem(this);
          //delete colliding_items[i];
          delete this;
          return;
        }
     }
 //move Ship right
 setPos(x()-5,y());

 if(pos().x () < (-100)){
     scene()->removeItem(this);
     delete this;
   }
}

void Ship::acquire_target(){

  QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();
  //ship is always colliding in attack area
  if(colliding_items.size() == 1){
    has_target = false;
    return;
  }

  QPointF closest_pt;
  double closest_distance = 500;
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
