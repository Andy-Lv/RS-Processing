//
// Created by andy on 2021/9/7.
//

#ifndef RS_PROCESSING_IMGSTRETCH_H
#define RS_PROCESSING_IMGSTRETCH_H

#pragma once

#include <QDialog>
#include <QString>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <map>
#include "process/image.h"


QT_BEGIN_NAMESPACE
namespace Ui
{
    class Dialog_imgStretch;
}
QT_END_NAMESPACE

class ImgStretch : public QDialog
{
Q_OBJECT

public:
    ImgStretch(QWidget *parent = Q_NULLPTR);

    void Init();

    void ImageStretching_tif();
    void ImageStretching_png();

private:
    Ui::Dialog_imgStretch *ui_imgStretch;

    QString InputImagePath;
    QString OutputImagePath;
    QString OutputImageName;

    //各个波段的像素
    map<int, double **> bandData;

    //图像信息
    int bandNum_all;
    int bandNum = 1;//当前为第几波段
    int imgWidth;
    int imgHeight;
    int depth;


};

#endif //RS_PROCESSING_IMGSTRETCH_H
