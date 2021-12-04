/********************************************************************************
** Form generated from reading UI file 'admindue.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDUE_H
#define UI_ADMINDUE_H

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

class Ui_admindue
{
public:
    QFrame *gridFrame_2;
    QLabel *label;
    QPushButton *back;
    QLabel *img;
    QTableWidget *adminDue;

    void setupUi(QDialog *admindue)
    {
        if (admindue->objectName().isEmpty())
            admindue->setObjectName(QString::fromUtf8("admindue"));
        admindue->resize(800, 560);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        admindue->setWindowIcon(icon);
        gridFrame_2 = new QFrame(admindue);
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
"background-color: rgb(77, 77, 77);\n"
"border-style: inset;\n"
"}\n"
""));
        label = new QLabel(gridFrame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 50, 401, 71));
        label->setStyleSheet(QString::fromUtf8("\n"
"\n"
"font: 40px;\n"
"\n"
""));
        back = new QPushButton(gridFrame_2);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(660, 40, 111, 41));
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
        img->setGeometry(QRect(20, 10, 181, 71));
        adminDue = new QTableWidget(gridFrame_2);
        adminDue->setObjectName(QString::fromUtf8("adminDue"));
        adminDue->setGeometry(QRect(60, 150, 651, 381));
        back->raise();
        img->raise();
        label->raise();
        adminDue->raise();

        retranslateUi(admindue);

        QMetaObject::connectSlotsByName(admindue);
    } // setupUi

    void retranslateUi(QDialog *admindue)
    {
        admindue->setWindowTitle(QCoreApplication::translate("admindue", "Yoobee Library System | Admin | Checked Out Books", nullptr));
        label->setText(QCoreApplication::translate("admindue", "Checked Out Books", nullptr));
        back->setText(QCoreApplication::translate("admindue", "Back", nullptr));
        img->setText(QCoreApplication::translate("admindue", "Yoobee Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admindue: public Ui_admindue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDUE_H
