#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "createfiles.h"
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

    // Code by Jakob
    if (user == "admin" && pass == "cs106")
    {
        hide();
        _adminWindow = new adminhome(nullptr);
        _adminWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
        _adminWindow->showNormal();
        connect(_adminWindow, SIGNAL(ClosedMainMenu()), this, SLOT(LoginScreenOpen()));
    }
    else
    {
        // Checking if the inputs exist in the members file
        QStringList a = CreateFiles::GetFileData(CSVFiles::_Members);
        int foundUser = a.indexOf(user);
        int foundPass = a.indexOf(pass);

        // indexOf returns a positive number if it found the username or password
        if (foundUser > 0 && foundPass > 0)
        {
            QString memName = a[foundUser - 2];
            QString memID = a[foundUser - 3];
            hide();
            // CALL YOUR DIALOG WINDOWS WITH (nullptr) SO THAT THEY HAVE A TASKBAR ICON
            _catalogueWindow = new Catalogue(nullptr, memName, memID);
            _catalogueWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
            _catalogueWindow->showMaximized();
            connect(_catalogueWindow, SIGNAL(OpenMainMenu()), this, SLOT(LoginScreenOpen()));
            //_catalogueWindow->setVariables(memName, memID);
        }
        else
        {
            QMessageBox::warning(this, "Login", "Unsucessful, try again."); //if enters a incorrect login/password  // - liv
        }
    }
}

void loginscreen::on_Create_clicked(){
    hide();
    _signup = new signupscreen(nullptr);
    _signup->setWindowFlags((windowFlags()) | Qt::WindowMinimizeButtonHint);
    _signup->show();
    connect(_signup, SIGNAL(OpenLoginScreen()), this, SLOT(LoginScreenOpen())); // Jakob
}

void loginscreen::on_close_clicked(){
   close();
   emit OpenMainMenu();
}

void loginscreen::LoginScreenOpen(){
    show();
}
