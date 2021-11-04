#include "signupscreen.h"
#include "ui_signupscreen.h"
#include "catalogue.h"
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
}

signupscreen::~signupscreen()
{
    delete ui;
}

void signupscreen::on_Next_clicked(){
    QString fName = ui->firstName->text();
    QString lName = ui->lastName->text();
    QString user = ui->Username->text(); //username input
    QString pass = ui->Password->text();
    QString mail = ui->email->text();
    QString phone = ui->phone->text();

    CreateFiles::CreateMember(fName, lName, user, pass, mail, phone);

//    if (user == "test" && pass == "test" && mail == "test" && phone == "111"){ //Input thats required to go to next screen
//        hide();


    QString fName = ui->firstname->text();
    QString Lname = ui->lastname->text();
    QString uName = ui->Username->text(); //username input
    QString pWord = ui->Password->text();
    QString email = ui->email->text();
    QString phoneNum = ui->phone->text();

    CreateFiles::CreateMember(fName, Lname, uName, pWord, email, phoneNum);

    if (fName == "test" && Lname == "test" && uName == "test" && pWord == "test" && email == "test" && phoneNum == "111"){ //Input thats required to go to next screen
        hide();

//}
//    else{
//        QMessageBox::warning(this, "Login", "unsuccessful, try again.");
//    }


}

void signupscreen::Signupclosed()
{
    show();
}


void signupscreen::on_close_clicked()
{
    close();
    emit OpenMainMenu();
}

