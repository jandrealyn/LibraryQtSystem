/********************************************************************************
** Form generated from reading UI file 'signupscreen2.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPSCREEN2_H
#define UI_SIGNUPSCREEN2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_signupscreen2
{
public:
    QFrame *gridFrame_2;
    QLabel *img;
    QPushButton *close;
    QLabel *label_4;
    QLabel *user_name;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *user_id;
    QPushButton *done;

    void setupUi(QDialog *signupscreen2)
    {
        if (signupscreen2->objectName().isEmpty())
            signupscreen2->setObjectName(QString::fromUtf8("signupscreen2"));
        signupscreen2->resize(1308, 663);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        signupscreen2->setWindowIcon(icon);
        gridFrame_2 = new QFrame(signupscreen2);
        gridFrame_2->setObjectName(QString::fromUtf8("gridFrame_2"));
        gridFrame_2->setGeometry(QRect(230, 30, 801, 551));
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
"\n"
"QPushButton{\n"
"color: white;\n"
"padding: 5px;\n"
"background: #27a9e3;\n"
"border-style: outset;\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton::pressed{\n"
"background-color: rgb(216, 150, 90);\n"
"border-style: inset;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: #59c7f7;\n"
"}\n"
"\n"
"QPushButton::disabled {\n"
"color: #ebebeb;\n"
"background-color: #1c7ba6;\n"
"}\n"
""));
        img = new QLabel(gridFrame_2);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(50, 20, 341, 121));
        img->setStyleSheet(QString::fromUtf8(""));
        close = new QPushButton(gridFrame_2);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(600, 60, 172, 28));
        close->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(gridFrame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 210, 41, 29));
        user_name = new QLabel(gridFrame_2);
        user_name->setObjectName(QString::fromUtf8("user_name"));
        user_name->setGeometry(QRect(300, 210, 81, 29));
        label_6 = new QLabel(gridFrame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(390, 210, 181, 29));
        label_7 = new QLabel(gridFrame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(300, 280, 51, 29));
        user_id = new QLineEdit(gridFrame_2);
        user_id->setObjectName(QString::fromUtf8("user_id"));
        user_id->setGeometry(QRect(360, 280, 201, 22));
        user_id->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));
        done = new QPushButton(gridFrame_2);
        done->setObjectName(QString::fromUtf8("done"));
        done->setGeometry(QRect(320, 400, 172, 28));
        done->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(signupscreen2);

        QMetaObject::connectSlotsByName(signupscreen2);
    } // setupUi

    void retranslateUi(QDialog *signupscreen2)
    {
        signupscreen2->setWindowTitle(QCoreApplication::translate("signupscreen2", "Yoobee Library System | Sign Up Complete", nullptr));
        img->setText(QCoreApplication::translate("signupscreen2", "Yoobee image", nullptr));
        close->setText(QCoreApplication::translate("signupscreen2", "Close", nullptr));
        label_4->setText(QCoreApplication::translate("signupscreen2", "Great ", nullptr));
        user_name->setText(QCoreApplication::translate("signupscreen2", "(username)", nullptr));
        label_6->setText(QCoreApplication::translate("signupscreen2", "We just Generated Your ID!", nullptr));
        label_7->setText(QCoreApplication::translate("signupscreen2", "Your ID:", nullptr));
        done->setText(QCoreApplication::translate("signupscreen2", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signupscreen2: public Ui_signupscreen2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPSCREEN2_H
