#include "score.h"
#include "define.h"
#include <QPainter>
#include <QPair>

Score::Score()
{
    for(int i=0; i<10; ++i) {
            picOffset[i].first = (i%5) * SCORE_WIDTH;
            picOffset[i].second = (i>4)? SCORE_HEIGHT : 0;
    }
    scoreNumber = 0;
    time = 0;
    first = false;
    scoreMusic = Phonon::createPlayer(Phonon::MusicCategory,
                                    Phonon::MediaSource("C:/Users/sasaki___cc/Desktop/mybird/untitled/Sounds/Point.wav"));
    connect(scoreMusic,SIGNAL(finished()),scoreMusic,SLOT(stop()));
    pixmap.load(":/Images/ScoreFont.png");
}

QRectF Score::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  80 + penWidth/2, 60 + penWidth/2);
}

void Score::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(SCORE_WIDTH,0,SCORE_WIDTH,SCORE_HEIGHT,pixmap,
                        picOffset[scoreNumber%10].first,picOffset[scoreNumber%10].second,
                        SCORE_WIDTH,SCORE_HEIGHT);
    if(scoreNumber/10)
        painter->drawPixmap(0,0,SCORE_WIDTH,SCORE_HEIGHT,pixmap,
                            picOffset[scoreNumber/10].first,picOffset[scoreNumber/10].second,
                SCORE_WIDTH,SCORE_HEIGHT);
}

void Score::resetScore()
{
    scoreNumber = 0;
    time = 0;
    first = false;
}

int Score::getScore()
{
    return this->scoreNumber;
}

void Score::updateSocre()
{
    if (!first)
    {
        first = true;
        time -= 3;
    }else if(time!=-2 && time) {
        ++scoreNumber;
        update();
        scoreMusic->play();
        time = 0;
    }
        ++time;
}


