/********************************************************************************
** Form generated from reading UI file 'adminoverdue.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINOVERDUE_H
#define UI_ADMINOVERDUE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_adminoverdue
{
public:
    QFrame *gridFrame_2;
    QLabel *label;
    QPushButton *back;
    QLabel *img;
    QTableWidget *adminOverdue;

    void setupUi(QDialog *adminoverdue)
    {
        if (adminoverdue->objectName().isEmpty())
            adminoverdue->setObjectName(QString::fromUtf8("adminoverdue"));
        adminoverdue->resize(802, 559);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        adminoverdue->setWindowIcon(icon);
        gridFrame_2 = new QFrame(adminoverdue);
        gridFrame_2->setObjectName(QString::fromUtf8("gridFrame_2"));
        gridFrame_2->setGeometry(QRect(0, 0, 801, 561));
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
"background-color: rgb(77, 77, 77);;\n"
"border-style: inset;\n"
"}\n"
""));
        label = new QLabel(gridFrame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 40, 301, 71));
        label->setStyleSheet(QString::fromUtf8("\n"
"\n"
"font: 40px;\n"
"\n"
""));
        back = new QPushButton(gridFrame_2);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(650, 30, 111, 41));
        back->setStyleSheet(QString::fromUtf8("*{\n"
"font-family: Century Gothic, sans-serif;\n"
"font-size: 15px;\n"
"}\n"
"\n"
"QPushButton{\n"
"color: white;\n"
"padding: 10px;\n"
"background: #27a9e3;\n"
"border-style: outset;\n"
"border-radius: 10px;\n"
"font: bold;\n"
"}\n"
"QPushButton::pressed{\n"
"background-color: rgb(216, 150, 90);\n"
"border-style: inset;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: #59c7f7;\n"
"}\n"
""));
        img = new QLabel(gridFrame_2);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(20, 10, 181, 91));
        adminOverdue = new QTableWidget(gridFrame_2);
        adminOverdue->setObjectName(QString::fromUtf8("adminOverdue"));
        adminOverdue->setGeometry(QRect(70, 130, 651, 381));

        retranslateUi(adminoverdue);

        QMetaObject::connectSlotsByName(adminoverdue);
    } // setupUi

    void retranslateUi(QDialog *adminoverdue)
    {
        adminoverdue->setWindowTitle(QCoreApplication::translate("adminoverdue", "Yoobee Library System | Admin | Overdue Books", nullptr));
        label->setText(QCoreApplication::translate("adminoverdue", "Overdue Books", nullptr));
        back->setText(QCoreApplication::translate("adminoverdue", "Back", nullptr));
        img->setText(QCoreApplication::translate("adminoverdue", "Yoobee Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminoverdue: public Ui_adminoverdue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINOVERDUE_H
