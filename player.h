#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class Player: public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
public:
  bool playerHit = 0;
  Player(QGraphicsItem *parent =0);
  void keyPressEvent(QKeyEvent *event);
public slots:
  void spawn(); //enemy
  void spawnFrontCloud();
  void spawnBackCloud();
  void spawnHealthPop();
  void spawnShip();

private:
  QMediaPlayer *bulletsound;
};


#endif // PLAYER_H
