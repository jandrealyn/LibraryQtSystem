#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "catalogue.h"
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


    //Login password & username for a normal user (not admin)  // - liv
    if(user == "test" && pass == "test"){
        hide();
        // CALL YOUR DIALOG WINDOWS WITH (nullptr) SO THAT THEY HAVE A TASKBAR ICON
        _catalogueWindow = new Catalogue(nullptr);
        _catalogueWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
        _catalogueWindow->showMaximized();
        connect(_catalogueWindow, SIGNAL(ClosedMainMenu()), this, SLOT(MainMenuClosed()));
    }
    else {
        QMessageBox::warning(this, "Login", "Unsucessful, try again."); //if enters a incorrect login/password  // - liv
    }

   // window = new Dialog(this);
    // window->show();

}

void MainWindow::MainMenuClosed()
{
    show();
}
