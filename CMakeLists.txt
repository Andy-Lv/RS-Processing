#设置cmake版本号
cmake_minimum_required(VERSION 3.4.0)

#设置工程名称
project(RS_Processing)

#查找需要的Qt库文件，最好每一个库都要写，Qt也会根据依赖关系自动添加
#find_package(Qt5Widgets)
#find_package(Qt5Core)
#find_package(Qt5Gui)

# Qt
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5Svg REQUIRED)

# Eigen
find_package(Eigen3 REQUIRED)

# GDAL
find_package(GDAL REQUIRED)
if (NOT GDAL_FOUND)
    message(FATAL_ERROR "GDAL not found, cannot proceed")
endif ()
if (NOT GDAL_CONFIG)
    message(FATAL_ERROR "gdal-config command not found (not in PATH?), cannot proceed")
endif ()

execute_process(
        COMMAND ${GDAL_CONFIG} --version
        OUTPUT_VARIABLE SYSTEM_GDAL_VERSION
)

if (SYSTEM_GDAL_VERSION VERSION_LESS "2.2")
    message(FATAL_ERROR "GDAL version \"${SYSTEM_GDAL_VERSION}\" is too old, at least 2.2 is required")
endif ()

# 自动调用moc，uic，rcc处理qt的扩展部分
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

qt5_wrap_cpp(MOC_SRCS
        include/login.h
        include/mainwindow.h
        include/treemenu.h
        include/information.h
        )

qt5_wrap_ui(UI_HEADERS
        ui/login.ui
        ui/mainwindow.ui)

add_custom_target(ui ALL DEPENDS ${UI_HEADERS})
add_custom_target(h ALL DEPENDS ${MOC_SRCS})

set(HEAD_FILES
        include/processing/bandCombination.h
        )

set(SRC_FILES
        src/login.cpp
        src/mainwindow.cpp
        src/treemenu.cpp
        src/information.cpp
        src/processing/bandCombination.cpp)

# ui
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

#设置工程包含当前目录，非必须
set(CMAKE_INCLUDE_CURRENT_DIR ON)


#创建工程文件
add_executable(${PROJECT_NAME}
        ${SRC_FILES}
        ${HEAD_FILES}
        ${RCC_FILES}
        ${WRAP_FILES}
        ${MOC_SRCS}
        main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        {CMAKE_SOURCE_DIR}/src
        {CMAKE_SOURCE_DIR}/include)

#添加Qt5 GDAL Eigen3依赖项
target_link_libraries(${PROJECT_NAME}
        Qt5::Widgets
        Qt5::Core
        Qt5::Gui
        Qt5::Network
        ${GDAL_LIBRARY}
        Eigen3::Eigen)