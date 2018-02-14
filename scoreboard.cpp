#include "scoreboard.h"
#include "define.h"
#include <QPainter>


ScoreBoard::ScoreBoard(QGraphicsItem *parent)
{
}

QRectF ScoreBoard::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  345 + penWidth/2, 177 + penWidth/2);
}

void ScoreBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap;
    pixmap.load(":/Images/ScoreBoard.png");
    painter->drawPixmap(0,0,345,177,pixmap,0,4,345,177);
}
