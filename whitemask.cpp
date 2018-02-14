#include "whitemask.h"
#include <QPainter>

WhiteMask::WhiteMask(QGraphicsItem *parent)
{
}

QRectF WhiteMask::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  800 + penWidth/2, 600 + penWidth/2);
}

void WhiteMask::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap;
    pixmap.load(":/Images/WhiteMask.png");
    painter->drawPixmap(0,0,800,600,pixmap,0,0,800,600);
}
