//
// Created by andy on 2021/8/19.
//

#include "include/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui_mainwindow(new Ui::MainWindow)
{
    //ui_mainwindow->treeWidget=new TreeMenu;
    ui_mainwindow->setupUi(this);
    treemenu->show();


//    ui_mainwindow->treeWidget->show();

}


MainWindow::~MainWindow()
{

}