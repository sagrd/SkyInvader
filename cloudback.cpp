#include "cloudback.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "game.h"
#include <typeinfo>

extern Game *game;

void CloudBack::randomCloudGenerator(){
  setZValue(-1);
  setPixmap(QPixmap(":/images/Sprites/cloudI.png"));
}

CloudBack::CloudBack(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

  int random_number = (Include::randomInInterval(0,200) );
  randomMovePixel = Include::randomInInterval(1,2);

  setPos(game->displayWidth  , random_number);
  randomCloudGenerator();

   QTimer *timer = new QTimer();
   connect(timer, SIGNAL(timeout()),this, SLOT(move()));
   timer->start(50);

}

void CloudBack::move(){
 //move Cloud right
 setPos(x()-randomMovePixel, y());

 if(pos().x () < (-100)){
     //removing cloud from scene and delating the cloud
     scene()->removeItem(this);
     delete this;
   }
}


