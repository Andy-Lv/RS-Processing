//
// Created by andy on 2021/8/21.
//

#ifndef RS_PROCESSING_TREEMENU_H
#define RS_PROCESSING_TREEMENU_H

#pragma once
#include <QDialog>
#include <QTreeWidget>
#include <QComboBox>
#include <QDir>
#include <QLabel>
#include <QLineEdit>
#include <QScrollBar>
#include <QMenu>
#include <QProcess>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QFile>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <string>
#include <QDebug>
#include "include/mainwindow.h"

using namespace std;

// 创建文件时 弹出的窗体
class NewBulidFile : public QDialog
{
Q_OBJECT
public:
    NewBulidFile(QWidget *parent = 0);

    QLineEdit *fileNameEdit;
    QComboBox *fileNameTypeBox;
    QPushButton *okButton;
    QPushButton *cancalButton;
};

// 创建文件夹时弹出的窗体
class NewBuildfolder : public QDialog
{
Q_OBJECT
public:
    NewBuildfolder(QWidget *parent = 0);

    QLineEdit *fileNameEdit;
    QPushButton *okButton;
    QPushButton *cancalButton;
};

class TreeMenu : public QTreeWidget
{
Q_OBJECT

public:
    TreeMenu(QWidget *parent = 0);

    void CreateTopItem(QString path);

    void FindFile(QDir *path, QTreeWidgetItem *parent);

    void buttonCollapseItem();


private:
    QTreeWidgetItem *root; //树的根
    QMenu *dirMenu;  //文件夹菜单栏
    QMenu *fileMenu;  //文件菜单栏
    QTreeWidgetItem *nowItem; //当前光标所在Item
    int nowCol; //当前所在列
    NewBulidFile *newFileWidget;
    NewBuildfolder *newDirWidget;
    QString FilePath;

signals:

    void showTextSignal(QString path, QString name, QTreeWidgetItem *item);

    void collapseItemSignal(const QTreeWidgetItem *item);

    void renameSignal();

private slots:

    void DoubleClickpath(QTreeWidgetItem *item, int column);

    void itemPressedSlot(QTreeWidgetItem *pressedItem, int column);

    void tempActionInformation(QAction *act);

    void bulidNewFileSlot(bool flag);

    void closeBuildFileSlot(bool flag);

    void buildNewDirSlot(bool flag);

    void cancelDirSlot(bool flag);
};


#endif //RS_PROCESSING_TREEMENU_H
