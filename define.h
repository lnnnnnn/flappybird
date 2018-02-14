#ifndef DEFINE_H
#define DEFINE_H
//Pipe用宏
#define GAP                     100                 //水管开口大小
#define GROUND_DISTANCE         113                 //地板高度
#define PIPE_DISTANCE           50                  //管道开口高度
#define RAND                    298                 //水管高度随机数
#define NEED_PIPE_TIME          1670                //需要PIPE的时间
//Bird用宏
#define PI                      3.141592654         //小鸟下落旋转系数
#define FLY_COEFFICIENT         -4                  //小鸟上升系数
#define DROP_COEFFICIENT        0.05                //下落用下落系数
#define DOWN_COEFFICIENT        0.15                //上升用下落系数
#define BIRD_FRAME_RATE         70                  //BIRD游戏帧数
#define DOWN_LOWER              60                  //下落角度极限
#define DIE_SCENE_DX            30                  //死亡往前移动制造正好撞击的效果
#define CORRECT_ANGLE           -30                 //死亡后矫正角度使小鸟保持水平
#define RISEZ_PERFECT           -30                 //最佳的向上飞行角度
#define PREPARE                 false               //false为准备状态
#define START                   true                //true为开始状态
#define BIRD_ALIVE              true                //true表示活着
#define BIRD_DIE                false               //false表示死亡
#define DIE_PERFECT_ANGLE       60                  //最佳死亡角度
#define BIRD_DOWN               true                //标示当前小鸟是下落
#define BIRD_FLY                false               //标示当前小鸟是上升
#define SCENE_HIGH              0                   //场景顶部
#define BIRD_RATE               7                   //bird图片刷新频率
#define SCENE_LOW               450                 //bird下落最低位置
//Ground用宏
#define GROUND_FRAME_RATE       167                 //GROUND游戏帧数
//计分器用宏
#define SCORE_WIDTH             40                  //score图片x轴偏移量
#define SCORE_HEIGHT            60                  //score图片y轴偏移量
//Rank用宏
#define SCORE_MINI_WIDTH        25                  //scoreMini图片x轴偏移量
#define SCORE_MINI_HEIGHT       32                  //scoreMini图片y轴偏移量


#endif // DEFINE_H
