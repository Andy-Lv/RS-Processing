//
// Created by andy on 2021/8/19.
//

#ifndef RS_PROCESSING_MAINWINDOW_H
#define RS_PROCESSING_MAINWINDOW_H

#pragma once
#include <unistd.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include "include/treemenu.h"
#include "include/picturebox.h"
#include "function/include/newfolder.h"
#include "function/include/bandcomb.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

    ~MainWindow();

private:
    Ui::MainWindow *ui_mainwindow;
//    打开新工程
    NewFolder dialog_newfolder;//声明新建文件夹对话框
    QString folderPath;//当前工程所在路径

//    波段组合
    BandComb dialog_bandComb;
};

#endif //RS_PROCESSING_MAINWINDOW_H
