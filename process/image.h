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

    map<int, double> GetMinimumValue();
    map<int, double> GetMaximumValue();
    map<int, double> GetMeanValue();
    map<int, double> GetSigmaValue();

    //输出图像直方图信息
    map<int,unsigned long long *>GetHistogramArray();


protected:
    //图像信息
    int bandNum;
    int imgWidth;
    int imgHeight;
    int depth;

    //获取各个波段的
    map<int, double> minimumValue;//最小值
    map<int, double> maximumValue;//最大值
    map<int, double> meanValue;//平均值
    map<int, double> sigmaValue;//标准差

    //创建暂时储存像素值的二维数组空指针
    double **imagedata;

    //GDAL提取图像后的图像数据
    GDALDataset *ImageData;

    //各个波段的像素
    map<int, double **> banddata;

    //各波段的直方图
    map<int,unsigned long long *>histogramArray;
};

#endif //RS_PROCESSING_IMAGE_H
