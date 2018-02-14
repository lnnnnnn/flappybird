#include "startbtn.h"
#include "define.h"
#include <QPainter>
#include <QMouseEvent>

StartBtn::StartBtn(QGraphicsItem *parent)
{
}

QRectF StartBtn::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  170 + penWidth/2, 85 + penWidth/2);
}

void StartBtn::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap;
    pixmap.load(":/Images/Buttons.png");
    painter->drawPixmap(0,0,170,85,pixmap,0,4,170,85);
}


