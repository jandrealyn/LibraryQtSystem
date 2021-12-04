/********************************************************************************
** Form generated from reading UI file 'adminedituser.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINEDITUSER_H
#define UI_ADMINEDITUSER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_adminedituser
{
public:
    QFrame *gridFrame_2;
    QPushButton *back;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label;
    QPushButton *canceledit;
    QLabel *label_3;
    QPushButton *confimedit;
    QLabel *label_5;
    QLineEdit *admin_first_user;
    QLabel *img;
    QPushButton *deleteuser;
    QLineEdit *admin_last_user;
    QLineEdit *admin_email_user;
    QLineEdit *admin_phone_user;

    void setupUi(QDialog *adminedituser)
    {
        if (adminedituser->objectName().isEmpty())
            adminedituser->setObjectName(QString::fromUtf8("adminedituser"));
        adminedituser->resize(549, 440);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        adminedituser->setWindowIcon(icon);
        gridFrame_2 = new QFrame(adminedituser);
        gridFrame_2->setObjectName(QString::fromUtf8("gridFrame_2"));
        gridFrame_2->setGeometry(QRect(0, 0, 551, 441));
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
        back = new QPushButton(gridFrame_2);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(640, 40, 111, 41));
        back->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"border-width: 1px;\n"
"\n"
"border-color: black;\n"
"\n"
"border-radius: 10px;\n"
"\n"
"border-style: outset;\n"
"\n"
"font: 14px;\n"
"\n"
"padding:2px;"));
        label_2 = new QLabel(gridFrame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 120, 111, 31));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        label_4 = new QLabel(gridFrame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 220, 61, 31));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        label = new QLabel(gridFrame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 30, 151, 51));
        label->setStyleSheet(QString::fromUtf8("font-size: 34px"));
        canceledit = new QPushButton(gridFrame_2);
        canceledit->setObjectName(QString::fromUtf8("canceledit"));
        canceledit->setGeometry(QRect(380, 360, 121, 51));
        label_3 = new QLabel(gridFrame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 170, 131, 31));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        confimedit = new QPushButton(gridFrame_2);
        confimedit->setObjectName(QString::fromUtf8("confimedit"));
        confimedit->setGeometry(QRect(210, 360, 121, 51));
        label_5 = new QLabel(gridFrame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 270, 101, 31));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        admin_first_user = new QLineEdit(gridFrame_2);
        admin_first_user->setObjectName(QString::fromUtf8("admin_first_user"));
        admin_first_user->setGeometry(QRect(130, 120, 281, 31));
        img = new QLabel(gridFrame_2);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(10, 10, 161, 71));
        deleteuser = new QPushButton(gridFrame_2);
        deleteuser->setObjectName(QString::fromUtf8("deleteuser"));
        deleteuser->setGeometry(QRect(40, 360, 121, 51));
        admin_last_user = new QLineEdit(gridFrame_2);
        admin_last_user->setObjectName(QString::fromUtf8("admin_last_user"));
        admin_last_user->setGeometry(QRect(130, 170, 281, 31));
        admin_email_user = new QLineEdit(gridFrame_2);
        admin_email_user->setObjectName(QString::fromUtf8("admin_email_user"));
        admin_email_user->setGeometry(QRect(130, 220, 281, 31));
        admin_phone_user = new QLineEdit(gridFrame_2);
        admin_phone_user->setObjectName(QString::fromUtf8("admin_phone_user"));
        admin_phone_user->setGeometry(QRect(130, 270, 281, 31));

        retranslateUi(adminedituser);

        QMetaObject::connectSlotsByName(adminedituser);
    } // setupUi

    void retranslateUi(QDialog *adminedituser)
    {
        adminedituser->setWindowTitle(QCoreApplication::translate("adminedituser", "Yoobee Library System | Admin | Edit user", nullptr));
        back->setText(QCoreApplication::translate("adminedituser", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("adminedituser", "First Name:", nullptr));
        label_4->setText(QCoreApplication::translate("adminedituser", "Email:", nullptr));
        label->setText(QCoreApplication::translate("adminedituser", "Edit User", nullptr));
        canceledit->setText(QCoreApplication::translate("adminedituser", "Cancel", nullptr));
        label_3->setText(QCoreApplication::translate("adminedituser", "Last Name:", nullptr));
        confimedit->setText(QCoreApplication::translate("adminedituser", "Confirm Changes", nullptr));
        label_5->setText(QCoreApplication::translate("adminedituser", "Phone No:", nullptr));
        img->setText(QCoreApplication::translate("adminedituser", "yoobee image", nullptr));
        deleteuser->setText(QCoreApplication::translate("adminedituser", "Delete User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminedituser: public Ui_adminedituser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINEDITUSER_H
