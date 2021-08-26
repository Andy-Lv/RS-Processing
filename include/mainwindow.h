//
// Created by andy on 2021/8/19.
//

#ifndef RS_PROCESSING_MAINWINDOW_H
#define RS_PROCESSING_MAINWINDOW_H

#pragma once
#include <unistd.h>
#include <QMainWindow>
#include <QFileDialog>
#include "include/treemenu.h"
#include "include/newfolder.h"

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
    NewFolder dialog_newfolder;//声明新建文件夹对话框
    QString folderPath;//当前工程所在路径
};

#endif //RS_PROCESSING_MAINWINDOW_H
