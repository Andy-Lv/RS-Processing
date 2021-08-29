//
// Created by andy on 2021/8/29.
//

#include "ui_bandcombination.h"
#include "function/include/bandcomb.h"

BandComb::BandComb(QWidget *parent)
        : QDialog(parent), ui_bandComb(new Ui::Dialog_bandComb)
{
    ui_bandComb->setupUi(this);

    connect(ui_bandComb->pushButton_openInputFolder,&QPushButton::released,this,
            [=]()
            {
                this->InputImagePath=QFileDialog::getOpenFileName(this, "pushButton_openInputFolder");
                ui_bandComb->lineEdit_inputPath->setText(this->InputImagePath);
                Init();
            });

    connect(ui_bandComb->pushButton_openOutputFolder,&QPushButton::released,this,
            [=]()
            {
                ui_bandComb->lineEdit_outputPath->setText(QFileDialog::getExistingDirectory(this, "pushButton_openOutputFolder"));
            });

//    connect(ui_bandComb->lineEdit_inputPath, &QLineEdit::editingFinished, this, &BandComb::Init);

    connect(ui_bandComb->pushButton_ok, &QPushButton::released, this, &BandComb::BandCombination);

    connect(ui_bandComb->pushButton_ok, &QPushButton::released, this, &QDialog::close);
}


void BandComb::Init()
{
    this->InputImagePath = ui_bandComb->lineEdit_inputPath->text();
    if (this->InputImagePath=="")
    {
        QMessageBox::warning(this, tr("警告"), tr("输入图像的地址不能为空"));
        return;
    }

    Image theImage;

    theImage.ReadImage(InputImagePath.toStdString().c_str());

    this->bandNum = theImage.GetBandNum();
    this->imgWidth = theImage.GetImgWidth();
    this->imgHeight = theImage.GetImgHeight();
    this->depth = theImage.GetDepth();
    this->bandData = theImage.GetImageData();

    //设置顶端显示
    ui_bandComb->label_bandNum->setText(QString(this->bandNum));

    //设置波段选择最大数量
    ui_bandComb->spinBox_R->setMaximum(this->bandNum);
    ui_bandComb->spinBox_G->setMaximum(this->bandNum);
    ui_bandComb->spinBox_B->setMaximum(this->bandNum);
}

//波段组合
void BandComb::BandCombination()
{
    this->OutputImageName = ui_bandComb->lineEdit_outputName->text();
    this->OutputImagePath = ui_bandComb->lineEdit_outputPath->text();

    if(this->OutputImageName==""||this->OutputImagePath=="")
    {
        QMessageBox::warning(this, tr("警告"), tr("输入图像的名称或地址不能为空"));
        return;
    }

    this->band_R=ui_bandComb->spinBox_R->value();
    this->band_G=ui_bandComb->spinBox_G->value();
    this->band_B=ui_bandComb->spinBox_B->value();

    //创建绘图设备
    QImage image(imgWidth, imgHeight, QImage::Format_ARGB32);

    //QImage可以修改图片
    for (int i = 0; i < imgHeight; i++)
    {
        for (int j = 0; j < imgWidth; j++)
        {
            //设置像素
            image.setPixel(QPoint(j, i), qRgb(bandData.find(band_R)->second[i][j],
                                              bandData.find(band_G)->second[i][j],
                                              bandData.find(band_B)->second[i][j]));
        }
    }

    //保存图片
    image.save(this->OutputImagePath + "/" + OutputImageName + ".png");

    this->close();
}

