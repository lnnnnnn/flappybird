#include "rankbtn.h"
#include "define.h"
#include <QPainter>


RankBtn::RankBtn(QGraphicsItem *parent)
{
}

QRectF RankBtn::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  170 + penWidth/2, 85 + penWidth/2);
}

void RankBtn::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap;
    pixmap.load(":/Images/Buttons.png");
    painter->drawPixmap(0,0,170,85,pixmap,174,4,170,85);
}
