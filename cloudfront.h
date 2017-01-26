#ifndef CLOUDFRONT_H
#define CLOUDFRONT_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class CloudFront: public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
private:
  void randomCloudGenerator();
  int randomMovePixel;
public:
  CloudFront(QGraphicsItem *parent = 0);
public slots:
  void move();
};


#endif // CLOUDFRONT_H
