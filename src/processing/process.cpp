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
    int bandNum = theImage.GetBandNum();
    map<int, double **> bandData = theImage.GetImageData();

    GDALAllRegister();

    //原始图像
    GDALDataset *InputImage = (GDALDataset *) GDALOpen(InputImagePath, GA_ReadOnly);

    //图像驱动
    GDALDriver *poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");

    //创建8bit的数据
    //TODO 输出图像需要指定
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
        double gap = maximumValue - minimumValue;
        double pixgap = gap / (double) histogramBuckets;
        double minpix = p1 * pixgap + minimumValue;
        double maxpix = p2 * pixgap + minimumValue;
        double stretched_gap = maxpix - minpix;





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
                    double temp = ((double) InputData[i * imgWidth + j] - minpix) / stretched_gap * 255;
                    OutputData[i * imgWidth + j] = (GByte) temp;
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

//获取同名点坐标
void Process::GetCoordinate()
{
    //TODO 获取纠正前和纠正后的同名点坐标
    // 两种解决方案
    // 1:点击图片坐标位置,直接传入此函数中获取变换参数
    // 2 获取图像坐标之后存取到临时文件中,再读取


    //定义中间变量
    int i = 0;
    double x, y;

    //打开纠正前坐标文件
    ifstream source;
    source.open("../data/Geometric_Correction/movingpoints.txt", ios::in);

    if (!source.is_open())
        cout << "can not open the movingpoints.txt" << endl;

    while (!source.eof())
    {
        //读取x坐标和y坐标
        source >> x >> y;
        this->coor_x[i] = x;
        this->coor_y[i] = y;
        //i+1 使得下一个读取的数据赋值到数组中
        i++;
    }
    source.close();

    //重置i
    i = 0;

    //读取纠正后坐标文件
    ifstream target;
    target.open("../data/Geometric_Correction/fixdpoints.txt", ios::in);

    if (!target.is_open())
        cout << "can not open the fixdpoints.txt" << endl;

    while (!target.eof())
    {
        //读取x坐标和y坐标
        target >> x >> y;
        this->coor_a[i] = x;
        this->coor_b[i] = y;
        //i+1 使得下一个读取的数据赋值到数组中
        i++;
    }
    target.close();
}

//获取变换参数
void Process::GetParameter(double source_x[8],
                           double source_y[8],
                           double target_x[8],
                           double target_y[8])
{
    //定义参数矩阵
    Matrix<double, 6, 1> delt_a;
    Matrix<double, 6, 1> delt_b;
    Matrix<double, 8, 6> A;
    Matrix<double, 8, 1> Lx;
    Matrix<double, 8, 1> Ly;
    Matrix<double, 8, 1> Vx;
    Matrix<double, 8, 1> Vy;

    //给参数矩阵赋值
    for (int i = 0; i < 8; ++i)
    {
        A(i, 0) = 1;
        A(i, 1) = target_x[i];
        A(i, 2) = target_y[i];
        A(i, 3) = pow(target_x[i], 2);
        A(i, 4) = target_x[i] * target_y[i];
        A(i, 5) = pow(target_y[i], 2);
        //        for (int j = 0; j < 6; ++j)
        //        {
        //            cout<<A(i,j)<<" ";
        //        }
        //        cout<<endl;
    }

    for (int i = 0; i < 8; ++i)
    {
        Lx(i, 0) = source_x[i];
        Ly(i, 0) = source_y[i];
        //cout<<source_x[i]<<" "<<source_y[i]<<endl;
    }

    //计算多项式系数
    delt_a = (A.transpose() * A).inverse() * A.transpose() * Lx;
    delt_b = (A.transpose() * A).inverse() * A.transpose() * Ly;

    //返回多项式结果到参数数组中
    for (int i = 0; i < 6; ++i)
    {
        //cout<<delt_a(i,0)<<" "<<delt_b(i,0)<<endl;
        this->para_a[i] = delt_a(i, 0);
        this->para_b[i] = delt_b(i, 0);
    }
}

