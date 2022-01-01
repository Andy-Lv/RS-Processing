//
// Created by andy on 2021/8/18.
//

#include <QApplication>//包含一个应用程序的类

#include "include/login.h"


//main程序的入口 argc命令行变量的数量 argv命令行变量的数组
int main(int argc, char *argv[])
{
    //a应用程序对象，在QT中，应用程序对象，有且只有一个
    QApplication a(argc, argv);

    //窗口对象
    Login w;

    //窗口对象不会默认显示，必须调用show方法
    w.show();

    //让应用程序对象进入消息循环
    return a.exec();
}