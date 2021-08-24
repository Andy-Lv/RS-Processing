//
// Created by andy on 2021/8/23.
//

#ifndef RS_PROCESSING_PROCESS_H
#define RS_PROCESSING_PROCESS_H

#pragma once

#include <iostream>
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

};

#endif //RS_PROCESSING_PROCESS_H
