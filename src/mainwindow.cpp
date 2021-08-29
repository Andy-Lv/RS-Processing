//
// Created by andy on 2021/8/19.
//

#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_newfolder.h"
#include "ui_bandcombination.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui_mainwindow(new Ui::MainWindow)
{

    ui_mainwindow->setupUi(this);


    connect(ui_mainwindow->treeWidget, SIGNAL(showTextSignal(QString, QString, QTreeWidgetItem * )),
            ui_mainwindow->widget,SLOT(showImage(QString,QString)));

//    page_edit
    //新建文件夹
    connect(ui_mainwindow->pushButton_new, &QPushButton::released, this,
            [=]()
            {
                dialog_newfolder.show();
                connect(this->dialog_newfolder.ui_newFolder->pushButton_OK, &QPushButton::released, this,
                        [=]()
                        {
                            folderPath = dialog_newfolder.folderPath;
                            if (folderPath != "")
                            {
                                ui_mainwindow->treeWidget->CreateTopItem(folderPath);
                            }
                        });
            });

    //打开文件夹
    connect(ui_mainwindow->pushButton_open, &QPushButton::released, this,
            [=]()
            {
                //获取文件夹路径,获取文件路径为getOpenFileName(this, "pushButton_open");
                folderPath = QFileDialog::getExistingDirectory(this, "pushButton_open");
                if (folderPath != "")
                {
                    ui_mainwindow->treeWidget->CreateTopItem(folderPath);
                }
            });


    //波段组合
    connect(ui_mainwindow->pushButton_bandComb,&QPushButton::released,this,
            [=]()
            {
                dialog_bandComb.show();
            });

}


MainWindow::~MainWindow()
{

}