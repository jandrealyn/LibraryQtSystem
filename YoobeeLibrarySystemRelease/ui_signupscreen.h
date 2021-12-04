/********************************************************************************
** Form generated from reading UI file 'signupscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPSCREEN_H
#define UI_SIGNUPSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signupscreen
{
public:
    QFrame *gridFrame_2;
    QLabel *img;
    QPushButton *close;
    QWidget *layoutWidget;
    QHBoxLayout *UsernameCheck;
    QLabel *usernamecheckImg;
    QLabel *usernameCheckText;
    QWidget *layoutWidget_2;
    QHBoxLayout *EmailCheck;
    QLabel *emailCheckImg;
    QLabel *emailCheckText;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QRadioButton *pup_avatar;
    QLabel *label_8;
    QRadioButton *jerboa_avatar;
    QLabel *label_7;
    QRadioButton *cat_avatar;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLineEdit *firstname;
    QLabel *label_6;
    QLineEdit *lastname;
    QLabel *label;
    QLineEdit *Username;
    QLabel *label_2;
    QLineEdit *Password;
    QLabel *label_3;
    QLineEdit *email;
    QLabel *label_4;
    QLineEdit *phone;
    QPushButton *Next;

    void setupUi(QDialog *signupscreen)
    {
        if (signupscreen->objectName().isEmpty())
            signupscreen->setObjectName(QString::fromUtf8("signupscreen"));
        signupscreen->resize(800, 549);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        signupscreen->setWindowIcon(icon);
        signupscreen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white;\n"
"background-color: #27a9e3;\n"
"border-radius: 3px;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"background-color: rgb(216, 150, 90);\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: #59c7f7;\n"
"}\n"
"\n"
"QPushButton::disabled {\n"
"color: #ebebeb;\n"
"background-color: #1c7ba6;\n"
"}"));
        gridFrame_2 = new QFrame(signupscreen);
        gridFrame_2->setObjectName(QString::fromUtf8("gridFrame_2"));
        gridFrame_2->setGeometry(QRect(0, 0, 801, 551));
        gridFrame_2->setStyleSheet(QString::fromUtf8("*{\n"
"background: rgb(255, 255, 255);\n"
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
        layoutWidget = new QWidget(gridFrame_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(500, 370, 141, 19));
        UsernameCheck = new QHBoxLayout(layoutWidget);
        UsernameCheck->setObjectName(QString::fromUtf8("UsernameCheck"));
        UsernameCheck->setContentsMargins(0, 0, 0, 0);
        usernamecheckImg = new QLabel(layoutWidget);
        usernamecheckImg->setObjectName(QString::fromUtf8("usernamecheckImg"));

        UsernameCheck->addWidget(usernamecheckImg);

        usernameCheckText = new QLabel(layoutWidget);
        usernameCheckText->setObjectName(QString::fromUtf8("usernameCheckText"));

        UsernameCheck->addWidget(usernameCheckText);

        layoutWidget_2 = new QWidget(gridFrame_2);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(500, 430, 141, 19));
        EmailCheck = new QHBoxLayout(layoutWidget_2);
        EmailCheck->setObjectName(QString::fromUtf8("EmailCheck"));
        EmailCheck->setContentsMargins(0, 0, 0, 0);
        emailCheckImg = new QLabel(layoutWidget_2);
        emailCheckImg->setObjectName(QString::fromUtf8("emailCheckImg"));

        EmailCheck->addWidget(emailCheckImg);

        emailCheckText = new QLabel(layoutWidget_2);
        emailCheckText->setObjectName(QString::fromUtf8("emailCheckText"));

        EmailCheck->addWidget(emailCheckText);

        layoutWidget1 = new QWidget(gridFrame_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(140, 120, 531, 161));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/images/jerboa-avatar.jpg")));

        gridLayout_2->addWidget(label_9, 0, 2, 1, 1);

        pup_avatar = new QRadioButton(layoutWidget1);
        pup_avatar->setObjectName(QString::fromUtf8("pup_avatar"));

        gridLayout_2->addWidget(pup_avatar, 1, 1, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/images/dog-avatar.jpg")));

        gridLayout_2->addWidget(label_8, 0, 1, 1, 1);

        jerboa_avatar = new QRadioButton(layoutWidget1);
        jerboa_avatar->setObjectName(QString::fromUtf8("jerboa_avatar"));

        gridLayout_2->addWidget(jerboa_avatar, 1, 2, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/images/cat-avatar.jpg")));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        cat_avatar = new QRadioButton(layoutWidget1);
        cat_avatar->setObjectName(QString::fromUtf8("cat_avatar"));

        gridLayout_2->addWidget(cat_avatar, 1, 0, 1, 1);

        formLayoutWidget = new QWidget(gridFrame_2);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(260, 310, 235, 175));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        firstname = new QLineEdit(formLayoutWidget);
        firstname->setObjectName(QString::fromUtf8("firstname"));
        firstname->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));

        formLayout->setWidget(0, QFormLayout::FieldRole, firstname);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        lastname = new QLineEdit(formLayoutWidget);
        lastname->setObjectName(QString::fromUtf8("lastname"));
        lastname->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lastname);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        Username = new QLineEdit(formLayoutWidget);
        Username->setObjectName(QString::fromUtf8("Username"));
        Username->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));

        formLayout->setWidget(2, QFormLayout::FieldRole, Username);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        Password = new QLineEdit(formLayoutWidget);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));
        Password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, Password);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        email = new QLineEdit(formLayoutWidget);
        email->setObjectName(QString::fromUtf8("email"));
        email->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));

        formLayout->setWidget(4, QFormLayout::FieldRole, email);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        phone = new QLineEdit(formLayoutWidget);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));
        phone->setMaxLength(10);

        formLayout->setWidget(5, QFormLayout::FieldRole, phone);

        Next = new QPushButton(gridFrame_2);
        Next->setObjectName(QString::fromUtf8("Next"));
        Next->setGeometry(QRect(280, 500, 191, 21));
        Next->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(signupscreen);

        QMetaObject::connectSlotsByName(signupscreen);
    } // setupUi

    void retranslateUi(QDialog *signupscreen)
    {
        signupscreen->setWindowTitle(QCoreApplication::translate("signupscreen", "Yoobee Library System | Sign Up", nullptr));
        img->setText(QCoreApplication::translate("signupscreen", "Yoobee image", nullptr));
        close->setText(QCoreApplication::translate("signupscreen", "Close", nullptr));
        usernamecheckImg->setText(QString());
        usernameCheckText->setText(QString());
        emailCheckImg->setText(QString());
        emailCheckText->setText(QString());
        label_9->setText(QString());
        pup_avatar->setText(QCoreApplication::translate("signupscreen", "Small Pup", nullptr));
        label_8->setText(QString());
        jerboa_avatar->setText(QCoreApplication::translate("signupscreen", "Jerboa", nullptr));
        label_7->setText(QString());
        cat_avatar->setText(QCoreApplication::translate("signupscreen", "Kitty Cat", nullptr));
        label_5->setText(QCoreApplication::translate("signupscreen", "First Name", nullptr));
        label_6->setText(QCoreApplication::translate("signupscreen", "Last Name", nullptr));
        label->setText(QCoreApplication::translate("signupscreen", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("signupscreen", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("signupscreen", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("signupscreen", "Phone", nullptr));
        Next->setText(QCoreApplication::translate("signupscreen", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signupscreen: public Ui_signupscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPSCREEN_H
