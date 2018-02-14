#ifndef STARTBTN_H
#define STARTBTN_H

#include <QGraphicsObject>

class StartBtn : public QGraphicsObject
{
public:
    StartBtn(QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};


#endif // STARTBUTTON_H
