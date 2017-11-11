#include "game.h"
#include <QGraphicsTextItem>
#include "enemy.h"
#include <QGraphicsView>
#include <QTimer>
#include <QFont>
#include "player.h"
#include <QImage>
#include "include.h"
#include "button.h"
#include <QGraphicsPixmapItem>
#include "score.h"
#include <QDebug>
#include "boss.h"

Game::Game(){

  displayWidth = Include::screenWidth();
  displayHeight = Include::screenHeight();


  //create a scene
  scene = new QGraphicsScene();
  scene->setSceneRect(0,0,displayWidth,displayHeight);
  setBackgroundBrush(QBrush(QImage(":/images/Sprites/BackGround-fix.png")));

  //adding the "scene"
  setScene(scene);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFixedSize(displayWidth,displayHeight);

  //spawn Clouds
  QTimer *frontCloudTimer = new QTimer();
  QObject::connect(frontCloudTimer, SIGNAL(timeout()), this, SLOT(spawnFrontCloud()));
  frontCloudTimer->start(8000);
  QTimer *backCloudTimer = new QTimer();
  QObject::connect(backCloudTimer, SIGNAL(timeout()), this, SLOT(spawnBackCloud()));
  backCloudTimer->start(15000);

  //spawn tree after
  QTimer *treeTimer = new QTimer();
  QObject::connect(treeTimer, SIGNAL(timeout()),this, SLOT(spawnTree()));
  treeTimer->start(1700);

  //play bg music
//  music = new QMediaPlayer();
//  music->setMedia(QUrl("qrc:/sounds/Sprites/bgsound.wav"));
//  music->play();

  //show();
}

void Game::start(){
  if(startingTime == false){
      delete player;
  }
  if(bossExist == true){
      scene->removeItem(boss);
      delete boss;
      createBoss();
    }else{
      createBoss();
    }
  player = new Player();
  isPlayerAlive = true;

  //player set position
  player->setPos(0, scene->height()/2 - 35);
  player->setZValue(0);

  //player to enable keyboard event
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();
  scene->addItem(player);

  if(startingTime == true){

      spawnEnemies();
      QTimer *scorePop = new QTimer();
      QObject::connect(scorePop, SIGNAL(timeout()),this, SLOT(spawnHealthPop()));
      scorePop->start(35000);
  }

  info = new QGraphicsPixmapItem();
  info->setPixmap(QPixmap(":/images/Sprites/info.png"));
  info->setPos(25,20);
  info->setZValue(4.5);
  scene->addItem(info);

  board = new QGraphicsPixmapItem();
  board->setPixmap(QPixmap(":/images/Sprites/board.png"));
  board->setZValue(4);
  scene->addItem(board);


  //create score and health
  score = new Score();
  score->setPos(150,20);
  scene->addItem(score);
  health = new Health();
  health->setPos(65,20);
  scene->addItem(health);
}

void Game::spawn(){
    if(isPlayerAlive == false){
        return;
    }
  //create an enemy
  Enemy *enemy = new Enemy();
  scene->addItem(enemy);
}

void Game::spawnFrontCloud(){
  //create an enemy
  CloudFront *cloudFront = new CloudFront();
  scene->addItem(cloudFront);
}


void Game::spawnBackCloud(){
  //create an enemy
  CloudBack *cloudBack = new CloudBack();
  scene->addItem(cloudBack);
}

void Game::spawnHealthPop()
{
    if(isPlayerAlive == false){
        return;
    }
  HealthPop *healthPop = new HealthPop();
  scene->addItem(healthPop);
}

void Game::spawnShip(){
    if(isPlayerAlive == false){
        return;
    }
  Ship *ship = new Ship();
  scene->addItem(ship);
}

void Game::spawnBoss(){
  boss = new Boss();
  scene->addItem(boss);
  bossTimer->stop();
}

void Game::spawnTree(){
  Tree *tree = new Tree();
  scene->addItem(tree);
}

