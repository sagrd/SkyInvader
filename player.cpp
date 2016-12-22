#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "enemy.h"
#include "bullet.h"


Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){
  bulletSound = new QMediaPlayer();
  bulletSound->setMedia(QUrl("qrc:/sounds/shotgun.mp3"));
}


void Player::keyPressEvent(QKeyEvent *event){
  if (event->key() == Qt::Key_Left){
      if(pos().x()>0)
         setPos(x()-10,y());
    }
  else if(event->key() == Qt::Key_Right){
      if((pos().x()+100) < 800)
         setPos(x()+10,y());
    }
// moving Up and Down

  //  else if(event->key() == Qt::Key_Up){
//      setPos(x(),y()-10);
//    }
//  else if(event->key() == Qt::Key_Down){
//      setPos(x(),y()+10);
//    }
  else if(event->key() == Qt::Key_Space){
      //create a bullet
      Bullet *bullet = new Bullet();
      bullet->setPos(x(),y());
      scene()->addItem(bullet);

      //playing bulletsound
      if(bulletSound->state()==QMediaPlayer::PlayingState){
          bulletSound->setPosition(0);
        }
      else if (bulletSound->state() == QMediaPlayer::StoppedState){
          bulletSound->play();
        }


    }
}

void Player::spawn()
{
  //create enemy
  Enemy *enemy = new Enemy();
  scene()->addItem(enemy);
}
