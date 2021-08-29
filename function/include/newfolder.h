//
// Created by andy on 2021/8/26.
//

#ifndef RS_PROCESSING_NEWFOLDER_H
#define RS_PROCESSING_NEWFOLDER_H

#pragma once

#include <QDialog>
#include <QRegExpValidator>
#include <QFileDialog>
#include <QMessageBox>
#include <unistd.h>
#include <sys/stat.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Dialog_newFolder;
}
QT_END_NAMESPACE

class NewFolder : public QDialog
{
Q_OBJECT

public:
    NewFolder(QWidget *parent = Q_NULLPTR);

    ~NewFolder();

    QString folderPath;//选择新建工程路径

    Ui::Dialog_newFolder *ui_newFolder;

};

#endif //RS_PROCESSING_NEWFOLDER_H
