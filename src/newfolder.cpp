//
// Created by andy on 2021/8/26.
//
#include "ui_newfolder.h"
#include "include/newfolder.h"

NewFolder::NewFolder(QWidget *parent)
        : QDialog(parent), ui_newFolder(new Ui::Dialog_newFolder)
{
    ui_newFolder->setupUi(this);
    //打开文件管理器,寻找文件创建位置
    connect(ui_newFolder->pushButton_openFolder, &QPushButton::released, this,
            [=]()
            {
                folderPath = QFileDialog::getExistingDirectory(this, "pushButton_open");
                if (folderPath != "")
                {
                    ui_newFolder->lineEdit_path->setText(folderPath);
                }
            });

    //点击ok按钮创建新文件夹
    connect(ui_newFolder->pushButton_OK, &QPushButton::released, this,
            [=]()
            {
                if (ui_newFolder->lineEdit_path->text() != "")
                {
                    folderPath = ui_newFolder->lineEdit_path->text();
                }

                if (folderPath == "")
                {
                    QMessageBox::warning(this, tr("警告"), tr("路径不能为空"));
                    return;
                }

                if (ui_newFolder->lineEdit_Name->text() == "")
                {
                    QMessageBox::warning(this, tr("警告"), tr("路径不能为空"));
                    return;
                }

                folderPath = folderPath + "/" + ui_newFolder->lineEdit_Name->text();

                if (access(folderPath.toStdString().c_str(), F_OK) != -1)
                {
                    QMessageBox::warning(this, tr("警告"), tr("文件已存在"));
                    return;
                }

                mkdir(folderPath.toStdString().c_str(), S_IRWXU | S_IRWXG | S_IRWXO);//所有人都可读写和运行,777权限
                this->close();
            });

    //点击cancel按钮关闭对话框
    connect(ui_newFolder->pushButton_Cancel, &QPushButton::released, this,
            [=]()
            {
                this->close();
            });
}

NewFolder::~NewFolder()
{

}