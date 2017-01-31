#ifndef CITY_H
#define CITY_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QPointF>

class City: public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
public:
  City(QGraphicsItem *parent = 0);
  double distanceTo(QGraphicsItem *item);
  void fire();
public slots:
  void move();
  void acquire_target();
private:
  QGraphicsPolygonItem *attack_area;
  QPointF attack_dest;
  bool has_target = true;
};

#endif // CITY_H
