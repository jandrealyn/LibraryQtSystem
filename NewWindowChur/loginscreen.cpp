//including modules

#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "SystemFiles.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug> //is a class that provides an output stream for debugging information
#include <QPushButton> //is a widget which executes an action when a user clicks on it.
#include <QLineEdit>

 // - liv (Worked on Login/Signup/Menu Screens)
// Jakob - connected the signup screens and made the login functional

/*
   Login screen is for allowing the user to have a entrance into their
   saved data.
*/

loginscreen::loginscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginscreen)
{
    ui->setupUi(this);
   QPixmap Img(":/images/YoobeeLibraries.png"); // - liv
   ui->img_2->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio)); // - liv

   // Checking if the remember me file has any username and password saved
   if (SystemFiles::_rememberMeLog.size() != 0)
   {
       QStringList rememberMeData;
       SystemFiles::_rememberMeLog.open(QIODevice::ReadOnly);
       QTextStream in(&SystemFiles::_rememberMeLog);
       while(!in.atEnd())
       {
           rememberMeData.append(in.readLine());
       }
       SystemFiles::_rememberMeLog.close();

       ui->username_input->setText(rememberMeData[0]);
       ui->password_input->setText(rememberMeData[1]);
       ui->checkBox_rememberMe->setCheckState(Qt::CheckState::Checked); // makes it so the user doesn't have to click remember me every time they log in.
   }

   connect(ui->password_input, SIGNAL(returnPressed()), this, SLOT(on_login_clicked()));

   setAttribute(Qt::WA_DeleteOnClose); // This makes it so that the deconstructor is called whenever this screen is closed :) - Jakob
}

loginscreen::~loginscreen()
{
    // Code by Jakob
    // This makes sure that when a user closes this window, we're still able to remember their login if they want.
    if (ui->checkBox_rememberMe->isChecked())
        SystemFiles::RememberUser(ui->username_input->text(), ui->username_input->text());
    else
        SystemFiles::ClearRememberUser();

    delete ui;
}

//When user clicks on login - liv
void loginscreen::on_login_clicked()
{
    QString user = ui->username_input->text(); //Username Input  // - liv
    QString pass = ui->password_input->text(); //password input // - liv

    if (user == "admin" && pass == "cs106")
    {
        // By lara
        hide();
        _adminWindow = new adminhome(nullptr);
        _adminWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
        _adminWindow->showNormal();
        connect(_adminWindow, SIGNAL(ClosedMainMenu()), this, SLOT(LoginScreenOpen()));
    }
    else
    {
        // Code by Jakob
        // Checking if the inputs exist in the members file
        QStringList membersData = SystemFiles::GetFileData(CSVFiles::_Members);

        int col = 0;
        bool foundUser = false;
        int usernameIndex;
        for (int i = 0; i < membersData.size(); i++)
        {
            if (col == 4) // Only check for username and password once we reach the username column.
            {
                if (user == membersData[i]) // this is the same as saying if (user == membersData[col])
                {
                    if (pass == membersData[i + 1])
                    {
                        foundUser = true;
                        usernameIndex = i; // we need this to find the users account details
                        break;
                    }
                    else
                        col++;
                }
                else
                    col++;
            }
            else if (col == 7)
            {
                col = 0; // Reset columns back to 0 since there are only 7 columns in members.csv
            }
            else
            {
              col++;
            }
        }

        if (foundUser)
        {
            // These are passed through the catalogue windows constructor
            QString memfName = membersData[usernameIndex - 2];
            QString memlName = membersData[usernameIndex - 1];
            QString memEmail = membersData[usernameIndex + 2];
            QString memPhone = membersData[usernameIndex + 3];
            QString memID = membersData[usernameIndex - 4];
            QString memAvatar = membersData[usernameIndex - 3];

            // Checking if they want their login details saved
            if (ui->checkBox_rememberMe->isChecked())
                SystemFiles::RememberUser(ui->username_input->text(), ui->username_input->text());
            else
                SystemFiles::ClearRememberUser();

            // Hiding the MainWindow to open the catalogue window
            hide();

            // CALL YOUR DIALOG WINDOWS WITH (nullptr) SO THAT THEY HAVE A TASKBAR ICON
            _catalogueWindow = new Catalogue(nullptr, user, pass, memfName, memlName, memEmail, memPhone, memID, memAvatar);
            _catalogueWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
            _catalogueWindow->showNormal();
            connect(_catalogueWindow, SIGNAL(OpenMainMenu()), this, SLOT(LoginScreenOpen()));
        }
        else
        {
            QMessageBox::warning(this, "Login", "Unsucessful, try again."); //if enters a incorrect login/password  // - liv
        }
    }
}

void loginscreen::on_Create_clicked(){ //Liv
    //hide "login screen " when use clicks the create button
    hide();
    _signup = new signupscreen(nullptr);
    _signup->setWindowFlags((windowFlags()) | Qt::WindowMinimizeButtonHint);
    _signup->show();
    connect(_signup, SIGNAL(OpenLoginScreen()), this, SLOT(LoginScreenOpen())); // Jakob
    connect(_signup, SIGNAL(LoginOnNextClicked(QString,QString)), this, SLOT(LoginThroughSignup(QString,QString)));
}

void loginscreen::on_close_clicked(){ //liv
   close();
   emit OpenMainMenu();
}

void loginscreen::LoginScreenOpen(){ //liv
    show();
}

// This function was made after alpha testing.
// We found that some of our users may want to login right after creating a user.
void loginscreen::LoginThroughSignup(QString uName, QString pWord)
{
    // Checking if the inputs exist in the members file
    QStringList membersData = SystemFiles::GetFileData(CSVFiles::_Members);

    int col = 0;
    bool foundUser = false;
    int usernameIndex;
    for (int i = 0; i < membersData.size(); i++)
    {
        if (col == 4) // Only check for username and password once we reach the username column.
        {
            if (uName == membersData[i]) // this is the same as saying if (user == membersData[col])
            {
                if (pWord == membersData[i + 1])
                {
                    foundUser = true;
                    usernameIndex = i; // we need this to find the users account details
                    break;
                }
                else
                    col++;
            }
            else
                col++;
        }
        else if (col == 7)
        {
            col = 0; // Reset columns back to 0 since there are only 7 columns in members.csv
        }
        else
        {
          col++;
        }
    }

    if (foundUser)
    {
        // These are passed through the catalogue windows constructor
        QString memfName = membersData[usernameIndex - 2];
        QString memlName = membersData[usernameIndex - 1];
        QString memEmail = membersData[usernameIndex + 2];
        QString memPhone = membersData[usernameIndex + 3];
        QString memID = membersData[usernameIndex - 4];
        QString memAvatar = membersData[usernameIndex - 3];

        hide();
        // CALL YOUR DIALOG WINDOWS WITH (nullptr) SO THAT THEY HAVE A TASKBAR ICON
        _catalogueWindow = new Catalogue(nullptr, uName, pWord, memfName, memlName, memEmail, memPhone, memID, memAvatar);
        _catalogueWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
        _catalogueWindow->showNormal();
        connect(_catalogueWindow, SIGNAL(OpenMainMenu()), this, SLOT(LoginScreenOpen()));
    }
    else
    {
        QMessageBox::warning(this, "Login Unsuccessful", "You may have entered your details wrong. Please try again.");
    }
}
