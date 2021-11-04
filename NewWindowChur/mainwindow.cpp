#include "mainwindow.h"
#include "adminhome.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "catalogue.h"
#include "createfiles.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug>
#include <QPushButton>

 // - liv (Worked on Login/Signup/Menu Screens)


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png"); // - liv
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio)); // - liv

}

MainWindow::~MainWindow()
{
    delete ui;
}


//When user clicks on login - liv
void MainWindow::on_login_clicked()
{
    QString user = ui->username_input->text(); //Username Input  // - liv
    QString pass = ui->password_input->text(); //password input // - liv

    QStringList a = CreateFiles::GetFileData("members");

    int foundUser = a.indexOf(QRegExp(user));
    int foundPass = a.indexOf(QRegExp(pass));

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

void MainWindow::MainMenuOpen()
{
    show();
}

void MainWindow::on_Create_clicked(){
    hide();
    _signup = new signupscreen(nullptr);
    _signup->setWindowFlags((windowFlags()) | Qt::WindowMinimizeButtonHint);
    _signup->show();
    connect(_signup, SIGNAL(OpenMainMenu()), this, SLOT(MainMenuOpen()));
}

