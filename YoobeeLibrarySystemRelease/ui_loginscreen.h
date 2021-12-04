/********************************************************************************
** Form generated from reading UI file 'loginscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginscreen
{
public:
    QFrame *gridFrame_3;
    QLabel *img_2;
    QPushButton *close;
    QPushButton *Create;
    QWidget *formLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *username_input;
    QLabel *label_2;
    QLineEdit *password_input;
    QPushButton *login;
    QCheckBox *checkBox_rememberMe;

    void setupUi(QDialog *loginscreen)
    {
        if (loginscreen->objectName().isEmpty())
            loginscreen->setObjectName(QString::fromUtf8("loginscreen"));
        loginscreen->resize(1012, 666);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        loginscreen->setWindowIcon(icon);
        gridFrame_3 = new QFrame(loginscreen);
        gridFrame_3->setObjectName(QString::fromUtf8("gridFrame_3"));
        gridFrame_3->setGeometry(QRect(110, 30, 801, 551));
        gridFrame_3->setStyleSheet(QString::fromUtf8("*{\n"
"background: rgb(255, 255, 255);\n"
"font-size: 15px;\n"
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
"background-color: rgb(224, 0, 0);\n"
"border-style: inset;\n"
"}\n"
""));
        img_2 = new QLabel(gridFrame_3);
        img_2->setObjectName(QString::fromUtf8("img_2"));
        img_2->setGeometry(QRect(40, 30, 341, 121));
        img_2->setStyleSheet(QString::fromUtf8(""));
        close = new QPushButton(gridFrame_3);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(580, 60, 172, 28));
        close->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"  color: white;\n"
"  background-color: #27a9e3;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}\n"
"hover:\n"
"\n"
"QPushButton:hover { background-color: #66c011; }"));
        Create = new QPushButton(gridFrame_3);
        Create->setObjectName(QString::fromUtf8("Create"));
        Create->setGeometry(QRect(290, 410, 256, 31));
        Create->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"  color: white;\n"
"  background-color: #27a9e3;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}\n"
"hover:\n"
"\n"
"QPushButton:hover { background-color: #66c011; }"));
        formLayoutWidget = new QWidget(gridFrame_3);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(310, 241, 221, 162));
        verticalLayout_2 = new QVBoxLayout(formLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        username_input = new QLineEdit(formLayoutWidget);
        username_input->setObjectName(QString::fromUtf8("username_input"));
        username_input->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));

        verticalLayout_2->addWidget(username_input);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        password_input = new QLineEdit(formLayoutWidget);
        password_input->setObjectName(QString::fromUtf8("password_input"));
        password_input->setStyleSheet(QString::fromUtf8("QLabel { color: white; }\n"
"QLineEdit { border-radius: 3px; }"));
        password_input->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(password_input);

        login = new QPushButton(formLayoutWidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"  color: white;\n"
"  background-color: #27a9e3;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}\n"
"hover:\n"
"\n"
"QPushButton:hover { background-color: #66c011; }"));

        verticalLayout_2->addWidget(login);

        checkBox_rememberMe = new QCheckBox(formLayoutWidget);
        checkBox_rememberMe->setObjectName(QString::fromUtf8("checkBox_rememberMe"));

        verticalLayout_2->addWidget(checkBox_rememberMe);

        QWidget::setTabOrder(username_input, password_input);
        QWidget::setTabOrder(password_input, login);
        QWidget::setTabOrder(login, checkBox_rememberMe);
        QWidget::setTabOrder(checkBox_rememberMe, Create);
        QWidget::setTabOrder(Create, close);

        retranslateUi(loginscreen);

        QMetaObject::connectSlotsByName(loginscreen);
    } // setupUi

    void retranslateUi(QDialog *loginscreen)
    {
        loginscreen->setWindowTitle(QCoreApplication::translate("loginscreen", "Yoobe Library System | Login", nullptr));
        img_2->setText(QCoreApplication::translate("loginscreen", "Yoobee image", nullptr));
        close->setText(QCoreApplication::translate("loginscreen", "Close", nullptr));
        Create->setText(QCoreApplication::translate("loginscreen", "Create An Account", nullptr));
        label->setText(QCoreApplication::translate("loginscreen", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("loginscreen", "Password", nullptr));
        login->setText(QCoreApplication::translate("loginscreen", "Login", nullptr));
        checkBox_rememberMe->setText(QCoreApplication::translate("loginscreen", "Remember me", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginscreen: public Ui_loginscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
