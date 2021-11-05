#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "createfiles.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug>
#include <QPushButton>

 // - liv (Worked on Login/Signup/Menu Screens)
// Jakob - connected the signup screens and made the login functional

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
        QStringList membersData = CreateFiles::GetFileData(CSVFiles::_Members);

        int col = 0;
        bool foundUser = false;
        int usernameIndex;
        int passwordIndex;
        for (int i = 0; i < membersData.size(); i++)
        {
            if (col == 3) // Only check for username and password once we reach the username column.
            {
                if (user == membersData[i])
                {
                    if (pass == membersData[i + 1])
                    {
                        foundUser = true;
                        usernameIndex = i;
                        passwordIndex = i + 1;
                    }
                }
            }
            else if (col == 6)
            {
                col = 0; // Reset columns back to 0 since there are only 6 columns in members.csv
            }
            else
            {
              col++;
            }
        }

        // indexOf returns a positive number if it found the username or password
        if (foundUser)
        {
            QString memName = membersData[usernameIndex - 2];
            QString memID = membersData[passwordIndex - 3];
            hide();
            // CALL YOUR DIALOG WINDOWS WITH (nullptr) SO THAT THEY HAVE A TASKBAR ICON
            _catalogueWindow = new Catalogue(nullptr, memName, memID);
            _catalogueWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
            _catalogueWindow->showMaximized();
            connect(_catalogueWindow, SIGNAL(OpenMainMenu()), this, SLOT(LoginScreenOpen()));
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
