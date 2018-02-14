#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsItem>
#include <QObject>
#include <phonon>

class Bird : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Bird();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void resetBird();
signals:
    void birdDie();
    void downOk();
public slots:
    void upFly();
    void moveBird();
private:
    int oldAngle;               //记录旋转的角度
    bool downFly;               //判断是飞还是下落或则上升
    int angle;                  //旋转角度
    static int picture[3];      //记录图片位置
    int index;                  //图片数组用索引
    bool FlyAngle;              //记录fly时候是否更新了30度
    bool dieAngle;              //记录死亡后是否跟新了角度
    double dy;                  //小鸟下降距离
    bool aliveDie;              //判断小鸟是否或者活着或者死亡
    bool dieMove;               //标记小鸟死亡后前移
    int pictureRate;            //控制刷新频率
    bool prepareOrStart;        //判断是否开始游戏
    QPixmap pixmap1;            //保存三种状态加速绘图
    QPixmap pixmap2;
    QPixmap pixmap3;
    Phonon::MediaObject *flyMusic;
};
#endif // BIRD_H
