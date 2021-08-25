//
// Created by andy on 2021/8/19.
//

#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui_mainwindow(new Ui::MainWindow)
{

    ui_mainwindow->setupUi(this);
    ui_mainwindow->treeWidget->CreateTopItem("/home/andy/Code/C++/RS-Processing");

}


MainWindow::~MainWindow()
{

}