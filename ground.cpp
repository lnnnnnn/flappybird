#include "ground.h"
#include <QPainter>

Ground::Ground()
{
    sx = 0;
    pixmap.load(":/Images/Ground.png");
}

QRectF Ground::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  800 + penWidth/2, 112 + penWidth/2);
}

void Ground::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widget*/)
{
    painter->drawPixmap(sx, 0, 839, 112, pixmap);
}

void Ground::advance(int phase)
{
    if(!phase)
        return;
    sx += -1;
    if(sx <= -26)
        sx = 0;
    update();
}
