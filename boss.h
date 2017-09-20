#ifndef BOSS_H
#define BOSS_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QPointF>

class Boss: public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
public:
  Boss(QGraphicsItem *parent = 0);
  double distanceTo(QGraphicsItem *item);
  void fire();
  int bossHealth = 50;

public slots:
  void move();
  void acquire_target();
private:
  QGraphicsPolygonItem *attack_area;
  QPointF attack_dest;
  bool has_target = true;

};

#endif // BOSS_H


