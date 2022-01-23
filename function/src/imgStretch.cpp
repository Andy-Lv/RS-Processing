//
// Created by andy on 2021/9/7.
//

#include "ui_imgStrech.h"
#include "function/include/imgStretch.h"

ImgStretch::ImgStretch(QWidget *parent)
        : QDialog(parent), ui_imgStretch(new Ui::Dialog_imgStretch)
{
    ui_imgStretch->setupUi(this);

    connect(ui_imgStretch->pushButton_openInputFolder, &QPushButton::released, this,
            [=]()
            {
                this->InputImagePath = QFileDialog::getOpenFileName(this, "pushButton_openInputFolder");
                ui_imgStretch->lineEdit_inputPath->setText(this->InputImagePath);

                Init();

//                //设置范围值
//                this->minimum = theImage.GetMinimumValue()[bandNum] + 1;
//                this->maximum = theImage.GetMaximumValue()[bandNum] - 1;

                //设置被拉伸像素值选择范围  初始值
                ui_imgStretch->spinBox_preMinGrayscale->setMinimum(theImage.GetMinimumValue()[bandNum]);
                ui_imgStretch->spinBox_preMaxGrayscale->setMaximum(theImage.GetMaximumValue()[bandNum]);

                ui_imgStretch->spinBox_preMinGrayscale->setValue(theImage.GetMinimumValue()[bandNum]);
                ui_imgStretch->spinBox_preMaxGrayscale->setValue(theImage.GetMaximumValue()[bandNum]);

            });

    connect(ui_imgStretch->pushButton_openOutputFolder, &QPushButton::released, this,
            [=]()
            {
                ui_imgStretch->lineEdit_outputPath->setText(
                        QFileDialog::getExistingDirectory(this, "pushButton_openOutputFolder"));
            });

    connect(ui_imgStretch->pushButton_ok, &QPushButton::released, this,
            [=]()
            {
                if (this->InputImagePath == "")
                {
                    QMessageBox::warning(this, tr("警告"), tr("输入图像的地址不能为空"));
                    return;
                }

                if (this->OutputImagePath == "")
                {
                    QMessageBox::warning(this, tr("警告"), tr("输出图像的地址不能为空"));
                    return;
                }

                if (this->OutputImageName == "")
                {
                    QMessageBox::warning(this, tr("警告"), tr("输出图像的地址不能为空"));
                    return;
                }

                if (ui_imgStretch->radioButton_png->isChecked())
                {
                    ImageStretching_png();
                }
                if (ui_imgStretch->radioButton_tif->isChecked())
                {
                    ImageStretching_tif();
                }
            });

    connect(ui_imgStretch->pushButton_cancel, &QPushButton::released, this, &QDialog::close);

    //上一个波段按钮
    connect(ui_imgStretch->pushButton_next, &QPushButton::released, this,
            [=]()
            {
                this->bandNum++;
                this->Init();
            });
    //下一个波段按钮
    connect(ui_imgStretch->pushButton_previous, &QPushButton::released, this,
            [=]()
            {
                this->bandNum--;
                this->Init();
            });

    connect(ui_imgStretch->spinBox_preMinGrayscale, &QSpinBox::textChanged, this,
            [=]()
            {
                //最大灰度的最小值与最小灰度的最大值的关系
                ui_imgStretch->spinBox_preMaxGrayscale->setMinimum(ui_imgStretch->spinBox_preMinGrayscale->value());
                ui_imgStretch->spinBox_preMinGrayscale->setMaximum(ui_imgStretch->spinBox_preMaxGrayscale->value());
                //设置范围值
                this->minimum = ui_imgStretch->spinBox_preMinGrayscale->value();
                this->maximum = ui_imgStretch->spinBox_preMaxGrayscale->value();
                this->Init();
            });

    connect(ui_imgStretch->spinBox_preMaxGrayscale, &QSpinBox::textChanged, this,
            [=]()
            {
                //最大灰度的最小值与最小灰度的最大值的关系
                ui_imgStretch->spinBox_preMaxGrayscale->setMinimum(ui_imgStretch->spinBox_preMinGrayscale->value());
                ui_imgStretch->spinBox_preMinGrayscale->setMaximum(ui_imgStretch->spinBox_preMaxGrayscale->value());
                //设置范围值
                this->minimum = ui_imgStretch->spinBox_preMinGrayscale->value();
                this->maximum = ui_imgStretch->spinBox_preMaxGrayscale->value();
                this->Init();
            });
}

