#ifndef UPDATEUSERDETAILS_H
#define UPDATEUSERDETAILS_H

#include <QDialog>

namespace Ui {
class UpdateUserDetails;
}

class UpdateUserDetails : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateUserDetails(QWidget *parent = nullptr,
                               QString memUsername = "",
                               QString memPassword = "",
                               QString memfName = "",
                               QString memlName = "",
                               QString memEmail = "",
                               QString memPhone = "",
                               QString memID = "");

    ~UpdateUserDetails();

    bool ValuesAreTheSame();

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_toggled(bool checked);

    void on_confirmChanges_clicked();

    void on_lineEdit_username_textChanged(const QString &arg1);

    void on_lineEdit_email_textChanged(const QString &arg1);

    void checkValues();

private:
    Ui::UpdateUserDetails *ui;
    QStringList membersData;
    QString _username, _password, _fname, _lname, _email, _phone, _id;
    bool _usernameGood, _emailGood;

};

#endif // UPDATEUSERDETAILS_H
