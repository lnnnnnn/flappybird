#include "hint.h"
#include <QPainter>

Hint::Hint(QGraphicsItem *parent)
{
}

QRectF Hint::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  300 + penWidth/2, 800 + penWidth/2);
}

void Hint::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap;
    pixmap.load(":/Images/Hint.png");
    painter->drawPixmap(0,0,300,90,pixmap,0,0,300,90);
    painter->drawPixmap(30,150,260,160,pixmap,0,170,260,160);
}


