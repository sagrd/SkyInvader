#ifndef SHIP_H
#define SHIP_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QPointF>

class Ship: public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
public:
  Ship(QGraphicsItem *parent = 0);
  double distanceTo(QGraphicsItem *item);
  void fire();
public slots:
  void move();
  void acquire_target();
private:
  QGraphicsPolygonItem *attack_area;
  QPointF attack_dest;
  bool has_target;
};

#endif // SHIP_H