//相对纠正
void Process::RelativeRegistration(const char *outputimage)
{
//第一步:纠正后图像边界范围确定

    //读取第一波段获得图像属性数据
    Image wuce;
    const char *InputImagePath = "../data/Geometric_Correction/wucesource.tif";
    wuce.ReadImage(InputImagePath);

    //获取四个角点像素坐标
    int corner_x[4] = {0, wuce.GetImgWidth(), wuce.GetImgWidth(), 0};
    int corner_y[4] = {0, 0, wuce.GetImgHeight(), wuce.GetImgWidth()};

    //计算角点转换后的坐标位置
    double new_corner_x[4];
    double new_corner_y[4];

    //获取参数
    this->GetParameter(coor_a, coor_b, coor_x, coor_y);

    for (int i = 0; i < 4; ++i)
    {
        new_corner_x[i] = this->para_a[0] + this->para_a[1] * corner_x[i] +
                          this->para_a[2] * corner_y[i] + this->para_a[3] * pow(corner_x[i], 2) +
                          this->para_a[4] * corner_x[i] * corner_y[i] + this->para_a[5] * pow(corner_y[i], 2);
        new_corner_y[i] = this->para_b[0] + this->para_b[1] * corner_x[i] +
                          this->para_b[2] * corner_y[i] + this->para_b[3] * pow(corner_x[i], 2) +
                          this->para_b[4] * corner_x[i] * corner_y[i] + this->para_b[5] * pow(corner_y[i], 2);
    }

    //获取转换后坐标位置的最大值和最小值
    double max_x, max_y, min_x, min_y;
    double temp_x = 0;
    double temp_y = 0;

    for (int i = 0; i < 4; ++i)
    {
        temp_x = max(temp_x, new_corner_x[i]);
        temp_y = max(temp_y, new_corner_y[i]);
    }
    max_x = temp_x;
    max_y = temp_y;

    for (int i = 0; i < 4; ++i)
    {
        temp_x = min(temp_x, new_corner_x[i]);
        temp_y = min(temp_y, new_corner_y[i]);
    }
    min_x = temp_x;
    min_y = temp_y;

    this->new_imgWidth = int((max_x - min_x)) + 1;
    this->new_imgHeight = int((max_y - min_y)) + 1;

    //间接法纠正
    GDALAllRegister();
    //图像驱动
    GDALDriver *poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");

    GDALDataset *InputImage = (GDALDataset *) GDALOpen(InputImagePath, GA_ReadOnly);
    //创建8bit的数据
    GDALDataset *TargetImage = poDriver->Create("../Output_Image/wuce_corrected.tif", new_imgWidth, new_imgHeight,
                                                wuce.GetBandNum(),
                                                GDT_Byte,
                                                NULL);
    double dGeoTrans[6] = {0};

    //设置仿射变换参数
    InputImage->GetGeoTransform(dGeoTrans);
    TargetImage->SetGeoTransform(dGeoTrans);
    //设置图像投影信息
    TargetImage->SetProjection(InputImage->GetProjectionRef());

    //用于保存读取的8bit数据
    GByte *TargetData = new GByte[new_imgHeight * new_imgWidth];
    //定义两幅图像坐标远点的偏移
    int Dx = int(min_x);
    int Dy = int(min_y);

    //定义原始波段像素数据
    double **banddata;

    //定义间接法回到原图像后的坐标
    double Gx, Gy;

    double temp;

    //获取参数
    this->GetParameter(coor_x, coor_y, coor_a, coor_b);

    //循环波段
    for (int iBand = 1; iBand <= wuce.GetBandNum(); iBand++)
    {
        GDALRasterBand *TargetBand = TargetImage->GetRasterBand(iBand);

        wuce.ReadImage(InputImagePath);
        banddata = wuce.GetImageData().find(iBand)->second;

        for (int i = 0; i < new_imgHeight; i++)    //循环图像高
        {
            //循环新图像,采用间接法双线性内插方式获取像素值
            for (int j = 0; j < new_imgWidth; j++)
            {
                //新图像坐标系转换为原图像的坐标系
                Gx = this->para_a[0] + this->para_a[1] * (j + Dx) +
                     this->para_a[2] * (i + Dy) + this->para_a[3] * pow((j + Dx), 2) +
                     this->para_a[4] * (j + Dx) * (i + Dy) + this->para_a[5] * pow((i + Dy), 2);
                Gy = this->para_b[0] + this->para_b[1] * (j + Dx) +
                     this->para_b[2] * (i + Dy) + this->para_b[3] * pow((j + Dx), 2) +
                     this->para_b[4] * (j + Dx) * (i + Dy) + this->para_b[5] * pow((i + Dy), 2);

                //双线性内插
                if (Gx < wuce.GetImgWidth() && Gy < wuce.GetImgHeight() && Gx >= 0 && Gy >= 0)
                {
                    double p = Gx - int(Gx);
                    double q = Gy - int(Gy);
                    if (Gx + 1 > wuce.GetImgWidth() || Gy + 1 > wuce.GetImgHeight())
                    {
                        temp = banddata[int(Gy)][int(Gx)];
                    } else
                    {
                        temp =
                                (1 - q) * ((1 - p) * banddata[int(Gy)][int(Gx)] + p * banddata[int(Gy)][int(Gx + 1)]) +
                                q * ((1 - p) * banddata[int(Gy + 1)][int(Gx)] + p * banddata[int(Gy + 1)][int(Gx + 1)]);
                    }
                    temp = (int) temp;
                    TargetData[i * new_imgWidth + j] = (GByte) temp;
                    temp = 0;
                } else
                {
                    TargetData[i * new_imgWidth + j] = (GByte) 255;
                }
            }
        }
        TargetBand->RasterIO(GF_Write, 0, 0, new_imgWidth, new_imgHeight, TargetData, new_imgWidth, new_imgHeight,
                             GDT_Byte, 0, 0);
    }
    delete[] TargetData;    //释放内存
    //关闭原始图像和结果图像
    GDALClose((GDALDatasetH) TargetImage);
    GDALClose((GDALDatasetH) InputImage);

    cout << "成功保存配准后的图像: " << outputimage << endl;
}

