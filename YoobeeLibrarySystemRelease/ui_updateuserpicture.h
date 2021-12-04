/********************************************************************************
** Form generated from reading UI file 'updateuserpicture.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEUSERPICTURE_H
#define UI_UPDATEUSERPICTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_UpdateUserPicture
{
public:

    void setupUi(QDialog *UpdateUserPicture)
    {
        if (UpdateUserPicture->objectName().isEmpty())
            UpdateUserPicture->setObjectName(QString::fromUtf8("UpdateUserPicture"));
        UpdateUserPicture->resize(400, 300);

        retranslateUi(UpdateUserPicture);

        QMetaObject::connectSlotsByName(UpdateUserPicture);
    } // setupUi

    void retranslateUi(QDialog *UpdateUserPicture)
    {
        UpdateUserPicture->setWindowTitle(QCoreApplication::translate("UpdateUserPicture", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UpdateUserPicture: public Ui_UpdateUserPicture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEUSERPICTURE_H
