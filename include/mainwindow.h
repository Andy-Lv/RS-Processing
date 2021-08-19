//
// Created by andy on 2021/8/19.
//

#ifndef RS_PROCESSING_MAINWINDOW_H
#define RS_PROCESSING_MAINWINDOW_H

#include "ui/ui_mainwindow.h"

class mainwindow : public QMainWindow
{
Q_OBJECT

public:
    mainwindow(QWidget *parent = Q_NULLPTR);

    ~mainwindow();

private:
    Ui::MainWindow *ui_mainwindow;
};

#endif //RS_PROCESSING_MAINWINDOW_H
