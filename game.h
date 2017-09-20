#ifndef GAME_H
#define GAME_H
#include <QObject>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMediaPlayer>

#include "player.h"
#include "score.h"
#include "health.h"
#include "include.h"
#include "cloudfront.h"
#include "cloudback.h"
#include "enemy.h"
#include "cloudfront.h"
#include "cloudback.h"
#include "healthpop.h"
#include "ship.h"
#include "tree.h"
#include "button.h"
#include "boss.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
  Game();

  bool startingTime = true;
  bool isPlayerAlive;
  bool bossExist = false;
  int displayHeight;
  int displayWidth;


  QGraphicsScene *scene;
  Player * player;
  Score *score;
  Health *health;
  Enemy *enemy;
  Ship *ship;
  Boss *boss;
  //wallpaper here

  void displayMainMenu();
  void prepareToReplay();
  void spawnEnemies();
  void createBoss();

private:
  QMediaPlayer *music;
  QGraphicsTextItem *storyText;
  QGraphicsTextItem *quoteText;
  QGraphicsPixmapItem *frontscreen;
  QGraphicsPixmapItem *info;
  Button *playButton;
  Button *quitButton;
  QTimer *bossTimer;
  QGraphicsPixmapItem *board;

public slots:
  void deleteMenu();
  void start();
  void spawn(); //enemy
  void spawnFrontCloud();
  void spawnBackCloud();
  void spawnHealthPop();
  void spawnShip();
  void spawnBoss();
  void spawnTree();
};

#endif // GAME_H
