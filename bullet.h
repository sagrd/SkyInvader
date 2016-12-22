#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

//in order to support signal and slots one has to inherit from QObject and has to add Q_OBJECT macro
class Bullet: public QObject,public QGraphicsPixmapItem{
private:
  Q_OBJECT
public:
  Bullet(QGraphicsItem *parent =0);

public slots:
  void move();
};



#endif // BULLET_H