void ImgStretch::Init()
{
    this->bandNum_all = theImage.GetBandNum();
    //设置波段切换按钮
    ui_imgStretch->pushButton_previous->setEnabled(true);
    ui_imgStretch->pushButton_next->setEnabled(true);
    if (bandNum == 1)
    {
        ui_imgStretch->pushButton_previous->setDisabled(true);
    }
    if (bandNum == this->bandNum_all)
    {
        ui_imgStretch->pushButton_next->setDisabled(true);
    }


    this->InputImagePath = ui_imgStretch->lineEdit_inputPath->text();

    theImage.ReadImage(InputImagePath.toStdString().c_str());

    //设置顶端显示
    ui_imgStretch->label_bandNum->setText(QString::number(bandNum));
    ui_imgStretch->label_bandNum_all->setText(QString::number(theImage.GetBandNum()));

    //显示直方图
    this->ui_imgStretch->widget_histogram->DrawHistogram(theImage.GetHistogramArray()[bandNum],
                                                         theImage.GetMaximumValue()[bandNum],
                                                         minimum, maximum);
}

void ImgStretch::ImageStretching_png()
{

}

void ImgStretch::ImageStretching_tif()
{

}
//{
//    //TODO 确定输入图像是多少位的，是否需要拉伸到不同的位，但感觉没什么意义
//    GDALAllRegister();
//
//    //原始图像
//    GDALDataset *InputImage = (GDALDataset *) GDALOpen(InputImagePath.toStdString().c_str(), GA_ReadOnly);
//
//    //图像驱动
//    GDALDriver *poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");
//
//    QString path = OutputImagePath + "/" + OutputImageName + "tif";
//    //创建8bit的数据
//    GDALDataset *OutputImage = poDriver->Create(path.toStdString().c_str(), imgWidth, imgHeight, bandNum,
//                                                GDT_Byte,
//                                                NULL);
//    double dGeoTrans[6] = {0};
//
//    //设置仿射变换参数
//    InputImage->GetGeoTransform(dGeoTrans);
//    OutputImage->SetGeoTransform(dGeoTrans);
//    //设置图像投影信息
//    OutputImage->SetProjection(InputImage->GetProjectionRef());
//
//    //用于保存读取的16bit数据
//    GUInt16 *InputData = new GUInt16[imgHeight * imgWidth];
//    //用于输出的8bit数据
//    GByte *OutputData = new GByte[imgHeight * imgWidth];
//
//    double minimumValue, maximumValue, meanValue, sigmaValue;
//
//    //定义直方图段数和数组
//    int histogramBuckets = 1024;
//    unsigned long long *histogramArray = new unsigned long long[histogramBuckets];
//
//    //循环波段
//    for (int iBand = 1; iBand <= bandNum; iBand++)
//    {
//        GDALRasterBand *InputBand = InputImage->GetRasterBand(iBand);
//        GDALRasterBand *OutputBand = OutputImage->GetRasterBand(iBand);
//
//        //获取该波段的最大值 最小值 平均值 和标准差
//        InputBand->GetStatistics(true, true, &minimumValue, &maximumValue, &meanValue, &sigmaValue);
//
//        //获取该波段灰度直方图
//        InputBand->GetHistogram(
//                minimumValue - std::numeric_limits<double>::epsilon(),
//                maximumValue + std::numeric_limits<double>::epsilon(),
//                histogramBuckets,
//                histogramArray,
//                false,
//                false,
//                GDALDummyProgress,
//                nullptr);
//
//        //定义线性拉伸界限
//        double minPercent = 0;
//        double maxPercent = 1;
//
//        unsigned long long p1 = 0;
//        unsigned long long p2 = histogramBuckets - 1;
//
//        while (minPercent < 0.02)
//        {
//            minPercent += (double) histogramArray[p1++] /
//                          double(imgWidth * imgHeight);
//        }
//        while (maxPercent > 0.98)
//        {
//            maxPercent -= (double) histogramArray[p2--] /
//                          double(imgWidth * imgHeight);
//        }
//
//        //确定线性拉伸范围灰度值界限
//        double gap = maximumValue - minimumValue;
//        double pixgap = gap / (double) histogramBuckets;
//        double minpix = p1 * pixgap + minimumValue;
//        double maxpix = p2 * pixgap + minimumValue;
//        double stretched_gap = maxpix - minpix;
//
//
//
//
//
//        //将数据读出来
//        InputBand->RasterIO(GF_Read, 0, 0, imgWidth, imgHeight, InputData, imgWidth, imgHeight, GDT_UInt16, 0, 0);
//
//        for (int i = 0; i < imgHeight; i++)    //循环图像高
//        {
//            //循环，将16bit数据专为8bit数据，使用线性拉伸方式
//            for (int j = 0; j < imgWidth; j++)
//            {
//                if (InputData[i * imgWidth + j] < minpix)
//                    OutputData[i * imgWidth + j] = 0;
//                else if (InputData[i * imgWidth + j] >= minpix && InputData[i * imgWidth + j] < maxpix)
//                {
//                    double temp = ((double) InputData[i * imgWidth + j] - minpix) / stretched_gap * 255;
//                    OutputData[i * imgWidth + j] = (GByte) temp;
//                    //cout<<OutputData[i * imgWidth + j]<<endl;
//                }
//                if (InputData[i * imgWidth + j] > maxpix)
//                    OutputData[i * imgWidth + j] = 255;
//            }
//        }
//        OutputBand->RasterIO(GF_Write, 0, 0, imgWidth, imgHeight, OutputData, imgWidth, imgHeight, GDT_Byte, 0, 0);
//    }
//
//    delete[] InputData;
//    delete[] OutputData;
//    //关闭原始图像和结果图像
//    GDALClose((GDALDatasetH) OutputImage);
//    GDALClose((GDALDatasetH) InputImage);
//}

