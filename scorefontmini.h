#ifndef SCOREFONTMINI_H
#define SCOREFONTMINI_H

#include <QGraphicsObject>

class ScoreFontMini : public QGraphicsObject
{
    Q_OBJECT
public:
    ScoreFontMini(QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void resetScore();
public slots:
    void updateSocre(int score);
private:
    QPair<int,int> picOffset[10];   //图片偏移量
    int scoreNumber;                //标记当前分数
    int HeightScore;                //记录历史最高
};


#endif // SCOREFONTMINI_H
