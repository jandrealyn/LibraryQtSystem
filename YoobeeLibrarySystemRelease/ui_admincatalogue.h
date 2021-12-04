/********************************************************************************
** Form generated from reading UI file 'admincatalogue.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINCATALOGUE_H
#define UI_ADMINCATALOGUE_H

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

class Ui_admincatalogue
{
public:
    QFrame *gridFrame_2;
    QLabel *label;
    QPushButton *back;
    QLabel *img;
    QTableWidget *adminCatalogue;
    QPushButton *addbook;

    void setupUi(QDialog *admincatalogue)
    {
        if (admincatalogue->objectName().isEmpty())
            admincatalogue->setObjectName(QString::fromUtf8("admincatalogue"));
        admincatalogue->resize(803, 562);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        admincatalogue->setWindowIcon(icon);
        gridFrame_2 = new QFrame(admincatalogue);
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
        label->setGeometry(QRect(270, 20, 251, 71));
        label->setStyleSheet(QString::fromUtf8("\n"
"\n"
"font: 28px;\n"
"\n"
""));
        back = new QPushButton(gridFrame_2);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(660, 30, 111, 41));
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
        img->setGeometry(QRect(20, 10, 181, 101));
        adminCatalogue = new QTableWidget(gridFrame_2);
        adminCatalogue->setObjectName(QString::fromUtf8("adminCatalogue"));
        adminCatalogue->setGeometry(QRect(70, 110, 651, 371));
        adminCatalogue->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        addbook = new QPushButton(gridFrame_2);
        addbook->setObjectName(QString::fromUtf8("addbook"));
        addbook->setGeometry(QRect(320, 490, 141, 51));

        retranslateUi(admincatalogue);

        QMetaObject::connectSlotsByName(admincatalogue);
    } // setupUi

    void retranslateUi(QDialog *admincatalogue)
    {
        admincatalogue->setWindowTitle(QCoreApplication::translate("admincatalogue", "Yoobee Library System | Admin | Catalogue", nullptr));
        label->setText(QCoreApplication::translate("admincatalogue", "Admin Catalogue", nullptr));
        back->setText(QCoreApplication::translate("admincatalogue", "Back", nullptr));
        img->setText(QCoreApplication::translate("admincatalogue", "Yoobee Image", nullptr));
        addbook->setText(QCoreApplication::translate("admincatalogue", "Add a book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admincatalogue: public Ui_admincatalogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINCATALOGUE_H
