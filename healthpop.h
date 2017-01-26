#ifndef HEALTHPOP_H
#define HEALTHPOP_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class HealthPop: public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
public:
  HealthPop(QGraphicsItem *parent = 0);
public slots:
  void move();
};
#endif // HEALTHPOP_h
