// ------------------------------------------------------------
//
// Update User Details
// Written by Jakob
//
// This lets users change their details as long as they don't
// clash with other users existing details (such as username
// and email).
//
// I've opted not to let the user change their ID, but they can
// still view it anyway.
//
// ------------------------------------------------------------

#include "updateuserdetails.h"
#include "ui_updateuserdetails.h"
#include "SystemFiles.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>

UpdateUserDetails::UpdateUserDetails(QWidget *parent, QString memUsername, QString memPassword, QString memfName, QString memlName, QString memEmail, QString memPhone, QString memID) :
    QDialog(parent),
    ui(new Ui::UpdateUserDetails)
{
    ui->setupUi(this);

    _username = memUsername;
    _password = memPassword;
    _fname = memfName;
    _lname = memlName;
    _email = memEmail;
    _phone = memPhone;
    _id = memID;

    _usernameGood = false;
    _emailGood = false;

    // Getting members data straight away
    membersData = SystemFiles::GetFileData(CSVFiles::_Members);

    // Settings all the line edits with user information
    ui->lineEdit_username->setText(memUsername);
    ui->lineEdit_password->setText(memPassword);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_password->setEnabled(false);
    ui->lineEdit_firstname->setText(memfName);
    ui->lineEdit_lastname->setText(memlName);
    ui->lineEdit_email->setText(memEmail);
    ui->lineEdit_phone->setText(memPhone);
    ui->lineEdit_userid->setText(memID);
    ui->lineEdit_userid->setEnabled(false);

    connect(ui->lineEdit_username, SIGNAL(textChanged(QString)), this, SLOT(checkValues()));
    connect(ui->lineEdit_password, SIGNAL(textChanged(QString)), this, SLOT(checkValues()));
    connect(ui->lineEdit_firstname, SIGNAL(textChanged(QString)), this, SLOT(checkValues()));
    connect(ui->lineEdit_lastname, SIGNAL(textChanged(QString)), this, SLOT(checkValues()));
    connect(ui->lineEdit_email, SIGNAL(textChanged(QString)), this, SLOT(checkValues()));
    connect(ui->lineEdit_phone, SIGNAL(textChanged(QString)), this, SLOT(checkValues()));

    // Not enabling the confirm changes button until a change is made AND they're valid changes (e.g. don't clash with other existing user info)
    ui->confirmChanges->setEnabled(false);
}

UpdateUserDetails::~UpdateUserDetails()
{
    delete ui;
}

// We don't want the user to be able to update their account with the exact same values they already have.
// This function stops them from doing that.
bool UpdateUserDetails::ValuesAreTheSame()
{
    if (ui->lineEdit_username->text() == _username &&
        ui->lineEdit_password->text() == _password &&
        ui->lineEdit_firstname->text() == _fname &&
        ui->lineEdit_lastname->text() == _lname &&
        ui->lineEdit_email->text() == _email &&
        ui->lineEdit_phone->text() == _phone)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void UpdateUserDetails::on_pushButton_2_clicked()
{
    close();
}

// This let's the user edit their password when the checkbox is checked.
void UpdateUserDetails::on_checkBox_toggled(bool checked)
{
    if (checked)
    {
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
        ui->lineEdit_password->setEnabled(true);
    }
    else
    {
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        ui->lineEdit_password->setEnabled(false);
    }
}

void UpdateUserDetails::on_confirmChanges_clicked()
{
    QMessageBox* confirm = new QMessageBox(this);
    confirm->setWindowTitle("Confirm Your Changes");
    confirm->setText("Are you sure you want to change your details?");
    confirm->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    confirm->setDefaultButton(QMessageBox::Yes);
    int result = confirm->exec();

    int userIndex = membersData.indexOf(_id);
    membersData[userIndex + 2] = ui->lineEdit_firstname->text(); // Firstname
    membersData[userIndex + 3] = ui->lineEdit_lastname->text();  // Last Name
    membersData[userIndex + 4] = ui->lineEdit_username->text();  // Username
    membersData[userIndex + 5] = ui->lineEdit_password->text();  // Password
    membersData[userIndex + 6] = ui->lineEdit_email->text();     // Email
    membersData[userIndex + 7] = ui->lineEdit_phone->text();     // Phone Number

    switch (result)
    {
    case QMessageBox::Yes:
        SystemFiles::UpdateMemberDetails(membersData);
        close();
        break;
    case QMessageBox::Cancel:
        break;
    default: break;
    }
}

void UpdateUserDetails::on_lineEdit_username_textChanged(const QString &arg1)
{
    if (arg1 == _username)
    {
        QPixmap p(":/images/username-ok.png");
        ui->usernamePic->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
        _usernameGood = true;
    }
    else if (arg1 == "admin")
    {
        QPixmap p(":/images/username-taken.png");
        ui->usernamePic->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
        _usernameGood = false;
    }
    else
    {
        if (arg1 != "")
        {
            if (membersData.indexOf(arg1) > 0) // If the username already exists
            {
                QPixmap p(":/images/username-taken.png");
                ui->usernamePic->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
                _usernameGood = false;
            }
            else // If the new username doesn't exist already
            {
                QPixmap p(":/images/username-ok.png");
                ui->usernamePic->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
                _usernameGood = true;
            }
        }
        else // If the line is empty, we don't allow the user to continue
        {
            QPixmap p(":/images/username-taken.png");
            ui->usernamePic->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
            _usernameGood = false;
        }
    }
}

void UpdateUserDetails::on_lineEdit_email_textChanged(const QString &arg1)
{
    if (arg1 == _email)
    {
        QPixmap p(":/images/username-ok.png");
        ui->emailPic->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
        _emailGood = true;
    }
    else
    {
        if (arg1 != "")
        {
            if (membersData.indexOf(arg1) > 0)
            {
                QPixmap p(":/images/username-taken.png");
                ui->emailPic->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
                _emailGood = false;
            }
            else
            {
                QPixmap p(":/images/username-ok.png");
                ui->emailPic->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
                _emailGood = true;
            }
        }
        else
        {
            QPixmap p(":/images/username-taken.png");
            ui->emailPic->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
            _emailGood = false;
        }
    }
}

void UpdateUserDetails::checkValues()
{
    if (!ui->lineEdit_username->text().isEmpty() &&
        _usernameGood &&
        !ui->lineEdit_password->text().isEmpty() &&
        !ui->lineEdit_firstname->text().isEmpty() &&
        !ui->lineEdit_lastname->text().isEmpty() &&
        !ui->lineEdit_email->text().isEmpty() &&
         _emailGood &&
        !ui->lineEdit_phone->text().isEmpty() &&
        !ValuesAreTheSame())
    {
        ui->confirmChanges->setEnabled(true);
    }
    else
    {
        ui->confirmChanges->setEnabled(false);
    }
}
