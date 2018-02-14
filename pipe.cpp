#include"pipe.h"
#include "define.h"
#include <QPainter>
#include <QDebug>

PipeTop::PipeTop(int H1)
{
    this->H1 = H1;
    pixmap.load(":/Images/pipe1.png");
}

void PipeTop::setHeight(int H1)
{
    this->H1 = H1;
}

void PipeTop::advance(int phase)
{
    if (!phase)
        return;
    moveBy(-1, 0);
}

QRectF PipeTop::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  52 + penWidth/2, H1 + penWidth/2);
}

void PipeTop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,52-2,H1-2,pixmap,0,420-H1,52,H1);
}

PipeBottom::PipeBottom(int H2)
{
    this->H2 = H2;
    pixmap.load(":/Images/pipe2.png");
}

void PipeBottom::setHeight(int H2)
{
    this->H2 = H2;
}

void PipeBottom::advance(int phase)
{
    if (!phase)
        return;
    moveBy(-1, 0);
}

QRectF PipeBottom::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  52 + penWidth/2, H2 + penWidth/2);
}

void PipeBottom::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,52-2,H2,pixmap,0,0,52,H2);
}


