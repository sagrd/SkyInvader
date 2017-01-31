#include "game.h"
#include <QGraphicsTextItem>
#include "enemy.h"
#include <QGraphicsView>
#include <QTimer>
#include <QFont>
#include "player.h"
#include <QMediaPlayer>
#include <QImage>
#include "include.h"




Game::Game(){
  //Constants
  displayWidth = Include::screenWidth();
  displayHeight = Include::screenHeight();

  //create a scene and player
  scene = new QGraphicsScene();
  scene->setSceneRect(0,0,displayWidth,displayHeight);
  setBackgroundBrush(QBrush(QImage(":/images/BackGround_fix.png")));

  //adding the "scene"
  setScene(scene);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFixedSize(displayWidth,displayHeight);


  player = new Player();
  //player set position
  player->setPos(0, scene->height()/2 - 35);
  player->setZValue(0);



  //player to enable keyboard events
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();
  scene->addItem(player);


  //spawn enemies
  QTimer *timer = new QTimer();
  QObject::connect(timer, SIGNAL(timeout()),player, SLOT(spawn()));
  timer->start(2000); //enemy after 2000 ms

  player->wallpaper();

  //spawn ships
  QTimer *cityTimer = new QTimer();
  QObject::connect(cityTimer, SIGNAL(timeout()),player, SLOT(spawnShip()));
  cityTimer->start(15000); //enemy after 2000 ms

  //spawn scorePop
  QTimer *scorePop = new QTimer();
  QObject::connect(scorePop, SIGNAL(timeout()),player, SLOT(spawnHealthPop()));
  scorePop->start(35000);

  //spawn Clouds
  QTimer *frontCloudTimer = new QTimer();
  QObject::connect(frontCloudTimer, SIGNAL(timeout()), player, SLOT(spawnFrontCloud()));
  frontCloudTimer->start(6000); //cloud after 5 sec
  QTimer *backCloudTimer = new QTimer();
  QObject::connect(backCloudTimer, SIGNAL(timeout()), player, SLOT(spawnBackCloud()));
  backCloudTimer->start(15000); //cloud after 10 sec

  QTimer *shipTimer = new QTimer();
  QObject::connect(shipTimer, SIGNAL(timeout()), player, SLOT(spawnCity()));
  shipTimer->start(30000);

  //create score and health
  score = new Score();
  scene->addItem(score);
  health = new Health();
  health->setPos(health->x(), health->y()+25);
  scene->addItem(health);

  //play bg music
//  QMediaPlayer *music = new QMediaPlayer();
//  music->setMedia(QUrl("qrc:/sounds/bgsound.wav"));
//  music->play();

  //show();
}

