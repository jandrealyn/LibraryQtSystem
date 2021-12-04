/********************************************************************************
** Form generated from reading UI file 'adminaddbook.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINADDBOOK_H
#define UI_ADMINADDBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminaddbook
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *gridFrame_2;
    QPushButton *back;
    QLabel *label_4;
    QLabel *label;
    QPushButton *canceladd;
    QLabel *label_3;
    QPushButton *confirmadd;
    QLabel *label_5;
    QLineEdit *book_name_label;
    QLineEdit *book_author_label;
    QLabel *img;
    QLabel *label_6;
    QLineEdit *book_copies_label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QCheckBox *bookone;
    QCheckBox *booktwo;
    QCheckBox *bookthree;
    QLabel *book1;
    QLabel *book2;
    QLabel *book3;

    void setupUi(QDialog *adminaddbook)
    {
        if (adminaddbook->objectName().isEmpty())
            adminaddbook->setObjectName(QString::fromUtf8("adminaddbook"));
        adminaddbook->resize(549, 460);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        adminaddbook->setWindowIcon(icon);
        adminaddbook->setStyleSheet(QString::fromUtf8("background-color: white;"));
        verticalLayout = new QVBoxLayout(adminaddbook);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridFrame_2 = new QFrame(adminaddbook);
        gridFrame_2->setObjectName(QString::fromUtf8("gridFrame_2"));
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
        label_4 = new QLabel(gridFrame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 150, 71, 31));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        label = new QLabel(gridFrame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 20, 161, 51));
        label->setStyleSheet(QString::fromUtf8("font-size: 34px"));
        canceladd = new QPushButton(gridFrame_2);
        canceladd->setObjectName(QString::fromUtf8("canceladd"));
        canceladd->setGeometry(QRect(300, 390, 121, 41));
        label_3 = new QLabel(gridFrame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 90, 41, 31));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        confirmadd = new QPushButton(gridFrame_2);
        confirmadd->setObjectName(QString::fromUtf8("confirmadd"));
        confirmadd->setGeometry(QRect(120, 390, 121, 41));
        label_5 = new QLabel(gridFrame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 300, 71, 31));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        book_name_label = new QLineEdit(gridFrame_2);
        book_name_label->setObjectName(QString::fromUtf8("book_name_label"));
        book_name_label->setGeometry(QRect(130, 90, 281, 31));
        book_author_label = new QLineEdit(gridFrame_2);
        book_author_label->setObjectName(QString::fromUtf8("book_author_label"));
        book_author_label->setGeometry(QRect(130, 150, 281, 31));
        img = new QLabel(gridFrame_2);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(10, 10, 161, 51));
        label_6 = new QLabel(gridFrame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 210, 71, 31));
        label_6->setStyleSheet(QString::fromUtf8("font-size: 20px"));
        book_copies_label = new QLineEdit(gridFrame_2);
        book_copies_label->setObjectName(QString::fromUtf8("book_copies_label"));
        book_copies_label->setGeometry(QRect(130, 210, 281, 31));
        gridLayoutWidget = new QWidget(gridFrame_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(130, 260, 291, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bookone = new QCheckBox(gridLayoutWidget);
        bookone->setObjectName(QString::fromUtf8("bookone"));

        gridLayout->addWidget(bookone, 1, 0, 1, 1);

        booktwo = new QCheckBox(gridLayoutWidget);
        booktwo->setObjectName(QString::fromUtf8("booktwo"));

        gridLayout->addWidget(booktwo, 1, 1, 1, 1);

        bookthree = new QCheckBox(gridLayoutWidget);
        bookthree->setObjectName(QString::fromUtf8("bookthree"));

        gridLayout->addWidget(bookthree, 1, 2, 1, 1);

        book1 = new QLabel(gridLayoutWidget);
        book1->setObjectName(QString::fromUtf8("book1"));
        book1->setScaledContents(true);

        gridLayout->addWidget(book1, 0, 0, 1, 1);

        book2 = new QLabel(gridLayoutWidget);
        book2->setObjectName(QString::fromUtf8("book2"));

        gridLayout->addWidget(book2, 0, 1, 1, 1);

        book3 = new QLabel(gridLayoutWidget);
        book3->setObjectName(QString::fromUtf8("book3"));

        gridLayout->addWidget(book3, 0, 2, 1, 1);


        verticalLayout->addWidget(gridFrame_2);


        retranslateUi(adminaddbook);

        QMetaObject::connectSlotsByName(adminaddbook);
    } // setupUi

    void retranslateUi(QDialog *adminaddbook)
    {
        adminaddbook->setWindowTitle(QCoreApplication::translate("adminaddbook", "Yoobee Library System | Admin | Add a book", nullptr));
        back->setText(QCoreApplication::translate("adminaddbook", "Back", nullptr));
        label_4->setText(QCoreApplication::translate("adminaddbook", "Author:", nullptr));
        label->setText(QCoreApplication::translate("adminaddbook", "Add Book", nullptr));
        canceladd->setText(QCoreApplication::translate("adminaddbook", "Cancel", nullptr));
        label_3->setText(QCoreApplication::translate("adminaddbook", "Title:", nullptr));
        confirmadd->setText(QCoreApplication::translate("adminaddbook", "Confirm Changes", nullptr));
        label_5->setText(QCoreApplication::translate("adminaddbook", "Image:", nullptr));
        img->setText(QCoreApplication::translate("adminaddbook", "yoobee image", nullptr));
        label_6->setText(QCoreApplication::translate("adminaddbook", "Copies:", nullptr));
        bookone->setText(QCoreApplication::translate("adminaddbook", "Cool Blue", nullptr));
        booktwo->setText(QCoreApplication::translate("adminaddbook", "Berserk!!!!", nullptr));
        bookthree->setText(QCoreApplication::translate("adminaddbook", "Default", nullptr));
        book1->setText(QCoreApplication::translate("adminaddbook", "book img", nullptr));
        book2->setText(QCoreApplication::translate("adminaddbook", "book img2", nullptr));
        book3->setText(QCoreApplication::translate("adminaddbook", "book img3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminaddbook: public Ui_adminaddbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINADDBOOK_H
