//
// Created by andy on 2021/8/19.
//

#include "include/mainwindow.h"
#include "ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui_mainwindow(new Ui::MainWindow)
{

    ui_mainwindow->setupUi(this);
    ui_mainwindow->treeWidget->CreateTopItem("./");



//    connect(ui_mainwindow->pushButton_new,&QPushButton::released,this,
//            [=]()
//            {
//                TreeMenu *treeMenu=new TreeMenu();
//
////                ui_mainwindow->treeWidget=treeMenu;
////                ui_mainwindow-
//                treeMenu->resize(250,700);
//                treeMenu->CreateTopItem("./");
//                treeMenu->show();
//            });

}


MainWindow::~MainWindow()
{

}