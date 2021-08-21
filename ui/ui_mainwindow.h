/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "include/treemenu.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_file;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_edit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_9;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_10;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_11;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_12;
    QSpacerItem *horizontalSpacer_12;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_13;
    QSpacerItem *horizontalSpacer_31;
    QPushButton *pushButton_32;
    QSpacerItem *horizontalSpacer_32;
    QPushButton *pushButton_33;
    QSpacerItem *horizontalSpacer_33;
    QPushButton *pushButton_34;
    QSpacerItem *horizontalSpacer_30;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QWidget *widget;
    QTableView *tableView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1212, 779);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(0, 70));
        tabWidget->setAcceptDrops(false);
        tabWidget->setAutoFillBackground(false);
        tab_file = new QWidget();
        tab_file->setObjectName(QString::fromUtf8("tab_file"));
        gridLayout = new QGridLayout(tab_file);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(tab_file);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(35, 35));
        pushButton_3->setMaximumSize(QSize(35, 35));

        gridLayout->addWidget(pushButton_3, 0, 5, 1, 1);

        pushButton = new QPushButton(tab_file);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(35, 35));
        pushButton->setMaximumSize(QSize(35, 35));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 4, 1, 1);

        pushButton_4 = new QPushButton(tab_file);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(35, 35));
        pushButton_4->setMaximumSize(QSize(35, 35));

        gridLayout->addWidget(pushButton_4, 0, 7, 1, 1);

        pushButton_2 = new QPushButton(tab_file);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(35, 35));
        pushButton_2->setMaximumSize(QSize(35, 35));

        gridLayout->addWidget(pushButton_2, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 8, 1, 1);

        tabWidget->addTab(tab_file, QString());
        tab_edit = new QWidget();
        tab_edit->setObjectName(QString::fromUtf8("tab_edit"));
        horizontalLayout_2 = new QHBoxLayout(tab_edit);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_9 = new QPushButton(tab_edit);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(35, 35));
        pushButton_9->setMaximumSize(QSize(35, 35));

        horizontalLayout_2->addWidget(pushButton_9);

        horizontalSpacer_11 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_11);

        pushButton_10 = new QPushButton(tab_edit);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(35, 35));
        pushButton_10->setMaximumSize(QSize(35, 35));

        horizontalLayout_2->addWidget(pushButton_10);

        horizontalSpacer_13 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        pushButton_11 = new QPushButton(tab_edit);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(35, 35));
        pushButton_11->setMaximumSize(QSize(35, 35));

        horizontalLayout_2->addWidget(pushButton_11);

        horizontalSpacer_14 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_14);

        pushButton_12 = new QPushButton(tab_edit);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(35, 35));
        pushButton_12->setMaximumSize(QSize(35, 35));

        horizontalLayout_2->addWidget(pushButton_12);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);

        tabWidget->addTab(tab_edit, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_5 = new QHBoxLayout(tab);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_13 = new QPushButton(tab);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(35, 35));
        pushButton_13->setMaximumSize(QSize(35, 35));

        horizontalLayout_5->addWidget(pushButton_13);

        horizontalSpacer_31 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_31);

        pushButton_32 = new QPushButton(tab);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
        pushButton_32->setMinimumSize(QSize(35, 35));
        pushButton_32->setMaximumSize(QSize(35, 35));

        horizontalLayout_5->addWidget(pushButton_32);

        horizontalSpacer_32 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_32);

        pushButton_33 = new QPushButton(tab);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));
        pushButton_33->setMinimumSize(QSize(35, 35));
        pushButton_33->setMaximumSize(QSize(35, 35));

        horizontalLayout_5->addWidget(pushButton_33);

        horizontalSpacer_33 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_33);

        pushButton_34 = new QPushButton(tab);
        pushButton_34->setObjectName(QString::fromUtf8("pushButton_34"));
        pushButton_34->setMinimumSize(QSize(35, 35));
        pushButton_34->setMaximumSize(QSize(35, 35));

        horizontalLayout_5->addWidget(pushButton_34);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_30);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeWidget = new QTreeWidget(centralwidget);
        //treeWidget=new TreeMenu();
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy1);
        treeWidget->setMinimumSize(QSize(250, 0));
        treeWidget->setMaximumSize(QSize(250, 16777215));

        horizontalLayout->addWidget(treeWidget);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setAcceptDrops(true);

        horizontalLayout->addWidget(widget);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMaximumSize(QSize(250, 16777215));

        horizontalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_file), QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_edit), QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_32->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_33->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_34->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\345\212\237\350\203\275", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
