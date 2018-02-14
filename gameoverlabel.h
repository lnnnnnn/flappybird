#ifndef GAMEOVERLABEL_H
#define GAMEOVERLABEL_H

#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsWidget>
class GameOverLabel : public QGraphicsWidget
{
public:
    GameOverLabel(QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // GAMEOVERLABEL_H
