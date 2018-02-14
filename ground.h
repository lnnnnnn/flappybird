#ifndef GROUND_H
#define GROUND_H

#include <QGraphicsItem>

class Ground : public QGraphicsItem
{
public:
    Ground();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void advance(int phase);
private:
    int sx;
    QPixmap pixmap;
};

#endif // GROUND_H
