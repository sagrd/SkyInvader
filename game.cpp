#include <QGraphicsScene>
#include "game.h"
#include <QGraphicsView>
#include <QTimer>
#include "enemy.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>

Game::Game(QWidget *parent){
  QGraphicsScene *scene = new QGraphicsScene();
  scene->setSceneRect(0,0,800,600);
  //disable horizontal and vertical scrollbar
  setScene(scene);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  //setting the size of view and scene
  setFixedSize(800,600);

  Player *player = new Player();
  player->setRect(0,0,100,100);
  player->setPos(400,500);

  //make rect focusable as focusable item
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();
  //adding the item to the scene
  scene->addItem(player);

  //adds the view
  //QGraphicsView *view = new QGraphicsView(scene);

  //creates the score
  score = new Score();
  scene->addItem(score);
  health = new Health();
  health->setPos(health->x(), health->y()+25);
  scene->addItem(health);

  //spawn enemies constantly
  QTimer *timer= new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
  timer->start(2000);

  //playbackground music
  QMediaPlayer *music = new QMediaPlayer();
  music->setMedia(QUrl("qrc:/sounds/sky.wav"));
  music->play();

  //bullet music

  show();
}
