#include "myview.h"
#include "ground.h"
#include "scorefontmini.h"
#include "whitemask.h"
#include "bird.h"
#include "score.h"
#include "startbtn.h"
#include "rankbtn.h"
#include "pipe.h"
#include "define.h"
#include "hint.h"
#include "scoreboard.h"
#include "gameoverlabel.h"
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <phonon>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QIcon>

MyView::MyView(QWidget *parent) :
    QGraphicsView(parent)
{
    PipeNumber = 1;
    StartOver = true;
    initView();
    initScene();
    hideItems();
    initHintPA();
    initDieFrames();
    initConnectTimer();
}

//初始化View函数
void MyView::initView()
{
    // 使用抗锯齿渲染
    setRenderHint(QPainter::Antialiasing);

    // 设置缓存背景，这样可以加快渲染速度
    setCacheMode(CacheBackground);
    setWindowTitle(tr("Flappy bird百度ID liy_forever"));
    setMinimumSize(805, 605);
    setMaximumSize(805, 605);
    setWindowIcon(QIcon(":/Images/FlappyBird.ico"));

    //设置场景
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 800, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setBackgroundBrush(QPixmap(":/Images/Background.png"));
    setScene(scene);
}

void MyView::initScene()
{
    //Ground加入场景
    createGround();
    //Bird加入场景
    createBird();
    //Hint加入场景
    createHint();
    //初始化Music
    createMusic();
    //Pipe加入场景
    createPipe();
    //Score加入场景
    createScore();
    //死亡框架加入场景
    createDieFrames();
}

//创建各种图形函数
void MyView::createPipe()
{
    pipeTop1 = new PipeTop(200);
    scene()->addItem(pipeTop1);
    pipeTop1->setPos(-52,0);

    pipeTop2 = new PipeTop(200);
    scene()->addItem(pipeTop2);
    pipeTop2->setPos(-52,0);


    pipeTop3 = new PipeTop(200);
    scene()->addItem(pipeTop3);
    pipeTop3->setPos(-52,0);

    pipeBottom1 = new PipeBottom(200);
    scene()->addItem(pipeBottom1);
    pipeBottom1->setPos(-52,200);

    pipeBottom2 = new PipeBottom(200);
    scene()->addItem(pipeBottom2);
    pipeBottom2->setPos(-52,200);

    pipeBottom3 = new PipeBottom(200);
    scene()->addItem(pipeBottom3);
    pipeBottom3->setPos(-52,200);
}

void MyView::createGround()
{
    ground = new Ground;
    scene()->addItem(ground);
    ground->setPos(0,488);
}

void MyView::createHint()
{
    hint = new Hint;
    scene()->addItem(hint);
    hint->setPos(250,60);
}

void MyView::createScore()
{
    score = new Score;
    scene()->addItem(score);
    score->setPos(360,50);
    score->setZValue(2);//设置Score为顶层item
}

void MyView::createBird()
{
    bird = new Bird;
    scene()->addItem(bird);
    bird->setPos(170,230);
    bird->setZValue(3);//设置bird为顶层item
}

void MyView::createMusic()
{
    flyMusic = Phonon::createPlayer(Phonon::MusicCategory,
                                    Phonon::MediaSource("C:/Users/sasaki___cc/Desktop/mybird/untitled/Sounds/Wing.wav"));

    dieMusic = Phonon::createPlayer(Phonon::MusicCategory,
                                    Phonon::MediaSource("C:/Users/sasaki___cc/Desktop/mybird/untitled/Sounds/Die.wav"));
    rankScoreMusic = Phonon::createPlayer(Phonon::MusicCategory,
                                    Phonon::MediaSource("C:/Users/sasaki___cc/Desktop/mybird/untitled/Sounds/Swooshing.wav"));
}

void MyView::initHintPA()
{
    hintAnimation = new QPropertyAnimation(hint,"opacity");
    hintAnimation->setDuration(2000);
    hintAnimation->setStartValue(1.0);
    hintAnimation->setEndValue(0.0);
    hintAnimation->stop();
}

