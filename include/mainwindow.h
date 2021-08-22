//
// Created by andy on 2021/8/19.
//

#ifndef RS_PROCESSING_MAINWINDOW_H
#define RS_PROCESSING_MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include "include/treemenu.h"

QT_BEGIN_NAMESPACE
namespace Ui {
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
};

#endif //RS_PROCESSING_MAINWINDOW_H
