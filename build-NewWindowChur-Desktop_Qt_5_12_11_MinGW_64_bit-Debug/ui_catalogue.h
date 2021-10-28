/********************************************************************************
** Form generated from reading UI file 'catalogue.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOGUE_H
#define UI_CATALOGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Catalogue
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QTableWidget *bookCatalogue;
    QPushButton *checkOutButton;
    QWidget *tab_2;
    QPushButton *yourAccount_logout;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Catalogue)
    {
        if (Catalogue->objectName().isEmpty())
            Catalogue->setObjectName(QString::fromUtf8("Catalogue"));
        Catalogue->resize(1046, 614);
        gridLayout = new QGridLayout(Catalogue);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Catalogue);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 1);

        bookCatalogue = new QTableWidget(tab);
        bookCatalogue->setObjectName(QString::fromUtf8("bookCatalogue"));

        gridLayout_2->addWidget(bookCatalogue, 1, 0, 1, 1);

        checkOutButton = new QPushButton(tab);
        checkOutButton->setObjectName(QString::fromUtf8("checkOutButton"));

        gridLayout_2->addWidget(checkOutButton, 1, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        yourAccount_logout = new QPushButton(tab_2);
        yourAccount_logout->setObjectName(QString::fromUtf8("yourAccount_logout"));
        yourAccount_logout->setGeometry(QRect(270, 230, 91, 23));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(180, 220, 91, 23));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 128, 128));
        label->setAutoFillBackground(true);
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 20, 81, 31));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Catalogue);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Catalogue);
    } // setupUi

    void retranslateUi(QDialog *Catalogue)
    {
        Catalogue->setWindowTitle(QApplication::translate("Catalogue", "Yoobee Library System", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("Catalogue", "Search our catalogue", nullptr));
        checkOutButton->setText(QApplication::translate("Catalogue", "Check out", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Catalogue", "Catalogue", nullptr));
        yourAccount_logout->setText(QApplication::translate("Catalogue", "Log out", nullptr));
        pushButton_3->setText(QApplication::translate("Catalogue", "Update Details", nullptr));
        label->setText(QApplication::translate("Catalogue", "Person Picture", nullptr));
        label_2->setText(QApplication::translate("Catalogue", "Person Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Catalogue", "Your account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Catalogue: public Ui_Catalogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGUE_H
