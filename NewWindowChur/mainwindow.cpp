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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));

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

    // Code by Jakob
    if (user == "admin" && pass == "cs106")
    {
        hide();
        _adminWindow = new adminhome(nullptr);
        _adminWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
        _adminWindow->showNormal();
        connect(_adminWindow, SIGNAL(ClosedMainMenu()), this, SLOT(MainMenuOpen()));
    }
    else
    {
        // Checking if the inputs exist in the members file
        QStringList a = CreateFiles::GetFileData(CSVFiles::_Members);
        int foundUser = a.indexOf(user);
        int foundPass = a.indexOf(pass);
        if (foundUser > 0 && foundPass > 0)
        {
            hide();
            // CALL YOUR DIALOG WINDOWS WITH (nullptr) SO THAT THEY HAVE A TASKBAR ICON
            _catalogueWindow = new Catalogue(nullptr);
            _catalogueWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
            _catalogueWindow->showMaximized();
            connect(_catalogueWindow, SIGNAL(OpenMainMenu()), this, SLOT(MainMenuOpen()));
        }
        else
        {
            QMessageBox::warning(this, "User not found", "Username or password did not match, try again.");
        }
    }

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
        connect(_adminWindow, SIGNAL(ClosedMainMenu()), this, SLOT(MainMenuOpen()));
    }
    else {
        QMessageBox::warning(this, "Login", "Unsucessful, try again."); //if enters a incorrect login/password  // - liv
    }
}

void MainWindow::MainMenuOpen()
{
    show();
}
