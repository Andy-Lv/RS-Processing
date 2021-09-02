//
// Created by andy on 2021/8/23.
//

#include "image.h"

void Image::ReadImage(const char *InputImagePath)
{
    //GDAL所有操作都需要先注册
    GDALAllRegister();

    //支持中文路径
    CPLSetConfigOption("GDAL_FILENAME_IS_UTF8", "NO");


    //读取TIFF图像信息
    ImageData = (GDALDataset *) GDALOpen(InputImagePath, GA_ReadOnly);

    //判断图像是否读取成功
    if (ImageData == nullptr)
    {
        cout << "Can not open the image" << endl;
    }

    //读取图像信息

    this->imgWidth = ImageData->GetRasterXSize();//图像宽度
    this->imgHeight = ImageData->GetRasterYSize();//图像高度
    this->bandNum = ImageData->GetRasterCount();    //波段数
    this->depth = GDALGetDataTypeSize(ImageData->GetRasterBand(1)->GetRasterDataType()) / 8;    //图像深度

    //读取每个波段的像素值存入到map中,波段是从1开始
    for (int nband = 1; nband <= bandNum; nband++)
    {
        imagedata = new double *[imgHeight];
        for (int i = 0; i < imgHeight; i++)
        {
            imagedata[i] = new double[imgWidth];
        }

        //读取波段
        GDALRasterBand *poBand;
        poBand = ImageData->GetRasterBand(nband);

        //读取该波段的像素值
        float *pafScanline;
        pafScanline = (float *) CPLMalloc(sizeof(float) * imgWidth * imgHeight);

        poBand->RasterIO(GF_Read, 0, 0, imgWidth, imgHeight, pafScanline, imgWidth, imgHeight, GDT_Float32, 0, 0);

        int t = 0;
        for (int i = 0; i < imgHeight; i++)
        {
            for (int j = 0; j < imgWidth; j++)
            {
                imagedata[i][j] = (float) pafScanline[t++];
            }
        }

        //将每个波段像素插入到map中,从1开始
        this->banddata.insert(pair<int, double **>(nband, imagedata));

        //释放缓冲区
        CPLFree(pafScanline);
    }

    //关闭图像
    GDALClose(ImageData);
}

int Image::GetBandNum()
{
    return this->bandNum;
}

int Image::GetImgWidth()
{
    return this->imgWidth;
}

int Image::GetImgHeight()
{
    return this->imgHeight;
}

int Image::GetDepth()
{
    return this->depth;
}

map<int,double **> Image::GetImageData()
{
    return this->banddata;
}