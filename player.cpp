#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include <QDebug>
#include "enemy.h"
#include "cloudfront.h"
#include "cloudback.h"
#include "healthpop.h"
#include "ship.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
  bulletsound = new QMediaPlayer();
  bulletsound->setMedia(QUrl("qrc:/sounds/bullet.mp3"));

  setPixmap(QPixmap(":/images/player_fly.png"));
}


void Player::keyPressEvent(QKeyEvent *event){
  if(playerHit == true){
    setPixmap(QPixmap(":/images/player_fly.png"));
    playerHit = false;
  }
    if(event->key() == Qt::Key_Left ){
        if(pos().x() > 0){
          setPos(x()-10,y());
        }
      }
    else if(event->key() == Qt::Key_Right){
      if(pos().x () < (scene()->width() -200)){
        setPos(x()+10,y());
        }
      }
    else if(event->key() == Qt::Key_Up){
        if(pos().y() > 0){
          setPos(x(),y()-10);
         }
      }
    else if(event->key() == Qt::Key_Down){
        if(pos().y() < (scene()->height() - 150)){
          setPos(x(),y()+10);
      }
    }
    else if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        bullet->setPos(x()+40,y()+40);
        //adding bullet to the same scene as player
        scene()->addItem(bullet);

        //play bullet sound
        if(bulletsound->state()==QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
          }
        else if (bulletsound->state()== QMediaPlayer::StoppedState){
          bulletsound->play();
         }
    }

}


void Player::spawn(){
  //create an enemy
  Enemy *enemy = new Enemy();
  scene()->addItem(enemy);
}

void Player::spawnFrontCloud(){
  //create an enemy
  CloudFront *cloudFront = new CloudFront();
  scene()->addItem(cloudFront);
}


void Player::spawnBackCloud(){
  //create an enemy
  CloudBack *cloudBack = new CloudBack();
  scene()->addItem(cloudBack);
}

void Player::spawnHealthPop()
{
  HealthPop *healthPop = new HealthPop();
  scene()->addItem(healthPop);
}

void Player::spawnShip(){
  Ship *ship = new Ship();
  scene()->addItem(ship);
}


