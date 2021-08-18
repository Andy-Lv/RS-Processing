//
// Created by andy on 2021/8/19.
//

#include "include/login.h"

login::login(QWidget *parent)
        : QDialog(parent), ui_login(new Ui::Dialog_login)
{
    ui_login->setupUi(this);

    //设置只能输入数字和英文,使用正则表达式
    QRegExpValidator *pRevalidotor = new QRegExpValidator(QRegExp("[a-zA-Z0-9]{25}"), this);
    ui_login->lineEdit_ID->setValidator(pRevalidotor);
    ui_login->lineEdit_Pwd->setValidator(pRevalidotor);



//    connect(ui_login->pushButton_login, &QPushButton::released, this, [=]()
//    {
//        b.show();
//    });

//    //处理子窗口的信号
//    connect(&b, &back::Mysignal, this, [=]()
//    {
//        b.close();
//        this->show();
//    });
}

login::~login()
{

}
