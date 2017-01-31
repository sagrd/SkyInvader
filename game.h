#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "player.h"
#include "score.h"
#include "health.h"
#include "include.h"
#include "cloudfront.h"
#include "cloudback.h"
#include "ship.h"
#include "wallpaper.h"


class Game: public QGraphicsView{
public:
  Game();
  bool startingTime = true;
  int displayHeight;
  int displayWidth;

  QGraphicsScene *scene;
  Player * player;
  Score *score;
  Health *health;
};

#endif // GAME_H
