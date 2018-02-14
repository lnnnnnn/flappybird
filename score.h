#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsItem>
#include <QObject>
#include <QPair>
#include <phonon>

class Score : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Score();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void resetScore();
    int getScore();
public slots:
    void updateSocre();
private:
    QPair<int,int> picOffset[10];   //图片偏移量
    int scoreNumber;                //标记当前分数
    bool first;                     //标记第一次是否更新
    int time;                       //场景调用更新分数
    QPixmap pixmap;
    Phonon::MediaObject *scoreMusic;
};

#endif // SCORE_H
