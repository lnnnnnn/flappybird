#ifndef WHITEMASK_H
#define WHITEMASK_H

#include <QGraphicsObject>

class WhiteMask : public QGraphicsObject
{
public:
    WhiteMask(QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // WHITEMASK_H
