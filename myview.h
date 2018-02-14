#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <phonon>

class ScoreFontMini;
class WhiteMask;
class BlackMask;
class StartBtn;
class RankBtn;
class ScoreBoard;
class Bird;
class Ground;
class PipeTop;
class PipeBottom;
class Score;
class Hint;
class GameOverLabel;
class QPropertyAnimation;
class QParallelAnimationGroup;

class MyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyView(QWidget *parent = 0);
signals:
    void birdFly();
    void HintHide();
    void start();
    void newScoreNumber(int);
public slots:
    void needPipe();
    void birdDie_();
    void gameOver();
    void hintOpacity(); //逐渐消失效果
    void GolShow();     //死亡组合动画
    void _start();
    void removeWhiteMark();
protected:
    void mousePressEvent(QMouseEvent *event);
private:
    void initView();
    void initScene();
    void initHintPA();//初始化hint动画
    void initDieFrames();//初始化死亡用并行框架
    void initConnectTimer();//初始化信号链接和计时器
    void hideItems();
    void createGround();
    void createPipe();
    void createBird();
    void createScore();
    void createMusic();
    void createHint();
    void hideItem();
    void createDieFrames();
    void resetPipe();
    void whiteMaskAnimation();
    void blackMaskAnimation();
private:
//场景需要的各种Item
    PipeTop *pipeTop1;
    PipeTop *pipeTop2;
    PipeTop *pipeTop3;
    PipeBottom *pipeBottom1;
    PipeBottom *pipeBottom2;
    PipeBottom *pipeBottom3;

    Ground *ground;
    Score *score;
    Bird *bird;
    Hint *hint;
    StartBtn *startBtn;
    RankBtn *rankBtn;
    ScoreBoard *scoreBoard;
    GameOverLabel *gameOverLabel;
    ScoreFontMini *scoreFontMini;
//场景需要的定时器
    QTimer *timer;
    QTimer *timerPipeScore;
    QTimer *timerBird;
    bool StartOver;
    int PipeNumber;
//场景需要的动画框架
    QPropertyAnimation *hintAnimation;
    QPropertyAnimation *startBtnAnimation;
    QPropertyAnimation *rankBtnAnimation;
    QPropertyAnimation *scoreBoardAnimation;
    QPropertyAnimation *gameOverLabelAnimation;
    QPropertyAnimation *scoreFontMiniAnimation;
    QParallelAnimationGroup *dieGroup;//死亡用并行动画组
//场景需要的mask
    WhiteMask *whiteMask;
//场景需要的音效
    Phonon::MediaObject *flyMusic;
    Phonon::MediaObject *dieMusic;
    Phonon::MediaObject *rankScoreMusic;
};

#endif // MYVIEW_H