void MyView::initDieFrames()
{
    startBtnAnimation = new QPropertyAnimation(startBtn,"opacity");
    startBtnAnimation->setDuration(1200);
    startBtnAnimation->setStartValue(0.0);
    startBtnAnimation->setEndValue(1.0);

    rankBtnAnimation = new QPropertyAnimation(rankBtn,"opacity");
    rankBtnAnimation->setDuration(1200);
    rankBtnAnimation->setStartValue(0.0);
    rankBtnAnimation->setEndValue(1.0);

    scoreBoardAnimation = new QPropertyAnimation(scoreBoard,"opacity");
    scoreBoardAnimation->setDuration(1200);
    scoreBoardAnimation->setStartValue(0.0);
    scoreBoardAnimation->setEndValue(1.0);

    gameOverLabelAnimation = new QPropertyAnimation(gameOverLabel,"geometry");
    gameOverLabelAnimation->setDuration(1000);
    gameOverLabelAnimation->setStartValue(QRect(250,-90,300,90));
    gameOverLabelAnimation->setEndValue(QRect(250,40,300,90));

    dieGroup = new QParallelAnimationGroup;
    dieGroup->addAnimation(startBtnAnimation);
    dieGroup->addAnimation(rankBtnAnimation);
    dieGroup->addAnimation(scoreBoardAnimation);
    dieGroup->addAnimation(gameOverLabelAnimation);

}

void MyView::createDieFrames()
{
    startBtn = new StartBtn;
    scene()->addItem(startBtn);
    startBtn->setPos(220,404);
    startBtn->setZValue(5);

    rankBtn = new RankBtn;
    scene()->addItem(rankBtn);
    rankBtn->setPos(390,404);

    scoreBoard = new ScoreBoard;
    scene()->addItem(scoreBoard);
    scoreBoard->setPos(225,165);

    gameOverLabel = new GameOverLabel;
    scene()->addItem(gameOverLabel);
    gameOverLabel->setPos(250,40);

    scoreFontMini = new ScoreFontMini;
    scene()->addItem(scoreFontMini);
    scoreFontMini->setPos(360,215);
    scoreFontMini->setZValue(20);
}

void MyView::whiteMaskAnimation()
{
    whiteMask = new WhiteMask;
    scene()->addItem(whiteMask);
    whiteMask->setPos(0,0);
    QPropertyAnimation *animation = new QPropertyAnimation(whiteMask,"opacity");
    //初始化whiteMark槽
    connect(animation, SIGNAL(finished()), whiteMask, SLOT(deleteLater()));
    animation->setDuration(200);
    animation->setStartValue(1.0);
    animation->setEndValue(0.0);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

//初始化连接和定时器
void MyView::initConnectTimer()
{
    timerPipeScore = new QTimer;
    connect(this, SIGNAL(start()),this, SLOT(_start()));
    //初始化场景推进计时器
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), scene(), SLOT(advance()));
    timer->start(1000 / GROUND_FRAME_RATE);
    //初始化小鸟计时器和信号连接
    timerBird = new QTimer;
    connect(timerBird, SIGNAL(timeout()),bird, SLOT(moveBird()));
    timerBird->start(1000 / BIRD_FRAME_RATE);
    connect(this, SIGNAL(birdFly()),bird, SLOT(upFly()));
    connect(bird, SIGNAL(birdDie()), this, SLOT(birdDie_()));
    connect(bird, SIGNAL(downOk()), this, SLOT(gameOver()));
    connect(bird, SIGNAL(downOk()), this, SLOT(GolShow()));
    //初始化逐渐消失hint动画的信号
    connect(this,SIGNAL(HintHide()), this, SLOT(hintOpacity()));
    //初始化各种音乐信号和槽
    connect(flyMusic,SIGNAL(finished()),flyMusic,SLOT(stop()));
    connect(this, SIGNAL(birdFly()), flyMusic,SLOT(play()));

    connect(dieMusic,SIGNAL(finished()),dieMusic,SLOT(stop()));
    connect(bird, SIGNAL(birdDie()), dieMusic, SLOT(play()));

    connect(rankScoreMusic,SIGNAL(finished()),rankScoreMusic,SLOT(stop()));
    //链接重新开始游戏槽
    connect(this, SIGNAL(start()),this, SLOT(_start()));
    //初始化Pipe槽
    connect(timerPipeScore, SIGNAL(timeout()), this, SLOT(needPipe()));
    connect(timerPipeScore, SIGNAL(timeout()), score, SLOT(updateSocre()));
    connect(this, SIGNAL(newScoreNumber(int)), scoreFontMini, SLOT(updateSocre(int)));

}

