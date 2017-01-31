#ifndef WALLPAPER_H
#define WALLPAPER_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>

class WallPaper: public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
public:
  WallPaper(QGraphicsItem *parent = 0);
public slots:
  void move();
private:
  QGraphicsPixmapItem *plane;

};


#endif // WALLPAPER_H
