#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>



//in order to support signal and slots one has to inherit from QObject and has to add Q_OBJECT macro
class Enemy: public QObject,public QGraphicsRectItem{
private:
  Q_OBJECT
public:
  Enemy(QGraphicsItem *parent=0);

public slots:
  void move();
};


#endif // ENEMY_H
