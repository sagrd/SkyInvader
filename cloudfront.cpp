#include "cloudfront.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "game.h"
#include <typeinfo>

extern Game *game;

void CloudFront::randomCloudGenerator(){
  setZValue(3);
      setPixmap(QPixmap(":/images/Sprites/cloudV.png"));

}

CloudFront::CloudFront(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
  randomMovePixel = Include::randomInInterval(3,5);
  int random_number = (Include::randomInInterval(0,200) );
  setPos(game->displayWidth  , random_number);
  randomCloudGenerator();



   QTimer *timer = new QTimer();
   connect(timer, SIGNAL(timeout()),this, SLOT(move()));
   timer->start(50);

}

void CloudFront::move(){
 //move Cloud right
 setPos(x()- randomMovePixel,y());

 if(pos().x () < (-100)){
     //removing from scene and delating the item
     scene()->removeItem(this);
     delete this;
   }
}


