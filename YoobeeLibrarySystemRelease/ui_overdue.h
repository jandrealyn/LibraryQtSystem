/********************************************************************************
** Form generated from reading UI file 'overdue.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERDUE_H
#define UI_OVERDUE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Overdue
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget_overdueBooks;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_gotIt;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Overdue)
    {
        if (Overdue->objectName().isEmpty())
            Overdue->setObjectName(QString::fromUtf8("Overdue"));
        Overdue->resize(486, 245);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Overdue->setWindowIcon(icon);
        Overdue->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout_2 = new QVBoxLayout(Overdue);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Overdue);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"MS Shell Dlg 2\";"));

        verticalLayout->addWidget(label);

        tableWidget_overdueBooks = new QTableWidget(Overdue);
        tableWidget_overdueBooks->setObjectName(QString::fromUtf8("tableWidget_overdueBooks"));

        verticalLayout->addWidget(tableWidget_overdueBooks);

        label_2 = new QLabel(Overdue);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_gotIt = new QPushButton(Overdue);
        pushButton_gotIt->setObjectName(QString::fromUtf8("pushButton_gotIt"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_gotIt->sizePolicy().hasHeightForWidth());
        pushButton_gotIt->setSizePolicy(sizePolicy);
        pushButton_gotIt->setMinimumSize(QSize(0, 0));
        pushButton_gotIt->setCheckable(false);
        pushButton_gotIt->setAutoRepeat(false);
        pushButton_gotIt->setFlat(false);

        horizontalLayout_2->addWidget(pushButton_gotIt);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Overdue);

        pushButton_gotIt->setDefault(false);


        QMetaObject::connectSlotsByName(Overdue);
    } // setupUi

    void retranslateUi(QDialog *Overdue)
    {
        Overdue->setWindowTitle(QCoreApplication::translate("Overdue", "Yoobee Library System | Overdue Message", nullptr));
        label->setText(QCoreApplication::translate("Overdue", "You have overdue books.", nullptr));
        label_2->setText(QCoreApplication::translate("Overdue", "Please return them as soon as possible. For every week overdue, a $10 penalty will be applied\n"
" to your account.", nullptr));
        pushButton_gotIt->setText(QCoreApplication::translate("Overdue", "Got it!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Overdue: public Ui_Overdue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERDUE_H
