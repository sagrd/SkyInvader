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
  int noOfBullet = 0;
  void bulletPixmap();
  QGraphicsPixmapItem *bar;

private:
  QMediaPlayer *bulletsound;


public slots:
  void reloadingTime();
};


#endif // PLAYER_H
