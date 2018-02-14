#ifndef PIPE_H
#define PIPE_H

#include<QGraphicsObject>

class PipeTop : public QGraphicsObject
{
public:
    PipeTop(int H1);
    void setHeight(int H1);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
private:
    int H1;
    QPixmap pixmap;
};


class PipeBottom : public QGraphicsObject
{
public:
    PipeBottom(int H2);
    void setHeight(int H2);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
private:
    int H2;
    QPixmap pixmap;
};

#endif // PIPE_H
