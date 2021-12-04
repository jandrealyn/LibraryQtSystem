/********************************************************************************
** Form generated from reading UI file 'adminsystem.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINSYSTEM_H
#define UI_ADMINSYSTEM_H

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

class Ui_adminsystem
{
public:
    QFrame *gridFrame_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *admin_due_btn;
    QPushButton *admin_overdue_btn;
    QLabel *label;
    QPushButton *back;
    QLabel *img;

    void setupUi(QDialog *adminsystem)
    {
        if (adminsystem->objectName().isEmpty())
            adminsystem->setObjectName(QString::fromUtf8("adminsystem"));
        adminsystem->resize(800, 562);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        adminsystem->setWindowIcon(icon);
        gridFrame_2 = new QFrame(adminsystem);
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
        verticalLayoutWidget->setGeometry(QRect(170, 120, 421, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        admin_due_btn = new QPushButton(verticalLayoutWidget);
        admin_due_btn->setObjectName(QString::fromUtf8("admin_due_btn"));
        admin_due_btn->setStyleSheet(QString::fromUtf8("*{\n"
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

        verticalLayout->addWidget(admin_due_btn);

        admin_overdue_btn = new QPushButton(verticalLayoutWidget);
        admin_overdue_btn->setObjectName(QString::fromUtf8("admin_overdue_btn"));
        admin_overdue_btn->setStyleSheet(QString::fromUtf8("*{\n"
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

        verticalLayout->addWidget(admin_overdue_btn);

        label = new QLabel(gridFrame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 30, 391, 71));
        label->setStyleSheet(QString::fromUtf8("\n"
"\n"
"font: 40px;\n"
"\n"
""));
        back = new QPushButton(gridFrame_2);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(640, 40, 111, 41));
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
        img->setGeometry(QRect(10, 10, 181, 91));

        retranslateUi(adminsystem);

        QMetaObject::connectSlotsByName(adminsystem);
    } // setupUi

    void retranslateUi(QDialog *adminsystem)
    {
        adminsystem->setWindowTitle(QCoreApplication::translate("adminsystem", "Yoobee Library System | Admin | System Logs", nullptr));
        admin_due_btn->setText(QCoreApplication::translate("adminsystem", "All Checked Out Books", nullptr));
        admin_overdue_btn->setText(QCoreApplication::translate("adminsystem", "Overdue Books", nullptr));
        label->setText(QCoreApplication::translate("adminsystem", "Checked Out Books", nullptr));
        back->setText(QCoreApplication::translate("adminsystem", "Back", nullptr));
        img->setText(QCoreApplication::translate("adminsystem", "Yoobee Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminsystem: public Ui_adminsystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSYSTEM_H
