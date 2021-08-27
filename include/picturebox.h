//
// Created by andy on 2021/8/27.
//

#ifndef RS_PROCESSING_PICTUREBOX_H
#define RS_PROCESSING_PICTUREBOX_H

#include <QWidget>
#include <QImage>
#include <QPixmap>

//FIXED_SIZE 模式下，显示的图像大小等于图像尺寸乘以缩放因子，如果控件的尺寸小于这个大小则多出的部分被裁切掉。
//FIX_SIZE_CENTRED模式与FIXED_SIZE 模式类似，但是，显示的图像居于窗口正中。
//AUTO_ZOOM 模式下，显示的图像大小自动适应控件窗口大小。
//AUTO_SIZE 模式下，这个控件的尺寸等于图像尺寸乘以缩放因子。

class PictureBox : public QWidget
{
Q_OBJECT
public:
    enum PB_MODE
    {
        FIXED_SIZE, FIX_SIZE_CENTRED, AUTO_ZOOM, AUTO_SIZE
    };

    explicit PictureBox(QWidget *parent = 0);

    void setMode(PB_MODE mode);

    ~PictureBox();

private:
    QPixmap m_pixmap;
    double m_scale;
    PB_MODE m_mode;
    QBrush m_brush;
protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:

    bool setImage(QImage &image, double scale = 1.0);

    void setBackground(QBrush brush);
};

#endif //RS_PROCESSING_PICTUREBOX_H
