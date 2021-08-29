//
// Created by andy on 2021/8/29.
//

#ifndef RS_PROCESSING_BANDCOMB_H
#define RS_PROCESSING_BANDCOMB_H

#pragma once

#include <QDialog>
#include <QString>
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

    void Init(QString InputImagePath,QString InputImageName);

    void BandCombination(const char *InputImagePath, int band_R, int band_G, int band_B);

public slots:
//    void soltInit();



private:
    Ui::Dialog_bandComb *ui_bandComb;

    //波段编号
    int band_R, band_G, band_B;

    QString InputImagePath;
    QString OutputImagePath;
    QString InputImageName;
    QString OutputImageName;

    //各个波段的像素
    map<int, double **> banddata;

    //图像信息
    int bandNum;
    int imgWidth;
    int imgHeight;
    int depth;
};


#endif //RS_PROCESSING_BANDCOMB_H
