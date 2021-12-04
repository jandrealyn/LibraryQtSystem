/********************************************************************************
** Form generated from reading UI file 'catalogue.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOGUE_H
#define UI_CATALOGUE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Catalogue
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_Home;
    QGridLayout *gridLayout_3;
    QLabel *yoobeeLogo_2;
    QLabel *label_3;
    QLabel *welcomeBack;
    QTextBrowser *textBrowser;
    QWidget *tab_Catalogue;
    QVBoxLayout *verticalLayout;
    QLineEdit *searchBar;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *tab_YourAccount;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *profile_picture;
    QSpacerItem *horizontalSpacer;
    QLabel *user_name;
    QLabel *user_id;
    QLabel *user_email;
    QLabel *user_phonenumber;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *yourAccount_update;
    QSpacerItem *horizontalSpacer_5;
    QTabWidget *users_books;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget_currentBooks;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *yourAccount_logout;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Catalogue)
    {
        if (Catalogue->objectName().isEmpty())
            Catalogue->setObjectName(QString::fromUtf8("Catalogue"));
        Catalogue->resize(1273, 704);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Catalogue->sizePolicy().hasHeightForWidth());
        Catalogue->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        Catalogue->setWindowIcon(icon);
        Catalogue->setStyleSheet(QString::fromUtf8("*{\n"
"font-family: Century Gothic, sans-serif;\n"
"}\n"
"\n"
"QPushButton{\n"
"color: white;\n"
"padding: 5px;\n"
"background: #27a9e3;\n"
"border-style: outset;\n"
"border-radius: 5px;\n"
"font: bold;\n"
"}\n"
"\n"
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
"\n"
"QLabel {\n"
"font-size: 12px;\n"
"}"));
        gridLayout = new QGridLayout(Catalogue);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Catalogue);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"height: 50px;\n"
"width: 120px;\n"
"}"));
        tabWidget->setIconSize(QSize(16, 16));
        tab_Home = new QWidget();
        tab_Home->setObjectName(QString::fromUtf8("tab_Home"));
        gridLayout_3 = new QGridLayout(tab_Home);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        yoobeeLogo_2 = new QLabel(tab_Home);
        yoobeeLogo_2->setObjectName(QString::fromUtf8("yoobeeLogo_2"));
        yoobeeLogo_2->setPixmap(QPixmap(QString::fromUtf8(":/images/YoobeeLibraries.png")));

        gridLayout_3->addWidget(yoobeeLogo_2, 0, 0, 1, 1);

        label_3 = new QLabel(tab_Home);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Century Gothic")});
        font.setBold(true);
        label_3->setFont(font);

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        welcomeBack = new QLabel(tab_Home);
        welcomeBack->setObjectName(QString::fromUtf8("welcomeBack"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Century Gothic")});
        welcomeBack->setFont(font1);

        gridLayout_3->addWidget(welcomeBack, 2, 0, 1, 1);

        textBrowser = new QTextBrowser(tab_Home);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_3->addWidget(textBrowser, 4, 0, 1, 1);

        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/tab-home-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_Home, icon1, QString());
        tab_Catalogue = new QWidget();
        tab_Catalogue->setObjectName(QString::fromUtf8("tab_Catalogue"));
        verticalLayout = new QVBoxLayout(tab_Catalogue);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        searchBar = new QLineEdit(tab_Catalogue);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));

        verticalLayout->addWidget(searchBar);

        scrollArea = new QScrollArea(tab_Catalogue);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1229, 583));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/tab-catalogue-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_Catalogue, icon2, QString());
        tab_YourAccount = new QWidget();
        tab_YourAccount->setObjectName(QString::fromUtf8("tab_YourAccount"));
        verticalLayout_4 = new QVBoxLayout(tab_YourAccount);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        profile_picture = new QLabel(tab_YourAccount);
        profile_picture->setObjectName(QString::fromUtf8("profile_picture"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(profile_picture->sizePolicy().hasHeightForWidth());
        profile_picture->setSizePolicy(sizePolicy2);
        profile_picture->setAutoFillBackground(false);

        horizontalLayout->addWidget(profile_picture);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        user_name = new QLabel(tab_YourAccount);
        user_name->setObjectName(QString::fromUtf8("user_name"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("MS Shell Dlg 2")});
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        user_name->setFont(font2);
        user_name->setStyleSheet(QString::fromUtf8("font: 75 16pt \"MS Shell Dlg 2\";"));

        verticalLayout_2->addWidget(user_name);

        user_id = new QLabel(tab_YourAccount);
        user_id->setObjectName(QString::fromUtf8("user_id"));
        user_id->setFont(font1);
        user_id->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 241, 241);"));

        verticalLayout_2->addWidget(user_id);

        user_email = new QLabel(tab_YourAccount);
        user_email->setObjectName(QString::fromUtf8("user_email"));
        user_email->setFont(font1);

        verticalLayout_2->addWidget(user_email);

        user_phonenumber = new QLabel(tab_YourAccount);
        user_phonenumber->setObjectName(QString::fromUtf8("user_phonenumber"));
        user_phonenumber->setFont(font1);
        user_phonenumber->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 241, 241);"));

        verticalLayout_2->addWidget(user_phonenumber);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        yourAccount_update = new QPushButton(tab_YourAccount);
        yourAccount_update->setObjectName(QString::fromUtf8("yourAccount_update"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(yourAccount_update->sizePolicy().hasHeightForWidth());
        yourAccount_update->setSizePolicy(sizePolicy3);
        yourAccount_update->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(yourAccount_update);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_2);

        users_books = new QTabWidget(tab_YourAccount);
        users_books->setObjectName(QString::fromUtf8("users_books"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(users_books->sizePolicy().hasHeightForWidth());
        users_books->setSizePolicy(sizePolicy4);
        users_books->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableWidget_currentBooks = new QTableWidget(tab);
        tableWidget_currentBooks->setObjectName(QString::fromUtf8("tableWidget_currentBooks"));

        horizontalLayout_2->addWidget(tableWidget_currentBooks);

        users_books->addTab(tab, QString());

        verticalLayout_4->addWidget(users_books);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        yourAccount_logout = new QPushButton(tab_YourAccount);
        yourAccount_logout->setObjectName(QString::fromUtf8("yourAccount_logout"));
        sizePolicy3.setHeightForWidth(yourAccount_logout->sizePolicy().hasHeightForWidth());
        yourAccount_logout->setSizePolicy(sizePolicy3);
        yourAccount_logout->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(yourAccount_logout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/tab-account-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_YourAccount, icon3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Catalogue);

        tabWidget->setCurrentIndex(0);
        users_books->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Catalogue);
    } // setupUi

    void retranslateUi(QDialog *Catalogue)
    {
        Catalogue->setWindowTitle(QCoreApplication::translate("Catalogue", "Yoobee Library System", nullptr));
        yoobeeLogo_2->setText(QString());
        label_3->setText(QCoreApplication::translate("Catalogue", "LATEST NEWS", nullptr));
        welcomeBack->setText(QCoreApplication::translate("Catalogue", "Welcome back, ", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Catalogue", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Century Gothic','sans-serif'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/images/top-books.png\" /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Home), QCoreApplication::translate("Catalogue", "Home", nullptr));
        searchBar->setPlaceholderText(QCoreApplication::translate("Catalogue", "Search our catalogue", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Catalogue), QCoreApplication::translate("Catalogue", "Catalogue", nullptr));
        profile_picture->setText(QCoreApplication::translate("Catalogue", "Person Picture", nullptr));
        user_name->setText(QCoreApplication::translate("Catalogue", "Person Name", nullptr));
        user_id->setText(QCoreApplication::translate("Catalogue", "User ID", nullptr));
        user_email->setText(QCoreApplication::translate("Catalogue", "User email", nullptr));
        user_phonenumber->setText(QCoreApplication::translate("Catalogue", "User phone number", nullptr));
        yourAccount_update->setText(QCoreApplication::translate("Catalogue", "Update Details", nullptr));
        users_books->setTabText(users_books->indexOf(tab), QCoreApplication::translate("Catalogue", "Your Current books", nullptr));
        yourAccount_logout->setText(QCoreApplication::translate("Catalogue", "Log out", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_YourAccount), QCoreApplication::translate("Catalogue", "Your account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Catalogue: public Ui_Catalogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGUE_H
