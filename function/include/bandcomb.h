//
// Created by andy on 2021/8/29.
//

#ifndef RS_PROCESSING_BANDCOMB_H
#define RS_PROCESSING_BANDCOMB_H

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
    class Dialog_bandComb;
}
QT_END_NAMESPACE

class BandComb : public QDialog
{
Q_OBJECT

public:
    BandComb(QWidget *parent = Q_NULLPTR);

    void Init();

    void BandCombination();

public slots:
//    void soltInit();



private:
    Ui::Dialog_bandComb *ui_bandComb;

    //波段编号
    int band_R, band_G, band_B;

    QString InputImagePath;
    QString OutputImagePath;
    QString OutputImageName;

    //各个波段的像素
    map<int, double **> bandData;

    //图像信息
    int bandNum;
    int imgWidth;
    int imgHeight;
    int depth;
};


#endif //RS_PROCESSING_BANDCOMB_H
