#include "signupscreen.h"
#include "ui_signupscreen.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug>
#include <QPushButton>
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
}

signupscreen::~signupscreen()
{
    delete ui;
}

void signupscreen::on_Next_clicked(){
    QString fName = ui->firstname->text();
    QString Lname = ui->lastname->text();
    QString uName = ui->Username->text(); //username input
    QString pWord = ui->Password->text();
    QString email = ui->email->text();
    QString phoneNum = ui->phone->text();

    CreateFiles::CreateMember(fName, Lname, uName, pWord, email, phoneNum);
    _signup2 = new signupscreen2(nullptr);
    _signup2->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
    _signup2->show();
    connect(_signup2, SIGNAL(OpenLoginScreen()), this, SLOT(on_close_clicked()));
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

// Written by Jakob
// If username is already taken, it will not let the user create an account.
void signupscreen::on_Username_textChanged(const QString &arg1)
{
    QStringList membersList = CreateFiles::GetFileData(CSVFiles::_Members);
    int index = membersList.indexOf(arg1);

    if(arg1 == "")
    {
        ui->usernameCheck->setPixmap(QPixmap());
        ui->usernameCheckTest->setText("");
        ui->Next->setEnabled(false);
    }
    else if (index < 0)
    {
        QPixmap p(":/images/username-ok.png");
        ui->usernameCheck->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
        ui->usernameCheckTest->setText("Username good");
        ui->Next->setEnabled(true);
    }
    else
    {
        QPixmap p(":/images/username-taken.png");
        ui->usernameCheck->setPixmap(p.scaled(15,15, Qt::KeepAspectRatio));
        ui->usernameCheckTest->setText("Username taken");
        ui->Next->setEnabled(false);
    }
}
