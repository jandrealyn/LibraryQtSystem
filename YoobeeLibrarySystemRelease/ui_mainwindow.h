/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Home;
    QGridLayout *gridLayout_3;
    QPushButton *login;
    QTextBrowser *textBrowser;
    QLabel *img;
    QLabel *label_3;
    QTextBrowser *textBrowser1;
    QWidget *Test;
    QVBoxLayout *verticalLayout;
    QLineEdit *searchBar;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1249, 716);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("*{\n"
"background-color:rgb(255, 255, 255);\n"
"font-family: cenury gothic, sans-serif;\n"
"\n"
"}\n"
"\n"
"QFrame{\n"
"background-color: #FFFFFF;\n"
"\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(100, 20, 1024, 592));
        Home = new QWidget();
        Home->setObjectName(QString::fromUtf8("Home"));
        gridLayout_3 = new QGridLayout(Home);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        login = new QPushButton(Home);
        login->setObjectName(QString::fromUtf8("login"));
        login->setStyleSheet(QString::fromUtf8("*{\n"
"background-color:rgb(255, 255, 255);\n"
"font-family: cenury gothic, sans-serif;\n"
"\n"
"}\n"
"QPushButton#login{\n"
"background-color: #d3d3d3;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: black;\n"
"min-width: 10em;\n"
"padding: 6px;\n"
"}"));

        gridLayout_3->addWidget(login, 0, 1, 1, 1);

        textBrowser = new QTextBrowser(Home);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_3->addWidget(textBrowser, 2, 0, 1, 1);

        img = new QLabel(Home);
        img->setObjectName(QString::fromUtf8("img"));
        img->setPixmap(QPixmap(QString::fromUtf8(":/images/yoobee-logo.png")));

        gridLayout_3->addWidget(img, 0, 0, 1, 1);

        label_3 = new QLabel(Home);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setFamilies({QString::fromUtf8("cenury gothic")});
        font.setPointSize(14);
        font.setBold(true);
        label_3->setFont(font);

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        textBrowser1 = new QTextBrowser(Home);
        textBrowser1->setObjectName(QString::fromUtf8("textBrowser1"));

        gridLayout_3->addWidget(textBrowser1, 2, 0, 1, 1);

        tabWidget->addTab(Home, QString());
        Test = new QWidget();
        Test->setObjectName(QString::fromUtf8("Test"));
        verticalLayout = new QVBoxLayout(Test);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        searchBar = new QLineEdit(Test);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));

        verticalLayout->addWidget(searchBar);

        scrollArea = new QScrollArea(Test);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 998, 520));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        tabWidget->addTab(Test, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1249, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Yoobe Libray System", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "Login/Signup", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'cenury gothic','sans-serif'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/images/top-books.png\" /></p></body></html>", nullptr));
        img->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "LATEST BOOK HITS!", nullptr));
        textBrowser1->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'cenury gothic','sans-serif'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/images/top-books.png\" /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Home), QCoreApplication::translate("MainWindow", "Home", nullptr));
        searchBar->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search our catalogue", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Test), QCoreApplication::translate("MainWindow", "Catalogue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
