//
// Created by andy on 2021/8/29.
//

#include "ui_bandcombination.h"
#include "function/include/bandcomb.h"

BandComb::BandComb(QWidget *parent)
        : QDialog(parent), ui_bandComb(new Ui::Dialog_bandComb)
{
    ui_bandComb->setupUi(this);

    if (ui_bandComb->lineEdit_inputName->text()!="")
    {
        if (ui_bandComb->lineEdit_inputPath->text()!="")
        {
            InputImagePath=ui_bandComb->lineEdit_inputPath->text();
            InputImageName=ui_bandComb->lineEdit_inputName->text();

            Init(InputImagePath,InputImageName);
        }
    }
}
//void BandComb::soltInit()
//{
//
//}


void BandComb::Init(QString InputImagePath,QString InputImageName)
{
    Image theImage;
    QString path=InputImagePath+"/"+InputImageName;

    theImage.ReadImage(path.toStdString().c_str());
}

//波段组合
void BandComb::BandCombination(const char *InputImagePath,int band_R,int band_G,int band_B)
{
    Image theImage;

    //读取图像所有波段,每个波段的像素数据储存在map容器banddata中
    //TODO 图片路径需要指定
    theImage.ReadImage(InputImagePath);

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
            image.setPixel(QPoint(j, i), qRgb(bandData.find(band_R)->second[i][j],
                                              bandData.find(band_G)->second[i][j],
                                              bandData.find(band_B)->second[i][j]));
        }
    }

//    //保存图片
//    image.save("../Output_Image/" + outputimage + ".png");
//
//    cout << "成功输出波段组合后图像 " << outputimage.toStdString() << ".png" << endl;
}

