#include "wallpaper.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "game.h"
#include <typeinfo>

extern Game *game;

WallPaper::WallPaper(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
  setZValue(2);
  setPixmap(QPixmap(":/images/black.png"));
  this->setScale(10);

   plane = new QGraphicsPixmapItem();
      plane->setPixmap(QPixmap(":/images/plane.png"));
   plane->setZValue(3);
   plane->setPos(0,0);

   //plane->show();



//  QGraphicsTextItem *play = new QGraphicsTextItem();
//  play->setPlainText(QString("PLAY"));
//  play->setPos(500,500);
//  play->setDefaultTextColor(Qt::red);
//  play->setFont(QFont("times",16));
//  play->setZValue(3);

//   QTimer *timer = new QTimer();
//   connect(timer, SIGNAL(timeout()),this, SLOT(move()));
//   timer->start(50);

}

void WallPaper::move(){
 //move Cloud right
 setPos(x()- 10,y());

 if(pos().x () < (-3000)){
     //removing from scene and delating the item
     scene()->removeItem(this);
     delete this;
   }
}