void Game::displayMainMenu(){
    // create the title text
    frontscreen = new QGraphicsPixmapItem();
    frontscreen->setPixmap(QPixmap(":/images/Sprites/frontscreen.png"));
    frontscreen->setPos((displayWidth/2) -423,(displayHeight/2) - 236);
    scene->addItem(frontscreen);

    QString q;
    if(startingTime == true){
      q = "General:\n"
          "A strom of enemy carriers are headed towards our capital.\n"
          "Our defences will not be able to handle all of them. Up there\n"
          "the world is divided into bastards and suckers. Make your choice. \n"
                  "\nWe're losing this war. \n"
                  "Shoot those birds down and we have a chance.\n\n\n"
                  "Arrow keys to control your airplane. Space to fire.";
    }
    else{

      if((score->getScore())<10){
          q = "General:\n\n"
              "What did they taught you at militiary academy?\n\n"
              "Remember!\n"
              "Arrow keys to control your airplane. Space to fire."
              "\n\n\n\nhttp://i.sagardhungel.com.np";

        }
      else if((score->getScore()) < 100){
          q = "General:\n\n"
              "I will miss the plane more.\n\n"
              "Remember!\n"
              "Arrow keys to control your airplane. Space to fire."
              "\n\n\n\nhttp://i.sagardhungel.com.np";
        }
      else if((score->getScore()) < 250){
          q = "General:\n\n"
              "Maybe I expected more than I should.\n\n"
              "Remember!\n"
              "Arrow keys to control your airplane. Space to fire."
              "\n\n\n\nhttp://i.sagardhungel.com.np";
        }
      else if((score->getScore()) >= 250){
          q = "General:\n\n"
              "Well done! You shalt be remembered.\n\n"
              "Remember!\n"
              "Arrow keys to control your airplane. Space to fire."
              "\n\n\n\nhttp://i.sagardhungel.com.np";
        }
    }
    storyText = new QGraphicsTextItem(q);
    QFont titleFont("Forte",12);
    storyText->setDefaultTextColor(Qt::white);

    storyText->setFont(titleFont);
    int txPos = (displayWidth/2) - 390;
    int tyPos = (displayHeight/2) - 100;
    storyText->setPos(txPos,tyPos);
    storyText->setZValue(3);
    scene->addItem(storyText);


    QString q1, q2, q3, q4;
    q1 = "\"Sure, jets are fast and economical, but, oh my, what fun we\'ve lost\n "
         "and what leisure we\'ve sacrificed in the race of efficiency.\"\n - Ginger Roger";
    q2 = "\"If god had really intended men to fly, He'd make it easier to get to \n"
        "the airport.\"\n - George Winters";
    q3 = "\"If you can walk away from a landing, it's a good landing. If you can use the\n"
        "airplane the next day, its an outstanding landing.\" \n- Chuck Yeager";
    q4 = "\"For once you have tasted flight you will walk the earth with your eyes"
        "\nskywards, for there you have been and there you will long to return.\""
        "\n - Leonardo da Vinci";
    int choice = Include::randomInInterval(0,3);
    switch(choice){
      case 0:
        quoteText = new QGraphicsTextItem(q1);
        break;
      case 1:
        quoteText = new QGraphicsTextItem(q2);
        break;
      case 2:
        quoteText = new QGraphicsTextItem(q4);
        break;
      case 3:
        quoteText = new QGraphicsTextItem(q3);
        break;
      }
    QFont quote("ariel",12);
    quoteText->setDefaultTextColor(Qt::white);
    quoteText->setFont(quote);
    txPos = (displayWidth/2) -390;
    tyPos = (displayHeight/2) + 160;
    quoteText->setPos(txPos,tyPos);
    quoteText->setZValue(3);
    scene->addItem(quoteText);

    // create the play button
    playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 + 210;
    int byPos = 530;
    playButton->setPos(bxPos,byPos);
    //playButton->setZValue(3);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    connect(playButton,SIGNAL(clicked()),this,SLOT(deleteMenu()));
    scene->addItem(playButton);

    // create the quit button
    quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 + 210;
    int qyPos = 570;
    quitButton->setPos(qxPos,qyPos);
    //quitButton->setZvalue(3);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::prepareToReplay(){
  delete info;
  scene->removeItem(player);
  delete score;
  delete health;
  delete player->bar;
  delete board;
  startingTime= false;
}

void Game::deleteMenu(){
  delete playButton;
  delete quitButton;
  delete quoteText;
  delete storyText;
  scene->removeItem(frontscreen);
  delete frontscreen;
}

void Game::spawnEnemies(){
  //spawn enemies
  QTimer *timer = new QTimer();
  QObject::connect(timer, SIGNAL(timeout()),this, SLOT(spawn()));
  timer->start(2000); //enemy after 2000 ms;

  QTimer *shipTimer = new QTimer();
  QObject::connect(shipTimer, SIGNAL(timeout()), this, SLOT(spawnShip()));
  shipTimer->start(6000);
}

void Game::createBoss()
{
  bossTimer = new QTimer();
  QObject::connect(bossTimer, SIGNAL(timeout()), this, SLOT(spawnBoss()));
  bossTimer->start(6000);
}
