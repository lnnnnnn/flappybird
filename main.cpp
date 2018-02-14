#include "myview.h"
#include <QApplication>
#include <QTime>
#include <QTextCodec>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //设置随机数的初始值
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    MyView a;
    a.show();
    return app.exec();
}
