#include "tree.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"
#include "include.h"
#include "player.h"


extern Game *game;

Tree::Tree(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
  setPos(game->displayWidth  , game->displayHeight - Include::randomInInterval(50,200));
  setZValue(-0.1);
  int choice = Include::randomInInterval(0,1);
  if(choice ==0){
      setPixmap(QPixmap(":/images/Sprites/city1bef.png"));
 } else{
      setPixmap(QPixmap(":/images/Sprites/plant2.png"));
}

//timer to move tree
 QTimer *timer = new QTimer();
 connect(timer, SIGNAL(timeout()),this, SLOT(move()));
 timer->start(50);

}

void Tree::move(){
 //move Ship right
 setPos(x()-10,y());

 if(pos().x () < (-100)){
     scene()->removeItem(this);
     delete this;
   }
}