Histogram::Histogram(QWidget *parent)
{

}

Histogram::~Histogram()
{

}

void Histogram::DrawHistogram(unsigned long long *histogramArray, double maximumValue, int min, int max)
{
    QCustomPlot *plot = new QCustomPlot(this);
    plot->resize(this->width(), this->height());

    double yrange = 0;
    QVector<double> datax;//储存横坐标
    QVector<double> datay;//储存纵坐标

    QVector<double> rangex;//储存范围横坐标
    QVector<double> rangey;//储存范围纵坐标
    plot->clearGraphs();
    //datay.resize(10);
    for (int i = 0; i < maximumValue; i++)
    {
        datax.append(i + 1);
        datay.append(histogramArray[i]);
    }

    QVector<double>::iterator it;
    for (it = datay.begin(); it != datay.end(); it++)
    {
        if (*it > yrange)
            yrange = *it;
    }

    plot->xAxis->setRange(0, maximumValue);  //x轴范围
    plot->yAxis->setRange(0, (int) yrange);  //y轴范围
    QCPBars *bars = new QCPBars(plot->xAxis, plot->yAxis);
    bars->setData(datax, datay);
    bars->setPen(QColor(0, 0, 0));
    bars->setWidth(0.05);
    plot->setVisible(true);
    plot->replot();

    //绘制范围
    rangex << min << max;
    rangey << (int) yrange << (int) yrange;
    QCPBars *rangebars = new QCPBars(plot->xAxis, plot->yAxis);
    rangebars->setData(rangex, rangey);
    rangebars->setPen(QColor(255, 0, 0));
    rangebars->setWidth(0.1);
    plot->setVisible(true);
    plot->replot();
}