//
// Created by andy on 2021/8/23.
//

#include "include/processing/process.h"
#include "include/processing/image.h"

//波段组合
void Process::BandCombination(const char *InputImagePath, const QString outputimage)
{
    Image theImage;

    //读取图像所有波段,每个波段的像素数据储存在map容器banddata中
    //TODO 图片路径需要指定
    theImage.ReadImage("InputImagePath");

    int imgWidth = theImage.GetImgWidth();
    int imgHeight = theImage.GetImgHeight();
    map<int, double **> bandData = theImage.GetImageData();

    //创建绘图设备
    QImage image(imgWidth, imgHeight, QImage::Format_ARGB32);

    //QImage可以修改图片
    for (int i = 0; i < imgHeight; i++)
    {
        for (int j = 0; j < imgWidth; j++)
        {
            //设置像素
            //TODO 此处需要设置波段组合的顺序
            image.setPixel(QPoint(j, i), qRgb(bandData.find(4)->second[i][j],
                                              bandData.find(3)->second[i][j],
                                              bandData.find(2)->second[i][j]));
        }
    }

    //保存图片
    image.save("../Output_Image/" + outputimage + ".png");

    cout << "成功输出波段组合后图像 " << outputimage.toStdString() << ".png" << endl;
}

//图像拉伸
void Process::ImageStretching(const char *InputImagePath, const char *outputimage)
{
    Image theImage;

    //读取图像所有波段,每个波段的像素数据储存在map容器banddata中
    //TODO 图片路径需要指定
    theImage.ReadImage("InputImagePath");

    int imgWidth = theImage.GetImgWidth();
    int imgHeight = theImage.GetImgHeight();
    int bandNum=theImage.GetBandNum();
    map<int, double **> bandData = theImage.GetImageData();

    GDALAllRegister();

    //原始图像
    GDALDataset *InputImage = (GDALDataset *) GDALOpen(InputImagePath, GA_ReadOnly);

    //图像驱动
    GDALDriver *poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");

    //创建8bit的数据
    GDALDataset *OutputImage = poDriver->Create("../Output_Image/gaojing_Stretched.tif", imgWidth, imgHeight, bandNum,
                                                GDT_Byte,
                                                NULL);
    double dGeoTrans[6] = {0};

    //设置仿射变换参数
    InputImage->GetGeoTransform(dGeoTrans);
    OutputImage->SetGeoTransform(dGeoTrans);
    //设置图像投影信息
    OutputImage->SetProjection(InputImage->GetProjectionRef());

    //用于保存读取的16bit数据
    GUInt16 *InputData = new GUInt16[imgHeight * imgWidth];
    //用于输出的8bit数据
    GByte *OutputData = new GByte[imgHeight * imgWidth];

    double minimumValue, maximumValue, meanValue, sigmaValue;

    //定义直方图段数和数组
    int histogramBuckets = 1024;
    unsigned long long *histogramArray = new unsigned long long[histogramBuckets];

    //循环波段
    for (int iBand = 1; iBand <= bandNum; iBand++)
    {
        GDALRasterBand *InputBand = InputImage->GetRasterBand(iBand);
        GDALRasterBand *OutputBand = OutputImage->GetRasterBand(iBand);

        //获取该波段的最大值 最小值 平均值 和标准差
        InputBand->GetStatistics(true, true, &minimumValue, &maximumValue, &meanValue, &sigmaValue);

        //获取该波段灰度直方图
        InputBand->GetHistogram(
                minimumValue - std::numeric_limits<double>::epsilon(),
                maximumValue + std::numeric_limits<double>::epsilon(),
                histogramBuckets,
                histogramArray,
                false,
                false,
                GDALDummyProgress,
                nullptr);

        //定义线性拉伸界限
        double minPercent = 0;
        double maxPercent = 1;

        unsigned long long p1 = 0;
        unsigned long long p2 = histogramBuckets - 1;

        while (minPercent < 0.02)
        {
            minPercent += (double) histogramArray[p1++] /
                    double(imgWidth * imgHeight);
        }
        while (maxPercent > 0.98)
        {
            maxPercent -= (double) histogramArray[p2--] /
                    double(imgWidth * imgHeight);
        }

        //确定线性拉伸范围灰度值界限
        double gap=maximumValue - minimumValue;
        double pixgap = gap /(double)histogramBuckets;
        double minpix = p1 * pixgap + minimumValue;
        double maxpix = p2 * pixgap + minimumValue;
        double stretched_gap=maxpix-minpix;





        //将数据读出来
        InputBand->RasterIO(GF_Read, 0, 0, imgWidth, imgHeight, InputData, imgWidth, imgHeight, GDT_UInt16, 0, 0);

        for (int i = 0; i < imgHeight; i++)    //循环图像高
            {
            //循环，将16bit数据专为8bit数据，使用线性拉伸方式
            for (int j = 0; j < imgWidth; j++)
            {
                if (InputData[i * imgWidth + j] < minpix)
                    OutputData[i * imgWidth + j] = 0;
                else if (InputData[i * imgWidth + j] >= minpix && InputData[i * imgWidth + j] < maxpix)
                {
                    double temp=((double)InputData[i * imgWidth + j] - minpix) / stretched_gap * 255;
                    OutputData[i * imgWidth + j] =(GByte)temp;
                    //cout<<OutputData[i * imgWidth + j]<<endl;
                }
                if (InputData[i * imgWidth + j] > maxpix)
                    OutputData[i * imgWidth + j] = 255;
            }
            }
            OutputBand->RasterIO(GF_Write, 0, 0, imgWidth, imgHeight, OutputData, imgWidth, imgHeight, GDT_Byte, 0, 0);
    }

    delete[] InputData;
    delete[] OutputData;
    //关闭原始图像和结果图像
    GDALClose((GDALDatasetH) OutputImage);
    GDALClose((GDALDatasetH) InputImage);

    cout << "成功实现图像16bit -> 8bit转换" << endl;
    cout << "成功实现图像分段线性拉伸" << endl;
    cout << "成功保存拉伸完的图像:" << outputimage << endl;
}
