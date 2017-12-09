#ifndef MISSILEENEMY_H
#define MISSILEENEMY_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class MissileEnemy: public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
public:
  MissileEnemy(QGraphicsItem *parent=0);
public slots:
  void move();
};


#endif // MISSILEENEMY_H
