/********************************************************************************
** Form generated from reading UI file 'adminreturn.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINRETURN_H
#define UI_ADMINRETURN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_adminreturn
{
public:
    QFrame *gridFrame_2;
    QLabel *label_2;
    QLabel *label;
    QPushButton *noreturn;
    QLabel *label_3;
    QPushButton *yesreturn;
    QLineEdit *return_name;
    QLineEdit *return_member;
    QLabel *img;

    void setupUi(QDialog *adminreturn)
    {
        if (adminreturn->objectName().isEmpty())
            adminreturn->setObjectName(QString::fromUtf8("adminreturn"));
        adminreturn->resize(550, 381);
        gridFrame_2 = new QFrame(adminreturn);
        gridFrame_2->setObjectName(QString::fromUtf8("gridFrame_2"));
        gridFrame_2->setGeometry(QRect(0, 0, 551, 411));
        gridFrame_2->setStyleSheet(QString::fromUtf8("*{\n"
"background: rgb(255, 255, 255);\n"
"fontsize: 15px;\n"
"font-family: Century Gothic, sans-serif;\n"
"}\n"
"\n"
"QFrame{\n"
"border: solid 10px rgba(0, 0, 0);\n"
"}\n"
"\n"
"QLineEdit{\n"
"color: #8d98a1;\n"
"background-color: #d3d3d3;\n"
"font-size: 18px;\n"
"border-style: outset;\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton{\n"
"background: #ced1d8;\n"
"border-style: outset;\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgb(77, 77, 77);\n"
"border-style: inset;\n"
"}\n"
""));
        label_2 = new QLabel(gridFrame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 120, 41, 31));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        label = new QLabel(gridFrame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 30, 201, 51));
        label->setStyleSheet(QString::fromUtf8("font-size: 34px"));
        noreturn = new QPushButton(gridFrame_2);
        noreturn->setObjectName(QString::fromUtf8("noreturn"));
        noreturn->setGeometry(QRect(300, 280, 131, 61));
        label_3 = new QLabel(gridFrame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 180, 171, 51));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        yesreturn = new QPushButton(gridFrame_2);
        yesreturn->setObjectName(QString::fromUtf8("yesreturn"));
        yesreturn->setGeometry(QRect(110, 280, 131, 61));
        return_name = new QLineEdit(gridFrame_2);
        return_name->setObjectName(QString::fromUtf8("return_name"));
        return_name->setGeometry(QRect(130, 120, 281, 31));
        return_member = new QLineEdit(gridFrame_2);
        return_member->setObjectName(QString::fromUtf8("return_member"));
        return_member->setGeometry(QRect(130, 190, 281, 31));
        img = new QLabel(gridFrame_2);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(10, 10, 161, 81));

        retranslateUi(adminreturn);

        QMetaObject::connectSlotsByName(adminreturn);
    } // setupUi

    void retranslateUi(QDialog *adminreturn)
    {
        adminreturn->setWindowTitle(QCoreApplication::translate("adminreturn", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("adminreturn", "Title:", nullptr));
        label->setText(QCoreApplication::translate("adminreturn", "Return Book", nullptr));
        noreturn->setText(QCoreApplication::translate("adminreturn", "No", nullptr));
        label_3->setText(QCoreApplication::translate("adminreturn", "Member:", nullptr));
        yesreturn->setText(QCoreApplication::translate("adminreturn", "Yes", nullptr));
        img->setText(QCoreApplication::translate("adminreturn", "yoobee image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminreturn: public Ui_adminreturn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINRETURN_H