//void Process::GetNDWI()
//{
//    The_Image wuhan;
//    BandData wuhan_water;
//
//    //wuhan_1993的TM2和TM4储存在banddata_1和banddata_2中
//    wuhan.ReadImage("../data/Water/1993_10_12_B2.TIF", 1);
//    wuhan_water.banddata_1 = wuhan.GetImageData();
//
//    wuhan.ReadImage("../data/Water/1993_10_12_B4.TIF", 1);
//    wuhan_water.banddata_2 = wuhan.GetImageData();
//
//    //wuhan_2005的TM2和TM4储存在banddata_3和banddata_4中
//    wuhan.ReadImage("../data/Water/2005_09_11_B2.TIF", 1);
//    wuhan_water.banddata_3 = wuhan.GetImageData();
//
//    wuhan.ReadImage("../data/Water/2005_09_11_B4.TIF", 1);
//    wuhan_water.banddata_4 = wuhan.GetImageData();
//
//    //获取图像大小
//    this->imgWidth = wuhan.GetImgWidth();
//    this->imgHeight = wuhan.GetImgHeight();
//
//
//    //创建NDWI像素矩阵
//    this->NDWI_1993 = new double *[wuhan.GetImgHeight()];
//    for (int i = 0; i < wuhan.GetImgHeight(); i++)
//    {
//        this->NDWI_1993[i] = new double[wuhan.GetImgWidth()];
//    }
//
//    //创建MNDWI像素矩阵
//    this->NDWI_2005 = new double *[wuhan.GetImgHeight()];
//    for (int i = 0; i < wuhan.GetImgHeight(); i++)
//    {
//        this->NDWI_2005[i] = new double[wuhan.GetImgWidth()];
//    }
//
//    //计算NDWI
//    for (int i = 0; i < wuhan.GetImgHeight(); ++i)
//    {
//        for (int j = 0; j < wuhan.GetImgWidth(); ++j)
//        {
//            NDWI_1993[i][j] = (wuhan_water.banddata_1[i][j] - wuhan_water.banddata_2[i][j]) /
//                    (wuhan_water.banddata_1[i][j] + wuhan_water.banddata_2[i][j]);
//            NDWI_2005[i][j] = (wuhan_water.banddata_3[i][j] - wuhan_water.banddata_4[i][j]) /
//                    (wuhan_water.banddata_3[i][j] + wuhan_water.banddata_4[i][j]);
//        }
//    }
//}
//
//void Process::GetMNDWI()
//{
//    The_Image wuhan;
//    BandData wuhan_water;
//
//    //wuhan_1993的TM2和TM5储存在banddata_1和banddata_2中
//    wuhan.ReadImage("../data/Water/1993_10_12_B2.TIF", 1);
//    wuhan_water.banddata_1 = wuhan.GetImageData();
//
//    wuhan.ReadImage("../data/Water/1993_10_12_B5.TIF", 1);
//    wuhan_water.banddata_2 = wuhan.GetImageData();
//
//    //wuhan_2005的TM2和TM5储存在banddata_3和banddata_4中
//    wuhan.ReadImage("../data/Water/2005_09_11_B2.TIF", 1);
//    wuhan_water.banddata_3 = wuhan.GetImageData();
//
//    wuhan.ReadImage("../data/Water/2005_09_11_B5.TIF", 1);
//    wuhan_water.banddata_4 = wuhan.GetImageData();
//
//
//    //创建MNDWI_1993像素矩阵
//    this->MNDWI_1993 = new double *[wuhan.GetImgHeight()];
//    for (int i = 0; i < wuhan.GetImgHeight(); i++)
//    {
//        this->MNDWI_1993[i] = new double[wuhan.GetImgWidth()];
//    }
//
//    //创建MNDWI_2005像素矩阵
//    this->MNDWI_2005 = new double *[wuhan.GetImgHeight()];
//    for (int i = 0; i < wuhan.GetImgHeight(); i++)
//    {
//        this->MNDWI_2005[i] = new double[wuhan.GetImgWidth()];
//    }
//
//    //计算NDWI
//    for (int i = 0; i < wuhan.GetImgHeight(); ++i)
//    {
//        for (int j = 0; j < wuhan.GetImgWidth(); ++j)
//        {
//            MNDWI_1993[i][j] = (wuhan_water.banddata_1[i][j] - wuhan_water.banddata_2[i][j]) /
//                    (wuhan_water.banddata_1[i][j] + wuhan_water.banddata_2[i][j]);
//            MNDWI_2005[i][j] = (wuhan_water.banddata_3[i][j] - wuhan_water.banddata_4[i][j]) /
//                    (wuhan_water.banddata_3[i][j] + wuhan_water.banddata_4[i][j]);
//        }
//    }
//}
//
//void Process::DrawImage(double **imagedata, const QString outputname)
//{
//    //1 创建绘图设备
//    QImage image(this->imgWidth, this->imgHeight, QImage::Format_ARGB32);
//
//    //对图像进行平滑处理
//    double filtering[9];//定义滤波区域
//
//    //QImage可以修改图片
//    for (int i = 0; i < this->imgHeight; i++)
//    {
//        for (int j = 0; j < this->imgWidth; j++)
//        {
//            //设置像素
//            if (imagedata[i][j] > 0)
//            {
//                image.setPixel(QPoint(j, i), qRgb(255, 255, 255));
//            } else
//            {
//                image.setPixel(QPoint(j, i), qRgb(0, 0, 0));
//            }
//
//
//        }
//    }
//
//    //4 保存图片
//    image.save("../Output_Image/" + outputname + ".png");
//
//    cout<<"成功保存图像: "<<outputname.toStdString()<< ".png" << endl;
//}
//
//bool cmp(QColor a,QColor b)
//{
//    return (a.red()+a.blue()+a.green())>(b.red()+b.blue()+b.green());
//}
//
//void Process::SmoothImage(const QString outputname)
//{
//    QImage origin("../Output_Image/" + outputname + ".png");
//    QImage newImage(origin.width(), origin.height(), QImage::Format_ARGB32);
//
//    QColor oldColor;
//
//    //对图像进行平滑处理
//    QColor filtering[9];//定义滤波区域
//
//    int averange;
//
//    for(int i = 0; i<origin.width(); i++)
//    {
//        for(int j = 0; j<origin.height(); j++)
//        {
//            //开始中值滤波处理
//            if(i>0&&j>0&&i<origin.width()-1&&j<origin.height()-1)
//            {
//                //滤波矩阵赋值
//                filtering[0]=origin.pixel(i-1,j-1);
//                filtering[1]=origin.pixel(i-1,j);
//                filtering[2]=origin.pixel(i-1,j+1);
//                filtering[3]=origin.pixel(i,j-1);
//                filtering[4]=origin.pixel(i,j);
//                filtering[5]=origin.pixel(i,j+1);
//                filtering[6]=origin.pixel(i+1,j-1);
//                filtering[7]=origin.pixel(i+1,j);
//                filtering[8]=origin.pixel(i+1,j+1);
//
//                //给滤波矩阵排序
//                sort(filtering,filtering+8,cmp);
//
//                //中值滤波完成
//                int average = (filtering[4].red()+filtering[4].green()+filtering[4].blue())/3;
//                newImage.setPixel(i,j,qRgb(average,average,average));
//            }
//            else
//            {
//                oldColor = QColor(origin.pixel(i,j));
//                int average = (oldColor.red()+oldColor.green()+oldColor.blue())/3;
//                newImage.setPixel(i,j,qRgb(average,average,average));
//            }
//        }
//    }
//
//    //4 保存图片
//    newImage.save("../Output_Image/" + outputname + "_smoothed.png");
//}