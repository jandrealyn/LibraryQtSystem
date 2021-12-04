/********************************************************************************
** Form generated from reading UI file 'reservebook.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVEBOOK_H
#define UI_RESERVEBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReserveBook
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *bookNameLabel;
    QLabel *label_4;
    QCalendarWidget *calendarWidget;
    QLabel *label_5;
    QLabel *returnDateLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirmReserve;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel;

    void setupUi(QDialog *ReserveBook)
    {
        if (ReserveBook->objectName().isEmpty())
            ReserveBook->setObjectName(QString::fromUtf8("ReserveBook"));
        ReserveBook->resize(574, 344);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ReserveBook->setWindowIcon(icon);
        ReserveBook->setStyleSheet(QString::fromUtf8("*{\n"
"font-family: Century Gothic, sans-serif;\n"
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
        verticalLayout = new QVBoxLayout(ReserveBook);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ReserveBook);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Century Gothic")});
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(0);
        label_2 = new QLabel(ReserveBook);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Century Gothic")});
        font1.setPointSize(12);
        label_2->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        bookNameLabel = new QLabel(ReserveBook);
        bookNameLabel->setObjectName(QString::fromUtf8("bookNameLabel"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Century Gothic")});
        font2.setPointSize(12);
        font2.setBold(true);
        bookNameLabel->setFont(font2);

        formLayout->setWidget(0, QFormLayout::FieldRole, bookNameLabel);

        label_4 = new QLabel(ReserveBook);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        calendarWidget = new QCalendarWidget(ReserveBook);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, calendarWidget);

        label_5 = new QLabel(ReserveBook);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        returnDateLabel = new QLabel(ReserveBook);
        returnDateLabel->setObjectName(QString::fromUtf8("returnDateLabel"));
        returnDateLabel->setFont(font1);

        formLayout->setWidget(2, QFormLayout::FieldRole, returnDateLabel);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        confirmReserve = new QPushButton(ReserveBook);
        confirmReserve->setObjectName(QString::fromUtf8("confirmReserve"));
        sizePolicy.setHeightForWidth(confirmReserve->sizePolicy().hasHeightForWidth());
        confirmReserve->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(confirmReserve);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel = new QPushButton(ReserveBook);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        sizePolicy.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ReserveBook);

        QMetaObject::connectSlotsByName(ReserveBook);
    } // setupUi

    void retranslateUi(QDialog *ReserveBook)
    {
        ReserveBook->setWindowTitle(QCoreApplication::translate("ReserveBook", "Yoobee Library System | Reserve a book", nullptr));
        label->setText(QCoreApplication::translate("ReserveBook", "Reserve in Advance", nullptr));
        label_2->setText(QCoreApplication::translate("ReserveBook", "You are placing a reservation for ", nullptr));
        bookNameLabel->setText(QCoreApplication::translate("ReserveBook", "\"Book Name\"", nullptr));
        label_4->setText(QCoreApplication::translate("ReserveBook", "Checkout Date:", nullptr));
        label_5->setText(QCoreApplication::translate("ReserveBook", "Return Date:", nullptr));
        returnDateLabel->setText(QCoreApplication::translate("ReserveBook", "\"Return Date\"", nullptr));
        confirmReserve->setText(QCoreApplication::translate("ReserveBook", "Confirm", nullptr));
        cancel->setText(QCoreApplication::translate("ReserveBook", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReserveBook: public Ui_ReserveBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVEBOOK_H
