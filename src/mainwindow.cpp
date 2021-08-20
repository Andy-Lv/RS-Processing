//
// Created by andy on 2021/8/19.
//

#include "include/mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
        : QMainWindow(parent), ui_mainwindow(new Ui::MainWindow)
{
    ui_mainwindow->setupUi(this);

}


mainwindow::~mainwindow()
{

}