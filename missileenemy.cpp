#include "missileenemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> //qSin, qCos, qTan takes in degrees
#include <QDebug>
#include "game.h"

extern Game *game;

MissileEnemy::MissileEnemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
  //set Pixmap
  setPixmap(QPixmap(":images/missile_const.png"));

  //connect to timer
  QTimer *move_timer = new QTimer();
  connect(move_timer, SIGNAL(timeout()),this, SLOT(move()));
  move_timer->start(50);
}

void MissileEnemy::move(){
  //moving bullet in a line on certain angle
  int STEP_SIZE =20; //no. of pixals moved at a time
  double theta = rotation(); //rotation() returns in degrees

  double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
  double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

  //setting the position of bullet
  setPos(x()+dx, y()+dy);
 // qDebug() << "fired";
  if((pos().x () > scene()->width()) || (pos().x () < 0) || (pos().y () > scene()->height()) ||(pos().y ()< 0 )){
      scene()->removeItem(this);
      delete this;
    }

}

