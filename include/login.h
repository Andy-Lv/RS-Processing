//
// Created by andy on 2021/8/19.
//

#ifndef RS_PROCESSING_LOGIN_H
#define RS_PROCESSING_LOGIN_H

#include <QDialog>
#include <QRegExpValidator>
#include "include/mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Dialog_login;
}
QT_END_NAMESPACE

class Login : public QDialog
{
Q_OBJECT

public:
    Login(QWidget *parent = Q_NULLPTR);

    ~Login();


private:
    Ui::Dialog_login *ui_login;

    //声明主新窗口
    MainWindow m_window;

};

#endif //RS_PROCESSING_LOGIN_H
