#ifndef CLOUDBACK_H
#define CLOUDBACK_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class CloudBack: public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
private:
  void randomCloudGenerator();
  int randomMovePixel;
public:
  CloudBack(QGraphicsItem *parent = 0);
public slots:
  void move();
};


#endif // CLOUDBACK_H
