/********************************************************************************
** Form generated from reading UI file 'checkoutscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTSCREEN_H
#define UI_CHECKOUTSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CheckOutScreen
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *titleLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *book_name_label_2;
    QLabel *book_name_label;
    QHBoxLayout *authorLayout;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *book_name_label_3;
    QLabel *book_author_label;
    QHBoxLayout *copiesLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *book_copies_label;
    QHBoxLayout *buttonsLayout;
    QPushButton *checkoutNow;
    QPushButton *reserve;
    QPushButton *cancel;

    void setupUi(QDialog *CheckOutScreen)
    {
        if (CheckOutScreen->objectName().isEmpty())
            CheckOutScreen->setObjectName(QString::fromUtf8("CheckOutScreen"));
        CheckOutScreen->resize(467, 255);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        CheckOutScreen->setWindowIcon(icon);
        CheckOutScreen->setAutoFillBackground(false);
        CheckOutScreen->setStyleSheet(QString::fromUtf8("QDialog {\n"
"background-color: white;\n"
"}\n"
"\n"
"book_name_label {\n"
"background-color: green;\n"
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
        verticalLayout = new QVBoxLayout(CheckOutScreen);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(CheckOutScreen);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(19);
        font.setBold(true);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: bold;"));

        verticalLayout_2->addWidget(label);

        titleLayout = new QHBoxLayout();
        titleLayout->setSpacing(6);
        titleLayout->setObjectName(QString::fromUtf8("titleLayout"));
        titleLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        titleLayout->setContentsMargins(0, -1, -1, -1);
        groupBox = new QGroupBox(CheckOutScreen);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 241, 241);"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        book_name_label_2 = new QLabel(groupBox);
        book_name_label_2->setObjectName(QString::fromUtf8("book_name_label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(book_name_label_2->sizePolicy().hasHeightForWidth());
        book_name_label_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        book_name_label_2->setFont(font1);
        book_name_label_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(book_name_label_2);

        book_name_label = new QLabel(groupBox);
        book_name_label->setObjectName(QString::fromUtf8("book_name_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(book_name_label->sizePolicy().hasHeightForWidth());
        book_name_label->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(12);
        book_name_label->setFont(font2);
        book_name_label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(book_name_label);


        titleLayout->addWidget(groupBox);


        verticalLayout_2->addLayout(titleLayout);

        authorLayout = new QHBoxLayout();
        authorLayout->setObjectName(QString::fromUtf8("authorLayout"));
        groupBox_3 = new QGroupBox(CheckOutScreen);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        book_name_label_3 = new QLabel(groupBox_3);
        book_name_label_3->setObjectName(QString::fromUtf8("book_name_label_3"));
        sizePolicy.setHeightForWidth(book_name_label_3->sizePolicy().hasHeightForWidth());
        book_name_label_3->setSizePolicy(sizePolicy);
        book_name_label_3->setFont(font1);

        horizontalLayout_6->addWidget(book_name_label_3);

        book_author_label = new QLabel(groupBox_3);
        book_author_label->setObjectName(QString::fromUtf8("book_author_label"));
        sizePolicy1.setHeightForWidth(book_author_label->sizePolicy().hasHeightForWidth());
        book_author_label->setSizePolicy(sizePolicy1);
        book_author_label->setFont(font2);

        horizontalLayout_6->addWidget(book_author_label);


        authorLayout->addWidget(groupBox_3);


        verticalLayout_2->addLayout(authorLayout);

        copiesLayout = new QHBoxLayout();
        copiesLayout->setObjectName(QString::fromUtf8("copiesLayout"));
        groupBox_2 = new QGroupBox(CheckOutScreen);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 241, 241);"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        book_copies_label = new QLabel(groupBox_2);
        book_copies_label->setObjectName(QString::fromUtf8("book_copies_label"));
        sizePolicy1.setHeightForWidth(book_copies_label->sizePolicy().hasHeightForWidth());
        book_copies_label->setSizePolicy(sizePolicy1);
        book_copies_label->setFont(font2);
        book_copies_label->setStyleSheet(QString::fromUtf8(""));
        book_copies_label->setTextFormat(Qt::AutoText);
        book_copies_label->setScaledContents(false);
        book_copies_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(book_copies_label);


        copiesLayout->addWidget(groupBox_2);


        verticalLayout_2->addLayout(copiesLayout);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        checkoutNow = new QPushButton(CheckOutScreen);
        checkoutNow->setObjectName(QString::fromUtf8("checkoutNow"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkoutNow->sizePolicy().hasHeightForWidth());
        checkoutNow->setSizePolicy(sizePolicy2);
        checkoutNow->setStyleSheet(QString::fromUtf8(""));

        buttonsLayout->addWidget(checkoutNow);

        reserve = new QPushButton(CheckOutScreen);
        reserve->setObjectName(QString::fromUtf8("reserve"));
        sizePolicy2.setHeightForWidth(reserve->sizePolicy().hasHeightForWidth());
        reserve->setSizePolicy(sizePolicy2);
        reserve->setStyleSheet(QString::fromUtf8(""));

        buttonsLayout->addWidget(reserve);

        cancel = new QPushButton(CheckOutScreen);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy3);
        cancel->setStyleSheet(QString::fromUtf8(""));

        buttonsLayout->addWidget(cancel);


        verticalLayout_2->addLayout(buttonsLayout);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(CheckOutScreen);

        QMetaObject::connectSlotsByName(CheckOutScreen);
    } // setupUi

    void retranslateUi(QDialog *CheckOutScreen)
    {
        CheckOutScreen->setWindowTitle(QCoreApplication::translate("CheckOutScreen", "Yoobee Library System | Check Out", nullptr));
        label->setText(QCoreApplication::translate("CheckOutScreen", "Checkout a book", nullptr));
        groupBox->setTitle(QString());
        book_name_label_2->setText(QCoreApplication::translate("CheckOutScreen", "Title:    ", nullptr));
        book_name_label->setText(QCoreApplication::translate("CheckOutScreen", "BookName", nullptr));
        groupBox_3->setTitle(QString());
        book_name_label_3->setText(QCoreApplication::translate("CheckOutScreen", "Author:", nullptr));
        book_author_label->setText(QCoreApplication::translate("CheckOutScreen", "Author", nullptr));
        groupBox_2->setTitle(QString());
        label_4->setText(QCoreApplication::translate("CheckOutScreen", "Copies:", nullptr));
        book_copies_label->setText(QCoreApplication::translate("CheckOutScreen", "0", nullptr));
        checkoutNow->setText(QCoreApplication::translate("CheckOutScreen", "Checkout Now", nullptr));
        reserve->setText(QCoreApplication::translate("CheckOutScreen", "Reserve in Advance", nullptr));
        cancel->setText(QCoreApplication::translate("CheckOutScreen", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckOutScreen: public Ui_CheckOutScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTSCREEN_H
