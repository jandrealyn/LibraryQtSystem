/********************************************************************************
** Form generated from reading UI file 'admineditbook.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINEDITBOOK_H
#define UI_ADMINEDITBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_admineditbook
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
    QLineEdit *book_name_label;
    QLineEdit *book_author_label;
    QLineEdit *book_copies_label;
    QLabel *img;
    QPushButton *deletebook;

    void setupUi(QDialog *admineditbook)
    {
        if (admineditbook->objectName().isEmpty())
            admineditbook->setObjectName(QString::fromUtf8("admineditbook"));
        admineditbook->resize(545, 439);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        admineditbook->setWindowIcon(icon);
        gridFrame_2 = new QFrame(admineditbook);
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
        label_2->setGeometry(QRect(80, 120, 41, 31));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        label_4 = new QLabel(gridFrame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 220, 91, 31));
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
        label_3->setGeometry(QRect(50, 170, 91, 31));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        confimedit = new QPushButton(gridFrame_2);
        confimedit->setObjectName(QString::fromUtf8("confimedit"));
        confimedit->setGeometry(QRect(210, 360, 121, 51));
        label_5 = new QLabel(gridFrame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 270, 71, 31));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        book_name_label = new QLineEdit(gridFrame_2);
        book_name_label->setObjectName(QString::fromUtf8("book_name_label"));
        book_name_label->setGeometry(QRect(130, 120, 281, 31));
        book_author_label = new QLineEdit(gridFrame_2);
        book_author_label->setObjectName(QString::fromUtf8("book_author_label"));
        book_author_label->setGeometry(QRect(130, 170, 281, 31));
        book_copies_label = new QLineEdit(gridFrame_2);
        book_copies_label->setObjectName(QString::fromUtf8("book_copies_label"));
        book_copies_label->setGeometry(QRect(130, 220, 281, 31));
        img = new QLabel(gridFrame_2);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(10, 10, 161, 81));
        deletebook = new QPushButton(gridFrame_2);
        deletebook->setObjectName(QString::fromUtf8("deletebook"));
        deletebook->setGeometry(QRect(40, 360, 121, 51));

        retranslateUi(admineditbook);

        QMetaObject::connectSlotsByName(admineditbook);
    } // setupUi

    void retranslateUi(QDialog *admineditbook)
    {
        admineditbook->setWindowTitle(QCoreApplication::translate("admineditbook", "Yoobee Library System | Admin | Edit book", nullptr));
        back->setText(QCoreApplication::translate("admineditbook", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("admineditbook", "Title:", nullptr));
        label_4->setText(QCoreApplication::translate("admineditbook", "Copies:", nullptr));
        label->setText(QCoreApplication::translate("admineditbook", "Edit Book", nullptr));
        canceledit->setText(QCoreApplication::translate("admineditbook", "Cancel", nullptr));
        label_3->setText(QCoreApplication::translate("admineditbook", "Author:", nullptr));
        confimedit->setText(QCoreApplication::translate("admineditbook", "Confirm Changes", nullptr));
        label_5->setText(QCoreApplication::translate("admineditbook", "Image:", nullptr));
        img->setText(QCoreApplication::translate("admineditbook", "yoobee image", nullptr));
        deletebook->setText(QCoreApplication::translate("admineditbook", "Delete Book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admineditbook: public Ui_admineditbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINEDITBOOK_H
