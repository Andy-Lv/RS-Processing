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
#include "qcustomplot.h"


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

    //图像信息
    Image theImage;

    int bandNum = 1;//默认为第一波段

    int bandNum_all;

    int minimum,maximum;//拉伸范围
};

class Histogram : public QWidget
{
Q_OBJECT

public:
    explicit Histogram(QWidget *parent = 0);

    ~Histogram();

    void DrawHistogram(unsigned long long *histogramArray, double maximumValue,int min, int max);
};

#endif //RS_PROCESSING_IMGSTRETCH_H
