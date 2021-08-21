//
// Created by andy on 2021/8/19.
//

#ifndef RS_PROCESSING_MAINWINDOW_H
#define RS_PROCESSING_MAINWINDOW_H

#include "ui/ui_mainwindow.h"
#include "include/treemenu.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

    ~MainWindow();

private:
    Ui::MainWindow *ui_mainwindow;
    QTreeWidget *treemenu=new TreeMenu();


};

#endif //RS_PROCESSING_MAINWINDOW_H
