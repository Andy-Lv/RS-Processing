# RS-Processing

各种格式遥感图像处理

### 项目开发日志

#### **8月20日**

完成在QT Designer中登陆窗体布局设计工作,并实现点击登陆按钮跳转到主窗体

#### **8月20日**

完成在QT Designer中主窗体布局设计工作

#### **8月21日**

<a href="https://blog.csdn.net/qq_37386287/article/details/107885260" target="_blank">博客</a>
创建treemenu类,完成继承自treewidget的treemenu类主体与内部函数的实现,包括新建文件夹和新建文件类

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
