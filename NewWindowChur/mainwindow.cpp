#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "catalogue.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap Img("C:/Users/olivi/OneDrive/Desktop/CS106/Assignment/LibraryCuties/NewWindowChur/images/YoobeeLibraries");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    QString user = ui->username_input->text(); //Username Input
    QString pass = ui->password_input->text(); //password input

    if(user == "test" && pass == "test"){
        hide();
        // CALL YOUR DIALOG WINDOWS WITH (nullptr) SO THAT THEY HAVE A TASKBAR ICON
        _catalogueWindow = new Catalogue(nullptr);
        _catalogueWindow->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
        _catalogueWindow->showMaximized();
        connect(_catalogueWindow, SIGNAL(ClosedMainMenu()), this, SLOT(MainMenuClosed()));
    }
    else {
        QMessageBox::warning(this, "Login", "Unsucessful, try again.");
    }

   // window = new Dialog(this);
    // window->show();

}

void MainWindow::MainMenuClosed()
{
    show();
}
