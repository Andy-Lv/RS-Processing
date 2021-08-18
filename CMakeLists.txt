#设置cmake版本号
cmake_minimum_required(VERSION 3.4.0)

#设置工程名称
project(RS_Processing)

# 自动调用moc，uic，rcc处理qt的扩展部分
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


#设置工程包含当前目录，非必须
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#查找需要的Qt库文件，最好每一个库都要写，Qt也会根据依赖关系自动添加
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)
# find_package(Qt5 COMPONENTS core gui network widgets REQUIRED)

#qt5_wrap_ui(UI_HEADERS login.ui)

#查找当前文件夹中的所有源代码文件，也可以通过Set命令将所有文件设置为一个变量
FILE(GLOB SRC_FILES "./src/*.cpp")
#同理，查找当前文件夹中所有的头文件
FILE(GLOB HEAD_FILES "./include/*.h")
#查找当前文件夹中所有的ui文件
#FILE(GLOB_RECURSE FORM_FILES "./ui/*.ui")

#创建工程文件
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES} ${RCC_FILES} ${WRAP_FILES}  main.cpp)
#添加Qt5依赖项
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui)