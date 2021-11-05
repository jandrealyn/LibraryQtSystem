#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "adminhome.h"
#include "dialog.h"
#include "catalogue.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug>
#include <QPushButton>

 // - liv (Worked on Login/Signup/Menu Screens)

loginscreen::loginscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginscreen)
{
    ui->setupUi(this);
       QPixmap Img(":/images/YoobeeLibraries.png"); // - liv
       ui->img_2->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio)); // - liv
}

loginscreen::~loginscreen()
{
    delete ui;
}

//When user clicks on login - liv
void loginscreen::on_login_clicked()
{


    QString user = ui->username_input->text(); //Username Input  // - liv
    QString pass = ui->password_input->text(); //password input // - liv


    //Login password & username for a normal user (not admin)  // - liv
    if(user == "test" && pass == "test"){
        hide();
        // CALL YOUR DIALOG WINDOWS WITH (nullptr) SO THAT THEY HAVE A TASKBAR ICON
        _catalogueWindow = new Catalogue(nullptr);
        _catalogueWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
        _catalogueWindow->showMaximized();
        connect(_catalogueWindow, SIGNAL(OpenMainMenu()), this, SLOT(MainMenuOpen()));
    }
    else if(user == "admin" && pass == "cs106") {
        hide();
        _adminWindow = new adminhome(nullptr);
        _adminWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
        _adminWindow->showNormal();
        connect(_adminWindow, SIGNAL(ClosedMainMenu()), this, SLOT(MainMenuClosed()));
    }
    else {
        QMessageBox::warning(this, "Login", "Unsucessful, try again."); //if enters a incorrect login/password  // - liv
    }

   // window = new Dialog(this);
    // window->show();

}

void loginscreen::MainMenuOpen()
{
    show();
}

void loginscreen::on_Create_clicked(){
    hide();
    _signup = new signupscreen(nullptr);
    _signup->setWindowFlags((windowFlags()) | Qt::WindowMinimizeButtonHint);
    _signup->show();
    connect(_signup, SIGNAL(OpenMainMenu()), this, SLOT(MainMenuOpen()));
}
void loginscreen::on_close_clicked(){
   close();
   emit OpenMainMenu();
}