//隐藏item函数
void MyView::hideItems()
{
    //隐藏分数表
    score->hide();
    //隐藏死亡框架
    startBtn->hide();
    rankBtn->hide();
    scoreBoard->hide();
    gameOverLabel->hide();
    scoreFontMini->hide();
}


//////////////////////////////////////////
///各种槽//////////////////////////////////
/////////////////////////////////////////


//需要水管槽
void MyView::needPipe()
{
    int H1 = qrand() % RAND + PIPE_DISTANCE;
    int H2 = 600 - GROUND_DISTANCE - GAP - H1;
    if(PipeNumber<3)
        ++PipeNumber;
    else
        PipeNumber = 1;
    if(PipeNumber == 1) {
        pipeTop1->setHeight(H1);
        pipeTop1->setPos(748, 0);
        pipeBottom1->setHeight(H2);
        pipeBottom1->setPos(748, H1+GAP);

    } else if(PipeNumber == 2) {
        pipeTop2->setHeight(H1);
        pipeTop2->setPos(748, 0);

        pipeBottom2->setHeight(H2);
        pipeBottom2->setPos(748, H1+GAP);

    } else {
        pipeTop3->setHeight(H1);
        pipeTop3->setPos(748, 0);

        pipeBottom3->setHeight(H2);
        pipeBottom3->setPos(748, H1+GAP);

    }
}

//小鸟死亡槽
void MyView::birdDie_()
{
    timer->stop();
    timerPipeScore->stop();
    dieMusic->play();
    StartOver = false;
    emit this->newScoreNumber(score->getScore());
    whiteMaskAnimation();
}

//游戏结束槽
void MyView::gameOver()
{
    timerBird->stop();
}

//hint逐渐消失 启动游戏开始槽
void MyView::hintOpacity()
{
    hintAnimation->start();
    disconnect(this,SIGNAL(HintHide()), this, SLOT(hintOpacity()));
    hint->setOpacity(1);
    score->show();

    timerPipeScore->start(NEED_PIPE_TIME);
}


//动画死亡死亡分数版槽
void MyView::GolShow()
{
    rankScoreMusic->play();
    startBtn->show();
    rankBtn->show();
    scoreBoard->show();
    gameOverLabel->show();
    scoreFontMini->show();
    score->hide();
    dieGroup->start();
}

void MyView::_start()
{
    StartOver = true;
    //复位pipe
    pipeTop1->setPos(-60,0);
    pipeTop2->setPos(-60,0);
    pipeTop3->setPos(-60,0);
    pipeBottom1->setPos(-60,300);
    pipeBottom2->setPos(-60,300);;
    pipeBottom3->setPos(-60,300);;
    //复位bird位置
    bird->setPos(170,230);
    timer->start(1000 / GROUND_FRAME_RATE);
    bird->resetBird();
    timerBird->start(1000 / BIRD_FRAME_RATE);
    //隐藏死亡框架
    startBtn->hide();
    rankBtn->hide();
    scoreBoard->hide();
    gameOverLabel->hide();
    scoreFontMini->hide();
    //复位显示是面链接槽
    hint->setOpacity(1);
    connect(this,SIGNAL(HintHide()), this, SLOT(hintOpacity()));
    //复位场景数据
    StartOver = true;
    PipeNumber = 1;
    //复位score
    score->resetScore();
}

void MyView::removeWhiteMark()
{
    scene()->removeItem(whiteMask);
}

void MyView::mousePressEvent(QMouseEvent *event)
{
    if(StartOver) {
        if(event->button() == Qt::LeftButton) {
            this->HintHide();
            this->birdFly();
        }
    } else
        emit this->start();
}
































