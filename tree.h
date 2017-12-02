#ifndef TREE_H
#define TREE_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QPointF>

class Tree: public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
public:
  Tree(QGraphicsItem *parent = 0);
public slots:
  void move();

};

#endif // CITY_H
