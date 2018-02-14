#ifndef HINT_H
#define HINT_H

#include <QGraphicsObject>

class Hint : public QGraphicsObject
{
public:
    Hint(QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // HINT_H
