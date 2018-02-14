#ifndef RANKBTN_H
#define RANKBTN_H

#include <QGraphicsObject>

class RankBtn : public QGraphicsObject
{
public:
    RankBtn(QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // RANKBTN_H
