//
// Created by andy on 2021/8/19.
//

#ifndef RS_PROCESSING_LOGIN_H
#define RS_PROCESSING_LOGIN_H

#include <QDialog>
#include <QRegExpValidator>
#include "ui/ui_login.h"
#include "include/mainwindow.h"
class Login : public QDialog
{
Q_OBJECT

public:
    Login(QWidget *parent = Q_NULLPTR);

    ~Login();


private:
    Ui::Dialog_login *ui_login;

    //声明一个新窗口
    MainWindow m_window;
    //TreeWidget treemenu;

};

#endif //RS_PROCESSING_LOGIN_H
