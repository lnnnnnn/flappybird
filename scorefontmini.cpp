#include "scorefontmini.h"
#include "define.h"
#include <QPainter>

ScoreFontMini::ScoreFontMini(QGraphicsItem *parent)
{
    for(int i=0; i<10; ++i) {
        picOffset[i].first = (i%5) * SCORE_MINI_WIDTH;
        picOffset[i].second = (i>4)? SCORE_MINI_HEIGHT : 0;
    }
    scoreNumber = 0;
    HeightScore = 0;
}

void ScoreFontMini::updateSocre(int score)
{
    if(this->HeightScore < score)
        this->HeightScore = score;
    this->scoreNumber = score;
}

QRectF ScoreFontMini::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
              50 + penWidth/2, 32 + penWidth/2);
}

void ScoreFontMini::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap;
    pixmap.load(":/Images/ScoreFontMini.png");
    //绘制当前成绩
    painter->drawPixmap(SCORE_MINI_WIDTH,0,SCORE_MINI_WIDTH,SCORE_MINI_HEIGHT,pixmap,
                    picOffset[scoreNumber%10].first,picOffset[scoreNumber%10].second,
                    SCORE_MINI_WIDTH,SCORE_MINI_HEIGHT);
    if(scoreNumber/10)
        painter->drawPixmap(0,0,SCORE_MINI_WIDTH,SCORE_MINI_HEIGHT,pixmap,
                        picOffset[scoreNumber/10].first,picOffset[scoreNumber/10].second,
                        SCORE_MINI_WIDTH,SCORE_MINI_HEIGHT);
    //绘制历史最高成绩
    painter->drawPixmap(SCORE_MINI_WIDTH,60,SCORE_MINI_WIDTH,SCORE_MINI_HEIGHT,pixmap,
                    picOffset[HeightScore%10].first,picOffset[HeightScore%10].second,
                    SCORE_MINI_WIDTH,SCORE_MINI_HEIGHT);
    if(HeightScore/10)
        painter->drawPixmap(0,60,SCORE_MINI_WIDTH,SCORE_MINI_HEIGHT,pixmap,
                        picOffset[HeightScore/10].first,picOffset[HeightScore/10].second,
                        SCORE_MINI_WIDTH,SCORE_MINI_HEIGHT);
}

void ScoreFontMini::resetScore()
{
    scoreNumber = 0;
}


