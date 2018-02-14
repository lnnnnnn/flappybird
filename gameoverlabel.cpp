#include "gameoverlabel.h"
#include <QPainter>

GameOverLabel::GameOverLabel(QGraphicsItem *parent)
{
}

QRectF GameOverLabel::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  300 + penWidth/2, 90 + penWidth/2);
}

void GameOverLabel::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap;
    pixmap.load(":/Images/Hint.png");
    painter->drawPixmap(0,0,300,90,pixmap,0,80,300,90);
}
