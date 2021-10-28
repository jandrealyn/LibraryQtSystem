/********************************************************************************
** Form generated from reading UI file 'checkoutscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTSCREEN_H
#define UI_CHECKOUTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_CheckOutScreen
{
public:
    QPushButton *pushButton_2;
    QPushButton *cancel;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QToolButton *toolButton;

    void setupUi(QDialog *CheckOutScreen)
    {
        if (CheckOutScreen->objectName().isEmpty())
            CheckOutScreen->setObjectName(QString::fromUtf8("CheckOutScreen"));
        CheckOutScreen->resize(384, 203);
        pushButton_2 = new QPushButton(CheckOutScreen);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 100, 81, 41));
        cancel = new QPushButton(CheckOutScreen);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(10, 170, 75, 23));
        label = new QLabel(CheckOutScreen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 186, 30));
        QFont font;
        font.setPointSize(19);
        label->setFont(font);
        pushButton = new QPushButton(CheckOutScreen);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 50, 81, 41));
        label_2 = new QLabel(CheckOutScreen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 60, 151, 21));
        label_3 = new QLabel(CheckOutScreen);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 110, 271, 21));
        label_3->setTextFormat(Qt::AutoText);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        toolButton = new QToolButton(CheckOutScreen);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(160, 170, 25, 19));

        retranslateUi(CheckOutScreen);

        QMetaObject::connectSlotsByName(CheckOutScreen);
    } // setupUi

    void retranslateUi(QDialog *CheckOutScreen)
    {
        CheckOutScreen->setWindowTitle(QApplication::translate("CheckOutScreen", "Dialog", nullptr));
        pushButton_2->setText(QApplication::translate("CheckOutScreen", "Prebook", nullptr));
        cancel->setText(QApplication::translate("CheckOutScreen", "Cancel", nullptr));
        label->setText(QApplication::translate("CheckOutScreen", "Checkout a book", nullptr));
        pushButton->setText(QApplication::translate("CheckOutScreen", "Checkout Now", nullptr));
        label_2->setText(QApplication::translate("CheckOutScreen", "Receive your book right away", nullptr));
        label_3->setText(QApplication::translate("CheckOutScreen", "For when the book is next available or for a specific date", nullptr));
        toolButton->setText(QApplication::translate("CheckOutScreen", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckOutScreen: public Ui_CheckOutScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTSCREEN_H
