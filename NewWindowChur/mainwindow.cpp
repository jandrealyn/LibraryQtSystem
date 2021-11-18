//including modules

#include "mainwindow.h"
#include "adminhome.h"
#include "loginscreen.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "catalogue.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug> //is a class that provides an output stream for debugging information
#include <QPushButton>//is a widget which executes an action when a user clicks on it.


/*
 * Main screen is for when a user enters the website to browse the online library without needing
 * to save their data. and can freely view the catalogue and main menu.
*/

//Livs code
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

void MainWindow::on_login_clicked(){
    hide();
    _loginWindow = new loginscreen(nullptr);
    _loginWindow->setWindowFlags((windowFlags()) | Qt::WindowMinimizeButtonHint);
    _loginWindow->show();
    connect(_loginWindow, SIGNAL(OpenMainMenu()), this, SLOT(MainMenuOpen()));
}
void MainWindow::MainMenuOpen()
{
    show();
}
