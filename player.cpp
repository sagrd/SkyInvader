#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include <QDebug>
#include <QTimer>
#include "game.h"

extern Game *game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
   //qDebug()<<"player created";
  //bulletsound = new QMediaPlayer();
  //bulletsound->setMedia(QUrl("qrc:/sounds/Sprites/bullet.mp3"));

  setPixmap(QPixmap(":/images/Sprites/player_fly.png"));


  bar = new QGraphicsPixmapItem();
  bar->setPixmap(QPixmap(":/images/Sprites/bar0.png"));
  bar->setPos(35, game->scene->height()/2 -45);
  bar->setZValue(1);
  game->scene->addItem(bar);

}


void Player::keyPressEvent(QKeyEvent *event){
    if(game->isPlayerAlive == false){
        return;
    }
    if(playerHit == true){
      setPixmap(QPixmap(":/images/Sprites/player_fly.png"));
      playerHit = false;
    }
      if(event->key() == Qt::Key_Left ){
          if(pos().x() > 0){
            setPos(x()-15,y());
          }
        }
      else if(event->key() == Qt::Key_Right){
        if(pos().x () < (scene()->width() -200)){
          setPos(x()+15,y());
          }
        }
      else if(event->key() == Qt::Key_Up){
          if(pos().y() > 0){
            setPos(x(),y()-15);
           }
        }
      else if(event->key() == Qt::Key_Down){
          if(pos().y() < (scene()->height() - 150)){
            setPos(x(),y()+15);
        }
      }
      else if(event->key() == Qt::Key_Space){
          if(noOfBullet <= 5){
            Bullet *bullet = new Bullet();
            noOfBullet++;
            bullet->setPos(x()+40,y()+40);
            //adding bullet to the same scene as player
            scene()->addItem(bullet);
            bulletPixmap();
            //play bullet sound
            //        if(bulletsound->state()==QMediaPlayer::PlayingState){
            //            bulletsound->setPosition(0);
            //          }
            //        else if (bulletsound->state()== QMediaPlayer::StoppedState){
            //          bulletsound->play();
            //         }
          }else{
              QTimer *reloadTime = new QTimer();
              reloadTime->start(2000);
              connect(reloadTime, SIGNAL(timeout()),this, SLOT(reloadingTime()));
              //every rand ms timeout signal will be emitted and enemy will move

            }
         }
      bar->setPos(x()+35,y()- 10);
  }

  void Player::bulletPixmap()
  {
    if(noOfBullet == 0){
        bar->setPixmap(QPixmap(":/images/Sprites/bar0.png"));
      }
    else if(noOfBullet == 1){
        bar->setPixmap(QPixmap(":/images/Sprites/bar1.png"));
      }
    else if(noOfBullet == 2){
        bar->setPixmap(QPixmap(":/images/Sprites/bar2.png"));
      }
    else if(noOfBullet == 3){
        bar->setPixmap(QPixmap(":/images/Sprites/bar3.png"));
      }
    else if(noOfBullet == 4){
        bar->setPixmap(QPixmap(":/images/Sprites/bar4.png"));
      }
    else if(noOfBullet == 5){
        bar->setPixmap(QPixmap(":/images/Sprites/bar5.png"));
      }
    else{
        bar->setPixmap(QPixmap(":/images/Sprites/bar6.png"));
      }
}

void Player::reloadingTime(){
    return;
}


