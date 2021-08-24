//
// Created by andy on 2021/8/23.
//

#ifndef RS_PROCESSING_PROCESS_H
#define RS_PROCESSING_PROCESS_H

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <qimage.h>
#include <map>
#include "gdal_priv.h"
#include "gdal.h"
#include "Eigen/Eigen"

using namespace Eigen;
using namespace std;

class Process
{
public:
    //波段组合
    void BandCombination(const char *InputImagePath, const QString outputimage);

    //图像拉伸
    void ImageStretching(const char *InputImagePath, const char *outputimage);

    //获取纠正前后像素坐标
    void GetCoordinate();

    //获取纠正参数
    void GetParameter(double source_x[8],
                      double source_y[8],
                      double target_x[8],
                      double target_y[8]);

    //相对配准(间接法)
    void RelativeRegistration(const char *outputimage);

protected:
    //定义参数数组(二阶多项式)
    double para_a[6];
    double para_b[6];

    //定义,纠正前的图像坐标
    double coor_x[8];
    double coor_y[8];
    //定义纠正后的图像坐标
    double coor_a[8];
    double coor_b[8];

    int new_imgWidth;
    int new_imgHeight;

};

#endif //RS_PROCESSING_PROCESS_H
