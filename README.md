# RS-Processing

各种格式遥感图像处理

### 项目开发日志

#### **8月19日**

完成在QT Designer中登陆窗体布局设计工作,并实现点击登陆按钮跳转到主窗体

#### **8月20日**

完成在QT Designer中主窗体布局设计工作

#### **8月21日**

参照<a href="https://blog.csdn.net/qq_37386287/article/details/107885260" target="_blank">博客</a>
,创建treemenu类,完成继承自treewidget的treemenu类主体与内部函数的实现,包括新建文件夹和新建文件类

#### **8月22日**

实现将treemenu类集成到mainwindow中的treewidget中,但文件路径需要后续添加改进.

#### **8月23日**

创建image,实现对Tiff格式图像每个波段的读取.储存到map容器中

#### **8月24日**

常见process类,添加功能:波段组合,图像拉伸,图像相对纠正

#### **8月25日**

添加图像获取NDWI,MNDWI函数,优化目录树构建逻辑

#### **8月26日**

1: 解决目录树中点击父节点创建文件夹或文件并不能真正创建文件或文件夹,只是在目录树中虚假的显示出来的问题  
2: 实现点击page_edit的open按钮打开文件管理器选择文件夹并将此文件夹显示在目录树中  
3: 实现点击page_edit的new按钮打开对话框选择新建项目地址和项目名称  
4: debug:点击新建之后此框不能自己关闭                     
5: debug:新建完毕之后再次点击新建按钮,目录树才会展示

#### **8月27日**

参照<a href="https://blog.csdn.net/liyuanbhu/article/details/46687495">博客</a>
的内容.对显示图片的主窗体进行构建,添加picturebox类,实现图像的显示一些列功能.  
成功完成在主窗体显示图像的demo,显示了一幅图像,后期会将图像各种处理方法融合

#### **8月28日**

完成点击目录树上的图片文件(png),主窗体显示该图像  
添加波段组合弹窗,晚上主窗口控件

#### **8月29日**
对波段组合弹窗进行优化，链接处理函数

#### **8月30日**
对波段组合功能进行debug

#### **8月31日**
折腾电脑，manjaro和windows双系统

#### **9月1日**
发现bug,波段组合后图像为灰白的，经过排查，问题出现在读取个波段的像素上。导致每个波段所存的数据是一样的。

#### **9月2日**
debug:发现在利用一个二维数组的指针作为map的value时，作为临时储存像素的二维数组。
在循环插入map中时，需要每次都重新申请空间，要不然最后的map的value都是指向一个地方的地址，而这个地址所对应的值为最后一次赋的值。

#### **9月5日**
优化波段组合功能

#### **9月6日**
完成图像拉伸ui

#### **9月7日**
优化图像拉伸ui,搭建图像拉伸功能框架  
添加png和tif两种保存格式，以及tif是否需要将深度改变，但感觉没什么意义。  
TODO：  
1、在Init函数中添加显示第一波段直方图的代码  
2、点击切换按键显示对应波段灰度直方图  
3、完善tif保存函数，使其支持不同深度的图像的线性拉伸  
4、完成png保存函数  
5、将水平滑动条优化为两个滑块，滑块运动，就对应直方图上有两个指示的条，然后就将滑块范围内的灰度线性拉伸

#### **12月29日**
修复图像拉伸窗口波段总数显示为整个像素点数的bug

#### **1月17日**
决定使用QCustomPLot库来进行直方图的绘制，Manjaro系统中使用该库，yay -D qcustomplot  
再在cmakelists中加入target_link_libraries qcustomplot即可使用
实现图片直方图的显示，下一步为添加入本项目

#### **1月21日**
图片直方图显示完成

#### **1月23日**
完成直方图显示后拉伸范围的显示以及数值的显示