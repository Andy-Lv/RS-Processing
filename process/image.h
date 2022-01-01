//
// Created by andy on 2021/8/23.
//

#ifndef RS_PROCESSING_IMAGE_H
#define RS_PROCESSING_IMAGE_H

#pragma once
#include <iostream>
#include <map>
#include "gdal_priv.h"
#include "gdal.h"

#include <QDebug>

using namespace std;

class Image
{
public:
    //提取图像各波段像素矩阵
    void ReadImage(const char *InputImagePath);

    //输出图像信息
    int GetBandNum();

    int GetImgWidth();

    int GetImgHeight();

    int GetDepth();

    //输出图像波段像素信息
    map<int,double **> GetImageData();


protected:
    //图像信息
    int bandNum;
    int imgWidth;
    int imgHeight;
    int depth;


    //创建暂时储存像素值的二维数组空指针
    double **imagedata;

    //GDAL提取图像后的图像数据
    GDALDataset *ImageData;

    //各个波段的像素
    map<int, double **> banddata;

};

#endif //RS_PROCESSING_IMAGE_H
