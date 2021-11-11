//including modules

#include "signupscreen.h"
#include "ui_signupscreen.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug> //is a class that provides an output stream for debugging information
#include <QPushButton>//is a widget which executes an action when a user clicks on it.
#include <QInputDialog>
#include "createfiles.h"
using namespace std;

 // - liv (Worked on Login/Signup/Menu Screens)

//--- Livs Part --//

signupscreen::signupscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupscreen)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png"); // - liv
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio)); // - liv
    ui->Next->setEnabled(false); // Jakob

    // Jakob
    _membersList = CreateFiles::GetFileData(CSVFiles::_Members);

    // Jakob - this bit of code disables the next button until all field have values
    connect(ui->cat_avatar, SIGNAL(clicked()), this, SLOT(checkValues()));
    connect(ui->pup_avatar, SIGNAL(clicked()), this, SLOT(checkValues()));
    connect(ui->jerboa_avatar, SIGNAL(clicked()), this, SLOT(checkValues()));
    connect(ui->no_avatar, SIGNAL(clicked()), this, SLOT(checkValues()));
    connect(ui->firstname, SIGNAL(textChanged()), this, SLOT(checkValues()));
    connect(ui->lastname, SIGNAL(textChanged()), this, SLOT(checkValues()));
    connect(ui->Password, SIGNAL(textChanged()), this, SLOT(checkValues()));
    connect(ui->phone, SIGNAL(textChanged()), this, SLOT(checkValues()));
}

signupscreen::~signupscreen()
{
    delete ui;
}

void signupscreen::on_Next_clicked(){
    QString fName = ui->firstname->text();//firstname input
    QString Lname = ui->lastname->text();//Lastname input
    QString uName = ui->Username->text(); //username input
    QString pWord = ui->Password->text();//password input
    QString email = ui->email->text();//email input
    QString phoneNum = ui->phone->text();//phone input

    CreateFiles::CreateMember(_avatar, fName, Lname, uName, pWord, email, phoneNum);

    Signupscreen2 = new signupscreen2(nullptr);
    Signupscreen2->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
    Signupscreen2->show();
    connect(Signupscreen2, SIGNAL(OpenLoginScreen()), this, SLOT(on_close_clicked()));
    close();
}


void signupscreen::Signupclosed()
{
    show();
}

void signupscreen::on_close_clicked()
{
    close();
    emit OpenLoginScreen(); // - Jakob
}



// By Jakob
// This function checks the text the users has typed in the username line edit.
// It will set _usernameOk to true if the email is not taken already.
void signupscreen::on_Username_textChanged(const QString &arg1)
{
    int index = _membersList.indexOf(arg1);

    if(arg1 == "")
    {
        ui->usernamecheckImg->setPixmap(QPixmap());
        ui->usernameCheckText->setText("");
    }
    else if (index < 0)
    {
        QPixmap p(":/images/username-ok.png");
        ui->usernamecheckImg->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
        ui->usernameCheckText->setText("Username good");
        _usernameOk = true;
    }
    else
    {
        QPixmap p(":/images/username-taken.png");
        ui->usernamecheckImg->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
        ui->usernameCheckText->setText("Username taken");
        _usernameOk = false;
    }
}

// By Jakob
// This function checks the text the users has typed in the email line edit.
// It will set _emailOk to true if the email is not taken already
void signupscreen::on_email_textChanged(const QString &arg1)
{
    int index = _membersList.indexOf(arg1);

    if(arg1 == "")
    {
        ui->emailCheckImg->setPixmap(QPixmap());
        ui->emailCheckText->setText("");
    }
    else if (index < 0)
    {
        QPixmap p(":/images/username-ok.png");
        ui->emailCheckImg->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
        ui->emailCheckText->setText("Email good");
        _emailOk = true;
    }
    else
    {
        QPixmap p(":/images/username-taken.png");
        ui->emailCheckImg->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
        ui->emailCheckText->setText("Email taken");
        _emailOk = false;
    }
}

void signupscreen::on_cat_avatar_toggled(bool checked)
{
    if (checked)
        _avatar = ":/images/cat-avatar.jpg";
}

void signupscreen::on_pup_avatar_toggled(bool checked)
{
    if (checked)
        _avatar = ":/images/dog-avatar.jpg";
}

void signupscreen::on_jerboa_avatar_toggled(bool checked)
{
    if (checked)
        _avatar = ":/images/jerboa-avatar.jpg";
}

void signupscreen::on_radioButton_toggled(bool checked)
{
    if (checked)
        _avatar = ":/images/default-avatar.png";
}

void signupscreen::checkValues()
{
    if (!ui->firstname->text().isEmpty() &&
        !ui->lastname->text().isEmpty() &&
        !ui->Password->text().isEmpty() &&
        _usernameOk &&
        _emailOk)
    {
        if (ui->cat_avatar->isChecked() ||
            ui->pup_avatar->isChecked() ||
            ui->jerboa_avatar->isChecked() ||
            ui->no_avatar->isChecked())
        {
            ui->Next->setEnabled(true);
        }
    }
    else
    {
        ui->Next->setEnabled(false);
    }
}
