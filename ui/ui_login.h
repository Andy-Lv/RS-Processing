/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_Pwd;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_login;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        Dialog->setMinimumSize(QSize(400, 300));
        Dialog->setMaximumSize(QSize(400, 300));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 30, 273, 221));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget1 = new QWidget(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_ID = new QLineEdit(widget1);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));

        gridLayout->addWidget(lineEdit_ID, 0, 1, 1, 1);

        lineEdit_Pwd = new QLineEdit(widget1);
        lineEdit_Pwd->setObjectName(QString::fromUtf8("lineEdit_Pwd"));
        lineEdit_Pwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_Pwd, 1, 1, 1, 1);

        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout->addWidget(widget1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_cancel = new QPushButton(widget_2);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_login = new QPushButton(widget_2);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));

        horizontalLayout->addWidget(pushButton_login);


        verticalLayout->addWidget(widget_2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "\347\231\273\351\231\206", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\345\257\206\347\240\201:", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Dialog", "\345\217\226\346\266\210", nullptr));
        pushButton_login->setText(QCoreApplication::translate("Dialog", "\347\231\273\351\231\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_login: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
