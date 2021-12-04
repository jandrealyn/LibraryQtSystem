/********************************************************************************
** Form generated from reading UI file 'updateuserdetails.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEUSERDETAILS_H
#define UI_UPDATEUSERDETAILS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UpdateUserDetails
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_password;
    QCheckBox *checkBox;
    QLabel *label_3;
    QLineEdit *lineEdit_firstname;
    QLabel *label_4;
    QLineEdit *lineEdit_lastname;
    QLabel *label_5;
    QLabel *label_8;
    QLineEdit *lineEdit_phone;
    QLabel *label_6;
    QLineEdit *lineEdit_userid;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_username;
    QLabel *usernamePic;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_email;
    QLabel *emailPic;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *confirmChanges;
    QPushButton *pushButton_2;

    void setupUi(QDialog *UpdateUserDetails)
    {
        if (UpdateUserDetails->objectName().isEmpty())
            UpdateUserDetails->setObjectName(QString::fromUtf8("UpdateUserDetails"));
        UpdateUserDetails->resize(619, 330);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UpdateUserDetails->sizePolicy().hasHeightForWidth());
        UpdateUserDetails->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        UpdateUserDetails->setWindowIcon(icon);
        UpdateUserDetails->setWindowOpacity(1.000000000000000);
        UpdateUserDetails->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"padding: 1px;\n"
"color: black;\n"
"background-color: white;\n"
"border: 1px solid gray;\n"
"border-radius: 10px;\n"
"font: 12pt;\n"
"}\n"
"\n"
"QLineEdit::disabled {\n"
"color: gray;\n"
"}\n"
"\n"
"QPushButton {\n"
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
        verticalLayout = new QVBoxLayout(UpdateUserDetails);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(UpdateUserDetails);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setToolTipDuration(0);
        label_7->setStyleSheet(QString::fromUtf8("font: 22px;"));

        horizontalLayout_3->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(UpdateUserDetails);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Poppins\";"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(UpdateUserDetails);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Poppins\";"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit_password = new QLineEdit(UpdateUserDetails);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(lineEdit_password);

        checkBox = new QCheckBox(UpdateUserDetails);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setStyleSheet(QString::fromUtf8("font: 8pt \"Poppins\";"));

        horizontalLayout_4->addWidget(checkBox);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_4);

        label_3 = new QLabel(UpdateUserDetails);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Poppins\";"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_firstname = new QLineEdit(UpdateUserDetails);
        lineEdit_firstname->setObjectName(QString::fromUtf8("lineEdit_firstname"));
        lineEdit_firstname->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_firstname);

        label_4 = new QLabel(UpdateUserDetails);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Poppins\";"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_lastname = new QLineEdit(UpdateUserDetails);
        lineEdit_lastname->setObjectName(QString::fromUtf8("lineEdit_lastname"));
        lineEdit_lastname->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_lastname);

        label_5 = new QLabel(UpdateUserDetails);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"Poppins\";"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_8 = new QLabel(UpdateUserDetails);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 12pt \"Poppins\";"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        lineEdit_phone = new QLineEdit(UpdateUserDetails);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_phone);

        label_6 = new QLabel(UpdateUserDetails);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"Poppins\";"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        lineEdit_userid = new QLineEdit(UpdateUserDetails);
        lineEdit_userid->setObjectName(QString::fromUtf8("lineEdit_userid"));
        lineEdit_userid->setStyleSheet(QString::fromUtf8(""));
        lineEdit_userid->setReadOnly(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_userid);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit_username = new QLineEdit(UpdateUserDetails);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setStyleSheet(QString::fromUtf8(""));
        lineEdit_username->setDragEnabled(false);
        lineEdit_username->setClearButtonEnabled(false);

        horizontalLayout_5->addWidget(lineEdit_username);

        usernamePic = new QLabel(UpdateUserDetails);
        usernamePic->setObjectName(QString::fromUtf8("usernamePic"));

        horizontalLayout_5->addWidget(usernamePic);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEdit_email = new QLineEdit(UpdateUserDetails);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));
        lineEdit_email->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_6->addWidget(lineEdit_email);

        emailPic = new QLabel(UpdateUserDetails);
        emailPic->setObjectName(QString::fromUtf8("emailPic"));

        horizontalLayout_6->addWidget(emailPic);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_6);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        confirmChanges = new QPushButton(UpdateUserDetails);
        confirmChanges->setObjectName(QString::fromUtf8("confirmChanges"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(confirmChanges->sizePolicy().hasHeightForWidth());
        confirmChanges->setSizePolicy(sizePolicy1);
        confirmChanges->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(confirmChanges);

        pushButton_2 = new QPushButton(UpdateUserDetails);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(UpdateUserDetails);

        QMetaObject::connectSlotsByName(UpdateUserDetails);
    } // setupUi

    void retranslateUi(QDialog *UpdateUserDetails)
    {
        UpdateUserDetails->setWindowTitle(QCoreApplication::translate("UpdateUserDetails", "Yoobee Library System | Update account", nullptr));
        label_7->setText(QCoreApplication::translate("UpdateUserDetails", "Edit personal details", nullptr));
        label->setText(QCoreApplication::translate("UpdateUserDetails", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("UpdateUserDetails", "Password:", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("UpdateUserDetails", "Enter a new password", nullptr));
        checkBox->setText(QCoreApplication::translate("UpdateUserDetails", "Show Password", nullptr));
        label_3->setText(QCoreApplication::translate("UpdateUserDetails", "First name:", nullptr));
        lineEdit_firstname->setPlaceholderText(QCoreApplication::translate("UpdateUserDetails", "Enter a new first name", nullptr));
        label_4->setText(QCoreApplication::translate("UpdateUserDetails", "Last Name:", nullptr));
        lineEdit_lastname->setPlaceholderText(QCoreApplication::translate("UpdateUserDetails", "Enter a new last name", nullptr));
        label_5->setText(QCoreApplication::translate("UpdateUserDetails", "Email:", nullptr));
        label_8->setText(QCoreApplication::translate("UpdateUserDetails", "Phone:", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("UpdateUserDetails", "Enter a new phone number", nullptr));
        label_6->setText(QCoreApplication::translate("UpdateUserDetails", "User ID:", nullptr));
        lineEdit_userid->setText(QString());
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("UpdateUserDetails", "Enter a new username", nullptr));
        usernamePic->setText(QCoreApplication::translate("UpdateUserDetails", "TextLabel", nullptr));
        lineEdit_email->setPlaceholderText(QCoreApplication::translate("UpdateUserDetails", "Enter a new email", nullptr));
        emailPic->setText(QCoreApplication::translate("UpdateUserDetails", "TextLabel", nullptr));
        confirmChanges->setText(QCoreApplication::translate("UpdateUserDetails", "Confirm Changes", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UpdateUserDetails", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UpdateUserDetails: public Ui_UpdateUserDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEUSERDETAILS_H
