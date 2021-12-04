/********************************************************************************
** Form generated from reading UI file 'adminhome.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINHOME_H
#define UI_ADMINHOME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminhome
{
public:
    QFrame *gridFrame_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *admin_catalogue_btn;
    QPushButton *admin_user_btn;
    QPushButton *admin_system_btn;
    QLabel *label;
    QPushButton *logout;
    QLabel *img;

    void setupUi(QDialog *adminhome)
    {
        if (adminhome->objectName().isEmpty())
            adminhome->setObjectName(QString::fromUtf8("adminhome"));
        adminhome->resize(765, 554);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        adminhome->setWindowIcon(icon);
        adminhome->setStyleSheet(QString::fromUtf8(""));
        gridFrame_2 = new QFrame(adminhome);
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
        verticalLayoutWidget = new QWidget(gridFrame_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(180, 160, 371, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        admin_catalogue_btn = new QPushButton(verticalLayoutWidget);
        admin_catalogue_btn->setObjectName(QString::fromUtf8("admin_catalogue_btn"));
        admin_catalogue_btn->setStyleSheet(QString::fromUtf8("*{\n"
"font-family: Century Gothic, sans-serif;\n"
"font-size: 15px;\n"
"}\n"
"\n"
"QPushButton{\n"
"color: white;\n"
"padding: 15px;\n"
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

        verticalLayout->addWidget(admin_catalogue_btn);

        admin_user_btn = new QPushButton(verticalLayoutWidget);
        admin_user_btn->setObjectName(QString::fromUtf8("admin_user_btn"));
        admin_user_btn->setStyleSheet(QString::fromUtf8("*{\n"
"font-family: Century Gothic, sans-serif;\n"
"font-size: 15px;\n"
"}\n"
"\n"
"QPushButton{\n"
"color: white;\n"
"padding: 15px;\n"
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

        verticalLayout->addWidget(admin_user_btn);

        admin_system_btn = new QPushButton(verticalLayoutWidget);
        admin_system_btn->setObjectName(QString::fromUtf8("admin_system_btn"));
        admin_system_btn->setStyleSheet(QString::fromUtf8("*{\n"
"font-family: Century Gothic, sans-serif;\n"
"font-size: 15px;\n"
"}\n"
"\n"
"QPushButton{\n"
"color: white;\n"
"padding: 15px;\n"
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

        verticalLayout->addWidget(admin_system_btn);

        label = new QLabel(gridFrame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 60, 231, 71));
        label->setStyleSheet(QString::fromUtf8("\n"
"\n"
"font: 34px;\n"
"\n"
""));
        logout = new QPushButton(gridFrame_2);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setGeometry(QRect(610, 50, 111, 41));
        logout->setStyleSheet(QString::fromUtf8("*{\n"
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
        img->setGeometry(QRect(20, 20, 191, 101));

        retranslateUi(adminhome);

        QMetaObject::connectSlotsByName(adminhome);
    } // setupUi

    void retranslateUi(QDialog *adminhome)
    {
        adminhome->setWindowTitle(QCoreApplication::translate("adminhome", "Yoobee Library System | Admin | Home", nullptr));
        admin_catalogue_btn->setText(QCoreApplication::translate("adminhome", "View Catalogue", nullptr));
        admin_user_btn->setText(QCoreApplication::translate("adminhome", "View User Information", nullptr));
        admin_system_btn->setText(QCoreApplication::translate("adminhome", "Checked Out Books", nullptr));
        label->setText(QCoreApplication::translate("adminhome", "Administration", nullptr));
        logout->setText(QCoreApplication::translate("adminhome", "Log Out", nullptr));
        img->setText(QCoreApplication::translate("adminhome", "Yoobee Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminhome: public Ui_adminhome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINHOME_H
